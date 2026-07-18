# OH_Rect
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_Rect {...} OH_Rect
```

## 概述

定义录屏界面的宽高以及画面信息。包含位置坐标和尺寸信息。可用于精确控制录屏范围，支持自定义区域录制、局部录制等场景。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t x | 录屏界面的X坐标，取值需大于等于0，单位：px。 |
| int32_t y | 录屏界面的Y坐标，取值需大于等于0，单位：px。 |
| int32_t width | 录屏区域的宽度，取值需大于0，单位：px。传入0或负数时录屏不生效。 |
| int32_t height | 录屏区域的高度，取值需大于0，单位：px。传入0或负数时录屏不生效。 |


