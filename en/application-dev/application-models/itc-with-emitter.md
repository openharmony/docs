# Using Emitter for Inter-Thread Communication


[Emitter](../reference/apis/js-apis-emitter.md) provides APIs for sending and processing events between threads, including the APIs for processing events that are subscribed to in persistent or one-shot manner, unsubscribing from events, and emitting events to the event queue.


To develop the Emitter mode, perform the following steps:


1. Subscribe to an event.

   ```ts
   import emitter from '@ohos.events.emitter';
   import promptAction from '@ohos.promptAction';
   ```
   ```ts
   // Define an event with eventId 1.
   let event: emitter.InnerEvent = {
     eventId: 1
   };
   
   // Trigger the callback after the event with eventId 1 is received.
   let callback = (eventData: emitter.EventData): void => {
     promptAction.showToast({
       message: JSON.stringify(eventData)
     });
     Logger.info(TAG, 'event callback:' + JSON.stringify(eventData));
   };
   
   // Subscribe to the event with eventId 1.
   emitter.on(event, callback);
   promptAction.showToast({
     message: $r('app.string.emitter_subscribe_success_toast')
   });
   ```

2. Emit the event.

   ```ts
   import emitter from '@ohos.events.emitter';
   ```
   ```ts
   // Define an event with eventId 1 and priority Low.
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
   
   // Emit the event with eventId 1 and event content eventData.
   emitter.emit(event, eventData);
   ```
