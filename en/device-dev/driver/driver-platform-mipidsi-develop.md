# MIPI DSI<a name="EN-US_TOPIC_0000001199825369"></a>


## Overview<a name="section1266787503161538"></a>

The Display Serial Interface \(DSI\) is a specification developed by the Mobile Industry Processor Interface \(MIPI\) Alliance to reduce the cost of display controllers in mobile devices. In the Hardware Driver Foundation (HDF) framework, the MIPI DSI module uses the service-free mode for API adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the OS system that does not distinguish the user mode and the kernel mode. In the service-free mode,  **DevHandle**  \(a void pointer\) directly points to the kernel-mode address of the device object.

**Figure  1**  Service-free mode<a name="fig207610236189"></a>  
![](figures/service-free-mode.png "service-free-mode")

## Available APIs<a name="section752964871810"></a>

MipiDsiCntlrMethod

```
struct MipiDsiCntlrMethod {// Member functions of the core layer structure
    int32_t (*setCntlrCfg)(struct MipiDsiCntlr *cntlr);
    int32_t (*setCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd);
    int32_t (*getCmd)(struct MipiDsiCntlr *cntlr, struct DsiCmdDesc *cmd, uint32_t readLen, uint8_t *out);
    void (*toHs)(struct MipiDsiCntlr *cntlr);
    void (*toLp)(struct MipiDsiCntlr *cntlr);
    void (*enterUlps)(struct MipiDsiCntlr *cntlr);//(Optional) Enter the ultra-low power consumption mode.
    void (*exitUlps)(struct MipiDsiCntlr *cntlr); // (Optional) Exit the ultra-low power consumption mode.
    int32_t (*powerControl)(struct MipiDsiCntlr *cntlr, uint8_t enable);// (Optional) Enable or disable power control.
    int32_t (*attach)(struct MipiDsiCntlr *cntlr);// (Optional) Connect a DSI device to the host.
};
```

**Table  1**  Callbacks for the members in the MipiDsiCntlrMethod structure

<a name="table218771071713"></a>
<table><thead align="left"><tr id="row1188121012177"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p118851010174"><a name="p118851010174"></a><a name="p118851010174"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p121881109177"><a name="p121881109177"></a><a name="p121881109177"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p1818831011176"><a name="p1818831011176"></a><a name="p1818831011176"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p1418815106171"><a name="p1418815106171"></a><a name="p1418815106171"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p10949971916"><a name="p10949971916"></a><a name="p10949971916"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row318920102175"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p01891103178"><a name="p01891103178"></a><a name="p01891103178"></a>setCntlrCfg</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1518931041716"><a name="p1518931041716"></a><a name="p1518931041716"></a><strong id="b14872821599"><a name="b14872821599"></a><a name="b14872821599"></a>cntlr</strong>: structure pointer to the MIPI DSI controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p51893103174"><a name="p51893103174"></a><a name="p51893103174"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p15189111019176"><a name="p15189111019176"></a><a name="p15189111019176"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p918911010174"><a name="p918911010174"></a><a name="p918911010174"></a>Sets controller parameters.</p>
</td>
</tr>
<tr id="row10189210151713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p518991017171"><a name="p518991017171"></a><a name="p518991017171"></a>setCmd</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p177917412215"><a name="p177917412215"></a><a name="p177917412215"></a><strong id="b4791144113213"><a name="b4791144113213"></a><a name="b4791144113213"></a>cntlr</strong>: structure pointer to the MIPI DSI controller. </p>
<p id="p12189131018174"><a name="p12189131018174"></a><a name="p12189131018174"></a><strong id="b192414338012"><a name="b192414338012"></a><a name="b192414338012"></a>cmd</strong>: structure pointer to the input instruction.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p191891210111710"><a name="p191891210111710"></a><a name="p191891210111710"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p15189201019178"><a name="p15189201019178"></a><a name="p15189201019178"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p15190110141710"><a name="p15190110141710"></a><a name="p15190110141710"></a>Sends instructions to a display device.</p>
</td>
</tr>
<tr id="row2190161061714"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p111901810181715"><a name="p111901810181715"></a><a name="p111901810181715"></a>getCmd</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p121902101179"><a name="p121902101179"></a><a name="p121902101179"></a><strong id="b516432716114"><a name="b516432716114"></a><a name="b516432716114"></a>cntlr</strong>: structure pointer to the MIPI DSI controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1519018101171"><a name="p1519018101171"></a><a name="p1519018101171"></a>cmd: structure pointer to the instruction to output.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p101904107171"><a name="p101904107171"></a><a name="p101904107171"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p519061031710"><a name="p519061031710"></a><a name="p519061031710"></a>Reads instructions from the display device.</p>
</td>
</tr>
<tr id="row1919071016171"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p16190131051710"><a name="p16190131051710"></a><a name="p16190131051710"></a>toHs</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p151906102178"><a name="p151906102178"></a><a name="p151906102178"></a><strong id="b159559351014"><a name="b159559351014"></a><a name="b159559351014"></a>cntlr</strong>: structure pointer to the MIPI DSI controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p10190181031720"><a name="p10190181031720"></a><a name="p10190181031720"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p019015102174"><a name="p019015102174"></a><a name="p019015102174"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p2190310101715"><a name="p2190310101715"></a><a name="p2190310101715"></a>Sets the high-speed mode.</p>
</td>
</tr>
<tr id="row01911510161718"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p10191141081717"><a name="p10191141081717"></a><a name="p10191141081717"></a>toLp</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p819121011714"><a name="p819121011714"></a><a name="p819121011714"></a><strong id="b189629351219"><a name="b189629351219"></a><a name="b189629351219"></a>cntlr</strong>: structure pointer to the MIPI DSI controller.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p3191510171717"><a name="p3191510171717"></a><a name="p3191510171717"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p8191110151714"><a name="p8191110151714"></a><a name="p8191110151714"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1919121091712"><a name="p1919121091712"></a><a name="p1919121091712"></a>Sets the low-power mode.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section545182932161538"></a>

The MIPI DSI module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the  **HdfDriverEntry**  structure.
    -   Call  **HDF\_INIT**  to register the  **HdfDriverEntry**  instance with the HDF framework.

2.  Configure attribute files.
    -   Add the  **deviceNode**  information to the  **device\_info.hcs**  file.
    -   \(Optional\) Add the  **mipidsi\_config.hcs**  file.

3.  Instantiate the MIPI DSI controller object.
    -   Initialize  **MipiDsiCntlr**.
    -   Instantiate  **MipiDsiCntlrMethod**  in the  **MipiDsiCntlr**  object.

        >![](../public_sys-resources/icon-note.gif) **NOTE**
 
        >For details, see [Available APIs](#available-apis).


4.  Debug the driver.
    -   \(Optional\) For new drivers, verify basic functions, for example, verify the information returned after the connect operation and whether data is successfully transmitted.



## Development Example<a name="section1167576616161538"></a>

The following uses  **mipi\_tx\_hi35xx.c**  as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Generally, you need to configure the device attributes in  **xx\_config.hcs**  and add the  **deviceNode**  information to the  **device\_info.hcs**  file. The device attribute values are closely related to the default values or value range of the  **MipiDsiCntlr**  members at the core layer. The  **deviceNode**  information is related to the driver entry registration.

    In this example, no additional attribute needs to be configured for the MIPI DSI controller. If required, you need to add the  **deviceMatchAttr**  information to  **deviceNode**  in the  **device\_info**  file and add the  **mipidsi\_config**  file.

    -   **device\_info.hcs**  configuration reference

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
                 moduleName = "HDF_MIPI_TX"; // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                  serviceName = "HDF_MIPI_TX";// (Mandatory) Unique name of the service published by the driver
                }
            }
            }
        }
        }
        ```

2.  Instantiate the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. The function pointer members of the  **HdfDriverEntry**  structure are filled by the vendors' operation functions. In the HDF framework, the start address of each  **HdfDriverEntry**  object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the  **Bind**  function and then the  **Init**  function to load a driver. If  **Init**  fails to be called, HDF calls  **Release**  to release driver resources and exits.

    -   MIPI DSI driver entry reference

        ```
        struct HdfDriverEntry g_mipiTxDriverEntry = {
            .moduleVersion = 1,             
             .Init = Hi35xxMipiTxInit, // See the Init function.
            .Release = Hi35xxMipiTxRelease, //See the Release function.
            .moduleName = "HDF_MIPI_TX", // (Mandatory) The value must be the same as that in the device_info.hcs file.
        };
        HDF_INIT(g_mipiTxDriverEntry);  // Call HDF_INIT to register the driver entry with the HDF framework.
        ```

3.  Initialize the  **MipiDsiCntlr**  object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating  **MipiDsiCntlrMethod**  \(used to call underlying functions of the driver\) in  **MipiDsiCntlr**, and implementing the  **HdfDriverEntry**  member functions \(**Bind**,  **Init**, and  **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the  **config**  file are used to initialize the structure members. In this example, the MIPI DSI has no device attribute file. Therefore, the basic member structure is similar to that of  **MipiDsiCntlr**.

        ```
        typedef struct {
          unsigned int devno; // Device number
          short laneId[LANE_MAX_NUM]; // Lane ID
          OutPutModeTag outputMode; // Output mode, which can be CSI mode, DSI Video mode, or DSI Command mode.
          VideoModeTag videoMode; // Synchronization mode of the display device
          OutputFormatTag outputFormat; // Format of the output DSI image, which can be RGB or YUV.
          SyncInfoTag syncInfo; // Settings related to timing
          unsigned int    phyDataRate;          // mbps 
          unsigned int    pixelClk;             // KHz
        } ComboDevCfgTag;
        
        // MipiDsiCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct MipiDsiCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          unsigned int devNo; // Device number
          struct MipiCfg cfg;
          struct MipiDsiCntlrMethod *ops;
          struct OsalMutex  lock;
          void *priv;
        };
        ```

    -   Instantiate the callback function structure  **MipiDsiCntlrMethod**  in  **MipiDsiCntlr**. Other members are initialized by using the Init  function.

        ```
        static struct MipiDsiCntlrMethod g_method = {
            .setCntlrCfg = Hi35xxSetCntlrCfg,
            .setCmd = Hi35xxSetCmd,
            .getCmd = Hi35xxGetCmd,
            .toHs = Hi35xxToHs,
            .toLp = Hi35xxToLp,
        };
        ```

    -   Init function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see  **HDF\_STATUS**  in the  **//drivers/framework/include/utils/hdf\_base.h**  file.\)

        <a name="table344041707161538"></a>
        <table><thead align="left"><tr id="row1205250994161538"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1646623665161538p0"><a name="entry1646623665161538p0"></a><a name="entry1646623665161538p0"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry36551796161538p0"><a name="entry36551796161538p0"></a><a name="entry36551796161538p0"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row1245832689161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry635453137161538p0"><a name="entry635453137161538p0"></a><a name="entry635453137161538p0"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1681554112161538p0"><a name="entry1681554112161538p0"></a><a name="entry1681554112161538p0"></a>Invalid object</p>
        </td>
        </tr>
        <tr id="row86233502161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2128705324161538p0"><a name="entry2128705324161538p0"></a><a name="entry2128705324161538p0"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1664050443161538p0"><a name="entry1664050443161538p0"></a><a name="entry1664050443161538p0"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row230078441161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry325107899161538p0"><a name="entry325107899161538p0"></a><a name="entry325107899161538p0"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry754791216161538p0"><a name="entry754791216161538p0"></a><a name="entry754791216161538p0"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row20758403161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1970333605161538p0"><a name="entry1970333605161538p0"></a><a name="entry1970333605161538p0"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1122658595161538p0"><a name="entry1122658595161538p0"></a><a name="entry1122658595161538p0"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row1425117417161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1844298129161538p0"><a name="entry1844298129161538p0"></a><a name="entry1844298129161538p0"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry712326009161538p0"><a name="entry712326009161538p0"></a><a name="entry712326009161538p0"></a>Operation successful</p>
        </td>
        </tr>
        <tr id="row1899574933161538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1964112434161538p0"><a name="entry1964112434161538p0"></a><a name="entry1964112434161538p0"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1481231483161538p0"><a name="entry1481231483161538p0"></a><a name="entry1481231483161538p0"></a>Operation failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Connects to the  **MipiDsiCntlrMethod**  instance, calls  **MipiDsiRegisterCntlr**, and performs other vendor-defined initialization operations.

        ```
        static int32_t Hi35xxMipiTxInit(struct HdfDeviceObject *device)
        {
        int32_t ret;
        g_mipiTx.priv = NULL; // g_mipiTx is a global variable.
                                //static struct MipiDsiCntlr g_mipiTx { 
                                //     .devNo=0
                                //};
        g_mipiTx.ops = &g_method;// Connect to the MipiDsiCntlrMethod instance.
        ret = MipiDsiRegisterCntlr(&g_mipiTx, device);// (Mandatory) Call the function at the core layer and g_mipiTx to initialize global variables at the core layer.
        ...
        return MipiTxDrvInit(0); // (Mandatory) Device initialization customized by the vendor.
        }
        
        // mipi_dsi_core.c, core layer file. 
        int32_t MipiDsiRegisterCntlr(struct MipiDsiCntlr *cntlr, struct HdfDeviceObject *device)
        {
        ...
        // Define the global variable static struct MipiDsiHandle g_mipiDsihandle[MAX_CNTLR_CNT].
        if (g_mipiDsihandle[cntlr->devNo].cntlr == NULL) {
            (void)OsalMutexInit(&g_mipiDsihandle[cntlr->devNo].lock);
            (void)OsalMutexInit(&(cntlr->lock));
        
            g_mipiDsihandle[cntlr->devNo].cntlr = cntlr;// Initialize MipiDsiHandle.
            g_mipiDsihandle[cntlr->devNo].priv = NULL;  
            cntlr->device = device; // Enable conversion between HdfDeviceObject and MipiDsiHandle.
             device->service = &(cntlr->service);  // Enable conversion between HdfDeviceObject and MipiDsiHandle.
            cntlr->priv = NULL;    
            ...
            return HDF_SUCCESS;
        }
        ...
        return HDF_FAILURE;
        }
        ```

    -   Release function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the  **Release**  API in the driver entry structure. When the HDF framework fails to call the  **Init**  function to initialize the driver, the  **Release**  function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the  **Init**  function has the corresponding value assignment operations.

        ```
        static void Hi35xxMipiTxRelease(struct HdfDeviceObject *device)
        {
        struct MipiDsiCntlr *cntlr = NULL;
        ...
        cntlr = MipiDsiCntlrFromDevice(device);// A forced conversion from HdfDeviceObject to MipiDsiCntlr is involved.
                                                //return (device == NULL) ? NULL : (struct MipiDsiCntlr *)device->service;
        ...
        MipiTxDrvExit(); // (Mandatory) Release the resources occupied by the vendor's devices.
        MipiDsiUnregisterCntlr(&g_mipiTx); // Empty function
        g_mipiTx.priv = NULL;
        HDF_LOGI("%s: unload mipi_tx driver 1212!", __func__);
        } 
        ```



