# ohos.screenLockFileManager Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 29300001 Invalid Parameter

**Error Message**

Invalid DataType.

**Possible Causes**

An error occurs during parameter verification. Specifically, **dataType** is not **MEDIA_DATA** or **ALL_DATA**.

**Solution**

Correct invalid parameter values.


## 29300002 System Service Abnormal

**Error Message**

The system ability work abnormally.

**Possible Causes**

System services are not working properly. The possible causes are as follows:
1. Sensitive data access management on the lock screen is not started properly.
2. The read or write of IPC data fails.

**Solution**

System services do not work properly. Try again later or restart the device.


## 29300003 Sensitive Data Access Management Under Lock Screen Is Not Enabled

**Error Message**

The application is not enabled the data protection under lock screen.

**Possible Causes**

1. The **ohos.permission.PROTECT_SCREEN_LOCK_DATA** permission is not configured in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md#requestpermissions) to enable the feature of protecting sensitive data on the lock screen.
2. The device does not support sensitive data access management on the lock screen.

**Solution**

Configure the **ohos.permission.PROTECT_SCREEN_LOCK_DATA** permission in the [module.json5 file](../../../application-dev/quick-start/module-configuration-file.md#requestpermissions) to enable the feature of protecting sensitive data on the lock screen.


## 29300004 Permission to Access Sensitive Data on the Lock Screen Has Been Revoked

**Error Message**

File access is denied.

**Possible Causes**

The permission to access sensitive data on the lock screen has been revoked.

**Solution**

Sensitive data cannot be accessed on the lock screen. If necessary, ask the user to unlock the screen again. The sensitive data can be used only after the screen is unlocked.


## 29300005 Permission to Access Sensitive Data on the Lock Screen Is Not Requested

**Error Message**

File access was not acquired.

**Possible Causes**

The permission to access sensitive data on the lock screen is not requested.

**Solution**

Ensure that the permission to access sensitive data on the lock screen is requested before calling the API to revoke the permission.
