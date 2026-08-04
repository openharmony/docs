# Obtaining the User Directory Environment (C/C++)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=60725424567562f162d93888576df6e82ec4222e translatedAt=2026-08-01T07:26:29.371Z pushedAt=2026-08-01T09:31:39.420Z -->

## When to Use

You can use [Environment](../reference/apis-core-file-kit/capi-oh-environment-h.md) to allow a third-party application to access files in a user directory.

## Constraints

- Before using the APIs of the **Environment** module, ensure that the device has SystemCapability.FileManagement.File.Environment.FolderObtain.

- The APIs provided by the **Environment** module can be used to obtain the application sandbox paths of the user directories. To operate the related directory and its subdirectories, user authorization is required via a dialog box. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

## Available APIs

For details about the APIs, see [oh_environment.h](../reference/apis-core-file-kit/capi-oh-environment-h.md).

| API Name | Description |
| -------- | -------- |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result)| Obtains the sandbox path of the user's **Download** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0. |
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result) | Obtains the sandbox path of the user's **Desktop** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0. |
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | Obtains the sandbox path of the user's **Document** directory. Supported on 2-in-1 devices.<br>Supported on tablet devices starting from API version 26.0.0. |

## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohenvironment.so libhilog_ndk.z.so)
```

**Adding Header Files**

```c++
#include <cstdlib>
#include <filemanagement/environment/oh_environment.h>
#include <filemanagement/fileio/oh_fileio.h>
#include <hilog/log.h>
```

1. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory. The memory allocated must be released using **free()**. <br>Example:

   <!--@[get_user_download_dir_path_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void GetUserDownloadDirPathExample()
   {
       char *downloadPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user download directory, path=%{public}s", downloadPath);
           free(downloadPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get download path, error code is %{public}d", ret);
       }
   }
   ```

2. Call **OH_Environment_GetUserDesktopDir** to obtain the sandbox path of the user **Desktop** directory. The memory allocated must be released using **free()**. <br>Example:

   <!--@[get_user_desktop_dir_path_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void GetUserDesktopDirPathExample()
   {
       char *desktopPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDesktopDir(&desktopPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user desktop directory, path=%{public}s", desktopPath);
           free(desktopPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get user desktop path, error code is %{public}d", ret);
       }
   }
   ```

3. Call **OH_Environment_GetUserDocumentDir** to obtain the sandbox path of the user **Document** directory. The memory allocated must be released using **free()**. <br>Example:

   <!--@[get_user_document_dir_path_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->    

   ``` C++
   void GetUserDocumentDirPathExample()
   {
       char *documentPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDocumentDir(&documentPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user document directory, path=%{public}s", documentPath);
           free(documentPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get user document path, error code is %{public}d", ret);
       }
   }
   ```

4. Call **OH_Environment_GetUserDocumentDir** to obtain the sandbox path of the user **Document** directory, and use the **stat** function to determine the space of the **Document** directory. <br>Example:

   Include the following header file before using the API.

   ``` C++
   #include <sys/stat.h>
   ```

   <!--@[get_user_download_dir_size_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/NDKEnvironmentSample/entry/src/main/cpp/napi_init.cpp)-->      

   ``` C++
   void GetUserDownloadDirSizeExample()
   {
       char *documentPath = nullptr;
       FileManagement_ErrCode ret = OH_Environment_GetUserDocumentDir(&documentPath);
       if (ret == 0) {
           OH_LOG_INFO(LOG_APP, "Succeeded in getting user document directory, path=%{public}s", documentPath);
           struct stat fileStat;
           int result = stat(documentPath, &fileStat);
           if (result == 0) {
               OH_LOG_INFO(LOG_APP, "Succeeded in getting file info. document Size=%{public}ld", fileStat.st_size);
           } else {
               OH_LOG_ERROR(LOG_APP, "Failed to stat user document directory, error code is %{public}d", result);
           }
           free(documentPath);
       } else {
           OH_LOG_ERROR(LOG_APP, "Failed to get user document directory, error code is %{public}d", ret);
       }
   }
   ```