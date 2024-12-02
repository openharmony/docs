# 使用AVScreenCapture录屏取码流(C/C++)

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（AVScreenCapture）模块的C API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。当开发直播、办公等应用时，可以调用录屏模块获取音视频原始码流，然后通过流的方式流转到其他模块处理，达成直播时共享桌面的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

当前在进行屏幕录制时默认使用主屏，图形默认根据主屏生产录屏帧数据到显示数据缓冲队列，录屏框架从显示数据缓冲队列获取数据进行相应处理。

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始屏幕录制时正在通话中或者屏幕录制过程中来电，录屏将自动停止。因通话中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL状态。

屏幕录制过程中发生系统用户切换事件时，录屏将自动停止。因系统用户切换中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../../reference/apis-media-kit/_a_v_screen_capture.md)。

如果配置了采集麦克风音频数据，需对应配置麦克风权限ohos.permission.MICROPHONE和申请长时任务，配置方式请参见[向用户申请权限](../../security/AccessToken/request-user-authorization.md)、[申请长时任务](../../task-management/continuous-task.md)。

## 开发步骤及注意事项

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。
在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

**在 CMake 脚本中链接动态库**

```c++
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libnative_buffer.so libnative_media_core.so)
```

1. 添加头文件。

    ```c++
    #include "napi/native_api.h"
    #include <multimedia/player_framework/native_avscreen_capture.h>
    #include <multimedia/player_framework/native_avscreen_capture_base.h>
    #include <multimedia/player_framework/native_avscreen_capture_errors.h>
    #include <native_buffer/native_buffer.h>
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

    ```c++
    OH_AudioCaptureInfo miccapinfo = {
        .audioSampleRate = 16000,
        .audioChannels = 2,
        .audioSource = OH_MIC
    };

    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 768,
        .videoFrameHeight = 1280,
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
    };

    OH_VideoInfo videoinfo = {
        .videoCapInfo = videocapinfo
    };

    OH_AVScreenCaptureConfig config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_ORIGINAL_STREAM,
        .audioInfo = audioinfo,
        .videoInfo = videoinfo
    };

    OH_AVScreenCapture_Init(capture, config);
    ```

4. 设置麦克风开关。

    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

5. 回调函数的设置，主要监听录屏过程中的错误事件的发生，音频流和视频流数据的产生事件。

    ```c++
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);
    ```

6. 调用StartScreenCapture()方法开始进行屏幕录制。

    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

    或调用StartScreenCaptureWithSurface方法以Surface模式进行屏幕录制。

    ```c++
    OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window);
    ```

7. 调用StopScreenCapture()方法停止录制。

    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

8. 在回调OnBufferAvailable()中获取并处理音频视频原始码流数据。

    ```c++
    OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,
        OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
    ```

9. 调用Release()方法销毁实例，释放资源。

    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

## 完整示例

下面展示了使用AVScreenCapture屏幕录制的完整示例代码。

创建OH_AVBuffer，可参考[视频解码Buffer模式](../avcodec/video-decoding.md#buffer模式)。

使用Surface模式录屏，可参考[视频编码Surface模式](../avcodec/video-encoding.md#surface模式)。

目前阶段流程结束后返回的buffer为原始码流，针对原始码流可以进行编码并以mp4等文件格式保存以供播放。

> **说明：**
> 编码格式当前阶段仅作预留，待后续版本实现。

```c++

#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <multimedia/player_framework/native_avbuffer.h>
#include <native_buffer/native_buffer.h>
#include <fcntl.h>
#include "string"
#include "unistd.h"

void OnError(OH_AVScreenCapture *capture, int32_t errorCode, void *userData) {
    (void)capture;
    (void)errorCode;
    (void)userData;
}

void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
    (void)capture;
    
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
        // 处理状态变更
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL ||
        stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
        // 录屏中断状态处理
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // 处理状态变更
    }
    (void)userData;
}

void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,
    OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
    // 获取解码后信息 可以参考编解码接口
    int bufferLen = OH_AVBuffer_GetCapacity(buffer);
    OH_NativeBuffer *nativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
    OH_NativeBuffer_Config config;
    OH_NativeBuffer_GetConfig(nativeBuffer, &config);
    int32_t videoSize= config.height * config.width * 4;
    uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
    if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
        // 处理视频buffer
    } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
        // 处理内录buffer
    } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
        // 处理麦克风buffer
    }
}

struct OH_AVScreenCapture *capture;
static napi_value Screencapture(napi_env env, napi_callback_info info) {
    // 从js端获取窗口id number[]
    std::vector<int> windowIdsExclude = {};
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    // 获取参数
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取数组长度
    uint32_t array_length;
    napi_get_array_length(env, args[0], &array_length);
    // 读初窗口id
    for (int32_t i = 0; i < array_length; i++) {
        napi_value temp;
        napi_get_element(env, args[0], i, &temp);
        uint32_t tempValue;
        napi_get_value_uint32(env, temp, &tempValue);
        windowIdsExclude.push_back(tempValue);
     }
    // 实例化ScreenCapture
    capture = OH_AVScreenCapture_Create();
    
    // 设置回调 
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, nullptr);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, nullptr);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, nullptr);

    // 可选 配置录屏旋转，此接口在感知到手机屏幕旋转时调用，如果手机的屏幕实际上没有发生旋转，调用接口是无效的。
    OH_AVScreenCapture_SetCanvasRotation(capture, true);
    // 可选 [过滤音频]
    OH_AVScreenCapture_ContentFilter *contentFilter= OH_AVScreenCapture_CreateContentFilter();
    // 添加过滤通知音
    OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
    // 排除指定窗口id
    OH_AVScreenCapture_ContentFilter_AddWindowContent(contentFilter, &windowIdsExclude[0],
                                                      static_cast<int32_t>(windowIdsExclude.size()));

    OH_AVScreenCapture_ExcludeContent(capture, contentFilter);

    // 初始化录屏，传入配置信息OH_AVScreenRecorderConfig
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

    // 可选 [Surface模式]
    // 通过 MIME TYPE 创建编码器，系统会根据MIME创建最合适的编码器。
    // OH_AVCodec *codec = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);    
    // 从视频编码器获取输入Surface
    // OH_AVErrCode OH_VideoEncoder_GetSurface(codec, window);
    // 启动编码器
    // int32_t retEnc = OH_VideoEncoder_Start(codec);
    // 指定surface开始录屏
    // int32_t retStart = OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window); 

    // 开始录屏
    OH_AVScreenCapture_StartScreenCapture(capture);

    // mic开关设置
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, true);

    // 可选 豁免隐私窗口 需传递应用豁免子窗口和主窗口ID，传空数组取消豁免隐私窗口
	// std::vector<int> windowIdsSkipPrivacy = {};
    // OH_AVScreenCapture_SkipPrivacyMode(capture, &windowIdsSkipPrivacy[0],
    //     static_cast<int32_t>(windowIdsSkipPrivacy.size()));

    // 可选 调整录屏分辨率 需在启动后调用，分辨率有范围限制 可参考avcodec编解码能力
    // OH_AVScreenCapture_ResizeCanvas(capture, 768, 1280);

    sleep(10); // 录制10s
    // 结束录屏
    OH_AVScreenCapture_StopScreenCapture(capture);
    // 释放ScreenCapture
    OH_AVScreenCapture_Release(capture);
    // 返回调用结果，示例仅返回随意值
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}
```
