# Ads Service Framework Error Codes


> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).


## 21800001 Internal System Error

**Error Message**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

Failed to connect to the OAID service.

**Procedure**

Check whether the service is running properly.


## 21800003 Ad Loading Failure

**Error Message**

Failed to load the ad request.

**Description**

This error code is reported if loading the ad fails.

**Possible Causes**

The network connection is abnormal, or an ad request parameter is incorrect.

**Procedure**

Check the network status, and correct the ad request parameters.


## 21800004 Ad Display Failure

**Error Message**

Failed to display the ad.

**Description**

This error code is reported if displaying the ad fails.

**Possible Causes**

The network connection is abnormal.

**Procedure**

Check the network status.


## 401 Incorrect Ads Request Parameter

**Error Message**

Invalid input parameter. Possible causes:1. Mandatory parameters are left unspecified.
2.Incorrect parameter types. 3.Parameter verification failed

**Description**

This error code is reported if an ads request parameter is incorrect.

**Possible Causes**

Ads request parameters fail the verification.

**Procedure**

Check whether the ads request parameters are correct.


## 801 Ad Request Failure

**Error Message**

Device not support

**Description**

This error code is reported when the device supports the target SysCap but does not support a specific API.

**Possible Causes**

The device does not support the API.

**Procedure**

Check whether the device supports the API.
