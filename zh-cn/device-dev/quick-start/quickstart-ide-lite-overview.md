# 轻量与小型系统入门概述


## 简介

OpenHarmony轻量和小型系统适用于内存较小的IOT设备（参考内存≥128KiB）。通过本文，开发者可以快速熟悉OpenHarmony轻量和小型系统的环境搭建、编译、烧录、调测以及运行“Hello World”等。

考虑到开发者的开发习惯，OpenHarmony为开发者提供了以下两种入门指导：

- IDE方式：完全采用IDE（DevEco Device Tool）进行一站式开发，编译依赖工具的安装及编译、烧录、运行都通过IDE进行操作。

- 安装包方式：通过命令行进行编译依赖工具的下载安装，编译操作也通过命令实现。烧录、运行等操作使用IDE。
  OpenHarmony还为开发者提供了[Docker环境](../get-code/gettools-acquire.md)，在很大程度上简化了编译前的环境配置，习惯使用安装包方式的开发者也可以选择Docker环境进行编译 。

本文采用DevEco Device Tool进行一站式开发介绍，习惯使用命令行的开发者可参考[轻量和小型系统快速入门（安装包方式）](../quick-start/quickstart-lite-overview.md)。


## 开发环境

推荐开发者采用Windows+Ubuntu环境进行OpenHarmony开发：

- Windows：用于源码开发、烧录等。

- Ubuntu：用于源码编译。

本文将介绍如何基于Windows+Ubuntu环境进行OpenHarmony的开发。


## 开发板

本文基于以下两款典型开发板进行开发介绍 ：Hi3861 WLAN模组、Hi3516DV300。开发板的具体外观和规格可参见[本文附录](../quick-start/quickstart-ide-lite-introduction-hi3861.md)，开发者可根据需要自行购买开发板。


## 开发流程

轻量和小型系统快速入门流程如下图所示。


  **图1** 轻量和小型系统快速入门开发流程 

 
  ![zh-cn_image_0000001226634676](figures/zh-cn_image_0000001226634676.png)
