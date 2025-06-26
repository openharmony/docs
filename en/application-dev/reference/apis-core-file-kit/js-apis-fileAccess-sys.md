# @ohos.file.fileAccess (User File Access and Management) (System API)

The **fileAccess** module provides a framework for accessing and operating user files based on [extension](../../application-models/extensionability-overview.md). This module interacts with a variety of file management services, such as the storage management service, and provides a set of unified file access and management APIs for system applications. The storage management service manages both the directories of the built-in storage and resources on external devices, such as shared disks, USB flash drives, and SD cards.

>**NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.
> - Currently, the APIs of this module can be called only by **FilePicker** and **FileManager**.

## Modules to Import

```ts
import fileAccess from '@ohos.file.fileAccess';
```

## Constant

Represents a URI used for observing the device online/offline status.

**Model restriction**: This constant can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

| Name| Type                       | Read-Only| Optional| Description                                                     |
| ---- | --------------------------- | ---- | ---- | --------------------------------------------------------- |
| DEVICES_URI<sup>11+</sup>  | string | No  | No  | URI used for observing the device online/offline status.                   |

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo() : Promise&lt;Array&lt;Want&gt;&gt;

Obtains information about all Wants with **extension** set to **fileAccess** in the system. A Want contains information for starting an ability. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt;&gt; | Promise used to return the want information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  async function getFileAccessAbilityInfo() {
    let wantInfos: Array<Want> = [];
    try {
      wantInfos = await fileAccess.getFileAccessAbilityInfo();
      console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.getFileAccessAbilityInfo

getFileAccessAbilityInfo(callback: AsyncCallback&lt;Array&lt;Want&gt;&gt;): void

Obtains information about all Wants with **extension** set to **fileAccess** in the system. A Want contains information for starting an ability. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| callback | AsyncCallback&lt;Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt;&gt; | Yes| Callback invoked to return the want information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  async function getFileAccessAbilityInfo() {
    try {
      fileAccess.getFileAccessAbilityInfo((err: BusinessError, wantInfos: Array<Want>) => {
        if (err) {
          console.error("Failed to getFileAccessAbilityInfo in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileAccessAbilityInfo data " + JSON.stringify(wantInfos));
      });
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileAccessAbilityInfo failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context, wants: Array&lt;Want&gt;) : FileAccessHelper

Creates a **Helper** object to bind with the specified Wants. This API returns the result synchronously. The **Helper** object provides file access and management capabilities.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes| Context of the ability.|
| wants | Array&lt;[Want](../apis-ability-kit/js-apis-app-ability-want.md)&gt; | Yes| Wants to start the abilities.|

**Return value**

| Type| Description|
| --- | -- |
| [FileAccessHelper](#fileaccesshelper) | **Helper** object created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import Want from '@ohos.app.ability.Want';
  import common from '@ohos.app.ability.common';
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
  function createFileAccessHelper01(context: common.UIAbilityContext) {
    let fileAccessHelper: fileAccess.FileAccessHelper;
    // Obtain wantInfos by using getFileAccessAbilityInfo().
    let wantInfos: Array<Want> = [
      {
        bundleName: "com.ohos.UserFile.ExternalFileManager",
        abilityName: "FileExtensionAbility",
      },
    ]
    try {
      // context is passed by EntryAbility.
      fileAccessHelper = fileAccess.createFileAccessHelper(context, wantInfos);
      if (!fileAccessHelper) {
        console.error("createFileAccessHelper interface returns an undefined object");
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## fileAccess.createFileAccessHelper

createFileAccessHelper(context: Context) : FileAccessHelper

Creates a **Helper** object to bind with all file management services in the system. This API returns the result synchronously.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes| Context of the ability.|

**Return value**

| Type| Description|
| --- | -- |
| [FileAccessHelper](#fileaccesshelper) | **Helper** object created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import common from '@ohos.app.ability.common';
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
  function createFileAccessHelper02(context: common.UIAbilityContext) {
    let fileAccessHelperAllServer: fileAccess.FileAccessHelper;
    // Create a Helper object to interact with all file management services configured with fileAccess in the system.
    try {
      // context is passed by EntryAbility.
      fileAccessHelperAllServer = fileAccess.createFileAccessHelper(context);
      if (!fileAccessHelperAllServer) {
        console.error("createFileAccessHelper interface returns an undefined object");
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFileAccessHelper failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

## FileInfo

Provides APIs for managing file or directory attribute information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### Properties

| Name| Type  | Read-Only| Optional| Description    |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | No| No| URI of the file or directory.|
| relativePath<sup>10+</sup> | string | Yes| No| Relative path of the file or directory.|
| fileName | string | No| No| Name of the file or directory.|
| mode | number | No| No| Permissions on the file or directory.|
| size | number | No| No|  Size of the file or directory.|
| mtime | number | No| No|  Time when the file or directory was last modified.|
| mimeType | string | No| No|  Multipurpose Internet Mail Extensions (MIME) type of the file or directory.|

### listFile

listFile(filter?: Filter) : FileIterator

Obtains a **FileIterator** object that lists the next-level files or directories matching the specified conditions of this directory. This API returns the result synchronously. [FileInfo](#fileinfo) is returned by [next()](#next). Currently, only built-in storage devices support the file filter.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter10) | No| **Filter** object that specifies the conditions for listing files. |

**Return value**

| Type| Description|
| --- | -- |
| [FileIterator](#fileiterator) | **FileIterator** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // fileInfoDir indicates information about a directory.
  // let filter = { suffix : [".txt", ".jpg", ".xlsx"] };
  let fileInfoDir :Array<fileAccess.FileInfo> = [];
  let subfileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < fileInfoDir.length; ++i) {
      let fileIterator = fileInfoDir[i].listFile();
      // listFile() with the filter implementation.
      // let fileIterator = fileInfoDir.listFile(filter);
      if (!fileIterator) {
        console.error("listFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          subfileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### scanFile

scanFile(filter?: Filter) : FileIterator;

Obtains a **FileIterator** object that recursively retrieves the files matching the specified conditions of this directory. This API returns the result synchronously. [FileInfo](#fileinfo) is returned by [next()](#next). Currently, this API supports only built-in storage devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter10) | No| **Filter** object that specifies the conditions for listing files. |

**Return value**

| Type| Description|
| --- | -- |
| [FileIterator](#fileiterator) | **FileIterator** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // fileInfoDir indicates information about a directory.
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let fileInfoDir: Array<fileAccess.FileInfo> = [];
  let subfileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < fileInfoDir.length; ++i) {
      let fileIterator = fileInfoDir[i].scanFile();
      // scanFile() with the filter implementation.
      // let fileIterator = fileInfoDir.scanFile(filter);
      if (!fileIterator) {
        console.error("scanFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          subfileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## FileIterator

Provides the **FileIterator** object.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### next

next() : { value: FileInfo, done: boolean }

Obtains information about the next-level files or directories.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

| Type| Description|
| --- | -- |
| {value: [FileInfo](#fileinfo), done: boolean} | File or directory information obtained. This API traverses the directory until **true** is returned. The **value** field contains the file or directory information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

## RootInfo

Provides APIs for managing the device's root attribute information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### Properties

| Name| Type  | Read-Only| Optional| Description    |
| ------ | ------ | -------- | ------ | -------- |
| deviceType | number | No| No|Device type.|
| uri | string | No| No| Root directory URI of the device.|
| relativePath<sup>10+</sup> | string | No| No| Relative path of the root directory.|
| displayName | string | No| No| Device name.|
| deviceFlags | number | No| No| Capabilities supported by the device.|

### listFile

listFile(filter?: Filter) : FileIterator

Obtains a **FileIterator** object that lists the first-level files or directories matching the specified conditions from the device root directory. This API returns the result synchronously. [FileInfo](#fileinfo) is return by [next](#next). Currently, only built-in storage devices support the file filter.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter10) | No| **Filter** object that specifies the conditions for listing files. |

**Return value**

| Type| Description|
| --- | -- |
| [FileIterator](#fileiterator) | **FileIterator** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // rootInfo can be obtained by getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo: Array<fileAccess.FileInfo> = [];
  let fileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < rootInfo.length; ++i) {
      let fileIterator = rootInfo[i].listFile();
      // listFile() with the filter implementation.
      // let fileIterator = rootInfo.listFile(filter);
      if (!fileIterator) {
        console.error("listFile interface returns an undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          fileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("listFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### scanFile

scanFile(filter?: Filter) : FileIterator

Obtains a **FileIterator** object that recursively retrieves the files matching the specified conditions from the device root directory. This API returns the result synchronously. [FileInfo](#fileinfo) is returned by [next](#next). Currently, this API supports only built-in storage devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | -- | -- |
| filter | [Filter](js-apis-file-fs.md#filter10) | No| **Filter** object that specifies the conditions for listing files. |

**Return value**

| Type| Description|
| --- | -- |
| [FileIterator](#fileiterator) | **FileIterator** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // rootInfo can be obtained by getRoots().
  // let filter = {suffix : [".txt", ".jpg", ".xlsx"]};
  let rootInfo: Array<fileAccess.FileInfo> = [];
  let fileInfos: Array<fileAccess.FileInfo> = [];
  let isDone: boolean = false;
  try {
    for (let i = 0; i < rootInfo.length; ++i) {
      let fileIterator = rootInfo[i].scanFile();
      // scanFile() with the filter implementation.
      // let fileIterator = rootInfo.scanFile(filter);
      if (!fileIterator) {
        console.error("scanFile interface returns undefined object");
      }
      while (!isDone) {
        let result = fileIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          fileInfos.push(result.value);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("scanFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## RootIterator

Provides an iterator object of the device root directory.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### next

next() : { value: RootInfo, done: boolean }

Obtains the next-level root directory.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

| Type| Description|
| --- | -- |
| {value: [RootInfo](#rootinfo), done: boolean} | Root directory information obtained. This API traverses the directory until **true** is returned. The **value** field contains the root directory information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

## FileAccessHelper

Provides a **FileAccessHelper** object.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

### getRoots

getRoots() : Promise&lt;RootIterator&gt;

Obtains information about the device root nodes of the file management services associated with the **Helper** object. This API uses a promise to return
a **RootIterator** object. You can use [next](#next-1) to return [RootInfo](#rootinfo).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;[RootIterator](#rootiterator)&gt; | Promise used to return a **RootIterator** object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
async function getRoots() {
  let rootIterator: fileAccess.RootIterator;
  let rootinfos: Array<fileAccess.RootInfo> = [];
  let isDone: boolean = false;
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      rootIterator = await fileAccessHelper.getRoots();
      if (!rootIterator) {
        console.error("getRoots interface returns an undefined object");
      }
      while (!isDone) {
        let result = rootIterator.next();
        console.log("next result = " + JSON.stringify(result));
        isDone = result.done;
        if (!isDone) {
          rootinfos.push(result.value);
        }
      }     
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
  ```

### getRoots

getRoots(callback:AsyncCallback&lt;RootIterator&gt;) : void

Obtains information about the device root nodes of the file management services associated with the **Helper** object. This API uses an asynchronous callback to return
a **RootIterator** object. You can use [next](#next-1) to return [RootInfo](#rootinfo).

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| callback | AsyncCallback&lt;[RootIterator](#rootiterator)&gt; | Yes| Callback invoked to return a **RootIterator** object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function getRoots() {
    let rootinfos: Array<fileAccess.RootInfo> = [];
    let isDone: boolean = false;
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        fileAccessHelper.getRoots((err: BusinessError, rootIterator: fileAccess.RootIterator) => {
          if (err) {
            console.error("Failed to getRoots in async, errCode:" + err.code + ", errMessage:" + err.message);
          }
          while (!isDone) {
            let result = rootIterator.next();
            console.log("next result = " + JSON.stringify(result));
            isDone = result.done;
            if (!isDone) {
              rootinfos.push(result.value);
            }
          }
        });       
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getRoots failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### createFile

createFile(uri: string, displayName: string) : Promise&lt;string&gt;

Creates a file in a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the destination directory for the file to create.|
| displayName | string | Yes| Name of the file to create. By default, the name of a local file must contain the file suffix.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the file created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function createFile() {
    // A built-in storage directory is used as an example.
    // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    let displayName: string = "file1";
    let fileUri: string;
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
        if (fileAccessHelper != undefined) {
        fileUri = await fileAccessHelper.createFile(sourceUri, displayName);
        if (!fileUri) {
          console.error("createFile return undefined object");
          return;
        }
        console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));       
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### createFile

createFile(uri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

Creates a file in a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the destination directory for the file to create.|
| displayName | string | Yes| Name of the file to create. By default, the name of a local file must contain the file suffix.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the URI of the file created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  let displayName: string = "file1";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.createFile(sourceUri, displayName, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to createFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("createFile sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("createFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### mkDir

mkDir(parentUri: string, displayName: string) : Promise&lt;string&gt;

Creates a directory in a specified directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| parentUri | string | Yes| URI of the destination directory for the directory to create.|
| displayName | string | Yes| Name of the directory to create.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the directory created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  async function createDirectory() {
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    let dirName: string = "dirTest";
    let dirUri: string;
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        dirUri = await fileAccessHelper.mkDir(sourceUri, dirName);
        if (!dirUri) {
          console.error("mkDir return undefined object");
        } else {
          console.log("mkDir success, dirUri: " + JSON.stringify(dirUri));
        }
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### mkDir

mkDir(parentUri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

Creates a directory in a specified directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| parentUri | string | Yes| URI of the destination directory for the directory to create.|
| displayName | string | Yes| Name of the directory to create.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the URI of the directory created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  let dirName: string = "dirTest";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.mkDir(sourceUri, dirName, (err: BusinessError, dirUri: string) => {
        if (err) {
          console.error("Failed to mkDir in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("mkDir sucess, dirUri: " + JSON.stringify(dirUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("mkDir failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### openFile

openFile(uri: string, flags: OPENFLAGS) : Promise&lt;number&gt;

Opens a file. This API uses a promise to return the result.

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

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function openFile01() {
    // A built-in storage directory is used as an example.
    // In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fd = await fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### openFile

openFile(uri: string, flags: OPENFLAGS, callback: AsyncCallback&lt;number&gt;) : void

Opens a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file to open.|
| flags | [OPENFLAGS](#openflags) | Yes| File open mode.|
| callback | AsyncCallback&lt;number&gt; | Yes| File descriptor.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.openFile(targetUri, fileAccess.OPENFLAGS.READ, (err: BusinessError, fd: number) => {
        if (err) {
          console.error("Failed to openFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("openFile sucess, fd: " + fd);
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("openFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### delete

delete(uri: string) : Promise&lt;number&gt;

Deletes a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file or directory to delete.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function deleteFile01() {
    // A built-in storage directory is used as an example.
    // In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let code = await fileAccessHelper.delete(targetUri);
        if (code != 0)
          console.error("delete failed, code " + code);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### delete

delete(uri: string, callback: AsyncCallback&lt;number&gt;) : void

Deletes a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file or directory to delete.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, targetUri indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let targetUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.delete(targetUri, (err: BusinessError, code: number) => {
        if (err) {
          console.error("Failed to delete in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("delete sucess, code: " + code);
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("delete failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### move

move(sourceFile: string, destFile: string) : Promise&lt;string&gt;

Moves a file or directory. This API uses a promise to return the result. Currently, this API does not support move of files or directories across devices.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| sourceFile | string | Yes| URI of the source file or directory to move.|
| destFile | string | Yes| URI of the destination directory, to which the file or directory is moved.|

**Return value**

| Type| Description|
| ----- | ------ |
| Promise&lt;string&gt; | Promise used to return the URI of the file or directory in the destination directory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function moveFile01() {
    // A built-in storage directory is used as an example.
    // In the sample code, sourceFile and destFile indicate the files and directories in the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileUri = await fileAccessHelper.move(sourceFile, destFile);
        console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### move

move(sourceFile: string, destFile: string, callback: AsyncCallback&lt;string&gt;) : void

Moves a file or directory. This API uses an asynchronous callback to return the result. Currently, this API does not support move of files or directories across devices.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| sourceFile | string | Yes| URI of the source file or directory to move.|
| destFile | string | Yes| URI of the destination directory, to which the file or directory is moved.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the URI of the file or directory in the destination directory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceFile and destFile indicate the files and directories in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.move(sourceFile, destFile, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to move in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("move sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("move failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### rename

rename(uri: string, displayName: string) : Promise&lt;string&gt;

Renames a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the source file or directory to rename.|
| displayName | string | Yes| New name of the file or directory, which can contain the file suffix.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;string&gt; | Promise used to return the URI of the renamed file or directory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function renameFile01() {
    // A built-in storage directory is used as an example.
    // In the sample code, sourceDir indicates a file in the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let DestDir = await fileAccessHelper.rename(sourceDir, "testDir");
        console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### rename

rename(uri: string, displayName: string, callback: AsyncCallback&lt;string&gt;) : void

Renames a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the source file or directory to rename.|
| displayName | string | Yes| New name of the file or directory, which can contain the file suffix.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the URI of the renamed file or directory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceDir indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.rename(sourceDir, "testDir", (err: BusinessError, DestDir: string) => {
        if (err) {
          console.error("Failed to rename in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("rename sucess, DestDir: " + JSON.stringify(DestDir));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("rename failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### access

access(sourceFileUri: string) : Promise&lt;boolean&gt;

Checks whether a file or directory exists. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| sourceFileUri | string | Yes| URI of the file or directory to check.|

**Return value**

| Type| Description|
| --- | -- |
| Promise&lt;boolean&gt; | Callback invoked to return the result. The value **true** means the file or directory exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceDir indicates a file in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  async function accessFunc() {
    let sourceDir: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let existJudgment = await fileAccessHelper.access(sourceDir);
        if (existJudgment) {
          console.log("sourceDir exists");
        } else {
          console.log("sourceDir does not exist");
        }
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### access

access(sourceFileUri: string, callback: AsyncCallback&lt;boolean&gt;) : void

Checks whether a file or directory exists. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| sourceFileUri | string | Yes| URI of the file or directory to check.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the result. The value **true** means the file or directory exists; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceDir indicates a directory in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceDir: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.access(sourceDir, (err: BusinessError, existJudgment: boolean) => {
        if (err) {
          console.error("Failed to access in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        if (existJudgment)
          console.log("sourceDir exists");
        else
          console.log("sourceDir does not exist");
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("access failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### getFileInfoFromUri<sup>10+</sup>

getFileInfoFromUri(uri: string) : Promise\<FileInfo>

Obtains a **FileInfo** object based on a URI. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file or directory.|

**Return value**

| Type| Description|
| --- | -- |
| Promise\<[FileInfo](#fileinfo)> | Promise used to return the **FileInfo** object obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  async function getUri() {
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileInfo = await fileAccessHelper.getFileInfoFromUri(sourceUri);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### getFileInfoFromUri<sup>10+</sup>

getFileInfoFromUri(uri: string, callback: AsyncCallback\<FileInfo>) : void

Obtains a **FileInfo** object based on a URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| uri | string | Yes| URI of the file or directory.|
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)&gt; | Yes| Callback invoked to return the **FileInfo** object obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri indicates the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.getFileInfoFromUri(sourceUri, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {
        if (err) {
          console.error("Failed to getFileInfoFromUri in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileInfoFromUri success, fileInfo: " + JSON.stringify(fileInfo));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getFileInfoFromUri failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```


### getFileInfoFromRelativePath<sup>10+</sup>

getFileInfoFromRelativePath(relativePath: string) : Promise\<FileInfo>

Obtains a **FileInfo** object based on a relative path. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| relativePath | string | Yes| Relative path of the file or directory.|

**Return value**

| Type| Description|
| --- | -- |
| Promise\<[FileInfo](#fileinfo)> | Promise used to return the **FileInfo** object obtained.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // In the sample code, relativePath indicates the Download directory, which is the relativePath in fileInfo.
  // You can use the relativePath obtained.
  async function getRelativePath() {
    let relativePath: string = "Download/";
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
      if (fileAccessHelper != undefined) {
        let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(relativePath);
      }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### getFileInfoFromRelativePath<sup>10+</sup>

getFileInfoFromRelativePath(relativePath: string, callback: AsyncCallback\<FileInfo>) : void

Obtains a **FileInfo** object based on a relative path. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | -- |
| relativePath | string | Yes| Relative path of the file or directory.|
| callback | AsyncCallback&lt;[FileInfo](#fileinfo)&gt; | Yes| Callback invoked to return the **FileInfo** object based on a relative path.|

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // In the sample code, relativePath indicates the Download directory, which is the relativePath in fileInfo.
  // You can use the relativePath obtained.
  let relativePath: string = "Download/";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.getFileInfoFromRelativePath(relativePath, (err: BusinessError, fileInfo: fileAccess.FileInfo) => {
        if (err) {
          console.error("Failed to getFileInfoFromRelativePath in async, errCode:" + err.code + ", errMessage:" + err.message);
          return;
        }
        console.log("getFileInfoFromRelativePath success, fileInfo: " + JSON.stringify(fileInfo));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getFileInfoFromRelativePath failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

### query<sup>10+</sup>

query(uri:string, metaJson: string) : Promise&lt;string&gt;

Queries the attribute information about a file or directory based on a URI. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name  | Type  | Mandatory| Description                                                |
| -------- | ------ | ---- | ---------------------------------------------------- |
| uri      | string | Yes  | File or directory URI obtained from [FileInfo](#fileinfo).|
| metaJson | string | Yes  | Attribute [FILEKEY](#filekey10) to query.      |

**Return value**

| Type                 | Description                            |
| :-------------------- | :------------------------------- |
| Promise&lt;string&gt; | Promise used to return a JSON string that contains the file attribute and the value obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function getQuery01() {
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
      let queryResult = await fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath);
      console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
  }
}
```

### query<sup>10+</sup>

query(uri:string, metaJson: string, callback: AsyncCallback&lt;string&gt;) : void

Queries the attribute information about a file or directory based on a URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name  | Type                       | Mandatory| Description                                                |
| -------- | --------------------------- | ---- | ---------------------------------------------------- |
| uri      | string | Yes  | File or directory URI obtained from [FileInfo](#fileinfo).|
| metaJson | string | Yes  | Attribute [FILEKEY](#filekey10) to query.       |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return a JSON string that contains the file attribute and the value obtained.                    |

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function getQuery02() {
  let imageFileRelativePath: string = "/storage/Users/currentUser/Download/queryTest/image/01.jpg";
  let jsonStrSingleRelativepath: string = JSON.stringify({ [fileAccess.FileKey.RELATIVE_PATH]: "" });
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let fileInfo = await fileAccessHelper.getFileInfoFromRelativePath(imageFileRelativePath);
      fileAccessHelper.query(fileInfo.uri, jsonStrSingleRelativepath, (err: BusinessError, queryResult: string) => {
        if (err) {
          console.error(`query_file_single faf query Failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.log("query_file_single faf query, queryResult.relative_path: " + JSON.parse(queryResult).relative_path);
      })
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("query_file_single faf query failed, error.code :" + error.code + ", errorMessage :" + error.message);
  }
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, force?: boolean) : Promise&lt;Array&lt;CopyResult&gt;&gt;

Copies a file or directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type   | Mandatory| Description                                                        |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | Yes  | URI of the source file or directory to copy. For example, **file://docs/storage/Users/currentUser/Download/1.txt**. |
| destUri   | string  | Yes  | URI of the destination directory, to which the file or directory is moved. For example, **file://docs/storage/Users/currentUser/Download/test**.       |
| force     | boolean | No  | Whether to forcibly overwrite the file with the same name. If **force** is **true**, the file with the same name will be overwritten. If **force** is **false** or not specified, the file with the same name will not be overwritten. The default value is **false**.|

**Return value**

| Type                                                   | Description                                                        |
| :------------------------------------------------------ | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | Promise used to return the result. If the file or directory is copied successfully, no information is returned. If the file copy fails, a **copyResult** array is returned.|

Example 1: Copy a file with **force** unspecified.

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
async function copyFunc01() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copy(sourceFile, destFile);
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 2: Copy a file or directory with **force** set to **true**.

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
async function copyFunc02() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copy(sourceFile, destFile, true);
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, callback: AsyncCallback&lt;Array&lt;CopyResult&gt;&gt;) : void

Copies a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | Yes  | URI of the source file or directory to copy. For example, **file://docs/storage/Users/currentUser/Download/1.txt**. |
| destUri   | string                                           | Yes  | URI of the destination directory, to which the file or directory is moved. For example, **file://docs/storage/Users/currentUser/Download/test**.        |
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | Yes  | Callback invoked to return the result. If the file or directory is copied successfully, no information is returned. If the copy fails, a **copyResult** array is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
// Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copy(sourceFile, destFile, async (err: BusinessError, copyResult: Array<fileAccess.CopyResult>) => {
      if (err) {
        console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### copy<sup>10+</sup>

copy(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback&lt;Array&lt;CopyResult&gt;&gt;) : void

Copies a file or directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | Yes  | URI of the source file or directory to copy. For example, **file://docs/storage/Users/currentUser/Download/1.txt**. |
| destUri   | string                                           | Yes  | URI of the destination directory, to which the file or directory is moved. For example, **file://docs/storage/Users/currentUser/Download/test**.        |
| force     | boolean                                          | Yes  | Whether to forcibly overwrite the file with the same name. If **force** is **true**, the file with the same name will be overwritten. If **force** is **false** or not specified, the file with the same name will not be overwritten.|
| callback  | AsyncCallback&lt;Array&lt;[CopyResult](#copyresult10)&gt;&gt; | Yes  | Callback invoked to return the result. If the file or directory is copied successfully, no information is returned. If the copy fails, a **copyResult** array is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
// Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copy(sourceFile, destFile, true, async (err: BusinessError, copyResult: Array<fileAccess.CopyResult>) => {
      if (err) {
        console.error("copy failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (copyResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < copyResult.length; i++) {
          console.error("errCode" + copyResult[i].errCode);
          console.error("errMsg" + copyResult[i].errMsg);
          console.error("sourceUri" + copyResult[i].sourceUri);
          console.error("destUri" + copyResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### copyFile<sup>11+</sup>

copyFile(sourceUri: string, destUri: string, fileName: string): Promise&lt;string&gt;

Copies a file with an alternative file name. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type   | Mandatory| Description                                                        |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | Yes  | URI of the source file or directory to copy. For example, **file://docs/storage/Users/currentUser/Download/1.txt**. |
| destUri   | string  | Yes  | URI of the destination directory, to which the file or directory is moved. For example, **file://docs/storage/Users/currentUser/Download/test**.       |
| fileName  | string  | Yes  | File name to use if there is a file with the same name as the source file in the destination directory.|

**Return value**

| Type                                                   | Description                                                        |
| :------------------------------------------------------ | :----------------------------------------------------------- |
| Promise&lt;string&gt; | URI of the file generated.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
async function copyFunc01() {
  let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
  let fileName: string = "2.txt";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let copyResult = await fileAccessHelper.copyFile(sourceFile, destFile, fileName);
      console.log("copyResult uri: " + copyResult);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### copyFile<sup>11+</sup>

copyFile(sourceUri: string, destUri: string, fileName: string, callback: AsyncCallback&lt;string&gt;) : void

Copies a file with an alternative file name. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type                                            | Mandatory| Description                                                        |
| --------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                           | Yes  | URI of the source file or directory to copy. For example, **file://docs/storage/Users/currentUser/Download/1.txt**. |
| destUri   | string                                           | Yes  | URI of the destination directory, to which the file or directory is moved. For example, **file://docs/storage/Users/currentUser/Download/test**.        |
| fileName  | string                                           | Yes  | File name to use if there is a file with the same name as the source file in the destination directory.|
| callback  | AsyncCallback&lt;string&gt; | Yes  | URI of the file generated.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
let sourceFile: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destFile: string = "file://docs/storage/Users/currentUser/Download/test";
let fileName: string = "2.txt";
// Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.copyFile(sourceFile, destFile, fileName, async (copyResult: string) => {
          console.log("copyResult uri: " + copyResult);
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("copy failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### registerObserver<sup>10+</sup>

registerObserver(uri: string, notifyForDescendants: boolean, callback: Callback&lt;NotifyMessage&gt;): void

Registers a callback to listen for a URI. URIs and callbacks can be in many-to-many relationships. You are advised to use one callback to listen for one URI.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name              | Type                                             | Mandatory| Description                          |
| -------------------- | ------------------------------------------------- | ---- | ------------------------------ |
| uri                  | string                                            | Yes  | URI of the file or directory.               |
| notifyForDescendants | boolean                                           | Yes  | Whether to observe changes of the files in the directory. The value **true** means to observe changes of the files in the directory; the value **false** means the opposite.|
| callback             | Callback&lt;[NotifyMessage](#notifymessage10)&gt; | Yes  | Callback invoked to return the notification.                  |

Example 1: Register a callback to listen for a URI.

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver01() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri1 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR1');
      let dirUri2 = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR2');
      // Two notifications are expected to receive because notifyForDescendants is set to true during registration.
      // The URI is 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE', and the event type is NOTIFY_MOVED_FROM.
      // The URI is 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE', and the event type is NOTIFY_MOVE_SELF.
      const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // The notification expected to receive is about the NOTIFY_MOVED_TO event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR2/SUB_FILE'.
      const callbackDir2 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // The notification expected to receive is about the NOTIFY_MOVE_SELF event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'.
      // The notification expected to receive is about the NOTIFY_MOVED_FROM event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR1/SUB_FILE'.
      const callbackFile = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      let fileUri = await fileAccessHelper.createFile(dirUri1, 'SUB_FILE');
      fileAccessHelper.registerObserver(dirUri1, true, callbackDir1);
      fileAccessHelper.registerObserver(dirUri2, true, callbackDir2);
      // If the moved file itself is not listened for, the NOTIFY_MOVE_SELF event will not be triggered.
      fileAccessHelper.registerObserver(fileUri, true, callbackFile);
      let moveFileUri = await fileAccessHelper.move(fileUri, dirUri2);
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri1, callbackDir1);
      fileAccessHelper.unregisterObserver(dirUri2, callbackDir2);
      fileAccessHelper.unregisterObserver(fileUri, callbackFile);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 2: Use the same **uri**, **notifyForDescendants**, and **callback** to register repeatedly.

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver02() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // The notification expected to receive is about the NOTIFY_ADD event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_DIR'.
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      // A message is returned indicating that the registration is successful. Repeated registration is reported only in the log.
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      let subDirUri = await fileAccessHelper.mkDir(dirUri, 'SUB_DIR');
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 3: Use the same **uri** and **callback** but different **notifyForDescendants** for registration. In this case, **notifyForDescendants** will be reset.

```ts
import { BusinessError } from '@ohos.base';
async function registerObserver03() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // The first notification expected to receive is about the NOTIFY_ADD event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_FILE_1'.
      // No second return is expected.
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      let subFile1 = await fileAccessHelper.createFile(dirUri, 'SUB_FILE_1');
      // After the registration is successful, change notifyForDescendants to false.
      fileAccessHelper.registerObserver(dirUri, false, callbackDir);
      let subFile2 = await fileAccessHelper.createFile(dirUri, 'SUB_FILE_2');
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("registerObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 4: Observe the device online/offline status.

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
      if (NotifyMessageDir != undefined) {
        console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
      } else {
        console.error("NotifyMessageDir is undefined");
      }
    }
    if (fileAccessHelper != undefined) {
      // Subscribe to the device online/offline status.
      fileAccessHelper.registerObserver(fileAccess.DEVICES_URI, true, callbackDir1);
      // Unsubscribe from the device online/offline status.
      fileAccessHelper.unregisterObserver(fileAccess.DEVICES_URI);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### unregisterObserver<sup>10+</sup>

 unregisterObserver(uri: string, callback?: Callback&lt;NotifyMessage&gt;): void

Unregisters a callback that is used to listen for the specified URI.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name  | Type                                             | Mandatory| Description                     |
| -------- | ------------------------------------------------- | ---- | ------------------------- |
| uri      | string                                            | Yes  | URI of the file or directory.          |
| callback | Callback&lt;[NotifyMessage](#notifymessage10)&gt; | No  | Callback to unregister. If this parameter is not specified, all callbacks of the specified URI will be unregistered.|

Example 1: Unregister a callback of the specified URI.

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver01() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // The notification expected to receive is about the NOTIFY_DELETE event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR'.
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      await fileAccessHelper.delete(dirUri);
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 2: Repeatedly unregister a callback of the specified URI.

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver02() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
      if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // The notification expected to receive is about the NOTIFY_DELETE event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR'.
      const callbackDir = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      fileAccessHelper.registerObserver(dirUri, true, callbackDir);
      await fileAccessHelper.delete(dirUri);
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
      // If the unregistration fails, throw the error code E_CAN_NOT_FIND_URI.
      fileAccessHelper.unregisterObserver(dirUri, callbackDir);
      }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 3: Unregister all callbacks of the specified URI.

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  let DirUri: string = 'file://docs/storage/Users/currentUser/Documents';
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let dirUri = await fileAccessHelper.mkDir(DirUri, 'NOTIFY_DIR');
      // The notification expected to receive is about the NOTIFY_MOVED_FROM event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/SUB_FILE'.
      // The notification expected to receive is about the NOTIFY_MOVED_TO event of the URI 'file://docs/storage/Users/currentUser/Documents/NOTIFY_DIR/RENAME_FILE'.
      const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      // No notification is expected to receive.
      const callbackDir2 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
        if (NotifyMessageDir != undefined) {
          console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
        } else {
          console.error("NotifyMessageDir is undefined");
        }
      }
      let fileUri = await fileAccessHelper.createFile(dirUri, 'SUB_FILE');
      fileAccessHelper.registerObserver(dirUri, true, callbackDir1);
      // The registration does not include the events about the next-level directory.
      fileAccessHelper.registerObserver(dirUri, false, callbackDir2);
      let renameUri = await fileAccessHelper.rename(fileUri, 'RENAME_FILE');
      // Unregister all callbacks (callbackDir1 and callbackDir2) of dirUri.
      // Do not unregister the callback immediately after the registration is complete, because the unregistration result may be returned before the notification is returned. If this occurs, the notification will not be received.
      fileAccessHelper.unregisterObserver(dirUri);
      await fileAccessHelper.delete(dirUri);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 4: Unregistger the device online/offline status.

```ts
import { BusinessError } from '@ohos.base';
async function UnregisterObserver03() {
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    const callbackDir1 = (NotifyMessageDir: fileAccess.NotifyMessage) => {
      if (NotifyMessageDir != undefined) {
        console.log('NotifyType: ' + NotifyMessageDir.type + 'NotifyUri:' + NotifyMessageDir.uris[0]);
      } else {
        console.error("NotifyMessageDir is undefined");
      }
    }
    if (fileAccessHelper != undefined) {
      // Subscribe to the device online/offline status.
      fileAccessHelper.registerObserver(fileAccess.DEVICES_URI, true, callbackDir1);
      // Unsubscribe from the device online/offline status.
      fileAccessHelper.unregisterObserver(fileAccess.DEVICES_URI);
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("unregisterObserver failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, force?: boolean) : Promise&lt;Array&lt;MoveResult&gt;&gt;

Moves a file or directory. This API uses a promise to return the result.

You can forcibly overwrite the file with the same name in the destination directory.

Currently, this API does not support move of files or directories across devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type   | Mandatory| Description                                                        |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| sourceUri | string  | Yes  | URI of the source file or directory to move.                                   |
| destUri   | string  | Yes  | URI of the destination directory, to which the file or directory is moved.                                           |
| force     | boolean | No  | Whether to forcibly overwrite the file with the same name. The value **true** means to overwrite the file forcibly; the value **false** means the opposite. The default value is **false**.|

**Return value**

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | Promise used to return the result. If the operation is successful, no information is returned. If the operation fails, a **MoveResult** array is returned.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

Example 1: Copy a file with **force** unspecified.

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
async function moveItemFunc01() {
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let moveResult = await fileAccessHelper.moveItem(sourceUri, destUri);
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

Example 2: Move a file or directory with **force** set to **true**.

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
async function moveItemFunc02() {
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      let moveResult = await fileAccessHelper.moveItem(sourceUri, destUri, true);
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, callback: AsyncCallback&lt;Array&lt;MoveResult&gt;&gt;) : void

Moves a file or directory. This API uses an asynchronous callback to return the result.

Currently, this API does not support move of files or directories across devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                                       | Yes  | URI of the source file or directory to move.                                   |
| destUri   | string                                                       | Yes  | URI of the destination directory, to which the file or directory is moved.                                           |
| callback  | AsyncCallback&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, no information is returned. If the operation fails, a **MoveResult** array is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
// Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.moveItem(sourceUri, destUri, async (err: BusinessError, copyResult: Array<fileAccess.MoveResult>) => {
      if (err) {
        console.error("moveItem failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (moveResult.length === 0) {
        console.log("moveItem success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### moveItem<sup>11+</sup>

moveItem(sourceUri: string, destUri: string, force: boolean, callback: AsyncCallback&lt;Array&lt;MoveResult&gt;&gt;) : void

Moves a file or directory. This API uses an asynchronous callback to return the result.

You can forcibly overwrite the file with the same name in the destination directory.

Currently, this API does not support move of files or directories across devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sourceUri | string                                                       | Yes  | URI of the source file or directory to move.                                   |
| destUri   | string                                                       | Yes  | URI of the destination directory, to which the file or directory is moved.                                           |
| force     | boolean                                                      | Yes  | Whether to forcibly overwrite the file with the same name. The value **true** means to overwrite the file forcibly; the value **false** means the opposite. The default value is **false**.|
| callback  | AsyncCallback&lt;Array&lt;[MoveResult](#moveresult11)&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, no information is returned. If the operation fails, a **MoveResult** array is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// A built-in storage directory is used as an example.
// In the sample code, sourceFile indicates the file (directory) in the Download directory to copy, destFile indicates the destination directory in the Download directory, and URI is the URI in fileInfo.
// You can use the URI obtained.
let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
// Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
try {
  if (fileAccessHelper != undefined) {
    fileAccessHelper.moveItem(sourceUri, destUri, true, async (err: BusinessError, moveResult: Array<fileAccess.MoveResult>) => {
      if (err) {
        console.error("moveItem failed, errCode:" + err.code + ", errMessage:" + err.message);
      }
      if (moveResult.length === 0) {
        console.log("copy success");
      } else {
        for (let i = 0; i < moveResult.length; i++) {
          console.error("errCode" + moveResult[i].errCode);
          console.error("errMsg" + moveResult[i].errMsg);
          console.error("sourceUri" + moveResult[i].sourceUri);
          console.error("destUri" + moveResult[i].destUri);
        }
      }
    });
  }
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("moveItem failed, errCode:" + error.code + ", errMessage:" + error.message);
}
```

### moveFile<sup>11+</sup>

moveFile(sourceUri: string, destUri: string, fileName: string) : Promise&lt;string&gt;

Moves a file, and renames it if a file with the same name already exists in the destination directory. This API uses a promise to return the result.

If a file with the same name exists (that is, a file moving conflict occurs), you can rename the file to be moved and save it to the destination directory.

Currently, this API does not support move of files across devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ---------- | ------ | ---- | ------------------- |
| sourceFile | string | Yes  | URI of the source file to move.|
| destFile   | string | Yes  | URI of the destination directory, to which the file is moved.  |
| fileName   | string | Yes  | New name of the file. |

**Return value**

| Type                 | Description               |
| --------------------- | ------------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the file in the destination directory.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  async function moveFile01() {
    // A built-in storage directory is used as an example.
    // In the sample code, sourceUri and destUri indicate the files or directories in the Download directory. The URI is the URI in fileInfo.
    // You can use the URI obtained.
    let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
    let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
    let fileName: string;
    // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
    let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
    try {
    if (fileAccessHelper != undefined) {
        let fileUri = await fileAccessHelper.moveFile(sourceUri, destUri, fileName);
        console.log("moveFile sucess, fileUri: " + JSON.stringify(fileUri));
    }
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error("moveFile failed, errCode:" + error.code + ", errMessage:" + error.message);
    }
  }
  ```

### moveFile<sup>11+</sup>

moveFile(sourceUri: string, destUri: string,  fileName: string, callback: AsyncCallback&lt;string&gt;) : void

Moves a file, and renames it if a file with the same name already exists in the destination directory. This API uses an asynchronous callback to return the result.

If a file with the same name exists (that is, a file moving conflict occurs), you can rename the file to be moved and save it to the destination directory.

Currently, this API does not support move of files across devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

**Parameters**

| Name    | Type                       | Mandatory| Description                 |
| ---------- | --------------------------- | ---- | --------------------- |
| sourceFile | string                      | Yes  | URI of the source file to move.|
| destFile   | string                      | Yes  | URI of the destination directory, to which the file is moved.    |
| fileName   | string                      | Yes  | New name of the file.   |
| callback   | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the URI of the file in the destination directory.  |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  // A built-in storage directory is used as an example.
  // In the sample code, sourceUri and destUri indicate the files or directories in the Download directory. The URI is the URI in fileInfo.
  // You can use the URI obtained.
  let sourceUri: string = "file://docs/storage/Users/currentUser/Download/1.txt";
  let destUri: string = "file://docs/storage/Users/currentUser/Download/test";
  let fileName: string;
  // Obtain fileAccessHelper by referring to the sample code of fileAccess.createFileAccessHelper.
  let fileAccessHelper : fileAccess.FileAccessHelper|undefined;
  try {
    if (fileAccessHelper != undefined) {
      fileAccessHelper.moveFile(sourceUri, destUri, fileName, (err: BusinessError, fileUri: string) => {
        if (err) {
          console.error("Failed to moveFile in async, errCode:" + err.code + ", errMessage:" + err.message);
        }
        console.log("moveFile sucess, fileUri: " + JSON.stringify(fileUri));
      });
    }
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("moveFile failed, errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## CopyResult<sup>10+</sup>

Defines the information returned when the file copy operation fails. If the copy operation is successful, no information is returned.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

| Name     | Type  | Read-Only| Optional| Description               |
| --------- | ------ | ---- | ---- | ----------------- |
| sourceUri | string | No  | No  | URI of the source file or directory.                                        |
| destUri   | string | No  | No  | URI of the conflicting file. If the error is not caused by a file conflict, **destUri** is empty.|
| errCode   | number | No  | No  | Error code.                                                |
| errMsg    | string | No  | No  | Error message.                                              |

## OPENFLAGS

Enumerates the file open modes.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name| Value| Description|
| ----- | ------ | ------ |
| READ | 0o0 | Read mode.|
| WRITE | 0o1 | Write mode.|
| WRITE_READ | 0o2 | Read/Write mode.|

## FILEKEY<sup>10+</sup>

Enumerates the keys of the file attributes to query.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name         | Value           | Description                               |
| ------------- | ------------- | ----------------------------------- |
| DISPLAY_NAME  | 'display_name'  | File name.                             |
| DATE_ADDED    | 'date_added'   | Date when the file was created. For example, **1501925454**.     |
| DATE_MODIFIED | 'date_modified' | Date when the file was modified. For example, **1665310670**.     |
| RELATIVE_PATH | 'relative_path' | Relative path. For example, **Pictures/Screenshots/**.|
| FILE_SIZE     | 'size'          | Size of the file or directory, in bytes.       |

## NotifyType<sup>10+</sup>

Enumerates the notification types.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name             | Value  | Description                                                        |
| ----------------- | ---- | ------------------------------------------------------------ |
| NOTIFY_ADD        | 0    | File added.<br>See examples 2 and 3 of **registerObserver**.                                                |
| NOTIFY_DELETE     | 1    | File deleted.<br>See examples 1 and 2 of **unregisterObserver(uri: string, callback: Callback&lt;NotifyMessage&gt;)**.                                              |
| NOTIFY_MOVED_TO   | 2    | File or directory moved in (for example, **rename()** is performed on a file or directory in this directory or a file or directory is moved to this directory). <br>See example 1 of **registerObserver** and example 1 of **unregisterObserver(uri: string)**.|
| NOTIFY_MOVED_FROM | 3    | File or directory moved out (for example, **rename()** is performed on a file or directory in this directory or a file or directory is moved out from this directory). <br>See example 1 of **registerObserver** and example 1 of **unregisterObserver(uri: string)**.|
| NOTIFY_MOVE_SELF  | 4    | File moved (for example, the target file or directory is renamed or moved).<br>See example 1 of **registerObserver**.    |
| NOTIFY_DEVICE_ONLINE<sup>11+</sup>   | 5    | Device goes online.    |
| NOTIFY_DEVICE_OFFLINE<sup>11+</sup>   | 6    | Device goes offline.    |

## NotifyMessage<sup>10+</sup>

Represents the notification message.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

| Name| Type                       | Read-Only| Optional| Description                                                     |
| ---- | --------------------------- | ---- | ---- | --------------------------------------------------------- |
| type | [NotifyType](#notifytype10) | No  | No  | Notification type.                                           |
| uris | Array&lt;string&gt;         | No  | No  | URIs of the changed files. Currently, only one notification is supported. A collection of multiple notifications will be supported in later versions.|

## MoveResult<sup>11+</sup>

Represents the information returned when the move operation fails. If the operation is successful, no information is returned.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileService

**Required permissions**: ohos.permission.FILE_ACCESS_MANAGER

| Name     | Type  | Read-Only| Optional| Description                                                        |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| sourceUri | string | No  | No  | URI of the source file or directory.                                              |
| destUri   | string | No  | No  | URI of the conflicting file. If the error is not caused by a file conflict, **destUri** is empty.    |
| errCode   | number | No  | No  | Error code. For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).|
| errMsg    | string | No  | No  | Error message.                                                  |
