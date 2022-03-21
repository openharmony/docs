# 通知内容。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationBasicContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型   | 必填 | 描述                               |
| -------------- | ---- | ---- | ------ | ---- | ---------------------------------- |
| title          | 是   | 是   | string | 是   | 通知标题。                         |
| text           | 是   | 是   | string | 是   | 通知内容。                         |
| additionalText | 是   | 是   | string | 否   | 通知次要内容，是对通知内容的补充。 |


## NotificationLongTextContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型   | 必填 | 描述                             |
| -------------- | ---- | --- | ------ | ---- | -------------------------------- |
| title          | 是  | 是  | string | 是   | 通知标题。                         |
| text           | 是  | 是  | string | 是   | 通知内容。                         |
| additionalText | 是  | 是  | string | 否   | 通知次要内容，是对通知内容的补充。 |
| longText       | 是  | 是  | string | 是   | 通知的长文本。                     |
| briefText      | 是  | 是  | string | 是   | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | 是  | 是  | string | 是   | 通知展开时的标题。                 |


## NotificationMultiLineContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型            | 必填 | 描述                             |
| -------------- | --- | --- | --------------- | ---- | -------------------------------- |
| title          | 是  | 是  | string          | 是   | 通知标题。                         |
| text           | 是  | 是  | string          | 是   | 通知内容。                         |
| additionalText | 是  | 是  | string          | 否   | 通知次要内容，是对通知内容的补充。 |
| briefText      | 是  | 是  | string          | 是   | 通知概要内容，是对通知内容的总结。 |
| longTitle      | 是  | 是  | string          | 是   | 通知展开时的标题。                 |
| lines          | 是  | 是  | Array\<string\> | 是   | 通知的多行文本。                   |


## NotificationPictureContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型           | 必填 | 描述                             |
| -------------- | ---- | --- | -------------- | ---- | -------------------------------- |
| title          | 是  | 是  | string         | 是   | 通知标题。                         |
| text           | 是  | 是  | string         | 是   | 通知内容。                         |
| additionalText | 是  | 是  | string         | 否   | 通知次要内容，是对通知内容的补充。 |
| briefText      | 是  | 是  | string         | 是   | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | 是  | 是  | string         | 是   | 通知展开时的标题。                 |
| picture        | 是  | 是  | image.PixelMap | 是   | 通知的图片内容。                   |


## NotificationContent

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称        | 可读 | 可写 | 类型                                                         | 必填 | 描述               |
| ----------- | ---- | --- | ------------------------------------------------------------ | ---- | ------------------ |
| contentType | 是  | 是  | [ContentType](#contenttype)                                  | 是   | 通知内容类型。       |
| normal      | 是  | 是  | [NotificationBasicContent](#notificationbasiccontent)        | 否   | 基本类型通知内容。   |
| longText    | 是  | 是  | [NotificationLongTextContent](#notificationlongtextcontent)  | 否   | 长文本类型通知内容。 |
| multiLine   | 是  | 是  | [NotificationMultiLineContent](#notificationmultilinecontent) | 否   | 多行类型通知内容。   |
| picture     | 是  | 是  | [NotificationPictureContent](#notificationpicturecontent)    | 否   | 图片类型通知内容。   |