# LiteOS-M Overview


## Overview

The OpenHarmony LiteOS-M kernel is a lightweight operating system (OS) kernel designed for the IoT field. It features small size, low power consumption, and high performance. The LiteOS-M kernel has simple code structure, including the minimum function set, kernel abstraction layer (KAL), optional components, and project directory. It supports the Hardware Driver Foundation (HDF), which provides unified driver standards and access mode for device vendors to simplify porting of drivers and allow one-time development for multi-device deployment.

The OpenHarmony LiteOS-M kernel architecture consists of the hardware layer and hardware-irrelevant layers, as shown in the figure below. The hardware layer is classified based on the compiler toolchain and chip architecture, and provides a unified Hardware Abstraction Layer (HAL) interface to improve hardware adaptation and facilitate the expansion of various types of AIoT hardware and compilation toolchains. The other modules are irrelevant to the hardware. The basic kernel module provides basic kernel capabilities. The extended modules provide capabilities of components, such as the network and file systems, as well as exception handling and debug tools. The KAL provides unified standard APIs.

  **Figure 1** Kernel architecture

  ![](figures/Liteos-m-architecture.png "kernel-architecture")


## CPU Architecture Support

The CPU architecture includes two layers: general architecture definition layer and specific architecture definition layer. The former provides interfaces supported and implemented by all architectures. The latter is specific to an architecture. For a new architecture to be added, the general architecture definition layer must be implemented first and the architecture-specific functions can be implemented at the specific architecture definition layer.

  **Table 1** CPU architecture rules

| Rule| General Architecture Layer| Specific Architecture Layer|
| -------- | -------- | -------- |
| Header file location| arch/include | arch/&lt;arch&gt;/&lt;arch&gt;/&lt;toolchain&gt;/ |
| Header file name| los_&lt;function&gt;.h | los_arch_&lt;function&gt;.h |
| Function name| Halxxxx | Halxxxx |

LiteOS-M supports mainstream architectures, such as RISC-V and ARM Cortex-M3, Cortex-M4, Cortex-M7, and Cortex-M33.


## Working Principles

In the  **target_config.h**  file of the development board, configure the system clock and number of ticks per second, and configure the task, memory, inter-process communication (IPC), and exception handling modules based on service requirements. When the system boots, the modules are initialized based on the configuration. The kernel startup process includes peripheral initialization, system clock configuration, kernel initialization, and OS boot, as shown in the figure below.

  **Figure 2** Kernel startup process

  ![](figures/kernel-startup-process.png "kernel-startup-process")

## Directory Structure

The directory structure is as follows:

```text
/kernel/liteos_m
├── arch                 # Kernel instruction architecture layer directory
│   └── arm              # Code of the ARM architectures
│   │   ├── arm9         # Code of ARM9
│   │   ├── cortex-m3    # Code of ARM Cortex-M3
│   │   ├── cortex-m33   # Code of ARM Cortex-M33
│   │   ├── cortex-m4    # Code of ARM Cortex-M4
│   │   ├── cortex-m55   # Code of ARM Cortex-M55
│   │   ├── cortex-m7    # code of ARM Cortex-M7
│   │   └── include      # Directory of the common header files of the ARM architectures
│   ├── csky             # Code of the C-SKY architecture
│   │   └── v2           # code of C-SKY v2
│   ├── include          # APIs exposed externally
│   ├── risc-v           # Code of the RISC-V architecture 
│   │   ├── nuclei       # Code of RISC-V for Nuclei
│   │   └── riscv32      # Code of the official RISC-V architecture
│   └── xtensa           # Code of the Xtensa architecture
│       └── lx6          # Code of Xtensa LX6
├── components           # Optional components
│   ├── backtrace        # Backtrace
│   ├── cppsupport       # C++ support
│   └── cpup             # CPU percent (CPUP)
│   ├── dynlink          # Dynamic loading and linking
│   ├── exchook          # Exception hooks
│   ├── fs               # File systems
│   ├── lmk              # Low memory killer mechanism
│   ├── lms              # Lite memory sanitizer mechanism
│   └── net              # Networking functions
│   ├── power            # Power consumption management
│   ├── shell            # Shell
│   └── trace            # Trace tool
├── drivers              # Driver framework Kconfig
├── kal                  # Kernel abstraction layer
│   ├── cmsis            # CMSIS API support
│   └── posix            # POSIX API support
├── kernel               # Minimum kernel function set
│   ├── include          # APIs exposed externally
│   └── src              # Source code of the minimum kernel function set
├── testsuites           # Kernel test cases
├── tools                # Kernel tools
├── utils                # Common code
```

## Constraints

OpenHarmony LiteOS-M supports only C and C++.

OpenHarmony LiteOS-M applies only to the architectures in **arch**.

For the shared library to be dynamically loaded, signature verification must be performed or the library source must be strictly controlled for security purposes.

## Usage

OpenHarmony
The OpenHarmony LiteOS-M kernel build system is a modular build system based on Generate Ninja (GN) and Ninja. It supports modular configuration, tailoring, and assembling, and helps you build custom products. This document describes how to build a LiteOS-M project based on GN and Ninja. For details about other building methods, such as GCC+gn, IAR, and Keil MDK, visit the related community websites.

### Setting Up the Environment

Before setting up the environment for a development board, you must set up the basic system environment for OpenHarmony first. The basic system environment refers to the OpenHarmony build environment and development environment. For details, see [Quick Start Overview](../quick-start/quickstart-overview.md).

### Obtaining OpenHarmony Source Code

For details about how to obtain the source code, see [Obtaining Source Code](../get-code/sourcecode-acquire.md). The directory to clone is **~/openHarmony** after the OpenHarmony repository code is obtained.

### Supported Sample Projects

QEMU: **arm_mps2_an386**, **esp32**, **riscv32_virt**, and **SmartL_E802**. For details, see [QEMU](https://gitee.com/openharmony/device_qemu).

bestechnic: **bes2600**. For details, see [device_bestechnic](https://gitee.com/openharmony/device_soc_bestechnic).

### Community Porting Project

The LiteOS-M kernel porting projects for specific development boards are provided by community developers. The following provides the links to these projects. You are also welcomed to share your porting projects.

-   Cortex-M3:

    - STM32F103 https://gitee.com/rtos_lover/stm32f103_simulator_keil

        This repository provides the Keil project code for building the OpenHarmony LiteOS-M kernel based on the STM32F103 chip architecture. This code supports build in Keil MDK mode.

-   Cortex-M4:

    - STM32F429IGTb https://gitee.com/harylee/stm32f429ig_firechallenger

        This repository provides the project code for porting the OpenHarmony LiteOS-M kernel to support the STM32F429IGTb development board. The code supports build in Ninja, GCC, and IAR modes.

## Contribution

[How To Contribute](../../contribute/how-to-contribute.md)

[Commit Message Specifications]((https://gitee.com/openharmony/kernel_liteos_m/wikis/Commit%20message%E8%A7%84%E8%8C%83))

[LiteOS-M Kernel Coding Specifications](https://gitee.com/openharmony/kernel_liteos_m/wikis/OpenHarmony%E8%BD%BB%E5%86%85%E6%A0%B8%E7%BC%96%E7%A0%81%E8%A7%84%E8%8C%83)

Contribute a chip based on LiteOS-M:

[Mini-System Chip Porting Guide](../porting/porting-minichip-overview.md)

[Mini-System Devices with Screens – Bestechnic SoC Porting Case](../porting/porting-bes2600w-on-minisystem-display-demo.md)

## Repositories Involved

[Kernel](../../readme/kernel.md)

[kernel\_liteos\_m](https://gitee.com/openharmony/kernel_liteos_m)
