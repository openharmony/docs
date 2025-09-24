# NotificationRequest
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

描述通知的请求。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationRequest

**系统能力**：SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 可选 | 说明                                                                    |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent-1)   |   否  | 否  | 通知内容。                                                                 |
| id                            | number                                                   |   否  | 是  | 通知ID，默认为0。当相同通知ID存在时，将更新该通知的内容。                                                                 |
| slotType<sup>(deprecated)</sup> | [notification.SlotType](./js-apis-notification.md#slottype)    |   否  | 是  | 通知渠道类型。<br>从API version 7开始支持，从API version 11开始废弃，建议使用notificationSlotType替代。                        |
| notificationSlotType<sup>11+</sup> | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) |   否  | 是  | 通知渠道类型，默认为OTHER_TYPES。                        |
| isOngoing                     | boolean                                                  |   否  | 是  | 预留能力，暂未支持。  |
| isUnremovable                 | boolean                                                  |   否  | 是  | 预留能力，暂未支持。  |
| updateOnly<sup>18+</sup>        | boolean                                       | 否  | 是  | 是否仅更新通知，默认值为false。<br/> - true：若相同ID通知存在，则更新通知；若相同ID通知不存在，则更新失败，不创建新的通知。<br/> - false：若相同ID通知存在，则更新通知；若相同ID通知不存在，则创建通知。         |
| deliveryTime                  | number                                                   |   否  | 是  | 通知发送时间。系统自动生成，无需开发者配置。<br>数据格式：时间戳。<br>单位：ms。                                                               |
| tapDismissed                  | boolean                                                  |   否  | 是  | 通知是否自动清除。当通知携带wantAgent或actionButtons时该字段生效。默认值为true。<br> - true：点击通知或按钮后，自动删除当前通知。<br> - false：点击通知或按钮后，保留当前通知。 |
| autoDeletedTime               | number                                                   |   否  | 是  | 自动清除的时间。<br>数据格式：时间戳。<br>单位：ms。<br>例如，希望某通知存留3秒（3000ms）后对其进行清除，则对应的清除时间为：new Date().getTime() + 3000。                                                              |
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | WantAgent封装了应用的行为意图，点击通知时触发该行为。                                       |
| extraInfo                     | {[key: string]: any}                                     |   否  | 是  | 扩展参数。为应用提供定制服务。                                                                 |
| color                         | number                                                   |   否  | 是  | 通知背景颜色。预留能力，暂未支持。                                                     |
| colorEnabled                  | boolean                                                  |   否  | 是  | 通知背景颜色是否使能。预留能力，暂未支持。                                                 |
| isAlertOnce                   | boolean                                                  |   否  | 是  | 发布或更新该通知时，是否只进行一次通知提醒，默认为false。<br/> - true：仅首次发布通知时进行提醒，后续更新该通知时，提醒方式变更为[LEVEL_MIN](js-apis-notificationManager.md#slotlevel)。<br/> - false：每次均按照配置的通知提醒方式进行提醒。                                                        |
| isStopwatch                   | boolean                                                  |   否  | 是  | 是否显示已用时间。预留能力，暂未支持。                                                             |
| isCountDown                   | boolean                                                  |   否  | 是  | 是否显示倒计时时间。预留能力，暂未支持。                                                            |
| isFloatingIcon                | boolean                                                  |   否  | 是  | 是否显示状态栏图标。预留能力，暂未支持。                                                            |
| label                         | string                                                   |   否  | 是  | 通知标签。<br>label字段的功能类似于id，可以单独使用，也可与id结合共同作为通知的标识。优先推荐使用id。<br>如果发布通知时label不为空，那么在更新或删除该通知时，也需要指定相应的label。                                                                 |
| badgeIconStyle                | number                                                   |   否  | 是  | 通知角标类型。预留能力，暂未支持。                                                     |
| showDeliveryTime              | boolean                                                  |   否  | 是  | 是否显示分发时间。预留能力，暂未支持。                                                             |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   否  | 是  | 通知按钮，默认一条通知中最多包含两个按钮。从API version 16开始，支持`wearable`设备，`wearable`设备中一条通知中最多包含三个按钮。                                                          |
| smallIcon                     | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)             |   否  | 是  | 通知小图标。可选字段，图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| largeIcon                     | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)             |   否  | 是  | 通知大图标。可选字段，图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| creatorBundleName             | string                                                   |   是  | 是  | 创建通知的包名。                                                              |
| creatorUid                    | number                                                   |   是  | 是  | 创建通知的UID。                                                             |
| creatorPid                    | number                                                   |   是  | 是  | 创建通知的PID。                                                             |
| creatorUserId<sup>8+</sup>     | number                                                   |   是  | 是  | 创建通知的UserId。                                                          |
| hashCode                      | string                                                   |   是  | 是  | 通知唯一标识。                                                               |
| groupName<sup>8+</sup>         | string                                                   |   否  | 是  | 组通知名称。默认为空。                                                                |
| template<sup>8+</sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   否  | 是  | 通知模板。                                                                 |
| distributedOption<sup>8+</sup> | [DistributedOptions](#distributedoptions8)                |   否  | 是  | 分布式通知的选项。预留能力，暂未支持。                                                             |
| notificationFlags<sup>8+</sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md)                   |   是  | 是  | 获取NotificationFlags。                                                  |
| removalWantAgent<sup>9+</sup>  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | 当移除通知时，通知将被重定向到的WantAgent实例。<br>当前不支持跳转UIAbility，只支持发布公共事件（即[WantAgentInfo](../apis-ability-kit/js-apis-inner-wantAgent-wantAgentInfo.md#wantagentinfo-1)的actionType字段取值为4）。                                          |
| badgeNumber<sup>9+</sup>       | number                                                   |   否  | 是  | 应用程序图标上显示的通知数，该数量累计展示。<br>当`badgeNumber`取值小于或等于0时，将忽略本次角标设定。<br>当角标累加设定个数取值大于99时，通知角标将显示99+。<br>例如，应用发布3条通知，`badgeNumber`依次设置为2、0、3，应用将依次展示为2、2、5。|
| appMessageId<sup>12+</sup>       | string                                                   |   否  | 是  | 应用发送通知携带的唯一标识字段, 用于通知去重。如果同一应用通过本地和云端等不同途径发布携带相同appMessageId的通知，设备只展示一条消息，之后收到的重复通知会被静默去重，不展示、不提醒。去重标识仅在通知发布的24小时内有效，超过24小时或者设备重启失效。
| sound<sup>12+</sup>            | string                                                   |   否  | 是  | 应用通知自定义铃声文件名。该文件必须放在resources/rawfile目录下，支持m4a、aac、mp3、ogg、wav、flac、amr等格式。<!--RP1-->该字段需要由具有[ohos.permission.NOTIFICATION_AGENT_CONTROLLER](../../security/AccessToken/permissions-for-system-apps.md#ohospermissionnotification_agent_controller)权限的系统应用调用接口[notificationManager.setAdditionalConfig](./js-apis-notificationManager-sys.md#notificationmanagersetadditionalconfig12)进行配置权益后，方可生效。<!--RP1End-->                                                        |

## DistributedOptions<sup>8+</sup>

描述跨设备协同选项。预留能力，暂未支持。

**系统能力**：SystemCapability.Notification.Notification

| 名称                   | 类型            | 只读 | 可选 | 说明                               |
| -----------------------| -------------- | ---- | ---- | --------------------------------- |
| isDistributed          | boolean        | 否   | 是   | 是否支持跨设备协同通知。<br/> - true：支持跨设备协同通知。<br/> - false：不支持跨设备协同通知。                  |
| supportDisplayDevices  | Array\<string> | 否   | 是   | 可以同步通知到的设备列表。           |
| supportOperateDevices  | Array\<string> | 否   | 是   | 可以打开通知的设备列表。             |
