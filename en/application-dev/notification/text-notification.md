# Publishing a Text Notification

You can publish text notifications to send SMS messages, alert messages, and more. There are two types of text notifications: normal text and multi-line text.

**Table 1** Basic notification content types

| Type                            | Description         |
| ------------------------------- | ------------- |
| NOTIFICATION_CONTENT_BASIC_TEXT | Normal text notification.|
| NOTIFICATION_CONTENT_MULTILINE  | Multi-line text notification.|

## Available APIs

The following table describes the APIs for notification publishing. You specify the notification information – content, ID, slot type, and publish time – by setting the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest) parameter in the APIs.

| Name| Description|
| -------- | -------- |
| publish(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Publishes a notification.                |


## How to Develop

1. Import the module.
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Create a **NotificationRequest** object and publish a progress notification.
   - A normal text notification consists of the **title**, **text**, and **additionalText** fields. For details, see [NotificationBasicContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent.md#notificationbasiccontent).
     
      ```ts
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT, // Basic notification
          normal: {
            title: 'test_title',
            text: 'test_text',
            additionalText: 'test_additionalText',
          }
        }
      };
      notificationManager.publish(notificationRequest, (err: BusinessError) => {
        if (err) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in publishing notification.');
      });
      ```


   - In addition to the fields in the normal text notification, the multi-line text notification provides the **lines**, **briefText**, and **longTitle** fields. For details, see [NotificationMultiLineContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent.md#notificationmultilinecontent).
     
      ```ts
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 3,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_MULTILINE, // Multi-line text notification
          multiLine: {
            title: 'test_title',
            text: 'test_text',
            briefText: 'test_briefText',
            longTitle: 'test_longTitle',
            lines: ['line_01', 'line_02', 'line_03'],
          }
        }
      };
      // Publish the notification.
      notificationManager.publish(notificationRequest, (err: BusinessError) => {
        if (err) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in publishing notification.');
      });
      ```
