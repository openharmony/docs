# NotificationRequest

描述通知的请求。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationRequest

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 必填 | 说明                                                                    |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent)   |   否  | 是  | 通知内容。                                                                 |
| id                            | number                                                   |   否  | 否  | 通知ID。                                                                 |
| slotType<sup>(deprecated)</sup> | [SlotType](js-apis-notificationManager.md#slottype)    |   否  | 否  | 通道类型。<br>从API version 11开始不再维护，建议使用notificationSlotType代替。                        |
| notificationSlotType<sup>11+</sup> | [SlotType](js-apis-notificationManager.md#slottype) |   否  | 否  | 通道类型。                        |
| isOngoing                     | boolean                                                  |   否  | 否  | 是否进行时通知。                                                              |
| isUnremovable                 | boolean                                                  |   否  | 否  | 预留能力，暂不支持。  |
| deliveryTime                  | number                                                   |   否  | 否  | 通知发送时间。                                                               |
| tapDismissed                  | boolean                                                  |   否  | 否  | 通知是否自动清除。                                                             |
| autoDeletedTime               | number                                                   |   否  | 否  | 自动清除的时间。                                                              |
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-wantAgent.md)            |   否  | 否  | WantAgent封装了应用的行为意图，点击通知时触发该行为。                                       |
| extraInfo                     | {[key: string]: any}                                     |   否  | 否  | 扩展参数。                                                                 |
| color                         | number                                                   |   否  | 否  | 通知背景颜色。预留能力，暂未支持。                                                     |
| colorEnabled                  | boolean                                                  |   否  | 否  | 通知背景颜色是否使能。预留能力，暂未支持。                                                 |
| isAlertOnce                   | boolean                                                  |   否  | 否  | 设置是否仅有一次此通知提醒。                                                        |
| isStopwatch                   | boolean                                                  |   否  | 否  | 是否显示已用时间。                                                             |
| isCountDown                   | boolean                                                  |   否  | 否  | 是否显示倒计时时间。                                                            |
| isFloatingIcon                | boolean                                                  |   否  | 否  | 是否显示状态栏图标。                                                            |
| label                         | string                                                   |   否  | 否  | 通知标签。                                                                 |
| badgeIconStyle                | number                                                   |   否  | 否  | 通知角标类型。预留能力，暂未支持。                                                     |
| showDeliveryTime              | boolean                                                  |   否  | 否  | 是否显示分发时间。                                                             |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   否  | 否  | 通知按钮，最多三个按钮。                                                          |
| smallIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   否  | 否  | 通知小图标。可选字段，图像像素的总字节数不超过100KB。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| largeIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   否  | 否  | 通知大图标。可选字段，图像像素的总字节数不超过100KB。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| creatorBundleName             | string                                                   |   是  | 否  | 创建通知的包名。                                                              |
| creatorUid                    | number                                                   |   是  | 否  | 创建通知的UID。                                                             |
| creatorPid                    | number                                                   |   是  | 否  | 创建通知的PID。                                                             |
| creatorUserId<sup>8+<sup>     | number                                                   |   是  | 否  | 创建通知的UserId。                                                          |
| hashCode                      | string                                                   |   是  | 否  | 通知唯一标识。                                                               |
| groupName<sup>8+<sup>         | string                                                   |   否  | 否  | 组通知名称。                                                                |
| template<sup>8+<sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   否  | 否  | 通知模板。                                                                 |
| distributedOption<sup>8+<sup> | [DistributedOptions](#distributedoptions)                |   否  | 否  | 分布式通知的选项。                                                             |
| notificationFlags<sup>8+<sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md#notificationflags)                   |   是  | 否  | 获取NotificationFlags。                                                  |
| removalWantAgent<sup>9+<sup>  | [WantAgent](../apis-ability-kit/js-apis-wantAgent.md)            |   否  | 否  | 当移除通知时，通知将被重定向到的WantAgent实例。当前不支持跳转UIAbility，只支持发布公共事件及跳转系统Service能力（WantAgent的OperationType >= 3）。                                          |
| badgeNumber<sup>9+<sup>       | number                                                   |   否  | 否  | 应用程序图标上显示的通知数。                                                        |

## DistributedOptions

描述分布式选项。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                   | 类型            | 必填 | 说明                               |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| isDistributed<sup>8+<sup>          | boolean        | 否   | 是否为分布式通知。                   |
| supportDisplayDevices<sup>8+<sup>  | Array\<string> | 否   | 可以同步通知到的设备列表。            |
| supportOperateDevices<sup>8+<sup>  | Array\<string> | 否   | 可以打开通知的设备列表。              |
