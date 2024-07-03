# Unsubscribing from Common Events in Dynamic Mode


## When to Use

You can call [unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe) to unsubscribe from a common event that is no longer required.


## Available APIs

| API| Description|
| -------- | -------- |
| unsubscribe(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback?:&nbsp;AsyncCallback) | Unsubscribes from a common event.|


## How to Develop

1. Import the **commonEventManager** module.
   
   ```ts
   import Base from '@ohos.base';
   import commonEventManager from '@ohos.commonEventManager';
   import promptAction from '@ohos.promptAction';
   import hilog from '@ohos.hilog';

   const TAG: string = 'ProcessModel';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Subscribe to an event by following the procedure described in [Subscribing to Common Events in Dynamic Mode](common-event-subscription.md).

3. Call the [unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe) method in **CommonEvent** to unsubscribe from an event.
   
   ```ts
   // The subscriber object is created during event subscription.
   if (this.subscriber !== null) {
     commonEventManager.unsubscribe(this.subscriber, (err: Base.BusinessError) => {
       if (err) {
         hilog.error(DOMAIN_NUMBER, TAG, `UnsubscribeCallBack err = ${JSON.stringify(err)}`);
       } else {
         promptAction.showToast({
           message: $r('app.string.unsubscribe_success_toast')
         });
         hilog.info(DOMAIN_NUMBER, TAG, `Unsubscribe success`);
         this.subscriber = null;
       }
     })
   } else {
     promptAction.showToast({
       message: $r('app.string.unsubscribe_failed_toast')
     });
   }
   ```
