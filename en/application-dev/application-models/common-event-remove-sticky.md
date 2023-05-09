# Removing Sticky Common Events


## When to Use

Subscribers can receive sticky common events that have been sent. If the events are no longer forwarded, the event publisher needs to remove them. OpenHarmony provides an API for removing sticky common events.

## Available APIs

For details, see [Common Event](../reference/apis/js-apis-commonEventManager.md)

| Name| Description|
| -------- | -------- |
| removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void | Removes a sticky common event.|


## How to Develop

1. Import the module.
   
   ```ts
   import commonEventManager from '@ohos.commonEventManager';
   ```

2. The sticky common event to be removed must have been released by the application. For details about how to release sticky common events, see [Publishing Common Events](common-event-publish.md).

   ```ts
   CommonEventManager.removeStickyCommonEvent("sticky_event", (err) => { // sticky_event indicates the name of the sticky common event to remove.
       if (err) {
           console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);
           return;
       }
       console.info(`Remove sticky event AsyncCallback success`);
       }
   });
   ```
