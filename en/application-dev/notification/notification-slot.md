# Managing Notification Slots

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=81f445fd08211cfc3b68579d2e6edda6177d5f3e translatedAt=2026-08-13T03:11:32.507Z pushedAt=2026-08-13T07:39:25.987Z -->

The system supports a range of notification slots. Different notification slots are assigned different reminder modes. You can choose notification slots for your application and manage them as required, such as creating, querying, and deleting notification slots.

## Notification Slots

The following table lists the notification slots and their reminder modes. **Y** indicates that the feature is supported, and **N** indicates that the feature is not supported.

<!--RP1-->
<!--RP1End-->
<!--RP2-->

| SlotType             | Value   | Classification     | Notification Center | Banner | Lock Screen | Sound/Vibration | Status Bar Icon | Screen Wake |
| -------------------- | ------ | --------| ------- |------|------|----------|-----------|---------|
| SOCIAL_COMMUNICATION | 1      | Social Communication | Y | Y | Y | Y | Y | Y |
| SERVICE_INFORMATION  | 2      | Service Reminder | Y | Y | Y | Y | Y | Y |
| CUSTOMER_SERVICE     | 5      | Customer Service | Y | N | N | Y | Y | N |
| CONTENT_INFORMATION  | 3      | Content Information | Y | N | N | N | N | N |
| UNKNOWN_TYPE         | 0      | Unknown Type | Y | N | N | N | N | N |
| OTHER_TYPES          | 0xFFFF | Other     | Y | N | N | N | N | N |

<!--RP2End-->

## Available APIs

The main notification slot APIs are as follows. For details about other APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

| **API**| **Description**|
| ---------- | -------- |
| addSlot(type: SlotType): Promise\<void\>                 | Adds a notification slot.          |
| getSlot(slotType: SlotType): Promise\<NotificationSlot\> | Obtains a notification slot.      |
| removeSlot(slotType: SlotType): Promise\<void\>          | Removes a notification slot for this application. |

In addition to using **addSlot()**, you can also create a notification slot by passing **notificationSlotType** in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1). If the specified notification slot does not exist, it is automatically created.

## How to Develop

1. Import the **notificationManager** module.

   <!-- @[manage_notification_ways_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/ManageNotificationWays.ets) -->

   ``` TypeScript
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Add a notification slot.

   <!-- @[create_type_channel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/ManageNotificationWays.ets) -->

   ``` TypeScript
   // addSlot callback
   let addSlotCallBack = (err: BusinessError): void => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG, `addSlot failed, code is ${err.code}, message is ${err.message}`);
     } else {
       hilog.info(DOMAIN_NUMBER, TAG, `addSlot success`);
     }
   };
   notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
   ```

3. Obtain a notification slot.

   Retrieve the slot's creation status and supported notification modes—for example, whether there is an alert tone, vibration, and lock screen visibility.

   <!-- @[get_type_channel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/ManageNotificationWays.ets) -->

   ``` TypeScript
   // getSlot callback
   let getSlotCallback = (err: BusinessError, data: notificationManager.NotificationSlot): void => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG, `Failed to get slot. Code is ${err.code}, message is ${err.message}`);
     } else {
       hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in getting slot.`);
       if (data != null) {
         hilog.info(DOMAIN_NUMBER, TAG, `slot enable status is ${JSON.stringify(data.enabled)}`);
         hilog.info(DOMAIN_NUMBER, TAG, `vibrationEnabled status is ${JSON.stringify(data.vibrationEnabled)}`);
         hilog.info(DOMAIN_NUMBER, TAG, `lightEnabled status is ${JSON.stringify(data.lightEnabled)}`);
       }
     }
   };
   let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
   notificationManager.getSlot(slotType, getSlotCallback);
   ```

4. Remove a notification slot.

   <!-- @[delete_type_channel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/ManageNotificationWays.ets) -->

   ``` TypeScript
   // removeSlot callback
   let removeSlotCallback = (err: BusinessError): void => {
     if (err) {
       hilog.error(DOMAIN_NUMBER, TAG,
         `removeSlot failed, code is ${JSON.stringify(err.code)}, message is ${JSON.stringify(err.message)}`);
     } else {
       hilog.info(DOMAIN_NUMBER, TAG, 'removeSlot success');
     }
   };
   let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
   notificationManager.removeSlot(slotType, removeSlotCallback);
   ```