# Crash Detection Overview
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--SE: @Maplestory-->
<!--TSE: @yufeifei-->

A process crash refers to an unexpected exit of an application or a system process. Unexpected process exit occurs in the following scenarios:

1. Native code does not process crash exception signals, and C++ crash logs are generated. For details, see [Cpp Crash (Process Crash) Detection](cppcrash-guidelines.md).

2. JS/ArkTS code does not process exceptions, and JS crash logs are generated. For details, see [JS Crash (Process Crash) Detection](jscrash-guidelines.md).

3. An application is freezing and AppFreeze logs are generated. For details, see [Application Freeze Detection](appfreeze-guidelines.md).

4. The system kills the process unexpectedly. For details, see [Application-Killed Detection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-runtime-appkilled-detection).
