# Using Emitter for Inter-Thread Communication

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

Emitter is an event processing mechanism used in a process. It provides the capabilities of subscribing to, publishing, and unsubscribing from events for applications.

## When to Use

Emitter is used to process events of the same thread or different threads in the same process in an asynchronous manner. To use this mechanism, you need to subscribe to an event and publish it, after which the Emitter distributes the published event to the subscriber, and the subscriber executes the callback method set during event subscription. Unsubscribe from the event in time to release the Emitter resources when the event does not need to be subscribed to.

## Working Principles
Emitter distributes tasks by maintaining an internal event queue. An application needs to subscribe to an event and set the callback method of the event. After the application publishes the event, an event is inserted into the queue. The task queue executes the tasks serially, during which the callback method of the task subscriber is called to process the event.

![emitter](figures/emitter.png)

## Available APIs
For details, see [@ohos.events.emitter (Emitter)](../../reference/apis-basic-services-kit/js-apis-emitter.md).
| API | Capability  | Description    |
| ------- | ------ | -------- |
| on | Event subscription| Continuously subscribes to an event until the event is unsubscribed from.|
| once | Event subscription| Subscribes to an event once.|
| emit | Event publishing| Publishes an event once.|
| off | Event unsubscription.| Unsubscribes from the event and subsequent notifications of this event will not be received.|

## How to Develop

To enable Emitter's capabilities mentioned above, perform the following steps:

1. Import the Emitter module.
   
   ```ts
   import { emitter, Callback } from '@kit.BasicServicesKit';
   ```

2. Subscribe to an event.

   Use **on()** for continuous subscription or **once()** for one-time subscription. Set the events to subscribe to and the callback function after the events are received.
   ```ts
    // Define an event with eventId 1.
    let event: emitter.InnerEvent = {
      eventId: 1
    };
    // Define a callback for an event.
    let callback: Callback<emitter.EventData> = (eventData: emitter.EventData) => {
      console.info(`eventData: ${JSON.stringify(eventData)}`);
    }

    // Execute the callback after receiving the event whose eventId is 1.
    emitter.on(event, callback);
   ```

   ```ts
    // Execute the callback after receiving the event whose eventId is 1.
    // Note that the event is received only once using once(), while the event is received until the subscription is canceled using on().
    emitter.once(event, callback);
   ```

3. Emit the event.

   Use **emit()** to send events and set the events to send and the parameters to pass.
    > **NOTE**
    >
    > This API can be used to emit data objects across threads. The data objects must meet the specifications specified in [Overview of Inter-thread Communication Objects](../../arkts-utils/serializable-overview.md). Currently, complex data decorated by decorators such as [@State](../../ui/state-management/arkts-state.md) and [@Observed](../../ui/state-management/arkts-observed-and-objectlink.md) is not supported.
   ```ts
   // Define an event with eventId 1 and priority Low.
   let event: emitter.InnerEvent = {
     eventId: 1,
     priority: emitter.EventPriority.LOW
   };

   let eventData: emitter.EventData = {
     data: {
       content: 'emitter',
       id: 1,
       isEmpty: false
     }
   };
   
   // Emit the event with eventId 1 and event content eventData.
   emitter.emit(event, eventData);
   ```

4. Unsubscribe from the event.
    > **NOTE**
    >
    > - If an event does not need to be subscribed to, cancel the subscription in a timely manner to prevent memory leakage.
    > - After the [off](../../reference/apis-basic-services-kit/js-apis-emitter.md#emitteroff) API is used to unsubscribe from an event, the event that has been published through the [emit](../../reference/apis-basic-services-kit/js-apis-emitter.md#emitteremit) API but has not been executed will be unsubscribed.
   ```ts
   // Unsubscribe from the event with eventId 1.
   emitter.off(1);
   ```
