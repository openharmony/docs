# Native API（NDK）入门

Native API是OpenHarmony SDK上提供的一组native开发接口与工具集合（也称为NDK），方便开发者使用C或者C++语言实现应用的关键功能。Native API只覆盖了OHOS基础的一些底层能力，如libc，图形库，窗口系统，多媒体，压缩库等，并没有完全提供类似于JS API上的完整的OHOS 平台能力。在应用中使用Native API会编译成动态库打包到应用中。

## 名词概念

|名词|名词解释|
|--|--|
|Native API|OHOS SDK里面native包提供的，面向三方应用开发的Native 接口以及相应编译脚本，编译工具链。包括C运行时基础库libc，3D图形库opengl，面向JS与C跨语言的接口Node-API等，具体内容详见下表。|
|NDK|Native Develop Kit的缩写，在OHOS上就是Native API；Native API是官方名字，NDK指代相同意思。|
|SDK CAPI|OHOS Native API中的C语言接口，以及工具链部分，当前OHOS的Native API里面只包含C语言接口，因此Native API与CAPI意思一样，建议交流的时候使用CAPI，防止Native API与napi缩写混用。|
|Node-API|曾用名napi，是OHOS中提供JS与C跨语言调用的接口，是Native API接口中的一部分. 该接口在Node.js提供的Node-API基础上扩展而来，但不完全与Node.js中的Node-API完全兼容。 |
|napi|Node-API的曾用名，当前Node-API头文件中的接口仍然以napi_开头，不建议使用。|

## Native API构成介绍

### Native API目录结构

Native API在SDK包的位置为$(SDK_ROOT)/native目录，主要有以下几个部分组成

|目录|功能说明|
|--|--|
|build|应用中编译动态库的toolchain cmake脚本；这个目录下ohos.toolchain.cmake文件定义了给OHOS交叉编译选项|
|build-tools|放置编译构建的工具，如cmake|
|docs|Native API接口参考文档，通过doxgen从头文件中提取出来|
|llvm|支持OHOS ABI的llvm交叉编译器|
|sysroot|放置编译链接的依赖文件目录，包含头文件，动态库等|

### Native API接口

|接口分类|接口功能|引入版本|
|--|--|--|
|[标准C库](native-lib/third_party_libc/musl.md)|以musl为基础提供的标准c库接口，当前提供了1500+的接口|8|
|[标准C++库](native-lib/third_party_libc/cpp.md)|c++运行时库libc++_shared，此库在打包的时候需要打包或者静态链接到应用中|8|
|日志|打印日志到系统的hilog接口|8|
|Node-API|ArkUI提供的，方便应用开发接入JS应用环境的一组类Node-API（也叫napi），是属于Native API的一部分|8|
|XComponent|ArkUI XComponent组件中的surface与触屏事件接口，方便开发者开发高性能图形应用|8|
|libuv|ArkUI集成的三方的异步IO库|8|
|libz|zlib库，提供基本的压缩，解压接口|8|
|Drawing|系统提供的2D图形库，可以在surface进行绘制|8|
|OpenGL|系统提供的openglv3接口|8|
|Rawfile|应用资源访问接口，可以读取应用中打包的各种资源|8|
|OpenSLES|用于2D，3D音频加速的接口库|8|
|Mindspore|AI模型接口库|9|
|包管理|包服务接口，方便查询应用包信息|8|

### Native API相关资料

* [Native API参考](native-apis/_o_h___native_x_component.md)，介绍各个API参考手册
* [Native API中支持的标准库](../reference/native-lib/third_party_libc/musl.md)，介绍Native API支持的开源标准库
* [Native API开发指南](../napi/napi-guidelines.md)，结合具体的例子，场景介绍各类接口的使用
* [使用NDK编译一个Cmake C/C++工程文档](../faqs/howto-migrate-cmake-with-ohosndk.md)，介绍如何使用使用Native API开发一个Cmake工程
* [Node-API在应用工程中的使用指导](../napi/napi-guidelines.md), 如何使用Node-API接口

## 使用建议

### 建议使用Native API的场景

主要有如下一些

1. 应用性能敏感代码，比如游戏，物理模拟等计算密集型场景
2. 需要复用已有的C或C++库
3. 需要针对CPU特性进行专项定制的库，如neon加速

### 不建议使用Native API的场景

1. 写一个纯native的的OHOS应用
2. 希望在尽可能多的OHOS设备上保持兼容的应用

## 维测能力

1. OHOS官方提供lldb remote方式代码调试，详细参看[lldb参考手册](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README_zh.md)。
2. musl库的log维测能力，请参看[libc库](./native-lib/third_party_libc/musl.md)维测章节。
