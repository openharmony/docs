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

The main notification slot APIs are as follows. For details about other APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

| **API**| **Description**|
| ---------- | -------- |
| addSlot(type: SlotType): Promise\<void\>                 | Adds a notification slot.          |
| getSlot(slotType: SlotType): Promise\<NotificationSlot\> | Obtains a notification slot.      |
| removeSlot(slotType: SlotType): Promise\<void\>          | Removes a notification slot for this application. |

In addition to using **addslot()**, you can also create a notification slot by passing **notificationSlotType** in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest). If the specified notification slot does not exist, it is automatically created.

## How to Develop

1. Import the **notificationManager** module.

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. Add a notification slot.

    ```ts
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

    Obtain whether the corresponding slot is created and the notification modes supported by the slot, for example, whether there is an alert tone whether there is vibration, and whether the lock screen is visible.
    ```ts
    // getSlot callback
    let getSlotCallback = (err: Base.BusinessError, data: notificationManager.NotificationSlot): void => {
        if (err) {
            console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
        } else {
            console.info(`getSlot success. `);
            if (data != null) {
                console.info(`slot enable status is ${JSON.stringify(data.enabled)}`);
                console.info(`slot level is ${JSON.stringify(data.level)}`);
                console.info(`vibrationEnabled status is ${JSON.stringify(data.vibrationEnabled)}`);
                console.info(`lightEnabled status is ${JSON.stringify(data.lightEnabled)}`);
            }
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
