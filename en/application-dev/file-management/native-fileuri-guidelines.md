# FileUri Development (C/C++)

## When to Use

You can use the APIs provided by the **fileUri** module to perform basic URI operations.

## Basic Concepts

**result**: path or URI that meets the service requirements.

## Constraints

- The parameters passed in must be correct and valid before a URI is converted or verified.

- To ensure data accuracy, only one object can be processed during the conversion or verification of a URI.

## Available APIs

For details about the APIs, see [File URI](../reference/apis-core-file-kit/fileuri.md).

| API| Description|
| -------- | -------- |
| FileManagement_ErrCode OH_FileUri_GetUriFromPath(const char *path, unsigned int length, char **result)| Obtains the URI from a path.|
| FileManagement_ErrCode OH_FileUri_GetPathFromUri(const char *uri, unsigned int length, char **result) | Obtains the sandbox path from a URI.|
| FileManagement_ErrCode OH_FileUri_GetFullDirectoryUri(const char *uri, unsigned int length, char **result) | Obtains the URI of the directory, in which a URI is located.|
| bool OH_FileUri_IsValidUri(const char *uri, unsigned int length) | Checks whether a URI is valid.|

## How to Develop

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.

```txt
target_link_libraries(sample PUBLIC libohfileuri.so)
```

**Adding the Header File**

```c++
#include <filemanagement/file_uri/oh_file_uri.h>
```

1. Use **OH_FileUri_GetUriFromPath** to obtain the URI from a path. The memory allocated must be released using **free()**. <br>Example:

   ```c
    #include <cstring>

    void OH_FileUri_GetUriFromPathExample() {
        char *path = "/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(path);
        char *uriResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetUriFromPath(path, length ,&uriResult); 
        if (ret == 0 && uriResult !=NULL) {
            printf("pathUri= %s", uriResult); // The URI obtained by application a is file://com.example.demo/data/storage/el2/base/files/test.txt.
        }
        if (uriResult != NULL) {
            free(uriResult);
        }
    }    
   ```

2. Use **OH_FileUri_GetPathFromUri** to convert a URI into a path. The memory allocated must be released using **free()**. <br>Example:

   ```c
    #include <cstring>

    void OH_FileUri_GetPathFromUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        char *pathResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetPathFromUri(uri, length, &pathResult);
        if (ret == 0 && pathResult != NULL) {
            printf ("pathResult= %s", pathResult); // PathResult is /data/storage/el2/base/files/test.txt.
        }
        if (pathResult != NULL) {
            free(pathResult);
        }
    }
   ```

3. Use **OH_FileUri_GetFullDirectoryUri** to obtain the URI of the directory where the specified URI is located. The memory allocated must be released using **free()**. <br>Example:

   ```c
    #include <cstring>
    
    void OH_FileUri_GetFullDirectoryUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        char *uriResult = NULL;
        FileManagement_ErrCode ret = OH_FileUri_GetFullDirectoryUri(uri, length, &uriResult);
        if (ret == 0 && uriResult != NULL) {
            printf("pathUri= %s",uriResult);// The URI obtained is file://com.example.demo/data/storage/el2/base/files/.
        }
        if (uriResult != NULL) {
            free(uriResult);
        }
    }
   ```

4. Use **OH_FileUri_IsValidUri** to check whether a URI is valid. <br>Example:

   ```c
    #include <cstring>
    
    void OH_FileUri_IsValidUriExample() {
        char *uri = "file://com.example.demo/data/storage/el2/base/files/test.txt";
        unsigned int length = strlen(uri);
        bool falgs = OH_FileUri_IsValidUri(uri, length);
        printf("The URI is valid? falgs=%d", falgs);
    }
   ```
