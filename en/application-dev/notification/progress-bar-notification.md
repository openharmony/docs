# Publishing a Progress Notification


The progress notification is a commonly used notification type, mainly used to display the progress of an ongoing operation, such as file downloading. When publishing a progress notification through the notification subsystem, you can use the readily available template by specifying the related attributes, such as the template name and template data.

In the [NotificationTemplate](../reference/apis/js-apis-inner-notification-notificationTemplate.md), which can only be of the progress type, **data** indicates custom template data.

**Figure 1** Example of a progress notification

![en-us_image_0000001416903138](figures/en-us_image_0000001416903138.png)

## Available APIs

 

| Name| Description|
| -------- | -------- |
| isSupportTemplate(templateName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether a specific template is supported. This API uses an asynchronous callback to return the result. For details, see [isSupportTemplate()](../reference/apis/js-apis-notificationManager.md#notificationmanagerissupporttemplate).<br>Only the progress-type template is supported.|


## How to Develop

1. [Enable notification](notification-enable.md). An application can use the notification feature only after being authorized by the user.

2. Import the module.
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   import { logger } from '../util/Logger';
   ```

3. Check whether a specific template is supported. In this example, the template of the **downloadTemplate** type is checked.
   
   ```ts
   notificationManager.isSupportTemplate('downloadTemplate').then((data:boolean) => {
     logger.info(`[ANS] isSupportTemplate success`);
     logger.info('Succeeded in supporting download template notification.');
     let isSupportTpl: boolean = data; // The value true means that the template of the downloadTemplate type is supported, and false means the opposite.
   }).catch((err:Base.BusinessError) => {
     logger.error(`Failed to support download template notification. Code is ${err.code}, message is ${err.message}`);
   });
   ```
   
   > **NOTE**
   >
   > Proceed with the step below only when the specified template is supported.
   
4. Create a **NotificationRequest** object and publish a progress notification.
   
   ```ts
   let notificationRequest: notificationManager.NotificationRequest = {
     id: 5,
     content: {
       notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
       normal: {
         title: 'test_title',
         text: 'test_text',
         additionalText: 'test_additionalText'
       }
     },
     // Create a progress template. The name field has a fixed value of downloadTemplate.
     template: {
       name: 'downloadTemplate',
       data: { title: 'File Title', fileName: 'music.mp4', progressValue: 45 }
     }
   }
   
   // Publish the notification.
   notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
     if (err) {
       logger.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     logger.info('Succeeded in publishing notification.');
   });
   ```
