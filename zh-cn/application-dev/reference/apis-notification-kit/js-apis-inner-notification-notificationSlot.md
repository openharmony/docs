# NotificationSlot

描述通知槽。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationSlot

**系统能力：** SystemCapability.Notification.Notification

| 名称                 | 类型                 | 只读 | 可选 | 说明                   |
| -------------------- | ---------------------|---- | --- |----------------------|
| type<sup>(deprecated)</sup> | [notification.SlotType](js-apis-notification.md#slottype) | 否 | 是  | 通道类型。<br>从API version 11开始不再维护，建议使用notificationType代替。                |
| notificationType<sup>11+</sup>                 | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) | 否 | 是  | 通道类型。                |
| level                | [notification.SlotLevel](../apis-notification-kit/js-apis-notificationManager.md#slotlevel)                | 否 | 是  | 通知级别。 |
| desc                 | string                | 否 | 是  | 通知渠道描述信息。            |
| badgeFlag            | boolean               | 否 | 是  | 是否显示角标。              |
| bypassDnd            | boolean               | 否 | 是  | 是否在系统中绕过免打扰模式。       |
| lockscreenVisibility | number                | 否 | 是  | 在锁定屏幕上显示通知的模式。预留能力，暂不支持。       |
| vibrationEnabled     | boolean               | 否 | 是  | 是否可振动。               |
| sound                | string                | 否 | 是  | 通知提示音。               |
| lightEnabled         | boolean               | 否 | 是  | 是否闪灯。                |
| lightColor           | number                | 否 | 是  | 通知灯颜色。预留能力，暂不支持。               |
| vibrationValues      | Array\<number\>       | 否 | 是  | 通知振动样式。预留能力，暂不支持。              |
| enabled<sup>9+</sup> | boolean               | 是 | 是  | 此通知插槽中的启停状态。true表示使能；false表示禁止。         |
