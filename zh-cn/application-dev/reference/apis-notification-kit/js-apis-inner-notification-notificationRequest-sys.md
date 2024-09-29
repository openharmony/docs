# NotificationRequest(系统接口)

描述通知的请求。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationRequest](./js-apis-inner-notification-notificationRequest.md)。

## NotificationRequest

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 可选 | 说明                                                                    |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| overlayIcon<sup>11+</sup>      | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   否  | 是  | 通知重叠图标。可选字段，图像像素的总字节数不超过100KB。<br>**系统接口**: 此接口为系统接口。                                                 |
| classification                | string                                                   |   否  | 是  | 通知分类。<br>**系统接口**: 此接口为系统接口。预留能力，暂未支持。                               |
| isRemoveAllowed<sup>8+</sup>   | boolean                                                  |   否  | 是  | 通知是否能被移除（点击通知下方删除按钮无法删除，左滑不出现删除按钮）。<br>**系统接口**: 此接口为系统接口。<br>**需要权限**: ohos.permission.SET_UNREMOVABLE_NOTIFICATION |
| source<sup>8+</sup>            | number                                                   |   是  | 是  | 通知源。<br>**系统接口**: 此接口为系统接口。预留能力，暂未支持。                                |
| deviceId<sup>8+</sup>          | string                                                   |   是  | 是  | 通知源的deviceId。<br>**系统接口**: 此接口为系统接口。预留能力，暂未支持。                       |
| representativeBundle<sup>12+</sup> | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 否 | 是 | 被代理的包信息。<br>**系统接口**: 此接口为系统接口。 |
| notificationControlFlags<sup>12+</sup>       | number                                                   |   否  | 是  | 通知提醒方式管控。<br>可以通过此接口减少当前通知的提醒方式。与[NotificationControlFlagStatus](js-apis-notificationManager-sys.md#notificationcontrolflagstatus12)的枚举进行按位或运算得到该参数。<br>**系统接口**：此接口为系统接口。            |
| unifiedGroupInfo<sup>12+</sup>       | [UnifiedGroupInfo](#unifiedgroupinfo12) |   否  | 是  |消息智能聚合信息字段。 <br>**系统接口**：此接口为系统接口。|
| creatorInstanceKey<sup>12+</sup>       | number |   是  | 是  | 创建者实例键值。 <br>**系统接口**：此接口为系统接口。|
| agentBundle<sup>12+</sup>       | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) |   是  | 是  | 创建通知的代理包信息。 <br>**系统接口**：此接口为系统接口。|

## DistributedOptions

描述分布式选项。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                   | 类型            | 必填 | 说明                               |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| remindType<sup>8+</sup>             | number         | 否   | 通知的提醒方式。<br>**系统接口**: 此接口为系统接口。  |


## NotificationFilter<sup>11+</sup>

描述查询普通实况窗时的筛选条件。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称            | 类型                                   | 必填 | 说明                               |
| ----------------| ------------------------------------- | ---- | ---------------------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 实况通知的包信息。|
| notificationKey | [NotificationKey](js-apis-notificationSubscribe-sys.md#notificationkey) | 是   | 通知信息，包含通知ID和通知标签。   |
| extraInfoKeys   | Array\<string>                        | 否   | 筛选附加信息的键值列表。不填表示查询所有的附加信息。|


## NotificationCheckRequest<sup>11+</sup>

描述通知的鉴权信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称          | 类型                                                       | 必填 | 说明              |
| --------------| --------------------------------------------------------- | ---- | ----------------- |
| contentType   | [ContentType](js-apis-notificationManager.md#contenttype) | 是   | 通知类型。         |
| slotType      | [SlotType](js-apis-notificationManager.md#slottype)       | 是   | 渠道类型。         |
| extraInfoKeys | Array\<string>                                            | 是   | 实况通知的附加信息。|

## UnifiedGroupInfo<sup>12+</sup>

描述通知智能聚合信息字段。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口。

| 名称                   | 类型            | 必填 | 说明                               |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| key          | string        | 否   | 聚合组ID。                   |
| title  | string | 否   | 聚合组标题。            |
| content  | string | 否   | 聚合组摘要正文。              |
| sceneName          | string        | 否   | 聚合场景名称。                   |
| extraInfo  | {[key: string]: any} | 否   | 其他聚合信息。            |
