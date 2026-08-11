# Session Configuration Issues

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=46a890d188d7f6818c431e97e537193ed2cefcf2 translatedAt=2026-08-10T09:16:19.420Z pushedAt=2026-08-10T12:30:45.672Z -->

## Symptom

The camera fails to start normally, and the session-related process reports errors.

## Possible Causes

The session configuration process consists of four steps: `beginConfig`, `addInput`, `addOutput`, and `commitConfig`. The calling sequence of these steps cannot be changed, and all four steps must be configured successfully for the camera to work properly. Possible causes include the following:

1. [beginConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#beginconfig11) fails.

2. [addInput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addinput11) fails.

3. [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) fails.

4. [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) fails.

**Problem Analysis Steps**

Step 1: `beginConfig` may fail for the following reasons: calling this API while the session is in `commitConfig`; a null pointer exception when the session object does not exist.

Step 2: `addInput` can only be called after the session calls `beginConfig`. It cannot be modified after `commitConfig`. Each session can be configured with only one input, and a null check is performed.

Step 3: `addOutput` can only be configured when the session is in the `beginConfig` state, after `addInput`, and before `commitConfig`. It checks the current profile to verify whether it matches the input. You can use `ValidateOutputProfile` to view the corresponding output profile content. A null check is performed.

Step 4: After the preceding configurations are confirmed, call `commitConfig` to submit the configuration to the underlying layer and connect the channels of the input stream and output stream, so that images can be returned to the app through the channels.

Related log search keywords: `beginConfig`|`addInput`|`addOutput`|`commitConfig`

## Solution

1. If `beginConfig` fails, check whether the session has been released or whether the session is currently performing a `commitConfig` operation.

2. Before calling the `addInput` API, you can call the `canAddInput` API to verify whether the current session can add an input.

3. Before calling the `addOutput` API, you can call the `canAddOutput` API to verify whether the current session can add an output.

4. When calling `commitConfig`, ensure that none of the preceding steps have failed and that the `session` has not been released or used for other operations during this process.

For normal session configuration, see [Photo Capture (ArkTS)](camera-shooting.md).