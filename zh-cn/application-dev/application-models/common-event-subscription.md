# 动态订阅公共事件


## 场景介绍

动态订阅是指当应用在运行状态时对某个公共事件进行订阅，在运行期间如果有订阅的事件发布那么订阅了这个事件的应用将会收到该事件及其传递的参数。例如，某应用希望在其运行期间收到电量过低的事件，并根据该事件降低其运行功耗，那么该应用便可动态订阅电量过低事件，收到该事件后关闭一些非必要的任务来降低功耗。订阅部分系统公共事件需要先[申请权限](../security/accesstoken-guidelines.md)，订阅这些事件所需要的权限请见[公共事件权限列表](../reference/apis/js-apis-commonEventManager.md#support)。


## 接口说明

详细接口见[接口文档](../reference/apis/js-apis-commonEventManager.md#commoneventmanagersubscribe)。

| 接口名 | 接口描述 |
| -------- | -------- |
| createSubscriber(subscribeInfo:&nbsp;[CommonEventSubscribeInfo](../reference/apis/js-apis-commonEventManager.md#commoneventsubscribeinfo),&nbsp;callback:&nbsp;AsyncCallback&lt;[CommonEventSubscriber](../reference/apis/js-apis-inner-commonEvent-commonEventSubscriber.md#使用说明)&gt;):&nbsp;void | 创建订阅者对象（callback） |
| createSubscriber(subscribeInfo:&nbsp;CommonEventSubscribeInfo):&nbsp;Promise&lt;CommonEventSubscriber&gt; | 创建订阅者对象（promise） |
| subscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback:&nbsp;AsyncCallback):&nbsp;void | 订阅公共事件 |


## 开发步骤

1. 导入模块。
   
   ```ts
   import commonEventManager from '@ohos.commonEventManager';
   ```

2. 创建订阅者信息，详细的订阅者信息数据类型及包含的参数请见[CommonEventSubscribeInfo](../reference/apis/js-apis-commonEventManager.md#commoneventsubscribeinfo)文档介绍。
   
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
   commonEventManager.createSubscriber(subscribeInfo, (err, data) => {
     if (err) {
       console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info('Succeeded in creating subscriber.');
     subscriber = data;
     // 订阅公共事件回调
   })
   ```

4. 创建订阅回调函数，订阅回调函数会在接收到事件时触发。订阅回调函数返回的data内包含了公共事件的名称、发布者携带的数据等信息，公共事件数据的详细参数和数据类型请见[CommonEventData](../reference/apis/js-apis-commonEventManager.md#commoneventdata)文档介绍。
   
   ```ts
   // 订阅公共事件回调
   if (subscriber !== null) {
     commonEventManager.subscribe(subscriber, (err, data) => {
       if (err) {
         console.error(`Failed to subscribe common event. Code is ${err.code}, message is ${err.message}`);
         return;
       }
     })
   } else {
     console.error(`Need create subscriber`);
   }
   ```
