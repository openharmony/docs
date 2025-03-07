# VPN Error Codes

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
