# @ohos.file.fileuri (File URI)

The **fileUri** module allows the uniform resource identifier (URI) of a file to be obtained based on the file path. With the file URI, you can use the APIs provided by [@ohos.file.fs](js-apis-file-fs.md) to operate the file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import fileUri from "@ohos.file.fileuri";
```

Before using this module, you need to obtain the path of the file in the application sandbox. The following is an example:

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
| path<sup>10+</sup> | string | Yes| No| Path of the file corresponding to the URI.|
| name<sup>10+</sup> | string | Yes| No| Name of the file.|

### constructor<sup>10+</sup>

constructor(uriOrPath: string)

A constructor used to create a **FileUri** instance.

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uriOrPath | string | Yes| URI or path. The following types of URIs are available:<br>- Application sandbox URI: **file://\<bundleName>/\<sandboxPath>**<br>- URI of the user's document: **file://docs/storage/Users/currentUser/\<publicPath>**<br>- URI of the user's media asset: **file://media/\<mediaType>/IMG_DATATIME_ID/\<displayName>**|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13900005 | I/O error |
| 13900042 | Unknown error |

**Example**

  ```ts
  let path = pathDir + '/test';
  let uri = fileUri.getUriFromPath(path);  // file://<packageName>/data/storage/el2/base/haps/entry/files/test
  let fileUriObject = new fileUri.FileUri(uri);
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
  let fileUriObject = new fileUri.FileUri(path);
  console.info("The uri of FileUri is " + fileUriObject.toString());
  ```

## fileUri.getUriFromPath

getUriFromPath(path: string): string

Obtains the URI of a file in synchronous mode.

**System capability**: SystemCapability.FileManagement.AppFileService

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| path   | string | Yes  | Path of the file in the application sandbox.|

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
  let uri = fileUri.getUriFromPath(filePath);
  ```
