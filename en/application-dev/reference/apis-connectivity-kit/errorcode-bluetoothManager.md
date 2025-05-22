# Bluetooth Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

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

Bluetooth disabled.

**Description**

Bluetooth is disabled.

**Possible Causes**

Bluetooth is disabled.

**Solution**

Enable Bluetooth.

## 2900004

**Error Message**

Profile not supported.

**Description**

The profile is not supported.

**Possible Causes**

The profile is not supported by the device.

**Solution**

Check whether the device supports the profile. Use a profile supported by the device.

## 2900005

**Error Message**

Device not connected.

**Description**

The device is not connected to Bluetooth.

**Possible Causes**

The device pairing fails.

**Solution**

Turn on Bluetooth again to start the pairing process.

## 2900006

**Error Message**

The maximum number of connections has been reached.

**Description**

The number of connections reaches the maximum.

**Possible Causes**

The number of connections reaches the limit.

**Solution**

Check whether the number of paired devices exceeds the threshold.

## 2900007

**Error Message**

Asynchronous interface invoking timeout.

**Description**

The asynchronous call timed out.

**Possible Causes**

The remote device does not respond.

**Solution**

Try again after the timeout. If the local and remote devices are connected, disconnect them and try again.

## 2900008

**Error Message**

The value of proxy is a null pointer.

**Description**

**pimpl** or **proxy** is null.

**Possible Causes**

The device pairing fails.

**Solution**

Turn on Bluetooth again to start the pairing process.

## 2900010

**Error Message**

Resources have reached the upper limit.

**Description**

This error code is reported if resource usage reaches the upper limit.

**Possible Causes**

The application applies for too many resources.

**Solution**

Call the corresponding API to release resources.

## 2900099

**Error Message**

Operation failed.

**Description**

The operation failed.

**Possible Causes**

The profile is not supported by the device.

**Solution**

Perform this operation again.

## 2900100

**Error Message**

IPC failed.

**Description**

IPC data transmission fails.

**Possible Causes**

The input data is incorrect.

**Solution**

Check the input data.

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

## 2902050

**Error Message**

Failed to start scan as Ble scan is already started by the app.

**Description**

This error code is reported if the attempt to enable scanning fails.

**Possible Causes**

BLE scanning has been enabled.

**Solution**

Check whether scanning is enabled.
