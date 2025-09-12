# User Authentication Error Codes

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 12500001 Authentication Failed

**Error Message**

Authentication failed.

**Possible Causes**

The credential does not match the credential enrolled.

**Solution**

Initiate authentication again.

## 12500002 General Operation Error

**Error Message**

General operation error.

**Possible Causes**

1. An error occurs when the NAPI layer parses parameters.
2. The process of the user authentication service is not started.
3. The proxy client fails to write data over IPC.
4. The stub server fails to parse data over IPC.
5. The driver service is not obtained.

**Solution**

Call the API again later or restart the device.

## 12500003 Authentication Canceled

**Error Message**

Authentication canceled.

**Possible Causes**

The authentication operation has been canceled.

**Solution**

Initiate authentication again.

## 12500004 Authentication Timed Out

**Error Message**

Authentication timeout.

**Possible Causes**

The authentication is not complete within the specified time.

**Solution**

Initiate authentication again.

## 12500005 Unsupported Authentication Type

**Error Message**

The authentication type is not supported.

**Possible Causes**

1. The input authentication type parameter is not supported. For example, if the authentication type passed in **getAvailableStatus** of the **userAuth** module is not **FACE** or **FINGERPRINT**, error code 12500005 is returned.
2. The device does not support the authentication type. For example, if fingerprint authentication is initiated on a device that has no fingerprint sensor, error code 12500005 is returned.

**Solution**

Check the authentication type parameter and call the API again.

## 12500006 Unsupported Authentication Trust Level

**Error Message**

The authentication trust level is not supported.

**Possible Causes**

1. The **authTrustLevel** value in **getAvailableStatus** or **getAuthInstance** of the **userAuth** module is not in the range [ATL1, ATL2, ATL3, ATL4].
2. The device does not support the authentication trust level. For example, if facial authentication for payment is initiated on a device that has only 2D cameras, error code 12500006 is returned.

**Solution**

Check that the **authTrustLevel** passed in is within the value range, and the device supports the specified authentication trust level.

## 12500007 Authentication Service Unavailable

**Error Message**

Authentication service is busy.

**Possible Causes**

Another authentication is initiated when the current authentication has not been finished yet.

**Solution**

Initiate authentication again later.

## 12500008 Parameter Verification Failed

**Error Message**

The parameter is out of range.

**Description**

Parameter verification failed.

**Possible Causes**

Parameter error.

**Solution**

Check the API parameters and initiate the request again.

## 12500009 Authentication Locked

**Error Message**

Authentication is locked out.

**Possible Causes**

The number of authentication failures exceeds the limit.

**Solution**

Initiate authentication later.

## 12500010 Credential Not Enrolled

**Error Message**

The type of credential has not been enrolled.

**Possible Causes**

The **authType** parameter set in **getAvailableStatus** of the **userAuth** module is **FACE**, but no facial credential is enrolled in the device. **start()** is called to initiate facial authentication, but no facial credential is enrolled in the device.

**Solution**

Check that the related type of credential has been enrolled in the device.

## 12500011 Switched to Custom Authentication

**Error Message**

Switched to the custom authentication process.

**Possible Causes**

The authentication is canceled by the user, who tapped the authentication widget button to apply custom authentication.

**Solution**

Initiate authentication again.

## 12500013 Password Expired

**Error Message**

Operation failed because of PIN expired.

**Possible Causes**

The authentication fails because the system lock screen password has expired. The error code 12500013 is returned if the lock screen password has expired when a PIN, fingerprint, or facial authentication is initiated.

**Solution**

Initiate an authentication again after the user sets a new lock screen password.

<!--Del-->
## 12500015 AuthToken Integrity Check Failed

**Error Message**

Operation failed because of authToken integrity check failed.

**Possible Causes**

The authentication token is invalid.

**Solution**

Initiate authentication again and issue a valid token.

## 12500016 AuthToken Has Expired

**Error Message**

Operation failed because of authToken has expired.

**Possible Causes**

The authentication token has expired. The interval between the time when the AuthToken is issued and the time when the verification is initiated exceeds the AuthToken validity period passed in.

**Solution**

Initiate authentication again and issue a valid token.

## 12500017 Authentication Result Reuse Failed

**Error Message**

Failed to reuse authtication result.

**Description**

Failed to reuse the identity authentication result.

**Possible Causes**

1. The authentication type does not match the specified type.
2. The authentication result has expired (the maximum reuse duration is 5 minutes).

**Solution**

Initiate an authentication request to obtain a valid authentication token with the use's manual authentication.

## 12700001 Facial Authentication Service Unavailable

**Error Message**

The service is unavailable.

**Possible Causes**

1. The facial authentication service is not started when **setSurfaceId()** of the **faceAuth** module is called.
2. The proxy client fails to write data over IPC.
3. The stub server fails to parse data over IPC.
4. An error occurs when the facial authentication driver is invoked.

**Solution**

Call the API again later or restart the device.
<!--DelEnd-->
