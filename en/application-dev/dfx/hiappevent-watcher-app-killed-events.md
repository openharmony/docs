# Application Killed Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=bbc8406212c76d396fc2036d1d8fe953b6305789 translatedAt=2026-08-15T01:46:36.757Z pushedAt=2026-08-15T07:13:09.409Z -->

## Overview

Since API version 20, HiAppEvent provides APIs for subscribing to application killed events.

The killed event refers to a phenomenon that an application is forced to exit by the system. Unlike an application crash, an application killed event is triggered not by an exception in the application's own code, but by the system's resource-management policy.

HiAppEvent APIs for subscribing to application killed events:

- [Subscribing to Application Killed Events (ArkTS)](hiappevent-watcher-app-killed-events-arkts.md)

- [Subscribing to Application Killed Events (C/C++)](hiappevent-watcher-app-killed-events-ndk.md)

> **NOTE**
>
> Application killed events can be subscribed to using HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone) and atomic services. Since API version 22, application killed events can be subscribed to using HiAppEvent in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide).

The **params** attribute in the application killed event is described as follows.

## Field Description

### params

The **params** attribute in the application killed event is described as follows.

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| reason  | string | Killed reason. For details, see [reason](#reason).|
| foreground | boolean | Whether the application is in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| app_running_unique_id | string | Unique ID associated with the app runtime.<br>**Note**: This parameter is supported since API version 24. |
| bundle_version | string | App version information.<br>**Note**: This parameter is supported since API version 24. |
| last_exit_detail_info | string | Detailed information before the app exits. For details, see [last_exit_detail_info](#last_exit_detail_info).<br>**Note:** This parameter is supported since API version 26.0.0. |

### reason

| Type  | Description                      |
| ------- | ------------------------- |
| LowMemoryKill                 | The system memory is low, and apps are terminated in ascending order of priority.        |
| SwapFull                      | The swap space is nearly full.                    |
| ResourceLeak(IonLeak)         | The Ion memory occupied by the app exceeds the limit.                   |
| ResourceLeak(GpuRsLeak)       | The GPU memory occupied by the app's ArkUI components in the Render Service process exceeds the limit. |
| ResourceLeak(GpuLeak)         | The GPU memory occupied by the app in its own process exceeds the limit.                    |
| ResourceLeak(AshmemLeak)      | The Ashmem memory occupied by the app exceeds the limit.                 |
| ResourceLeak(CES)             | The CES registration exceeds the limit.                        |
| ResourceLeak(PSSSoftLeak)     | The memory usage of the background app exceeds twice the detection threshold, with PSS memory accounting for the highest proportion.   |
| ResourceLeak(PSSLeak)         | The memory usage of the background app exceeds a specific threshold, with PSS memory accounting for the highest proportion.     |
| ResourceLeak(VMALeak)         | A VMA leak occurs.                          |
| ResourceLeak(FDLeak)          | An FD leak occurs.                           |
| ResourceLeak(ThreadLeak)      | A thread leak occurs.                          |
| ResourceLeak(KernelZoneLeak)  | A page table memory leak occurs.                  |
| IllegalAudioRendererBySuspend | The app's audio playback does not request a proper background task, and a large amount of audio playback continues after the app moves to the background.       |
| PowerSaveClean | The device is switched to the power saving mode or emergency mode.|
| VrsKill                       | A third-party app detects a malicious process and calls the PC-side virus detection and handling service API to terminate the process.                |
| RssThresholdKiller            | The RSS (Resident Set Size) usage of the app exceeds the limit.  |
| OomKiller                     | The system low memory triggers kernel control, which terminates apps based on a certain policy.                  |
| CpaKiller                     | When DRM (Digital Rights Management) services request memory but the memory is insufficient, processes are terminated based on a certain policy to reclaim memory.        |
| KillApplication               | The app exits actively.                         |
| OnRemoteDied                  | The remote service dies.                          |
| Restart                       | The app restarts.                           |
| UserRequest                   | The user swipes up or clears the app from the recent tasks screen.                      |
| Uninstall                     | The app exits due to uninstallation.                         |
| Upgrade                       | The app exits due to an update.                         |
| Logout                        | The app sandbox is uninstalled when the user logs out.                   |
| PermissionUpdate              | The app permissions are updated.                          |
| aaForceStop                   | The app is forcibly stopped using the aa command.                    |
| ThreadBlock6S                 | The main thread of the app is frozen and times out.                       |
| AppInputBlock                 | The user input response times out.                        |
| LifecycleTimeout              | The app lifecycle times out.                        |
| JsError                       | A crash occurs at the JS layer.                        |
| CppCrash                      | A crash occurs at the native layer.                    |
| RSPixelMapFdOverLimit         | The app uses excessive PixelMap resources, causing an FD leak in the Render Service.        |
| CPUHighloadNotify             | The app has a high CPU load in the background, a dialog box appears, and the user chooses to stop the app.        |
| CPUHighloadUserRequest        | The app has a high CPU load in the background, and the user chooses to stop the app in the Settings screen.        |
| IllegalAudioCapturerBySuspend | The app's audio recording does not request a proper background task, and recording continues after the app moves to the background.        |
| IOHighload                    | The IO load is high.                          |
| AppFreeze                     | The app freezes and becomes unresponsive.                        |
| MaliciousContinuousTaskActive | A malicious continuous task is active.                        |
| RsDataOverflow                | RS data overflows.                          |
| HighTemperature               | The temperature exceeds the limit.                           |
| TransientTaskTimeout          | The transient task times out after 6 seconds and is in the background.                 |
| TooManyReadyThreads           | There are too many ready threads.                          |
| JsHeapSleepCleanKill          | In the sleep state (charging at night), a JS heap size check is performed, and the app is terminated if the limit is exceeded.              |
| HardwareDecodingResourcesLimit | The hardware decoding resources are limited.                        |
| AppRecoveryNotifyAppOverLimit | The app recovery notification exceeds the limit.                      |
| GpuError                      | A GPU error occurs.                           |
| NotAttachedToStatusBar        | The app is not attached to the status bar.                         |
| CPUHighload                   | The app has a high CPU load in the background, and the system automatically terminates the app.              |
| AshmemKiller                  | The system memory is low, and the ASHMEM memory of a single process exceeds the limit.                       |
| GpuKiller                     | The system memory is low, and the GPU usage of a single process reaches the threshold.                      |
| DmaKiller                     | The system memory is low, and the DMA usage of a single process reaches the threshold.                      |
| ThreadKiller                  | The threads of a single process exceed the limit.                           |
| UninstallStorage              | The storage card is uninstalled.                          |

### last_exit_detail_info

| Name | Type | Description |
| -------- | -------- | -------- |
| exit_msg | string | App exit information. |
| kill_reason | string | Reason for the app exit. |
| pid | string | App process ID. |
| process_name | string | App process name. |
| process_state | string | App process state. |
| pss | string | Physical memory actually used by the process, in KB. |
| rss | string | Memory actually occupied by the process, in KB. |
| timestamp | string | Timestamp when the fault occurred. |
| uid | string | App user ID. |