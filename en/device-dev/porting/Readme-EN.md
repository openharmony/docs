## Introduction

OpenHarmony has organized a Special Interest Group (SIG) [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md) to provide support for third-party development boards.

Before learning about how to port the code of a development board, take a look at the device classification on OpenHarmony. The porting methods vary according to the device type.

| Device Type| Hardware Requirement| Supported Kernel|
|---------|-------------|----------------|
| Mini-system devices| Memory > 128 KB| LiteOS-M       |
| Small-system devices| Memory > 1 MB, with MMU| LiteOS-A and Linux|
| Standard-system devices| Memory > 128 MB|  Linux       |

## Code Preparation

OpenHarmony has created repositories for vendors in openharmony-sig. To participate in the repository development, you need to use the following method to initialize and download the code.

```shell
repo init -u https://gitee.com/openharmony-sig/manifest.git -b master -m devboard.xml --no-repo-verify
```

The download steps for other resources are the same as those in the mainline version.

## Porting Procedure

- Mini System SoC Porting Guide
  - [Overview](porting-minichip-overview.md)
  - [Porting Preparation](porting-minichip-prepare.md)
  - [Kernel Porting](porting-minichip-kernel.md)
  - Subsystem Porting
    - [Subsystem Porting Overview](porting-minichip-subsys-overview.md)
    - [Porting the Startup Subsystem](porting-minichip-subsys-startup.md)
    - [Porting the File Subsystem](porting-minichip-subsys-filesystem.md)
    - [Porting the Security Subsystem](porting-minichip-subsys-security.md)
    - [Porting the Communication Subsystem](porting-minichip-subsys-communication.md)
    - [Porting the Driver Subsystem](porting-minichip-subsys-driver.md)
    - [Configuring Other Subsystems](porting-minichip-subsys-others.md)
  - [Porting Verification](porting-minichip-verification.md)
  - [FAQs](porting-chip-faqs.md)
- Small System SoC Porting Guide
  - Porting Preparations
    - [Before You Start](porting-smallchip-prepare-needs.md)
    - [Compilation and Building](porting-smallchip-prepare-building.md)
  - Kernel Porting
    - [LiteOS Cortex-A](porting-smallchip-kernel-a.md)
    - [Linux Kernel](porting-smallchip-kernel-linux.md)
  - Driver Porting
    - [Overview](porting-smallchip-driver-overview.md)
    - [Platform Driver Porting](porting-smallchip-driver-plat.md)
    - [Device Driver Porting](porting-smallchip-driver-oom.md)
- Standard System SoC Porting Guide
    - [Standard System Porting Guide](standard-system-porting-guide.md)
    - [A Method for Rapidly Porting the OpenHarmony Linux Kernel](porting-linux-kernel.md)
- Third-Party Library Porting Guide for Mini and Small Systems
    - [Overview](porting-thirdparty-overview.md)
    - [Porting a Library Built Using CMake](porting-thirdparty-cmake.md)
    - [Porting a Library Built Using Makefile](porting-thirdparty-makefile.md)

## SoC Porting Cases

- Mini System SoC Porting Cases
    - [Mini-System Devices with Screens – Bestechnic SoC Porting Case](porting-bes2600w-on-minisystem-display-demo.md)
    - [Combo Solution – ASR Chip Porting Case](porting-asr582x-combo-demo.md)
    - [IoT Solution - Chipsea CST85 Chip Porting Case](porting-cst85f01-combo-demo.md)
    - [Mini System STM32F407 SoC Porting Case](porting-stm32f407-on-minisystem-eth.md)
    - [Combo Solution – W800 Chip Porting Case](porting-w800-combo-demo.md)
- Small System SoC Porting Cases
    - [Mini-System Devices – STM32MP1 SoC Porting Case](porting-stm32mp15xx-on-smallsystem.md)
- Standard System SoC Porting Cases
    - [Standard System Solution – Rockchip RK3568 Porting Case](porting-dayu200-on_standard-demo.md)
    - [Standard System Solution – Rockchip RK3566 Porting Case](https://gitee.com/openharmony/vendor_kaihong/blob/master/khdvk_3566b/porting-khdvk_3566b-on_standard-demo.md)
    - [Standard System Solution – Yangfan Porting Case](porting-yangfan-on_standard-demo.md)
