# Using AVScreenCapture to Capture Screens and Obtain Streams (C/C++)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

Screen recording enables you to capture screen data for various applications like screen recording, conference sharing, and live streaming. The stream data captured through screen recording can be processed differently based on the use case. For example:
- You can connect to NativeImage as the consumer to provide a surface associated with an OpenGL external texture. For details, see [Native Image Development (C/C++)](../../graphics/native-image-guidelines.md).
- You can connect to encoders and muxers to encode and multiplex the data. For detailed usage, see [Video Encoding](../avcodec/video-encoding.md) and [Media Data Multiplexing](../avcodec/audio-video-muxer.md).
<!--RP1--><!--RP1End-->

You can call the C APIs of the [AVScreenCapture](media-kit-intro.md#avscreencapture) module to record the screen and collect audio and video source data output by the device and microphone. When developing a live streaming or an office application, you can call the APIs to obtain original audio and video streams and transfer the streams to other modules for processing. In this way, the home screen can be shared during live streaming.

The AVScreenCapture, Window, and Graphics modules together implement the entire video capture process.

By default, the main screen is captured, and the Graphics module generates the screen capture frame data based on the main screen and places the data to the display data buffer. The player framework obtains the data from the buffer for processing.

The full screen capture process involves creating an AVScreenCapture instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing resources.

If you are in a call when screen capture starts or a call is coming during screen capture, screen capture automatically stops, and the **OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL** status is reported.

Screen capture automatically stops upon system user switching, and **OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES** is reported.

This topic describes how to use the AVScreenCapture APIs to carry out one-time screen capture. For details about the API reference, see [AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture.md).

If microphone data collection is configured, configure the permission ohos.permission.MICROPHONE and request a continuous task. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md) and [Continuous Task](../../task-management/continuous-task.md).

<!--RP2--><!--RP2End-->

## How to Develop

After an AVScreenCapture instance is created, different APIs can be called to switch the AVScreenCapture to different states and trigger the required behavior.

If an API is called when the AVScreenCapture is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCapture state before triggering state transition.

**Linking the dynamic libraries in the CMake Script**

```c++
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libnative_buffer.so libnative_media_core.so)
```

1. Add the header files.

    ```c++
    #include "napi/native_api.h"
    #include <multimedia/player_framework/native_avscreen_capture.h>
    #include <multimedia/player_framework/native_avscreen_capture_base.h>
    #include <multimedia/player_framework/native_avscreen_capture_errors.h>
    #include <multimedia/player_framework/native_avbuffer.h>
    #include <native_buffer/native_buffer.h>
    #include <vector>
    ```

2. Check whether there is a running screen capture service instance. If yes, wait until the instance is stopped and the resources are released.

3. Create an AVScreenCapture instance, named **capture** in this example.

    ```c++
    OH_AVScreenCapture* capture = OH_AVScreenCapture_Create();
    ```

4. Set screen capture parameters.

    After the capture instance is created, you can set the parameters required for screen capture. For details about how to set the audio and video parameters, see [Detailed Description](#detailed-description).

    ```c++
    OH_AudioInfo audioinfo = {
        .micCapInfo = miccapinfo,
        .innerCapInfo = innerCapInfo,
        .audioEncInfo = audioEncInfo
    };

    OH_VideoInfo videoinfo = {
        .videoCapInfo = videocapinfo,
        .videoEncInfo = videoEncInfo
    };

    OH_AVScreenCaptureConfig config = {
        .captureMode = OH_CAPTURE_HOME_SCREEN,
        .dataType = OH_ORIGINAL_STREAM,
        .audioInfo = audioinfo,
        .videoInfo = videoinfo
    };

    OH_AVScreenCapture_Init(capture, config);
    ```

5. (Optional) Enable the microphone.

    ```c++
    bool isMic = true;
    OH_AVScreenCapture_SetMicrophoneEnabled(capture, isMic);
    ```

6. Set callback functions, which are used to listen for errors that may occur during screen capture, the generation of audio and video stream data, the retrieval of the display ID, and the change of screen capture content. See [Detailed Description](#detailed-description) for more information.

    ```c++
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, userData);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, userData);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, userData);
    OH_AVScreenCapture_SetDisplayCallback(capture, OnDisplaySelected, userData);
    OH_AVScreenCapture_SetCaptureContentChangedCallback(capture, OnCaptureContentChanged, userData);
    OH_AVScreenCapture_SetSelectionCallback(capture, OnUserSelected, userData);
    ```

7. (Optional) Set screen capture strategies.

   7.1 (Optional) Set the privacy window masking mode for screen capture.

        The value **0** means that the full-screen masking mode is used, and **1** means that the window masking mode is used. The default value is full-screen masking mode.

        ```c++
        int value = 0;
        OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
        OH_AVScreenCapture_StrategyForPrivacyMaskMode(strategy, value);
        OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
        ```

   7.2 (Optional) Set the automatic rotation following configuration for screen capture.  

       Set **StrategyForCanvasFollowRotation** to **true** to enable automatic rotation following. This will automatically adjust the virtual screen size after a rotation, ensuring the output follows the rotation promptly. After this setting, there is no need to manually call **OH_AVScreenCapture_ResizeCanvas** after rotation notifications.

        ```c++
        OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
        OH_AVScreenCapture_StrategyForCanvasFollowRotation(strategy, true);
        OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
        ```

8. Call **StartScreenCapture()** to start screen capture.

    ```c++
    bool IsCaptureStreamRunning = true;
    OH_AVScreenCapture_StartScreenCapture(capture);
    ```

    Alternatively, call **StartScreenCaptureWithSurface()** to start screen capture in surface mode.

    ```c++
    OH_AVScreenCapture_StartScreenCaptureWithSurface(capture, window);
    ```

9. Call **StopScreenCapture()** to stop screen capture. See [Detailed Description](#detailed-description) for more information.

    ```c++
    OH_AVScreenCapture_StopScreenCapture(capture);
    ```

10. Call **Release()** to release the instance.

    ```c++
    OH_AVScreenCapture_Release(capture);
    ```

## Specifications for Selecting the Window to Capture on PCs or 2-in-1 Devices
The screen capture feature for PCs or 2-in-1 devices, utilizing the APIs related to screen capture, provides a window selection dialog box that appears based on the configurations outlined in the table below. When a window ID is provided, the PC or 2-in-1 device displays a picker for users to select the corresponding window. The content that gets captured ultimately depends on the user's choice within the picker.

Starting from API level 20, [OH_AVScreenCapture_SetCaptureArea](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea) is supported to enable the area-based screen capture feature, which pops up a privacy permission dialog box.

| Screen Mode Type                                         | Number of Window IDs Passed    | Dialog Box Type           |
| ----------------------------------------------------- | ------------------ | ------------------- |
| OH_CAPTURE_HOME_SCREEN                                | Invalid Window IDs| Privacy permission dialog box|
| OH_CAPTURE_SPECIFIED_SCREEN                           | Invalid Window IDs| Picker dialog box         |
| OH_CAPTURE_SPECIFIED_WINDOW                           | Zero or one window ID    | Picker dialog box         |
| OH_CAPTURE_SPECIFIED_WINDOW                           | Two or more window IDs   | Privacy permission dialog box|
| Area-based screen capture (enabled by calling OH_AVScreenCapture_SetCaptureArea)| Invalid Window IDs| Privacy permission dialog box|

It is recommended that the selection page be used in **OH_CAPTURE_SPECIFIED_WINDOW** mode. You need to configure the screen capture height and width based on the PC's or 2-in-1 device's resolution and pass the display ID (and a window ID if you want to capture a specific window).

```c++
// Configure the screen capture width and height in config_ based on the PC's or 2-in-1 device's resolution.
config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

// Set the screen capture mode to OH_CAPTURE_SPECIFIED_WINDOW and pass a display ID.
config_.captureMode = OH_CAPTURE_SPECIFIED_WINDOW;
config_.videoInfo.videoCapInfo.displayId = 0;

// (Optional) Pass a window ID if you want to capture a specific window.
vector<int32_t> missionIds = {61}; // Window 61 is pre-selected in the picker.
config_.videoInfo.videoCapInfo.missionIDs = &missionIds[0];
config_.videoInfo.videoCapInfo.missionIDsLen = static_cast<int32_t>(missionIds.size());
```

The selection page on the PC or 2-in-1 device is also compatible with the following screen capture modes:

1. OH_CAPTURE_SPECIFIED_WINDOW mode, with multiple window IDs passed.

    The PC or 2-in-1 device does not display a picker dialog box. Instead, it displays a privacy dialog box to ask for user approval. Multiple windows can be captured at the same time.

    ```c++
    // Configure the screen capture width and height in config_ based on the PC's or 2-in-1 device's resolution.
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // Set the screen capture mode to OH_CAPTURE_SPECIFIED_WINDOW and pass a display ID.
    config_.captureMode = OH_CAPTURE_SPECIFIED_WINDOW;
    config_.videoInfo.videoCapInfo.displayId = 0;

    // Pass multiple window IDs.
    vector<int32_t> missionIds = {60, 61}; // Windows 60 and 61 are to be captured at the same time.
    config_.videoInfo.videoCapInfo.missionIDs = &missionIds[0];
    config_.videoInfo.videoCapInfo.missionIDsLen = static_cast<int32_t>(missionIds.size());
    ```

2. OH_CAPTURE_SPECIFIED_SCREEN mode.

    The PC or 2-in-1 device displays a picker dialog box, with the display (specified by the passed display ID) pre-selected.

    ```c++
    // Configure the screen capture width and height in config_ based on the PC's or 2-in-1 device's resolution.
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // Set the screen capture mode to OH_CAPTURE_SPECIFIED_SCREEN and pass a display ID.
    config_.captureMode = OH_CAPTURE_SPECIFIED_SCREEN;
    config_.videoInfo.videoCapInfo.displayId = 0;
    ```

3. OH_CAPTURE_HOME_SCREEN mode.

    The PC or 2-in-1 device does not display a picker dialog box. Instead, it displays a privacy dialog box to ask for user approval.

    In this mode, the configured **videoCapInfo.displayId** does not take effect. The default display ID of the primary screen is used.

    ```c++
    // Configure the screen capture width and height in config_ based on the PC's or 2-in-1 device's resolution.
    config_.videoInfo.videoCapInfo.videoFrameWidth = 2880;
    config_.videoInfo.videoCapInfo.videoFrameHeight = 1920;

    // Set the screen capture mode to OH_CAPTURE_HOME_SCREEN and pass a display ID.
    config_.captureMode = OH_CAPTURE_HOME_SCREEN;
    ```

## Detailed Description
This section describes how to set screen capture parameters, set callback functions, and stop the screen capture service instance involved in [How to Develop](#how-to-develop).

1. Set screen capture parameters.
    ```c++
    // Configure audio information in audioinfo.
    OH_AudioCaptureInfo micCapinfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_SOURCE_DEFAULT
    };
    OH_AudioCaptureInfo innerCapInfo = {
        .audioSampleRate = 48000,
        .audioChannels = 2,
        .audioSource = OH_ALL_PLAYBACK
    };
    OH_AudioEncInfo audioEncInfo = {
        .audioSampleRate = 48000,
        .audioCodecformat = OH_AudioCodecFormat::OH_AAC_LC
    };

    // Configure video information in videoinfo.
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
    ```

2. Set callback functions.

    Listeners are provided for error events, state changes, data obtained, and screen capture content changes involved in screen capture.

    ```c++
    // OnError(), a callback function invoked when an error occurs.
    void OnError(OH_AVScreenCapture *capture, int32_t errorCode, void *userData) {
        (void)capture;
        // Handle the event based on the error code.
        (void)errorCode;
        (void)userData;
    }

    // OnStateChange(), a callback function invoked when the state changes.
    void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
        (void)capture;
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
            // Process the screen capture start event.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_CANCELED) {
            // Process the screen capture cancellation event.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
            // Process the event indicating that screen capture is interrupted by a call.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE) {
            // Process the event indicating that the microphone is unavailable during screen capture.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
            // Process the event indicating that screen capture is interrupted by others.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER) {
            // Process the event indicating that the user mutes the microphone during screen capture.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER) {
            // Process the event indicating that the user unmutes the microphone during screen capture.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE) {
            // Process the event indicating that the application enters the privacy mode during screen capture.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE) {
            // Process the event indicating that the application exits the privacy mode during screen capture.
        }
        if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
            // Process the event indicating that screen capture is interrupted by the user.
        }
        (void)userData;
    }

    // Obtain and process the OnBufferAvailable() callback function of the original audio and video stream data.
    void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
        // Screen capture is in progress.
        if (IsCaptureStreamRunning) {
            if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
                // Video buffer.
                OH_NativeBuffer *nativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
                if (nativeBuffer != nullptr && capture != nullptr) {
                    // Obtain the buffer capacity.
                    int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                    // Obtain the buffer attribute.
                    OH_AVCodecBufferAttr info;
                    OH_AVBuffer_GetBufferAttr(buffer, &info);

                    // Obtain the native buffer configuration.
                    OH_NativeBuffer_Config config;
                    OH_NativeBuffer_GetConfig(nativeBuffer, &config);

                    // Obtain the buffer address.
                    uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                    if (buf == nullptr) {
                        return;
                    }
                    // Use the buffer data.

                    // The reference count of the native buffer is decremented by 1. When the reference count reaches 0, the buffer is released.
                    OH_NativeBuffer_Unreference(nativeBuffer);
                }
            } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
                // Buffer for internal recording.
                // Obtain the buffer attribute.
                OH_AVCodecBufferAttr info;
                OH_AVBuffer_GetBufferAttr(buffer, &info);

                // Obtain the buffer capacity.
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // Obtain the buffer address.
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // Use the buffer data.
            } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
                // Microphone buffer.
                // Obtain the buffer capacity.
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // Obtain the buffer address.
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // Use the buffer data.
            }
        }
    }

    // The callback OnDisplaySelected() is invoked to obtain the display ID.
    void OnDisplaySelected(struct OH_AVScreenCapture *capture, uint64_t displayId, void *userData) {
        (void)capture;
        (void)displayId;
        (void)userData;
    }

    // OnCaptureContentChanged(), a callback function invoked when screen capture content changes.
    void OnCaptureContentChanged(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect *area, void *userData) {
        (void)capture;
        if (event == OH_SCREEN_CAPTURE_CONTENT_HIDE) {
            // Process the event indicating that screen capture content is hidden.
        }
        if (event == OH_SCREEN_CAPTURE_CONTENT_VISIBLE) {
            // Process the event indicating that screen capture content is visible.
            // Obtain the window area information from the area parameter returned by the callback function when the screen capture content becomes visible.
        }
        if (event == OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE) {
            // Process the event indicating that screen capture content becomes unavailable, for example, the screen capture window is closed.
        }
        (void)area;
        (void)userData;
    }

    // The callback OnUserSelected() is invoked to handle user selection results on the manual confirmation UI.
    void OnUserSelected(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData) {
        (void)capture;
        (void)userData;
        int* selectType = new int;
        uint64_t* displayId = new uint64_t;
        // Obtain the selection type and display ID through the API. OH_AVScreenCapture_UserSelectionInfo* selections is valid only in the OnUserSelected callback.
        OH_AVSCREEN_CAPTURE_ErrCode errorSelectType = OH_AVScreenCapture_GetCaptureTypeSelected(selections, selectType);
        OH_AVSCREEN_CAPTURE_ErrCode errorDisplayId = OH_AVScreenCapture_GetDisplayIdSelected(selections, displayId);
    }
    ```

3. Stops the screen capture service and releases resources.
    ```c++
    void StopScreenCapture() {
        // Screen capture is in progress and a screen capture service instance exists.
        if (IsCaptureStreamRunning && capture != nullptr) {
            // Stop screen capture.
            OH_AVScreenCapture_StopScreenCapture(capture);

            // Release screen capture resources.
            OH_AVScreenCapture_Release(capture);

            // Clear other resources, such as closing the file.

            // Set IsCaptureStreamRunning to false and the screen capture service instance to a null pointer.
            IsCaptureStreamRunning = false;
            capture = nullptr;
        }
    }
    ```

## Complete Sample Code

Refer to the sample code below to implement screen capture using AVScreenCapture.

For details about how to create an OH_AVBuffer instance, see [Buffer Mode](../avcodec/video-decoding.md#buffer-mode).

For details about screen capture in surface mode, see [Surface Mode](../avcodec/video-encoding.md#surface-mode).

Currently, the buffer holds original streams, which can be encoded and saved in MP4 format for playback.

> **NOTE**
>
> The encoding format is reserved and will be implemented in later versions.

```c++
#include "napi/native_api.h"
#include <multimedia/player_framework/native_avscreen_capture.h>
#include <multimedia/player_framework/native_avscreen_capture_base.h>
#include <multimedia/player_framework/native_avscreen_capture_errors.h>
#include <multimedia/player_framework/native_avbuffer.h>
#include <native_buffer/native_buffer.h>
#include <vector>

// OnError(), a callback function invoked when an error occurs.
void OnError(OH_AVScreenCapture *capture, int32_t errorCode, void *userData) {
    (void)capture;
    // Handle the event based on the error code.
    (void)errorCode;
    (void)userData;
}

// OnStateChange(), a callback function invoked when the state changes.
void OnStateChange(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData) {
    (void)capture;
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STARTED) {
        // Process the screen capture start event.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_CANCELED) {
        // Process the screen capture cancellation event.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL) {
        // Process the event indicating that screen capture is interrupted by a call.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE) {
        // Process the event indicating that the microphone is unavailable during screen capture.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER) {
        // Process the event indicating that screen capture is interrupted by others.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER) {
        // Process the event indicating that the user mutes the microphone during screen capture.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER) {
        // Process the event indicating that the user unmutes the microphone during screen capture.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE) {
        // Process the event indicating that the application enters the privacy mode during screen capture.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE) {
        // Process the event indicating that the application exits the privacy mode during screen capture.
    }
    if (stateCode == OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES) {
        // Process the event indicating that screen capture is interrupted by the user.
    }
    (void)userData;
}

// Obtain and process the OnBufferAvailable() callback function of the original audio and video stream data.
bool IsCaptureStreamRunning = true;
void OnBufferAvailable(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData) {
    // Screen capture is in progress.
    if (IsCaptureStreamRunning) {
        if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO) {
            // Video buffer.
            OH_NativeBuffer *nativeBuffer = OH_AVBuffer_GetNativeBuffer(buffer);
            if (nativeBuffer != nullptr && capture != nullptr) {
                // Obtain the buffer capacity.
                int bufferLen = OH_AVBuffer_GetCapacity(buffer);

                // Obtain the buffer attribute.
                OH_AVCodecBufferAttr info;
                OH_AVBuffer_GetBufferAttr(buffer, &info);

                // Obtain the native buffer configuration.
                OH_NativeBuffer_Config config;
                OH_NativeBuffer_GetConfig(nativeBuffer, &config);

                // Obtain the buffer address.
                uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
                if (buf == nullptr) {
                    return;
                }
                // Use the buffer data.

                // The reference count of the native buffer is decremented by 1. When the reference count reaches 0, the buffer is released.
                OH_NativeBuffer_Unreference(nativeBuffer);
            }
        } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER) {
            // Buffer for internal recording.
            // Obtain the buffer attribute.
            OH_AVCodecBufferAttr info;
            OH_AVBuffer_GetBufferAttr(buffer, &info);

            // Obtain the buffer capacity.
            int bufferLen = OH_AVBuffer_GetCapacity(buffer);

            // Obtain the buffer address.
            uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
            if (buf == nullptr) {
                return;
            }
            // Use the buffer data.
        } else if (bufferType == OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC) {
            // Microphone buffer.
            // Obtain the buffer capacity.
            int bufferLen = OH_AVBuffer_GetCapacity(buffer);

            // Obtain the buffer address.
            uint8_t *buf = OH_AVBuffer_GetAddr(buffer);
            if (buf == nullptr) {
                return;
            }
            // Use the buffer data.
        }
    }
}

// The callback OnDisplaySelected() is invoked to obtain the display ID.
void OnDisplaySelected(struct OH_AVScreenCapture *capture, uint64_t displayId, void *userData) {
    (void)capture;
    (void)displayId;
    (void)userData;
}

// OnCaptureContentChanged(), a callback function invoked when screen capture content changes.
void OnCaptureContentChanged(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect *area, void *userData) {
    (void)capture;
    if (event == OH_SCREEN_CAPTURE_CONTENT_HIDE) {
        // Process the event indicating that screen capture content is hidden.
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_VISIBLE) {
        // Process the event indicating that screen capture content is visible.
        // Obtain the window area information from the area parameter returned by the callback function when the screen capture content becomes visible.
    }
    if (event == OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE) {
        // Process the event indicating that screen capture content becomes unavailable, for example, the screen capture window is closed.
    }
    (void)area;
    (void)userData;
}

// The callback OnUserSelected() is invoked to handle user selection results on the manual confirmation UI.
void OnUserSelected(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData) {
    (void)capture;
    (void)userData;
    int* selectType = new int;
    uint64_t* displayId = new uint64_t;
    // Obtain the selection type and display ID through the API. OH_AVScreenCapture_UserSelectionInfo* selections is valid only in the OnUserSelected callback.
    OH_AVSCREEN_CAPTURE_ErrCode errorSelectType = OH_AVScreenCapture_GetCaptureTypeSelected(selections, selectType);
    OH_AVSCREEN_CAPTURE_ErrCode errorDisplayId = OH_AVScreenCapture_GetDisplayIdSelected(selections, displayId);
}

struct OH_AVScreenCapture *capture;
// Call StartScreenCapture to start screen capture.
static napi_value StartScreenCapture(napi_env env, napi_callback_info info) {
    // Obtain the window ID number[] from the JS side.
    std::vector<int> windowIdsExclude = {};
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    // Obtain parameters.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the length of the array.
    uint32_t array_length;
    napi_get_array_length(env, args[0], &array_length);
    // Read the initial window ID.
    for (uint32_t i = 0; i < array_length; i++) {
        napi_value temp;
        napi_get_element(env, args[0], i, &temp);
        uint32_t tempValue;
        napi_get_value_uint32(env, temp, &tempValue);
        windowIdsExclude.push_back(tempValue);
     }
    // Instantiate AVScreenCapture.
    capture = OH_AVScreenCapture_Create();
    
    // Set the callbacks.
    OH_AVScreenCapture_SetErrorCallback(capture, OnError, nullptr);
    OH_AVScreenCapture_SetStateCallback(capture, OnStateChange, nullptr);
    OH_AVScreenCapture_SetDataCallback(capture, OnBufferAvailable, nullptr);
    // (Optional) Set a callback to obtain the display ID. This operation must be performed before screen capture starts.
    OH_AVScreenCapture_SetDisplayCallback(capture, OnDisplaySelected, nullptr);
    // (Optional) Set a callback to handle user selection results on the manual confirmation UI. This operation must be performed before screen capture starts.
    OH_AVScreenCapture_SetSelectionCallback(capture, OnUserSelected, nullptr);

    // (Optional) Set a callback for screen capture content changes.
    OH_Rect* area = nullptr;
    OH_AVScreenCapture_SetCaptureContentChangedCallback(capture, OnCaptureContentChanged, area);

    // (Optional) Set the privacy window masking mode.
    int value = 0;
    OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
    OH_AVScreenCapture_StrategyForPrivacyMaskMode(strategy, value);
	// (Optional) Set the automatic rotation following configuration.
    OH_AVScreenCapture_StrategyForCanvasFollowRotation(strategy, true);
    OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);

    // (Optional) Set the cursor display switch. This operation must be performed before screen capture starts.
    OH_AVScreenCapture_ShowCursor(capture, false);
    // (Optional) Configure screen capture rotation. This API should be called when the device screen rotation is detected. If the device screen does not rotate, the API call is invalid.
    OH_AVScreenCapture_SetCanvasRotation(capture, true);
    // Optional. Filter audio.
    OH_AVScreenCapture_ContentFilter *contentFilter= OH_AVScreenCapture_CreateContentFilter();
    // Add a filter announcement.
    OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
    // Exclude the specified window ID.
    OH_AVScreenCapture_ContentFilter_AddWindowContent(contentFilter, &windowIdsExclude[0],
                                                      static_cast<int32_t>(windowIdsExclude.size()));

    OH_AVScreenCapture_ExcludeContent(capture, contentFilter);

    // Initialize the screen capture parameters and pass in an OH_AVScreenRecorderConfig struct.
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

    // Optional (supported since API version 20) Set the coordinates and size of the area to capture. For example, the following creates a rectangle area starting at (0, 0) with a length of 100 and a width of 100. This API can also be set after screen capture starts.
    OH_Rect* region = new OH_Rect;
    region->x = 0;
    region->y = 0;
    region->width = 100;
    region->height = 100;
    uint64_t regionDisplayId = 0; // ID of the display where the rectangle area is located.
    OH_AVScreenCapture_SetCaptureArea(capture, regionDisplayId, region);

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

    // (Optional) Transfer the IDs of the subwindows and main windows to skip from screen capture. Transfer an empty array to cancel the windows that have been configured for exemption.
	// std::vector<int> windowIdsSkipPrivacy = {};
    // OH_AVScreenCapture_SkipPrivacyMode(capture, &windowIdsSkipPrivacy[0],
    //     static_cast<int32_t>(windowIdsSkipPrivacy.size()));

    // (Optional) Adjust the screen capture resolution after the capture starts. For details about the resolution range, see the AVCodec encoding and decoding capabilities.
    // OH_AVScreenCapture_ResizeCanvas(capture, 768, 1280);

    // (Optional) Set the maximum frame rate for screen capture. Call the function after screen capture starts.
    // OH_AVScreenCapture_SetMaxVideoFrameRate(capture, 20);

    // Call StopScreenCapture to stop screen capture.
    
    // Return the call result. In the example, only a random number is returned.
    napi_value sum;
    napi_create_double(env, 5, &sum);

    return sum;
}

// Call StopScreenCapture to stop screen capture.
static napi_value StopScreenCapture(napi_env env, napi_callback_info info) {
    if (IsCaptureStreamRunning && capture != nullptr) {
        // Stop screen capture.
        OH_AVScreenCapture_StopScreenCapture(capture);

        // Release screen capture resources.
        OH_AVScreenCapture_Release(capture);

        // Clear other resources, such as closing the file.

        // Set IsCaptureStreamRunning to false and the screen capture service instance to a null pointer.
        IsCaptureStreamRunning = false;
        capture = nullptr;
    }
    // Return the call result. In the example, only a random number is returned.
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
