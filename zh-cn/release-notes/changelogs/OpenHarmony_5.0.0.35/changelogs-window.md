# 窗口子系统变更说明

## cl.window.1 recover接口增加校验条件，调用行为变更

**访问级别**

公开接口

**变更原因**

设计方案缺陷，原始需求交付的时候没有考虑支持的窗口模式。

**变更影响**

该变更为不兼容变更。

变更前：不支持自由悬浮窗口模式的窗口调用recover接口，可以恢复成自由窗口。

变更后：recover接口调用时，会对窗口是否支持自由悬浮模式进行校验，不支持自由悬浮模式的窗口调用此接口时，不会恢复成自由窗口。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.35开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：recover

**适配指导**

不推荐不支持自由悬浮模式的窗口调用此接口，若调用则产生1300002错误。

recover接口仅支持声明支持自由悬浮模式的窗口调用，即[module.json5配置文件中abilities标签下的supportWindowMode属性](../../../application-dev/quick-start/module-configuration-file.md#abilities标签)默认不配置或配置范围包含"floating"，或者配置[WindowMode](../../../application-dev/reference/apis-arkui/js-apis-window-sys.md#windowmode7)为window.WindowMode.FLOATING。