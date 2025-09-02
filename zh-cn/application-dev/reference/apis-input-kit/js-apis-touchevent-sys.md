# @ohos.multimodalInput.touchEvent (触屏输入事件)(系统接口)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

设备上报的触屏事件，继承自[InputEvent](./js-apis-inputevent.md)。

> **说明：**
>
> 本模块首批接口从API version 19开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimodalInput.touchEvent (触屏输入事件)](js-apis-touchevent.md)。

## 导入模块

```js
import { FixedMode, Touch, TouchEvent } from '@kit.InputKit';
```

## FixedMode

修正坐标的模式。

**系统能力**：SystemCapability.MultimodalInput.Input.Core

**系统API**: 此接口为系统接口。

| 名称          | 值  | 说明   |
| ------------ | ------ | ---- |
| NONE       |  0 | 正常模式。 |
| AUTO |  1 | 单手模式。 |

## Touch

触屏点信息。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**系统API**: 此接口为系统接口。

| 名称          | 类型   | 只读   | 可选   | 说明                                  |
| ----------- | ------ | ---- | ---- | ----------------------------------- |
| fixedDisplayX | number| 否    | 是    | 适配单手模式下screenX坐标的修正值。 |
| fixedDisplayY | number| 否    | 是    | 适配单手模式下screenY坐标的修正值。    |

## TouchEvent

触屏事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**系统API**: 此接口为系统接口。

| 名称         | 类型       | 只读   | 可选   | 说明        |
| ---------- | ---------- | ---- | ---- | --------- |
| fixedMode  | [FixedMode](#fixedmode)   | 否    | 是    | 修正坐标的模式。|
| isInject<sup>20+</sup>  | boolean   | 否    | 是    | 表示该触屏事件是否为注入事件。注入事件详细介绍可参考[@ohos.multimodalInput.inputEventClient](js-apis-inputeventclient-sys.md)。|
