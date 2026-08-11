# Camera Preview Stream Startup Issues

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=46a890d188d7f6818c431e97e537193ed2cefcf2 translatedAt=2026-08-10T09:15:13.109Z pushedAt=2026-08-10T12:01:48.538Z -->

## Symptom

When the app opens the camera, a black screen or image stretching occurs, preventing the camera from functioning properly.

## Possible Causes

The preview stream (`previewOutput`) in the camera process consists of three stages: creation, addition, and startup. Dependencies exist between these stages. If a previous stage fails, subsequent stages will also fail, resulting in a black screen on the camera. Possible causes include the following:

1. The `SurfaceId` is not correctly passed in, causing the image to fail to display properly.

2. [createPreviewOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput) fails, or the `profile` used does not match the `cameraDevice`.

3. [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) fails, causing the output to not be successfully configured into the `session`.

4. The resolution ratio of `previewOutput` is inconsistent with that of `photoOutput`/`videoOutput`.

**Analysis Steps**

Step 1: Print the `surfaceId` within the app and compare it with internal logs to check whether the `surfaceId` matches, or search for previewOutput surface-related logs to check whether the `surfaceId` is normal. When creating preview, photo, and video outputs, use profiles with the same resolution ratio.

Step 2: If the profile configuration is incorrect, logs related to `ValidCreateOutputStream` will appear. If the width and height of the camera profile differ from those of the display component (such as XComponent), the image will appear stretched.

Step 3: When calling [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11), timing detection is performed. The configuration can only be made after the session enters `beginConfig` and `addInput` is called, and before `commitConfig`. You can use `ValidateOutputProfile` to view the profile content of the corresponding `previewOutput`.

Log search keywords: `CreatePreviewOutput`|`ValidCreateOutputStream`|`CanAddOutput`|`ValidateOutputProfile`

## Solution

1. Perform a null and validity check on the input parameter `surfaceId` to ensure that the image can be displayed correctly.

2. If a `profile` parameter is passed, use the `getSupportedOutputCapability` method to obtain the profile of the corresponding input, and ensure that `mode` and `cameraDevice` are correctly matched.

3. Before calling `addOutput`, call the `canAddOutput` method to ensure that the output can be added to the session properly. If any issue is detected, recreate the output and add it again in a timely manner.

4. Before setting `previewOutput` and `photoOutput`/`videoOutput`, compare their profiles to ensure that both have the same resolution.