# NotificationSorting

提供有关活动通知的排序信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 以下为系统接口，三方应用不支持调用。

| 名称                 | 类型                  | 只读 | 必填 | 说明                                       |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| slot                 | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是  | 是  | 通道类型。                                   |
| level                | number                | 是  | 是  | 通知级别，不设置则根据通知渠道类型有默认值。 |
| desc                 | string                | 是  | 是  | 通知渠道描述信息。                           |
