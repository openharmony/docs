# 事件通知子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，事件通知子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.commonEvent  | Support      | COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT"                                                                                                                                             | 新增 |
| ohos.commonEvent  | Support      | COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED"                                                                                                                                     | 新增 |
| ohos.commonEvent  | Support      | COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE"                                                                                                                                                   | 新增 |
| ohos.commonEvent  | Support      | COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED"                                                                                                                                               | 新增 |
| ohos.notification | RemoveReason | CANCEL_REASON_REMOVE = 2                                                                                                                                                                                               | 新增 |
| ohos.notification | RemoveReason | CLICK_REASON_REMOVE = 1                                                                                                                                                                                                | 新增 |
| ohos.notification | notification | function getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>function getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>;                          | 新增 |
| ohos.notification | notification | function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>; | 新增 |
| ohos.notification | notification | function getSyncNotificationEnabledForUninstallApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>function getSyncNotificationEnabledForUninstallApp(userId: number): Promise\<boolean>;                          | 删除 |
| ohos.notification | notification | function setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>function setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean): Promise\<void>; | 删除 |