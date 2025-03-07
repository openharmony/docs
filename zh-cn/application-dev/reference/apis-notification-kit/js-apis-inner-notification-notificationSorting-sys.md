# NotificationSorting(系统接口)

提供有关活动通知的排序信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 属性

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：以下为系统接口，三方应用不支持调用。

| 名称      | 类型              | 只读   | 可选 | 说明                     |
|-----------| ---------------- | -------|----- |-------------------------|
| slot        | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是 | 否 | 通道类型。                  |
| ranking     | number                                                             | 是 | 否 | 通知级别，不设置则根据通知渠道类型有默认值。 |
| hashCode    | string                                                             | 是 | 否 | 通知唯一标识。                |
