# 事件通知子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，事件通知子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| notificationRequest | NotificationRequest | badgeNumber?: number; | 新增 |
| notificationRequest | NotificationRequest | removalWantAgent?: WantAgent; | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_SPN_INFO_CHANGED = "usual.event.SPN_INFO_CHANGED" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_SLOT_CHANGE = "usual.event.SLOT_CHANGE" | 新增 |
| ohos.notification | notification | getSyncNotificationEnabledForUninstallApp(userId: number, callback: AsyncCallback\<boolean>): void;<br>getSyncNotificationEnabledForUninstallApp(userId: number): Promise\<boolean>; | 新增 |
| ohos.notification | notification | setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean, callback: AsyncCallback\<void>): void;<br>setSyncNotificationEnabledForUninstallApp(userId: number, enable: boolean): Promise\<void>; | 新增 |

