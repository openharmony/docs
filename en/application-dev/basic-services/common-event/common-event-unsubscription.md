# Unsubscribing from Common Events in Dynamic Mode


## When to Use

You can call [unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe) to unsubscribe from a common event that is no longer required.


## Available APIs

| API| Description|
| -------- | -------- |
| unsubscribe(subscriber:&nbsp;[CommonEventSubscriber](../../reference/apis-basic-services-kit/js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber),&nbsp;callback?:&nbsp;AsyncCallback) | Unsubscribes from a common event.|


## How to Develop

1. Import the **commonEventManager** module.
   
   ```ts
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = 'ProcessModel';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Subscribe to an event by following the procedure described in [Subscribing to Common Events in Dynamic Mode](common-event-subscription.md).

3. Call the [unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe) method in **CommonEvent** to unsubscribe from an event.
   
   ```ts
   // The subscriber object is created during event subscription.
   if (this.subscriber !== null) {
     commonEventManager.unsubscribe(this.subscriber, (err: BusinessError) => {
       if (err) {
         hilog.error(DOMAIN_NUMBER, TAG, `UnsubscribeCallBack err = ${JSON.stringify(err)}`);
       } else {
         hilog.info(DOMAIN_NUMBER, TAG, `Unsubscribe success`);
         this.subscriber = null;
       }
     })
   }
   ```
