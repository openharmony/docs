# Background Task Overview

On an OS that allows for user interaction, resources gravitate to service processes that interact with users. In other words, apart from processes that support system running, service processes that can be perceived by users have the highest priority. Therefore, background task management is applicable to service processes that cannot be perceived by users.


## Background Task Types

Background tasks described in this document refer to the services that need to be continued when the respective applications or service modules are running in the background (not visible to the users). For more targeted management of background applications and service modules, OpenHarmony classifies applications and service modules into the following types:

1. No background task: An application or service module does not need further processing when switched to the background.

2. Transient task: If an application or service module has an urgent, short task that must continue in the background until it is completed, such as data compression, the application or service module can request a transient task for delayed suspension.

3. Continuous task: If an application or service module has a user-initiated, perceivable task that needs to run in an extended period of time in the background, it can request a continuous task so that it will not be suspended. Examples of continuous tasks include music playback, navigation, upload and download, device connection, and VoIP.


## Transient Tasks

As mentioned above, applications and service modules with transient tasks have their suspension delayed so that their running is not affected by background lifecycle management within the specified time frame.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> Applications and service modules can request transient tasks only for temporary tasks. The time quota is 3 minutes per time and 10 minutes per day. The system allocates the time frame based on the application scenario and system status.


### Restrictions on Using Transient Tasks

Adhere to the following constraints and rules when using transient tasks:

- **When to request**: An application can request a transient task only when it is running in the foreground or before it is suspended in the background. Otherwise, the application may be suspended, resulting in request failure. By default, an application has 6–12 seconds of running time (subject to the application scenario) before it is suspended in the background.

- **Timeout**: The system notifies the application of the suspension delay timeout by using a callback. The application must then cancel the delayed suspension or apply for delayed suspension again. Otherwise, the application will be forcibly suspended.

- **When to cancel**: The requesting application shall cancel the request when the transient task is complete. If the request is forcibly canceled by the system, the time frame allowed for the application to run in the background will be affected.

- **Quota mechanism**: To prevent abuse of the keepalive, each application has a certain quota every day (dynamically adjusted based on user habits). After using up the quota, an application cannot request transient tasks. Therefore, applications should cancel their request immediately after the transient tasks are complete, to avoid quota consumption. (Note: The quota refers to the requested duration and does not include the time when the application runs in the background.)

## Continuous Tasks
Continuous tasks provide background running lifecycle support for services that can be directly perceived by users and need to run in the background. For example, if a service needs to play audio or continue with navigation and positioning in the background, which can be perceived by users, it can execute a continuous task in the respective background mode.

### Background Mode Classification
OpenHarmony provides 9 background modes for services that require continuous task execution.

**Table 1** Background modes for continuous tasks

| Background Mode| Description| Hint in Notification Panel| Remarks|
| -------- | -------- | -------- | -------- |
| dataTransfer | Data transfer through the network or peer device, such as upload, download, backup, and restore| A data transfer task is running.|  |
| audioPlayback | Audio output| An audio playback task is running.|  |
| audioRecording | Audio input| A recording task is running.|  |
| location | Positioning and navigation| A positioning task is running.|  |
| bluetoothInteraction | Bluetooth transmission| A Bluetooth-related task is running.|  |
| multiDeviceConnection | Distributed interconnection| A distributed task is running.|  |
| wifiInteraction | WLAN transmission| A WLAN-related task is running.| System API, which is available only to system applications|
| voip | Voice and video calls over VoIP| A call-related task is running.| System API, which is available only to system applications|
| taskKeeping | Computing task| A computing task is running| PC-specific, valid only on PCs|

### Restrictions on Using Continuous Tasks
- If a user triggers a perceivable task, such as broadcasting, navigation, upload, and download, the corresponding background mode is triggered. When the task is started, the system forcibly displays a notification to the user.
- If the task is complete, the application should exit the background mode. If the system detects that an application is not using the resources in the corresponding background mode when the application is running in the background, the application is suspended.
- Ensure that the requested continuous task background mode matches the application type. If the background mode does not match the application type, the system will suspend the task once it detects the issue.
- If a requested continuous task is not actually executed, the system will suspend the task once it detects the issue.
- Each ability can request only one continuous task at a time.
