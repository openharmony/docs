# 通知标志

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationFlagStatus

通知标志的状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 值  | 描述                               |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | 默认标志。                         |
| TYPE_OPEN      | 1   | 通知标志打开。                     |
| TYPE_CLOSE     | 2   | 通知标志关闭。                     |


## NotificationFlags

NotificationFlags实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称             | 可读 | 可写 | 类型                    | 必填 | 描述                               |
| ---------------- | ---- | ---- | ---------------------- | ---- | --------------------------------- |
| soundEnabled     | 是   | 否   | NotificationFlagStatus | 否   | 是否启用声音提示。                  |
| vibrationEnabled | 是   | 否   | NotificationFlagStatus | 否   | 是否启用振动提醒功能。               |