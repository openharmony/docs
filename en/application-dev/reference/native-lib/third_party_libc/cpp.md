
# libc++

OpenHarmony uses [libc++](https://libcxx.llvm.org/) of the open-source LLVM project as its C++ runtime library.

## libc++ Version

From OpenHarmony 4.0, libc++ is upgraded to Clang/LLVM 15.0.4.

From OpenHarmony 3.2, libc++ is upgraded to Clang/LLVM 12.0.1.

From OpenHarmony 3.0, libc++ uses Clang/LLVM 10.0.1.

## Support for C++ Capabilities

The C++11 and C++14 standards are supported, and the C++17 and C++20 standards are on the way. For details about the standards supported, see the corresponding Release Notes at [https://libcxx.llvm.org/](https://libcxx.llvm.org/).


## Selecting libc++ in CMake

In the **{ndk_root}/build/cmake/ohos.toolchain.cmake** file of the NDK, the **OHOS_STL** variable specifies the mode, in which the native library links the C++ runtime library. The **OHOS_STL** can be set to any of the following values:
* **c++_shared**: The native library dynamically links **libc++_shared.so**.
* **c++_static**: The native library links the static library **libc++_static.a**.

## Precautions

1. In an application project, the native library can be linked to the C++ runtime library in only one mode. The C++ runtime library has many global variables and states. Using the two modes in a project may cause coexistence of multiple states, which result in C++ runtime exceptions.

2. Prevent the application binary interface (ABI) compatibility issues. In OpenHarmony, both the system library and application native library use the libc++. However, the two libc++ libraries are different. The libc++ of the system library is updated with the system image version, while the libc++ of the application native library is updated with the version of the SDK used for build. The two libc++ libraries may be different from multiple major versions, which causes ABI compatibility issues. To solve this problem, OpenHarmony differentiates the two libc++ libraries as follows:

    * System library: uses **libc++.so**, which is released with the system image.
    * Application native library: uses **libc++_shared.so**, which is released with the application.

   The two libc++ libraries use different namespaces. **libc++_shared.so** uses **__n1** as the namespace for C++ symbols, and **libc++.so** uses **__h** for C++ symbols.

   > **CAUTION**
   >
   > The system library cannot use the libc++ of the application native library, and vice versa. Currently, the Native APIs must be C interfaces only, which isolates the two libc++ runtime environments.
