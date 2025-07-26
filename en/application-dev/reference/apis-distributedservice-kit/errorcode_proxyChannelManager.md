# Proxy Channel Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 32390001 Bluetooth Disabled

**Error Message**

BR is disabled.

**Description**

This error code is reported if Bluetooth is disabled on the local device.

**Possible Causes**

Bluetooth is disabled on the local device.

**Solution**

Enable Bluetooth on the local device and try again.

## 32390002 Bluetooth Unpaired

**Error Message**

Device not paired.

**Description**

This error code is reported if the local device has not established a Bluetooth pairing.

**Possible Causes**

1. The local device has not established a Bluetooth pairing with the target device.
2. The Bluetooth service on the peer device has not enabled listening for pairing requests.

**Solution**

1. Use the Health & Fitness app to add the device and pair it via Bluetooth.
2. Check whether the Bluetooth service on the peer device has enabled listening for pairing requests.

## 32390004 Invalid or Unavailable Channel ID

**Error Message**

ChannelId is invalid or unavailable.

**Description**

This error code is reported if the channel ID is invalid or unavailable.

**Possible Causes**

1. The input **channelId** is invalid, that is, it is not the one returned by **openProxyChannel**.
2. The related channel has been closed.

**Solution**

1. Review the code logic to determine if **channelId** is the one returned by **openProxyChannel**.
2. Review the code logic to determine if **channelId** is still used after the channel is closed. 

## 32390006 Parameter Verification Error

**Error Message**

Parameter error.

**Description**

This error code is reported if the parameter verification fails.

**Possible Causes**

1. The format of the input MAC address or service UUID is incorrect.
2. The type of the input parameters is incorrect.

**Solution**

Review the code logic to determine if the MAC address and service UUID are in correct format and the type of the input parameters is correct.

## 32390100 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported if an internal error occurs.

**Possible Causes**

System errors, such as null pointer, insufficient memory, unexpected distributed service restart, IPC exception, and JS engine exception.

**Solution**

Try again. If the fault persists, restart the application, update the application, or update the device version.

## 32390101 Call Restricted

**Error Message**

Call is restricted.

**Description**

This error code is reported if an API call is restricted.

**Possible Causes**

The callers is not authorized to perform the operation.

**Solution**

Apply for the required permissions.

## 32390102 Operation Failed or Connection Timed Out

**Error Message**

Operation failed or Connection timed out.

**Description**

This error code is reported if the operation fails or the connection times out.

**Possible Causes**

The underlying Bluetooth is faulty, leading to a connection failure or timeout.

**Solution**

1. Enable and disable Bluetooth on the local device and the target device.
2. Restart the local device and the target device, and then enable Bluetooth on the devices.

## 32390103 Data Too Long

**Error Message**

Data too long.

**Description**

This error code is reported if the data to be sent exceeds the length limit.

**Possible Causes**

The length of the data to be sent exceeds 4096 bytes.

**Solution**

Check the length of the data to be sent.

## 32390104 Data Sending Failed

**Error Message**

Send failed.

**Description**

This error code is reported if data fails to be sent via Bluetooth.

**Possible Causes**

The underlying Bluetooth is faulty.

**Solution**

1. Restart Bluetooth on the local device and the target device.
2. Restart the local device and the target device.
