# Bluetooth Error Codes

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=59ee555b00022e6000d8d297f01d37cde4dac791 translatedAt=2026-08-03T02:10:34.751Z pushedAt=2026-08-03T03:03:50.953Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2900001 Bluetooth Service Stopped

**Error Message**

Service stopped.

**Description**

The Bluetooth service is stopped, and the APIs related to the Bluetooth service cannot be called.

**Possible Causes**

The Bluetooth service fails to start.

**Solution**

Start the Bluetooth service.

## 2900003 Bluetooth Disabled

**Error Message**

Bluetooth disabled.

**Description**

Bluetooth is disabled.

**Possible Causes**

Bluetooth is disabled.

**Solution**

Enable Bluetooth.

## 2900004 Profile Not Supported

**Error Message**

Profile not supported.

**Description**

The profile is not supported.

**Possible Causes**

The profile is not supported by the device.

**Solution**

Check whether the device supports the profile. Use a profile supported by the device.

## 2900005 Bluetooth Device Not Connected

**Error Message**

Device not connected.

**Description**

The device is not connected to Bluetooth.

**Possible Causes**

The device pairing fails.

**Solution**

Turn on Bluetooth again to start the pairing process.

## 2900006 Maximum Number of Connections Reached

**Error Message**

The maximum number of connections has been reached.

**Description**

The number of connections reaches the maximum.

**Possible Causes**

The number of connections reaches the limit.

**Solution**

Check whether the number of paired devices exceeds the threshold.

## 2900007 Asynchronous API Call Timeout

**Error Message**

Asynchronous interface invoking timeout.

**Description**

The asynchronous call timed out.

**Possible Causes**

The remote device does not respond.

**Solution**

Try again after the timeout. If the local and remote devices are connected, disconnect them and try again.

## 2900008 Null Pointer

**Error Message**

The value of proxy is a null pointer.

**Description**

**pimpl** or **proxy** is null.

**Possible Causes**

The device pairing fails.

**Solution**

Turn on Bluetooth again to start the pairing process.

## 2900009 Insufficient Hardware Resources

**Error Message**

Fails to start scan as it is out of hardware resources.

**Description**

Starting a scan fails due to insufficient hardware resources.

**Possible Causes**

An excessive number of scan channels have been activated by this application or other applications, resulting in insufficient hardware resources.

**Solution**

If this application has never started a scan, you can turn Bluetooth off and then back on to release the scanning resources occupied by other applications.

If this application has already started a scan on another channel, you can call the **stopScan** API to halt the scan. After the hardware resources are released, restart the current scan.

## 2900010 Resource Usage Reaches the Upper Limit

**Error Message**

Resources have reached the upper limit.

**Description**

This error code is reported if resource usage reaches the upper limit.

**Possible Causes**

The application applies for too many resources.

**Solution**

Call the corresponding API to release resources.

## 2900011 Frequent Operations

**Error Message**

The operation is busy. The last operation is not complete.

**Description**

This error code is reported if the previous operation is not complete.

**Possible Causes**

The current operation is executed before the previous operation is complete. For example, the [readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue) API is called when the current API call is still in progress.

Other involved APIs are [writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue), [readDescriptorValue](js-apis-bluetooth-ble.md#readdescriptorvalue), [writeDescriptorValue](js-apis-bluetooth-ble.md#writedescriptorvalue), [getRssiValue](js-apis-bluetooth-ble.md#getrssivalue), [setCharacteristicChangeNotification](js-apis-bluetooth-ble.md#setcharacteristicchangenotification) and [setCharacteristicChangeIndication](js-apis-bluetooth-ble.md#setcharacteristicchangeindication). A new API call will be blocked if the current API call is not yet complete.

**Solution**

A new call of an asynchronous API is permitted only after the callback or promise of the previous API call is received.

## 2900013 Preparation Timeout

**Error Message**

The user does not respond.

**Description**

This error code is reported if the user does not respond to the preprocessing operation.

**Possible Causes**

The user does not perform the required operation within a specified period of time. As a result, the preprocessing operation times out.

**Solution**

Perform the preprocessing operation again.

## 2900014 User Rejected the Operation

**Error Message**

User refuse the action.

**Description**

This error code is reported if the user rejects the preprocessing operation.

**Possible Causes**

The user rejects the preprocessing operation.

**Solution**

Perform the preprocessing operation again.

## 2900015 Parameter Format Inconsistent with Specifications

**Error Message**

Parameter format mismatch with specification.

**Description**

The parameter format is inconsistent with the specifications.

**Possible Causes**

For example, the parameter length does not meet the specifications, or lowercase letters are passed for a parameter that should use uppercase letters.

**Solution**

Check whether the parameter format complies with the specifications.

## 2900016 Device Not Paired

**Error Message**

Device unpaired.

**Description**

The device is not paired.

**Possible Causes**

The queried address is not paired with the device.

**Solution**

On the Bluetooth settings screen, check whether the device is paired.

## 2900099 Operation Failed

**Error Message**

Operation failed.

**Description**

The operation failed. An internal system error occurred, such as an SA or IPC exception.

**Possible Causes**

Common error code for Bluetooth API calling failures. The possible causes are as follows:

1. The prerequisites for calling the API are not met.

2. The specified virtual address does not exist.

**Solution**

1. Check the prerequisites for calling the API. For details, see [2900099 Bluetooth API Call Error](../../connectivity/bluetooth/bluetooth-faq-2900099-errorcode.md).

## 2900100 IPC Transmission Failure

**Error Message**

IPC failed.

**Description**

IPC data transmission fails.

**Possible Causes**

The input data is incorrect.

**Solution**

Check the input data.

## 2901000 Read Operation Forbidden

**Error Message**

Read forbidden.

**Description**

The read operation is not allowed.

**Possible Causes**

The caller does not have the read permission.

**Solution**

Check whether the caller has the read permission.

## 2901001 Write Operation Forbidden

**Error Message**

Write forbidden.

**Description**

The write operation is not allowed.

**Possible Causes**

The caller does not have the write permission.

**Solution**

Check whether the caller has the write permission.

## 2901003 GATT Disconnected

**Error Message**

The connection is not established.

**Description**

This error code is reported if the GATT connection is not established.

**Possible Causes**

An API call is invoked when the GATT connection is not established, for example, [getServices](js-apis-bluetooth-ble.md#getservices) or [readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue) is called.

**Solution**

Ensure that the GATT connection is established.

## 2901004 GATT Connection Congested

**Error Message**

The connection is congested.

**Description**

This error code is reported if the GATT connection is congested.

**Possible Causes**

Characteristic or descriptor read and write operations are performed frequently, causing congestion in underlying data transmission. For example, if the [writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue) API is frequently called with [GattWriteType](js-apis-bluetooth-ble.md#gattwritetype) being set as **WRITE_NO_RESPONSE**, congestion may occur.

**Solution**

Reduce the frequency of read and write operations. If **GattWriteType** is set to **WRITE_NO_RESPONSE**, the recommended interval is greater than 50 ms.

## 2901005 GATT Not Encrypted

**Error Message**

The connection is not encrypted.

**Description**

This error code is reported if characteristic or descriptor read and write operations requiring the encryption permission is performed when the GATT connection is not encrypted. Whether encryption is required for the operation is subject to the permission of the characteristic or descriptor on the server.

**Possible Causes**

The GATT encryption permission is not available.

**Solution**

Check whether the encryption permission is available for the GATT connection.

## 2901006 GATT Unauthenticated

**Error Message**

The connection is not authenticated.

**Description**

This error code is reported if characteristic or descriptor read and write operations requiring authentication is performed when the GATT connection is not authenticated. Whether encryption is required for the operation is subject to the permission of the characteristic or descriptor on the server.

**Possible Causes**

The GATT connection is not authenticated.

**Solution**

Check whether the device is paired with the peer device and whether the GATT connection is authenticated.

## 2901007 GATT Unauthorized

**Error Message**

The connection is not authorized.

**Description**

This error code is reported if characteristic or descriptor read and write operations requiring authorization is performed when the GATT connection is not authorized. Whether authorization is required for the operation is subject to the permission of the characteristic or descriptor on the server.

**Possible Causes**

The GATT connection is not authorized.

**Solution**

Check whether the GATT connection is authorized.

## 2901008 GATT Service Not Found

**Error Message**

GATT service is not found.

**Description**

The GATT service does not exist. Before obtaining the specified GATT service, ensure that the service has been added.

**Possible Causes**

The GATT service has not been added.

**Solution**

Call [addService](js-apis-bluetooth-ble.md#addservice) to add the service.

## 2901054 IO Transmission Failure

**Error Message**

IO error.

**Description**

The I/O operation failed.

**Possible Causes**

The I/O transmission is abnormal.

**Solution**

Perform this operation again.

## 2902050 Failed to Enable Scanning

**Error Message**

Failed to start scan as Ble scan is already started by the app.

**Description**

This error code is reported if the attempt to enable scanning fails.

**Possible Causes**

BLE scanning has been enabled.

**Solution**

Check whether scanning is enabled.

## 2902054 Advertising Data Length Exceeds the Upper Limit

**Error Message**

The length of the advertising data exceeds the upper limit.

**Description**

This error code is reported if the length of the advertising data exceeds the upper limit.

**Possible Causes**

The maximum length of traditional advertising packets is 31 bytes. If the maximum length is exceeded, an exception is returned. Currently, this length limit applies only to traditional advertising but not extended advertising.

**Solution**

Check whether the length of the advertising packet exceeds the upper limit.

## 2902055 Invalid Advertising ID

**Error Message**

Invalid advertising id.

**Description**

This error code is reported if the advertising ID is invalid.

**Possible Causes**

The input advertising ID must be the value returned by [startAdvertising](js-apis-bluetooth-ble.md#blestartadvertising11). The invalid advertising ID is **0xFF** by default.

**Solution**

Check whether the input advertising ID is a valid advertising ID returned by [startAdvertising](js-apis-bluetooth-ble.md#blestartadvertising11).

## 2903050 HID Is Not in the Foreground

**Error Message**

HID application is not int the foreground.

**Description**

The application that registers the HID device is not in the foreground.

**Possible Causes**

The application that registers the HID device is in the background.

**Solution**

Check whether the application that registers the HID device is in the foreground.

## 2903051 HID Has Been Registered

**Error Message**

Any HID application has been registered.

**Description**

The HID device has been registered by another application.

**Possible Causes**

Only one application can register the HID device.

**Solution**

Check whether the HID device has been registered by another application.

## 2903052 HID Not Registered

**Error Message**

HID application does not register.

**Description**

The application has not registered the HID device.

**Possible Causes**

An application can connect to and exchange data with the HID host only after registering the HID device.

**Solution**

Check whether the application successfully registers the HID device.

## 2903053 HID Not Connected

**Error Message**

HID device is not connected.

**Description**

The HID device has not connected to the HID host.

**Possible Causes**

The HID device can exchange data with the HID host only after the connection is successful.

**Solution**

Check whether the application successfully registers the HID device and connects to the HID host.