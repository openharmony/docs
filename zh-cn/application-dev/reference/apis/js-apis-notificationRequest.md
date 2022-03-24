# NotificationRequest

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## NotificationRequest

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                  | 可读 | 可写 | 类型                                          | 必填 | 描述                       |
| --------------------- | ---- | --- | --------------------------------------------- | ---- | -------------------------- |
| content               | 是  | 是  | [NotificationContent](#notificationcontent)   | 是   | 通知内容。                   |
| id                    | 是  | 是  | number                                        | 否   | 通知ID。                     |
| slotType              | 是  | 是  | [SlotType](#slottype)                                      | 否   | 通道类型。                   |
| isOngoing             | 是  | 是  | boolean                                       | 否   | 是否进行时通知。             |
| isUnremovable         | 是  | 是  | boolean                                       | 否   | 是否可移除。                 |
| deliveryTime          | 是  | 是  | number                                        | 否   | 通知发送时间。               |
| tapDismissed          | 是  | 是  | boolean                                       | 否   | 通知是否自动清除。           |
| autoDeletedTime       | 是  | 是  | number                                        | 否   | 自动清除的时间。             |
| wantAgent             | 是  | 是  | WantAgent                                     | 否   | 点击跳转的WantAgent。        |
| extraInfo             | 是  | 是  | {[key: string]: any}                          | 否   | 扩展参数。                   |
| color                 | 是  | 是  | number                                        | 否   | 通知背景颜色。               |
| colorEnabled          | 是  | 是  | boolean                                       | 否   | 通知背景颜色是否使能。       |
| isAlertOnce           | 是  | 是  | boolean                                       | 否   | 设置是否仅有一次此通知警报。 |
| isStopwatch           | 是  | 是  | boolean                                       | 否   | 是否显示已用时间。           |
| isCountDown           | 是  | 是  | boolean                                       | 否   | 是否显示倒计时时间。         |
| isFloatingIcon        | 是  | 是  | boolean                                       | 否   | 是否显示状态栏图标。         |
| label                 | 是  | 是  | string                                        | 否   | 通知标签。                   |
| badgeIconStyle        | 是  | 是  | number                                        | 否   | 通知角标类型。               |
| showDeliveryTime      | 是  | 是  | boolean                                       | 否   | 是否显示分发时间。           |
| actionButtons         | 是  | 是  | Array\<[NotificationActionButton](#notificationactionbutton)\>             | 否   | 通知按钮，最多两个按钮。     |
| smallIcon             | 是  | 是  | PixelMap                                      | 否   | 通知小图标。                 |
| largeIcon             | 是  | 是  | PixelMap                                      | 否   | 通知大图标。                 |
| creatorBundleName     | 是  | 否  | string                                        | 否   | 创建通知的包名。             |
| creatorUid            | 是  | 否  | number                                        | 否   | 创建通知的UID。              |
| creatorPid            | 是  | 否  | number                                        | 否   | 创建通知的PID。              |
| creatorUserId<sup>8+</sup>| 是  | 否  | number                                    | 否   | 创建通知的UserId。           |
| hashCode              | 是  | 否  | string                                        | 否   | 通知唯一标识。               |
| classification        | 是  | 是  | string                                        | 否   | 通知分类。                   |
| groupName<sup>8+</sup>| 是  | 是  | string                                        | 否   | 组通知名称。                 |
| template<sup>8+</sup> | 是  | 是  | [NotificationTemplate](#notificationtemplate) | 否   | 通知模板。                   |
| isRemoveAllowed<sup>8+</sup> | 是  | 否  | boolean                                | 否   | 通知是否能被移除。                   |
| source<sup>8+</sup>   | 是  | 否  | number                                        | 否   | 通知源。                   |
| distributedOption<sup>8+</sup>   | 是  | 是  | DistributedOptions                 | 否   | 分布式通知的选项。          |
| deviceId<sup>8+</sup> | 是  | 否  | string                                        | 否   | 通知源的deviceId。          |
| notificationFlags<sup>8+</sup> | 是  | 否  | NotificationFlags                    | 否   | 获取NotificationFlags。          |


## DistributedOptions<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                   | 可读 | 可写 | 类型            | 必填 | 描述                               |
| ---------------------- | ---- | ---- | -------------- | ---- | ---------------------------------- |
| isDistributed          | 是   | 是   | boolean        | 否   | 是否为分布式通知。                  |
| supportDisplayDevices  | 是   | 是   | Array\<string> | 是   | 可以同步通知到的设备类型。           |
| supportOperateDevices  | 是   | 是   | Array\<string> | 否   | 可以打开通知的设备。                |
| remindType             | 是   | 否   | number         | 否   | 通知的提醒方式。                    |