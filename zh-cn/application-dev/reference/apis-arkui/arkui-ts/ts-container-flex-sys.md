# Flex (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

以弹性方式布局子组件的容器组件。Flex组件提供弹性布局能力，支持通过主轴（子组件排列的主要方向）和交叉轴（与主轴垂直的方向）对子组件进行排列和对齐，适用于需要动态调整布局和响应式界面设计的场景。详见[Flex组件](ts-container-flex.md)。

> **说明：**
>
> - 该组件从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[Flex](ts-container-flex.md)。

## 属性

### pointLight

pointLight(value: PointLightStyle)

设置点光源样式，用于为Flex组件添加点光源效果，影响周围标记为可被照亮组件的光照渲染。通过PointLightStyle可配置光源的位置、颜色、强度等参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式，用于设置光源的位置、颜色、强度等属性，影响组件的光照效果。仅Image、Column、Flex、Row、Stack组件支持设置点光源。 |


