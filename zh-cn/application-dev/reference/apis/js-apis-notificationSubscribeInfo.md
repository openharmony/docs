# 订阅通知的过滤条件

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

设置发布者订阅所需通知的过滤条件。

## NotificationSubscribeInfo

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称        | 可读 | 可写 | 类型            | 必填 | 描述                            |
| ----------- | --- | ---- | --------------- | ---- | ------------------------------- |
| bundleNames | 是  | 是  | Array\<string\> | 否   | 指定订阅哪些包名的APP发来的通知。 |
| userId      | 是  | 是  | number          | 否   | 指定订阅哪个用户下发来的通知。    |