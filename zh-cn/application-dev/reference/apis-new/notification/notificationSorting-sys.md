# notificationSorting    
提供有关活动通知的排序信息。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationSorting  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slot | NotificationSlot | true | true | 通道类型。<br/> |  
| hashCode | string | true | true | 通知级别，不设置则根据通知渠道类型有默认值。<br/> |  
| ranking | number | true | true | 通知唯一标识。 |  
