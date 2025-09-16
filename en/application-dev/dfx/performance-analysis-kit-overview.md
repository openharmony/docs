# Introduction to Performance Analysis Kit

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

Performance Analysis Kit provides the event, log, and tracing analysis tools to help you check the running status of your application for further behavior, fault, security, and statistical analysis.

Performance Analysis Kit provides a collection of capabilities for improving application quality.

## When to Use

- Application debugging: provides the HiLog functionality to help you record and obtain log information for fault analysis.

- Fault locating: provides log, event, and tracing information related to reliability, performance, power consumption, and distributed faults.

- Online monitoring: provides log, event, and tracing APIs to help you record and analyze the running status of your application.


## Available Capabilities

- [Fault detection](fault-detection-overview.md): provides the capability of detecting application stability faults, including the crash, address sanitizer, application freeze, resource leak, and task timeout events.

- Power consumption detection: provides the capability of detecting abnormal application power consumption, such as high CPU load.

- Performance detection: provides the capability of detecting application performance exceptions, such as time-consuming application launches and scrolling frame loss.

- [HiLog](hilog-guidelines-arkts.md): provides the capability of recording and obtaining logs.

- [HiAppEvent](hiappevent-intro.md): provides the capability of recording fault, behavior, security, and statistical events, subscribing to system events, and setting data processors for data upload.

- [HiTraceMeter](hitracemeter-intro.md) and [HiTraceChain](hitracechain-intro.md): provide the capabilities of performance tracing and cross-thread and cross-process distributed tracing.

- [HiChecker](hichecker-guidelines-arkts.md): provides the capability of detecting time-consuming application thread calls and ability resource leaks.

- [HiDebug](hidebug-guidelines.md): provides the capability of obtaining application and system resource usage.

- [HiCollie](hicollie-guidelines-ndk.md): provides the capability of detecting service thread task execution timeout and reporting timeout events.

- [ErrorManager](errormanager-guidelines.md) and [AppRecovery](apprecovery-guidelines.md): provide the capability of capturing application runtime exceptions and restoring the startup status and data after an application exits unexpectedly.

- Command line tools for debugging the system and applications: [hdc](hdc.md), [HiLog](hilog.md), [HiDumper](hidumper.md), [HiTrace](hitrace.md) and [HiPerf](hiperf.md) .


## Features

**Convenient APM System Setup**

- Provides [HiDebug](hidebug-guidelines.md), [HiAppEvent](hiappevent-intro.md) and [HiLog](hilog-guidelines-arkts.md) APIs to build an Application Performance Management (APM) SDK on the device for interconnection with the APM developed by vendors.

- Provides the functionalities of customizing [application events](event-subscription-overview.md#application-events) and subscribing to system events so that you can quickly collect events required for O&M.

**Powerful Exception Detection and Handling Mechanism**

- Provides a comprehensive application quality detection mechanism, including [fault detection](fault-detection-overview.md), performance detection and power consumption detection.

- Provides simplified, standard, and complete exception logs to accurately record exception propagation paths.

- Provides a comprehensive exception detection mechanism to detect exceptions in real time, notify the application of exceptions, and automatically restart the application.

**Comprehensive Basic Maintenance and Debugging Capabilities**

- Classifies logs by level and category and supports multiple languages, privacy processing, and traffic control. 

- Provides a complete event framework and mechanisms for event logging, recording, and reporting. 

- Traces process tracks for performance analysis.
