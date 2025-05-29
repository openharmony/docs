# Notification Subsystem ChangeLog

## cl.notificationManager.1 Request Notification Enabling API Deprecated

**Access Level**

Public API

**Reason for Change**

    1. If malicious applications call pop-up windows in the background, security risks may exist.
    
    2. When this API is used to call a pop-up window, this window cannot follow the application window, resulting in poor UX.

**Change Impact**

This API is deprecated in the **notificationManager** module.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.31

**Deprecated APIs/Components**

|Original API|New API|
|-------|-------|
|requestEnableNotification(callback: AsyncCallback\<void\>): void|requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void\>): void|
|requestEnableNotification(): Promise\<void\>|requestEnableNotification(context: UIAbilityContext): Promise\<void\>|


**Adaptation Guide**

Use the new API **requestEnableNotification**, which has an input parameter **context**.

Code example before deprecation:

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Request notification pop-up window is unable to follow the application window.
notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
}).catch((err: BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```
Code example after deprecation:

```ts
import { notificationManager } from '@kit.NotificationKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';

let context = getContext(this) as common.UIAbilityContext;
// Request notification pop-up window passes in the UIAbilityContext parameter, enabling the pop-up window to follow the application window.
notificationManager.requestEnableNotification(context).then(() => {
    console.info("requestEnableNotification success");
}).catch((err: BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```
