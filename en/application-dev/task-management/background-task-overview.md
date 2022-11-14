# Background Task Management Overview

Frequent activities of background applications cause user devices to consume power quickly and respond slowly. To meet performance and power consumption requirements, the system allows applications to execute only activities within the specifications in the background. Activities beyond the specifications are suspended by default, and resources allocated to them will be reclaimed when the available resources are insufficient.


## Background Task Types

Background tasks described in this document refer to the services that need to be continued when the respective applications or service modules are running in the background (not visible to the users). For more targeted management of background applications and service modules, OpenHarmony classifies applications and service modules into the following types:

- **No background task**: An application or service module does not need further processing when switched to the background.

- **Transient task**: If an application or service module has an urgent, short task that must continue in the background until it is completed, such as data compression, the application or service module can request a transient task to delay the suspension.

- **Continuous task**: If an application or service module has a user-initiated, perceivable task that needs to run in an extended period of time in the background, it can request a continuous task so that it will not be suspended. Examples of continuous tasks include music playback, navigation, device connection, and VoIP.

- **Efficiency resources**: If an application needs to ensure that it will not be suspended within a period of time or can normally use certain system resources when it is suspended, it can request efficiency resources, including CPU, WORK_SCHEDULER, software, and hardware resources. Different types of efficiency resources come with different privileges. For example, the CPU resources enable an application or process to keep running without being suspended, and WORK_SCHEDULER resources allow for more task execution time before the application or process is suspended.


## Transient Tasks

As mentioned above, applications and service modules with transient tasks have their suspension delayed so that their running is not affected by background lifecycle management within the specified time frame.

> **NOTE**
>
> Applications and service modules can request transient tasks only for temporary tasks. The time quota is 3 minutes per time and 10 minutes per day. The system allocates the time frame based on the application scenario and system status.


### Restrictions on Using Transient Tasks

Adhere to the following constraints and rules when using transient tasks:

- **When to request**: An application can request a transient task only when it is running in the foreground or before it is suspended in the background. Otherwise, the application may be suspended, resulting in request failure. By default, an application has 6–12 seconds of running time (subject to the application scenario) before it is suspended in the background.

- **Timeout**: If a suspension delay is about to time out, the system notifies the application of the timeout by using a callback. The application must then cancel the delayed suspension. Otherwise, the application will be forcibly terminated.

- **When to cancel**: The application shall proactively cancel the request when the transient task is complete, rather than waiting for a system callback. Otherwise, the time frame allowed for the application to run in the background will be affected.

- **Quota mechanism**: To prevent abuse of the keepalive, each application has a certain quota every day (dynamically adjusted based on user habits). After using up the quota, an application cannot request transient tasks. Therefore, applications should cancel their request immediately after the transient tasks are complete, to avoid quota consumption. (Note: The quota refers to the requested duration and does not include the time when the application runs in the background.)

## Continuous Tasks
Continuous tasks provide background running lifecycle support for services that can be directly perceived by users and need to run in the background. For example, if a service needs to play audio or continue with navigation and positioning in the background, which can be perceived by users, it can execute a continuous task in the respective background mode.

### Background Mode Classification
OpenHarmony provides 9 background modes for services that require continuous task execution.

**Table 1** Background modes for continuous tasks

| Background Mode| Description| Hint in Notification Panel| Remarks|
| -------- | -------- | -------- | -------- |
| dataTransfer | Data transfer through the network or peer device, such as download, backup, share, and transfer| A data transfer task is running.| - |
| audioPlayback | Audio output| An audio playback task is running.| - |
| audioRecording | Audio input| A recording task is running.| - |
| location | Positioning and navigation| A positioning task is running.| - |
| bluetoothInteraction | Bluetooth transmission| A Bluetooth-related task is running.| - |
| multiDeviceConnection | Distributed interconnection| A distributed task is running.| - |
| wifiInteraction | WLAN transmission| A WLAN-related task is running.| System API, which is available only to system applications|
| voip | Voice and video calls over VoIP| A call-related task is running.| System API, which is available only to system applications|
| taskKeeping | Computing task| A computing task is running| Effective only for specific devices|

### Restrictions on Using Continuous Tasks
- If a user triggers a perceivable task, such as broadcasting and navigation, the corresponding background mode is triggered. When the task is started, the system forcibly displays a notification to the user.
- If the task is complete, the application should exit the background mode. If the system detects that an application is not using the resources in the corresponding background mode when the application is running in the background, the application is suspended.
- Ensure that the requested continuous task background mode matches the application type. If the background mode does not match the application type, the system will suspend the task once it detects the issue.
- If a requested continuous task is not actually executed, the system will suspend the task once it detects the issue.
- Each ability can request only one continuous task at a time.

## Efficiency Resources
Efficiency resources are classified into CPU, WORK_SCHEDULER, software, and hardware resources.
An application or process is assigned the privileges associated with the obtained efficiency resources. For example, with the CPU resources, the application or process will not be suspended. With the WORK_SCHEDULER resources, the application or process has more time to execute a task and is not restricted by the execution frequency. With the software and hardware resources, related resources are not proxied when the application or process is suspended.


**Table 2** Efficiency resource types

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| CPU                     | 1    | CPU resources, which prevent the application from being suspended.            |
| COMMON_EVENT            | 2    | A type of software resources, which prevent common events from being proxied when the application is suspended. |
| TIMER                   | 4    | A type of software resources, which prevent timers from being proxied when the application is suspended.   |
| WORK_SCHEDULER          | 8    | WORK_SCHEDULER resources, which ensure that the application has more time to execute the task.     |
| BLUETOOTH               | 16   | A type of hardware resources, which prevent Bluetooth resources from being proxied when the application is suspended. |
| GPS                     | 32   | A type of hardware resources, which prevent GPS resources from being proxied when the application is suspended. |
| AUDIO                   | 64   | A type of hardware resources, which prevent audio resources from being proxied when the application is suspended.|

### Restrictions on Using Efficiency Resources
- Applications or processes are responsible for requesting and releasing efficiency resources. A process can release the resources requested by itself, whereas an application can release the resources requested by both itself and its processes. For example, an application requests CPU resources, and its process requests CPU and WORK_SCHEDULER resources. If the application initiates CPU resource release, the CPU resources requested by the process are also released. However, the WORK_SCHEDULER resources are not released. If the process initiates CPU resource release, the CPU resources requested by the application are retained until being released by the application.
- If persistent resources and non-persistent resources of the same type are requested, the persistent resources overwrite the non-persistent resources and they will not be released upon a timeout. For example, if an application first requests 10-second CPU resources and then requests persistent CPU resources at the 5th second, the CPU resources become persistent and will not be released at the tenth second. If the application releases the CPU resources at the 8th second, both types of CPU resources are released.
- The WORK_SCHEDULER resources can be requested and released by applications, but not by processes.
