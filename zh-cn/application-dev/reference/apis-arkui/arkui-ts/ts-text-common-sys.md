# 文本组件公共接口 (系统接口)

文本类组件公共接口。

>  **说明：**
>
>  本模块首批接口从API version 20开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  当前页面仅包含本模块的系统接口，其他公开接口参见[文本组件公共接口](ts-text-common.md)。

## KeyboardGradientMode枚举说明

键盘模糊效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 值 | 说明                                       |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | 键盘无模糊效果。 |
| LINEAR_GRADIENT | 1 | 键盘设置线性渐变模糊效果。 |

## KeyboardFluidLightMode枚举说明

键盘流光效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 值 | 说明                                       |
| ---------------------------------- | --- | ---------------------------------------- |
| NONE | 0 | 键盘无流光效果。 |
| BACKGROUND_FLUID_LIGHT | 1 | 键盘设置流光效果。 |

## KeyboardAppearanceConfig

键盘外观样式属性。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 必填 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| gradientMode  | [KeyboardGradientMode](#keyboardgradientmode枚举说明) | 否   | 键盘的模糊效果。<br/>默认值：KeyboardGradientMode.NONE |
| fluidLightMode  | [KeyboardFluidLightMode](#keyboardfluidlightmode枚举说明) | 否   | 键盘的流光效果。<br/>默认值：KeyboardFluidLightMode.NONE |
