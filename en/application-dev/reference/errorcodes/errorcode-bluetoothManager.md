# Bluetooth Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 2900001

**Error Message**

Service stopped.

**Description**

The Bluetooth service is stopped, and the APIs related to the Bluetooth service cannot be called.

**Possible Causes**

The Bluetooth service fails to start.

**Solution**

Start the Bluetooth service.

## 2900003

**Error Message**

Bluetooth switch is off.

**Description**

Bluetooth is disabled.

**Possible Causes**

Bluetooth is disabled.

**Solution**

Enable Bluetooth.

## 2900004

**Error Message**

Profile is not supported.

**Description**

The profile is not supported.

**Possible Causes**

The profile is not supported by the device.

**Solution**

Check whether the device supports the profile. Use a profile supported by the device.

## 2900099

**Error Message**

Operation failed.

**Description**

The operation failed.

**Possible Causes**

The profile is not supported by the device.

**Solution**

Perform this operation again.

## 2901000

**Error Message**

Read forbidden.

**Description**

The read operation is not allowed.

**Possible Causes**

The caller does not have the read permission.

**Solution**

Check whether the caller has the read permission.

## 2901001

**Error Message**

Write forbidden.

**Description**

The write operation is not allowed.

**Possible Causes**

The caller does not have the write permission.

**Solution**

Check whether the caller has the write permission.

## 2901054

**Error Message**

IO error.

**Description**

The I/O operation failed.

**Possible Causes**

The I/O transmission is abnormal.

**Solution**

Perform this operation again.
