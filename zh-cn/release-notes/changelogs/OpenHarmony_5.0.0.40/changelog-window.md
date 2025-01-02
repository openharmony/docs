# 窗口子系统变更说明

## cl.window.1 maximize接口增加校验条件，调用行为变更

**访问级别**

公开接口

**变更原因**

接口实现与设计不一致，接口仅在2in1设备上生效。

**变更影响**

该变更为不兼容变更。

变更前：非2in1设备的窗口也可以正常调用。

变更后：窗口调用maximize接口时，会校验是否是2in1设备，非2in1设备的窗口调用此接口时，不会最大化窗口。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.40开始。

**变更的接口/组件**

@ohos.window.d.ts

系统能力：SystemCapability.Window.SessionManager

接口：maximize

**适配指导**

不推荐非2in1设备调用此接口，若调用不会报错但无响应。