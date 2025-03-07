# @ohos.file.environment (Directory Environment Capability) (System API)

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.environment](js-apis-file-environment-sys.md).

## Modules to Import

```ts
import { Environment } from '@kit.CoreFileKit';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

Obtains the root directory of the memory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | Promise used to return the root directory of the memory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getStorageDataDir().then((path: string) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
      console.error("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

Obtains the root directory of the memory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

**System API**: This is a system API.

**Parameters**

| Name  | Type                       | Mandatory| Description                            |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the root directory of the memory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getStorageDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.error("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getUserDataDir().then((path: string) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
    console.error("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
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
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the root directory of user files.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getUserDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.error("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getExternalStorageDir<sup>11+</sup>

getExternalStorageDir(): string

Obtains the sandbox path of the root directory of an external storage card. This API is available only to the devices with the SystemCapability.FileManagement.File.Environment.FolderObtain system capability.

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**System API**: This is a system API.

**Return value**

| Type                 | Description           |
| --------------------- |---------------|
| string | Sandbox path of the root directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message      |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getExternalStorageDirExample() {
  try {
    let path = Environment.getExternalStorageDir();
    console.log(`success to getExternalStorageDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getExternalStorageDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserHomeDir<sup>11+</sup>

getUserHomeDir(): string

Obtains the sandbox path of the built-in card directory of the current user. This API is available only to the devices with the SystemCapability.FileManagement.File.Environment.FolderObtain system capability.

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System capability**: SystemCapability.FileManagement.File.Environment.FolderObtain

**System API**: This is a system API.

**Return value**

| Type                 | Description             |
| --------------------- |-----------------|
| string | Sandbox path of the built-in card directory obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message      |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserHomeDirExample() {
  try {
    let path = Environment.getUserHomeDir();
    console.log(`success to getUserHomeDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserHomeDir because: ${JSON.stringify(error)}`);
  }
}
```
