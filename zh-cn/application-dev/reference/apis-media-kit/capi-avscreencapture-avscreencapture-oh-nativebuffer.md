# OH_NativeBuffer
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_NativeBuffer OH_NativeBuffer
```

## 概述

提供录屏的视频原始数据缓冲区结构体。OH_NativeBuffer提供录屏的视频原始数据处理能力，支持对录屏过程中产生的视频原始数据进行封装、传输和管理。

用于在AVScreenCapture录屏场景中承载获取的视频帧原始数据。可用于录屏数据的二次处理场景，如视频编辑应用中对录屏帧数据进行像素级操作、直播推流场景中对原始码流进行编码推送等。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

