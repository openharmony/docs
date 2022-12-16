# 公共事件取消订阅


## 场景介绍

订阅者完成业务需要时，需要主动取消订阅，订阅者通过下面方法取消订阅事件。


## 接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| unsubscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback?:&nbsp;AsyncCallback) | 取消订阅公共事件 |


## 开发步骤

1. 导入CommonEvent模块。
   
   ```ts
   import commonEvent from '@ohos.commonEventManager';
   ```

2. 根据[事件订阅章节](common-event-subscription.md)的步骤来订阅某个事件。

3. 调用CommonEvent中的unsubscribe方法取消订阅某事件。
   
   ```ts
   // subscriber为订阅事件时创建的订阅者对象
   if (subscriber !== null) {
       commonEvent.unsubscribe(subscriber, (err) => {
           if (err) {
               console.error(`[CommonEvent] UnsubscribeCallBack err=${JSON.stringify(err)}`)
           } else {
               console.info(`[CommonEvent] Unsubscribe`)
               subscriber = null
           }
       })
   }
   ```
