# DLP Service Error Codes
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--SE: @lucky-jinduo-->
<!--TSE: @nacyli-->

> **NOTE**
> 
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 19100001 Invalid Parameter

**Error Message**

Invalid parameter value.

**Description**

Invalid parameters are specified.

**Possible Causes**

1. The value of **account** is empty or exceeds 1024 characters.

2. The account type is incorrect.

3. The **aeskey** or **iv** is invalid.

4. The authorization expiration time is earlier than the system time.

5. **Fd** is less than **0**.

6. The value of **tokenid** is **0**.

7. The bundle name is empty.

8. The value of **appIndex** is less than **0**.

9. The value of **userId** is less than **0**.

**Solution**

Set parameters correctly.

<!--Del-->
## 19100002 Encryption and Decryption Error

**Error Message**

Credential service busy due to too many tasks or duplicate tasks.

**Description**

An error occurs in encryption or decryption.

**Possible Causes**

1. The number of active encryption and decryption tasks is greater than 100.

2. Duplicate encryption/decryption tasks are performed.

**Solution**

Try again later.
<!--DelEnd-->

<!--Del-->
## 19100003 Encryption/Decryption Timeout

**Error Message**

Credential task time out.

**Description**

The encryption or decryption timed out.

**Possible Causes**

It takes more than 10 seconds to encrypt or decrypt a DLP file.

**Solution**

Try again later.
<!--DelEnd-->

<!--Del-->
## 19100004 Credential Service Error

**Error Message**

Credential service error.

**Description**

An error occurs in the credential service.

**Possible Causes**

1. The DLP credential service does not exist.

2. The DLP credential service is abnormal.

**Solution**

Wait for a while and try again, or restart the device.
<!--DelEnd-->

<!--Del-->
## 19100005 Credential Authentication Server Error

**Error Message**

Credential authentication server error.

**Description**

The credential authentication server is abnormal.

**Possible Causes**

1. The credential authentication server cannot be connected.

2. The credential authentication server does not exist.

**Solution**

Check the credential authentication server and try again.
<!--DelEnd-->

## 19100006 Access Denied for a Non-DLP Sandbox Application

**Error Message**

No permission to call this API, which is available only for DLP sandbox applications.

**Description**

The caller is not a DLP sandbox application.

**Possible Causes**

The caller is not a DLP sandbox application.

**Solution**

The caller must be a DLP sandbox application.

## 19100007 Access Denied for a DLP Sandbox Application

**Error Message**

No permission to call this API, which is available only for non-DLP sandbox applications.

**Description**

The caller cannot be a DLP sandbox application.

**Possible Causes**

The caller cannot be a DLP sandbox application.

**Solution**

The caller must be a DLP sandbox application.

<!--Del-->
## 19100008 Non-DLP File

**Error Message**

The file is not a DLP file.

**Description**

The file is not a DLP file.

**Possible Causes**

The file is not a DLP file.

**Solution**

Use a DLP file.
<!--DelEnd-->

<!--Del-->
## 19100009 Failed to Operate the DLP File

**Error Message**

Failed to operate the DLP file.

**Description**

The operation on the DLP file fails.

**Possible Causes**

1. The user is not an authorized user.

2. The sandbox application fails to be installed.

3. The link file is not associated.

4. The number of opened DLP files reaches 1000.

**Solution**

1. Check that you are authorized to access the DLP file.

2. Wait for a while or restart the system and try again.
<!--DelEnd-->

<!--Del-->
## 19100010 Read-Only DLP File

**Error Message**

The DLP file is read only.

**Description**

The DLP file is read-only.

**Possible Causes**

1. You cannot modify the permission on a DLP file, which is read-only.

2. You cannot write a DLP file, which is read-only.

**Solution**

Check the permission on the file.
<!--DelEnd-->

## 19100011 System Service Abnormal

**Error Message**

The system ability works abnormally.

**Description**

The system service is abnormal.

**Possible Causes**

1. The DLP permission service fails to start.

2. The RPC object of the DLP permission service cannot be obtained.

3. The service, on which the DLP permission service depends, fails to start.

4. The read or write of IPC data fails.

5. The service is not initialized.

**Solution**

Try again later or restart the device.

## 19100012 Failed to Apply for Memory

**Error Message**

System memory is insufficient.

**Description**

Failed to obtain the memory.

**Possible Causes**

The system memory is insufficient.

**Solution**

Try again later or restart the device.

<!--Del-->
## 19100013 User Access Denied

**Error Message**

The user does not have the permission.

**Description**

The user has no permission.

**Solution**

Check the user permissions.
<!--DelEnd-->

<!--Del-->
## 19100014 Account Not Logged In

**Error Message**

Account not logged in.

**Description**

You have not logged in with an account.

**Solution**

Log in using your account.
<!--DelEnd-->

<!--Del-->
## 19100015 Upgrade Required

**Error Message**

The system needs to be upgraded.

**Description**

The system needs to be upgraded.

**Solution**

Upgrade the system.
<!--DelEnd-->

## 19100016 URI Missing in Want

**Error Message**

The uri field is missing in the want parameter.

**Description**

The **want** parameter does not contain the URI.

**Solution**

Set parameters correctly.

## 19100017 displayName Missing in Want

**Error Message**

The displayName field is missing in the want parameter.

**Description**

The **want** parameter does not contain **displayName**.

**Solution**

Set parameters correctly.

## 19100018 Application Unauthorized

**Error Message**

The application is not authorized.

**Description**

The application is not authorized.

**Possible Causes**

The application is not in the authorized application list.

**Solution**

Set the authorized application list.

<!--Del-->
## 19100019 DLP File Has Expired

**Error Message**

The DLP file has expired.

**Description**

The DLP file has expired.

**Solution**

Contact the file owner to authorize the file.
<!--DelEnd-->

<!--Del-->
## 19100020 Network Disconnected

**Error Message**

No network connection.

**Description**

The device is not connected to Wi-Fi.

**Solution**

Connect the device to Wi-Fi.
<!--DelEnd-->
