# 文本组件公共接口 (系统接口)

文本类组件公共接口。

>  **说明：**
>
>  本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  当前页面仅包含本模块的系统接口，其他公开接口参见[公共类型](ts-types.md)和[文本组件公共接口](ts-text-common.md)。

## TextContentControllerBase

TextInput、TextArea、Search的基础控制器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getText<sup>19+</sup>

getText(range?: TextRange): string

获取指定范围的文本内容。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| range | [TextRange](ts-text-common.md#textrange12) | 否    | 获取文本的范围，包括需要获取文本的起始位置和终止位置。<br>未指定范围时，默认将获取全部文本。未指定获取文本的起始位置，则默认从下标0开始；未指定获取文本的终止位置，则默认以文本末尾作为结束点。 |

**返回值：**

| 类型    | 说明               |
| ------ | ---------------- |
| string | 指定范围的文本内容。 |

## KeyboardGradientMode<sup>20+</sup>枚举说明

键盘模糊效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 值 | 说明                                       |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | 键盘无模糊效果。 |
| LINEAR_GRADIENT | 1 | 键盘设置线性渐变模糊效果。 |

## KeyboardFluidLightMode<sup>20+</sup>枚举说明

键盘流光效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 值 | 说明                                       |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | 键盘无流光效果。 |
| BACKGROUND_FLUID_LIGHT | 1 | 键盘设置流光效果。 |

## KeyboardAppearanceConfig<sup>20+</sup>

键盘外观样式属性。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 必填 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| gradientMode  | [KeyboardGradientMode](#keyboardgradientmode20枚举说明) | 否   | 键盘的模糊效果。<br/>默认值：KeyboardGradientMode.NONE |
| fluidLightMode  | [KeyboardFluidLightMode](#keyboardfluidlightmode20枚举说明) | 否   | 键盘的流光效果。<br/>默认值：KeyboardFluidLightMode.NONE |