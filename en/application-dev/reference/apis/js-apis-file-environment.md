# @ohos.file.environment (Directory Environment Capability)

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import environment from '@ohos.file.environment';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

Obtains the root directory of the storage. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | Promise used to return the root directory of the storage.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getStorageDataDir().then((path: string) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
      console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

Obtains the root directory of the storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Parameters**

| Name  | Type                       | Mandatory| Description                            |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Asynchronous callback invoked to return the root directory of the storage.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getStorageDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getStorageDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getUserDataDir

getUserDataDir():Promise&lt;string&gt;

Obtains the root directory of user files. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Return value**

| Type                 | Description              |
| --------------------- | ------------------ |
| Promise&lt;string&gt; | Promise used to return the root directory of user files.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getUserDataDir().then((path: string) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
    console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

Obtains the root directory of user files. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Parameters**

| Name  | Type                       | Mandatory| Description                            |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Asynchronous callback used to return the root directory of user files.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getUserDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string

Obtains the sandbox path of the pre-authorized **Download** directory of the current user. This API is available only to specific devices.

**Required permissions**: ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the pre-authorized **Download** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

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

Obtains the sandbox path of the pre-authorized **Desktop** directory of the current user. This API is available only to specific devices.

**Required permissions**: ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the **Desktop** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

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

Obtains the sandbox path of the pre-authorized **Documents** directory of the current user. This API is available only to specific devices.

**Required permissions**: ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**System capability**: SystemCapability.FileManagement.File.Environment

**Return value**

| Type                 | Description                 |
| --------------------- |---------------------|
| string | Sandbox path of the pre-authorized **Documents** directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

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

## environment.getExternalStorageDir<sup>11+</sup>

getExternalStorageDir(): string

Obtains the sandbox path of the root directory of the external storage card. This API is available only to specific devices.

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Return value**

| Type                 | Description           |
| --------------------- |---------------|
| string | Sandbox path of the root directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message      |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@ohos.base';
function getExternalStorageDirExample() {
  try {
    let path = environment.getExternalStorageDir();
    console.log(`success to getExternalStorageDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getExternalStorageDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserHomeDir<sup>11+</sup>

getUserHomeDir(): string

Obtains the sandbox path of the built-in card directory of the current user. This API is available only to specific devices.

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Return value**

| Type                 | Description             |
| --------------------- |-----------------|
| string | Sandbox path of the built-in card directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message      |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@ohos.base';
function getUserHomeDirExample() {
  try {
    let path = environment.getUserHomeDir();
    console.log(`success to getUserHomeDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserHomeDir because: ${JSON.stringify(error)}`);
  }
}
```
