# @ohos.file.statvfs (File System Space Statistics)

The **statfs** module provides APIs for obtaining file system information, including the total size and free size a file system, in bytes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import statvfs from '@ohos.file.statvfs';
```

## statvfs.getFreeSize

getFreeSize(path:string):Promise&lt;number&gt;

Obtains the free size of the specified file system in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Promise used to return the free size obtained, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path: string = "/dev";
  statvfs.getFreeSize(path).then((number: number) => {
    console.info("getFreeSize succeed, Size: " + number);
  }).catch((err: BusinessError) => {
    console.error("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statvfs.getFreeSize

getFreeSize(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the free size of the specified file system in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the free size obtained, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path: string = "/dev";
  statvfs.getFreeSize(path, (err: BusinessError, number: number) => {
    if (err) {
      console.error("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getFreeSize succeed, Size: " + number);
    }
  });
  ```

## statvfs.getFreeSizeSync<sup>10+</sup>

getFreeSizeSync(path:string): number

Obtains the free size of the specified file system in bytes. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description          |
  | --------------------- | -------------- |
  | number | Free size obtained, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let path = "/dev";
  let number = statvfs.getFreeSizeSync(path);
  console.info("getFreeSizeSync succeed, Size: " + number);
  ```

## statvfs.getTotalSize

getTotalSize(path: string): Promise&lt;number&gt;

Obtains the total size of the specified file system in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Promise used to return the total size obtained, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path: string = "/dev";
  statvfs.getTotalSize(path).then((number: number) => {
    console.info("getTotalSize succeed, Size: " + number);
  }).catch((err: BusinessError) => {
    console.error("getTotalSize failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statvfs.getTotalSize

getTotalSize(path: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total size of the specified file system in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total size obtained, in bytes.  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path: string = "/dev";
  statvfs.getTotalSize(path, (err: BusinessError, number: number) => {
    if (err) {
      console.info("getTotalSize failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getTotalSize succeed, Size: " + number);
    }
  });
  ```

## statvfs.getTotalSizeSync<sup>10+</sup>

getTotalSizeSync(path: string): number

Obtains the total size of the specified file system in bytes. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes  | File path of the file system.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | number | Total size obtained, in bytes.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

**Example**

  ```ts
  let path = "/dev";
  let number = statvfs.getTotalSizeSync(path);
  console.info("getTotalSizeSync succeed, Size: " + number);
  ```
