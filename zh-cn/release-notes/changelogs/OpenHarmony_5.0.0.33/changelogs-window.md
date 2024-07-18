# 窗口子系统变更说明

## cl.window.1 SetWindowSystemBarEnable、SetSystemBarEnable 不在2in1设备生效行为变更

**访问级别**

公开接口

**变更原因**

应用在2in设备上不规范使用该接口会导致应用进入状态栏隐藏、显示后遮挡窗口等问题。为了杜绝此类问题，在全屏的时候由系统规范约束布局，SystemBar中状态栏的显示和隐藏由系统控制规范窗口在全屏时候的布局，不再由应用控制。

**变更影响**

该变更为不兼容变更。
此变更从OpenHarmony SDK 5.0.0.33，API 12及以后开始生效，API 11及之前保持原状。
变更前2in1设备上全屏调用此接口可以显示和隐藏状态栏。
变更后窗口布局会自动适配避让逻辑，应用无需再次调用接口控制。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

SetWindowSystemBarEnable
SetSystemBarEnable

**适配指导**

调用行为的变更：
不推荐在2in1设备上调用接口