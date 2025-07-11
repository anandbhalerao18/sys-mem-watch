# 🧠 SysMemWatch — Advanced System Memory Monitor in C

`SysMemWatch` is a lightweight and powerful **system memory monitoring tool written in C** for Linux systems. It continuously tracks RAM usage, logs it to a file with timestamps, and provides live terminal output along with alerts when usage exceeds a given threshold.

Ideal for:
- System resource tracking
- Performance diagnostics
- C language + low-level system programming showcase for resumes

---

## 🚀 Features

- 📊 Real-time memory usage display using `/proc/meminfo`
- 📝 Logs memory usage to a file with timestamps
- 🔁 Runs in an infinite loop every few seconds
- ⚠️ Customizable memory usage alert threshold (e.g., 90%)
- 🧪 Lightweight and fast — written in pure C
- 🛠️ Extendable with CLI arguments using `getopt()`

---

## 📥 How to Clone This Project

```bash
git clone https://github.com/anandbhalerao18/sys-mem-watch.git
cd sys-mem-watch

```
## how to run this project 
run below two cmds in your root folder
```bash
1. gcc src/sysmemwatch.c -o bin/sysmemwatch
2. ./bin/sysmemwatch
```
To watch the log in real time ;-
```bash
tail -f logs/log.txt
```
