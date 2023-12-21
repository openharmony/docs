# 发布实况窗类型通知（仅对系统应用开放）

实况窗类型通知继承了普通文本类型的字段，包含了系统实况窗类型和普通实况窗类型。

 - 系统实况窗通知需要使用`subscribeSystemLiveView()`订阅按钮，用户点击按钮时，可自行决定业务实现。

 - 普通实况窗通知有生命周期的限制，该实况窗在4小时无更新或者距离创建时间8小时都会自动删除。并且支持重启恢复。

**表1** 基础类型通知中的内容分类

| 类型                                                   | 值 | 描述                |
| ------------------------------------------------------ | --- | ------------------ |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5  | 实况窗类型通知。    |
| NOTIFICATION_CONTENT_LIVE_VIEW<sup>11+</sup>           | 6  | 普通实况窗类型通知。|
## 接口说明

通知发布接口如下表所示，不同发布类型通知由[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)的字段携带不同的信息。比如发布渠道可以通过notificationSlotType选择相应的通知渠道进行提醒。

| **接口名** | **描述** |
| -------- | -------- |
| publish(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 发布通知。                 |
| cancel(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消指定的通知。      |


# 开发步骤

1. [使能通知开关](notification-enable.md)，获得用户授权后，才能使用通知功能。

2. 导入模块。
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

3. 发布通知 。

   - 系统实况窗类型通知继承了普通文本类型的字段，新增了类型标识符、胶囊、按钮、时间和进度，类型描述参考[NotificationSystemLiveViewContent](../reference/apis/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent)。
     
      ```ts
      import image from '@ohos.multimedia.image';
      import notificationSubscribe from '@ohos.notificationSubscribe';

      let imagePixelMap: image.PixelMap | undefined = undefined; // 需要获取图片PixelMap信息
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
          notificationSlotType: notificationManager.SlotType.LIVE_VIEW, // 实况窗类型
          id: 0, // 通知id，默认为0
          content: {
            notificationContentType : notificationManager.ContentType.NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW,
            systemLiveView: {
              title: "test_title",
              text:"test_text",
              typeCode: 1, // 调用方的类型
              // 按钮
              button: {
                names: ["buttonName1"],
                icons: [imagePixelMap],
              },
              // 胶囊
              capsule: {
                title: "testTitle",
                icon: imagePixelMap,
                backgroundColor: "testColor",
              },
              // 进度，更新进度时，只需修改progress，重复publish即可
              progress: {
                maxValue: 100,ss
                currentValue: 21,
                isPercentage: false,
              },
              // 时间
              time: {
                initialTime: 12,
                isCountDown: true,
                isPaused: true,
                isInTitle: false,
              }
            }
          }
        };
        // subscribe回调
        let subscribeCallback = (err: Base.BusinessError): void => {
          if (err) {
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
          } else {
            console.info("subscribe success");
          }
        };
        // publish回调
        let publishCallback = (err: Base.BusinessError): void => {
          if (err) {
            console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
          } else {
            console.info("publish success");
          }
        };
        // 按钮回调(用户点击按钮，会返回这个回调，业务自己决定如何处理)
        let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
          console.info("response callback: " + JSON.stringify(option) + "notificationId" + id);
        }
        let systemLiveViewSubscriber: notificationManager.SystemLiveViewSubscriber  = {
          onResponse: onResponseCallback
        };
        // subscriber取消通知回调
        let onCancelCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
          console.info("Cancel callback: " + JSON.stringify(data));
        }
        let notificationSubscriber: notificationSubscribe.NotificationSubscriber = {
          onCancel: onCancelCallback
        };
        let info: notificationSubscribe.NotificationSubscribeInfo = {
          bundleNames: ["bundleName1"],
          userId: 123
        };
        // 订阅通知
        notificationSubscribe.subscribe(notificationSubscriber, info, subscribeCallback);
        // 订阅系统实况窗(按钮)
        notificationManager.subscribeSystemLiveView(systemLiveViewSubscriber);
        // 发布通知
        notificationManager.publish(notificationRequest, publishCallback);
      }
      ```

   - 普通实况窗类型通知继承了普通文本类型的字段，新增了实况通知状态、实况通知版本号、通知附加内容和通知附加内容中的图片信息，类型描述参考[NotificationLiveViewContent](../reference/apis/js-apis-inner-notification-notificationContent.md#notificationliveviewcontent11)。

      ```ts
      import Want from '@ohos.app.ability.Want';
      import wantAgent, {WantAgent as _wantAgent} from '@ohos.app.ability.wantAgent';

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
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
          liveView: {
            status: notificationManager.LiveViewStatus.LIVE_VIEW_CREATE,
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
            }
          }
        },
        notificationSlotType: notificationManager.SlotType.LIVE_VIEW,
        isOngoing: true,
        isUnremovable: false,
        autoDeletedTime: 500,
        wantAgent: await WantAgent.getWantAgent(WantAgentInfo),
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
      ```
