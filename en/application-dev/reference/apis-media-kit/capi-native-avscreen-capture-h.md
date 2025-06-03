# native_avscreen_capture.h

## Overview

The **native_avscreen_capture.h** file declares the APIs used to create an **OH_AVScreenCapture** instance.

**Library**: libnative_avscreen_capture.so

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)](#oh_avscreencapture_create) | Creates an **OH_AVScreenCapture** instance.<br>You can release the instance by calling [OH_AVScreenCapture_Release](#oh_avscreencapture_release).|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)](#oh_avscreencapture_init) | Initializes parameters related to an [OH_AVScreenCapture](capi-avscreencapture.md) instance, including audio sampling parameters for external capture using microphones (optional), audio sampling parameters for internal capture, and video resolution parameters.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreencapture) | Starts screen capture and collects original streams.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreencapture) | Stops screen capture. This function is used in pair with [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture). After calling this function, the application stops screen capture or screen share and releases the microphone.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreenrecording) | Starts screen recording, with recordings saved in files.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreenrecording) | Stops screen recording. This function is used in pair with [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording).|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)](#oh_avscreencapture_acquireaudiobuffer) | Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.|
| [OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture, int32_t *fence, int64_t *timestamp, struct OH_Rect *region)](#oh_avscreencapture_acquirevideobuffer) | Obtains a video buffer. The application can call this function to obtain information such as the video buffer and timestamp.<br>When a video buffer is no longer needed, call **OH_AVScreenCapture_ReleaseVideoBuffer** to release it.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)](#oh_avscreencapture_releaseaudiobuffer) | Releases an audio buffer. When an audio buffer is no longer needed, call this function to release it.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_releasevideobuffer) | Releases a video buffer. When a video buffer is no longer needed, call this function to release it.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)](#oh_avscreencapture_setcallback) | Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_release) | Releases an **OH_AVScreenCapture** instance. This function is used in pair with [OH_AVScreenCapture_Create](#oh_avscreencapture_create).|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)](#oh_avscreencapture_setmicrophoneenabled) | Enables or disables the microphone.<br>When **isMicrophone** is set to **true**, the microphone is enabled, and the original PCM data of the microphone can be obtained by calling **OH_AVScreenCapture_StartScreenCapture** and **OH_AVScreenCapture_AcquireAudioBuffer**. When **isMicrophone** is set to **false**, the obtained audio data is silent data.<br>By default, the microphone is enabled.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)](#oh_avscreencapture_setstatecallback) | Sets a state change callback. This function must be called before screen capture starts.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)](#oh_avscreencapture_setdatacallback) | Sets a data processing callback. This function must be called before screen capture starts.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)](#oh_avscreencapture_seterrorcallback) | Sets an error processing callback. This function must be called before screen capture starts.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,OHNativeWindow *window)](#oh_avscreencapture_startscreencapturewithsurface) | Starts screen capture in surface mode.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)](#oh_avscreencapture_setcanvasrotation) | Sets canvas rotation for screen capture.<br>You can call this function to set whether to rotate the recorded screen data. When **canvasRotation** is set to **true**, screen capture rotation is enabled and the recorded screen data remains positive. The default value is **false**.|
| [struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void)](#oh_avscreencapture_createcontentfilter) | Creates a content filter.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_releasecontentfilter) | Releases a content filter.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content)](#oh_avscreencapture_contentfilter_addaudiocontent) | Adds audio content to a content filter.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_excludecontent) | Sets a content filter for an **OH_AVScreenCapture** instance.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_contentfilter_addwindowcontent) | Adds a list of window IDs to a **ContentFilter** instance.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)](#oh_avscreencapture_resizecanvas) | Adjusts the screen resolution.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_skipprivacymode) | Exempts privacy windows during screen capture.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)](#oh_avscreencapture_setmaxvideoframerate) | Sets the maximum frame rate for screen capture.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)](#oh_avscreencapture_showcursor) | Sets whether to show the cursor.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnDisplaySelected callback, void *userData)](#oh_avscreencapture_setdisplaycallback) | Sets a callback function for obtaining the display ID.|
| [OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)](#oh_avscreencapture_createcapturestrategy) | Creates a screen capture strategy.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)](#oh_avscreencapture_releasecapturestrategy) | Releases a screen capture strategy.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)](#oh_avscreencapture_setcapturestrategy) | Sets a screen capture strategy for an **OH_AVScreenCapture** instance.<br>This function must be called before screen capture starts.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)](#oh_avscreencapture_strategyforkeepcaptureduringcall) | Sets whether to keep screen capture during a cellular call.|
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData)](#oh_avscreencapture_setcapturecontentchangedcallback) | Sets the callback for screen capture content changes. This function must be called before screen capture starts.|

## Function Description

### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)
```

**Description**

Creates an **OH_AVScreenCapture** instance.

You can release the instance by calling [OH_AVScreenCapture_Release](#oh_avscreencapture_release).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Returns**

| Type| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) | Pointer to the **OH_AVScreenCapture** instance.|

### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)
```

**Description**

Initializes parameters related to an [OH_AVScreenCapture](capi-avscreencapture.md) instance, including audio sampling parameters for external capture using microphones (optional), audio sampling parameters for internal capture, and video resolution parameters.

In the scenario where screen recording files are stored, the application must ensure that the video encoding parameters, video sampling parameters, audio encoding parameters, audio sampling parameters for internal capture, and audio sampling parameters for external capture using microphones (optional) are valid.

In the scenario where screen capture streams are generated, the application must ensure that either audio sampling parameters for internal capture or video sampling parameters are valid, or both are valid, and audio sampling parameters for external capture using microphones are valid (optional).

The members of the struct variables are not initialized during initialization. Therefore, the application must correctly set the parameters based on the use scenario. You are advised to set all memory bytes of the OH_AVScreenCaptureConfig struct variables to **0**, and then set valid parameters based on the screen capture scenario.

If both **audioSampleRate** and **audioChannels** in the [OH_AudioCaptureInfo](capi-oh-audiocaptureinfo.md) struct are **0**, the **OH_AVScreenCapture** instance ignores the corresponding audio parameters and does not collect the audio data.

If both **videoFrameWidth** and **videoFrameHeight** in the [OH_VideoCaptureInfo](capi-oh-videocaptureinfo.md) struct are **0**, the **OH_AVScreenCapture** instance ignores the corresponding video parameters and does not collect the screen data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCaptureConfig](capi-oh-avscreencaptureconfig.md) config | Parameters related to screen capture initialization.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The configuration fails to be initialized.|

### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)
```

**Description**

Starts screen capture and collects original streams.

After this function is called, the callback [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) can be used to check whether streams are generated, and the callback [OH_AVScreenCapture_OnStateChange](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onstatechange) can be used to check the startup status.

The application can obtain the original streams of screen capture by calling [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) and [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen capture fails to start.|

### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)
```

**Description**

Stops screen capture. This function is used in pair with [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture). After calling this function, the application stops screen capture or screen share and releases the microphone.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Screen capture fails to stop.|

### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)
```

**Description**

Starts screen recording, with recordings saved in files.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen capture fails to start.|

### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)
```

**Description**

Stops screen recording. This function is used in pair with [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Screen capture fails to stop.|

### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)
```

**Description**

Obtains an audio buffer. When calling this function, the application must allocate the memory of the corresponding struct size to the audio buffer.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AudioBuffer](capi-oh-audiobuffer.md) **audiobuffer | Pointer to the struct for storing the audio buffer. This struct is used to obtain the information about the audio buffer and the timestamp of the buffer.|
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **audiobuffer** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The audio buffer fails to be allocated due to insufficient memory.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or the audio buffer fails to be obtained.|

### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture, int32_t *fence, int64_t *timestamp, struct OH_Rect *region)
```

**Description**

Obtains a video buffer. The application can call this function to obtain information such as the video buffer and timestamp.

When a video buffer is no longer needed, call **OH_AVScreenCapture_ReleaseVideoBuffer** to release it.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10



**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| int32_t *fence | Pointer to parameters for synchronization display.|
| int64_t *timestamp | Pointer to the timestamp of the video frame.|
| struct [OH_Rect](capi-oh-rect.md) *region | Pointer to the coordinates related to video display.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) | **OH_NativeBuffer** object if the operation is successful. The application can call the APIs provided by the **OH_NativeBuffer** object to obtain information such as the video buffer and resolution.|

### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)
```

**Description**

Releases an audio buffer. When an audio buffer is no longer needed, call this function to release it.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | Type of the audio buffer, which is used to distinguish external streams recorded by the microphone from internal streams played by the system.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback has been set or the audio buffer fails to be released.|

### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)
```

**Description**

Releases a video buffer. When a video buffer is no longer needed, call this function to release it.

From API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback has been set or the video buffer fails to be released.|

### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)
```

**Description**

Sets a callback to listen for available video buffers and audio buffers and errors that occur during the function calling.

From API version 12, you are advised to use [OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback) and [OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback) instead.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| struct [OH_AVScreenCaptureCallback](capi-oh-avscreencapturecallback.md) callback | OH_AVScreenCaptureCallback struct, which stores related callback function pointers.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The callback fails to be set.|

### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)
```

**Description**

Releases an **OH_AVScreenCapture** instance. This function is used in pair with [OH_AVScreenCapture_Create](#oh_avscreencapture_create).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The **OH_AVScreenCapture** instance fails to be released.|

### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)
```

**Description**

Enables or disables the microphone.

When **isMicrophone** is set to **true**, the microphone is enabled, and the original PCM data of the microphone can be obtained by calling [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) and [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer). When **isMicrophone** is set to **false**, the obtained audio data is silent data.

By default, the microphone is enabled.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| bool isMicrophone | Whether to enable the microphone.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The microphone fails to be enabled or disabled.|

### OH_AVScreenCapture_SetStateCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)
```

**Description**

Sets a state change callback. This function must be called before screen capture starts.

The callback is triggered when the state changes during the running of an **OH_AVScreenCapture** instance.

A privacy dialog box is displayed to ask for user consent before screen capture starts. After a successful call to this function, the following scenarios are possible:

1. If the user agrees, the screen capture startup process starts. If screen capture starts successfully, the state change callback is triggered to report the [OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_STARTED status to notify the application of the startup success, with a screen capture notification displayed. If screen capture fails to start, the state change callback is triggered to report the failure information (for example, [OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE if the microphone is unavailable), or the error processing callback [OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror) is triggered to report the error information.

2. If the user disagrees, the screen capture startup process stops. The state change callback is triggered to report the [OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_CANCELED status to notify the application of the startup failure due to user rejection.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_OnStateChange](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onstatechange) callback | State change callback.|
| void *userData | Pointer to the user-defined data. The data is returned as an input parameter when the state change callback is triggered.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The state callback fails to be set.|

### OH_AVScreenCapture_SetDataCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)
```

**Description**

Sets a data processing callback. This function must be called before screen capture starts.

The callback is triggered when an audio buffer or a video buffer becomes available during the running of an **OH_AVScreenCapture** instance.

The application needs to process microphone audio, internal audio, and video data based on the data type in the callback. After the callback is triggered, the buffer is no longer valid.

A successful call to this function leads to the following scenarios:

1. The callbacks [OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable) and [OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable) set by calling [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) will no longer be triggered, even when an audio buffer or a video buffer becomes available.

2. A failure message is returned for a call to any of the following functions: [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer), [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer), [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer), and [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer).

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) callback | Data processing callback.|
| void *userData | Pointer to the user-defined data. The data is returned as an input parameter when the data processing callback is triggered.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The data callback fails to be set.|

### OH_AVScreenCapture_SetErrorCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)
```

**Description**

Sets an error processing callback. This function must be called before screen capture starts.

The callback is triggered when an error occurs during the running of an **OH_AVScreenCapture** instance.

After a successful call to this function, the callback [OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror) set by calling [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) will no longer be triggered, even when an error occurs in the **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror) callback | Error processing callback.|
| void *userData | Pointer to the user-defined data. The data is returned as an input parameter when the error processing callback is triggered.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The error callback fails to be set.|

### OH_AVScreenCapture_StartScreenCaptureWithSurface()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,OHNativeWindow *window)
```

**Description**

Starts screen capture in surface mode.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow.md) *window | Pointer to the **OHNativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture**, input parameter **window**, or **windowSurface** pointed to by **window** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The privacy permission fails to be enabled or screen capture with a surface fails to start.|

### OH_AVScreenCapture_SetCanvasRotation()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)
```

**Description**

Sets canvas rotation for screen capture.

You can call this function to set whether to rotate the recorded screen data. When **canvasRotation** is set to **true**, screen capture rotation is enabled and the recorded screen data remains positive.

The default value is **false**.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| bool canvasRotation | Whether to enable screen data rotation.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. Canvas rotation fails to be set for screen capture.|

### OH_AVScreenCapture_CreateContentFilter()

```
struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void)
```

**Description**

Creates a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| struct [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) | **OH_AVScreenCapture_ContentFilter** instance if the operation is successful; a null pointer otherwise.|

### OH_AVScreenCapture_ReleaseContentFilter()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter)
```

**Description**

Releases a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) *filter | Pointer to the **OH_AVScreenCapture_ContentFilter** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **filter** is a null pointer.|

### OH_AVScreenCapture_ContentFilter_AddAudioContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content)
```

**Description**

Adds audio content to a content filter.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) *filter | Pointer to the **OH_AVScreenCapture_ContentFilter** instance.|
| [OH_AVScreenCaptureFilterableAudioContent](capi-native-avscreen-capture-base-h.md#oh_avscreencapturefilterableaudiocontent) content | Pointer to the **OH_AVScreenCaptureFilterableAudioContent** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **filter** is a null pointer or the input parameter **content** is invalid.|

### OH_AVScreenCapture_ExcludeContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,struct OH_AVScreenCapture_ContentFilter *filter)
```

**Description**

Sets a content filter for an **OH_AVScreenCapture** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| struct [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) *filter | Pointer to the **OH_AVScreenCapture_ContentFilter** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **filter** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_UNSUPPORT**: The operation is not supported. For streams, the AudioCapturer API must be called for the operation to take effect during the start.<br>         For captured files, the Recorder API must be called for the operation to take effect during the start.|

### OH_AVScreenCapture_ContentFilter_AddWindowContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)
```

**Description**

Adds a list of window IDs to a **ContentFilter** instance.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) *filter | Pointer to the **OH_AVScreenCapture_ContentFilter** instance.|
| int32_t *windowIDs | Pointer to the window IDs.|
| int32_t windowCount | Length of the window ID list.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK** if the operation is successful; a specific error code if the operation fails.|

### OH_AVScreenCapture_ResizeCanvas()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)
```

**Description**

Adjusts the screen resolution.

This function is used to set the resolution of screen capture data. **width** indicates the screen width and **height** indicates the screen height.

Currently, this function supports only the scenario of capturing streams, but not the scenario of storing captured files. In addition, the caller of this function and the video data consumer must ensure that they support resolution changes of the received video data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| int32_t width | Width of the screen to capture.|
| int32_t height | Height of the screen to capture.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_AVScreenCapture_SkipPrivacyMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)
```

**Description**

Exempts privacy windows during screen capture.

Currently, all the IDs of the subwindows and main windows to skip must be passed in.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| int32_t *windowIDs | Pointer to the IDs of the privacy windows to skip.|
| int32_t windowCount | Length of the privacy window ID list.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_AVScreenCapture_SetMaxVideoFrameRate()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)
```

**Description**

Sets the maximum frame rate for screen capture.

This function must be called after screen capture starts.

 

The maximum frame rate that can be configured is subject to the device's limitations and is ultimately governed by the capabilities of the underlying system.

Although there is no limit on the maximum value of the input parameter, the maximum frame rate supported is 60 FPS. If the input parameter value exceeds 60 FPS, 60 FPS is used. If the value does not exceed the upper limit, the passed value is used.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| int32_t frameRate | Maximum frame rate for screen capture.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer, or the input parameter **frameRate** is not supported.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.|

### OH_AVScreenCapture_ShowCursor()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)
```

**Description**

Sets whether to show the cursor.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| bool showCursor | Whether to show the cursor.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | Result code of the function.<br>         **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The cursor setting fails.|

### OH_AVScreenCapture_SetDisplayCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnDisplaySelected callback, void *userData)
```

**Description**

Sets a callback function for obtaining the display ID.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_OnDisplaySelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_ondisplayselected) callback | Callback function for returning the display ID.|
| void *userData | Pointer to the user-defined data. The data is returned as an input parameter when the state change callback is triggered.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_STATE**: The callback must be called before the **start** function.|

### OH_AVScreenCapture_CreateCaptureStrategy()

```
OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)
```

**Description**

Creates a screen capture strategy.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md)* | **OH_AVScreenCapture_CaptureStrategy** instance if the operation is successful; a null pointer otherwise.|

### OH_AVScreenCapture_ReleaseCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)
```

**Description**

Releases a screen capture strategy.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md)* strategy | Pointer to the **OH_AVScreenCapture_CaptureStrategy** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **strategy** is a null pointer.|

### OH_AVScreenCapture_SetCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)
```

**Description**

Sets a screen capture strategy for an **OH_AVScreenCapture** instance.

This function must be called before screen capture starts.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md)* strategy | Pointer to the **OH_AVScreenCapture_CaptureStrategy** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **strategy** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_UNSUPPORT**: The operation is not supported. For example, the function is called after screen capture.|

### OH_AVScreenCapture_StrategyForKeepCaptureDuringCall()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)
```

**Description**

Sets whether to keep screen capture during a cellular call.

When **value** is set to **true** and screen capture is active during a cellular call, for privacy reasons, the voices of both parties (local microphone and remote speaker) are not recorded. Other system sounds are recorded normally. After the call ends, the screen capture framework resumes microphone recording. If the screen capture application is running in the background when the call ends, microphone recording fails to start because the audio module does not allow background applications to activate microphone recording.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md) strategy | Pointer to the **OH_AVScreenCapture_CaptureStrategy** instance.|
| bool value | Whether to keep screen capture during a cellular call.<br>The value **true** means to keep screen capture during a cellular call, and **false** means the opposite. The default value is **false**.<br>The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **strategy** is a null pointer.|

### OH_AVScreenCapture_SetCaptureContentChangedCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData)
```

**Description**

Sets the callback for screen capture content changes. This function must be called before screen capture starts.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture |Pointer to the **OH_AVScreenCapture** instance.|
| [OH_AVScreenCapture_OnCaptureContentChanged](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_oncapturecontentchanged) callback | Pointer to the callback method instance for the screen capture content change event.|
| void *userData | Pointer to the user-defined data. The data is returned as an input parameter when the error processing callback is triggered.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | **AV_SCREEN_CAPTURE_ERR_OK**: The operation is successful.<br>         **AV_SCREEN_CAPTURE_ERR_INVALID_VAL**: The input parameter **capture** or **callback** is a null pointer.<br>         **AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The screen capture callback fails to be set.|

 <!--no_check--> 