# @ohos.file.environment (Directory Environment Capability)

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import environment from '@ohos.file.environment';
```

## environment.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string

Obtains the sandbox path of the pre-authorized **Download** directory of the current user. This API is available only to the devices with the required system capability.

**Required permissions**: ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the pre-authorized **Download** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@ohos.base';
function getUserDownloadDirExample() {
  try {
    let path = environment.getUserDownloadDir();
    console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDownloadDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserDesktopDir<sup>11+</sup>

getUserDesktopDir(): string

Obtains the sandbox path of the pre-authorized **Desktop** directory of the current user. This API is available only to the devices with the required system capability.

**Required permissions**: ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Desktop** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@ohos.base';
function getUserDesktopDirExample() {
  try {
    let path = environment.getUserDesktopDir();
    console.log(`success to getUserDesktopDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDesktopDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserDocumentDir<sup>11+</sup>

getUserDocumentDir(): string

Obtains the sandbox path of the pre-authorized **Documents** directory of the current user. This API is available only to the devices with the required system capability.

**Required permissions**: ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the pre-authorized **Documents** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID   | Error Message      |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@ohos.base';
function getUserDocumentDirExample() {
  try {
    let path = environment.getUserDocumentDir();
    console.log(`success to getUserDocumentDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDocumentDir because: ${JSON.stringify(error)}`);
  }
}
```
