# VPN Error Codes

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2203001 Failed to Create a VPN

**Error Information**

VPN creation denied. Check the user type.

**Description**

This error code is reported if a VPN fails to be created.

**Possible Causes**

The login user does not have the operation permission. Specifically, the GUEST user does not have the permission to call the **setUp** API.

**Solution**

Check the type of the login user.


## 2203002 VPN Already Exists

**Error Information**

VPN already exists.

**Description**

This error code is reported if a VPN already exists.

**Possible Causes**

The VPN has been created.

**Solution**

Call the **destroy** API to destroy the existing VPN, and then call the **setUp** API.


## 2203004 Invalid Descriptor

**Error Information**

Invalid socket file descriptor.

**Description**

This error code is reported if the socket file descriptor is invalid.

**Possible Causes**

A TCP socket connection fails to be established.

**Solution**

Check whether a TCP socket connection is set up successfully.

## 19900001 Invalid Parameter

**Error Information**

Invalid parameter value.

**Description**

This error code is reported if one or more parameters are invalid.

**Possible Causes**

The type or number of parameters is incorrect.

**Solution**

Check the type and number of parameters.

## 19900002 System Internal Error

**Error Information**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

An internal error is probably due to a null pointer, memory allocation error, or IPC communication error.

**Solution**

Check whether the VPN service is normal.
