# Kernel<a name="EN-US_TOPIC_0000001051340509"></a>

-   [Overview](#section12995104752113)
-   [Directory Structure](#section1121775732114)
-   [Constraints](#section1967115154223)
-   [Usage](#section1821123352217)
-   [Repositories Involved](#section2392425183215)

## Overview<a name="section12995104752113"></a>

The OpenHarmony kernel is a real-time OS kernel developed for IoT devices. It is as lightweight as the real-time operating system \(RTOS\) and as easy-to-use as Linux.

The OpenHarmony kernel provides basic kernel functions such as process and thread scheduling, memory management, inter-process communication \(IPC\) mechanism, and timer management.

The source code of the OpenHarmony kernel consists of two repositories: the  **kernel\_liteos\_a**  repository for standard devices and the  **kernel\_liteos\_m**  repository for tiny and mini devices. The following describes the  **kernel\_liteos\_a**  repository.  [Figure1](#fig115631528152315)  shows the architecture of the  LiteOS Cortex-A kernel.

**Figure  1**  Architecture of the OpenHarmony LiteOS Cortex-A kernel<a name="fig115631528152315"></a>  
![](figures/architecture-of-the-openharmony-liteos-cortex-a-kernel.png "architecture-of-the-openharmony-liteos-cortex-a-kernel")

## Directory Structure<a name="section1121775732114"></a>

```
/kernel/liteos_a
├── apps                   # User-space init and shell application programs
├── arch                   # System architecture, such as ARM
│   └── arm                # Code for ARM architecture
├── bsd                    # Code of the driver and adaptation layer module related to the FreeBSD, such as the USB module
├── compat                 # Kernel API compatibility
│   └── posix              # POSIX APIs
├── drivers                # Kernel drivers
│   └── char               # Character device
│       ├── mem            # Driver for accessing physical input/output (I/O) devices
│       ├── quickstart     # APIs for quick start of the system
│       ├── random         # Driver for random number generators
│       └── video          # Framework of the framebuffer driver
├── fs                     # File system module, which mainly derives from the NuttX open-source project
│   ├── fat                # FAT file system
│   ├── jffs2              # JFFS2 file system
│   ├── include            # Header files exposed externally
│   ├── nfs                # NFS file system
│   ├── proc               # proc file system
│   ├── ramfs              # RAMFS file system
│   └── vfs                # VFS layer
├── kernel                 # Kernel modules including the process, memory, and IPC modules
│   ├── base               # Basic kernel modules including the scheduling and memory modules
│   ├── common             # Common components used by the kernel
│   ├── extended           # Extended kernel modules including the dynamic loading, vDSO, and LiteIPC modules
│   ├── include            # Header files exposed externally
│   └── user               # Init process loading
├── lib                    # Kernel library
├── net                    # Network module, which mainly derives from the lwIP open-source project
├── platform               # Code for supporting different systems on a chip (SOCs), such as Hi3516D V300
│   ├── hw                 # Logic code related to clocks and interrupts
│   ├── include            # Header files exposed externally
│   └── uart               # Logic code related to the serial port
├── platform               # Code for supporting different systems on a chip (SOCs), such as Hi3516D V300
├── security               # Code related to security features, including process permission management and virtual ID mapping management
├── syscall                # System calling
└── tools                  # Building tools as well as related configuration and code
```

## Constraints<a name="section1967115154223"></a>

Hi3518E V300 uses the JFFS2 file system by default, and Hi3516D V300 uses the VFAT file system by default. If other file systems need to be used, the configurations of the file systems must be added accordingly.

## Usage<a name="section1821123352217"></a>

For details, see the  **Usage**  section of  _LiteOS Cortex-A_  and  _LiteOS Cortex-M_

## Repositories Involved<a name="section2392425183215"></a>

Kernel subsystem

drivers\_liteos

kernel\_liteos\_a

kernel\_liteos\_m

