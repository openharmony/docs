# OH_RecorderInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_RecorderInfo {...} OH_RecorderInfo
```

## 概述

录制文件信息。

OH_RecorderInfo用于存储屏幕录制文件的输出信息，包括录制文件的URL地址、URL长度及文件格式，适用于需要配置屏幕录制输出目标及格式的场景，帮助开发者灵活指定录制文件的存储路径和封装格式。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* url | 录制文件的URL，用于指定录屏文件的输出位置。仅支持本地文件路径URL格式。需与urlLen配合使用。 |
| uint32_t urlLen | 录制文件的URL的长度值，表示url参数所指字符串的字节长度（不包括终止空字符）。需与url参数配合使用，不匹配时可能导致录制异常。 |
| [OH_ContainerFormatType](capi-native-avscreen-capture-base-h.md#oh_containerformattype) fileFormat | 录制文件的容器封装格式类型，用于指定录屏输出的文件封装格式。可选值：CFT_MPEG_4A（M4A格式，适用于仅需要录制音频的场景）、CFT_MPEG_4（MP4格式，适用于需要同时录制音视频的场景）。可选值为[OH_ContainerFormatType](capi-native-avscreen-capture-base-h.md#oh_containerformattype)中定义的格式类型。 |


