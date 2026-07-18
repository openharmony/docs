# OH_PrivacyProtectInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct {...} OH_PrivacyProtectInfo;
```

## 概述

隐私保护信息结构体。

用于在屏幕录制场景中对系统窗口和敏感应用进行隐私保护。通过设置该结构体的成员变量，可以控制是否开启系统窗口隐私保护和敏感应用隐私保护，避免在屏幕录制过程中泄露隐私信息。systemWindowProtection控制系统窗口级别的隐私保护，sensitiveAppProtection控制敏感应用级别的隐私保护，适用于需要在屏幕录制时保护用户隐私数据的场景。如屏幕录制或截图时，需要保护敏感窗口（如银行应用、聊天窗口）不被捕获；金融类应用需要保护用户输入的敏感信息；视频会议应用需要保护共享屏幕中的隐私内容的场景。

**起始版本：** 24

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| bool systemWindowProtection | 是否开启系统窗口隐私保护。true表示开启隐私保护，false表示关闭隐私保护，默认值为true。系统窗口是指系统级应用（如设置、通知等）的窗口；需在屏幕录制启动前配置该参数，开启后录屏时该类窗口内容将被保护处理。典型场景：在屏幕录制或共享时，开启此项可保护通知栏、弹窗等系统窗口中的隐私信息不被录制或共享出去。<br>**起始版本：** 24 |
| bool sensitiveAppProtection | 是否开启敏感应用的隐私保护。true表示开启隐私保护，false表示关闭隐私保护，默认值为true。敏感应用是指包含用户隐私数据的应用；需在屏幕录制启动前配置该参数，开启后录屏时该类应用窗口内容将被保护处理。典型场景：在屏幕录制或共享时，开启此项可保护银行、社交等敏感应用的内容不被录制或共享出去。<br>**起始版本：** 24 |
