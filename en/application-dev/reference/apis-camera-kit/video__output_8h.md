# video_output.h


## Overview

The **video_output.h** file declares the video output concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/video_output.h&gt; 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [VideoOutput_Callbacks](_video_output___callbacks.md) | Describes the callbacks related to video output.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) | Defines a struct for the video output object.| 
| typedef void(\* [OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.| 
| typedef void(\* [OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t frameCount) | Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.| 
| typedef void(\* [OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.| 
| typedef struct [VideoOutput_Callbacks](_video_output___callbacks.md) [VideoOutput_Callbacks](_o_h___camera.md#videooutput_callbacks) | Defines a struct for the callbacks related to video output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Registers a callback to listen for video output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_UnregisterCallback](_o_h___camera.md#oh_videooutput_unregistercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Unregisters the callback used to listen for video output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Start](_o_h___camera.md#oh_videooutput_start) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Starts video output.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Stop](_o_h___camera.md#oh_videooutput_stop) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Stops video output.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_Release](_o_h___camera.md#oh_videooutput_release) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Releases a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetActiveProfile](_o_h___camera.md#oh_videooutput_getactiveprofile) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_VideoProfile](_camera___video_profile.md) \*\*profile) | Obtains the profile of a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_DeleteProfile](_o_h___camera.md#oh_videooutput_deleteprofile) ([Camera_VideoProfile](_camera___video_profile.md) \*profile) | Deletes the profile of this **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetSupportedFrameRates](_o_h___camera.md#oh_videooutput_getsupportedframerates) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | Obtains the list of frame rates supported by a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_DeleteFrameRates](_o_h___camera.md#oh_videooutput_deleteframerates) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Deletes the frame rate list.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_SetFrameRate](_o_h___camera.md#oh_videooutput_setframerate) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t minFps, int32_t maxFps) | Sets the frame rates for a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetActiveFrameRate](_o_h___camera.md#oh_videooutput_getactiveframerate) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Obtains the active frame rates of a **VideoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_IsMirrorSupported](_o_h___camera.md#oh_videooutput_ismirrorsupported) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, bool \*isSupported) | Checks whether a video output supports mirror mode.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_EnableMirror](_o_h___camera.md#oh_videooutput_enablemirror) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, bool mirrorMode) | Enables or disables mirror mode for a video output.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_VideoOutput_GetVideoRotation](_o_h___camera.md#oh_videooutput_getvideorotation) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int deviceDegree, [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) \*imageRotation) | Obtains the rotation angle of a video output.| 
