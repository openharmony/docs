# Environment

This module provides JS APIs for obtaining the root directories of the storage and public files.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```js
import environment from '@ohos.environment';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

Obtains the root directory of the storage. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

- Return value

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;string&gt; | Promise returned with the root directory of the storage.|

- Example

  ```js
  environment.getStorageDataDir().then(function(path){
      console.info("getStorageDataDir successfully:"+ path);
  }).catch(function(error){
      console.info("getStorageDataDir failed with error:"+ error);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

Obtains the root directory of the storage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

- Parameters

  | Name  | Type                       | Mandatory| Description                            |
  | -------- | --------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Asynchronous callback used to return the root directory of the storage.|

- Example

  ```js
  environment.getStorageDataDir(function(error, path){
      // do something
  });
  ```

## environment.getUserDataDir

getUserDataDir():Promise&lt;string&gt;

Obtains the root directory of public files. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

- Return value

  | Type                 | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;string&gt; | Promise returned with the root directory of public files.|

- Example

  ```js
  environment.getUserDataDir().then(function(path){
      console.info("getUserDataDir successfully:"+ path);
  }).catch(function(error){
      console.info("getUserDataDir failed with error:"+ error);
  });
  ```

## environment.getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

Obtains the root directory of public files. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.Environment

- Parameters

  | Name  | Type                       | Mandatory| Description                            |
  | -------- | --------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Asynchronous callback used to return the root directory of public files.|
  
- Example

  ```js
  environment.getUserDataDir(function(error, path){
      // do something
  });
  ```
