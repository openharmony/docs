# MMC


## Overview

In the Hardware Driver Foundation (HDF), the MultiMedia Card (MMC) uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png "MMC independent service mode")


## Available APIs

**MmcCntlrOps**:


```
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
  int32_t  (*tune)(struct MmcCntlr *cntlr, uint32_t cmdCode);
  int32_t (*rescanSdioDev)(struct MmcCntlr *cntlr);
};
```

  **Table 1** Description of callback functions in MmcCntlrOps

| Function| Input Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- |
| doRequest | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**cmd**: structure pointer to the command to execute.| HDF_STATUS| Processes the request.|
| setClock | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**clock**: clock frequency to set.| HDF_STATUS| Sets the clock frequency.|
| setPowerMode | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**mode**: power consumption mode, which is an enumerated value.| HDF_STATUS| Sets the power consumption mode.|
| setBusWidth | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**width**: bus width, which is an enumerated value.| HDF_STATUS| Sets the bus width.|
| setBusTiming | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**timing**: bus timing, which is an enumerated value.| HDF_STATUS| Sets the bus timing.|
| setSdioIrq | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**enable**: whether to enable Secure Digital Input Output (SDIO) interrupts.| HDF_STATUS| Enables or disables SDIO interrupts.|
| hardwareReset | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Resets hardware.|
| systemInit | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Performs system initialization.|
| setEnhanceStrobe | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**enable**: whether to enable the enhanced strobe feature.| HDF_STATUS| Sets the enhanced strobe feature.|
| switchVoltage | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**volt**: voltage to set, which can be 3.3 V, 1.8 V, or 1.2 V.| HDF_STATUS| Sets the voltage.|
| devReadOnly | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is read-only.|
| cardPlugged | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is removed.|
| devBusy | **cntlr**: structure pointer to the MMC controller at the core layer.| Boolean value| Checks whether the device is being used.|
| tune | **cntlr**: structure pointer to the MMC controller at the core layer.<br>**cmdCode**: command code of the uint32_t type.| HDF_STATUS| Tunes the oscillator circuit frequency.|
| rescanSdioDev | **cntlr**: structure pointer to the MMC controller at the core layer.| HDF_STATUS| Scans and adds an SDIO device.|


## How to Develop

The MMC module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **mmc_config.hcs** file.

3. Instantiate the MMC controller object.
   - Initialize **MmcCntlr**.
   - Instantiate **MmcCntlrOps** in the **MmcCntlr** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **MmcCntlrOps**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify the basic functions, for example, check the information returned after the **MmcCntlrOps** instance is attached and whether the device starts successfully.


## Development Example

The following uses **himci.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

     MMC driver entry example:
   
   ```
   struct HdfDriverEntry g_mmcDriverEntry = {
       .moduleVersion = 1,
       .Bind = HimciMmcBind,             // See the Bind function.
       .Init = HimciMmcInit,             // See the Init function.
       .Release = HimciMmcRelease,       // See the Release function.
       .moduleName = "hi3516_mmc_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   HDF_INIT(g_mmcDriverEntry);           // Call HDF_INIT to register the driver entry with the HDF.
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **mmc_config.hcs** file.

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **MmcCntlr** members at the core layer.

   If there are multiple devices, you need to add the **deviceNode** information to the **device_info** file and add the device attributes to the **mmc_config** file for each device.

   - **device_info.hcs** configuration example
   
     
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_mmc:: device {
             device0 :: deviceNode {
               policy = 2;
               priority = 10;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";   // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
               serviceName = "HDF_PLATFORM_MMC_0";   // (Mandatory) Unique name of the service published by the driver.
               deviceMatchAttr = "hi3516_mmc_emmc";// (Mandatory) Private data of the controller. The value must be the same as the controller information in mmc_config.hcs.
             }
             device1 :: deviceNode {
               policy = 1;
               priority = 20;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";
               serviceName = "HDF_PLATFORM_MMC_1";
               deviceMatchAttr = "hi3516_mmc_sd"; // The MMC is an SD card.
             }
             device2 :: deviceNode {
               policy = 1;
               priority = 30;
               permission = 0644;
               moduleName = "hi3516_mmc_driver";
               serviceName = "HDF_PLATFORM_MMC_2";
               deviceMatchAttr = "hi3516_mmc_sdio";// The MMC is an SDIO card.
             }
           }
         }
       }
     }
     ```
   
   - **mmc_config.hcs** configuration example
   
     
     ```
     root {
       platform {
         mmc_config {
           template mmc_controller { // Template configuration. In the template, you can configure the common parameters shared by device nodes.
             match_attr = "";
             voltDef = 0;            // 3.3V
             freqMin = 50000;        // (Mandatory) Minimum frequency
             freqMax = 100000000;    // (Mandatory) Maximum frequency
             freqDef = 400000;       // (Mandatory) Default frequency
             maxBlkNum = 2048;       // (Mandatory) Maximum block number
             maxBlkSize = 512;       // (Mandatory) Maximum number of blocks
             ocrDef = 0x300000;      // (Mandatory) Working voltage.
             caps2 = 0;              // (Mandatory) Attribute register. For details, see MmcCaps2 in mmc_caps.h.
             regSize = 0x118;        // (Mandatory) Register bit width
             hostId = 0;             // (Mandatory) Host ID
             regBasePhy = 0x10020000;// (Mandatory) Physical base address of the register
             irqNum = 63;            // (Mandatory) Interrupt number
             devType = 2;            // (Mandatory) Device type, which can be eMMC, SD, SDIO, or COMBO.
             caps = 0x0001e045;      // (Mandatory) Attribute register. For details, see MmcCaps in mmc_caps.h.
           }
           controller_0x10100000 :: mmc_controller {
             match_attr = "hi3516_mmc_emmc";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
             hostId = 0;
             regBasePhy = 0x10100000;
             irqNum = 96;
             devType = 0;            // The MMC is an eMMC card.
             caps = 0xd001e045;
             caps2 = 0x60;
           }
           controller_0x100f0000 :: mmc_controller {
             match_attr = "hi3516_mmc_sd";
             hostId = 1;
             regBasePhy = 0x100f0000;
             irqNum = 62;
             devType = 1;            // The MMC is an SD card.
             caps = 0xd001e005;
           }
           controller_0x10020000 :: mmc_controller {
             match_attr = "hi3516_mmc_sdio";
             hostId = 2;
             regBasePhy = 0x10020000;
             irqNum = 63;
             devType = 2;            // The MMC is an SDIO card.
             caps = 0x0001e04d;
           }
         }
       }
     }
     ```

3. Initialize the **MmcCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **MmcCntlrOps** in **MmcCntlr** (so that the underlying driver functions can be called).

   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **mmc_config.hcs** file to initialize the members in the custom structure and passes important parameters to the **MmcCntlr** object at the core layer.

      
      ```
      struct HimciHost {
          struct MmcCntlr *mmc;// (Mandatory) Core layer structure
          struct MmcCmd *cmd; // (Mandatory) Core layer structure used to pass commands. For details about related commands, see MmcCmdCode.
          //(Optional) Set parameters based on actual requirements.
          void *base;
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

   - Instantiating **MmcCntlrOps** in **MmcCntlr** (other members are initialized by **Bind**)

     
      ```
      static struct MmcCntlrOps g_himciHostOps = {
          .request        = HimciDoRequest,
          .setClock       = HimciSetClock,
          .setPowerMode   = HimciSetPowerMode,
          .setBusWidth    = HimciSetBusWidth,
          .setBusTiming   = HimciSetBusTiming,
          .setSdioIrq     = HimciSetSdioIrq,
          .hardwareReset  = HimciHardwareReset,
          .systemInit     = HimciSystemInit,
          .setEnhanceStrobe= HimciSetEnhanceStrobe,
          .switchVoltage  = HimciSwitchVoltage,
          .devReadOnly    = HimciDevReadOnly,
          .devPlugged      = HimciCardPlugged,
          .devBusy        = HimciDevBusy,
          .tune           = HimciTune,
          .rescanSdioDev  = HimciRescanSdioDev,
      };
      ```
   - **Bind** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      **Function description**:

      Initializes the custom structure **HimciHost** object and **MmcCntlr**, and calls the **MmcCntlrAdd** function at the core layer. **MmcCntlr**, **HimciHost**, and **HdfDeviceObject** assign values with each other so that other functions can be converted successfully.

      
      ```
      static int32_t HimciMmcBind(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          struct HimciHost *host = NULL;
          int32_t ret;
          cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));
          host = (struct HimciHost *)OsalMemCalloc(sizeof(struct HimciHost));
          
          host->mmc = cntlr;                       // (Mandatory) Prerequisites for conversion between HimciHost and MmcCntlr.
          cntlr->priv = (void *)host;              // (Mandatory) Prerequisites for conversion between HimciHost and MmcCntlr.
          cntlr->ops = &g_himciHostOps;            // (Mandatory) Attach the MmcCntlrOps instance.
          cntlr->hdfDevObj = obj;                  // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.
          obj->service = &cntlr->service;          // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.
          ret = MmcCntlrParse(cntlr, obj);         // (Mandatory) Initialize MmcCntlr. If the initialization fails, execute goto _ERR.
          ... 
          ret = HimciHostParse(host, obj);         // (Mandatory) Initialize HimciHost. If the initialization fails, execute goto _ERR.
          ...
          ret = HimciHostInit(host, cntlr);        // Customized initialization. If the initialization fails, execute goto _ERR.
          ...
          ret = MmcCntlrAdd(cntlr);                // Call the functions at the core layer. If the operation fails, execute goto _ERR.
          ...
          (void)MmcCntlrAddDetectMsgToQueue(cntlr);// Add the card detection message to the queue.
          HDF_LOGD("HimciMmcBind: success.");
          return HDF_SUCCESS;
      _ERR:
          HimciDeleteHost(host);
          HDF_LOGD("HimciMmcBind: fail, err = %d.", ret);
          return ret;
      }
      ```

   - **Init** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      HDF_STATUS

      **Function description**:

      Implements **ProcMciInit**.

      
      ```
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
   - **Release** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      No value is returned.

      **Function description**:

      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.


     static void HimciMmcRelease(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          ...
          cntlr = (struct MmcCntlr *)obj->service;        // Forcibly convert HdfDeviceObject to MmcCntlr by using service. For details about the value assignment, see the Bind function.
          ...
          HimciDeleteHost((struct HimciHost *)cntlr->priv);// Customized memory release function. A forced conversion from MmcCntlr to HimciHost is involved in the process.
      }


