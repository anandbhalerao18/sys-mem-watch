#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   // Need this for sleep() function
#include <time.h>     // For getting timestamps in logs
#include <getopt.h>   // For handling command line args (though we're not using them much here)

#define LOG_FILE "logs/log.txt"  // Where we'll store our logs
#define INTERVAL 5               // How often to check memory (in seconds)

// Gets how much RAM is being used right now (returns percentage)
float get_memory_usage() {
    // Open the system's memory info file
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Failed to open /proc/meminfo");  // oops, couldn't open file
        exit(1);
    }

    char line[256];  // buffer to read each line
    float total = 0, available = 0;  // we'll store values here

    // Read the file line by line
    while (fgets(line, sizeof(line), fp)) {
        // Check if this line has total memory
        if (sscanf(line, "MemTotal: %f kB", &total) == 1) {}
        // Or if it has available memory
        else if (sscanf(line, "MemAvailable: %f kB", &available) == 1) {}
    }

    fclose(fp);  // close the file when done

    // Do some math to get the percentage used
    float used = total - available;
    float percent = (used / total) * 100;

    return percent;  // gives back something like 42.5%
}

// Writes the memory usage to our log file
void log_to_file(float percent) {
    // Open log file in append mode (so we don't overwrite old logs)
    FILE *log = fopen(LOG_FILE, "a");
    if (!log) {
        perror("Could not open log file");  // whoops, can't open log
        return;
    }

    // Get current time for timestamp
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    // ctime() adds a newline we don't want, so remove it
    timestamp[strcspn(timestamp, "\n")] = '\0';

    // Write the log entry: [timestamp] Memory Usage: XX.XX%
    fprintf(log, "[%s] Memory Usage: %.2f%%\n", timestamp, percent);
    fclose(log);  // always close files when done!
}

int main(int argc, char *argv[]) {
    // Infinite loop - runs forever until you Ctrl+C
    while (1) {
        float usage = get_memory_usage();

        // Show current usage in terminal
        printf("Memory Usage: %.2f%%\n", usage);
        // Also save it to log file
        log_to_file(usage);

        // If memory is getting too high, show a warning
        if (usage > 90) {
            printf("⚠️  Warning: Memory usage is above 90%%\n");
        }

        // Wait for X seconds before checking again
        sleep(INTERVAL);
    }

    return 0;  // (though we never actually get here because of the infinite loop)
}
