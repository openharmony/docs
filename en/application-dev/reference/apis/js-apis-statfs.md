# statfs

> **NOTE:**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

This module provides information related to the file system. It provides JS APIs to obtain the total number of bytes and the number of idle bytes of the file system.

## Modules to Import

```js
import statfs from '@ohos.statfs';
```

## Guidelines

Before using the APIs provided by this module to perform operations on a file or directory, obtain the path of the application sandbox. For details, see [getOrCreateLocalDir of the Context module](js-apis-Context.md).

Application sandbox path of a file or directory = Application directory + File name or directory name

For example, if the application directory obtained by using **getOrCreateLocalDir** is **dir** and the file name is **xxx.txt**, the application sandbox path of the file is as follows:

```js
let path = dir + "xxx.txt";
```

## statfs.getFreeBytes

getFreeBytes(path:string):Promise&lt;number&gt;

Obtains the number of free bytes of the specified file system in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes  | File path of the file system.|

- Return value

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Promise used to return the number of free bytes obtained.|

- Example

  ```js
  let path = "/dev";
  statfs.getFreeBytes(path).then(function (number){
      console.info("getFreeBytes promise successfully:"+ number);
  }).catch(function(err){
      console.info("getFreeBytes failed with error:"+ err);
  });
  ```

## statfs.getFreeBytes

getFreeBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the number of free bytes of the specified file system in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the number of free bytes obtained.|

- Example

  ```js
  statfs.getFreeBytes(path, function(err, number){
      console.info("getFreeBytes callback successfully:"+ number);
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string): Promise&lt;number&gt;

Obtains the total number of bytes of the specified file system in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes  | File path of the file system.|

- Return value

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Promise used to return the total number of bytes obtained.|

- Example

  ```js
  let path = "/dev";
  statfs.getTotalBytes(path).then(function (number){
      console.info("getTotalBytes promise successfully:"+ number);
  }).catch(function(err){
      console.info("getTotalBytes failed with error:"+ err);
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total number of bytes of the specified file system in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes  | File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total number of bytes obtained.  |

- Example

  ```js
  statfs.getTotalBytes(path, function(err, number){
      console.info("getTotalBytes callback successfully:"+ number);
  });
  ```
