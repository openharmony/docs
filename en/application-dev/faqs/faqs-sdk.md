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

## What should I do if an error is reported when OH\_LOG\_Print in the native code is used to print logs?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

**Problem**

When **OH\_LOG\_Print** is used in the native code to print logs, the following error is reported: **undefined symbol: OH\_LOG\_Print**.

**Cause**

The link library file is missing.

**Solution**

Open the **CMakeLists.txt** file and append **libhilog\_ndk.z.so** to **target\_link\_libraries**.

```
set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entry PUBLIC
    libace_napi.z.so
    libhilog_ndk.z.so
)
```

## How do I traverse files in rawfile?

Applicable to: OpenHarmony 3.1 Beta 5 (API version 9)

**Solution**

Use the **OH\_ResourceManager\_OpenRawDir\(\)** native API to obtain the root directory of **rawfile** and traverse the root directory.

**Reference**

[Rawfile](../reference/native-apis/rawfile.md)