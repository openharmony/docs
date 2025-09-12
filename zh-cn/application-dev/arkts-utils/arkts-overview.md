# ArkTS简介

<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @fanglou-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

ArkTS是OpenHarmony应用开发的官方高级语言。

ArkTS在[TypeScript](https://www.typescriptlang.org/)（简称TS）生态基础上做了进一步扩展，保持了TS的基本风格，同时通过规范定义强化开发期静态检查和分析，提升代码健壮性，并实现更好的程序执行稳定性和性能。对比标准TS的差异可以参考[从TypeScript到ArkTS的适配规则](../quick-start/typescript-to-arkts-migration-guide.md)。ArkTS同时也支持与TS/JavaScript（简称JS）高效互操作。

ArkTS基础类库和容器类库增强了语言的基础功能，提供包括[高精度浮点运算](../reference/apis-arkts/js-apis-arkts-decimal.md)、[二进制Buffer](buffer.md)、[XML生成解析转换](xml-overview.md)和多种容器库等能力，协助开发者简化开发工作，提升开发效率。

针对TS/JS并发能力支持有限的问题，ArkTS对并发编程API和能力进行了增强，提供了[TaskPool](taskpool-introduction.md)和[Worker](worker-introduction.md)两种并发API供开发者选择。另外，ArkTS进一步提出了Sendable的概念来支持对象在并发实例间的引用传递，提升ArkTS对象在并发实例间的通信性能。

方舟编译运行时（ArkCompiler）支持ArkTS、TS和JS的编译运行，目前主要分为ArkTS编译工具链和ArkTS运行时两部分。ArkTS编译工具链负责将高级语言编译为方舟字节码文件（\*.abc），ArkTS运行时则负责在设备侧运行字节码文件，执行程序逻辑。

未来，ArkTS会结合应用开发/运行的需求持续演进，逐步提供并发能力增强、系统类型增强、分布式开发范式等更多特性。
