# Basic Concepts

The musl libc library of the debug version provides maintenance and test methods, such as memory leak check, heap memory statistics, memory corruption check, and backtrace, to improve the efficiency of locating memory problems in user space.

Instrumentation is performed on the  **malloc**  and  **free**  APIs to log key node information. When memory is requested and released by a program, the memory node integrity is checked. When the program ends, memory statistics are provided for identifying memory leaks.

