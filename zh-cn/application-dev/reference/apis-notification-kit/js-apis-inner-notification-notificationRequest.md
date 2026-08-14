# NotificationRequest
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

定义了[通知请求](../../notification/notification-glossary.md#notification-request通知请求)的数据结构，用于描述一条通知的全部信息，包括[通知内容](../../notification/notification-glossary.md#notification-content通知内容)、标识、展示样式、交互行为等。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationRequest

定义了[通知请求](../../notification/notification-glossary.md#notification-request通知请求)的数据结构，用于描述一条通知的全部信息，包括[通知内容](../../notification/notification-glossary.md#notification-content通知内容)、标识、展示样式、交互行为等。

**系统能力**：SystemCapability.Notification.Notification

| 名称                            | 类型                                                    |  只读 | 可选 | 说明                                                                          |
| ---------------------------------- | -------------------------------------------------------- | ----- | --- |-------------------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent-1)   |   否  | 否  | 通知展示内容。包括通知标题、正文等。                              |
| id                            | number                                                   |   否  | 是  | 通知ID，默认值为0。若已存在相同ID的通知，则更新该通知；若不存在相同ID的通知，则创建新的通知。 |
| updateOnly<sup>18+</sup>      | boolean                                                  |   否  | 是  | 是否仅更新通知，默认值为false。<br/> - true：若已存在相同ID的通知，则更新该通知；若不存在相同ID的通知，则更新失败，并且不创建新的通知。<br/> - false：若已存在相同ID的通知，则更新该通知；若不存在相同ID的通知，则创建新的通知。         |
| appMessageId<sup>12+</sup>       | string                                                |   否  | 是  | 应用发送通知携带的唯一标识字段，用于通知去重。如果同一应用通过本地和云端等不同途径发布携带相同appMessageId的通知，设备只展示一条消息，之后收到的重复通知会被静默去重，不展示、不提醒。去重标识仅在通知发布的24小时内有效，超过24小时或者设备重启失效。<br>大小不超过202字节，超出部分会被截断。默认为空。 |
| notificationSlotType<sup>11+</sup> | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) |   否  | 是  | [通知渠道](../../notification/notification-glossary.md#notification-slot通知渠道)类型，默认值为OTHER_TYPES。不同渠道类型的[通知提醒方式](../../notification/notification-glossary.md#notification-reminder-mode通知提醒方式)不同。 |
| notificationFlags<sup>8+</sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md) |   否  | 是  | [通知标志位](../../notification/notification-glossary.md#notification-flags通知标志位)设置，默认为空。从API version 23开始成为可写参数，设置该参数可削减通知的提醒方式，当通知渠道类型为[LIVE_VIEW](js-apis-notificationManager.md#slottype)时，该参数设置不生效。 |
| priorityNotificationType<sup>23+</sup>  | [notificationManager.PriorityNotificationType](js-apis-notificationManager.md#prioritynotificationtype23)   | 否 | 是 | 通知优先级类型，默认值为OTHER。设置该参数可使通知置顶，并且在[通知中心](../../notification/notification-glossary.md#notification-center通知中心)以突出方式显示。<!--RP2--><!--RP2End-->实际显示效果依赖于设备能力和通知中心UI样式。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| isAlertOnce                   | boolean                                                  |   否  | 是  | 发布或更新该通知时，是否只进行一次通知提醒，默认为false。<br/> - true：仅首次发布通知时进行提醒，后续更新该通知时，提醒方式变更为[LEVEL_LOW](js-apis-notificationManager.md#slotlevel)。<br/> - false：每次均按照配置的通知提醒方式进行提醒。                                                        |
| sound<sup>12+</sup>           | string                                                   |   否  | 是  | 应用通知[自定义铃声](../../notification/notification-glossary.md#customized-ringtone自定义铃声)资源路径，默认为空。支持两种音频资源来源：<br/> - 资源文件：应用预置的音频文件，资源文件必须放在resources/rawfile目录下，使用时直接传入文件名。<br/> - 沙箱文件：网络下载或者用户生成的音频文件，必须放在[沙箱文件目录](../../file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)EL1区域的files目录或者其子目录下，传入格式为uri::{fileUri}，其中fileUri是通过[getUriFromPath](../apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath)获取的路径。例如，应用将下载的音频资源demo.mp3传入沙箱文件目录/data/storage/el1/base/files/，通过getUriFromPath获取的路径为file://{bundleName}/data/storage/el1/base/files/demo.mp3，使用该路径发布通知即可播放应用下载的音频资源。<br/>支持m4a、aac、mp3、ogg、wav、flac、amr等格式。|
| badgeNumber<sup>9+</sup>      | number                                                   |   否  | 是  | 应用图标上显示的通知数，该数量累计展示，默认值为0。<br>当`badgeNumber`取值小于或等于0时，将忽略本次角标设定。<br>当角标累加设定个数取值大于99时，[通知角标](../../notification/notification-glossary.md#notification-badge通知角标)将显示99+。<br>例如，应用发布3条通知，`badgeNumber`依次设置为2、0、3，应用将依次展示为2、2、5。|
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | 封装了应用的行为意图，点击通知时触发该行为，默认为空。                   |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   否  | 是  | [通知按钮](../../notification/notification-glossary.md#notification-button通知按钮)，默认为空。一条通知中最多包含两个按钮。从API version 16开始，`wearable`设备一条通知最多包含三个按钮。                                                          |
| removalWantAgent<sup>9+</sup> | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   否  | 是  | 封装了应用的行为意图，移除通知时触发该行为，默认为空。<br>当前不支持跳转UIAbility，只支持发布公共事件（即[WantAgentInfo](../apis-ability-kit/js-apis-inner-wantAgent-wantAgentInfo.md#wantagentinfo-1)的actionType字段取值为4）。                                          |
| tapDismissed                  | boolean                                                  |   否  | 是  | 点击通知携带的wantAgent或actionButtons时，该通知是否自动清除。当通知携带wantAgent或actionButtons时该字段生效。默认值为true。<br> - true：点击通知或按钮后，自动删除当前通知。<br> - false：点击通知或按钮后，保留当前通知。 |
| autoDeletedTime               | number                                                   |   否  | 是  | 通知定时清除时间。设置该参数可使通知在指定时间后自动清除。默认值为0。传入小于0的值或过去的时间值，该参数不生效。<br>数据格式：时间戳。<br>单位：毫秒。<br>例如，希望某通知存留3秒（3000ms）后对其进行清除，则对应的清除时间为：new Date().getTime() + 3000。 |
| deliveryTime                  | number                                                   |   否  | 是  | 通知发送时间。系统自动生成，无需开发者配置。<br>数据格式：时间戳。<br>单位：毫秒。      |
| label                         | string                                                   |   否  | 是  | 通知标签。<br>label字段的功能类似于id，可以单独使用，也可与id结合共同作为通知的标识。优先推荐使用id。<br>如果发布通知时label不为空，那么在更新或删除该通知时，也需要指定相应的label。<br>大小不超过202字节，超出部分会被截断。默认为空。                                                                 |
| smallIcon                      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)             |   否  | 是  | 通知小图标，默认为空。图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），超出后设置不生效。<br>未设置`smallIcon`时，通知将展示应用默认图标。建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| largeIcon                      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)             |   否  | 是  | 通知大图标，默认为空。图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），超出后设置不生效。<br>未设置`largeIcon`时，通知将不展示大图标。建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。                                                 |
| overlayIcon<sup>23+</sup>      | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)            |   否  | 是  | 通知重叠图标，默认为空。图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），超出后设置不生效。<br>未设置`overlayIcon`时，通知将不展示重叠图标。<br>此接口只在[notificationSlotType](#notificationrequest-1)类型设置为SOCIAL_COMMUNICATION时生效。建议图标像素长宽为128*128。实际显示效果依赖于设备能力和通知中心UI样式。 |
| groupName<sup>8+</sup>         | string                                                  |   否  | 是  | 通知所属组。当不同通知的groupName相同时，这些通知将成组展示。<br>大小不超过202字节，超出部分会被截断。默认为空。              |
| template<sup>8+</sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   否  | 是  | 通知模板，默认为空。                                                  |
| extraInfo                      | {[key: string]: any}                                    |   否  | 是  | 扩展参数。为应用提供定制服务。默认为空。<br/>以下Key由系统赋值，开发者手动修改也不会生效，系统在数据传递时会自动修改为实际值。<br/> - 'ohos.notificationManager.wantUri'：用户点击通知时传递给应用的[Want](../apis-ability-kit/js-apis-app-ability-want.md#want) 中的uri字段，使用[getActiveNotifications](./js-apis-notification.md#notificationgetactivenotifications)接口获取该信息。 |
| slotType<sup>(deprecated)</sup> | [notification.SlotType](./js-apis-notification.md#slottype)    |   否  | 是  | 通知渠道类型，默认值为OTHER_TYPES。<br>从API version 7开始支持，从API version 11开始废弃，建议使用notificationSlotType替代。 |
| hashCode                       | string                                                  |   是  | 是  | 通知唯一标识。                                                                   |
| creatorBundleName              | string                                                  |   是  | 是  | 创建通知的应用名称。                                                              |
| creatorUid                     | number                                                  |   是  | 是  | 创建通知的应用UID。                                                              |
| creatorPid                     | number                                                  |   是  | 是  | 创建通知的PID。                                                                  |
| creatorUserId<sup>8+</sup>     | number                                                  |   是  | 是  | 创建通知的用户ID。                                                               |
| isOngoing                      | boolean                                                 |   否  | 是  | 预留能力，暂未支持。                                                             |
| isUnremovable                  | boolean                                                 |   否  | 是  | 预留能力，暂未支持。                                                             |
| color                          | number                                                  |   否  | 是  | 通知背景颜色。预留能力，暂未支持。                                                |
| colorEnabled                   | boolean                                                 |   否  | 是  | 通知背景颜色是否使能。预留能力，暂未支持。                                         |
| isStopwatch                    | boolean                                                 |   否  | 是  | 是否显示已用时间。预留能力，暂未支持。                                             |
| isCountDown                    | boolean                                                 |   否  | 是  | 是否显示倒计时时间。预留能力，暂未支持。                                           |
| isFloatingIcon                 | boolean                                                 |   否  | 是  | 是否显示状态栏图标。预留能力，暂未支持。                                           |
| distributedOption<sup>8+</sup> | [DistributedOptions](#distributedoptions8)              |   否  | 是  | [分布式通知](../../notification/notification-glossary.md#distributed-notification分布式通知)的选项。预留能力，暂未支持。                                             |
| badgeIconStyle                 | number                                                  |   否  | 是  | 通知角标类型。预留能力，暂未支持。                                                 |
| showDeliveryTime               | boolean                                                 |   否  | 是  | 是否显示分发时间。预留能力，暂未支持。                                             |

## DistributedOptions<sup>8+</sup>

描述[跨设备协同](../../notification/notification-glossary.md#cross-device-collaboration跨设备协同)选项。预留能力，暂未支持。

**系统能力**：SystemCapability.Notification.Notification

| 名称                   | 类型            | 只读 | 可选 | 说明                               |
| -----------------------| -------------- | ---- | ---- | --------------------------------- |
| isDistributed          | boolean        | 否   | 是   | 是否支持跨设备协同通知。默认为true。<br/> - true：支持跨设备协同通知。<br/> - false：不支持跨设备协同通知。                  |
| supportDisplayDevices  | Array\<string> | 否   | 是   | 可以同步通知到的设备列表。           |
| supportOperateDevices  | Array\<string> | 否   | 是   | 可以打开通知的设备列表。             |

## NotificationParameters<sup>24+</sup>

描述[NotificationRequest](#notificationrequest-1)中wantAgent的部分信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.Notification

| 名称                   | 类型            | 只读 | 可选 | 说明                               |
| -----------------------| -------------- | ---- | ---- | --------------------------------- |
| wantAction          | string        | 否   | 是   | 应用在创建wantAgent时，传入的want的action字段，具体含义请参考[action](../apis-ability-kit/js-apis-app-ability-want.md#want)。|
| wantUri  | string | 否   | 是   | 应用在创建wantAgent时，传入的want的uri字段，具体含义请参考[uri](../apis-ability-kit/js-apis-app-ability-want.md#want)。 |
| wantParameters  | Record\<string, Object> | 否   | 是   | 应用在创建wantAgent时，传入的want的parameters字段，具体含义请参考[parameters](../apis-ability-kit/js-apis-app-ability-want.md#want)。 |