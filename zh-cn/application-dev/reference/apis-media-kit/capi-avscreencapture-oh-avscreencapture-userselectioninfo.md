# OH_AVScreenCapture_UserSelectionInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVScreenCapture_UserSelectionInfo OH_AVScreenCapture_UserSelectionInfo
```

## 概述

开发者可通过OH_AVScreenCapture_UserSelectionInfo获取用户在授权界面（选择界面）选择的参数（如捕获类型，捕获窗口等）。例如，在屏幕录制应用中，用户可以选择录制区域、录制音频源等参数后，使用该结构体获取用户的选择结果。

该结构体用于在屏幕录制授权流程中承载用户的选择结果，开发者可在授权完成后通过此结构体读取用户的授权选择信息。适用于应用需要根据用户授权选择来配置录屏行为的场景，帮助开发者灵活适配用户的录屏偏好。

**起始版本：** 20

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

