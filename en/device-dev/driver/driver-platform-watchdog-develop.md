# Watchdog


## **Overview**

A watchdog, also called a watchdog timer, is a hardware timing device used to facilitate automatic correction of temporary hardware faults or recover from system malfunctions. 

In the Hardware Driver Foundation (HDF), the watchdog uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png "Watchdog independent service mode")


## **Available APIs**

**WatchdogMethod**:


```
struct WatchdogMethod {
  int32_t (*getStatus)(struct WatchdogCntlr *wdt, int32_t *status);
  int32_t (*setTimeout)(struct WatchdogCntlr *wdt, uint32_t seconds);
  int32_t (*getTimeout)(struct WatchdogCntlr *wdt, uint32_t *seconds);
  int32_t (*start)(struct WatchdogCntlr *wdt);
  int32_t (*stop)(struct WatchdogCntlr *wdt);
  int32_t (*feed)(struct WatchdogCntlr *wdt);
  int32_t (*getPriv)(struct WatchdogCntlr *wdt); // (Optional) If WatchdogCntlr has the priv member, instantiate priv.
  void (*releasePriv)(struct WatchdogCntlr *wdt);// (Optional)
};
```

  **Table 1** Description of the callback functions in WatchdogMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| getStatus | **wdt**: structure pointer to the watchdog controller at the core layer.| **status**: int32_t pointer to the watchdog status (started or stopped).| HDF_STATUS| Obtains the watchdog status.|
| start | **wdt**: structure pointer to the watchdog controller at the core layer.| –| HDF_STATUS| Starts a watchdog.|
| stop | **wdt**: structure pointer to the watchdog controller at the core layer.| –| HDF_STATUS   | Stops a watchdog.|
| setTimeout | **wdt**: structure pointer to the watchdog controller at the core layer.<br/>**seconds**: Timeout duration to set, in seconds. The value is of the uint32_t type. | – | HDF_STATUS | Sets the timeout duration for a watchdog. |
| getTimeout | **wdt**: structure pointer to the watchdog controller at the core layer.| **seconds**: Pointer to the watchdog timeout duration obtained. The value is of the uint32_t type. | HDF_STATUS| Obtains the timeout duration of a watchdog.|
| feed | **wdt**: structure pointer to the watchdog controller at the core layer.| –| HDF_STATUS| Feeds a watchdog. |


## How to Develop

The watchdog module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **watchdog_config.hcs** file.

3. Instantiate the watchdog controller object.
   - Initialize **WatchdogCntlr**.
   - Instantiate **WatchdogMethod** in the **WatchdogCntlr** object.

   > ![](../public_sys-resources/icon-note.gif) **NOTE** 
   > 
   > For details about the functions in **WatchdogMethod**, see [Available APIs](#available-apis).

4. Debug the driver.
   
   (Optional) For new drivers, verify basic functions, for example, check the information returned after the driver is attached and whether the watchdog timer is successfully set.


## Development Example

The following uses **watchdog_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.
   
   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   
   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.
   
   Watchdog driver entry example:

   ```
   struct HdfDriverEntry g_watchdogDriverEntry = {
   .moduleVersion = 1,
   .Bind = Hi35xxWatchdogBind,           // See the Bind function.
   .Init = Hi35xxWatchdogInit,           // See the Init function.
   .Release = Hi35xxWatchdogRelease,     // See the Release function.
   .moduleName = "HDF_PLATFORM_WATCHDOG",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   HDF_INIT(g_watchdogDriverEntry);// Call HDF_INIT to register the driver entry with the HDF.
   ```
  
2. Add the **deviceNode** information to the **device_info.hcs** file and configure the component attributes in the **watchdog_config.hcs** file. 

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **WatchdogCntlr** members at the core layer.

   In this example, there is only one watchdog controller. If there are multiple watchdog controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **watchdog_config** file for each controller.

   - **device_info.hcs** configuration example:

     
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         device_watchdog :: device {// Device node.
           device0:: deviceNode {   // Device node of the driver.
             policy = 1;             // Policy for the driver to provide services.
             priority = 20;          // Driver startup priority.
             permission = 0644;    // Permission to create device nodes for the driver.
             moduleName = "HDF_PLATFORM_WATCHDOG";             
              // (Mandatory) Driver name. The value must be the same as that of moduleName in the driver entry structure.
             serviceName = "HDF_PLATFORM_WATCHDOG_0";          
             // (Mandatory) Unique name of the service published by the driver.
             deviceMatchAttr = "hisilicon_hi35xx_watchdog_0";  
             // (Mandatory) Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
           } 
         }
       }
     }
     ```

   - **watchdog_config.hcs** configuration example:

     
     ```
     root {
       platform {
         template watchdog_controller {// (Mandatory) Template configuration. In the template, you can configure the common parameters shared by device nodes.
           id = 0;
           match_attr = "";
           regBase = 0x12050000;       //  (Mandatory) Used for address mapping.
           regStep = 0x1000;           // (Mandatory) Used for address mapping.
         }
         controller_0x12050000 :: watchdog_controller {// (Mandatory) Keyword for matching the private data of the device driver.
           match_attr = "hisilicon_hi35xx_watchdog_0"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
           }
           // Configure this parameter when there are multiple watchdogs.
           ...  
         }
     }
     ```

3. Initialize the **WatchdogCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **WatchdogMethod** in **WatchdogCntlr** (so that the underlying driver functions can be called).
   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **watchdog_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the index and the number of pins, to the **WatchdogCntlr** object at the core layer.

      
      ```
      struct Hi35xxWatchdog {
        struct WatchdogCntlr wdt; // (Mandatory) Carrier that connects the upper and underlying layers. For details, see the following description.
        OsalSpinlock lock;
        volatile unsigned char *regBase;// [Mandatory] Used for address mapping.
        uint32_t phyBase;               // (Mandatory) Used for address mapping.
        uint32_t regStep;               // (Mandatory) Used for address mapping.
      };
      // WatchdogCntlr is the core layer controller structure. The Init function assigns values to the members of WatchdogCntlr.
      struct WatchdogCntlr {
        struct IDeviceIoService service;// Driver service.
        struct HdfDeviceObject *device; // Driver device.
        OsalSpinlock lock;              // This variable is called by the HDF core layer to implement the spinlock function.
        struct WatchdogMethod *ops;     // Callbacks.
        int16_t wdtId                  // ID of the watchdog device.
        void *priv;                    // Pointer to the driver's private data.
      };
      ```
      
   - Instantiating **WatchdogMethod** in **WatchdogCntlr** (other members are initialized by **Init** and **Bind**)

     
      ```
      static struct WatchdogMethod g_method = {
          .getStatus = Hi35xxWatchdogGetStatus,
          .start = Hi35xxWatchdogStart,
          .stop = Hi35xxWatchdogStop,
          .setTimeout = Hi35xxWatchdogSetTimeout,
          .getTimeout = Hi35xxWatchdogGetTimeout,
          .feed = Hi35xxWatchdogFeed,
      };
      ```

   - **Init** and **Bind** functions

      Input parameter:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      HDF_STATUS

      The table below lists some status. For more information, see **HDF_STATUS** in the /drivers/framework/include/utils/hdf_base.h file.
      
        **Table 2** HDF_STATUS
      
      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Failed to locate the watchdog device.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      Function description:

      Initializes the custom structure object and **WatchdogCntlr**, and calls the **WatchdogCntlrAdd** function at the core layer.
      
      
      ```
      // Generally, the Init function initializes the members of the Hi35xxWatchdog structure based on the attribute values in **HdfDeviceObject**.
      // In this example, the Bind function initializes the Hi35xxWatchdog structure.
      static int32_t Hi35xxWatchdogInit(struct HdfDeviceObject *device)
      {
      (void)device;
      return HDF_SUCCESS;
      }
      
      static int32_t Hi35xxWatchdogBind(struct HdfDeviceObject *device)
      {
      int32_t ret;
      struct Hi35xxWatchdog *hwdt = NULL;
      ...
      hwdt = (struct Hi35xxWatchdog *)OsalMemCalloc(sizeof(*hwdt));// Apply for memory for the Hi35xxWatchdog structure.
      ...
      hwdt->regBase = OsalIoRemap(hwdt->phyBase, hwdt->regStep); // Address mapping
      ...
      hwdt->wdt.priv = (void *)device->property;// (Optional) Assign the device attribute values to priv. However, priv is not called subsequently.
                                                  //If the priv member is required, instantiate getPriv() and releasePriv() of WatchdogMethod.
      hwdt->wdt.ops = &g_method;                // (Mandatory) Assign the instantiated objects to the ops members so that the top layer can invoke the WatchdogMethod functions.
      hwdt->wdt.device = device;                // (Mandatory) Enable conversion between HdfDeviceObject and WatchdogcCntlr.
      ret = WatchdogCntlrAdd(&hwdt->wdt);       // (Mandatory) Call this function to initialize the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
      if (ret != HDF_SUCCESS) {                 // If the operation fails, release the resources used by Init().
          OsalIoUnmap((void *)hwdt->regBase);
          OsalMemFree(hwdt);
          return ret;
      }    
      return HDF_SUCCESS;
      }
      ```
      
   - **Release** function

      Input parameter:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      No value is returned.

      Function description:

      Releases driver resources. This function assigns values to **Release()** in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, **Release()** can be called to release driver resources. The **Release()** function must contain the operations for releasing the memory and deleting the controller. 

      All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.
      
      
      ```
      static void Hi35xxWatchdogRelease(struct HdfDeviceObject *device)
      {
      struct WatchdogCntlr *wdt = NULL;
      struct Hi35xxWatchdog *hwdt = NULL;
      ...
      wdt = WatchdogCntlrFromDevice(device);// Use service to convert HdfDeviceObject to WatchdogCntlr.
                                              // return (device == NULL) ? NULL : (struct WatchdogCntlr *)device->service;
      if (wdt == NULL) {
          return;
      }
      WatchdogCntlrRemove(wdt);                // Core layer function used to execute wdt->device->service = NULL and release cntlr->lock.
      hwdt = (struct Hi35xxWatchdog *)wdt; // Convert WatchdogCntlr to HimciHost.
      if (hwdt->regBase != NULL) {            // Unmap addresses.
          OsalIoUnmap((void *)hwdt->regBase);
          hwdt->regBase = NULL;
      }
      OsalMemFree(hwdt);                    // Release the memory occupied by the vendor-defined objects.
      }
      ```
