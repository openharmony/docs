# @ohos.file.securityLabel (Data Label)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--SE: @gsl_1234; @wangke25-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

The **securityLabel** module provides APIs for managing data security levels of files, including obtaining and setting file security levels.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { securityLabel } from '@kit.CoreFileKit';
```

## How to Use

Before using the APIs provided by this module to perform operations on a file or directory, obtain the application sandbox path of the file or directory as follows:


  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

## DataLevel

type DataLevel = 's0' | 's1' | 's2' | 's3' | 's4'

Defines the data security level.

**System capability**: SystemCapability.FileManagement.File.FileIO

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:DataLevel):Promise&lt;void&gt;

Sets a security label for a file. The security label cannot be changed from a higher level to a lower level. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type      | Mandatory| Description                                        |
| --------- | ------    | ---- | -------------------------------------------- |
| path      | string    | Yes  | File path.                                    |
| type      | [DataLevel](#datalevel) | Yes  | Security label to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Return value**

  | Type               | Description            |
  | ------------------- | ---------------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0").then(() => {
    console.info("setSecurityLabel successfully");
  }).catch((err: BusinessError) => {
    console.error("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.setSecurityLabel

setSecurityLabel(path:string, type:DataLevel, callback: AsyncCallback&lt;void&gt;):void

Sets a security label for a file. The security label cannot be changed from a higher level to a lower level. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type                     | Mandatory| Description                                        |
| --------- | ------------------------- | ---- | -------------------------------------------- |
| path      | string                    | Yes  | File path.                                    |
| type      | [DataLevel](#datalevel)   | Yes  | Security label to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the security label set.                  |

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + '/test.txt';
  securityLabel.setSecurityLabel(filePath, "s0", (err: BusinessError) => {
    if (err) {
      console.error("setSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("setSecurityLabel successfully.");
    }
  });
  ```

## securityLabel.setSecurityLabelSync

setSecurityLabelSync(path:string, type:DataLevel):void

Sets a security label for a file. This API returns the result synchronously. The security label cannot be changed from a higher level to a lower level.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name   | Type  | Mandatory| Description                                        |
| --------- | ------ | ---- | -------------------------------------------- |
| path      | string | Yes  | File path.                                    |
| type      | [DataLevel](#datalevel) | Yes  | Security label to set, which can be **s0**, **s1**, **s2**, **s3**, or **s4**.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

```ts
let filePath = pathDir + '/test.txt';
securityLabel.setSecurityLabelSync(filePath, "s0");
```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string):Promise&lt;string&gt;

Obtains the security label. If no security label has been set for the file, **s3** is returned by default. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name| Type  | Mandatory| Description    |
  | ------ | ------ | ---- | -------- |
  | path   | string | Yes  | File path.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;string&gt; | Security label obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath).then((type: string) => {
    console.log("getSecurityLabel successfully, Label: " + type);
  }).catch((err: BusinessError) => {
    console.error("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## securityLabel.getSecurityLabel

getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void

Obtains the security label. If no security label has been set for the file, **s3** is returned by default. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

  | Name  | Type                       | Mandatory| Description                      |
  | -------- | --------------------------- | ---- | -------------------------- |
  | path     | string                      | Yes  | File path.                  |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the security label obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let filePath = pathDir + '/test.txt';
  securityLabel.getSecurityLabel(filePath, (err: BusinessError, type: string) => {
    if (err) {
      console.error("getSecurityLabel failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.log("getSecurityLabel successfully, Label: " + type);
    }
  });
  ```

## securityLabel.getSecurityLabelSync

getSecurityLabelSync(path:string):string

Obtains the security label. This API returns the result synchronously. If no security label has been set for the file, **s3** is returned by default.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| path   | string | Yes  | File path.|

**Return value**

| Type  | Description        |
| ------ | ------------ |
| string | Security label obtained.|

**Error codes**

For details about the error codes, see [Basic File IO Error Codes](errorcode-filemanagement.md#basic-file-io-error-codes).

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

```ts
let filePath = pathDir + '/test.txt';
let type = securityLabel.getSecurityLabelSync(filePath);
console.log("getSecurityLabel successfully, Label: " + type);
```
