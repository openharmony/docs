# NotificationContent
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

## NotificationContent

[通知内容](../../notification/notification-glossary.md#notification-content通知内容)。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型                                                                        | 只读 | 可选 | 说明               |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| notificationContentType<sup>11+</sup>    | [notificationManager.ContentType](./js-apis-notificationManager.md#contenttype)                | 否  | 是  | [通知内容类型](../../notification/notification-glossary.md#content-type通知内容类型)，用于指定通知的内容布局类型，决定了通知在[通知中心](../../notification/notification-glossary.md#notification-center通知中心)中的展示样式。需与对应类型的通知内容对象配合使用，例如设置为NOTIFICATION_CONTENT_BASIC_TEXT时需同时填充normal字段。       |
| normal         | [NotificationBasicContent](#notificationbasiccontent)                      | 否  | 是  | 基本类型通知内容。当notificationContentType为NOTIFICATION_CONTENT_BASIC_TEXT时使用，通知以普通文本样式展示标题和正文。   |
| longText       | [NotificationLongTextContent](#notificationlongtextcontent)                | 否  | 是  | 长文本类型通知内容。当notificationContentType为NOTIFICATION_CONTENT_LONG_TEXT时使用，通知展开后可展示完整长文本内容。 |
| multiLine      | [NotificationMultiLineContent](#notificationmultilinecontent)              | 否  | 是  | 多行类型通知内容。当notificationContentType为NOTIFICATION_CONTENT_MULTILINE时使用，通知展开后以多行列表样式展示。   |
| picture        | [NotificationPictureContent](#notificationpicturecontent)                  | 否  | 是  | 图片类型通知内容。当notificationContentType为NOTIFICATION_CONTENT_PICTURE时使用。通知展开后可展示图片。   |
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | 否  | 是  | [系统实况窗](../../notification/notification-glossary.md#system-live-view系统实况窗)类型通知内容。不支持三方应用直接创建该类型通知，可以由系统代理创建系统实况窗类型通知后，三方应用发布同ID的通知来更新指定内容。|
| contentType<sup>(deprecated)</sup> | [notification.ContentType](./js-apis-notification.md#contenttype)  | 否  | 是  | 通知内容类型。<br>从API version 7开始支持，从API version 11开始废弃，建议使用notificationContentType替代。       |

## NotificationBasicContent

描述普通文本通知，用于展示标题和正文内容，是其他通知类型的基础内容结构。其他通知类型（如长文本、多行文本、图片、实况窗）均继承本接口，在此基础上扩展各自特有字段。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                               |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  否  |  否  | 通知标题，显示在通知顶部。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。         |
| text           | string |  否  |  否  | 通知正文内容，显示在标题下方。<br>不可为空字符串，大小不超过3072字节，超出部分会被截断。         |
| additionalText | string |  否  |  是  | 通知附加内容，是对[通知内容](../../notification/notification-glossary.md#notification-content通知内容)的补充，不在[通知中心](../../notification/notification-glossary.md#notification-center通知中心)中显示。<br>默认为空。大小不超过3072字节，超出部分会被截断。   |
| lockscreenPicture<sup>12+</sup> | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) |  否  |  是  | 通知在锁屏界面显示的图片，默认为空。当前仅支持实况窗类型通知。图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。   |

## NotificationLongTextContent

描述长文本通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> - 当该类型通知与其他通知形成[组通知](../../notification/notification-glossary.md#group-notification组通知)时，该通知类型的展示效果默认为折叠态，显示的标题与正文为该类型继承的[普通文本](#notificationbasiccontent)中的`title`与`text`。<br>当该类型通知单独展示，没有与其他通知形成组通知时，该通知类型的展示效果默认为展开态，显示的标题为展开时的标题`expandedTitle`，显示的正文内容为长文本`longText`。
>
> - 用户点击成组展示的通知，查看各个通知详情时，该通知的展示效果变化为展开态。
>
> - 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型    | 只读 | 可选 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| expandedTitle  | string |  否  | 否  | 通知展开时的标题。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。                 |
| longText       | string |  否  | 否  | 通知展开后显示的完整长文本内容。<br>不可为空字符串，大小不超过3072字节，超出部分会被截断。  |
| briefText      | string |  否  | 否  | 通知概要内容，是对[通知内容](../../notification/notification-glossary.md#notification-content通知内容)的总结，不在通知中心中显示。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。   |


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

| 名称           | 类型            | 只读 | 可选 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| longTitle      | string          | 否  | 否  | 通知展开时的标题。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。|
| lines          | Array\<string\> | 否  | 否  | 通知展开后显示的多行文本列表，每行作为独立条目展示，最多支持三行。<br>每行大小不超过1024字节，超出部分会被截断。  |
| briefText      | string          | 否  | 否  | 通知概要内容，是对[通知内容](../../notification/notification-glossary.md#notification-content通知内容)的总结，不在通知中心中显示。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。 |


## NotificationPictureContent

描述附有图片的通知。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> - 当该类型通知与其他通知形成[组通知](../../notification/notification-glossary.md#group-notification组通知)时，该通知类型的展示效果默认为折叠态，显示的标题与正文为该类型继承的[普通文本](#notificationbasiccontent)中的`title`与`text`。<br>当该类型通知单独展示，没有与其他通知形成组通知时，该通知类型的展示效果默认为展开态，显示的标题为展开时的标题`expandedTitle`，显示的正文为该类型继承的`普通文本`中的`text`+该类型的图片内容`picture`。
>
> - 用户点击成组展示的通知，查看各个通知详情时，该通知的展示效果变化为展开态。
>
> - 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型                                          | 只读 | 可选 | 说明                               |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| expandedTitle  | string                                       |  否  | 否  | 通知展开时的标题。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。    |
| picture        | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) |  否  | 否  | 通知展开后显示的图片内容。<br>图标像素的总字节数不能超过2MB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取）。|
| briefText      | string                                       |  否  | 否  | 通知概要内容，是对[通知内容](../../notification/notification-glossary.md#notification-content通知内容)的总结，不在通知中心中显示。<br>不可为空字符串，大小不超过1024字节，超出部分会被截断。 |


## NotificationSystemLiveViewContent

描述[系统实况窗](../../notification/notification-glossary.md#system-live-view系统实况窗)[通知内容](../../notification/notification-glossary.md#notification-content通知内容)，用于在实况窗中展示实时状态信息。不支持三方应用直接创建该类型通知，可以由系统代理创建系统实况窗类型通知后，三方应用发布同ID的通知来更新指定内容。继承自[NotificationBasicContent](#notificationbasiccontent)。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称                         | 类型                                             | 只读| 可选 | 说明                               |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| typeCode<sup>11+</sup>       | number                                          | 否  | 否  | 类型标识符，标记调用方业务类型，用于区分不同实况窗业务场景。       |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | 否  | 是  | [实况通知](../../notification/notification-glossary.md#live-view-notification实况通知)的胶囊。默认为空。            |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | 否  | 是  | 实况通知的按钮。默认为空。            |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | 否  | 是  | 实况通知的时间。默认为空。            |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | 否  | 是  | 实况内容的进度。默认为空。            |


## NotificationCapsule<sup>11+</sup>

描述[通知胶囊](../../notification/notification-glossary.md#notification-capsule通知胶囊)，用于在实况窗中展示胶囊形态。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称            | 类型                                          | 只读 | 可选 | 说明                            |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | 否  | 是  | 胶囊标题。<br>大小不超过202字节，超出部分会被截断。默认为空。  |
| icon            | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否  | 是  | 胶囊图标。<br>图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。                        |
| backgroundColor | string                                       | 否  | 是  | 胶囊背景颜色。支持rgb、rgba或者argb的格式颜色。<br>rgb格式颜色示例：'#ffffff'、'rgb(255, 100, 255)'。<br>rgba格式颜色示例：'rgba(255, 100, 255, 0.5)'。<br>argb格式颜色示例：'#ff000000'。<br>大小不超过202字节，超出部分会被截断。默认为空。                        |


## NotificationButton<sup>11+</sup>

描述[通知按钮](../../notification/notification-glossary.md#notification-button通知按钮)，用于在实况窗中展示可交互的按钮。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称  | 类型                                                   | 只读 | 可选 | 说明             |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | 否  |  是 | 按钮名称列表，每个名称对应一个通知按钮的文本显示。最多支持3个按钮。<br>每个名称的大小不超过202字节，超出部分会被截断。默认为空。   |
| icons | Array\<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)\> | 否  |  是 | 按钮图标列表，与names一一对应，每个图标显示在对应按钮上。最多支持3个。图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。默认为空。该属性与iconsResource互斥，只使用其中一个即可。   |
| iconsResource<sup>12+</sup> | Array\<[Resource](../apis-arkui/arkui-ts/ts-types.md#resource)\> | 否  |  是 | 按钮图标资源列表，与names一一对应，使用Resource资源引用图标。最多支持3个。默认为空。与icons互斥，只使用其中一个即可。   |

## NotificationTime<sup>11+</sup>

描述通知计时信息。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型              | 只读 | 可选 | 说明                             |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | 否  | 是  | 计时起始时间，用于设置实况窗中的计时起点。默认值为0。<br>单位：毫秒。  |
| isCountDown    | boolean          | 否  | 是  | 是否为倒计时模式。默认为false。<br> - true：时间从initialTime开始递减显示。<br> - false：时间从initialTime开始递增显示。 |
| isPaused       | boolean          | 否  | 是  | 计时是否暂停。默认为false。<br> - true：计时暂停在当前值。<br> - false：计时正常运行。   |
| isInTitle      | boolean          | 否  | 是  | 时间信息是否展示在通知标题中。默认为false。<br> - true：计时信息将嵌入标题区域展示。<br> - false：计时信息在独立区域展示。|

**示例：**

<!--code_no_check-->
```ts
// 该通知从3秒开始倒计时，并且时间展示在title中。
time: {
    initialTime: 3000,
    isCountDown: true,
    isPaused: false,
    isInTitle: true,
}
```


## NotificationProgress<sup>11+</sup>

描述[通知进度](../../notification/notification-glossary.md#notification-progress通知进度)，用于在实况窗中展示进度条信息。

> **说明：**
>
> 实际显示效果依赖于设备能力和[通知中心](../../notification/notification-glossary.md#notification-center通知中心)UI样式。

**系统能力**：SystemCapability.Notification.Notification

| 名称           | 类型            | 只读 | 可选 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | 否  | 是  | 进度最大值。                       |
| currentValue    | number         | 否  | 是  | 进度当前值。                       |
| isPercentage    | boolean        | 否  | 是  | 是否按百分比展示进度。默认为false。<br> - true：进度以百分比形式展示。<br> - false：进度以绝对值形式展示。|
