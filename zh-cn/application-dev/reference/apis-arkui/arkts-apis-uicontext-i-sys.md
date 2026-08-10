# Interfaces (其他)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 以下API需先调用ohos.window中的[getUIContext()](arkts-apis-window-Window.md#getuicontext10)方法或自定义组件内置方法[getUIContext()](arkui-ts/ts-custom-component-api.md#getuicontext)获取UIContext实例，再通过此实例调用对应方法。本文中UIContext对象以uiContext表示。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[Interfaces (其他)](arkts-apis-uicontext-i.md)。

## BackgroundLuminanceSamplingConfigs<sup>23+</sup>

背景亮度采样参数配置。背景亮度采样用于定期从组件背景区域取色，根据亮度阈值判定背景的明暗程度，以支持组件自适应明暗风格等场景。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型 | 只读  | 可选 | 说明                    |
| --------- | ---- | ----- | ---- | -----------------------|
| samplingInterval  | number | 否 | 是 | 取色间隔，单位为毫秒，取值范围：≥180ms。传入小于180ms的值时，自动修正为180ms。当需要更频繁的背景取色响应时可设置较小值（如180-300ms），当需要节省系统资源时可设置较大值（如500-1000ms）。<br> 默认值：500ms |
| brightThreshold   | number | 否 | 是 | 浅色亮度阈值：[0, 255]内的整数，设置的浅色亮度阈值应大于深色亮度阈值，若浅色亮度阈值不大于深色亮度阈值，将抛出异常。当需要调整浅色判定灵敏度时可自定义此值，低于默认值220的设置使浅色判定更宽松，高于默认值的设置使浅色判定更严格。<br> 默认值：220 |
| darkThreshold     | number | 否 | 是 | 深色亮度阈值：[0, 255]内的整数，设置的深色亮度阈值应小于浅色亮度阈值。当需要调整深色判定灵敏度时可自定义此值，高于默认值150的设置使深色判定更宽松，低于默认值的设置使深色判定更严格。<br> 默认值：150 |
| region     | [Edges](js-apis-arkui-graphics.md#edgest12)\<[LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12)\> | 否 | 是 | 相对组件的采样区域偏移，以组件自身的左上点为基准进行偏移计算。取色区域建议设置在可见范围内，避免偏移超出组件可见区域导致采样结果不准确。<br> 默认取色区域与所配置组件区域一致（即不设置偏移时，取色区域等于组件自身区域）。 |
