# notificationRequest    
描述通知的请求。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationRequest  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| content | NotificationContent | false | true | 通知内容。 |  
| id | number | false | false | 通知ID。 |  
| slotType | notification.SlotType | false | false | 通道类型。 |  
| isOngoing | boolean | false | false | 是否进行时通知。 |  
| isUnremovable | boolean | false | false | 是否可移除（应用于长时间通知任务上，比如地图、音乐播放；点击通知下方删除按钮无法删除，左滑点击单个删除按钮可删除）。 |  
| deliveryTime | number | false | false | 通知发送时间。 |  
| tapDismissed | boolean | false | false | 通知是否自动清除。 |  
| autoDeletedTime | number | false | false | 自动清除的时间。 |  
| wantAgent | WantAgent | false | false | WantAgent封装了应用的行为意图，点击通知时触发该行为。 |  
| extraInfo | object | false | false | 扩展参数。 |  
| color | number | false | false | 通知背景颜色。预留能力，暂未支持。 |  
| colorEnabled | boolean | false | false | 通知背景颜色是否使能。预留能力，暂未支持。 |  
| isAlertOnce | boolean | false | false | 设置是否仅有一次此通知提醒。 |  
| isStopwatch | boolean | false | false | 是否显示已用时间。 |  
| isCountDown | boolean | false | false | 是否显示倒计时时间。 |  
| isFloatingIcon | boolean | false | false | 是否显示状态栏图标。 |  
| label | string | false | false | 通知标签。 |  
| badgeIconStyle | number | false | false | 通知角标类型。预留能力，暂未支持。 |  
| showDeliveryTime | boolean | false | false | 是否显示分发时间。 |  
| actionButtons | Array<NotificationActionButton> | false | false | 通知按钮，最多三个按钮。 |  
| smallIcon | image.PixelMap | false | false | 通知小图标。可选字段，大小不超过30KB。 |  
| largeIcon | image.PixelMap | false | false | 通知大图标。可选字段，大小不超过30KB。 |  
| groupName<sup>(8+)</sup> | string | false | false | 创建通知的包名。 |  
| creatorBundleName | string | true | false | 创建通知的包名。 |  
| creatorUid | number | true | false | 创建通知的UID。 |  
| creatorPid | number | true | false | 创建通知的PID。 |  
| creatorUserId<sup>(8+)</sup> | number | true | false | 创建通知的UserId。 |  
| hashCode | string | true | false | 通知唯一标识。 |  
| template<sup>(8+)</sup> | NotificationTemplate | false | false | 通知模板。 |  
| distributedOption<sup>(8+)</sup> | DistributedOptions | false | false | 分布式通知的选项。 |  
| notificationFlags<sup>(8+)</sup> | NotificationFlags | true | false | 获取NotificationFlags。 |  
| removalWantAgent<sup>(9+)</sup> | WantAgent | false | false | 当移除通知时，通知将被重定向到的WantAgent实例。 |  
| badgeNumber<sup>(9+)</sup> | number | false | false | 应用程序图标上显示的通知数。 |  
    
## DistributedOptions<sup>(8+)</sup>    
描述分布式选项。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isDistributed<sup>(8+)</sup> | boolean | false | false | 是否为分布式通知。 |  
| supportDisplayDevices<sup>(8+)</sup> | Array<string> | false | false | 可以同步通知到的设备列表。 |  
| supportOperateDevices<sup>(8+)</sup> | Array<string> | false | false | 可以打开通知的设备列表。 |  
