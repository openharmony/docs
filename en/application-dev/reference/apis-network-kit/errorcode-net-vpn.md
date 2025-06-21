# VPN Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2203001 Failed to Create a VPN

**Error Message**

VPN creation denied. Check the user type.

**Error Description**

This error code is reported if a VPN fails to be created.

**Possible Cause**

The login user does not have the operation permission. Specifically, the GUEST user does not have the permission to call the **setUp** API.

**Solution**

Check the type of the login user.


## 2203002 VPN Already Exists

**Error Message**

VPN already exists.

**Error Description**

This error code is reported if a VPN already exists.

**Possible Cause**

The VPN has been created.

**Solution**

Call the **destroy** API to destroy the existing VPN, and then call the **setUp** API.


## 2203004 Invalid Descriptor

**Error Message**

Invalid socket file descriptor.

**Error Description**

This error code is reported if the socket file descriptor is invalid.

**Possible Cause**

A TCP socket connection fails to be established.

**Solution**

Check whether a TCP socket connection is set up successfully.
