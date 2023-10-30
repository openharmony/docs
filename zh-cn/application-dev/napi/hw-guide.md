# 硬件兼容性
## 简介
使用C/C++开发OpenHarmony应用原生库的时候，往往需要感知到硬件特性；OpenHarmony系统会运行在多种架构，多厂商的设备上，如何保证使用原生库的OpenHarmony应用兼容性，体验一致性是一个非常大的挑战。

本章节介绍OpenHarmony应用二进制接口（Application Binary Interface，简称ABI），定义了当前OpenHarmony系统支持的[ABI标准](./ohos-abi.md)；同时也提供了如何使用[CPU扩展特性](./cpu-features.md)的指导，方便应用不破坏兼容性的基础上更好的利用CPU硬件特性。最后通过一些简单的示例演示如何更好的使用[ARM Neon特性](./neon-guide.md)。

