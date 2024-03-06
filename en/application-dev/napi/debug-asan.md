# C/C++ Memory Error Detection


To achieve better performance of C/C++, the compiler and OS (Windows, Linux, and macOS) runtime framework do not perform security detection on memory operations. This is where AddressSanitizer (ASan) comes into the picture. ASan is integrated in DevEco Studio to detect C/C++ out-of-bounds addresses, and display error stack details and problematic code lines through FaultLog.

