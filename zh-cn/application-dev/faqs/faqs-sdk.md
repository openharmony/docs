# SDK使用常见问题

## cmake中arm64-v8a/armeabi-v7a这层目录的宏定义是什么

适用于：OpenHarmony 3.1 Beta5  API 9

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

访问到目录的宏定义为：\$\{CMAKE\_CURRENT\_SOURCE\_DIR\}/../../../libs/$\{OHOS\_ARCH\}/xxxx.so

CMAKE\_CURRENT\_SOURCE\_DIR：CMakeList.txt文件所在目录。

OHOS\_ARCH：设置应用程序二进制接口ABI，类型为 armeabi-v7a、arm64-v8a，默认值是 arm64-v8a。

**使用示例**

CMakeLists.txt 中添加链接库。

```
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/libMyDemo.so
)
```

