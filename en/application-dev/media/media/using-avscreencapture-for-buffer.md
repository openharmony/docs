# Using AVScreenCapture to Obtain Original Streams (C/C++)

Screen capture is mainly used to record the main screen.

You can call the C APIs of the **AVScreenCapture** module to record the screen and collect audio and video source data output by the device and microphone. When developing a live streaming or an office application, you can call the APIs to obtain original audio and video streams and transfer the streams to other modules for processing. In this way, the home screen can be shared during live streaming.

The **AVScreenCapture**, **Window**, and **Graphics** modules together implement the entire video capture process.

By default, the main screen is captured, and the **Graphics** module generates the screen capture frame data based on the main screen and places the data to the display data buffer. The screen capture framework obtains the data from the buffer for processing.

The full screen capture process involves creating an **AVScreenCapture** instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing resources.

If you are in a call when screen capture starts or a call is coming during screen capture, screen capture automatically stops, and the **OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL** status is reported.

This topic describes how to use the **AVScreenCapture** APIs to carry out one-time screen capture. For details about the API reference, see [AVScreenCapture](../../reference/apis-media-kit/_a_v_screen_capture.md).

## How to Develop

After an **AVScreenCapture** instance is created, different APIs can be called to switch the AVScreenCapture to different states and trigger the required behavior.

If an API is called when the AVScreenCapture is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCapture state before triggering state transition.

**Linking the Dynamic Library in the CMake Script**

```c++
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so)
```

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

4. Enable the microphone.

    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

5. Set callback functions, which are used to listen for errors that may occur during screen capture and the generation of audio and video stream data.

    ```c++
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);
    ```

6. Call **StartScreenCapture()** to start screen capture.

    ```c++
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

    Alternatively, call **StartScreenCaptureWithSurface()** to start screen capture in surface mode.

    ```c++
    OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window);
    ```

7. Call **StopScreenCapture()** to stop screen capture.

    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

8. Call **AcquireAudioBuffer()** to obtain an audio buffer.

    ```c++
    OH_AVScreenCapture_AcquireAudioBuffer(capture, &audiobuffer, type);
    ```

9. Call **AcquireVideoBuffer()** to obtain a video buffer.

    ```c++
    OH_NativeBuffer* buffer = OH_AVScreenCapture_AcquireVideoBuffer(capture, &fence, &timestamp, &damage);
    ```

10. Call **ReleaseAudioBuffer()** to release the audio buffer.

    ```c++
    OH_AVScreenCapture_ReleaseAudioBuffer(capture, type);
    ```

11. Call **ReleaseVideoBuffer()** to release the video buffer.

    ```c++
    OH_AVScreenCapture_ReleaseVideoBuffer(capture);
    ```

12. Call **Release()** to release the instance.

    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

## Example

Refer to the sample code below to implement screen capture using **AVScreenCapture**.

For details about how to create an **OH_AVBuffer** instance, see [Buffer Output](../avcodec/video-decoding.md#buffer-output).

For details about screen capture in surface mode, see [Surface Input](../avcodec/video-encoding.md#surface-input).

Currently, the buffer holds original streams, which can be encoded and saved in MP4 format for playback.

> **NOTE**
> The encoding format is reserved and will be implemented in later versions.

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
        // Process the state change.
        // (Optional) Configure screen capture rotation.
        int32_t retRotation = OH_AVScreenCapture_SetCanvasRotation(capture, true);
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
        // Process the screen capture interruption caused by incoming calls.
        OH_LOG_INFO(LOG_APP, "DEMO OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL");
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // Process the state change.
    }
    (void)userData;
}

void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,
    OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
    int32_t ret;
    // Obtain the decoded information.
    OH_AVCodecBufferAttr info;
    ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
    if (ret != AV_ERR_OK) {
        // Exception handling.
    }
    if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
        // Process the video buffer.
    } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
        // Process the internal capture buffer.
    } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
        // Process the microphone buffer.
    }
}

struct OH_AVScreenCapture *capture;
static napi_value Screencapture(napi_env env, napi_callback_info info) {
    // Instantiate AVScreenCapture.
    capture = OH_AVScreenCapture_Create();
    
    // Set the callbacks.
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);

    // (Optional) Configure screen capture rotation. This API should be called when the device screen rotation is detected. If the device screen does not rotate, the API call is invalid.
    OH_AVScreenCapture_SetCanvasRotation(capture, true);
    // Optional. Filter audio.
    OH_AVScreenCapture_ContentFilter contentFilter= OH_AVScreenCapture_CreateContentFilter();
    // Add a filter announcement.
    OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
    // Exclude the content.
    //OH_AVScreenCapture_ExcludeContent(capture, contentFilter);

    // Initialize the screen capture parameters and pass in an OH_AVScreenRecorderConfig struct.
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

    // Optional. Use the surface mode.
    // To create an encoder by MIME type, call OH_VideoEncoder_CreateByMime. The system creates the most appropriate encoder based on the MIME type.
    // OH_AVCodec *codec = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);    
    // Obtain the input surface from a video encoder.
    // OH_AVErrCode OH_VideoEncoder_GetSurface(codec, window);
    // Start the encoder.
    // int32_t retEnc = OH_VideoEncoder_Start(codec);
    // Specify a surface to start screen capture.
    // int32_t retStart = OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window); 

    // Start screen capture.
    OH_AVScreenCapture_StartScreenCapture(capture);
    // Enable the microphone.
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, true);

    sleep(10); // Capture the screen for 10s.
    // Stop screen capture.
    OH_AVScreenCapture_StopScreenCapture(capture);
    // Release the AVScreenCapture instance.
    OH_AVScreenCapture_Release(capture);
    // Return the call result. In the example, only a random number is returned.
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}
```
