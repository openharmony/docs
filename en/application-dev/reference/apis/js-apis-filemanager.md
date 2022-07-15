# User File Access and Management

The fileManager module provides APIs for accessing and managing user files. It interworks with the underlying file management services to implement media library and external card management, and provides capabilities for applications to query and create user files.

>**NOTE**<br/>
>
>- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs of this module are system APIs and cannot be called by third-party applications. Currently, these APIs can be called only by **filepicker**.

## Modules to Import

```js
import filemanager from '@ohos.fileManager';
```

## filemanager.getRoot

getRoot(options? : {dev? : DevInfo}) : Promise&lt;FileInfo[]&gt;

Obtains information about the root album or directory in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**
| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;[FileInfo](#fileinfo)[]&gt; | Promise used to return the root album or directory information obtained.|

**Example**

  ```js
  filemanager.getRoot().then((fileInfo) => {
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      }
  }).catch((err) => {
      console.log(err)
  });
  ```

## filemanager.getRoot

getRoot(options? : {dev? : DevInfo}, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

Obtains information about the root album or directory in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name  | Type                     | Mandatory| Description                         |
| -------- | ------------------------- | ---- | ----------------------------- |
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.|
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | Yes  | Callback invoked to return the root album or directory information obtained. |

**Example**

  ```js
  let options = {
    "dev":{
      "name":"local"
    }
  };
  filemanager.getRoot(options, (err, fileInfo)=>{
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      } 
  });
  
  ```

## filemanager.listFile

listFile(path : string, type : string, options? : {dev? : DevInfo, offset? : number, count? : number}) : Promise&lt;FileInfo[]&gt;

Obtains information about the second-level album or files in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**
| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| path | string | Yes| URI of the directory to query.|
| type | string | Yes| Type of the files to query. The file type can be **file**, **image**, **audio**, or **video**.|
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.<br>- &nbsp;**offset**: position to start the query. The value is a number.<br>- &nbsp;**count**: number of files to query.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;FileInfo[]&gt; | Promise used to return the album or file information obtained.|

**Error**

| Error Info| Error Code|Description|
| -- | --- | -- |
| No such file or directory | 2      | The directory or album of the specified URI does not exist.|
| No such process | 3 | Failed to obtain the FMS service.|
| Not a directory | 20 | The object specified by the URI is not a directory or album.|

**Example**

  ```js
  // Obtain all files in the directory.
  // Call listFile() and getRoot() to obtain the file URI.
  let media_path = ""
  filemanager.listFile(media_path, "file")
  .then((fileInfo) => {
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      }
  }).catch((err) => {
      console.log("Failed to get file"+err);
  });
  ```

## filemanager.listFile

listFile(path : string, type : string, options? : {dev? : DevInfo, offset? : number, count? : number}, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

Obtains information about the second-level album or files in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | Yes  | URI of the directory to query.                                               |
| type     | string                    | Yes  | Type of the files to query. The file type can be **file**, **image**, **audio**, or **video**.|
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.<br>- &nbsp;**offset**: position to start the query. The value is a number.<br>- &nbsp;**count**: number of files to query.|
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | Yes  | Callback invoked to return the root album or directory information obtained.                                |

**Error**

| Error Info                 | Error Code| Description                     |
| ------------------------- | ------ | ------------------------- |
| No such file or directory | 2      | The directory or album of the specified URI does not exist.|
| No such process           | 3      | Failed to obtain the FMS service.          |
| Not a directory           | 20     | The object specified by the URI is not a directory or album.|

**Example**

  ```js
  // Call listFile() and getRoot() to obtain the file path.
  let fileInfos = filemanager.getRoot(); 
  let media_path  = "";
  for (let i = 0; i < fileInfos.length; i++) {
	if (fileInfos[i].name == "image_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "audio_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "video_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "file_folder") {
	  media_path = fileInfos[i].path;
	}
  }

  filemanager.listFile(media_path, "file")
  .then((fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log("file:"+JSON.stringify(fileInfo));
        }
    }
  }).catch((err) => {
    console.log("Failed to get file"+err);
  });
  ```

## filemanager.createFile

createFile(path : string, filename : string, options? : {dev? : DevInfo})  :   Promise&lt;string&gt;

Creates a file in the specified path in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**
| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| filename | string | Yes| Name of the file to create.|
| path | string | Yes| URI of the file to create.|
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the file created.|

**Error**

| Error Info| Error Code|Description|
| -- | --- | -- |
| Operation not permitted | 1 | A file with the same name already exists.|
| No such file or directory | 2 | The directory or album of the specified URI does not exist.|
| No such process | 3 | Failed to obtain the FMS service.|
| Not a directory | 20 | The object specified by the URI is not a directory or album.|

**Example**

  ```js
  // Create a file.
  let media_path = "" // Obtain the file URI using listFile() and getRoot().
  let name = "xxx.jpg" // File to be saved.
  filemanager.createFile(media_path, name).then((uri) => {
      // The URI of the file created is returned.
      console.log("file uri:"+uri);
  }).catch((err) => {
      console.log(err);
  });
  ```

## filemanager.createFile

createFile(path : string, filename: string, options? : {dev? : DevInfo}, callback : AsyncCallback&lt;string&gt;) : void

Creates a file in the specified path in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name  | Type                     | Mandatory| Description                         |
| -------- | ------------------------- | ---- | ----------------------------- |
| filename | string                    | Yes  | Name of the file to create.               |
| path     | string                    | Yes  | URI of the file to create.            |
| options | Object | No| The options are as follows:<br>- &nbsp;**dev**: See [DevInfo](#devinfo). It is **dev = {name: "local"}** by default if not specified. Currently, only 'local' is supported.|
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | Yes  | Callback invoked to return the root album or directory information obtained. |

**Error**

| Error Info                 | Error Code| Description                     |
| ------------------------- | ------ | ------------------------- |
| Operation not permitted   | 1      | A file with the same name already exists.             |
| No such file or directory | 2      | The directory or album of the specified URI does not exist.|
| No such process           | 3      | Failed to obtain the FMS service.          |
| Not a directory           | 20     | The object specified by the URI is not a directory or album.|

**Example**

  ```js
  // Create a file.
  // Call listFile() and getRoot() to obtain the file URI.
  let media_path = ""
  // File to be saved.
  let name = "xxx.jpg"
  let options = {
    "dev":{
      "name":"local"
    }
  };
  filemanager.createFile(media_path, name, options, function(err, uri) {
    // The URI of the file created is returned.
    console.log("file uri:"+uri);
  });

  ```

## FileInfo
Defines the file information returned by **getRoot()** or **listFile()**.

**System capability**: SystemCapability.FileManagement.UserFileService

### Attributes

| Name| Type| Readable| Writable| Description|
| --- | -- | -- | -- | -- |
| name | string | Yes| No| File name.|
| path | string | Yes| No| URI of the file.|
| type | string | Yes| No| File type.|
| size | number | Yes| No| File size.|
| addedTime | number | Yes| No| Time when the file was scanned to the database.|
| modifiedTime | number | Yes| No| Time when the file was modified.|

## DevInfo

Defines the device type.

**System capability**: SystemCapability.FileManagement.UserFileService

### Attributes

| Name| Type  | Readable| Writable| Description    |
| ------ | ------ | ---- | ---- | -------- |
| name   | string | Yes  | Yes  | Device name.|
