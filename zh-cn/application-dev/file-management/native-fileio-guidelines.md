# 应用文件访问(C/C++)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

## 场景介绍

FileIO模块提供了部分文件基础操作能力，其他能力请参考[libc标准库](../reference/native-lib/musl.md)/[标准C++库](../reference/native-lib/cpp.md)。

## 约束限制

进行文件操作之前，必须保证传入正确有效的URI或path。

## 接口说明

接口的详细说明，请参考[FileIO](../reference/apis-core-file-kit/capi-oh-fileio-h.md)。

| 接口名称 | 描述 |
| -------- | -------- |
| FileManagement_ErrCode OH_FileIO_GetFileLocation(char *uri, int uriLength, FileIO_FileLocation *location)| 获取文件存储位置。|
| enum FileIO_FileLocation FileIO_FileLocation| 文件存储位置枚举值。 |
| enum FileManagement_ErrCode FileManagement_ErrCode| 文件管理模块错误码。|

## 开发步骤

**在CMake脚本中链接动态库**

CMakeLists.txt中添加以下lib。

```txt
target_link_libraries(sample PUBLIC libohfileio.so)
```

**添加头文件**

```c++
#include <cstdio>
#include <cstring>
#include <filemanagement/fileio/oh_fileio.h>
```

调用OH_FileIO_GetFileLocation接口获取文件存储位置。示例代码如下所示：
```c
void GetFileLocationExample() {
    char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
    FileIO_FileLocation location;
    FileManagement_ErrCode ret = OH_FileIO_GetFileLocation(uri, strlen(uri), &location);
    if (ret == 0) {
        if (location == FileIO_FileLocation::LOCAL) {
            printf("This file is on local.");
        } else if (location == FileIO_FileLocation::CLOUD) {
            printf("This file is on cloud.");
        } else if (location == FileIO_FileLocation::LOCAL_AND_CLOUD) {
            printf("This file is both on local and cloud.");
        }
    } else {
        printf("GetFileLocation failed, error code is %d", ret);
    }
}
```
