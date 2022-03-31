# 轻量与小型系统入门概述


## 简介

OpenHarmony轻量和小型系统适用于内存较小的IOT设备（参考内存≥128KiB）。通过本文，开发者可以快速熟悉OpenHarmony轻量和小型系统的环境搭建、编译、烧录、调测以及运行“Hello World”等。

考虑到开发者的开发习惯，OpenHarmony为开发者提供了以下两种入门指导：

- 完全采用IDE（Deveco Device Tool）进行一站式开发，编译依赖工具的安装及编译、烧录、运行都通过IDE进行操作。

- 通过命令行进行编译依赖工具的下载安装，编译操作也通过命令实现。烧录、运行等操作使用IDE。

本文采用Deveco Device Tool进行一站式开发介绍，习惯使用命令行的开发者可参考[轻量和小型系统快速入门（命令行方式）](../quick-start/quickstart-lite-overview.md)。


## 开发环境

因当前OpenHarmony不支持在Windows下进行编译，基于Deveco Device Tool的轻量和小型系统开发有以下两种方法，开发者可根据使用习惯进行选择：

- 在Linux环境下进行开发、编译和烧录。

- 在indows环境下进行开发和烧录，在Linux环境下进行编译。

本文将介绍第一种方法，相关操作均在Linux环境下进行。使用第二种方式的开发者可参考[Deveco Device Tool使用指导](https://device.harmonyos.com/cn/docs/documentation/guide/service_introduction-0000001050166905)。


## 开发板

本文基于以下两款典型开发板进行开发介绍 ：Hi3861 WLAN模组、Hi3516DV300。开发板的具体外观和规格可参见[本文附录](../quick-start/quickstart-ide-lite-board-introduction.md)，开发者可根据需要自行购买开发板。


## 开发流程

轻量和小型系统快速入门流程如下图所示。

  **图1** 轻量和小型系统快速入门开发流程
  ![zh-cn_image_0000001262860145](figures/zh-cn_image_0000001262860145.png)
