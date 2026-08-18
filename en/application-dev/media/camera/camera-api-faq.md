# Camera API Call Sequence Issues

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=46a890d188d7f6818c431e97e537193ed2cefcf2 translatedAt=2026-08-10T09:11:48.779Z pushedAt=2026-08-10T09:59:18.347Z -->

## Symptom

The camera fails to start normally, and related logs indicate issues such as failed checks or parameter errors.

## Possible Causes

The normal camera startup process includes creating a camera manager (`cameraManager`), creating input and output streams, creating a session, configuring the session, and starting the session. These steps are interdependent. If any part fails to be created, is released during the process (resulting in a nonexistent object), or uses a mismatched profile, the camera cannot start properly. For example, an output stream may be created without first creating an input stream, or the output stream may be created without using the capabilities obtained from the corresponding input stream, causing a mismatch between the input and output streams. Specific causes may include the following:

1. An incorrect profile is used, causing the created output stream to mismatch the input stream, which results in a black screen when the camera starts.

2. Camera configuration APIs are called prematurely, before the corresponding configuration is fully set, causing the camera to fail to start.

3. The listener is registered at the wrong time, so it does not take effect, causing the camera to fail to start.

**Problem Analysis Steps**

Step 1: Create a camera manager ([cameraManager](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md)), select the camera device to use ([getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras)), and then obtain the output stream profile ([getSupportedOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedoutputcapability11)) through the selected camera device. Ensure that the profile matches the output stream mode (photo capture or video recording).

Step 2: Create the corresponding input stream based on the profile, call the [open](../../reference/apis-camera-kit/arkts-apis-camera-CameraInput.md#open) method of the input stream to open the camera device, and then create the output streams (preview, photo capture/video recording). It is recommended to register the photoAvailable listener at this point to obtain photos. Keep the resolutions of the output streams the same, and then create a session of the corresponding mode. Ensure that the mode matches the output streams.

Step 3: Call the [beginConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#beginconfig11) method of the session to start configuration. First, call the [addInput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addinput11) method to add the input stream. Then, call the [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) method to add the output streams. After that, call the [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) method to commit the session configuration. At this point, the session configuration is complete. Most issues are reported during this process. If a problem occurs, the entire [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) process cannot be completed normally.

Step 4: After [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11), most session listener methods can be configured at this stage, and certain effect settings, such as white balance, can be applied.

## Solution

1. Before creating the output stream and input stream, compare the resolutions in their profiles to ensure they are consistent.

2. Most set methods are recommended to be called after `commitConfig`, such as the set APIs related to white balance.

3. Most listener-related APIs must be called after `addInput` to ensure that data can be returned through the listener after the camera is opened and added to the session.

For specific code, refer to [Photo Capture Practices (ArkTS)](camera-shooting-case.md).