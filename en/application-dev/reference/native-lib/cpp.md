
# libc++

OpenHarmony uses [libc++](https://libcxx.llvm.org/) of the open-source LLVM project as its C++ runtime library.

## libc++ Version

- Clang/LLVM 15.0.4 from OpenHarmony 4.0

- Clang/LLVM 12.0.1 from OpenHarmony 3.2

- Clang/LLVM 10.0.1 from OpenHarmony 3.0


## Support for C++ Capabilities

The C++11 and C++14 standards are supported, and the C++17 and C++20 standards are on the way. For details about the standards supported, see the corresponding Release Notes at [https://libcxx.llvm.org/](https://libcxx.llvm.org/).


## Selecting libc++ in CMake

In the **{ndk_root}/build/cmake/ohos.toolchain.cmake** file of the NDK, the **OHOS_STL** variable specifies the mode, in which the native library links the C++ runtime library. The **OHOS_STL** can be set to any of the following values:
* **c++_shared**: The native library dynamically links **libc++_shared.so**.
* **c++_static**: The native library links the static library **libc++_static.a**.

## C++ Runtime Compatibility

In OpenHarmony, both the system library and the application native library use libc++. However, the upgrade pace of the two libraries is different, and the dependent C++ runtime versions may be different. The libc++ of the system library is updated with the image version, while the libc++ of the application native library is updated with the version of the SDK used for compilation. The two libc++ libraries may be different from multiple major versions, which causes Application Binary Interface (ABI) compatibility issues. To solve this problem, OpenHarmony differentiates the two libc++ libraries as follows:

    * System library: uses **libc++.so**, which is released with the system image.
    * Application native library: uses **libc++_shared.so**, which is released with the application.

The two libc++ libraries use different namespaces. **libc++_shared.so** uses **__n1** as the namespace for C++ symbols, and **libc++.so** uses **__h** for C++ symbols.

   > **NOTE**<br>The system library cannot use the libc++ of the application native library, and vice versa. Currently, the Native APIs must be C interfaces only. This also isolates the two libc runtime environments.

## Precautions

- The upgrade of the C++ runtime library toolchain to a major version does not ensure ABI compatibility. If an application package has multiple dynamic libraries, these dynamic libraries must be compiled using the Clang toolchain of the same major version and depend on the libc++_shared library of the same version. Otherwise, unpredictable errors may occur.

- If there is only one shared library in your application project, you are advised to use **c++_static**, which simplifies the C++ runtime code run by the linker and reduces the package size. Dynamic linking of libc++ is recommended if there are multiple libraries in your project, the dependency is a HAR package of a dynamic library, or there are binary .so packages in the OHPM library. Static linking may cause multiple copies of a function or an object defined in an application, which violates the One Definition Rule of C++.
