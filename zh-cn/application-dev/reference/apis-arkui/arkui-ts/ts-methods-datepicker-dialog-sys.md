# 日期滑动选择器弹窗 (DatePickerDialog) (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->

DatePickerDialog提供了系统级的日期滑动选择器弹窗，支持设置非线性动画模式和流光动画效果，适用于需要在应用中集成系统材质风格日期选择器的场景，能够提供统一的视觉体验和流畅的交互动画，提升用户体验的一致性。

> **说明：**
>
> - 该组件从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块功能依赖UI的执行上下文，不可在[UI上下文不明确](../../../ui/arkts-global-interface.md#ui上下文不明确)的地方使用，参见[UIContext](../arkts-apis-uicontext-uicontext.md)说明。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[日期滑动选择器弹窗 (DatePickerDialog)](ts-methods-datepicker-dialog.md)。

## DatePickerDialogOptions

日期滑动选择器弹窗选项。DatePickerDialog通过弹窗方式展示日期滑动选择器，提供系统材质动画效果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | 否 | 是 | 设置系统材质下弹窗的非线性动画模式。当需要自定义弹窗的非线性动画效果时传入此参数。<br>**默认值：** DistortionMode.DISTORTION_AUTO <br>**起始版本：** 26.0.0<br>**系统接口：** 此接口为系统接口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**说明：** 当取值为 DISTORTION_AUTO 时，需设置 [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) 类型材质方可生效，并依据设备算力档位自动生效非线性效果（高中档算力设备生效，低档算力设备不生效）。非线性动画会增加渲染开销，建议在低端设备上谨慎使用。各枚举取值含义请参见 [DistortionMode](./ts-appendix-enums-sys.md#distortionmode)。|
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | 否 | 是 | 设置系统材质下弹窗的流光动画模式。当需要自定义弹窗的流光动画效果时传入此参数。<br>**默认值：** EdgeLightMode.EDGELIGHT_AUTO <br>**起始版本：** 26.0.0<br>**系统接口：** 此接口为系统接口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**说明：** 当取值为 EDGELIGHT_AUTO 时，需设置 [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) 类型材质方可生效，并依据设备算力档位自动生效流光效果（高档算力设备生效，中低档算力设备不生效）。流光动画会增加渲染开销，建议在低端设备上谨慎使用。各枚举取值含义请参见 [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode)。 |
