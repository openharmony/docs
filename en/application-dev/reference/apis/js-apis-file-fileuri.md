# @ohos.file.fileuri (File URI)

The **fileUri** module allows the uniform resource identifier (URI) of a file to be obtained based on the file path. With the file URI, you can use the APIs provided by [@ohos.file.fs](js-apis-file-fs.md) to operate the file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fileuri from "@ohos.file.fileuri";
```

Before using this module, you need to obtain the application sandbox path of the file. The following is an example:

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

## FileUri<sup>10+</sup>

### Attributes

**System capability**: SystemCapability.FileManagement.AppFileService

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| path<sup>10+</sup> | string | Yes| No| Path of the file. |
| name<sup>10+</sup> | string | Yes| No| Name of the file.|

### constructor<sup>10+</sup>

constructor(uriOrPath: string)

A constructor used to create a **FileUri** instance.

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uriOrPath | string | Yes| URI or path. The following types of URIs are available:<br>- Application sandbox URI: **file://\<bundleName>/\<sandboxPath>**<br>- User file URI: **file://docs/storage/Users/currentUser/\<publicPath>**<br>- User media asset URI: **file://media/\<mediaType>/IMG_DATATIME_ID/\<displayName>** |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13900005 | I/O error |
| 13900042 | Unknown error |

**Example**

  ```ts
  let path = pathDir + '/test';
  let uri = fileuri.getUriFromPath(path);  // file://<packageName>/data/storage/el2/base/haps/entry/files/test
  let fileUriObject = new fileuri.FileUri(uri);
  console.info("The name of FileUri is " + fileUriObject.name);
  ```

### toString<sup>10+</sup>

toString(): string

**System capability**: SystemCapability.FileManagement.AppFileService

Obtains the URI of the string type.

**Return value**

| Type| Description|
| -------- | -------- |
| string | URI of the string type obtained.|

**Example**

  ```ts
  let path = pathDir + '/test';
  let fileUriObject = new fileuri.FileUri(path);
  console.info("The uri of FileUri is " + fileUriObject.toString());
  ```

### getFullDirectoryUri<sup>11+</sup>

getFullDirectoryUri(): string

Obtains the URI of the full directory of this file or folder.

For a file, this API returns the URI of the directory where the file is located. For example, **xxx** will be returned for the  **xxx/example.txt** file.

For a folder, this API returns the URI of the folder.

**System capability**: SystemCapability.FileManagement.AppFileService

**Return value**

| Type                 | Description                               |
| --------------------- |-----------------------------------|
| string | URI of the directory where the current file is located or URI of the current folder.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message                     |
| ---------------------------- |---------------------------|
| 13900002 | No such file or directory |
| 13900012 | Permission denied         |
| 13900042 | Unknown error             |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let path = pathDir + '/test.txt';
    let fileUriObject = new fileuri.FileUri(path);
    let directoryUri = fileUriObject.getFullDirectoryUri();
    console.log(`success to getFullDirectoryUri: ${JSON.stringify(directoryUri)}`);
  } catch (error) {
    console.error(`failed to getFullDirectoryUri because: ${JSON.stringify(error)}`);
  }
  ```

## fileuri.getUriFromPath

getUriFromPath(path: string): string

Obtains the URI based on a file path. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Application sandbox path of the file. |

**Return value**

| Type                          | Description        |
| ---------------------------- | ---------- |
| string | File URI obtained.|

**Error codes** 

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid |

**Example**

  ```ts
  let filePath = pathDir + "/test";
  let uri = fileuri.getUriFromPath(filePath);
  ```
