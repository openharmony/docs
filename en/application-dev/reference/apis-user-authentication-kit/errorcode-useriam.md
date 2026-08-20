# User Authentication Error Codes

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

This topic describes error codes specific to the user authentication service. It helps you locate and handle authentication exceptions.

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 12500001 Authentication Failed

**Error Message**

Authentication failed.

**Description**

The user authentication failed, indicating that the authentication credential provided by the user does not match the credential registered on the device. This is a common authentication result, indicating that the user entered incorrect information or used an unregistered credential.

**Possible Causes**

1. The password, face, or fingerprint entered by the user does not match the registered credential.
2. The user uses an unregistered credential for authentication.
3. The biometric feature collection quality is poor, resulting in a comparison failure (for example, insufficient light for face recognition or incomplete fingerprint pressing).

**Solution**

1. It is recommended that the user be prompted to try authentication again.
2. If the biometric authentication fails, you can prompt the user to adjust the operation (for example, improve the illumination or press the fingerprint sensor correctly).
3. If the authentication fails for multiple times, prompt the user to check whether the corresponding credential has been registered or switch to another authentication mode.
4. Record the number of failures. When the number reaches the threshold, prompt the user that the lock mechanism may be triggered.

## 12500002 Common Error Code of the Identity Authentication System

**Error Message**

General operation error.

**Description**

An unrecoverable internal error occurred in the authentication system. This is a common error code, indicating that the system is abnormal and you cannot rectify the fault by adjusting parameters or operations.

**Possible Causes**

1. An error occurred when the NAPI layer parsed parameters. An exception occurred during parameter transfer.
2. The process of the user authentication service is not started or is terminated unexpectedly.
3. The proxy client of the IPC fails to write data, and the data transfer is abnormal.
4. The stub server of the IPC fails to parse data, and the data receiving is abnormal.
5. The driver service fails to be obtained, and the underlying driver service is unavailable.
6. The system resources are insufficient, and the memory allocation fails.

**Solution**

1. The internal system service is abnormal. You are advised to call the API again.
2. If the failure persists after multiple retries, you are advised to restart the device.

## 12500003 Authentication Canceled

**Error Message**

Authentication canceled.

**Description**

The authentication operation is canceled, indicating that the user proactively or passively terminates the authentication process.

**Possible Causes**

1. The user taps the cancel button or back button to proactively cancel the authentication.
2. The application calls the **cancel** API to proactively cancel the authentication.
3. The subsequent authentication request is preferentially completed, causing the previous authentication request to be forcibly canceled.

**Solution**

1. Determine whether to initiate the authentication again based on the user intent.
2. If the authentication is canceled due to system preemption, you are advised to initiate the authentication request again later.
3. Do not initiate multiple authentication requests at the same time to avoid preemption.

## 12500004 Authentication Timed Out

**Error Message**

Authentication timeout.

**Description**

The authentication operation times out. The authentication process is automatically terminated because the user failed to complete the interaction within the specified time.

**Possible Causes**

1. The user stays on the authentication page for too long and does not enter the password or perform biometric authentication in a timely manner.
2. During face authentication, the user does not look at the camera lens, and therefore valid face images cannot be captured for a long time.

**Solution**

1. Prompt the user to initiate the authentication again and pay attention to the operation time limit.
2. Prompt the user to respond in a timely manner during authentication, for example, look at the camera lens during face authentication.
3. Prompt the user to enter the password before timeout for password authentication.

## 12500005 Unsupported Authentication Type

**Error Message**

The authentication type is not supported.

**Description**

The current device or system does not support the requested authentication mode.

**Possible Causes**

1. The input authentication mode parameter is invalid. For example, the **authType** parameter passed when the [getAvailableStatus](js-apis-useriam-userauth.md#userauthgetavailablestatus9) API is called is not within the supported range (such as **PIN**, **FACE**, and **FINGERPRINT**).
2. The device does not support the authentication mode. For example, fingerprint authentication is initiated on a device that has no fingerprint sensor.

**Solution**

1. Check whether the input authentication mode parameter is correct. Ensure that the parameter value is supported.
2. Before initiating authentication, call [getAvailableStatus](js-apis-useriam-userauth.md#userauthgetavailablestatus9) to check whether the device supports the specified authentication mode. If the device does not support a certain authentication mode, you are advised to use another supported authentication mode.

## 12500006 Unsupported Authentication Trust Level

**Error Message**

The authentication trust level is not supported.

**Description**

The current authentication mode cannot meet the requested security level.

**Possible Causes**

1. When the [getAvailableStatus](js-apis-useriam-userauth.md#userauthgetavailablestatus9) or [getUserAuthInstance](js-apis-useriam-userauth.md#userauthgetuserauthinstance10) API is called, the value of the input parameter **authTrustLevel** is not within the valid range. The value should be **ATL1(10000)**, **ATL2(20000)**, **ATL3(30000)**, or **ATL4(40000)**.
2. The authentication capability of the current device cannot reach the specified authentication trust level. For example, face authentication of the ATL4 level is initiated on a 2D face authentication device.
3. The security level of the credential registered by the user is lower than the requested authentication trust level. For example, a 4-digit PIN can only reach the ATL3 level and cannot meet the ATL4 requirement.

**Solution**

1. Check whether the value of the input parameter **authTrustLevel** is within the valid range (ATL1 to ATL4).
2. If the parameter value is within the valid range, the current device may not support the authentication trust level. In this case, you are advised to reduce the authentication level.
3. Call the **getAvailableStatus** API to check whether the device supports the specified authentication trust level.
4. If a service requires a high security level, you can use an authentication mode that supports a higher level (for example, using PIN instead of face authentication).
5. For details about the level range supported by each authentication mode, see [Principles for Classifying Biometric Authentication Trust Levels](../../security/UserAuthenticationKit/user-authentication-overview.md).

## 12500007 Authentication Service Is Busy

**Error Message**

Authentication service is busy.

**Description**

The authentication service is busy processing other requests and cannot respond to the current authentication request. The system authentication service is temporarily unavailable.

**Possible Causes**

1. The authentication service is processing the authentication requests of other applications, and resources are occupied.
2. The system is performing other authentication-related operations (such as device unlocking) and cannot respond to new authentication requests.
3. The authentication service cannot respond to requests during startup.

**Solution**

1. If the service is busy, you are advised to initiate the authentication request again later.
2. Avoid frequently initiating authentication requests within a short period of time. You can increase the request interval.

## 12500008 Parameter Verification Failed

**Error Message**

The parameter is out of range.

**Description**

The parameter value is out of the valid range, indicating that the input parameter value is not within the valid range of the API description.

**Possible Causes**

1. The parameter value is out of the valid range. For example, the value of **reuseDuration** exceeds the value of **MAX_ALLOWABLE_REUSE_DURATION** (300,000 ms).
2. The value of a numeric parameter is a negative number or zero, but the API requires a positive integer.
3. The length of a string parameter exceeds the upper limit. For example, the value of **title** exceeds 500 characters, or the value of **navigationButtonText** exceeds 60 characters.
4. The array parameter is empty, but the API requires that the parameter be not empty. For example, the **authType** list is empty.
5. The length of a Uint8Array parameter exceeds the upper limit. For example, the value of **challenge** exceeds 32 bytes, or the value of **authToken** exceeds 1024 bytes.

**Solution**

1. Check the valid value range of each parameter in the parameter description in the API document, correct the parameter, and initiate the request again.
2. Ensure that the value of the numeric parameter is within the valid range and meet the type requirements.
3. Ensure that the length of the string parameter does not exceed the limit and the content meets the requirements.
4. Ensure that the array parameter is not empty and the elements are valid.
5. Ensure that the length of the binary data parameter is within the valid range.

## 12500009 Authentication Locked

**Error Message**

Authentication is locked out.

**Description**

The specified authentication mode has been locked, indicating that the anti-brute force mechanism is triggered due to consecutive authentication failures. As a result, the authentication function is temporarily unavailable.

**Possible Causes**

The user frequently attempts to use incorrect authentication credentials, and the system starts the protection mechanism to prevent brute-force attacks.

**Solution**

1. Notify the user that the authentication is locked and they can continue the authentication only after the lock is released.
2. You can call the [getAuthLockState](js-apis-useriam-userauth.md#userauthgetauthlockstate22) API to query the current lock status, including the remaining lock time and remaining attempts.
3. If the lock is temporary, notify the user to try again after the lock duration expires.
4. If the lock is permanent, notify the user that they can continue using biometric authentication only after unlocking it with a password.
5. Advise the user to authenticate with the correct credentials after the lock is released to avoid triggering the lock again.

## 12500010 Credential Not Enrolled

**Error Message**

The type of credential has not been enrolled.

**Description**

The user has not enrolled the specified type of authentication credential, indicating that the credential data corresponding to the requested authentication mode is not registered on the device.

**Possible Causes**

1. When the [getAvailableStatus](js-apis-useriam-userauth.md#userauthgetavailablestatus9) API of the **userAuth** module is called to check the authentication capability, the value of **authType** is **FACE** or **FINGERPRINT**, but the user has not enrolled the face or fingerprint credential on the device.
2. When the **start** API is called to initiate authentication, the credential corresponding to the requested authentication mode is not enrolled. For example, the user initiates fingerprint authentication but has not enrolled a fingerprint.
3. The credential that the user has enrolled has been deleted. For example, the user deletes the enrolled face or fingerprint in the settings.
4. The new user account has not enrolled any authentication credential.

**Solution**

1. Check whether the user has enrolled the credential of this type.
2. If the user has not enrolled the credential, guide the user to enroll the credential (face, fingerprint, or PIN) in the system settings.
3. You can call the [getEnrolledState](js-apis-useriam-userauth.md#userauthgetenrolledstate12) API to query the credential enrollment status.
4. If the user refuses to enroll the credential, you are advised to switch to another enrolled authentication mode.
5. Notify the user that the authentication function can be used only after the credential is enrolled.

## 12500011 Switched to Custom Authentication

**Error Message**

Switched to the custom authentication process.

**Description**

The user cancels the system authentication and uses a custom authentication of the application.

**Possible Causes**

The user taps the navigation button (specified by the **navigationButtonText** parameter) on the authentication widget page. The current system authentication operation is canceled and the user uses the custom authentication mode of the application.

**Solution**

After receiving this error code, the application needs to display the custom authentication page for the user to complete authentication.

## 12500013 Password Expired

**Error Message**

Operation failed because of PIN expired.

**Description**

The password has expired due to security policy requirements.

**Possible Causes**

1. The system lock screen password has expired, which is usually caused by enterprise security policies or system settings (for example, requiring periodic password updates).
2. When a user initiates password authentication, fingerprint authentication, or face authentication, the system detects that the lock screen password has expired.
3. After the password expires, biometric (fingerprint and face) authentication cannot be used because they rely on the password as an alternate unlock method.

**Solution**

1. Notify the user that the password has expired and the authentication function can be used only after the password is changed.
2. Guide the user to update the password in the system settings.
3. After updating the password, the user can initiate an authentication request again.
4. In an enterprise environment, the user may need to contact the administrator to understand the password update requirements.
5. Remind the user to periodically update the password to avoid impact caused by password expiration.

<!--Del-->
## 12500015 AuthToken Integrity Check Failed

**Error Message**

Operation failed because of authToken integrity check failed.

**Description**

The integrity verification of the **AuthToken** fails, indicating that the token is invalid or has been tampered with. The digital signature or data integrity verification of the token fails, and the authenticity of the token cannot be confirmed.

**Possible Causes**

1. The **AuthToken** to be verified is not a valid token issued by the system and may be a forged token.
2. The AuthToken is tampered with during transmission, and the data integrity is compromised.
3. The digital signature of **AuthToken** fails to be verified because the signature does not match or the signature algorithm is incorrect.
4. The AuthToken format is incorrect and does not comply with the token format defined by the system.
5. The **AuthToken** has expired. For example, the token becomes invalid due to the user credential change.

**Solution**

1. Initiate an authentication request again to obtain a valid **AuthToken** issued by the system.
2. Ensure that the **AuthToken** is not modified during transmission and use a secure data transmission mode.
3. If the credential has been changed, perform authentication again to obtain a new **AuthToken**.
4. For details about the **AuthToken** verification process, see the [verifyAuthToken](js-apis-useriam-useraccessctrl-sys.md#useraccessctrlverifyauthtoken) API.

## 12500016 AuthToken Has Expired

**Error Message**

Operation failed because of authToken has expired.

**Description**

The **AuthToken** has expired, indicating that the interval between the issuance time and the verification time of the authentication token exceeds the maximum validity period.

**Possible Causes**

1. The interval between the issuance time and the verification time of the **AuthToken** exceeds the maximum validity period specified by the **allowableDuration** parameter.
2. The **AuthToken** has been used for a long time, exceeding the maximum validity period (24 hours) set in the system.
3. The application initiates verification only when the **AuthToken** is about to expire. As a result, the verification times out.
4. The maximum validity period of the reused **AuthToken** is too short. As a result, the token expires in advance. The reason is that the **AuthToken** issuance time is the original authentication time, not the current call time.

**Solution**

1. Initiate an authentication request again to obtain a new valid **AuthToken**.
2. Use the **AuthToken** as soon as possible within its validity period to avoid expiration due to delay.
3. Set the **allowableDuration** parameter based on the service scenario to ensure that service requirements are met.

## 12500017 Authentication Result Reuse Failed

**Error Message**

Failed to reuse authentication result.

**Description**

The authentication result cannot be reused, indicating that the system cannot find the authentication result that meets the reuse conditions.

**Possible Causes**

1. The authentication mode does not match the specified reuse mode. For example, the face authentication result is requested for reuse, but the previous authentication uses the fingerprint.
2. The authentication result has exceeded the maximum reuse duration (5 minutes), and the previous authentication result has expired.
3. The reuse duration expires after the device is unlocked or after the last authentication.
4. The credential has changed within the reuse duration. For example, the user has deleted or added a fingerprint or face credential, causing the previous result to become unusable.
5. The trust level of the previous authentication is lower than that of the current request, and the reuse conditions are not met.
6. There are no history records of device unlocking or authentication that can be reused.

**Solution**

1. Initiate a new authentication request to obtain a valid **AuthToken** with the user's manual authentication.
2. Check whether the **reuseUnlockResult** parameter configuration is correct, including **reuseMode** and **reuseDuration**.
3. If the authentication result needs to be reused, ensure that the request is initiated within the validity period (a maximum of 5 minutes).
4. For details about the reuse mechanism and conditions, see [authentication result reuse](js-apis-useriam-userauth.md#reuseunlockresult12). Select a proper reuse mode and set a proper validity period.

## 12700001 Facial Authentication Service Unavailable

**Error Message**

The service is unavailable.

**Description**

The face authentication service is unavailable, indicating that the service required for face enrollment or authentication is not running properly.

**Possible Causes**

1. When the [setSurfaceId](js-apis-useriam-faceauth-sys.md#setsurfaceid) API of the **faceAuth** module is called, the face authentication service is not started.
2. The proxy client of the IPC fails to write data, and the data transfer is abnormal.
3. The stub server of the IPC fails to parse data, and the data receiving is abnormal.
4. The driver layer of the face service fails to be called, and the underlying driver service is abnormal.
5. The camera hardware service is unavailable, and the face image capture cannot be performed.
6. The face service process crashes or is terminated unexpectedly.

**Solution**

1. The internal system service is abnormal. You are advised to call the API again later.
2. If the failure persists after multiple retries, you are advised to restart the device.
3. Check whether the camera hardware works properly and whether other applications can use the camera properly.
4. Check the system logs to see whether there are records of service breakdown or driver exceptions.

## 32600001 System Service Not Working Properly

**Error Message**

The system service is not working properly. Please try again later.

**Description**

The companion device authentication service is unavailable, indicating that the system is abnormal and cannot respond to authentication requests.

**Possible Causes**

1. The companion device authentication service process is not started or is terminated unexpectedly.
2. The proxy client of the IPC fails to write data, and the data transfer is abnormal.
3. The stub server of the IPC fails to parse data, and the data receiving is abnormal.
4. System resources are insufficient, and the service cannot run properly.
5. The service cannot respond to requests during startup.

**Solution**

1. The system service is abnormal. You are advised to call the API again later.
2. If the failure persists after multiple retries, you are advised to restart the device.
3. Check the system logs to see whether there are records of service breakdown or insufficient resources.
4. Report this problem to the system administrator or technical support.

## 32600002 Template Not Found

**Error Message**

The template is not found.

**Description**

The companion device authentication template is not found, indicating that the specified template ID does not exist or has been deleted.

**Possible Causes**

1. The passed template ID is incorrect, and the corresponding template record does not exist.
2. The template has been deleted. For example, the user deletes the registered companion device.
3. The template ID format is incorrect and does not comply with the ID format defined by the system.
4. No companion device template is registered for the queried user.

**Solution**

1. Before updating the service scope or subscribing to the authentication status, ensure that the template exists.
2. If the template has been deleted, add the companion device again and register the template.
3. Ensure that the passed template ID matches the template registered by the user.
4. Check whether the template ID is correct. You can call [getTemplateStatus](js-apis-useriam-companiondeviceauth-sys.md#gettemplatestatus) to query the template list of the current user.

## 32600003 Invalid Service ID

**Error Message**

The business id is invalid.

**Description**

The service ID is invalid, indicating that the passed service ID is not within the supported range or does not meet the format requirements.

**Possible Causes**

1. The passed service ID is incorrect and is not within the supported service range.
2. The service ID is smaller than the reserved value range (0-9999) and conflicts with the service ID predefined in the system.
3. The service ID is greater than **VENDOR_BEGIN(10000)** but is not defined in the application.
4. The passed service ID array contains invalid values.
5. The service ID format is incorrect. It should be of the integer type.

**Solution**

1. Check whether the service ID is correct. For details about the service IDs supported by the system, see [BusinessId](js-apis-useriam-companiondeviceauth-sys.md#businessid).
2. Use the predefined system service ID (such as **DEFAULT**) or the vendor-defined ID (≥ 10000).
3. Ensure that the custom service ID is clearly defined in the application to avoid conflicts with the reserved values of the system.
4. When passing a service ID array, ensure that all elements are valid.
5. For details about the service ID usage requirements, see [updateEnabledBusinessIds](js-apis-useriam-companiondeviceauth-sys.md#companiondeviceauthupdateenabledbusinessids).
<!--DelEnd-->
