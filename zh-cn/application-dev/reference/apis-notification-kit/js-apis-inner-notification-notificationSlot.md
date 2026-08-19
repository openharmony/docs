# NotificationSlot
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

描述[通知渠道](../../notification/notification-glossary.md#notification-slot通知渠道)，不同通知渠道对应的[通知提醒方式](../../notification/notification-glossary.md#notification-reminder-mode通知提醒方式)不同。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationSlot

**系统能力：** SystemCapability.Notification.Notification

| 名称                 | 类型                 | 只读 | 可选 | 说明                   |
| -------------------- | ---------------------|---- | --- |----------------------|
| notificationType<sup>11+</sup>                 | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) | 否 | 是  | 渠道类型。不同渠道类型的[通知提醒方式](../../notification/notification-glossary.md#notification-reminder-mode通知提醒方式)不同。 |
| enabled<sup>9+</sup> | boolean               | 是 | 是  | 是否允许发布此[通知渠道](../../notification/notification-glossary.md#notification-slot通知渠道)类型的通知。<br> - true：允许发布通知。<br> - false：禁止发布通知。   |
| notificationLevel<sup>20+</sup>                 | [notificationManager.SlotLevel](js-apis-notificationManager.md#slotlevel) | 否 | 是  | 通知级别，用于描述该渠道类型通知的显示优先级和提醒强度。           |
| desc                 | string                | 否 | 是  | 通知渠道描述信息。大小不超过243字节，超出部分会被截断。 |
| badgeFlag            | boolean               | 否 | 是  | 是否显示角标。默认值为true。<br> - true：显示角标。<br> - false：不显示角标。              |
| bypassDnd            | boolean               | 否 | 是  | 是否在系统中绕过[免打扰模式](../../notification/notification-glossary.md#do-not-disturb-mode免打扰模式)。默认值为false。<br> - true：绕过免打扰模式，免打扰模式下仍会提醒。<br> - false：不绕过免打扰模式，免打扰模式下不提醒。      |
| vibrationEnabled     | boolean               | 否 | 是  | 是否可振动。默认值为false。<br> - true：可振动。<br> - false：不可振动。                  |
| sound                | string                | 否 | 是  | 该渠道的通知的[自定义铃声](../../notification/notification-glossary.md#customized-ringtone自定义铃声)文件名。该文件放在resources/rawfile目录下，支持m4a、aac、mp3、ogg、wav、flac、amr等格式。大小不超过243字节，超出部分会被截断。 |
| lightEnabled         | boolean               | 否 | 是  | 是否闪灯。默认值为false。<br> - true：闪灯。<br> - false：不闪灯。                        |
| type<sup>(deprecated)</sup> | [notification.SlotType](js-apis-notification.md#slottype) | 否 | 是  | 渠道类型。<br>从API version 7开始支持，从API version 11开始废弃，建议使用notificationType替代。        |
| level<sup>(deprecated)</sup> | [notification.SlotLevel](js-apis-notificationManager.md#slotlevel) | 否 | 是  | 通知级别。<br>从API version 7开始支持，从API version 20开始废弃，建议使用notificationLevel替代。 |
| lockscreenVisibility | number                | 否 | 是  | 在锁定屏幕上显示通知的模式。预留能力，暂不支持。 |
| lightColor           | number                | 否 | 是  | 通知灯颜色。预留能力，暂不支持。                |
| vibrationValues      | Array\<number\>       | 否 | 是  | 通知振动样式。预留能力，暂不支持。              |
