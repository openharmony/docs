# Publishing Common Events


## When to Use

You can use [publish()](../reference/apis/js-apis-commonEventManager.md#commoneventmanagerpublish) to publish a custom common event, which can carry data for subscribers to parse and process.

> **NOTE**
>
> Subscribers can receive sticky common events that have been sent. However, they must subscribe to common events of other types before receiving them. For details about subscription, see [Subscribing to Common Events](common-event-subscription.md).


## Available APIs

For details about the APIs, see [API Reference](../reference/apis/js-apis-commonEventManager.md#commoneventmanagerpublish).

| API| Description|
| -------- | -------- |
| publish(event: string, callback: AsyncCallback) | Publishes a common event.|
| publish(event: string, options: [CommonEventPublishData](../reference/apis/js-apis-commonEventManager.md#commoneventpublishdata), callback: AsyncCallback) | Publishes a common event with given attributes.|


## Publishing a Common Event That Does Not Carry Information

Common events that do not carry information can be published only as unordered common events.

1. Import the **commonEventManager** module.
   
   ```ts
   import commonEventManager from '@ohos.commonEventManager';
   ```

2. Pass in the common event name and callback, and publish the event.
   
   ```ts
   // Publish a common event.
   commonEventManager.publish("usual.event.SCREEN_OFF", (err) => {
       if (err) {
           console.error(`[CommonEvent] PublishCallBack err=${JSON.stringify(err)}`);
       } else {
           console.info(`[CommonEvent] Publish success`);
       }
   })
   ```


## Publishing a Common Event That Carries Information

Common events that carry information can be published as unordered, ordered, and sticky common events, which are specified by the **isOrdered** and **isSticky** fields of [CommonEventPublishData](../reference/apis/js-apis-commonEventManager.md#commoneventpublishdata).

1. Import the **commonEventManager** module.
   
   ```ts
   import commonEventManager from '@ohos.commonEventManager';
   ```

2. Pass in the common event name and callback, and publish the event.
   
   ```ts
   // Attributes of a common event.
   let options = {
       code: 1, // Result code of the common event.
       data: "initial data", // Result data of the common event.
   }
   ```

3. Pass in the common event name, attributes of the common event, and callback, and publish the event.
   
   ```ts
   // Publish a common event.
   commonEventManager.publish("usual.event.SCREEN_OFF", options, (err) => {
       if (err) {
           console.error('[CommonEvent] PublishCallBack err=' + JSON.stringify(err));
       } else {
           console.info('[CommonEvent] Publish success')
       }
   })
   ```
