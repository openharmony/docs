# JS API Changes of the Common Event and Notification Subsystem

The table below lists the APIs changes of the common event and notification subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.commonEvent  | Support      | COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT"                                                                                                                                             | Added|
| ohos.commonEvent  | Support      | COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED"                                                                                                                                     | Added|
| ohos.commonEvent  | Support      | COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE"                                                                                                                                                   | Added|
| ohos.commonEvent  | Support      | COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED"                                                                                                                                               | Added|
| ohos.notification | RemoveReason | CANCEL_REASON_REMOVE = 2                                                                                                                                                                                               | Added|
| ohos.notification | RemoveReason | CLICK_REASON_REMOVE = 1                                                                                                                                                                                                | Added|
| ohos.notification | notification | function getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>function getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>;                          | Added|
| ohos.notification | notification | function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>; | Added|
| ohos.notification | notification | function getSyncNotificationEnabledForUninstallApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>function getSyncNotificationEnabledForUninstallApp(userId: number): Promise\<boolean>;                          | Deleted|
| ohos.notification | notification | function setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>function setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean): Promise\<void>; | Deleted|
