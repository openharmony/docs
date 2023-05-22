# CommonEventPublishData

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力：** `SystemCapability.Notification.CommonEvent`

| 名称                  | 类型                 | 可读 | 可写 | 说明                         |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | 是  | 否  | 表示包名称。                   |
| code                  | number               | 是  | 否  | 表示公共事件的结果代码。       |
| data                  | string               | 是  | 否  | 表示公共事件的自定义结果数据。 |
| subscriberPermissions | Array\<string>       | 是  | 否  | 表示订阅者的权限。             |
| isOrdered             | boolean              | 是  | 否  | 表示是否是有序事件。           |
| isSticky              | boolean              | 是  | 否  | 表示是否是粘性事件。仅系统应用或系统服务允许发送粘性事件。 |
| parameters            | {[key: string]: any} | 是  | 否  | 表示公共事件的附加信息。       |