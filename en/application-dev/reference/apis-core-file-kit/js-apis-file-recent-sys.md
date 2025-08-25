# @ohos.file.recent (Latest Access List) (System API)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

The **file.recent** module provides APIs for managing the list of recently accessed files.

>**NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.
> - Currently, the APIs of this module can be called only by **FileManager**.

## Modules to Import

```js
import recent from '@ohos.file.recent';
```

## recent.add

add(uri: string): void

Adds the file of the specified URI to the recent file list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file to add.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let uri = 'file://docs/storage/Users/currentUser/<publicPath>';
  recent.add(uri);
  ```

## recent.remove

remove(uri: string): void

Removes the file of the specified URI from the recent file list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | Yes  | URI of the file to remove.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let uri = 'file://docs/storage/Users/currentUser/<publicPath>';
  recent.remove(uri);
  ```

## recent.listFile

listFile(): Array\<FileInfo>

Lists the files that are accessed recently.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**System API**: This is a system API.

**Return value**

  | Type| Description|
  | --- | -- |
  |  Array<[FileInfo](#fileinfo)> | List of the files.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```js
  let fileinfos = recent.listFile();
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

## FileInfo

Represents information about the recent file list.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Type  | Read-Only| Optional| Description    |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | Yes| No| File URI.|
| srcPath | string | Yes| No| File path.|
| fileName | string | Yes| No| File name.|
| mode | number | Yes| No| [Permissions on the file](js-apis-file-fs.md#stat).|
| size | number | Yes| No|  File size, in bytes.|
| mtime | number | Yes| No|  Time when the file was last modified.|
| ctime | number | Yes| No|  Time when the file was created.|
