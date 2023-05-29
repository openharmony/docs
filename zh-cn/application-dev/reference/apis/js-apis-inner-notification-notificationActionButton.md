# NotificationActionButton

描述通知中显示的操作按钮。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称      | 类型                                            | 只读 | 必填 | 说明                      |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | 否  | 是  | 按钮标题。                  |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md)   | 否  | 是  | 点击按钮时触发的WantAgent。 |
| extras    | { [key: string]: any }                          | 否  | 否  | 按钮扩展信息。              |
| userInput<sup>8+</sup> | [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md) | 否  | 否  | 用户输入对象实例。          |
