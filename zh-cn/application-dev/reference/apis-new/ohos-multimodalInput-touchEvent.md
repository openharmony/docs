# @ohos.multimodalInput.touchEvent    
设备上报的触摸（触屏）事件，继承自<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inputevent.md">InputEvent</a>。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Action    
触摸事件类型。  
    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CANCEL | 0 | 触摸取消<br/> |  
| DOWN | 1 | 触摸按下 |  
| MOVE | 2 | 触摸移动 |  
| UP | 3 | 触摸抬起 |  
    
## ToolType    
操作触摸的工具类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FINGER | 0 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>手指 |  
| PEN | 1 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>笔 |  
| RUBBER | 2 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>x橡皮擦 |  
| BRUSH | 3 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>笔刷 |  
| PENCIL | 4 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>铅笔 |  
| AIRBRUSH | 5 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>气笔 |  
| MOUSE | 6 | 系统能力：SystemCapability.MultimodalInput.Input.Core<br>鼠标 |  
| LENS | 7 | 透镜 |  
    
## SourceType    
触摸来源的设备类型。    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TOUCH_SCREEN | 0 | 触摸屏 |  
| PEN | 1 | 手写笔 |  
| TOUCH_PAD | 2 | 触控板 |  
    
## Touch    
触摸点信息。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | 触摸事件标识 |  
| pressedTime | number | false | true | 按下时间戳，单位为微秒（μs） |  
| screenX | number | false | true | 触摸位置所属的屏幕x坐标 |  
| screenY | number | false | true | 触摸位置所属的屏幕y坐标 |  
| windowX | number | false | true | 触摸位置在窗口中的x坐标 |  
| windowY | number | false | true | 触摸位置在窗口中的y坐标 |  
| pressure | number | false | true | 压力值，取值范围是[0.0, 1.0], 0.0表示不支持 |  
| width | number | false | true | 触摸区域的宽度 |  
| height | number | false | true | 触摸区域的高度 |  
| tiltX | number | false | true | 相对YZ平面的角度,取值的范围[-90, 90]，其中正值是向右倾斜 |  
| tiltY | number | false | true | 相对XZ平面的角度,值的范围[-90, 90]，其中正值是向下倾斜 |  
| toolX | number | false | true | 工具区域的中心点x坐标 |  
| toolY | number | false | true | 工具区域的中心点y坐标 |  
| toolWidth | number | false | true | 工具区域宽度 |  
| toolHeight | number | false | true | 工具区域高度 |  
| rawX | number | false | true | 输入设备上的x坐标 |  
| rawY | number | false | true | 输入设备上的y坐标 |  
| toolType | ToolType | false | true | 工具类型 |  
    
## TouchEvent    
触屏事件。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| action | Action | false | true | 触屏事件类型 |  
| touch | Touch | false | true | 当前触摸点信息 |  
| touches | Touch[] | false | true | 所有触摸点 |  
| sourceType | SourceType | false | true | 触摸来源的设备类型。 |  
