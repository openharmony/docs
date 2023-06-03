
# 标准C++库

OpenHarmony当前使用的是llvm项目的C++标准库实现[libc++](https://libcxx.llvm.org/)。

## 版本

从OpenHarmony 3.0开始，libc++使用clang/llvm 10.0.1版本

从OpenHarmony 3.2开始，libc++升级到clang/llvm 12.0.1版本

从OpenHarmony 4.0开始，libc++升级到clang/llvm 15.0.4版本

## 支持的能力

C++11、C++14标准已完全支持，C++17和C++20标准正在完善。具体语言特性支持标准可以参考[https://libcxx.llvm.org/](https://libcxx.llvm.org/)网站对应的ReleaseNotes。

## ABI(application binary interface)兼容
在OpenHarmony系统中，系统库与应用Native库都在使用C++标准库，两部分依赖的版本是不一样的。系统库依赖的C++标准库随镜像版本升级，而应用Native库依赖的C++标准库随编译使用的SDK版本升级，两部分依赖的C++基础库会跨多个大版本，产生ABI兼容性问题。为了解决此问题，OpenHarmony上把两部分依赖的C++标准库进行了区分。
  * 系统库：使用libc++.so， 随系统镜像发布
  * 应用Native库：使用libc++_shared.so，随应用发布

两个库使用的C++命名空间不一样，libc++_shared.so使用__n1作为C++符号的命名空间，libc++.so使用__h作为C++符号的命名空间。

注意：两边使用的C++标准库不能进行混用，Native API接口当前只能是C接口，可以通过这个接口隔离两边的C++运行环境。