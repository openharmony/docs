# @ohos.file.keyManager (User Key Management) (System API)

This module provides common functions related to user key management, including user key uninstallation.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module.

## Modules to Import

```ts
import { keyManager } from "@kit.CoreFileKit";
```

## keyManager.deactivateUserKey

deactivateUserKey(userId: number):void

When the screen is locked, the specified user key is uninstalled synchronously. **(Currently, this API is available only to lock screen applications.)**

**Required permission**: ohos.permission.STORAGE_MANAGER_CRYPT

**System capability**: SystemCapability.FileManagement.StorageService.Encryption

**System API**: This is a system API.

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | userId | number | Yes  | User ID. This parameter specifies the user who currently logs in to the lock screen application.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified; Or input parameter has type different from the type the interface requires. |
| 13600001 | IPC error. |
| 13600008 | No such object. Possible causes: Cannot find user key for the specified user. |
| 13600009 | User ID out of range. Possible causes: input parameter userId < 100 or userId > 10736. |

**Example**:

  ```ts
  import { keyManager } from "@kit.CoreFileKit";
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  try {
    keyManager.deactivateUserKey(userId);
    console.info("deactivateUserKey success");
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("deactivateUserKey failed with error:" + JSON.stringify(error));
  }
  ```
