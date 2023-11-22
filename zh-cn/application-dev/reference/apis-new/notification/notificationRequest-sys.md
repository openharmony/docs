# notificationRequest    
描述通知的请求。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## NotificationRequest  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| classification | string | false | false | 通知唯一标识。 |  
| isRemoveAllowed<sup>(8+)</sup> | boolean | false | false | 通知是否能被移除（点击通知下方删除按钮无法删除，左滑不出现删除按钮）。 |  
| source<sup>(8+)</sup> | number | true | false | 通知源。 |  
| deviceId<sup>(8+)</sup> | string | true | false | 通知源的deviceId。 |  
    
## DistributedOptions<sup>(8+)</sup>    
描述分布式选项。  
 **系统能力:**  SystemCapability.Notification.Notification    
### 属性    
 **系统能力:**  SystemCapability.Notification.Notification    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| remindType<sup>(8+)</sup> | number | true | false | 通知的提醒方式。 |  
