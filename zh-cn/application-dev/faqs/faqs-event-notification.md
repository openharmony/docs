# 事件通知开发常见问题


## 如何封装一个通用的commonEvent工具类(API 9)

**问题现象**

封装一个通用的commonEvent工具类：希望在创建订阅者的同时注册一个自定义的回调函数，然后在收到事件通知的同时能调用这个自定义的回调函数。

**解决措施**

```
import commonEvent from '@ohos.commonEventManager';

export class SubscribeEvent {
  private static subscriber = null
  // 自定义的回调函数变量
  private static callback = null
  /**
   * 创建订阅者
   * @param subscribeInfo 订阅事件
   * @callback 用户自定义回调函数
   */
  static createSubscriber(subscribeInfo, callback:(a,b)=>void) {
    this.callback = callback
    commonEvent.createSubscriber(subscribeInfo, (err, subscriber) => {
      if (err) {
        console.error('CreateSubscriberCallBack err = ' + JSON.stringify(err))
      } else {
        this.subscriber = subscriber;
        this.subscribe(this.subscriber)
        console.info('Create subscriber succeed')
      }
    })
  }

  /**
   * 订阅公共事件
   * @param subscriber 订阅者
   */
  private static subscribe(subscriber) {
    if (subscriber != null) {
      commonEvent.subscribe(subscriber, (err, data) => {
        if (err) {
          console.error('subscribe err = ' + JSON.stringify(err))
        } else {
          console.info('SubscribeCallBack data= ' + JSON.stringify(data))
          this.callback('hello callback', data)
        }
      })
    } else {
      console.info("Need create subscriber")
    }
  }
}

@Entry
@Component
struct Faq10_1 {
  @State message: string = ''

  build() {
    Row() {
      Column() {
        Text('订阅：' + this.message)
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            let subscribeInfo = {
              events: ["myEvent"]
            };
            let callback = (a,b) => {
              this.message = a
            }
            SubscribeEvent.createSubscriber(subscribeInfo,callback)
          })
        Text('发布')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            //公共事件相关信息
            let options = {
              code: 0,    //公共事件的初始代码
              data: "initial data",//公共事件的初始数据
              isOrdered: true  //有序公共事件
            }
            //发布公共事件回调
            function publishCB(err) {
              if (err) {
                console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
              } else {
                console.info("publish");
              }
            }
            //发布公共事件
            try {
              commonEvent.publish("myEvent", options, publishCB);
            } catch (err) {
              console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
            }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**参考链接**

[公共事件模块](../reference/apis-basic-services-kit/js-apis-commonEventManager.md)

## 如何让事件只在一个UIAbility实例中传递(API 9)

**问题现象**

应该如何实现事件只在一个UIAbility实例中订阅和触发

**解决措施**

在UIAbility中使用EventHub订阅事件，EventHub模块提供了事件中心，提供订阅、取消订阅、触发事件的能力

**代码示例**

```
import UIAbility from '@ohos.app.ability.UIAbility';
 export default class EntryAbility extends UIAbility {
    onCreate() {
        this.context.eventHub.on('myEvent', this.eventFunc);
    }

    onDestroy() {
        // 结果：
        // eventFunc is called,undefined,undefined
        this.context.eventHub.emit('myEvent');
        // 结果：
        // eventFunc is called,1,undefined
        this.context.eventHub.emit('myEvent', 1);
        // 结果：
        // eventFunc is called,1,2
        this.context.eventHub.emit('myEvent', 1, 2);
    }

     eventFunc(argOne, argTwo) {
        console.log('eventFunc is called, ${argOne}, ${argTwo}');
    }}
```

**参考链接**

[使用EventHub进行数据](../application-models/uiability-data-sync-with-ui.md#使用eventhub进行数据通信)


## 如何实现点击Notification通知打开App功能(API 9)

**解决措施**

通过配置Notification.publish发布通知接口的参数NotificationRequest中wantAgent属性实现

**代码示例**

```
import notificationManager from '@ohos.notificationManager';
import WantAgent from '@ohos.app.ability.wantAgent';

async function publishNotification() {
  let wantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.webuseragent", // 自己应用的bundleName
        abilityName: "EntryAbility",
      }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 1,
  }
  const wantAgent = await WantAgent.getWantAgent(wantAgentInfo)
  let contentType = notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT;
  await notificationManager.publish({
    content: {
      contentType: contentType,
      normal: {
        title: "测试标题",
        text: "测试内容",
      }
    },
    id: 1,
    wantAgent: wantAgent
  })
}
```

**参考链接**

[Notification](../reference/apis-notification-kit/js-apis-notificationManager.md)、[WantAgent](../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)


## 调用notificationManager.publish发布通知失败(API 9)

**问题现象**

发布通知后，无错误日志信息，通知栏没有通知显示

**解决措施**

发布通知时，需要在真机端系统设置中，开启对应应用的通知开关，然后才能在通知栏中看到发布的通知。

手动开启步骤：设置 &gt; 通知和状态栏 &gt; 应用名称 &gt; 允许通知。

也可通过接口notificationManager.requestEnableNotification()来弹窗让用户授权（仅弹一次）。
