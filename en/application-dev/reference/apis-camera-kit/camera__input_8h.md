# camera_input.h


## Overview

The **camera_input.h** file declares the camera input concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/camera_input.h&gt;

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [CameraInput_Callbacks](_camera_input___callbacks.md) | Describes the callbacks used to listen for camera input errors. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_Input](_o_h___camera.md#camera_input) [Camera_Input](_o_h___camera.md#camera_input) | Defines a struct for the camera input object. | 
| typedef void(\* [OH_CameraInput_OnError](_o_h___camera.md#oh_camerainput_onerror)) (const [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors. | 
| typedef struct [CameraInput_Callbacks](_camera_input___callbacks.md) [CameraInput_Callbacks](_o_h___camera.md#camerainput_callbacks) | Defines a struct for the callbacks used to listen for camera input errors. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_RegisterCallback](_o_h___camera.md#oh_camerainput_registercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Registers a callback to listen for camera input events. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_UnregisterCallback](_o_h___camera.md#oh_camerainput_unregistercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Unregisters the callback used to listen for camera input events. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Open](_o_h___camera.md#oh_camerainput_open) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Opens a camera. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_OpenSecureCamera](_o_h___camera.md#oh_camerainput_opensecurecamera) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, uint64_t \*secureSeqId) | Opens a camera in secure mode. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_OpenConcurrentCameras](_o_h___camera.md#oh_camerainput_openconcurrentcameras) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) type) | Opens the camera based on the specified concurrency type.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Closes a camera. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraInput_Release](_o_h___camera.md#oh_camerainput_release) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Releases a **CameraInput** instance. This function has the same capability as [OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close). Therefore, you do not need to call [OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close) after calling this function. | 
