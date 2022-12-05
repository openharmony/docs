# Access Token Error Codes

## 401 Parameter Error

### Error Message
Parameter error.${messageInfo}.

### Possible Causes
This error code is reported if an error occurs during JS parameter parsing. The possible causes are as follows:
1. The number of input parameters is insufficient.
2. The parameter type is incorrect.

### Solution
1. Add input parameters.
2. Correct parameter types.


## 201 Permission denied.

### Error Message
Permission denied.${messageInfo}.

### Possible Causes
This error code is reported if the application process that calls an API is not granted the required permission. The possible causes are as follows:
1. The application process is not granted the required permission.
2. The permission requires user authorization to take effect, but the application process does not obtain the user authorization.

### Solution
1. Check whether the application process is granted the required permission.
2. Check whether the application process has obtained the user authorization if the permission requires user authorization to take effect.


## 12100001 Invalid Parameters

### Error Message
Parameter invalid, message is ${messageInfo}.

### Possible Causes
This error code is reported if an error occurs during parameter verification. The possible causes are as follows:
1. The value of **tokenId** is **0**.
2. The specified permission name is empty or contains more than 256 characters.
3. The **flag** value in the permission authorization or revocation request is invalid.
4. The input parameters specified for registering a listener are incorrect.

### Solution
1. Correct the invalid parameter values.


## 12100002 TokenId does not exist.

### Error Message
TokenId does not exist.

### Possible Causes
1. The specified **tokenId** does not exist.
2. The process corresponding to the specified **tokenId** is not an application process.

### Solution
Set a correct **tokenId**, and make sure that the process corresponding to the specified **tokenId** is an application process.


## 12100003 Permission Not Exist

### Error Message
Permission does not exist.

### Possible Causes
1. The specified **permissionName** does not exist.
2. The specified **permissionName** does not match the specified **tokenId** in the permission authorization or revocation scenario.
3. The specified **permissionName** is not a sensitive permission that requires user authorization.

### Solution
Set the **permissionName** parameter correctly. For details, see [permission-list](../../security/permission-list.md).


## 12100004 Listener APIs Not Used in Pairs

### Error Message
The listener interface is not used together.

### Possible Causes
This error code is reported if listener APIs are not used in pairs. The possible causes are as follows:
1. The listener APIs that need to be used in pairs are repeatedly called.
2. The listener APIs that need to be used in pairs are independently called.

### Solution
1. Check whether the API needs to be used in pairs. That is, if an API is called to enable listening, an API with the same input parameters cannot be called unless an API is called to stop listening first.
2. Check whether the API needs to be used in pairs. That is, an API for disabling listening or unregistering a listener can only be called after the API for enabling listening or registering a listener is called.


## 12100005 Listener Overflow

### Error Message
The number of listeners exceeds the limit.

### Possible Causes
The number of listeners exceeds 200 (the upper limit).

### Solution
Abandon unused listeners in a timely manner.


## 12100006 Permission Granting or Revocation Not Supported for the Specified Application

### Error Message
The specified application does not support the permissions granted or ungranted as specified.

### Possible Causes
1. The specified **tokenId** is the identity of the remote device. Distributed granting and revocation are not yet supported.
2. The specified **tokenId** belongs to a sandbox application, which is not allowed to apply for the specified permission.

### Solution
1. Check whether the method of obtaining **tokenId** is correct.
2. Check whether the sandbox application works in restrictive mode. Most permissions cannot be granted to a sandbox application in restrictive mode.


## 12100007 System Services Not Working Properly

### Error Message
Service is abnormal.

### Possible Causes
This error code is reported if system services are not working properly. The possible causes are as follows:
1. The permission management service cannot be started properly.
2. An error occurs while reading or writing IPC data.

### Solution
System services do not work properly. Try again later or restart the device.


## 12100008 Out of Memory

### Error Message
Out of memory.

### Possible Causes
The system memory is insufficient.

### Solution
Try again later or restart the device.
