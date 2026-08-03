# OH_MultiDisplayCapability
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_MultiDisplayCapability {...} OH_MultiDisplayCapability
```

## 概述

多屏幕录制能力信息。多屏场景下，用户选择的多屏幕是否支持联合录制，以及联合录制的屏幕宽度和高度。联合录制指将多个屏幕的内容同时录制到一个视频文件中。该结构体支持查询多屏设备的联合录制能力，帮助开发者判断当前设备是否支持同时对多个屏幕进行录制，适用于会议演示、游戏录制、教学场景等需要跨屏录制的应用场景。通过联合录制能力，用户可以一次性捕获多个屏幕的内容，提升录制效率和内容完整性。

**起始版本：** 24

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| bool isMultiDisplaySupport | 是否支持多屏幕联合录制，true表示支持多屏幕联合录制，此时width和height为联合录制区域尺寸；false表示不支持多屏幕联合录制，此时width和height无效。 |
| uint32_t width | 多屏幕联合录制的屏幕区域宽度（单位：像素）。当isMultiDisplaySupport为true时，该值为所有选中屏幕联合录制区域的宽度；当isMultiDisplaySupport为false时，该值无效。 |
| uint32_t height | 多屏幕联合录制的屏幕区域高度（单位：像素）。当isMultiDisplaySupport为true时，该值为所有选中屏幕联合录制区域的高度；当isMultiDisplaySupport为false时，该值无效。 |