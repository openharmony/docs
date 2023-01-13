# Unsubscribing from Common Events


## When to Use

You can call **unsubscribe()** to unsubscribe from a common event that is no longer required.


## Available APIs

| API| Description|
| -------- | -------- |
| unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback) | Unsubscribes from a common event.|


## How to Develop

1. Import the **commonEvent** module.
   
   ```ts
   import commonEvent from '@ohos.commonEventManager';
   ```

2. Subscribe to an event by following the procedure described in [Subscribing to Common Events](common-event-subscription.md).

3. Call **unsubscribe** in **CommonEvent** to unsubscribe from the common event.
   
   ```ts
   // The subscriber object iscreated during event subscription.
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
