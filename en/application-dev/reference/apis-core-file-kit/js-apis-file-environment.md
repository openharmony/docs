# @ohos.file.environment (Directory Environment Capability)

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { Environment } from '@kit.CoreFileKit';
```

## Environment.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string

Obtains the sandbox path of the pre-authorized **Download** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Download** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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
    console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDownloadDir because: ${JSON.stringify(error)}`);
  }
}
```

## Environment.getUserDesktopDir<sup>11+</sup>

getUserDesktopDir(): string

Obtains the sandbox path of the pre-authorized **Desktop** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Desktop** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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
    console.log(`success to getUserDesktopDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDesktopDir because: ${JSON.stringify(error)}`);
  }
}
```

## Environment.getUserDocumentDir<sup>11+</sup>

getUserDocumentDir(): string

Obtains the sandbox path of the pre-authorized **Document** directory. Currently, only 2-in-1 devices are supported.

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Documents** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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
    console.log(`success to getUserDocumentDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDocumentDir because: ${JSON.stringify(error)}`);
  }
}
```
