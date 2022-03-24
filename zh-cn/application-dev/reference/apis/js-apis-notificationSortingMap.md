# 通知排序

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

已订阅的所有通知中的活动通知的排序信息。

## NotificationSortingMap

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型                                                         | 必填 | 描述             |
| -------------- | ---- | --- | ------------------------------------------------------------ | ---- | ---------------- |
| sortings       | 是  | 否  | {[key: string]: [NotificationSorting](#notificationsorting)} | 是   | 通知排序信息数组。 |
| sortedHashCode | 是  | 否  | Array\<string\>                                              | 是   | 通知唯一标识数组。 |