# @ohos.statfs (statfs)

The **statfs** module provides APIs for obtaining file system information, including the total size and free size of a file system, in bytes.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [@ohos.file.statvfs](js-apis-file-statvfs.md).

## Modules to Import

```ts
import statfs from '@ohos.statfs';
```

## statfs.getFreeBytes

getFreeBytes(path:string):Promise&lt;number&gt;

Obtains the free size of the specified file system, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes  | Path of the file system.|

**Return value**

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Promise used to return the free size obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path = "/dev";
  statfs.getFreeBytes(path).then((number: number) => {
    console.info("getFreeBytes promise successfully:" + number);
  }).catch((err: BusinessError) => {
    console.error("getFreeBytes failed with error:" + JSON.stringify(err));
  });
  ```

## statfs.getFreeBytes

getFreeBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the free size of the specified file system, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | Path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the free size obtained.|

**Example**

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getFreeBytes(path, (err: BusinessError, freeBytes:Number) => {
      if (err) {
          console.error('getFreeBytes callback failed');
      } else {
          console.info('getFreeBytes callback success' + freeBytes);
      }
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string): Promise&lt;number&gt;

Obtains the total size of the specified file system, in byte. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes  | Path of the file system.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Promise used to return the total size obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let path = "/dev";
  statfs.getTotalBytes(path).then((number: number) => {
    console.info("getTotalBytes promise successfully:" + number);
  }).catch((err: BusinessError) => {
    console.error("getTotalBytes failed with error:" + JSON.stringify(err));
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total size of the specified file system, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | Path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the total size obtained.  |

**Example**

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getTotalBytes(path, (err: BusinessError, totalBytes:Number) => {
      if (err) {
          console.error('getTotalBytes callback failed');
      } else {
          console.info('getTotalBytes callback success' + totalBytes);
      }
  });
  ```
