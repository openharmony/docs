# OAID Error Codes

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--Designer: @zhansf1988-->
<!--Tester: @hongmei_may-->
<!--Adviser: @RayShih-->

> **NOTE**
>
> - This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 17300001 System Internal Error

**Error Message**

System internal error.

**Error Description**

This error code is reported if an internal system error occurs.

**Possible Cause**

Failed to connect to the OAID service.

**Solution**

Check whether the service is running properly.

## 17300002 Not in the Trust List

**Error Message**

Not in the trust list.

**Error Description**

The system application is not in the trust list.

**Possible Cause**

The system application that is not in the trust list calls the API.

**Solution**

Add the system application to the [trust list].
