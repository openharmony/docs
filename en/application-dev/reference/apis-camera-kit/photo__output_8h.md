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
| struct  [PhotoOutput_Callbacks](_photo_output___callbacks.md) | Describes the callbacks related to photo output.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) | Defines a struct for the photo output object.| 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events.| 
| typedef void(\* [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors.| 
| typedef void(\* [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the callback invoked when the capture ends.| 
| typedef void(\* [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_CaptureStartInfo](_camera___capture_start_info.md) \*Info) | Defines the callback invoked when the capture starts.| 
| typedef void(\* [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*Info) | Defines the callback invoked when frame shutter ends.| 
| typedef void(\* [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Defines the callback invoked when the camera is ready to take photos. When the callback is received, the next capture can be performed.| 
| typedef void(\* [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int64_t duration) | Defines the callback for the estimated capture duration.| 
| typedef void(\* [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo) | Defines the callback invoked when a high-resolution photo is available.| 
| typedef void(\* [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, OH_MediaAsset \*photoAsset) | Defines the callback invoked when a photo asset is available.| 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](_o_h___camera.md#photooutput_callbacks) | Defines a struct for the callbacks related to photo output.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Registers a callback to listen for photo output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](_o_h___camera.md#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Unregisters the callback used to listen for photo output events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureStartWithInfoCallback](_o_h___camera.md#oh_photooutput_registercapturestartwithinfocallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo) callback) | Registers a callback to listen for capture start events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback](_o_h___camera.md#oh_photooutput_unregistercapturestartwithinfocallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo) callback) | Unregisters the callback used to listen for capture start events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureEndCallback](_o_h___camera.md#oh_photooutput_registercaptureendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend) callback) | Registers a callback to listen for capture end events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureEndCallback](_o_h___camera.md#oh_photooutput_unregistercaptureendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend) callback) | Unregisters the callback used to listen for capture end events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterFrameShutterEndCallback](_o_h___camera.md#oh_photooutput_registerframeshutterendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend) callback) | Registers a callback to listen for frame shutter end events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterFrameShutterEndCallback](_o_h___camera.md#oh_photooutput_unregisterframeshutterendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend) callback) | Unregisters the callback used to listen for frame shutter end events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureReadyCallback](_o_h___camera.md#oh_photooutput_registercapturereadycallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready) callback) | Registers a callback to listen for camera ready events. After the callback is received, the next capture can be performed.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureReadyCallback](_o_h___camera.md#oh_photooutput_unregistercapturereadycallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready) callback) | Unregisters the callback used to listen for camera ready events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback](_o_h___camera.md#oh_photooutput_registerestimatedcapturedurationcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration) callback) | Registers a callback to listen for estimated capture duration events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback](_o_h___camera.md#oh_photooutput_unregisterestimatedcapturedurationcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration) callback) | Unregisters the callback used to listen for estimated capture duration events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAvailableCallback](_o_h___camera.md#oh_photooutput_registerphotoavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable) callback) | Registers a callback to listen for photo availability events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAvailableCallback](_o_h___camera.md#oh_photooutput_unregisterphotoavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable) callback) | Unregisters the callback used to listen for photo availability events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAssetAvailableCallback](_o_h___camera.md#oh_photooutput_registerphotoassetavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable) callback) | Registers a callback to listen for photo asset availability events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback](_o_h___camera.md#oh_photooutput_unregisterphotoassetavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable) callback) | Unregisters the callback used to listen for photo asset availability events.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture](_o_h___camera.md#oh_photooutput_capture) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Captures a photo.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](_o_h___camera.md#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | Captures a photo with capture parameters.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Release](_o_h___camera.md#oh_photooutput_release) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | Releases a **PhotoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](_o_h___camera.md#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether mirroring is supported.|
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_EnableMirror](_o_h___camera.md#oh_photooutput_enablemirror) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool enabled) | Enables dynamic photo capture.|
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_GetActiveProfile](_o_h___camera.md#oh_photooutput_getactiveprofile) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | Obtains the profile of a **PhotoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_DeleteProfile](_o_h___camera.md#oh_photooutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | Deletes the profile of this **PhotoOutput** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMovingPhotoSupported](_o_h___camera.md#oh_photooutput_ismovingphotosupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether moving photos are supported.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_EnableMovingPhoto](_o_h___camera.md#oh_photooutput_enablemovingphoto) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool enabled) | Enables moving photos.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_GetPhotoRotation](_o_h___camera.md#oh_photooutput_getphotorotation) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int devicedegree, [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) \*imageRotation) | Obtains the photo rotation angle.| 
