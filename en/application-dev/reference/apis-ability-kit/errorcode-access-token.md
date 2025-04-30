# Access Control Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 12100001 Invalid Parameters

**Error Message**

Invalid Parameter. Error message: ${messageInfo}.

**Possible Causes**

1. The value of **tokenId** is **0**.
2. The permission name is empty or exceeds 256 characters.
3. The **flag** value in the permission authorization or revocation request is invalid.
4. The parameters specified for registering a listener are incorrect.
5. The specified context does not belong to the current application.
6. The requested permissions do not belong to the same permission group.
7. The requested permissions include permissions that are not declared by the application.
8. The type of the requested global switch is invalid.

**Solution**

Check and set input parameters correctly.


## 12100002 TokenId Not Exist

**Error Message**

TokenId does not exist.

**Possible Causes**

1. The specified **tokenId** does not exist.
2. The process of the specified **tokenId** is not an application process.

**Solution**

Check and set input parameters correctly.


## 12100003 Permission Not Exist

**Error Message**

Permission does not exist.

**Possible Causes**

1. The specified **permissionName** does not exist.
2. The specified **permissionName** does not match the **tokenId** in the permission authorization or revocation scenario.
3. The specified **permissionName** is not a sensitive permission that requires user authorization.

**Solution**

Check and set input parameters correctly. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).


## 12100004 Listener APIs Not Used in Pairs

**Error Message**

The API is not used in pair with others.

**Possible Causes**

1. One of the listener APIs that must be used in pairs is repeatedly called.
2. One of the listener APIs that must be used in pairs is independently called.

**Solution**

1. For the APIs that must be used in pairs, for example, **on()** and **off()**, check whether **on()** with the same parameters is called again before **off()** is called.
2. For the APIs that must be used in pairs, for example, **on()** and **off()**, check whether **off()** is called before **on()**.


## 12100005 Listener Overflows

**Error Message**

The number of listeners exceeds the limit.

**Possible Causes**

The number of listeners exceeds 200.

**Solution**

Release unused listeners in a timely manner.


## 12100006 Permission Granting or Revocation Not Supported

**Error Message**

The specified application does not support the permissions granted or ungranted as specified.

**Possible Causes**

1. The specified **tokenId** is the identity of a remote device. Distributed permission granting and revocation are not yet supported.
2. The specified **tokenId** belongs to a sandbox application, which is not allowed to request the specified permission.

**Solution**

1. Check whether the method of obtaining **tokenId** is correct.
2. Check whether the sandbox application works in restrictive mode. Most permissions cannot be granted to a sandbox application in restrictive mode.


## 12100007 System Service Not Working Properly

**Error Message**

The service is abnormal.

**Possible Causes**

1. The permission management service fails to start properly.
2. The data read or write via IPC fails.

**Solution**

Try again later or restart the device.


## 12100008 Out of Memory

**Error Message**

Out of memory.

**Possible Causes**

The system memory is insufficient.

**Solution**

Try again later or restart the device.


## 12100009 Internal Service Error

**Error Message**

Common inner error.

**Possible Causes**

An internal error occurs in the system service.

**Solution**

Analyze the fault log to identify the error.

## 12100010 Pending Request

**Error Message**

The request already exists.

**Possible Causes**

The last request has not been processed yet.

**Solution**

Wait until the last request is processed.


## 12100011 All Requested Permissions Granted

**Error Message**

All permissions in the permission list have been granted.

**Possible Causes**

All requested permissions have been granted.

**Solution**

No action is required. If this error code is returned, the permission has been granted and the permission settings dialog box will not be displayed.


## 12100012 Not All Permissions Are Rejected by the User

**Error Message**

The permission list contains the permission that has not been revoked by the user.

**Possible Causes**

The requested permissions include the permissions that are not rejected by the user.

**Solution**

Call **requestPermissionsFromUser** to request permissions from the user first.


## 12100013 Global Switch Enabled

**Error Message**

The specific global switch is already open.

**Possible Causes**

The global switch is already turned on.

**Solution**

No action is required. If this error code is returned, the global switch has been enabled and the dialog box for setting the global switch will not be displayed.
