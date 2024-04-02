# metadata_output.h


## Overview

The **metadata_output.h** file declares the metadata output concepts.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [MetadataOutput_Callbacks](_metadata_output___callbacks.md) | Defines the callback functions of metadata output.| 


### Types

| Name| Description| 
| -------- | -------- |
| [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) | Defines the metadata output object.| 
| [OH_MetadataOutput_OnMetadataObjectAvailable](_o_h___camera.md#oh_metadataoutput_onmetadataobjectavailable)) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [Camera_MetadataObject](_camera___metadata_object.md) \*metadataObject, uint32_t size) | Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output data.| 
| [OH_MetadataOutput_OnError](_o_h___camera.md#oh_metadataoutput_onerror)) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output errors.| 
| [MetadataOutput_Callbacks](_o_h___camera.md#metadataoutput_callbacks) | Defines the callback functions of metadata output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_MetadataOutput_RegisterCallback](_o_h___camera.md#oh_metadataoutput_registercallback) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Registers a callback to listen for metadata output events.| 
| [OH_MetadataOutput_UnregisterCallback](_o_h___camera.md#oh_metadataoutput_unregistercallback) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Unregisters the callback used to listen for metadata output events.| 
| [OH_MetadataOutput_Start](_o_h___camera.md#oh_metadataoutput_start) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | Starts metadata output.| 
| [OH_MetadataOutput_Stop](_o_h___camera.md#oh_metadataoutput_stop) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | Stops metadata output.| 
| [OH_MetadataOutput_Release](_o_h___camera.md#oh_metadataoutput_release) ([Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | Releases a **MetadataOutput** instance.| 
