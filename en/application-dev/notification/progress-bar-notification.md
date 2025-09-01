# Publishing a Progress Notification
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The progress notification is a commonly used notification type, mainly used to display the progress of an ongoing operation, such as file downloading. When publishing a progress notification through the notification subsystem, you can use the readily available template by specifying the related attributes, such as the template name and template data.

In the [NotificationTemplate](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-notification-kit/js-apis-inner-notification-notificationTemplate.md), which can only be of the progress type, **data** indicates custom template data.

## Available APIs

[isSupportTemplate()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerissupporttemplate) is used to check whether a specific template is supported. Currently, only the progress bar template is supported.

| Name| Description|
| -------- | -------- |
| isSupportTemplate(templateName: string): Promise\<boolean\> | Checks whether a specific template is supported.|


## How to Develop

1. Import the module.
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Check whether a specific template is supported. In this example, the template of the **downloadTemplate** type is checked.
   
   ```ts
   notificationManager.isSupportTemplate('downloadTemplate').then((data:boolean) => {
     let isSupportTpl: boolean = data; // The value true means that the template of the downloadTemplate type is supported, and false means the opposite.
     hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in supporting download template notification. data is ${isSupportTpl}`);
   }).catch((err: BusinessError) => {
     hilog.error(DOMAIN_NUMBER, TAG, `Failed to support download template notification. Code is ${err.code}, message is ${err.message}`);
   });
   ```
   
   > **NOTE**
   > Proceed with the step below only when the specified template is supported.
   
3. Create a **NotificationRequest** object and publish a progress notification.
   
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
   notificationManager.publish(notificationRequest, (err: BusinessError) => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG, `Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in publishing notification.');
   });
   ```
