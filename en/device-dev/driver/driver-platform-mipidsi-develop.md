# MIPI DSI


## Overview

The Display Serial Interface (DSI) is a specification developed by the Mobile Industry Processor Interface (MIPI) Alliance to reduce the cost of display controllers in mobile devices. In the Hardware Driver Foundation (HDF), the MIPI DSI module uses the service-free mode for API adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the operating system (OS) that does not distinguish the user mode and the kernel mode. In the service-free mode, **DevHandle** (a void pointer) directly points to the kernel-mode address of the device object.

  **Figure 1** Service-free mode

  ![](figures/service-free-mode.png "service-free-mode")


## Available APIs

**MipiDsiCntlrMethod**:


```
struct MipiDsiCntlrMethod { // Member functions of the core layer structure
    int32_t (*setCntlrCfg)(struct MipiDsiCntlr *cntlr);
    int32_t (*setCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd);
    int32_t (*getCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd, uint32_t readLen, uint8_t *out);
    void (*toHs)(struct MipiDsiCntlr *cntlr);
    void (*toLp)(struct MipiDsiCntlr *cntlr);
    void (*enterUlps)(struct MipiDsiCntlr *cntlr);                      // (Optional) Enter the Ultra-Low Power State (ULPS).
    void (*exitUlps)(struct MipiDsiCntlr *cntlr);                       // (Optional) Exit the ULPS.
    int32_t (*powerControl)(struct MipiDsiCntlr *cntlr, uint8_t enable);// (Optional) Enable or disable power control.
    int32_t (*attach)(struct MipiDsiCntlr *cntlr);                      // (Optional) Attach a DSI device to the host.
};
```

  **Table 1** Description of the callback functions in MipiDsiCntlrMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| setCntlrCfg | **cntlr**: structure pointer to the MIPI DSI controller.| –| HDF_STATUS| Sets controller parameters.|
| setCmd | **cntlr**: structure pointer to the MIPI DSI controller.<br>**cmd**: structure pointer to the commands to send. | –| HDF_STATUS| Sends commands to a display device.|
| getCmd | **cntlr**: structure pointer to the MIPI DSI controller.<br>**cmd**: pointer to the command description structure.<br>**readLen**: length of the data to read.| **out**: structure pointer to the data obtained.| HDF_STATUS| Reads data by sending commands.|
| toHs | **cntlr**: structure pointer to the MIPI DSI controller.| –| HDF_STATUS| Sets the high speed (HS) mode.|
| toLp | **cntlr**: structure pointer to the MIPI DSI controller.| –| HDF_STATUS| Sets the low power (LP) mode.|


## How to Develop

The MIPI DSI module adaptation involves the following steps:

1. Configure attribute files.
   - Add the **deviceNode** description to the **device_info.hcs** file.
   - (Optional) Add the **mipidsi_config.hcs** file.

2. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

3. Instantiate the MIPI DSI controller object.
   - Initialize **MipiDsiCntlr**.
   - Instantiate **MipiDsiCntlrMethod** in the **MipiDsiCntlr** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
      > For details about the functions in **MipiDsiCntlrMethod**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify basic functions, for example, check the information returned after the driver is attached and whether data is successfully transmitted.


## Development Example

The following uses **mipi_tx_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1. Configure the device attributes in **xx_config.hcs** and add the **deviceNode** information to the **device_info.hcs** file.

   The device attribute values are closely related to the default values or value range of the **MipiDsiCntlr** members at the core layer. The **deviceNode** information is related to the driver entry registration.

   In this example, no additional attribute needs to be configured for the MIPI DSI controller. If required, add the **deviceMatchAttr** information to **deviceNode** in the **device_info** file and add the **mipidsi_config** file.

     **device_info.hcs** configuration example:
   
   ```
   root {
   device_info {
       match_attr = "hdf_manager";
       platform :: host {
       hostName = "platform_host";
       priority = 50;
       device_mipi_dsi:: device {
           device0 :: deviceNode {
           policy = 0;
           priority = 150;
           permission = 0644;
           moduleName = "HDF_MIPI_TX";    // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
           serviceName = "HDF_MIPI_TX";   // (Mandatory) Unique name of the service published by the driver.
           }
       }
       }
   }
   }
   ```

2. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. The function pointer members in the **HdfDriverEntry** structure are filled by the vendors' operation functions. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   MIPI DSI driver entry example:
        
      ```
      struct HdfDriverEntry g_mipiTxDriverEntry = {
          .moduleVersion = 1,             
          .Init = Hi35xxMipiTxInit,       // See the Init function.
          .Release = Hi35xxMipiTxRelease, // See the Release function.
          .moduleName = "HDF_MIPI_TX",    // (Mandatory) The value must be the same as that in the device_info.hcs file.
      };
      HDF_INIT(g_mipiTxDriverEntry);      // Call HDF_INIT to register the driver entry with the HDF.
      ```

3. Initialize the **MipiDsiCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **MipiDsiCntlrMethod** in **MipiDsiCntlr** (so that the underlying driver functions can be called).

   - Defining a custom structure

     To the driver, the custom structure holds parameters and data. Generally, the values in the **config** file are used to initialize the structure members. However, in this example, the MIPI DSI has no device attribute file. Therefore, the basic member structure is similar to that of **MipiDsiCntlr**.

     ```
     typedef struct {
       unsigned int devno;                   // Device number
       short           laneId[LANE_MAX_NUM]; // Lane ID
       OutPutModeTag   outputMode;           // Output mode, which can be CSI mode, DSI Video mode, or DSI Command mode.
       VideoModeTag    videoMode;            // Synchronization mode of the display device
       OutputFormatTag outputFormat;         // Format of the output DSI image, which can be RGB or YUV.
       SyncInfoTag syncInfo;                 // Settings related to timing
       unsigned int phyDataRate;             // Data rate, in Mbit/s
       unsigned int    pixelClk;             // Clock, in kHz
     } ComboDevCfgTag;
     
     // MipiDsiCntlr is the controller structure at the core layer. The Init function assigns values to the members of MipiDsiCntlr.
     struct MipiDsiCntlr {
       struct IDeviceIoService service;
       struct HdfDeviceObject *device;
       unsigned int devNo;         // Device number
       struct MipiCfg cfg;
       struct MipiDsiCntlrMethod *ops;
       struct OsalMutex  lock;
       void *priv;
     };
     ```

   - Instantiating **MipiDsiCntlrMethod** in **MipiDsiCntlr** (other members are initialized by **Init**)

     ```
     static struct MipiDsiCntlrMethod g_method = {
         .setCntlrCfg = Hi35xxSetCntlrCfg,
         .setCmd = Hi35xxSetCmd,
         .getCmd = Hi35xxGetCmd,
         .toHs = Hi35xxToHs,
         .toLp = Hi35xxToLp,
     };
     ```

   - **Init** function

     **Input parameter**:

     **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

     **Return value**:

     **HDF_STATUS**

     The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

     | Status                 | Description                |
     | ---------------------- | -------------------------- |
     | HDF_ERR_INVALID_OBJECT | Invalid object.            |
     | HDF_ERR_MALLOC_FAIL    | Failed to allocate memory. |
     | HDF_ERR_INVALID_PARAM  | Invalid parameter.         |
     | HDF_ERR_IO             | I/O error.                 |
     | HDF_SUCCESS            | Operation successful.      |
     | HDF_FAILURE            | Operation failed.          |

     **Function description**:

     Attaches the **MipiDsiCntlrMethod** instance, calls **MipiDsiRegisterCntlr**, and performs other vendor-defined initialization operations.

     ```
      static int32_t Hi35xxMipiTxInit(struct HdfDeviceObject *device)
      {
      int32_t ret;
      g_mipiTx.priv = NULL;                         // g_mipiTx is a global variable defined.
                                                     // static struct MipiDsiCntlr g_mipiTx { 
                                                     //     .devNo=0
                                                     //};
      g_mipiTx.ops = &g_method;                     // Attach the MipiDsiCntlrMethod instance.
      ret = MipiDsiRegisterCntlr(&g_mipiTx, device);// (Mandatory) Call the function at the core layer and g_mipiTx to initialize global variables at the core layer.
      ...
      return MipiTxDrvInit(0);                      // (Mandatory) Device initialization customized by the vendor.
      }
       
      // mipi_dsi_core.c file
      int32_t MipiDsiRegisterCntlr(struct MipiDsiCntlr *cntlr, struct HdfDeviceObject *device)
      {
      ...
      // Define the global variable static struct MipiDsiHandle g_mipiDsihandle[MAX_CNTLR_CNT].
      if (g_mipiDsihandle[cntlr->devNo].cntlr == NULL) {
          (void)OsalMutexInit(&g_mipiDsihandle[cntlr->devNo].lock);
          (void)OsalMutexInit(&(cntlr->lock));
       
          g_mipiDsihandle[cntlr->devNo].cntlr = cntlr;// Initialize MipiDsiHandle.
          g_mipiDsihandle[cntlr->devNo].priv = NULL;  
          cntlr->device = device;                     // Prerequisites for conversion between HdfDeviceObject and MipiDsiHandle.
          device->service = &(cntlr->service);       // Prerequisites for conversion between HdfDeviceObject and MipiDsiHandle.
          cntlr->priv = NULL;    
          ...
          return HDF_SUCCESS;
      }
      ...
      return HDF_FAILURE;
      }
     ```

   - **Release** function

     **Input parameter**:

     **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

     **Return value**:

     No value is returned.

     **Function description**:

     Releases the memory and deletes the controller. This function assigns values to the **Release** API in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

        > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
		> 
        > All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.

     ```
      static void Hi35xxMipiTxRelease(struct HdfDeviceObject *device)
      {
      struct MipiDsiCntlr *cntlr = NULL;
      ...
      cntlr = MipiDsiCntlrFromDevice(device);// A forced conversion from HdfDeviceObject to MipiDsiCntlr is involved.
                                               // return (device == NULL) ? NULL : (struct MipiDsiCntlr *)device->service;
      ...
      MipiTxDrvExit(;                        // (Mandatory) Release the resources occupied by the vendor's devices.
      MipiDsiUnregisterCntlr(&g_mipiTx);     // Empty function
      g_mipiTx.priv = NULL;
      HDF_LOGI("%s: unload mipi_tx driver 1212!", __func__);
      } 
     ```
