# avrecorder.h


## Overview

The **avrecorder.h** file declares the AVRecorder APIs. Applications can use the APIs to record media data.

**Library**: libavrecorder.so

**File to include**: &lt;multimedia/player_framework/avrecorder.h&gt;

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \* [OH_AVRecorder_Create](_a_v_recorder.md#oh_avrecorder_create) (void) | Creates an AVRecorder instance. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*config) | Sets AVRecorder parameters to prepare for recording. This function must be called after [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PREPARED state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_GetAVRecorderConfig](_a_v_recorder.md#oh_avrecorder_getavrecorderconfig) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_Config](_o_h___a_v_recorder___config.md) \*\*config) | Obtains the AVRecorder configuration. This function must be called after the recording preparation is complete. **config** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_GetInputSurface](_a_v_recorder.md#oh_avrecorder_getinputsurface) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OHNativeWindow](../apis-arkgraphics2d/_native_window.md#ohnativewindow) \*\*window) | Obtains an input surface. This function must be called after [OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is called.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_UpdateRotation](_a_v_recorder.md#oh_avrecorder_updaterotation) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, int32_t rotation) | Updates the video rotation angle. This function must be called after [OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare) is successfully triggered and before [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is called.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Starts recording. This function must be called after [OH_AVRecorder_Prepare](_a_v_recorder.md#oh_avrecorder_prepare) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Pause](_a_v_recorder.md#oh_avrecorder_pause) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Pauses recording. This function must be called after [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is successfully triggered and the AVRecorder is in the AVRECORDER_STARTED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_PAUSED state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Resume](_a_v_recorder.md#oh_avrecorder_resume) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Resumes recording. This function must be called after [OH_AVRecorder_Pause](_a_v_recorder.md#oh_avrecorder_pause) is successfully triggered and the AVRecorder is in the AVRECORDER_PAUSED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STARTED state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Stop](_a_v_recorder.md#oh_avrecorder_stop) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Stops recording. This function must be called after [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is successfully triggered. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_STOPPED state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Reset](_a_v_recorder.md#oh_avrecorder_reset) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Resets the recording state. This function must be called when the AVRecorder is not in the AVRECORDER_RELEASED state. After this function is successfully called, the AVRecorder transitions to the AVRECORDER_IDLE state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_Release](_a_v_recorder.md#oh_avrecorder_release) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder) | Releases recording resources. After this API is successfully called, the AVRecorder transitions to the AVRECORDER_RELEASED state. The recorder memory will be released. The application layer must explicitly set the recorder to a null pointer to avoid access to wild pointers.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_GetAvailableEncoder](_a_v_recorder.md#oh_avrecorder_getavailableencoder) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_EncoderInfo](_o_h___a_v_recorder___encoder_info.md) \*\*info, int32_t \*length) | Obtains the available encoders and encoder information of the AVRecorder. **info** must be set to a null pointer. The framework layer allocates and releases the memory in a unified manner to avoid issues with memory management, such as leaks or double freeing.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_SetStateCallback](_a_v_recorder.md#oh_avrecorder_setstatecallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnStateChange](_a_v_recorder.md#oh_avrecorder_onstatechange) callback, void \*userData) | Sets a state callback so that the application can respond to state change events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is called.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_SetErrorCallback](_a_v_recorder.md#oh_avrecorder_seterrorcallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnError](_a_v_recorder.md#oh_avrecorder_onerror) callback, void \*userData) | Sets an error callback so that the application can respond to error events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is called.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVRecorder_SetUriCallback](_a_v_recorder.md#oh_avrecorder_seturicallback) ([OH_AVRecorder](_a_v_recorder.md#oh_avrecorder) \*recorder, [OH_AVRecorder_OnUri](_a_v_recorder.md#oh_avrecorder_onuri) callback, void \*userData) | Sets a URI callback so that the application can respond to URI events generated by the AVRecorder. This function must be called before [OH_AVRecorder_Start](_a_v_recorder.md#oh_avrecorder_start) is called.| 
