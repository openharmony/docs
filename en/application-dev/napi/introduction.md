# Introduction to Native APIs

Native APIs are a set of native development interfaces and tools provided by the OHOS SDK. It enables the use of C or C++ code to implement key application functionalities. Native APIs provide part of basic underlying capabilities of OHOS, such as libc, graphics library, window system, multimedia, and compression library. They do not provide complete OHOS platform capabilities as JS APIs do. Native APIs are compiled into a dynamic library before being packed into the application.

## Native API Composition

### Native API Directory Structure

Native APIs are stored in the **$(SDK_ROOT)/native** directory of the SDK. They consist of the following parts:

|Directory|Description|
|--|--|
|build|Used to build the toolchain.cmake script of the dynamic library in the application. The **ohos.toolchain.cmake** file in this directory defines OHOS cross compilation options.|
|build-tools|Stores build tools, such as CMake.|
|docs|Stores Native API reference documents, which is extracted from the header files using Doxgen.|
|llvm|Stores LLVM, a cross compiler that supports OHOS ABIs.|
|sysroot|Stores dependent files of build links, including header files and dynamic libraries.|

### Native APIs

|Category|Function|Introduced In|
|--|--|--|
|C standard library|C standard library interfaces based on musl. Currently, more than 1500 interfaces are provided.|API version 8|
|C++ standard library|C++ runtime library libc++_shared. This library must be packed or statically linked to the application during packing.|API version 8|
|Log|HiLog interfaces for printing logs to the system|API version 8|
|napi|A group of Node-APIs provided by ArkUI to facilitate access to the JS application environment during application development. Node-APIs are part of native APIs.|API version 8|
|XComponent|Provides surface and touchscreen event interfaces for developing high-performance graphics applications.|API version 8|
|libuv|Third-party asynchronous I/O library integrated by ArkUI.|API version 8|
|libz|zlib library that provides basic compression and decompression interfaces.|API version 8|
|Drawing|2D graphics library that can be used for drawing on the surface.|API version 8|
|OpenGL|OpenGL 3.0 interfaces.|API version 8|
|Rawfile|Application resource access interfaces that can be used to read various resources packed in the application.|API version 8|
|OpenSLES|Interface library used for 2D and 3D audio acceleration.|API version 8|
|Mindspore|AI model interface library.|API version 9|
|Bundle management|Bundle service interfaces that can be used to query bundle information of the application.|API version 8|

Some native APIs use open-source standards. For details, see [Native Standard Libraries Supported by OpenHarmony](../reference/native-lib/third_party_libc/musl.md) and [Node-API](../reference/native-lib/third_party_napi/napi.md).

## Usage Guidelines

### Scenarios Where Native APIs Are Recommended

You can use native APIs when you want to:

1. Develop performance-sensitive code in computing-intensive scenarios such as gaming and physical simulation.
2. Reuse the existing C or C++ library.
3. Customize libraries related to CPU features, such as neon acceleration.

### Scenarios Where Native APIs Are Not Recommended<br>You do not need to use native APIs when you want to:

1. Write a native OHOS application.
2. Develop an application compatible on as many OHOS devices as possible.
