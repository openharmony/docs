# Time and Time Zone Service Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## -1 Time and Time Zone Service Error

**Error Message**

Parameter check failed, permission denied, or system error.

**Description**

This error code is reported when the time and time zone service error occurs.

**Possible Cause**

The system is not running properly due to a common kernel error, such as a memory allocation and multi-thread processing error.

**Solution**

Make sure that the memory is sufficient.

## 13000001 Network or OS Error

**Error Message**

Network connection error or OS error.

**Description**

This error code is reported when the network or OS error occurs.

**Possible Cause**

The network or OS is not running properly due to a system error, such as network connection failure or socket creation failure.

**Solution**

Make sure the network is connected and the system resources are sufficient.


## 13000002 NTP Time Not Updated

**Error Message**

The local NTP time of the system is invalid.

**Description**

This error code is reported when the NTP time is invalid.

**Possible Cause**

The local NTP time has not been updated and becomes invalid.

**Solution**

Call the **updateNtpTime()** API to update the NTP time.
