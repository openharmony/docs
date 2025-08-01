# ArkTS运行时概述
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @guobingbing3-->
<!--SE: @xwcai98-->
<!--TSE: @kirl75;@zsw_zhushiwei-->

ArkTS运行时是OpenHarmony上应用的默认语言运行时，支持ArkTS、TS和JS语言的字节码及相关标准库。它提供解释器、AOT和JIT高效执行方式，并通过[Node-API](../napi/napi-introduction.md)实现完善的跨语言调用接口，支持多语言混合开发。

ArkTS Runtime主要由四个子系统组成：

- **Core Subsystem**：主要由与语言无关的基础运行库组成，其中包括承载字节码的File组件、支持Debugger的Tooling组件以及负责适配系统调用的Base库组件等。

- **Execution Subsystem**：包含执行方舟字节码的解释器、快速路径内联缓存以及[文件模块化管理运行](module-principle.md)。

- **Compiler Subsystem**：包含Stub编译器、基于IR的编译优化框架、AOT静态编译器以及JIT动态编译器（实验中）。

- **Runtime subsystem**：包含以下ArkTS/TS/JS运行相关的模块。

  - 内存管理：对象分配器与[垃圾回收器](gc-introduction.md)（并发标记和部分内存压缩的CMS-GC和Partial-Compressing-GC）。

  - 分析工具：DFX工具、CPU和heap的profiling工具。

  - 并发管理：Actor并发模型中的方舟字节码文件管理器。

  - 标准库：ECMAScript规范定义的标准库、高效的container容器库与对象模型。
  
  - 其他：包括异步工作队列和C++交互的Node-API接口等功能。
