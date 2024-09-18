# @ohos.ability.screenLockFileManager (Sensitive Data Access Management Under Lock Screen)

Once the screen is locked, the keys for sensitive data are destroyed, preventing any read or write operations on that data. These keys can be restored only after the screen is unlocked. To facilitate data access on the lock screen, the screenLockFileManager module has been introduced. This module provides APIs to request and revoke the permission to access sensitive data on the lock screen, thereby managing sensitive data access securely.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { screenLockFileManager } from '@kit.AbilityKit';
```

## AccessStatus

Enumerates the statuses available for access to sensitive data on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

| Name          | Value  | Description                    |
| -------------- | ---- | ------------------------ |
| ACCESS_DENIED  | -1   | Denies access to sensitive data on the lock screen.|
| ACCESS_GRANTED | 0    | Allows access to sensitive data on the lock screen.    |


## ReleaseStatus

Enumerates the types of operations used to revoke the permission to access sensitive data on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

| Name| Value| Description|
|-----------------|----|----|
| RELEASE_DENIED |  -1 | Revokes the permission that denies access to sensitive data on the lock screen.|
| RELEASE_GRANTED |  0  |  Revokes the permission that allows access to sensitive data on the lock screen. |

## screenLockFileManager.acquireAccess

acquireAccess(): AccessStatus

Requests the permission to access sensitive data on the lock screen. This API returns the result synchronously. Generally sensitive data cannot be accessed after the screen is locked. However, you can call this API to access sensitive data on the lock screen.

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| [AccessStatus](#accessstatus) | Sensitive data access status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801 | Capability not supported. |
| 29300002 | The system ability work abnormally. |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300004 | File access is denied. |

**Example**

```ts
// Request the permission to access sensitive data on the lock screen.
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let acquireStatus = screenLockFileManager.acquireAccess();
    if (acquireStatus === screenLockFileManager.AccessStatus.ACCESS_GRANTED) {
        hilog.info(0x0000, 'testTag', 'acquireAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'acquireAccess failed: %{public}s', message);
}
```

## screenLockFileManager.releaseAccess

releaseAccess(): ReleaseStatus

Revokes the permission to access sensitive data on the lock screen. This API returns the result synchronously.

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Return value**

| Type                           | Description                          |
| ------------------------------- | ------------------------------ |
| [ReleaseStatus](#releasestatus) | Type of the operation used to revoke the permission to access sensitive data on the lock screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.                                    |
| 29300002 | The system ability work abnormally.                          |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300005 | File access was not acquired. |

**Example**

```ts
// Revoke the permission to access sensitive data on the lock screen.
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let releaseStatus = screenLockFileManager.releaseAccess();
    if (releaseStatus === screenLockFileManager.ReleaseStatus.RELEASE_GRANTED) {
        hilog.info(0x0000, 'testTag', 'releaseAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'releaseAccess failed: %{public}s', message);
}
```
