# Canceling a Notification

When a user taps a notification and starts the application in the foreground, the application can cancel one or all notifications.

For example, after a user receives an IM from a friend and taps a notification to view the message, the application can cancel the notification.

## Available APIs

The table below lists some APIs for canceling notifications. For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

| **API**| **Description**|
| -------- | -------- |
| cancel(id:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels a notification.          |
| cancelAll(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels all notifications published by the application.|


## How to Develop

The following describes how to cancel a text notification. This procedure is applicable for canceling other types of notifications.

1. Import modules.
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Publish a notification.

   For details, see [Publishing a Text Notification](./text-notification.md).

3. Cancel the notification.

   ```ts
    // After the application is started in the foreground and the message is viewed, call this API to cancel the notification.
    notificationManager.cancel(1, (err: BusinessError) => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `Failed to cancel notification. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in canceling notification.');
    });
   ```
