# Pin<a name="title_PinDevelop"></a>


## Overview<a name="section1_PinDevelop"></a>

The pin module controls the states and functionalities of system pins. In the Hardware Driver Foundation (HDF), the pin module uses the service-free mode for API adaptation. The service-free mode applies to devices that do not provide user-mode APIs or the OS system that does not distinguish the user mode and the kernel mode. In the service-free mode, DevHandle (a void pointer) directly points to the kernel-mode address of the device object.

Figure 1 Service-free mode
![image1](figures/service-free-mode.png "service-free-mode")

## Available APIs<a name="section2_PinDevelop"></a>

**PinCntlrMethod**:

```c
struct PinCntlrMethod {
    int32_t (*SetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType pullType);
    int32_t (*GetPinPull)(struct PinCntlr *cntlr, uint32_t index, enum PinPullType *pullType);
    int32_t (*SetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t strength);
    int32_t (*GetPinStrength)(struct PinCntlr *cntlr, uint32_t index, uint32_t *strength);
    int32_t (*SetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char *funcName);
    int32_t (*GetPinFunc)(struct PinCntlr *cntlr, uint32_t index, const char **funcName);
};
```

**Table 1** APIs for the members in the PinCntlrMethod structure

| API    | Input Parameter                                       | Return Value| Description|
| ------------ | ------------------------------------------- | ------ | ---- |
| SetPinPull | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**pullType**: pull type of the pin. It is an enum constant.|HDF_STATUS|Sets the pull type of a pin.|
| GetPinPull | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**pullType**: pointer to the pull type of the pin.| HDF_STATUS| Obtains the pull type of a pin.|
| SetPinStrength | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**strength**: pull strength of the pin. It is a uint32_t variable.| HDF_STATUS| Sets the pull strength of a pin.|
| GetPinStrength | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**strength**: pointer to the pull strength of the pin.| HDF_STATUS| Obtains the pull strength of a pin.|
| SetPinFunc | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**funcName**: char pointer to the pin functionality.| HDF_STATUS| Sets the pin functionality.|
| GetPinFunc | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable.<br>**funcName**: char double pointer to the pin functionality.| HDF_STATUS| Obtains the pin functionalities.|

## How to Develop<a name="section3_PinDevelop"></a>

The pin module adaptation involves the following steps:

1. Instantiate the driver entry.
   
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.
   
2. Configure attribute files.

   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **pin_config.hcs** file.

3. Instantiate the pin controller object.
   
   - Initialize the **PinCntlr** object.
   
   - Instantiate **PinCntlrMethod** in the **PinCntlr** object.
   
        >![](../public_sys-resources/icon-note.gif) **NOTE**
        >For details, see [Available APIs](#section2_PINDevelop).
   
4. Debug the driver.
   
   - (Optional) Verify basic functionalities of new drivers. For example, verify the information returned when the driver is loaded and whether data is successfully transmitted.

## Development Example<a name="section4_PinDevelop"></a>

The following uses **pin_hi35xx.c** as an example to present the content to be provided by the vendor to implement device functionalities.

1. Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf\_device\_desc.h**), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers are collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load the driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   Pin driver entry reference:

   ```c
   static struct HdfDriverEntry g_hi35xxPinDriverEntry = {
       .moduleVersion = 1,
       .Bind = Hi35xxPinBind,
       .Init = Hi35xxPinInit,
       .Release = Hi35xxPinRelease,
       .moduleName = "hi35xx_pin_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_hi35xxPinDriverEntry);
   ```

2. Add **deviceNode** to the **device\_info.hcs** file, and set the device attributes in the **pin\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **PinCntlr** members at the core layer.
   
    >![](../public_sys-resources/icon-note.gif) **NOTE**
   >If there are multiple devices, add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **pin\_config** file.

   - **device\_info.hcs** reference:

     ```c
     root {
       device_info { 
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_pin :: device {
                     device0:: deviceNode {   // Set an HDF device node for each pin controller.
                         policy = 0;			  // 2: visible in user mode; 1: visible in kernel mode; 0: no service required.
                         priority = 10;        // Driver startup priority.
                         permission = 0644;    // Permission to create device nodes for the driver.
                         /* (Mandatory) Driver name, which must be the same as the moduleName in the driver entry. */
                         moduleName = "hi35xx_Pin_driver";
                         /* (Mandatory) Set the controller private data, which must be same as that in Pin_config.hcs. */
                         deviceMatchAttr = "hisilicon_hi35xx_Pin_0";
                     }
                     device1 :: deviceNode {
                         policy = 0;
                         priority = 10;
                         permission = 0644;
                         moduleName = "hi35xx_Pin_driver";
                         deviceMatchAttr = "hisilicon_hi35xx_Pin_1";
                     }
               		...
           }
         }
       }
     }
     ```

   - **Pin\_config.hcs** reference:

     ```c
     root {
         platform {
             Pin_config_hi35xx {
                 template Pin_controller {    // (Mandatory) Template configuration. In the template, you can configure the common parameters shared by device nodes.
                     number = 0;              // (Mandatory) Controller ID.
                     regStartBasePhy = 0;     // (Mandatory) Start physical base address of the register.
                     regSize = 0;           // (Mandatory) Register bit width.
                     PinCount = 0;            // (Mandatory) Number of pins.
                     match_attr = "";
                     template Pin_desc {
                         PinName = "";        // (Mandatory) Pin name.
                         init = 0;           // (Mandatory) Default value of the register.
                         F0 = "";             // (Mandatory) Functionality 0.
                         F1 = "";             // Functionality 1.
                         F2 = "";             // Functionality 2.
                         F3 = "";             // Functionality 3.
                         F4 = "";             // Functionality 4.
                         F5 = "";             // Functionality 5.
                     }
                 }
                 controller_0 :: Pin_controller {
                     number = 0;
                     regStartBasePhy = 0x10FF0000;
                     regSize = 0x48;
                     PinCount = 18;
                     match_attr = "hisilicon_hi35xx_Pin_0";
                     T1 :: Pin_desc {
                         PinName = "T1";
                         init = 0x0600;
                         F0 = "EMMC_CLK";
                         F1 = "SFC_CLK";
                         F2 = "SFC_BOOT_MODE";
                     }
                     ...
                 }
                 ...// Each pin controller corresponds to a controller node. If there are multiple pin controllers, add the corresponding controller nodes one by one.
             }
         }
     }
     ```
   
3. Initialize the **PinCntlr** object at the core layer, including initializing the vendor custom structure (passing parameters and data), instantiating **PinCntlrMethod** (used to call underlying functions of the driver) in **PinCntlr**, and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**).

   - Initializing the vendor custom structure

     The **PinCntlr** structure holds parameters and data for the driver. The HDF obtains the values in **pin\_config.hcs** using **DeviceResourceIface**.

     ```c
     // PinCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function.
     struct PinCntlr {
         struct IDeviceIoService service;
         struct HdfDeviceObject *device;
         struct PinCntlrMethod *method;
         struct DListHead node;
         OsalSPinlock sPin;
         uint16_t number;
         uint16_t PinCount;
         struct PinDesc *Pins;
         void *priv;
     };
     
     struct PinDesc {
         const char *PinName;    // Pointer to the pin name.
         void *priv;
     };
     ```
     
   - Instantiating **PinCntlrMethod** (other members are initialized by **Init**)
   
     ```c
     // Example of Pin_hi35xx.c: Instantiate the hook.
     static struct PinCntlrMethod g_method = {
         .SetPinPull = Hi35xxPinSetPull,
         .GetPinPull = Hi35xxPinGetPull,
         .SetPinStrength = Hi35xxPinSetStrength,
         .GetPinStrength = Hi35xxPinGetStrength,
         .SetPinFunc = Hi35xxPinSetFunc,
         .GetPinFunc = Hi35xxPinGetFunc,
     };
     ```
     
   - **Init** function
   
     Input parameters:
   
     **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration.
   
     Return value:
   
     **HDF\_STATUS** (The following table lists some states. For more details, see **HDF\_STATUS** in **/drivers/framework/include/utils/hdf\_base.h**.)
   
     **Table 2** HDF\_STATUS
   
     <table><thead align="left"><tr id="row31521027164144"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1990732428164144p0"><a name="entry1990732428164144p0"></a><a name="entry1990732428164144p0"></a>State</p>
     </th>
     <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry2123581292164144p0"><a name="entry2123581292164144p0"></a><a name="entry2123581292164144p0"></a>Description</p>
     </th>
     </tr>
     </thead>
     <tbody><tr id="row1749271383164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry202330388164144p0"><a name="entry202330388164144p0"></a><a name="entry202330388164144p0"></a>HDF_ERR_INVALID_OBJECT</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1717598064164144p0"><a name="entry1717598064164144p0"></a><a name="entry1717598064164144p0"></a>Invalid controller object</p>
     </td>
     </tr>
     <tr id="row1715354988164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry450625221164144p0"><a name="entry450625221164144p0"></a><a name="entry450625221164144p0"></a>HDF_ERR_MALLOC_FAIL</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry361497788164144p0"><a name="entry361497788164144p0"></a><a name="entry361497788164144p0"></a>Failed to allocate memory</p>
     </td>
     </tr>
     <tr id="row1202091366164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry370837906164144p0"><a name="entry370837906164144p0"></a><a name="entry370837906164144p0"></a>HDF_ERR_INVALID_PARAM</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry353311523164144p0"><a name="entry353311523164144p0"></a><a name="entry353311523164144p0"></a>Invalid parameter</p>
     </td>
     </tr>
     <tr id="row602018308164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1984036607164144p0"><a name="entry1984036607164144p0"></a><a name="entry1984036607164144p0"></a>HDF_ERR_IO</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1221756048164144p0"><a name="entry1221756048164144p0"></a><a name="entry1221756048164144p0"></a>I/O error</p>
     </td>
     </tr>
     <tr id="row47997479164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1220816374164144p0"><a name="entry1220816374164144p0"></a><a name="entry1220816374164144p0"></a>HDF_SUCCESS</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1903499126164144p0"><a name="entry1903499126164144p0"></a><a name="entry1903499126164144p0"></a>Initialization successful</p>
     </td>
     </tr>
     <tr id="row2031856197164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry463793674164144p0"><a name="entry463793674164144p0"></a><a name="entry463793674164144p0"></a>HDF_FAILURE</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry516362874164144p0"><a name="entry516362874164144p0"></a><a name="entry516362874164144p0"></a>Initialization failed</p>
     </td>
     </tr>
     </tbody>
     </table>

      Function description:
	  
      Initializes the custom structure and **PinCntlr** members, and connects to the pin controller by calling the **PinCntlrAdd** function at the core layer.

        ```c
        static int32_t Hi35xxPinInit(struct HdfDeviceObject *device)
        {
            ...
            struct Hi35xxPinCntlr *hi35xx = NULL;
            ...
            ret = Hi35xxPinCntlrInit(device, hi35xx);    // Obtain .hcs information.
            ...
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxPinParsePinNode(childNode, hi35xx, index);    // (Mandatory) The implementation is as follows:
                ...
            }
     
            hi35xx->cntlr.method = &g_method; // Instantiate OPS.
            ret = PinCntlrAdd(&hi35xx->cntlr);   // Connect to the controller.
            ...
        }
     
        static int32_t Hi35xxPinParsePinNode(const struct DeviceResourceNode *node,
                                             struct Hi35xxPinCntlr *hi35xx,
                                             int32_t index)
        {
            ...
            hi35xx->cntlr.Pins[index].PinName = hi35xx->desc[index].PinName;    // Instantiate PinName.
            hi35xx->cntlr.Pins[index].priv = (void *)node;					    // Instantiate nodes.
            ...
        }

   
   - **Release** function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration.

        Return value:

        –

        Function description:

        Releases memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

        ```c
        static void Hi35xxPinRelease(struct HdfDeviceObject *device)
        {
        struct PinCntlr *cntlr = NULL;
        ...
        PinCntlrRemove(cntlr);// (Mandatory) Call the function at the core layer to release pin controller devices and services.
        ...
        }
        ```
