# FileUri开发指导(C/C++)

## 场景介绍

FileUri提供了关于文件URI的基本操作，对外提供了URI与沙箱路径之间互相转换、远端URI判定、获取URI所在目录路径的URI等接口，方便用户将文件URI与沙箱路径相互转换。

## 基本概念

**结果集**：满足使用场景正确的路径或者URI。

## 约束限制

- 转换或者判断URI类型之前必须保证传入的参数正确有效。

- 为保证数据的准确性，在转换或者判断过程中只允许处理一个对象。

## 接口说明

接口的详细说明，请参考[API参考](../reference/apis-core-file-kit/fileuri.md)

| 接口名称 | 描述                                         |
| -------- |--------------------------------------------|
| FileManagement_ErrCode OH_FileUri_GetUriFromPath(const char *path, unsigned int length, char **result)| 通过传入的路径PATH获取到对应的URI。                      |
| FileManagement_ErrCode OH_FileUri_GetPathFromUri(const char *uri, unsigned int length, char **result) | 通过传入的URI获取到对应的沙箱路径PATH。                    |
| FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri(const char *uri, unsigned int length, char **result) | 获取所在路径URI，文件获取所在路径URI，如果URI指向目录则获取当前路径URI。 |
| bool OH_FileUri_IsValidUri(const char *uri, unsigned int length) | 判断传入的URI的格式是否正确。                           |
| FileManagement_ErrCode OH_FileUri_GetFileName(const char *uri, unsigned int length, char **result) | 通过传入的URI获取到对应的文件名称。                        |

## 开发步骤

**在CMake脚本中链接动态库**

CMakeLists.txt中添加以下lib。

```txt
target_link_libraries(sample PUBLIC libohfileuri.so)
```

**添加头文件**

```c++
#include <filemanagement/file_uri/oh_file_uri.h>
```

1. 调用OH_FileUri_GetUriFromPath接口，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

   ```c
    #include <cstring>

    void OH_FileUri_GetUriFromPathExample() {
        char *path = "/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(path);
        char *uriResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetUriFromPath(path, length ,&uriResult); 
        if (ret == 0 && uriResult !=NULL) {
            printf("pathUri=%s", uriResult); // 应用a获取到的URI为：file://com.example.demo/data/storage/el2/base/files/test.txt
        }
        if (uriResult != NULL) {
            free(uriResult);
        }
    }    
   ```

2. 调用OH_FileUri_GetPathFromUri通过URi转成对应的PATH，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

   ```c
    #include <cstring>

    void OH_FileUri_GetPathFromUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        char *pathResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetPathFromUri(uri, length, &pathResult);
        if (ret == 0 && pathResult != NULL) {
            printf("pathResult=%s", pathResult); // PathResult值为：/data/storage/el2/base/files/test.txt
        }
        if (pathResult != NULL) {
            free(pathResult);
        }
    }
   ```

3. 调用OH_FileUri_GetFullDirectoryUri获取URI所在路径的URI，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

   ```c
    #include <cstring>
    
    void OH_FileUri_GetFullDirectoryUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        char *uriResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetFullDirectoryUri(uri, length, &uriResult);
        if (ret == 0 && uriResult != NULL) {
            printf("pathUri=%s",uriResult);//URI所在路径的URI：file://com.example.demo/data/storage/el2/base/files/
        }
        if (uriResult != NULL) {
            free(uriResult);
        }
    }
   ```

4. 可以调用OH_FileUri_IsValidUri接口进行URI格式验证。 示例代码如下所示：

   ```c
    #include <cstring>
    
    void OH_FileUri_IsValidUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        bool falgs = OH_FileUri_IsValidUri(uri, length);
        printf("The URI is valid? falgs=%d", falgs);
    }
   ```
   
5. 调用OH_FileUri_GetFileName获取URI中的文件名称，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

   ```c
    #include <cstring>
    
    void OH_FileUri_GetFileNameExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        char *uriResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetFileName(uri, length, &uriResult);
        if (ret == 0 && uriResult != NULL) {
            printf("pathUri=%s",uriResult);//获取到URI中的文件名：test.txt
        }
        if (uriResult != NULL) {
            free(uriResult);
        }
    }
   ```

