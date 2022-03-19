# 在通知中显示的操作按钮。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationActionButton

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称      | 可读 | 可写 | 类型                                            | 必填 | 描述                      |
| --------- | --- | ---- | ----------------------------------------------- | ---- | ------------------------- |
| title     | 是  | 是  | string                                          | 是   | 按钮标题。                  |
| wantAgent | 是  | 是  | WantAgent                                       | 是   | 点击按钮时触发的WantAgent。 |
| extras    | 是  | 是  | { [key: string]: any }                          | 否   | 按钮扩展信息。              |
| userInput\<sup>9+</sup> | 是  | 是  | [NotificationUserInput](#notificationuserinput) | 否   | 用户输入对象实例。          |