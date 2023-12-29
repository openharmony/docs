# Screen Capture (C/C++)

Screen capture is mainly used to record the main screen.

You can call the native APIs of the **AVScreenCapture** module to record the screen and collect audio and video source data output by the device and microphone. When developing a live streaming or an office application, you can call the APIs to obtain original audio and video streams and transfer the streams to other modules for processing. In this way, the home screen can be shared during live streaming.

The **AVScreenCapture**, **Window**, and **Graphics** modules together implement the entire video capture process.

By default, the main screen is captured, and the **Graphics** module generates the screen capture frame data based on the main screen and places the data to the display data buffer queue. The screen capture framework obtains the data from the display data buffer queue for processing.

## Development Guidelines

The full screen capture process involves creating an **AVScreenCapture** instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing the instance. This topic describes how to use the **AVScreenCapture** module to carry out one-time screen capture. For details about the API reference, see [AVScreenCapture](../reference/native-apis/_a_v_screen_capture.md).

After an **AVScreenCapture** instance is created, different APIs can be called to switch the AVScreenCapture to different states and trigger the required behavior. If an API is called when the AVScreenCapture is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCapture state before triggering state transition.

### Permissions Required for Capturing Original Streams

Before development, configure the following permissions for your application. For details about permission configuration, see [Permission Application Guide](../security/accesstoken-guidelines.md).

| Permission| Description| Authorization Mode| APL|
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | Allows an application to take screenshots.| system_grant | system_core |
| ohos.permission.MICROPHONE | Allows an application to access the microphone.<br>This permission is required only when you need to record the audio output by the microphone.| user_grant | normal |

### Procedure and Precautions for Capturing Original Streams

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
    OH_NativeBuffer* buffer = OH_AVScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
    ```

9. Call **ReleaseAudioBuffer()** to release the audio buffer.
     
    ```c++
    OH_AVScreenCapture_ReleaseAudioBuffer(capture, type);
    ```

10. Call **ReleaseVideoBuffer()** to release the video buffer.
     
    ```c++
    OH_AVScreenCapture_ReleaseVideoBuffer(capture);
    ```

11. Call **release()** to release the instance.
     
    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

### Sample Code for Capturing Original Streams

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
    // Initialize the screen capture parameters and pass in an OH_AVScreenRecorderConfig struct.
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
    // Start screen capture.
    int32_t ret = OH_AVScreenCapture_StartScreenCapture(capture);
    // Enable the microphone.
    int32_t ret = OH_AVScreenCapture_SetMicrophoneEnabled(capture, true);
    sleep(10); // Capture the screen for 10s.
    // Stop screen capture.
    int32_t ret = OH_AVScreenCapture_StopScreenCapture(capture);
    // Release the AVScreenCapture instance.
    int32_t ret = OH_AVScreenCapture_Release(capture);
    return 0;
}
```

### Permissions Required for Storing Captured Files

Before development, configure the following permissions for your application. For details about permission configuration, see [Permission Application Guide](../security/accesstoken-guidelines.md).

| Permission| Description| Authorization Mode| APL|
| ------ | ----- | --------| ------- |
| ohos.permission.CAPTURE_SCREEN | Allows an application to take screenshots.| system_grant | system_core |
| ohos.permission.MICROPHONE | Allows an application to access the microphone.| user_grant | normal |
| ohos.permission.READ_MEDIA | Allows an application to read media files from the user's external storage.| user_grant | normal |
| ohos.permission.WRITE_MEDIA | Allows an application to read media files from and write media files into the user's external storage.| user_grant | normal |
| ohos.permission.SYSTEM_FLOAT_WINDOW | Allows an application to be displayed in a floating window on top of other applications.| system_grant | system_basic |

### Procedure and Precautions for Storing Captured Files

Link the dynamic library in the CMake script.
    ```c++
    target_link_libraries(entry PUBLIC libnative_avscreen_capture.so)
    ```

Then perform the following steps to store a captured file:

1. Add the header files.

    ```c++
    #include "napi/native_api.h"
    #include <multimedia/player_framework/native_avscreen_capture.h>
    #include <multimedia/player_framework/native_avscreen_capture_base.h>
    #include <multimedia/player_framework/native_avscreen_capture_errors.h>
    #include <fcntl.h>
    #include "string"
    #include "unistd.h"
    ```

2. Create an **AVScreenCapture** instance, named **capture** in this example.

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

3. Set screen capture parameters.
    
    After creating the **capture** instance, you can set the parameters required for screen capture.
    
    The setting that specifies whether to record microphone audio can be configured only during the initialization triggered by **OH_AVScreenCapture_Init**. It cannot be used to control the on/off status of the microphone once the recording starts.
    
    In addition, no callback function is required for storing captured files.

    ```c++
    // Obtain the microphone audio or internal sound. If both are set, the internal recording parameters are used preferentially. If the internal recording parameters fail to be set, the microphone parameter setting is used.
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

4. Call **StartScreenCapture** to start screen capture.
     
    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

5. Call **StopScreenCapture()** to stop screen capture.
     
    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

6. Call **release()** to release the instance.
     
    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

### Sample Code for Storing Captured Files

Refer to the sample code below to implement captured file storage using **AVScreenCapture**.
  
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

    // Initialize the screen capture parameters and pass in an OH_AVScreenRecorderConfig struct.
    OH_RecorderInfo recorderInfo;
    const std::string SCREEN_CAPTURE_ROOT = "/data/storage/el2/base/files/";
    int32_t outputFd = open((SCREEN_CAPTURE_ROOT + "screen01.mp4").c_str(), O_RDWR | O_CREAT, 0777);
    std::string fileUrl = "fd://" + std::to_string(outputFd);
    recorderInfo.url = const_cast<char *>(fileUrl.c_str());
    recorderInfo.fileFormat = OH_ContainerFormatType::CFT_MPEG_4;
    config.recorderInfo = recorderInfo;

    // Initialize AVScreenCapture.
    int32_t retInit = OH_AVScreenCapture_Init(capture, config);

    // Start screen capture.
    int32_t retStart = OH_AVScreenCapture_StartScreenCapture(capture);

    // Capture the screen for 10s.
    sleep(10);

    // Stop screen capture.
    int32_t retStop = OH_AVScreenCapture_StopScreenCapture(capture);

    // Release the AVScreenCapture instance.
    int32_t retRelease = OH_AVScreenCapture_Release(capture);

    // Return the invoking result. In the example, only a random number is returned.
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
