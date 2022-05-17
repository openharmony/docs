# SPI<a name="EN-US_TOPIC_0000001199690327"></a>


## Overview<a name="section84922229152909"></a>

In the Hardware Driver Foundation \(HDF\), the Serial Peripheral Interface \(SPI\) uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDFDeviceManager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1** Independent service mode<a name="fig666465313303"></a>  
![](figures/independent-service-mode.png "SPI-independent-service-mode")

## Available APIs<a name="section752964871810"></a>

SpiCntlrMethod:

```
struct SpiCntlrMethod {
  int32_t (*GetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*SetCfg)(struct SpiCntlr *cntlr, struct SpiCfg *cfg);
  int32_t (*Transfer)(struct SpiCntlr *cntlr, struct SpiMsg *msg, uint32_t count);
  int32_t (*Open)(struct SpiCntlr *cntlr);
  int32_t (*Close)(struct SpiCntlr *cntlr);
};
```
**Table  1** Callbacks for the members in the SpiCntlrMethod structure

<a name="table7167123615321"></a>
<table><thead align="left"><tr id="row816783615326"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p8167193643218"><a name="p8167193643218"></a><a name="p8167193643218"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p31672362325"><a name="p31672362325"></a><a name="p31672362325"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="24.98%" id="mcps1.2.5.1.3"><p id="p51673367328"><a name="p51673367328"></a><a name="p51673367328"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="25.019999999999996%" id="mcps1.2.5.1.4"><p id="p1116883619322"><a name="p1116883619322"></a><a name="p1116883619322"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row816883693214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11683369329"><a name="p11683369329"></a><a name="p11683369329"></a>Transfer</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p0671913132514"><a name="p0671913132514"></a><a name="p0671913132514"></a><strong id="b19675134258"><a name="b19675134258"></a><a name="b19675134258"></a>cntlr</strong>: structure pointer to the SPI controller at the core layer.</p>
<p id="p192109186258"><a name="p192109186258"></a><a name="p192109186258"></a><strong id="b1921051810258"><a name="b1921051810258"></a><a name="b1921051810258"></a>msg</strong>: structure pointer to the SPI message.</p>
<p id="p6168736173213"><a name="p6168736173213"></a><a name="p6168736173213"></a><strong id="b92627310191"><a name="b92627310191"></a><a name="b92627310191"></a>count</strong>: number of messages. The value is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p19168736113216"><a name="p19168736113216"></a><a name="p19168736113216"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p18168236143218"><a name="p18168236143218"></a><a name="p18168236143218"></a>Transfers messages.</p>
</td>
</tr>
<tr id="row3168113633211"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p4168636193212"><a name="p4168636193212"></a><a name="p4168636193212"></a>SetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p242632402513"><a name="p242632402513"></a><a name="p242632402513"></a><strong id="b742642452513"><a name="b742642452513"></a><a name="b742642452513"></a>cntlr</strong>: structure pointer to the SPI controller at the core layer.</p>
<p id="p11168163643217"><a name="p11168163643217"></a><a name="p11168163643217"></a><strong id="b1283910558207"><a name="b1283910558207"></a><a name="b1283910558207"></a>cfg</strong>: structure pointer to the SPI attributes.</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p101683367325"><a name="p101683367325"></a><a name="p101683367325"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1216815368329"><a name="p1216815368329"></a><a name="p1216815368329"></a>Sets SPI controller attributes.</p>
</td>
</tr>
<tr id="row13168183683215"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11168436123220"><a name="p11168436123220"></a><a name="p11168436123220"></a>GetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p9698153182520"><a name="p9698153182520"></a><a name="p9698153182520"></a><strong id="b19698131162510"><a name="b19698131162510"></a><a name="b19698131162510"></a>cntlr</strong>: structure pointer to the SPI controller at the core layer.</p>
<p id="p3168936133218"><a name="p3168936133218"></a><a name="p3168936133218"></a><strong id="b11555148182113"><a name="b11555148182113"></a><a name="b11555148182113"></a>cfg</strong>: structure pointer to the SPI attributes.</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p18169036193219"><a name="p18169036193219"></a><a name="p18169036193219"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p3169136173219"><a name="p3169136173219"></a><a name="p3169136173219"></a>Obtains SPI controller attributes.</p>
</td>
</tr>
<tr id="row9169133643218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p13169163615320"><a name="p13169163615320"></a><a name="p13169163615320"></a>Open</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p181697365327"><a name="p181697365327"></a><a name="p181697365327"></a><strong id="b1876822162218"><a name="b1876822162218"></a><a name="b1876822162218"></a>cntlr</strong>: structure pointer to the SPI controller at the core layer. </p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p1169163693216"><a name="p1169163693216"></a><a name="p1169163693216"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1116963693218"><a name="p1116963693218"></a><a name="p1116963693218"></a>Enables the SPI.</p>
</td>
</tr>
<tr id="row11169436153214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0169736153219"><a name="p0169736153219"></a><a name="p0169736153219"></a>Close</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p31691936193210"><a name="p31691936193210"></a><a name="p31691936193210"></a><strong id="b16798152112239"><a name="b16798152112239"></a><a name="b16798152112239"></a>cntlr</strong>: structure pointer to the SPI controller at the core layer. </p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.3 "><p id="p2169123617322"><a name="p2169123617322"></a><a name="p2169123617322"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.4 "><p id="p1169636103220"><a name="p1169636103220"></a><a name="p1169636103220"></a>Disables the SPI.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section799667984152909"></a>

The SPI module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **spi\_config.hcs** file.

3.  Instantiate the SPI controller object.
    -   Initialize **SpiCntlr**.
    -   Instantiate **SpiCntlrMethod** in the **SpiCntlr** object.

        For details, see [Available APIs](#section752964871810). 

 4.  \(Optional\) Debug the driver.
     For new drivers, verify the basic functions, such as the SPI control status and response to interrupts.


## Development Example<a name="section956157227152909"></a>

The following uses **spi\_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exit.

    -   SPI driver entry reference

        ```
        struct HdfDriverEntry g_hdfSpiDevice = {
            .moduleVersion = 1,
            .moduleName = "HDF_PLATFORM_SPI",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
                .Bind = HdfSpiDeviceBind,   // See the Bind function.
         .Init = HdfSpiDeviceInit, // See the Init function.
             .Release = HdfSpiDeviceRelease,  //See the Release function.
        };
        // Call HDF_INIT to register the driver entry with the HDF.
        HDF_INIT(g_hdfSpiDevice);
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the device attributes in the **spi\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **SpiCntlr** members at the core layer.

    In this example, there is only one SPI controller. If there are multiple SPI controllers, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **spi\_config** file.

    -  **device\_info.hcs** configuration reference

        ```
        root {
        device_info {
            match_attr = "hdf_manager";
            platform :: host {
            hostName = "platform_host";
            priority = 50;
            device_spi :: device {// Configure an HDF device node for each SPI controller.
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
                moduleName = "HDF_PLATFORM_SPI"; // (Mandatory) Driver name, which must be the same as that of moduleName in the driver entry structure.
                   serviceName = "HDF_PLATFORM_SPI_1"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hisilicon_hi35xx_spi_1";// The value must be the same as that of match_attr in the .hcs file.
                }
                ...
            }
            }
        }
        }
        ```

    -  **spi\_config.hcs** configuration reference

        ```
        root {
        platform {
            spi_config {// Configure private data for each SPI controller.
              template spi_controller {// Template configuration. In the template, you can configure the common parameters shared by service nodes.
                serviceName = "";
                match_attr = "";
                transferMode = 0; // Data transfer mode, which can be interrupt transfer (0), flow control transfer (1), or DMA transfer (2).
                busNum = 0; // Bus number
                clkRate = 100000000;
                bitsPerWord = 8; // Bit width of the data transferred
                mode = 19; // SPI data input/output mode
                maxSpeedHz = 0; // Maximum clock frequency
                minSpeedHz = 0;  // Minimum clock frequency
                speed = 2000000; // Current message transfer speed
                fifoSize = 256; // FIFO size
                numCs = 1; // Chip select (CS) number
                regBase = 0x120c0000; // Used for address mapping.
                irqNum = 100; // Interruption number
                REG_CRG_SPI = 0x120100e4;       // CRG_REG_BASE(0x12010000) + 0x0e4
                CRG_SPI_CKEN = 0;
                CRG_SPI_RST = 0;
                REG_MISC_CTRL_SPI = 0x12030024; // MISC_REG_BASE(0x12030000) + 0x24
                MISC_CTRL_SPI_CS = 0;
                MISC_CTRL_SPI_CS_SHIFT = 0;
            }      
            controller_0x120c0000 :: spi_controller {
                busNum = 0; // (Mandatory) Bus number
                CRG_SPI_CKEN = 0x10000;    // (0x1 << 16) 0:close clk, 1:open clk 
                CRG_SPI_RST = 0x1;         // (0x1 << 0) 0:cancel reset, 1:reset 
                  match_attr = "hisilicon_hi35xx_spi_0";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
            }      
            controller_0x120c1000 :: spi_controller {
                busNum = 1;
                CRG_SPI_CKEN = 0x20000;    // (0x1 << 17) 0:close clk, 1:open clk
                CRG_SPI_RST = 0x2;         // (0x1 << 1) 0:cancel reset, 1:reset 
                match_attr = "hisilicon_hi35xx_spi_1"; 
                regBase = 0x120c1000; // (Mandatory) Used for address mapping.
                   irqNum = 101; // (Mandatory) Interrupt number
            }
            ...
            //(Optional) Add nodes to the device_info.hcs file as required.
            }
        }
        }
        ```

3.  Initialize the **SpiCntlr** object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating **SpiCntlrMethod** \(used to call underlying functions of the driver\) in **SpiCntlr**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **spi\_config.hcs** file are read by HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values, such as the device number and bus number, are also passed to the object at the core layer.

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
        
        // SpiCntlr is the core layer controller structure. Its members are assigned with values by using the Init function.
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

    -   Instantiate the callback function structure **SpiCntlrMethod** in **SpiCntlr**. Other members are initialized by using the **Init** function.

        ```
        // Example in spi_hi35xx.c: instantiate the hook.
        struct SpiCntlrMethod g_method = {
            .Transfer = Pl022Transfer,
            .SetCfg = Pl022SetCfg,
            .GetCfg = Pl022GetCfg,
            .Open = Pl022Open,
            .Close = Pl022Close,
        };
        ```

    -   Bind function

        Input parameters:

       **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS

        Function description:

        Associates the **SpiCntlr** object with **HdfDeviceObject**.

        ```
        static int32_t HdfSpiDeviceBind(struct HdfDeviceObject *device)
        {
            ...
            return (SpiCntlrCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS;
        }
        
        struct SpiCntlr *SpiCntlrCreate(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL; // Create the SpiCntlr object of the core layer.
            ...
             cntlr = (struct SpiCntlr *)OsalMemCalloc(sizeof(*cntlr));// Allocate memory.
            ...
            cntlr->device = device; // Enable conversion between HdfDeviceObject and SpiCntlr.
             device->service = &(cntlr->service); // Enable conversion between HdfDeviceObject and SpiCntlr.
            (void)OsalMutexInit(&cntlr->lock); // Initialize the lock.
            DListHeadInit(&cntlr->list); // Add the corresponding node.
            cntlr->priv = NULL;
            return cntlr;
        }
        ```

    -   Init function

        Input parameters:

       **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **/drivers/framework/include/utils/hdf\_base.h** file.\)

       **Table  2** Input parameters and return values of the init function

        <a name="table4311552173914"></a>
        <table><thead align="left"><tr id="row8314152103916"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p331413523392"><a name="p331413523392"></a><a name="p331413523392"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p7314145220390"><a name="p7314145220390"></a><a name="p7314145220390"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row93142052183918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p93141252123914"><a name="p93141252123914"></a><a name="p93141252123914"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p331485215390"><a name="p331485215390"></a><a name="p331485215390"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row331445211399"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p83141352183917"><a name="p83141352183917"></a><a name="p83141352183917"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15314175220397"><a name="p15314175220397"></a><a name="p15314175220397"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row20314175213918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9314352113917"><a name="p9314352113917"></a><a name="p9314352113917"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p131535273910"><a name="p131535273910"></a><a name="p131535273910"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row1431565233911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0315052103915"><a name="p0315052103915"></a><a name="p0315052103915"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1831585215398"><a name="p1831585215398"></a><a name="p1831585215398"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row2315152193914"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7315185263919"><a name="p7315185263919"></a><a name="p7315185263919"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1731585213910"><a name="p1731585213910"></a><a name="p1731585213910"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row5315752163916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6315105211392"><a name="p6315105211392"></a><a name="p6315105211392"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p83157528399"><a name="p83157528399"></a><a name="p83157528399"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and **SpiCntlr**.

        ```
        static int32_t HdfSpiDeviceInit(struct HdfDeviceObject *device)
        {
        int32_t ret;
        struct SpiCntlr *cntlr = NULL;
        ...
            cntlr = SpiCntlrFromDevice(device);// Forcibly convert HdfDeviceObject to SpiCntlr by using service. For details about the value assignment, see the Bind function.
                                            //return (device == NULL) ? NULL : (struct SpiCntlr *)device->service;
        ...
        ret = Pl022Init(cntlr, device);// (Mandatory) Instantiate the operation object customized by the vendor. The following is an example:
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
        pl022 = (struct Pl022 *)OsalMemCalloc(sizeof(*pl022));// Apply for memory.
        ...
        ret = SpiGetBaseCfgFromHcs(pl022, device->property); // Initialize busNum, numCs, speed, fifoSize, clkRate, mode, bitsPerWord, and transferMode.
        ...
        ret = SpiGetRegCfgFromHcs(pl022, device->property); // Initialize regBase, phyBase, irqNum, regCrg, clkEnBit ,clkRstBit, regMiscCtrl, miscCtrlCs, and miscCtrlCsShift.
        ...
        // Calculate the frequencies corresponding to the maximum and minimum speeds.
        pl022->maxSpeedHz = (pl022->clkRate) / ((SCR_MIN + 1) * CPSDVSR_MIN);
        pl022->minSpeedHz = (pl022->clkRate) / ((SCR_MAX + 1) * CPSDVSR_MAX);
        DListHeadInit(&pl022->deviceList);// Initialize the DList linked list.
        pl022->cntlr = cntlr;                // Enable conversion between Pl022 and SpiCntlr.
        cntlr->priv = pl022;              // Enable conversion between Pl022 and SpiCntlr.
        cntlr->busNum = pl022->busNum;    // Assign a value to busNum in SpiCntlr.
        cntlr->method = &g_method;        // Connect to the SpiCntlrMethod instance.
        ...
        ret = Pl022CreatAndInitDevice(pl022);
        if (ret != 0) {
            Pl022Release(pl022);             // Release the Pl022 object if the initialization fails.
            return ret;
        }
        return 0;
        }
        ```
		
    -   Release function

        Input parameters:

       **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.

        ```
        static void HdfSpiDeviceRelease(struct HdfDeviceObject *device)
        {
            struct SpiCntlr *cntlr = NULL;
            ...
            cntlr = SpiCntlrFromDevice(device);// Forcibly convert HdfDeviceObject to SpiCntlr by using service. For details about the value assignment, see the Bind function.
                                            // return (device==NULL) ?NULL:(struct SpiCntlr *)device->service;
            ...
            if (cntlr->priv != NULL) {
                Pl022Remove((struct Pl022 *)cntlr->priv);// A forced conversion from SpiCntlr to Pl022 is involved. 
            }
            SpiCntlrDestroy(cntlr);                         // Release the Pl022 object.
        }
        ```