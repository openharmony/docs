# Obtaining and Accessing a User Directory

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=a4ab7818ed885325c1c229f68951ad01a4b5d585 translatedAt=2026-08-01T07:27:45.381Z pushedAt=2026-08-01T11:06:17.229Z -->

## Obtaining and Accessing a User Directory (ArkTS)

You can use [ohos.file.environment](../reference/apis-core-file-kit/js-apis-file-environment.md) to allow a third-party application to access files in a user directory.

 **Constraints**

 - To use this method, ensure that the device has the following system capability: SystemCapability.FileManagement.File.Environment.FolderObtain. Currently, 2-in-1 devices are supported.<br>Starting from API version 26.0.0, tablet devices are supported.

   ```ts
   if (!canIUse('SystemCapability.FileManagement.File.Environment.FolderObtain')) {
       console.error('this api is not supported on this device');
       return;
   }
   ```

 - The public directory obtaining API is used only to obtain the public directory path and does not verify the public directory access permission. To access a public directory, you must apply for the corresponding public directory access permission. When a third-party app needs to access a public directory, it must request the user to grant the [Download directory permission](../security/AccessToken/permissions-for-all-user.md#ohospermissionread_write_download_directory), [Documents directory permission](../security/AccessToken/permissions-for-all-user.md#ohospermissionread_write_documents_directory), or [Desktop directory permission](../security/AccessToken/restricted-permissions.md#ohospermissionread_write_desktop_directory). For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

### Example

1. Obtain a user directory.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Environment } from '@kit.CoreFileKit';
   
   ```

   <!--@[get_user_dir_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/EnvironmentSample/entry/src/main/ets/pages/Index.ets)-->    

   ``` TypeScript
   function getUserDirExample() {
     try {
       const downloadPath = Environment.getUserDownloadDir();
       console.info(`Succeeded in getting user download dir: ${downloadPath}`);
       const documentsPath = Environment.getUserDocumentDir();
       console.info(`Succeeded in getting user document dir: ${documentsPath}`);
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to get user dir. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

2. Access files in the **Download** directory.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Environment } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { common } from '@kit.AbilityKit';
   
   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   
   ```

   <!--@[read_user_download_dir_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/EnvironmentSample/entry/src/main/ets/pages/Index.ets)-->      

   ``` TypeScript
   function readUserDownloadDirExample(context: common.UIAbilityContext) {
     try {
       // Obtain the path to the Download directory.
       const downloadPath = Environment.getUserDownloadDir();
       console.info(`Succeeded in getting user download dir: ${downloadPath}`);
       const dirPath = context.filesDir;
       // List the files in the Download directory and copy them to the sandbox directory.
       let fileList: string[] = fileIo.listFileSync(downloadPath);
       fileList.forEach((file, index) => {
         console.info(`${downloadPath} ${index}: ${file}`);
         if (fileIo.statSync(`${downloadPath}/${file}`).isFile()) {
           fileIo.copyFileSync(`${downloadPath}/${file}`, `${dirPath}/${file}`);
         }
       });
       // List the files in the sandbox directory.
       fileList = fileIo.listFileSync(dirPath);
       fileList.forEach((file, index) => {
         console.info(`Succeeded in listing file, ${dirPath} ${index}: ${file}`);
       });
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to read user download dir. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

3. Save a file to the **Download** directory.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Environment } from '@kit.CoreFileKit';
   import { fileIo } from '@kit.CoreFileKit';
   
   ```

   <!--@[write_user_download_dir_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/EnvironmentSample/entry/src/main/ets/pages/Index.ets)-->      

   ``` TypeScript
   function writeUserDownloadDirExample() {
     // Check whether the caller has the READ_WRITE_DOWNLOAD_DIRECTORY permission. If not, apply for the permission from the user.
     try {
       // Obtain the path to the Download directory.
       const downloadPath = Environment.getUserDownloadDir();
       console.info(`Succeeded in getting user download dir: ${downloadPath}`);
       // Save temp.txt to the Download directory.
       const file = fileIo.openSync(`${downloadPath}/temp.txt`, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
       fileIo.writeSync(file.fd, 'write a message');
       fileIo.closeSync(file);
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to write user download dir. Code: ${err.code}, message: ${err.message}`);
     }
   }
   ```

## Obtaining and Accessing a User Directory (C/C++)

In addition to accessing public directories through ArkTS, you can also access directories through C/C++ APIs. For details, see [oh_environment.h](../reference/apis-core-file-kit/capi-oh-environment-h.md).

 **Constraints**

 - The device must have SystemCapability.FileManagement.File.Environment.FolderObtain.

 - When a third-party app needs to access a public directory, it must request the user to grant the **Download** directory permission, **Documents** directory permission, or **Desktop** directory permission through a pop-up authorization. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

### Available APIs

For details about the APIs, see [oh_environment.h](../reference/apis-core-file-kit/capi-oh-environment-h.md).

| API                                                                | Description                          |
| ------------------------------------------------------------------------ | ------------------------------ |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result) | Obtains the sandbox path of the user's **Download** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0. |
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result)  | Obtains the sandbox path of the user's **Desktop** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0.  |
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | Obtains the sandbox path of the user's **Document** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0. |

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

1. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory. The memory allocated by **malloc()** must be released using **free()** after use. The sample code is as follows:

   ```c++
   #include <cstdlib>
   
   ```

   <!--@[get_user_download_dir_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void GetUserDownloadDirExample()
   {
       char *downloadPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user download directory, download path=%{public}s", downloadPath);
           free(downloadPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get download path, error code is %{public}d", ret);
       }
   }
   ```

2. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory and view the files in the **Download** directory. The sample code is as follows:

   ```c++
   #include <cstdlib>
   #include <dirent.h>
   
   ```

   <!--@[scan_user_download_dir_path_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void ScanUserDownloadDirPathExample()
   {
       // Obtain the Download path.
       char *downloadPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in scanning user download directory, path=%{public}s", downloadPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get download path, error code is %{public}d", ret);
           return;
       }
       // View the files in the Download directory.
       struct dirent **namelist = nullptr;
       int num = scandir(downloadPath, &namelist, nullptr, nullptr);
       if (num < 0) {
           free(downloadPath);
           OH_LOG_ERROR(LOG_APP, "Failed to scan directory");
           return;
       }
   
       for (int i = 0; i < num; i++) {
           OH_LOG_INFO(LOG_APP, "Succeeded in scanning directory, file name is %{public}s", namelist[i]->d_name);
       }
       free(downloadPath);
       for (int i = 0; i < num; i++) {
           free(namelist[i]);
       }
       free(namelist);
   }
   ```

3. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory and save **temp.txt** to the **Download** directory. The sample code is as follows:

   ```c++
   #include <fstream>
   
   ```

   <!--@[write_user_download_dir_path_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void WriteUserDownloadDirPathExample()
   {
       // Obtain the Download path.
       char *downloadPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user download directory, path=%{public}s", downloadPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get download path, error code is %{public}d", ret);
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
       outfile.write(msg.c_str(), msg.size());
       outfile.close();
   }
   ```