# commonEventPublishData    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## CommonEventPublishData    
包含公共事件内容和属性。  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
### 属性    
 **系统能力:**  SystemCapability.Notification.CommonEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | false | 表示订阅者包名称，只有包名为bundleName的订阅者才能收到该公共事件。<br/> |  
| code | number | false | false | 表示公共事件的结果代码。<br/> |  
| data | string | false | false | 表示公共事件的自定义结果数据。<br/> |  
| subscriberPermissions | Array<string> | false | false | 表示订阅者的权限。<br/> |  
| isOrdered | boolean | false | false | 表示是否是有序事件。<br/> |  
| isSticky | boolean | false | false | 表示是否是粘性事件。仅系统应用或系统服务允许发送粘性事件。<br/> |  
| parameters | object | false | false | 表示公共事件的附加信息。 |  
