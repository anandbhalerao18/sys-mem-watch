CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/sysmemwatch.c
OUT = bin/sysmemwatch

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

