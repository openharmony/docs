# User File Access and Management

The **fileAccess** module is a framework for accessing and operating user files based on the extension mechanism. This module interacts with diverse file management services, such as the media library and external storage management service, and provides a set of unified file access and management APIs for system applications. The media library service allows access to user files on local devices and distributed devices. The external storage management service allows access to the user files stored on devices such as shared disks, USB flash drives, and SD cards.

>**NOTE**
>
>- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>- The APIs provided by this module are system APIs and cannot be called by third-party applications. Currently, the APIs can be called only by FilePicker and the file manager app.

## Modules to Import

```js
import fileAccess from '@ohos.data.fileAccess';
```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo( ) : Promise&lt;Array&lt;Want&gt;&gt;

Obtains information about all wants with **extension** set to **fileAcesss** in the system. A want is a basic communication component used to start services. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

None

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;Array&lt;Want&gt;&gt; | Promise used to return the want information obtained.|

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

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

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
    let fileAccesssHelper = null;
    // Obtain want information by using getFileAccessAbilityInfo().
    // Create a Helper object to interact with the media library service only.
    let wantInfo = {
        "bundleName": "com.ohos.medialibrary.medialibrarydata",
        "abilityName": "FileExtensionAbility",
    }
    try {
      fileAccesssHelper = fileAccess.createFileAccessHelper(this.context, wantInfos);
      if (!fileAccesssHelper)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context) : FileAccessHelper

Synchronously creates a **Helper** object that connects to all file management services in the current system.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

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
    let fileAccesssHelperAllServer = null;
    // Create a Helper object to interact with all file management services configured with fileAccess in the system.
    try {
      fileAccesssHelperAllServer = fileAccess.createFileAccessHelper(this.context);
      if (!fileAccesssHelperAllServer)
        console.error("createFileAccessHelper interface returns an undefined object");
    } catch (error) {
      console.error("createFileAccessHelper failed, error " + error);
    }
  }
  ```

## FileAccessHelper.getRoots

getRoots( ) : Promise&lt;RootIterator&gt;

Obtains information about the root nodes for the devices of the file management service type connected to the **Helper** object. This API uses a promise to return a **RootIterator** object, which
returns [RootInfo](#rootinfo) by using [next()](#rootiteratornext).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

None

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;RootIterator&gt; | **RootIterator** object obtained.|

**Example**

  ```js
  async getRoots() {
    let rootIterator = null;
    let rootinfos = [];
    let isDone = false;
    try {
      rootIterator = await fileAccesssHelper.getRoots();
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

Synchronously obtains the **FileIterator** object of the first-level files (file folder) matching the conditions of the filter from the root node of a device. The **FileIterator** object then returns [FileInfo](#fileinfo) by using [next()](#fileiteratornext).

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
  / / Obtain root information by using getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo = rootinfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
    let fileIterator = rootInfo.listFile();
    // ListFile that contains the filter implementation.
    // let fileIterator = rootInfo.listFile(filter);
     if (fileIterator) {
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

Recursively obtains the **FileIterator** object of the files matching the conditions of the filter from the root node of a device synchronously. The **FileIterator** object then returns [FileInfo](#fileinfo) by using the [next()](#fileiteratornext).

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
  / / Obtain root information by using getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo = rootinfos[0];
  let fileInfos = [];
  let isDone = false;
  try {
      let fileIterator = rootInfo.scanFile();
      // ScanFile that contains the filter implementation
      // let fileIterator = rootInfo.scanFile(filter);
       if (fileIterator) {
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
    // ListFile that contains the filter implementation.
    // let fileIterator = rootInfo.listFile(filter);
     if (fileIterator) {
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
    // ScanFile that contains the filter implementation
    // let fileIterator = rootInfo.scanFile(filter);
     if (fileIterator) {
      console.error("scanFile interface returns an undefined object");
      return;
    }
    while (!isDone) {
      let result = fileIterator.next();
      console.error("next result = " + JSON.stringify(result));
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
| Promise&lt;string&gt; | URI of the file created.|

**Example**

  ```js
  // The URI of a shared disk is used as an example.
  let sourceUri = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon";
  let displayName = "file1"
  let fileUri = null;
  try {
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
| Promise&lt;string&gt; | URI of the folder created.|

**Example**

  ```js
  // The URI of a shared disk is used as an example.
  let sourceUri = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon";
  let dirName = "dirTest"
  let dirUri = null;
  try {
    dirUri = await fileAccessHelper.mkDir(sourceUri, displayName)
    if (!dirUri) {
      console.error("mkDir return undefined object");
      return;
    }
    console.log("Folder created successfully. fileUri: " + JSON.stringify(fileUri));
  } catch (error) {
    console.error("mkDir failed, error " + error);
  };
  ```

## FileAccessHelper.openFile

openFile(uri: string, flags: [OPENFLAGS](#openflags)) : Promise&lt;number&gt;

Opens a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file to open.|
| flags | OPENFLAGS |  |File open mode.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;number&gt | Handle of the file opened.|

**Example**

  ```js
  // The URI of a shared disk is used as an example.
  let targetUri = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/file1";
  try {
    let fd = await fileAccessHelper.openFile(targetUri, OPENFLAGS.READ);
  } cache (error) {
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
  // The URI of a shared disk is used as an example.
  let targetUri = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/file1";
  try {
    let code = await fileAccessHelper.delete(targetUri);
    if (code != 0)
      console.error("delete failed, code " + code);
  } cache (error) {
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
| Promise&lt;string&gt; | URI of the file or folder in the destination directory.|

**Example**

  ```js
  // The URI of a shared disk is used as an example.
  let sourceFile = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/file1";
  let destFile = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/dirTest";
  try {
    let fileUri = await fileAccessHelper.move(sourceFile, destFile);
    console.log("Operation successful. fileUri: " + JSON.stringify(fileUri));
  } cache (error) {
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
| Promise&lt;string&gt; | URI of the renamed file or folder.|

**Example**

  ```js
  // The URI of a shared disk is used as an example.
  let sourceDir = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/dirTest";
  try {
    let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
    console.log("Operation successful. DestDir: " + JSON.stringify(DestDir));
  } cache (error) {
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
  // The URI of a shared disk is used as an example.
  let sourceDir = "datashare:///com.ohos.UserFile.ExternalFileManager/data/storage/el1/bundle/storage_daemon/dirTest";
  try {
    let existJudgment = await fileAccessHelper.access(sourceDir);
    if (existJudgment)
      console.log("sourceDir exists");
    else
      console.log("sourceDir does not exist");
  } cache (error) {
    console.error("rename failed, error " + error);
  };
  ```

## RootIterator.next

next( ) : { value: RootInfo, done: boolean }

Obtains the next-level device root directory. **RootIterator** is an iterator object of the device root directory.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

None

**Return value**

| Type| Description|
| --- | -- |
| {value: RootInfo, done: boolean} | Root directory information obtained. This API traverses the folder until **done** returns **true**. The **value** field contains the root directory information.|

## FileIterator.next

next( ) : { value: FileInfo, done: boolean }

Obtains the information about the next-level file or folder. **FileIterator** is an iterator object of a folder.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

None

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
| mimeType | string | Yes| No|  Media resource type of the file or folder.|

## OPENFLAGS

Enumerates the modes for opening a file.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Value| Description|
| ----- | ------ | ------ |
| READ | 0o0 | Read mode.|
| WRITE | 0o1 | Write mode.|
| WRITE_READ | 0o2 | Read/Write mode.|
