# 屏幕录制支持矩形区域录制

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun-->
<!--Designer: @yxc2-->
<!--Tester: @zengxi_3007-->
<!--Adviser: @zengyawen-->

## 基础概念

从API20开始，屏幕录制支持矩形区域录制是在现有的录制区域捕获基础上开放的能力，允许开发者自主选择录屏需要捕获的区域位置，并通过调整屏幕捕获ID和指定的捕获区域area确定矩形录制区域。
在功能开发前，开发者需要掌握以下基础概念：
- 屏幕捕获ID（displayId）：需要执行矩形区域录制的屏幕ID。
- 指定的捕获区域（area）：依据需要设置区域坐标和尺寸，如创建区域的起点和录制矩形的长度和宽度。

## 适用场景

用户希望能够提供矩形区域录制功能的场景，例如：
- **在线教育场景**：教师在进行课程讲解时，会在一个较大的屏幕上展示多种内容。若能够选择性地录制某个矩形区域，则可以减少不必要的干扰，使学生更加专注于教学内容。
- **游戏直播场景**：对于玩家来说，在直播或录制游戏时，仅关注游戏界面本身，可通过区域录制让观众专注于游戏本身。

## 开发指导

**在CMake脚本中链接动态库**

```cmake
target_link_libraries(sample PUBLIC libnative_avscreen_capture.so)
```

> **说明：**
>
> 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。
>

**添加头文件**

```c++
#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <fcntl.h>
#include <string>
```

调用[OH_AVScreenCapture_SetCaptureArea()](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea)接口传入希望录制的矩形区域。

示例中的变量说明如下：

- capture：指向[OH_AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture-oh-avscreencapture.md)实例的指针。
- displayId：需要捕获区域所在的屏幕Id。
- area：需要捕获区域的坐标和宽高。类型为OH_Rect，包括成员变量x、y、width、height。
  - x、y分别为矩形区域起点的横坐标、纵坐标位置。
  - width、height分别为矩形区域的宽度和长度。
  - 多个参数之间通过";"连接，所有参数均为整数。
  - 使用前请确保传入参数有效，并尽量避免坐标和宽高为负数。

> **注意**
> 
> **录制区域限制**：
> - 安全图层不支持录制。
> - 不支持跨屏（一边在左边/一边在右边）录制。
> **录制区域更改**：支持录制过程中，更新录制区域。
> **设置失败的处理**：如果区域位置设置失败，系统将按照上一次的区域进行捕获。建议开发者在设置区域时进行错误检查和处理，以确保捕获区域的准确性。
> **参数设置非负**：该接口设置的坐标和宽高不能为负数，捕获区域不能跨屏幕，区域位置设置失败后仍按照上一次的区域进行捕获。

    ```c++
    struct OH_AVScreenCapture *capture = OH_AVScreenCapture_Create();
    // 初始化录屏，传入配置信息OH_AVScreenRecorderConfig。
    OH_AudioCaptureInfo miccapinfo = {.audioSampleRate = 16000, .audioChannels = 2, .audioSource = OH_MIC};
    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 768, .videoFrameHeight = 1280, .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA};
    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
    };
    OH_VideoInfo videoinfo = {.videoCapInfo = videocapinfo};
    OH_AVScreenCaptureConfig config = {.captureMode = OH_CAPTURE_HOME_SCREEN,
                                       .dataType = OH_ORIGINAL_STREAM,
                                       .audioInfo = audioinfo,
                                       .videoInfo = videoinfo};
    OH_AVScreenCapture_Init(capture, config);
    // 1. 可选，可以根据需要设置区域坐标和大小，设置想要捕获的区域，如下方创建了一个从（0, 0）为起点的长100，宽100的矩形区域。
    OH_Rect* region = new OH_Rect;
    region->x = 0;
    region->y = 0;
    region->width = 100;
    region->height = 100;
    // 2. 传入矩形区域所在的屏幕Id。
    uint64_t regionDisplayId = 0;
    OH_AVScreenCapture_SetCaptureArea(capture, regionDisplayId, region);

    // 开始录屏。
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```
