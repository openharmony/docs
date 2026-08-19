# NotificationContent (系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

NotificationContent中定义通知的内容结构，提供多种通知类型的内容描述接口。当应用需要发布通知时，可根据通知的展示需求（如普通文本、长文本、多行文本、图片、实况窗），选择对应的内容类型接口构造[通知内容](../../notification/notification-glossary.md#notification-content通知内容)。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[NotificationContent](./js-apis-inner-notification-notificationContent.md)。

## NotificationContent

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | 否  | 是  | 普通实况窗类型[通知内容](../../notification/notification-glossary.md#notification-content通知内容)。<br>**系统接口**：此接口为系统接口。|

## NotificationBasicContent

描述普通文本通知。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| structuredText<sup>21+</sup> | Map<string, string> |  否  |  是  | 通知结构化字段。当前仅支持服务提醒类短信在[通知中心](../../notification/notification-glossary.md#notification-center通知中心)结构化展示。默认为空。（key/value大小不超过512字节，超出部分会被截断，最多支持3对结构化数据，超出部分会被忽略。）   |

## NotificationLiveViewContent<sup>11+</sup>

描述[普通实况通知](../../notification/notification-glossary.md#normal-live-view普通实况通知)。继承自[NotificationBasicContent](#notificationbasiccontent)。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称           | 类型                                                                | 只读| 可选 | 说明                                                  |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | 否  | 否  | 通知状态。                  |
| version        | number                                                             | 否  | 是  | 通知版本号（如果数据库存储版本号为0xffffffff，则本次更新和结束不校验版本号大小，否则需要校验本次版本号>数据库存储版本号）。不填默认为0xffffffff。|
| extraInfo      | Record<string, Object\>                                               | 否  | 是  | [实况通知](../../notification/notification-glossary.md#live-view-notification实况通知)附加内容。默认为空。           |
| pictureInfo    | Record<string, Array<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)\>\> | 否  | 是  | 实况通知附加内容中的图片信息。默认为空。|
| isLocalUpdateOnly<sup>12+</sup> | boolean                                           | 否  | 是  | 实况窗是否只在本地更新。默认为false。<br> - true：是。<br> - false：否。     |
| extensionWantAgent<sup>20+</sup> | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)    |  否  |  是  | 点击辅助区的跳转动作。默认为空。      |


## NotificationSystemLiveViewContent<sup>18+</sup>

描述[系统实况窗](../../notification/notification-glossary.md#system-live-view系统实况窗)[通知内容](../../notification/notification-glossary.md#notification-content通知内容)，用于在实况窗中展示实时状态信息。不支持三方应用直接创建该类型通知，可以由系统代理创建系统实况窗类型通知后，三方应用发布同ID的通知来更新指定内容。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                         | 类型                                             | 只读| 可选 | 说明                               |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| liveViewType | [LiveViewTypes](#liveviewtypes18)  | 否 | 是  | 实况窗类型。默认值为LIVE_VIEW_ACTIVITY。  |
| cardButtons | Array\<[NotificationIconButton](#notificationiconbutton18)\>    |  否  |  是  | 实况窗按钮（最多支持3个）。默认为空。      |

## NotificationCapsule<sup>11+</sup>

描述[通知胶囊](../../notification/notification-glossary.md#notification-capsule通知胶囊)，用于在实况窗中展示胶囊形态。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                  |  类型                         | 只读 | 可选 | 说明                              |
| --------------------- | ---------------------------- | ---- | ---- | -------------------------------- |
| content<sup>12+</sup> | string                       |  否  |  是  | 胶囊的拓展文本。默认为空。                   |
| time<sup>18+</sup> | number                       |  否  |  是  | 即时任务类实况胶囊展示时长。默认值为0。<br>单位：秒。   |
| capsuleButtons<sup>18+</sup> | Array\<[NotificationIconButton](#notificationiconbutton18)\>    |  否  |  是  | 即时任务类实况胶囊的按钮（最多支持2个）。默认为空。      |

## LiveViewStatus<sup>11+</sup>

描述[普通实况通知](../../notification/notification-glossary.md#normal-live-view普通实况通知)的状态。

**系统能力**：SystemCapability.Security.AccessToken

**系统接口**：此接口为系统接口。

| 名称                         | 值 |   说明   |
| ---------------------------- |----|----------|
| LIVE_VIEW_CREATE             | 0  | 创建     |
| LIVE_VIEW_INCREMENTAL_UPDATE | 1  | 增量更新 |
| LIVE_VIEW_END                | 2  | 结束     |
| LIVE_VIEW_FULL_UPDATE        | 3  | 全量更新 |
| LIVE_VIEW_PENDING_CREATE<sup>23+</sup>     | 4  | 条件触发创建<br>**模型约束**：此接口仅可在Stage模型下使用。 |
| LIVE_VIEW_PENDING_END<sup>23+</sup>        | 6  | 条件触发结束<br>**模型约束**：此接口仅可在Stage模型下使用。 |

## NotificationIconButton<sup>18+</sup>

描述系统[通知按钮](../../notification/notification-glossary.md#notification-button通知按钮)。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称          | 类型                    | 只读 | 可选 | 说明                                      |
| ------------ | ----------------------- | ---- | ---- | ---------------------------------------- |
| name         | string                  | 否   |  否  | 按钮标识，用于区分同一通知的多个不同按钮。字符串长度不超过202字节，超出部分会被截断。不可为空字符串。   |
| iconResource | [IconType](#icontype18) | 否   |  否  | 按钮的背景图。                             |
| text         | string                  | 否   |  是  | 按钮展示的信息。默认为空。字符串长度不超过202字节，超出部分会被截断。             |
| hidePanel    | boolean                 | 否   |  是  | 点击按钮时，是否隐藏[通知中心](../../notification/notification-glossary.md#notification-center通知中心)。默认为false。<br> - true：是。<br> - false：否。   |

## IconType<sup>18+</sup>

type IconType = Resource | image.PixelMap

描述图标的类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 类型                                                             | 说明                              |
| ---------------------------------------------------------------- | -------------------------------- |
| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)          | 表示值类型为图片资源。             |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 表示值类型为图片。                 |

## LiveViewTypes<sup>18+</sup>

描述[实况通知](../../notification/notification-glossary.md#live-view-notification实况通知)的类型。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                         | 值 |   说明   |
| ---------------------------- |----|----------|
| LIVE_VIEW_ACTIVITY           | 0  | 实时活动类（进度类）系统实况 |
| LIVE_VIEW_INSTANT            | 1  | 即时任务类系统实况 |
| LIVE_VIEW_LONG_TERM          | 2  | 长时任务类系统实况 |

## NotificationMultiLineContent

描述多行文本通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> - 当该类型通知与其他通知形成[组通知](../../notification/notification-glossary.md#group-notification组通知)时，该通知类型的展示效果默认为折叠态，显示的标题与正文为该类型继承的[普通文本](#notificationbasiccontent)中的`title`与`text`。<br>当该类型通知单独展示，没有与其他通知形成组通知时，该通知类型的展示效果默认为展开态，显示的标题为展开时的标题`longTitle`，多行文本内容`lines`作为正文多行显示。
>
> - 用户点击成组展示的通知，查看各个通知详情时，该通知的展示效果变化为展开态。
>
> - 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| lineWantAgents<sup>20+</sup>       | Array<[WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)> |  否  | 是  | 点击多行文本中某一行文本消息触发的wantAgent。不同行的文本分别对应于不同的wantAgent。该字段配置的行数不能大于[lines](./js-apis-inner-notification-notificationContent.md#notificationmultilinecontent)字段配置的行数。默认为空。<br>**系统接口**：此接口为系统接口。<br>**需要权限**：ohos.permission.NOTIFICATION_AGENT_CONTROLLER |