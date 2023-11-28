# 屏幕录制

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（AVScreenCapture）模块的Native API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。当开发直播、办公等应用时，可以调用录屏模块获取音视频原始码流，然后通过流的方式流转到其他模块处理，达成直播时共享桌面的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块完成整个视频采集的流程。

当前在进行屏幕录制时默认使用主屏，图形默认根据主屏生产录屏帧数据到显示数据缓冲队列，录屏框架从显示数据缓冲队列获取数据进行相应处理。

## 开发指导

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。本开发指导将以一次录制屏幕数据的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../reference/native-apis/_a_v_screen_capture.md)。

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。
在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

### 录屏取原始码流权限说明

在开发前，请根据应用实际需求，参考[访问控制授权申请指导](../security/accesstoken-guidelines.md)申请以下权限：

| 权限名 | 说明 | 授权方式 | 权限级别 |
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | 允许应用截取屏幕图像。| system_grant | system_core |
| ohos.permission.MICROPHONE | 允许应用使用麦克风（可选）。<br>如需录制麦克风源的音频，需要申请该权限。| user_grant | normal |

### 录屏取原始码流开发步骤及注意事项

开发者可以通过以下几个步骤来实现一个简单的屏幕录制功能。

1. 创建AVScreenCapture实例capture。

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

2. 配置屏幕录制参数。
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

3. 设置麦克风开关。
     
    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

4. 回调函数的设置，主要监听录屏过程中的错误事件的发生,音频流和视频流数据的产生事件。
     
    ```c++
    OH_AVScreenCaptureCallback callback;
    callback.onAudioBufferAvailable = OnAudioBufferAvailable;
    callback.onVideoBufferAvailable = OnVideoBufferAvailable;
    OH_AVScreenCapture_SetCallback(capture, callback);
    ```

5. 调用StartScreenCapture方法开始进行屏幕录制。
     
    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

6. 调用StopScreenCapture()方法停止录制。
     
    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

7. 调用AcquireAudioBuffer()获取音频原始码流数据
     
    ```c++
    OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
    ```

8. 调用AcquireVideoBuffer()获取视频原始码流数据。
     
    ```c++
    OH_NativeBuffer* buffer = OH_ScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
    ```

9. 调用ReleaseAudioBuffer方法释放音频buffer。
     
    ```c++
    OH_ScreenCapture_ReleaseAudioBuffer(capture, type);
    ```

10. 调用ReleaseVideoBuffer()释放视频数据。
     
    ```c++
    OH_ScreenCapture_ReleaseVideoBuffer(capture);
    ```

11. 调用release()方法销毁实例，释放资源。
     
    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

### 录屏取原始码流完整示例

下面展示了使用AVScreenCapture屏幕录制的完整示例代码。
目前阶段流程结束后返回的buffer为原始码流，针对原始码流可以进行编码并以mp4等文件格式保存以供播放。编码格式当前阶段仅作预留，待后续版本实现。
  
```c++

#include "multimedia/player_framework/native_avscreen_capture.h"
#include "multimedia/player_framework/native_avscreen_capture_base.h"
#include "multimedia/player_framework/native_avscreen_capture_errors.h"

void OnError(struct OH_AVScreenCapture *capture, int32_t errorCode)
{
    (void) capture;
    (void) errorCode;
}

void OnAudioBufferAvailable(struct OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
{
    if (isReady) {
        OH_AudioBuffer *audiobuffer = (struct OH_AudioBuffer*) malloc (sizeof(OH_AudioBuffer));
        //获取音频流
        int32_t ret = OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
        /* get buffer */
        (void)audiobuffer->buf;
        /* getbuffer size */
        (void)audiobuffer->size;
        /* get audiobuffer timestamp */
        (void)audiobuffer->timestamp;
        free(audiobuffer);
        audiobuffer = nullptr;
        //释放音频流
        int32_t ret = OH_ScreenCapture_ReleaseAudioBuffer(capture, type);
    }
}

void OnVideoBufferAvailable(struct OH_AVScreenCapture *capture, bool isReady)
{
    if (isReady) {
        int32_t fence = 0;
        int64_t timestamp = 0;
        struct OH_Rect damage;
        //获取视频流
        OH_NativeBuffer* buffer = OH_ScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
        void *virAddr = nullptr;
        OH_NativeBuffer_Map(buffer, &virAddr);  //获取buffer
        OH_NativeBuffer_Config config;
        OH_NativeBuffer_GetNativeBufferConfig(buffer, config); //获取config信息 宽，高，format
        // fence, timestampe, damage 获取fence,时间戳，坐标信息
        OH_NativeBuffer_UnMap(buffer); //释放buffer
        //释放视频流
        int32_t ret = OH_ScreenCapture_ReleaseVideoBuffer(capture);
    }
}

int main()
{
    //实例化ScreenCapture
    struct OH_AVScreenCapture* capture = OH_AVScreenCapture_Create(void);
    //设置回调
    struct OH_AVScreenCaptureCallback callback;
    callback.onError = OnError;
    callback.onAudioBufferAvailable = OnAudioBufferAvailable ; 
    callback.onVideoBufferAvailable = OnVideoBufferAvailable;
    int32_t ret = OH_AVScreenCapture_SetCallback(capture, callback);
    //初始化录屏，传入配置信息OH_AVScreenRecorderConfig
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
    int32_t ret = OH_AVScreenCapture_Init(capture, config);
    //开始录屏
    int32_t ret = OH_AVScreenCapture_StartScreenCapture(capture);
    //mic开关设置
    int32_t ret = OH_ScreenCapture_SetMicrophoneEnable(capture, true);
    sleep(10); //录制10s
    //结束录屏
    int32_t ret = OH_ScreenCapture_StopScreenCapture(capture);
    //释放ScreenCapture
    int32_t ret = OH_ScreenCapture_Realease(capture);
    return 0;
}
```

### 录屏存文件权限说明

在开发前，请根据应用实际需求，参考[访问控制授权申请指导](../security/accesstoken-guidelines.md)申请以下权限：

| 权限名 | 说明 | 授权方式 | 权限级别 |
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | 允许应用截取屏幕图像。| system_grant | system_core |
| ohos.permission.MICROPHONE | 允许应用使用麦克风（可选）。| user_grant | normal |
| ohos.permission.READ_MEDIA | 允许应用读取用户外部存储中的媒体文件信息。| user_grant | normal |
| ohos.permission.WRITE_MEDIA | 允许应用读写用户外部存储中的媒体文件信息。| user_grant | normal |
| ohos.permission.SYSTEM_FLOAT_WINDOW | 允许应用使用悬浮窗的能力。| system_grant | system_basic |

### 录屏存文件开发步骤及注意事项

在 CMake 脚本中链接动态库
    ```c++
    target_link_libraries(entry PUBLIC libnative_avscreen_capture.so)
    ```

开发者可以通过以下几个步骤来实现一个简单的屏幕录制存文件的功能。

1. 添加头文件

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
    
    其中，录屏存文件仅仅能够在OH_AVScreenCapture_Init时期设置是否录制麦克风音频，在录制的过程中，无法控制麦克风的开启与关闭。
    
    同时，录屏存文件无需设置回调函数。

    ```c++
    //录屏时获取麦克风或者内录，二者选择其一，如果都设置了，优先取内录的参数设置，如果内录参数设置失败，取麦克风的参数设置
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
        .videoFrameWidth = 720,
        .videoFrameHeight = 1080,
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_VideoEncInfo videoEncInfo = {
        .videoCodec = OH_MPEG4,
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

4. 调用StartScreenCapture方法开始进行屏幕录制。
     
    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

5. 调用StopScreenCapture()方法停止录制。
     
    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

6. 调用release()方法销毁实例，释放资源。
     
    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

### 录屏存文件完整示例

下面展示了使用AVScreenCapture屏幕录制存文件的完整示例代码。
  
```c++

#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <fcntl.h>
#include "string"
#include "unistd.h"

static napi_value Screencapture(napi_env env, napi_callback_info info) {
    OH_AVScreenCaptureConfig config;
    OH_AudioCaptureInfo micCapInfo = {
        .audioSampleRate = 48000, 
        .audioChannels = 2, 
        .audioSource = OH_MIC
    };

    OH_AudioEncInfo audioEncInfo = {
        .audioBitrate = 48000, 
        .audioCodecformat = OH_AudioCodecFormat::OH_AAC_LC
    };

    OH_VideoCaptureInfo videoCapInfo = {
        .videoFrameWidth = 720, 
        .videoFrameHeight = 1080, 
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_VideoEncInfo videoEncInfo = {
        .videoCodec = OH_VideoCodecFormat::OH_H264, 
        .videoBitrate = 2000000, 
        .videoFrameRate = 30
    };

    OH_AudioInfo audioInfo = {
        .micCapInfo = micCapInfo, 
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

    struct OH_AVScreenCapture *capture = OH_AVScreenCapture_Create();

    // 初始化录屏参数，传入配置信息OH_AVScreenRecorderConfig
    OH_RecorderInfo recorderInfo;
    const std::string SCREEN_CAPTURE_ROOT = "/data/storage/el2/base/files/";
    int32_t outputFd = open((SCREEN_CAPTURE_ROOT + "screen01.mp4").c_str(), O_RDWR | O_CREAT, 0777);
    std::string fileUrl = "fd://" + std::to_string(outputFd);
    recorderInfo.url = const_cast<char *>(fileUrl.c_str());
    recorderInfo.fileFormat = OH_ContainerFormatType::CFT_MPEG_4;
    config.recorderInfo = recorderInfo;

    // 进行初始化操作
    int32_t retInit = OH_AVScreenCapture_Init(capture, config);

    // 开始录屏
    int32_t retStart = OH_AVScreenCapture_StartScreenCapture(capture);

    // 录制10s
    sleep(10);

    // 结束录屏
    int32_t retStop = OH_AVScreenCapture_StopScreenCapture(capture);

    // 释放ScreenCapture
    int32_t retRelease = OH_AVScreenCapture_Release(capture);

    // 返回调用结果，示例仅返回随意值
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    napi_property_descriptor desc[] = {
        {"screencapture", nullptr, Screencapture, nullptr, nullptr, nullptr, napi_default, nullptr}};
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
