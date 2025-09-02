# NotificationSubscribeInfo(系统接口)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

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
| bundleNames          | Array<string\>         | 否 | 是 | 应用Bundle名称。                              |
| userId               | number                | 否 | 是  | 用户ID。                                      |
| deviceType<sup>12+</sup>           | string                | 否 | 是 | 设备类型。根据[设备信息](../apis-basic-services-kit/js-apis-device-info.md)获取。                                    |
| slotTypes<sup>18+</sup>   | Array<[notificationManager.SlotType](js-apis-notificationManager.md#slottype)\>| 否 | 是 | 通知渠道类型。 |
| filterLimit<sup>18+</sup>   | number| 否 | 是 | 通知过滤范围。取值范围包括：<br>- 0：不进行任何过滤，订阅全部通知。 <br>- 1：将渠道类型为[SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype)且[userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton)为空的通知过滤掉。<br>- 2：将渠道类型为[SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype)且[userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton)不为空的通知过滤掉。|
