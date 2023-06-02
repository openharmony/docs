# Native API介绍

Native API是OHOS SDK上提供的一组native开发接口与工具集合，方便开发者使用C或者C++语言实现应用的关键功能。Native API只覆盖了OHOS基础的一些底层能力，如libc，图形库，窗口系统，多媒体，压缩库等，并没有完全提供类似于JS API上的完整的OHOS 平台能力。在应用中使用Native API会编译成动态库打包到应用中。

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
|标准C库|以musl为基础提供的标准c库接口，当前提供了1500+的接口|8|
|标准C++库|c++运行时库libc++_shared，此库在打包的时候需要打包或者静态链接到应用中|8|
|日志|打印日志到系统的hilog接口|8|
|napi|ArkUI提供的，方便应用开发接入JS应用环境的一组类Node-API，是属于Native API的一部分|8|
|XComponent|ArkUI XComponent组件中的surface与触屏事件接口，方便开发者开发高性能图形应用|8|
|libuv|ArkUI集成的三方的异步IO库|8|
|libz|zlib库，提供基本的压缩，解压接口|8|
|Drawing|系统提供的2D图形库，可以在surface进行绘制|8|
|OpenGL|系统提供的openglv3接口|8|
|Rawfile|应用资源访问接口，可以读取应用中打包的各种资源|8|
|OpenSLES|用于2D，3D音频加速的接口库|8|
|Mindspore|AI模型接口库|9|
|包管理|包服务接口，方便查询应用包信息|8|

Native API中有一部分接口采用开源标准，详细列表见《[Native API中支持的标准库](../reference/native-lib/third_party_libc/musl.md)》《[Node_API](../reference/native-lib/third_party_napi/napi.md)》

## 使用介绍

### 建议使用Native API的场景

主要有如下一些

1. 应用性能敏感代码，比如游戏，物理模拟等计算密集型场景
2. 需要复用已有的C或C++库
3. 需要针对CPU特性进行专项定制的库，如neon加速

### 不建议使用Native API的场景

1. 写一个纯native的的OHOS应用
2. 希望在尽可能多的OHOS设备上保持兼容的应用
