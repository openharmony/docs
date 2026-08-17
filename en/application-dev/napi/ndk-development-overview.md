# About This Kit

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @liyiming13-->
<!--Designer: @huang_huijin-->
<!--Tester: @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=fa3fc214ef4b265f033bc3f0d0a2df54f511a497 translatedAt=2026-08-12T06:28:16.205Z pushedAt=2026-08-12T12:02:10.234Z -->

The Native Development Kit (NDK) is a toolset that allows you to use C and C++ code with OpenHarmony. As a subset of OpenHarmony SDK, it provides native APIs, compile scripts, and compile toolchain to help you implement key application features using C or C++. The NDK covers only some basic underlying capabilities of OpenHarmony, such as the C runtime libc, graphics library, window system, multimedia, compression library, and Node-API that bridges ArkTS/JS and C code. It does not provide complete capabilities of ArkTS/JS APIs.

You can use Node-API in the NDK to access, create, and operate JS objects, and use native dynamic libraries in JS objects.

## Use Scenarios

The NDK can be helpful for the cases in which you need to:

- Increase performance in compute-intensive cases, such as games or physical simulations.

- Reuse existing C or C++ libraries.

- Customize a library based on CPU features, for example, performing Neon acceleration.

You are not advised to use the NDK to develop the following:

- C or C++ applications

- Applications that can run on a wide variety of OpenHarmony devices

## NDK Basics

Before getting started, familiarity with the following basics is helpful.

### Preparatory Knowledge

- Linux C programming knowledge

  The kernel and libc base libraries are extended from standards such as POSIX. Mastering basic Linux C programming knowledge helps you better understand OpenHarmony NDK development.

- CMake

  CMake is the default build system of OpenHarmony. For details about how to use CMake, see [CMake Tutorial](https://cmake.org/cmake/help/v3.16/guide/tutorial/).

- Node addons

  ArkTS uses Node-API as the cross-language invocation interface. Familiarity with basic [Node Addon development patterns](https://nodejs.org/api/addons.html) helps you better understand how Node-API is used in the NDK.

- Clang/LLVM

  Basic knowledge of the Clang or LLVM compiler helps you compile better native dynamic libraries.

- **[Node-API](napi-introduction.md)**

  Node-API, formerly called NAPI, is a set of APIs provided for you to use C and C++ code with OpenHarmony ArkTS/JS. Node-API is an extension of Node-API in Node.js but is not fully compatible.

### NDK Directory Structure

For details about how to obtain the NDK, see <!--RP1-->[Downloading the NDK Development Package](build-with-ndk-cmake.md#downloading-the-ndk-development-package)<!--RP1End-->.

- **build** directory: stores the predefined toolchain script file <!--RP2-->[ohos.toolchain.cmake](build-with-ndk-overview.md#introduction-to-ohostoolchaincmake).<!--RP2End-->

  ![ndk-build-structure](figures/ndk-build-structure.png)

  During compilation, CMake locates the file through **CMAKE_TOOLCHAIN_FILE** and reads the default values in this file, such as the compiler architecture and C++ library link mode.

- **build-tools** folder: contains the build tools provided by the NDK.

  ```shell
  # Check the CMake version.
  cmake -version
  # The version information is displayed.
  cmake version 3.16.5
  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

- **llvm** folder: contains the compilers provided by the NDK.

  ![ndk-tools-list](figures/ndk-tools-list.png)

## Common NDK Modules

The following table describes the common modules of the NDK and their functionalities.

| Module| Description|
| -------- | -------- |
| C standard library| Provides C standard library APIs based on musl.|
| C++ standard library| Provides the C++ runtime APIs.|
| Log| Provides APIs for outputting HiLog logs to the system.|
| Node-API | Provides APIs for interaction between ArkTS/JS and C/C++.|
| FFRT | Provides a task-based concurrent programming framework.|
| libuv | Provides a third-party asynchronous I/O library.|
| zlib | Provides the zlib library for basic data compression and decompression.|
| Rawfile | Provides APIs for reading various packaged resources of an application.|
| XComponent | Provides surface and touchscreen event APIs for you to develop high-performance graphics applications.|
| Drawing | Provides a 2D graphics library for drawing on the surface.|
| OpenGL | Provides OpenGL 3D graphics interfaces.|
| OpenSL ES | Provides APIs for 2D and 3D audio acceleration.|