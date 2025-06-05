# NotificationActionButton

描述通知中显示的操作按钮。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 属性

**系统能力：** SystemCapability.Notification.Notification

| 名称      | 类型                                            | 只读 | 可选 | 说明                      |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | 否  | 否  | 按钮标题。字符串长度不超过200字节，超出部分会被截断；也不可为空字符串。                  |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)   | 否  | 否  | 点击按钮时触发的WantAgent。 |
| extras    | { [key: string]: any }                          | 否  | 是  | 按钮扩展信息。预留能力，暂未支持。              |
| userInput<sup>8+</sup> | [NotificationUserInput](js-apis-inner-notification-notificationUserInput.md) | 否  | 是  | 用户输入对象实例。表示用户输入时的标识。          |
