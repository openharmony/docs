# 屏幕录制

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（AVScreenCapture）模块的Native API接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。当开发直播、办公等应用时，可以调用录屏模块获取音视频原始码流，然后通过流的方式流转到其他模块处理，达成直播时共享桌面的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块完成整个视频采集的流程。

当前在进行屏幕录制时默认使用主屏，图形默认根据主屏生产录屏帧数据到显示数据缓冲队列，录屏框架从显示数据缓冲队列获取数据进行相应处理。

## 开发指导

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。本开发指导将以一次录制屏幕数据的过程为例，向开发者讲解如何使用AVScreenCapture进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../reference/native-apis/_a_v_screen_capture.md)。

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。
在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

### 权限说明

在开发前，请根据应用实际需求，参考[访问控制授权申请指导](../security/accesstoken-guidelines.md)申请以下权限：

| 权限名 | 说明 | 授权方式 | 权限级别 |
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | 允许应用截取屏幕图像。| system_grant | system_core |
| ohos.permission.MICROPHONE | 允许应用使用麦克风（可选）。<br>如需录制麦克风源的音频，需要申请该权限。| user_grant | normal |

### 开发步骤及注意事项

开发者可以通过以下几个步骤来实现一个简单的屏幕录制功能。

1. 创建AVScreenCapture实例capture。

    ```c++
    OH_AVScreenCapture* capture = AVScreenCapture_Create();
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
        .videoFrameWidth = display->GetWidth(),
        .videoFrameHeight = display->Height(),
        .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
    };

    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
    };

    OH_VideoInfo videoinfo = {
        .videoCapInfo = videocapinfo
    };

    OH_RecorderInfo recorderinfo = {
        .url = name
    };

    OH_AVScreenCaptureConfig config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_ORIGINAL_STREAM,
        .audioInfo = audioinfo,
        .videoInfo = videoinfo,
        .recorderInfo = recorderinfo
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
    OH_AVScreenCapture_StopScreenCapture(capture_);
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

### 完整示例

下面展示了使用AVScreenCapture屏幕录制的完整示例代码。
目前阶段流程结束后返回的buffer为原始码流，针对原始码流可以进行编码并以mp4等文件格式保存以供播放。编码格式与文件格式当前阶段仅作预留，待后续版本实现。
  
```c++

#include "multimedia/player_framework/native_avscreen_capture.h"
#include "multimedia/player_framework/native_avscreen_capture_base.h"
#include "multimedia/player_framework/native_avscreen_capture_errors.h"

void OnError(struct OH_AVScreenCapture *capture, int32_t errorCode)
{
    (void) capture;
    (void) errorCode;
}

void OnAudioBufferAvailable(struct OH_AVScreenCapture *capture, bool isReady, OH_AudioCapSourceType type)
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

void OnVideoBufferAvailable(struct OH_ScreenCapture *capture, bool isReady)
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
    callack.onAudioBufferAvailable = OnAudioBufferAvailable ; 
    callack.onVideoBufferAvailable = OnVideoBufferAvailable;
    int32_t ret = OH_AVScreenCapture_SetCallback(capture, callback);
    //初始化录屏，传入配置信息OH_AVScreenRecorderConfig
    OH_AudioCaptureInfo miccapinfo = {
        .audioSampleRate = 16000,
        .audioChannels = 2,
        .audioSource = OH_MIC
    };
    OH_VideoCaptureInfo videocapinfo = {
        .videoFrameWidth = 720,
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
        .videoInfo = videoinfo,
        .recorderInfo = recorderinfo
    };
    OH_AVScreenCapture_Init(capture, config);
    int32_t ret = OH_AVScreenCapture_Init(capture, &config);
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
