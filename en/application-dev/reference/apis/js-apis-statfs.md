# statfs

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE:**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import statfs from '@ohos.statfs';
```

## Note

Before using this module to perform operations on a file or directory, obtain the absolute path of the file or directory. For details, see [getOrCreateLocalDir of the Context module](js-apis-Context.md).

Absolute file or directory path = Application directory + File name or directory name

For example, if the application directory obtained by using **getOrCreateLocalDir** is **dir** and the file name is **xxx.txt**, the absolute path of the file is as follows:

```js
let path = dir + "xxx.txt";
```

## System Capabilities

SystemCapability.FileManagement.File.FileIO

## statfs.getFreeBytes

getFreeBytes(path:string):Promise&lt;number&gt;

Obtains the number of free bytes of the specified file system in asynchronous mode. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | Yes| File path of the file system.|

- Return values

  | Type| Description|
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Number of free bytes obtained.|

- Example

  ```js
  let path = "/data";
  statfs.getFreeBytes(path).then(function (number){
      console.info("getFreeBytes successfully:"+ number);
  }).catch(function(err){
      console.info("getFreeBytes failed with error:"+ err);
  });
  ```

## statfs.getFreeBytes

getFreeBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the number of free bytes of the specified file system in asynchronous mode. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes| File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of free bytes obtained.|

- Example

  ```js
  statfs.getFreeBytes(path, function(err, number){
      // Do something.
  });
  ```

## statfs.getTotalBytes

getTotalBytes.(path:string):Promise&lt;number&gt;

Obtains the total number of bytes of the specified file system in asynchronous mode. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | Yes| File path of the file system.|

- Return values

  | Type| Description|
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Total number of bytes obtained.|

- Example

  ```js
  let path = "/data";
  statfs.getTotalBytes(path).then(function (number){
      console.info("getTotalBytes successfully:"+ number);
  }).catch(function(err){
      console.info("getTotalBytes failed with error:"+ err);
  });
  ```

## statfs.getTotalBytes

getTotalBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

Obtains the total number of bytes of the specified file system in asynchronous mode. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | Yes| File path of the file system.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the total number of bytes obtained.|

- Example

  ```js
  statfs.getTotalBytes(path, function(err, number){
      // Do something.
  });
  ```
