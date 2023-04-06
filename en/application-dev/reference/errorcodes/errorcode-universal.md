# Universal Error Codes

## 201 Permission Denied

**Error Message**

Permission verification failed, usually the result returned by VerifyAccessToken.

**Description**

This error code is reported when permission verification fails.

**Possible Causes**

The application calls an API without the required permission.

**Solution**

Check the permission required to call the API and make sure the application has the permission.

## 202 Permission Verification Failed for Calling a System API

**Error Message**

Permission verification failed, application which is not a system application uses system API.

**Description**

This error code is reported when a non-system application failed the permission verification.

**Possible Causes**

The API called by the application is a system API.

**Solution**

Check whether any system API is called. Delete it if any.

## 401 Parameter Check Failed

**Error Message**

BusinessError 401: Parameter error. The type of "${parameterName}" must be ${validType}[or ${validInput}].

**Description**

This error code is reported when a parameter error occurs.

**Possible Causes**

The mandatory parameter is not passed in, or the parameter type is invalid.

**Solution**

Make sure the mandatory parameter is passed in and the type of the passed parameter is invalid.

## 801 API Not Supported

**Error Message**

BusinessError 801: Capability not supported. function ${functionName } can not work correctly due to limited device capabilities.

**Description**

This error code is reported when the device supports the target SysCap but does not support a specific API.

**Possible Causes**

The device does not support the API.

**Solution**

Check whether the device supports the API.
