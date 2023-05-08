# Raw File Development

## When to Use

This document describes how to use the native Rawfile APIs to manage raw file directories and files in OpenHarmony. You can use Rawfile APIs to perform operations such as traversing the file list, opening, searching for, reading, and closing raw files.

## Available APIs

| Name                                                      | Description                                    |
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

   The following describes how to obtain the raw file list, raw file content, and raw file descriptor on the JavaScript side as an example.

**1. Create a project.**

![Creating a C++ application](figures/rawfile1.png)

**2. Add dependencies.**

   After a project is created, the **cpp** directory is created under the project. The directory contains files such as **libentry/index.d.ts**, **hello.cpp**, and **CMakeLists.txt**.

   1. Open the **src/main/cpp/CMakeLists.txt** file, and add **librawfile.z.so** and **libhilog_ndk.z.so** to **target_link_libraries**.

    ```c++
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so librawfile.z.so)
    ```

   2. Open the **src/main/cpp/types/libentry/index.d.ts** file, and declare the application functions **getFileList**, **getRawFileContent**, and **getRawFileDescriptor**.

    ```c++
    import resourceManager from '@ohos.resourceManager';
    export const getFileList: (resmgr: resourceManager.ResourceManager, path: string) => Array<String>;
    export const getRawFileContent: (resmgr: resourceManager.ResourceManager, path: string) => Uint8Array;
    export const getRawFileDescriptor: (resmgr: resourceManager.ResourceManager, path: string) => resourceManager.RawFileDescriptor;    
    ```

3. Modify the source file.

   1. Open the **src/main/cpp/hello.cpp** file. During initialization, the file maps the external JavaScript APIs **getFileList**, **getRawFileContent**, and **getRawFileDescriptor** to C++ native APIs **GetFileList**, **GetRawFileContent**, and **GetRawFileDescriptor**.

    ```c++
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "getFileList", nullptr, GetFileList, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "getRawFileContent", nullptr, GetRawFileContent, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "getRawFileDescriptor", nullptr, GetRawFileDescriptor, nullptr, nullptr, nullptr, napi_default, nullptr }
        };

        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```

   2. Add the three functions to the **src/main/cpp/hello.cpp** file.

    ```c++
    static napi_value GetFileList(napi_env env, napi_callback_info info)
    static napi_value GetRawFileContent(napi_env env, napi_callback_info info)
    static napi_value GetRawFileDescriptor(napi_env env, napi_callback_info info)
    ```

   3. Obtain JavaScript resource objects from the **hello.cpp** file, and convert them to native resource objects. Then, call the native APIs to obtain the raw file list, raw file content, and raw file descriptor {fd, offset, length}. The sample code is as follows:

    ```c++
    // Example 1: Use GetFileList to obtain the raw file list.
    static napi_value GetFileList(napi_env env, napi_callback_info info)
    {
        OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "NDKTest Begin");
        size_t requireArgc = 3;
        size_t argc = 2;
        napi_value argv[2] = { nullptr };
        // Obtain arguments of the native API.
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

        // Obtain argv[0], which specifies conversion of the JavaScript resource object (that is, OH_ResourceManager_InitNativeResourceManager) to a native object.
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);

        // Obtain argv[1], which specifies the relative path of the raw file.
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string dirName(strBuf, strSize);

        // Obtain the corresponding rawDir pointer object.
        RawDir* rawDir = OH_ResourceManager_OpenRawDir(mNativeResMgr, dirName.c_str());

        // Obtain the number of files and folders in rawDir.
        int count = OH_ResourceManager_GetRawFileCount(rawDir);

        // Traverse rawDir to obtain the list of file names and save it.
        std::vector<std::string> tempArray;
        for(int i = 0; i < count; i++) {
            std::string filename = OH_ResourceManager_GetRawFileName(rawDir, i);
            tempArray.emplace_back(filename);
        }

        napi_value fileList;
        napi_create_array(env, &fileList);
        for (size_t i = 0; i < tempArray.size(); i++) {
            napi_value jsString;
            napi_create_string_utf8(env, tempArray[i].c_str(), NAPI_AUTO_LENGTH, &jsString);
            napi_set_element(env, fileList, i, jsString);
        }

        // Close the rawDir pointer object.
        OH_ResourceManager_CloseRawDir(rawDir);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        return fileList;
    }

    // Example 2: Use rawDir pointer object to obtain the content of the raw file.
    napi_value CreateJsArrayValue(napi_env env, std::unique_ptr<uint8_t[]> &data, long length)
    {
        napi_value buffer;
        napi_status status = napi_create_external_arraybuffer(env, data.get(), length,
                [](napi_env env, void *data, void *hint) {
                    delete[] static_cast<char*>(data);
                }, nullptr, &buffer);
        if (status != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "Failed to create external array buffer");
            return nullptr;
        }
        napi_value result = nullptr;
        status = napi_create_typedarray(env, napi_uint8_array, length, buffer, 0, &result);
        if (status != napi_ok) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "Failed to create media typed array");
            return nullptr;
        }
        data.release();
        return result;
    }
    static napi_value GetRawFileContent(napi_env env, napi_callback_info info)
    {
        OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "GetFileContent Begin");
        size_t requireArgc = 3;
        size_t argc = 2;
        napi_value argv[2] = { nullptr };
        // Obtain parameter information.
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

        // Obtain argv[0], which specifies conversion of OH_ResourceManager_InitNativeResourceManager to a native object.
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string filename(strBuf, strSize);

        // Obtain the raw file pointer object.
        RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
        if (rawFile != nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "OH_ResourceManager_OpenRawFile success");
        }
        // Obtain the size of the raw file and apply for memory.
        long len = OH_ResourceManager_GetRawFileSize(rawFile);
        std::unique_ptr<uint8_t[]> data= std::make_unique<uint8_t[]>(len);
        // Read the raw file.
        int res = OH_ResourceManager_ReadRawFile(rawFile, data.get(), len);
        // Close the raw file pointer object.
        OH_ResourceManager_CloseRawFile(rawFile);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        // Convert the native object to a JavaScript object.
        return CreateJsArrayValue(env, data, len);
    }

    // Example 3: Use GetRawFileDescriptor to obtain the FD of the raw file.
    napi_value createJsFileDescriptor(napi_env env, RawFileDescriptor &descriptor)
    {
        napi_value result;
        napi_status status = napi_create_object(env, &result);
        if (status != napi_ok) {
            return result;
        }

        napi_value fd;
        status = napi_create_int32(env, descriptor.fd, &fd);
        if (status != napi_ok) {
            return result;
        }
        status = napi_set_named_property(env, result, "fd", fd);
        if (status != napi_ok) {
            return result;
        }

        napi_value offset;
        status = napi_create_int64(env, descriptor.start, &offset);
        if (status != napi_ok) {
            return result;
        }
        status = napi_set_named_property(env, result, "offset", offset);
        if (status != napi_ok) {
            return result;
        }

        napi_value length;
        status = napi_create_int64(env, descriptor.length, &length);
        if (status != napi_ok) {
            return result;
        }
        status = napi_set_named_property(env, result, "length", length);
        if (status != napi_ok) {
            return result;
        }
        return result;
    }
    static napi_value GetRawFileDescriptor(napi_env env, napi_callback_info info)
    {
        OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "NDKTest GetRawFileDescriptor Begin");
        size_t requireArgc = 3;
        size_t argc = 2;
        napi_value argv[2] = { nullptr };
        // Obtain argument information.
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
        
        napi_valuetype valueType;
        napi_typeof(env, argv[0], &valueType);
        // Obtain the native resourceManager object.
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string filename(strBuf, strSize);
        // Obtain the raw file pointer object.
        RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
        if (rawFile != nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "OH_ResourceManager_OpenRawFile success");
        }
        // Obtain the FD of the raw file, that is, RawFileDescriptor {fd, offset, length}.
        RawFileDescriptor descriptor;
        OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
        // Close the raw file pointer object.
        OH_ResourceManager_CloseRawFile(rawFile);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        // Convert the native object to a JavaScript object.
        return createJsFileDescriptor(env,descriptor);
    }
    ```

**4. Call APIs on the JavaScript side.**

   1. Open **src\main\ets\pages\index.ets**, and import **libentry.so**.

   2. Obtain the JavaScript resource object, that is, **resourceManager**.
    
   3. Call **getFileList**, that is, the native API declared in **src/main/cpp/types/libentry/index.d.ts**. When calling the API, pass the JavaScript resource object and the relative path of the raw file. The sample code is as follows:

    ```js
    import hilog from '@ohos.hilog';
    import testNapi from 'libentry.so'  // Import the libentry.so file.
    @Entry
    @Component
    struct Index {
        @State message: string = 'Hello World'
        private resmgr = getContext().resourceManager;  // Obtain the JavaScript resource object.
        build() {
            Row() {
            Column() {
                Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                    hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
                    let rawfilelist = testNapi.getFileList(this.resmgr, ""); // Pass the JavaScript resource object and the relative path of the raw file.
                    console.log("rawfilelist" + rawfilelist);
                    let rawfileContet = testNapi.getRawFileContent(this.resmgr, "rawfile1.txt");
                    console.log("rawfileContet" + rawfileContet);
                    let rawfileDescriptor = testNapi.getRawFileDescriptor(this.resmgr, "rawfile1.txt");
                    console.log("getRawFileDescriptor" + rawfileDescriptor.fd, rawfileDescriptor.offset, rawfileDescriptor.length);
                })
            }
            .width('100%')
            }
            .height('100%')
        }
    }
    ```

## Using C++ Functions

1. Call **OH_ResourceManager_OpenRawDir** to obtain a **RawDir** instance based on the **NativeResourceManager** instance.

    ```c++
    RawDir* rawDir = OH_ResourceManager_OpenRawDir(nativeResourceManager, path.c_str());
    ```
    
2. Call **OH_ResourceManager_GetRawFileCount** to obtain the total number of raw files in the directory based on the **RawDir** instance.

    ```c++
    int count = OH_ResourceManager_GetRawFileCount(rawDir);
    ```
    
3. Call **OH_ResourceManager_GetRawFileName** to obtain the name of the raw file with the specified index.

    ```c++
    for (int index = 0; index < count; index++) {
        std::string fileName = OH_ResourceManager_GetRawFileName(rawDir, index);
    }
    ```

4. Call **OH_ResourceManager_OpenRawFile** to obtain a **RawFile** instance with the specified file name.

    ```c++
    RawFile* rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, fileName.c_str());
    ```
    
5. Call **OH_ResourceManager_GetRawFileSize** to obtain the size of the raw file.

    ```c++
    long rawFileSize = OH_ResourceManager_GetRawFileSize(rawFile);
    ```

6. Call **OH_ResourceManager_SeekRawFile** to seek a read/write position in the raw file based on the specified offset.

    ```c++
    int position = OH_ResourceManager_SeekRawFile(rawFile, 10, 0);
    int position = OH_ResourceManager_SeekRawFile(rawFile, 0 , 1);
    int position = OH_ResourceManager_SeekRawFile(rawFile, -10, 2);
    ```

7. Call **OH_ResourceManager_GetRawFileOffset** to obtain the raw file offset.

    ```c++
    long rawFileOffset = OH_ResourceManager_GetRawFileOffset(rawFile)
    ```

8. Call **OH_ResourceManager_ReadRawFile** to read the raw file.

    ```c++
    std::unique_ptr<char[]> mediaData = std::make_unique<char[]>(rawFileSize);
    long rawFileOffset = OH_ResourceManager_ReadRawFile(rawFile, mediaData.get(), rawFileSize);
    ```

9. Call **OH_ResourceManager_CloseRawFile** to close the file to release resources.

    ```c++
    OH_ResourceManager_CloseRawFile(rawFile);
    ```

10. Call **OH_ResourceManager_CloseRawDir** to close the raw file directory.

    ```c++
    OH_ResourceManager_CloseRawDir(rawDir);
    ```

11. Call **OH_ResourceManager_GetRawFileDescriptor** to obtain the FD of the raw file.

    ```c++
    RawFileDescriptor descriptor;
    bool result = OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
    ```

12. Call **OH_ResourceManager_ReleaseRawFileDescriptor** to release the FD of the raw file.

    ```c++
    OH_ResourceManager_ReleaseRawFileDescriptor(descriptor);
    ```

13. Call **OH_ResourceManager_ReleaseNativeResourceManager** to release the native resource manager.

    ```c++
    OH_ResourceManager_ReleaseNativeResourceManager(nativeResourceManager);
    ```
