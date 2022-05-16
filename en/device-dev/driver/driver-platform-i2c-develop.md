# I2C<a name="EN-US_TOPIC_0000001153579420"></a>



## Overview<a name="section2040078630114257"></a>

The Inter-Integrated Circuit \(I2C\) bus is a simple and bidirectional two-wire synchronous serial bus developed by Philips. In the Hardware Driver Foundation (HDF) framework, the I2C module uses the unified service mode for API adaptation. In this mode, a device service is used as the I2C manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the I2C module has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services.

**Figure  1** Unified service mode<a name="fig17640124912440"></a>  
![](figures/unified-service-mode.png "unified-service-mode-8")

## Available APIs<a name="section752964871810"></a>

I2cMethod and I2cLockMethod

```
struct I2cMethod {
int32_t (*transfer)(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count);
};
struct I2cLockMethod {// Lock mechanism operation structure
     int32_t (*lock)(struct I2cCntlr *cntlr); // Add a lock.
     void (*unlock)(struct I2cCntlr *cntlr);  // Release the lock.
};
```

**Table  1** Callbacks for the members in the I2cMethod structure

<a name="table10549174014611"></a>
<table><thead align="left"><tr id="row17550114013460"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p155014403467"><a name="p155014403467"></a><a name="p155014403467"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p165507404466"><a name="p165507404466"></a><a name="p165507404466"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p8550194015467"><a name="p8550194015467"></a><a name="p8550194015467"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p65501540184618"><a name="p65501540184618"></a><a name="p65501540184618"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p185501740194610"><a name="p185501740194610"></a><a name="p185501740194610"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row75509402460"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p0550104084617"><a name="p0550104084617"></a><a name="p0550104084617"></a>transfer</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p9551164011468"><a name="p9551164011468"></a><a name="p9551164011468"></a><strong id="b1413775771219"><a name="b1413775771219"></a><a name="b1413775771219"></a>cntlr</strong>: structure pointer to the I2C controller at the core layer. <strong id="b13955019171313"><a name="b13955019171313"></a><a name="b13955019171313"></a>msgs</strong>: structure pointer to the user message. <strong id="b4678857181319"><a name="b4678857181319"></a><a name="b4678857181319"></a>count</strong>: number of messages, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p6551140124620"><a name="p6551140124620"></a><a name="p6551140124620"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p555144084619"><a name="p555144084619"></a><a name="p555144084619"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p8551174044612"><a name="p8551174044612"></a><a name="p8551174044612"></a>Transfers user messages.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1085786591114257"></a>

The I2C module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF framework.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **i2c\_config.hcs** file.

3.  Instantiate the I2C controller object.
    -   Initialize **I2cCntlr**.
    -   Instantiate **I2cMethod** and **I2cLockMethod** in **I2cCntlr**.

        For details, see [Available APIs](#available-apis). 
       
4.  \(Optional\) Debug the driver.

    For new drivers, verify basic functions, for example, verify the information returned after the connect operation and whether data is successfully transmitted.




## Development Example<a name="section1773332551114257"></a>

The following uses **i2c\_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF framework, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exit.

    -   I2C driver entry reference

        Many devices may be connected to the I2C module. Therefore, in the HDF framework, a manager object is created for the I2C, and a manager service is launched to handle external access requests in a unified manner. When a user wants to open a device, the user obtains the manager service first. Then, the manager service locates the target device based on the parameters specified by the user.

        The driver of the I2C manager is implemented by the core layer. Vendors do not need to pay attention to the implementation of this part. However, when they implement the **Init** function, the **I2cCntlrAdd** function of the core layer must be called to implement the corresponding features.

        ```
        struct HdfDriverEntry g_i2cDriverEntry = {
            .moduleVersion = 1,
            .Init = Hi35xxI2cInit,
            .Release = Hi35xxI2cRelease,
            .moduleName = "hi35xx_i2c_driver",// (Mandatory) The value must be the same as that in the config.hcs file.
        };
        HDF_INIT(g_i2cDriverEntry);   // Call HDF_INIT to register the driver entry with the HDF framework.
        
        // Driver entry of the i2c_core.c manager service at the core layer
        struct HdfDriverEntry g_i2cManagerEntry = {
            .moduleVersion = 1,
            .Bind = I2cManagerBind,
            .Init = I2cManagerInit,
            .Release = I2cManagerRelease,
         .moduleName = "HDF_PLATFORM_I2C_MANAGER",// This parameter corresponds to device0 in the device_info file.
        };
        HDF_INIT(g_i2cManagerEntry);
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the device attributes in the **i2c\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or value ranges of the **I2cCntlr** members at the core layer.

    In the unified service mode, the first device node in the **device\_info** file must be the I2C manager.  [Table 2](#table96651915911)  lists settings of its parameters.

   **Table  2** Settings of the I2C manager

    <a name="table96651915911"></a>
    <table><thead align="left"><tr id="row96618194915"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1066119790"><a name="p1066119790"></a><a name="p1066119790"></a>Member</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p8674191494"><a name="p8674191494"></a><a name="p8674191494"></a>Value</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row767111916914"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p46714196920"><a name="p46714196920"></a><a name="p46714196920"></a>moduleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p36717191292"><a name="p36717191292"></a><a name="p36717191292"></a>It has a fixed value of <strong id="b1343012314357"><a name="b1343012314357"></a><a name="b1343012314357"></a>HDF_PLATFORM_I2C_MANAGER</strong>.</p>
    </td>
    </tr>
    <tr id="row16671119392"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11671019699"><a name="p11671019699"></a><a name="p11671019699"></a>serviceName</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p86716195912"><a name="p86716195912"></a><a name="p86716195912"></a>It has a fixed value of <strong id="b107651238143515"><a name="b107651238143515"></a><a name="b107651238143515"></a>HDF_PLATFORM_I2C_MANAGER</strong>.</p>
    </td>
    </tr>
    <tr id="row17673191911"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p5673191898"><a name="p5673191898"></a><a name="p5673191898"></a>policy</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18677191699"><a name="p18677191699"></a><a name="p18677191699"></a>The value can be <strong id="b13997735183718"><a name="b13997735183718"></a><a name="b13997735183718"></a>1</strong> or <strong id="b165591038103717"><a name="b165591038103717"></a><a name="b165591038103717"></a>2</strong>, depending on whether it is visible to the user mode.</p>
    </td>
    </tr>
    <tr id="row8675191894"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12677191913"><a name="p12677191913"></a><a name="p12677191913"></a>deviceMatchAttr</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1567171918915"><a name="p1567171918915"></a><a name="p1567171918915"></a>This parameter is not used.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Configure I2C controller information from the second node. This node specifies a type of I2C controllers rather than an I2C controller. The **busID** and **reg\_pbase** parameters distinguish controllers, which can be seen in the **i2c\_config** file.

    -  **device\_info.hcs** configuration reference

        ```
        root {
        device_info {
        match_attr = "hdf_manager";
            device_i2c :: device {
            device0 :: deviceNode {
                policy = 2;
                priority = 50;
                permission = 0644;
                moduleName = "HDF_PLATFORM_I2C_MANAGER";
                serviceName = "HDF_PLATFORM_I2C_MANAGER";
                deviceMatchAttr = "hdf_platform_i2c_manager";
            }
            device1 :: deviceNode {
         policy = 0; // The value 0 indicates that no service needs to be published.
                 priority = 55;                           // Driver startup priority
                permission = 0644;                  // Permission for the driver to create a device node
                moduleName = "hi35xx_i2c_driver";        // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                serviceName = "HI35XX_I2C_DRIVER"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hisilicon_hi35xx_i2c";// (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller in i2c_config.hcs.
                } // The specific controller information is in i2c_config.hcs.
            }
            }
        }
        }
        ```

    -  **i2c\_config.hcs** configuration reference

        ```
        root {
        platform {
            i2c_config {
            match_attr = "hisilicon_hi35xx_i2c";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
            template i2c_controller {           // Template configuration. In the template, you can configure the common parameters shared by service nodes.
                  bus = 0;                          // (Mandatory) I2C ID
                 reg_pbase = 0x120b0000;           // (Mandatory) Physical base address
               reg_size = 0xd1;                  // (Mandatory) Register bit width
                 irq = 0;                          // (Optional) Configured based on the vendor's requirements.
                freq = 400000;                    // (Optional) Configured based on the vendor's requirements.
                 clk = 50000000;                   // (Optional) Configured based on the vendor's requirements.
            }
            controller_0x120b0000 :: i2c_controller {
                bus = 0;
            }
            controller_0x120b1000 :: i2c_controller {
                bus = 1;
                reg_pbase = 0x120b1000;
            }
            ...
            }
        }
        }
        ```

3.  Initialize the **I2cCntlr** object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating **I2cMethod** \(used to call underlying functions of the driver\) in **I2cCntlr**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **i2c\_config.hcs** file are read by HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values, such as the device number and bus number, are also passed to the **I2cCntlr** object at the core layer.

        ```
        // Vendor custom function structure
        struct Hi35xxI2cCntlr {
            struct I2cCntlr cntlr;            // (Mandatory) Control object of the core layer. For details, see the following description.
            OsalSpinlock spin;                // (Mandatory) The vendor needs to implement lock and unlock for I2C operation functions based on this variable.
            volatile unsigned char  *regBase; // (Mandatory) Base address of the register
             uint16_t regSize; // (mandatory) Bit width of the register
            int16_t bus;                      // (Mandatory) The value can be read from the i2c_config.hcs file.
            uint32_t clk;                     // (Optional) Customized by the vendor.
            uint32_t freq;                    // (Optional) Customized by the vendor.
            uint32_t irq;                     // (Optional) Customized by the vendor.
            uint32_t regBasePhy;              // (Mandatory) Physical base address of the register
        };
        
        // I2cCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct I2cCntlr {
            struct OsalMutex lock;
            void *owner;
            int16_t busId;
            void *priv;
            const struct I2cMethod *ops;
            const struct I2cLockMethod *lockOps;
        };
        ```

    -   Instantiate the member callback function structure **I2cMethod** in **I2cCntlr** and the lock callback function structure **I2cLockMethod**. Other members are initialized by using the **Init** function.

        ```
        // Example in i2c_hi35xx.c
        static const struct I2cMethod g_method = {
            .transfer = Hi35xxI2cTransfer,
        };
        
        static const struct I2cLockMethod g_lockOps = {
            .lock = Hi35xxI2cLock, // Lock function
            .unlock = Hi35xxI2cUnlock,// Unlock function
        };
        ```

    -   Init function

        Input parameters:

       **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **//drivers/framework/include/utils/hdf\_base.h** file.\)

       **Table  3** Input parameters and return values of the Init function

        <a name="table1743073181511"></a>
        <table><thead align="left"><tr id="row443033171513"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p34306341517"><a name="p34306341517"></a><a name="p34306341517"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1243123101510"><a name="p1243123101510"></a><a name="p1243123101510"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row5431638151"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1043114319156"><a name="p1043114319156"></a><a name="p1043114319156"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p343173101513"><a name="p343173101513"></a><a name="p343173101513"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row1243143181516"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1443118317154"><a name="p1443118317154"></a><a name="p1443118317154"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p343113341515"><a name="p343113341515"></a><a name="p343113341515"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row1943115391516"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1843143171511"><a name="p1843143171511"></a><a name="p1843143171511"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p943114391515"><a name="p943114391515"></a><a name="p943114391515"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row1443183101514"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p54311031157"><a name="p54311031157"></a><a name="p54311031157"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p74315311158"><a name="p74315311158"></a><a name="p74315311158"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row3431437158"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8432332158"><a name="p8432332158"></a><a name="p8432332158"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p104329391519"><a name="p104329391519"></a><a name="p104329391519"></a>Transmission successful</p>
        </td>
        </tr>
        <tr id="row34321136152"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p184325391517"><a name="p184325391517"></a><a name="p184325391517"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1343220319154"><a name="p1343220319154"></a><a name="p1343220319154"></a>Transmission failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and **I2cCntlr**, calls the **I2cCntlrAdd** function at the core layer, and connects to the VFS \(optional\).

        ```
        static int32_t Hi35xxI2cInit(struct HdfDeviceObject *device)
        {
            ...
        // Traverse and parse all nodes in i2c_config.hcs and call Hi35xxI2cParseAndInit to initialize the devices separately.
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = Hi35xxI2cParseAndInit(device, childNode);// For details about the function definition, see the following description.
            ...
            }
            ...
        }
        
        static int32_t Hi35xxI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            struct Hi35xxI2cCntlr *hi35xx = NULL;
            ... 
            hi35xx = (struct Hi35xxI2cCntlr *)OsalMemCalloc(sizeof(*hi35xx));   // Apply for memory.
            ... 
        hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); // Address mapping
            ... 
            Hi35xxI2cCntlrInit(hi35xx);         // (Mandatory) Initialize the I2C device.
            
           hi35xx->cntlr.priv = (void *)node;  // (Mandatory) Store device attributes.
            hi35xx->cntlr.busId = hi35xx->bus; // (Mandatory) Initialize busId in I2cCntlr.
         hi35xx->cntlr.ops = &g_method;      // (Mandatory) Connect to the I2cMethod instance.
         hi35xx->cntlr.lockOps = &g_lockOps; // (Mandatory) Connect to the I2cLockMethod instance.
            (void)OsalSpinInit(&hi35xx->spin); // (Mandatory) Initialize the lock.
          ret = I2cCntlrAdd(&hi35xx->cntlr);  // (Mandatory) Call this function to set the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
            ...
        #ifdef USER_VFS_SUPPORT
            (void)I2cAddVfsById(hi35xx->cntlr.busId);// (Optional) Connect the driver to the user-level virtual file system supported.
        #endif
            return HDF_SUCCESS;
         __ERR__:                       // If the operation fails, execute the initialization function reversely.
            if (hi35xx != NULL) {
                if (hi35xx->regBase != NULL) {
                    OsalIoUnmap((void *)hi35xx->regBase);
                    hi35xx->regBase = NULL;
                }
                OsalMemFree(hi35xx);
                hi35xx = NULL;
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

        Releases the memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. When the HDF framework fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

        ```
        static void Hi35xxI2cRelease(struct HdfDeviceObject *device)
        {
            ...
            // Release each node separately, like Hi35xxI2cInit.
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
            Hi35xxI2cRemoveByNode(childNode);// The function definition is as follows:
            }
        }
        
        static void Hi35xxI2cRemoveByNode(const struct DeviceResourceNode *node)
        {
            ... 
            // (Mandatory) Call the I2cCntlrGet function to obtain the I2cCntlr object based on busid of the device, and call the I2cCntlrRemove function to release the I2cCntlr object.
            cntlr = I2cCntlrGet(bus);
            if (cntlr != NULL && cntlr->priv == node) {
                ...
                I2cCntlrRemove(cntlr); 
                // (Mandatory) Remove the address mapping and release the lock and memory.
                hi35xx = (struct Hi35xxI2cCntlr *)cntlr; 
                OsalIoUnmap((void *)hi35xx->regBase);
                (void)OsalSpinDestroy(&hi35xx->spin);
                OsalMemFree(hi35xx);
            }
            return;
        }
        ```