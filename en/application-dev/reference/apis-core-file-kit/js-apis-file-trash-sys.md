# @ohos.file.trash (Trash) (System API)

The **file.trash** module provides APIs for querying, recovering, or permanently deleting the files or directories in **Recently deleted** (trash). Currently, only local files and directories are supported.

You can use **delete()** of [@ohos.file.fileAccess](js-apis-fileAccess-sys.md) to move a file or directory to the trash.

>**NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.
> - Currently, the APIs of this module can be called only by **FileManager**.

## Modules to Import

```js
import trash from '@ohos.file.trash';
```

## trash.listFile

listFile(): Array\<FileInfo>

Lists the files and directories in the **Recently deleted** list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Return value**

  | Type| Description|
  | --- | -- |
  | Array [\<FileInfo>](#fileinfo) | List of the files and directories obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let fileinfos = trash.listFile();
  for(let i = 0; i < fileinfos.length; i++){
    console.info('uri: ' + fileinfos[i].uri);
    console.info('srcPath: ' + fileinfos[i].srcPath);
    console.info('fileName: ' + fileinfos[i].fileName);
    console.info('mode: ' + fileinfos[i].mode);
    console.info('size: ' + fileinfos[i].size);
    console.info('mtime: ' + fileinfos[i].mtime);
    console.info('ctime: ' + fileinfos[i].ctime);
  }
  ```

## trash.recover

recover(uri: string): void

Recovers a file or directory from the trash.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file or directory to recover.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let fileinfos = trash.listFile();
  let uri = fileinfos[0].uri;
  trash.recover(uri);
  ```

## trash.completelyDelete

completelyDelete(uri: string): void

Permanently deletes a file or directory from the **Recently deleted** list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file or directory to delete.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let fileinfos = trash.listFile();
  let uri = fileinfos[0].uri;
  trash.completelyDelete(uri);
  ```

## FileInfo

Represents information about a file or directory in the **Recently deleted** list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Type  | Read-Only| Optional| Description    |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | Yes| No| URI of the file or directory.|
| srcPath | string | Yes| No| Path of the file or directory before being deleted.|
| fileName | string | Yes| No| Name of the file or directory.|
| mode | number | Yes| No| Permission on the file or directory.|
| size | number | Yes| No|  Size of a file or directory, in bytes.|
| mtime | number | Yes| No|  Time when the file or directory was last modified. It is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).|
| ctime | number | Yes| No|  Time when the file or directory was created. It is the number of seconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).|
