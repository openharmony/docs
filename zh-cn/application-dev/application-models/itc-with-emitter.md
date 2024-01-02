# 使用Emitter进行线程间通信


[Emitter](../reference/apis/js-apis-emitter.md)主要提供线程间发送和处理事件的能力，包括对持续订阅事件或单次订阅事件的处理、取消订阅事件、发送事件到事件队列等。


Emitter的开发步骤如下：


1. 订阅事件

   ```ts
   import emitter from '@ohos.events.emitter';
   import promptAction from '@ohos.promptAction';
   ```
   ```ts
   // 定义一个eventId为1的事件
   let event: emitter.InnerEvent = {
     eventId: 1
   };
   
   // 收到eventId为1的事件后执行该回调
   let callback = (eventData: emitter.EventData): void => {
     promptAction.showToast({
       message: JSON.stringify(eventData)
     });
     Logger.info(TAG, 'event callback:' + JSON.stringify(eventData));
   };
   
   // 订阅eventId为1的事件
   emitter.on(event, callback);
   promptAction.showToast({
     message: $r('app.string.emitter_subscribe_success_toast')
   });
   ```

2. 发送事件

   ```ts
   import emitter from '@ohos.events.emitter';
   ```
   ```ts
   // 定义一个eventId为1的事件，事件优先级为Low
   let event: emitter.InnerEvent = {
     eventId: 1,
     priority: emitter.EventPriority.LOW
   };
   
   let eventData: emitter.EventData = {
     data: {
       content: 'c',
       id: 1,
       isEmpty: false
     }
   };
   
   // 发送eventId为1的事件，事件内容为eventData
   emitter.emit(event, eventData);
   ```