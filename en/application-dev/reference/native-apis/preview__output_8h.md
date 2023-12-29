# preview_output.h


## Overview

The **preview_output.h** file declares the preview output concepts.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [PreviewOutput_Callbacks](_preview_output___callbacks.md) | Defines the callbacks used for preview output.| 


### Types

| Name| Description| 
| -------- | -------- |
| [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) | Defines the preview output object.| 
| (\*[OH_PreviewOutput_OnFrameStart](_o_h___camera.md#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.| 
| (\*[OH_PreviewOutput_OnFrameEnd](_o_h___camera.md#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame end events.| 
| (\*[OH_PreviewOutput_OnError](_o_h___camera.md#oh_previewoutput_onerror)) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.| 
| [PreviewOutput_Callbacks](_o_h___camera.md#previewoutput_callbacks) | Defines the callbacks used for preview output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_PreviewOutput_RegisterCallback](_o_h___camera.md#oh_previewoutput_registercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Registers a callback to listen for preview output events.| 
| [OH_PreviewOutput_UnregisterCallback](_o_h___camera.md#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Unregisters the callback used to listen for preview output events.| 
| [OH_PreviewOutput_Start](_o_h___camera.md#oh_previewoutput_start) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Starts preview output.| 
| [OH_PreviewOutput_Stop](_o_h___camera.md#oh_previewoutput_stop) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Stops preview output.| 
| [OH_PreviewOutput_Release](_o_h___camera.md#oh_previewoutput_release) ([Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | Releases a **PreviewOutput** instance.| 
