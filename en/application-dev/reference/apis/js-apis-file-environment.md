# @ohos.file.environment (Directory Environment Capability)

The **Environment** module provides APIs for obtaining the root directories of the storage and user files.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```js
import environment from '@ohos.file.environment';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

Obtains the root directory of the storage. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

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

  ```js
  environment.getStorageDataDir().then((path) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err) => {
      console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

Obtains the root directory of the storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

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

  ```js
  environment.getStorageDataDir((err, path) => {
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

  ```js
  environment.getUserDataDir().then((path) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err) => {
    console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

Obtains the root directory of user files. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

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

  ```js
  environment.getUserDataDir((err, path) => {
    if (err) {
      console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```
