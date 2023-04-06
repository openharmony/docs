# 方舟运行时子系统<a name="ZH-CN_TOPIC_0000001138852894"></a>

- [方舟运行时子系统<a name="ZH-CN_TOPIC_0000001138852894"></a>](#方舟运行时子系统)
  - [简介<a name="section11660541593"></a>](#简介)
  - [目录<a name="section161941989596"></a>](#目录)
  - [使用指南<a name="section18393638195820"></a>](#使用指南)
  - [相关仓<a name="section1371113476307"></a>](#相关仓)

## 简介<a name="section11660541593"></a>

方舟编译器\(ArkCompiler\)是为支持多种编程语言、多种芯片平台的联合编译、运行而设计的统一编译运行时平台。它支持包括动态类型和静态类型语言在内的多种编程语言，如JS、TS、ArkTS；它是支撑OpenHarmony系统成为打通手机、PC、平板、电视、车机和智能穿戴等多种设备的操作系统的编译运行时底座。

ArkCompiler主要分成两个部分：编译工具链与运行时.

**图1** 编译工具链架构
![](figures/zh-cn_image_ark_frontend.png)

ArkCompiler的编译工具链以ArkTS/TS/JS源码作为输入，将其编译生成为abc(ArkCompiler Bytecode，即方舟字节码)文件。

**图2** 运行时架构

![](figures/zh-cn_image_ark-ts-arch.png)

ArkCompiler运行时直接运行字节码文件，实现对应语言规范的语义逻辑。

主要由四个子系统组成：

-   Core Subsystem

    Core Subsystem主要由与语言无关的基础运行库组成，包括承载字节码的File组件、支持Debugger的Tooling组件、负责适配系统调用的Base库组件等。

-   Execution Subsystem

    Execution Subsystem包含执行字节码的解释器、快速路径内联缓存、以及抓取运行时信息的Profiler。

-   Compiler Subsystem

    Compiler Subsystem包含Stub编译器、基于IR的编译优化框架和代码生成器。

-   Runtime subsystem

    Runtime Subsystem包含了ArkTS/TS/JS运行相关的模块。
    - 内存管理：对象分配器与垃圾回收器\(并发标记和部分内存压缩的CMS-GC和Partial-Compressing-GC\)
    - 分析工具：DFX工具、cpu和heap的profiling工具
    - 并发管理：actor并发模型中的abc文件管理器
    - 标准库：Ecmascript规范定义的标准库、高效的container容器库与对象模型
    - 其他：异步工作队列、TypeScript类型加载、跟C++交互的JSNAPI接口等。

**ArkCompiler eTS Runtime的设计特点：**

- 原生支持类型
  目前业界引擎执行TS的方式是先把TS转化为JS，再运行JS源码来完成对应的语义逻辑。ArkCompiler的编译工具链编译TS源码时，会分析推导TS的类型信息并将其传递给运行时。运行时直接使用类型信息在运行前预生成内联缓存（Inline Cache）以加速字节码执行。另外，TSAOT (Ahead-of-Time) Compiler，可以利用字节码文件中的类型信息，直接编译生成优化机器码，使得应用可以直接运行优化机器码，获得高性能运行体验。

- 并发：并发模型优化与并发API

  ArkCompiler eTS Runtime选择将ArkTS程序预先静态编译为方舟字节码\(带上静态类型信息\)，从而减少运行时的编译和类型信息收集开销。另外出于安全性和性能的考虑，ArkCompiler eTS Runtime选择不支持eval和只支持strict模式的代码。

- 原生支持TypeScript：
  ECMAScript规范没有提供并发语义表述；业界引擎，如浏览器或者Node.js，通常会提供基于Actor并发模型的Worker API来支持多线程开发。Actor模型下执行体之间不共享任何数据对象，通过消息机制进行通信。因此Web引擎或者Node.js引擎的Worker都有启动速度慢、内存占用高这些缺陷。  针对这些缺陷，ArkCompiler的运行时已经实现了Actor实例中的不可变或者不易变的对象（方法和字节码）的共享，较大程度地优化了Actor的启动性能和启动内存。
  方舟编译运行时不只提供了业界通用的Worker API，还提供了TaskPool作为并发API的增强。TaskPool是一个支持优先级调度、工作线程自动扩缩容的任务池功能库。开发者无需关心并发实例的生命周期，也无需关心任务负载变化时需要创建或者销毁并发实例，极大地简化了高性能多线程OpenHarmony应用的开发。


- 安全
  ArkCompiler前端编译工具链将ArkTS/TS/JS程序预先静态编译为方舟字节码，并且还提供了多重混淆能力的增强，有效地提升了开发者代码资产的安全强度。另外出于安全的考虑，ArkCompiler不支持sloppy模式的JS代码，也不支持eval等运行动态字符串的功能。

## 目录<a name="section161941989596"></a>

```
/arkcompiler
├── ets_runtime       # ArkTS运行时组件
├── runtime_core      # 运行时公共组件
├── ets_frontend      # ArkTS语言的前端工具
└── toolchain         # ArkTS工具链
```

## 使用指南<a name="section18393638195820"></a>

[方舟运行时使用指南](https://gitee.com/openharmony/arkcompiler_ets_runtime/blob/master/docs/README_zh.md)

## 相关仓<a name="section1371113476307"></a>

[arkcompiler\_runtime\_core](https://gitee.com/openharmony/arkcompiler_runtime_core)

[arkcompiler\_ets\_runtime](https://gitee.com/openharmony/arkcompiler_ets_runtime)

[arkcompiler\_ets\_frontend](https://gitee.com/openharmony/arkcompiler_ets_frontend)

[arkcompiler\_toolchain](https://gitee.com/openharmony/arkcompiler_toolchain)