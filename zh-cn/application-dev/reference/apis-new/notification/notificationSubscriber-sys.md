# notificationSubscriber    
作为订阅通知接口[subscribe](js-apis-notificationSubscribe.md)的入参，提供订阅者接收到新通知、取消通知等的回调方法。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationSubscriber  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onConsume | (data: SubscribeCallbackData) => void | false | false | 接收到新通知的回调函数。 |  
| onCancel | (data: SubscribeCallbackData) => void | false | false | 取消通知的回调函数。 |  
| onUpdate | (data: NotificationSortingMap) => void | false | false | 更新通知排序的回调函数。 |  
| onConnect | () => void | false | false | 订阅完成的回调函数。 |  
| onDisconnect | () => void | false | false | 取消订阅的回调函数。 |  
| onDestroy | () => void | false | false | 服务失联回调函数。 |  
| onDoNotDisturbDateChange<sup>(8+)</sup> | (mode: notification.DoNotDisturbDate) => void | false | false | 免打扰时间选项发生变更时的回调函数。 |  
| onEnabledNotificationChanged<sup>(8+)</sup> | (callbackData: EnabledNotificationCallbackData) => void | false | false | 监听应用通知使能变化。 |  
| onBadgeChanged<sup>(10+)</sup> | (data: BadgeNumberCallbackData) => void | false | false | 监听应用角标个数变化。 |  
    
## SubscribeCallbackData  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| request | NotificationRequest | true | true | 通知内容。 |  
| sortingMap | NotificationSortingMap | true | false | 通知排序信息。 |  
| reason | number | true | false | 删除原因。 |  
| sound | string | true | false | 通知声音。 |  
| vibrationValues | Array<number> | true | false | 通知震动。 |  
    
## EnabledNotificationCallbackData<sup>(8+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundle<sup>(8+)</sup> | string | true | true | 应用的包名。 |  
| uid<sup>(8+)</sup> | number | true | true | 应用的uid。 |  
| enable<sup>(8+)</sup> | boolean | true | true | 应用通知使能状态。 |  
    
## BadgeNumberCallbackData<sup>(10+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundle<sup>(10+)</sup> | string | true | true | 应用的包名。 |  
| uid<sup>(10+)</sup> | number | true | true | 应用的uid。 |  
| badgeNumber<sup>(10+)</sup> | number | true | true | 角标个数。 |  
