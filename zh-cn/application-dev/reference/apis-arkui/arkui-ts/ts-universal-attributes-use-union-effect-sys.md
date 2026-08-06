# 融合效果 (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

本模块介绍如何设置使用融合效果。融合效果是指多个子组件在UnionEffectContainer容器中进行形状融合，形成统一的视觉融合形态。

> **说明：**
>
> - 从API version 23开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 本模块为系统接口。

## useUnionEffect

useUnionEffect(value: boolean \| undefined): T;

表示是否使用祖先组件[UnionEffectContainer](ts-container-unioneffectcomponent-sys.md)的融合效果，即是否作为UnionEffectContainer做形状融合的一部分，参与融合形态计算。

未设置时，默认不使用祖先组件UnionEffectContainer的融合效果。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | boolean \| undefined | 是 | 表示是否使用祖先组件UnionEffectContainer的融合效果。<br>取值为true时，当前组件使用祖先组件UnionEffectContainer的融合效果，在祖先组件UnionEffectContainer计算形状时会作为UnionEffectContainer的一部分；若当前组件不存在祖先UnionEffectContainer，则设置useUnionEffect为true不产生融合效果。<br>取值为false时，当前组件不使用祖先组件UnionEffectContainer的融合效果。<br>设置为undefined时恢复为不使用祖先组件UnionEffectContainer的融合效果。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## useUnionEffect

useUnionEffect(value: boolean \| undefined, options?: GravityCenterOptions): T

表示是否使用祖先组件[UnionEffectContainer](ts-container-unioneffectcomponent-sys.md)的融合效果，是否作为UnionEffectContainer做形状融合的一部分，参与融合形态计算。当不存在祖先组件UnionEffectContainer时，设置该属性不产生效果。

未设置时，默认不使用祖先组件UnionEffectContainer的融合效果。

> **说明：**
>
> 多次调用该接口传入[GravityCenterOptions](#gravitycenteroptions)参数时，仅最后一次设置的引力中心参数生效。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | boolean \| undefined | 是 | 是否使用祖先组件UnionEffectContainer的融合效果。<br>取值为true时，当前组件使用祖先组件UnionEffectContainer的融合效果，在祖先组件UnionEffectContainer计算形状时会作为UnionEffectContainer的一部分；若当前组件不存在祖先UnionEffectContainer，则取值为true不产生融合效果。<br>取值为false时，当前组件不使用祖先组件UnionEffectContainer的融合效果。<br>设置为undefined时，恢复为不使用祖先组件UnionEffectContainer的融合效果。|
| options | [GravityCenterOptions](#gravitycenteroptions) | 否 | 引力中心参数。<br>未设置时，不启用引力中心功能。<br>**说明：**<br>此参数必须与[unionMode](./ts-container-unioneffectcomponent-sys.md#unionmode)一起使用，且unionMode须为UnionMode.GRAVITY_UNION，同时value须为true时才生效，单独设置或不满足前提条件时不生效。      |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## GravityCenterOptions

定义引力中心参数。

> **说明：**
>
> 此参数必须与[unionMode](./ts-container-unioneffectcomponent-sys.md#unionmode)一起使用，且unionMode须为UnionMode.GRAVITY_UNION，同时useUnionEffect的value须为true时才生效，单独设置不生效。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

| 名称               | 类型                              | 只读 | 可选 | 说明                                                    |
| ------------------ | -------------------------------- | ---- | ---- |------------------------------------------------------- |
| gravityCenter      | boolean                          | 否   | 是   | 指定当前组件是否为引力中心。<br>设置为true表示当前组件是引力中心；设置为false表示当前组件不是引力中心。<br>默认值：false                                           |
| gravityIntensity   | number                           | 否   | 是   | 定义引力中心处吸引力或排斥力的强度。<br>仅在gravityCenter为true时生效。<br>默认值：0<br>负数表示排斥力，正数表示吸引力。 |

**示例：**

示例请参考[UnionEffectContainer示例](ts-container-unioneffectcomponent-sys.md#示例)。
