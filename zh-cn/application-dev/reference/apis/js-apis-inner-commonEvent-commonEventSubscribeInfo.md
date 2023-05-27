# CommonEventSubscribeInfo

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力：** `SystemCapability.Notification.CommonEvent`

| 名称                | 类型           | 可读 | 可写 | 说明                                                         |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | 是  | 否  | 表示要发送的公共事件。                                         |
| publisherPermission | string         | 是  | 否  | 表示发布者的权限。                                             |
| publisherDeviceId   | string         | 是  | 否  | 表示设备ID，该值必须是同一ohos网络上的现有设备ID。             |
| userId              | number         | 是  | 否  | 表示用户ID。此参数是可选的，默认值当前用户的ID。如果指定了此参数，则该值必须是系统中现有的用户ID。 |
| priority            | number         | 是  | 否  | 表示订阅者的优先级。值的范围是-100到1000。                     |