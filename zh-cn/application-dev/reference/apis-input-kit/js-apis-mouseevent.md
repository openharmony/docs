# @ohos.multimodalInput.mouseEvent (鼠标输入事件)

设备上报的鼠标事件，继承自[InputEvent](./js-apis-inputevent.md)。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { Action, Button, Axis, AxisValue, MouseEvent } from '@kit.InputKit';
```

## Action

鼠标事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称        | 值 | 说明                 |
| ----------- | -------- | -------------------- |
| CANCEL      | 0   | 取消。             |
| MOVE        | 1   | 鼠标移动。             |
| BUTTON_DOWN | 2   | 鼠标按钮按下。         |
| BUTTON_UP   | 3   | 鼠标按钮抬起。         |
| AXIS_BEGIN  | 4   | 鼠标轴事件开始。 |
| AXIS_UPDATE | 5   | 鼠标轴事件更新。 |
| AXIS_END    | 6   | 鼠标轴事件结束。 |
| ACTION_DOWN<sup>11+</sup> | 7   | 触摸板按下。 |
| ACTION_UP<sup>11+</sup> | 8   | 触摸板抬起。 |

## Button

鼠标按键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称      | 值  | 说明    |
| ------- | ------| ----- |
| LEFT    | 0 | 鼠标左键。  |
| MIDDLE  | 1 | 鼠标中键。  |
| RIGHT   | 2 | 鼠标右键。  |
| SIDE    | 3 | 鼠标侧边键。 |
| EXTRA   | 4 | 鼠标扩展键。 |
| FORWARD | 5 | 鼠标前进键。 |
| BACK    | 6 | 鼠标后退键。 |
| TASK    | 7 | 鼠标任务键。 |

## Axis

鼠标轴类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称                | 值     | 说明    |
| ----------------- | ------- | ----- |
| SCROLL_VERTICAL   | 0 | 垂直滚动轴。 |
| SCROLL_HORIZONTAL | 1 | 水平滚动轴。 |
| PINCH             | 2 | 捏合轴。   |


## AxisValue

鼠标轴类型和轴的值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称    | 类型   | 只读   | 可选   | 说明   |
| ----- | ------ | ---- | ---- | ---- |
| axis  | [Axis](#axis)   | 否    | 否    | 轴类型。  |
| value | number | 否    | 否    | 轴的值。  |

## ToolType<sup>11+</sup>

工具类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称      | 值  | 说明    |
| ------- | ------| ----- |
| UNKNOWN<sup>11+</sup> | 0 | 未知类型。  |
| MOUSE<sup>11+</sup>  | 1 | 鼠标。 |
| JOYSTICK<sup>11+</sup> | 2 | 摇杆。 |
| TOUCHPAD<sup>11+</sup> | 3 | 触摸板。 |

## MouseEvent

鼠标事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称             | 类型        | 只读   | 可选   | 说明                                       |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| action         | [Action](#action)      | 否    | 否    | 鼠标事件动作。                                   |
| screenX        | number      | 否    | 否    | 鼠标光标在屏幕中的横坐标。                             |
| screenY        | number      | 否    | 否    | 鼠标光标在屏幕中的纵坐标。                             |
| windowX        | number      | 否    | 否    | 鼠标所在窗口的横坐标。                               |
| windowY        | number      | 否    | 否    | 鼠标所在窗口的纵坐标。                               |
| rawDeltaX      | number      | 否    | 否    | 鼠标本次操作横坐标偏移值。 |
| rawDeltaY      | number      | 否    | 否    | 鼠标本次操作纵坐标偏移值。                          |
| button         | [Button](#button)      | 否    | 否    | 鼠标按钮。                       |        
| pressedButtons | [Button](#button)[]    | 否    | 否    | 当前处于按下状态的鼠标按钮。                              |
| axes           | [AxisValue](#axisvalue)[] | 否    | 否    | 事件包含的所有轴数据。                               |
| pressedKeys    | [KeyCode](js-apis-keycode.md#keycode)[]   | 否    | 否    | 当前处于按下状态的按键列表。                            |
| ctrlKey        | boolean     | 否    | 否    | 当前ctrlKey是否处于按下状态。 <br>true表示处于按下状态，false表示处于抬起状态。    |
| altKey         | boolean     | 否    | 否    | 当前altKey是否处于按下状态。 <br>true表示处于按下状态，false表示处于抬起状态。                         |
| shiftKey       | boolean     | 否    | 否    | 当前shiftKey是否处于按下状态。 <br>true表示处于按下状态，false表示处于抬起状态。                       |
| logoKey        | boolean     | 否    | 否    | 当前logoKey是否处于按下状态。 <br>true表示处于按下状态，false表示处于抬起状态。                        |
| fnKey          | boolean     | 否    | 否    | 当前fnKey是否处于按下状态。 <br>true表示处于按下状态，false表示处于抬起状态。                          |
| capsLock       | boolean     | 否    | 否    | 当前capsLock是否处于激活状态。 <br>true表示激活状态，false表示处于未激活状态。  |
| numLock        | boolean     | 否    | 否    | 当前numLock是否处于激活状态。 <br>true表示激活状态，false表示处于未激活状态。                        |
| scrollLock     | boolean     | 否    | 否    | 当前scrollLock是否处于激活状态。 <br>true表示激活状态，false表示处于未激活状态。                     |
| toolType<sup>11+</sup> | [ToolType](#tooltype11) | 否    | 否    | 工具类型。                     |
