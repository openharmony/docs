# NotificationSubscribeInfo (系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

通知发布者的信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## NotificationSubscribeInfo

**系统能力**：SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口。

| 名称                 | 类型                  | 只读 | 可选 | 说明                                       |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| bundleNames          | Array<string\>         | 否 | 是 | 应用Bundle名称。 不传递该参数时，默认订阅所有应用的通知。 |
| userId               | number                | 否 | 是  | 用户ID。 不传递该参数时，默认订阅当前用户ID的通知。 |
| deviceType<sup>12+</sup>           | string                | 否 | 是 | 设备类型。不传递该参数时，默认订阅当前设备的通知。根据[设备信息](../apis-basic-services-kit/js-apis-device-info.md)获取。                                    |
| slotTypes<sup>18+</sup>   | Array<[notificationManager.SlotType](js-apis-notificationManager.md#slottype)\>| 否 | 是 | [通知渠道](../../notification/notification-glossary.md#notification-slot通知渠道)类型。 不传递该参数时，默认订阅所有渠道类型的通知。 |
| filterLimit<sup>18+</sup>   | number| 否 | 是 | 通知过滤范围。默认值为0。取值范围包括：<br>- 0：不进行任何过滤，订阅全部通知。 <br>- 1：将渠道类型为[SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype)且[userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton-1)为空的通知过滤掉。<br>- 2：将渠道类型为[SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype)且[userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton-1)不为空的通知过滤掉。|
| voiceContentOptions   | [VoiceContentOptions](#voicecontentoptions)| 否 | 是 | 通知语音播报配置项。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|
| pictureOptions   | [PictureOptions](#pictureoptions)| 否 | 是 | [实况通知](../../notification/notification-glossary.md#live-view-notification实况通知)图片配置项。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|
| enableClassification   | boolean | 否 | 是 | 是否启用通知分类。<br> - true：表示启用。<br> - false：表示禁用。默认值为false。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|
| needSilentReplayOnSubscribe   | boolean | 否 | 是 | 是否启用订阅时的静默重放。<br> - true：表示启用。<br> - false：表示禁用。默认值为false。<br> 启用后，首次订阅时会以静默方式重新推送历史通知，不会出现响铃和振动提醒。<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。|

## VoiceContentOptions

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称      | 类型              | 只读   | 可选 | 说明                     |
|-----------| ---------------- | -------|----- |-------------------------|
| enabled        | boolean | 否 | 是 | 是否订阅通知语音播报内容。 <br> - true：订阅。<br> - false：不订阅。默认值为false。 |

## PictureOptions

**起始版本**：26.0.0

**系统能力**：SystemCapability.Notification.Notification

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称      | 类型              | 只读   | 可选 | 说明                     |
|-----------| ---------------- | -------|----- |-------------------------|
| preparseLiveViewPicList | string[] | 否 | 是 | 订阅普通实况类型通知中[NotificationLiveViewContent](js-apis-inner-notification-notificationContent-sys.md#notificationliveviewcontent11)的extraInfo中的图片信息。入参为extraInfo中需要解析为pixelMap格式的图片文件名的Key。<br>当应用发布普通实况类型通知时，通过[onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume)将解析后的图片信息回调给订阅者，解析后的图片信息存放于NotificationLiveViewContent的pictureInfo内。 |