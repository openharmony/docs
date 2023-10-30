
# 标准C++库

OpenHarmony使用llvm开源项目的C++标准库[libc++](https://libcxx.llvm.org/)作为C++运行时库。

## libc++版本

从OpenHarmony 4.0开始，libc++升级到clang/llvm 15.0.4版本

从OpenHarmony 3.2开始，libc++升级到clang/llvm 12.0.1版本

从OpenHarmony 3.0开始，libc++使用clang/llvm 10.0.1版本

## C++语言支持能力

C++11、C++14标准已完全支持，C++17和C++20标准正在完善。具体语言特性支持标准可以参考[https://libcxx.llvm.org/](https://libcxx.llvm.org/)网站对应的Release Notes。


## 如何在CMake中选择C++

在NDK的{ndk_root}/build/cmake/ohos.toolchain.cmake文件中，定义了OHOS_STL变量，可以通过设置"c++_shared"或者"c++_static"来控制应用工程中原生库链接C++运行库的方式。
* c++_shared，原生库动态链接libc++_shared.so
* c++_static，原生库静态链接libc++_static.a

## 注意事项

1. 在一个应用工程里面，原生库只能使用一种方式链接C++运行时库。C++运行时里面有很多的全局变量、状态；混合使用会导致这些状态存在多份，可能会出现各种C++运行时异常。

2. 动态链接ABI(application binary interface)兼容。 在OpenHarmony系统中，系统库与应用原生库都在使用C++标准库，两部分依赖的版本是不一样的。系统库依赖的C++标准库随镜像版本升级，而应用原生库依赖的C++标准库随编译使用的SDK版本升级，两部分依赖的C++基础库会跨多个大版本，产生ABI兼容性问题。为了解决此问题，OpenHarmony上把两部分依赖的C++标准库进行了区分。

    * 系统库：使用libc++.so， 随系统镜像发布。
    * 应用Native库：使用libc++_shared.so，随应用发布。

   两个库使用的C++命名空间不一样，libc++_shared.so使用__n1作为C++符号的命名空间，libc++.so使用__h作为C++符号的命名空间。

   注意：两边使用的C++标准库不能进行混用，Native API接口当前只能是C接口，可以通过这个接口隔离两边的C++运行环境。