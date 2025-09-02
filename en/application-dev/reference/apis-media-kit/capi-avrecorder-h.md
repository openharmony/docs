# avrecorder.h

## Overview

The file declares the AVRecorder APIs. Applications can use the APIs to record media data.

**File to include**: <multimedia/player_framework/avrecorder.h>

**Library**: libavrecorder.so

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_AVRecorder *OH_AVRecorder_Create(void)](#oh_avrecorder_create) | Creates an AVRecorder instance. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.|
| [OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)](#oh_avrecorder_prepare) | Sets AVRecorder parameters to prepare for recording. This function must be called after [OH_AVRecorder_Create](#oh_avrecorder_create) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PREPARED state.<br>To record only audio, you do not need to set video parameters. Similarly, to record only video, you do not need to set audio parameters.|
| [OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)](#oh_avrecorder_getavrecorderconfig) | Obtains the AVRecorder configuration. This function must be called after the recording preparation is complete. **config** must be set to nullptr. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.|
| [OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)](#oh_avrecorder_getinputsurface) | Obtains an input surface. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.<br>The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.|
| [OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)](#oh_avrecorder_updaterotation) | Updates the video rotation angle. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| [OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)](#oh_avrecorder_start) | Starts recording. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.|
| [OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)](#oh_avrecorder_pause) | Pauses recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered and the AVRecorder is in the AVRECORDER_STARTED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PAUSED state.<br>Then, you can call [OH_AVRecorder_Resume](#oh_avrecorder_resume) to resume recording, and the AVRecorder transitions the AVRECORDER_STARTED state again.|
| [OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)](#oh_avrecorder_resume) | Resumes recording. This function must be called after [OH_AVRecorder_Pause](#oh_avrecorder_pause) is successfully triggered and the AVRecorder is in the AVRECORDER_PAUSED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.|
| [OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)](#oh_avrecorder_stop) | Stops recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STOPPED state.<br>For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording.<br>For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.|
| [OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)](#oh_avrecorder_reset) | Resets the recording state. This function must be called when the AVRecorder is not in the AVRECORDER_RELEASED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.<br>For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording.<br>For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.|
| [OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)](#oh_avrecorder_release) | Releases recording resources. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_RELEASED state.<br>The recorder memory will be released. The application layer must explicitly set the recorder to nullptr to avoid access to wild pointers. After the resources are released, you can no longer perform any operation on the OH_AVRecorder instance.|
| [OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info,int32_t *length)](#oh_avrecorder_getavailableencoder) | Obtains the available encoders and encoder information of the AVRecorder.<br>**info** must be set to nullptr. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.|
| [OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)](#oh_avrecorder_setstatecallback) | Sets a state callback so that the application can respond to state change events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| [OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)](#oh_avrecorder_seterrorcallback) | Sets an error callback so that the application can respond to error events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| [OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)](#oh_avrecorder_seturicallback) | Sets a URI callback so that the application can respond to URI events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.|
| [OH_AVErrCode OH_AVRecorder_SetWillMuteWhenInterrupted(OH_AVRecorder *recorder, bool muteWhenInterrupted)](#oh_avrecorder_setwillmutewheninterrupted) | Sets whether to enable the mute interruption mode.|

## Function Description

### OH_AVRecorder_Create()

```
OH_AVRecorder *OH_AVRecorder_Create(void)
```

**Description**

Creates an AVRecorder instance. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) | Pointer to the OH_AVRecorder instance created if the operation is successful; nullptr otherwise.|

### OH_AVRecorder_Prepare()

```
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)
```

**Description**

Sets AVRecorder parameters to prepare for recording. This function must be called after [OH_AVRecorder_Create](#oh_avrecorder_create) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PREPARED state.

To record only audio, you do not need to set video parameters. Similarly, to record only video, you do not need to set audio parameters.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) *config | Pointer to the OH_AVRecorder_Config instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or the preparation fails.|

### OH_AVRecorder_GetAVRecorderConfig()

```
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)
```

**Description**

Obtains the AVRecorder configuration. This function must be called after the recording preparation is complete.

**config** must be set to nullptr. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) **config | Pointer to the OH_AVRecorder_Config instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or **config** is not nullptr.<br>**AV_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.|

### OH_AVRecorder_GetInputSurface()

```
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)
```

**Description**

Obtains an input surface. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) **window | Pointer to the OHNativeWindow instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr.|

### OH_AVRecorder_UpdateRotation()

```
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)
```

**Description**

Updates the video rotation angle. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| int32_t rotation | Video rotation angle. The value must be an integer in the range [0, 90, 180, 270].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr, **rotation** is invalid, or the update operation fails.|

### OH_AVRecorder_Start()

```
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)
```

**Description**

Starts recording. This function must be called after [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to start.|

### OH_AVRecorder_Pause()

```
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)
```

**Description**

Pauses recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered and the AVRecorder is in the AVRECORDER_STARTED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PAUSED state.

Then, you can call [OH_AVRecorder_Resume](#oh_avrecorder_resume) to resume recording, and the AVRecorder transitions the AVRECORDER_STARTED state again.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to pause.|

### OH_AVRecorder_Resume()

```
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)
```

**Description**

Resumes recording. This function must be called after [OH_AVRecorder_Pause](#oh_avrecorder_pause) is successfully triggered and the AVRecorder is in the AVRECORDER_PAUSED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to resume.|

### OH_AVRecorder_Stop()

```
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)
```

**Description**

Stops recording. This function must be called after [OH_AVRecorder_Start](#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STOPPED state.

For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording.

For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to stop.|

### OH_AVRecorder_Reset()

```
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)
```

**Description**

Resets the recording state. This function must be called when the AVRecorder is not in the AVRECORDER_RELEASED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.

For audio-only recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) again for re-recording.

For video-only recording or audio and video recording, you can call [OH_AVRecorder_Prepare](#oh_avrecorder_prepare) and [OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to reset.|

### OH_AVRecorder_Release()

```
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)
```

**Description**

Releases recording resources. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_RELEASED state.

The recorder memory will be released. The application layer must explicitly set the recorder to nullptr to avoid access to wild pointers. After the resources are released, you can no longer perform any operation on the OH_AVRecorder instance.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr or recording fails to release.|

### OH_AVRecorder_GetAvailableEncoder()

```
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info,int32_t *length)
```

**Description**

Obtains the available encoders and encoder information of the AVRecorder.

**info** must be set to nullptr. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_EncoderInfo](capi-avrecorder-oh-avrecorder-encoderinfo.md) **info | Pointer to the OH_AVRecorder_EncoderInfo instance.|
| int32_t *length | Pointer to the number of available encoders.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** is nullptr.<br>**AV_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.|

### OH_AVRecorder_SetStateCallback()

```
OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)
```

**Description**

Sets a state callback so that the application can respond to state change events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_OnStateChange](capi-avrecorder-base-h.md#oh_avrecorder_onstatechange) callback | Status callback function.|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is nullptr.|

### OH_AVRecorder_SetErrorCallback()

```
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)
```

**Description**

Sets an error callback so that the application can respond to error events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_OnError](capi-avrecorder-base-h.md#oh_avrecorder_onerror) callback | Error callback function.|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is nullptr.|

### OH_AVRecorder_SetUriCallback()

```
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)
```

**Description**

Sets a URI callback so that the application can respond to URI events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](#oh_avrecorder_start) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| [OH_AVRecorder_OnUri](capi-avrecorder-base-h.md#oh_avrecorder_onuri) callback | Callback used to return the result.|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is nullptr.|

### OH_AVRecorder_SetWillMuteWhenInterrupted()

```
OH_AVErrCode OH_AVRecorder_SetWillMuteWhenInterrupted(OH_AVRecorder *recorder, bool muteWhenInterrupted)
```

**Description**

Sets whether to enable the mute interruption mode.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | Pointer to the OH_AVRecorder instance.|
| bool muteWhenInterrupted | Whether to mute the audio stream when an audio interruption occurs. The value **true** means to mute the stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **recorder** or **callback** is nullptr.<br>**AV_ERR_INVALID_STATE**: The function is called in an invalid state. It must be in the prepared state.|
<!--no_check-->