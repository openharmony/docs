# NotificationSortingMap(系统接口)

提供有关已订阅的所有通知中的活动通知的排序信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 属性

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：以下为系统接口，三方应用不支持调用。

| 名称        | 类型     | 只读 | 必填 | 说明                                       |
| ----------- | ------- | --- | ----- |------------------------------------------ |
| sortings    | Record<string, [NotificationSorting](js-apis-inner-notification-notificationSorting-sys.md)\> | 是 | 是  | 通知排序信息。                                   |
| sortedHashCode | Array<string\> | 是 | 是  | 通知排序的HashCode。 |
