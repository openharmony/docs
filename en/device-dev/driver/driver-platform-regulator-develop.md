# Regulator<a name="title_REGULATORDevelop"></a>


## Overview<a name="section1_REGULATORDevelop"></a>

The regulator module controls the voltage and current supplies of some devices in the system. In the Hardware Driver Foundation (HDF), the regulator module uses the unified service mode for API adaptation. In this mode, a device service is used as the regulator manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the regulator has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and more memory resources will be consumed by services.

**Figure 1** Unified service mode
![image1](figures/unified-service-mode.png)

## Available APIs<a name="section2_REGULATORDevelop"></a>

**RegulatorMethod** structure:

```c
struct RegulatorMethod {
    int32_t (*open)(struct RegulatorNode *node);
    int32_t (*close)(struct RegulatorNode *node);
    int32_t (*release)(struct RegulatorNode *node);
    int32_t (*enable)(struct RegulatorNode *node);
    int32_t (*disable)(struct RegulatorNode *node);
    int32_t (*forceDisable)(struct RegulatorNode *node);
    int32_t (*setVoltage)(struct RegulatorNode *node, uint32_t minUv, uint32_t maxUv);
    int32_t (*getVoltage)(struct RegulatorNode *node, uint32_t *voltage);
    int32_t (*setCurrent)(struct RegulatorNode *node, uint32_t minUa, uint32_t maxUa);
    int32_t (*getCurrent)(struct RegulatorNode *node, uint32_t *regCurrent);
    int32_t (*getStatus)(struct RegulatorNode *node, uint32_t *status);
};
```

**Table 1** APIs for the members in the RegulatorMethod structure

| Method    | Input Parameter                                       | Return Value| Description|
| ------------ | ------------------------------------------- | ------ | ---- |
| open         | **node**: structure pointer to the regulator node at the core layer.|HDF_STATUS|Opens a device.|
| close        | **node**: structure pointer to the regulator node at the core layer.| HDF_STATUS| Closes a device.|
| release      | **node**: structure pointer to the regulator node at the core layer.| HDF_STATUS| Releases a device handle.|
| enable       | **node**: structure pointer to the regulator node at the core layer.| HDF_STATUS| Enables a device.|
| disable      | **node**: structure pointer to the regulator node at the core layer.| HDF_STATUS| Disables a device.|
| forceDisable | **node**: structure pointer to the regulator node at the core layer.| HDF_STATUS| Forcibly disables a device.|
| setVoltage   | **node**: structure pointer to the regulator node at the core layer.<br>**minUv**: minimum voltage to set. It is a uint32_t variable.<br>**maxUv**: maximum voltage to set. It is a uint32_t variable.| HDF_STATUS| Sets the output voltage range.|
| getVoltage   | **node**: structure pointer to the regulator node at the core layer.<br>**voltage**: pointer to the output voltage value.| HDF_STATUS| Obtains the voltage.|
| setCurrent   | **node**: structure pointer to the regulator node at the core layer.<br>**minUa**: minimum current to set. It is a uint32_t variable.<br>**maxUa**: maximum current to set. It is a uint32_t variable.| HDF_STATUS| Sets the output current range.|
| getCurrent   | **node**: structure pointer to the regulator node at the core layer.<br>**regCurrent**: pointer to the output current, which is of the uint32_t type.| HDF_STATUS| Obtains the current.|
| getStatus    | **node**: structure pointer to the regulator node at the core layer.<br>**status**: pointer to the output status, which is of the uint32_t type.| HDF_STATUS| Obtains the device status.|

## How to Develop<a name="section3_REGULATORDevelop"></a>

The regulator module adaptation involves the following steps:

1. Instantiate the driver entry.  
   
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.
   
2. Configure attribute files.  

   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **regulator_config.hcs** file.

3. Instantiate the regulator controller object.  
   
   - Initialize **RegulatorNode** members.
   
   - Instantiate **RegulatorMethod**.
   
        >![](../public_sys-resources/icon-note.gif) **NOTE**
        >For details, see [Available APIs](#section2_REGULATORDevelop).
   
4. Debug the driver.
   - (Optional) Verify basic functionalities of new drivers. For example, verify the information returned when the driver is loaded and whether data is successfully transmitted.

## Development Example<a name="section4_REGULATORDevelop"></a>

The following uses **regulator_virtual.c** as an example to present the content to be provided by the vendor to implement device functionalities.

1. Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf\_device\_desc.h**), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers are collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load the driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   Regulator driver entry reference:

   ```c
   struct HdfDriverEntry g_regulatorDriverEntry = {
       .moduleVersion = 1,
       .moduleName = "virtual_regulator_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
       .Init = VirtualRegulatorInit,
       .Release = VirtualRegulatorRelease,
   };
   // Call HDF_INIT to register the driver entry with the HDF framework.
   HDF_INIT(g_regulatorDriverEntry);
   ```

2. Add **deviceNode** to the **device\_info.hcs** file, and set the device attributes in the **regulator\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **RegulatorNode** members at the core layer.

   >![](W:\doc\docs\en\device-dev\public_sys-resources\icon-note.gif) **NOTE**
   >If there are multiple devices, add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **regulator\_config** file.

   - **device\_info.hcs** reference:

     ```c
     root {
       device_info { 
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_regulator :: device {
               device0 :: deviceNode {	// Configure an HDF device node for each regulator controller.
                   policy = 1;			// 2: visible in user mode; 1: visible in kernel mode; 0: no service required.
                   priority = 50;		// Driver startup priority.
                   permission = 0644;	// Permission to create device nodes of the driver.
                   /* (Mandatory) Driver name, which must be the same as the moduleName in the driver entry. */
                   moduleName = "HDF_PLATFORM_REGULATOR_MANAGER";		
                   serviceName = "HDF_PLATFORM_REGULATOR_MANAGER";		// (Mandatory) Unique name of the service published by the driver.
                  /* (Mandatory) Set the controller private data, which must be same as that in regulator_config.hcs. */
                   deviceMatchAttr = "hdf_platform_regulator_manager";
               }
               device1 :: deviceNode {
                   policy = 0;
                   priority = 55;
                   permission = 0644;
                   moduleName = "linux_regulator_adapter";
                   deviceMatchAttr = "linux_regulator_adapter";
               }
           }
         }
       }
     }
     ```

   - **regulator\_config.hcs** reference:

     ```c
     root {
         platform {
             regulator_config {
     			match_attr = "linux_regulator_adapter";
     			template regulator_controller {    // (Mandatory) Template configuration. In the template, you can configure the common parameters shared by device nodes.
     			    device_num = 1;
     				name = "";
     			    devName = "regulator_adapter_consumer01";
     				supplyName = "";
     				mode = 1;
     				minUv = 0;
     				maxUv = 20000;
     				minUa = 0;
     				maxUa = 0;
     			}
     			controller_0x130d0000 :: regulator_controller {
     			    device_num = 1;
     			    name = "regulator_adapter_1";
     				devName = "regulator_adapter_consumer01";
     				supplyName = "virtual-regulator-hdf-adapter";
     				mode = 1;
     				minUv = 1000;
     				maxUv = 50000;
     				minUa = 0;
     				maxUa = 0;
     			}
                 /* Each regulator controller corresponds to a controller node. If there are multiple regulator controllers, add the corresponding controller nodes one by one.*/
     			controller_0x130d0001 :: regulator_controller {
     			    device_num = 1;
     			    name = "regulator_adapter_2";
     				devName = "regulator_adapter_consumer01";
     				supplyName = "virtual2-regulator-hdf-adapter";
     				mode = 2;
     				minUv = 0;
     				maxUv = 0;
     				minUa = 1000;
     				maxUa = 50000;
     			}
             }
         }
     }
     ```

3. Initialize the **RegulatorNode** object at the core layer, including initializing the vendor custom structure (passing parameters and data), instantiating **RegulatorMethod** (used to call underlying functions of the driver) in **PinCntlr**, and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**).

   - Initializing the vendor custom structure

     The **RegulatorNode** structure holds parameters and data for the driver. The HDF obtains the values in **regulator\_config.hcs** using **DeviceResourceIface**.

     ```c
     // RegulatorNode is the controller structure at the core layer. Its members are assigned with values by using the Init function.
     struct RegulatorNode {
         struct RegulatorDesc regulatorInfo;
         struct DListHead node;
         struct RegulatorMethod *ops;
         void *priv;
         struct OsalMutex lock;
     };
     
     struct RegulatorDesc {
         const char *name;              /* Regulator name. */
         const char *parentName;        /* Regulator parent node name. */
         struct RegulatorConstraints constraints;    /* Regulator constraint information. */
         uint32_t minUv;                  /* Minimum output voltage. */
         uint32_t maxUv;                  /* Maximum output voltage. */
         uint32_t minUa;                  /* Minimum output current. */
         uint32_t maxUa;                  /* Maximum output current. */
         uint32_t status;                  /* Regulator status, which can be on or off. */
         int useCount;
         int consumerRegNums;             /* Number of regulator consumers. */
         RegulatorStatusChangecb cb;      /* Variable used to notify the regulator status changes. */
     };
     
     struct RegulatorConstraints {
         uint8_t alwaysOn;     /* Whether the regulator is always on. */
         uint8_t mode;         /* Voltage or current. */
         uint32_t minUv;       /* Minimum output voltage allowed. */
         uint32_t maxUv;       /* Maximum output voltage allowed. */
         uint32_t minUa;     /* Minimum output current allowed. */
         uint32_t maxUa;       /* Maximum output current allowed. */
     };
     ```
     
   - Instantiating **RegulatorMethod** (other members are initialized by **Init**)
   
     ```c
     // Example of regulator_virtual.c: Instantiate the hook.
     static struct RegulatorMethod g_method = {
         .enable = VirtualRegulatorEnable,
         .disable = VirtualRegulatorDisable,
         .setVoltage = VirtualRegulatorSetVoltage,
         .getVoltage = VirtualRegulatorGetVoltage,
         .setCurrent = VirtualRegulatorSetCurrent,
         .getCurrent = VirtualRegulatorGetCurrent,
         .getStatus = VirtualRegulatorGetStatus,
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
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1717598064164144p0"><a name="entry1717598064164144p0"></a><a name="entry1717598064164144p0"></a>Invalid controller object.</p>
     </td>
     </tr>
     <tr id="row1715354988164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry450625221164144p0"><a name="entry450625221164144p0"></a><a name="entry450625221164144p0"></a>HDF_ERR_MALLOC_FAIL</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry361497788164144p0"><a name="entry361497788164144p0"></a><a name="entry361497788164144p0"></a>Failed to allocate memory.</p>
     </td>
     </tr>
     <tr id="row1202091366164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry370837906164144p0"><a name="entry370837906164144p0"></a><a name="entry370837906164144p0"></a>HDF_ERR_INVALID_PARAM</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry353311523164144p0"><a name="entry353311523164144p0"></a><a name="entry353311523164144p0"></a>Invalid parameter.</p>
     </td>
     </tr>
     <tr id="row602018308164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1984036607164144p0"><a name="entry1984036607164144p0"></a><a name="entry1984036607164144p0"></a>HDF_ERR_IO</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1221756048164144p0"><a name="entry1221756048164144p0"></a><a name="entry1221756048164144p0"></a>I/O error.</p>
     </td>
     </tr>
     <tr id="row47997479164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1220816374164144p0"><a name="entry1220816374164144p0"></a><a name="entry1220816374164144p0"></a>HDF_SUCCESS</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1903499126164144p0"><a name="entry1903499126164144p0"></a><a name="entry1903499126164144p0"></a>Initialization successful.</p>
     </td>
     </tr>
     <tr id="row2031856197164144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry463793674164144p0"><a name="entry463793674164144p0"></a><a name="entry463793674164144p0"></a>HDF_FAILURE</p>
     </td>
     <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry516362874164144p0"><a name="entry516362874164144p0"></a><a name="entry516362874164144p0"></a>Initialization failed.</p>
     </td>
     </tr>
     </tbody>
     </table>
        Function description:
        Initializes the custom structure and **RegulatorNode** members, and adds the regulator controller by calling the **RegulatorNodeAdd** function at the core layer.
     
        ```c
     static int32_t VirtualRegulatorInit(struct HdfDeviceObject *device)
     {
         int32_t ret;
         const struct DeviceResourceNode *childNode = NULL;
         ...
             DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
             ret = VirtualRegulatorParseAndInit(device, childNode);// (Mandatory) The implementation is as follows:
             ...
         }
         ...
     }
     
     static int32_t VirtualRegulatorParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
     {
         int32_t ret;
         struct RegulatorNode *regNode = NULL;
         (void)device;
     
         regNode = (struct RegulatorNode *)OsalMemCalloc(sizeof(*regNode));// Load the .hcs file.
         ...
             ret = VirtualRegulatorReadHcs(regNode, node);// Read .hcs information.
         ...
             regNode->priv = (void *)node;     // Instantiate the node.
         regNode->ops = &g_method;     // Instantiate OPS.
     
         ret = RegulatorNodeAdd(regNode);     // Add the node.
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
        static void VirtualRegulatorRelease(struct HdfDeviceObject *device)
        {
            ...
            RegulatorNodeRemoveAll();// (Mandatory) Call the function at the core layer to release regulator controller devices and services.
        }
