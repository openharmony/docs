# 获取用户目录环境(C/C++)

## 场景介绍

[Environment](../reference/apis-core-file-kit/_environment.md)提供了获取公共文件用户目录路径的能力，以支持三方应用在公共文件用户目录下进行文件访问操作。

## 约束限制

- 使用此接口，需确认设备具有以下系统能力：SystemCapability.FileManagement.File.Environment.FolderObtain。
- 此接口仅用作公共沙箱目录路径的获取接口，操作对应的公共目录及其子目录需获取通过弹窗授权方式向用户申请授予对应目录的权限，具体参考[访问控制-向用户申请授权](../security/AccessToken/request-user-authorization.md)

## 接口说明

接口的详细说明，请参考[API参考](../reference/apis-core-file-kit/_environment.md)

| 接口名称 | 描述 |
| -------- | -------- |
| FileManagement_ErrCode OH_Environment_GetUserDownloadDir (char **result)| 获取用户Download目录沙箱路径。只支持2in1设备 |
| FileManagement_ErrCode OH_Environment_GetUserDesktopDir (char **result) | 获取用户Desktop目录沙箱路径。只支持2in1设备 |
| FileManagement_ErrCode OH_Environment_GetUserDocumentDir (char **result) | 获取用户Document目录沙箱路径。只支持2in1设备 |

## 开发步骤

**在CMake脚本中链接动态库**

CMakeLists.txt中添加以下lib。

```txt
target_link_libraries(sample PUBLIC libohenvironment.so)
```

**添加头文件**

```c++
#include <filemanagement/environment/oh_environment.h>
#include <filemanagement/fileio/oh_fileio.h>
```

1. 调用OH_Environment_GetUserDownloadDir接口获取用户Download目录沙箱路径，在接口中使用malloc申请的内存需要在使用完后释放因此需要free对应的内存。示例代码如下所示：

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

2. 调用OH_Environment_GetUserDesktopDir接口获取用户Desktop目录沙箱路径，在接口中使用malloc申请的内存需要在使用完后释放因此需要free对应的内存。示例代码如下所示：

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

3. 调用OH_Environment_GetUserDocumentDir接口获取用户Document目录沙箱路径，在接口中使用malloc申请的内存需要在使用完后释放因此需要free对应的内存。示例代码如下所示：

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
