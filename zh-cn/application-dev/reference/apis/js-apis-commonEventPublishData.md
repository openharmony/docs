# 公共事件内容和属性

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CommonEventPublishData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                  | 读写属性 | 类型                 | 必填 | 描述                         |
| --------------------- | -------- | -------------------- | ---- | ---------------------------- |
| bundleName            | 只读     | string               | 否   | 表示包名称。                   |
| code                  | 只读     | number               | 否   | 表示公共事件的结果代码。       |
| data                  | 只读     | string               | 否   | 表示公共事件的自定义结果数据。 |
| subscriberPermissions | 只读     | Array\<string>       | 否   | 表示订阅者的权限。             |
| isOrdered             | 只读     | boolean              | 否   | 表示是否是有序事件。           |
| isSticky              | 只读     | boolean              | 否   | 表示是否是粘性事件。           |
| parameters            | 只读     | {[key: string]: any} | 否   | 表示公共事件的附加信息。       |

