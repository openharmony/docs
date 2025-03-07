# NotificationTemplate

通知模板。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 属性

**系统能力**：SystemCapability.Notification.Notification

| 名称 | 类型                   | 只读 | 可选 | 说明       |
| ---- | ---------------------- | ---- | ----|----------- |
| name | string                 | 否 | 否   | 模板名称。当前仅支持'downloadTemplate'：下载模板。|
| data | Record<string, Object> | 否 | 否   | 模板数据。<br> - title: 表示下载标题。必填字段，值为字符串类型。<br> - fileName: 表示下载文件名。必填字段，值为字符串类型。<br> - progressValue: 表示下载进度，值为数值类型。 |
