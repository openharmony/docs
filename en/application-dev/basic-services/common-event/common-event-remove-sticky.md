# Removing Sticky Common Events (for System Applications Only)


## When to Use

Subscribers can receive sticky common events that have been sent. If the events are no longer forwarded, the event publisher needs to remove them. The system provides an API for removing sticky common events.

## Available APIs

For details, see [API Reference](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md).

| API| Description|
| -------- | -------- |
| removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void | Removes a sticky common event.|


## How to Develop

1. Declare the **ohos.permission.COMMONEVENT_STICKY** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

2. Import the module.

   ```ts
   import Base from '@ohos.base';
   import commonEventManager from '@ohos.commonEventManager';
   import hilog from '@ohos.hilog';

   const TAG: string = 'ProcessModel';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

3. Call the [`removeStickyCommonEvent()`](../../reference/apis-basic-services-kit/js-apis-commonEventManager-sys.md#commoneventmanagerremovestickycommonevent10) method to remove the corresponding sticky common event.

   > **NOTE**
   >
   > The sticky common event to be removed must have been released by the application. For details about how to publish sticky common events, see [Publishing Common Events](common-event-publish.md).

   ```ts
   // Remove the sticky common event. Replace the event field with the actual event name.
   commonEventManager.removeStickyCommonEvent('event', (err: Base.BusinessError) => {
     // sticky_event indicates the name of the target sticky common event.
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG, `Failed to remove sticky common event. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     //...
     hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in removeing sticky event.`);
   });
   ```
