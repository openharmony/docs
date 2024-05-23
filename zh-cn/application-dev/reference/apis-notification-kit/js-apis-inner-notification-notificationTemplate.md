# NotificationTemplate

通知模板。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称 | 类型                    | 必填 | 说明       |
| ---- | ---------------------- | ---- | ---------- |
| name | string                 | 是   | 模板名称。当前仅支持'downloadTemplate'：下载模板。|
| data | {[key:string]: Object} | 是   | 模板数据。 |
