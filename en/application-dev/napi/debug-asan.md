# C/C++ Memory Error Detection

<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @eric96-->
<!--SE: @liuyingying19huawei-->
<!--TSE: @hwu-mc-->

To achieve better performance of C/C++, the compiler and OS (Windows, Linux, and macOS) runtime framework do not perform security detection on memory operations. This is where AddressSanitizer (ASan) comes into the picture. ASan is integrated in DevEco Studio to detect C/C++ out-of-bounds addresses, and display error stack details and problematic code lines through FaultLog.


For details about how to use ASan, see <!--RP1-->[ASan](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-asan-V5)<!--RP1End-->.
