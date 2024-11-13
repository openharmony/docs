# preview_output.h


## Overview

The **preview_output.h** file declares the preview output concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/preview_output.h&gt; 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [PreviewOutput_Callbacks](_preview_output___callbacks.md) | Describes the callbacks related to preview output.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) | Defines a struct for the preview output object.| 
| typedef void(\* [OH_PreviewOutput_OnFrameStart](_o_h___camera.md#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.| 
| typedef void(\* [OH_PreviewOutput_OnFrameEnd](_o_h___camera.md#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, int32_t frameCount) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame end events.| 
| typedef void(\* [OH_PreviewOutput_OnError](_o_h___camera.md#oh_previewoutput_onerror)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.| 
| typedef struct [PreviewOutput_Callbacks](_preview_output___callbacks.md) [PreviewOutput_Callbacks](_o_h___camera.md#previewoutput_callbacks) | Defines a struct for the callbacks related to preview output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_RegisterCallback](_o_h___camera.md#oh_previewoutput_registercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Registers a callback to listen for preview output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_UnregisterCallback](_o_h___camera.md#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Unregisters the callback used to listen for preview output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_Start](_o_h___camera.md#oh_previewoutput_start) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Starts preview output.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_Stop](_o_h___camera.md#oh_previewoutput_stop) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Stops preview output.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_Release](_o_h___camera.md#oh_previewoutput_release) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Releases a **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_GetActiveProfile](_o_h___camera.md#oh_previewoutput_getactiveprofile) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | Obtains the profile of a **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_DeleteProfile](_o_h___camera.md#oh_previewoutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | Deletes the profile of this **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_GetSupportedFrameRates](_o_h___camera.md#oh_previewoutput_getsupportedframerates) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | Obtains the list of frame rates supported by a **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_DeleteFrameRates](_o_h___camera.md#oh_previewoutput_deleteframerates) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Deletes the frame rate list.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_SetFrameRate](_o_h___camera.md#oh_previewoutput_setframerate) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, int32_t minFps, int32_t maxFps) | Sets the frame rates for a **PreviewOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PreviewOutput_GetActiveFrameRate](_o_h___camera.md#oh_previewoutput_getactiveframerate) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Obtains the active frame rates of a **PreviewOutput** instance.| 
