# Obtaining the User Directory Environment (C/C++)

## When to Use

Before accessing or operating a user file, a third-party application needs to obtain the user directory. The **Environment** module provides the APIs for obtaining the user directories.

## Constraints

- Before using the APIs of the **Environment** module, ensure that the device has SystemCapability.FileManagement.File.Environment.FolderObtain.
- The APIs provided by the **Environment** module can be used to obtain the application sandbox paths of the user directories. To operate the related directory and its subdirectories, user authorization is required via a dialog box. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

## Available APIs

For details about the APIs, see [Environment](../reference/apis-core-file-kit/_environment.md).

| API| Description|
| -------- | -------- |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result)| Obtains the sandbox path of the **Download** directory. This API is available only for 2-in-1 devices.|
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result)	 | Obtains the sandbox path of the **Desktop** directory. This API is available only for 2-in-1 devices.|
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | Obtains the sandbox path of the **Documents** directory. This API is available only for 2-in-1 devices.|

## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohenvironment.so)
```

**Adding Header Files**

```c++
#include <filemanagement/environment/oh_environment.h>
#include <filemanagement/fileio/oh_fileio.h>
```

1. Call **OH_Environment_GetUserDownloadDir** to obtain the sandbox path of the user **Download** directory. The memory allocated must be released using **free()**. <br>Example:

    ```c
    void GetUserDownloadDirPathExample() {
        char *downloadPath = NULL;
        FileManagement_ErrCode ret = OH_Environment_GetUserDownloadDir(&downloadPath);
        if (ret == 0) {
            printf("Download Path=%s", downloadPath);
            free(downloadPath);
        } else {
            printf("GetDownloadPath failed, error code is %d", ret);
        }
    }
   ```

2. Call **OH_Environment_GetUserDesktopDir** to obtain the sandbox path of the user **Desktop** directory. The memory allocated must be released using **free()**. <br>Example:

    ```c
    void GetUserDesktopDirPathExample() {
        char *desktopPath = NULL;
        FileManagement_ErrCode ret = OH_Environment_GetUserDesktopDir(&desktopPath);
        if (ret == 0) {
            printf("Desktop Path=%s", desktopPath);
            free(desktopPath);
        } else {
            printf("GetDesktopPath failed, error code is %d", ret);
        }
    }
   ```

3. Call **OH_Environment_GetUserDocumentDir** to obtain the sandbox path of the user **Documents** directory. The memory allocated must be released using **free()**. <br>Example:

    ```c
    void GetUserDocumentDirPathExample() {
        char *documentPath = NULL;
        FileManagement_ErrCode ret = OH_Environment_GetUserDocumentDir(&documentPath);
        if (ret == 0) {
            printf("Document Path=%s", documentPath);
            free(documentPath);
        } else {
            printf("GetDocumentPath failed, error code is %d", ret);
        }
    }
   ```
