# @ohos.file.securityLabel (Data Label)

The **securityLabel** module provides APIs for managing data security levels of files, including obtaining and setting file security levels.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

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

setSecurityLabel(path:string, type:DataLevel):Promise&lt;void&gt;

Sets a security label for a file in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type      | Mandatory| Description                                        |
| --------- | ------    | ---- | -------------------------------------------- |
| path      | string    | Yes  | Path of the target file.                                    |
| type      | DataLevel | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Return value**

  | Type               | Description            |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0").then(() => {
      console.info("setSecurityLabel successfully");
  }).catch((err) => {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:DataLevel, callback: AsyncCallback&lt;void&gt;):void

Sets a security label for a file in asynchronous mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                     | Mandatory| Description                                        |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | Yes  | Path of the target file.                                    |
| type      | DataLevel                 | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0", (err) => {
    if (err) {
      console.info("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("setSecurityLabel successfully.");
    }
  });
  ```

## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, type:DataLevel):void

Sets a security label for a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                        |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | Yes  | Path of the target file.                                    |
| type      | DataLevel | Yes  | File security level to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

```js
let filePath = pathDir + '/test.txt';
securityLabel.setSecurityLabelSync(filePath, "s0");
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

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath).then((type) => {
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

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath, (err, type) => {
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

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900001 | Operation not permitted |
| 13900007 | Arg list too long |
| 13900015 | File exists |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900037 | No data available |
| 13900041 | Quota exceeded |
| 13900042 | Unknown error |

**Example**

```js
let filePath = pathDir + '/test.txt';
let type = securityLabel.getSecurityLabelSync(filePath);
console.log("getSecurityLabel successfully, Label: " + type);
```
