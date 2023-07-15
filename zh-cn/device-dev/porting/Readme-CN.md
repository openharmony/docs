## 概述
目前OpenHarmony已经成立了SIG组[sig_devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)。该SIG组以支持更多第三方开发板为目标，提供开发板移植的支撑。

在了解开发板移植前，需要先了解一下OpenHarmony对设备的分类。不同设备类型的移植方法会有较大差异。

| 设备类型    | 硬件要求        | 支持的内核          |
|---------|-------------|----------------|
| 轻量系统类设备 | 内存>128KB    | LiteOS-M       |
| 小型系统类设备 | 内存>1MB、有MMU | LiteOS-A、Linux |
| 标准系统类设备 | 内存>128MB    |  Linux       |

## 代码准备

目前OpenHarmony已经为各厂家创建了仓库并在OpenHarmony-sig中进行孵化。参与孵化仓开发，需要使用如下方法初始化和下载代码。

```shell
repo init -u https://gitee.com/openharmony-sig/manifest.git -b master -m devboard.xml --no-repo-verify
```

其他下载步骤与主线相同。

## 芯片移植指导

- 轻量系统芯片移植指导
  - [概述](porting-minichip-overview.md)
  - [移植准备](porting-minichip-prepare.md)
  - [移植内核](porting-minichip-kernel.md)
  - 移植子系统
    - [移植子系统概述](porting-minichip-subsys-overview.md)
    - [移植启动恢复子系统](porting-minichip-subsys-startup.md)
    - [移植文件子系统](porting-minichip-subsys-filesystem.md)
    - [移植安全子系统](porting-minichip-subsys-security.md)
    - [移植通信子系统](porting-minichip-subsys-communication.md)
    - [移植外设驱动子系统](porting-minichip-subsys-driver.md)
    - [配置其他子系统](porting-minichip-subsys-others.md)
  - [移植验证](porting-minichip-verification.md)
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
    - [物联网解决方案之芯海cst85芯片移植案例](porting-cst85f01-combo-demo.md)
    - [轻量系统STM32F407芯片移植案例](porting-stm32f407-on-minisystem-eth.md)
    - [Combo解决方案之W800芯片移植案例](porting-w800-combo-demo.md)
- 小型系统芯片移植案例
    - [小型设备STM32MP1芯片移植案例](porting-stm32mp15xx-on-smallsystem.md)
- 标准系统芯片移植案例
    - [标准系统方案之瑞芯微RK3568移植案例](porting-dayu200-on_standard-demo.md)
    - [标准系统方案之瑞芯微RK3566移植案例](https://gitee.com/openharmony/vendor_kaihong/blob/master/khdvk_3566b/porting-khdvk_3566b-on_standard-demo.md)
    - [标准系统方案之扬帆移植案例](porting-yangfan-on_standard-demo.md)
