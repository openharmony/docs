# Row (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

沿水平方向布局的容器，适用于工具栏、导航栏等水平排列场景，可灵活控制子组件的对齐方式、间距和排列顺序。

> **说明：**
>
> - 该组件从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[Row](ts-container-row.md)。

## 属性

### pointLight

pointLight(value: PointLightStyle)

设置点光源样式，用于为Row组件添加点光源效果，影响周围标记为可被照亮组件的光照渲染。点光源是从特定位置向四周发射光线的光源类型，可用于增强UI界面的立体感和视觉层次。通过PointLightStyle可配置光源的位置、颜色、强度等参数。详细信息请参见[PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle)对象说明。

**系统接口：** 此接口为系统接口。
**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式，用于设置点光源照亮周围组件的UI效果。PointLightStyle对象包含光源位置、颜色、强度等参数，具体配置方式详见链接说明。仅Image、Column、Flex、Row、Stack组件支持设置点光源。 |

