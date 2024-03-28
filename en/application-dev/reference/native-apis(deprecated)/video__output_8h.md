# video_output.h


## Overview

The **video_output.h** file declares the video output concepts.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [VideoOutput_Callbacks](_video_output___callbacks.md) | Defines the callbacks used for video output.| 


### Types

| Name| Description| 
| -------- | -------- |
| [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) | Defines the video output object.| 
| (\*[OH_VideoOutput_OnFrameStart](_o_h___camera.md#oh_videooutput_onframestart)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.| 
| (\*[OH_VideoOutput_OnFrameEnd](_o_h___camera.md#oh_videooutput_onframeend)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.| 
| (\*[OH_VideoOutput_OnError](_o_h___camera.md#oh_videooutput_onerror)) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.| 
| [VideoOutput_Callbacks](_o_h___camera.md#videooutput_callbacks) | Defines the callbacks used for video output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_VideoOutput_RegisterCallback](_o_h___camera.md#oh_videooutput_registercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Registers a callback to listen for video output events.| 
| [OH_VideoOutput_UnregisterCallback](_o_h___camera.md#oh_videooutput_unregistercallback) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Unregisters the callback used to listen for video output events.| 
| [OH_VideoOutput_Start](_o_h___camera.md#oh_videooutput_start) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Starts video output.| 
| [OH_VideoOutput_Stop](_o_h___camera.md#oh_videooutput_stop) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Stops video output.| 
| [OH_VideoOutput_Release](_o_h___camera.md#oh_videooutput_release) ([Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | Releases a **VideoOutput** instance.| 
