# 事件通知开发常见问题

## 如何封装一个通用的commonEvent工具类

适用于OpenHarmony 3.1 Beta5  API 9

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

[公共事件模块](../reference/apis/js-apis-commonEventManager.md)

## 如何让事件只在一个UIAbility实例中传递

适用于：OpenHarmony 3.2 Beta5  API 9 

**问题现象**

应该如何实现事件只在一个UIAbility实例中订阅和触发

**解决措施**

在UIAbility中使用EventHub订阅事件，EventHub模块提供了事件中心，提供订阅、取消订阅、触发事件的能力

**代码示例**

```
import UIAbility from '@ohos.app.ability.UIAbility';
 export default class EntryAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc);
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
