# Porting Overview<a name="EN-US_TOPIC_0000001153683022"></a>

## Porting Process<a name="section1283115812294"></a>

After the minimum system is ported, you can port the board-level system by:

1.  Implementing the board-level driver adaptation
2.  Completing the implementation at the HAL
3.  Implementing the XTS
4.  Verifying service functions

**Figure 1**  Process for board-level driver adaptation<a name="fig14619153362215"></a>  
![process-for-board-level-driver-adaptation](figure/process-for-board-level-driver-adaptation.png)

## Board-Level Directory Specifications<a name="section6204129143013"></a>

For details about board-level system building adaptation, see  [Compilation and Building Subsystem](porting-chip-prepare-process.md). The board-related drivers, software development software kits \(SDKs\), directories, and HAL implementation are stored in the  **device**  directory. The directory structure and its description are as follows:

```
.
├── device                                              --- Sample board
│   └── xxx                                             --- <Vendor name of the board>
│       └── xxx                                         --- <Board name>. This directory contains the demo of the LiteOS Cortex-M kernel, which can run properly.
│           ├── BUILD.gn                                --- Building configuration file of the board
│           ├── board                                   --- Specific implementation of the board (Optional. If a product-level demo is provided, implementation at the application layer is stored in this directory.)
│           ├── liteos_m                                --- LiteOS Cortex-M kernel to use based on the kernel_type in the BUILD.gn file
│           │   └── config.gni                          --- Building options
│           ├── libraries                               --- Board-level SDK
│           │   └── include                             --- SDK-provided header files that are exposed externally
│           │   └── ...                                 --- binary or source files
│           ├── main.c                                  --- main function entry (Product level configuration is used if the same definition exists at the product level.)
│           ├── target_config.h                         --- Board-level kernel configuration
│           ├── project                                 --- Board-level project configuration file (Product-level configuration is used if the same definition exists at the product level.)
│           └── adapter                                 --- HAL interfaces (Optional)
│               └── hals
│                   ├── communication
│                   │  └── wifi_lite
│                   │      ├── ...
│                   └── iot_hardware
│                       ├── upgrade
│                       ├── utils
│                       └── wifiiot_lite
├── vendor                                              --- End-to-end feature product sample of OpenHarmony
│   └── huawei                                          --- Vendor name
│       └── wifiiot                                     --- Feature product
│           ├── app
│           │   └── main.c                              --- main function entry of the product
│           ├── project                                 --- Project configuration file
│           ├── BUILD.gn                                --- Project building entry
│           └── config.json                             --- Building configuration file of the product and components used for product configuration
└── out                                                 --- Output directory during the building
    ├── ...                                             --- .bin files generated during board/product building
```

