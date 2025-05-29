# Universal Error Codes

## 201 Permission Denied

**Error Message**

Permission verification failed. The application does not have the permission required to call the API.

**Description**

This error code is reported when permission verification fails.

**Possible Causes**

The application calls an API without the required permission.

**Solution**

Check the permission required to call the API and make sure the application has the permission.

## 202 Permission Verification Failed for Calling a System API

**Error Message**

Permission verification failed. A non-system application calls a system API.

**Description**

This error code is reported when a non-system application failed the permission verification.

**Possible Causes**

The API called by the application is a system API.

**Solution**

Check whether any system API is called. Delete it if any.

## 401 Parameter Check Failed

**Error Message**

Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.

**Description**

1. A mandatory parameter is left unspecified.

2. A parameter type is incorrect.

3. Parameter verification failed. Regardless of whether the API is synchronous or asynchronous, this type of error is generally thrown in synchronous mode.

**Possible Causes**

1. A mandatory parameter is not passed.

2. A parameter type is incorrect (Type Error).

3. The number of parameters is incorrect (Argument Count Error).

4. A null parameter is incorrect (Null Argument Error).

5. A parameter format is incorrect (Format Error).

6. A value range is incorrect (Value Range Error).

**Solution**

Make sure all the mandatory parameters are passed in and the types of the passed-in parameter are valid. If parameter verification fails, read the parameter specifications and locate the fault based on the possible causes.

## 801 API Not Supported

**Error Message**

Capability not supported. Failed to call the API due to limited device capabilities.

**Description**

The device does not support this API. Therefore, it cannot be called properly.

**Possible Causes**

The device supports Syscap associated with the API but does not support the API itself.

**Solution**

Do not use this API on the device. Alternatively, implement conditional checks in the code to mitigate the effects of the application running across various devices, particularly under abnormal circumstances.
