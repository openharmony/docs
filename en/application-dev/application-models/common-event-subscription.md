# Subscribing to Common Events


## When to Use

You can create a subscriber object to subscribe to a common event so as to obtain the parameters passed in the event. Certain system common events [require specific permissions](../security/accesstoken-guidelines.md) to subscribe to. For details, see [Required Permissions](../reference/apis/js-apis-commonEventManager.md#support).


## Available APIs

For details about the APIs, see [API Reference](../reference/apis/js-apis-commonEvent.md#commoneventcreatesubscriber).

| API| Description|
| -------- | -------- |
| createSubscriber(subscribeInfo: [CommonEventSubscribeInfo](../reference/apis/js-apis-commonEventManager.md#commoneventsubscribeinfo), callback: AsyncCallback&lt;[CommonEventData](../reference/apis/js-apis-commonEventManager.md#commoneventdata)&gt;): void | Creates a subscriber. This API uses an asynchronous callback to return the result.|
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise&lt;CommonEventSubscriber&gt; | Creates a subscriber. This API uses a promise to return the result.|
| subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback): void | Subscribes to common events.|


## How to Develop

1. Import the **commonEvent** module.
   
   ```ts
   import commonEvent from '@ohos.commonEventManager';
   ```

2. Create a **subscribeInfo** object. For details about the data types and parameters of the object, see [CommonEventSubscribeInfo](../reference/apis/js-apis-commonEventManager.md#commoneventsubscribeinfo).
   
   ```ts
   // Used to save the created subscriber object for subsequent subscription and unsubscription.
   let subscriber = null;
   // Subscriber information.
   let subscribeInfo = {
       events: ["usual.event.SCREEN_OFF"], // Subscribe to the common event screen-off.
   }
   ```

3. Create a subscriber object and save the returned object for subsequent operations such as subscription and unsubscription.
   
   ```ts
   // Callback for subscriber creation.
   commonEvent.createSubscriber(subscribeInfo, (err, data) => {
       if (err) {
           console.error(`[CommonEvent] CreateSubscriberCallBack err=${JSON.stringify(err)}`);
       } else {
           console.info(`[CommonEvent] CreateSubscriber success`);
           subscriber = data;
           // Callback for common event subscription.
       }
   })
   ```

4. Create a subscription callback, which is triggered when an event is received. The data returned in the subscription callback contains information such as the common event name and data carried by the publisher. For details about the data types and parameters of the common event data, see [CommonEventData](../reference/apis/js-apis-commonEventManager.md#commoneventdata).
   
   ```ts
   // Callback for common event subscription.
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
