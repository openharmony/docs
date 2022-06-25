# ADC


## Overview

An analog-to-digital converter (ADC) is a device that converts analog signals into digital signals. In the Hardware Driver Foundation (HDF), the ADC module uses the unified service mode for API adaptation. In this mode, a device service is used as the ADC manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the ADC has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services.

  **Figure 1** Unified service mode

  ![](figures/unified-service-mode.png "ADC Unified Service Mode")


## Available APIs

**AdcMethod**:


```
struct AdcMethod {
  int32_t (*read)(struct AdcDevice *device, uint32_t channel, uint32_t *val);
  int32_t (*start)(struct AdcDevice *device);
  int32_t (*stop)(struct AdcDevice *device);
};
```

  **Table 1** Description of the callback functions in AdcMethod

| Function| Input Parameter| Output Parameter| Return Value| Description| 
| -------- | -------- | -------- | -------- | -------- |
| read | **device**: structure pointer to the ADC controller at the core layer.<br>**channel**: channel ID, which is of the uint32_t type.| **val**: pointer to the signal data to be transmitted. It is of the uint32_t type.| HDF_STATUS| Reads the signal data sampled by the ADC.| 
| stop | **device**: structure pointer to the ADC controller at the core layer.| –| HDF_STATUS| Stops an ADC device.| 
| start | **device**: structure pointer to the ADC controller at the core layer.| –| HDF_STATUS| Starts an ADC device.| 


## How to Develop

The ADC module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **adc_config.hcs** file.

3. Instantiate the ADC controller object.
   - Initialize **AdcDevice**.
   - Instantiate **AdcMethod** in the **AdcDevice** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **AdcMethod**, see [Available APIs](#available-apis).

4. Debug the driver.
   (Optional) For new drivers, verify basic functions, for example, check the information returned after the driver is attached and check whether signals are successfully collected.


## Development Example

  The following uses **adc_hi35xx.c** as an example to present the information required for implementing device functions.
1. Instantiate the driver entry.<br/>The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   ADC driver entry example:

   Many devices may connect to the ADC. In the HDF, a manager object needs to be created for the ADC. When a device needs to be started, the manager object locates the target device based on the specified parameters.

   The driver of the ADC manager is implemented by the core layer. The **Init** function of the driver layer calls **AdcDeviceAdd** of the core layer to add devices to the ADC manager. Therefore, vendors do not need to implement this part.

   
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
    .moduleName = "HDF_PLATFORM_ADC_MANAGER",// Correspond to device0 in the device_info file.
   };
   HDF_INIT(g_adcManagerEntry);
   ```

2. Add **deviceNode** to the **device_info.hcs** file, and configure the device attributes in the **adc_config.hcs** file.<br> The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or restriction ranges of the **AdcDevice** members at the core layer.
     In the unified service mode, the first device node in the **device_info** file must be the ADC manager. The parameters must be set as follows:
   | Parameter| Value| 
   | -------- | -------- |
   | moduleName | **HDF_PLATFORM_ADC_MANAGER**| 
   | serviceName | –| 
   | policy | **0**, which indicates that no service is published.| 
   | deviceMatchAttr | Reserved.| 

   Configure ADC controller information from the second node. This node specifies a type of ADC controllers rather than an ADC controller. In this example, there is only one ADC device. If there are multiple ADC devices, add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **adc_config** file for each device.

   - **device_info.hcs** configuration example

     
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
              policy = 0;        // The value 0 indicates that no service is published.
              priority = 55;     // Driver startup priority.
              permission = 0644; // Permission to create device nodes for the driver.
              moduleName = "hi35xx_adc_driver"; // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
              serviceName = "HI35XX_ADC_DRIVER"; // (Mandatory) Unique name of the service published by the driver.
              deviceMatchAttr = "hisilicon_hi35xx_adc";// (Mandatory) Private data of the controller. The value must be the same as that of the corresponding controller in adc_config.hcs.
              }                                        // The specific controller information is configured in adc_config.hcs.
            }
          }
        }
      }
      ```
   - **adc_config.hcs** configuration example

     
      ```
      root {
      platform {
          adc_config_hi35xx {
          match_attr = "hisilicon_hi35xx_adc";
          template adc_device {
              regBasePhy = 0x120e0000;// Physical base address of the register.
              regSize = 0x34;         // Bit width of the register.
              deviceNum = 0;          // Device number.
              validChannel = 0x1;     // Valid channel.
              dataWidth = 10;          // Bit width of the received signal.
              scanMode = 1;          // Scan mode.
              delta = 0;              // Delta parameter.
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

3. Initialize the **AdcDevice** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **AdcMethod** in **AdcDevice** (so that the underlying driver functions can be called).
   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface()** function provided by the HDF reads **adc_config.hcs** to initialize the custom structure and passes some important parameters, such as the device number and bus number, to the **AdcDevice** object at the core layer.

      
      ```
      struct Hi35xxAdcDevice {
          struct AdcDevice device;// (Mandatory) Control object of the core layer. For details, see the description of AdcDevice.
          volatile unsigned char *regBase;// (Mandatory) Base address of the register.
          volatile unsigned char *pinCtrlBase;
          uint32_t regBasePhy; // (Mandatory) Physical base address of the register.
          uint32_t regSize; // (Mandatory) Bit width of the register.
          uint32_t deviceNum; // (Mandatory) Device number.
          uint32_t dataWidth; // (Mandatory) Data bit width of received signals.
          uint32_t validChannel; // (Mandatory) Valid channel.
          uint32_t scanMode; // (Mandatory) Scan mode.
          uint32_t delta;
          uint32_t deglitch;
          uint32_t glitchSample;
          uint32_t rate;         // (Mandatory) Sampling rate.
      };
      
      // AdcDevice is the core layer controller structure. The **Init()** function assigns values to the members of AdcDevice.
      struct AdcDevice {
          const struct AdcMethod *ops;
          OsalSpinlock spin;
          uint32_t devNum;
          uint32_t chanNum;
          const struct AdcLockMethod *lockOps;
          void *priv;
      };
      ```

   - Instantiating **AdcMethod** in **AdcDevice**<br>This example does not provide the implementation of the **AdcLockMethod** callback. For details, see I2C driver development. Other members are initialized by the **Init** function.

     
      ```
      static const struct AdcMethod g_method = {
          .read = Hi35xxAdcRead,
          .stop = Hi35xxAdcStop,
          .start = Hi35xxAdcStart,
      };
      ```
   - **Init** function

      Input parameter:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      Return value:

      HDF_STATUS<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

        | Status| Description| 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.| 
      | HDF_ERR_INVALID_PARAM | Invalid parameter.| 
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.| 
      | HDF_ERR_IO | I/O error.| 
      | HDF_SUCCESS | Transmission successful.| 
      | HDF_FAILURE | Transmission failed.| 

      Function description:

       Initializes the custom structure object and **AdcDevice**, and calls the **AdcDeviceAdd** function at the core layer.
      
      ```
      static int32_t Hi35xxAdcInit(struct HdfDeviceObject *device)
      {
          int32_t ret;
          struct DeviceResourceNode *childNode = NULL;
          ...
          // Traverse and parse all nodes in adc_config.hcs and call the **Hi35xxAdcParseInit** function to initialize the devices separately.   
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              ret = Hi35xxAdcParseInit(device, childNode);// The function definition is as follows: 
              ...
          }
          return ret;
      }
      
      static int32_t Hi35xxAdcParseInit(struct HdfDeviceObject *device, struct DeviceResourceNode *node)
      {
      int32_t ret;
      struct Hi35xxAdcDevice *hi35xx = NULL; // (Mandatory) Custom structure object.
      (void)device;
      
      hi35xx = (struct Hi35xxAdcDevice *)OsalMemCalloc(sizeof(*hi35xx)); // (Mandatory) Allocate memory.
      ...
      ret = Hi35xxAdcReadDrs(hi35xx, node);     // (Mandatory) Fill the default values in the adc_config file to the structure.
      ...
      hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize);// (Mandatory) Address mapping.
      ...
      hi35xx->pinCtrlBase = OsalIoRemap(HI35XX_ADC_IO_CONFIG_BASE, HI35XX_ADC_IO_CONFIG_SIZE);
      ...
      Hi35xxAdcDeviceInit(hi35xx);              // (Mandatory) Initialize the ADC.
      hi35xx->device.priv = (void *)node;       // (Mandatory) Store device attributes.
      hi35xx->device.devNum = hi35xx->deviceNum;// (Mandatory) Initialize AdcDevice members.
      hi35xx->device.ops = &g_method;           // (Mandatory) Attach the AdcMethod instance object.
      ret = AdcDeviceAdd(&hi35xx->device));      // (Mandatory) Call this function to set the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
      ...
      return HDF_SUCCESS;
      
      __ERR__:
      if (hi35xx != NULL) {                     // If the operation fails, execute the initialization function reversely.
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
   - **Release** function

      Input parameter:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      Return value:

      No value is returned.

      Function description:

      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the value assignment operations.

      
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
          AdcDeviceRemove(device);               // (Mandatory) Remove the AdcDevice object from the driver manager.
          hi35xx = (struct Hi35xxAdcDevice *)device;// (Mandatory) Obtain the custom object through forced conversion and perform the release operation.
          OsalIoUnmap((void *)hi35xx->regBase);
          OsalMemFree(hi35xx);
      }
      return
      ```
