# 窗口子系统变更说明

## cl.window.1 getTitleButtonRect接口返回错误码变更

**访问级别**

公开接口

**变更原因**

接口实现与设计不一致，接口仅在2in1设备上生效。

**变更影响**

该变更为不兼容变更。

变更前：非2in1设备调用getTitleButtonRect接口返回1300002错误码。

变更后：非2in1设备调用getTitleButtonRect接口返回801错误码。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.30开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：getTitleButtonRect

**适配指导**

不推荐非2in1设备调用此接口，若调用则产生801错误。