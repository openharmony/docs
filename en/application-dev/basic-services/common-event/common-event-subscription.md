# Subscribing to Common Events in Dynamic Mode


## When to Use

In dynamic subscription mode, an application, when it is running, subscribes to a common event and then receives the event once it is published, together with the parameters passed in the event.

For example, if an application expects to be notified of low battery so that it can reduce power consumption accordingly when running, then the application can subscribe to the low-battery event. Upon receiving the event, the application can close some unnecessary tasks to reduce power consumption.

Certain system common events [require specific permissions](../../security/AccessToken/determine-application-mode.md) to subscribe to. For details, see [System Common Events](../../reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md).

> **NOTE**
>
> The lifecycle of the subscriber object needs to be managed by the application. If the subscriber object is no longer used, it needs to be destroyed and released to avoid memory leakage.

## Available APIs

For details about the APIs, see [API Reference](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagersubscribe).

| API| Description|
| -------- | -------- |
| createSubscriber(subscribeInfo:&nbsp;[CommonEventSubscribeInfo](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscribeInfo.md),&nbsp;callback:&nbsp;AsyncCallback&lt;[CommonEventSubscriber](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscriber.md#how-to-use)&gt;):&nbsp;void| Creates a subscriber. This API uses an asynchronous callback to return the result.|
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise&lt;CommonEventSubscriber&gt; | Creates a subscriber. This API uses a promise to return the result.|
| subscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback:&nbsp;AsyncCallback<CommonEventData\>):&nbsp;void | Subscribes to common events.|


## How to Develop

1. Import the **commonEventManager** module.
   
   ```ts
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = 'ProcessModel';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Create a **subscribeInfo** object. For details about the data types and parameters of the object, see [CommonEventSubscribeInfo](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscribeInfo.md).
   
   ```ts
   // Used to save the created subscriber object for subsequent subscription and unsubscription.
   let subscriber: commonEventManager.CommonEventSubscriber | null = null;
   //Subscriber information. Replace the event field with the actual event name.
   let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
       events: ['event'], // Subscribe to the common event screen-off.
   };
   ```

3. Create a subscriber object and save the returned object for subsequent operations such as subscription, unsubscription, and event callback.
   
   ```ts
   // Callback for subscriber creation.
   commonEventManager.createSubscriber(subscribeInfo, (err: BusinessError, data: commonEventManager.CommonEventSubscriber) => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG, `Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in creating subscriber.');
     subscriber = data;
   })
   ```

4. Create a subscription callback, which is triggered when an event is received. The data returned in the subscription callback contains information such as the common event name and data carried by the publisher. For details about the data types and parameters of the common event data, see [CommonEventData](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventData.md).
   
   ```ts
   // Callback for common event subscription.
   if (subscriber !== null) {
     commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
       if (err) {
         hilog.error(DOMAIN_NUMBER, TAG, `Failed to subscribe common event. Code is ${err.code}, message is ${err.message}`);
         return;
       }
       // ...
     })
   } else {
     hilog.error(DOMAIN_NUMBER, TAG, `Need create subscriber`);
   }
   ```

<!--RP1-->
<!--RP1End-->
