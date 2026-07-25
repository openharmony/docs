# @ohos.inputMethodEngine (输入法服务)(系统接口)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

本模块为系统输入法应用提供管理能力，包括创建软键盘窗口、插入/删除字符、选中文本、监听物理键盘按键事件等。适用于需要自定义输入法交互的场景，能提升输入体验。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标标记接口起始版本。

## 导入模块

```ts
import { inputMethodEngine } from '@kit.IMEKit';
```

## SizeUpdateCallback<sup>14+</sup>

type SizeUpdateCallback = (size: window.Size, keyboardArea: KeyboardArea) => void

当输入法面板大小变化时触发的回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名       | 类型                                                 | 必填 | 说明                             |
| ------------ | ---------------------------------------------------- | ---- | -------------------------------- |
| size         | [window.Size](../apis-arkui/arkts-apis-window-i.md#size7) | 是   | 当前面板大小，包含宽度和高度。                   |
| keyboardArea | [KeyboardArea](./js-apis-inputmethodengine.md#keyboardarea15)    | 是   | 当前面板的键盘区域大小。 |

## Panel<sup>10+</sup>

下列API均需使用[createPanel](./js-apis-inputmethodengine.md#createpanel10)获取到Panel实例后，通过实例调用。

### on('sizeUpdate')<sup>14+</sup>

on(type: 'sizeUpdate', callback: SizeUpdateCallback): void

通过Panel实例监听当前面板大小变化，在变化发生时通过callback异步回调。

**返回值：**

| 类型 | 说明 |
| --- | --- |
| void | 无返回值，用于异步注册监听当前面板大小变化的事件 |

> **说明:**
>
> 仅用于SOFT_KEYBOARD类型，状态为FLG_FIXED或FLG_FLOATING的面板。输入法通过[adjustPanelRect](./js-apis-inputmethodengine.md#adjustpanelrect15)等接口对面板大小进行调节时，系统会根据一定规则校验计算出最终的数值（例如：超出屏幕等场景）。输入法应用可通过该回调获取最终的面板大小，完成最终的面板布局刷新。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                   |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                      | 是   | 监听当前面板的大小是否产生变化，固定取值为'sizeUpdate'。 |
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | 是   | 面板大小变化时的回调，参数包含当前软键盘面板的宽度和高度。 |

**示例：**

```ts
import { window } from '@kit.ArkUI';

// 监听面板大小变化
panel.on('sizeUpdate', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
  // 打印面板大小和键盘区域信息
  console.info(`panel size changed, windowSize: ${windowSize.width}, ${windowSize.height}, ` +
    `keyboardArea: ${keyboardArea.top}, ${keyboardArea.bottom}, ${keyboardArea.left}, ${keyboardArea.right}`);
});
```

### off('sizeUpdate')<sup>14+</sup>

off(type: 'sizeUpdate', callback?: SizeUpdateCallback): void

通过Panel实例取消监听当前面板大小变化，停止callback异步回调。

**返回值：**

| 类型 | 说明 |
| --- | --- |
| void | 无返回值，用于异步取消监听当前面板大小变化的事件 |

> **说明:**
>
> 仅用于SOFT_KEYBOARD类型，状态为FLG_FIXED或FLG_FLOATING的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                     |
| -------- | ------------------------------------------- | ---- | -------------------------------------------------------- |
| type     | string                                      | 是   | 取消监听当前面板的大小是否产生变化，固定值为'sizeUpdate'。 |
| callback | [SizeUpdateCallback](#sizeupdatecallback14) | 否   | 回调函数。用于指定要取消监听的回调函数，如果不填则取消所有sizeUpdate监听。 |

**示例：**

```ts
import { window } from '@kit.ArkUI';

// 取消监听面板大小变化
panel.off('sizeUpdate', (windowSize: window.Size, _keyboardArea: inputMethodEngine.KeyboardArea) => {
  // 打印面板宽度、高度信息
  console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
});
```

### setShadow<sup>22+</sup>

setShadow(radius: number, color: string, offsetX: number, offsetY: number): void

通过Panel实例设置输入法窗口阴影效果。

**返回值：**

| 类型 | 说明 |
| --- | --- |
| void | 无返回值，用于设置输入法窗口阴影效果 |

> **说明:**
>
> 不支持[PanelType](./js-apis-inputmethodengine.md#paneltype10)为SOFT_KEYBOARD类型且[PanelFlag](./js-apis-inputmethodengine.md#panelflag10)状态为FLG_FIXED的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| radius  | number | 是   | 窗口边缘阴影的模糊半径，单位px，取值范围[0.0, +∞)，0.0时关闭窗口边缘阴影。 |
| color   | string | 是   | 窗口边缘阴影的颜色，十六进制RGB或ARGB格式，不区分大小写，例如`#000000`或`#FF000000`。 |
| offsetX | number | 是   | 窗口边缘阴影X轴的偏移量，单位px。正值向右偏移，负值向左偏移。 |
| offsetY | number | 是   | 窗口边缘阴影Y轴的偏移量，单位px。正值向下偏移，负值向上偏移。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 202 | not system application. |
| 12800013  | window manager service error.      |
| 12800017 | invalid panel type or panel flag. Possible causes: Panel's flag is FLG_FIXED. |

**示例：**

```ts
// 设置输入法窗口阴影效果，半径20px，颜色黑色，X/Y轴偏移量均为20px
panel.setShadow(20, '#000000', 20, 20);
```
## FluidLightMode<sup>20+</sup>

枚举，输入法流光模式。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

| 名称         | 值 | 说明               |
| ------------ | -- | ------------------ |
| NONE | 0 | 不使用流光模式。 |
| BACKGROUND_FLUID_LIGHT  | 1 | 开启背景流光模式。系统面板变为透明，流光效果由编辑框宿主应用实现。 |

## EditorAttribute<sup>20+</sup>

编辑框属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

| 名称         | 类型 | 只读 | 可选 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| fluidLightMode | [FluidLightMode](#fluidlightmode20) | 否 | 是 | 流光模式。未设置或设置非法值时，默认不使用流光模式。<br>该属性仅系统应用可以使用。|

## ImmersiveEffect<sup>20+</sup>

沉浸效果。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

| 名称   | 类型                                  | 只读 | 可选 | 说明           |
| ------ | ------------------------------------ | ---- | ---- | -------------- |
| fluidLightMode | [FluidLightMode](#fluidlightmode20) | 否   | 是   | 流光模式，未填充时默认为NONE。<br>该属性仅系统应用可以使用。 |
<!--no_check-->