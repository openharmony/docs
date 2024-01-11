# 发布实况窗类型通知（仅对系统应用开放）

实况窗类型的通知可以让用户实时感知当前任务的进度，按照实现机制和使用场景的不同，可以分为以下两种类型：

- 系统实况窗：主要用于展示录音、录屏、音视频播放、计时、通话等长时任务的实时进展。此类通知不会进行持久化存储，其生命周期与通知发布方的生命周期一致。

- 普通实况窗：不仅可以用于展示录音、录屏、音视频播放、计时、通话等长时任务的实时进展，还可用于展示外卖、打车、航班、赛事等实时进展。此类通知存在生命周期的限制，4小时内无更新或者创建8小时后也会自动删除，同时也支持设置通知留存期（即实况窗正常结束后在通知中心留存的时长）。在创建和更新通知时，会进行持久化存储，当设备开机重启后，支持恢复处于创建/更新状态的实况窗。

**表1** 基础类型通知中的内容分类

| 类型                                                   | 值 | 描述                |
| ------------------------------------------------------ | --- | ------------------ |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5  | 实况窗类型通知。    |
| NOTIFICATION_CONTENT_LIVE_VIEW<sup>11+</sup>           | 6  | 普通实况窗类型通知。|
## 接口说明

通知发布接口说明详见下表，通知发布的详情可通过入参[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)来进行指定。可以包括通知内容、通知ID、通知的通道类型和通知发送时间等信息。

| **接口名** | **描述** |
| -------- | -------- |
| [publish](../reference/apis/js-apis-notificationManager.md#notificationmanagerpublish)(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 发布通知。                 |
| [cancel](../reference/apis/js-apis-notificationManager.md#notificationmanagercancel)(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消指定的通知。      |


## 开发步骤

1. [请求通知授权](notification-enable.md)。获得用户授权后，才能使用通知功能。

2. 导入模块。
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

3. 发布通知 。

   - 系统实况窗类型通知继承了普通文本类型的字段，新增了类型标识符、胶囊、按钮、时间和进度，该类型的具体字段描述参考[NotificationSystemLiveViewContent](../reference/apis/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent)。
     
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

   - 普通实况窗类型通知继承了普通文本类型的字段，新增了实况通知状态、实况通知版本号、通知附加内容和通知附加内容中的图片信息，该类型的具体字段描述参考[NotificationLiveViewContent](../reference/apis/js-apis-inner-notification-notificationContent.md#notificationliveviewcontent11)。

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
