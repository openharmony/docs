# @ohos.ability.screenLockFileManager (Sensitive Data Access Management Under Lock Screen) (System API)

Once the screen is locked, the keys for sensitive data are destroyed, preventing any read or write operations on that data. These keys can be restored only after the screen is unlocked. To facilitate data access on the lock screen, the screenLockFileManager module has been introduced. This module provides APIs to request and revoke the permission to access sensitive data on the lock screen, thereby managing sensitive data access securely.

> **NOTE**
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.ability.screenLockFileManager](js-apis-screenLockFileManager.md).

## Modules to Import

```ts
import { screenLockFileManager } from '@kit.AbilityKit';
```

## DataType

Enumerates the types of sensitive data that can be accessed on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

 **System API**: This is a system API.

| Name      | Value        | Description          |
| ---------- | ---------- | -------------- |
| MEDIA_DATA | 0x00000001 | Media data.|
| ALL_DATA   | 0xffffffff | All encrypted data.    |

## screenLockFileManager.acquireAccess

acquireAccess(dataType: DataType): AccessStatus

Requests the permission to access a specified type of sensitive data on the lock screen. This API returns the result synchronously. Generally, sensitive data cannot be accessed once the screen is locked. However, you can call this API to access sensitive data of the specified type on the lock screen.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_MEDIA_DATA or ohos.permission.ACCESS_SCREEN_LOCK_ALL_DATA

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| dataType | [DataType](#datatype) | Yes  | Type of sensitive data that is accessible on the lock screen.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| [AccessStatus](js-apis-screenLockFileManager.md#accessstatus) | Sensitive data access status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. |
| 29300001 | Invalid parameter. |
| 29300002 | The system ability work abnormally. |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300004 | File access is denied. |

**Example**

```ts
// Request the permission to access media data on the lock screen.
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let acquireStatus = screenLockFileManager.acquireAccess(screenLockFileManager.DataType.MEDIA_DATA);
    if (acquireStatus === screenLockFileManager.AccessStatus.ACCESS_GRANTED) {
        hilog.info(0x0000, 'testTag', 'acquireAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'acquireAccess failed: %{public}s', message);
}
```

## screenLockFileManager.releaseAccess

releaseAccess(dataType: DataType): ReleaseStatus

Revokes the permission to access a specified type of sensitive data on the lock screen. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_SCREEN_LOCK_MEDIA_DATA or ohos.permission.ACCESS_SCREEN_LOCK_ALL_DATA

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| dataType | [DataType](#datatype) | Yes  | Type of sensitive data that is accessible on the lock screen.|

**Return value**

| Type                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| [ReleaseStatus](js-apis-screenLockFileManager.md#releasestatus) | Type of the operation used to revoke the permission to access sensitive data on the lock screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported.                                    |
| 29300001 | Invalid parameter.                                           |
| 29300002 | The system ability work abnormally.                          |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300005 | File access was not acquired.                                |

**Example**

```ts
// Revoke the permission to access media data on the lock screen.
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let releaseStatus = screenLockFileManager.releaseAccess(screenLockFileManager.DataType.MEDIA_DATA);
    if (releaseStatus === screenLockFileManager.ReleaseStatus.RELEASE_GRANTED) {
        hilog.info(0x0000, 'testTag', 'releaseAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'releaseAccess failed: %{public}s', message);
}
```
