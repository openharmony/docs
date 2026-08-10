# Camera Preview Rotation Issues

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=46a890d188d7f6818c431e97e537193ed2cefcf2 translatedAt=2026-08-10T09:16:02.855Z pushedAt=2026-08-10T12:12:44.488Z -->

## Symptom

When an app opens the camera, the preview screen may be rotated incorrectly, preventing the camera from working properly.

## Possible Causes

Camera preview rotation occurs in two scenarios: calling the preview rotation API during session configuration, and correcting the preview angle when the camera window rotates. If the rotation angle is not adjusted accordingly in the corresponding scenario, the preview image will appear at an incorrect rotation angle. The specific causes may include the following:

1. During session configuration, the camera preview rotation APIs are not adapted: [getPreviewRotation](../../reference/apis-camera-kit/arkts-apis-camera-PreviewOutput.md#getpreviewrotation12) and [setPreviewRotation](../../reference/apis-camera-kit/arkts-apis-camera-PreviewOutput.md#setpreviewrotation12).

2. The timing during session configuration is incorrect; that is, session [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) is not completed before calling the camera preview rotation APIs.

3. When the camera window rotates, the camera preview rotation APIs are not adapted.

4. The API input parameters of `getPreviewRotation` and `setPreviewRotation` are incorrect.

**Troubleshooting Steps**

Step 1: Confirm whether `getPreviewRotation` and `setPreviewRotation` are correctly called after `commitConfig` is invoked for the session configuration.

Step 2: If the following error occurs, it indicates that `commitConfig` was not completed for the session before the camera preview rotation API was called during session configuration.

Related log: PreviewOutput GetPreviewOutputRotation error!, session is nullptr|PreviewRotation call failed. error code: 7400201

Step 3: Check whether `Display` object changes are monitored to perceive the current window state. When the camera window rotates, call `getPreviewRotation` and `setPreviewRotation` to correct the preview stream angle.

Step 4: The API input parameter of `getPreviewRotation` is the rotation angle of the current camera window, which is obtained through `display.getDefaultDisplaySync.rotation`. In the API input parameters of `setPreviewRotation`, `previewRotation` is the output of `getPreviewRotation`. `isDisplayLocked` must be consistent with the setting of `setXComponentSurfaceRotation`.

Related log search keywords: `GetPreviewRotation|SetPreviewRotation|session is nullptr`

## Case Analysis

**Symptom**

When the scan feature was opened in a floating window, the preview image was rotated by an extra 90 degrees during landscape-portrait switching.

**Problem Analysis**

When the camera was opened in a floating window, the preview rotation API was adapted during session configuration. The preview rotation was normal upon cold start, but the preview image was rotated by 90 degrees when the screen switched between landscape and portrait orientations.

Log analysis revealed the cause: the app called `getPreviewRotation`/`setPreviewRotation` to adjust the preview stream angle before the camera window was rotated.

**Conclusion**

The app did not call `getPreviewRotation` or `setPreviewRotation` to correct the preview stream angle when the camera window rotated.

**Fix Suggestion**

When the camera window rotates, call `getPreviewRotation` and `setPreviewRotation` to correct the preview stream angle.

Reference: [Adapting Camera Rotation Angle (ArkTS)](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/camera-rotation-angle-adaptation#preview).

## Preventive Measures

The preview rotation API must be used during session configuration. It is recommended that you call it after the session calls the `commitConfig` API and before the `start` API.

When using the camera, the app listens for `Display` object changes to perceive the current window state. If the current camera window rotates, you need to correct the preview stream angle. It is recommended that you create the listener immediately after calling the preview rotation API during session configuration.

Reference: [Adapting Camera Rotation Angle (ArkTS)](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/camera-rotation-angle-adaptation#preview)