# camera_input.h


## Overview

The **camera_input.h** file declares the camera input concepts.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [CameraInput_Callbacks](_camera_input___callbacks.md) | Defines the callbacks used to listen for camera input errors.| 


### Types

| Name| Description| 
| -------- | -------- |
| [Camera_Input](_o_h___camera.md#camera_input) | Defines the camera input object.| 
| (\*[OH_CameraInput_OnError](_o_h___camera.md#oh_camerainput_onerror)) (const [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors.| 
| [CameraInput_Callbacks](_o_h___camera.md#camerainput_callbacks) | Defines the callbacks used to listen for camera input errors.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_CameraInput_RegisterCallback](_o_h___camera.md#oh_camerainput_registercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Registers a callback to listen for camera input changes.| 
| [OH_CameraInput_UnregisterCallback](_o_h___camera.md#oh_camerainput_unregistercallback) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Unregisters the callback used to listen for camera input events.| 
| [OH_CameraInput_Open](_o_h___camera.md#oh_camerainput_open) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Opens a camera.| 
| [OH_CameraInput_Close](_o_h___camera.md#oh_camerainput_close) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Closes a camera.| 
| [OH_CameraInput_Release](_o_h___camera.md#oh_camerainput_release) ([Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | Releases a **CameraInput** instance.| 
