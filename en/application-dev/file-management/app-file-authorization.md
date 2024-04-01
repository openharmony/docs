# Authorizing Access to Application Files

The system prevents unauthorized access to application files. An application can access a file or folder after obtaining the path to the file or folder. You can implement authorized access to application files in the following scenarios:

- Obtain the access to a user directory by declaring the permission.
- Obtain a temporary permission on a file or folder using FilePicker and persist the temporary permission.
- Obtain the URI of a file or folder using APIs.
- Obtain user directories and the directory of a built-in or external card using APIs.

Only certain devices support the access authorization operations.

The following walks you through common file operations.

## Declaring the Permission on the Download Directory

1. Set the permission on the **Download** directory.

    ```json
   "requestPermissions" : [
        "name": "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY"
    ]
   ```

2. Use the [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) API to obtain the path to **Download**. After obtaining the directory path, the application can access the directory and perform operations.
  ```ts
  import { BusinessError } from '@ohos.base';
  import environment from '@ohos.file.environment';
  import fs from '@ohos.file.fs';
  
  async function getUserDownloadDirExample() {
    try {
      let path = environment.getUserDownloadDir();
      console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
      await fs.mkdir(path + "/brower");
      let fd = await fs.open(path + "/brower/1.txt", fs.OpenMode.CREATE);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`failed to getUserDownloadDir because: ${JSON.stringify(err)}`);
    }
  }
  ```

## Persisting a Temporary Permission Obtained by FilePicker

Use FilePicker to select a file or folder, and set permanent authorization for your application on the file or folder. When the application restarts, the permission needs to be activated. You can use [ohos.fileshare](../reference/apis-core-file-kit/js-apis-fileShare.md) to implement file authorization.

1. Use the **select()** API of FilePicker to select and save an URI. After the file or folder corresponding to the URI is selected and saved by the user, the application obtains a temporary permission to access the file or folder. 

   The following sample code demonstrates how to obtain the URI of a folder.

  ```ts
  import { BusinessError } from '@ohos.base';
  import picker from '@ohos.file.picker';
  
  async function selectExample() {
    try {
      let DocumentSelectOptions = new picker.DocumentSelectOptions();
      DocumentSelectOptions.selectMode = picker.DocumentSelectMode.FOLDER;
      let documentPicker = new picker.DocumentViewPicker();
      let uris = await documentPicker.select(DocumentSelectOptions);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('select failed with err: ' + JSON.stringify(err));
    }
  }
  ```

2. Persist the permission on the path as required. The parameter **uri** is the path obtained by FilePicker in step 1. 

   The following sample code demonstrates how to persist a permission on a URI.
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function persistPermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/1.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.persistPermission(policies).then(() => {
        console.info("persistPermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001) {
          console.log("error data : " + JSON.stringify(err.data));
        }
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('persistPermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

3. Revoke the persistent permission on the path as required. The parameter **uri** is the path obtained by FilePicker in step 1. 

   The following sample code demonstrates how to revoke a persistent permission from a URI.
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function revokePermissionExample() {
    try {
      let uri = "file://docs/storage/Users/username/1.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.revokePermission(policies).then(() => {
        console.info("revokePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
        if (err.code == 13900001) {
          console.log("error data : " + JSON.stringify(err.data));
        }
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('revokePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

4. Activate the persistent permission on the URI when the application restarts. The **activatePermission** method must be used with **persistPermission()** together.

   The following sample code demonstrates how to activate the persistent permission on a URI when the application restarts. The parameter **uri** specifies a recently accessed file to be read after the application is restarted.

  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function activatePermissionExample01() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.activatePermission(policies).then(() => {
        console.info("activatePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("activatePermission failed with error message: " + err.message + ", error code: " + err.code);
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('activatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

5. Deactivate a persistent permission as required. The parameter **uri** specifies a recently accessed file read after the application is restarted. 

   The following sample code demonstrates how to deactivate a persistent permission.
  ```ts
  import { BusinessError } from '@ohos.base';
  import fileshare from '@ohos.fileshare';
  import fs from '@ohos.file.fs';
  
  async function deactivatePermissionExample01() {
    try {
      let uri = "file://docs/storage/Users/username/tmp.txt";
      let policyInfo: fileshare.PolicyInfo = {
        uri: uri,
        operationMode: fileshare.OperationMode.READ_MODE,
      };
      let policies: Array<fileshare.PolicyInfo> = [policyInfo];
      fileshare.deactivatePermission(policies).then(() => {
        console.info("deactivatePermission successfully");
      }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
        console.info("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
      });
      let fd = await fs.open(uri);
      await fs.close(fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('deactivatePermission failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## Obtaining the URI of a File or Folder

Use the [ohos.file.fileuri](../reference/apis/js-apis-file-fileuri.md) API to obtain the URI of a file or folder. If **FileUri** points to a file, the URI of the directory where the file is located is returned. If **FileUri** points to a folder, the URI of the current directory is returned.

The following sample code demonstrates how to obtain the parent directory of a file.

  ```ts
  import { BusinessError } from '@ohos.base';
  import fileUri from '@ohos.file.fileuri';
  
  function getFullDirectoryUriExample01() {
    try {
      let uri = "file://docs/storage/Users/100/tmp/1.txt";
      let fileObject = new fileUri.FileUri(uri);
      let directoryUri = fileObject.getFullDirectoryUri();
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getFullDirectoryUri failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## Obtaining a User Directory or Directory of a Built-in or External Card

A common application can obtain the following user directories: **Download**, **Desktop**, and **Document**. Only the **Files** application can obtain the root directory of an external card and the built-in card directory in the sandbox directory of the current user using the [ohos.file.environment](../reference/apis/js-apis-file-environment.md) APIs.

The following sample code demonstrates how to obtain these directories.

  ```ts
  import { BusinessError } from '@ohos.base';
  import environment from '@ohos.file.environment';
  
  function getDirectoryExample01() {
    try {
      // Obtain the Download directory.
      let downloadPath = environment.getUserDownloadDir();
      // Obtain the Desktop directory.
      let desktopPath = environment.getUserDesktopDir();
      // Obtain the Document directory.
      let documentPath = environment.getUserDocumentDir();
      // Obtain the root directory of an external card.
      let externalStoragePath = environment.getExternalStorageDir();
      // Obtain the built-in card directory in the application sandbox directory of the current user.
      let userHomePath = environment.getUserHomeDir();
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getDirectory failed with err: ' + JSON.stringify(err));
    }
  }
  ```
