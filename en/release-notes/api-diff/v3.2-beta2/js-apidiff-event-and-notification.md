# JS API Changes of the Common Event and Notification Subsystem

The table below lists the APIs changes of the common event and notification subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| notificationRequest | NotificationRequest | badgeNumber?: number; | Added|
| notificationRequest | NotificationRequest | removalWantAgent?: WantAgent; | Added|
| ohos.commonEvent | Support | COMMON_EVENT_SPN_INFO_CHANGED = "usual.event.SPN_INFO_CHANGED" | Added|
| ohos.commonEvent | Support | COMMON_EVENT_SLOT_CHANGE = "usual.event.SLOT_CHANGE" | Added|
| ohos.notification | notification | getSyncNotificationEnabledForUninstallApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>getSyncNotificationEnabledForUninstallApp(userId: number): Promise\<boolean>; | Added|
| ohos.notification | notification | setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean): Promise\<void>; | Added|
