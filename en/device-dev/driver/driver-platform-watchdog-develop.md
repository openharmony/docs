# Watchdog<a name="EN-US_TOPIC_0000001199821009"></a>


## Overview<a name="section1315827527160117"></a>

In the Hardware Driver Foundation \(HDF\), the Watchdog \(also called Watchdog timer\) module uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDF Device Manager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1** Independent service mode<a name="fig61584136211"></a>  
![](figures/independent-service-mode.png "independent-service-mode-15")

## Available APIs<a name="section1180575010271"></a>

WatchdogMethod

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

**Table  1** Callbacks for the members in the WatchdogMethod structure

<a name="table1370451732"></a>
<table><thead align="left"><tr id="row370511435"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p170681939"><a name="p170681939"></a><a name="p170681939"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p870641434"><a name="p870641434"></a><a name="p870641434"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p27061011739"><a name="p27061011739"></a><a name="p27061011739"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p10707618315"><a name="p10707618315"></a><a name="p10707618315"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p37071516316"><a name="p37071516316"></a><a name="p37071516316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18707191835"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p970720118311"><a name="p970720118311"></a><a name="p970720118311"></a>getStatus</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p124968261413"><a name="p124968261413"></a><a name="p124968261413"></a><strong id="b13481135102819"><a name="b13481135102819"></a><a name="b13481135102819"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p17071515316"><a name="p17071515316"></a><a name="p17071515316"></a><strong id="b142021397417"><a name="b142021397417"></a><a name="b142021397417"></a>status</strong>: int32_t pointer indicating the watchdog status (started or stopped).</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p5707319312"><a name="p5707319312"></a><a name="p5707319312"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p2707511312"><a name="p2707511312"></a><a name="p2707511312"></a>Obtains the watchdog status.</p>
</td>
</tr>
<tr id="row27071911538"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p370701533"><a name="p370701533"></a><a name="p370701533"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p117071316317"><a name="p117071316317"></a><a name="p117071316317"></a><strong id="b136901310133110"><a name="b136901310133110"></a><a name="b136901310133110"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p127071411735"><a name="p127071411735"></a><a name="p127071411735"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p19707111331"><a name="p19707111331"></a><a name="p19707111331"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p170811111319"><a name="p170811111319"></a><a name="p170811111319"></a>Starts a watchdog.</p>
</td>
</tr>
<tr id="row17708191130"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p11708113315"><a name="p11708113315"></a><a name="p11708113315"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p870841138"><a name="p870841138"></a><a name="p870841138"></a><strong id="b14846151912249"><a name="b14846151912249"></a><a name="b14846151912249"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p770841533"><a name="p770841533"></a><a name="p770841533"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p18708115313"><a name="p18708115313"></a><a name="p18708115313"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p3708121738"><a name="p3708121738"></a><a name="p3708121738"></a>Stops a watchdog.</p>
</td>
</tr>
<tr id="row107081818310"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p10708181136"><a name="p10708181136"></a><a name="p10708181136"></a>setTimeout</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p2021212409407"><a name="p2021212409407"></a><a name="p2021212409407"></a><strong id="b1521224016409"><a name="b1521224016409"></a><a name="b1521224016409"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
<p id="p1870801834"><a name="p1870801834"></a><a name="p1870801834"></a><strong id="b721091763217"><a name="b721091763217"></a><a name="b721091763217"></a>seconds</strong>: input time value, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p77081011731"><a name="p77081011731"></a><a name="p77081011731"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p470871436"><a name="p470871436"></a><a name="p470871436"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p57091717315"><a name="p57091717315"></a><a name="p57091717315"></a>Sets the timeout period (in seconds) for a watchdog. Ensure that the actual watchdog running time complies with this setting.</p>
</td>
</tr>
<tr id="row3709911938"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p2070911932"><a name="p2070911932"></a><a name="p2070911932"></a>getTimeout</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p47091711732"><a name="p47091711732"></a><a name="p47091711732"></a><strong id="b88511419192416"><a name="b88511419192416"></a><a name="b88511419192416"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p57091411632"><a name="p57091411632"></a><a name="p57091411632"></a><strong id="b3906135871316"><a name="b3906135871316"></a><a name="b3906135871316"></a>seconds</strong>: output time value, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1470941838"><a name="p1470941838"></a><a name="p1470941838"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p17091511139"><a name="p17091511139"></a><a name="p17091511139"></a>Obtains the timeout period of a watchdog.</p>
</td>
</tr>
<tr id="row1770919112319"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1270913116313"><a name="p1270913116313"></a><a name="p1270913116313"></a>feed</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p570971736"><a name="p570971736"></a><a name="p570971736"></a><strong id="b1854319172417"><a name="b1854319172417"></a><a name="b1854319172417"></a>wdt</strong>: structure pointer to the Watchdog controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p67091517315"><a name="p67091517315"></a><a name="p67091517315"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1670915111312"><a name="p1670915111312"></a><a name="p1670915111312"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p10709818316"><a name="p10709818316"></a><a name="p10709818316"></a>Feeds a watchdog. </p>
</td>
</tr>
</tbody>
</table>


## How to Develop<a name="section477974542160117"></a>

The Watchdog module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **watchdog\_config.hcs** file.

3.  Instantiate the Watchdog controller object.
    -   Initialize **WatchdogCntlr**.
    -   Instantiate **WatchdogMethod** in the **WatchdogCntlr** object.

        For details, see [Available APIs](#available-apis).

4.  \(Optional\) Debug the driver.

    For new drivers, verify basic functions, for example, verify the information returned after the connect operation and whether the watchdog timer is successfully set.


## Development Example<a name="section1832270347160117"></a>

The following uses **watchdog\_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exit.

    -   Watchdog driver entry reference

        ```
        struct HdfDriverEntry g_watchdogDriverEntry = {
        .moduleVersion = 1,
           .Bind = Hi35xxWatchdogBind, // See the Bind function.
        .Init = Hi35xxWatchdogInit,  // See the Init function.
        .Release = Hi35xxWatchdogRelease, //See the Release function.
        .moduleName = "HDF_PLATFORM_WATCHDOG",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
        };
        HDF_INIT(g_watchdogDriverEntry);// Call HDF_INIT to register the driver entry with the HDF.
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the component attributes in the **watchdog\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **WatchdogCntlr** members at the core layer.

    In this example, there is only one Watchdog controller. If there are multiple Watchdog controllers, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **watchdog\_config** file.

    -  **device\_info.hcs** configuration reference

        ```
        root {
          device_info {
            match_attr = "hdf_manager";
            device_watchdog :: device {// Device node
              device0:: deviceNode {// DeviceNode of the driver
                The policy = 1; // The value 1 indicates that the driver publishes kernel-mode services. The value 2 indicates that the driver publishes user-mode services.
         priority = 20; // Driver startup priority
         permission = 0644; // Permission to create device nodes for the driver
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

    -  **watchdog\_config.hcs** configuration reference

        ```
        root {
          platform {
               template watchdog_controller {// Template configuration. In the template, you can configure the common parameters shared by service nodes.
              id = 0;
              match_attr = "";
              regBase = 0x12050000; // (Mandatory) Used for address mapping.
                regStep = 0x1000;   // (Mandatory) Used for address mapping.
            }
            controller_0x12050000 :: watchdog_controller {// (Mandatory) Keyword for matching the private data of the device driver.
                match_attr = "hisilicon_hi35xx_watchdog_0"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
              }
              // Configure this parameter when there are multiple watchdogs.
              ...  
            }
        }
        ```

3.  Initialize the **WatchdogCntlr** object at the core layer, including initializing the vendor custom structure \(passing parameters and data\), instantiating **WatchdogMethod** \(used to call underlying functions of the driver\) in **WatchdogCntlr**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **watchdog\_config.hcs** file are read by HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values, such as the index and the number of pins, are also passed to the **WatchdogCntlr** object at the core layer.

        ```
        struct Hi35xxWatchdog {
          struct WatchdogCntlr wdt; // (Mandatory) Carrier that connects the upper and underlying layers. For details, see the following description.
          OsalSpinlock lock;
          volatile unsigned char *regBase;// [Mandatory] Used for address mapping.
                 uint32_t phyBase;   // (Mandatory) Used for address mapping.
              uint32_t regStep;  // (Mandatory) Used for address mapping.
        };
        // WatchdogCntlr is the core layer controller structure. Its members are assigned with values by using the Init function.
        struct WatchdogCntlr {
          struct IDeviceIoService service;// Driver service
          struct HdfDeviceObject *device; // Drive device
          OsalSpinlock lock; // This variable implements the spinlock function.
          struct WatchdogMethod *ops; // Interface callback
          int16_t wdtId; // ID of the watchdog device
          void *priv; // Save the pointer.
        };
        ```

    -   Instantiate the callback function structure **WatchdogMethod** in **WatchdogCntlr**. Other members are initialized by using the **Init** and **Bind** functions.

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

    -   Init and Bind functions

        Input parameters:

       **HdfDeviceObject**: device object created by the HDF for each driver. It stores device-related private data and service APIs.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **//drivers/framework/include/utils/hdf\_base.h** file.\)

       **Table  2** Input parameters and return values of the Init and Bind functions

        <a name="table86931033998"></a>
        <table><thead align="left"><tr id="row10694203319911"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1669433319918"><a name="p1669433319918"></a><a name="p1669433319918"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p06945331911"><a name="p06945331911"></a><a name="p06945331911"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row869417338918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p96941433391"><a name="p96941433391"></a><a name="p96941433391"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4694333395"><a name="p4694333395"></a><a name="p4694333395"></a>Failed to locate the watchdog device</p>
        </td>
        </tr>
        <tr id="row136941833091"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p66941336920"><a name="p66941336920"></a><a name="p66941336920"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1694133395"><a name="p1694133395"></a><a name="p1694133395"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row469443317913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p116951933293"><a name="p116951933293"></a><a name="p116951933293"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p969511331918"><a name="p969511331918"></a><a name="p969511331918"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row369533318911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p669511331891"><a name="p669511331891"></a><a name="p669511331891"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p136951233699"><a name="p136951233699"></a><a name="p136951233699"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row17695633596"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1469583314910"><a name="p1469583314910"></a><a name="p1469583314910"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10695193311919"><a name="p10695193311919"></a><a name="p10695193311919"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and **WatchdogCntlr**, and calls the **WatchdogCntlrAdd** function at the core layer.

        ```
        // Generally, the Init function initializes the members of the Hi35xxWatchdog structure based on the attribute values of the input parameter (HdfDeviceObject).
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
                                                    //If priv needs to be called, instantiate the getPriv and releasePriv member functions in WatchdogMethod.
        hwdt->wdt.ops = &g_method; // (Mandatory) Assign the instantiated objects to the ops member so that the top layer can invoke the WatchdogMethod member functions.
        hwdt->wdt.device = device; // (Mandatory) Enable conversion between HdfDeviceObject and WatchdogcCntlr.
        ret = WatchdogCntlrAdd(&hwdt->wdt);   // (Mandatory) Call this function to initialize the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
        if (ret != HDF_SUCCESS) {// If the operation fails, release the resources used by the Init function.
            OsalIoUnmap((void *)hwdt->regBase);
            OsalMemFree(hwdt);
            return ret;
        }    
        return HDF_SUCCESS;
        }
        ```

    -   Release function

        Input parameters:

       **HdfDeviceObject**: device object created by the HDF for each driver. It stores device-related private data and service APIs.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.

        ```
        static void Hi35xxWatchdogRelease(struct HdfDeviceObject *device)
        {
        struct WatchdogCntlr *wdt = NULL;
        struct Hi35xxWatchdog *hwdt = NULL;
        ...
        wdt = WatchdogCntlrFromDevice(device);// Convert HdfDeviceObject to WatchdogCntlr by the service member.
                                                //return (device == NULL) ? NULL : (struct WatchdogCntlr *)device->service;
        if (wdt == NULL) {
            return;
        }
        WatchdogCntlrRemove(wdt); // Core layer function used to execute wdt->device->service = NULL and release cntlr->lock.
        hwdt = (struct Hi35xxWatchdog *)wdt; // Convert WatchdogCntlr to HimciHost.
        if (hwdt->regBase != NULL) {// Remove address mapping.
            OsalIoUnmap((void *)hwdt->regBase);
            hwdt->regBase = NULL;
        }
        OsalMemFree(hwdt); // Release the memory occupied by the vendor-defined objects.
        }
        ```