# NotificationSlot

描述通知槽

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 类型                  | 可读 | 可写 | 说明                                       |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| type                 | [SlotType](js-apis-notificationManager.md#slottype) | 是  | 是  | 通道类型。                                   |
| level                | number                | 是  | 是  | 通知级别，不设置则根据通知渠道类型有默认值。 |
| desc                 | string                | 是  | 是  | 通知渠道描述信息。                           |
| badgeFlag            | boolean               | 是  | 是  | 是否显示角标。                               |
| bypassDnd            | boolean               | 是  | 是  | 置是否在系统中绕过免打扰模式。               |
| lockscreenVisibility | number                | 是  | 是  | 在锁定屏幕上显示通知的模式。                 |
| vibrationEnabled     | boolean               | 是  | 是  | 是否可振动。                                 |
| sound                | string                | 是  | 是  | 通知提示音。                                 |
| lightEnabled         | boolean               | 是  | 是  | 是否闪灯。                                   |
| lightColor           | number                | 是  | 是  | 通知灯颜色。                                 |
| vibrationValues      | Array\<number\>       | 是  | 是  | 通知振动样式。                               |
| enabled<sup>9+</sup> | boolean               | 是  | 否  | 此通知插槽中的启停状态。                      |
