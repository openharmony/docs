# SDK Usage

## What is the macro definition of the arm64-v8a/armeabi-v7a directory in CMake?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

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

The macro for accessing the directory is **\$\{CMAKE\_CURRENT\_SOURCE\_DIR\}/../../../libs/$\{OHOS\_ARCH\}/xxxx.so**.

**CMAKE\_CURRENT\_SOURCE\_DIR**: directory where the **CMakeList.txt** file is stored.

**OHOS\_ARCH**: type of the application binary interface (ABI). The value can be **armeabi-v7a** or **arm64-v8a**. The default value is **arm64-v8a**.

**Example**

Add the link library to **CMakeLists.txt**.

```
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../libs/${OHOS_ARCH}/libMyDemo.so
)
```

