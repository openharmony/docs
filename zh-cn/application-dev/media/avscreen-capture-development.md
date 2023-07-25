# 开发屏幕录制功能

屏幕录制功能主要有主屏幕录屏、指定物理屏录屏和应用内录屏三个子功能。

录屏（AVScreenCapture）以单独的原子能力构建，北向给开发者提供能力接口，视频采集南向对接窗口子系统和图形子系统，语音采集和编码后码流横向在媒体子系统内部对接AudioService和AVCodecService。AVScreenCapture采用client-server设计结构，用openharmony IPC进行通信，图中绿色为新增模块。proxy和stub，负责IPC接口通信，npi提供kit层级的接口，client负责权限校验以及接口能力。server负责音视频的采集，以及buffer管理等。

主屏幕录屏：录屏框架在makeMirror时默认使用主屏；图形默认根据主屏produce surface到BufferQueue；录屏框架从BufferQueue consumer数据进行相应处理。

指定物理屏录屏：app从窗口子系统获取所有displayId；app根据用户选择，在调用录屏框架接口init时，带入用户选择 共享的屏幕；录屏框架在makeMirror时，传入displayId给窗口子系统； 窗口子系统向图形那边设置图层白名单；图形根据设置的白名单图层produce surface到BufferQueue； 录屏框架从BufferQueue consumer数据进行相应处理。(api 10对此功能暂仅作参数预留，未做实际实现)

应用内录屏：app从missionManger获取全局的mission；app根据用户选择，在调用录屏框架接口init时，带入用户选择 的missionId（可以是多个）；录屏框架在createVirtualScreen时，传入missionId给窗口子系统；窗口子系统向图形那边设置图层白名单；图形根据设置的白名单图层produce surface到BufferQueue；录屏框架从BufferQueue consumer数据进行相应处理。(api 10对此功能暂仅作参数预留，未做实际实现)

## 开发指导

使用AVScreenCapture录制屏幕涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。本开发指导将以一次录制屏幕数据的过程为例，向开发者讲解如何使用AVScreenCapturer进行屏幕录制，详细的API声明请参考[AVScreenCapture API参考](../reference/native-apis/_a_v_screen_capture.md)。

使用AVScreenCapture时要注意状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。需要注意的是在确定的状态执行不合适的方法可能导致AVScreenCapture发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

### 开发步骤及注意事项

开发者可以通过以下几个步骤来实现一个简单的屏幕录制功能。

1. 创建AVScreenCapture实例capture。

   ```c++

   OH_AVScreenCapture* capture = AVScreenCapture_Create();
   ```

2. 配置屏幕录制参数。
      创建AVScreenCapture实例capture后，可以设置屏幕录制所需要的参数，可以参考下面的案例。
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

8. 调用AcquireVideoBuffer()方法停止录制。
     
   ```c++

  OH_NativeBuffer* buffer = OH_ScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
   ```

9. 调用ReleaseAudioBuffer方法释放音频buffer。
     
   ```c++

  OH_ScreenCapture_ReleaseAudioBuffer(capture, type);
   ```

10. 调用ReleaseVideoBuffer()方法停止录制。
     
   ```c++

  OH_ScreenCapture_ReleaseVideoBuffer(capture);
   ```

11. 调用release()方法销毁实例，释放资源。
     
   ```c++

  OH_AVScreenCapture_Release(capture);
   ```

### 完整示例

下面展示了使用AVScreenCapture屏幕录制的完整示例代码。
  
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
        /* get audiobuffer timestampe */
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
