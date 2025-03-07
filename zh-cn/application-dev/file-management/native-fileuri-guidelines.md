# FileUri开发指导(C/C++)

## 场景介绍

FileUri提供了关于文件uri的基本操作，将uri转换成对应的沙箱路径path、将应用沙箱路径path转换成对应应用自己的uri、获取uri所在目录路径的uri等接口能力，方便应用对文件分享业务中uri的访问。

## 基本概念

**结果集**：满足使用场景正确的路径或者uri。

## 约束限制

- uri转path时，uri来源建议使用系统能力获取，例如：picker、剪切板、拖拽、及系统提供的path转uri接口等系统能力返回的uri；如果转换应用或用户拼接的uri，则转换后的path可能无法访问。

- 为保证数据的准确性，在转换或者判断过程中只允许处理一个对象。

## 接口说明

接口的详细说明，请参考[API参考](../reference/apis-core-file-kit/fileuri.md)

| 接口名称 | 描述 |
| -------- |-------|
| FileManagement_ErrCode OH_FileUri_GetUriFromPath(const char *path, unsigned int length, char **result)| 通过传入的路径path生成应用自己的uri(不支持媒体类型uri的获取)；将path转uri时，路径中的中文及非数字字母的特殊字符将会被编译成对应的ASCII码，拼接在uri中。|
| FileManagement_ErrCode OH_FileUri_GetPathFromUri(const char *uri, unsigned int length, char **result) | 将uri转换成对应的沙箱路径path。 1、uri转path过程中会将uri中存在的ASCII码进行解码后拼接在原处，非系统接口生成的uri中可能存在ASCII码解析范围之外的字符，导致字符串无法正常拼接；2、转换处理为系统约定的字符串替换规则（规则随系统演进可能会发生变化），转换过程中不进行路径校验操作，无法保证转换结果的一定可以访问。 |
| FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri(const char *uri, unsigned int length, char **result) | 获取所在路径uri。uri指向文件则返回所在路径的uri，uri指向目录则不处理直接返回原串；uri指向的文件不存在或属性获取失败则返回空串。|
| bool OH_FileUri_IsValidUri(const char *uri, unsigned int length) | 判断传入的uri的格式是否正确。仅校验uri是否满足系统定义的格式规范，不校验uri的有效性。|
| FileManagement_ErrCode OH_FileUri_GetFileName(const char *uri, unsigned int length, char **result) | 通过传入的uri获取到对应的文件名称。（如果文件名中存在ASCII码将会被解码处理后拼接在原处）。|

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

2. 调用OH_FileUri_GetPathFromUri通过URi转成对应的path，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

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

3. 调用OH_FileUri_GetFullDirectoryUri获取uri所在路径的uri，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

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

4. 可以调用OH_FileUri_IsValidUri接口进行uri格式验证。 示例代码如下所示：

   ```c
    #include <cstring>
    
    void OH_FileUri_IsValidUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        bool falgs = OH_FileUri_IsValidUri(uri, length);
        printf("The URI is valid? falgs=%d", falgs);
    }
   ```
   
5. 调用OH_FileUri_GetFileName获取uri中的文件名称，在接口中malloc的内存需要在使用完后释放，因此需要free对应的内存。示例代码如下所示：

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

