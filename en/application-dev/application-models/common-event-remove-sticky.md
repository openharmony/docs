# Removing Sticky Common Events (for System Applications Only)


## When to Use

Subscribers can receive sticky common events that have been sent. If the events are no longer forwarded, the event publisher needs to remove them. The system provides an API for removing sticky common events.

## Available APIs

For details, see [Common Event](../reference/apis/js-apis-commonEventManager.md)

| Name| Description|
| -------- | -------- |
| removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void | Removes a sticky common event.|


## How to Develop

1. Declare the **ohos.permission.COMMONEVENT_STICKY** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Import the module.

   ```ts
   import Base from '@ohos.base';
   import commonEventManager from '@ohos.commonEventManager';
   import Logger from '../utils/Logger';

   const TAG: string = 'ProcessModel';
   ```

3. Call the [removeStickyCommonEvent()](../reference/apis/js-apis-commonEventManager.md#commoneventmanagerremovestickycommonevent10) API to remove the target sticky common event.

   > **NOTE**
   >
   > The sticky common event to be removed must have been released by the application. For details about how to release sticky common events, see [Publishing Common Events](common-event-publish.md).

   ```ts
   commonEventManager.removeStickyCommonEvent('usual.event.SCREEN_OFF', (err: Base.BusinessError) => {
     // sticky_event indicates the name of the target sticky common event.
     if (err) {
       Logger.error(TAG, `Failed to remove sticky common event. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     ...
     Logger.info(TAG, `Succeeded in removeing sticky event.`);
   });
   ```
