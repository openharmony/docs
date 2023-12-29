# Removing Sticky Common Events (for System Applications Only)


## When to Use

Subscribers can receive sticky common events that have been sent. If the events are no longer forwarded, the event publisher needs to remove them. The system provides an API for removing sticky common events.

## Available APIs

For details, see [Common Event](../reference/apis/js-apis-commonEventManager.md)

| Name| Description|
| -------- | -------- |
| removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void | Removes a sticky common event.|


## How to Develop

1. Request the **ohos.permission.COMMONEVENT_STICKY** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Import the module.

   ```ts
   import commonEventManager from '@ohos.commonEventManager';
   import Base from '@ohos.base';
   ```

3. Call the [removeStickyCommonEvent()](../reference/apis/js-apis-commonEventManager.md#commoneventmanagerremovestickycommonevent10) API to remove the target sticky common event.

   > **NOTE**
   >
   > The sticky common event to be removed must have been released by the application. For details about how to release sticky common events, see [Publishing Common Events](common-event-publish.md).

   ```ts
   commonEventManager.removeStickyCommonEvent("sticky_event", (err: Base.BusinessError) => { // sticky_event indicates the name of the target sticky common event.
     if (err) {
       console.error(`Failed to remove sticky common event. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info(`Succeeded in removeing sticky event.`);
   });
   ```
