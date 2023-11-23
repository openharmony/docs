# @ohos.multimodalInput.keyEvent    
设备上报的按键事件，继承自<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inputevent.md">InputEvent</a>。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Action    
按键事件类型。  
    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CANCEL | 0 | 按键取消<br/> |  
| DOWN | 1 | 按键按下<br/> |  
| UP | 2 | 按键抬起<br/> |  
    
## Key    
按键。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code | KeyCode | false | true | 按键码<br/> |  
| pressedTime | number | false | true | 按键按下时间，单位为微秒（μs）<br/> |  
| deviceId | number | false | true | 按键所属设备id<br/> |  
    
## KeyEvent    
按键事件。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| action | Action | false | true | 按键动作<br/> |  
| key | Key | false | true | 当前上报的按键<br/> |  
| unicodeChar | number | false | true | 按键对应的uniCode字符<br/> |  
| keys | Key[] | false | true | 当前处于按下状态的按键列表<br/> |  
| ctrlKey | boolean | false | true | 当前ctrlKey是否处于按下状态<br/>ture表示处于按下状态，false表示处于抬起状态。<br/> |  
| altKey | boolean | false | true | 当前altKey是否处于按下状态<br/> |  
| shiftKey | boolean | false | true | 当前shiftKey是否处于按下状态<br/> |  
| logoKey | boolean | false | true | 当前logoKey是否处于按下状态<br/> |  
| fnKey | boolean | false | true | 当前fnKey是否处于按下状态<br/> |  
| capsLock | boolean | false | true | 当前capsLock是否处于激活状态<br/>ture表示处于激活状态，false表示处于未激活状态。 |  
| numLock | boolean | false | true | 当前numLock是否处于激活状态<br/> |  
| scrollLock | boolean | false | true | 当前scrollLock是否处于激活状态。 |  
