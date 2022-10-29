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

LiteOS-M supports mainstream architectures, such as ARM Cortex-M3, ARM Cortex-M4, ARM Cortex-M7, ARM Cortex-M33, and RISC-V.


## Working Principles

In the  **target\_config.h**  file of the development board, configure the system clock and number of ticks per second, and configure the task, memory, inter-process communication (IPC), and exception handling modules based on service requirements. When the system boots, the modules are initialized based on the configuration. The kernel startup process includes peripheral initialization, system clock configuration, kernel initialization, and OS boot, as shown in the figure below.

  **Figure 2** Kernel startup process<br>
  ![](figures/kernel-startup-process.png "kernel-startup-process")
## Directory Structure<a name="section161941989596"></a>

The directory structure is as follows.

```text
/kernel/liteos_m
├── arch                 # Code of the kernel instruction architecture layer
│   ├── arm              # Code of the ARM32 architecture
│   │   ├── arm9         # Code of the ARM9 architecture
│   │   ├── cortex-m3    # Code of the cortex-m3 architecture
│   │   ├── cortex-m33   # Code of the cortex-m33 architecture
│   │   ├── cortex-m4    # Code of the cortex-m4 architecture
│   │   ├── cortex-m7    # Code of the cortex-m7 architecture
│   │   └── include      # Arm architecture public header file directory
│   ├── csky             # Code of the csky architecture
│   │   └── v2           # Code of the csky v2 architecture
│   ├── include          # APIs exposed externally
│   ├── risc-v           # Code of the risc-v architecture
│   │   ├── nuclei       # Code of the nuclei system technology risc-v architecture
│   │   └── riscv32      # Code of the risc-v architecture
│   └── xtensa           # Code of the xtensa architecture
│       └── lx6          # Code of the lx6 xtensa architecture
├── components           # Optional components
│   ├── backtrace        # Backtrace support
│   ├── cppsupport       # C++ support
│   ├── cpup             # CPU percent (CPUP)
│   ├── dynlink          # Dynamic loading and linking
│   ├── exchook          # Exception hooks
│   ├── fs               # File systems
│   ├── lmk              # Low memory killer functions
│   ├── lms              # Lite memory sanitizer functions
│   ├── net              # Networking functions
│   ├── power            # Power management
│   ├── shell            # Shell function
│   ├── fs               # File systems
│   └── trace            # Trace tool
├── drivers              # driver Kconfig
├── kal                  # Kernel abstraction layer
│   ├── cmsis            # CMSIS API support
│   └── posix            # POSIX API support
├── kernel               # Minimum kernel function set
│   ├── include          # APIs exposed externally
│   └── src              # Source code of the minimum kernel function set
├── testsuites           # Kernel testsuites
├── tools                # Kernel tools
├── utils                # Common directory
```

## Constraints<a name="section119744591305"></a>

OpenHarmony LiteOS-M supports only C and C++.

Applicable architecture: See the directory structure for the arch layer.

As for dynamic loading module, the shared library to be loaded needs signature verification or source restriction to ensure security.

## Usage<a name="section3732185231214"></a>

The OpenHarmony LiteOS-M kernel build system is a modular build system based on Generate Ninja (GN) and Ninja. It supports module-based configuration, tailoring, and assembling, and helps you build custom products. This document describes how to build a LiteOS-M project based on GN and Ninja. For details about the methods such as GCC+gn, IAR, and Keil MDK, visit the community websites.

### Setting Up the Environment

Before setting up the environment for a development board, you must set up the basic system environment for OpenHarmony first. The basic system environment includes the OpenHarmony build environment and development environment. For details, see [Setting Up Development Environment](../quick-start/quickstart-lite-env-setup.md).

### Obtaining the OpenHarmony Source Code

For details about how to obtain the source code, see [Source Code Acquisition](../get-code/sourcecode-acquire.md). This document assumes that the clone directory is `~/openHarmony` after the complete OpenHarmony repository code is obtained.

### Example projects

Qemu simulator: `arm_mps2_an386、esp32、riscv32_virt、SmartL_E802`. For details about how to compile and run, see [qemu guide](https://gitee.com/openharmony/device_qemu).

Bestechnic: `bes2600`. For details about how to compile and run, see [Bestechnic developer guide](https://gitee.com/openharmony/device_soc_bestechnic).

### Community Porting Project Links

The LiteOS-M kernel porting projects for specific development boards are provided by community developers. The following provides the links to these projects. If you have porting projects for more development boards, you can provide your links to share your projects.

-   Cortex-M3:

    - STM32F103 https://gitee.com/rtos_lover/stm32f103_simulator_keil

        This repository provides the Keil project code for building the OpenHarmony LiteOS-M kernel based on the STM32F103 chip architecture. This code supports build in Keil MDK mode.

-   Cortex-M4:

    - STM32F429IGTb https://gitee.com/harylee/stm32f429ig_firechallenger

        This repository provides the project code for porting the OpenHarmony LiteOS-M kernel to support the STM32F429IGTb development board. The code supports build in Ninja, GCC, and IAR modes.

## Contribution<a name="section1371123476307"></a>

[How to involve](../../contribute/contribution-process.md)

[Commit message spec](https://gitee.com/openharmony/kernel_liteos_m/wikis/Commit%20message%E8%A7%84%E8%8C%83)

[Liteos-M kernel coding style guide](https://gitee.com/openharmony/kernel_liteos_m/wikis/OpenHarmony%E8%BD%BB%E5%86%85%E6%A0%B8%E7%BC%96%E7%A0%81%E8%A7%84%E8%8C%83)

How to contribute a chip based on Liteos-M kernel:

[ Board-Level Directory Specifications](../porting/porting-chip-board-overview.md)

[Mini System SoC Porting Guide](../porting/porting-minichip.md)

## Repositories Involved<a name="section1371113476307"></a>

[Kernel Subsystem](../../readme/kernel.md)

[kernel\_liteos\_m](https://gitee.com/openharmony/kernel_liteos_m/blob/master/README.md)
