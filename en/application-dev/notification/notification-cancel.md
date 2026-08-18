# Canceling a Notification

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=a56d795a51f9068e61c2cc2726ea675f5d93d82a translatedAt=2026-08-13T03:10:43.733Z pushedAt=2026-08-13T07:29:34.029Z -->

When a user taps a notification to bring the application to the foreground, the application may cancel one, multiple, or all notifications.

When a user launches the application from the home screen icon and views in-app messages, the application may cancel the notifications associated with those messages.

Examples:

- Scenario 1: The user receives an instant message from a friend. After they tap the notification to open the application and view the message, the application cancels the corresponding notification.

- Scenario 2: The user receives an instant message from a friend. After they launch the application from the home screen icon and view the message, the application cancels the corresponding notification.

## Available APIs

The table below lists some APIs for canceling notifications. For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

| **API**| **Description**|
| -------- | -------- |
| cancel(id:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels a notification.          |
| cancelAll(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels all notifications published by the application.|

## How to Develop

The following describes how to cancel a text notification. This procedure is applicable for canceling other types of notifications.

1. Import modules.

   <!-- @[cancel_notification_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/CancelNotification.ets) -->

   ``` TypeScript
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Publish a notification.

   For details, see [Publishing a Text Notification](./text-notification.md).

3. Cancel the notification.

   <!-- @[cancel_notification_content](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/CancelNotification.ets) -->

   ``` TypeScript
   // After the application is started in the foreground and the message is viewed, call this API to cancel the notification.
   notificationManager.cancel(1, (err: BusinessError) => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG,
         `Failed to cancel notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in canceling notification.');
   });
   ```