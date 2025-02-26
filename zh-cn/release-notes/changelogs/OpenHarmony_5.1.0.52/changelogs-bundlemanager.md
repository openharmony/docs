# 包管理子系统Changelog

## cl.bundlemanager.1 supportWindowModes选项配置fullscreen和split时，窗口由自由窗口状态启动变更为全屏启动

**访问级别**

公开接口

**变更原因**

2in1设备上 通过 [supportWindowModes](../../../application-dev/quick-start/module-configuration-file.md#abilities标签)配置fullscreen和split时，2in1设备的窗口将以自由窗口状态启动，与预期效果不符。

**变更影响**

此变更涉及应用适配。

变更前：supportWindowModes配置fullscreen和split时，2in1设备上以自由窗口启动。

变更后：supportWindowModes配置fullscreen和split时，2in1设备上窗口全屏启动。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.52 版本开始。

**变更的接口/组件**

module.json5中supportWindowModes标签

**适配指导**

API version 15及之后的版本, 开发者需要关注supportWindowModes配置fullscreen和split时，2in1设备上窗口全屏启动。
若预期是以自由窗口启动，则需要在supportWindowModes原来的配置项中增加floating配置项。