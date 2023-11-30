# Window Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 1300001 Repeated Operation
**Error Message**

Repeated operation.

**Description**

This error code is reported when a repeated operation is performed.

**Possible Causes**

The window to create already exists.

**Solution**

Before creating a window, check whether the window already exists. If it already exists, use it directly.

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

The window stage has been destroyed when being operated.

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

## 1001 Window Null Pointer Exception<sup>(deprecated)</sup>

**Error Message**

This window nullptr occurs.

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

An invalid window type is used. For details about valid window types, see [WindowType](../apis/js-apis-window.md#windowtype7).

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

Start ability failed.

**Description**

This error code is reported when a WindowExtensionAbility fails to start an application.

**Possible Causes**

Incorrect parameters are passed into the API used by the WindowExtensionAbility to start the application.

**Solution**

Pass in the correct parameters.
