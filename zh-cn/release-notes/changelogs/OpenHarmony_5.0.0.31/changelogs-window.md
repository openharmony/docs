# 窗口子系统变更说明

## cl.window.1 setWindowSystemBarEnable、setSystemBarEnable 不在2in1设备生效

**访问级别**

公开接口

**变更原因**

在2in1设备下，全屏状态下的状态栏显示控制由系统布局约束，无需再调用接口去控制状态栏的显示和隐藏。即设置的setWindowSystemBarEnable、setSystemBarEnable在2in1设备上不生效。
![Alt text](figures/window_layout.png)

**变更影响**

该变更为不兼容变更。
此变更从API 12起生效，使用API 11及之前版本SDK进行编译的应用不受影响。<br/>
变更前2in1设备上全屏调用此接口可以显示和隐藏状态栏。<br/>
变更后2in1设备上窗口布局会自动适配避让逻辑，无需调用接口控制。<br/>

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**变更的接口/组件**

@ohos.window.d.ts

setWindowSystemBarEnable

setSystemBarEnable
