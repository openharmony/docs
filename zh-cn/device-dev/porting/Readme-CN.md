## 概述
目前OpenHarmony已经成立了SIG组[sig-devboard](https://gitee.com/openharmony/community/blob/master/sig/sig-devboard/sig_devboard_cn.md)。该SIG组以支持更多第三方开发板为目标，提供开发板移植的支撑。

在了解开发板移植前，需要先了解一下OpenHarmony对设备的分类。不同设备类型的移植方法会有较大差异。

| 设备类型    | 硬件要求        | 支持的内核          |
|---------|-------------|----------------|
| 轻量系统类设备 | 内存>128KB    | LiteOS-M       |
| 小型系统类设备 | 内存>1MB、有MMU | LiteOS-A、Linux |
| 标准系统类设备 | 内存>128MB    |  Linux       |

## 代码准备

目前OpenHarmony已经为各厂家创建了仓库并在openharmony-sig中进行孵化。参与孵化仓开发，需要使用如下方法初始化和下载代码。

```shell
repo init -u https://gitee.com/openharmony-sig/manifest.git -b master -m devboard.xml --no-repo-verify
```

其他下载步骤与主线相同。

## 芯片移植指导

- 轻量系统芯片移植指导
  - 移植准备
    - [移植须知](porting-chip-prepare-knows.md)
    - [编译构建适配流程](porting-chip-prepare-process.md)
  - 内核移植
    - [移植概述](porting-chip-kernel-overview.md)
    - [内核基础适配](porting-chip-kernel-adjustment.md)
    - [内核移植验证](porting-chip-kernel-verify.md)
  - 板级系统移植
    - [移植概述](porting-chip-board-overview.md)
    - [板级驱动适配](porting-chip-board-driver.md)
    - [HAL层实现](porting-chip-board-hal.md)
    - [系统组件调用](porting-chip-board-component.md)
    - [lwIP组件适配](porting-chip-board-lwip.md)
    - [三方组件适配](porting-chip-board-bundle.md)
    - [XTS认证](porting-chip-board-xts.md)
  - [常见问题](porting-chip-faqs.md)
- 小型系统芯片移植指导
  - 移植准备
    - [移植须知](porting-smallchip-prepare-needs.md)
    - [编译构建](porting-smallchip-prepare-building.md)
  - 移植内核
    - [LiteOS-A内核](porting-smallchip-kernel-a.md)
    - [Linux内核](porting-smallchip-kernel-linux.md)
  - 驱动移植
    - [移植概述](porting-smallchip-driver-overview.md)
    - [平台驱动移植](porting-smallchip-driver-plat.md)
    - [器件驱动移植](porting-smallchip-driver-oom.md)
- 标准系统芯片移植指导
  - [标准系统移植指南](standard-system-porting-guide.md)
  - [一种快速移植OpenHarmony Linux内核的方法](porting-linux-kernel.md)
- 轻量和小型系统三方库移植指导
  - [概述](porting-thirdparty-overview.md)
  - [CMake方式组织编译的库移植](porting-thirdparty-cmake.md)
  - [Makefile方式组织编译的库移植](porting-thirdparty-makefile.md)

## 芯片移植案例

- 轻量系统芯片移植案例
    - [带屏解决方案之恒玄芯片移植案例](porting-bes2600w-on-minisystem-display-demo.md)
    - [Combo解决方案之ASR芯片移植案例](porting-asr582x-combo-demo.md)
    - [轻量系统STM32F407芯片移植案例](porting-stm32f407-on-minisystem-eth.md)

