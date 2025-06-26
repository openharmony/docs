# Obtaining and Accessing a User Directory

## Obtaining and Accessing a User Directory (ArkTS)

You can use [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) to allow a third-party application to access files in a user directory.

 **Constraints**
 - The device must have the SystemCapability.FileManagement.File.Environment.FolderObtain system capability. Currently, only 2-in-1 devices are supported.
   ```ts
   if (!canIUse('SystemCapability.FileManagement.File.Environment.FolderObtain')) {
       console.error('this api is not supported on this device');
       return;
   }
   ```
 - The APIs for obtaining user directories do not verify the permissions for accessing the related user directories. To access the user directories, the caller must have the related permissions. If a third-party application needs to access a user directory, user authorization for access to the **Download**, **Documents**, or **Desktop** directory is required via a dialog box. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).
   <!--RP1-->
   ```json
   "requestPermissions" : [
       "ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY",
       "ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY",
       "ohos.permission.READ_WRITE_DESKTOP_DIRECTORY",
   ]
   ```
   <!--RP1End-->

### Example

1. Obtain a user directory.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Environment } from '@kit.CoreFileKit';

function getUserDirExample() {
    try {
        const downloadPath = Environment.getUserDownloadDir();
        console.info(`success to getUserDownloadDir: ${downloadPath}`);
        const documentsPath = Environment.getUserDocumentDir();
        console.info(`success to getUserDocumentDir: ${documentsPath}`);
    } catch (error) {
        const err: BusinessError = error as BusinessError;
        console.error(`failed to get user dir, Error code: ${err.code}, message: ${err.message}`);
    }
}
```

2. Access files in the **Download** directory.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Environment } from '@kit.CoreFileKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

function readUserDownloadDirExample(context: common.UIAbilityContext) {
    // Check whether the caller has the READ_WRITE_DOWNLOAD_DIRECTORY permission. If not, apply for the permission from the user.
    try {
        // Obtain the path to the Download directory.
        const downloadPath = Environment.getUserDownloadDir();
        console.info(`success to getUserDownloadDir: ${downloadPath}`);
        const dirPath = context.filesDir;
        console.info(`success to get filesDir: ${dirPath}`);
        // List the files in the Download directory and copy them to the sandbox directory.
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

3. Save the file to the **Download** directory.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Environment } from '@kit.CoreFileKit';
import { fileIo as fs } from '@kit.CoreFileKit';

function writeUserDownloadDirExample() {
// Check whether the caller has the READ_WRITE_DOWNLOAD_DIRECTORY permission. If not, apply for the permission from the user.
    try {
        // Obtain the path to the Download directory.
        const downloadPath = Environment.getUserDownloadDir();
        console.info(`success to getUserDownloadDir: ${downloadPath}`);
        // Save temp.txt to the Download directory.
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
 - If a third-party application needs to access a user directory, user authorization for access to the **Download**, **Documents**, or **Desktop** directory is required via a dialog box. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

### Available APIs

For details about the APIs, see [Environment](../reference/apis-core-file-kit/_environment.md).

| API                                                                | Description                          |
| ------------------------------------------------------------------------ | ------------------------------ |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result) | Obtains the sandbox path of the **Download** directory. This API is available only for 2-in-1 devices.|
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result)  | Obtains the sandbox path of the **Desktop** directory. This API is available only for 2-in-1 devices. |
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | Obtains the sandbox path of the **Documents** directory. This API is available only for 2-in-1 devices.|

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

1. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory. The memory allocated by **malloc()** must be released using **free()**. <br>Example:

```c++
#include <cstdlib>

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

2. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the **Download** directory and view the files in it. <br>Example:

```c++
#include <cstdlib>
#include <dirent.h>

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
    // View the files in the Download directory.
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

3. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory and save **temp.txt** to this directory. <br>Example:

```c++
#include <fstream>

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
    // Save a file to the Download directory.
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
