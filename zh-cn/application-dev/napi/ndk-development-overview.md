# NDK开发导读

NDK（Native Development Kit）是OpenHarmony SDK提供的Native API、相应编译脚本和编译工具链的集合，方便开发者使用C或C++语言实现应用的关键功能。NDK只覆盖了OpenHarmony一些基础的底层能力，如C运行时基础库libc、图形库、窗口系统、多媒体、压缩库、面向ArkTS/JS与C跨语言的Node-API等，并没有提供ArkTS/JS API的完整能力。


运行态，开发者可以使用NDK中的Node-API接口，访问、创建、操作JS对象；也允许JS对象使用Native动态库。


## NDK适用场景

**适合使用NDK的场景：应用涉及如下场景时，适合采用NDK开发**

- 性能敏感的场景，如游戏、物理模拟等计算密集型场景。

- 需要复用已有C或C++库的场景。

- 需要针对CPU特性进行专项定制库的场景，如Neon加速。

**不建议使用NDK的场景：应用涉及如下场景时，不建议采用NDK开发**

- 纯C或C++的应用。

- 希望在尽可能多的OpenHarmony设备上保持兼容的应用。


## NDK必备基础知识

为顺利进行NDK开发，开发者需要先掌握必要的基本概念及基础知识。


### NDK基本概念

- **[Node-API](napi-introduction.md)**

  曾用名NAPI，是OpenHarmony中提供ArkTS/JS与C/C++跨语言调用的接口，是NDK接口中的一部分。该接口是在Node.js提供的Node-API基础上扩展而来，但与Node.js中的Node-API不完全兼容。

- **C API**

  OpenHarmony NDK的曾用名，不再使用。


### 前置知识

- **Linux C语言编程知识**
  内核、libc基础库基于POSIX等标准扩展而来，掌握基本的Linux C编程知识能够更好的帮助理解OpenHarmony NDK开发。

- **CMake使用知识**
  CMake是OpenHarmony默认支持的构建系统。请先通过[CMake官方文档](https://cmake.org/cmake/help/v3.16/guide/tutorial/)了解基础用法。

- **Node Addons开发知识**
  ArkTS采用Node-API作为跨语言调用接口，熟悉基本的[Node Addons开发模式](https://nodejs.org/api/addons.html)，可以更好理解NDK中Node-API的使用。

- **Clang/LLVM编译器使用知识**
  具备一定的Clang/LLVM编译器基础知识，能够帮助开发者编译出更优的Native动态库。


### NDK目录简介

- build目录：放置预定义的toolchain脚本文件ohos.toolchain.cmake

  ![zh-cn_image_0000001770128125](figures/zh-cn_image_0000001770128125.png)

  CMake编译时需要读取该文件中的默认值，比如编译器架构、C++库链接方式等，因此在编译时会通过CMAKE_TOOLCHAIN_FILE指出该文件的路径，便于CMake在编译时定位到该文件。

- build-tools文件夹：放置NDK提供的编译工具
  ```
  # 键入下一行命令查看CMake的版本
  cmake -version
  # 结果
  cmake version 3.16.5
  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

- llvm文件夹：放置NDK提供的编译器

  ![zh-cn_image_0000001696408864](figures/zh-cn_image_0000001696408864.png)


## NDK常用模块

下表介绍了NDK的常用模块。


| 模块 | 模块简介 | 
| -------- | -------- |
| 标准C库 | 以musl为基础提供的标准C库接口。 | 
| 标准C++库 | C++运行时库libc++_shared。 | 
| 日志 | 打印日志到系统的HiLog接口。 | 
| Node-API | 当需要实现ArkTS/JS和C/C++之间的交互时，可以使用Node-API。 | 
| FFRT | 基于任务的并发编程框架。 | 
| libuv | 三方异步IO库。 | 
| zlib | zlib库，提供基本的数据压缩、解压接口。 | 
| Rawfile | 应用资源访问接口，可以读取应用中打包的各种资源。 | 
| XComponent | ArkUI XComponent组件提供surface与触屏事件等接口，方便开发者开发高性能图形应用。 | 
| Drawing | 系统提供的2D图形库，可以在surface进行绘制。 | 
| OpenGL | 系统提供的OpenGL 3D图形接口。 | 
| OpenSL ES | 用于2D、3D音频加速的接口库。 | 
