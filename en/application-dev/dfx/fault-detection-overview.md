# Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=552600b0ea7451a7ac2f58aae751acd2a0a9b5bf translatedAt=2026-07-29T10:46:45.221Z pushedAt=2026-07-29T11:06:23.355Z -->

Performance Analysis Kit provides comprehensive capabilities such as fault detection and exception handling. As faults vary in causes and symptoms, application stability deteriorates, affecting application development efficiency, delivery costs, and user experience. Therefore, you need to improve quality by designing a fault management system, which includes the detection, analysis, locating and rectification of faults, and quality measurement.

To help you quickly locate and rectify app faults, this topic describes the detection principles, log specifications, log obtaining methods, and constraints of faults such as process crash, address out-of-bounds, app freeze, resource leak, task execution timeout, and app termination.

> **NOTE**
>
> The following faults cause unexpected application or system process exit:
>
> 1. Native code does not process crash exception signals, and C++ crash logs are generated. For details, see [Cpp Crash (Process Crash) Detection](cppcrash-guidelines.md).
>
> 2. JS/ArkTS code does not process exceptions, and JS crash logs are generated. For details, see [JS Crash (Process Crash) Detection](jscrash-guidelines.md).
>
> 3. The application is freezing and AppFreeze logs are generated. For details, see [Application Freeze Detection](appfreeze-guidelines.md).
>
> 4. The application process is terminated by the system, and the application exits unexpectedly. For details, see [Application Killed Detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/appkilled-guidelines).