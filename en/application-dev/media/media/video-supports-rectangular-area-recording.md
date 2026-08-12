# Capturing the Specified Area on a Screen

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @zengxi_3007-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=2c4efd24da9b5c0e73791677e0324b0efa690b44 translatedAt=2026-08-11T01:56:13.659Z pushedAt=2026-08-12T03:31:42.069Z -->

## Basic Concepts

Starting from API version 20, you can capture a specified rectangular area of the screen during recording. This feature enhances the existing screen capture capability by allowing you to select a specific area to record. You can define this area by providing a screen capture ID (**displayId**) and the target capture area (**area**).

Before implementing this feature, familiarize yourself with the following concepts:

- Screen capture ID (**displayId**): ID of the screen where rectangular area capture will be performed.

- Target capture area (**area**): coordinates and dimensions of the region to be captured, including the starting point (x, y) and the width and height of the rectangular area.

## When to Use

This feature is particularly useful in scenarios such as:

- **Online education**: When teachers present various materials on a large screen, selectively capturing a specific rectangular area helps minimize distractions, allowing students to focus better on the core content.

- **Game streaming**: Players can capture only the game window during live streams or recordings, keeping the audience focused purely on the gameplay.

## How to Develop

**Linking Dynamic Libraries in the CMake Script**

```CMake
target_link_libraries(sample PUBLIC libnative_avscreen_capture.so libnative_display_manager.so libability_runtime.so)
```

> **NOTE**
>
> Replace **'sample'** with your actual project name.
>

**Adding Header Files**

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

Call [OH_AVScreenCapture_SetCaptureArea()](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea) to specify the rectangular area you want to capture.

In the code snippet below, the following variables are used:

- **g_avCapture**: pointer to an [OH_AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture-oh-avscreencapture.md) instance.

- **regionDisplayId**: ID of the screen where the capture area is located.

- **region**: coordinates and width and height of the capture area. The type is OH_Rect, including member variables x, y, width, and height.

  - **x** and **y** indicate the horizontal and vertical coordinates of the start point of the rectangular area, respectively.

  - **width** and **height** indicate the width and height of the rectangular area, respectively.

  - Multiple parameters are separated by semicolons (;). All parameters are non-negative integers.

  - Before using, ensure that the input parameters are valid and avoid negative coordinates, width, and height.

> **NOTE**
> 
> **Recording area restrictions**:
> - Security layers cannot be captured.
> - Capturing across multiple screens is not supported.
> **Changing the recording area**: The recording area can be updated during recording.
> **Handling of setting failures**: If the area position setting fails, the system captures based on the previous area. You are advised to perform error checking and handling when setting the area to ensure the accuracy of the recording area.
> **Non-negative parameter settings**: The coordinates, width, and height set by this API must not be negative.

<!-- @[screenCapture_startScreenCapture_rectangular](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) --> 

``` C++
g_avCapture = OH_AVScreenCapture_Create();
if (g_avCapture == nullptr) {
    OH_LOG_ERROR(LOG_APP, "create screen capture failed");
}
OpenFile("Demo");
SetCallback(g_avCapture);
// Initialize the screen capture parameters and pass in an OH_AVScreenRecorderConfig struct.
OH_AVScreenCaptureConfig config;
SetConfig05(config);
OH_AVSCREEN_CAPTURE_ErrCode result = OH_AVScreenCapture_Init(g_avCapture, config);
if (result != AV_SCREEN_CAPTURE_ERR_OK) {
    OH_LOG_ERROR(LOG_APP,
        "==ScreenCaptureSample== ScreenCapture OH_AVScreenCapture_Init failed %{public}d", result);
}
// 1. (Optional) Set the coordinates and dimensions of the capture area. For example, the following creates a 100*100 rectangular area starting at (0, 0).
OH_Rect* region = new OH_Rect;
region->x = 0;
region->y = 0;
region->width = CAPTURE_REGION_SIZE;
region->height = CAPTURE_REGION_SIZE;
// 2. Pass in the screen ID where the rectangular area is located.
uint64_t regionDisplayId = 0;
OH_AVScreenCapture_SetCaptureArea(g_avCapture, regionDisplayId, region);
// Start screen capture.
result = OH_AVScreenCapture_StartScreenCapture(g_avCapture);
delete region;
region = nullptr;
```