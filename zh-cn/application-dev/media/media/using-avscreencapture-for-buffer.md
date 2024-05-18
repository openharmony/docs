# 使用AVScreenCapture录屏取原始码流(C/C++)

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（AVScreenCapture）模块的C API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。当开发直播、办公等应用时，可以调用录屏模块获取音视频原始码流，然后通过流的方式流转到其他模块处理，达成直播时共享桌面的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

当前在进行屏幕录制时默认使用主屏，图形默认根据主屏生产录屏帧数据到显示数据缓冲队列，录屏框架从显示数据缓冲队列获取数据进行相应处理。

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始屏幕录制时正在通话中或者屏幕录制过程中来电，录屏将自动停止。因通话中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../../reference/apis-media-kit/_a_v_screen_capture.md)。

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

    ```c++
    OH_AudioCaptureInfo miccapinfo = {
        .audioSampleRate = 16000,
        .audioChannels = 2,
        .audioSource = OH_MIC
    };

    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 720,
        .videoFrameHeight = 1080,
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

5. 回调函数的设置，主要监听录屏过程中的错误事件的发生,音频流和视频流数据的产生事件。

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

8. 调用AcquireAudioBuffer()获取音频原始码流数据.

    ```c++
    OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
    ```

9. 调用AcquireVideoBuffer()获取视频原始码流数据。

    ```c++
    OH_NativeBuffer* buffer = OH_AVScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
    ```

10. 调用ReleaseAudioBuffer()方法释放音频buffer。

    ```c++
    OH_AVScreenCapture_ReleaseAudioBuffer(capture, type);
    ```

11. 调用ReleaseVideoBuffer()释放视频数据。

    ```c++
    OH_AVScreenCapture_ReleaseVideoBuffer(capture);
    ```

12. 调用Release()方法销毁实例，释放资源。

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
        //可选 配置录屏旋转
        int32_t retRotation = OH_AVScreenCapture_SetCanvasRotation(capture, true);
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
        // 通话中断状态处理
        OH_LOG_INFO(LOG_APP, "DEMO OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL");
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // 处理状态变更
    }
    (void)userData;
}

void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,
    OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
    int32_t ret;
    // 获取解码后信息
    OH_AVCodecBufferAttr info;
    ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // 异常处理
    }
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
    // 实例化ScreenCapture
    capture = OH_AVScreenCapture_Create();
    
    // 设置回调 
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);

    // 可选 配置录屏旋转，此接口在感知到手机屏幕旋转时调用，如果手机的屏幕实际上没有发生旋转，调用接口是无效的。
    OH_AVScreenCapture_SetCanvasRotation(capture, true);
    // 可选 [过滤音频]
    OH_AVScreenCapture_ContentFilter contentFilter= OH_AVScreenCapture_CreateContentFilter();
    // 添加过滤通知音
    OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
    // 排除过滤器
    //OH_AVScreenCapture_ExcludeContent(capture, contentFilter);

    // 初始化录屏，传入配置信息OH_AVScreenRecorderConfig
    OH_AudioCaptureInfo miccapinfo = {.audioSampleRate = 16000, .audioChannels = 2, .audioSource = OH_MIC};
    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 720, .videoFrameHeight = 1080, .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA};
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
