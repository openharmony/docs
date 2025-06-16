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

This error code is reported when you operate a window stage in the abnormal state, for example, a window stage that has been destroyed.

**Possible Causes**

The window stage is not created or has been destroyed.

**Solution**

Before operating a window stage, check whether it exists.

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
2. You attempt to start PiP in a non-full-screen window.

**Solution**

1. Correct the input parameters.
2. Do not start PiP in a non-full-screen window.

## 1300014 PiP Internal Error

**Error Message**

PiP internal error.

**Description**

This error code is reported when an internal error occurs in PiP.

**Possible Causes**
1. The window on which the PiP feature depends is abnormal. The window may be empty.
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

2. The parameter length exceeds the allowed length.

3. The parameter format is incorrect.

**Solution**

Verify that the parameters adhere to the required standards.

## 1300017 Filter Controller Calling Error

**Error Message**

Incorrect filter calling.

**Description**

The filter controller is invalidly invoked, for example, the invoking sequence is incorrect.

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
