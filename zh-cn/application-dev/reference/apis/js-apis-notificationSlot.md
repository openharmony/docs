# NotificationSlot

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## NotificationSlot

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 可读 | 可写 | 类型                  | 必填 | 描述                                       |
| -------------------- | ---- | --- | --------------------- | ---- | ------------------------------------------ |
| type                 | 是  | 是  | [SlotType](#slottype) | 是   | 通道类型。                                   |
| level                | 是  | 是  | number                | 否   | 通知级别，不设置则根据通知渠道类型有默认值。 |
| desc                 | 是  | 是  | string                | 否   | 通知渠道描述信息。                           |
| badgeFlag            | 是  | 是  | boolean               | 否   | 是否显示角标。                               |
| bypassDnd            | 是  | 是  | boolean               | 否   | 置是否在系统中绕过免打扰模式。               |
| lockscreenVisibility | 是  | 是  | boolean               | 否   | 在锁定屏幕上显示通知的模式。                 |
| vibrationEnabled     | 是  | 是  | boolean               | 否   | 是否可振动。                                 |
| sound                | 是  | 是  | string                | 否   | 通知提示音。                                 |
| lightEnabled         | 是  | 是  | boolean               | 否   | 是否闪灯。                                   |
| lightColor           | 是  | 是  | number                | 否   | 通知灯颜色。                                 |
| vibrationValues      | 是  | 是  | Array\<number\>       | 否   | 通知振动样式。                               |