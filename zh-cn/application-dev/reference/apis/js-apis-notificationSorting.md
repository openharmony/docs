# 活跃通知排序

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

活跃通知的排序信息。

## NotificationSorting

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称     | 可读 | 可写 | 类型                                  | 必填 | 描述         |
| -------- | ---- | --- | ------------------------------------- | ---- | ------------ |
| slot     | 是  | 否  | [NotificationSlot](#notificationslot) | 是   | 通知通道内容。 |
| hashCode | 是  | 否  | string                                | 是   | 通知唯一标识。 |
| ranking  | 是  | 否  | number                                | 是   | 通知排序序号。 |