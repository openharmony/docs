# SDK使用常见问题


## cmake中arm64-v8a/armeabi-v7a这层目录的宏定义是什么(API 9)

**解决方案**

arm64-v8a及armeabi-v7a目录如下所示：

```
entry
├─ libs
│    ├─ arm64-v8a
│    │    └─ libMyDemo.so
│    └─ armeabi-v7a
│         └─ libMyDemo.so
└─ src
     └─ main
          └─ cpp
               └─ CMakeLists.txt
```

访问到目录的宏定义为：${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/xxxx.so

CMAKE_CURRENT_SOURCE_DIR：CMakeList.txt文件所在目录。

OHOS_ARCH：设置应用程序二进制接口ABI，类型为 armeabi-v7a、arm64-v8a，默认值是 arm64-v8a。

**使用示例**

CMakeLists.txt 中添加链接库。

```
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/libMyDemo.so
)
```


## 在Native代码中使用OH_LOG_Print打印日志报错(API 9)

**问题现象**

在Native代码中使用OH_LOG_Print打印日志，上报错误：undefined symbol: OH_LOG_Print

**原因分析**

缺少链接库文件。

**解决措施**

打开CMakeLists.txt文件，在target_link_libraries最后追加libhilog_ndk.z.so。

```
set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
)
```


## 如何遍历rawfiles中的文件(API 9)

**解决方案：**

使用Native API中的OH_ResourceManager_OpenRawDir()方法获取到rawfile的根目录，然后对其进行遍历。

**参考文档：**

[Native开发指导](../reference/apis-localization-kit/rawfile.md)

