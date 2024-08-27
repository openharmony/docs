# Publishing a Live View Notification (for System Applications Only)

The live view notification provides real-time progress of long-duration tasks, including voice recording, screen recording, audio and video playback, timing, and phone call. Such type of notification is not stored persistently, and its lifecycle is consistent with that of the notification publisher.

**Table 1** Types of live view notifications

| Type                                                  | Value| Description               |
| ------------------------------------------------------ | --- | ------------------ |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5  | Live view notification.   |

## Available APIs

The following table describes the APIs for notification publishing. You can specify the notification information – content, ID, slot type, and delivery time – by setting the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest) parameter in the APIs.  

| **API**| **Description**|
| -------- | -------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish)(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Publishes a notification.                |
| [cancel](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagercancel)(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels a specified notification.     |


## How to Develop

1. Import the modules.
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { image } from '@kit.ImageKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Publishes a notification.

   In addition to the parameters in the normal text notification, the system live view notification provides the **typeCode**, **capsule**, **button**, **time**, and **progress** parameters. For details, see [NotificationSystemLiveViewContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent).
     
      ```ts
      let imagePixelMap: image.PixelMap | undefined = undefined; // Obtain the image pixel map information.
      let color = new ArrayBuffer(4);
      imagePixelMap = await image.createPixelMap(color, {
        size: {
          height: 1,
          width: 1
        }
      })
      if(imagePixelMap !== undefined) {
        let notificationRequest: notificationManager.NotificationRequest = {
          notificationSlotType: notificationManager.SlotType.LIVE_VIEW, // Live view
          id: 0, // Notification ID. The default value is 0.
          content: {
            notificationContentType : notificationManager.ContentType.NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW,
            systemLiveView: {
              title: "test_title",
              text:"test_text",
              typeCode: 1, // Type of the invoking service.
              // Button
              button: {
                names: ["buttonName1"],
                icons: [imagePixelMap],
              },
              // Capsule
              capsule: {
                title: "testTitle",
                icon: imagePixelMap,
                backgroundColor: "testColor",
              },
              // Progress. To update the progress, you only need to modify the progress value and publish the notification again.
              progress: {
                maxValue: 100,
                currentValue: 21,
                isPercentage: false,
              },
              // Time
              time: {
                initialTime: 12,
                isCountDown: true,
                isPaused: true,
                isInTitle: false,
              }
            }
          }
        };
        // publish callback
        let publishCallback = (err: BusinessError): void => {
          if (err) {
            hilog.error(DOMAIN_NUMBER, TAG, `publish failed, code is ${err.code}, message is ${err.message}`);
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, `publish success`);
          }
        };
        // Button callback (It is returned when the button is touched. You can determine how to process the callback.)
        let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
          hilog.info(DOMAIN_NUMBER, TAG, `response callback: ` + JSON.stringify(option) + `notificationId` + id);
        }
        let systemLiveViewSubscriber: notificationManager.SystemLiveViewSubscriber  = {
          onResponse: onResponseCallback
        };
        // Subscribe to the system live view notification (button).
        await notificationManager.subscribeSystemLiveView(systemLiveViewSubscriber);
        // Publish the notification.
        notificationManager.publish(notificationRequest, publishCallback);
      }
      ```
