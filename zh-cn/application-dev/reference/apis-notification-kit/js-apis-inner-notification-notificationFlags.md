# NotificationFlags
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

描述[通知标志位](../../notification/notification-glossary.md#notification-flags通知标志位)。应用可以使用`NotificationFlags`按需削减通知的提醒方式。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationFlags

描述[通知标志位](../../notification/notification-glossary.md#notification-flags通知标志位)。

**系统能力**：SystemCapability.Notification.Notification

| 名称             | 类型                    | 只读 | 可选 | 说明                                         |
| ---------------- | ---------------------- | ---- | -----|-------------------------------------------- |
| soundEnabled     | [NotificationFlagStatus](#notificationflagstatus11) | 否  | 是 | 是否启用声音提示功能。默认值为TYPE_NONE。从API version 23开始成为可写参数，设置时仅[TYPE_CLOSE](#notificationflagstatus11)会生效。    |
| vibrationEnabled | [NotificationFlagStatus](#notificationflagstatus11) | 否  | 是 | 是否启用振动提醒功能。默认值为TYPE_NONE。从API version 23开始成为可写参数，设置时仅[TYPE_CLOSE](#notificationflagstatus11)会生效。 |
| bannerEnabled<sup>23+</sup> | [NotificationFlagStatus](#notificationflagstatus11) | 否  | 是 | 是否启用横幅功能。默认值为TYPE_NONE。设置时仅[TYPE_CLOSE](#notificationflagstatus11)会生效。 |
| lockScreenEnabled<sup>23+</sup> | [NotificationFlagStatus](#notificationflagstatus11) | 否  | 是 | 是否启用锁屏功能。默认值为TYPE_NONE。设置时仅[TYPE_CLOSE](#notificationflagstatus11)会生效。 |


## NotificationFlagStatus<sup>11+</sup>

描述通知标志状态。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 值  | 说明                               |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | 未设置标志时的默认值，与TYPE_OPEN效果相同。     |
| TYPE_OPEN      | 1   | 通知标志打开。                     |
| TYPE_CLOSE     | 2   | 通知标志关闭。                     |
