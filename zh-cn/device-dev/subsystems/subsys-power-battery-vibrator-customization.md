# 充电振动定制开发指导

## 概述

### 功能简介

OpenHarmony提供定制电池服务振动的能力，产品定制开发者可根据产品设计规格来定制。当前该定制能力仅支持在插入充电器场景下使用，定制时采用修改配置文件的方式，实现电池连接充电器时触发振动效果。

### 约束与限制

该功能依赖于设备硬件，设备需要有振动马达器件。


## 开发指导

### 搭建环境

- 设备要求：

  标准系统开发板，如DAYU200开源套件，外接振动马达器件。

- 环境要求：

  Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤

本文以RK3568开发板为例，说明如何实现插入充电器振动的定制方法。

1. 修改[base\powermgr\battery_manager\services\native\profile](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile)路径下的电池服务振动配置文件battery_vibrator.json。

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ├── battery_vibrator.json
    ```

    以如下配置为例：

    ```json
    {
        "start_charge": {
            "enable": true, 
            "type": "haptic.charging"
        }
    }
    ```
   - start_charge：振动场景字符串名称，不可修改。

   - enable：振动使能开关，配置为true则触发振动，为false则不触发振动，默认为false。

   - type：振动波形名，默认为haptic.charging，暂未提供其他波形名。

2. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. 将定制版本烧录到RK3568开发板中。

### 调测验证 

烧录版本后重启设备，插入充电器观察是否按照预期振动，如按照预期振动则功能测试成功。


## 参考

开发过程中可参考的配置文件路径：

[系统默认插入充电器振动配置源码路径](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile)