# eBPF Demo – File Open/Close Tracing

This repository demonstrates how **eBPF** and **bpftrace** can be used to trace system calls in Linux — specifically, file **open** and **close** operations.

The project contains two main parts:
1. A **bpftrace script** (`tracing_open_close.bt`) that dynamically attaches to kernel functions related to file operations.
2. A **C-based eBPF demo** (`ebpf_demo.c`) that shows how to load and attach a simple eBPF program manually.

---

## 🧠 What is eBPF?

**eBPF (extended Berkeley Packet Filter)** is a Linux kernel technology that allows you to safely run sandboxed programs in the kernel without modifying kernel source or loading modules.  
It’s widely used for:
- Observability (like tracing syscalls, network packets, etc.)
- Performance profiling
- Security monitoring (e.g., filtering system activity)

---

## 📁 Repository Structure
.
├── tracing_open_close.bt # bpftrace script to trace file open/close events.
├── bpftrace.JPG # Screenshot of bpftrace output in action.
├── demo.txt # Example output / notes.
└── ebpf_demo/.
└── ebpf_demo.c # Example eBPF C program.

Screenshot Explanation (bpftrace.JPG).

The screenshot in this repository (bpftrace.JPG) shows live output from running the tracing script.
Each line represents a system call event captured by the eBPF program running inside the kernel.

Field	Meaning
open()	The syscall being traced (file open)
filename	The file path being accessed
PID	The process ID performing the action
comm	The command/process name
timestamp (optional)	When the event occurred
