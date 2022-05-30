# Rawfile开发指导

 

## 场景介绍

开发者可以通过本指导了解在OpenHarmony应用中，如何使用Rawfile Native接口操作Rawfile目录和文件。功能包括遍历、打开、搜索、读取和关闭Rawfile。

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

1. 添加头文件。

    ```c++
    #include "raw_file_manager.h"
    ```
    
    

2. 使用OH_ResourceManager_InitNativeResourceManager(napi_env env, napi_value jsResMgr)接口获取NativeResourceManager实例。

    ```js
    // js侧传递js resource manager。
    import resManager from '@ohos.resourceManager'
    import rawfileTest from 'librawFileTest.so'
    resManager.getResourceManager().then(resmgr => {
        rawfileTest.testRawFile("test", resmgr, (error, value) => {
            console.log("test rawFile");
        })
    });
    ```

    ```c++
    // C++侧获取解析js侧传递的参数。
    NativeResourceManager* nativeResourceManager = nullptr;
    std::string path;
    if (i == 0 && valueType == napi_string) {
        // 解析第一个参数，参数为相对rawfile目录的文件/目录路径。
        ......
        path = buf.data();
    } else if (i == 1 && valueType == napi_object) {
        // 解析第二个参数，参数为js resource manager。
        nativeResourceManager = OH_ResourceManager_InitNativeResourceManager(env, argv[i]);
    }
    ```

    

3. 根据NativeResourceManager实例，使用OH_ResourceManager_OpenRawDir接口获取RawDir实例。

    ```c++
    RawDir* rawDir = OH_ResourceManager_OpenRawDir(nativeResourceManager, path.c_str());
    ```
    
    
    
4. 根据RawDir实例，使用OH_ResourceManager_GetRawFileCount接口获取对应目录下的rawfile文件总数 。

    ```c++
    int count = OH_ResourceManager_GetRawFileCount(rawDir);
    ```
    
    
    
5. 根据RawDir实例，使用OH_ResourceManager_GetRawFileName接口获取目录下对应index的rawfile文件名。

    ```c++
    for (int index = 0; index < count; index++) {
        std::string fileName = OH_ResourceManager_GetRawFileName(rawDir, index);
    }
    ```

    

6. 根据NativeResourceManager实例，使用OH_ResourceManager_OpenRawFile接口获取指定文件名的RawFile实例

    ```c++
    RawFile* rawFile = OH_ResourceManager_OpenRawFile(nativeResourceManager, fileName.c_str());
    ```
    
    
    
7. 根据RawFile实例，使用OH_ResourceManager_GetRawFileSize接口获取对应rawfile文件大小。

    ```c++
    long rawFileSize = OH_ResourceManager_GetRawFileSize(rawFile);
    ```
    
    

8. 根据RawFile实例，使用OH_ResourceManager_SeekRawFile接口指定rawfile偏移量。

    ```c++
    int position = OH_ResourceManager_SeekRawFile(rawFile, 10, 0);
    int position = OH_ResourceManager_SeekRawFile(rawFile, 0 , 1);
    int position = OH_ResourceManager_SeekRawFile(rawFile, -10, 2);
    ```
    
    

9. 根据RawFile实例，使用OH_ResourceManager_GetRawFileOffset接口获取rawfile偏移量。

    ```c++
    long rawFileOffset = OH_ResourceManager_GetRawFileOffset(rawFile)
    ```
    
    

10. 根据RawFile实例，使用OH_ResourceManager_ReadRawFile接口读取rawfile文件内容。

    ```c++
    std::unique_ptr<char[]> mediaData = std::make_unique<char[]>(rawFileSize);
    long rawFileOffset = OH_ResourceManager_ReadRawFile(rawFile, mediaData.get(), rawFileSize);
    ```

    

11. 根据RawFile实例，使用OH_ResourceManager_CloseRawFile接口释放rawfile文件相关资源。

    ```c++
    OH_ResourceManager_CloseRawFile(rawFile);
    ```
    
    

12. 根据RawDir实例，使用OH_ResourceManager_CloseRawDir接口释放rawfile目录相关资源。

    ```c++
    OH_ResourceManager_CloseRawDir(rawDir);
    ```
    
    

13. 根据RawFile实例，使用OH_ResourceManager_GetRawFileDescriptor接口获取rawfile的RawFileDescriptor。

    ```c++
    RawFileDescriptor descriptor;
    bool result = OH_ResourceManager_GetRawFileDescriptor(rawFile, descriptor);
    ```

    

14. 根据RawFileDescriptor实例，使用OH_ResourceManager_ReleaseRawFileDescriptor接口关闭rawfile的fd。

    ```c++
    OH_ResourceManager_ReleaseRawFileDescriptor(descriptor);
    ```



15. 根据NativeResourceManager实例，使用OH_ResourceManager_ReleaseNativeResourceManager接口释放native resource manager。

    ```c++
    OH_ResourceManager_ReleaseNativeResourceManager(nativeResourceManager);
    ```

