# Publishing a Live View Notification (for System Applications Only)

Live view notifications enable users to get the latest updates of tasks in real time. Based on the implementation mechanism and usage scenario, there are two types of live view notifications:

- System live view: displays the real-time progress of continuous tasks such as voice recording, screen recording, audio and video playback, timing, and calling. Such type of notification is not stored persistently, and its lifecycle is consistent with that of the notification publisher.

- Common live view: displays the real-time progress of lifestyle services, such as takeout, taxi hailing, flight, and sports events, as well as continuous tasks. Such type of notification has a lifecycle. If the notification is not updated within 4 hours or has been retained for 8 hours, it is automatically deleted. You can customize the notification retention period (how long the notification will be retained in the notification panel). A common live view notification is stored persistently once it is created or updated. After the device is powered on or restarted, the notification in the created or updated state can be restored.

**Table 1** Types of live view notifications

| Type                                                  | Value| Description               |
| ------------------------------------------------------ | --- | ------------------ |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5  | Live view notification.   |
| NOTIFICATION_CONTENT_LIVE_VIEW<sup>11+</sup>           | 6  | Common live view notification.|
## Available APIs

The following table describes the APIs for notification publishing. You can specify the notification information – content, ID, slot type, and delivery time – by setting the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest) parameter in the APIs.  

| **API**| **Description**|
| -------- | -------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish)(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Publishes a notification.                |
| [cancel](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagercancel)(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Cancels a specified notification.     |


## How to Develop

1. Import the modules.
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. Publishes a notification.

   - In addition to the parameters in the normal text notification, the system live view notification provides the **typeCode**, **capsule**, **button**, **time**, and **progress** parameters. For details, see [NotificationSystemLiveViewContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent).
     
      ```ts
      import image from '@ohos.multimedia.image';

      let imagePixelMap: image.PixelMap | undefined = undefined; // Obtain the image pixel map information.
      let color = new ArrayBuffer(4);
      image.createPixelMap(color, {
        size: {
          height: 1,
          width: 1
        }
      }).then((data: image.PixelMap) => {
        imagePixelMap = data;
      }).catch((err: Base.BusinessError) => {
        console.log(`createPixelMap failed, error: ${err}`);
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
        let publishCallback = (err: Base.BusinessError): void => {
          if (err) {
            console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
          } else {
            console.info("publish success");
          }
        };
        // Button callback (It is returned when the button is touched. You can determine how to process the callback.)
        let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
          console.info("response callback: " + JSON.stringify(option) + "notificationId" + id);
        }
        let systemLiveViewSubscriber: notificationManager.SystemLiveViewSubscriber  = {
          onResponse: onResponseCallback
        };
        // Subscribe to the system live view notification (button).
        notificationManager.subscribeSystemLiveView(systemLiveViewSubscriber);
        // Publish the notification.
        notificationManager.publish(notificationRequest, publishCallback);
      }
      ```

   - In addition to the parameters in the normal text notification, the common live view provides the **status**, **version**, **extraInfo**, and **pictureInfo** parameters. For details, see [NotificationLiveViewContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent-sys.md#notificationliveviewcontent11).

      ```ts
      import wantAgent from '@ohos.app.ability.wantAgent';
      import { WantAgent } from '@ohos.app.ability.wantAgent';

      let wantAgentObj: WantAgent;
      let wantAgentInfo: wantAgent.WantAgentInfo = {
        wants: [
          {
            deviceId: '',
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            action: '',
            entities: [],
            uri: '',
            parameters: {}
          }
        ],
        operationType: wantAgent.OperationType.START_ABILITY,
        requestCode: 0,
        wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG]
      }
      // Create a WantAgent object.
      wantAgent.getWantAgent(wantAgentInfo, (err:Base.BusinessError, data:WantAgent) => {
        if (err) {
          console.error(`Failed to get want agent. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in getting want agent.');
        wantAgentObj = data;

        let notificationRequest: notificationManager.NotificationRequest = {
          id: 1,
          content: {
            notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
            liveView: {
              title: "title",
              text: "text",
              status: 0,
              version: 1,
              extraInfo: {
                "event": "TAXI",
                "isMute": false,
                "primaryData.title": "primary title",
                "primaryData.content": [{ text: "text1", textColor: "#FFFFFFFF"}, { text: "text2", textColor: "#FFFFFFFF"}],
                "primaryData.keepTime": 60,
                "primaryData.extend.text": "extendData text",
                "primaryData.extend.type": 1,
                "PickupLayout.layoutType": 4,
                "PickupLayout.title": "layout title",
                "PickupLayout.content": "layout content",
                "PickupLayout.underlineColor": "#FFFFFFFF",
                "CapsuleData.status": 1,
                "CapsuleData.type": 1,
                "CapsuleData.backgroundColor": "#FFFFFFFF",
                "CapsuleData.title": "capsule title",
                "CapsuleData.content": "capsule content",
                "TimerCapsule.content": "capsule title",
                "TimerCapsule.initialtime": 7349485944,
                "TimerCapsule.isCountdown": false,
                "TimerCapsule.isPause": true
              },
            },
          },
          notificationSlotType: notificationManager.SlotType.LIVE_VIEW,
          isOngoing: true,
          isUnremovable: false,
          autoDeletedTime: 500,
          wantAgent: wantAgentObj,
          extraInfo: {
            'testKey': 'testValue'
          },
        }
        notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
          if (err) {
            console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
            return;
          }
          console.info('Succeeded in publishing notification.');
        });
      });
      ```
