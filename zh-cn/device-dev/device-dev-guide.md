# 导读<a name="ZH-CN_TOPIC_0000001152533331"></a>

-   [系统类型](#section767218232110)
-   [文档导读](#section19810171681218)

为了方便开发者正确获取内容，本导读基于OpenHarmony学习路径同时结合开发者具体业务对相关资料、资源进行了分类。

## 系统类型<a name="section767218232110"></a>

在正式学习OpenHarmony开发前，开发者需要先了解系统类型，方便后续根据自身业务匹配对应的系统及对应文档资源。

OpenHarmony是一款面向全场景的开源分布式操作系统，采用组件化设计，支持在128KiB到xGiB RAM资源的设备上运行系统组件，设备开发者可基于目标硬件能力自由选择系统组件进行集成。

为了保证在不同硬件上集成的易用性，OpenHarmony当前定义了三种基础系统类型，设备开发者通过选择基础系统类型完成必选组件集配置后，便可实现其最小系统的开发。这三种基础系统类型的参考定义如下：

-   轻量系统（mini system）

    面向MCU类处理器，例如Arm Cortex-M、RISC-V 32位的设备，硬件资源极其有限，支持的设备最小内存为128KiB，可以提供多种轻量级网络协议，轻量级的图形框架，以及丰富的IOT总线读写部件等。可支撑的产品如智能家居领域的连接类模组、传感器设备、穿戴类设备等。

-   小型系统（small system）

    面向应用处理器，例如Arm Cortex-A的设备，支持的设备最小内存为1MiB，可以提供更高的安全能力、标准的图形框架、视频编解码的多媒体能力。可支撑的产品如智能家居领域的IP Camera、电子猫眼、路由器以及智慧出行域的行车记录仪等。

-   标准系统（standard system）

    面向应用处理器，例如Arm Cortex-A的设备，支持的设备最小内存为128MiB，可以提供增强的交互能力、3D GPU以及硬件合成能力、更多控件以及动效更丰富的图形能力、完整的应用框架。可支撑的产品如高端的冰箱显示屏。


OpenHarmony也提供了一系列可选的系统组件，方便设备开发者按需配置，以支撑其特色功能的扩展或定制开发。系统将这些可选的系统组件组合为一系列描述为特性或功能的系统能力，以方便设备开发者理解和选择。

## 文档导读<a name="section19810171681218"></a>

**表 1**  轻量和小型系统开发指导（参考内存<128MiB）

| 学习路径 | 开发者业务 | 相关文档 |
| -------- | -------- | -------- |
| 了解OpenHarmony | 整体认知OpenHarmony | -&nbsp;[OpenHarmony概述](https://gitee.com/openharmony)<br/>-&nbsp;[术语](../glossary.md) |
| 获取开发资源 | 准备开发前相关资源 | -&nbsp;[获取源码](get-code/sourcecode-acquire.md)<br/>-&nbsp;[获取工具](get-code/gettools-acquire.md) |
| 快速入门 | 快速熟悉OpenHarmony环境搭建、编译、烧录、调测、运行 | -&nbsp;[轻量和小型系统快速入门](quick-start/quickstart-ide-lite-overview.md) |
| 基础能力使用 | 使用OpenHarmony提供的基础能力 | -&nbsp;[轻量系统内核开发指南](kernel/kernel-mini-overview.md)<br/>-&nbsp;[小型系统内核开发指南](kernel/kernel-small-overview.md)<br/>-&nbsp;[驱动开发指南](driver/driver-hdf-overview.md)<br/>-&nbsp;[子系统开发指南](subsystems/subsys-build-mini-lite.md)<br/>-&nbsp;[安全指南](security/security-guidelines-overall.md)<br/>-&nbsp;[隐私保护](security/security-privacy-protection.md) |
| 进阶开发 | 结合系统能力开发智能设备 | -&nbsp;[WLAN连接类产品](guide/device-wlan-led-control.md)<br/>-&nbsp;[无屏摄像头类产品](guide/device-iotcamera-control-overview.md)<br/>-&nbsp;[带屏摄像头类产品](guide/device-camera-control-overview.md) |
| 移植适配 | -&nbsp;针对特定芯片做移植适配<br/>-&nbsp;对三方库进行移植适配 | -&nbsp;[轻量系统芯片移植指导](porting/porting-minichip.md)<br/>-&nbsp;[小型系统芯片移植指导](porting/porting-smallchip-prepare-needs.md)<br/>-&nbsp;[轻量和小型系统三方库移植指导](porting/porting-thirdparty-overview.md) |
| 贡献组件 | 为OpenHarmony贡献功能组件 | -&nbsp;[HPM&nbsp;Part&nbsp;介绍](hpm-part/hpm-part-about.md)<br/>-&nbsp;[HPM&nbsp;Part&nbsp;开发指导](hpm-part/hpm-part-development.md)<br/>-&nbsp;[HPM&nbsp;Part&nbsp;参考](hpm-part/hpm-part-reference.md) |
| 参考 | 开发参考 | [常见问题](faqs/faqs-overview.md) |


**表 2**  标准系统开发指导（参考内存≥128MiB）
| 学习路径 | 开发者业务 | 相关文档 |
| -------- | -------- | -------- |
| 了解OpenHarmony | 整体认知OpenHarmony | -&nbsp;[OpenHarmony概述](https://gitee.com/openharmony)<br/>-&nbsp;[术语](../glossary.md) |
| 获取开发资源 | 准备开发前相关资源 | -&nbsp;[获取源码](get-code/sourcecode-acquire.md)<br/>-&nbsp;[获取工具](get-code/gettools-acquire.md) |
| 快速入门 | 快速熟悉OpenHarmony环境搭建、编译、烧录、调测、运行 | -&nbsp;[标准系统快速入门](quick-start/quickstart-ide-standard-overview.md) |
| 基础能力使用 | 使用OpenHarmony提供的基础能力 | -&nbsp;[内核开发指南](kernel/kernel-standard.md)<br/>-&nbsp;[驱动开发指南](driver/driver-hdf-overview.md)<br/>-&nbsp;[子系统开发指南](subsystems/subsys-build-standard-large.md)<br/>-&nbsp;[安全指南](security/security-guidelines-overall.md)<br/>-&nbsp;[隐私保护](security/security-privacy-protection.md) |
| 进阶开发 | 结合系统能力开发智能设备 | -&nbsp;[时钟应用开发指导](guide/device-clock-guide.md)<br/>-&nbsp;[平台驱动开发示例](guide/device-driver-demo.md)<br/>-&nbsp;[外设驱动开发示例](guide/device-outerdriver-demo.md) |
| 移植适配 | 对三方库进行移植适配 | -&nbsp;[标准系统芯片移植指导](porting/standard-system-porting-guide.md)<br/>-&nbsp;[一种快速移植OpenHarmony&nbsp;Linux内核的方法](porting/porting-linux-kernel.md) |
| 贡献组件 | 为OpenHarmony贡献功能组件 | -&nbsp;[HPM&nbsp;Part&nbsp;介绍](hpm-part/hpm-part-about.md)<br/>-&nbsp;[HPM&nbsp;Part&nbsp;开发指导](hpm-part/hpm-part-development.md)<br/>-&nbsp;[HPM&nbsp;Part&nbsp;参考](hpm-part/hpm-part-reference.md) |
| 参考 | 开发参考 | [常见问题](faqs/faqs-overview.md) |
