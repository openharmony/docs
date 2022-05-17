# ADC<a name="EN-US_TOPIC_0000001153677754"></a>

## Overview<a name="section268031773165048"></a>

The analog-to-digital converter \(ADC\) is a device that converts analog signals into digital signals. In the Hardware Driver Foundation \(HDF\), the ADC module uses the unified service mode for API adaptation. In this mode, a device service is used as the ADC manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the ADC has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services.

**Figure  1** Unified service mode<a name="fig14423182615525"></a>  
![](figures/unified-service-mode.png "ADC-unified-service-mode")

## Available APIs<a name="section752964871810"></a>

### AdcMethod<a name="section1618135285210"></a>

```
struct AdcMethod {
  int32_t (*read)(struct AdcDevice *device, uint32_t channel, uint32_t *val);
  int32_t (*start)(struct AdcDevice *device);
  int32_t (*stop)(struct AdcDevice *device);
};
```

**Table  1** Callbacks for the members in the AdcMethod structure

<a name="table1943202316536"></a>
<table><thead align="left"><tr id="row2451223135315"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p845123185313"><a name="p845123185313"></a><a name="p845123185313"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p345192315311"><a name="p345192315311"></a><a name="p345192315311"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p74512313536"><a name="p74512313536"></a><a name="p74512313536"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p174542313531"><a name="p174542313531"></a><a name="p174542313531"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p445112315535"><a name="p445112315535"></a><a name="p445112315535"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row545102316536"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p14562345312"><a name="p14562345312"></a><a name="p14562345312"></a>read</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p474720389561"><a name="p474720389561"></a><a name="p474720389561"></a><strong id="b167472038115611"><a name="b167472038115611"></a><a name="b167472038115611"></a>device</strong>: structure pointer to the ADC controller at the core layer.</p>
<p id="p14459238536"><a name="p14459238536"></a><a name="p14459238536"></a><strong id="b179891252205514"><a name="b179891252205514"></a><a name="b179891252205514"></a>channel</strong>: channel ID of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p746423195320"><a name="p746423195320"></a><a name="p746423195320"></a><strong id="b626111125816"><a name="b626111125816"></a><a name="b626111125816"></a>val</strong>: pointer to the signal data to be transmitted. It is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1746192315311"><a name="p1746192315311"></a><a name="p1746192315311"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p146152311537"><a name="p146152311537"></a><a name="p146152311537"></a>Reads the signal data sampled by the ADC.</p>
</td>
</tr>
<tr id="row6461236531"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p446182316538"><a name="p446182316538"></a><a name="p446182316538"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1446112318536"><a name="p1446112318536"></a><a name="p1446112318536"></a><strong id="b345886135912"><a name="b345886135912"></a><a name="b345886135912"></a>device</strong>: structure pointer to the ADC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p4461823125317"><a name="p4461823125317"></a><a name="p4461823125317"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1346122314530"><a name="p1346122314530"></a><a name="p1346122314530"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1346223185318"><a name="p1346223185318"></a><a name="p1346223185318"></a>Stops the ADC device.</p>
</td>
</tr>
<tr id="row194622375313"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p144642305313"><a name="p144642305313"></a><a name="p144642305313"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p17461323185314"><a name="p17461323185314"></a><a name="p17461323185314"></a><strong id="b1988212105110"><a name="b1988212105110"></a><a name="b1988212105110"></a>device</strong>: structure pointer to the ADC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1146623105317"><a name="p1146623105317"></a><a name="p1146623105317"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p546132311535"><a name="p546132311535"></a><a name="p546132311535"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1471623195311"><a name="p1471623195311"></a><a name="p1471623195311"></a>Starts the ADC device.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section100579767165048"></a>

The ADC module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **adc\_config.hcs** file.

3.  Instantiate the ADC controller object.
    -   Initialize **AdcDevice**.
    -   Instantiate **AdcMethod** in the **AdcDevice** object.

        For details, see [Available APIs](#available-apis).

4.  \(Optional\) Debug the driver.
    For new drivers, verify basic functions, for example, verify the information returned after the connect operation and whether the signal collection is successful.


## Development Example<a name="section1745221471165048"></a>

The following uses **adc\_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exits.

    -   ADC driver entry reference

        Many devices may connect to the ADC. In the HDF, a manager object needs to be created for the ADC. When a device needs to be started, the manager object locates the device based on the specified parameters.

        The driver of the ADC manager is implemented by the core layer. Vendors do not need to pay attention to the implementation of this part. However, when they implement the **Init** function, the **AdcDeviceAdd** function of the core layer must be called to implement the corresponding features.

        ```
        static struct HdfDriverEntry g_hi35xxAdcDriverEntry = {
         .moduleVersion = 1,
         .Init = Hi35xxAdcInit,
         .Release = Hi35xxAdcRelease,
         .moduleName = "hi35xx_adc_driver",// (Mandatory) This parameter must be the same as that in the .hcs file.
        };
        HDF_INIT(g_hi35xxAdcDriverEntry); // Call HDF_INIT to register the driver entry with the HDF.
        
        // Driver entry of the adc_core.c manager service at the core layer
        struct HdfDriverEntry g_adcManagerEntry = {
         .moduleVersion = 1,
         .Init     = AdcManagerInit,
         .Release  = AdcManagerRelease,
         .moduleName = "HDF_PLATFORM_ADC_MANAGER",// This parameter corresponds to device0 in the device_info file.
        };
        HDF_INIT(g_adcManagerEntry);
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the device attributes in the **adc\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or value ranges of the **AdcDevice** members at the core layer.

    In the unified service mode, the first device node in the **device\_info** file must be the ADC manager, and the parameters must be set as follows:

    <a name="table1344068233165048"></a>
    <table><thead align="left"><tr id="row1551612465165048"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry1856185125165048p0"><a name="entry1856185125165048p0"></a><a name="entry1856185125165048p0"></a>Member</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry720672143165048p0"><a name="entry720672143165048p0"></a><a name="entry720672143165048p0"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row583452627165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry747665129165048p0"><a name="entry747665129165048p0"></a><a name="entry747665129165048p0"></a>moduleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry912596825165048p0"><a name="entry912596825165048p0"></a><a name="entry912596825165048p0"></a>It has a fixed value of <strong id="b581184091716"><a name="b581184091716"></a><a name="b581184091716"></a>HDF_PLATFORM_ADC_MANAGER</strong>.</p>
    </td>
    </tr>
    <tr id="row218211231165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry568759156165048p0"><a name="entry568759156165048p0"></a><a name="entry568759156165048p0"></a>serviceName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1349637957165048p0"><a name="entry1349637957165048p0"></a><a name="entry1349637957165048p0"></a>–</p>
    </td>
    </tr>
    <tr id="row1166331861165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1142726988165048p0"><a name="entry1142726988165048p0"></a><a name="entry1142726988165048p0"></a>policy</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry781016408165048p0"><a name="entry781016408165048p0"></a><a name="entry781016408165048p0"></a>The value is <strong id="b229121291813"><a name="b229121291813"></a><a name="b229121291813"></a>0</strong>, which indicates that no service is published.</p>
    </td>
    </tr>
    <tr id="row1822624516165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry982991296165048p0"><a name="entry982991296165048p0"></a><a name="entry982991296165048p0"></a>deviceMatchAttr</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry367170471165048p0"><a name="entry367170471165048p0"></a><a name="entry367170471165048p0"></a>This parameter is not used.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Configure ADC controller information from the second node. This node specifies a type of ADC controllers rather than an ADC controller. In this example, there is only one ADC device. If there are multiple ADC devices, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **adc\_config** file.

    -  **device\_info.hcs** configuration reference

        ```
        root {
            device_info {
            platform :: host {
            device_adc :: device {
            device0 :: deviceNode {
                policy = 0;
                priority = 50;
                permission = 0644;
                moduleName = "HDF_PLATFORM_ADC_MANAGER";
                serviceName = "HDF_PLATFORM_ADC_MANAGER";
            }
            device1 :: deviceNode {
         policy = 0; // The value 0 indicates that no service needs to be published.
         priority = 55; // Driver startup priority
         permission = 0644; // Permission to create device nodes for the driver
                moduleName = "hi35xx_adc_driver"; // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                serviceName = "HI35XX_ADC_DRIVER"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hisilicon_hi35xx_adc";// (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller in adc_config.hcs.
                } // The specific controller information is in adc_config.hcs.
              }
            }
          }
        }
        ```

    -   adc\_config.hcs configuration reference

        ```
        root {
        platform {
            adc_config_hi35xx {
            match_attr = "hisilicon_hi35xx_adc";
            template adc_device {
                regBasePhy = 0x120e0000;// Physical base address of the register
                regSize = 0x34; // Bit width of the register
                deviceNum = 0; // Device number
                validChannel = 0x1; // Valid channel
                dataWidth = 10; // Data bit width of received signals
                scanMode = 1; // Scan mode
                delta = 0; // Delta parameter
                deglitch = 0;            
                glitchSample = 5000;     
                rate = 20000;            
            }
            device_0 :: adc_device {
                deviceNum = 0;
                validChannel = 0x2;
            }
            }
        }
        }
        ```

3.  Initialize the **AdcDevice** object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating **AdcMethod** \(used to call underlying functions of the driver\) in **AdcDevice**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **adc\_config.hcs** file are read by HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values, such as the device number and bus number, are also passed to the **AdcDevice** object at the core layer.

        ```
        struct Hi35xxAdcDevice {
            struct AdcDevice device;// (Mandatory) Control object of the core layer. For details, see the description of AdcDevice.
            volatile unsigned char *regBase;// (Mandatory) Base address of the register
            volatile unsigned char *pinCtrlBase;
            uint32_t regBasePhy; // (Mandatory) Physical base address of the register
            uint32_t regSize; // (mandatory) Bit width of the register 
            uint32_t deviceNum; // (Mandatory) Device number
            uint32_t dataWidth; // (Mandatory) Data bit width of received signals
            uint32_t validChannel; // (Mandatory) Valid channel
            uint32_t scanMode; // (Mandatory) Scan mode
            uint32_t delta;
            uint32_t deglitch;
            uint32_t glitchSample;
            uint32_t rate; // (Mandatory) Sampling rate
        };
        
        // AdcDevice is the core layer controller structure. Its members are assigned with values by using the Init function.
        struct AdcDevice {
            const struct AdcMethod *ops;
            OsalSpinlock spin;
            uint32_t devNum;
            uint32_t chanNum;
            const struct AdcLockMethod *lockOps;
            void *priv;
        };
        ```

    -   Instantiate the callback function structure **AdcMethod** in **AdcDevice**. The **AdcLockMethod** callback function structure is not implemented in this example. To instantiate the structure, refer to the I2C driver development. Other members are initialized in the **Init** function.

        ```
        static const struct AdcMethod g_method = {
            .read = Hi35xxAdcRead,
            .stop = Hi35xxAdcStop,
            .start = Hi35xxAdcStart,
        };
        ```

    -   Init function

        Input parameters:

       **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **//drivers/framework/include/utils/hdf\_base.h** file.\)

        <a name="table127573104165048"></a>
        <table><thead align="left"><tr id="row1932243367165048"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry405408385165048p0"><a name="entry405408385165048p0"></a><a name="entry405408385165048p0"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry407875094165048p0"><a name="entry407875094165048p0"></a><a name="entry407875094165048p0"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row1845195554165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry144793493165048p0"><a name="entry144793493165048p0"></a><a name="entry144793493165048p0"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1933449399165048p0"><a name="entry1933449399165048p0"></a><a name="entry1933449399165048p0"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row1203086670165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry766973904165048p0"><a name="entry766973904165048p0"></a><a name="entry766973904165048p0"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry999036326165048p0"><a name="entry999036326165048p0"></a><a name="entry999036326165048p0"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row1147526196165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry271913224165048p0"><a name="entry271913224165048p0"></a><a name="entry271913224165048p0"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1349459344165048p0"><a name="entry1349459344165048p0"></a><a name="entry1349459344165048p0"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row42206428165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry826579070165048p0"><a name="entry826579070165048p0"></a><a name="entry826579070165048p0"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry740637684165048p0"><a name="entry740637684165048p0"></a><a name="entry740637684165048p0"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row456623770165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2126491887165048p0"><a name="entry2126491887165048p0"></a><a name="entry2126491887165048p0"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1585614415165048p0"><a name="entry1585614415165048p0"></a><a name="entry1585614415165048p0"></a>Transmission successful</p>
        </td>
        </tr>
        <tr id="row2048732992165048"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry131232818165048p0"><a name="entry131232818165048p0"></a><a name="entry131232818165048p0"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry42178503165048p0"><a name="entry42178503165048p0"></a><a name="entry42178503165048p0"></a>Transmission failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and **AdcDevice**, and calls the **AdcDeviceAdd** function at the core layer.

        ```
        static int32_t Hi35xxAdcInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct DeviceResourceNode *childNode = NULL;
            ...
        // Traverse and parse all nodes in adc_config.hcs and call the Hi35xxAdcParseInit function to initialize the devices separately.
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxAdcParseInit(device, childNode);// For details about the function definition, see the following description.
                ...
            }
            return ret;
        }
        
        static int32_t Hi35xxAdcParseInit(struct HdfDeviceObject *device, struct DeviceResourceNode *node)
        {
        int32_t ret;
        struct Hi35xxAdcDevice *hi35xx = NULL; // (Mandatory) Custom structure object
        (void)device;
        
        hi35xx = (struct Hi35xxAdcDevice *)OsalMemCalloc(sizeof(*hi35xx)); // (Mandatory) Memory allocation
        ...
        ret = Hi35xxAdcReadDrs(hi35xx, node); // (Mandatory) Fill the default values in the adc_config file to the structure.
        ...
        hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize);// (Mandatory) Address mapping
        ...
        hi35xx->pinCtrlBase = OsalIoRemap(HI35XX_ADC_IO_CONFIG_BASE, HI35XX_ADC_IO_CONFIG_SIZE);
        ...
        Hi35xxAdcDeviceInit(hi35xx); // (Mandatory) Initialize the ADC.
        hi35xx->device.priv = (void *)node; // (Mandatory) Store device attributes.
        hi35xx->device.devNum = hi35xx->deviceNum;// (Mandatory) Initialize the AdcDevice members.
        hi35xx->device.ops = &g_method; // (Mandatory) Mount the AdcMethod instance object.
        ret = AdcDeviceAdd(&hi35xx->device); // (Mandatory and important) Call this function to set the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
        ...
        return HDF_SUCCESS;
        
        __ERR__:
        if (hi35xx != NULL) {                     // If the operation fails, you need to execute the initialization function reversely.
            if (hi35xx->regBase != NULL) {
            OsalIoUnmap((void *)hi35xx->regBase);
            hi35xx->regBase = NULL;
            }
            AdcDeviceRemove(&hi35xx->device);
            OsalMemFree(hi35xx);
        }
        return ret;
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
        static void Hi35xxAdcRelease(struct HdfDeviceObject *device)
        {
        const struct DeviceResourceNode *childNode = NULL;
        ...
        // Traverse and parse all nodes in adc_config.hcs and perform the release operation on each node.
        DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            Hi35xxAdcRemoveByNode(childNode);// The function definition is as follows:
        }
        }
        
        static void Hi35xxAdcRemoveByNode(const struct DeviceResourceNode *node)
        {
        int32_t ret;
        int32_t deviceNum;
        struct AdcDevice *device = NULL;
        struct Hi35xxAdcDevice *hi35xx = NULL;
        struct DeviceResourceIface *drsOps = NULL;
        
        drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
        ...
        ret = drsOps->GetUint32(node, "deviceNum", (uint32_t *)&deviceNum, 0);
        ...
        // You can call the AdcDeviceGet function to obtain the AdcDevice object based on deviceNum and call the AdcDeviceRemove function to release the AdcDevice object.
        device = AdcDeviceGet(deviceNum);
        if (device != NULL && device->priv == node) {
            AdcDevicePut(device);   
            AdcDeviceRemove(device); // (Mandatory) Remove the AdcDevice object from the driver manager.
            hi35xx = (struct Hi35xxAdcDevice *)device;// (Mandatory) Obtain the custom object through forced conversion and release the object.
            OsalIoUnmap((void *)hi35xx->regBase);
            OsalMemFree(hi35xx);
        }
        return
        ```