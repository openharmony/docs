# Column (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

沿垂直方向布局的容器。Column组件用于将子组件沿垂直方向依次排列，支持设置对齐方式、间距等属性，简化垂直布局的实现过程，适用于表单、列表项、垂直导航等多种场景。

> **说明：**
>
> - 该组件从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[Column](ts-container-column.md)。

## 属性

### pointLight<sup>11+</sup>

pointLight(value: PointLightStyle)

为Column组件添加点光源效果，影响周围标记为可被照亮组件的光照渲染。点光源是从特定位置向四周发射光线的光源类型，可用于增强UI界面的立体感和视觉层次。通过PointLightStyle可配置光源的位置、颜色、强度等参数。详细信息请参见[PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle)对象说明。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式，用于设置点光源照亮周围组件的UI效果。仅Image、Column、Flex、Row、Stack组件支持设置点光源。 |

