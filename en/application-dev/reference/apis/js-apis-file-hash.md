# @ohos.file.hash (File Hash Processing)

The **FileHash** module implements hash processing on files.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import Hash from '@ohos.file.hash';
```

## Guidelines

Before using the APIs provided by this module to perform operations on a file or directory, obtain the path of the file or directory in the application sandbox as follows:

Stage Model

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
 ```

FA Model

 ```js
 import featureAbility from '@ohos.ability.featureAbility';
 
 let context = featureAbility.getContext();
 context.getFilesDir().then((data) => {
      let pathDir = data;
 })
 ```

For details about how to obtain the FA model context, see [Context](js-apis-inner-app-context.md#context).

## Hash.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

Calculates a hash value for a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| path      | string | Yes  | Path of the file in the application sandbox.                            |
| algorithm | string | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|

**Return value**

  | Type                   | Description                        |
  | --------------------- | -------------------------- |
  | Promise&lt;string&gt; | Promise used to return the hash value. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  Hash.hash(filePath, "sha256").then((str) => {
    console.info("calculate file hash succeed:" + str);
  }).catch((err) => {
    console.info("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## Hash.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

Calculates a hash value for a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                       | Mandatory| Description                                                        |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | Yes  | Path of the file in the application sandbox.                            |
| algorithm | string                      | Yes  | Algorithm used to calculate the hash value. The value can be **md5**, **sha1**, or **sha256**. **sha256** is recommended for security purposes.|
| callback  | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the hash value obtained. The hash value is a hexadecimal string consisting of digits and uppercase letters.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](../errorcodes/errorcode-filemanagement.md#basic-file-io-error-codes).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  let filePath = pathDir + "/test.txt";
  Hash.hash(filePath, "sha256", (err, str) => {
    if (err) {
      console.info("calculate file hash failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("calculate file hash succeed:" + str);
    }
  });
  ```
