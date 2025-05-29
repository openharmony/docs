# 使用AVScreenCapture录屏写文件(C/C++)

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（[AVScreenCapture](media-kit-intro.md#avscreencapture)）模块的C API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。可以调用录屏模块获取音视频文件，然后通过文件的形式流转到其他模块进行播放或处理，达成文件形式分享屏幕内容的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始屏幕录制时正在通话中或者屏幕录制过程中来电，录屏将自动停止。因通话中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL状态。

屏幕录制过程中发生系统用户切换事件时，录屏将自动停止。因系统用户切换中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../../reference/apis-media-kit/capi-avscreencapture.md)。

如果配置了采集麦克风音频数据，需对应配置麦克风权限ohos.permission.MICROPHONE和申请长时任务，配置方式请参见[向用户申请权限](../../security/AccessToken/request-user-authorization.md)、[申请长时任务](../../task-management/continuous-task.md)。

## 开发步骤及注意事项

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。
在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

**在 CMake 脚本中链接动态库**

```c++
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so)
```

1. 添加头文件。

    ```c++
    #include "napi/native_api.h"
    #include <multimedia/player_framework/native_avscreen_capture.h>
    #include <multimedia/player_framework/native_avscreen_capture_base.h>
    #include <multimedia/player_framework/native_avscreen_capture_errors.h>
    #include <fcntl.h>
    #include "string"
    #include "unistd.h"
    ```

2. 创建AVScreenCapture实例capture。

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

3. 配置屏幕录制参数。

    创建AVScreenCapture实例capture后，可以设置屏幕录制所需要的参数。

    其中，录屏存文件时默认录制内录，麦克风可以动态开关，可以同时内外录制。

    同时，录屏存文件需要设置状态回调，感知录制状态。

    ```c++
    //录屏时获取麦克风或者内录，内录参数必填，如果都设置了，内录和麦克风的参数设置需要一致。
    OH_AudioCaptureInfo micCapInfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_MIC
    };

    OH_AudioCaptureInfo innerCapInfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_ALL_PLAYBACK
    };

    OH_AudioEncInfo audioEncInfo = {
        .audioBitrate = 48000,
        .audioCodecformat = OH_AAC_LC
    };

    OH_VideoCaptureInfo videoCapInfo = {
        .videoFrameWidth = 768,
        .videoFrameHeight = 1280,
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_VideoEncInfo videoEncInfo = {
        .videoCodec = OH_H264,
        .videoBitrate = 2000000,
        .videoFrameRate = 30
    };

    OH_AudioInfo audioInfo = {
        .innerCapInfo = innerCapInfo,
        .audioEncInfo = audioEncInfo
    };

    OH_VideoInfo videoInfo = {
        .videoCapInfo = videoCapInfo,
        .videoEncInfo = videoEncInfo
    };

    config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_CAPTURE_FILE,
        .audioInfo = audioInfo,
        .videoInfo = videoInfo,
    };

    OH_AVScreenCapture_Init(capture, config);
    ```

4. 调用StartScreenRecording()方法开始进行屏幕录制。

    ```c++
    OH_AVScreenCapture_StartScreenRecording(capture);
    ```

5. 调用StopScreenRecording()方法停止录制。

    ```c++
    OH_AVScreenCapture_StopScreenRecording(capture);
    ```

6. 调用Release()方法销毁实例，释放资源。

    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

## 完整示例

下面展示了使用AVScreenCapture屏幕录制存文件的完整示例代码。

```c++
#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <fcntl.h>
#include "string"
#include "unistd.h"

void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
    (void)capture;
    
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
        // 处理状态变更。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL ||
        stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
        // 录屏中断状态处理。
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // 处理状态变更。
    }
    (void)userData;
}

// 获取录屏屏幕id的回调函数OnDisplaySelected()。
void OnDisplaySelected(struct OH_AVScreenCapture *capture, uint64_t displayId, void *userData) {
    (void)capture;
    (void)displayId;
    (void)userData;
}

// 录屏内容变更回调函数OnCaptureContentChanged()。
void OnCaptureContentChanged(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect *area, void *userData) {
    (void)capture;
    if (event == OH_SCREEN_CAPTURE_CONTENT_HIDE) {
        // 处理录屏内容变为隐藏。
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_VISIBLE) {
        // 处理录屏内容变为可见。
        // 录屏内容变为可见时，可通过回调回传的area参数，获取窗口的位置信息。
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE) {
        // 处理录屏内容变为不可用，如录屏窗口关闭。
    }
    (void)area;
    (void)userData;
}

struct OH_AVScreenCapture *capture;
// 开始录屏时调用StartScreenCapture。
static napi_value StartScreenCapture(napi_env env, napi_callback_info info) {
    OH_AVScreenCaptureConfig config;
    OH_AudioCaptureInfo micCapInfo = {
        .audioSampleRate = 48000, 
        .audioChannels = 2, 
        .audioSource = OH_MIC
    };

    OH_AudioCaptureInfo innerCapInfo = {
        .audioSampleRate = 48000, 
        .audioChannels = 2, 
        .audioSource = OH_ALL_PLAYBACK
    };

    OH_AudioEncInfo audioEncInfo = {
        .audioBitrate = 48000, 
        .audioCodecformat = OH_AudioCodecFormat::OH_AAC_LC
    };

    OH_VideoCaptureInfo videoCapInfo = {
        .videoFrameWidth = 768, 
        .videoFrameHeight = 1280, 
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_VideoEncInfo videoEncInfo = {
        .videoCodec = OH_VideoCodecFormat::OH_H264, 
        .videoBitrate = 2000000, 
        .videoFrameRate = 30
    };

    OH_AudioInfo audioInfo = {
        .micCapInfo = micCapInfo,
        .innerCapInfo = innerCapInfo,
        .audioEncInfo = audioEncInfo
    };

    OH_VideoInfo videoInfo = {
        .videoCapInfo = videoCapInfo, 
        .videoEncInfo = videoEncInfo
    };

    config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_CAPTURE_FILE,
        .audioInfo = audioInfo,
        .videoInfo = videoInfo,
    };

    // 实例化ScreenCapture。
    capture = OH_AVScreenCapture_Create();

    // 初始化录屏参数，传入配置信息OH_AVScreenRecorderConfig。
    OH_RecorderInfo recorderInfo;
    const std::string SCREEN_CAPTURE_ROOT = "/data/storage/el2/base/files/";
    int32_t outputFd = open((SCREEN_CAPTURE_ROOT + "screen01.mp4").c_str(), O_RDWR | O_CREAT, 0777);
    std::string fileUrl = "fd://" + std::to_string(outputFd);
    recorderInfo.url = const_cast<char *>(fileUrl.c_str());
    recorderInfo.fileFormat = OH_ContainerFormatType::CFT_MPEG_4;
    config.recorderInfo = recorderInfo;

    //设置状态回调。
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, nullptr);

    // 可选，设置录屏内容变化回调。
    OH_Rect* area = nullptr;
    OH_AVScreenCapture_SetCaptureContentChangedCallback(capture, OnCaptureContentChanged, area);

    // 可选，设置录屏屏幕Id回调，必须在开始录屏前调用。
    OH_AVScreenCapture_SetDisplayCallback(capture, OnDisplaySelected, nullptr);

    // 可选，设置光标显示开关，开始录屏前后均可调用。
    OH_AVScreenCapture_ShowCursor(capture, false);

    // 进行初始化操作。
    int32_t retInit = OH_AVScreenCapture_Init(capture, config);
    
    // 开始录屏。
    int32_t retStart = OH_AVScreenCapture_StartScreenRecording(capture);

    // 结束录屏见StopScreenCapture。
    
    // 返回调用结果，示例仅返回随意值。
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

// 结束录屏时调用StopScreenCapture。
static napi_value StopScreenCapture(napi_env env, napi_callback_info info) {
    if (capture != nullptr) {
        // 结束录屏。
        int32_t retStop = OH_AVScreenCapture_StopScreenRecording(capture);

        // 释放ScreenCapture。
        int32_t retRelease = OH_AVScreenCapture_Release(capture);
        capture = nullptr;
    }
    // 返回调用结果，示例仅返回随意值。
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"startScreenCapture", nullptr, StartScreenCapture, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"stopScreenCapture", nullptr, StopScreenCapture, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```
