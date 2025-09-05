# NotificationRequest(系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

描述通知的请求。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationRequest](./js-apis-inner-notification-notificationRequest.md)。

## NotificationRequest

**系统能力**：SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 可选 | 说明                                                                    |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| overlayIcon<sup>11+</sup>      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)             |   否  | 是  | 通知重叠图标。图像像素的总字节数不超过192KB。<br>**系统接口**：此接口为系统接口。                                                 |
| classification                | string                                                   |   否  | 是  | 通知分类。<br>**系统接口**：此接口为系统接口。预留能力，暂未支持。                               |
| isRemoveAllowed<sup>8+</sup>   | boolean                                                  |   否  | 是  | 通知是否能被移除（点击通知下方删除按钮无法删除，左滑不出现删除按钮）。默认为false。<br> - true：是。<br> - false：否。<br>**系统接口**：此接口为系统接口。<br>**需要权限**：ohos.permission.SET_UNREMOVABLE_NOTIFICATION |
| source<sup>8+</sup>            | number                                                   |   是  | 是  | 通知源。<br>**系统接口**：此接口为系统接口。预留能力，暂未支持。                                |
| deviceId<sup>8+</sup>          | string                                                   |   是  | 是  | 通知源的deviceId。<br>**系统接口**：此接口为系统接口。预留能力，暂未支持。                       |
| representativeBundle<sup>12+</sup> | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 否 | 是 | 被代理的包信息。<br>**系统接口**：此接口为系统接口。 |
| notificationControlFlags<sup>12+</sup>       | number                                                   |   否  | 是  | 通知提醒方式管控。<br>可以通过此接口减少当前通知的提醒方式。与[NotificationControlFlagStatus](js-apis-notificationManager-sys.md#notificationcontrolflagstatus12)的枚举进行按位或运算得到该参数。<br>**系统接口**：此接口为系统接口。            |
| unifiedGroupInfo<sup>12+</sup>       | [UnifiedGroupInfo](#unifiedgroupinfo12) |   否  | 是  |消息智能聚合信息字段。 <br>**系统接口**：此接口为系统接口。|
| creatorInstanceKey<sup>(deprecated)</sup>      | number |   是  | 是  | 创建者实例键值。 <br>**系统接口**：此接口为系统接口。|
| agentBundle<sup>12+</sup>       | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) |   是  | 是  | 创建通知的代理包信息。 <br>**系统接口**：此接口为系统接口。|
| appInstanceKey<sup>15+</sup>       | string |   是  | 是  | 应用实例键值。 <br>**系统接口**：此接口为系统接口。|
| notDistributed<sup>18+</sup> | boolean | 否 | 是 | 通知是否不进行全场景跨设备协同显示，默认为false。<br/>**说明**:<br/>该字段与forceDistributed字段互斥，当两者同时配置时，仅notDistributed字段生效。<br/>-&nbsp;设置为true时：通知仅在本设备上显示。<br/>-&nbsp;设置为false时：通知将在所有协同设备上显示。<br>**系统接口**: 此接口为系统接口。 |
| forceDistributed<sup>18+</sup> | boolean | 否 | 是 | 通知是否强制进行全场景跨设备协同显示，默认为false。<br/>**说明**:<br/>仅当应用在跨设备协同管控名单中且未配置notDistributed字段时，该字段才会生效。通过读取notification_config.json文件（文件配置路径见：[notification_config_parse.h](https://gitee.com/openharmony/notification_distributed_notification_service/blob/master/services/ans/include/notification_config_parse.h) 中的NOTIFICAITON_CONFIG_FILE属性）中的collaborationFilter字段，查看是否包含应用的UID或包名。如果包含，说明是在应用跨设备协同管控名单中。<br>-&nbsp;设置为true时：通知将在所有协同设备上显示。<br/>-&nbsp;设置为false时：通知将按照协同管控名单显示。<br>**系统接口**: 此接口为系统接口。 |
| extendInfo<sup>20+</sup> | Record<string, Object> | 否 | 是 | 系统应用发布通知时的自定义扩展参数。<br>**系统接口**: 此接口为系统接口。 |

## DistributedOptions<sup>8+</sup>

描述分布式选项。

**系统能力**：SystemCapability.Notification.Notification

| 名称                    | 类型           | 只读 | 可选 | 说明                               |
| ---------------------- | -------------- | ---- | ---- | ---------------------------------- |
| remindType             | number         |  是  |  是   | 通知的提醒方式。<br>**系统接口**：此接口为系统接口。  |


## NotificationFilter<sup>11+</sup>

描述查询普通实况窗时的筛选条件。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称            | 类型                                   | 只读 | 可选 | 说明                               |
| ----------------| ------------------------------------- | ---- | ---- | ---------------------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 否 | 否   | 实况通知的包信息。|
| notificationKey | [notificationSubscribe.NotificationKey](js-apis-notificationSubscribe-sys.md#notificationkey) | 否 | 否   | 通知信息，包含通知ID和通知标签。   |
| extraInfoKeys   | Array\<string>                        | 否 |   是   | 筛选附加信息的键值列表。不填表示查询所有的附加信息。|


## NotificationCheckRequest<sup>11+</sup>

描述通知的鉴权信息。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称          | 类型                                                       | 只读 | 可选 | 说明              |
| --------------| --------------------------------------------------------- | ---- | ---- | ----------------- |
| contentType   | [notificationManager.ContentType](js-apis-notificationManager.md#contenttype) | 否 | 否   | 通知类型。         |
| slotType      | [notificationManager.SlotType](js-apis-notificationManager.md#slottype)       | 否 | 否   | 渠道类型。         |
| extraInfoKeys | Array\<string>                                            | 否 | 否 | 实况通知的附加信息。|

## UnifiedGroupInfo<sup>12+</sup>

描述通知智能聚合信息字段。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                   | 类型            | 只读 | 可选 | 说明                               |
| ---------------------- | -------------- | ---- | ---- | ---------------------------------- |
| key          | string        | 否 | 是   | 聚合组ID。                   |
| title  | string | 否 | 是   | 聚合组标题。            |
| content  | string | 否 | 是   | 聚合组摘要正文。              |
| sceneName          | string        | 否 | 是   | 聚合场景名称。                   |
| extraInfo  | {[key: string]: any} | 否 |  是   | 其他聚合信息。            |
