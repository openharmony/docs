# Window Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 1300001 Repeated Operation
**Error Message**

Repeated operation.

**Description**

This error code is reported when a repeated operation is performed.

**Possible Causes**
1. The window has been created.
2. The window is in the current state.

**Solution**

Before creating a window, check whether the window has been created or is in the current state.

## 1300002 Abnormal Window State
**Error Message**

This window state is abnormal.

**Description**

This error code is reported when you operate a window in an abnormal state, for example, a window that is not created yet or has been destroyed.

**Possible Causes**

The window to operate is not created or has been destroyed.

**Solution**

Operate the window that exists.

## 1300003 Abnormal Window Manager Service
**Error Message**

This window manager service works abnormally.

**Description**

This error code is reported when the window manager service is abnormal.

**Possible Causes**

The internal services of the window are not started normally.

**Solution**

Try again later or restart the device.

## 1300004 Unauthorized Operation
**Error Message**

Unauthorized operation.

**Description**

This error code is reported when the API does not have the required permissions to operate an object.

**Possible Causes**

The window object of another process is operated.

**Solution**

Check whether unauthorized operations are performed on the object of another process. If yes, delete the operations.

## 1300005 Abnormal Window Stage
**Error Message**

This window stage is abnormal.

**Description**

This error code is reported when you operate a WindowStage in the abnormal state, for example, a WindowStage that has been destroyed.

**Possible Causes**

The WindowStage is not created or has been destroyed.

**Solution**

Before operating a WindowStage, check whether it exists.

## 1300006 Abnormal Window Context
**Error Message**

This window context is abnormal.

**Description**

This error code is reported when you operate a window context in the abnormal state, for example, a window context that has been destroyed.

**Possible Causes**

The window context has been destroyed when being operated.

**Solution**

Before operating the window context, check whether it exists.

## 1300007 Application Startup Failure by WindowExtensionAbility

**Error Message**

Failed to start the ability.

**Description**

This error code is reported when a WindowExtensionAbility fails to start an application.

**Possible Causes**

Incorrect parameters are passed into the API used by the WindowExtensionAbility to start the application.

**Solution**

Pass in the correct parameters.

## 1300008 Display Device Exception

**Error Message**

The display device is abnormal.

**Description**

This error code is reported when the display device is abnormal.

**Possible Causes**

1. The display device is not ready.
2. The display device is removed.
3. The display device is damaged.

**Solution**

Ensure that the display device is normal.

## 1300009 Invalid Parent Window

**Error Message**

The parent window is invalid.

**Description**

This error code is reported when the parent window is invalid.

**Possible Causes**

1. No parent window is bound.
2. The parent window bound is abnormal. For example, the parent window has been destroyed.

**Solution**

1. Ensure that the subwindow is bound to the parent window.
2. Ensure that the status of the parent window is normal.

## 1300010 Unsupported Operation in the Current Window Mode

**Error Message**

The operation in the current window status is invalid.

**Description**

This error code is reported when the operation is not supported in the current window mode.

**Possible Causes**

1. Perform the move operation in the full-screen or split-screen window.
2. Perform the resize operation in the full-screen or split-screen window.

**Solution**

1. Do not move the full-screen or split-screen window.
2. Do not resize the full-screen or split-screen window.

## 1300011 Failure in Destroying a PiP Window

**Error Message**

Failed to destroy the PiP window.

**Description**

This error code is reported when destroying a PiP window fails.

**Possible Causes**

The pointer to the PiP window is null.

**Solution**

No action is required.

## 1300012 Abnormal PiP Window Status

**Error Message**

The PiP window state is abnormal.

**Description**

This error code is reported when the PiP window status is abnormal.

**Possible Causes**

The PiP window status is abnormal.

**Solution**

No action is required.

## 1300013 Failure in Creating a PiP Window

**Error Message**

Failed to create the PiP window.

**Description**

This error code is reported when creating a PiP window fails.

**Possible Causes**

1. Incorrect parameters are passed in to create the PiP window.
2. Attempt to start PiP in a non-full-screen window.

**Solution**

1. Correct the input parameters.
2. Do not start PiP in a non-full-screen window.

## 1300014 PiP Internal Error

**Error Message**

PiP internal error.

**Description**

This error code is reported when an internal error occurs in PiP.

**Possible Causes**
1. The window on which the PiP feature depends is abnormal or empty.
2. The PiP controller is abnormal.

**Solution**

No action is required.

## 1300015 Repeated PiP Operations

**Error Message**

Repeated PiP operation.

**Description**

This error code is reported when a repeated PiP operation is performed.

**Possible Causes**

The PiP window has been started or closed.

**Solution**

Do not start or stop PiP repeatedly.

## 1300016 Parameter Verification Error

**Error Message**

Parameter validation error.

**Description**

This error code is reported when parameters are incorrect. For example, the parameter value exceeds the allowed range, the length of the string or array does not meet the requirements, or the parameter format is incorrect.

**Possible Causes**

1. The parameter value is out of range.

2. The parameter length exceeds the allowed limits.

3. The parameter format is incorrect.

**Solution**

Verify that the parameters adhere to the required standards.

## 1300017 Filter Controller Calling Error

**Error Message**

Incorrect filter calling.

**Description**

This error code is reported when the filter controller is invalidly invoked. For example, the invoking sequence is incorrect.

**Possible Causes**

**setBackgroundFilter** is called after **animateBackgroungFilter**.

**Solution**

Check the order of operations to ensure that **setBackgroundFilter** is called before **animateBackgroungFilter**.

## 1300018 API Call Timeout

**Error Message**

API call timed out.

**Description**

This error code is reported when the API call times out.

**Possible Causes**

The wait time for a synchronous API call exceeds the upper limit.

**Solution**

The solution will vary based on the specific context. Typical approaches are:

1. Retry the API call a limited number of times.

2. Implement fallback measures, such as using cached data or alternative logic.

3. Abort the current processing logic.

## 1300019 Floating Ball Parameter Verification Error

**Error Message**

Wrong parameters for operating the floating ball.

**Description**

This error code is reported when parameters are incorrect. For example, the parameter value exceeds the allowed range, the length of the string or array does not meet the requirements, or the parameter format is incorrect.

**Possible Causes**

1. The parameter value is out of range.

2. The parameter length exceeds the allowed limits.

3. The parameter format is incorrect.

**Solution**

1. Ensure that the parameter value is within the allowed range.

2. Ensure that the parameter length is within the allowed limits.

3. Use the correct format for parameters.

## 1300020 Failure in Creating a Floating Ball Window

**Error Message**

Failed to create the floating ball window.

**Description**

This error code is reported when creating a floating ball window fails.

**Possible Causes**

1. Incorrect parameters are passed in to start the floating ball.

2. Attempt to start the floating ball on an unsupported device.

3. Attempt to start the floating ball when the application is in the background.

**Solution**

1. Check the parameters before starting the floating ball.

2. Verify that the device supports the floating ball before starting it.

3. Ensure that the application is in the foreground before starting the floating ball.

## 1300021 Failure in Starting Multiple Floating Balls

**Error Message**

Failed to start multiple floating ball windows.

**Description**

This error code is reported when starting multiple floating balls fails.

**Possible Causes**

Multiple floating ball controllers are created for the same application.

**Solution**

An application should create only one floating ball controller to start the floating ball. You are advised to use a singleton pattern to hold the floating ball controller.

## 1300022 Repeated Floating Ball Operation

**Error Message**

Repeated floating ball operation.

**Description**

This error code is reported when a repeated operation is performed on the floating ball.

**Possible Causes**

1. Attempt to start the floating ball while it is already running.

2. Attempt to stop the floating ball after it has already stopped.

3. Attempt to register the floating ball callback multiple times.

**Solution**

1. Check whether the floating ball is already running before starting it.

2. Check whether the floating ball has already stopped before stopping it.

3. Ensure that the callback is not already registered before registering the floating ball callback.

## 1300023 Internal Error of the Floating Ball

**Error Message**

Floating ball internal error.

**Description**

This error code is reported when an internal error occurs in the floating ball.

**Possible Causes**

1. The window on which the floating ball depends is abnormal or empty.

2. The floating ball controller is abnormal or empty.

**Solution**

1. Check the window of the floating ball to ensure it is not empty.

2. Check the status of the floating ball controller to ensure it is not empty.

## 1300024 Abnormal Floating Ball Window State

**Error Message**

The floating ball window state is abnormal.

**Description**

This error code is reported when the floating ball window state is abnormal.

**Possible Causes**

The floating ball window may not have been created or may have been destroyed.

**Solution**

Check that the floating ball window has been created and is not destroyed.

## 1300025 Unsupported Operation in the Current Floating Ball State

**Error Message**

The floating ball state does not support this operation.

**Description**

This error code is reported when the operation is not supported in the current floating ball state.

**Possible Causes**

1. Attempt to update the floating ball when it is not active.

2. Attempt to query window information when the floating ball is not active.

3. Attempt to launch an application window when the floating ball is not active.

4. Attempt to start the floating ball before the stop process is complete.

**Solution**

1. Check whether the floating ball is active before updating it.

2. Check whether the floating ball is active before querying window information.

3. Check whether the floating ball is active before launching an application window.

4. Wait for the floating ball to stop completely before restarting it.

## 1300026 Failure in Launch an Application Window via a Floating Ball

**Error Message**

Failed to restore the main window.

**Description**

This error code is reported when launching an application window via the floating ball fails.

**Possible Causes**

1. Incorrect parameters are passed.

2. The application window is not launched within 5 seconds after clicking.

3. Attempt to launch a window that belongs to another application.

**Solution**

1. Check the parameters used to launch the application window.

2. Ensure to launch the application window within 5 seconds after clicking.

3. Launch the window that belongs to the current application.

## 1300027 Cannot Change Template Type When Updating the Floating Ball

**Error Message**

When updating the floating ball, the template type cannot be changed.

**Description**

This error code is reported when changing the template type fails.

**Possible Causes**

The template type used during the update is inconsistent with the one used during creation.

**Solution**

Ensure that the template type used when updating the floating ball matches the one used when it was created.

## 1300028 Floating Ball Based on a Static Template Cannot Be Updated

**Error Message**

Updating static template-based floating balls is not supported.

**Description**

This error code is reported when users attempt to update a floating ball based on a static template.

**Possible Causes**

Updating floating balls based on static templates is not supported.

**Solution**

Delete any existing floating balls based on static templates and create new ones.

## 1001 Window Null Pointer Exception<sup>(deprecated)</sup>
**Error Message**

A window null pointer occurs.

**Description**

This error code is reported when you operate a window pointed to by a null pointer.

**Possible Causes**

A null pointer is used.

**Solution**

Operate the window that exists.

## 1002 Invalid Window Type<sup>(deprecated)</sup>
**Error Message**

This window type is invalid.

**Description**

This error code is reported when the window type is invalid.

**Possible Causes**

An invalid window type is used. For details about valid window types, see [WindowType](arkts-apis-window-e.md#windowtype7).

**Solution**

Use a window type supported.

## 1003 Invalid Window Parameter<sup>(deprecated)</sup>
**Error Message**

This window parameter is invalid.

**Description**

This error code is reported when a window parameter is invalid.

**Possible Causes**

Invalid parameters are passed in.

**Solution**

Correct the parameters.

## 1004 Ability Service Exception<sup>(deprecated)</sup>
**Error Message**

This system ability service works abnormally.

**Description**

This error code is reported when the ability service is abnormal.

**Possible Causes**

When the window is destroyed, the proxy fails to be initialized.

**Solution**

Restart the device and try again.

## 1005 IPC Failure<sup>(deprecated)</sup>
**Error Message**

This window IPC failed.

**Description**

This error code is reported when IPC fails.

**Possible Causes**

The window parameters fail to be transferred.

**Solution**

Before operating a window, ensure that the client and server services in the window are normal.

## 1007 Application Startup Failure by WindowExtensionAbility<sup>(deprecated)</sup>
**Error Message**

Failed to start the ability.

**Description**

This error code is reported when a WindowExtensionAbility fails to start an application.

**Possible Causes**

Incorrect parameters are passed into the API used by the WindowExtensionAbility to start the application.

**Solution**

Pass in the correct parameters.
