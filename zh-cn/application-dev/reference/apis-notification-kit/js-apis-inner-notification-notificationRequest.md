# NotificationRequest

描述通知的请求。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationRequest

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 可选 | 说明                                                                    |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent)   |   否  | 否  | 通知内容。                                                                 |
| id                            | number                                                   |   否  | 是  | 通知ID，默认为0。                                                                 |
| slotType<sup>(deprecated)</sup> | [notification.SlotType](./js-apis-notification.md#slottype)    |   否  | 是  | 通道类型。<br>从API version 11开始不再维护，建议使用notificationSlotType代替。                        |
| notificationSlotType<sup>11+</sup> | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) |   否  | 是  | 通道类型。                        |
| isOngoing                     | boolean                                                  |   否  | 是  | 预留能力，暂未支持。  |
| isUnremovable                 | boolean                                                  |   否  | 是  | 预留能力，暂未支持。  |
| deliveryTime                  | number                                                   |   否  | 是  | 通知发送时间。<br>数据格式：时间戳。<br>单位：ms。                                                               |
| tapDismissed                  | boolean                                                  |   否  | 是  | 通知是否自动清除。预留能力，暂未支持。                                                             |
| autoDeletedTime               | number                                                   |   否  | 是  | 自动清除的时间。<br>数据格式：时间戳。<br>单位：ms。                                                              |
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | WantAgent封装了应用的行为意图，点击通知时触发该行为。                                       |
| extraInfo                     | {[key: string]: any}                                     |   否  | 是  | 扩展参数。                                                                 |
| color                         | number                                                   |   否  | 是  | 通知背景颜色。预留能力，暂未支持。                                                     |
| colorEnabled                  | boolean                                                  |   否  | 是  | 通知背景颜色是否使能。预留能力，暂未支持。                                                 |
| isAlertOnce                   | boolean                                                  |   否  | 是  | 设置是否仅有一次此通知提醒。                                                        |
| isStopwatch                   | boolean                                                  |   否  | 是  | 是否显示已用时间。预留能力，暂未支持。                                                             |
| isCountDown                   | boolean                                                  |   否  | 是  | 是否显示倒计时时间。预留能力，暂未支持。                                                            |
| isFloatingIcon                | boolean                                                  |   否  | 是  | 是否显示状态栏图标。预留能力，暂未支持。                                                            |
| label                         | string                                                   |   否  | 是  | 通知标签。                                                                 |
| badgeIconStyle                | number                                                   |   否  | 是  | 通知角标类型。预留能力，暂未支持。                                                     |
| showDeliveryTime              | boolean                                                  |   否  | 是  | 是否显示分发时间。预留能力，暂未支持。                                                             |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   否  | 是  | 通知按钮，一条通知中最多包含两个按钮。                                                          |
| smallIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   否  | 是  | 通知小图标。可选字段，图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/js-apis-image.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| largeIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   否  | 是  | 通知大图标。可选字段，图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/js-apis-image.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| creatorBundleName             | string                                                   |   是  | 是  | 创建通知的包名。                                                              |
| creatorUid                    | number                                                   |   是  | 是  | 创建通知的UID。                                                             |
| creatorPid                    | number                                                   |   是  | 是  | 创建通知的PID。                                                             |
| creatorUserId<sup>8+</sup>     | number                                                   |   是  | 是  | 创建通知的UserId。                                                          |
| hashCode                      | string                                                   |   是  | 是  | 通知唯一标识。                                                               |
| groupName<sup>8+</sup>         | string                                                   |   否  | 是  | 组通知名称。                                                                |
| template<sup>8+</sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   否  | 是  | 通知模板。                                                                 |
| distributedOption<sup>8+</sup> | [DistributedOptions](#distributedoptions)                |   否  | 是  | 分布式通知的选项。预留能力，暂未支持。                                                             |
| notificationFlags<sup>8+</sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md#notificationflags)                   |   是  | 是  | 获取NotificationFlags。                                                  |
| removalWantAgent<sup>9+</sup>  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | 当移除通知时，通知将被重定向到的WantAgent实例。当前不支持跳转UIAbility，只支持发布公共事件及跳转系统Service能力（WantAgent的OperationType >= 3）。                                          |
| badgeNumber<sup>9+</sup>       | number                                                   |   否  | 是  | 应用程序图标上显示的通知数。                                                        |
| appMessageId<sup>12+</sup>       | string                                                   |   否  | 是  | 应用发送通知携带的唯一标识字段, 用于通知去重。如果同一应用通过本地和云端等不同途径发布携带相同appMessageId的通知，设备只展示一条消息，之后收到的重复通知会被静默去重，不展示、不提醒。去重标识仅在通知发布的24小时内有效，超过24小时或者设备重启失效。
| sound<sup>12+</sup>            | string                                                   |   否  | 是  | 应用通知自定义铃声文件名。该文件必须放在resources/rawfile目录下，支持m4a、aac、mp3、ogg、wav、flac、amr等格式。<!--RP1-->该字段需要由具有[ohos.permission.NOTIFICATION_AGENT_CONTROLLER](../../security/AccessToken/permissions-for-system-apps.md#ohospermissionnotification_agent_controller)权限的系统应用调用接口[notificationManager.setAdditionalConfig](./js-apis-notificationManager-sys.md#notificationmanagersetadditionalconfig12)进行配置权益后，方可生效。<!--RP1End-->                                                        |

## DistributedOptions

描述分布式选项。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                               | 类型            | 只读 | 可选 | 说明                               |
| ---------------------------------- | -------------- | ---- | ---- | --------------------------------- |
| isDistributed<sup>8+</sup>          | boolean        | 否   | 是   | 是否为分布式通知。                  |
| supportDisplayDevices<sup>8+</sup>  | Array\<string> | 否   | 是   | 可以同步通知到的设备列表。           |
| supportOperateDevices<sup>8+</sup>  | Array\<string> | 否   | 是   | 可以打开通知的设备列表。             |
