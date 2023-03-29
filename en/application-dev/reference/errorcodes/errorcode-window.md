# Window Error Codes

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

This error code is reported when you operate a window in an abnormal state, for example, a window that has been destroyed.

**Possible Causes**

The window has been destroyed when being operated.

**Solution**

Before operating the window, check whether it exists.

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

**Procedure**

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