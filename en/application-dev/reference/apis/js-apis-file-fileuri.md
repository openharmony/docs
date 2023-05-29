# @ohos.file.fileuri (File URI)

The **fileUri** module allows the uniform resource identifier (URI) of a file to be obtained based on the file path. With the file URI, you can use the APIs provided by [@ohos.file.fs](js-apis-file-fs.md) to operate the file.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import fileuri from "@ohos.file.fileuri";
```

Before using this module, you need to obtain the path of the file in the application sandbox. The following is an example:

 ```js
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
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

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid |

**Example**

  ```js
let filePath = pathDir + "test.txt";
let uri = fileuri.getUriFromPath(filePath);
  ```
