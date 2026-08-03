# 屏幕录制支持矩形区域录制

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @zengxi_3007-->
<!--Adviser: @w_Machine_cc-->

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

```CMake
target_link_libraries(sample PUBLIC libnative_avscreen_capture.so libnative_display_manager.so libability_runtime.so)
```

> **说明：**
>
> 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。
>

**添加头文件**

<!-- @[screenCapture_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/main.h) --> 

``` C
#include "hilog/log.h"
#include "napi/native_api.h"
#include <window_manager/oh_display_info.h>
#include <window_manager/oh_display_manager.h>
#include <AbilityKit/ability_runtime/application_context.h>
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
```

调用[OH_AVScreenCapture_SetCaptureArea()](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea)接口传入希望录制的矩形区域。

示例中的变量说明如下：

- g_avCapture：指向[OH_AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture-oh-avscreencapture.md)实例的指针。
- regionDisplayId：需要捕获区域所在的屏幕ID。
- region：需要捕获区域的坐标和宽高。类型为OH_Rect，包括成员变量x、y、width、height。
  - x、y分别为矩形区域起点的横坐标、纵坐标位置。
  - width、height分别为矩形区域的宽度和高度。
  - 多个参数之间通过";"连接，所有参数均为非负整数。
  - 使用前请确保传入参数有效，避免坐标和宽高为负数。

> **注意**
> 
> **录制区域限制**：
> - 安全图层不支持录制。
> - 不支持跨屏（一边在左边/一边在右边）录制。
> **录制区域更改**：支持录制过程中，更新录制区域。
> **设置失败的处理**：如果区域位置设置失败，系统将按照上一次的区域进行捕获。建议开发者在设置区域时进行错误检查和处理，以确保捕获区域的准确性。
> **参数设置非负**：该接口设置的坐标和宽高不能为负数。

<!-- @[screenCapture_startScreenCapture_rectangular](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
g_avCapture = OH_AVScreenCapture_Create();
if (g_avCapture == nullptr) {
    OH_LOG_ERROR(LOG_APP, "create screen capture failed");
}
OpenFile("Demo");
SetCallback(g_avCapture);
// 初始化录屏，传入配置信息OH_AVScreenRecorderConfig。
OH_AVScreenCaptureConfig config;
SetConfig05(config);
OH_AVSCREEN_CAPTURE_ErrCode result = OH_AVScreenCapture_Init(g_avCapture, config);
if (result != AV_SCREEN_CAPTURE_ERR_OK) {
    OH_LOG_ERROR(LOG_APP,
        "==ScreenCaptureSample== ScreenCapture OH_AVScreenCapture_Init failed %{public}d", result);
}
// 1. 可选，可以根据需要设置区域坐标和大小，设置想要捕获的区域，如下方创建了一个从（0, 0）为起点的长100，宽100的矩形区域。
OH_Rect* region = new OH_Rect;
region->x = 0;
region->y = 0;
region->width = CAPTURE_REGION_SIZE;
region->height = CAPTURE_REGION_SIZE;
// 2.传入矩形区域所在的屏幕ID。
uint64_t regionDisplayId = 0;
OH_AVScreenCapture_SetCaptureArea(g_avCapture, regionDisplayId, region);
// 开始录屏。
result = OH_AVScreenCapture_StartScreenCapture(g_avCapture);
delete region;
region = nullptr;
```
