# @ohos.multimodalInput.gestureEvent    
设备上报的手势事件。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Pinch    
捏合事件。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ActionType | false | true | 捏合事件类型<br/> |  
| scale | number | false | true | 捏合度，取值范围大于等于0<br/> |  
    
## ThreeFingersSwipe    
三指滑动事件。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ActionType | false | true | 三指滑动事件类型<br/> |  
| x | number | false | true | 坐标x<br/> |  
| y | number | false | true | 坐标y<br/> |  
    
## FourFingersSwipe    
四指滑动事件。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ActionType | false | true | 四指滑动事件类型<br/> |  
| x | number | false | true | 坐标x<br/> |  
| y | number | false | true | 坐标y<br/> |  
    
## ActionType    
手势事件类型。    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CANCEL | 0 | 取消<br/> |  
| BEGIN | 1 | 手势开始<br/> |  
| UPDATE | 2 | 手势更新<br/> |  
| END | 3 | 手势结束。 |  
