# 标准系统入门概述


## 简介

OpenHarmony标准系统适用于参考内存≥128MiB的设备。通过本文，开发者可以快速熟悉OpenHarmony标准系统的环境搭建、编译、烧录、调测以及运行“Hello World”等。

考虑到开发者的开发习惯，OpenHarmony为开发者提供了以下两种入门指导：

- IDE方式：完全采用IDE（DevEco Device Tool）进行一站式开发，编译依赖工具的安装及编译、烧录、运行都通过IDE进行操作。

- 安装包方式：通过命令行进行编译依赖工具的下载安装，编译操作也通过命令实现。烧录、运行等操作使用IDE。
  OpenHarmony还为开发者提供了[Docker环境](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/gettools-acquire.md)，在很大程度上简化了编译前的环境配置，习惯使用安装包方式的开发者也可以选择Docker环境进行编译 。

本文采用安装包方式进行介绍，习惯使用DevEco Device Tool的开发者可参考[标准系统快速入门（IDE方式）](../quick-start/quickstart-ide-standard-overview.md)。


## 开发环境

推荐开发者采用Windows+Ubuntu环境进行OpenHarmony开发：

- Windows：用于源码开发、烧录等。

- Ubuntu：用于源码编译。

本文将介绍如何基于Windows+Ubuntu环境进行OpenHarmony的开发。


## 开发板

本文选取了两款典型开发板：Hi3516DV300、RK3516，并基于上述两款开发板进行开发介绍。开发板的具体外观和规格可参见[本文附录](../quick-start/quickstart-standard-board-introduction-hi3516.md)，开发者可根据需要自行购买开发板。


## 开发流程

标准系统快速入门流程如下图所示。

  **图1** 标准系统快速入门开发流程  


![zh-cn_image_0000001227082314](figures/zh-cn_image_0000001227082314.png)
