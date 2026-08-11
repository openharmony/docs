# syscap_ndk.h
<!--Kit: ArkUI-->
<!--Subsystem: Startup-->
<!--Owner: @chenjinxiang3-->
<!--Designer: @chenjinxiang3-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->

## 概述

查询单个系统能力（SystemCapability）是否被支持的API。开发者可在运行时查询设备是否支持特定系统能力，实现差异化功能适配。典型使用场景包括：针对不同设备型号适配功能、特性降级开关控制、条件功能分支判断等。该API具有轻量级、高效的特点，能帮助开发者避免因调用设备不支持的API而导致的崩溃问题，提高应用在不同设备上的兼容性和稳定性。

**起始版本：**

8

**相关模块：**

[Init](init.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| bool [canIUse](init.md#caniuse) (const char \*cap) | 返回指定的系统能力是否被支持。返回true表示支持，返回false表示不支持。cap参数为系统能力名称，格式为"SystemCapability.xxx.xxx"。 <br>系统能力（SystemCapability，简称 SysCap），指操作系统中每一个相对独立的特性。不同的设备对应不同的系统能力集，每个系统能力对应一个或多个API。开发者可根据系统能力来判断是否可以使用对应的API。 <br>**起始版本：** 8 |