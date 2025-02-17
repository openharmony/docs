# CommonEventPublishData

包含公共事件内容和属性。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 如果不加限制，任何应用都可以订阅公共事件并读取相关信息，应避免在公共事件中携带敏感信息。通过本模块的subscriberPermissions和bundleName参数，可以限制公共事件接收方的范围。

## 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                  | 类型                 | 只读 | 可选 | 说明                         |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | 否  | 是  | 表示订阅者包名称，只有包名为bundleName的订阅者才能收到该公共事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| code                  | number               | 否  | 是  | 表示公共事件的结果代码。默认值为0。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| data                  | string               | 否  | 是  | 表示公共事件的自定义结果数据。数据大小不超过64KB。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| subscriberPermissions | Array\<string>       | 否  | 是  | 表示订阅者的权限。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| isOrdered             | boolean              | 否  | 是  | 表示是否是有序事件。           |
| isSticky              | boolean              | 否  | 是  | 表示是否是粘性事件。仅系统应用或系统服务允许发送粘性事件。 |
| parameters            | {[key: string]: any} | 否  | 是  | 表示公共事件的附加信息。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |