# Introduction

OpenHarmony has organized a Special Interest Group (SIG) [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig-devboard/sig_devboard.md) to provide support for third-party development boards.

Before learning about how to port the code of a development board, take a look at the device classification on OpenHarmony. The porting methods vary according to the device type.

| Device Type| Hardware Requirement| Supported Kernel|
|---------|-------------|----------------|
| Mini-system devices| Memory > 128 KB| LiteOS-M       |
| Small-system devices| Memory > 1 MB, with MMU| LiteOS-A and Linux|
| Standard-system devices| Memory > 128 MB|  Linux       |

# Code Preparation

OpenHarmony has created repositories for vendors in openharmony-sig. To participate in the repository development, you need to use the following method to initialize and download the code.

```shell
repo init -u https://gitee.com/openharmony-sig/manifest.git -b master -m devboard.xml --no-repo-verify
```

The download steps for other resources are the same as those in the mainline version.

# Porting Procedure

- [Mini System SoC Porting Guide](porting-minichip.md)
  - Porting Preparations
    - [Before You Start](porting-chip-prepare-knows.md)
    - [Building Adaptation Process](porting-chip-prepare-process.md)
  - Kernel Porting
    - [Overview](porting-chip-kernel-overview.md)
    - [Basic Kernel Adaptation](porting-chip-kernel-adjustment.md)
    - [Kernel Porting Verification](porting-chip-kernel-verify.md)
  - Board-Level OS Porting
    - [Overview](porting-chip-board-overview.md)
    - [Board-Level Driver Adaptation](porting-chip-board-driver.md)
    - [Implementation of APIs at the HAL](porting-chip-board-hal.md)
    - [System Modules](porting-chip-board-component.md)
    - [lwIP Module Adaptation](porting-chip-board-lwip.md)
    - [Third-party Module Adaptation](porting-chip-board-bundle.md)
    - [XTS](porting-chip-board-xts.md)
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
  - [Mini-System Devices with Screens — Bestechnic SoC Porting Case](porting-bes2600w-on-minisystem-display-demo.md)
  - [Combo Solution – ASR Chip Porting Case](porting-asr582x-combo-demo.md)

