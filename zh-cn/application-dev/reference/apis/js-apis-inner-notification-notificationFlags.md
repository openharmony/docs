# NotificationFlags

描述通知标志的实例。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称             | 类型                    | 只读 | 必填 | 说明                               |
| ---------------- | ---------------------- | ---- | ---- | --------------------------------- |
| soundEnabled     | [NotificationFlagStatus](#notificationflagstatus) | 是   | 否   | 是否启用声音提示。                  |
| vibrationEnabled | [NotificationFlagStatus](#notificationflagstatus) | 是   | 否   | 是否启用振动提醒功能。               |


## NotificationFlagStatus

描述通知标志状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 名称           | 值  | 说明                               |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | 默认标志。                         |
| TYPE_OPEN      | 1   | 通知标志打开。                     |
| TYPE_CLOSE     | 2   | 通知标志关闭。                     |
