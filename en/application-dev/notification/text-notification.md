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
| cancel(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels a notification.          |
| cancelAll(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | Cancels all notifications published by the application.|


## How to Develop

1. Import the module.
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. Create a **NotificationRequest** object and publish a progress notification.
   - A normal text notification consists of the **title**, **text**, and **additionalText** parameters, of which **title** and **text** are mandatory. The value of these parameters contains less than 200 bytes.
     
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
      notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
        if (err) {
          console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in publishing notification.');
      });
      ```


   - In addition to the parameters in the normal text notification, the multi-line text notification provides the **lines**, **briefText**, and **longTitle** parameters. The value of these parameters contains less than 200 bytes. By default, a multi-line notification looks in the same way as a normal text notification. When expanded, the notification displays the title and content specified in **longTitle** and **lines**, respectively.
     
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
            lines: ['line_01', 'line_02', 'line_03', 'line_04'],
          }
        }
      };
      // Publish the notification.
      notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
        if (err) {
          console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in publishing notification.');
      });
      ```
3. Delete the notification.

   ```ts
    notificationManager.cancel(1, (err:Base.BusinessError) => {
      if (err) {
        console.error(`Failed to cancel notification. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('Succeeded in cancel notification.');
    });
   ```
