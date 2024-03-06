# Native API Introduction

Native APIs, also called Native Develop Kit (NDK), are a set of native interfaces and tools provided by the OpenHarmony SDK for implementing key application features by using C or C++. Different from JS APIs, the Native APIs provide only part of underlying capabilities of OpenHarmony, such as the libc, graphics library, window system, multimedia, and compression library. The Native APIs will be build as a dynamic library before being packaged into an application.

## Concepts

|Term|Description|
|--|--|
|Native API|Native interfaces, build scripts, and compiler toolchains provided by the **native** package in the OpenHarmony SDK for third-party application development. Native APIs include the C runtime libc, 3D graphics library **OpenGL**, and Node-APIs for cross-language programming between JS and C.|
|NDK|Native Develop Kit (NDK) that provides the Native APIs in OpenHarmony. NDK is the equivalent of Native API. Native API is the official name.|
|SDK CAPI|C interfaces and toolchains in OpenHarmony Native APIs.<br/>Currently, OpenHarmony Native APIs contain only C interfaces. Therefore, Native API is CAPI. However, you are advised to use CAPI.|
|Node-API|Native interfaces that implement cross-language invocation between C and JS. Node-API is formerly called napi. Although OpenHarmony Node-APIs are extension of the Node-APIs provided by **Node.js**, they are not fully compatible with the Node-APIs in **Node.js**.|
|napi|Former name of Node-API. It is not used because it may be interpreted as Native API or Node-API by mistake. Currently, the interfaces in the Node-API header files still start with **napi_**.|

## Native API Composition

### Native API Directory Structure

Native APIs are stored in the **$(SDK_ROOT)/native** directory of the SDK.

|Directory|Description|
|--|--|
|build|Provides the toolchain cmake script used to build the dynamic library of an application. The **ohos.toolchain.cmake** file in this directory defines OpenHarmony cross-compilation options.|
|build-tools|Provides build tools, such as CMake.|
|docs|Provides Native API reference documents, which are extracted from the header files using Doxgen.|
|llvm|Provides the LLVM, a cross compiler that supports the OpenHarmony Application Binary Interface (ABI).|
|sysroot|Provides dependencies of links, including header files and dynamic libraries.|

### Native APIs

|Category|Description|Introduced Since Version|
|--|--|--|
|[C standard library](native-lib/third_party_libc/musl.md)|Provides more than 1500 libc interfaces based on musl.|8|
|[C++ standard library](native-lib/third_party_libc/cpp.md)|Provides the libc++_shared library for C++ runtime. This library must be packed or statically linked to the application during packing.|8|
|Log|Provides HiLog interfaces for printing logs to the system.|8|
|Node-API|Provides APIs like Node-APIs (also called napis) for accessing the JS application environment. Node-APIs are provided by ArkUI and are part of Native APIs.|8|
|XComponent|Provides Surface and touchscreen event interfaces for developing high-performance graphics applications on ArkUI.|8|
|libuv|Provides a third-party asynchronous I/O library integrated by ArkUI.|8|
|libz|Provides basic compression and decompression interfaces.|8|
|Drawing|Provides a 2D graphics library for drawing on Surface.|8|
|OpenGL|Provides OpenGL 3.0 interfaces.|8|
|Rawfile|Provides application resource access interfaces for reading various resources packed in applications.|8|
|OpenSLES|Provides interfaces for 2D and 3D audio acceleration.|8|
|Mindspore|Provides AI model interfaces.|9|
|Bundle management|Provides bundle service interfaces for querying bundle information of applications.|8|

### Native API Documents

* [Native API Reference](native-apis/_o_h___native_x_component.md): provides reference for Native APIs.
* [Standard Libraries Supported by Native APIs](../reference/native-lib/third_party_libc/musl.md): describes the open-source standard libraries supported by Native APIs.
* [Native API Development](../napi/napi-guidelines.md): describes how to use Native APIs.
* [Using NDK to Build a CMake C/C++ Project](../faqs/cmake-with-ndk.md): describes how to use Native APIs to develop a CMake project.
* [Using Node-APIs in Application Projects](../napi/napi-guidelines.md): describes how to use Node-APIs.

## How to Use

### Recommended Use of Native APIs

Use Native APIs when you want to:

1. Develop performance-sensitive code in computing-intensive scenarios, such as gaming and physical simulation.
2. Reuse the existing C or C++ library.
3. Customize libraries related to CPU features, such as neon acceleration.

### Use of Native APIs Not Recommended

Do not use Native APIs when you want to:

1. Develop a pure OpenHarmony application.
2. Develop an application that is compatible on as many OpenHarmony devices as possible.

## Debugging Capabilities

1. OpenHarmony provides remote code debugging by using the low-level Debugger (LLDB). For details, see [LLDB](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README_en.md).
2. OpenHarmony provides the log debugging for the musl library. For details, see "Debugging Capabilities" in [libc](./native-lib/third_party_libc/musl.md).

 <!--no_check--> 