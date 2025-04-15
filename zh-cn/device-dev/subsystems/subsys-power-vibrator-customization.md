# 关机振动定制开发指导

## 概述

### 简介

OpenHarmony提供了定制电源服务振动提示的能力，产品定制开发者可根据产品设计规格来定制。在该模式下可通过修改配置文件在手机关机出现弹窗的同时触发振动效果，且当前暂时仅支持在关机弹窗场景下使用。

### 基本概念

### 约束与限制

该功能依赖于设备硬件，设备需要有振动马达器件。

## 开发指导

### 搭建环境

设备要求：

标准系统开发板，如DAYU200开源套件，外接振动马达器件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤

本文以power_manager项目开发关机弹窗振动为例。

1. 在[power_manager项目](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_vibrator.json)中，编写定制的"power_vibrator.json"，例如：

    ```json
    {
    "shutdown_diag": {
        "enable": true,
        "type": "haptic.long_press.heavy"
        }
    }
    ```
    - shutdown_diag: 振动场景字符串名称，不可修改。

    - enable: 振动使能开关，配置true则触发振动，false则不触发，默认为false。

    - type: 振动的波形名称，当前模式下的名称默认如上。

2. 参考《[快速入门](../quick-start/Readme-CN.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. 将定制版本烧录到DAYU200开发板中。

### 调测验证

长按power键，浮现关机弹窗的同时手机触发振动效果。

## 参考

[关机弹窗振动默认配置](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_vibrator.json)