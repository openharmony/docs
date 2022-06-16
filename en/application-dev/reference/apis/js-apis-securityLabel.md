# Security Label

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Manages file data security levels, including obtaining and setting file data security levels.

## Modules to Import

```js
import securityLabel from '@ohos.securityLabel';
```

## Usage

Before using the APIs provided by this module to perform operations on a file or directory, obtain the path of the application sandbox. For details, see [getOrCreateLocalDir of the Context module](js-apis-Context.md).

Application sandbox path of a file or directory = Application directory + File name or directory name

For example, if the application directory obtained by using **getOrCreateLocalDir** is **dir** and the file name is **xxx.txt**, the application sandbox path of the file is as follows:

```js
let path = dir + "/xxx.txt";
```

The file descriptor is as follows:

```js
let fd = fileio.openSync(path, 0o102, 0o666);
```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, dataLevel:string):Promise&lt;void&gt;

Sets the security label for a file in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

| Name   | Type  | Mandatory| Description                                        |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | Yes  | File path.                                    |
| dataLevel | string | Yes  | File security level, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Return value**

  | Type               | Description            |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise used to return the result. An empty value will be returned.|

**Example**

  ```js
  securityLabel.setSecurityLabel(path, dataLevel).then(function(){
      console.info("setSecurityLabel successfully");
  }).catch(function(error){
      console.info("setSecurityLabel failed with error:" + error);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, dataLevel:string, callback: AsyncCallback&lt;void&gt;):void

Sets the security label for a file in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

| Name   | Type                     | Mandatory| Description                                        |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | Yes  | File path.                                    |
| dataLevel | string                    | Yes  | File security level, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                  |

**Example**

  ```js
  securityLabel.setSecurityLabel(path, dataLevel, function(error){
      console.info("setSecurityLabel:" + JSON.stringify(error));
  });
  ```
## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, dataLevel:string):void

Sets the security label for a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

| Name   | Type  | Mandatory| Description                                        |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | Yes  | File path.                                    |
| dataLevel | string | Yes  | File security level, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Example**

```js
securityLabel.setSecurityLabelSync(path, dataLevel);
```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string):Promise&lt;string&gt;

Obtains the security label of a file in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

  | Name| Type  | Mandatory| Description    |
  | ------ | ------ | ---- | -------- |
  | path   | string | Yes  | File path.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;string&gt; | Promise used to return the security label obtained.|

**Example**

  ```js
  securityLabel.getSecurityLabel(path).then(function(dataLevel){
      console.log("getSecurityLabel successfully:" + dataLevel);
  }).catch(function(error){
      console.log("getSecurityLabel failed with error:" + error);
  });
  ```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void

Obtains the security label of a file in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

  | Name  | Type                       | Mandatory| Description                      |
  | -------- | --------------------------- | ---- | -------------------------- |
  | path     | string                      | Yes  | File path.                  |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the security label obtained.|

**Example**

  ```js
  securityLabel.getSecurityLabel(function(error, dataLevel){
      console.log("getSecurityLabel successfully:" + dataLevel);
  });
  ```
## securityLabel.getSecurityLabelSync

getSecurityLabelSync(path:string):string

Obtains the security label of a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.DistributedFile

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| path   | string | Yes  | File path.|

**Return value**

| Type  | Description        |
| ------ | ------------ |
| string | Security label obtained.|

**Example**

```js
let result = securityLabel.getSecurityLabelSync(path);
console.log("getSecurityLabel successfully:" + result);
```
