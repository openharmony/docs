# Getting Started with the NDK

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


### Basic NDK Concepts

- **[Node-API](napi-introduction.md)**

  Node-API, formerly called NAPI, is a set of interfaces provided for you to use C and C++ code with OpenHarmony ArkTS/JS. It is a part of NDK interfaces. Although extended from Node-API provided by Node.js, OpenHarmony Node-API is not fully compatible with it.

- **C API**

  C API is a former name of OpenHarmony NDK and is no longer used.


### Preparatory Knowledge

- Linux C programming knowledge
  The kernel and libc are extended based on standards such as POSIX. Mastering basic Linux C programming knowledge can help you better understand OpenHarmony development with the NDK.

- CMake
  CMake is the default build system of OpenHarmony. For details about how to use CMake, see [CMake Tutorial](https://cmake.org/cmake/help/v3.16/guide/tutorial/).

- Node addons
  ArkTS uses Node-API as the cross-language invoking interface. Familiarity with the basic [node addons](https://nodejs.org/api/addons.html) helps you better understand how to use Node-API in the NDK.

- Clang/LLVM
  Basic knowledge of the Clang or LLVM compiler helps you compile better native dynamic libraries.


### NDK Directory Structure

- **build** folder: contains the predefined toolchain script **ohos.toolchain.cmake**.

  ![](figures/en_image_0000001770128125.png)

  During compilation, CMake locates the file through **CMAKE_TOOLCHAIN_FILE** and reads the default values in this file, such as the compiler architecture and C++ library link mode.

- **build-tools** folder: contains the build tools provided by the NDK.
  ```
  # Check the CMake version.
  cmake -version
  # The version information is displayed.
  cmake version 3.16.5
  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

- **llvm** folder: contains the compilers provided by the NDK.

  ![en_image_0000001696408864](figures/en_image_0000001696408864.png)


## Common NDK Modules

The following table describes the common modules of the NDK.


| Module| Description| 
| -------- | -------- |
| C standard library| Provides C standard library interfaces based on musl.| 
| C++ standard library| Provides libc++_shared, a C++ runtime library.| 
| Log| Prints logs to the HiLog interface of the system.| 
| Node-API | Acts as an intermediary between ArkTS/JS and C/C++.| 
| FFRT | Provides a task-based concurrent programming framework.| 
| libuv | Provides a third-party asynchronous I/O library.| 
| zlib | Provides basic data compression and decompression interfaces.| 
| Rawfile | Provides interfaces for reading various packaged resources of an application.| 
| XComponent | Provides surface and touchscreen event interfaces for you to develop high-performance graphics applications.| 
| Drawing | Provides a 2D graphics library for drawing on the surface.| 
| OpenGL | Provides OpenGL 3D graphics interfaces.| 
| OpenSL ES | Provides interfaces for 2D and 3D audio acceleration.| 
