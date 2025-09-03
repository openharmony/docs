# Camera Error Codes
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 7400101 Invalid Parameter

**Error Message**

Parameter missing or parameter type incorrect.

**Error Description**

A parameter passed in the API is invalid.

**Possible Cause**

The parameter is invalid. For example, the parameter value is not within the range supported.

**Solution**

Pass the correct parameters in the API.

## 7400102 Invalid Operation

**Error Message**

Operation not allowed.

**Error Description**

The operation is not performed in the specified mode.

**Possible Cause**

The API execution sequence is incorrect. For example, the **commitConfig** API is called in prior to **beginConfig**.

**Solution**

Perform operations according to the API reference and guide.

## 7400103 Session Not Configured

**Error Message**

Session not config.

**Error Description**

An operation that requires session configuration is performed before the session is configured.

**Possible Cause**

For example, the **start()** API is called before the session is configured.

**Solution**

Configure the session first.

## 7400104 Session Not Running

**Error Message**

Session not running.

**Error Description**

An operation that requires a running session is performed before the session runs.

**Possible Cause**

For example, the **capture()** API is called before the session runs.

**Solution**

Perform the operation to run the session first.

## 7400105 Session Configuration Locked

**Error Message**

Session config locked.

**Error Description**

The session configuration is locked.

**Possible Cause**

Another thread has locked the session configuration.

**Solution**

Wait until the session configuration is unlocked.

## 7400106 Device Configuration Locked

**Error Message**

Device setting locked.

**Error Description**

The device configuration is locked.

**Possible Cause**

Another thread has locked the device configuration.

**Solution**

Wait until the device configuration is unlocked.

## 7400107 Camera Conflict

**Error Message**

Can not use camera cause of conflict.

**Error Description**

The camera cannot be used due to a conflict.

**Possible Cause**

The opened camera conflicts with the local camera to be used.

**Solution**

Wait until the conflicting camera is released.

## 7400108 Camera Disabled Due to Security Reasons

**Error Message**

Camera disabled cause of security reason.

**Error Description**

The camera cannot be used due to security policies.

**Possible Cause**

The application running in the background attempts to open the camera.

**Solution**

Switch the application to the foreground first.

## 7400109 Camera Preempted

**Error Message**

Can not use camera cause of preempted.

**Error Description**

The camera cannot be used because it is preempted.

**Possible Cause**

Two applications attempt to open the same camera simultaneously.

**Solution**

N/A

## 7400110 Configuration Conflicts

**Error Message**

Unresolved conflicts with current configurations.

**Error Description**

The committed configuration is incompatible with the configuration supported by the device.

**Possible Cause**

The frame rate of the preview stream exceeds that supported by the device.

**Solution**

Check whether the committed configuration is supported by the device.

## 7400201 Camera Service Error

**Error Message**

Camera service fatal error.

**Error Description**

The camera service is abnormal.

**Possible Cause**

For example, the camera service is restarted or cross-process invoking is abnormal.

**Solution**

Create the service again.
