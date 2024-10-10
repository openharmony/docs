# NotificationContent

描述通知类型。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| contentType<sup>(deprecated)</sup> | [notification.ContentType](./js-apis-notification.md#contenttype)  | 否  | 是  | 通知内容类型。<br>从API version 11开始不再维护，建议使用notificationContentType代替。       |
| notificationContentType<sup>11+</sup>    | [notificationManager.ContentType](./js-apis-notificationManager.md#contenttype)                | 否  | 是  | 通知内容类型。       |
| normal         | [NotificationBasicContent](#notificationbasiccontent)                      | 否  | 是  | 基本类型通知内容。   |
| longText       | [NotificationLongTextContent](#notificationlongtextcontent)                | 否  | 是  | 长文本类型通知内容。 |
| multiLine      | [NotificationMultiLineContent](#notificationmultilinecontent)              | 否  | 是  | 多行类型通知内容。   |
| picture        | [NotificationPictureContent](#notificationpicturecontent)                  | 否  | 是  | 图片类型通知内容。   |
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | 否  | 是  | 系统实况窗类型通知内容。不支持三方应用直接创建该类型通知，可以由系统代理创建系统实况窗类型通知后，三方应用发布同ID的通知来更新指定内容。|

## NotificationBasicContent

描述普通文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                               |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  否  |  否  | 通知标题（不可为空字符串，大小不超过200字节，超出部分会被截断）。         |
| text           | string |  否  |  否  | 通知内容（不可为空字符串，大小不超过200字节，超出部分会被截断）。         |
| additionalText | string |  否  |  是  | 通知附加内容，是对通知内容的补充（大小不超过200字节，超出部分会被截断）。   |
| lockscreenPicture<sup>12+</sup> | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) |  否  |  是  | 通知在锁屏界面显示的图片。当前仅支持实况窗类型通知。   |

## NotificationLongTextContent

描述长文本通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> 实际显示效果依赖于设备能力和通知中心UI样式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| longText       | string |  否  | 否  | 通知的长文本（不可为空字符串，大小不超过1024字节，超出部分会被截断）。                     |
| briefText      | string |  否  | 否  | 通知概要内容，是对通知内容的总结（不可为空字符串，大小不超过200字节，超出部分会被截断）。   |
| expandedTitle  | string |  否  | 否  | 通知展开时的标题（不可为空字符串，大小不超过200字节，超出部分会被截断）。                 |


## NotificationMultiLineContent

描述多行文本通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> 实际显示效果依赖于设备能力和通知中心UI样式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 只读 | 可选 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| briefText      | string          | 否  | 否  | 通知概要内容，是对通知内容的总结（不可为空字符串，大小不超过200字节，超出部分会被截断）。 |
| longTitle      | string          | 否  | 否  | 通知展开时的标题（不可为空字符串，大小不超过200字节，超出部分会被截断）。|
| lines          | Array\<string\> | 否  | 否  | 通知的多行文本（大小不超过200字节，超出部分会被截断）。                  |


## NotificationPictureContent

描述附有图片的通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> 实际显示效果依赖于设备能力和通知中心UI样式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型                                          | 只读 | 可选 | 说明                               |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| briefText      | string                                       |  否  | 否  | 通知概要内容，是对通知内容的总结（不可为空字符串，大小不超过200字节，超出部分会被截断）。 |
| expandedTitle  | string                                       |  否  | 否  | 通知展开时的标题（不可为空字符串，大小不超过200字节，超出部分会被截断）。    |
| picture        | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) |  否  | 否  | 通知的图片内容(图像像素的总字节数不能超过2MB)。|


## NotificationSystemLiveViewContent

描述系统实况窗通知内容。不支持三方应用直接创建该类型通知，可以由系统代理创建系统实况窗类型通知后，三方应用发布同ID的通知来更新指定内容。继承自[NotificationBasicContent](#notificationbasiccontent)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                         | 类型                                             | 只读| 可选 | 说明                               |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| typeCode<sup>11+</sup>       | number                                          | 否  | 否  | 类型标识符，标记调用方业务类型。       |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | 否  | 是  | 实况通知的胶囊。                     |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | 否  | 是  | 实况通知的按钮。                     |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | 否  | 是  | 实况通知的时间。                     |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | 否  | 是  | 实况内容的进度。                     |


## NotificationCapsule<sup>11+</sup>

描述通知胶囊。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称            | 类型                                          | 只读 | 可选 | 说明                            |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | 否  | 是  | 胶囊标题。                        |
| icon            | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 否  | 是  | 胶囊图片。                        |
| backgroundColor | string                                       | 否  | 是  | 背景颜色。                        |


## NotificationButton<sup>11+</sup>

描述通知按钮。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 类型                                                   | 只读 | 可选 | 说明             |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | 否  |  是 | 按钮名称（最多支持3个）。   |
| icons | Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)\> | 否  |  是 | 按钮图片（最多支持3个）。   |
| iconsResource<sup>12+</sup> | Array\<[Resource](../apis-arkui/arkui-ts/ts-types.md#resource)\> | 否  |  是 | 按钮资源（最多支持3个）。   |

## NotificationTime<sup>11+</sup>

描述通知时间。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型              | 只读 | 可选 | 说明                             |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | 否  | 是  | 起始时间。<br>数据格式：时间戳。<br>单位：ms。                |
| isCountDown    | boolean          | 否  | 是  | 是否倒计时。                     |
| isPaused       | boolean          | 否  | 是  | 是否暂停。                       |
| isInTitle      | boolean          | 否  | 是  | 时间是否展示在title中。           |


## NotificationProgress<sup>11+</sup>

描述通知进度。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 只读 | 可选 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | 否  | 是  | 进度最大值。                       |
| currentValue    | number         | 否  | 是  | 进度当前值。                       |
| isPercentage    | boolean        | 否  | 是  | 是否按百分比展示。                   |
