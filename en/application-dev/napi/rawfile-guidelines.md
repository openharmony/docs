# Raw File Development

 

## When to Use

This document describes how to use the native Rawfile APIs to manage raw file directories and files in OpenHarmony. You can use the APIs to traverse, open, search for, read, and close raw files.

## Available APIs

| API                                                      | Description                                    |
| :----------------------------------------------------------- | :--------------------------------------- |
| NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr) | Initializes the native resource manager.         |
| RawDir *OH_ResourceManager_OpenRawDir(const NativeResourceManager *mgr, const char *dirName) | Opens a raw file directory.                   |
| int OH_ResourceManager_GetRawFileCount(RawDir *rawDir)       | Obtains the number of raw files in the specified directory.|
| const char *OH_ResourceManager_GetRawFileName(RawDir *rawDir, int index) | Obtains the name of a raw file.                       |
| RawFile *OH_ResourceManager_OpenRawFile(const NativeResourceManager *mgr, const char *fileName) | Opens a raw file.                   |
| long OH_ResourceManager_GetRawFileSize(RawFile *rawFile)     | Obtains the size of a raw file.                   |
| int OH_ResourceManager_SeekRawFile(const RawFile *rawFile, long offset, int whence) | Seeks a read/write position in a raw file based on the specified offset.                   |
| long OH_ResourceManager_GetRawFileOffset(const RawFile *rawFile) | Obtains the offset.                     |
| int OH_ResourceManager_ReadRawFile(const RawFile *rawFile, void *buf, size_t length) | Reads a raw file.                   |
| void OH_ResourceManager_CloseRawFile(RawFile *rawFile)       | Closes a raw file to release resources.               |
| void OH_ResourceManager_CloseRawDir(RawDir *rawDir)          | Closes a raw file directory to release resources.               |
| bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor) | Obtains the file descriptor (FD) of a raw file.                       |
| bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor) | Releases the FD of a raw file.                       |
| void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr) | Releases the native resource manager.   |

## How to Develop

1. Add the header file.

    ```c++
    #include "raw_file_manager.h"
    ```
    
    

2. Call **OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr)** to obtain a **NativeResourceManager** instance.

    ```js
    // Import the JS resource manager from the JS head file and pass it to the C++ file.
    import resManager from '@ohos.resourceManager'
    import rawfileTest from 'librawFileTest.so'
    resManager.getResourceManager().then(resmgr => {
        rawfileTest.testRawFile("test", resmgr, (error, value) => {
            console.log("test rawFile");
        })
    });
    ```

    ```c++
    // Obtain and parse the parameters in the C++ file.
    NativeResourceManager* nativeResourceManager = nullptr;
    std::string path;
    if (i == 0 && valueType == napi_string) {
        // Parse the first parameter, which is the file or directory path relative to the raw file directory.
        ......
        path = buf.data();
    } else if (i == 1 && valueType == napi_object) {
        // Parse the second parameter, which is the JS resource manager.
        nativeResourceManager = OH_ResourceManager_InitNativeResourceManager(env, argv[i]);
    }
    ```

    

3. Call **OH_ResourceManager_OpenRawDir** to obtain a **RawDir** instance based on the **NativeResourceManager** instance.

    ```c++
    RawDir* rawDir = OH_ResourceManager_OpenRawDir(nativeResourceManager, path.c_str());
    ```
    
    
    
4. Call **OH_ResourceManager_GetRawFileCount** to obtain the total number of raw files in the directory based on the **RawDir** instance.

    ```c++
    int count = OH_ResourceManager_GetRawFileCount(rawDir);
    ```
    
    
    
5. Call **OH_ResourceManager_GetRawFileName** to obtain the name of the raw file with the specified index.

    ```c++
    for (int index = 0; index < count; index++) {
        std::string fileName = OH_ResourceManager_GetRawFileName(rawDir, index);
    }
    ```

    

6. Call **OH_ResourceManager_OpenRawFile** to obtain a **RawFile** instance with the specified file name.

    ```c++
    RawFile* rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, fileName.c_str());
    ```
    
    
    
7. Call **OH_ResourceManager_GetRawFileSize** to obtain the size of the raw file.

    ```c++
    long rawFileSize = OH_ResourceManager_GetRawFileSize(rawFile);
    ```
    
    

8. Call **OH_ResourceManager_SeekRawFile** to seek a read/write position in the raw file based on the specified offset.

    ```c++
    int position = OH_ResourceManager_SeekRawFile(rawFile, 10, 0);
    int position = OH_ResourceManager_SeekRawFile(rawFile, 0 , 1);
    int position = OH_ResourceManager_SeekRawFile(rawFile, -10, 2);
    ```
    
    

9. Call **OH_ResourceManager_GetRawFileOffset** to obtain the raw file offset.

    ```c++
    long rawFileOffset = OH_ResourceManager_GetRawFileOffset(rawFile)
    ```
    
    

10. Call **OH_ResourceManager_ReadRawFile** to read the raw file.

    ```c++
    std::unique_ptr<char[]> mediaData = std::make_unique<char[]>(rawFileSize);
    long rawFileOffset = OH_ResourceManager_ReadRawFile(rawFile, mediaData.get(), rawFileSize);
    ```

    

11. Call **OH_ResourceManager_CloseRawFile** to close the file to release resources.

    ```c++
    OH_ResourceManager_CloseRawFile(rawFile);
    ```
    
    

12. Call **OH_ResourceManager_CloseRawDir** to close the raw file directory.

    ```c++
    OH_ResourceManager_CloseRawDir(rawDir);
    ```
    
    

13. Call **OH_ResourceManager_GetRawFileDescriptor** to obtain the FD of the raw file.

    ```c++
    RawFileDescriptor descriptor;
    bool result = OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
    ```

    

14. Call **OH_ResourceManager_ReleaseRawFileDescriptor** to release the FD of the raw file.

    ```c++
    OH_ResourceManager_ReleaseRawFileDescriptor(descriptor);
    ```



15. Call **OH_ResourceManager_ReleaseNativeResourceManager** to release the native resource manager.

    ```c++
    OH_ResourceManager_ReleaseNativeResourceManager(nativeResourceManager);
    ```
