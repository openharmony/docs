# CommonEventSubscribeInfo
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

用于表示公共事件订阅者的信息，支持配置订阅的公共事件类型、发布者权限、发布者设备ID、用户ID、订阅优先级等参数，适用于应用需要订阅[系统公共事件](../../basic-services/common-event/common-event-glossary.md#system-common-event系统公共事件)或自定义公共事件并精细化控制事件来源的场景。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 订阅自定义公共事件后，任意应用都可以向订阅者发送潜在的恶意公共事件。通过本模块的publisherPermission和publisherBundleName参数，可以限制公共事件发布者的范围。

## 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** `SystemCapability.Notification.CommonEvent`

| 名称                | 类型           | 只读 | 可选 | 说明                                                         |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | 否  | 否  | 表示要订阅的公共事件列表。                                         |
| publisherPermission | string         | 否  | 是  | 表示发布者的权限，取值为系统已定义的权限名。用于限制订阅方只接收具有该权限的发布方发布的公共事件。不设置时，可接收所有发布方发布的公共事件。                                             |
| publisherDeviceId   | string         | 否  | 是  | 表示设备ID，用于限制订阅者只接收来自指定设备发布的公共事件。通过[@ohos.deviceInfo](js-apis-device-info.md)获取udid，作为发布者的设备ID。预留能力，暂不支持。         |
| userId              | number         | 否  | 是  | 表示用户ID，用于限制订阅者只接收指定用户ID相关的公共事件。此参数是可选的，默认值为当前用户的ID。如果指定了此参数，则该值必须是系统中现有的用户ID。通过[getOsAccountLocalId](./js-apis-osAccount.md#getosaccountlocalid9)获取系统用户ID，作为发布者的用户ID。 |
| priority            | number         | 否  | 是  | 表示订阅者的优先级，数值越大，订阅者优先级越高，越优先接收到[有序公共事件](../../basic-services/common-event/common-event-glossary.md#ordered-common-event有序公共事件)。取值范围是-100到1000，超过上下限的优先级将被设置为对应的上下限值，默认优先级为0。                 |
| publisherBundleName<sup>11+</sup> | string  | 否  | 是  | 表示要订阅的发布者的bundleName，用于限制订阅方只接收该bundleName的发布者发布的公共事件。不设置时，可接收所有应用发布的公共事件。                 |
