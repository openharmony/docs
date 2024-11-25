# NotificationSubscribeInfo(系统接口)

通知发布者的信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## NotificationSubscribeInfo

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**: 以下为系统接口，三方应用不支持调用。

| 名称                 | 类型                  |  必填 | 说明                                       |
| -------------------- | --------------------- | --- | ------------------------------------------ |
| bundleNames          | Array<string\>         | 否  | 应用Bundle名称。                              |
| userId               | number                | 否  | 用户ID。                                      |
| deviceType<sup>12+</sup>           | string                | 否  | 设备类型。根据[设备信息](../apis-basic-services-kit/js-apis-device-info.md)获取。                                    |
