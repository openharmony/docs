# Common Event and Notification Subsystem ChangeLog

## cl.notification.1 Deleting Deprecated APIs (Version 9)

In the [event notification exception handling rectification](../OpenHarmony_3.2.8.3/changelogs-notification.md), some APIs in API version 9 are marked as deprecated, and these APIs need to be deleted, according to OpenHarmony API specifications.

**Change Impacts**

The application developed based on earlier versions needs to use new APIs to replace the deleted ones. Otherwise, the application compilation will be affected.

**Key API/Component Changes**

Deprecated APIs in API version 9 will be deleted, and they will be replaced with new ones with same names.

| Original API                 | New API                          |
| ----------------------- | -------------------------------- |
| @ohos.commonEvent.d.ts  | @ohos.commonEventManager.d.ts    |
| @ohos.notification.d.ts | @ohos.notificationManager.d.ts   |
| @ohos.notification.d.ts | @ohos.notificationSubscribe.d.ts |

APIs or attributes are deleted:

- @ohos.notification.d.ts
  - The **publishAsBundle**, **cancelAsBundle**, **isNotificationSlotEnabled**, **setSyncNotificationEnabledWithoutApp**, and **getSyncNotificationEnabledWithoutApp** APIs are deleted. Replace them with APIs with same names in **api/@ohos.notificationManager.d.ts**.
  - The **enableNotificationSlot** API is deleted. Replace it with **setNotificationEnableSlot** in **api/@ohos.notificationManager.d.ts**.
  - The export classes **NotificationActionButton**, **NotificationBasicContent**, **NotificationContent**, **NotificationLongTextContent**, **NotificationMultiLineContent**, **NotificationPictureContent**, **NotificationFlags**, **NotificationFlagStatus**, **NotificationRequest**, **DistributedOptions**, **NotificationSlot**, **NotificationSorting**, **NotificationTemplate**, and **NotificationUserInput** are deleted. Replace them with the export classes with the same names in **api/@ohos.notificationManager.d.ts**.
  - The export classes **NotificationSubscribeInfo**, **NotificationSubscriber**, **SubscribeCallbackData**, and **EnabledNotificationCallbackData** are deleted. Replace them with the export classes with the same names in **api/@ohos.notificationSubscribe.d.ts**.

**Adaptation Guide**

The original APIs are only migrated to the new namespace. Therefore, you can modify **import** to solve the adaptation problem.

If the original API uses **@ohos.commonEvent**:

```js
import commonEvent from '@ohos.commonEvent';
```

You can directly modify **import** to switch to the new namespace:

```js
import commonEvent from '@ohos.commonEventManager';
```

**@ohos.notification** is split into two namespaces. You need to select a new namespace for adaptation.

In addition, exception handling is needed. For details, see the API reference for the new APIs.
