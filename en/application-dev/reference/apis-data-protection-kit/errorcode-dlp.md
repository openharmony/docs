# DLP Service Error Codes


> **NOTE**
> 
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 19100001 Invalid Parameter

**Error Message**

Invalid parameter.

**Description**

Invalid parameter values are detected.

**Possible Causes**

- The value of **account** is empty or exceeds 1024 characters.

- The account type is incorrect.

- The **aeskey** or **iv** is invalid.

- The authorization expiration time is earlier than the system time.

- **Fd** is less than **0**.

- The value of **tokenid** is **0**.

- The bundle name is empty.

- The value of **appindex** is less than **0**.

- The value of **userId** is less than **0**.

**Solution**

Check that all the parameters are set correctly.


## 19100002 Encryption/Decryption Error

**Error Message**

Begin encryption or decryption error.

**Description**

An error occurs in encryption or decryption.

**Possible Causes**

- The number of active encryption/decryption tasks is greater than 100.

- Duplicate encryption/decryption tasks are performed.

**Solution**

Try again later.


## 19100003 Encryption/Decryption Timeout

**Error Message**

Encryption or decryption timeout.

**Description**

The encryption or decryption timed out.

**Possible Causes**

The DLP file encryption/decryption task is not complete within 10 seconds.

**Solution**

Try again later.


## 19100004 Credential Service Error

**Error Message**

Credential service error.

**Description**

An error occurs in the credential service.

**Possible Causes**

- The DLP credential service does not exist.

- The DLP credential service is abnormal.

**Solution**

Wait for a while and try again, or restart the device.


## 19100005 Credential Authentication Server Error

**Error Message**

Credential server error.

**Description**

The credential authentication server is abnormal.

**Possible Causes**

- The credential authentication server cannot be connected.

- The credential authentication server does not exist.

**Solution**

Check the credential authentication server and try again.


## 19100006 Access Denied for a Non-DLP Sandbox Application

**Error Message**

No permission to call this API, which is available only for DLP sandbox applications.

**Description**

The caller is not a DLP sandbox application and cannot call the API.

**Possible Causes**

The API must be called by a DLP sandbox application.

**Solution**

The caller must be a DLP sandbox application.


## 19100007 Access Denied for a DLP Sandbox Application

**Error Message**

No permission to call this API, which is available only for non-DLP sandbox applications.

**Description**

The caller is a DLP sandbox application and cannot call the API.

**Possible Causes**

The API cannot be called by a DLP sandbox application.

**Solution**

The caller cannot be a DLP sandbox application.


## 19100008 Non-DLP File

**Error Message**

The file is not a DLP file.

**Description**

The file is not a DLP file.

**Possible Causes**

The file is not a DLP file.

**Solution**

Use a DLP file.


## 19100009 Failed to Operate the DLP File

**Error Message**

Failed to operate the DLP file.

**Description**

The operation on the DLP file fails.

**Possible Causes**

- The user is not an authorized user.

- The sandbox application fails to be installed.

- The link file is not associated.

- The number of opened DLP files reaches 1000.

**Solution**

1. Check that you are authorized to access the DLP file.

2. Wait for a while or restart the system and try again.


## 19100010 Read-Only DLP File

**Error Message**

The DLP file is read only.

**Description**

The DLP file is read-only.

**Possible Causes**

- You cannot modify the permission on a DLP file that is read-only.

- You cannot write a DLP file that is read-only.

**Solution**

Check the permission on the file.


## 19100011 System Service Abnormal

**Error Message**

The system ability works abnormally.

**Description**

The system service is abnormal.

**Possible Causes**

- The DLP permission service fails to start.

- The RPC object of the DLP permission service cannot be obtained.

- The service, on which the DLP permission service depends, fails to start.

- The IPC data fails to be read or written.

- The service is not initialized.

**Solution**

Try again later or restart the device.


## 19100012 Failed to Apply for Memory

**Error Message**

Out of memory.

**Description**

Failed to obtain the memory.

**Possible Causes**

The system memory is insufficient.

**Solution**

Try again later or restart the device.


## 19100013 User Access Denied

**Error Message**

The user does not have the permission.

**Description**

The user has no permission.

**Solution**

Check the user permissions.


## 19100014 Account Not Logged In

**Error Message**

Account not logged in.

**Description**

The user has not logged in with the account.

**Solution**

Log in with the account.


## 19100015 Upgrade Required

**Error Message**

Upgrade required.

**Description**

The system needs to be upgraded.

**Solution**

Upgrade the system.


## 19100016 URI Missing in Want

**Error Message**

uri missing in want.

**Description**

The **want** parameter does not contain the URI.

**Solution**

Set parameters correctly.


## 19100017 displayName Missing in Want

**Error Message**

displayName missing in want.

**Description**

The **want** parameter does not contain **displayName**.

**Solution**

Set parameters correctly.


## 19100018 Application Unauthorized

**Error Message**

Application not authorized.

**Description**

The application is not authorized.

**Possible Causes**

The application is not in the authorized application list.

**Solution**

Set the authorized application list.


## 19100019 DLP File Expired

**Error Message**

The DLP file has expired.

**Description**

The DLP file has expired.

**Solution**

Contact the file owner to authorize the file.


## 19100020 Network Disconnected

**Error Message**

No network connection.

**Description**

The device is not connected to Wi-Fi.

**Solution**

Connect the device to Wi-Fi.
