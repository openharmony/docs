# 使用Emitter进行线程间通信


[Emitter](../../reference/apis-basic-services-kit/js-apis-emitter.md)主要提供线程间发送和处理事件的能力，包括对持续订阅事件或单次订阅事件的处理、取消订阅事件、发送事件到事件队列等。


Emitter的开发步骤如下：


1. 订阅事件

   ```ts
   import { emitter } from '@kit.BasicServicesKit';
   import { promptAction } from '@kit.ArkUI';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = 'ThreadModel';
   const DOMAIN_NUMBER: number = 0xFF00;
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
     hilog.info(DOMAIN_NUMBER, TAG, 'event callback:' + JSON.stringify(eventData));
   };
   
   // 订阅eventId为1的事件
   emitter.on(event, callback);
   promptAction.showToast({
     message: JSON.stringify('emitter subscribe success')
   });
   ```

2. 发送事件

   ```ts
   import { emitter } from '@kit.BasicServicesKit';
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