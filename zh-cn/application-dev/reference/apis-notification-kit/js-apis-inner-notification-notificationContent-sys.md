# NotificationContent(系统接口)

描述通知类型。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationContent](./js-apis-inner-notification-notificationContent.md)。

## NotificationContent

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | 否  | 是  | 普通实况窗类型通知内容。<br>**系统接口**：此接口为系统接口。|

## NotificationLiveViewContent<sup>11+</sup>

描述普通实况通知。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称           | 类型                                                                | 只读| 可选 | 说明                                                  |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | 否  | 否  | 通知状态。                  |
| version        | number                                                             | 否  | 是  | 通知版本号（如果数据库存储版本号为0xffffffff，则本次更新和结束不校验版本号大小，否则需要校验本次版本号>数据库存储版本号）。不填默认为0xffffffff。|
| extraInfo      | Record<string, Object\>                                               | 否  | 是  | 实况通知附加内容。           |
| pictureInfo    | Record<string, Array<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)\>\> | 否  | 是  | 实况通知附加内容中的图片信息。|
| isLocalUpdateOnly<sup>12+</sup> | boolean                                           | 否  | 是  | 实况窗是否只在本地更新。默认为false。<br> - true：是。<br> - false：否。     |
| liveViewType<sup>18+</sup>  | [LiveViewTypes](#liveviewtypes18)  | 否 | 是  | 实况窗类型。  |
| cardButtons<sup>18+</sup> | Array\<[NotificationIconButton](#notificationiconbutton18)\>    |  否  |  是  | 实况窗按钮（最多支持3个）。      |

## NotificationCapsule<sup>11+</sup>

描述通知胶囊。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                  |  类型                         | 只读 | 可选 | 说明                              |
| --------------------- | ---------------------------- | ---- | ---- | -------------------------------- |
| content<sup>12+</sup> | string                       |  否  |  是  | 胶囊的拓展文本。                   |
| time<sup>18+</sup> | number                       |  否  |  是  | 即时任务类实况胶囊展示时长（单位：秒）。   |
| capsuleButtons<sup>18+</sup> | Array\<[NotificationIconButton](#notificationiconbutton18)\>    |  否  |  是  | 即时任务类实况胶囊的按钮（最多支持2个）。      |

## LiveViewStatus<sup>11+</sup>

描述普通实况通知的状态。

**系统能力**：SystemCapability.Security.AccessToken

**系统接口**：此接口为系统接口。

| 名称                         | 值 |   说明   |
| ---------------------------- |----|----------|
| LIVE_VIEW_CREATE             | 0  | 创建     |
| LIVE_VIEW_INCREMENTAL_UPDATE | 1  | 增量更新 |
| LIVE_VIEW_END                | 2  | 结束     |
| LIVE_VIEW_FULL_UPDATE        | 3  | 全量更新 |

## NotificationIconButton<sup>18+</sup>

描述系统通知按钮。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称          | 类型                    | 只读 | 可选 | 说明                                      |
| ------------ | ----------------------- | ---- | ---- | ---------------------------------------- |
| name         | string                  | 否   |  否  | 按钮标识，用于区分同一通知的多个不同按钮。   |
| iconResource | [IconType](#icontype18) | 否   |  否  | 按钮的背景图。                             |
| text         | string                  | 否   |  是  | 按钮展示的信息。                           |
| hidePanel    | boolean                 | 否   |  是  | 点击按钮时，是否隐藏通知中心。默认为false。<br> - true：是。<br> - false：否。   |

## IconType<sup>18+</sup>

type IconType = Resource | image.PixelMap

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 类型                                                             | 说明                              |
| ---------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)          | 表示值类型为图片资源。             |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 表示值类型为图片。                 |

## LiveViewTypes<sup>18+</sup>

描述实况通知的类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                         | 值 |   说明   |
| ---------------------------- |----|----------|
| LIVE_VIEW_ACTIVITY           | 0  | 实时活动类（进度类）系统实况 |
| LIVE_VIEW_INSTANT            | 1  | 即时任务类系统实况 |
| LIVE_VIEW_LONG_TERM          | 2  | 长时任务类系统实况 |

## NotificationMultiLineContent

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| lineWantAgents<sup>20+</sup>       | Array<[wantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)> |  否  | 是  | 点击多行文本中某一行文本消息触发的wantAgent。不同行的文本分别对应于不同的wantAgent。该字段配置的行数不能大于[lines](./js-apis-inner-notification-notificationContent.md#notificationmultilinecontent)字段配置的行数。<br>**系统接口**：此接口为系统接口。<br>**需要权限**：ohos.permission.NOTIFICATION_AGENT_CONTROLLER |