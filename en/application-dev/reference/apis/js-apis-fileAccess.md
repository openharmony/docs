# @ohos.data.fileAccess (User File Access and Management)

The **fileAccess** module is a framework for accessing and operating user files based on the Extension ability mechanism. This module interacts with diverse file management services, such as the media library and external storage management service, and provides a set of file access and management APIs for system applications. The media library service allows access to user files on local devices and distributed devices. The external storage management service allows access to the user files stored on devices such as shared disks, USB flash drives, and SD cards.

>**NOTE**
>
>- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs provided by this module are system APIs and cannot be called by third-party applications. Currently, the APIs can be called only by **FilePicker** and **Files**.

## Modules to Import

```js
import fileAccess from '@ohos.data.fileAccess';
```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo( ) : Promise&lt;Array&lt;Want&gt;&gt;

Obtains information about all wants with **extension** set to **fileAccess** in the system. A want is a basic communication component used to start services. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Return value**

  | Type| Description|
  | --- | -- |
  | Promise&lt;Array&lt;Want&gt;&gt; | Promise used to return the **want** information obtained.|

**Example**

  ```js
  async getFileAccessAbilityInfo() {
    let wantInfos = [];
    try {
      wantInfos = await fileAccess.getFileAccessAbilityInfo();
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
    } catch (error) {
      console.error("getFileAccessAbilityInfo failed, error " + error);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context, wants: Array&lt;Want&gt;) : FileAccessHelper

Synchronously creates a **Helper** object to connect to the specified wants. The **Helper** object provides file access and management capabilities.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | context | Context | Yes| Context of the ability.|
  | wants | Array&lt;Want&gt; | Yes| Wants to connect.|

**Return value**

  | Type| Description|
  | --- | -- |
  | FileAccessHelper | **Helper** object created.|

**Example**

  ```js
  createFileAccessHelper() {
    let fileAccessHelper = null;
    / / Obtain wantInfos by using getFileAccessAbilityInfo().
    // Create a Helper object to interact with the media library service only.
    let wantInfos = [
      {
        "bundleName": "com.ohos.medialibrary.medialibrarydata",
        "abilityName": "FileExtensionAbility",
      },
    ]
    try {
      // this.context is passed by MainAbility.
      fileAccessHelper = fileAccess.createFileAccessHelper(this.context, wantInfos);
      if (!fileAccessHelper)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context) : FileAccessHelper

Synchronously creates a **Helper** object to connect to all file management services in the system.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | context | Context | Yes| Context of the ability.|

**Return value**

  | Type| Description|
  | --- | -- |
  | FileAccessHelper | **Helper** object created.|

**Example**

  ```js
  createFileAccessHelper() {
    let fileAccessHelperAllServer = null;
    // Create a Helper object to interact with all file management services configured with fileAccess in the system.
    try {
      // this.context is passed by MainAbility.
      fileAccessHelperAllServer = fileAccess.createFileAccessHelper(this.context);
      if (!fileAccessHelperAllServer)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## FileAccessHelper.getRoots

getRoots( ) : Promise&lt;RootIterator&gt;

Obtains information about the device root nodes of the file management service type connected to the **Helper** object. This API uses a promise to return a **RootIterator** object,
which returns [RootInfo](#rootinfo) by using [next](#rootiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

  | Type| Description|
  | --- | -- |
  | Promise&lt;RootIterator&gt; | Promise used to return the **RootIterator** object obtained.|

**Example**

  ```js
  async getRoots() {
    let rootIterator = null;
    let rootinfos = [];
    let isDone = false;
    try {
      // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
      rootIterator = await fileAccessHelper.getRoots();
      if (!rootIterator) {
        console.error("getRoots interface returns an undefined object");
        return;
      }
      while (!isDone) {
        let result = rootIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone)
          rootinfos.push(result.value);
      }
    } catch (error) {
      console.error("getRoots failed, error " + error);
    }
  }
  ```

## RootInfo.listfile

listFile(filter?: Filter) : FileIterator

Synchronously obtains the **FileIterator** object of the first-level files (file folder) matching the conditions of the filter from the device root node. The **FileIterator** object then returns [FileInfo](#fileinfo) by using [next()](#fileiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | -- | -- |
  | filter | Filter | No| **Filter** object. |


**Return value**

  | Type| Description|
  | --- | -- |
  | FileIterator | **FileIterator** object obtained.|

**Example**

  ```js
  // Obtain rootInfos by using getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo = rootinfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
    let fileIterator = rootInfo.listFile();
    // listFile contains the filter implementation.
    // let fileIterator = rootInfo.listFile(filter);
    if (!fileIterator) {
      console.error("listFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        fileInfos.push(result.value);
    }
  } catch (error) {
    console.log("listFile failed, error " + error);
  }
  ```

## RootInfo.scanFile

scanFile(filter?: Filter) : FileIterator

Recursively obtains the **FileIterator** object of the files matching the conditions of the filter from the device root node synchronously. The **FileIterator** object then returns [FileInfo](#fileinfo) by using [next()](#fileiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | -- | -- |
  | filter | Filter | No| **Filter** object. |

**Return value**

  | Type| Description|
  | --- | -- |
  | FileIterator | **FileIterator** object obtained.|

**Example**

  ```js
  // Obtain rootInfos by using getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo = rootInfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
    let fileIterator = rootInfo.scanFile();
    // scanFile contains the filter implementation.
    // let fileIterator = rootInfo.scanFile(filter);
    if (!fileIterator) {
      console.error("scanFile interface returns undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        fileInfos.push(result.value);
    }
  } catch (error) {
    console.error("scanFile failed, error " + error);
  }
  ```

## FileInfo.listfile

listFile(filter?: Filter) : FileIterator

Synchronously obtains the **FileIterator** object of the next-level files (file folders) matching the conditions of the filter from a directory. The **FileIterator** object then returns [FileInfo](#fileinfo) by using [next()](#fileiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | -- | -- |
  | filter | Filter | No| **Filter** object. |

**Return value**

  | Type| Description|
  | --- | -- |
  | FileIterator | **FileIterator** object obtained.|

**Example**

  ```js
  // fileInfoDir specifies the target directory.
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let fileInfoDir = fileInfos[0];
  let subfileInfos = [];
  let isDone = false;
  try {
    let fileIterator = fileInfoDir.listFile();
    // listFile contains the filter implementation.
    // let fileIterator = rootInfo.listFile(filter);
    if (!fileIterator) {
      console.error("listFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        subfileInfos.push(result.value);
    }
  } catch (error) {
    console.error("listFile failed, error " + error);
  }
  ```

## FileInfo.scanfile

scanFile(filter?: Filter) : FileIterator;

Recursively obtains the **FileIterator** object of the files matching the conditions of the filter from a directory synchronously. The **FileIterator** object then returns [FileInfo](#fileinfo) by using [next()](#fileiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | -- | -- |
  | filter | Filter | No| **Filter** object. |


**Return value**

  | Type| Description|
  | --- | -- |
  | FileIterator | **FileIterator** object obtained.|

**Example**

  ```js
  // fileInfoDir specifies the target directory.
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let fileInfoDir = fileInfos[0];
  let subfileInfos = [];
  let isDone = false;
  try {
    let fileIterator = fileInfoDir.scanFile();
    // scanFile contains the filter implementation.
    // let fileIterator = rootInfo.scanFile(filter);
    if (!fileIterator) {
      console.error("scanFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.log("next result = " + JSON.stringify(result));
      isDone = result.done;
      if (!isDone)
        subfileInfos.push(result.value);
    }
  } catch (error) {
    console.error("scanFile-filter failed, error " + error);
  }
  ```

## FileAccessHelper.createFile

createFile(uri: string, displayName: string) : Promise&lt;string&gt;

Creates a file in a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | uri | string | Yes| URI of the parent directory for the file to create.|
  | displayName | string | Yes| Name of the file to create. A file name extension must be added for a local file. It is not required for a file stored in a shared disk.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the file created.|

**Example**

  ```js
  // The media library URI is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri = "datashare:///media/file/6";
  let displayName = "file1"
  let fileUri = null;
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    fileUri = await fileAccessHelper.createFile(sourceUri, displayName)
    if (!fileUri) {
      console.error("createFile return undefined object");
      return;
    }
    console.log("File created successfully. fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("createFile failed, error " + error);
  };
  ```

## FileAccessHelper.mkDir

mkDir(parentUri: string, displayName: string) : Promise&lt;string&gt;

Creates a folder in a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | parentUri | string | Yes| URI of the parent directory for the folder to create.|
  | displayName | string | Yes| Name of the folder to create.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the folder created.|

**Example**

  ```js
  // The media library URI is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri = "datashare:///media/file/6";
  let dirName = "dirTest"
  let dirUri = null;
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    dirUri = await fileAccessHelper.mkDir(sourceUri, dirName)
    if (!dirUri) {
      console.error("mkDir return undefined object");
      return;
    }
    console.log("Folder created successfully. dirUri: " + JSON.stringify(dirUri));
  } catch (error) {
    console.error("mkDir failed, error " + error);
  };
  ```

## FileAccessHelper.openFile

openFile(uri: string, flags: OPENFLAGS) : Promise&lt;number&gt;

Opens a file in asynchronous mode and returns a file descriptor. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | uri | string | Yes| URI of the file to open.|
  | flags | [OPENFLAGS](#openflags) | Yes| File open mode.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;number&gt; | File descriptor.|

**Example**

  ```js
  // The media library URI is used as an example.
  //In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let targetUri  = "datashare:///media/file/100";
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fd = await fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ);
  } catch (error) {
    console.error("openFile failed, error " + error);
  };
  ```

## FileAccessHelper.delete

delete(uri: string) : Promise&lt;number&gt;

Deletes a file or folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | uri | string | Yes| URI of the file or folder to delete.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;number&gt | Promise used to return the result.|

**Example**

  ```js
  // The media library URI is used as an example.
  //In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let targetUri = "datashare:///media/file/100";
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let code = await fileAccessHelper.delete(targetUri);
    if (code != 0)
      console.error("delete failed, code " + code);
  } catch (error) {
    console.error("delete failed, error " + error);
  };
  ```

## FileAccessHelper.move

move(sourceFile: string, destFile: string) : Promise&lt;string&gt;

Moves a file or folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | sourceFile | string | Yes| URI of the file or folder to move.|
  | destFile | string | Yes| URI of the folder to which the file or folder is moved.|

**Return value**

| Type| Description|
| ----- | ------ |
| Promise&lt;string&gt; | Promise used to return the URI of the file or folder in the destination directory.|

**Example**

  ```js
  // The media library URI is used as an example.
  //In the sample code, sourceFile destFile indicates the file or folder in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceFile = "datashare:///media/file/102";
  let destFile = "datashare:///media/file/101";
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileUri = await fileAccessHelper.move(sourceFile, destFile);
    console.log("Operation successful. fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("move failed, error " + error);
  };
  ```

## FileAccessHelper.rename

rename(uri: string, displayName: string) : Promise&lt;string&gt;

Renames a file or folder. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | uri | string | Yes| URI of the file or folder to rename.|
  | displayName | string | Yes| New name of the file or folder, which can contain the file name extension.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the renamed file or folder.|

**Example**

  ```js
  // The media library URI is used as an example.
  // In the sample code, sourceDir indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceDir = "datashare:///media/file/100";
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
    console.log("Operation successful. DestDir: " + JSON.stringify(DestDir));
  } catch (error) {
    console.error("rename failed, error " + error);
  };
  ```

## FileAccessHelper.access

access(sourceFileUri: string) : Promise&lt;boolean&gt;

Checks whether a file or folder exists. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

  | Name| Type| Mandatory| Description|
  | --- | --- | --- | -- |
  | sourceFileUri | string | Yes| URI of the file or folder.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  // The media library URI is used as an example.
  // In the sample code, sourceDir indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceDir = "datashare:///media/file/100";
  try {
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let existJudgment = await fileAccessHelper.access(sourceDir);
    if (existJudgment)
      console.log("sourceDir exists");
    else
      console.log("sourceDir does not exist");
  } catch (error) {
    console.error("rename failed, error " + error);
  };
  ```

## RootIterator.next

next( ) : { value: RootInfo, done: boolean }

Obtains the next-level device root directory. **RootIterator** is an iterator object of the device root directory.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

| Type| Description|
| --- | -- |
| {value: RootInfo, done: boolean} | Root directory information obtained. This API traverses the folder until **done** returns **true**. The **value** field contains the root directory information.|

## FileIterator.next

next( ) : { value: FileInfo, done: boolean }

Obtains the information about the next-level file or folder. **FileIterator** is an iterator object of a folder.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

| Type| Description|
| --- | -- |
| {value: FileInfo, done: boolean} | File or folder information obtained. This API traverses the specified folder until **done** returns **true**. The **value** field contains the file or folder information obtained.|

## RootInfo

Represents the root attribute information and interface capabilities of a device.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### Attributes

| Name| Type  | Readable| Writable| Description    |
| ------ | ------ | -------- | ------ | -------- |
| deviceType | number | Yes| No|Device type.|
| uri | string | Yes| No| Root directory URI of the device.|
| displayName | string | Yes| No| Device name.|
| deviceFlags | number | Yes| No| Capabilities supported by the device.|

## FileInfo

Represents the file or folder attribute information and interface capabilities.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### Attributes

| Name| Type  | Readable| Writable| Description    |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | Yes| No| URI of the file or folder.|
| fileName | string | Yes| No| Name of a file or folder.|
| mode | number | Yes| No| Permissions on the file or folder.|
| size | number | Yes| No|  Size of the file or folder.|
| mtime | number | Yes| No|  Time when the file or folder was last modified.|
| mimeType | string | Yes| No|  MIME type of the file or folder.|

## OPENFLAGS

Enumerates the modes for opening a file.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Value| Description|
| ----- | ------ | ------ |
| READ | 0o0 | Read mode.|
| WRITE | 0o1 | Write mode.|
| WRITE_READ | 0o2 | Read/Write mode.|
