# Screen Capture

Screen capture is mainly used to record the main screen.

You can call the native APIs of the **AVScreenCapture** module to record the screen and collect audio and video source data output by the device and microphone. When developing a live streaming or an office application, you can call the APIs to obtain original audio and video streams and transfer the streams to other modules for processing. In this way, the home screen can be shared during live streaming.

The **AVScreenCapture**, **Window**, and **Graphics** modules together implement the entire video capture process.

By default, the main screen is captured, and the **Graphics** module generates the screen capture frame data based on the main screen and places the data to the display data buffer queue. The screen capture framework obtains the data from the display data buffer queue for processing.

## Development Guidelines

The full screen capture process involves creating an **AVScreenCapture** instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing the instance. This topic describes how to use the **AVScreenCapture** module to carry out one-time screen capture. For details about the API reference, see [AVScreenCapture](../reference/native-apis/_a_v_screen_capture.md).

After an **AVScreenCapture** instance is created, different APIs can be called to switch the AVScreenCapture to different states and trigger the required behavior. If an API is called when the AVScreenCapture is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCapture state before triggering state transition.

### Permission Description

Before development, configure the following permissions for your application. For details about permission configuration, see [Permission Application Guide](../security/accesstoken-guidelines.md).

| Permission| Description| Authorization Mode| APL|
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | Allows an application to take screenshots.| system_grant | system_core |
| ohos.permission.MICROPHONE | Allows an application to access the microphone.<br>This permission is required only when you need to record the audio output by the microphone.| user_grant | normal |

### How to Develop

The following walks you through how to implement simple screen capture:

1. Create an **AVScreenCapture** instance, named **capture** in this example.

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

2. Set screen capture parameters.
      After creating the **capture** instance, you can set the parameters required for screen capture.

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

3. Enable the microphone.
   
    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

4. Set callback functions, which are used to listen for errors that may occur during screen capture and the generation of audio and video stream data.
   
    ```c++
    OH_AVScreenCaptureCallback callback;
    callback.onAudioBufferAvailable = OnAudioBufferAvailable;
    callback.onVideoBufferAvailable = OnVideoBufferAvailable;
    OH_AVScreenCapture_SetCallback(capture, callback);
    ```

5. Call **StartScreenCapture** to start screen capture.
   
    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

6. Call **StopScreenCapture()** to stop screen capture.
   
    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

7. Call **AcquireAudioBuffer()** to obtain an audio buffer.
   
    ```c++
    OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
    ```

8. Call **AcquireVideoBuffer()** to obtain a video buffer.
   
    ```c++
    OH_NativeBuffer* buffer = OH_ScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
    ```

9. Call **ReleaseAudioBuffer()** to release the audio buffer.
   
    ```c++
    OH_ScreenCapture_ReleaseAudioBuffer(capture, type);
    ```

10. Call **ReleaseVideoBuffer()** to release the video buffer.
    
    ```c++
    OH_ScreenCapture_ReleaseVideoBuffer(capture);
    ```

11. Call **release()** to release the instance.
    
    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

### Sample Code

Refer to the sample code below to implement screen capture using **AVScreenCapture**.
Currently, the buffer holds original streams, which can be encoded and saved in MP4 format for playback. The encoding format is reserved and will be implemented in later versions.

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
        // Obtain an audio buffer.
        int32_t ret = OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
        /* Obtain a buffer. */
        (void)audiobuffer->buf;
        /* Obtain the buffer size. */
        (void)audiobuffer->size;
        /* Obtain the timestamp of the audio buffer. */
        (void)audiobuffer->timestamp;
        free(audiobuffer);
        audiobuffer = nullptr;
        // Release the audio buffer.
        int32_t ret = OH_ScreenCapture_ReleaseAudioBuffer(capture, type);
    }
}

void OnVideoBufferAvailable(struct OH_AVScreenCapture *capture, bool isReady)
{
    if (isReady) {
        int32_t fence = 0;
        int64_t timestamp = 0;
        struct OH_Rect damage;
        // Obtain a video buffer.
        OH_NativeBuffer* buffer = OH_ScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
        void *virAddr = nullptr;
        OH_NativeBuffer_Map (buffer, &virAddr); // Obtain a buffer.
        OH_NativeBuffer_Config config;
        OH_NativeBuffer_GetNativeBufferConfig(buffer, config); // Obtain the width, height, and format.
        // Obtain the fence, timestamp, and coordinate information.
        OH_NativeBuffer_UnMap (buffer); // Release the buffer.
        // Release the video buffer.
        int32_t ret = OH_ScreenCapture_ReleaseVideoBuffer(capture);
    }
}

int main()
{
    // Instantiate AVScreenCapture.
    struct OH_AVScreenCapture* capture = OH_AVScreenCapture_Create(void);
    // Set the callbacks.
    struct OH_AVScreenCaptureCallback callback;
    callback.onError = OnError;
    callback.onAudioBufferAvailable = OnAudioBufferAvailable ; 
    callback.onVideoBufferAvailable = OnVideoBufferAvailable;
    int32_t ret = OH_AVScreenCapture_SetCallback(capture, callback);
    // Initialize AVScreenCapture and pass in an OH_AVScreenRecorderConfig struct.
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
        .videoInfo = videoinfo
    };
    int32_t ret = OH_AVScreenCapture_Init(capture, config);
    // Start screen capture.
    int32_t ret = OH_AVScreenCapture_StartScreenCapture(capture);
    // Enable the microphone.
    int32_t ret = OH_ScreenCapture_SetMicrophoneEnable(capture, true);
    sleep(10); // Capture the screen for 10s.
    // Stop screen capture.
    int32_t ret = OH_ScreenCapture_StopScreenCapture(capture);
    // Release the AVScreenCapture instance.
    int32_t ret = OH_ScreenCapture_Realease(capture);
    return 0;
}
```
