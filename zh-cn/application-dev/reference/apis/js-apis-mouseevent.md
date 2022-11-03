# 鼠标输入事件

设备上报的鼠标事件。

>  **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import {Action,Button,Axis,AxisValue,MouseEvent} from '@ohos.multimodalInput.mouseEvent';
```

## Action

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称        | 参数类型 | 可读 | 可写 | 描述                 |
| ----------- | -------- | ---- | ---- | -------------------- |
| CANCEL      | number   | 是   | 否   | 取消动作             |
| MOVE        | number   | 是   | 否   | 鼠标移动             |
| BUTTON_DOWN | number   | 是   | 否   | 鼠标按钮按下         |
| BUTTON_UP   | number   | 是   | 否   | 鼠标按钮抬起         |
| AXIS_BEGIN  | number   | 是   | 否   | 鼠标关联的轴事件开始 |
| AXIS_UPDATE | number   | 是   | 否   | 鼠标关联的轴事件更新 |
| AXIS_END    | number   | 是   | 否   | 鼠标关联的轴事件结束 |


## Button

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称      | 参数类型   | 可读   | 可写   | 描述    |
| ------- | ------ | ---- | ---- | ----- |
| LEFT    | number | 是    | 否    | 鼠标左键  |
| MIDDLE  | number | 是    | 否    | 鼠标中键  |
| RIGHT   | number | 是    | 否    | 鼠标右键  |
| SIDE    | number | 是    | 否    | 鼠标侧边键 |
| EXTRA   | number | 是    | 否    | 鼠标扩展键 |
| FORWARD | number | 是    | 否    | 鼠标前进键 |
| BACK    | number | 是    | 否    | 鼠标后退键 |
| TASK    | number | 是    | 否    | 鼠标任务键 |

## Axis

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称                | 参数类型   | 可读   | 可写   | 描述    |
| ----------------- | ------ | ---- | ---- | ----- |
| SCROLL_VERTICAL   | number | 是    | 否    | 垂直滚动轴 |
| SCROLL_HORIZONTAL | number | 是    | 否    | 水平滚动轴 |
| PINCH             | number | 是    | 否    | 捏合轴   |


## AxisValue

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称    | 参数类型   | 可读   | 可写   | 描述   |
| ----- | ------ | ---- | ---- | ---- |
| axis  | Axis   | 是    | 否    | 轴类型  |
| value | number | 是    | 否    | 轴的值  |


## MouseEvent

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称             | 参数类型        | 可读   | 可写   | 描述                                       |
| -------------- | ----------- | ---- | ---- | ---------------------------------------- |
| action         | Action      | 是    | 否    | 鼠标事件动作                                   |
| screenX        | number      | 是    | 否    | 鼠标光标在屏幕中的x坐标                             |
| screenY        | number      | 是    | 否    | 鼠标光标在屏幕中的y坐标                             |
| windowX        | number      | 是    | 否    | 鼠标归属窗口的x坐标                               |
| windowY        | number      | 是    | 否    | 鼠标归属窗口的y坐标                               |
| rawDeltaX      | number      | 是    | 否    | X轴相对上次上报鼠标位置的偏移，在屏幕边缘位置时，该值可能小于两次鼠标上报的坐标差 |
| rawDeltaY      | number      | 是    | 否    | Y轴相对上次上报鼠标位置的偏移                          |
| button         | Button      | 是    | 否    | 当前按下/抬起的按钮                               |
| pressedButtons | Button[]    | 是    | 否    | 当前处于按下状态的按钮                              |
| axes           | AxisValue[] | 是    | 否    | 事件包含的所有轴数据                               |
| pressedKeys    | KeyCode[]   | 是    | 否    | 当前处于按下状态的按键列表                            |
| ctrlKey        | boolean     | 是    | 否    | 当前ctrlKey是否处于按下状态                        |
| altKey         | boolean     | 是    | 否    | 当前altKey是否处于按下状态                         |
| shiftKey       | boolean     | 是    | 否    | 当前shiftKey是否处于按下状态                       |
| logoKey        | boolean     | 是    | 否    | 当前logoKey是否处于按下状态                        |
| fnKey          | boolean     | 是    | 否    | 当前fnKey是否处于按下状态                          |
| capsLock       | boolean     | 是    | 否    | 当前capsLock是否处于激活状态                       |
| numLock        | boolean     | 是    | 否    | 当前numLock是否处于激活状态                        |
| scrollLock     | boolean     | 是    | 否    | 当前scrollLock是否处于激活状态                     |
