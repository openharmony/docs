# @ohos.file.environment (Directory Environment Capability)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--SE: @gsl_1234; @wangke25-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { Environment } from '@kit.CoreFileKit';
```

## Environment.getUserDownloadDir

getUserDownloadDir(): string

Obtains the sandbox path of the pre-authorized **Download** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Download** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message      |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDownloadDirExample() {
  try {
    let path = Environment.getUserDownloadDir();
    console.info(`Succeeded in getUserDownloadDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDownloadDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## Environment.getUserDesktopDir

getUserDesktopDir(): string

Obtains the sandbox path of the pre-authorized **Desktop** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Desktop** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message      |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDesktopDirExample() {
  try {
    let path = Environment.getUserDesktopDir();
    console.info(`Succeeded in getUserDesktopDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDesktopDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## Environment.getUserDocumentDir

getUserDocumentDir(): string

Obtains the sandbox path of the pre-authorized **Document** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Documents** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message      |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDocumentDirExample() {
  try {
    let path = Environment.getUserDocumentDir();
    console.info(`Succeeded in getUserDocumentDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDocumentDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```
