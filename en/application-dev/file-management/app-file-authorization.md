# Authorizing File Access (ArkTS)

An application must have the related permission before accessing a file. To enable your application to access files, you may need to:

1. Declare the permissions required for accessing user directories.
2. Use FilePicker to select the files or directories that your application can access and persist the temporary permission.
3. Obtain the URI of a file or folder using APIs.
4. Obtain a user directory or a directory of the external storage using APIs.

Only some devices support the access authorization operations.

The following walks you through common operations.

## Requesting Permissions for Your Application and Obtaining the Access Path

Request the permissions for accessing the **Download**, **Documents**, or **Desktop**, and obtain the access path.

1. Request the permissions via the ACL for a third-party application and display a dialog box for the user to grant the permission to access the **Download**, **Documents**, or **Desktop** directory. For details, see [Workflow for Using Permissions](../security/AccessToken/determine-application-mode.md).

   ```json
    "requestPermissions" : [
        "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY",
        "ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY",
        "ohos.permission.READ_WRITE_DESKTOP_DIRECTORY",
    ]
   ```

2. Use [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) to obtain the environment path.

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

Use FilePicker to select a file or folder, and persist the temporary permission for your application. If the application restarts, the permission needs to be activated. You can use [ohos.fileshare](../reference/apis/js-apis-fileShare.md) to persist and activate permissions on files or folders based on their URI.

1. Use **select()** or **save()** of FilePicker to select or save a file. The file URI is returned. Because the user is involved in selecting or saving the file that the application can access, the application can access the file without any system permission. That is, the application has temporary permission to access the file.

   Example:

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

2. Check whether the application has persist permission on the file. If not, go to the next step to persist the permission.

   Example:

   ```ts
   import { BusinessError } from '@ohos.base';
   import picker from '@ohos.file.picker';
   import fileshare from '@ohos.fileshare';

   async function checkPersistentPermissionExample() {
     try {
       let documentSelectOptions = new picker.DocumentSelectOptions();
       let documentPicker = new picker.DocumentViewPicker();
       let uris = await documentPicker.select(documentSelectOptions);
       let policyInfo: fileshare.PolicyInfo = {
         uri: uris[0],
         operationMode: fileshare.OperationMode.READ_MODE,
       };
       let policies: Array<fileshare.PolicyInfo> = [policyInfo];
       fileshare.checkPersistentPermission(policies).then(async (data) => {
         let results: Array<boolean> = data;
         for (let i = 0; i < results.length; i++) {
           console.log("checkPersistentPermission result: " + JSON.stringify(results[i]));
           if (!results[i]) {
             let info: fileshare.PolicyInfo = {
               uri: policies[i].uri,
               operationMode: policies[i].operationMode,
             };
             let policy: Array<fileshare.PolicyInfo> = [info];
             await fileshare.persistPermission(policy);
           }
         }
       }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
         console.info("checkPersistentPermission failed with error message: " + err.message + ", error code: " + err.code);
       });
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('checkPersistentPermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

3. Persist the permission on the file based on the URI obtained in step 1.

   Example:

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
         if (err.code == 13900001 && err.data) {
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

4. Revoke the persistent permission from the file if required.

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
       await fileshare.persistPermission(policy);
       fileshare.revokePermission(policies).then(() => {
         console.info("revokePermission successfully");
       }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
         console.info("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
         if (err.code == 13900001 && err.data) {
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

5. Activate the persistent permission after the application restarts. <br>Before a URI is accessed or after an application is restarted, check whether the URI has persistent permissions. If yes, activate the persistent permissions. Note that the API for persisting permissions and the API for activating permissions must be used together.

   Example: The URI specifies the path the file for which the permissions are to be activated.

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
       let results = await fileshare.checkPersistentPermission(policies);
       for (let i = 0; i < results.length; i++) {
         console.log("checkPersistentPermission result: " + JSON.stringify(results[i]));
         if (results[i]) {
           let info: fileshare.PolicyInfo = {
             uri: policies[i].uri,
             operationMode: policies[i].operationMode,
           };
           let policy: Array<fileshare.PolicyInfo> = [info];
           await fileshare.activatePermission(policy);
           console.info("activatePermission successfully");
         }
       }
       let fd = await fs.open(uri);
       await fs.close(fd);
     } catch (error) {
       let err: BusinessError = error as BusinessError;
       console.error('activatePermission failed with err: ' + JSON.stringify(err));
     }
   }
   ```

6. Deactivate the persistent permissions on the URI if required.

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
       await fileshare.activatePermission(policies);
       fileshare.deactivatePermission(policies).then(() => {
         console.info("deactivatePermission successfully");
       }).catch((err: BusinessError<Array<fileshare.PolicyErrorResult>>) => {
         console.info("deactivatePermission failed with error message: " + err.message + ", error code: " + err.code);
         if (err.code == 13900001 && err.data) {
           console.log("error data : " + JSON.stringify(err.data));
         }
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

Use [ohos.file.fileuri](../reference/apis-core-file-kit/js-apis-file-fileuri.md) to obtain the URI of a file or folder. If **FileUri** points to a file, the URI of the directory where the file is located will be returned. If **FileUri** points to a folder, the URI of the current path is returned. 

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

## Obtaining a User Directory or a Directory of the Internal or External Storage (for System Applications Only)

A common application can obtain the following user directories: **Download**, **Desktop**, and **Document**. Only the **Files** application can obtain the root directory of an external card and the built-in card directory in the sandbox directory of the current user using the [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) APIs.

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
