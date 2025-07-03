# @ohos.multimodalInput.gestureEvent (手势事件)(系统接口)

设备上报的手势事件。

>  **说明：**
>
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```js
import { Touch } from '@kit.InputKit';
```

## TouchGestureEvent

触摸屏手势事件。

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称               | 类型                      | 只读 | 可选 | 说明             |
| ------------------ | ------------------------- | ---- | ---- | ---------------- |
| action | [TouchGestureAction](#touchgestureaction18) | 否   | 否   | 触摸屏手势类型。 |
| touches | [Touch](js-apis-touchevent.md#touch)[] | 否 | 否 | 触屏点信息。 |

## TouchGestureAction<sup>18+</sup>

触摸屏手势类型。

**系统能力**：SystemCapability.MultimodalInput.Input.Core

| 名称            | 值  | 说明             |
| --------------- | --- | --------------- |
| SWIPE_DOWN | 0   | 多指向下滑动。   |
| SWIPE_UP | 1   | 多指向上滑动。   |
| SWIPE_LEFT | 2   | 多指向左滑动。   |
| SWIPE_RIGHT | 3   | 多指向右滑动。   |
| PINCH_CLOSED | 4   | 多指捏合。       |
| PINCH_OPENED | 5   | 多指张开。       |
| GESTURE_END | 6   | 手势结束。       |
