# JSVM-API简介

## 场景介绍

OpenHarmony JSVM-API是基于标准JS引擎提供了一套稳定的API，为开发者提供了完整的JS引擎能力，包括创建和销毁引擎、执行JS代码、JS/C++交互等关键能力。

OpenHarmony JSVM-API是C语言接口，遵循C99标准。

通过JSVM-API，开发者可以在应用运行期间直接执行一段动态加载的JS代码。也可以选择将一些对性能、底层系统调用有较高要求的核心功能用C/C++实现并将C++方法注册到JS侧，在JS代码中直接调用，提高应用的执行效率。

本文中如无特别说明，后续均使用JSVM-API指代OpenHarmony JSVM-API能力。


## JSVM-API的组成架构

**图1** JSVM-API的组成架构
  
![jsvm-api_mechanism](figures/jsvm-api_mechanism.png)

- Native Module：开发者使用JSVM-API开发的模块，用于在Native侧使用。

- VM Life Cycle Manager：管理JSVM_VM的生命周期。

- JS Context Manager：管理JSVM_Env的生命周期。

- Context Snapshot：上下文快照，可用以缩短JS Context的创建时间。

- JS Code Execute：执行JS代码。

- JS/C++ Interaction：连接JS层与C++层，用于支撑JS与C++之间的交互。

- Code Cache：编译后的JS代码的缓存，能提升JS代码执行的启动速度。

- Debugger：调试器，用于调试JS代码。

- CPU Profiler：该工具能记录JS代码执行所用的时间，使用此工具能帮助开发者分析JS代码的性能瓶颈，为代码优化提供数据支撑。

- Heap Snapshot：JS堆内存分析/调优工具，可以进行内存优化和发现内存泄漏问题。

- Heap Statistics：JS堆统计信息，包括内存大小及上下文数量。

- Memory Adjustment：调整外部内存大小、虚拟机内存压力，以加快触发GC。

- VM Information：JSVM_VM的信息。

- Standard JS Engine：标准JS引擎。

## JSVM-API的关键交互流程

**图2** JSVM-API的关键交互流程

![JSVM-API 关键交互流程](figures/process_jsvm-api.png)

JSVM-API和Native模块之间的交互流程，主要分为以下两步：

1. **初始化阶段**：在Native模块上初始化JSVM和JS上下文，并完成Native函数的注册。Native方法将会被挂载到JS执行环境的全局上下文即GlobalThis。

2. **调用阶段**：当JS侧调用通过JSVM-API注册到JS全局上下文的方法时，JS引擎会找到并调用对应的C/C++方法。
