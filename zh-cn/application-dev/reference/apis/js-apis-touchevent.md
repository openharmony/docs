# 触摸输入事件

设备上报的触屏事件。

>  **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {Action,ToolType,SourceType,Touch,TouchEvent} from '@ohos.multimodalInput.touchEvent';
```

## Action

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称     | 类型   | 可读   | 可写   | 说明   |
| ------ | ------ | ---- | ---- | ---- |
| CANCEL | number | 是    | 否    | 触摸取消 |
| DOWN   | number | 是    | 否    | 触摸按下 |
| MOVE   | number | 是    | 否    | 触摸移动 |
| UP     | number | 是    | 否    | 触摸抬起 |

## ToolType

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称       | 类型   | 可读   | 可写   | 说明   |
| -------- | ------ | ---- | ---- | ---- |
| FINGER   | number | 是    | 否    | 手指   |
| PEN      | number | 是    | 否    | 笔    |
| RUBBER   | number | 是    | 否    | 橡皮擦  |
| BRUSH    | number | 是    | 否    | 笔刷   |
| PENCIL   | number | 是    | 否    | 铅笔   |
| AIRBRUSH | number | 是    | 否    | 气笔   |
| MOUSE    | number | 是    | 否    | 鼠标   |
| LENS     | number | 是    | 否    | 透镜   |

## SourceType 

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称           | 类型   | 可读   | 可写   | 说明   |
| ------------ | ------ | ---- | ---- | ---- |
| TOUCH_SCREEN | number | 是    | 否    | 触摸屏  |
| PEN          | number | 是    | 否    | 手写笔  |
| TOUCH_PAD    | number | 是    | 否    | 触摸板  |

## Touch

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称          | 类型   | 可读   | 可写   | 说明                                  |
| ----------- | ------ | ---- | ---- | ----------------------------------- |
| id          | number | 是    | 否    | 触摸事件标识                                |
| pressedTime | number | 是    | 否    | 按下时间戳                             |
| screenX     | number | 是    | 否    | 触摸位置所属的屏幕x坐标                        |
| screenY     | number | 是    | 否    | 触摸位置所属的屏幕y坐标                        |
| windowX     | number | 是    | 否    | 触摸位置在窗口中的x坐标                        |
| windowY     | number | 是    | 否    | 触摸位置在窗口中的y坐标                        |
| pressure    | number | 是    | 否    | 压力值，取值范围是[0.0, 1.0], 0.0表示不支持       |
| width       | number | 是    | 否    | 触摸区域的宽度                           |
| height      | number | 是    | 否    | 触摸区域的高度                           |
| tiltX       | number | 是    | 否    | 相对YZ平面的角度,取值的范围[-90, 90]，其中正值是向右倾斜。 |
| tiltY       | number | 是    | 否    | 相对XZ平面的角度,值的范围[-90, 90]，其中正值是向下倾斜。  |
| toolX       | number | 是    | 否    | 工具区域的中心点x坐标                           |
| toolY       | number | 是    | 否    | 工具区域的中心点y坐标                           |
| toolWidth   | number | 是    | 否    | 工具区域宽度                              |
| toolHeight  | number | 是    | 否    | 工具区域高度                              |
| rawX        | number | 是    | 否    | 输入设备上的x坐标                           |
| rawY        | number | 是    | 否    | 输入设备上的y坐标                           |
| toolType    | number | 是    | 否    | 工具类型                                |

## TouchEvent

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称         | 类型       | 可读   | 可写   | 说明        |
| ---------- | ---------- | ---- | ---- | --------- |
| action     | Action     | 是    | 否    | 触摸动作      |
| touch      | Touch      | 是    | 否    | 当前触摸点     |
| touches    | Touch[]    | 是    | 否    | 所有触摸点     |
| sourceType | SourceType | 是    | 否    | 触摸来源的设备类型 |
