# 菜单控制（系统接口）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

为组件绑定弹出式菜单，支持长按、点击或鼠标右键来触发菜单的弹出，菜单项以垂直列表形式显示。

> **说明：**
>
> - 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本文仅介绍当前模块的系统接口，其他公开接口参见[菜单控制](./ts-universal-attributes-menu.md)。

## ContextMenuOptions<sup>10+</sup>

配置系统菜单的视觉表现选项，支持设置新材质下菜单的非线性动画模式（扭曲效果）及流光动画模式，提升菜单展示的交互体验与视觉质感。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

<!--Table: 20%; 20%; 10%; 10%; 40%-->
| 名称                  | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | 否 | 是 | 设置系统材质下菜单的非线性动画模式。<br />**默认值：** DistortionMode.DISTORTION_AUTO <br/>**起始版本：** 26.0.0 <br />**系统接口：** 此接口为系统接口。|
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode)| 否 | 是 | 设置系统材质下菜单的流光动画模式。<br />**默认值：** EdgeLightMode.EDGELIGHT_DISABLED <br/>**起始版本：** 26.0.0 <br />**系统接口：** 此接口为系统接口。|
