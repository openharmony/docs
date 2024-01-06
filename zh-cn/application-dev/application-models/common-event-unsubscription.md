# 取消动态订阅公共事件


## 场景介绍

动态订阅者完成业务需要时，需要主动取消订阅，订阅者通过调用[unsubscribe()](../reference/apis/js-apis-commonEventManager.md#commoneventmanagerunsubscribe)方法取消订阅事件。


## 接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| unsubscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback?:&nbsp;AsyncCallback) | 取消订阅公共事件 |


## 开发步骤

1. 导入模块。
   
   ```ts
   import Base from '@ohos.base';
   import commonEventManager from '@ohos.commonEventManager';
   import promptAction from '@ohos.promptAction';
   ```

2. 根据[动态订阅公共事件](common-event-subscription.md)章节的步骤来订阅某个事件。

3. 调用CommonEvent中的unsubscribe()方法取消订阅某事件。
   
   ```ts
   // subscriber为订阅事件时创建的订阅者对象
   if (this.subscriber !== null) {
     commonEventManager.unsubscribe(this.subscriber, (err: Base.BusinessError) => {
       if (err) {
         Logger.error(TAG, `UnsubscribeCallBack err = ${JSON.stringify(err)}`);
       } else {
         promptAction.showToast({
           message: $r('app.string.unsubscribe_success_toast')
         });
         Logger.info(TAG, `Unsubscribe success`);
         this.subscriber = null;
       }
     })
   } else {
     promptAction.showToast({
       message: $r('app.string.unsubscribe_failed_toast')
     });
   }
   ```
