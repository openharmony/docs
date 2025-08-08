# Accessing Application Files (C/C++) 
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--SE: @gsl_1234; @wangke25-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

## When to Use

The **FileIO** module provides some APIs for basic file operations. For details about other APIs, see [libc](../reference/native-lib/musl.md) and [libc++](../reference/native-lib/cpp.md).

## Constraints

Before performing file operations, ensure that the URI or path passed in is correct and valid.

## Available APIs

For details about the APIs, see [FileIO](../reference/apis-core-file-kit/capi-oh-fileio-h.md).

| API| Description|
| -------- | -------- |
| FileManagement_ErrCode OH_FileIO_GetFileLocation(char *uri, int uriLength, FileIO_FileLocation *location)| Obtains the location of a file.|
| enum FileIO_FileLocation FileIO_FileLocation| Enumerates the file locations.|
| enum FileManagement_ErrCode FileManagement_ErrCode| Enumerates the error codes used in the **FileIO** module.|

## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohfileio.so)
```

**Adding the Header File**

```c++
#include <cstdio>
#include <cstring>
#include <filemanagement/fileio/oh_fileio.h>
```

Call **OH_FileIO_GetFileLocation** to obtain the location of a file. <br>Example:
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
