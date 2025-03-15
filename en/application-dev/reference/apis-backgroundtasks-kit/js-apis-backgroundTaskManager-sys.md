# @ohos.backgroundTaskManager (Background Task Management) (System API)

The **BackgroundTaskManager** module provides APIs to manage background tasks.

If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task to delay the suspension or a continuous task to prevent the suspension.

If an application has a task that needs to be continued when the application is switched to the background and can be completed within a short period of time, the application can request a transient task. For example, if a user chooses to clear junk files in the **Files** application and exits the application, the application can request a transient task to complete the cleanup.

If an application has a service that can be intuitively perceived by users and needs to run in the background for a long period of time (for example, music playback in the background), the application can request a continuous task.

If a privileged system application needs to use certain system resources (for example, it wants to receive common events when suspended), it can request efficiency resources.

>  **NOTE**
>
> - This module is deprecated since API version 9. You are advised to use [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](js-apis-resourceschedule-backgroundTaskManager-sys.md).
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.backgroundTaskManager (Background Task Management)](js-apis-backgroundTaskManager.md).


## Modules to Import

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```

## BackgroundMode<sup>8+</sup>

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| WIFI_INTERACTION        | 7    | WLAN-related.<br>This is a system API.|
| VOIP                    | 8    | Audio and video calls.<br>This is a system API. |
