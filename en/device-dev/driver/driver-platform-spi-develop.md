# SPI


## Overview

Serial Peripheral Interface (SPI) is a serial bus specification used for high-speed, full-duplex, and synchronous communication. In the Hardware Driver Foundation (HDF), the SPI module uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png)

## Available APIs

**SpiCntlrMethod**:


```
struct SpiCntlrMethod {
  int32_t (*GetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*SetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*Transfer)(struct SpiCntlr *cntlr, struct SpiMsg *msg, uint32_t count);
  int32_t (*Open)(struct SpiCntlr *cntlr);
  int32_t (*Close)(struct SpiCntlr *cntlr);
};
```

  **Table 1** Description of the callback functions in SpiCntlrMethod

| Function| Input Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- |
| Transfer | **cntlr**: structure pointer to the SPI controller at the core layer.<br>**msg**: structure pointer to the SPI message.<br>**count**: number of messages. The value is of the uint32_t type.| HDF_STATUS| Transfers messages.|
| SetCfg | **cntlr**: structure pointer to the SPI controller at the core layer.<br>**cfg**: structure pointer to the SPI attributes.| HDF_STATUS| Sets SPI controller attributes.|
| GetCfg | **cntlr**: structure pointer to the SPI controller at the core layer.<br>**cfg**: structure pointer to the SPI attributes.| HDF_STATUS| Obtains SPI controller attributes.|
| Open | **cntlr**: structure pointer to the SPI controller at the core layer.| HDF_STATUS| Opens an SPI device.|
| Close | **cntlr**: structure pointer to the SPI controller at the core layer.| HDF_STATUS| Closes an SPI device.|


## How to Develop

The SPI module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **spi_config.hcs** file.

3. Instantiate the SPI controller object.
   - Initialize **SpiCntlr**.
   - Instantiate **SpiCntlrMethod** in the **SpiCntlr** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **SpiCntlrMethod**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify the basic functions, such as the SPI status control and response to interrupts.


## Development Example

The following uses **spi_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**.

   In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   SPI driver entry example:
   
   ```
   struct HdfDriverEntry g_hdfSpiDevice = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_SPI",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
       .Bind = HdfSpiDeviceBind,        // See the Bind function.
       .Init = HdfSpiDeviceInit,        // See the Init function.
       .Release = HdfSpiDeviceRelease,  //See the Release function.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_hdfSpiDevice);
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **spi_config.hcs** file.

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **SpiCntlr** members at the core layer.

   In this example, there is only one SPI controller. If there are multiple SPI controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **spi_config** file for each controller.

   - **device_info.hcs** configuration example
   
     
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_spi :: device {                            // Configure an HDF device node for each SPI controller.
             device0 :: deviceNode {
               policy = 1;
               priority = 60;
               permission = 0644;
               moduleName = "HDF_PLATFORM_SPI";
               serviceName = "HDF_PLATFORM_SPI_0";
               deviceMatchAttr = "hisilicon_hi35xx_spi_0";
             }
             device1 :: deviceNode {
               policy = 1;
               priority = 60;
               permission = 0644;
               moduleName = "HDF_PLATFORM_SPI";             // (Mandatory) Driver name, which must be the same as that of moduleName in the driver entry structure.
               serviceName = "HDF_PLATFORM_SPI_1";           // (Mandatory) Unique name of the service published by the driver.
               deviceMatchAttr = "hisilicon_hi35xx_spi_1";       // The value must be the same as that of match_attr in the .hcs file.
             }
             ...
           }
         }
       }
     }
     ```
   
   - **spi_config.hcs** configuration example
   
     
     ```
     root {
       platform {
         spi_config {                        // Configure private data for each SPI controller.
           template spi_controller {           // Template configuration. In the template, you can configure the common parameters shared by device nodes.
             serviceName = "";
             match_attr = "";
             transferMode = 0; // Data transfer mode. The value **0** indicates interrupt transfer, **1** indicates flow control transfer, and **2** indicates DMA transfer.
             busNum = 0;           // Bus number.
             clkRate = 100000000;
             bitsPerWord = 8;                // Number of bits per word.
             mode = 19;                      // SPI data input/output mode.
             maxSpeedHz = 0;                 // Maximum clock frequency.
             minSpeedHz = 0;                 // Minimum clock frequency.
             speed = 2000000;                // Current message transfer speed.
             fifoSize = 256;                 // FIFO size.
             numCs = 1;                      // Chip select (CS) number.
             regBase = 0x120c0000;           // Used for address mapping.
             irqNum = 100;                   // Interrupt request (IRQ) number.
             REG_CRG_SPI = 0x120100e4;       // CRG_REG_BASE(0x12010000) + 0x0e4
             CRG_SPI_CKEN = 0;
             CRG_SPI_RST = 0;
             REG_MISC_CTRL_SPI = 0x12030024; // MISC_REG_BASE(0x12030000) + 0x24
             MISC_CTRL_SPI_CS = 0;
             MISC_CTRL_SPI_CS_SHIFT = 0;
           }      
           controller_0x120c0000 :: spi_controller {
             busNum = 0;                           // (Mandatory) Bus number.
             CRG_SPI_CKEN = 0x10000;               // (0x1 << 16) 0:close clk, 1:open clk 
             CRG_SPI_RST = 0x1;                    // (0x1 << 0) 0:cancel reset, 1:reset 
             match_attr = "hisilicon_hi35xx_spi_0";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
           }      
           controller_0x120c1000 :: spi_controller {
             busNum = 1;
             CRG_SPI_CKEN = 0x20000;    // (0x1 << 17) 0:close clk, 1:open clk
             CRG_SPI_RST = 0x2;         // (0x1 << 1) 0:cancel reset, 1:reset 
             match_attr = "hisilicon_hi35xx_spi_1"; 
             regBase = 0x120c1000;      // (Mandatory) Used for address mapping.
             irqNum = 101;              // (Mandatory) IRQ number.
           }
         ...
         //(Optional) Add nodes to the device_info.hcs file as required.
         }
       }
     }
     ```

3. Initialize the **SpiCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **SpiCntlrMethod** in **SpiCntlr** (so that the underlying driver functions can be called).

   - Defining a custom structure

     To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **spi_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the device number and bus number, to the **SpiCntlr** object at the core layer.

     
      ```
      struct Pl022 {// Corresponds to parameters in .hcs.
          struct SpiCntlr *cntlr;
          struct DListHead deviceList;
          struct OsalSem sem;
          volatile unsigned char *phyBase;
          volatile unsigned char *regBase;
          uint32_t irqNum;
          uint32_t busNum;
          uint32_t numCs;
          uint32_t curCs;
          uint32_t speed;
          uint32_t fifoSize;
          uint32_t clkRate;
          uint32_t maxSpeedHz;
          uint32_t minSpeedHz;
          uint32_t regCrg;
          uint32_t clkEnBit;
          uint32_t clkRstBit;
          uint32_t regMiscCtrl;
          uint32_t miscCtrlCsShift;
          uint32_t miscCtrlCs;
          uint16_t mode;
          uint8_t bitsPerWord;
          uint8_t transferMode;
      };
      
      // SpiCntlr is the core layer controller structure. The Init function assigns values to the members of SpiCntlr.
      struct SpiCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          uint32_t busNum;
          uint32_t numCs;
          uint32_t curCs;
          struct OsalMutex lock;
          struct SpiCntlrMethod *method;
          struct DListHead list;
          void *priv;
      };
      ```

   - Instantiating **SpiCntlrMethod** in **SpiCntlr** (other members are initialized by **Init**)

     
      ```
      // Example in spi_hi35xx.c: instantiate the hooks.
      struct SpiCntlrMethod g_method = {
          .Transfer = Pl022Transfer,
          .SetCfg = Pl022SetCfg,
          .GetCfg = Pl022GetCfg,
          .Open = Pl022Open,
          .Close = Pl022Close,
      };
      ```

   - **Bind** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**

      **Function description**:

      Associates the **SpiCntlr** object with **HdfDeviceObject**.

      
      ```
      static int32_t HdfSpiDeviceBind(struct HdfDeviceObject *device)
      {
          ...
          return (SpiCntlrCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS;
      }
      
      struct SpiCntlr *SpiCntlrCreate(struct HdfDeviceObject *device)
      {
          struct SpiCntlr *cntlr = NULL;                           // Create an SpiCntlr object.
          ...
          cntlr = (struct SpiCntlr *)OsalMemCalloc(sizeof(*cntlr));// Allocate memory.
          ...
          cntlr->device = device;                                  // Prerequisites for conversion between HdfDeviceObject and SpiCntlr.
          device->service = &(cntlr->service);                     // Prerequisites for conversion between HdfDeviceObject and SpiCntlr.
          (void)OsalMutexInit(&cntlr->lock);                       // Initialize the lock.
          DListHeadInit(&cntlr->list);                             // Add nodes.
          cntlr->priv = NULL;
          return cntlr;
      }
      ```

   - **Init** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

        **Table 2** Description of HDF_STATUS
      
      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      **Function description**:

      Initializes the custom structure object and **SpiCntlr**.

      
      ```
      static int32_t HdfSpiDeviceInit(struct HdfDeviceObject *device)
      {
      int32_t ret;
      struct SpiCntlr *cntlr = NULL;
      ...
      cntlr = SpiCntlrFromDevice(device); // Forcibly convert HdfDeviceObject to SpiCntlr using service. For details about the value assignment, see the Bind function.
                                          // return (device == NULL) ? NULL : (struct SpiCntlr *)device->service;
      ...
      ret = Pl022Init(cntlr, device);     // (Mandatory) Instantiate the custom operation object. The following is an example:
      ...
      ret = Pl022Probe(cntlr->priv);
      ...
      return ret;
      }
      
      static int32_t Pl022Init(struct SpiCntlr *cntlr, const struct HdfDeviceObject *device)
      {
      int32_t ret;
      struct Pl022 *pl022 = NULL;
      ...
      pl022 = (struct Pl022 *)OsalMemCalloc(sizeof(*pl022));// Request memory.
      ...
      ret = SpiGetBaseCfgFromHcs(pl022, device->property);  // Initialize busNum, numCs, speed, fifoSize, clkRate, mode, bitsPerWord, and transferMode.
      ...
      ret = SpiGetRegCfgFromHcs(pl022, device->property);   // Initialize regBase, phyBase, irqNum, regCrg, clkEnBit, clkRstBit, regMiscCtrl, regMiscCtrl, miscCtrlCs, and miscCtrlCsShift.
      ...
      // Calculate the frequencies corresponding to the maximum and minimum speeds.
      pl022->maxSpeedHz = (pl022->clkRate) / ((SCR_MIN + 1) * CPSDVSR_MIN);
      pl022->minSpeedHz = (pl022->clkRate) / ((SCR_MAX + 1) * CPSDVSR_MAX);
      DListHeadInit(&pl022->deviceList);// Initialize the DList linked list.
      pl022->cntlr = cntlr;              // Prerequisite for conversion between Pl022 and SpiCntlr.
      cntlr->priv = pl022;               // Prerequisite for conversion between Pl022 and SpiCntlr.
      cntlr->busNum = pl022->busNum;     // Assign a value to busNum in SpiCntlr.
      cntlr->method = &g_method;         // Attach the SpiCntlrMethod instance.
      ...
      ret = Pl022CreatAndInitDevice(pl022);
      if (ret != 0) {
          Pl022Release(pl022);           // Release the Pl022 object if the initialization fails.
          return ret;
      }
      return 0;
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

      
      ```
      static void HdfSpiDeviceRelease(struct HdfDeviceObject *device)
      {
          struct SpiCntlr *cntlr = NULL;
          ...
          cntlr = SpiCntlrFromDevice(device);             // Forced conversion from HdfDeviceObject to SpiCntlr is involved. For details about the value assignment, see the Bind function.
                                                          // return (device==NULL) ?NULL:(struct SpiCntlr *)device->service;
          ...
          if (cntlr->priv != NULL) {
              Pl022Remove((struct Pl022 *)cntlr->priv);// A forced conversion from SpiCntlr to Pl022 is involved.
          }
          SpiCntlrDestroy(cntlr);                         // Release the Pl022 object.
      }
      ```
