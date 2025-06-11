# Ads Service Framework Error Codes

> **NOTE**
> - This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

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

1. The network connection is abnormal.

2. Incorrect ad request parameter.

3. The server does not have proper ad filling.

**Procedure**

1. Check the network status.

2. Check whether the ad request parameters meet the requirements based on the API reference.

## 21800004 Ad Display Failure

**Error Message**

Failed to display the ad.

**Description**

This error code is reported if displaying the ad fails.

**Possible Causes**

The network connection is abnormal.

**Procedure**

Check the network status.

## 21800005 Ad Data Parsing Failure

**Error Message**

Failed to parse the ad response.

**Description**

This error code is reported if ad data is failed to be parsed.

**Possible Causes**

Key attributes are missing or the structure of the ad response data is incorrect.

**Procedure**

Check the ad response data.

## 401 Incorrect Ads Request Parameter

**Error Message**

Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.

**Description**

This error code is reported if an ads request parameter is incorrect.

**Possible Causes**

Ads request parameters fail the verification.

**Procedure**

Check whether the ads request parameters are correct.

## 801 Ad Request Failure

**Error Message**

Device not supported.

**Description**

This error code is reported when the device supports the target SysCap but does not support a specific API.

**Possible Causes**

The device does not support the API.

**Procedure**

Check whether the device supports the API.
