# Development Example for Platform Drivers<a name="EN-US_TOPIC_0000001157064271"></a>

## Overview<a name="section194201316174215"></a>

This document uses the I2C driver as an example to describe how to develop platform drivers based on the hardware driver foundation \(HDF\).

>![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
>The sample code in this document is for reference only and cannot be directly used for commercial integration.

The HDF provides a standard driver framework for common peripherals. To use the APIs provided by the HDF to perform operations on peripherals, you only need to adapt the specific driver to the HDF.

In this example, an I2C driver is used.  [Figure 1](#fig9596628607)  shows the sequence diagram of the I2C driver.

**Figure  1**  I2C driver sequence diagram<a name="fig9596628607"></a>  
![](figures/i2c-driver-sequence-diagram.png "i2c-driver-sequence-diagram")

## Preparations<a name="section6926133918422"></a>

Follow the instructions in [Getting Started with the Standard System with Hi3516 (IDE Mode)](../quick-start/quickstart-appendix-hi3516-ide.md).

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>This development example applies to standard, small, and mini OpenHarmony systems. The following sections use the standard system as an example. You can refer to the specific guide for your system to set up the environment.

## Development<a name="section65801539470"></a>

### File Description<a name="section0708184454414"></a>

The following table lists the files involved in this example and their paths.

**Table  1**  File description

<a name="table15887645104012"></a>
<table><thead align="left"><tr id="row198881452404"><th class="cellrowborder" align="center" valign="top" width="13.489999999999998%" id="mcps1.2.4.1.1"><p id="p158742406488"><a name="p158742406488"></a><a name="p158742406488"></a>File</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="68.52000000000001%" id="mcps1.2.4.1.2"><p id="p6975142717432"><a name="p6975142717432"></a><a name="p6975142717432"></a>File Path</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="17.990000000000002%" id="mcps1.2.4.1.3"><p id="p98891454405"><a name="p98891454405"></a><a name="p98891454405"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="row1088914458407"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p78741540104813"><a name="p78741540104813"></a><a name="p78741540104813"></a>Sample file</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p1066541692916"><a name="p1066541692916"></a><a name="p1066541692916"></a>/drivers/adapter/khdf/linux/platform/i2c/i2c_sample.c</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p208891445144012"><a name="p208891445144012"></a><a name="p208891445144012"></a>New file</p>
</td>
</tr>
<tr id="row1388984594013"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p88741840104811"><a name="p88741840104811"></a><a name="p88741840104811"></a>Device service file</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p486417183298"><a name="p486417183298"></a><a name="p486417183298"></a>/drivers/adapter/khdf/linux/hcs/device_info/device_info.hcs</p>
</td>
<td class="cellrowborder" rowspan="3" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p128898458401"><a name="p128898458401"></a><a name="p128898458401"></a></p>
<p id="p168904455404"><a name="p168904455404"></a><a name="p168904455404"></a>New content will be added to these files.</p>
<p id="p7890124516405"><a name="p7890124516405"></a><a name="p7890124516405"></a></p>
</td>
</tr>
<tr id="row9889164513406"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p138741640124812"><a name="p138741640124812"></a><a name="p138741640124812"></a>Configuration file</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p26905191293"><a name="p26905191293"></a><a name="p26905191293"></a>/drivers/adapter/khdf/linux/hcs/platform/i2c_config.hcs</p>
</td>
</tr>
<tr id="row1189044513404"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p1687424074814"><a name="p1687424074814"></a><a name="p1687424074814"></a>Build file</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p1885032192917"><a name="p1885032192917"></a><a name="p1885032192917"></a>/drivers/adapter/khdf/linux/platform/i2c/Makefile</p>
</td>
</tr>
<tr id="row10890144564011"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p118752040104810"><a name="p118752040104810"></a><a name="p118752040104810"></a>Dependency</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p15821718182916"><a name="p15821718182916"></a><a name="p15821718182916"></a>/drivers/framework/include/core/hdf_device_desc.h</p>
</td>
<td class="cellrowborder" rowspan="2" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p989012451401"><a name="p989012451401"></a><a name="p989012451401"></a>Header file to be included</p>
<p id="p1890134594014"><a name="p1890134594014"></a><a name="p1890134594014"></a></p>
</td>
</tr>
<tr id="row6890164564015"><td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.1 "><p id="p128756401484"><a name="p128756401484"></a><a name="p128756401484"></a>Core-layer header file</p>
</td>
<td class="cellrowborder" align="left" valign="top" headers="mcps1.2.4.1.2 "><p id="p47681122152918"><a name="p47681122152918"></a><a name="p47681122152918"></a>/drivers/framework/support/platform/include/i2c_core.h</p>
</td>
</tr>
<tr id="row1499682234817"><td class="cellrowborder" align="left" valign="top" width="13.489999999999998%" headers="mcps1.2.4.1.1 "><p id="p1187513403487"><a name="p1187513403487"></a><a name="p1187513403487"></a>HCS configuration entry file</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="68.52000000000001%" headers="mcps1.2.4.1.2 "><p id="p499818225487"><a name="p499818225487"></a><a name="p499818225487"></a>/drivers/adapter/khdf/linux/hcs/hdf.hcs</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="17.990000000000002%" headers="mcps1.2.4.1.3 "><p id="p3998152254820"><a name="p3998152254820"></a><a name="p3998152254820"></a>Entry to HCS configuration files</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
>The file paths involved in this example are used for demonstration only. Determine the paths for storing the source files as required when developing your driver.

### Instantiating the Driver Entry<a name="section85325864412"></a>

Instantiate an  **HdfDriverEntry**  object as the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(which is defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. When loading the driver, the HDF calls the  **Bind**  function first and then the  **Init**  function. If an error occurred during the calling of the  **Init**  function, the HDF calls  **Release**  to release the driver resource and exit.

The  **Bind**  function is not implemented in the I2C driver because the I2C controller is managed by the I2C manager and the  **Bind**  function has been implemented in the manager. Therefore, services do not need to be bound in the I2C driver.

The sample code for instantiating the driver entry is as follows:

```
/* Define a driver entry object. It must be a global variable of the HdfDriverEntry type (defined in hdf_device_desc.h). */
struct HdfDriverEntry g_sampleI2cDriverEntry = {
    .moduleVersion = 1,
    .Init = SampleI2cInit,
    .Release = SampleI2cRelease,
    .moduleName = "demo_i2c_driver",
};
/* Call HDF_INIT to register the driver entry with the HDF. */
HDF_INIT(g_sampleI2cDriverEntry);
```

### Setting Related Parameters<a name="section8155172019453"></a>

Configure the  **device\_info.hcs**  file and obtain and parse device configuration parameters from the HCS to ensure that the driver can be correctly loaded.

1.  \(Mandatory\) Add a device service node.

    Edit the  **device\_info.hcs**  file and add a driver device service node under  **device\_i2c :: device**. The following is an example:

    ```
     root {
        device_info {
            match_attr = "hdf_manager";
                device_i2c :: device {                        // I2C devices
    		device2 :: deviceNode {                   // Device node of an I2C driver
                        policy = 0;                           // Policy for releasing the driver service
                        priority = 55;                        // Driver startup priority
                        permission = 0644;                    // Permission for the driver to create a device node
                        moduleName = "demo_i2c_driver";       // Driver name. The value of this field must be the same as that of moduleName in the driver entry data structure.
                        serviceName = "DEMO_I2C_DRIVER";      // Name of the service released by the driver. The name must be unique.
                        deviceMatchAttr = "demo_i2c_config";  // Keyword matching the private data of the driver. The value must be the same as that of
                                                              // match_attr in the private configuration data table of the driver.
                    }
                }
        }
    }
    
    ```

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >The  **priority**  attribute \(an integer ranging from 0 to 200\) in the configuration file indicates the priority of a host or drivers. Drivers in a host with a smaller priority value have a higher loading priority than those in other hosts. The driver with a smaller priority value in a host has a higher loading priority than the other drivers in the host. The loading sequence is random for drivers with the same priority.

2.  \(Optional\) Add configuration parameters.

    The driver may require private configuration information to ensure that the register configuration meets the requirements of different products. If private configuration data is required, you can add a driver configuration file to store some default configuration information about the driver. When loading the driver, the HDF obtains the specified configuration information, saves it in the  **property**  attribute of  **HdfDeviceObject**, and passes it to the driver via  **Bind**  and  **Init**. For details about how to use  **Bind**  and  **Init**, see  [Driver Development](../driver/driver-overview-foundation.md). You can create a configuration file and reference it in the  **hdf.hcs**  file of the board-level driver. In this example, configuration parameters are directly added to the existing configuration file  **i2c\_config.hcs**.

    The following configuration parameters are added to the  **i2c\_config.hcs**  file:

    ```
    root {
        platform {
                i2c_config_demo {                
                match_attr = "demo_i2c_config";        // The value of this field must be the same as that of deviceMatchAttr in device_info.hcs.
    
                template i2c_controller {              // Parameter template
                    bus = 0;
                    reg_pbase = 0x120b0000;
                    reg_size = 0xd1;
                }
    
                controller_demo_0 :: i2c_controller {  // Two sample I2C controllers
                    bus = 8;
                }
                controller_demo_1 :: i2c_controller {
                    bus = 9;
                }
            }
        }
    }
    ```

    The value of  **match\_attr**  must be the same as that of  **deviceMatch\_Attr**  in the  **device\_info.hcs**  file. The  **match\_attr**  attribute is used to match the configured parameters in the configuration file \(**i2c\_config.hcs**  in this example\) with the particular driver, so that the driver can call  **DeviceResourceGetIfaceInstance\(\)**  in the  **Bind**  or  **Init**  function to obtain these configuration parameters.

    If you create a new configuration file to set parameters, reference this file in the board-level configuration entry file  **hdf.hcs**. For example:

    ```
    #include "device_info/device_info.hcs"
    #include "i2c/i2c_config.hcs"
    ```

    In this development example, we use an existing configuration file  **i2c\_config.hcs**  to add parameters, and therefore do not need to add it to the board-level configuration entry file.

3.  Enable the driver to obtain configuration parameters from the HCS.

    In this example, the driver needs to obtain configuration parameters, such as the physical base address of the register, register size, and bus number, from the HCS to correctly configure the controller.

    ```
    /* Obtain configuration parameters from the HCS. */
    static int32_t SampleI2cReadDrs(struct SampleI2cCntlr *sampleCntlr, const struct DeviceResourceNode *node)
    {
        int32_t ret;
        struct DeviceResourceIface *drsOps = NULL;
    
        drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        if (drsOps == NULL || drsOps->GetUint32 == NULL) {                         // Ensure that the GetUint32 function is available.
            HDF_LOGE("%s: invalid drs ops fail!", __func__);
            return HDF_FAILURE;
        }
    
        ret = drsOps->GetUint32(node, "reg_pbase", &sampleCntlr->regBasePhy, 0);   // Read the physical base address from the HCS.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read regBase fail!", __func__);
            return ret;
        }
    
        ret = drsOps->GetUint16(node, "reg_size", &sampleCntlr->regSize, 0);       // Read the register size from the HCS.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read regsize fail!", __func__);
            return ret;
        }
    
        ret = drsOps->GetUint16(node, "bus", (uint16_t *)&sampleCntlr->bus, 0);    // Read the bus number from the HCS.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read bus fail!", __func__);
            return ret;
        }
    
        return HDF_SUCCESS;
    }
    ```


### Adding a Controller<a name="section1335374114452"></a>

Initialize the controller hardware, call core-layer APIs to add or delete devices to or from the core layer, and implement a hook.

1.  Define an I2C controller structure, implement a hook, and assign the hook to the function pointer.

    The  **I2cMethod**  structure is defined in the  **i2c\_core.h**  header file. This structure defines the functions to be implemented by the I2C driver by using function pointers. The  **SampleI2cTransfer**  function is a hook used for data transmission, which must be implemented in the driver and must be assigned to a function pointer.

    The sample code is as follows:

    ```
    /* Custom device structure, which is inherited from I2cCntlr */
    struct SampleI2cCntlr {
        struct I2cCntlr cntlr;
        OsalSpinlock spin;
        volatile unsigned char  *regBase;
        uint16_t regSize;
        int16_t bus;
        uint32_t regBasePhy;
    };
    
    /* Message structure, which is inherited from I2cMsg */
    struct SampleTransferData {
        struct I2cMsg *msgs;
        int16_t index;
        int16_t count;
    };
    /* Hook implementation */
    static int32_t SampleI2cTransfer(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count)
    {
        int32_t ret = HDF_SUCCESS;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        struct SampleTransferData td;
    
        if (cntlr == NULL || cntlr->priv == NULL) {
            HDF_LOGE("SampleI2cTransfer: cntlr lor sampleCntlr is null!");
            return HDF_ERR_INVALID_OBJECT;
        }
        sampleCntlr = (struct SampleI2cCntlr *)cntlr;
    
        if (msgs == NULL || count <= 0) {
            HDF_LOGE("SampleI2cTransfer: err parms! count:%d", count);
            return HDF_ERR_INVALID_PARAM;
        }
        td.msgs = msgs;
        td.count = count;
        td.index = 0;
    
        HDF_LOGE("Successfully transmitted!");  // Data transmission is successful.
          
        td.index = count;                       // The total number of sent messages is returned. The message handling process is not provided in this sample code.
        return (td.index > 0) ? td.index : ret;
    }
    /* Assign the hook to a function pointer. */
    static struct I2cMethod g_method = {
        .transfer = SampleI2cTransfer,
    };
    ```

2.  Write a driver initialization function.

    This example uses  **SampleI2cInit**  as the name of the driver initialization function \(this function name is configurable\). This function must be assigned to the  **Init**  function in the driver entry structure so that the HDF can call it to initialize the driver. The driver initialization function needs to parse the configuration parameters obtained from the HCS and create a controller based on these parameters. The sample code is as follows:

    ```
    /* Parse parameters, apply for memory, and create a controller. */
    static int32_t SampleI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
    {
        int32_t ret;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        (void)device;
    
        sampleCntlr = (struct SampleI2cCntlr *)OsalMemCalloc(sizeof(*sampleCntlr));
        if (sampleCntlr == NULL) {
            HDF_LOGE("%s: malloc sampleCntlr fail!", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
    
        ret = SampleI2cReadDrs(sampleCntlr, node);              // Obtain configuration parameters from the HCS.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read drs fail! ret:%d", __func__, ret);
            goto __ERR__;
        }
    
        sampleCntlr->regBase = OsalIoRemap(sampleCntlr->regBasePhy, sampleCntlr->regSize);
        if (sampleCntlr->regBase == NULL) {
            HDF_LOGE("%s: ioremap regBase fail!", __func__);
            ret = HDF_ERR_IO;
            goto __ERR__;
        }
    
        HDF_LOGE("The controller has been initialized!");       // The controller has been initialized successfully. (The initialization process is not provided here.)
    
        sampleCntlr->cntlr.priv = (void *)node;
        sampleCntlr->cntlr.busId = sampleCntlr->bus;
        sampleCntlr->cntlr.ops = &g_method;
        (void)OsalSpinInit(&sampleCntlr->spin);                 // Initialize the spin lock.
        ret = I2cCntlrAdd(&sampleCntlr->cntlr);                 // Add a controller to the core layer.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: add i2c controller fail:%d!", __func__, ret);
            goto __ERR__;
        }
    
        return HDF_SUCCESS;
    __ERR__:                                                    // Handle errors.
        if (sampleCntlr != NULL) {
            if (sampleCntlr->regBase != NULL) {
                OsalIoUnmap((void *)sampleCntlr->regBase);      // Cancel address mapping.
                sampleCntlr->regBase = NULL;
            }
            OsalMemFree(sampleCntlr);                           // Release the memory.
            sampleCntlr = NULL;
        }
        return ret;
    }
    /* Driver initialization function */
    static int32_t SampleI2cInit(struct HdfDeviceObject *device)
    {
        int32_t ret;
        const struct DeviceResourceNode *childNode = NULL;
    
        HDF_LOGE("%s: Enter", __func__);
        if (device == NULL || device->property == NULL) {
            HDF_LOGE("%s: device or property is NULL", __func__);
            return HDF_ERR_INVALID_OBJECT;
        }
    
        ret = HDF_SUCCESS;
        DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            ret = SampleI2cParseAndInit(device, childNode);    // Call the function for parsing parameters and creating a controller.
            if (ret != HDF_SUCCESS) {
                break;
            }
        }
        return ret;
    }
    ```

3.  Write a driver release function.

    This example uses  **SampleI2cRelease**  as the name of the driver release function \(you can name your own function\). This function must be assigned to the  **Release**  function in the driver entry structure so that the HDF can call it to initialize the driver if the driver fails to be initialized via  **Init**. The driver release function must contain operations for releasing the memory and deleting the controller. The sample code is as follows:

    ```
    /* Function for deleting the controller */
    static void SampleI2cRemoveByNode(const struct DeviceResourceNode *node)
    {
        int32_t ret;
        int16_t bus;
        struct I2cCntlr *cntlr = NULL;
        struct SampleI2cCntlr *sampleCntlr = NULL;
        struct DeviceResourceIface *drsOps = NULL;
    
        drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        if (drsOps == NULL || drsOps->GetUint32 == NULL) {
            HDF_LOGE("%s: invalid drs ops fail!", __func__);
            return;
        }
    
        ret = drsOps->GetUint16(node, "bus", (uint16_t *)&bus, 0); // Obtain the I2C bus number from the HCS.
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: read bus fail!", __func__);
            return;
        }
    
        cntlr = I2cCntlrGet(bus);
        if (cntlr != NULL && cntlr->priv == node) {                // Delete the controller based on the I2C bus number.
            I2cCntlrPut(cntlr);
            I2cCntlrRemove(cntlr);
            sampleCntlr = (struct SampleI2cCntlr *)cntlr;
            OsalIoUnmap((void *)sampleCntlr->regBase);
            OsalMemFree(sampleCntlr);
        }
        return;
    }
    /* Release resources. */
    static void SampleI2cRelease(struct HdfDeviceObject *device)
    {
        const struct DeviceResourceNode *childNode = NULL;
    
        HDF_LOGI("%s: enter", __func__);
    
        if (device == NULL || device->property == NULL) {
            HDF_LOGE("%s: device or property is NULL", __func__);
            return;
        }
    
        DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            SampleI2cRemoveByNode(childNode);                       // Delete a controller.
        }
    }
    ```


## Building Source Code and Burning Images<a name="section164824754712"></a>

1.  Edit the Makefile and add a source file to it, as shown in the following example:

    ```
    include drivers/hdf/khdf/platform/platform.mk
    
    obj-y  += $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_core.o \
              $(HDF_PLATFORM_FRAMEWORKS_ROOT)/src/i2c_if.o \
              ./i2c_adapter.o \
              ./i2c_sample.o
    ```

    **./i2c\_sample.o**  is the source file added to the Makefile in this example.

2.  Build source code and burn images to the development board.

    - For details about the operations using the installation package, see [Building Source Code](../quick-start/quickstart-appendix-hi3516-pkg.md#building-source-code) and [Burning an Image](../quick-start/quickstart-appendix-hi3516-pkg.md#burning-an-image).
    
    - For details about the operations in IDE mode, see [Building Source Code](../quick-start/quickstart-appendix-hi3516-ide.md#building-source-code) and [Burning an Image](../quick-start/quickstart-appendix-hi3516-ide.md#burning-an-image).

