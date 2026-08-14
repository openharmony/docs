# capture_session.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f242764258e1097caebeaca2bb56a8d636b4df3e translatedAt=2026-08-11T02:02:41.003Z pushedAt=2026-08-12T03:13:40.760Z -->

## Overview

The file declares the capture session concepts.

**File to include**: <ohcamera/capture_session.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) | CaptureSession_Callbacks | Describes the callbacks used for a capture session.|
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md) | Camera_CaptureSession | Describes the capture session object.<br> You can use [OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession) to create such an object.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)](#oh_capturesession_onfocusstatechange) | OH_CaptureSession_OnFocusStateChange | Defines the callback defined in the [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) struct and used to report focus status changes of a capture session.|
| [typedef void (\*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)](#oh_capturesession_onerror) | OH_CaptureSession_OnError | Defines the callback defined in the [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) struct and used to report capture session errors.|
| [typedef void (\*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session, Camera_SmoothZoomInfo* smoothZoomInfo)](#oh_capturesession_onsmoothzoominfo) | OH_CaptureSession_OnSmoothZoomInfo | Defines the callback invoked when smooth zoom is triggered for a capture session.|
| [typedef void (\*OH_CaptureSession_OnAutoDeviceSwitchStatusChange)(Camera_CaptureSession* session, Camera_AutoDeviceSwitchStatusInfo* autoDeviceSwitchStatusInfo)](#oh_capturesession_onautodeviceswitchstatuschange) | OH_CaptureSession_OnAutoDeviceSwitchStatusChange | Defines the callback used to listen for device switching events.|
| [typedef void (\*OH_CaptureSession_OnSystemPressureLevelChange)(Camera_CaptureSession* session, Camera_SystemPressureLevel systemPressureLevel)](#oh_capturesession_onsystempressurelevelchange) | OH_CaptureSession_OnSystemPressureLevelChange | Defines the callback used to listen for capture system pressure level changes.|
| [typedef void (\*OH_CaptureSession_OnControlCenterEffectStatusChange)(Camera_CaptureSession* session, Camera_ControlCenterStatusInfo* controlCenterStatusInfo)](#oh_capturesession_oncontrolcentereffectstatuschange) | OH_CaptureSession_OnControlCenterEffectStatusChange | Defines the callback used to listen for effect status changes of a camera controller.|
| [Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)](#oh_capturesession_registercallback) | - | Registers a callback to listen for capture session events.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)](#oh_capturesession_unregistercallback) | - | Unregisters the callback used to listen for capture session events.|
| [Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)](#oh_capturesession_registersmoothzoominfocallback) | - | Registers a callback to listen for smooth zoom events.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)](#oh_capturesession_unregistersmoothzoominfocallback) | - | Unregisters the callback used to listen for smooth zoom events.|
| [Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)](#oh_capturesession_setsessionmode) | - | Sets a session mode.<br> This API cannot be called after [OH_CaptureSession_BeginConfig](capi-capture-session-h.md#oh_capturesession_beginconfig).<br> You are advised to call this function immediately after [OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession).|
| [Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)](#oh_capturesession_addsecureoutput) | - | Marks a preview output stream as secure output.|
| [Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)](#oh_capturesession_beginconfig) | - | Starts the configuration for a capture session.|
| [Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)](#oh_capturesession_commitconfig) | - | Commits the configuration for a capture session.|
| [Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)](#oh_capturesession_addinput) | - | Adds a Camera_Input instance to a session.|
| [Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)](#oh_capturesession_removeinput) | - | Removes a Camera_Input instance from a session.|
| [Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)](#oh_capturesession_addpreviewoutput) | - | Adds a PreviewOutput instance to a session.|
| [Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)](#oh_capturesession_removepreviewoutput) | - | Removes a PreviewOutput instance from a session.|
| [Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)](#oh_capturesession_addphotooutput) | - | Adds a PhotoOutput instance to a session.|
| [Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)](#oh_capturesession_removephotooutput) | - | Removes a PhotoOutput instance from a session.|
| [Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)](#oh_capturesession_addvideooutput) | - | Adds a VideoOutput instance to a session.|
| [Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)](#oh_capturesession_removevideooutput) | - | Removes a VideoOutput instance from a session.|
| [Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)](#oh_capturesession_addmetadataoutput) | - | Adds a MetadataOutput instance to a session.|
| [Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)](#oh_capturesession_removemetadataoutput) | - | Removes a MetadataOutput instance from a session.|
| [Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)](#oh_capturesession_start) | - | Starts a capture session.|
| [Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)](#oh_capturesession_stop) | - | Stops a capture session.|
| [Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)](#oh_capturesession_release) | - | Releases a CaptureSession instance.|
| [Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)](#oh_capturesession_hasflash) | - | Checks whether the device has flash.|
| [Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session, Camera_FlashMode flashMode, bool* isSupported)](#oh_capturesession_isflashmodesupported) | - | Checks whether a flash mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)](#oh_capturesession_getflashmode) | - | Obtains the flash mode in use.|
| [Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)](#oh_capturesession_setflashmode) | - | Sets a flash mode for the device.|
| [typedef void (\*OH_CaptureSession_OnFlashStateChange)(const Camera_CaptureSession* session, OH_Camera_FlashState flashState)](#oh_capturesession_onflashstatechange) | OH_CaptureSession_OnFlashStateChange | Defines the callback used to listen for flash state changes of a camera capture session.|
| [Camera_ErrorCode OH_CaptureSession_RegisterFlashStateChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnFlashStateChange flashStateChange)](#oh_capturesession_registerflashstatechangecallback) | - | Registers a callback to listen for flash state changes.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterFlashStateChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnFlashStateChange flashStateChange)](#oh_capturesession_unregisterflashstatechangecallback) | - | Unregisters the callback to listen for flash state changes.|
| [Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session, Camera_ExposureMode exposureMode, bool* isSupported)](#oh_capturesession_isexposuremodesupported) | - | Checks whether an exposure mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)](#oh_capturesession_getexposuremode) | - | Obtains the exposure mode in use.|
| [Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)](#oh_capturesession_setexposuremode) | - | Sets an exposure mode for the device.|
| [Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)](#oh_capturesession_getmeteringpoint) | - | Obtains the metering point in use.|
| [Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)](#oh_capturesession_setmeteringpoint) | - | Sets the metering point, which is the center point of the metering rectangle.|
| [Camera_ErrorCode OH_CaptureSession_IsExposureMeteringModeSupported(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode exposureMeteringMode, bool* isSupported)](#oh_capturesession_isexposuremeteringmodesupported) | - | Checks whether the specified exposure metering mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetExposureMeteringMode(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode* exposureMeteringMode)](#oh_capturesession_getexposuremeteringmode) | - | Obtains the exposure metering mode in use.|
| [Camera_ErrorCode OH_CaptureSession_SetExposureMeteringMode(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode exposureMeteringMode)](#oh_capturesession_setexposuremeteringmode) | - | Sets exposure metering mode.|
| [Camera_ErrorCode OH_CaptureSession_GetSupportedISORange(const Camera_CaptureSession* session, int32_t *minIsoValue, int32_t *maxIsoValue)](#oh_capturesession_getsupportedisorange) | - | Obtains the ISO range.|
| [Camera_ErrorCode OH_CaptureSession_GetIso(const Camera_CaptureSession* session, int32_t* isoValue)](#oh_capturesession_getiso) | - | Obtains the ISO sensitivity or ISO speed (compliant with the ISO 12232:2006 standard).|
| [Camera_ErrorCode OH_CaptureSession_SetIso(const Camera_CaptureSession* session, int32_t isoValue)](#oh_capturesession_setiso) | - | Sets the ISO sensitivity or ISO speed. The value must be within the range specified by [OH_CaptureSession_GetSupportedISORange](capi-capture-session-h.md#oh_capturesession_getsupportedisorange). When [ExposureMode](capi-camera-h.md#camera_exposuremode) is set to **EXPOSURE_MODE_LOCKED**, the ISO sensitivity or ISO speed cannot be set. |
| [Camera_ErrorCode OH_CaptureSession_GetSupportedPhysicalApertures(const Camera_CaptureSession* session, OH_Camera_PhysicalAperture** apertures, uint32_t* size)](#oh_capturesession_getsupportedphysicalapertures) | - | Obtains the supported physical apertures. Call [OH_CaptureSession_DeletePhysicalApertures](capi-capture-session-h.md#oh_capturesession_deletephysicalapertures) to delete the supported physical apertures.|
| [Camera_ErrorCode OH_CaptureSession_DeletePhysicalApertures(const Camera_CaptureSession* session, OH_Camera_PhysicalAperture* apertures, uint32_t size)](#oh_capturesession_deletephysicalapertures) | - | Deletes the supported physical apertures.|
| [Camera_ErrorCode OH_CaptureSession_GetPhysicalAperture(const Camera_CaptureSession* session, double* aperture)](#oh_capturesession_getphysicalaperture) | - | Obtains the physical aperture in use.|
| [Camera_ErrorCode OH_CaptureSession_SetPhysicalAperture(const Camera_CaptureSession* session, double aperture)](#oh_capturesession_setphysicalaperture) | - | Sets a physical aperture.|
| [Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias, float* maxExposureBias, float* step)](#oh_capturesession_getexposurebiasrange) | - | Obtains the exposure compensation values of the device.|
| [Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)](#oh_capturesession_setexposurebias) | - | Sets an exposure compensation value for the device.|
| [Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)](#oh_capturesession_getexposurebias) | - | Obtains the exposure compensation value in use.|
| [Camera_ErrorCode OH_CaptureSession_GetSupportedExposureDurationRange(const Camera_CaptureSession* session, int32_t* minExposureDuration, int32_t* maxExposureDuration)](#oh_capturesession_getsupportedexposuredurationrange) | - | Obtains the supported exposure durations, in microseconds.|
| [Camera_ErrorCode OH_CaptureSession_SetExposureDuration(const Camera_CaptureSession* session, int32_t exposureDuration)](#oh_capturesession_setexposureduration) | - | Sets the exposure duration, in microseconds. If the sensor cannot use the set exposure duration, the system automatically adjusts it to a value closest to the set value and reports the value to the application by calling [OH_CaptureSession_OnExposureDurationChange](capi-capture-session-h.md#oh_capturesession_onexposuredurationchange). This setting takes effect only in [ExposureMode](capi-camera-h.md#camera_exposuremode).EXPOSURE_MODE_MANUAL mode. |
| [Camera_ErrorCode OH_CaptureSession_GetExposureDuration(const Camera_CaptureSession* session, int32_t* exposureDuration)](#oh_capturesession_getexposureduration) | - | Obtains the exposure duration, in microseconds.|
| [typedef void (\*OH_CaptureSession_OnExposureDurationChange)(const Camera_CaptureSession* session, int32_t exposureDuration)](#oh_capturesession_onexposuredurationchange) | OH_CaptureSession_OnExposureDurationChange | Defines the callback used to listen for exposure duration changes of a camera capture session.|
| [Camera_ErrorCode OH_CaptureSession_RegisterExposureInfoChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnExposureDurationChange exposureDurationChange)](#oh_capturesession_registerexposureinfochangecallback) | - | Registers a callback to listen for exposure information changes. After the exposure parameters are modified, the system returns the updated exposure information.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterExposureInfoChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnExposureDurationChange exposureDurationChange)](#oh_capturesession_unregisterexposureinfochangecallback) | - | Unregisters the callback to listen for exposure information changes. This method is called after the camera operation is complete.|
| [Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session, Camera_FocusMode focusMode, bool* isSupported)](#oh_capturesession_isfocusmodesupported) | - | Checks whether a focus mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)](#oh_capturesession_getfocusmode) | - | Obtains the focus mode in use.|
| [Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)](#oh_capturesession_setfocusmode) | - | Sets a focus mode for the device.|
| [Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)](#oh_capturesession_getfocuspoint) | - | Obtains the focal point in use.|
| [Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)](#oh_capturesession_setfocuspoint) | - | Sets a focal point for the device.|
| [Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)](#oh_capturesession_getzoomratiorange) | - | Obtains the supported zoom ratio range.|
| [Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)](#oh_capturesession_getzoomratio) | - | Obtains the zoom ratio in use.|
| [Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)](#oh_capturesession_setzoomratio) | - | Sets a zoom ratio for the device.|
| [Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode, bool* isSupported)](#oh_capturesession_isvideostabilizationmodesupported) | - | Checks whether a video stabilization mode is supported. |
| [Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode* mode)](#oh_capturesession_getvideostabilizationmode) | - | Obtains the video stabilization mode in use.|
| [Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode)](#oh_capturesession_setvideostabilizationmode) | - | Sets a video stabilization mode for the device.|
| [Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session, Camera_Input* cameraInput, bool* isSuccessful)](#oh_capturesession_canaddinput) | - | Checks whether a **Camera_Input** instance can be added to a session.|
| [Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddpreviewoutput) | - | Checks whether a **PreviewOutput** instance can be added to a session.|
| [Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddphotooutput) | - | Checks whether a **PhotoOutput** instance can be added to a session.|
| [Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddvideooutput) | - | Checks whether a **VideoOutput** instance can be added to a session.|
| [Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, bool* canPreconfig)](#oh_capturesession_canpreconfig) | - | Checks whether a preconfigured resolution type is supported.|
| [Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)](#oh_capturesession_canpreconfigwithratio) | - | Checks whether a preconfigured resolution type with an aspect ratio is supported.|
| [Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType)](#oh_capturesession_preconfig) | - | Sets a preconfigured resolution type.|
| [Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)](#oh_capturesession_preconfigwithratio) | - | Sets a preconfigured resolution type with an aspect ratio.|
| [Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)](#oh_capturesession_getexposurevalue) | - | Obtains the exposure value.|
| [Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)](#oh_capturesession_getfocallength) | - | Obtains the current focal length.|
| [Camera_ErrorCode OH_CaptureSession_GetFocusDistance(const Camera_CaptureSession* session, float* focusDistance)](#oh_capturesession_getfocusdistance) | - | Obtains the focus distance in use. The value range is [0.0, 1.0], where **0.0** indicates the shortest achievable focus distance and **1.0** indicates the longest focus distance. The default value is **1.0**.|
| [Camera_ErrorCode OH_CaptureSession_SetFocusDistance(const Camera_CaptureSession* session, float focusDistance)](#oh_capturesession_setfocusdistance) | - | Sets the focus distance. The value range is [0.0, 1.0], where **0.0** indicates the shortest achievable focus distance and **1.0** indicates the longest focus distance. The default value is **1.0**.|
| [Camera_ErrorCode OH_CaptureSession_IsFocusDistanceSupported(const Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_isfocusdistancesupported) | - | Checks whether the focus distance can be set.|
| [Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session, float targetZoom, Camera_SmoothZoomMode smoothZoomMode)](#oh_capturesession_setsmoothzoom) | - | Sets smooth zoom.|
| [Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)](#oh_capturesession_getsupportedcolorspaces) | - | Obtains the supported color spaces.|
| [Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)](#oh_capturesession_deletecolorspaces) | - | Deletes color spaces.|
| [Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)](#oh_capturesession_getactivecolorspace) | - | Obtains the active color space.|
| [Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace colorSpace)](#oh_capturesession_setactivecolorspace) | - | Sets the active color space.|
| [Camera_ErrorCode OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session, OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)](#oh_capturesession_registerautodeviceswitchstatuscallback) | - | Registers a callback to listen for device switching changes.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session, OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)](#oh_capturesession_unregisterautodeviceswitchstatuscallback) | - | Unregisters the callback used to listen for device switching changes.|
| [Camera_ErrorCode OH_CaptureSession_IsAutoDeviceSwitchSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_isautodeviceswitchsupported) | - | Checks whether automatic device switching is supported.|
| [Camera_ErrorCode OH_CaptureSession_EnableAutoDeviceSwitch(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enableautodeviceswitch) | - | Enables or disables automatic device switching.|
| [Camera_ErrorCode OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)](#oh_capturesession_registersystempressurelevelchangecallback) | - | Registers a callback to listen for capture system pressure level changes.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)](#oh_capturesession_unregistersystempressurelevelchangecallback) | - | Unregisters the callback used to listen for capture system pressure level changes.|
| [Camera_ErrorCode OH_CaptureSession_SetQualityPrioritization(Camera_CaptureSession* session, Camera_QualityPrioritization qualityPrioritization)](#oh_capturesession_setqualityprioritization) | - | Sets the priority level for video recording quality.<br> The default value is **HIGH_QUALITY**. Switching to **POWER_BALANCE** will compromise video recording quality to achieve lower power usage. The extent of power conservation achieved varies depending on the platform. It is recommended that this API be called between [OH_CaptureSession_CommitConfig](capi-capture-session-h.md#oh_capturesession_commitconfig) and [OH_CaptureSession_Start](capi-capture-session-h.md#oh_capturesession_start).|
| [Camera_ErrorCode OH_CaptureSession_IsMacroSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_ismacrosupported) | - | Checks whether macro photography is supported.|
| [Camera_ErrorCode OH_CaptureSession_EnableMacro(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enablemacro) | - | Enables or disables macro photography for the camera device.|
| [Camera_ErrorCode OH_CaptureSession_SetWhiteBalance(Camera_CaptureSession* session, int32_t colorTemperature)](#oh_capturesession_setwhitebalance) | - | Sets the white balance hue adjustment. Before setting this parameter, you are advised to use [OH_CaptureSession_GetColorTintRange](capi-capture-session-h.md#oh_capturesession_getcolortintrange) to obtain the supported white balance hue adjustment range.|
| [Camera_ErrorCode OH_CaptureSession_GetColorTintRange(const Camera_CaptureSession* session, int32_t *minColorTint, int32_t *maxColorTint)](#oh_capturesession_getcolortintrange) | - | Obtains the supported white balance hue adjustment range.|
| [Camera_ErrorCode OH_CaptureSession_GetColorTint(const Camera_CaptureSession* session, int32_t *colorTint)](#oh_capturesession_getcolortint) | - | Obtains the white balance hue adjustment.|
| [Camera_ErrorCode OH_CaptureSession_SetColorTint(Camera_CaptureSession* session, int32_t colorTint)](#oh_capturesession_setcolortint) | - | Sets the white balance hue adjustment. Before setting this parameter, you are advised to use [OH_CaptureSession_GetColorTintRange](capi-capture-session-h.md#oh_capturesession_getcolortintrange) to obtain the supported white balance hue adjustment range. |
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalance(Camera_CaptureSession* session, int32_t *colorTemperature)](#oh_capturesession_getwhitebalance) | - | Obtains the white balance color temperature.|
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode* whiteBalanceMode)](#oh_capturesession_getwhitebalancemode) | - | Obtains the white balance mode in use.|
| [Camera_ErrorCode OH_CaptureSession_IsWhiteBalanceModeSupported(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode, bool* isSupported)](#oh_capturesession_iswhitebalancemodesupported) | - | Checks whether the specified white balance mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_SetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode)](#oh_capturesession_setwhitebalancemode) | - | Sets a white balance mode.|
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceRange(Camera_CaptureSession* session, int32_t *minColorTemperature, int32_t *maxColorTemperature)](#oh_capturesession_getwhitebalancerange) | - | Obtains the supported white balance color temperature range.|
| [Camera_ErrorCode OH_CaptureSession_IsControlCenterSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_iscontrolcentersupported) | - | Checks whether the camera controller is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetSupportedEffectTypes(Camera_CaptureSession* session, Camera_ControlCenterEffectType** types, uint32_t* size)](#oh_capturesession_getsupportedeffecttypes) | - | Obtains the effect types supported by the camera controller.|
| [Camera_ErrorCode OH_CaptureSession_DeleteSupportedEffectTypes(Camera_CaptureSession* session, Camera_ControlCenterEffectType* types, uint32_t size)](#oh_capturesession_deletesupportedeffecttypes) | - | Deletes the effect types supported by the camera controller.|
| [Camera_ErrorCode OH_CaptureSession_EnableControlCenter(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enablecontrolcenter) | - | Enables or disables the camera controller.|
| [Camera_ErrorCode OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)](#oh_capturesession_registercontrolcentereffectstatuschangecallback) | - | Registers a callback to listen for effect status changes of a camera controller.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)](#oh_capturesession_unregistercontrolcentereffectstatuschangecallback) | - | Unregisters the callback used to listen for effect status changes of a camera controller.|
| [typedef void (\*OH_CaptureSession_OnMacroStatusChange)(Camera_CaptureSession* session, bool isMacroDetected)](#oh_capturesession_onmacrostatuschange) | OH_CaptureSession_OnMacroStatusChange | Defines the callback used to listen for macro status changes of a camera session.|
| [Camera_ErrorCode OH_CaptureSession_RegisterMacroStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnMacroStatusChange macroStatusChange)](#oh_capturesession_registermacrostatuschangecallback) | - | Registers a callback to listen for macro status changes of a camera session.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterMacroStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnMacroStatusChange macroStatusChange)](#oh_capturesession_unregistermacrostatuschangecallback) | - | Unregisters the callback used to listen for macro status changes of a camera session.|
| [typedef void (\*OH_CaptureSession_OnIsoChange)(Camera_CaptureSession* session, int32_t isoValue)](#oh_capturesession_onisochange) | OH_CaptureSession_OnIsoChange | Defines the callback used to listen for ISO changes in a camera session.|
| [Camera_ErrorCode OH_CaptureSession_RegisterIsoChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnIsoChange isoChange)](#oh_capturesession_registerisochangecallback) | - | Registers a callback to listen for ISO changes.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterIsoChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnIsoChange isoChange)](#oh_capturesession_unregisterisochangecallback) | - | Unregisters the callback used to listen for ISO changes.|
| [Camera_ErrorCode OH_CaptureSession_GetRAWCaptureZoomRatioRange(const Camera_CaptureSession* session, float* minZoom, float* maxZoom)](#oh_capturesession_getrawcapturezoomratiorange) | - | Obtains the supported zoom range of the physical camera during shooting in RAW format.|
| [Camera_ErrorCode OH_CaptureSession_IsOISModeSupported(const Camera_CaptureSession* session, OH_Camera_OISMode oisMode, bool* isSupported)](#oh_capturesession_isoismodesupported) | - | Checks whether the optical image stabilization (OIS) mode is supported.|
| [Camera_ErrorCode OH_CaptureSession_GetSupportedOISBiasRange(const Camera_CaptureSession* session, OH_Camera_OISAxes oisAxis, float* minBias, float* maxBias, float* step)](#oh_capturesession_getsupportedoisbiasrange) | - | Obtains the offset range supported on the specified OIS axis.|
| [Camera_ErrorCode OH_CaptureSession_GetCurrentOISMode(const Camera_CaptureSession* session, OH_Camera_OISMode* oisMode)](#oh_capturesession_getcurrentoismode) | - | Obtains the OIS mode.|
| [Camera_ErrorCode OH_CaptureSession_GetCurrentCustomOISBias(const Camera_CaptureSession* session, float* pitchBias, float* yawBias)](#oh_capturesession_getcurrentcustomoisbias) | - | Obtains the custom offsets on all OIS axes.|
| [Camera_ErrorCode OH_CaptureSession_SetOISMode(const Camera_CaptureSession* session, OH_Camera_OISMode oisMode)](#oh_capturesession_setoismode) | - | Sets the OIS mode.|
| [Camera_ErrorCode OH_CaptureSession_SetOISModeCustom(const Camera_CaptureSession* session, float pitchBias, float yawBias)](#oh_capturesession_setoismodecustom) | - | Sets the custom offset for an OIS axis.|
| [typedef void (\*OH_CaptureSession_OnExposureStateChange)(void* context, OH_Camera_ExposureState exposureState)](#oh_capturesession_onexposurestatechange) | OH_CaptureSession_OnExposureStateChange | Defines a callback to be invoked when the exposure state changes.|
| [Camera_ErrorCode OH_CaptureSession_RegisterExposureStateChangeCallback(const Camera_CaptureSession* session, void* context, OH_CaptureSession_OnExposureStateChange callback)](#oh_capturesession_registerexposurestatechangecallback) | - | Registers a callback function to listen for exposure state changes. This callback is invoked when the exposure state in the capture session changes.|
| [Camera_ErrorCode OH_CaptureSession_UnregisterExposureStateChangeCallback(const Camera_CaptureSession* session, void* context, OH_CaptureSession_OnExposureStateChange callback)](#oh_capturesession_unregisterexposurestatechangecallback) | - | Unregisters a callback to be invoked when the exposure state changes.|
| [Camera_ErrorCode OH_CaptureSession_GetZoomPointInfos(const Camera_CaptureSession* session, uint32_t* size, OH_Camera_ZoomPointInfo** zoomPointInfo)](#oh_capturesession_getzoompointinfos) | - | Obtains the zoom information.<br> You need to call [OH_CaptureSession_DeleteZoomPointInfos](capi-capture-session-h.md#oh_capturesession_deletezoompointinfos) to release the memory for storing the zoom information.|
| [Camera_ErrorCode OH_CaptureSession_DeleteZoomPointInfos(const Camera_CaptureSession* session, OH_Camera_ZoomPointInfo* zoomPointInfo)](#oh_capturesession_deletezoompointinfos) | - | Deletes the zoom information.|
| [bool OH_CaptureSession_IsLockFocusTrackingSupported(const Camera_CaptureSession* session)](#oh_capturesession_islockfocustrackingsupported) | - |Checks whether locking focus tracking is supported. |
| [Camera_ErrorCode OH_CaptureSession_LockFocusTracking(Camera_CaptureSession* session, Camera_Point focusPoint)](#oh_capturesession_lockfocustracking) | - | Locks focus tracking. You can unlock focus tracking by calling [OH_CaptureSession_UnlockFocusTracking](#oh_capturesession_unlockfocustracking). |
| [Camera_ErrorCode OH_CaptureSession_UnlockFocusTracking(Camera_CaptureSession* session)](#oh_capturesession_unlockfocustracking) | - | Unlocks focus tracking. |

## Function Description

### OH_CaptureSession_OnFocusStateChange()

```c
typedef void (*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)
```

**Description**

Defines the callback defined in the [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) struct and used to report focus status changes of a capture session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_FocusState](capi-camera-h.md#camera_focusstate) focusState | Focus status.|

### OH_CaptureSession_OnError()

```c
typedef void (*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) struct and used to report capture session errors.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported in a capture session.|

**See also**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_CaptureSession_OnSmoothZoomInfo()

```c
typedef void (*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session, Camera_SmoothZoomInfo* smoothZoomInfo)
```

**Description**

Defines the callback invoked when smooth zoom is triggered for a capture session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_SmoothZoomInfo](capi-oh-camera-camera-smoothzoominfo.md)* smoothZoomInfo | Pointer to the smooth zoom information passed by the callback.|

### OH_CaptureSession_OnAutoDeviceSwitchStatusChange()

```c
typedef void (*OH_CaptureSession_OnAutoDeviceSwitchStatusChange)(Camera_CaptureSession* session, Camera_AutoDeviceSwitchStatusInfo* autoDeviceSwitchStatusInfo)
```

**Description**

Defines the callback used to listen for device switching events.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_AutoDeviceSwitchStatusInfo](capi-oh-camera-camera-autodeviceswitchstatusinfo.md)* autoDeviceSwitchStatusInfo | Pointer to the device switching information passed by the callback.|

### OH_CaptureSession_OnSystemPressureLevelChange()

```c
typedef void (*OH_CaptureSession_OnSystemPressureLevelChange)(Camera_CaptureSession* session, Camera_SystemPressureLevel systemPressureLevel)
```

**Description**

Defines the callback used to listen for capture system pressure level changes.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_SystemPressureLevel](capi-camera-h.md#camera_systempressurelevel) systemPressureLevel | Pointer to the system pressure level passed by the callback.|

### OH_CaptureSession_OnControlCenterEffectStatusChange()

```c
typedef void (*OH_CaptureSession_OnControlCenterEffectStatusChange)(Camera_CaptureSession* session, Camera_ControlCenterStatusInfo* controlCenterStatusInfo)
```

**Description**

Defines the callback used to listen for effect status changes of a camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [Camera_ControlCenterStatusInfo](capi-oh-camera-camera-controlcenterstatusinfo.md)* controlCenterStatusInfo | Pointer to the effect status information passed by the callback.|

### OH_CaptureSession_RegisterCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**Description**

Registers a callback to listen for capture session events.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for capture session events.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_RegisterSmoothZoomInfoCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**Description**

Registers a callback to listen for smooth zoom events.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnSmoothZoomInfo](capi-capture-session-h.md#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterSmoothZoomInfoCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**Description**

Unregisters the callback used to listen for smooth zoom events.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnSmoothZoomInfo](capi-capture-session-h.md#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_SetSessionMode()

```c
Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)
```

**Description**

Sets a session mode.<br> This API cannot be called after [OH_CaptureSession_BeginConfig](capi-capture-session-h.md#oh_capturesession_beginconfig).<br> You are advised to call this function immediately after [OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession).

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode) sceneMode | Scene mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_CONFIG_LOCKED**: The session configuration is locked.|

### OH_CaptureSession_AddSecureOutput()

```c
Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Marks a preview output stream as secure output.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target Camera_PreviewOutput instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_CONFIG_LOCKED**: The session configuration is locked.|

### OH_CaptureSession_BeginConfig()

```c
Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)
```

**Description**

Starts the configuration for a capture session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_CONFIG_LOCKED**: The session configuration is locked.|

### OH_CaptureSession_CommitConfig()

```c
Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)
```

**Description**

Commits the configuration for a capture session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_AddInput()

```c
Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**Description**

Adds a Camera_Input instance to a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the Camera_Input instance to add.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_RemoveInput()

```c
Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**Description**

Removes a Camera_Input instance from a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the Camera_Input instance to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_AddPreviewOutput()

```c
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Adds a PreviewOutput instance to a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance to add.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_RemovePreviewOutput()

```c
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Removes a PreviewOutput instance from a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_AddPhotoOutput()

```c
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**Description**

Adds a PhotoOutput instance to a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | Pointer to the PhotoOutput instance to add.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_RemovePhotoOutput()

```c
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**Description**

Removes a PhotoOutput instance from a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | Pointer to the PhotoOutput instance to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_AddVideoOutput()

```c
Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**Description**

Adds a **VideoOutput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the **Camera_VideoOutput** instance to add.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_RemoveVideoOutput()

```c
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**Description**

Removes a VideoOutput instance from a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_AddMetadataOutput()

```c
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**Description**

Adds a MetadataOutput instance to a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance to add.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_RemoveMetadataOutput()

```c
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**Description**

Removes a MetadataOutput instance from a session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | Pointer to the MetadataOutput instance to remove.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_Start()

```c
Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)
```

**Description**

Starts a capture session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance to start.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_Stop()

```c
Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)
```

**Description**

Stops a capture session.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance to stop.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_Release()

```c
Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)
```

**Description**

Releases a CaptureSession instance.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance to release.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_HasFlash()

```c
Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)
```

**Description**

Checks whether the device has flash.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool* hasFlash | Pointer to the check result for whether the device has flash. **true** if the device has flash, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsFlashModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session, Camera_FlashMode flashMode, bool* isSupported)
```

**Description**

Checks whether a flash mode is supported.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode) flashMode | Flash mode to check.|
| bool* isSupported | Pointer to the check result for the support of the flash mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetFlashMode()

```c
Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)
```

**Description**

Obtains the flash mode in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode)* flashMode | Pointer to the flash mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetFlashMode()

```c
Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)
```

**Description**

Sets a flash mode for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode) flashMode | Flash mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_OnFlashStateChange()

```c
typedef void (*OH_CaptureSession_OnFlashStateChange)(const Camera_CaptureSession* session, OH_Camera_FlashState flashState)
```

**Description**

Defines the callback used to listen for flash state changes of a camera capture session.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance that transfers the callback.|
| [OH_Camera_FlashState](capi-camera-h.md#oh_camera_flashstate) flashState | Flash state passed by the callback.|

### OH_CaptureSession_RegisterFlashStateChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterFlashStateChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnFlashStateChange flashStateChange)
```

**Description**

Registers a callback to listen for flash state changes.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_CaptureSession_OnFlashStateChange](capi-capture-session-h.md#oh_capturesession_onflashstatechange) flashStateChange | Callback to listen for flash state changes to register.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterFlashStateChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterFlashStateChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnFlashStateChange flashStateChange)
```

**Description**

Unregisters the callback to listen for flash state changes.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_CaptureSession_OnFlashStateChange](capi-capture-session-h.md#oh_capturesession_onflashstatechange) flashStateChange | Callback to listen for flash state changes to unregister.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_IsExposureModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session, Camera_ExposureMode exposureMode, bool* isSupported)
```

**Description**

Checks whether an exposure mode is supported.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode) exposureMode | Exposure mode to check.|
| bool* isSupported | Pointer to the check result for the support of the exposure mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetExposureMode()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)
```

**Description**

Obtains the exposure mode in use. This API directly returns an invalid value if you have not set the exposure mode using [OH_CaptureSession_SetExposureMode](capi-capture-session-h.md#oh_capturesession_setexposuremode).

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode)* exposureMode | Pointer to the exposure mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetExposureMode()

```c
Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)
```

**Description**

Sets an exposure mode for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode) exposureMode | Exposure mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetMeteringPoint()

```c
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)
```

**Description**

Obtains the metering point in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Point](capi-oh-camera-camera-point.md)* point | Pointer to the metering point.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetMeteringPoint()

```c
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)
```

**Description**

Sets the metering point, which is the center point of the metering rectangle.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Point](capi-oh-camera-camera-point.md) point | Metering point to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsExposureMeteringModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsExposureMeteringModeSupported(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode exposureMeteringMode, bool* isSupported)
```

**Description**

Checks whether the specified exposure metering mode is supported.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_ExposureMeteringMode](capi-camera-h.md#oh_camera_exposuremeteringmode) exposureMeteringMode | Exposure metering mode to check.|
| bool* isSupported | Whether the exposure mode is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetExposureMeteringMode()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureMeteringMode(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode* exposureMeteringMode)
```

**Description**

Obtains the exposure metering mode in use.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_ExposureMeteringMode](capi-camera-h.md#oh_camera_exposuremeteringmode)* exposureMeteringMode | Exposure metering mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetExposureMeteringMode()

```c
Camera_ErrorCode OH_CaptureSession_SetExposureMeteringMode(const Camera_CaptureSession* session, OH_Camera_ExposureMeteringMode exposureMeteringMode)
```

**Description**

Sets exposure metering mode.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_ExposureMeteringMode](capi-camera-h.md#oh_camera_exposuremeteringmode) exposureMeteringMode | Exposure metering mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedISORange()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedISORange(const Camera_CaptureSession* session, int32_t *minIsoValue, int32_t *maxIsoValue)
```

**Description**

Obtains the ISO range.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t *minIsoValue | Minimum ISO value.|
| int32_t *maxIsoValue | Maximum ISO value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetIso()

```c
Camera_ErrorCode OH_CaptureSession_GetIso(const Camera_CaptureSession* session, int32_t* isoValue)
```

**Description**

Obtains the ISO sensitivity or ISO speed (compliant with the ISO 12232:2006 standard).

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t* isoValue | ISO sensitivity or ISO speed.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetIso()

```c
Camera_ErrorCode OH_CaptureSession_SetIso(const Camera_CaptureSession* session, int32_t isoValue)
```

**Description**

Sets the ISO sensitivity or ISO speed. The value must be within the range specified by [OH_CaptureSession_GetSupportedISORange](capi-capture-session-h.md#oh_capturesession_getsupportedisorange). When [ExposureMode](capi-camera-h.md#camera_exposuremode) is set to **EXPOSURE_MODE_LOCKED**, the ISO sensitivity or ISO speed cannot be set.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t isoValue | Target ISO value to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedPhysicalApertures()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedPhysicalApertures(const Camera_CaptureSession* session, OH_Camera_PhysicalAperture** apertures, uint32_t* size)
```

**Description**

Obtains the supported physical apertures. Call [OH_CaptureSession_DeletePhysicalApertures](capi-capture-session-h.md#oh_capturesession_deletephysicalapertures) to delete the supported physical apertures.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_Camera_PhysicalAperture](capi-oh-camera-oh-camera-physicalaperture.md)** apertures | Pointer to the array used to store physical aperture values.|
| uint32_t* size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_DeletePhysicalApertures()

```c
Camera_ErrorCode OH_CaptureSession_DeletePhysicalApertures(const Camera_CaptureSession* session, OH_Camera_PhysicalAperture* apertures, uint32_t size)
```

**Description**

Deletes the supported physical apertures.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_PhysicalAperture](capi-oh-camera-oh-camera-physicalaperture.md)* apertures | Array of physical apertures to delete.|
| uint32_t size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_GetPhysicalAperture()

```c
Camera_ErrorCode OH_CaptureSession_GetPhysicalAperture(const Camera_CaptureSession* session, double* aperture)
```

**Description**

Obtains the physical aperture in use.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| double* aperture | Aperture value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetPhysicalAperture()

```c
Camera_ErrorCode OH_CaptureSession_SetPhysicalAperture(const Camera_CaptureSession* session, double aperture)
```

**Description**

Sets a physical aperture.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| double aperture | Aperture value to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetExposureBiasRange()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias, float* maxExposureBias, float* step)
```

**Description**

Obtains the exposure compensation values of the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* minExposureBias | Pointer to the minimum exposure compensation value.|
| float* maxExposureBias | Pointer to the maximum exposure compensation value.|
| float* step | Pointer to the exposure compensation step.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetExposureBias()

```c
Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)
```

**Description**

Sets an exposure compensation value for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float exposureBias | Exposure compensation value to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetExposureBias()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)
```

**Description**

Obtains the exposure compensation value in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* exposureBias | Pointer to the exposure compensation value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedExposureDurationRange()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedExposureDurationRange(const Camera_CaptureSession* session, int32_t* minExposureDuration, int32_t* maxExposureDuration)
```

**Description**

Obtains the supported exposure durations, in microseconds.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t* minExposureDuration | Minimum exposure duration.|
| int32_t* maxExposureDuration | Maximum exposure duration.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetExposureDuration()

```c
Camera_ErrorCode OH_CaptureSession_SetExposureDuration(const Camera_CaptureSession* session, int32_t exposureDuration)
```

**Description**

Sets the exposure duration, in microseconds. If the sensor cannot use the set exposure duration, the system automatically adjusts it to a value closest to the set value and reports the value to the application by calling [OH_CaptureSession_OnExposureDurationChange](capi-capture-session-h.md#oh_capturesession_onexposuredurationchange). This setting takes effect only in [ExposureMode](capi-camera-h.md#camera_exposuremode).EXPOSURE_MODE_MANUAL mode.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t exposureDuration | Target exposure duration to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetExposureDuration()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureDuration(const Camera_CaptureSession* session, int32_t* exposureDuration)
```

**Description**

Obtains the exposure duration, in microseconds.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t* exposureDuration | Exposure duration.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_OnExposureDurationChange()

```c
typedef void (*OH_CaptureSession_OnExposureDurationChange)(const Camera_CaptureSession* session, int32_t exposureDuration)
```

**Description**

Defines the callback used to listen for exposure duration changes of a camera capture session.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)\* session | Pointer to the **Camera_CaptureSession** instance that transfers the callback.|
| int32_t exposureDuration | Exposure duration passed by the callback.|

### OH_CaptureSession_RegisterExposureInfoChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterExposureInfoChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnExposureDurationChange exposureDurationChange)
```

**Description**

Registers a callback to listen for exposure information changes. After the exposure parameters are modified, the system returns the updated exposure information.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_CaptureSession_OnExposureDurationChange](capi-capture-session-h.md#oh_capturesession_onexposuredurationchange) exposureDurationChange | Callback to listen for exposure duration changes to register.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterExposureInfoChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterExposureInfoChangeCallback(const Camera_CaptureSession* session, OH_CaptureSession_OnExposureDurationChange exposureDurationChange)
```

**Description**

Unregisters the callback to listen for exposure information changes. This method is called after the camera operation is complete.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_CaptureSession_OnExposureDurationChange](capi-capture-session-h.md#oh_capturesession_onexposuredurationchange) exposureDurationChange | Callback to listen for exposure duration changes to unregister.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_IsFocusModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session, Camera_FocusMode focusMode, bool* isSupported)
```

**Description**

Checks whether a focus mode is supported.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode) focusMode | Focus mode to check.|
| bool* isSupported | Pointer to the check result for the support of the focus mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetFocusMode()

```c
Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)
```

**Description**

Obtains the focus mode in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode)* focusMode | Pointer to the focus mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetFocusMode()

```c
Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)
```

**Description**

Sets a focus mode for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode) focusMode | Focus mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetFocusPoint()

```c
Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)
```

**Description**

Obtains the focal point in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Point](capi-oh-camera-camera-point.md)* focusPoint | Pointer to the focal point.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetFocusPoint()

```c
Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)
```

**Description**

Sets a focal point for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Point](capi-oh-camera-camera-point.md) focusPoint | Focal point to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetZoomRatioRange()

```c
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)
```

**Description**

Obtains the supported zoom ratio range.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* minZoom | Pointer to the minimum zoom ratio.|
| float* maxZoom | Pointer to the maximum zoom ratio.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetZoomRatio()

```c
Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)
```

**Description**

Obtains the zoom ratio in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* zoom | Pointer to the zoom ratio.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetZoomRatio()

```c
Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)
```

**Description**

Sets a zoom ratio for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float zoom | Target zoom ratio.<br> It takes some time for the zoom ratio to take effect at the bottom layer. To obtain the correct zoom ratio, you need to wait for one to two frames.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsVideoStabilizationModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode, bool* isSupported)
```

**Description**

Checks whether a video stabilization mode is supported. 

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode) mode | Video stabilization mode to check.|
| bool* isSupported | Pointer to the check result for the support of the video stabilization mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetVideoStabilizationMode()

```c
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode* mode)
```

**Description**

Obtains the video stabilization mode in use.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode)* mode | Pointer to the video stabilization mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetVideoStabilizationMode()

```c
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode)
```

**Description**

Sets a video stabilization mode for the device.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode) mode | Video stabilization mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_CanAddInput()

```c
Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session, Camera_Input* cameraInput, bool* isSuccessful)
```

**Description**

Checks whether a **Camera_Input** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the Camera_Input instance to check.|
| bool* isSuccessful | Pointer to the check result for whether the **Camera_Input** instance can be added to the session. **true** if it can be added to the session, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_CanAddPreviewOutput()

```c
Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **PreviewOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* cameraOutput | Pointer to the PreviewOutput instance to check.|
| bool* isSuccessful | Pointer to the check result for whether the PreviewOutput instance can be added to the session. **true** if it can be added to the session, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_CanAddPhotoOutput()

```c
Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **PhotoOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* cameraOutput | Pointer to the PhotoOutput instance to check.|
| bool* isSuccessful | Pointer to the check result for whether the PhotoOutput instance can be added to the session. **true** if it can be added to the session, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_CanAddVideoOutput()

```c
Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **VideoOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* cameraOutput | Pointer to the **Camera_VideoOutput** instance to add.|
| bool* isSuccessful | Pointer to the check result for whether the VideoOutput instance can be added to the session. **true** if it can be added to the session, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_CanPreconfig()

```c
Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, bool* canPreconfig)
```

**Description**

Checks whether a preconfigured resolution type is supported.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | Target preconfigured resolution type.|
| bool* canPreconfig | Pointer to the check result for the support of the preconfigured resolution type. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_CanPreconfigWithRatio()

```c
Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)
```

**Description**

Checks whether a preconfigured resolution type with an aspect ratio is supported.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | Target preconfigured resolution type.|
| [Camera_PreconfigRatio](capi-camera-h.md#camera_preconfigratio) preconfigRatio | Target preconfigured aspect ratio.|
| bool* canPreconfig | Pointer to the check result for the support of the preconfigured resolution type. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_Preconfig()

```c
Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType)
```

**Description**

Sets a preconfigured resolution type.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | Target preconfigured resolution type.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_PreconfigWithRatio()

```c
Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)
```

**Description**

Sets a preconfigured resolution type with an aspect ratio.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | Target preconfigured resolution type.|
| [Camera_PreconfigRatio](capi-camera-h.md#camera_preconfigratio) preconfigRatio | Target preconfigured aspect ratio.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_GetExposureValue()

```c
Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)
```

**Description**

Obtains the exposure value.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* exposureValue | Pointer to the exposure value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_GetFocalLength()

```c
Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)
```

**Description**

Obtains the current focal length.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* focalLength | Pointer to the focal length.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetFocusDistance()

```c
Camera_ErrorCode OH_CaptureSession_GetFocusDistance(const Camera_CaptureSession* session, float* focusDistance)
```

**Description**

Obtains the focus distance in use. The value range is [0.0, 1.0], where **0.0** indicates the shortest achievable focus distance and **1.0** indicates the longest focus distance. The default value is **1.0**.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| float* focusDistance | Focus distance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or input device may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetFocusDistance()

```c
Camera_ErrorCode OH_CaptureSession_SetFocusDistance(const Camera_CaptureSession* session, float focusDistance)
```

**Description**

Sets the focus distance. The value range is [0.0, 1.0], where **0.0** indicates the shortest achievable focus distance and **1.0** indicates the longest focus distance. The default value is **1.0**.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| float focusDistance | Focus distance to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or input device may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsFocusDistanceSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsFocusDistanceSupported(const Camera_CaptureSession* session, bool* isSupported)
```

**Description**

Checks whether the focus distance can be set.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| bool* isSupported | Whether the focus distance is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetSmoothZoom()

```c
Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session, float targetZoom, Camera_SmoothZoomMode smoothZoomMode)
```

**Description**

Sets smooth zoom.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float targetZoom | Target zoom ratio.|
| [Camera_SmoothZoomMode](capi-camera-h.md#camera_smoothzoommode) smoothZoomMode | Smooth zoom mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedColorSpaces()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)
```

**Description**

Obtains the supported color spaces.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| OH_NativeBuffer_ColorSpace** colorSpace | Double pointer to the list of supported color spaces, which are defined in the OH_NativeBuffer_ColorSpace struct, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of supported color spaces.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_DeleteColorSpaces()

```c
Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**Description**

Deletes color spaces.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)* colorSpace | Pointer to the list of color spaces, which are defined in the OH_NativeBuffer_ColorSpace struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_GetActiveColorSpace()

```c
Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**Description**

Obtains the active color space.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)* colorSpace | Pointer to the OH_NativeBuffer_ColorSpace instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetActiveColorSpace()

```c
Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace colorSpace)
```

**Description**

Sets the active color space.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace) colorSpace | Target OH_NativeBuffer_ColorSpace instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session, OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)
```

**Description**

Registers a callback to listen for device switching changes.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_CaptureSession_OnAutoDeviceSwitchStatusChange](capi-capture-session-h.md#oh_capturesession_onautodeviceswitchstatuschange) autoDeviceSwitchStatusChange | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session, OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)
```

**Description**

Unregisters the callback used to listen for device switching changes.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [OH_CaptureSession_OnAutoDeviceSwitchStatusChange](capi-capture-session-h.md#oh_capturesession_onautodeviceswitchstatuschange) autoDeviceSwitchStatusChange | Target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_IsAutoDeviceSwitchSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsAutoDeviceSwitchSupported(Camera_CaptureSession* session, bool* isSupported)
```

**Description**

Checks whether automatic device switching is supported.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool* isSupported | Pointer to the check result for the support of automatic device switching. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_EnableAutoDeviceSwitch()

```c
Camera_ErrorCode OH_CaptureSession_EnableAutoDeviceSwitch(Camera_CaptureSession* session, bool enabled)
```

**Description**

Enables or disables automatic device switching.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool enabled | Whether to enable or disable automatic switching. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_RegisterSystemPressureLevelChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)
```

**Description**

Registers a callback to listen for capture system pressure level changes.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnSystemPressureLevelChange](capi-capture-session-h.md#oh_capturesession_onsystempressurelevelchange) systemPressureLevelChange | Target callback, which is OH_CaptureSession_OnSystemPressureLevelChange.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterSystemPressureLevelChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)
```

**Description**

Unregisters the callback used to listen for capture system pressure level changes.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnSystemPressureLevelChange](capi-capture-session-h.md#oh_capturesession_onsystempressurelevelchange) systemPressureLevelChange | Target callback, which is OH_CaptureSession_OnSystemPressureLevelChange.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_SetQualityPrioritization()

```c
Camera_ErrorCode OH_CaptureSession_SetQualityPrioritization(Camera_CaptureSession* session, Camera_QualityPrioritization qualityPrioritization)
```

**Description**

Sets the priority level for video recording quality.<br> The default value is **HIGH_QUALITY**. Switching to **POWER_BALANCE** will compromise video recording quality to achieve lower power usage. The extent of power conservation achieved varies depending on the platform. It is recommended that this API be called between [OH_CaptureSession_CommitConfig](capi-capture-session-h.md#oh_capturesession_commitconfig) and [OH_CaptureSession_Start](capi-capture-session-h.md#oh_capturesession_start).

**Since**: 14

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_QualityPrioritization](capi-camera-h.md#camera_qualityprioritization) qualityPrioritization | Priority level to set. The default value is **HIGH_QUALITY**.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsMacroSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsMacroSupported(Camera_CaptureSession* session, bool* isSupported)
```

**Description**

Checks whether macro photography is supported.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool* isSupported | Pointer to the check result for the support of macro photography. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         **CAMERA_OK = 0**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_EnableMacro()

```c
Camera_ErrorCode OH_CaptureSession_EnableMacro(Camera_CaptureSession* session, bool enabled)
```

**Description**

Enables or disables macro photography for the camera device.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool enabled | Whether to enable or disable macro capability. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         **CAMERA_OK = 0**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.|

### OH_CaptureSession_SetWhiteBalance()

```c
Camera_ErrorCode OH_CaptureSession_SetWhiteBalance(Camera_CaptureSession* session, int32_t colorTemperature)
```

**Description**

Sets the white balance color temperature.<br> Before setting this parameter, you are advised to use [OH_CaptureSession_GetWhiteBalanceRange](capi-capture-session-h.md#oh_capturesession_getwhitebalancerange) to obtain the supported white balance color temperature range.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t colorTemperature | Color temperature, in Kelvin.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The setting is successful.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_GetColorTintRange()

```c
Camera_ErrorCode OH_CaptureSession_GetColorTintRange(const Camera_CaptureSession* session, int32_t *minColorTint, int32_t *maxColorTint)
```

**Description**

Obtains the supported white balance hue adjustment range.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t *minColorTint | Pointer to the minimum hue value.|
| int32_t *maxColorTint | Pointer to the maximum hue value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured when the API is called.|

### OH_CaptureSession_GetColorTint()

```c
Camera_ErrorCode OH_CaptureSession_GetColorTint(const Camera_CaptureSession* session, int32_t *colorTint)
```

**Description**

Obtains the white balance hue adjustment.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t *colorTint | Pointer to the hue value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured when the API is called.|

### OH_CaptureSession_SetColorTint()

```c
Camera_ErrorCode OH_CaptureSession_SetColorTint(Camera_CaptureSession* session, int32_t colorTint)
```

**Description**

Sets the white balance hue adjustment. Before setting this parameter, you are advised to use [OH_CaptureSession_GetColorTintRange](capi-capture-session-h.md#oh_capturesession_getcolortintrange) to obtain the supported white balance hue adjustment range.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t colorTint | Hue adjustment value.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured when the API is called.|

### OH_CaptureSession_GetWhiteBalance()

```c
Camera_ErrorCode OH_CaptureSession_GetWhiteBalance(Camera_CaptureSession* session, int32_t *colorTemperature)
```

**Description**

Obtains the white balance color temperature.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t *colorTemperature | Color temperature, in Kelvin.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The function is successfully called.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_GetWhiteBalanceMode()

```c
Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode* whiteBalanceMode)
```

**Description**

Obtains the white balance mode in use.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode)* whiteBalanceMode | Pointer to the white balance mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The function is successfully called.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_IsWhiteBalanceModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsWhiteBalanceModeSupported(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode, bool* isSupported)
```

**Description**

Checks whether the specified white balance mode is supported.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode) whiteBalanceMode | White balance mode.|
| bool* isSupported | Pointer to the check result for the support of the specified white balance mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The function is successfully called.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_SetWhiteBalanceMode()

```c
Camera_ErrorCode OH_CaptureSession_SetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode)
```

**Description**

Sets a white balance mode.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode) whiteBalanceMode | Pointer to the white balance mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The setting is successful.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_GetWhiteBalanceRange()

```c
Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceRange(Camera_CaptureSession* session, int32_t *minColorTemperature, int32_t *maxColorTemperature)
```

**Description**

Obtains the supported white balance color temperature range.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| int32_t *minColorTemperature | Pointer to the minimum supported color temperature, in Kelvin.|
| int32_t *maxColorTemperature | Pointer to the maximum supported color temperature, in Kelvin.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The function is successfully called.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.|

### OH_CaptureSession_IsControlCenterSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsControlCenterSupported(Camera_CaptureSession* session, bool* isSupported)
```

**Description**

Checks whether the camera controller is supported.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool* isSupported | Pointer to the check result for the support of the camera controller. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK = 0**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedEffectTypes()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedEffectTypes(Camera_CaptureSession* session, Camera_ControlCenterEffectType** types, uint32_t* size)
```

**Description**

Obtains the effect types supported by the camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_ControlCenterEffectType](capi-camera-h.md#camera_controlcentereffecttype)** types | Double pointer to the list of supported effect types, which are defined in the Camera_ControlCenterEffectType struct, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of supported effect types.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_DeleteSupportedEffectTypes()

```c
Camera_ErrorCode OH_CaptureSession_DeleteSupportedEffectTypes(Camera_CaptureSession* session, Camera_ControlCenterEffectType* types, uint32_t size)
```

**Description**

Deletes the effect types supported by the camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| [Camera_ControlCenterEffectType](capi-camera-h.md#camera_controlcentereffecttype)* types | Pointer to the list of effect types, which are defined in the Camera_ControlCenterEffectType struct.|
| uint32_t size | Size of the list of supported effect types.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_EnableControlCenter()

```c
Camera_ErrorCode OH_CaptureSession_EnableControlCenter(Camera_CaptureSession* session, bool enabled)
```

**Description**

Enables or disables the camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| bool enabled | Whether to enable the camera controller. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK = 0**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)
```

**Description**

Registers a callback to listen for effect status changes of a camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnControlCenterEffectStatusChange](capi-capture-session-h.md#oh_capturesession_oncontrolcentereffectstatuschange) controlCenterEffectStatusChange | Target callback, which is OH_CaptureSession_OnControlCenterEffectStatusChange.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)
```

**Description**

Unregisters the callback used to listen for effect status changes of a camera controller.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance that transfers the callback.|
| [OH_CaptureSession_OnControlCenterEffectStatusChange](capi-capture-session-h.md#oh_capturesession_oncontrolcentereffectstatuschange) controlCenterEffectStatusChange | Target callback, which is OH_CaptureSession_OnControlCenterEffectStatusChange.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_OnMacroStatusChange()

```c
 typedef void (*OH_CaptureSession_OnMacroStatusChange)(Camera_CaptureSession* session, bool isMacroDetected)
```

**Description**

Defines the callback used to listen for macro status changes of a camera session.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance.|
| bool isMacroDetected | Whether the camera is in macro mode. **true** if the camera is in macro mode, **false** otherwise.|

### OH_CaptureSession_RegisterMacroStatusChangeCallback()

```c
 Camera_ErrorCode OH_CaptureSession_RegisterMacroStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnMacroStatusChange macroStatusChange)
```

**Description**

Registers a callback to listen for macro status changes of a camera session.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance.|
| [OH_CaptureSession_OnMacroStatusChange](capi-capture-session-h.md#oh_capturesession_onmacrostatuschange) macroStatusChange | Callback used to return the macro status change.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterMacroStatusChangeCallback()

```c
 Camera_ErrorCode OH_CaptureSession_UnregisterMacroStatusChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnMacroStatusChange macroStatusChange)
```

**Description**

Unregisters the callback used to listen for macro status changes of a camera session.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance.|
| [OH_CaptureSession_OnMacroStatusChange](capi-capture-session-h.md#oh_capturesession_onmacrostatuschange) macroStatusChange | Callback used to return the macro status change.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_OnIsoChange()

```c
typedef void (*OH_CaptureSession_OnIsoChange)(Camera_CaptureSession* session, int32_t isoValue)
```

**Description**

Defines the callback used to listen for ISO changes in a camera session.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| int32_t isoValue | ISO value obtained in the callback.|

### OH_CaptureSession_RegisterIsoChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterIsoChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnIsoChange isoChange)
```

**Description**

Registers a callback to listen for ISO changes.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance.|
| [OH_CaptureSession_OnIsoChange](capi-capture-session-h.md#oh_capturesession_onisochange) isoChange | Callback of the **OH_CaptureSession_OnIsoChange** type, which is used to listen for ISO changes.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterIsoChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterIsoChangeCallback(Camera_CaptureSession* session, OH_CaptureSession_OnIsoChange isoChange)
```

**Description**

Unregisters the callback used to listen for ISO changes.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the Camera_CaptureSession instance.|
| [OH_CaptureSession_OnIsoChange](capi-capture-session-h.md#oh_capturesession_onisochange) isoChange | Callback of the **OH_CaptureSession_OnIsoChange** type, which is used to listen for ISO changes.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_GetRAWCaptureZoomRatioRange()

```c
Camera_ErrorCode OH_CaptureSession_GetRAWCaptureZoomRatioRange(const Camera_CaptureSession* session, float* minZoom, float* maxZoom)
```

**Description**

Obtains the supported zoom range of the physical camera during shooting in RAW format.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| float* minZoom | Minimum zoom ratio.|
| float* maxZoom | Maximum zoom ratio.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed. The session or camera status may be abnormal.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_IsOISModeSupported()

```c
Camera_ErrorCode OH_CaptureSession_IsOISModeSupported(const Camera_CaptureSession* session, OH_Camera_OISMode oisMode, bool* isSupported)
```

**Description**

Checks whether the optical image stabilization (OIS) mode is supported.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_OISMode](capi-camera-h.md#oh_camera_oismode) oisMode | OIS mode to check.|
| bool* isSupported | Whether the device supports the mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetSupportedOISBiasRange()

```c
Camera_ErrorCode OH_CaptureSession_GetSupportedOISBiasRange(const Camera_CaptureSession* session, OH_Camera_OISAxes oisAxis, float* minBias, float* maxBias, float* step)
```

**Description**

Obtains the offset range supported on the specified OIS axis.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_OISAxes](capi-camera-h.md#oh_camera_oisaxes) oisAxis | OIS axis.|
| float* minBias | Minimum offset.|
| float* maxBias | Maximum offset.|
| float* step | Offset step.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetCurrentOISMode()

```c
Camera_ErrorCode OH_CaptureSession_GetCurrentOISMode(const Camera_CaptureSession* session, OH_Camera_OISMode* oisMode)
```

**Description**

Obtains the OIS mode.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_OISMode](capi-camera-h.md#oh_camera_oismode)* oisMode | OIS mode.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_GetCurrentCustomOISBias()

```c
Camera_ErrorCode OH_CaptureSession_GetCurrentCustomOISBias(const Camera_CaptureSession* session, float* pitchBias, float* yawBias)
```

**Description**

Obtains the custom offsets on all OIS axes.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| float* pitchBias | Offset on the pitch axis.|
| float* yawBias | Offset on the yaw axis.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetOISMode()

```c
Camera_ErrorCode OH_CaptureSession_SetOISMode(const Camera_CaptureSession* session, OH_Camera_OISMode oisMode)
```

**Description**

Sets the OIS mode.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| [OH_Camera_OISMode](capi-camera-h.md#oh_camera_oismode) oisMode | OIS mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_SetOISModeCustom()

```c
Camera_ErrorCode OH_CaptureSession_SetOISModeCustom(const Camera_CaptureSession* session, float pitchBias, float yawBias)
```

**Description**

Sets the custom offset for an OIS axis.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance.|
| float pitchBias | Offset on the pitch axis.|
| float yawBias | Offset on the yaw axis.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_OnExposureStateChange()

```c
typedef void (*OH_CaptureSession_OnExposureStateChange)(void* context, OH_Camera_ExposureState exposureState)
```

**Description**

Defines a callback to be invoked when the exposure state changes.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| (void\* context | Pointer to the custom context.|
| [OH_Camera_ExposureState](capi-camera-h.md#oh_camera_exposurestate) exposureState | Current exposure state.|

### OH_CaptureSession_RegisterExposureStateChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_RegisterExposureStateChangeCallback(const Camera_CaptureSession* session, void* context, OH_CaptureSession_OnExposureStateChange callback)
```

**Description**

Registers a callback function to listen for exposure state changes. This callback is invoked when the exposure state in the capture session changes.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session |  Pointer to the target Camera_CaptureSession instance.|
| void* context | Pointer to the custom context.|
| [OH_CaptureSession_OnExposureStateChange](capi-capture-session-h.md#oh_capturesession_onexposurestatechange) callback | Triggered when the playback state changes.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_UnregisterExposureStateChangeCallback()

```c
Camera_ErrorCode OH_CaptureSession_UnregisterExposureStateChangeCallback(const Camera_CaptureSession* session, void* context, OH_CaptureSession_OnExposureStateChange callback)
```

**Description**

Unregisters a callback to be invoked when the exposure state changes.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the target Camera_CaptureSession instance.|
| void* context | Pointer to the custom context specified during callback registration.|
| [OH_CaptureSession_OnExposureStateChange](capi-capture-session-h.md#oh_capturesession_onexposurestatechange) callback | Triggered when the playback state changes.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_GetZoomPointInfos()

```c
Camera_ErrorCode OH_CaptureSession_GetZoomPointInfos(const Camera_CaptureSession* session, uint32_t* size, OH_Camera_ZoomPointInfo** zoomPointInfo)
```

**Description**

Obtains the zoom information.<br> You need to call [OH_CaptureSession_DeleteZoomPointInfos](capi-capture-session-h.md#oh_capturesession_deletezoompointinfos) to release the memory for storing the zoom information.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the capture session object.|
| uint32_t* size | Output parameter, which returns the number of queried zoom information records.|
| [OH_Camera_ZoomPointInfo](capi-oh-camera-oh-camera-zoompointinfo.md)** zoomPointInfo | Output parameter, which returns an array of queried zoom information records.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.|

### OH_CaptureSession_DeleteZoomPointInfos()

```c
Camera_ErrorCode OH_CaptureSession_DeleteZoomPointInfos(const Camera_CaptureSession* session, OH_Camera_ZoomPointInfo* zoomPointInfo)
```

**Description**

Deletes the zoom information.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the capture session object.|
| [OH_Camera_ZoomPointInfo](capi-oh-camera-oh-camera-zoompointinfo.md)* zoomPointInfo | Array of zoom information records to be deleted. The memory is released after the API is called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CaptureSession_IsLockFocusTrackingSupported()

```c
bool OH_CaptureSession_IsLockFocusTrackingSupported(const Camera_CaptureSession* session)
```

**Description**

Checks whether locking focus tracking is supported.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether focus tracking is supported. The value **true** indicates that focus tracking is supported, and the value **false** indicates that focus tracking is not supported. |

### OH_CaptureSession_LockFocusTracking()

```c
Camera_ErrorCode OH_CaptureSession_LockFocusTracking(Camera_CaptureSession* session, Camera_Point focusPoint)
```

**Description**

Locks focus tracking. You can unlock focus tracking by calling [OH_CaptureSession_UnlockFocusTracking](#oh_capturesession_unlockfocustracking).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance. |
| [Camera_Point](capi-oh-camera-camera-point.md) focusPoint | Focus point locked for tracking. |

**Returns**

| Type | Description |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) |   **CAMERA_OK**: The operation is successful.<br>   **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal. |

### OH_CaptureSession_UnlockFocusTracking()

```c
Camera_ErrorCode OH_CaptureSession_UnlockFocusTracking(Camera_CaptureSession* session)
```

**Description**

Unlocks focus tracking.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [const Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Pointer to the **Camera_CaptureSession** instance. |

**Returns**

| Type | Description |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>   **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal. |