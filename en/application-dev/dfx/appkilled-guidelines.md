# Application Killed Detection

## Overview

An application crash refers to the unexpected exit of the application during use. When an application behaves abnormally, for example, consuming excessive system resources such as CPU and memory, the system kills the application based on rules to maintain its health status. Typically, the system kills the application by sending the **SIGKILL** signal (the signal value is **9**) to the application through the service process. By default, the OS does not generate maintenance and debugging information such as stack logs for the **SIGKILL** behavior. As a result, no log is generated in the faultLogger when the application crashes.

## Basic Concepts

An application exits in the following scenarios:

1. When an application is abnormal or throws an exception, for example, the **CPP_CRASH** exception triggered by **SIGSEGV** or **SIGABRT**, the system monitors the exception and record maintenance and debugging logs.

2. When a user manually terminates an application, for example, by clicking the clear button in the task list to clear all applications or swiping up to clear an application, no stack or other maintenance and debugging logs are generated.

3. When **exit** is called, maintenance and debugging logs such as stack logs are not generated.

4. When the application main thread is blocked, the UI freezes and the **APP_FREEZE** log is generated.

5. When resources are overused, the system kills the process and provides detailed maintenance and debugging information. For example, when memory leaks occur in an application, the corresponding maintenance and debugging logs are generated. You can subscribe to **RESOURCE_OVERLIMIT** through **HiAppEvent** to obtain the information.

6. When the system kills the process under conditions such as **LowMemoryKiller**, RSS exceeding 4 GB, or rapid memory leaks, it produces no detailed maintenance or debugging information—specifically, no **RESOURCE_OVERLIMIT** log is generated.

This topic describes the killing caused by the **SIGKILL** signal in scenarios 5 and 6.

## Implementation Principles

1. Both the kernel and service processes monitor system resources.

2. If an exception is detected, the application is killed.

3. The system adds system event logging when triggering application killing.

4. The logging information includes the UID, bundle name, foreground and background information, killing reason, and maintenance and debugging information.

## Constraints

1. The application needs to subscribe to the killing event through HiAppEvent.

2. The killing event is asynchronously released to the application. The application can receive the event only when it is started next time.

3. The killing behavior of the system is subject to versions. Therefore, the current killing mechanism may be incomplete.

## Triggering Scenario

The system may kill applications in the following scenarios:

1. The memory, CPU, and I/O load of the application exceeds the specified limit, and the number of file handles and threads exceeds the threshold.

2. When the device memory is low, applications are killed based on the memory usage and priority.

3. Power-consuming scenarios include frequent wake-ups caused by Binder calls, system freezes during audio playback or recording, and abnormal use of peripherals such as GPS or Bluetooth.

## Detection Methods

Applications can detect abnormal killing in either of the following ways:

1. Obtain the killing reason from the **onCreate** callback parameter of the ability. Specifically, set the **LastExitReason** parameter in **LaunchParam**. For details, see [LastExitReason](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md).

2. Subscribe to the **APP_KILLED** event through HiAppEvent. For details, see [HiAppEvent](hiappevent-watcher-app-killed-events.md).

## Analysis Method and Procedure

1. Obtain the killing reason from the **onCreate** callback parameter of the ability.

    For details, see the following table.

    | lastExitReason(enum) | lastExitMessage(string)  | Causes                                            | Handling Policy                                                    |
    | -------------------- | ------------------------ | ---------------------------------------------------- | ------------------------------------------------------------ |
    | APP_FREEZE           | APP_FREEZE               | The application exits because watchdog detects that the application is frozen.| Subscribe to the **APP_FREEZE** event through HiAppEvent and match its fault types.|
    | RESOURCE_CONTROL     | CPU Highload             | The CPU load is high.                                         | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | CPU_EXT Highload         | Fast CPU load detection.                                   | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | IO Manager Control       | I/O manager control.                                           | Reduce the I/O of the application.                                     |
    | RESOURCE_CONTROL     | App Memory Deterioration | The application memory usage exceeds the threshold.                                  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more logs.      |
    | RESOURCE_CONTROL     | Temperature Control      | Temperature control.                                          | Reduce the CPU load of the application.                                 |
    | RESOURCE_CONTROL     | Memory Pressure          | The system memory is low, triggering application killing in ascending order of priority.                | Reduce the memory usage of the application.|

2. Subscribe to the **APP_KILLED** event through HiAppEvent.

    Based on the **APP_KILLED** event, you can obtain key information such as the killing cause and application foreground and background. Perform operations based on the following table.

    | reason(string)                | Causes                                                    | Handling Policy                                                    | Whether Control Is Triggered by Application Exceptions| Whether There Are Associated Events|
    | ----------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------ | -------------- |
    | LowMemoryKill                 | The system memory is low, triggering application killing in ascending order of priority.| Reduce the memory usage of the application.| No                      | No            |
    | SwapFull                      | The swap space is almost used up, which may be caused by memory leaks of some processes or too many background processes.| Reduce the memory usage of the application.| No                      | No            |
    | ResourceLeak(IonLeak)         | The ION memory used by the application exceeds the threshold.                                     | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more ION memory logs. After finding the leak point, reduce the ION memory usage of the application. Generally, the leak is caused by the **Image** component or pixmap.| Yes                      | Yes            |
    | ResourceLeak(GpuRsLeak)       | The GPU memory used by the ArkUI component of the application in the **render_service** process exceeds the threshold.  | Reduce the GPU memory usage of the ArkUI component of the application.                        | Yes                      | No            |
    | ResourceLeak(GpuLeak)         | The GPU memory used by the application in the process (that is, the GPU memory generated by self-rendering) exceeds the threshold.  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more GPU memory logs, find the leak point, and reduce the GPU memory usage of the application self-rendering (using the **XComponent** component).| Yes                      | Yes            |
    | ResourceLeak(AshmemLeak)      | The ashmem memory used by the application exceeds the threshold.                                  | Subscribe to **RESOURCE_OVERLIMIT** through HiAppEvent to obtain more ashmem memory logs. After finding the leak point, reduce the ashmem memory usage of the application. Generally, the leak is caused by the **Image** component or pixmap.| Yes                      | Yes            |
    | IllegalAudioRendererBySuspend | No proper background task is applied, but a large amount of audio is played in the background.              | When the application is switched to the background, unnecessary background audio playback should be avoided or the background task should be properly used. For details, see [Background Tasks Kit](../task-management/background-task-overview.md).| Yes                      | No            |
    | PowerSaveClean                | The device is switched to the power saving mode or emergency mode.                              | No operation is required.                                                  | No                      | No            |
    | RssThresholdKiller            | The RSS memory of the application exceeds the threshold.                                   | Reduce the RSS memory usage of the application. | Yes                      | No            |
    | OomKiller                     | The device memory is low, which triggers the kernel to kill applications based on certain policies.                | Reduce the memory usage of the application.| No                      | No            |
    | CpaKiller                     | When the Digital Right Management (DRM) service applies for memory but the memory is insufficient, the system kills processes based on certain policies to reclaim the memory.| Reduce the memory usage of the application.| No                      | No            |
