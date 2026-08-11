# Pressure Management (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=abc0089348a50a5b847f5d0ffe23935755465c25 translatedAt=2026-08-10T09:21:06.518Z pushedAt=2026-08-10T13:43:52.628Z -->

Starting from API version 20, the camera framework supports monitoring of system pressure levels.

In scenarios requiring prolonged camera usage (such as live streaming), applications can dynamically adjust image quality parameters (such as the frame rate or resolution) based on system pressure level changes. This helps balance power consumption, heat generation, and system load, ensuring stable and extended camera functionality.

## Status Listening

To monitor system pressure status changes, register the [OH_CaptureSession_OnSystemPressureLevelChange](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_onsystempressurelevelchange) callback.

When the system pressure level changes, the callback returns the **Camera_SystemPressureLevel** parameter.

For details about this parameter, see [Camera_SystemPressureLevel](../../reference/apis-camera-kit/capi-camera-h.md#camera_systempressurelevel).

<!-- @[system_pressure_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

``` C++
void SystemPressureLevelChangeCallback(Camera_CaptureSession *captureSession,
    Camera_SystemPressureLevel systemPressureLevel)
{
    OH_LOG_INFO(LOG_APP, "SystemPressureLevelChangeCallback level: %{public}d", systemPressureLevel);
}

Camera_ErrorCode NDKCamera::RegisterSystemPressureCallback()
{
    Camera_ErrorCode ret = OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(
        captureSession_, SystemPressureLevelChangeCallback);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP,
            "OH_CaptureSession_RegisterSystemPressureLevelChangeCallback failed.");
    }
    return ret;
}
```