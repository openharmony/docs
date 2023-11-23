# @ohos.multimodalInput.mouseEvent    
设备上报的鼠标事件，继承自<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inputevent.md">InputEvent</a>。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Action    
鼠标事件类型。  
    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CANCEL | 0 | 取消<br/> |  
| MOVE | 1 | 鼠标移动<br/> |  
| BUTTON_DOWN | 2 | 鼠标按钮按下<br/> |  
| BUTTON_UP | 3 | 鼠标按钮抬起<br/> |  
| AXIS_BEGIN | 4 | 鼠标轴事件开始<br/> |  
| AXIS_UPDATE | 5 | 鼠标轴事件更新<br/> |  
| AXIS_END | 6 | 鼠标轴事件结束<br/> |  
    
## Button    
鼠标按键。  
    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LEFT | 0 | 鼠标左键<br/> |  
| MIDDLE | 1 | 鼠标中键<br/> |  
| RIGHT | 2 | 鼠标右键<br/> |  
| SIDE | 3 | 鼠标侧边键<br/> |  
| EXTRA | 4 | 鼠标扩展键<br/> |  
| FORWARD | 5 | 鼠标前进键<br/> |  
| BACK | 6 | 鼠标后退键<br/> |  
| TASK | 7 | 鼠标任务键<br/> |  
    
## Axis    
鼠标轴类型。  
    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCROLL_VERTICAL | 0 | 垂直滚动轴<br/> |  
| SCROLL_HORIZONTAL | 1 | 水平滚动轴<br/> |  
| PINCH | 2 | 捏合轴<br/> |  
    
## AxisValue    
鼠标轴类型和轴的值。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| axis | Axis | false | true | 轴类型<br/> |  
| value | number | false | true | 轴的值<br/> |  
    
## MouseEvent    
鼠标事件。  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| action | Action | false | true | 鼠标事件动作<br/> |  
| screenX | number | false | true | 鼠标光标在屏幕中的横坐标<br/> |  
| screenY | number | false | true | 鼠标光标在屏幕中的纵坐标<br/> |  
| windowX | number | false | true | 鼠标所在窗口的横坐标<br/> |  
| windowY | number | false | true | 鼠标所在窗口的纵坐标<br/> |  
| rawDeltaX | number | false | true | 鼠标本次操作横坐标偏移值<br/> |  
| rawDeltaY | number | false | true | 鼠标本次操作纵坐标偏移值<br/> |  
| button | Button | false | true | 鼠标按钮<br/> |  
| pressedButtons | Button[] | false | true | 当前处于按下状态的鼠标按钮<br/> |  
| axes | AxisValue[] | false | true | 事件包含的所有轴数据<br/> |  
| pressedKeys | KeyCode[] | false | true | 当前处于按下状态的按键列表<br/> |  
| ctrlKey | boolean | false | true | 当前ctrlKey是否处于按下状态<br/>ture表示处于按下状态，false表示处于抬起状态<br/> |  
| altKey | boolean | false | true | 当前altKey是否处于按下状态<br/> |  
| shiftKey | boolean | false | true | 当前shiftKey是否处于按下状态<br/> |  
| logoKey | boolean | false | true | 当前logoKey是否处于按下状态<br/> |  
| fnKey | boolean | false | true | 当前fnKey是否处于按下状态<br/> |  
| capsLock | boolean | false | true | 当前capsLock是否处于激活状态<br/>ture表示激活状态，false表示处于未激活状态<br/> |  
| numLock | boolean | false | true | 当前numLock是否处于激活状态<br/> |  
| scrollLock | boolean | false | true | 当前scrollLock是否处于激活状态。 |  
