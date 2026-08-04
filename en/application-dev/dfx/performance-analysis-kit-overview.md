# About This Kit

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mzyan-->
<!--Designer: @liyueric-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=552600b0ea7451a7ac2f58aae751acd2a0a9b5bf translatedAt=2026-07-31T01:35:21.116Z pushedAt=2026-07-31T08:32:22.547Z -->

Performance Analysis Kit provides the event, log, and tracing analysis tools to help you check the running status of your application for further behavior, fault, security, and statistical analysis.

Performance Analysis Kit provides a collection of capabilities for improving application quality. For details, see [Application Quality Overview](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-quality-overview).

## When to Use

- Application debugging: provides the HiLog functionality to help you record and obtain log information for fault analysis.

- Fault locating: provides log, event, and tracing information related to reliability, performance, power consumption, and distributed faults.

- Online monitoring: provides log, event, and tracing APIs to help you record and analyze the running status of your application.

- Grayscale collection: works with the cloud side to enable full fault log collection on a small number of selected devices and upload the logs to the cloud, providing more detailed fault information to help you better locate faults.

## Available Capabilities

- [Fault detection](fault-detection-overview.md): provides the capability of detecting application stability faults, including the crash, address sanitizer, application freeze, resource leak, and task timeout events.

- [Power consumption detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/power-detection): provides the capability of detecting abnormal application power consumption, such as high CPU load.

- [Performance detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/perf-detection): provides the capability of detecting application performance exceptions, such as time-consuming application launches and scrolling frame loss.

- [HiLog](hilog-guidelines-arkts.md): provides the capability of recording and obtaining logs.

- [HiAppEvent](hiappevent-intro.md): provides the capability of recording fault, behavior, security, and statistical events, subscribing to system events, and setting data processors for data upload.

- [HiTraceMeter](hitracemeter-intro.md) and [HiTraceChain](hitracechain-intro.md): provide the capabilities of performance tracing and cross-thread and cross-process distributed tracing.

- [HiChecker](hichecker-guidelines-arkts.md): provides the capability of detecting time-consuming application thread calls and ability resource leaks.

- [HiDebug](hidebug-guidelines.md): provides the capability of obtaining application and system resource usage.

- [HiCollie](hicollie-guidelines-ndk.md): provides the capability of detecting service thread task execution timeout and reporting timeout events.

- [ErrorManager](errormanager-guidelines.md) and [AppRecovery](apprecovery-guidelines.md): provide the capability of capturing application runtime exceptions and restoring the startup status and data after an application exits unexpectedly.

- [App grayscale collection](hiretrieval-intro.md): provides the app grayscale collection capability, allowing you to enable full log collection on a small number of selected devices to obtain more detailed fault logs and better locate faults.

- Command line tools for debugging the system and applications: [hdc](hdc.md), [HiLog](hilog.md), [HiDumper](hidumper.md), [HiTrace](hitrace.md) and [HiPerf](hiperf.md) .

## Features

**Hassle-free APM System Setup**

- Provides [HiDebug](hidebug-guidelines.md), [HiAppEvent](hiappevent-intro.md) and [HiLog](hilog-guidelines-arkts.md) APIs to build an Application Performance Management (APM) SDK on the device for interconnection with the APM developed by vendors.

- Provides [HiAppEvent system events](event-subscription-overview.md#system-events) and [application events](event-subscription-overview.md#application-events) for subscribing to events (such as crash and application freeze events) triggered during application running, and quickly records and collects event information required for O&M.

**Powerful Exception Detection and Handling Mechanism**

- Provides a comprehensive application quality detection mechanism, including [fault detection](fault-detection-overview.md), [performance detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/perf-detection) and [power consumption detection](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/power-detection).

- Provides simplified, standard, and complete exception logs to accurately record exception propagation paths.

- Provides a comprehensive exception detection mechanism to detect exceptions in real time, notify the application of exceptions, and automatically restart the application.

- Provides the grayscale collection capability, which selects a small number of devices to precisely collect full fault logs for specific faults, balancing app performance and fault locating requirements.

**Comprehensive Basic Maintenance and Debugging Capabilities**

- Classifies logs by level and category and supports multiple languages, privacy processing, and traffic control. 

- Provides a complete event framework and mechanisms for event logging, recording, and reporting. 

- Traces process tracks for performance analysis.

<!--RP1--><!--RP1End-->