# 资源管理Rawfile开发指导

## 场景介绍

开发者可以通过本指导了解在OpenHarmony应用中，如何使用Native Rawfile接口操作Rawfile目录和文件。功能包括文件列表遍历、文件打开、搜索、读取和关闭Rawfile。

## 接口说明

| 接口名                                                       | 描述                                     |
| :----------------------------------------------------------- | :--------------------------------------- |
| NativeResourceManager *OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr) | 初始化native resource manager。          |
| RawDir *OH_ResourceManager_OpenRawDir(const NativeResourceManager *mgr, const char *dirName) | 打开指定rawfile目录。                    |
| int OH_ResourceManager_GetRawFileCount(RawDir *rawDir)       | 获取指定rawfile目录下的rawfile文件数量。 |
| const char *OH_ResourceManager_GetRawFileName(RawDir *rawDir, int index) | 获取rawfile名字。                        |
| RawFile *OH_ResourceManager_OpenRawFile(const NativeResourceManager *mgr, const char *fileName) | 打开指定rawfile文件。                    |
| long OH_ResourceManager_GetRawFileSize(RawFile *rawFile)     | 获取rawfile文件大小。                    |
| int OH_ResourceManager_SeekRawFile(const RawFile *rawFile, long offset, int whence) | 指定rawfile内偏移量。                    |
| long OH_ResourceManager_GetRawFileOffset(const RawFile *rawFile) | 获取rawfile偏移量。                      |
| int OH_ResourceManager_ReadRawFile(const RawFile *rawFile, void *buf, size_t length) | 读取rawfile文件内容。                    |
| void OH_ResourceManager_CloseRawFile(RawFile *rawFile)       | 释放rawfile文件相关资源。                |
| void OH_ResourceManager_CloseRawDir(RawDir *rawDir)          | 释放rawfile目录相关资源。                |
| bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor) | 获取rawfile的fd。                        |
| bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor) | 释放rawfile的fd。                        |
| void OH_ResourceManager_ReleaseNativeResourceManager(NativeResourceManager *resMgr) | 释放native resource manager相关资源。    |

## 开发步骤

   以Js侧获取rawfile文件列表、rawfile文件内容、rawfile描述符{fd, offset, length}三种调用方式为例。

**1. 创建工程**

![创建C++应用](figures/rawfile1.png)

**2. 添加依赖**

创建完成后，IDE会在工程生成cpp目录，目录有libentry/index.d.ts、hello.cpp、CMakeLists.txt等文件。

1. 打开src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加资源的librawfile.z.so以及日志依赖libhilog_ndk.z.so

    ```c++
    target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so librawfile.z.so)
    ```

2. 打开src/main/cpp/types/libentry/index.d.ts文件，此文件声明了应用侧函数getFileList、getRawFileContent、getRawFileDescriptor。

    ```c++
    import resourceManager from '@ohos.resourceManager';
    export const getFileList: (resmgr: resourceManager.ResourceManager, path: string) => Array<String>;
    export const getRawFileContent: (resmgr: resourceManager.ResourceManager, path: string) => Uint8Array;
    export const getRawFileDescriptor: (resmgr: resourceManager.ResourceManager, path: string) => resourceManager.RawFileDescriptor;    
    ```

**3. 修改源文件**

1. 打开src/main/cpp/hello.cpp文件，文件Init会对当前方法进行初始化映射，这里定义对外接口为getFileList、getRawFileContent、getRawFileDescriptor，映射C++接口分别为GetFileList、GetRawFileContent、GetRawFileDescriptor。

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

2. 把src/main/cpp/hello.cpp文件中，增加对应的三个方法，如下所示

    ```c++
    static napi_value GetFileList(napi_env env, napi_callback_info info)
    static napi_value GetRawFileContent(napi_env env, napi_callback_info info)
    static napi_value GetRawFileDescriptor(napi_env env, napi_callback_info info)
    ```

3. 在hello.cpp文件中获取Js的资源对象，并转为Native的资源对象，即可调用资源的Native接口，获取rawfile列表、rawfile文件内容以及rawfile描述符{fd, offset, length}三种调用方式示例代码如下：

    ```c++
    // 示例一：获取rawfile文件列表 GetFileList
    static napi_value GetFileList(napi_env env, napi_callback_info info)
    {
        OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "NDKTest Begin");
        size_t requireArgc = 3;
        size_t argc = 2;
        napi_value argv[2] = { nullptr };
        // 获取参数信息
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

        // argv[0]即为函数第一个参数Js资源对象，OH_ResourceManager_InitNativeResourceManager转为Native对象。
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);

        // 获取函数argv[1]，此为为rawfile相对路径
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string dirName(strBuf, strSize);

        // 获取对应的rawDir指针对象
        RawDir* rawDir = OH_ResourceManager_OpenRawDir(mNativeResMgr, dirName.c_str());

        // 获取rawDir下文件及文件夹数量
        int count = OH_ResourceManager_GetRawFileCount(rawDir);

        // 遍历获取文件名称，并保存
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

        // 关闭打开的指针对象
        OH_ResourceManager_CloseRawDir(rawDir);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        return fileList;
    }

    // 示例二：获取rawfile文件内容 GetRawFileContent
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
        // 获取参数信息
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

        // argv[0]即为函数第一个参数Js资源对象，OH_ResourceManager_InitNativeResourceManager转为Native对象。
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string filename(strBuf, strSize);

        // 获取rawfile指针对象
        RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
        if (rawFile != nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "OH_ResourceManager_OpenRawFile success");
        }
        // 获取rawfile大小并申请内存
        long len = OH_ResourceManager_GetRawFileSize(rawFile);
        std::unique_ptr<uint8_t[]> data= std::make_unique<uint8_t[]>(len);
        // 读取rawfile
        int res = OH_ResourceManager_ReadRawFile(rawFile, data.get(), len);
        // 关闭打开的指针对象
        OH_ResourceManager_CloseRawFile(rawFile);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        // 转为js对象
        return CreateJsArrayValue(env, data, len);
    }

    // 示例三：获取rawfile文件描述符 GetRawFileDescriptor
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
        // 获取参数信息
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
        
        napi_valuetype valueType;
        napi_typeof(env, argv[0], &valueType);
        // 获取native的resourceManager对象
        NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
        size_t strSize;
        char strBuf[256];
        napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
        std::string filename(strBuf, strSize);
        // 获取rawfile指针对象
        RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
        if (rawFile != nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, tag, "OH_ResourceManager_OpenRawFile success");
        }
        // 获取rawfile的描述符RawFileDescriptor {fd, offset, length}
        RawFileDescriptor descriptor;
        OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
        // 关闭打开的指针对象
        OH_ResourceManager_CloseRawFile(rawFile);
        OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
        // 转为js对象
        return createJsFileDescriptor(env,descriptor);
    }
    ```

**4. Js侧调用**

1. 打开src\main\ets\pages\index.ets, 导入"libentry.so";

2. 获取当前js的resourceManager对象;
    
3. 调用Native接口getFileList即为src/main/cpp/types/libentry/index.d.ts中声明的接口，传入js的资源对象，以及rawfile文件夹的相对路径。示例如下:

    ```js
    import hilog from '@ohos.hilog';
    import testNapi from 'libentry.so'  // 导入so
    @Entry
    @Component
    struct Index {
        @State message: string = 'Hello World'
        private resmgr = getContext().resourceManager;  // 获取js的资源对象
        build() {
            Row() {
            Column() {
                Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                    hilog.isLoggable(0x0000, 'testTag', hilog.LogLevel.INFO);
                    let rawfilelist = testNapi.getFileList(this.resmgr, ""); //传入资源对象，以及访问的rawfile文件夹名称
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

## 函数介绍

1. 根据NativeResourceManager实例，使用OH_ResourceManager_OpenRawDir接口获取RawDir实例。

    ```c++
    RawDir* rawDir = OH_ResourceManager_OpenRawDir(nativeResourceManager, path.c_str());
    ```
    
2. 根据RawDir实例，使用OH_ResourceManager_GetRawFileCount接口获取对应目录下的rawfile文件总数 。

    ```c++
    int count = OH_ResourceManager_GetRawFileCount(rawDir);
    ```
    
3. 根据RawDir实例，使用OH_ResourceManager_GetRawFileName接口获取目录下对应index的rawfile文件名。

    ```c++
    for (int index = 0; index < count; index++) {
        std::string fileName = OH_ResourceManager_GetRawFileName(rawDir, index);
    }
    ```

4. 根据NativeResourceManager实例，使用OH_ResourceManager_OpenRawFile接口获取指定文件名的RawFile实例

    ```c++
    RawFile* rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, fileName.c_str());
    ```
    
5. 根据RawFile实例，使用OH_ResourceManager_GetRawFileSize接口获取对应rawfile文件大小。

    ```c++
    long rawFileSize = OH_ResourceManager_GetRawFileSize(rawFile);
    ```

6. 根据RawFile实例，使用OH_ResourceManager_SeekRawFile接口指定rawfile偏移量。

    ```c++
    int position = OH_ResourceManager_SeekRawFile(rawFile, 10, 0);
    int position = OH_ResourceManager_SeekRawFile(rawFile, 0 , 1);
    int position = OH_ResourceManager_SeekRawFile(rawFile, -10, 2);
    ```

7. 根据RawFile实例，使用OH_ResourceManager_GetRawFileOffset接口获取rawfile偏移量。

    ```c++
    long rawFileOffset = OH_ResourceManager_GetRawFileOffset(rawFile)
    ```

8. 根据RawFile实例，使用OH_ResourceManager_ReadRawFile接口读取rawfile文件内容。

    ```c++
    std::unique_ptr<char[]> mediaData = std::make_unique<char[]>(rawFileSize);
    long rawFileOffset = OH_ResourceManager_ReadRawFile(rawFile, mediaData.get(), rawFileSize);
    ```

9. 根据RawFile实例，使用OH_ResourceManager_CloseRawFile接口释放rawfile文件相关资源。

    ```c++
    OH_ResourceManager_CloseRawFile(rawFile);
    ```

10. 根据RawDir实例，使用OH_ResourceManager_CloseRawDir接口释放rawfile目录相关资源。

    ```c++
    OH_ResourceManager_CloseRawDir(rawDir);
    ```

11. 根据RawFile实例，使用OH_ResourceManager_GetRawFileDescriptor接口获取rawfile的RawFileDescriptor。

    ```c++
    RawFileDescriptor descriptor;
    bool result = OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
    ```

12. 根据RawFileDescriptor实例，使用OH_ResourceManager_ReleaseRawFileDescriptor接口关闭rawfile的fd。

    ```c++
    OH_ResourceManager_ReleaseRawFileDescriptor(descriptor);
    ```

13. 根据NativeResourceManager实例，使用OH_ResourceManager_ReleaseNativeResourceManager接口释放native resource manager。

    ```c++
    OH_ResourceManager_ReleaseNativeResourceManager(nativeResourceManager);
    ```

