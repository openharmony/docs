# 事件通知子系统ChangeLog

## cl.notification.1 删除标记为废弃的API9接口

[事件通知异常处理整改](../OpenHarmony_3.2.8.3/changelogs-notification.md)将部分API9接口标记为了废弃，根据OpenHarmony接口规范，需要删除标记为废弃的API9接口。

**变更影响**

基于此前版本开发的应用，需要将被删除的接口替换为新接口，否则会影响应用编译。

**关键接口/组件变更**

原接口中标记为废弃的API9接口将被删除，可以使用新接口中的同名接口替换。

| 原接口                  | 新接口                           |
| ----------------------- | -------------------------------- |
| @ohos.commonEvent.d.ts  | @ohos.commonEventManager.d.ts    |
| @ohos.notification.d.ts | @ohos.notificationManager.d.ts   |
| @ohos.notification.d.ts | @ohos.notificationSubscribe.d.ts |

接口、属性被删除：

- @ohos.notification.d.ts
  - 接口 publishAsBundle、cancelAsBundle、isNotificationSlotEnabled、setSyncNotificationEnabledWithoutApp、getSyncNotificationEnabledWithoutApp 被删除。可以使用 api/@ohos.notificationManager.d.ts 的同名接口替换。
  - 接口 enableNotificationSlot 被删除。可以使用 api/@ohos.notificationManager.d.ts 的接口 setNotificationEnableSlot 替换。
  - 导出类 NotificationActionButton、NotificationBasicContent、NotificationContent、NotificationLongTextContent、NotificationMultiLineContent、NotificationPictureContent、NotificationFlags、NotificationFlagStatus、NotificationRequest、DistributedOptions、NotificationSlot、NotificationSorting、NotificationTemplate、NotificationUserInput 被删除。可以使用 api/@ohos.notificationManager.d.ts 的同名导出类替换。
  - 导出类 NotificationSubscribeInfo、NotificationSubscriber、SubscribeCallbackData、EnabledNotificationCallbackData 被删除。可以使用 api/@ohos.notificationSubscribe.d.ts 的同名导出类替换。

**适配指导**

如上所述，仅将老接口平移到了新的namespace中，所以可以通过修改import来解决适配问题：

如原先接口使用了@ohos.commonEvent

```js
import commonEvent from '@ohos.commonEvent';
```

可以通过直接修改import，来切换到新的namespace上：

```js
import commonEvent from '@ohos.commonEventManager';
```

@ohos.notification拆分成了两个namespace，需要根据接口情况选择需要的新namespace进行适配。

此外还需要适配异常处理，具体参考新接口的接口文档。

