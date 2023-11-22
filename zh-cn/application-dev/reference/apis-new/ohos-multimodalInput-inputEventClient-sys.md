# @ohos.multimodalInput.inputEventClient    
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputEventClient from '@ohos.multimodalInput.inputEventClient'    
```  
    
## KeyEvent    
按键注入描述信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputSimulator    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputSimulator    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isPressed | boolean | false | true | 按键是否按下。<br>ture表示按键按下，false表示按键抬起。 |  
| keyCode | number | false | true | 按键键码值。当前仅支持返回键/KEYCODE_BACK键。 |  
| keyDownDuration | number | false | true | 按键按下持续时间，单位为微秒（μs）。 |  
| isIntercepted | boolean | false | true | 按键是否可以被拦截。<br>ture表示可以被拦截，false表示不可被拦截。 |  
    
## injectEvent    
按键(包括单个按键和组合键)注入。  
 **调用形式：**     
- injectEvent({ KeyEvent: KeyEvent }): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputSimulator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| { KeyEvent: KeyEvent } |  | true | 按键注入描述信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let backKeyDown: inputEventClient.KeyEvent = {  
    isPressed: true,  
    keyCode: 2,  
    keyDownDuration: 0,  
    isIntercepted: false  
  }  
  
  class EventDown {  
    KeyEvent: inputEventClient.KeyEvent | null = null  
  }  
  
  let eventDown: EventDown = { KeyEvent: backKeyDown }  
  inputEventClient.injectEvent(eventDown);  
  
  let backKeyUp: inputEventClient.KeyEvent = {  
    isPressed: false,  
    keyCode: 2,  
    keyDownDuration: 0,  
    isIntercepted: false  
  };  
  
  class EventUp {  
    KeyEvent: inputEventClient.KeyEvent | null = null  
  }  
  
  let eventUp: EventUp = { KeyEvent: backKeyUp }  
  inputEventClient.injectEvent(eventUp);  
} catch (error) {  
  console.log(`Failed to inject KeyEvent, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
