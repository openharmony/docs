# 使用HiSmartPerf采集V8 trace
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## 简介

V8的trace是V8引擎提供的一种用于分析和调试JavaScript代码执行过程的工具。它可以记录并输出关于代码执行的详细信息，包括函数调用、执行时间、内存使用情况等，帮助开发者了解代码的性能、诊断潜在问题，进行优化。

HiSmartPerf目前已经对接了V8的compile、runtime、builtin、JS_Execution类别的trace点，可以在HiSmartPerf中直接看到这些类别event的相关信息。

## 使用方法

### 默认状态
V8是否采集trace由运行时开关“web.debug.rcs”控制，默认状态下该开关为关闭状态。启动web场景，在hilog中可以观察到有“RCS is off”日志打印输出。

### 采集V8 trace
1. 要采集V8的trace，需要在启动web场景前，打开“web.debug.rcs”开关。在启动web场景前，执行以下命令：

``` shell
hdc shell setenforce 0
hdc shell param set web.debug.rcs true
```
2. 启动web场景，可以看到hilog中有“RCS is on”的日志打印输出
3. 使用hitrace工具抓取对应场景的trace，hitrace使用方法可参考[hitrace](../dfx/hitrace.md)使用指导文档。
4. 使用HiSmartPerf工具解析抓取到的trace，可以看到有“RCS_”前缀的trace点，即为V8对接到HiSmartPerf中的trace点。
5. 要查看compile、runtime、builtin、JS_Execution不同类别的trace数据，可使用以下关键字进行过滤：
- compile：RCS_v8.compile
- runtime：RCS_V8.Runtime
- builtin：RCS_v8.runtime_V8.Builtin
- JS_Execution：RCS_JS_Execution
