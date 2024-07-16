# photo_output.h


## Overview

The **photo_output.h** file declares the photo output concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/photo_output.h&gt; 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[PhotoOutput_Callbacks](_photo_output___callbacks.md) | Describes the callbacks related to photo output. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) | Defines a struct for the photo output object. | 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events. | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events. | 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events. | 
| typedef void(\* [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors. | 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](_o_h___camera.md#photooutput_callbacks) | Defines a struct for the callbacks related to photo output. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Registers a callback to listen for photo output events. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](_o_h___camera.md#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Unregisters the callback used to listen for photo output events. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture](_o_h___camera.md#oh_photooutput_capture) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Captures a photo. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](_o_h___camera.md#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | Captures a photo with the photographing parameters. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Release](_o_h___camera.md#oh_photooutput_release) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Releases a **PhotoOutput** instance. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](_o_h___camera.md#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether mirroring is supported. | 
