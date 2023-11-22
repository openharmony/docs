# notificationSlot    
描述通知槽。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationSlot  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | notification.SlotType | false | true | 通道类型。 |  
| level | notification.SlotLevel | false | false | 通知级别，不设置则根据通知渠道类型有默认值。 |  
| desc | string | false | false | 通知渠道描述信息。 |  
| badgeFlag | boolean | false | false | 是否显示角标。 |  
| bypassDnd | boolean | false | false | 是否在系统中绕过免打扰模式。 |  
| lockscreenVisibility | number | false | false | 在锁定屏幕上显示通知的模式。 |  
| vibrationEnabled | boolean | false | false | 是否可振动。 |  
| sound | string | false | false | 通知提示音。 |  
| lightEnabled | boolean | false | false | 是否闪灯。 |  
| lightColor | number | false | false | 通知灯颜色。 |  
| vibrationValues | Array<number> | false | false | 通知振动样式。 |  
| enabled<sup>(9+)</sup> | boolean | true | false | 此通知插槽中的启停状态。 |  
