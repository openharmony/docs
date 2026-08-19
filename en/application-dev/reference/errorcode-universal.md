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

## 203 System Function Prohibited by Enterprise Management Policies

**Error Message**

This function is prohibited by enterprise management policies.

**Description**

The enterprise management policies do not allow the use of this system function.

**Possible Causes**

You attempted to operate a system function that has been disabled by the device management application.

**Solution**

Use [getDisallowedPolicy](./apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicydeprecated) to check whether the system function is disabled, and use [setDisallowedPolicy](./apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) to enable the system function.

<!--Del-->
## 204 Access Denied by User Access Control Policy

**Error Message**

Access denied due to user access control policy. Possible causes:
1. The operation is prohibited by OS-account constraints.
2. The required privilege for the operation has expired or has not been granted.

**Description**

Access denied due to user access control policy. Possible causes:
1. The required privilege for the operation has not been obtained.
2. The operation is restricted by OS-account constraints.

**Possible Causes**

1. OS-account constraints prohibit this operation.
2. The privilege required for this operation has expired or has not been granted.

**Solution**

1. Confirm the user constraints and user privileges involved in the target operation.
2. If the target operation is subject to constraint control, call [isOsAccountConstraintEnabled](./apis-basic-services-kit/js-apis-osAccount.md#isosaccountconstraintenabled11) to check whether the related constraint is enabled. If it is enabled, stop the operation.
3. If the target operation is subject to privilege control, call [acquireAuthorization](./apis-basic-services-kit/js-apis-osAccount-sys.md#acquireauthorization24) to request the required privilege. If the request succeeds, continue the target operation. Otherwise, stop the operation.
<!--DelEnd-->

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

<!--RP1--><!--RP1End-->
