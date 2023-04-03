# MMC

## Overview

### Function

A multimedia card (MMC) is a small-sized and large-capacity flash memory card used for solid-state non-volatile storage.

Nowadays, MMC refers to a standard driver interface to solid-state storage cards. Memory devices that comply with this standard can be called MMCs. An MMC consists of the MMC controller, MMC bus, and memory card, which can be an MMC, Secure Digital (SD) card, Secure Digital Input Output (SDIO) card, or TransFlash (TF) card.

The MMC, SD, and SDIO buses have similar bus specifications, which have evolved from the MMC bus specifications. The MMC features multimedia storage; the SD focuses on security and data protection; the SDIO, evolving from the SD, provides the interface regardless of the specific form of the peer end (Wi-Fi, Bluetooth, or GPS device).

### Basic Concepts

- SD card

  Introduced as an improvement over the MMC, the SD cards can protect their contents from erasure or modification, prevent unauthorized access, and protect copyrighted content using digital rights management. The size of a standard SD card is 24 mm x 32 mm x 2.1 mm, which is a little thicker than an MMC card. The SD cards are forward compatible with MMC cards, that is, all devices that support SD cards also support MMC cards.

- SDIO

  SDIO is an interface designed as an extension for the SD card standard. It introduces the low-speed transfer standard, which supports low-speed I/O with the minimum hardware overhead. The SDIO interface is compatible with the SD cards.

### Working Principles

In the Hardware Driver Foundation (HDF), the MMC uses the independent service mode (see Figure 1) for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

In the independent service mode, the core layer does not publish a service for the upper layer. Therefore, a service must be published for each controller. To achieve this purpose:

- You need to implement the **Bind()** function in **HdfDriverEntry** to bind services.
- The **policy** field of **deviceNode** in the **device_info.hcs** file must be **1** or **2**, but not **0**.

The MMC module is divided into the following layers:

- Interface layer: provides APIs for opening an MMC device, checking whether the MMC controller has devices, and closing an MMC device.
- Core layer: provides the capabilities of adding or removing an MMC controller, performing device management, and providing common controller services. The core layer interacts with the adaptation layer through hook functions.
- Adaptation layer: instantiates the hook functions to implement specific features.

**Figure 1** Independent service mode

![img1](figures/independent-service-mode.png)

## Development Guidelines

### When to Use

The MMC is used to store multimedia files. Before using your MMC device with OpenHarmony, you need to perform MMC driver adaptation.

### Available APIs

To enable the upper layer to successfully operate the MMC controller by calling the MMC APIs, hook functions are defined in **//drivers/hdf_core/framework/model/storage/include/mmc/mmc_corex.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

**MmcCntlrOps**:

```c
struct MmcCntlrOps {
    int32_t (*request)(struct MmcCntlr *cntlr, struct MmcCmd *cmd);
    int32_t (*setClock)(struct MmcCntlr *cntlr, uint32_t clock);
    int32_t (*setPowerMode)(struct MmcCntlr *cntlr, enum MmcPowerMode mode);
    int32_t (*setBusWidth)(struct MmcCntlr *cntlr, enum MmcBusWidth width);
    int32_t (*setBusTiming)(struct MmcCntlr *cntlr, enum MmcBusTiming timing);
    int32_t (*setSdioIrq)(struct MmcCntlr *cntlr, bool enable);
    int32_t (*hardwareReset)(struct MmcCntlr *cntlr);
    int32_t (*systemInit)(struct MmcCntlr *cntlr);
    int32_t (*setEnhanceStrobe)(struct MmcCntlr *cntlr, bool enable);
    int32_t (*switchVoltage)(struct MmcCntlr *cntlr, enum MmcVolt volt);
    bool (*devReadOnly)(struct MmcCntlr *cntlr);
    bool (*devPlugged)(struct MmcCntlr *cntlr);
    bool (*devBusy)(struct MmcCntlr *cntlr);
    int32_t (*tune)(struct MmcCntlr *cntlr, uint32_t cmdCode);
    int32_t (*rescanSdioDev)(struct MmcCntlr *cntlr);
};
```

**Table 1** Hook functions in **MmcCntlrOps**

| Function| Input Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- |
| doRequest | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**cmd**: structure pointer to the command to execute.| HDF_STATUS| Processes the request.|
| setClock | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**clock**: clock frequency to set.| HDF_STATUS| Sets the clock frequency.|
| setPowerMode | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**mode**: power consumption mode. For details, see **MmcPowerMode**.| HDF_STATUS| Sets the power consumption mode.|
| setBusWidth | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**width**: bus width. For details, see **MmcBusWidth**.| HDF_STATUS| Sets the bus width.|
| setBusTiming | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**timing**: bus timing. For details, see **MmcBusTiming**.| HDF_STATUS| Sets the bus timing.|
| setSdioIrq | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**enable**: whether to enable SDIO interrupts.| HDF_STATUS| Enables or disables SDIO interrupts.|
| hardwareReset | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Resets hardware.|
| systemInit | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Performs system initialization.|
| setEnhanceStrobe | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**enable**: whether to enable the enhanced strobe feature.| HDF_STATUS| Sets the enhanced strobe feature.|
| switchVoltage | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**volt**: voltage to set, which can be 3.3 V, 1.8 V, or 1.2 V.| HDF_STATUS| Sets the voltage.|
| devReadOnly | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is read-only.|
| cardPlugged | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is removed.|
| devBusy | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is being used.|
| tune | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**cmdCode**: command code, which is of the uint32_t type.| HDF_STATUS| Tunes the oscillator circuit frequency.|
| rescanSdioDev | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Scans and adds an SDIO device.|

### How to Develop

The MMC module adaptation procedure is as follows:

1. Instantiate the driver entry.
2. Configure attribute files.
3. Instantiate the MMC controller object.
4. Debug the driver.

### Example

The following uses the **//device_soc_hisilicon/common/platform/mmc/himci_v200/himci.c** driver of the Hi3516D V300 development board as an example to describe the driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   MMC driver entry example:

   ```c
   struct HdfDriverEntry g_mmcDriverEntry = {
       .moduleVersion = 1,
       .Bind = HimciMmcBind,                 // See the Bind function.
       .Init = HimciMmcInit,                 // See the Init function.
       .Release = HimciMmcRelease,           // See the Release function.
       .moduleName = "hi3516_mmc_driver",    // (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   HDF_INIT(g_mmcDriverEntry);               // Call HDF_INIT to register the driver entry with the HDF.
   ```

2. Configure attribute files.

   Add the deviceNode information to the **device_info.hcs** file. The deviceNode information is related to the driver entry registration. The following example uses three MMC controllers as an example. If there are more MMC controllers, add the deviceNode information to the **device_info.hcs** file for each controller. The device attribute values configured in **mmc_config.hcs** are closely related to the default values or value ranges of the **MmcCntlr** members at the core layer.

   - **device_info.hcs** example:

      Add the deviceNode information to the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file.

      ```c
      root {
          device_info {
              match_attr = "hdf_manager";
              platform :: host {
                  hostName = "platform_host";
                  priority = 50;
                  device_mmc:: device {
                      device0 :: deviceNode {                     // DeviceNode of the driver.
                          policy = 2;                             // The value 2 means to publish services for both kernel- and user-mode processes. 
                          priority = 10;                          // Driver startup priority.
                          permission = 0644;                      // Permission for the device node created.
                          moduleName = "hi3516_mmc_driver";       // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                          serviceName = "HDF_PLATFORM_MMC_0";     // (Mandatory) Unique name of the service published by the driver.
                          deviceMatchAttr = "hi3516_mmc_emmc";    // (Mandatory) Private data of the controller. The value must be the same as the controller information in mmc_config.hcs.
                      }
                      device1 :: deviceNode {
                          policy = 1;
                          priority = 20;
                          permission = 0644;
                          moduleName = "hi3516_mmc_driver";
                          serviceName = "HDF_PLATFORM_MMC_1";
                          deviceMatchAttr = "hi3516_mmc_sd";      // The MMC is an SD card.
                      }
                      device2 :: deviceNode {
                          policy = 1;
                          priority = 30;
                          permission = 0644;
                          moduleName = "hi3516_mmc_driver";
                          serviceName = "HDF_PLATFORM_MMC_2";
                          deviceMatchAttr = "hi3516_mmc_sdio";    // The MMC is an SDIO card.
                      }
                      ... 
                  }
              }
          }
      }
      ```

   - **mmc_config.hcs** example

      Configure the device attributes in the **//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/mmc/mmc_config.hcs** file. The parameters are as follows:

      ```c
      root {
          platform {
              mmc_config {
                  template mmc_controller {                     // Template configuration. If the template is used to configure device node information, the default values in the template will be used for the fields that are not declared for the node.
                      match_attr = "";
                      voltDef = 0;                              // MMC default voltage. The value 0 stands for 3.3 V, 1 for 1.8 V, and 2 for 1.2 V.
                      freqMin = 50000;                          // (Mandatory) Minimum frequency.
                      freqMax = 100000000;                      // (Mandatory) Maximum frequency.
                      freqDef = 400000;                         // (Mandatory) Default frequency.
                      maxBlkNum = 2048;                         // (Mandatory) Maximum block number.
                      maxBlkSize = 512;                         // (Mandatory) Maximum block size.
                      ocrDef = 0x300000;                        // (Mandatory) working voltage.
                      caps2 = 0;                                // (Mandatory) Attribute register. For details, see MmcCaps2 in mmc_caps.h.
                      regSize = 0x118;                          // (Mandatory) Register size.
                      hostId = 0;                               // (Mandatory) Host number.
                      regBasePhy = 0x10020000;                  // (Mandatory) Physical base address of the register.
                      irqNum = 63;                              // (Mandatory) IRQ number.
                      devType = 2;                              // (Mandatory) Device type, which can be eMMC, SD, SDIO, or COMBO.
                      caps = 0x0001e045;                        // (Mandatory) Attribute register. For details, see MmcCaps in mmc_caps.h.
                  }
                  controller_0x10100000 :: mmc_controller {
                      match_attr = "hi3516_mmc_emmc";           // (Mandatory) The value must be the same as deviceMatchAttr in device_info.hcs.
                      hostId = 0;
                      regBasePhy = 0x10100000;
                      irqNum = 96;
                      devType = 0;                              // The device is an eMMC card.
                      caps = 0xd001e045;
                      caps2 = 0x60;
                  }
                  controller_0x100f0000 :: mmc_controller {
                      match_attr = "hi3516_mmc_sd";
                      hostId = 1;
                      regBasePhy = 0x100f0000;
                      irqNum = 62;
                      devType = 1;                              // The device is an SD card.
                      caps = 0xd001e005;
                  }
                  controller_0x10020000 :: mmc_controller {
                      match_attr = "hi3516_mmc_sdio";
                      hostId = 2;
                      regBasePhy = 0x10020000;
                      irqNum = 63;
                      devType = 2;                              // The device is an SDIO card.
                      caps = 0x0001e04d;
                  }
              }
          }
      }
      ```

      After the **mmc_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/mmc/mmc_config.hcs" // Relative path of the file.
      ```

3. Instantiate the MMC controller object.

   Initialize the **MmcCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **MmcCntlrOps** in **MmcCntlr** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **mmc_config.hcs** file to initialize the members in the custom structure and passes important parameters to the **MmcCntlr** object at the core layer.

      ```c
      struct HimciHost {
          struct MmcCntlr *mmc;                             // (Mandatory) Core layer control object.
          struct MmcCmd *cmd                                // (Mandatory) Core layer structure used to pass commands. For details about related commands, see MmcCmdCode.
          void *base;                                       // Register base address used for address mapping.
          enum HimciPowerStatus powerStatus;
          uint8_t *alignedBuff;
          uint32_t buffLen;
          struct scatterlist dmaSg;
          struct scatterlist *sg;
          uint32_t dmaSgNum;
          DMA_ADDR_T dmaPaddr;
          uint32_t *dmaVaddr;
          uint32_t irqNum;
          bool isTuning;
          uint32_t id;
          struct OsalMutex mutex;
          bool waitForEvent;
          HIMCI_EVENT himciEvent;
      };
      // MmcCntlr is the core layer controller structure. The Bind function assigns values to the members of MmcCntlr.
      struct MmcCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *hdfDevObj;
          struct PlatformDevice device;
          struct OsalMutex mutex;
          struct OsalSem released;
          uint32_t devType;
          struct MmcDevice *curDev;
          struct MmcCntlrOps *ops;
          struct PlatformQueue *msgQueue;
          uint16_t index;
          uint16_t voltDef;
          uint32_t vddBit;
          uint32_t freqMin;
          uint32_t freqMax;
          uint32_t freqDef;
          union MmcOcr ocrDef;
          union MmcCaps caps;
          union MmcCaps2 caps2;
          uint32_t maxBlkNum;
          uint32_t maxBlkSize;
          uint32_t maxReqSize;
          bool devPlugged;
          bool detecting;
          void *priv;
      };
      ```

   - Instantiate **MmcCntlrOps** in **MmcCntlr**.

      ```c
      static struct MmcCntlrOps g_himciHostOps = {
          .request = HimciDoRequest,
          .setClock = HimciSetClock,
          .setPowerMode = HimciSetPowerMode,
          .setBusWidth = HimciSetBusWidth,
          .setBusTiming = HimciSetBusTiming,
          .setSdioIrq = HimciSetSdioIrq,
          .hardwareReset = HimciHardwareReset,
          .systemInit = HimciSystemInit,
          .setEnhanceStrobe = HimciSetEnhanceStrobe,
          .switchVoltage = HimciSwitchVoltage,
          .devReadOnly = HimciDevReadOnly,
          .devPlugged = HimciCardPlugged,
          .devBusy = HimciDevBusy,
          .tune = HimciTune,
          .rescanSdioDev = HimciRescanSdioDev,
      };
      ```

   - Implement the **Bind** function.

      **Input parameter**:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

      **Table 2** HDF_STATUS description

      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      **Function description**:

      Initializes the **HimciHost** object and **MmcCntlr**, and calls the **MmcCntlrAdd** function at the core layer to add the MMC controllers.

      ```c
      static int32_t HimciMmcBind(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          struct HimciHost *host = NULL;
          int32_t ret;
          cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));
          host = (struct HimciHost *)OsalMemCalloc(sizeof(struct HimciHost));
          
          host->mmc = cntlr;                              // (Mandatory) Prerequisites for conversion between HimciHost and MmcCntlr.
          cntlr->priv = (void *)host;                     // (Mandatory) Prerequisites for conversion between HimciHost and MmcCntlr.
          cntlr->ops = &g_himciHostOps;                   // (Mandatory) Attach the MmcCntlrOps instance to MmcCntlr.
          cntlr->hdfDevObj = obj;                         // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.
          obj->service = &cntlr->service;                 // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.
          ret = MmcCntlrParse(cntlr, obj);                // (Mandatory) Initialize MmcCntlr. If the initialization fails, execute goto _ERR.
          ...
          ret = HimciHostParse(host, obj);                // (Mandatory) Initialize HimciHost. If the initialization fails, execute goto _ERR.
          ...
          ret = HimciHostInit(host, cntlr);               // Customized initizlization. If the initialization fails, goto _ERR.
          ...
          ret = MmcCntlrAdd(cntlr);                       // Call MmcCntlrAdd at the core layer. If the operation fails, execute goto _ERR.
          ...
          (void)MmcCntlrAddDetectMsgToQueue(cntlr);       // Add the card detection message to the queue.
          HDF_LOGD("HimciMmcBind: success.");
          return HDF_SUCCESS;
      ERR:
          HimciDeleteHost(host);
          HDF_LOGD("HimciMmcBind: fail, err = %d.", ret);
          return ret;
      }
      ```

   - Implement the **Init** function.

      **Input parameter**:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      **Return value**:

      HDF_STATUS

      **Function description**:

      Implements **ProcMciInit**.

      ```c
      static int32_t HimciMmcInit(struct HdfDeviceObject *obj)
      {
          static bool procInit = false;
          (void)obj;
          if (procInit == false) {
              if (ProcMciInit() == HDF_SUCCESS) {
                  procInit = true;
                  HDF_LOGD("HimciMmcInit: proc init success.");
              }
          }
          HDF_LOGD("HimciMmcInit: success.");
          return HDF_SUCCESS;
      }
      ```

   - Implement the **Release** function.

      **Input parameter**:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      **Return value**:

      No value is returned.

      **Function description**:

      Releases the memory and deletes the controller. This function assigns values to **Release()** in the driver entry structure. If the HDF fails to call **Init()** to initialize the driver, **Release()** is called to release driver resources.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.

      ```c
      static void HimciMmcRelease(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          ...
          cntlr = (struct MmcCntlr *)obj->service;             // Forcibly convert HdfDeviceObject to MmcCntlr by using service. For details about the value assignment, see the Bind function.
          ...
          HimciDeleteHost((struct HimciHost *)cntlr->priv);    // Memory release function customized. Forced conversion between MmcCntlr and HimciHost is involved.
      }
      ```

4. Debug the driver.

   (Optional) For new drivers, verify basic functions, for example, check the information returned after the driver is attached and whether data is successfully transmitted.
