# Application Killed Detection

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T04:09:17.072Z pushedAt=2026-07-29T06:36:19.557Z -->

## Overview

An application crash refers to the unexpected exit of the application during use. When an application behaves abnormally, for example, consuming excessive system resources such as CPU and memory, the system manages the application based on rules to maintain its health status. Typically, the system kills the application by sending the **SIGKILL** signal (the signal value is **9**) to the application through the service process. By default, the OS does not generate maintenance and debugging information such as stack logs for the **SIGKILL** behavior. As a result, no log is generated in the faultLogger when the application crashes.

## Basic Concepts

An application exits in the following scenarios:

1. When an application is abnormal or throws an exception, for example, the **CPP_CRASH** exception triggered by **SIGSEGV** or **SIGABRT**, the system monitors the exception and records maintenance and debugging logs.

2. When a user manually terminates an application, for example, by clicking the clear button in the task list to clear all applications or swiping up to clear an application, no stack or other maintenance and debugging logs are generated.

3. When **exit** is called, maintenance and debugging logs such as stack logs are not generated.

4. When the application main thread is blocked, the UI freezes and the **APP_FREEZE** log is generated.

5. When resources are overused, the system manages the process and provides detailed maintenance and debugging information. For example, when memory leaks occur in an application, the corresponding maintenance and debugging logs are generated. You can subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain the corresponding events and logs.

6. When the system manages an app, detailed maintenance and debugging information cannot be provided in some scenarios, such as LowMemoryKiller, the app's RSS memory exceeding 4 GB, and rapid leaks.

This topic describes the application termination caused by the **SIGKILL** signal in scenarios 5 and 6.

## Implementation Principles

1. Both the kernel and service processes monitor system resources.

2. When an exception is detected, the system selects and manages the application.

3. The system adds system event logging when triggering application termination.

4. The logging information includes the UID, bundle name, foreground and background information, termination reason, and maintenance and debugging information.

## Constraints

1. The application needs to subscribe to the termination event through HiAppEvent.

2. Termination events are sent to the application asynchronously. The application receives the events upon the next startup.

3. The system management behavior is subject to versions. Therefore, the current management mechanism may be incomplete.

## Triggering Scenario

The system terminates an application in the following scenarios:

1. The memory, CPU, and I/O load of the application exceeds the specified limit, and the number of file handles and threads exceeds the threshold.

2. When the device memory is low, the system terminates applications based on the memory usage and priority.

3. Power-consuming scenarios include frequent wake-ups caused by Binder calls, system freezes during audio playback or recording, and abnormal use of peripherals such as GPS or Bluetooth.

## Detection Methods

Applications can detect abnormal termination in either of the following ways:

1. Obtain the termination reason from the **onCreate** callback parameter of the ability. Specifically, obtain the **LastExitReason** parameter in **LaunchParam**. For details, see [LastExitReason](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#lastexitreason).

2. Subscribe to the **APP_KILLED** event through HiAppEvent. For details, see [Application Killed Event Overview](hiappevent-watcher-app-killed-events.md).

## Analysis Method and Procedure

1. Obtain the termination reason from the **onCreate** callback parameter of the ability.

    For details, see the following table.

    | lastExitReason(enum) | lastExitMessage(string)  | Causes                                            | Handling Policy                                                    |
    | -------------------- | ------------------------ | ---------------------------------------------------- | ------------------------------------------------------------ |
    | APP_FREEZE           | APP_FREEZE               | The application exits because watchdog detects that the application is frozen.| Subscribe to the **APP_FREEZE** event through HiAppEvent and match its fault types.|
    | RESOURCE_CONTROL     | CPU Highload             | The CPU load is high.                                         | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | CPU_EXT Highload         | Fast CPU load detection.                                   | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | IO Manager Control       | I/O manager control.                                           | Reduce the I/O of the application.                                     |
    | RESOURCE_CONTROL     | App Memory Deterioration | The application memory usage exceeds the threshold.                                  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more logs.      |
    | RESOURCE_CONTROL     | Temperature Control      | Temperature control.                                          | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | Memory Pressure          | The system is low on memory, triggering process termination in ascending order of priority.                | Reduce the memory usage of the application.|

2. Subscribe to the **APP_KILLED** event through HiAppEvent.

    Based on the **APP_KILLED** event, you can obtain key information such as the termination reason and application foreground and background. Perform operations based on the following table.

    | reason(string)                | Causes                                                    | Handling Policy                                                    | Whether Control Is Triggered by Application Exceptions| Whether There Are Associated Events|
    | ----------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------ | -------------- |
    | LowMemoryKill                 | The system is low on memory, triggering process termination in ascending order of priority.| Reduce the memory usage of the application.| No                      | No            |
    | SwapFull                      | The swap space is almost used up, which may be caused by memory leaks of some processes or too many background processes.| Reduce the memory usage of the application.| No                      | No            |
    | ResourceLeak(IonLeak)         | The ION memory used by the application exceeds the threshold.                                     | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more ION memory logs. After finding the leak point, reduce the ION memory usage of the application. Generally, the leak is caused by the **Image** component or pixmap.| Yes                      | Yes            |
    | ResourceLeak(GpuRsLeak)       | The GPU memory used by the ArkUI component of the application in the **render_service** process exceeds the threshold.  | Reduce the GPU memory usage of the ArkUI component of the application.                        | Yes                      | No            |
    | ResourceLeak(GpuLeak)         | The GPU memory used by the application in the process (that is, the GPU memory generated by self-rendering) exceeds the threshold.  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more GPU memory logs, find the leak point, and reduce the GPU memory usage of the application self-rendering (using the **XComponent** component).| Yes                      | Yes            |
    | ResourceLeak(AshmemLeak)      | The ashmem memory used by the application exceeds the threshold.                                  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more ashmem memory logs. After finding the leak point, reduce the ashmem memory usage of the application. Generally, the leak is caused by the **Image** component or pixmap.| Yes                      | Yes            |
    | ResourceLeak(CES)                  | CES registration limit exceeded.                                                      | Attempt to reduce the number of CES registrations in the app.                                                                                         | Yes             | No        |
    | ResourceLeak(PSSSoftLeak)          | The memory usage of a background app exceeds twice the detection threshold, with PSS memory accounting for the highest proportion.                                 | Attempt to reduce the app's own memory usage.                                                                                         | Yes             | Yes        |
    | ResourceLeak(PSSLeak)              | The memory usage of a background app exceeds a specific threshold, with PSS memory accounting for the highest proportion.                                   | Attempt to reduce the app's own memory usage.                                                                                         | Yes             | Yes        |
    | ResourceLeak(VMALeak)              | VMA leak.                                                        | Attempt to reduce the app's own VMA memory usage, and release the corresponding virtual memory area after each call.                          | No             | No        |
    | ResourceLeak(FDLeak)               | FD leak.                                                         | Attempt to obtain more FD leak logs by subscribing to RESOURCE_OVERLIMIT through HiAppEvent. After locating the leak point, close unnecessary file handles in a timely manner.                                    | Yes             | Yes        |
    | ResourceLeak(ThreadLeak)           | Thread leak.                                                         | Attempt to obtain more thread leak logs by subscribing to RESOURCE_OVERLIMIT through HiAppEvent. After locating the leak point, destroy unnecessary threads in a timely manner.                                      | Yes             | Yes        |
    | ResourceLeak(KernelZoneLeak)       | Page table memory leak.                                                | No handling required.                 | Yes             | No        |
    | IllegalAudioRendererBySuspend      | The app's audio playback does not request a proper background task, and a large amount of audio playback continues after the app moves to the background.    | When the app moves to the background, avoid unnecessary background audio playback, or use background tasks properly. For details, see [Background Task Development Service](../task-management/background-task-overview.md).       | Yes             | No        |
    | PowerSaveClean                | The device is switched to the power saving mode or emergency mode.                              | No operation is required.                                                  | No                      | No            |
    | VrsKill                            | A third-party app detects a malicious process and calls the PC-side virus detection and handling service API to terminate the process.                             | No handling required.                                                                                                  | No             | No        |
    | RssThresholdKiller                 | The app's RSS memory exceeds a certain threshold.                                                | Attempt to obtain more RSS memory logs by subscribing to RESOURCE_OVERLIMIT through HiAppEvent. After locating the leak point, attempt to reduce the app's own memory usage to avoid the RSS memory exceeding the threshold.                                                                        | Yes             | Yes        |
    | OomKiller                     | The system is low on memory, triggering kernel management and application termination based on specific policies.                | Reduce the memory usage of the application.| No                      | No            |
    | CpaKiller                          | When DRM (Digital Rights Management) services request memory but memory is insufficient, processes are terminated based on certain policies to reclaim memory. | Attempt to reduce the app's own memory usage to reduce the probability of being selected by the device-wide management policy.                                                                         | No             | No        |
    | KillApplication                    | The app exits proactively.                                                       | No handling required.                                                                                                  | No             | No        |
    | OnRemoteDied                       | Remote service died.                                                       | Check whether the dependent remote service is functioning properly.                                                                                         | No             | No        |
    | Restart                            | App restart.                                                         | No handling required.                                                                                                  | No             | No        |
    | UserRequest                        | Swiped away or cleared from the recent tasks list.                                                    | No handling required.                                                                                                  | No             | No        |
    | Uninstall                          | The app exits due to uninstallation.                                                       | No handling required.                                                                                                  | No             | No        |
    | Upgrade                            | The app exits due to an update.                                                       | No handling required.                                                                                                  | No             | No        |
    | Logout                             | The app sandbox is uninstalled when the user logs out.                                                 | No handling required.                                                                                                  | No             | No        |
    | PermissionUpdate                   | App permission update.                                                       | Check whether the app's permission usage is reasonable.                                                                                          | No             | No        |
    | aaForceStop                        | The app is forcibly stopped using the aa command.                                                 | No handling required.                                                                                                  | No             | No        |
    | ThreadBlock6S                      | The app's main thread is blocked and times out.                                                    | Check whether there are blocking operations on the app's main thread, and optimize the code logic.                                                                                | Yes             | Yes. For details, see [ThreadBlock6S](./appfreeze-guidelines.md#thread_block_6s-app-main-thread-freeze-timeout).        |
    | AppInputBlock                      | User input response timeout.                                                     | Check whether the app's UI response is timely, and optimize the input handling logic.                                                                                 | Yes             | Yes. For details, see [AppInputBlock](./appfreeze-guidelines.md#app_input_block-user-input-response-timeout).        |
    | LifecycleTimeout                   | App lifecycle timeout.                                                     | Check whether there are time-consuming operations in the app's lifecycle callbacks.                                                                                    | Yes             | No       |
    | JsError                            | JS layer program crash.                                                      | Check whether there are exceptions in the JS code, and optimize error handling.                                                                                   | Yes             | Yes. For details, see [JsError](./jscrash-guidelines.md).        |
    | CppCrash                           | Native layer program crash.                                                  | Check whether there are exceptions in the native code, and optimize error handling.                                                                               | Yes             | Yes. For details, see [CppCrash](./cppcrash-guidelines.md).        |
    | RSPixelMapFdOverLimit              | The app's use of PixelMap image resources exceeds the limit, causing an FD leak in the render service.                      | Attempt to reduce the frequency of using PixelMap image resources in the app.                                                                                       | Yes             | No        |
    | CPUHighloadNotify                  | The app has a high CPU load in the background, a dialog box appears, and the user chooses to stop the app.                                    | Attempt to reduce the app's own CPU load.                                                                                        | No             | No        |
    | CPUHighloadUserRequest             | The app has a high CPU load in the background, and the user chooses to stop the app from the Settings screen.                                     | Attempt to reduce the app's own CPU load.                                                                                        | No             | No        |
    | IllegalAudioCapturerBySuspend      | The app's audio recording does not request a proper background task, and recording continues after the app moves to the background.           | When the app moves to the background, avoid unnecessary background recording, or use background tasks properly.                                                                        | Yes             | No        |
    | IOHighload                         | High I/O load.                                                        | Attempt to reduce the app's own I/O operations.                                                                                        | No             | No        |
    | AppFreeze                          | The app freezes and becomes unresponsive.                                                      | Subscribe to the APP_FREEZE event through HiAppEvent and match against the APP_FREEZE event.                                                        | Yes             | Yes. For details, see [AppFreeze](./appfreeze-guidelines.md).        |
    | MaliciousContinuousTaskActive      | Malicious continuous task is active.                                                     | Check whether there are malicious continuous tasks in the app, and optimize task scheduling.                                                                                 | Yes             | No        |
    | RsDataOverflow                     | RS data overflow.                                                       | Attempt to reduce the app's RS data usage.                                                                                         | No             | No        |
    | HighTemperature                    | Temperature limit exceeded.                                                         | Attempt to reduce the app's own CPU load to reduce heat generation.                                                                                   | No             | No        |
    | TransientTaskTimeout               | The transient task times out after 6 seconds and the app is in the background.                                               | Check whether there are time-consuming operations in the transient task, and optimize the task execution efficiency.                                                                               | Yes             | No        |
    | TooManyReadyThreads                | Too many ready threads in a single process.                                                       | Attempt to reduce the number of threads created by the app, and optimize thread management.                                                                                  | Yes             | No        |
    | JsHeapSleepCleanKill               | JS heap size is checked during sleep state (overnight charging), and the app is terminated if the limit is exceeded.                     | Categorized as device-wide background memory cleanup. Attempt to optimize the JS heap usage.                                                                                         | No             | No        |
    | HardwareDecodingResourcesLimit     | Hardware decoding resource limit.                                                     | Attempt to reduce the app's use of hardware decoding resources.                                                                                      | No             | No        |
    | AppRecoveryNotifyAppOverLimit      | App recovery notification indicates the app has exceeded the limit.                                                   | Check whether there are exceptions in the app recovery mechanism, and optimize the recovery logic.                                                                                 | Yes             | No        |
    | GpuError                           | GPU error.                                                        | Check whether the app's GPU usage is reasonable, and optimize GPU resource management.                                                                               | Yes             | No        |
    | NotAttachedToStatusBar             | Not attached to the status bar.                                                      | Check whether the app's status bar attachment logic is correct.                                                                                       | Yes             | No        |
    | CPUHighload                        | The app has a high CPU load in the background, and the system automatically terminates the app.                                            | Attempt to reduce the app's own CPU load.                                                                                        | No             | No        |
    | AshmemKiller                       | Low device memory, and the ASHMEM memory of a single process exceeds the limit.                                     | Attempt to reduce the app's own ashmem memory usage. Attempt to obtain more ashmem memory overrun logs by subscribing to RESOURCE_OVERLIMIT through HiAppEvent.                                                               | Yes             | Yes        |
    | GpuKiller                          | Low device memory, and the GPU usage of a single process reaches the threshold.                                        | Attempt to reduce the app's own GPU memory usage. Attempt to obtain more logs of single-process GPU usage reaching the threshold by subscribing to RESOURCE_OVERLIMIT through HiAppEvent.                                                           | Yes             | Yes        |
    | DmaKiller                          | Low device memory, and the DMA usage of a single process reaches the threshold.                             | Attempt to reduce the app's own DMA memory usage. Attempt to obtain more logs of DMA usage reaching the threshold by subscribing to RESOURCE_OVERLIMIT through HiAppEvent.                        | Yes             | Yes        |
    | ThreadKiller                       | Thread limit exceeded for a single process.                                                         | Attempt to reduce the number of threads created by the app, and optimize thread management.                                                                                  | Yes             | Yes        |
    | UninstallStorage                   | Storage card uninstalled.                                                        | No handling required.                                                                                                  | No             | No        |