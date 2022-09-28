# SDIO


## Overview

A Secure Digital Input Output (SDIO) card is an extension of the SD specification to cover I/O functions. SD and SDIO cards are called multimedia cards (MMCs). In the Hardware Driver Foundation (HDF), the SDIO module uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png)


## Available APIs

**SdioDeviceOps**:


```
// Function template
struct SdioDeviceOps {
  int32_t (*incrAddrReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*incrAddrWriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*fixedAddrReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  int32_t (*fixedAddrWriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size, uint32_t scatterLen);
  int32_t (*func0ReadBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*func0WriteBytes)(struct SdioDevice *dev, uint8_t *data, uint32_t addr, uint32_t size);
  int32_t (*setBlockSize)(struct SdioDevice *dev, uint32_t blockSize);
  int32_t (*getCommonInfo)(struct SdioDevice *dev, SdioCommonInfo *info, uint32_t infoType);
  int32_t (*setCommonInfo)(struct SdioDevice *dev, SdioCommonInfo *info, uint32_t infoType);
  int32_t (*flushData)(struct SdioDevice *dev);
  int32_t (*enableFunc)(struct SdioDevice *dev);
  int32_t (*disableFunc)(struct SdioDevice *dev);
  int32_t (*claimIrq)(struct SdioDevice *dev, SdioIrqHandler *irqHandler);
  int32_t (*releaseIrq)(struct SdioDevice *dev);
  int32_t (*findFunc)(struct SdioDevice *dev, struct SdioFunctionConfig *configData);
  int32_t (*claimHost)(struct SdioDevice *dev);
  int32_t (*releaseHost)(struct SdioDevice *dev);
};
```

  **Table 1** Description of the callback functions in SdioDeviceOps

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| incrAddrReadBytes | **dev**: structure pointer to the SDIO device controller.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to read, which is of the uint32_t type.| **data**: pointer to the output value, which is of the uint8_t type.| HDF_STATUS| Incrementally reads data of a given length from the specified SDIO address.|
| incrAddrWriteBytes | **dev**: structure pointer to the SDIO device controller.<br>**data**: pointer to the input value, which is of the uint8_t type.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to write, which is of the uint32_t type.| –| HDF_STATUS| Incrementally writes data of a given length to the specified SDIO address.|
| fixedAddrReadBytes | **dev**: structure pointer to the SDIO device controller.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to read, which is of the uint32_t type.<br>**scatterLen**: data length, which is of the uint32_t type.| **data**: pointer to the output value, which is of the uint8_t type.| HDF_STATUS| Reads data of a given length from a fixed SDIO address.|
| fixedAddrWriteBytes | **dev**: structure pointer to the SDIO device controller.<br>**data**: pointer to the input value, which is of the uint8_t type.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to write, which is of the uint32_t type.<br>**scatterLen**: data length, which is of the uint32_t type.| –| HDF_STATUS| Writes data of a given length to the fixed SDIO address.|
| func0ReadBytes | **dev**: structure pointer to the SDIO device controller.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to read, which is of the uint32_t type.| **data**: pointer to the output value, which is of the uint8_t type.| HDF_STATUS| Reads data of a given length from the address space of SDIO function 0.|
| func0WriteBytes | **dev**: structure pointer to the SDIO device controller.<br>**data**: pointer to the input value, which is of the uint8_t type.<br>**addr**: SDIO address, which is of the uint32_t type.<br>**size**: size of the data to write, which is of the uint32_t type.| –| HDF_STATUS| Writes data of a given length to the address space of SDIO function 0.|
| setBlockSize | **dev**: structure pointer to the SDIO device controller.<br>**blockSize**: block size, which is of the uint32_t type.| –| HDF_STATUS| Sets the block size.|
| getCommonInfo | **dev**: structure pointer to the SDIO device controller.  <br>**infoType**: info type, which is of the uint32_t type.| **info**: structure pointer to the output **SdioFuncInfo**.| HDF_STATUS| Obtains **CommonInfo**. For details, see the **NOTE** below this table.|
| setCommonInfo | **dev**: structure pointer to the SDIO device controller.<br>**info**: union pointer to the input **SdioFuncInfo**.<br>**infoType**: info type, which is of the uint32_t type.| –| HDF_STATUS| Sets **CommonInfo**. For details, see the **NOTE** below this table.|
| flushData | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Called to flush data when the SDIO device needs to be re-initialized or an error occurs.|
| enableFunc | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Enables an SDIO device.|
| disableFunc | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Disables an SDIO device.|
| claimIrq | **dev**: structure pointer to the SDIO device controller.<br>**irqHandler**: void function pointer to the interrupt request (IRQ) handler.| –| HDF_STATUS| Claims an SDIO IRQ.|
| releaseIrq | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Releases an SDIO IRQ.|
| findFunc | **dev**: structure pointer to the SDIO device controller.<br>**configData**: structure pointer to the key SDIO function information.| –| HDF_STATUS| Obtains the matching funcNum.|
| claimHost | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Claims a host exclusively.|
| releaseHost | **dev**: structure pointer to the SDIO device controller.| –| HDF_STATUS| Releases the exclusively claimed host.|


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> CommonInfo includes the following information:<br>- **maxBlockNum**: specifies the maximum number of blocks in a request. <br>- **maxBlockSize**: specifies the maximum number of bytes in a block. <br>- **maxRequestSize**: specifies the maximum number of bytes in a request. <br>- **enTimeout**: specifies the maximum timeout period, in milliseconds. <br>- **funcNum**: specifies the function number, which ranges from 1 to 7. <br>- **irqCap**: specifies the IRQ capabilities. <br>- **(void \*)data**


## How to Develop

The SDIO module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **sdio_config.hcs** file.

3. Instantiate the SDIO controller object.
   - Initialize **SdioDevice**.
   - Instantiate **SdioDeviceOps** in the **SdioDevice** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **SdioDeviceOps**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify the basic functions, such as the SDIO control status and response to interrupts.


## Development Example

The following uses **sdio_adapter.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**.

   In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   SDIO driver entry example:
   
   ```
   struct HdfDriverEntry g_sdioDriverEntry = {
       .moduleVersion = 1,
       .Bind = Hi35xxLinuxSdioBind,       // See the Bind function.
       .Init = Hi35xxLinuxSdioInit,       // See the Init function.
       .Release = Hi35xxLinuxSdioRelease, // See the Release function.
       .moduleName = "HDF_PLATFORM_SDIO",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_sdioDriverEntry);
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **sdio_config.hcs** file.

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **SdioDevice** members at the core layer.

   In this example, there is only one SDIO controller. If there are multiple SDIO controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **sdio_config** file for each controller.

   - **device_info.hcs** configuration example:
   
     
     ```
      root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_sdio :: device {
             device0 :: deviceNode {
               policy = 1;
               priority = 70;
               permission = 0644;
               moduleName = "HDF_PLATFORM_SDIO";          // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
               serviceName = "HDF_PLATFORM_MMC_2";        // (Mandatory) Unique name of the service published by the driver.
               deviceMatchAttr = "hisilicon_hi35xx_sdio_0";// (Mandatory) Private data of the controller. The value must be the same as the controller information in sdio_config.hcs.
             }
           }
         }
       }
     }
     ```
   
   - **sdio_config.hcs** configuration example:
   
     
     ```
     root {
       platform {
         sdio_config {
           template sdio_controller {
             match_attr = "";
             hostId = 2;                            // (Mandatory) The value must be 2. For details, see mmc_config.hcs.
             devType = 2;                           // (Mandatory) The value must be 2. For details, see mmc_config.hcs.
           }
           controller_0x2dd1 :: sdio_controller {
             match_attr = "hisilicon_hi35xx_sdio_0";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
         }
       }
     }
     ```

3. Initialize the **SdioDevice** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **SdioDeviceOps** in **SdioDevice** (so that the underlying driver functions can be called).

   - Defining a custom structure

     To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **sdio_config.hcs** file to initialize the members in the custom structure and passes important parameters to the object at the core layer.

     
      ```
      typedef struct {
          uint32_t maxBlockNum;    // Maximum number of blocks in a request.
          uint32_t maxBlockSize;   // Maximum number of bytes in a block. The value range is 1 to 2048.
          uint32_t maxRequestSize; // Maximum number of bytes in a request. The value range is 1 to 2048.
          uint32_t enTimeout;      // Maximum timeout period in milliseconds. The value cannot exceed one second.
          uint32_t funcNum;        // Function number, which ranges from 1 to 7.
          uint32_t irqCap;         // IRQ capabilities.
          void *data;              // Private data.
      } SdioFuncInfo;
      
      // SdioDevice is the core layer controller structure. The Bind function assigns values to the members of SdioDevice.
      struct SdioDevice {
          struct SdDevice sd;
          struct SdioDeviceOps *sdioOps;
          struct SdioRegister sdioReg;
          uint32_t functions;
          struct SdioFunction *sdioFunc[SDIO_MAX_FUNCTION_NUMBER];
          struct SdioFunction *curFunction;
          struct OsalThread thread;  /* irq thread */
          struct OsalSem sem;
          bool irqPending;
          bool threadRunning;
      };
      ```

   - Instantiating **SdioDeviceOps** in **SdioDevice** (other members are initialized by **Init**)

     
      ```
      static struct SdioDeviceOps g_sdioDeviceOps = {
          .incrAddrReadBytes   = Hi35xxLinuxSdioIncrAddrReadBytes,
          .incrAddrWriteBytes  = Hi35xxLinuxSdioIncrAddrWriteBytes,
          .fixedAddrReadBytes  = Hi35xxLinuxSdioFixedAddrReadBytes,
          .fixedAddrWriteBytes = Hi35xxLinuxSdioFixedAddrWriteBytes,
          .func0ReadBytes  = Hi35xxLinuxSdioFunc0ReadBytes,
          .func0WriteBytes = Hi35xxLinuxSdioFunc0WriteBytes,
          .setBlockSize    = Hi35xxLinuxSdioSetBlockSize,
          .getCommonInfo   = Hi35xxLinuxSdioGetCommonInfo,
          .setCommonInfo   = Hi35xxLinuxSdioSetCommonInfo,
          .flushData       = Hi35xxLinuxSdioFlushData,
          .enableFunc      = Hi35xxLinuxSdioEnableFunc,
          .disableFunc = Hi35xxLinuxSdioDisableFunc,
          .claimIrq    = Hi35xxLinuxSdioClaimIrq,
          .releaseIrq  = Hi35xxLinuxSdioReleaseIrq,
          .findFunc    = Hi35xxLinuxSdioFindFunc,
          .claimHost   = Hi35xxLinuxSdioClaimHost,
          .releaseHost = Hi35xxLinuxSdioReleaseHost,
      };
      ```
      
- **Bind** function
  
   **Input parameter**:
   
   **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.
   
   **Return value**:
   
   **HDF_STATUS**
   
   The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.
   
   **Table 2** Description of HDF_STATUS
   
   | Status                 | Description                |
   | ---------------------- | -------------------------- |
   | HDF_ERR_INVALID_OBJECT | Invalid controller object. |
   | HDF_ERR_MALLOC_FAIL    | Failed to allocate memory. |
   | HDF_ERR_INVALID_PARAM  | Invalid parameter.         |
   | HDF_ERR_IO             | I/O error.                 |
   | HDF_SUCCESS            | Initialization successful. |
   | HDF_FAILURE            | Initialization failed.     |
   
   **Function description**:
   
   Initializes the custom structure object and **SdioCntlr**, calls the **SdioCntlrAdd** function at the core layer, and performs other initialization operations customized by the vendor.
   
   ```
   static int32_t Hi35xxLinuxSdioBind(struct HdfDeviceObject *obj)
      {
          struct MmcCntlr *cntlr = NULL;
          int32_t ret;
          ...
           cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));// Allocate memory.
          ...
          cntlr->ops = &g_sdioCntlrOps;                                     // (Mandatory) struct MmcCntlrOps g_sdioCntlrOps={
                                                                            // .rescanSdioDev = Hi35xxLinuxSdioRescan,};
          cntlr->hdfDevObj = obj;                                           // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.
          obj->service = &cntlr->service;                                   // (Mandatory) Prerequisites for conversion between HdfDeviceObject and MmcCntlr.   
          ret = Hi35xxLinuxSdioCntlrParse(cntlr, obj);                      // (Mandatory) Initialize index and devType of cntlr. If the initialization fails, execute goto _ERR.
          ...
          ret = MmcCntlrAdd(cntlr);                                         // (Mandatory) Call the function in mmc_core.c. If the operation fails, execute goto _ERR.
          ...
          ret = MmcCntlrAllocDev(cntlr, (enum MmcDevType)cntlr->devType);   // (Mandatory) Call the function in mmc_core.c. If the operation fails, execute goto _ERR.
          ...
          
          MmcDeviceAddOps(cntlr->curDev, &g_sdioDeviceOps);                // (Mandatory) Call the function in mmc_core.c to hook the related functions.
          HDF_LOGD("Hi35xxLinuxSdioBind: Success!");
          return HDF_SUCCESS;
      
      _ERR:
          Hi35xxLinuxSdioDeleteCntlr(cntlr);
          HDF_LOGE("Hi35xxLinuxSdioBind: Fail!");
       return HDF_FAILURE;
      }
   ```

- **Init** function
  
   **Input parameter**:
   
   **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.
   
   **Return value**:
   
   **HDF_STATUS**
   
   **Function description**:
   
   You can add operations as required.
   
   ```
   static int32_t Hi35xxLinuxSdioInit(struct HdfDeviceObject *obj)
      {
          (void)obj;// No operation. You can add operations as required.
          HDF_LOGD("Hi35xxLinuxSdioInit: Success!");
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
   > All forced conversion operations for obtaining the corresponding object can be successful only when the **Bind** function has the corresponding value assignment operations.

   ```
   static void Hi35xxLinuxSdioRelease(struct HdfDeviceObject *obj)
   {
       if (obj == NULL) {
           return;
       }
       Hi35xxLinuxSdioDeleteCntlr((struct MmcCntlr *)obj->service);// (Mandatory) Custom function for releasing memory. A forced conversion from HdfDeviceObject to MmcCntlr is involved.
   }
   ```
