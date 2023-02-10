# @ohos.file.securityLabel (Data Label)

The **securityLabel** module provides APIs for managing data security levels of files, including obtaining and setting file security levels.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs of this module support processing of error codes. For details, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

## Modules to Import

```js
import securityLabel from '@ohos.file.securityLabel';
```

## Guidelines

Before using the APIs provided by this module to perform operations on files or directories, obtain the path of the file or directory in the application sandbox as follows:

**Stage Model**

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
 ```

**FA Model**

 ```js
 import featureAbility from '@ohos.ability.featureAbility';
 
 let context = featureAbility.getContext();
 context.getFilesDir().then((data) => {
      let pathDir = data;
 })
 ```

For details about how to obtain the FA model context, see [Context](js-apis-inner-app-context.md#context).

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:dataLevel):Promise&lt;void&gt;

Sets a security label for a file in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type      | Mandatory| Description                                        |
| --------- | ------    | ---- | -------------------------------------------- |
| path      | string    | Yes  | Path of the target file.                                    |
| type      | dataLevel | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Return value**

| Type               | Description            |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  securityLabel.setSecurityLabel(path, "s0").then(() => {
      console.info("setSecurityLabel successfully");
  }).catch((err) => {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:dataLevel, callback: AsyncCallback&lt;void&gt;):void

Sets a security label for a file in asynchronous mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                     | Mandatory| Description                                        |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | Yes  | Path of the target file.                                    |
| type      | dataLevel                 | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                  |

**Example**

  ```js
  securityLabel.setSecurityLabel(path, "s0", (err) => {
    if (err) {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("setSecurityLabel successfully.");
    }
  });
  ```

## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, type:dataLevel):void

Sets a security label for a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                        |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | Yes  | Path of the target file.                                    |
| type      | dataLevel | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Example**

```js
securityLabel.setSecurityLabelSync(path, "s0");
```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string):Promise&lt;string&gt;

Obtains the security label of a file in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| path   | string | Yes  | Path of the target file.|

**Return value**

| Type                 | Description        |
| --------------------- | ------------ |
| Promise&lt;string&gt; | Security label obtained.|

**Example**

  ```js
  securityLabel.getSecurityLabel(path).then((type) => {
      console.log("getSecurityLabel successfully, Label: " + type);
  }).catch((err) => {
      console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void

Obtains the security label of a file in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name  | Type                       | Mandatory| Description                      |
| -------- | --------------------------- | ---- | -------------------------- |
| path     | string                      | Yes  | Path of the target file.                  |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the security label obtained.|

**Example**

  ```js
  securityLabel.getSecurityLabel(path, (err, type) => {
    if (err) {
      console.log("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.log("getSecurityLabel successfully, Label: " + type);
    }
  });
  ```
## securityLabel.getSecurityLabelSync

getSecurityLabelSync(path:string):string

Obtains the security label of a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| path   | string | Yes  | Path of the target file.|

**Return value**

| Type  | Description        |
| ------ | ------------ |
| string | Security label obtained.|

**Example**

```js
let type = securityLabel.getSecurityLabelSync(path);
console.log("getSecurityLabel successfully, Label: " + type);
```
