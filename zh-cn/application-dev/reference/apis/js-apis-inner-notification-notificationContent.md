# NotificationContent

描述通知类型。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 必填 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| contentType<sup>(deprecated)</sup> | [ContentType](./js-apis-notificationManager.md#contenttype)  | 否  | 否  | 通知内容类型。<br>从API version 11开始不再维护，建议使用notificationContentType代替。       |
| notificationContentType<sup>11+</sup>    | [ContentType](./js-apis-notificationManager.md#contenttype)                | 否  | 否  | 通知内容类型。       |
| normal         | [NotificationBasicContent](#notificationbasiccontent)                      | 否  | 否  | 基本类型通知内容。   |
| longText       | [NotificationLongTextContent](#notificationlongtextcontent)                | 否  | 否  | 长文本类型通知内容。 |
| multiLine      | [NotificationMultiLineContent](#notificationmultilinecontent)              | 否  | 否  | 多行类型通知内容。   |
| picture        | [NotificationPictureContent](#notificationpicturecontent)                  | 否  | 否  | 图片类型通知内容。   |
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | 否  | 否  | 系统实况窗类型通知内容（仅对系统应用开放）。|
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | 否  | 否  | 普通实况窗类型通知内容。|

## NotificationBasicContent

描述普通文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 必填 | 说明                               |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  否  |  是  | 通知标题（不可为空字符串）。         |
| text           | string |  否  |  是  | 通知内容（不可为空字符串）。         |
| additionalText | string |  否  |  否  | 通知附加内容，是对通知内容的补充。   |


## NotificationLongTextContent

描述长文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 必填 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string |  否  | 是  | 通知标题（不可为空字符串）。                         |
| text           | string |  否  | 是  | 通知内容（不可为空字符串）。                         |
| additionalText | string |  否  | 否  | 通知附加内容，是对通知内容的补充。   |
| longText       | string |  否  | 是  | 通知的长文本（不可为空字符串）。                     |
| briefText      | string |  否  | 是  | 通知概要内容，是对通知内容的总结（不可为空字符串）。   |
| expandedTitle  | string |  否  | 是  | 通知展开时的标题（不可为空字符串）。                 |


## NotificationMultiLineContent

描述多行文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 只读 | 必填 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | 否  | 是  | 通知标题（不可为空字符串）。       |
| text           | string          | 否  | 是  | 通知内容（不可为空字符串）。       |
| additionalText | string          | 否  | 否  | 通知附加内容，是对通知内容的补充。 |
| briefText      | string          | 否  | 是  | 通知概要内容，是对通知内容的总结（不可为空字符串）。 |
| longTitle      | string          | 否  | 是  | 通知展开时的标题（不可为空字符串）。|
| lines          | Array\<string\> | 否  | 是  | 通知的多行文本。                  |


## NotificationPictureContent

描述附有图片的通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                          | 只读 | 必填 | 说明                               |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| title          | string                                       |  否  | 是  | 通知标题（不可为空字符串）。          |
| text           | string                                       |  否  | 是  | 通知内容（不可为空字符串）。          |
| additionalText | string                                       |  否  | 否  | 通知附加内容，是对通知内容的补充。    |
| briefText      | string                                       |  否  | 是  | 通知概要内容，是对通知内容的总结（不可为空字符串）。 |
| expandedTitle  | string                                       |  否  | 是  | 通知展开时的标题（不可为空字符串）。    |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) |  否  | 是  | 通知的图片内容(最大支持2MB的图片文件)。|


## NotificationSystemLiveViewContent

描述系统实况窗通知内容（仅对系统应用开放）。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                         | 类型                                             | 只读| 必填 | 说明                               |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| title                        | string                                          | 否  | 是  | 通知标题（不可为空字符串）。          |
| text                         | string                                          | 否  | 是  | 通知内容（不可为空字符串）。          |
| additionalText               | string                                          | 否  | 否  | 通知附加内容，是对通知内容的补充。     |
| typeCode<sup>11+</sup>       | number                                          | 否  | 是  | 类型标识符，标记调用方业务类型。       |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | 否  | 否  | 实况通知的胶囊。                     |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | 否  | 否  | 实况通知的按钮。                     |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | 否  | 否  | 实况通知的时间。                     |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | 否  | 否  | 实况内容的进度。                     |


## NotificationCapsule<sup>11+</sup>

描述通知胶囊。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称            | 类型                                          | 只读 | 必填 | 说明                            |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | 否  | 否  | 胶囊标题。                        |
| icon            | [image.PixelMap](js-apis-image.md#pixelmap7) | 否  | 否  | 胶囊图片。                        |
| backgroundColor | string                                       | 否  | 否  | 背景颜色。                        |


## NotificationButton<sup>11+</sup>

描述通知按钮。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 类型                                                   | 只读 | 必填 | 说明             |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | 否  |  否 | 按钮名称（最多支持3个）。   |
| icons | Array\<[image.PixelMap](js-apis-image.md#pixelmap7)\> | 否  |  否 | 按钮图片（最多支持3个）。   |


## NotificationTime<sup>11+</sup>

描述通知时间。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型              | 只读 | 必填 | 说明                             |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | 否  | 否  | 起始时间。                |
| isCountDown    | boolean          | 否  | 否  | 是否倒计时。                     |
| isPaused       | boolean          | 否  | 否  | 是否暂停。                       |
| isInTitle      | boolean          | 否  | 否  | 时间是否展示在title中。           |


## NotificationProgress<sup>11+</sup>

描述通知进度。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 只读 | 必填 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | 否  | 否  | 进度最大值。                       |
| currentValue    | number         | 否  | 否  | 进度当前值。                       |
| isPercentage    | boolean        | 否  | 否  | 是否按百分比展示。                   |

## NotificationLiveViewContent<sup>11+</sup>

描述普通实况通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                                                | 只读| 必填 | 说明                                                  |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | 否  | 是  | 通知状态。                  |
| version        | number                                                             | 否  | 否  | 通知版本号（如果数据库存储版本号为0xffffffff，则本次更新和结束不校验版本号大小，否则需要校验本次版本号>数据库存储版本号）。不填默认为0xffffffff。|
| extraInfo      | [key: string] object                                               | 否  | 否  | 实况通知附加内容。           |
| pictureInfo    | [key: string] Array\<[image.PixelMap](js-apis-image.md#pixelmap7)> | 否  | 否  | 实况通知附加内容中的图片信息。|

## LiveViewStatus<sup>11+</sup>

描述普通实况通知的状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                         |               值              |   说明   |
| ---------------------------- | ---------------------------- |----------|
| LIVE_VIEW_CREATE             | LIVE_VIEW_CREATE             | 创建     |
| LIVE_VIEW_INCREMENTAL_UPDATE | LIVE_VIEW_INCREMENTAL_UPDATE | 增量更新  |
| LIVE_VIEW_END                | LIVE_VIEW_END                | 结束     |
| LIVE_VIEW_FULL_UPDATE        | LIVE_VIEW_FULL_UPDATE        | 全量更新  |
