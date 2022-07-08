# Before You Start


This document provides basic guidance for OpenHarmony developers and system on a chip (SoC) or module vendors to port OpenHarmony to typical chip architectures, such as the Cortex-M and RISC-V series. Currently, the Bluetooth service is not supported. Due to the complexity of the OpenHarmony project, this document is subject to update as the version and APIs change.


This guide is intended for readers who have experience in developing embedded systems. Therefore, it mainly describes operations and key points during platform porting instead of basic introduction to the OS.


## Porting Directory

The implementation of the OpenHarmony project directories and functions relies on the OS itself. If no enhancement for a complex feature is involved, you only need to focus on the directories described in the following table.

  **Table 1** Key directories in the porting process

| Directory| Description|
| -------- | -------- |
| /build/lite | OpenHarmony basic compilation and building framework.|
| /kernel/liteos_m | Basic kernel. The implementation related to the chip architecture is in the **arch** directory.|
| /device | Board-level implementation, which complies with the OpenHarmony specifications. For details about the directory structure and porting process, see [Overview](../porting/porting-chip-board-overview.md).|
| /vendor | Product-level implementation, which is contributed by Huawei or product vendors.|

The **device** directory is in the internal structure of **device/{Chip solution vendor}/{Development board}**. The following uses HiSilicon **hispark_taurus** as an example:


```
device
└── hisilicon                      # Name of the chip solution vendor
    ├── common                     # Common part of the chip solution development board
    └── hispark_taurus             # Name of the development board
        ├── BUILD.gn               # Entry to building the development board
        ├── hals                   # OS hardware adaptation of the chip solution vendor
        ├── linux                  # Linux version
        │   └── config.gni         # Configurations of the building toolchain and building options for the Linux version
        └── liteos_a               # LiteOS Cortex-A version
            └── config.gni         # Configurations of the building toolchain and building options for the LiteOS Cortex-A version
```


The **vendor** directory is in the internal structure of **vendor/{Product solution vendor}/{Product name}**. The following uses the Huawei Wi-Fi IoT product as an example:



```
vendor                       # Product solution vendor
└── example                  # Name of the product solution vendor
    └── wifiiot              # Product name
          ├── hals           # OS adaptation of the product solution vendor
          ├── BUILD.gn       # Product building script
          └── config.json    # Product configuration file
```


## Porting Process

The **device** directory of OpenHarmony is the adaptation directory for the basic SoC. You can skip the porting process and directly develop system applications if complete SoC adaptation code is already available in the directory. If there is no corresponding SoC porting implementation in the directory, complete the porting process by following the instructions provided in this document. The following figure shows the process of porting OpenHarmony to a third-party SoC.

  **Figure 1** Key steps for SoC porting

  ![en-us_image_0000001200336823](figures/en-us_image_0000001200336823.png)


## Porting Specifications

- The porting must comply with the basic principles described in [How to Contribute](../../contribute/how-to-contribute.md).

- The code required for third-party SoC adaptation is stored in the **device**, **vendor**, and **arch** directories. Naming and usage of these directories must comply with specified naming and usage specifications. For details, see [Overview](../porting/porting-chip-kernel-overview.md) and [Board-Level Directory Specifications](../porting/porting-chip-board-overview.md#section6204129143013).
