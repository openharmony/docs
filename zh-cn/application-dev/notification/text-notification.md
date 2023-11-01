# 发布基础类型通知


基础类型通知主要应用于发送短信息、提示信息、广告推送等，支持普通文本类型、长文本类型、多行文本类型和图片类型。

**表1** 基础类型通知中的内容分类

| 类型 | 描述 |
| -------- | -------- |
| NOTIFICATION_CONTENT_BASIC_TEXT | 普通文本类型。 |
| NOTIFICATION_CONTENT_LONG_TEXT | 长文本类型。 |
| NOTIFICATION_CONTENT_MULTILINE | 多行文本类型。 |
| NOTIFICATION_CONTENT_PICTURE | 图片类型。 |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW | 系统实况窗类型。|


目前，系统仅支持通知栏订阅通知，将通知显示在通知栏中。基本类型通知的效果示意如下图所示。

**图1** 基础类型通知呈现效果示意图  
![zh-cn_image_0000001466462305](figures/zh-cn_image_0000001466462305.png)


## 接口说明

通知发布接口如下表所示，不同发布类型通知由[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)的字段携带不同的信息。

| **接口名** | **描述** |
| -------- | -------- |
| publish(request:&nbsp;NotificationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 发布通知。                 |
| cancel(id:&nbsp;number,&nbsp;label:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消指定的通知。           |
| cancelAll(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void; | 取消所有该应用发布的通知。 |


## 开发步骤

1. [使能通知开关](notification-enable.md)，获得用户授权后，才能使用通知功能。

2. 导入模块。
   
   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

3. 构造NotificationRequest对象，并发布通知。
   - 普通文本类型通知由标题、文本内容和附加信息三个字段组成，其中标题和文本内容是必填字段，大小均需要小于200字节。
     
      ```ts
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT, // 普通文本类型通知
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

      运行效果如下图所示。  
     ![zh-cn_image_0000001466782033](figures/zh-cn_image_0000001466782033.png)
   - 长文本类型通知继承了普通文本类型的字段，同时新增了长文本内容、内容概要和通知展开时的标题，其中长文本内容不超过1024字节，其他字段小于200字节。通知默认显示与普通文本相同，展开后，标题显示为展开后标题内容，内容为长文本内容。
     
      ```ts
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LONG_TEXT, // 长文本类型通知
          longText: {
            title: 'test_title',
            text: 'test_text',
            additionalText: 'test_additionalText',
            longText: 'test_longText',
            briefText: 'test_briefText',
            expandedTitle: 'test_expandedTitle',
          }
        }
      };
      
      // 发布通知
      notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
        if (err) {
          console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in publishing notification.');
      });
      ```
   
      运行效果如下图所示。  
     ![zh-cn_image_0000001416745530](figures/zh-cn_image_0000001416745530.png)
   - 多行文本类型通知继承了普通文本类型的字段，同时新增了多行文本内容、内容概要和通知展开时的标题，其字段均小于200字节。通知默认显示与普通文本相同，展开后，标题显示为展开后标题内容，多行文本内容多行显示。
     
      ```ts
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        content: {
          contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_MULTILINE, // 多行文本类型通知
          multiLine: {
            title: 'test_title',
            text: 'test_text',
            briefText: 'test_briefText',
            longTitle: 'test_longTitle',
            lines: ['line_01', 'line_02', 'line_03', 'line_04'],
          }
        }
      };
      
      // 发布通知
      notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
        if (err) {
          console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in publishing notification.');
      });
      ```
   
      运行效果如下图所示。  
     ![zh-cn_image_0000001417062446](figures/zh-cn_image_0000001417062446.png)
   - 图片类型通知继承了普通文本类型的字段，同时新增了图片内容、内容概要和通知展开时的标题，图片内容为[PixelMap](../reference/apis/js-apis-image.md#pixelmap7)类型对象，其大小不能超过2M。
     
      ```ts
      import image from '@ohos.multimedia.image';

      let imagePixelMap: image.PixelMap | undefined = undefined; // 需要获取图片PixelMap信息
      let color = new ArrayBuffer(0);
      image.createPixelMap(color, {
        size: {
          height: 0,
          width: 0
        }
      }).then((data: image.PixelMap) => {
        imagePixelMap = data;
      }).catch((err: Base.BusinessError) => {
        console.log(`createPixelMap failed, error: ${err}`);
      })
      
      if (imagePixelMap !== undefined) {
        let notificationRequest: notificationManager.NotificationRequest = {
          id: 1,
          content: {
            contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_PICTURE,
            picture: {
              title: 'test_title',
              text: 'test_text',
              additionalText: 'test_additionalText',
              briefText: 'test_briefText',
              expandedTitle: 'test_expandedTitle',
              picture: imagePixelMap
            }
          }
        };

        // 发布通知
        notificationManager.publish(notificationRequest, (err:Base.BusinessError) => {
          if (err) {
            console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
            return;
          }
          console.info('Succeeded in publishing notification.');
        });
      }
      ```
   
      运行效果如下图所示。  
     ![zh-cn_image_0000001466582045](figures/zh-cn_image_0000001466582045.png)
   - 实况窗类型通知继承了普通文本类型的字段，新增了类型标识符、胶囊、按钮、时间和进度，类型描述参考[NotificationSystemLiveViewContent](../../application-dev/reference/apis/js-apis-inner-notification-notificationContent.md#notificationsystemliveviewcontent)。
     
      ```ts
      import image from '@ohos.multimedia.image';

      let imagePixelMap: image.PixelMap | undefined = undefined; // 需要获取图片PixelMap信息
      let color = new ArrayBuffer(0);
      image.createPixelMap(color, {
        size: {
          height: 0,
          width: 0
        }
      }).then((data: image.PixelMap) => {
        imagePixelMap = data;
      }).catch((err: Base.BusinessError) => {
        console.log(`createPixelMap failed, error: ${err}`);
      })
      let notificationRequest: notificationManager.NotificationRequest = {
        slotType: LIVE_VIEW, // 实况窗类型
        id: 0, // 通知id，默认为0
        content: {
          contentType = notificationManager.ContentType.NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW,
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
      let subscriber: notificationManager.SystemLiveViewSubscriber  = {
        onResponse: onResponseCallback
      };
      // subscriber回调
      let subscriber = (err: Base.BusinessError): void => {
        if (err) {
         console.error(`subscriber failed, code is ${err.code}, message is ${err.message}`);
        } else {
         console.info("subscriber success");
        }
      };
      // subscriber取消通知回调
      let onCancelCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
        console.info("Cancel callback: " + JSON.stringify(data));
      }
      let subscriber: notificationSubscribe.NotificationSubscriber = {
        onCancel: onCancelCallback
      };
      let info: notificationSubscribe.NotificationSubscribeInfo = {
        bundleNames: ["bundleName1"],
        userId: 123
      };
      // 订阅通知，此接口为系统接口，三方应用不支持调用。
      notificationSubscribe.subscribe(subscriber, info, subscribeCallback);
      // 订阅系统实况窗(按钮)，此接口为系统接口，三方应用不支持调用。
      notificationManager.subscribeSystemLiveView(subscriber);
      // 发布通知
      notificationManager.publish(notificationRequest, publishCallback);
      ```

