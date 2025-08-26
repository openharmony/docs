# @ohos.ability.screenLockFileManager (Sensitive Data Access Management Under Lock Screen)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @hongjin-li_admin-->
<!--Designer: @JerryH1011-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

Once the screen is locked, the keys for sensitive data are destroyed, preventing any read or write operations on that data. These keys can be restored only after the screen is unlocked. To facilitate data access on the lock screen, the screenLockFileManager module has been introduced. This module provides APIs to request and release the permission to access sensitive data on the lock screen, thereby managing sensitive data access securely.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { screenLockFileManager } from '@kit.AbilityKit';
```

## AccessStatus

Enumerates the statuses for requesting access to sensitive data on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

| Name          | Value  | Description                    |
| -------------- | ---- | ------------------------ |
| ACCESS_DENIED  | -1   | Access to sensitive data on the lock screen is denied.|
| ACCESS_GRANTED | 0    | Access to sensitive data on the lock screen is granted.    |


## ReleaseStatus

Enumerates the statuses for releasing access permissions to sensitive data on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

| Name| Value| Description|
|-----------------|----|----|
| RELEASE_DENIED |  -1 | Release of access to sensitive data on the lock screen is denied.|
| RELEASE_GRANTED |  0  |  Release of access to sensitive data on the lock screen is granted. |

## KeyStatus<sup>18+</sup>

Enumerates the statuses for access permissions for sensitive data on the lock screen.

 **System capability**: SystemCapability.Security.ScreenLockFileManager

| Name| Value| Description|
|-----------------|----|----|
| KEY_NOT_EXIST |  -2 | The application has not enabled sensitive data protection on the lock screen.|
| KEY_RELEASED |  -1 | The access permission for sensitive data on the lock screen has been released.|
| KEY_EXIST |  0  |  The application can access sensitive data on the lock screen. |

## screenLockFileManager.acquireAccess

acquireAccess(): AccessStatus

Requests the permission to access the application's sensitive data on the lock screen. This API returns the result synchronously. Generally, sensitive data cannot be accessed once the screen is locked. However, you can call this API to access the application's sensitive data on the lock screen.

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| [AccessStatus](#accessstatus) | State for requesting access to sensitive data on the lock screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801 | The specified SystemCapability name was not found. |
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

Releases the permission to access the application's sensitive data on the lock screen. This API returns the result synchronously.

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Return value**

| Type                           | Description                          |
| ------------------------------- | ------------------------------ |
| [ReleaseStatus](#releasestatus) | State for releasing access permissions to sensitive data on the lock screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | The specified SystemCapability name was not found.           |
| 29300002 | The system ability work abnormally.                          |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300005 | File access was not acquired. |

**Example**

```ts
// Release the permission to access sensitive data on the lock screen.
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

## screenLockFileManager.queryAppKeyState<sup>18+</sup>

queryAppKeyState(): KeyStatus

Obtains the state of access permissions for the application's sensitive data on the lock screen. This API returns the result synchronously.

**System capability**: SystemCapability.Security.ScreenLockFileManager

**Return value**

| Type                           | Description                          |
| ------------------------------- | ------------------------------ |
| [KeyStatus](#keystatus18) | State of access permissions for sensitive data on the lock screen.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [ohos.screenLockFileManager](errorcode-screenLockFileManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 801      | The specified SystemCapability name was not found.           |
| 29300002 | The system ability work abnormally.                          |

**Example**

```ts
// Obtain the state of access permissions for sensitive data on the lock screen.
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let keyStatus = screenLockFileManager.queryAppKeyState();
    if (keyStatus === screenLockFileManager.KeyStatus.KEY_NOT_EXIST) {
        hilog.info(0x0000, 'testTag', 'Key does not exist.');
    } else if (keyStatus === screenLockFileManager.KeyStatus.KEY_RELEASED) {
        hilog.info(0x0000, 'testTag', 'Key has been released.');
    } else if (keyStatus === screenLockFileManager.KeyStatus.KEY_EXIST) {
        hilog.info(0x0000, 'testTag', 'Key exists.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAppKeyState failed: %{public}s', message);
}
```
