# 发布实况窗类型通知（仅对系统应用开放）

实况窗类型的通知可以让用户实时感知当前任务的进度。主要用于展示录音、录屏、音视频播放、计时、通话等长时任务的实时进展。此类通知不会进行持久化存储，其生命周期与通知发布方的生命周期一致。

**表1** 基础类型通知中的内容分类

| 类型                                                   | 值 | 描述                |
| ------------------------------------------------------ | --- | ------------------ |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5  | 实况窗类型通知。    |

## 接口说明

通知发布接口说明详见下表，通知发布的详情可通过入参[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)来进行指定。可以包括通知内容、通知ID、通知的通道类型和通知发送时间等信息。

| **接口名** | **描述** |
| -------- | -------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish)(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 发布通知。                 |
| [cancel](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagercancel)(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消指定的通知。      |


## 开发步骤

1. 导入模块。
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { image } from '@kit.ImageKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 发布通知。

   系统实况窗类型通知继承了普通文本类型的字段，新增了类型标识符、胶囊、按钮、时间和进度，该类型的具体字段描述参考[NotificationSystemLiveViewContent](../reference/apis-notification-kit/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent)。
     
      ```ts
      let imagePixelMap: image.PixelMap | undefined = undefined; // 需要获取图片PixelMap信息
      let color = new ArrayBuffer(4);
      imagePixelMap = await image.createPixelMap(color, {
        size: {
          height: 1,
          width: 1
        }
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
                maxValue: 100,
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
        // publish回调
        let publishCallback = (err: BusinessError): void => {
          if (err) {
            hilog.error(DOMAIN_NUMBER, TAG, `publish failed, code is ${err.code}, message is ${err.message}`);
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, `publish success`);
          }
        };
        // 按钮回调(用户点击按钮，会返回这个回调，业务自己决定如何处理)
        let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
          hilog.info(DOMAIN_NUMBER, TAG, `response callback: ` + JSON.stringify(option) + `notificationId` + id);
        }
        let systemLiveViewSubscriber: notificationManager.SystemLiveViewSubscriber  = {
          onResponse: onResponseCallback
        };
        // 订阅系统实况窗(按钮)
        await notificationManager.subscribeSystemLiveView(systemLiveViewSubscriber);
        // 发布通知
        notificationManager.publish(notificationRequest, publishCallback);
      }
      ```