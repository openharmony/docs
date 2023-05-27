# @ohos.file.statvfs (File System Space Statistics)

The **statfs** module provides APIs for obtaining file system information, including the total number of bytes and the number of idle bytes of the file system.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import statvfs from '@ohos.file.statvfs';
```

## statvfs.getFreeSize

getFreeSize(path:string):Promise&lt;number&gt;

Obtains the number of free bytes of the specified file system in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Promise used to return the number of free bytes obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```js
  let path = "/dev";
  statvfs.getFreeSize(path).then((number) => {
    console.info("getFreeSize promise successfully, Size: " + number);
  }).catch((err) => {
    console.info("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statvfs.getFreeSize

getFreeSize(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the number of free bytes of the specified file system in asynchronous mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of free bytes obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```js
  let path = "/dev";
  statvfs.getFreeSize(path, (err, number) => {
    if (err) {
      console.info("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getFreeSize callback successfully, Size: " + number);
    }
  });
  ```

## statvfs.getTotalSize

getTotalSize(path: string): Promise&lt;number&gt;

Obtains the total number of bytes of the specified file system in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Promise used to return the total number of bytes obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```js
  let path = "/dev";
  statvfs.getTotalSize(path).then((number) => {
    console.info("getTotalSize promise successfully, Size: " + number);
  }).catch((err) => {
    console.info("getTotalSize with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statvfs.getTotalSize

getTotalSize(path: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total number of bytes of the specified file system in asynchronous mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total number of bytes obtained.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```js
  let path = "/dev";
  statvfs.getTotalSize(path, (err, number) => {
    if (err) {
      console.info("getTotalSize with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getTotalSize promise successfully, Size: " + number);
    }
  });
  ```
