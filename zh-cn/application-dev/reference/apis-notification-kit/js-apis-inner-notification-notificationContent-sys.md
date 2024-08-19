# NotificationContent(系统接口)

描述通知类型。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationContent](./js-apis-inner-notification-notificationContent.md)。

## NotificationContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | 否  | 是  | 普通实况窗类型通知内容。<br>**系统接口**：此接口为系统接口。|

## NotificationLiveViewContent<sup>11+</sup>

描述普通实况通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称           | 类型                                                                | 只读| 可选 | 说明                                                  |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | 否  | 否  | 通知状态。                  |
| version        | number                                                             | 否  | 是  | 通知版本号（如果数据库存储版本号为0xffffffff，则本次更新和结束不校验版本号大小，否则需要校验本次版本号>数据库存储版本号）。不填默认为0xffffffff。|
| extraInfo      | [key: string] object                                               | 否  | 是  | 实况通知附加内容。           |
| pictureInfo    | [key: string] Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | 否  | 是  | 实况通知附加内容中的图片信息。|
| isLocalUpdateOnly<sup>12+</sup> | boolean                                           | 否  | 是  | 实况窗是否只在本地更新。     |

## NotificationCapsule<sup>11+</sup>

描述通知胶囊。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                  |  类型                         | 只读 | 可选 | 说明                              |
| --------------------- | ---------------------------- | ---- | ---- | -------------------------------- |
| content<sup>12+</sup> | string                       |  否  |  是  | 胶囊的拓展文本。                   |

## LiveViewStatus<sup>11+</sup>

描述普通实况通知的状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.AccessToken

**系统接口**：此接口为系统接口。

| 名称                         | 值 |   说明   |
| ---------------------------- |----|----------|
| LIVE_VIEW_CREATE             | 0  | 创建     |
| LIVE_VIEW_INCREMENTAL_UPDATE | 1  | 增量更新 |
| LIVE_VIEW_END                | 2  | 结束     |
| LIVE_VIEW_FULL_UPDATE        | 3  | 全量更新 |
