# NotificationContent

描述通知类型。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称        | 类型                                                         | 只读 | 必填 | 说明               |
| ----------- | ------------------------------------------------------------ | ---- | --- | ------------------ |
| contentType | [ContentType](./js-apis-notificationManager.md#contenttype)  | 否  | 是  | 通知内容类型。       |
| normal      | [NotificationBasicContent](#notificationbasiccontent)        | 否  | 否  | 基本类型通知内容。   |
| longText    | [NotificationLongTextContent](#notificationlongtextcontent)  | 否  | 否  | 长文本类型通知内容。 |
| multiLine   | [NotificationMultiLineContent](#notificationmultilinecontent) | 否  | 否  | 多行类型通知内容。   |
| picture     | [NotificationPictureContent](#notificationpicturecontent)    | 否  | 否  | 图片类型通知内容。   |

## NotificationBasicContent

描述普通文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型   | 只读 | 必填 | 说明                               |
| -------------- | ------ | ---- | ---- | ---------------------------------- |
| title          | string | 否   | 是   | 通知标题。                         |
| text           | string | 否   | 是   | 通知内容。                         |
| additionalText | string | 否   | 否   | 通知附加内容，是对通知内容的补充。 |


## NotificationLongTextContent

描述长文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型   | 只读 | 必填 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string | 否  | 是  | 通知标题。                         |
| text           | string | 否  | 是  | 通知内容。                         |
| additionalText | string | 否  | 否  | 通知附加内容，是对通知内容的补充。 |
| longText       | string | 否  | 是  | 通知的长文本。                     |
| briefText      | string | 否  | 是  | 通知概要内容，是对通知内容的总结。   |
| expandedTitle  | string | 否  | 是  | 通知展开时的标题。                 |


## NotificationMultiLineContent

描述多行文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 可读 | 可写 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | 否  | 是  | 通知标题。                         |
| text           | string          | 否  | 是  | 通知内容。                         |
| additionalText | string          | 否  | 否  | 通知附加内容，是对通知内容的补充。 |
| briefText      | string          | 否  | 是  | 通知概要内容，是对通知内容的总结。 |
| longTitle      | string          | 否  | 是  | 通知展开时的标题。                 |
| lines          | Array\<string\> | 否  | 是  | 通知的多行文本。                   |


## NotificationPictureContent

描述附有图片的通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型           | 可读 | 可写 | 说明                             |
| -------------- | -------------- | ---- | --- | -------------------------------- |
| title          | string         | 否  | 是  | 通知标题。                         |
| text           | string         | 否  | 是  | 通知内容。                         |
| additionalText | string         | 否  | 否  | 通知附加内容，是对通知内容的补充。 |
| briefText      | string         | 否  | 是  | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | string         | 否  | 是  | 通知展开时的标题。                 |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) | 否  | 是  | 通知的图片内容。                   |
