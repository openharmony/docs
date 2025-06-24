# RoomLocation Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 33800001 Service Exception

**Error Message**

Service exception.

**Symptom**

This error code is reported if a service exception occurs when the **on** and **off** API of the roomLocation module is called.

**Possible Causes**

The service status is abnormal.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. You can also attempt to obtain the sensor list to check for device availability.



## 33800002 Subscription Exception

**Error Message**

Subscription failed.

**Symptom**

This error code is reported if subscription fails when the **on** API of the roomLocation module is called.

**Possible Causes**

Subscription to change events has failed.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. 



## 31500003 Unsubscription Exception

**Error Message**

UnSubscription failed.

**Symptom**

This error code is reported if unsubscription fails when the **off** API of the roomLocation module is called.

**Possible Causes**

Unsubscription from change events has failed.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. 



## 31500004 SetDevicesInfos Exception

**Error Message**

Failed to set device information.

**Symptom**

This error code is reported if unsubscription fails when the **setDevicesInfos** API of the roomLocation module is called.

**Possible Causes**

Failed to set device information.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry.



## 31500005 GetRoomLocationResult Exception

**Error Message**

Failed to obtain room-level location information.

**Symptom**

This error code is reported if unsubscription fails when the **getRoomLocationResult** API of the roomLocation module is called.

**Possible Causes**

Failed to obtain room-level location information.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry.
