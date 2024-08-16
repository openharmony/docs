# Obtaining and Accessing a User Directory

## Obtaining and Accessing a User Directory (ArkTS)

You can use [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) to allow a third-party application to access files in a user directory.

 **Constraints**
 - The device must have SystemCapability.FileManagement.File.Environment.FolderObtain.
   ```ts
   if (!canIUse('SystemCapability.FileManagement.File.Environment.FolderObtain')) {
       console.error('this api is not supported on this device');
       return;
   }
   ```
 - The third-party application needs to apply for the required permissions via ACL and request user authorization for accessing the **Download**, **Documents**, or **Desktop** directory in a dialog box. For details, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).
   ```json
   "requestPermissions" : [
       "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY",
       "ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY",
       "ohos.permission.READ_WRITE_DESKTOP_DIRECTORY",
   ]
   ```

### Example

1. Obtain the path to a user folder, for example, **Download**.

   ```ts
    import { BusinessError } from '@ohos.base';
    import environment from '@ohos.file.environment';

    function getUserDirExample() {
        try {
            const downloadPath = environment.getUserDownloadDir();
            console.info(`success to getUserDownloadDir: ${downloadPath}`);
            const documentsPath = environment.getUserDocumentDir();
            console.info(`success to getUserDocumentDir: ${documentsPath}`);
            const desktopPath = environment.getUserDesktopDir();
            console.info(`success to getUserDesktopDir: ${desktopPath}`);
        } catch (error) {
            const err: BusinessError = error as BusinessError;
            console.error(`failed to get user dir, because: ${JSON.stringify(err)}`);
        }
    }
   ```

2. Access files in the **Download** folder.

   ```ts
    import { BusinessError } from '@ohos.base';
    import environment from '@ohos.file.environment';
    import fs from '@ohos.file.fs';
    import common from '@ohos.app.ability.common';

    function readUserDownloadDirExample() {
        // Check whether the caller has the READ_WRITE_DOWNLOAD_DIRECTORY permission. If not, apply for the permission from the user.
        try {
            // Obtain the path to the Download folder.
            const downloadPath = environment.getUserDownloadDir();
            console.info(`success to getUserDownloadDir: ${downloadPath}`);
            const context = getContext() as common.UIAbilityContext;
            const dirPath = context.filesDir;
            console.info(`success to get filesDir: ${dirPath}`);
            // List the files in the Download folder and copy them to the sandbox directory.
            let fileList: string[] = fs.listFileSync(downloadPath);
            fileList.forEach((file, index) => {
                console.info(`${downloadPath} ${index}: ${file}`);
                fs.copyFileSync(`${downloadPath}/${file}`, `${dirPath}/${file}`);
            });
            // List the files in the sandbox directory.
            fileList = fs.listFileSync(dirPath);
            fileList.forEach((file, index) => {
                console.info(`${dirPath} ${index}: ${file}`);
            });
        } catch (error) {
            const err: BusinessError = error as BusinessError;
            console.error(`Error code: ${err.code}, message: ${err.message}`);
        }
    }
   ```

3. Save a file to the **Download** folder.

   ```ts
    import { BusinessError } from '@ohos.base';
    import environment from '@ohos.file.environment';
    import fs from '@ohos.file.fs';

    function writeUserDownloadDirExample() {
    // Check whether the caller has the READ_WRITE_DOWNLOAD_DIRECTORY permission. If not, apply for the permission from the user.
        try {
            // Obtain the path to the Download folder.
            const downloadPath = environment.getUserDownloadDir();
            console.info(`success to getUserDownloadDir: ${downloadPath}`);
            // Save temp.txt to the Download folder.
            const file = fs.openSync(`${downloadPath}/temp.txt`, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
            fs.writeSync(file.fd, 'write a message');
            fs.closeSync(file);
        } catch (error) {
            const err: BusinessError = error as BusinessError;
            console.error(`Error code: ${err.code}, message: ${err.message}`);
        }
    }
   ```



## Obtaining and Accessing a User Directory (C/C++)

In addition to ArkTS APIs, you can use C/C++ APIs to allow a third-party application to obtain and access a user directory. For details about the APIs, see [Environment](../reference/apis-core-file-kit/_environment.md).

 **Constraints**
 - The device must have SystemCapability.FileManagement.File.Environment.FolderObtain.
 - The third-party application needs to apply for the required permissions via ACL and request user authorization for accessing the user directory in a dialog box. For details, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).


### Available APIs

For details about the APIs, see [Environment](../reference/apis-core-file-kit/_environment.md).

| API| Description|
| -------- | -------- |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result)| Obtains the sandbox path of the **Download** folder. <br/>The caller must have the ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY permission. |
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result)	 | Obtains the sandbox path of the **Desktop** folder. <br/>The caller must have the ohos.permission.READ_WRITE_DESKTOP_DIRECTORY permission. |
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | Obtains the sandbox path of the **Documents** folder. <br/>The caller must have the ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY permission. |

### How to Develop

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohenvironment.so libhilog_ndk.z.so)
```

**Adding Header Files**

```c++
#include <filemanagement/environment/oh_environment.h>
#include <filemanagement/fileio/oh_fileio.h>
#include <hilog/log.h>
```

- Use **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** folder. The memory allocated by **malloc()** must be released using **free()**. <br>Example:


```c++
void GetUserDownloadDirExample()
{
    char *downloadPath = nullptr;
    FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
    if (ret == 0) {
        OH_LOG_INFO(LOG_APP, "Download Path=%{public}s", downloadPath);
        free(downloadPath);
    } else {
        OH_LOG_ERROR(LOG_APP, "GetDownloadPath fail, error code is %{public}d", ret);
    }
}  
```

- Use **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the **Download** folder and view the files in it. <br>Example:


```c++
void ScanUserDownloadDirPathExample()
{
    // Obtain the Download path.
    char *downloadPath = nullptr;
    FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
    if (ret == 0) {
        OH_LOG_INFO(LOG_APP, "Download Path=%{public}s", downloadPath);
    } else {
        OH_LOG_ERROR(LOG_APP, "GetDownloadPath fail, error code is %{public}d", ret);
        return;
    }
    // View the files in the Download folder.
    struct dirent **namelist = {nullptr};
    int num = scandir(downloadPath, &namelist, nullptr, nullptr);
    if (num < 0) {
        free(downloadPath);
        OH_LOG_ERROR(LOG_APP, "Failed to scan dir");
        return;
    }
    for (int i = 0; i < num; i++) {
        OH_LOG_INFO(LOG_APP, "%{public}s", namelist[i]->d_name);
    }
    free(downloadPath);
    free(namelist);
}
```

- Use **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** folder and save **temp.txt** to this folder. <br>Example:


```c++
void WriteUserDownloadDirPathExample()
{
    // Obtain the Download path.
    char *downloadPath = nullptr;
    FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
    if (ret == 0) {
        OH_LOG_INFO(LOG_APP, "Download Path=%{public}s", downloadPath);
    } else {
        OH_LOG_ERROR(LOG_APP, "GetDownloadPath fail, error code is %{public}d", ret);
        return;
    }
    // Save a file to the Download folder.
    std::string filePath = std::string(downloadPath) + "/temp.txt";
    free(downloadPath);

    std::ofstream outfile;
    outfile.open(filePath.c_str());
    if (!outfile) {
        OH_LOG_ERROR(LOG_APP, "Failed to open file");
        return;
    }
    std::string msg = "Write a message";
    outfile.write(msg.c_str(), sizeof(msg));
    outfile.close();
}  
```