# 公共事件订阅


## 场景介绍

当需要订阅某个公共事件，获取该公共事件传递的参数时，需要创建一个订阅者对象，用于作为订阅公共事件的载体，订阅公共事件并获取公共事件传递而来的参数。订阅部分系统公共事件需要先[申请权限](../security/accesstoken-guidelines.md)，订阅这些事件所需要的权限请见[公共事件权限列表](../reference/apis/js-apis-commonEvent.md#support)。


## 接口说明

详细接口见[接口文档](../reference/apis/js-apis-commonEvent.md#commoneventcreatesubscriber)。

| 接口名 | 接口描述 |
| -------- | -------- |
| createSubscriber(subscribeInfo:&nbsp;[CommonEventSubscribeInfo](../reference/apis/js-apis-commonEvent.md#commoneventsubscribeinfo),&nbsp;callback:&nbsp;AsyncCallback&lt;[CommonEventData](../reference/apis/js-apis-commonEvent.md#commoneventdata)&gt;):&nbsp;void | 创建订阅者对象(callback) |
| createSubscriber(subscribeInfo:&nbsp;CommonEventSubscribeInfo):&nbsp;Promise&lt;CommonEventSubscriber&gt; | 创建订阅者对象(promise) |
| subscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback:&nbsp;AsyncCallback):&nbsp;void | 订阅公共事件 |


## 开发步骤

1. 导入CommonEvent模块。
   
   ```ts
   import commonEvent from '@ohos.commonEventManager';
   ```

2. 创建订阅者信息，详细的订阅者信息数据类型及包含的参数请见[CommonEventSubscribeInfo](../reference/apis/js-apis-commonEvent.md#commoneventsubscribeinfo)文档介绍。
   
   ```ts
   // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
   let subscriber = null;
   // 订阅者信息
   let subscribeInfo = {
       events: ["usual.event.SCREEN_OFF"], // 订阅灭屏公共事件
   }
   ```

3. 创建订阅者，保存返回的订阅者对象subscriber，用于执行后续的订阅、退订等操作。
   
   ```ts
   // 创建订阅者回调
   commonEvent.createSubscriber(subscribeInfo, (err, data) => {
       if (err) {
           console.error(`[CommonEvent] CreateSubscriberCallBack err=${JSON.stringify(err)}`);
       } else {
           console.info(`[CommonEvent] CreateSubscriber success`);
           subscriber = data;
           // 订阅公共事件回调
       }
   })
   ```

4. 创建订阅回调函数，订阅回调函数会在接收到事件时触发。订阅回调函数返回的data内包含了公共事件的名称、发布者携带的数据等信息，公共事件数据的详细参数和数据类型请见[CommonEventData](../reference/apis/js-apis-commonEvent.md#commoneventdata)文档介绍。
   
   ```ts
   // 订阅公共事件回调
   if (subscriber !== null) {
       commonEvent.subscribe(subscriber, (err, data) => {
           if (err) {
               console.error(`[CommonEvent] SubscribeCallBack err=${JSON.stringify(err)}`);
           } else {
               console.info(`[CommonEvent] SubscribeCallBack data=${JSON.stringify(data)}`);
           }
       })
   } else {
       console.error(`[CommonEvent] Need create subscriber`);
   }
   ```
