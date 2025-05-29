# 窗口子系统Changelog

## cl.window.1 2in1设备上，悬浮窗层级由低于dock栏调整为高于dock栏

**访问级别**

公开接口

**变更原因**

应用创建的TYPE_FLOAT类型的悬浮窗，因为层级低于Dock，会被Dock栏遮挡，在视频会议等场景，体验不符合应用预期。

**变更影响**

此变更不涉及应用适配。

- 变更前：在2in1设备上，TYPE_FLOAT类型的悬浮窗层级在dock栏之下。
  
- 变更后：在2in1设备上，TYPE_FLOAT类型的悬浮窗层级在dock栏之上。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.1.52开始。

**变更的接口/组件**

@ohos.window.d.ts

接口：TYPE_FLOAT

**适配指导**

默认行为变更，无需适配。 