
# libc++

Currently, OpenHarmony uses the C++ standard library [(libc++)](https://libcxx.llvm.org/) of the LLVM project.

## Version

From OpenHarmony 3.0, libc++ uses Clang/LLVM 10.0.1.

From OpenHarmony 3.2, libc++ is upgraded to Clang/LLVM 12.0.1.

From OpenHarmony 4.0, libc++ is upgraded to Clang/LLVM 15.0.4.

## Supported Capabilities

The C++11 and C++14 standards are supported, and the C++17 and C++20 standards are on the way. For details about the standards supported by language features, see the corresponding Release Notes at [https://libcxx.llvm.org/](https://libcxx.llvm.org/).

## ABI Compatibility
In OpenHarmony, both the system library and application native library use the libc++. However, the two libc++ are different. The libc++ of the system library is updated with the image version, while the libc++ of the application native library is updated with the SDK version used for compilation. Both the libc++ libraries cross multiple major versions, which may cause Application Binary Interface (ABI) compatibility issues. To solve this problem, OpenHarmony differentiates the libc++ libraries as follows:
  * System library: uses **libc++.so**, which is released with the system image.
  * Application native library: uses **libc++_shared.so**, which is released with the application.

The two libc++ libraries use different namespaces. **libc++_shared.so** uses **__n1** as the namespace for C++ symbols, and **libc++.so** uses **__h** as the namespace for C++ symbols.

> **CAUTION**
>
> Currently, the Native API supports C only. The system library can use any programming language.

<!--no_check-->