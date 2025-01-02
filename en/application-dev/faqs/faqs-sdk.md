# SDK Usage


## What is the macro definition of the arm64-v8a/armeabi-v7a directory in CMake? (API version 9)

**Solution**

The **arm64-v8a** and **armeabi-v7a** directories are as follows:

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

The macro for accessing the directory is **${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/xxxx.so**.

**CMAKE_CURRENT_SOURCE_DIR**: directory where the **CMakeList.txt** file is stored.

**OHOS_ARCH**: type of the application binary interface (ABI). The value can be **armeabi-v7a** or **arm64-v8a**. The default value is **arm64-v8a**.

**Example**

Add the link library to **CMakeLists.txt**.

```
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/libMyDemo.so
)
```


## What should I do if an error is reported when OH_LOG_Print in the native code is used to print logs? (API version 9)

**Problem**

When **OH\_LOG\_Print** is used in the native code to print logs, the following error is reported: **undefined symbol: OH_LOG_Print**.

**Cause**

The link library file is missing.

**Solution**

Open the **CMakeLists.txt** file and append **libhilog_ndk.z.so** to the end of **target_link_libraries**.

```
set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
)
```


## How do I traverse files in rawfile? (API version 9)

**Solution**

Use the **OH_ResourceManager_OpenRawDir()** native API to obtain the root directory of **rawfile** and traverse the root directory.

**Reference**

[Rawfile](../reference/apis-localization-kit/rawfile.md)
