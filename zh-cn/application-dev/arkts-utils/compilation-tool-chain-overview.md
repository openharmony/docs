# ArkTS编译工具链概述

为了支持ArkTS应用编译，ArkTS编译构建SDK提供一套完整的编译工具链，通过将其部署在Hvigor编译任务的编排工具上，实现将应用的ArkTS/TS/JS源码编译生成方舟字节码文件（\*.abc）。

在编译过程中，首先是语法转换阶段，包含了语法检查、UI转换。同时为了源码安全，使用[ArkGuard源码混淆工具](source-obfuscation.md)对源码进行混淆操作，并且在落盘字节码之前判断是否需要进行[字节码自定义修改](customize-bytecode-during-compilation.md)，如果需要则加载自定义修改代码并执行，在生成字节码文件后，使用[Disassembler反汇编工具](tool-disassembler.md)可以查看字节码文件中包含的内容，字节码的具体内容可以参考[方舟字节码](arkts-bytecode-overview.md)章节。

ArkTS编译工具链当前主要包括如下功能：

1. 语法检查：检查ArkTS/TS语法正确性。

2. UI转换：将ArkTS的UI范式语法转换为标准TS语法。

3. 源码混淆：使用ArkGuard源码混淆工具对源码进行混淆，开发者可根据业务需要选择开启。

4. 字节码编译：使用方舟编译器生成方舟字节码文件（\*.abc）。

5. 自定义修改方舟字节码：提供开发者修改字节码能力的入口，在字节码编译落盘前调用。

6. 反汇编：使用Disassembler反汇编工具将字节数据反汇编成可阅读的汇编指令。

流程详情参考下图：

![compilation-tool-overview](figures/compilation-tool-overview.png)

