# @ohos.accessibility.GesturePath    
GesturePath表示手势路径信息。  
  
本模块用于创建辅助功能注入手势所需的手势路径信息。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## GesturePath  
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
### 属性    
 **系统能力:**  SystemCapability.BarrierFree.Accessibility.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| points | Array<GesturePoint> | false | true | 手势触摸点。 |  
| durationTime | number | false | true | 手势总耗时, 单位为毫秒。 |  
