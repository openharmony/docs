# USB串口通信服务开发概述

## 基本概念

本模块主要提供USB Host转串口协议通信的功能，USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。
它提供获取USB Host转串口协议的、已连接的端口列表，同时提供打开端口、关闭端口、设置参数、获取参数、读取数据、写入数据和设备权限管理这些基本功能。

## 实现原理

### 设备枚举与驱动加载

- 插入USB转串口设备后，主机通过USB总线发起枚举过程，获取设备描述符（如厂商ID、设备ID、通信类CDC类标识）。
操作系统根据描述符匹配驱动（如厂商专用驱动或系统内置CDC驱动），完成设备初始化和虚拟串口注册。

### 数据收发流程

- 发送方向：
串口应用层发送数据 → 虚拟串口驱动捕获数据 → 驱动通过USB通道传输至设备 → 设备解析数据并通过物理串口发送。

- 接收方向：
设备接收物理串口数据 → 数据经USB打包上传至主机 → 驱动接收数据并存入串口缓冲区 → 应用层读取数据。

## 环境准备

### 环境要求

- 开发工具及配置：

  DevEco Studio作为开发工具，是进行开发必备条件之一，开发者可以使用该工具进行开发、调试、打包等操作。请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-tools-overview-V14)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-create-new-project-V14)进行基本的操作验证，保证DevEco Studio可正常运行。

- SDK版本配置：

  本模块提供的ArkTs接口，所需SDK版本为API16及以上才可使用。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API 16或以上，更新SDK的具体操作可参见[更新指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)。
- USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。