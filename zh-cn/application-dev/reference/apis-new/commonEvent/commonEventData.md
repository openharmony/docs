# commonEventData    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## CommonEventData    
公共事件的数据。  
  
 **系统能力:**  SystemCapability.Notification.CommonEvent    
### 属性    
 **系统能力:**  SystemCapability.Notification.CommonEvent    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| event | string | false | true | 表示当前接收的公共事件名称。<br/> |  
| bundleName | string | false | false | 表示包名称，当前默认为空。<br/> |  
| code | number | false | false | 表示公共事件的结果代码，用于传递int类型的数据。<br/> |  
| data | string | false | false | 表示公共事件的自定义结果数据，用于传递string类型的数据。<br/> |  
| parameters | object | false | false | 表示公共事件的附加信息。 |  
