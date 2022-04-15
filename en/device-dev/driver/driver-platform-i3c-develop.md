# I3C 

## Overview<a name="1"></a>

The Improved Inter-Integrated Circuit (I3C) is a simple and cost-efficient bidirectional 2-wire synchronous serial bus protocol developed by the Mobile Industry Processor Interface (MIPI) Alliance. In the Hardware Driver Foundation (HDF), the I3C module uses the unified service mode for API adaptation. In this mode, a device service is used as the I3C manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the I3C has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services.

**Figure 1** Unified service mode<a name="fig1"></a>

![image1](figures/unified-service-mode.png)


## Available APIs<a name="2"></a>

**I3cMethod**:
    ```c
    struct I3cMethod {
        int32_t (*sendCccCmd)(struct I3cCntlr *cntlr, struct I3cCccCmd *ccc);
        int32_t (*transfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
        int32_t (*i2cTransfer)(struct I3cCntlr *cntlr, struct I3cMsg *msgs, int16_t count);
        int32_t (*setConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
        int32_t (*getConfig)(struct I3cCntlr *cntlr, struct I3cConfig *config);
        int32_t (*requestIbi)(struct I3cDevice *dev);
        void (*freeIbi)(struct I3cDevice *dev);
    };
    ```

    **Table 1** APIs for the members in the I3cMethod structure
    
    |Method|Input Parameter|Output Parameter|Return Value|Description|
    |-|-|-|-|-|
    |sendCccCmd|**cntlr**: structure pointer to an I3C controller at the core layer. <br/>**ccc**: pointer to the input common command code (CCC) structure.|**ccc**: pointer to the output CCC structure.|HDF_STATUS|Sends a CCC.|
    |Transfer  |**cntlr**: structure pointer to an I3C controller at the core layer. <br/>**msgs**: structure pointer to user messages. <br/>**count**: number of messages, which is of the int16_t type.|**msgs**: structure pointer to user messages.|HDF_STATUS|Transfers user messages in I3C mode.|
    |i2cTransfer |**cntlr**: structure pointer to an I3C controller at the core layer. <br/>**msgs**: structure pointer to user messages. <br>**count**: number of messages, which is of the int16_t type.|**msgs**: structure pointer to user messages.|HDF_STATUS|Transfers user messages in I2C mode.|
    |setConfig|**cntlr**: structure pointer to an I3C controller at the core layer. <br/>**config**: pointer to controller configuration parameters.|–|HDF_STATUS|Sets an I3C controller.|
    |getConfig|**cntlr**: structure pointer to an I3C controller at the core layer.|**config**: pointer to controller configuration parameters.|HDF_STATUS|Obtains the configuration of an I3C controller.|
    |requestIbi|**device**: structure pointer to an I3C device at the core layer.|–|HDF_STATUS|Requests an IBI for an I3C device.|
    |freeIbi|**device**: structure pointer to an I3C device at the core layer.|–|HDF_STATUS|Releases the IBI for an I3C device.|

## How to Develop<a name="3"></a>

The I3C module adaptation involves the following steps:

1. Instantiate the driver entry.
    - Instantiate the **HdfDriverEntry** structure.
    - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   
    - Add the **deviceNode** information to the **device_info.hcs** file.
    - (Optional) Add the **i3c_config.hcs** file.
  
3. Instantiate the I3C controller object.
   
    - Initialize **I3cCntlr**.
    - Instantiate **I3cMethod** in **I3cCntlr**. For details, see [Available APIs](#Available_apis).
  
4. Register an interrupt handler.
    Register an interrupt handler for the controller to implement the device hot-join and in-band interrupt (IBI) features.

  

## Development Example<a name="4"></a>

1. Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf\_device\_desc.h**), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers are collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

    I3C driver entry reference:

    > The I3C module may be connected with multiple controllers. Therefore, in the HDF, a manager object is created for the I3C, and a manager service is published to handle external access requests in a unified manner. Before a controller is opened, the manager service needs to be obtained first. Then, the manager service locates the target controller based on the specified parameters.
    >
    > The core layer implements the driver of the I3C manager service. Vendors do not need to care about the implementation. However, during the implementation of **Init()**, the **I3cCntlrAdd()** function at the core layer needs to be called to implement related features.

    ```c
    static struct HdfDriverEntry g_virtualI3cDriverEntry = {
        .moduleVersion = 1,
        .Init = VirtualI3cInit,
        .Release = VirtualI3cRelease,
        .moduleName = "virtual_i3c_driver",// (Mandatory) The value must be the same as that in the .hcs file.
    };
    HDF_INIT(g_virtualI3cDriverEntry);  // Call HDF_INIT to register the driver entry with the HDF.
    
    /* Driver entry of the i3c_core.c manager service at the core layer */
    struct HdfDriverEntry g_i3cManagerEntry = {
        .moduleVersion = 1,
        .Init     = I3cManagerInit,
        .Release  = I3cManagerRelease,
        .moduleName = "HDF_PLATFORM_I3C_MANAGER",// Correspond to device0 in the device_info file.
    };
    HDF_INIT(g_i3cManagerEntry);
    ```

2. Add **deviceNode** to the **device\_info.hcs** file, and configure the device attributes in the **i3c\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or restriction ranges of the **I3cCntlr** members at the core layer.

    In the unified service mode, the first device node in the **device\_info** file must be the I3C manager. The I3C manager parameters must be set as follows:
    
    |Member|Value|
    |-|-|
    |moduleName |HDF_PLATFORM_I3C_MANAGER|
    |serviceName|Reserved|
    |policy|0|
    |cntlrMatchAttr| Reserved |
    
    Configure I3C controller information from the second node. This node specifies a type of I3C controllers rather than a specific I3C controller. In this example, there is only one I3C controller. If there are multiple I3C controllers, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **i3c\_config** file.

    - **device_info.hcs** configuration reference

        ```c
        root {
            device_i3c :: device {
                device0 :: deviceNode {
                    policy = 0;
                    priority = 52;
                    permission = 0644;
                    serviceName = "HDF_PLATFORM_I3C_MANAGER";
                    moduleName = "HDF_PLATFORM_I3C_MANAGER";
                }
            }
            i3c_virtual :: deviceNode {
                policy = 0;        // The value 0 indicates that no service is published.
                priority = 56;     // Driver startup priority.
                permission = 0644; // Permission to create device nodes for the driver.
                moduleName = "virtual_i3c_driver"; // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                serviceName = "VIRTUAL_I3C_DRIVER"; // (Mandatory) Unique name of the service published by the driver.
                deviceMatchAttr = "virtual_i3c"; // (Mandatory) Controller private data, which must be same as that of the corresponding controller in i3c_config.hcs.
            }                                             // The specific controller information is in i3c_config.hcs.
        }
        ```

    - **i3c_config.hcs** configuration reference

        ```c
        root {
            platform {
                i3c_config {
                    match_attr = "virtual_i3c"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                    template i3c_controller {    // Template configuration. In the template, you can configure the common parameters shared by device nodes.
                        busId = 0;               // (Mandatory) I3C bus number.
                        busMode = 0x0;          // Bus mode. Which can be 0x0 (pure), 0x1 (mixed-fast), 0x2 (mixed-limited), or 0x3 (mixed-slow).
                        regBasePhy = 0x120b0000; // (Mandatory) Physical base address.
                        regSize = 0xd1;        // (Mandatory) Register bit width.
                        IrqNum = 20;           // (Mandatory) Interrupt request (IRQ) number.
                        i3cMaxRate = 12900000;  // (Optional) Maximum clock rate in I3C mode.
                        i3cRate = 12500000;      // (Optional) Clock rate in I3C mode.
                        i2cFmRate = 1000000;    // (Optional) Clock rate in I2C FM mode.
                        i2cFmPlusRate = 400000; // (Optional) Clock rate in I2C FM+ mode.
                    }
                    controller_0 :: i3c_controller {
                        busId = 18;
                        IrqNum = 20;
                    }
                }
            }
        }
        ```

3. Initialize the **I3cCntlr** object at the core layer, including initializing the custom structure (passing parameters and data) and instantiating **I3cMethod** (used to call the underlying functions of the driver) in **I3cCntlr**.

    The **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) must be implemented in this step.

    - Custom structure reference
      
        > The custom structure holds parameters and data for the driver. The HDF reads the values in the **i3c_config.hcs** file and initializes the structure members through **DeviceResourceIface**. Some important values, such as the device number and bus number, are also passed to the **I3cCntlr** object at the core layer.
    
        ```c
        struct VirtualI3cCntlr {
            struct I3cCntlr cntlr;   // (Mandatory) Control object at the core layer. For details, see the following description of I3cCntlr.
            volatile unsigned char *regBase;// (Mandatory) Register base address.
            uint32_t regBasePhy;     // (Mandatory) Physical base address of the register.
            uint32_t regSize;        // (Mandatory) Bit width of the register.
            uint16_t busId;          // (Mandatory) Device number.
            uint16_t busMode;
            uint16_t IrqNum;
            uint32_t i3cMaxRate;
            uint32_t i3cRate;
            uint32_t i2cFmRate;
            uint32_t i2cFmPlusRate;
        };
        
        /* I3cCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct I3cCntlr {
            OsalSpinlock lock;
            void *owner;
            int16_t busId;
            struct I3cConfig config;
            uint16_t addrSlot[(I3C_ADDR_MAX + 1) / ADDRS_PER_UINT16];
            struct I3cIbiInfo *ibiSlot[I3C_IBI_MAX];
            const struct I3cMethod *ops;
            const struct I3cLockMethod *lockOps;
            void *priv;
        };
        ```

        > **(Important)** This example does not provide the instantiation of the **I3cLockMethod** callback structure in **I3cCntlr**. For details, see the I2C driver development. Other members are initialized in the **Init** function.

    
    - **Init** function
    
        > Input parameter:
        >  **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration.
        > 
        > Return value:
        > **HDF_STATUS** (The following table lists some states. For more details, see **HDF\_STATUS** definition in the **/drivers/framework/include/utils/hdf\_base.h file**.)
        
        |State|Description|
        |:-|:--|
        |HDF_ERR_INVALID_OBJECT|Invalid controller object.|
        |HDF_ERR_INVALID_PARAM |Invalid parameter.|
        |HDF_ERR_MALLOC_FAIL   |Failed to allocate memory.|
        |HDF_ERR_IO            |I/O error.|
        |HDF_SUCCESS           |Transmission successful.|
        |HDF_FAILURE           |Transmission failed.|
    
        > Function description:
        > Initializes the custom structure object and **I3cCntlr**, and calls the **I3cCntlrAdd** function to add the I3C controller to the core layer.

        ```c
        static int32_t VirtualI3cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            int32_t ret;
            struct VirtualI3cCntlr *virtual = NULL;    // (Mandatory) Custom structure object.
            (void)device;
    
            virtual = (struct VirtualI3cCntlr *)OsalMemCalloc(sizeof(*virtual)); // (Mandatory) Allocate memory.
            if (virtual == NULL) {
                HDF_LOGE("%s: Malloc virtual fail!", __func__);
                return HDF_ERR_MALLOC_FAIL;
            }
    
            ret = VirtualI3cReadDrs(virtual, node);     // (Mandatory) Fill the default values defined in the i3c_config file to the structure.
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
                goto __ERR__;
            }
            ...
            virtual->regBase = OsalIoRemap(virtual->regBasePhy, virtual->regSize);// (Mandatory) Address mapping.
            ret = OsalRegisterIrq(hi35xx->softIrqNum, OSAL_IRQF_TRIGGER_NONE, I3cIbiHandle, "I3C", virtual); // (Mandatory) Register the interrupt handler.
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: register irq failed!", __func__);
                return ret;
            }
            ...
            VirtualI3cCntlrInit(virtual);              // (Mandatory) Initialize the I3C device.
            virtual->cntlr.priv = (void *)node;        // (Mandatory) Set the storage device attributes.
            virtual->cntlr.busId = virtual->busId;     // (Mandatory) Initialize I3cCntlr.
            virtual->cntlr.ops = &g_method;           // (Mandatory) Connect to the I3cMethod instance. 
            (void)OsalSpinInit(&virtual->spin);
            ret = I3cCntlrAdd(&virtual->cntlr);        // (Mandatory) Call this function to add the controller to the core layer. If a success signal is returned, the driver is completely connected to the core layer.
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: add i3c controller failed! ret = %d", __func__, ret);
                (void)OsalSpinDestroy(&virtual->spin);
                goto __ERR__;
            }

            return HDF_SUCCESS;
        __ERR__:                                       // If the controller fails to be added, deinitialize related functions.
            if (virtual != NULL) {
                OsalMemFree(virtual);
                virtual = NULL;
            }

            return ret;
        }
    
        static int32_t VirtualI3cInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            const struct DeviceResourceNode *childNode = NULL;

            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return HDF_ERR_INVALID_OBJECT;
            }

            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ret = VirtualI3cParseAndInit(device, childNode);
                if (ret != HDF_SUCCESS) {
                    break;
                }
            }

            return ret;
        }
        ```

    - **Release** function

        > Input parameter:
        > **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration.
        > 
        > Return value:
        > None.
        > 
        > Function description:
        > Releases the memory and deletes the controller. This function assigns a value to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.
    
        ```c
        static void VirtualI3cRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int16_t busId;
            struct I3cCntlr *cntlr = NULL;
            struct VirtualI3cCntlr *virtual = NULL;
            struct DeviceResourceIface *drsOps = NULL;
        
            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("%s: invalid drs ops fail!", __func__);
                return;
            }
        
            ret = drsOps->GetUint16(node, "busId", (uint16_t *)&busId, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("%s: read busId fail!", __func__);
                return;
            }
        ...
        /* Call the I3cCntlrGet function to obtain the I3cCntlr object through the cntlrNum of the device, and call the I3cCntlrRemove function to release the I3cCntlr object. */
            cntlr = I3cCntlrGet(busId);
            if (cntlr != NULL && cntlr->priv == node) {
                I3cCntlrPut(cntlr);
                I3cCntlrRemove(cntlr);                    // (Mandatory) Remove the I3cCntlr object from the manager driver.
                virtual = (struct VirtualI3cCntlr *)cntlr; // (Mandatory) Obtain the custom object through a forced conversion and perform the release operation.
                (void)OsalSpinDestroy(&virtual->spin);
                OsalMemFree(virtual);
            }
            return;
        }
        
        static void VirtualI3cRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;
        
            HDF_LOGI("%s: enter", __func__);
        
            if (device == NULL || device->property == NULL) {
                HDF_LOGE("%s: device or property is NULL", __func__);
                return;
            }
        ...
        // Traverse and parse all nodes in i3c_config.hcs and perform the release operation on each node.
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                VirtualI3cRemoveByNode(childNode);  // See the description of VirtualI3cRemoveByNode for more details.
            }
        }
        ```

4. Implement the interrupt handler. The interrupt handler helps implement operations such as hot-join and IBI based on the address of the interrupt generated.

    ```c
    static int32_t VirtualI3cReservedAddrWorker(struct VirtualI3cCntlr *virtual, uint16_t addr)
    {
        (void)virtual;
        switch (addr) {
            case I3C_HOT_JOIN_ADDR:
                 VirtualI3cHotJoin(virtual);
                break;
            case I3C_RESERVED_ADDR_7H3E:
            case I3C_RESERVED_ADDR_7H5E:
            case I3C_RESERVED_ADDR_7H6E:
            case I3C_RESERVED_ADDR_7H76:
            case I3C_RESERVED_ADDR_7H7A:
            case I3C_RESERVED_ADDR_7H7C:
            case I3C_RESERVED_ADDR_7H7F:
            /* All single-bit errors in the broadcast address */
            HDF_LOGW("%s: broadcast Address single bit error!", __func__);
                break;
            default:
                HDF_LOGD("%s: Reserved address which is not supported!", __func__);
                break;
        }
        
        return HDF_SUCCESS;
    }
    ```

    ```c
    static int32_t I3cIbiHandle(uint32_t irq, void *data)
    {
        struct VirtualI3cCntlr *virtual = NULL;
        struct I3cDevice *device = NULL;
        uint16_t ibiAddr;
        char *testStr = "Hello I3C!";
    
        (void)irq;
        if (data == NULL) {
            HDF_LOGW("%s: data is NULL!", __func__);
            return HDF_ERR_INVALID_PARAM;
        }
        virtual = (struct VirtualI3cCntlr *)data;
        /* (Mandatory) Obtain the address where the interrupt is generated. Use the CHECK_RESERVED_ADDR macro to determine whether the address is a reserved address of the I3C. */
        ibiAddr = VirtualI3cGetIbiAddr();
        if (CHECK_RESERVED_ADDR(ibiAddr) == I3C_ADDR_RESERVED) {
            HDF_LOGD("%s: Calling VirtualI3cResAddrWorker...", __func__);
            return VirtualI3cReservedAddrWorker(virtual, ibiAddr);
        } else {
            HDF_LOGD("%s: Calling I3cCntlrIbiCallback...", __func__);
            device = GetDeviceByAddr(&virtual->cntlr, ibiAddr);
            if (device == NULL) {
                HDF_LOGE("func:%s device is NULL!",__func__);
                return HDF_ERR_MALLOC_FAIL;
            }
            if (device->ibi->payload > VIRTUAL_I3C_TEST_STR_LEN) {
                /* Place the string "Hello I3C!" into the IBI buffer. */
                *device->ibi->data = *testStr;
            }
            /* Invoke the IBI callback based on the I3C device that generates the IBI. */
            return I3cCntlrIbiCallback(device);
        }
    
        return HDF_SUCCESS;
    }
    ```
