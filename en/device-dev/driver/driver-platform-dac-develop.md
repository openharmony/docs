# DAC 

## Overview

### DAC

A digit-to-analog converter (DAC) is a device that converts a digital signal into an analog signal in electronics.

The DAC module supports development of digital-to-analog conversion. The DAC devices can be used to:

- Provide the output channel for the process control computer system and connect to the executor to implement automatic control of the production process.
- Serve as an important module in the analog-to-digital converter using feedback technologies.

### Basic Concepts

- Resolution

  The number of binary bits that can be converted by a DAC. A greater number of bits indicates a higher resolution.

- Conversion precision

  Difference between the actual output value of the DAC and the theoretical value when the maximum value is added to the input end. The conversion precision of a DAC converter varies depending on the structure of the chip integrated on the DAC and the interface circuit configuration. The ideal conversion precision value should be as small as possible. To achieve optimal DAC conversion precision, the DAC must have high resolution. In addition, errors in the devices or power supply of the interface circuits will affect the conversion precision. When the error exceeds a certain degree, a DAC conversion error will be caused.

- Conversion speed

  The conversion speed is determined by the setup time. The setup time is the period from the time the input suddenly changes from all 0s to all 1s to the time the output voltage remains within the FSR ± ½LSB (or FSR ± x%FSR). It is the maximum response time of the DAC, and hence used to measure the conversion speed.

  - The full scale range (FSR) is the maximum range of the output signal amplitude of a DAC. Different DACs have different FSRs, which can be limited by positive and negative currents or voltages.

  - The least significant byte (LSB) refers to bit 0 (the least significant bit) in a binary number.

### Working Principles

In the Hardware Driver Foundation (HDF), the DAC module uses the unified service mode for API adaptation. In this mode, a device service is used as the DAC manager to handle access requests from the devices of the same type in a unified manner. The unified service mode applies to the scenario where there are many device objects of the same type. If the independent service mode is used in this case, more device nodes need to be configured and more memory resources will be consumed. The DAC module uses the unified service mode, as shown in Figure 1.

The DAC module is divided into the following layers:
- Interface layer: provides the capabilities of opening and closing a device and writing data.
- Core layer: provides the capabilities of binding, initializing, and releasing devices.
- Adaptation layer: implements hardware-related functions, such as controller initialization.

In the unified service mode, the core layer manages all controllers in a unified manner and publishes a service for the interface layer. That is, the driver does not need to publish a service for each controller.

>![](../public_sys-resources/icon-note.gif) **NOTE**<br/>The core layer can call the APIs of the interface layer and uses hooks to call APIs of the adaptation layer. In this way, the adaptation layer can indirectly call the APIs of the interface layer, but the interface layer cannot call the APIs of the adaptation layer.

**Figure 1** Unified service mode 

![](figures/unified-service-mode.png "DAC unified service mode")

### Constraints

The DAC module supports only the kernel (LiteOS-A) for mini and small systems.

## Development Guidelines

### When to Use

The DAC module is used for digital-to-analog conversion, audio output, and motor control. The DAC driver is used when the digital signals input by the DAC module are converted into analog signals to output. Before using DAC devices with OpenHarmony, you need to adapt the DAC driver to OpenHarmony. The following describes how to do it.

### Available APIs

To enable the upper layer to successfully operate the hardware by calling the DAC APIs, hook functions are defined in **//drivers/hdf_core/framework/support/platform/include/dac/dac_core.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

Definitions of **DacMethod** and **DacLockMethod**:

```c++
struct DacMethod {
    /* Hook used to write data. */
    int32_t (*write)(struct DacDevice *device, uint32_t channel, uint32_t val);
    /* Hook used to start a DAC device. */
    int32_t (*start)(struct DacDevice *device);
    /* Hook used to stop a DAC device. */
    int32_t (*stop)(struct DacDevice *device);
};

struct DacLockMethod {
    int32_t (*lock)(struct DacDevice *device);
    void (*unlock)(struct DacDevice *device);
};
```
At the adaptation layer, **DacMethod** must be implemented, and **DacLockMethod** can be implemented based on service requirements. The core layer provides the default **DacLockMethod**, in which a spinlock is used to protect the critical section.

```c
static int32_t DacDeviceLockDefault(struct DacDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalSpinLock(&device->spin);
}

static void DacDeviceUnlockDefault(struct DacDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return;
    }
    (void)OsalSpinUnlock(&device->spin);
}

static const struct DacLockMethod g_dacLockOpsDefault = {
    .lock = DacDeviceLockDefault,
    .unlock = DacDeviceUnlockDefault,
};
```

If spinlock cannot be used, you can use another type of lock to implement **DacLockMethod**. The implemented **DacLockMethod** will replace the default **DacLockMethod**.

**Table 1** Hook functions in **DacMethod**

| Function| Input Parameter                                                        | Output Parameter| Return Value            | Description          |
| -------- | ------------------------------------------------------------ | ---- | ------------------ | -------------- |
| write    | **device**: structure pointer to the DAC controller at the core layer.<br>**channel**: channel ID, which is of the uint32_t type.<br>**val**: data to write, which is of the uint32_t type.| -  | HDF_STATUS| Writes the target digit-to-analog (DA) value.|
| start    | **device**: structure pointer to the DAC controller at the core layer.                       | -  | HDF_STATUS| Starts a DAC device.   |
| stop     | **device**: structure pointer to the DAC controller at the core layer.                       | -  | HDF_STATUS| Stops a DAC device.   |

**Table 2** Functions in **DacLockMethod**

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| lock | **device**: structure pointer to the DAC device object at the core layer.| -| HDF_STATUS| Acquires the critical section lock.|
| unlock | **device**: structure pointer to the DAC device object at the core layer.| -| HDF_STATUS| Releases the critical section lock.|


### How to Develop

The DAC module adaptation procedure is as follows:

1. Instantiate the driver entry.
2. Configure attribute files.
3. Instantiate the core layer APIs.
4. Debug the driver.

### Example

The following uses the Hi3516D V300 driver **//device/soc/hisilicon/common/platform/dac/dac_hi35xx.c** as an example to describe how to perform the DAC driver adaptation.

1. Instantiate the driver entry.

    The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the module name must be the same as that in **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, the HDF calls **Init()** to load the driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

    ```c++
    static struct HdfDriverEntry g_dacDriverEntry = {
        .moduleVersion = 1,
        .Init = VirtualDacInit,
        .Release = VirtualDacRelease,
        .moduleName = "virtual_dac_driver",// (Mandatory) The value must be the same as that in the .hcs file.
    };
    HDF_INIT(g_dacDriverEntry);             // Call HDF_INIT to register the driver entry with the HDF.
    ```

2. Configure attribute files.

   - Add the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file.

     The device attribute values are closely related to the driver implementation and the default values or value ranges of the **DacDevice** members at the core layer, for example, the number of device channels and the maximum transmission speed.

     In the unified service mode, the first device node in the **device_info.hcs** file must be the DAC manager. The parameters must be set as follows:

     | Parameter          | Value                                                                 |
     | --------------- | ------------------------------------------------------------------- |
     | policy          | **0**, which indicates that no service is published.                                               |
     | priority        | Driver startup priority. The value range is 0 to 200. A larger value indicates a lower priority. For the drivers with the same priority, the device loads them randomly.|
     | permission      | Driver permission.                                                            |
     | moduleName      | **HDF_PLATFORM_DAC_MANAGER**                                      |
     | serviceName     | **HDF_PLATFORM_DAC_MANAGER**                                      |
     | deviceMatchAttr | Reserved.                                                      |

     Configure DAC controller information from the second node. This node specifies a type of DAC controllers rather than a specific DAC controller. In this example, there is only one DAC device. If there are multiple DAC devices, add the **deviceNode** information to the **device_info.hcs** file and add the corresponding device attributes to the **dac_config.hcs** file for each device.

     **device_info.hcs** example:

        ```hcs
        root {
            device_dac :: device {
                /* device0 is the DAC manager. */
                device0 :: deviceNode {
                    policy = 0;
                    priority = 52;
                    permission = 0644;
                    serviceName = "HDF_PLATFORM_DAC_MANAGER";
                    moduleName = "HDF_PLATFORM_DAC_MANAGER";
                }
            }
            /* dac_virtual is a DAC controller. */
            dac_virtual :: deviceNode {
                policy = 0;
                priority = 56;
                permission = 0644;
                moduleName = "virtual_dac_driver";        // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                serviceName = "VIRTUAL_DAC_DRIVER";       // (Mandatory) Unique name of the service published by the driver.
                deviceMatchAttr = "virtual_dac";          // (Mandatory) Controller private data, which must be same as that of the controller in dac_config.hcs.
                }                                          
        }
        ```

    - Configure the **dac_test_config.hcs** file.

      Add a file to the directory of a product to configure driver parameters. For example, add the **vendor/hisilicon/hispark_taurus/hdf_config/hdf_test/dac_test_config.hcs** file for the hispark_taurus development board. 

      The configuration parameters are as follows:

        ```hcs
        root {
            platform {
            dac_config {
                    match_attr = "virtual_dac"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.   
                    template dac_device {
                        deviceNum = 0;          // Device number.    
                        validChannel = 0x1; // Valid channel 1.
                        rate = 20000; // Transmission speed.
                    }
                    device_0 :: dac_device {
                        deviceNum = 0;          // Device number.
                        validChannel = 0x2; // Valid channel 2.
                    }
                }
            }
        }
        ```

      After the **dac_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      For example, if the path of **dac_config.hcs** is **device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/dac/dac_config.hcs**, add the following statement to **hdf.hcs** of the product:

        ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/dac/dac_config.hcs" // Relative path of the file.
        ```

3. Instantiate the core layer APIs.

    - Initialize the **DacDevice** object.

        Initialize **DacDevice** in the **VirtualDacParseAndInit** function.

        ```c++
        /* Custom structure of the virtual driver. */
        struct VirtualDacDevice {
        /* DAC device structure. */
            struct DacDevice device;
            /* DAC device number. */
            uint32_t deviceNum;
            /* Valid channel. */ 
            uint32_t validChannel;
            /* DAC rate. */
            uint32_t rate;
        };
        /* Parse and initialize the **DacDevice** object of the core layer. */
        static int32_t VirtualDacParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
        {
            /* Define the return values. */
            int32_t ret;
            /* Pointer to the virtual DAC device. */
            struct VirtualDacDevice *virtual = NULL;
            (void)device;
            /* Allocate space for this pointer. */
            virtual = (struct VirtualDacDevice *)OsalMemCalloc(sizeof(*virtual));
        if (virtual == NULL) {
            /* If the value is null, return an error code. */
            HDF_LOGE("%s: Malloc virtual fail!", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
        /* Read the attribute file. */
        ret = VirtualDacReadDrs(virtual, node);
        if (ret != HDF_SUCCESS) {
            /* Failed to read the file. */
            HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
            /* Release the space for the virtual DAC device. */
            OsalMemFree(virtual);
            /* Set the pointer to 0. */
            virtual = NULL;
            return ret;
        }
        /* Initialize the pointer to the virtual DAC device. */
        VirtualDacDeviceInit(virtual);
        /* Initialize the priv object in DacDevice. */
        virtual->device.priv = (void *)node;
        /* Initialize the devNum object in DacDevice. */
        virtual->device.devNum = virtual->deviceNum;
        /* Initialize the ops object in DacDevice. */
        virtual->device.ops = &g_method;
        /* Add a DAC device. */
        ret = DacDeviceAdd(&virtual->device);
        if (ret != HDF_SUCCESS) {
            /* Failed to add the device. */
            HDF_LOGE("%s: add Dac controller failed! ret = %d", __func__, ret);
            /* Release the space for the virtual DAC device. */
            OsalMemFree(virtual);
            /* Set this pointer to null. */
            virtual = NULL;
            return ret;
        }
        
        return HDF_SUCCESS;
           }
        ```

        

    - Define a custom structure. 

        The custom structure holds parameters and data for the driver. Define the custom structure based on the function parameters of the device. The **DacTestReadConfig()** provided by the HDF reads the values in the **dac_config.hcs** file, and **DeviceResourceIface()** initializes the custom structure and passes some important parameters, such as the device number and bus number, to the **DacDevice** object at the core layer.

        ```c++
        struct VirtualDacDevice {
              struct DacDevice device;// (Mandatory) Control object at the core layer. For details, see the description below.
              uint32_t deviceNum;      // (Mandatory) Device number.
              uint32_t validChannel;   // (Mandatory) Valid channel.
              uint32_t rate;           // (Mandatory) Sampling rate.
          };
          
          /* DacDevice is the core layer controller structure. The Init() function assigns values to the members of DacDevice. */
          struct DacDevice {
              const struct DacMethod *ops;
              OsalSpinlock spin;      // Spinlock.
              uint32_t devNum; // Device number.
              uint32_t chanNum; // Device channel number.
              const struct DacLockMethod *lockOps;
              void *priv;
          };
        ```

        

    - Instantiate **DacDevice** in **DacMethod**.

        The **VirtualDacWrite**, **VirtualDacStop**, and **VirtualDacStart** functions are instantiated in **dac_virtual.c**.

        ```c++
        static const struct DacMethod g_method = {
            .write = VirtualDacWrite, // Write data to a DAC device. 
            .stop = VirtualDacStop, // Stop a DAC device.
            .start = VirtualDacStart, // Start a DAC device.
        };
        ```

        >![](../public_sys-resources/icon-note.gif) **NOTE**<br>For details about **DacMethod**, see [Available APIs](#available-apis).

    

    - Implement the **Init** function.

        Input parameter:

        **HdfDeviceObject**, an interface parameter provided by the driver, contains the .hcs information.

        Return value:

        **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

        | Status                 | Description                |
        | ---------------------- | -------------------------- |
        | HDF_ERR_INVALID_OBJECT | Invalid controller object. |
        | HDF_ERR_INVALID_PARAM  | Invalid parameter.         |
        | HDF_ERR_MALLOC_FAIL    | Failed to allocate memory. |
        | HDF_ERR_IO             | I/O error.                 |
        | HDF_SUCCESS            | Transmission successful.   |
        | HDF_FAILURE            | Transmission failed.       |

        

        Function description:

        Initializes the custom structure object and **DacDevice**, and calls the **DacDeviceAdd** function at the core layer.

        ```c++
          static int32_t VirtualDacParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
            {
                /* Define the return values. */
                int32_t ret;
                /* Pointer to the VirtualDacDevice structure. */
                struct VirtualDacDevice *virtual = NULL;
                (void)device;
                /* Allocate memory of the specified size. */
                virtual = (struct VirtualDacDevice *)OsalMemCalloc(sizeof(*virtual));
                if (virtual == NULL) {
                    /* Failed to allocate memory. */
                    HDF_LOGE("%s: Malloc virtual fail!", __func__);
                    return HDF_ERR_MALLOC_FAIL;
                }
                /* Read the node parameters in the HCS. The function definition is as follows. */
                ret = VirtualDacReadDrs(virtual, node);
                if (ret != HDF_SUCCESS) {
                    /* Failed to read the node data. */
                    HDF_LOGE("%s: Read drs fail! ret:%d", __func__, ret);
                    goto __ERR__;
                }
                /* Initialize the DAC device pointer. */
                VirtualDacDeviceInit(virtual);
                /* Pass in the private data of the node. */
                virtual->device.priv = (void *)node;
                /* Pass in the device number. */
                virtual->device.devNum = virtual->deviceNum;
                /* Pass in the method. */
                virtual->device.ops = &g_method;
                /* Add a DAC device. */
                ret = DacDeviceAdd(&virtual->device);
                if (ret != HDF_SUCCESS) {
                    /* Failed to add the DAC device. */
                    HDF_LOGE("%s: add Dac controller failed! ret = %d", __func__, ret);
                    goto __ERR__;
                }
                /* The DAC device is added successfully. */
                return HDF_SUCCESS;
            __ERR__:
                /* If the pointer is null */
                if (virtual != NULL) {
                    / Release the memory. */
                    OsalMemFree(virtual);
                    /* Set this pointer to null. */
                    virtual = NULL;
                }
            
                return ret;
            }
            
            static int32_t VirtualDacInit(struct HdfDeviceObject *device)
            {
                /* Define return values. */
                int32_t ret;
                /* Child node of the device structure. */
                const struct DeviceResourceNode *childNode = NULL;
                /* Check the input parameter pointer. */
                if (device == NULL || device->property == NULL) {
                    /* The input parameter pointer is null. */
                    HDF_LOGE("%s: device or property is NULL", __func__);
                    return HDF_ERR_INVALID_OBJECT;
                }
                /* The input parameter pointer is not null. */
                ret = HDF_SUCCESS;
                DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                    /* Parse the child node. */
                    ret = VirtualDacParseAndInit(device, childNode);
                    if (ret != HDF_SUCCESS) {
                        /* Failed to parse the child node. */
                        break;
                    }
                }
                /* The child node is parsed. */
                return ret;
            }
            
            static int32_t VirtualDacReadDrs(struct VirtualDacDevice *virtual, const struct DeviceResourceNode *node)
            {
                struct DeviceResourceIface *drsOps = NULL;
            
                /* Obtain the drsOps method. */
                drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
                if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetUint16 == NULL) {
                    HDF_LOGE("%s: Invalid drs ops fail!", __func__);
                    return HDF_FAILURE;
                }
                /* Read the configuration parameters in sequence and fill them in the structure. */
                if (drsOps->GetUint32(node, "deviceNum", &virtual->deviceNum, 0) != HDF_SUCCESS) {
                    HDF_LOGE("%s: Read deviceNum fail!", __func__);
                    return HDF_ERR_IO;
                }
                if (drsOps->GetUint32(node, "validChannel", &virtual->validChannel, 0) != HDF_SUCCESS) {
                    HDF_LOGE("%s: Read validChannel fail!", __func__);
                    return HDF_ERR_IO;
                }
                if (drsOps->GetUint32(node, "rate", &virtual->rate, 0) != HDF_SUCCESS) {
                    HDF_LOGE("%s: Read rate fail!", __func__);
                    return HDF_ERR_IO;
                }
                return HDF_SUCCESS;
            }
        ```

          

    - Implement the **Release** function.

      Input parameter:

      **HdfDeviceObject**, an interface parameter provided by the driver, contains the .hcs information.

      Return value:

      No value is returned.

      Function description:

      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

       >![](../public_sys-resources/icon-note.gif) **NOTE** <br>
       >
       >All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.

       

      ```c++
       static void VirtualDacRemoveByNode(const struct DeviceResourceNode *node)
           {
               /* Define return values. */
               int32_t ret;
               /*Define the DAC device number. */
               int16_t devNum;
               /* Pointer to the DacDevice structure. */
               struct DacDevice *device = NULL;
               // Pointer to the VirtualDacDevice structure. */
               struct VirtualDacDevice *virtual = NULL;
               /* Pointer to the DeviceResourceIface structure. */
               struct DeviceResourceIface *drsOps = NULL;
               /* Obtain device resources through the instance entry. */
               drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
               /* Check the input parameter pointer. */
               if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                   /* The pointer is null. */
                   HDF_LOGE("%s: invalid drs ops fail!", __func__);
                   return;
               }
               /* Obtain data of the devNum node. */
               ret = drsOps->GetUint16(node, "devNum", (uint16_t *)&devNum, 0);
               if (ret != HDF_SUCCESS) {
                   /* The information fails to be obtained. */
                   HDF_LOGE("%s: read devNum fail!", __func__);
                   return;
               }
               /* Obtain the DAC device number. */
               device = DacDeviceGet(devNum);
               /* Check whether the DAC device number and data are null. */
               if (device != NULL && device->priv == node) {
                   /* Release the DAC device number if the device data is null. */
                   DacDevicePut(device);
                   /* Remove the DAC device number. */
                   DacDeviceRemove(device);
                   virtual = (struct VirtualDacDevice *)device;
                   /* Release the virtual pointer. */
                   OsalMemFree(virtual);
               }
               return;
           }
           
           static void VirtualDacRelease(struct HdfDeviceObject *device)
           {
               /* Define the child node structure pointer to the DeviceResourceNode. */
               const struct DeviceResourceNode *childNode = NULL;
               /* Check whether the input parameter pointer is null. */
               if (device == NULL || device->property == NULL) {
                   /* The input parameter pointer is null. */
                   HDF_LOGE("%s: device or property is NULL", __func__);
                   return;
               }
               
               DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                   /* Remove the DAC by node. */
                   VirtualDacRemoveByNode(childNode);
               }
           }
      ```

        


4. Debug the driver.

   (Optional) Verify the basic functions of the new driver, for example, check whether the test cases are successful after the driver is loaded.
