# 窗口子系统变更说明

## cl.window.1 setWindowLayoutFullScreen、setImmersiveModeEnabledState接口在2in1设备下禁用

**访问级别**

公开接口

**变更原因**

2in1设备下禁用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口，只能调用maximize接口进入沉浸式。

**变更影响**

该变更为不兼容变更。

变更前：2in1设备下调用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口，窗口进入/退出沉浸式。

变更后：2in1设备下调用setWindowLayoutFullScreen、setImmersiveModeEnabledState接口不生效。

**起始 API Level**

14

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：setWindowLayoutFullScreen、setImmersiveModeEnabledState

**适配指导**

2in1设备下需要调用替代接口，替代接口为[maximize](../../../application-dev/reference/apis-arkui/js-apis-window.md#maximize12)，建议同时调用[setWindowLayoutFullScreen](../../../application-dev/reference/apis-arkui/js-apis-window.md#setwindowlayoutfullscreen9)/[setImmersiveModeEnabledState](../../../application-dev/reference/apis-arkui/js-apis-window.md#setimmersivemodeenabledstate12)和maximize接口。