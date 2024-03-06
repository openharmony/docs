# NDK Project Building Overview


By default, the OpenHarmony NDK uses CMake as the build system. To simplify your configuration process, the NDK provides the configuration file [ohos.toolchain.cmake](#introduction-to-ohostoolchaincmake) that complies with the OpenHarmony toolchain to predefine CMake variables.


You can build your project with the NDK in the following modes:


- Build from source code

  To build from source code, you can use:

  - [C++ application template provided by DevEco Studio](build-with-ndk-ide.md)
  - [CMake from the command line](build-with-ndk-cmake.md)

- [Build with prebuilt libraries](build-with-ndk-prebuilts.md)


This section uses examples to describe how to use the NDK in a native project and how to write a CMake script to build a project with the NDK.


## Introduction to ohos.toolchain.cmake

**ohos.toolchain.cmake** is the toolchain script provided by the OpenHarmony NDK for CMake. It predefines the build parameters that need to be set for building OpenHarmony applications, such as the target of the cross compilation device and the link mode of C++ runtime libraries. These parameters can be passed in by running CMake commands to change the default compilation and linking behavior. The following table lists the common parameters in this file.

| Name| Type| Description|
| -------- | -------- | -------- |
| OHOS_STL | c++_shared/c++_static | Link mode of libc++.<br> Default value: **c++_shared**<br>Available options are as follows:<br>**c++_shared**: The native library dynamically links **libc++_shared.so**.<br>**c++_static**: The native library links the static library **libc++_static.a**.<br>Because some global variables are involved during C++ runtime, all native libraries must be linked to your application in the same mode.|
| OHOS_ARCH | armeabi-v7a/arm64-v8a/x86_64 | Target architecture for native cross compilation. Available options are as follows: **armeabi-v7a**, **arm64-v8a**, and **x86_64**.|
| OHOS_PLATFORM | OHOS | Target platform. Currently, only OpenHarmony is supported.|

The preceding parameters control the cross compilation commands of Clang and generate proper command parameters.

- The **--target={arch}-linux-ohos** parameter instructs the compiler to generate binary files that comply with OpenHarmony ABI in the corresponding architecture.

- The **--sysroot={ndk_root}/sysroot** parameter notifies the compiler of the location of the OpenHarmony header files.
