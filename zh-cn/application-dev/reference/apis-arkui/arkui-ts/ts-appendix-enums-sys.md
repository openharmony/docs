# 枚举说明 (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

>**说明：**
>
> - 本模块首批接口从API version 11开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## IlluminatedType

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 值   | 说明                                               |
| ------ | ---- | ------------------------------------------------------ |
| NONE | 0    | 组件不会被照亮。 |
| BORDER | 1    | 组件边缘可以被照亮。 |
| CONTENT | 2    | 组件内容可以被照亮。 |
| BORDER_CONTENT | 3    | 组件边缘和内容可以被照亮。 |
| BLOOM_BORDER | 4    | 组件边缘可以被照亮，边缘带有发光效果。 |
| BLOOM_BORDER_CONTENT | 5    | 组件边缘和内容可以被照亮，边缘带有发光效果。 |

## ColorSpace<sup>20+</sup>

定义了颜色空间的类型，用于指定颜色显示的模式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    |  值   | 说明                   |
| ------  | ---- | -------------------- |
| BT2020 | 2 | BT2020颜色空间，具有更广的色域，适用于高端显示设备。 <br/>**模型约束：** 此接口仅可在Stage模型下使用。 <br/>**系统接口：** 此接口为系统接口。 <br/>**起始版本：** 26.0.0。 |

## EdgeLightPosition枚举说明

边缘流光位置。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

| 名称           | 值  | 说明                         |
| -------------- | --- |---------------------------- |
| TOP_LEFT       | 0   | 边缘流光在左上角。            |
| TOP_RIGHT      | 1   | 边缘流光在右上角。            |
| BOTTOM_LEFT    | 2   | 边缘流光在左下角。            |
| BOTTOM_RIGHT   | 3   | 边缘流光在右下角。            |
| TOP            | 4   | 边缘流光在顶部。              |
| BOTTOM         | 5   | 边缘流光在底部。              |
| LEFT           | 6   | 边缘流光在左边。              |
| RIGHT          | 7   | 边缘流光在右边。              |

## DistortionMode

非线性动效模式枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值 | 说明              |
| ------ | --- | --------------- |
| DISTORTION_AUTO | 0 | 当设置[IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial)类型的材质，依据设备算力档位和系统设置中的沉浸光感配置自动生效非线性效果。高算力设备在沉浸光感配置为强或均衡时生效，为弱时不生效；中算力和低算力设备均不生效。 |
| DISTORTION_ENABLED | 1 | 沉浸式材质下非线性动效生效。|
| DISTORTION_DISABLED | 2 | 沉浸式材质下非线性动效不生效。 |


## EdgeLightMode

流光动效模式枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值 | 说明              |
| ------ | --- | --------------- |
| EDGELIGHT_AUTO | 0 | 当设置[IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial)类型的材质，组件类型不同，流光效果的自动生效规则不同。对于在组件接口处未做特殊说明的组件，依据设备算力档位和系统设置中的沉浸光感配置自动生效流光效果：高算力设备在沉浸光感配置为强或均衡时生效流光动画，为弱时不生效；中算力设备在沉浸光感配置为强时生效流光动画，为均衡或弱时不生效；低算力设备不生效。 |
| EDGELIGHT_ENABLED | 1 | 沉浸式材质下流光动效生效。|
| EDGELIGHT_DISABLED | 2 | 沉浸式材质下流光动效不生效。 |
