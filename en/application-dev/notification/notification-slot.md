# Managing Notification Slots
The system supports a range of notification slots. Different notification slots are assigned different reminder modes. You can choose notification slots for your application and manage them as required, such as creating, querying, and deleting notification slots.

## Notification Slots

The following table lists the notification slots and their reminder modes. **Y** indicates that the feature is supported, and **N** indicates that the feature is not supported.

| SlotType             | Value  | Category    | Notification Panel| Banner| Lock Screen| Alert Tone/Vibration| Status Bar Icon| Automatic Screen-on|
| -------------------- | ------ | --------| ------- |------|------|----------|-----------|---------|
| SOCIAL_COMMUNICATION | 1      | Social communication| Y | Y | Y | Y | Y | Y |
| SERVICE_INFORMATION  | 2      | Service notification| Y | N | Y | Y | Y | Y |
| CONTENT_INFORMATION  | 3      | Content and news| Y | N | N | N | Y | N |
| CUSTOMER_SERVICE     | 5      | Customer service| Y | N | N | Y | Y | N |
| OTHER_TYPES          | 0xFFFF | Other    | Y | N | N | N | N | N |


## Available APIs

| **API**| **Description**|
| ---------- | -------- |
| [addSlot](../reference/apis/js-apis-notificationManager.md#notificationmanageraddslot-2)(type: SlotType, callback: AsyncCallback\<void\>): void <br> [addSlot](../reference/apis/js-apis-notificationManager.md#notificationmanageraddslot-3)(type: SlotType): Promise\<void\> | Adds a notification slot.         |
| [getSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslot)(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void <br>[getSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslot-1)(slotType: SlotType): Promise\<NotificationSlot\> | Obtains a notification slot. |
| [getSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslots)(callback: AsyncCallback\<Array\<NotificationSlot>>): void <br> [getSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslots-1)(): Promise\<Array\<NotificationSlot>>  | Obtains all notification slots for this application.    |
| [removeSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveslot)(slotType: SlotType, callback: AsyncCallback\<void\>): void  <br> [removeSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveslot-1)(slotType: SlotType): Promise\<void\>  | Removes a notification slot for this application. |
| [removeAllSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveallslots)(callback: AsyncCallback\<void\>): void <br> [removeAllSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveallslots-1)(): Promise\<void\>   | Removes all notification slots for this application.      |

In addition to using **addslot()**, you can also create a notification slot by passing **notificationSlotType** in the [NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest). If the specified notification slot does not exist, it is automatically created.

## How to Develop

1. Import the **notificationManager** module.

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. Add a notification slot.

    ```ts
    import Base from '@ohos.base';

    // addSlot callback
    let addSlotCallBack = (err: Base.BusinessError): void => {
        if (err) {
            console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
        } else {
            console.info("addSlot success");
        }
    }
    notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
    ```

3. Obtain a notification slot.

    ```ts
    // getSlot callback
    let getSlotCallback = (err: Base.BusinessError, data: notificationManager.NotificationSlot): void => {
        if (err) {
            console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
        } else {
            console.info(`getSlot success, data is ${JSON.stringify(data)}`);
        }
    }
    let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.getSlot(slotType, getSlotCallback);
    ```

4. Remove a notification slot.

    ```ts
    // removeSlot callback
    let removeSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeSlot success");
    }
    }
    let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.removeSlot(slotType, removeSlotCallback);
    ```
