# statfs

The statfs module provides APIs for obtaining file system information, including the total number of bytes and the number of idle bytes of the file system.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import statfs from '@ohos.statfs';
```
## statfs.getFreeBytes

getFreeBytes(path:string):Promise&lt;number&gt;

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

**Example**

  ```js
  let path = "/dev";
  statfs.getFreeBytes(path).then(function (number) {
      console.info("getFreeBytes promise successfully:" + number);
  }).catch(function (err) {
      console.info("getFreeBytes failed with error:" + err);
  });
  ```

## statfs.getFreeBytes

getFreeBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the number of free bytes of the specified file system in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of free bytes obtained.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  let context = featureAbility.getContext();
  context.getFilesDir().then(function (path) {
      statfs.getFreeBytes(path, function (err, number) {
          console.info("getFreeBytes callback successfully:" + number);
      });
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string): Promise&lt;number&gt;

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

**Example**

  ```js
  let path = "/dev";
  statfs.getTotalBytes(path).then(function (number) {
      console.info("getTotalBytes promise successfully:" + number);
  }).catch(function (err) {
      console.info("getTotalBytes failed with error:" + err);
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total number of bytes of the specified file system in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total number of bytes obtained.  |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  let context = featureAbility.getContext();
  context.getFilesDir().then(function (path) {
      statfs.getTotalBytes(path, function(err, number) {
          console.info("getTotalBytes callback successfully:" + number);
      });
  });
  ```
