# Overview of Performance Tracing

hiTraceMeter is a tool for you to trace service processes and monitor system performance. Through encapsulating and extending the ftrace inside the kernel, hiTraceMeter supports performance tracing for code execution in the user space. You can use hiTraceMeter APIs to implement performance tracing and use the hiTraceMeter CLI tool to collect traced data.

## Basic Concepts

- **hiTraceMeter Tag**

  Tag used for tracing data categorization. It is also known as **hiTraceMeter Category**. Generally, one subsystem maps to a tag. The tag is passed as the **Tag** parameter in performance tracing APIs. When you use the hiTraceMeter CLI tool to collect tracing data, only the tracing data specified by the **Tag** parameter is collected.

## Working Principles

- The application calls hiTraceMeter APIs to perform performance tracing. The APIs output the tracing data to the kernel's ftrace data buffer through the kernel's sysfs file interface.
- The hiTraceMeter CLI tool reads the tracing data in the ftrace data buffer and saves the trace data as a text file on the device.

## Constraints

- Due to the asynchronous I/O feature of JS, the hiTraceMeter module provides only asynchronous APIs.
