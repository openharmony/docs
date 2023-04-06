# Pin

## Overview

### Function

The pin module, also called pin controller, manages pin resources of the system on a chip (SoC) and implements the pin multiplexing function.

### Basic Concepts

Pin is a software concept designed to uniformly manage SoC pins, implement pin multiplexing, and set electrical features of pins.

- SoC

  An SoC is a chip that integrates microprocessors, analog IP cores, digital IP cores, and memory for specific purposes.

- Pin multiplexing

  When the number of pins of a chip cannot handle the increasing connection requests, you can set software registers to make the pins to work in different states.

### Working Principles

In the Hardware Driver Foundation (HDF), the pin module uses the unified service mode for API adaptation. In this mode, a device service is used as the pin manager to handle access requests from the devices of the same type in a unified manner. The unified service mode applies to the scenario where there are many device objects of the same type. If the independent service mode is used in this case, more device nodes need to be configured and more memory resources will be consumed. The following figure shows the unified service mode.

In the unified service mode, the core layer manages all controllers in a unified manner and publishes a service for the interface layer. That is, the driver does not need to publish a service for each controller.

The pin module is divided into the following layers:

- Interface layer: provides APIs for obtaining a pin, setting or obtaining the pull type, pull strength, and function of a pin, and releasing a pin.
- Core layer: provides APIs for matching pin resources, adding and removing a pin controller, and managing pins. The core layer interacts with the adaptation layer through hook functions.
- Adaptation layer: instantiates the hook functions to implement specific features.

**Figure 1** Unified service mode

![](figures/unified-service-mode.png)

### Constraints

The pin module supports only the LiteOS-A kernel of the small system.

## Development Guidelines

### When to Use

The pin module is used to manage pin resources. Before using the SoC with the HDF, you need to perform PIN driver adaptation.

### Available APIs

To enable the upper layer to successfully operate pins by calling the pin driver APIs, hook functions are defined in **//drivers/hdf_core/framework/support/platform/include/pin/pin_core.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

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

**Table 1** Hook functions in PinCntlrMethod

| Function    | Input Parameter                                       | Output Parameter                                  | Return Value| Description|
| ------------ | ------------------------------------------- | ------ | ---- | ---- |
| SetPinPull | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. <br>**pullType**: pull type of the pin.| -|HDF_STATUS|Sets the pull type of a pin.|
| GetPinPull | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. | **pullType**: pointer to the pull type obtained.| HDF_STATUS| Obtains the pull type of a pin.|
| SetPinStrength | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. <br>**strength**: pull type to set, which is a uint32_t variable.| -| HDF_STATUS| Sets the pull strength of a pin.|
| GetPinStrength | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. | **strength**: pointer to the pull strength obtained.| HDF_STATUS| Obtains the pull strength of a pin.|
| SetPinFunc | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. <br>**funcName**: pointer to the pin function to set. It is a character constant.| -| HDF_STATUS| Sets the pin function.|
| GetPinFunc | **cntlr**: structure pointer to the pin controller at the core layer.<br>**index**: pin index, which is a uint32_t variable. | **funcName**: double pointer to the PIN function obtained. It is a character constant.| HDF_STATUS| Obtains the pin function.|

### How to Develop

The pin module adaptation procedure is as follows:

- Instantiate the driver entry.
- Configure attribute files.
- Instantiate the pin controller object.
- Debug the driver.

### Example

The following uses the **//device_soc_hisilicon/common/platform/pin/pin_hi35xx.c** driver of the Hi3516D V300 development board as an example to describe the pin driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls **Bind()** and then **Init()** to load a driver. If **Init()** fails to be called, the HDF calls **Release()** to release driver resources and exit.

   PIN driver entry example:

   ```c
   static struct HdfDriverEntry g_hi35xxPinDriverEntry = {
       .moduleVersion = 1,
       .Bind = Hi35xxPinBind,
       .Init = Hi35xxPinInit,
       .Release = Hi35xxPinRelease,
       .moduleName = "hi35xx_pin_driver",  // (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   HDF_INIT(g_hi35xxPinDriverEntry);      // Call HDF_INIT to register the driver entry with the HDF.
   ```

2. Configure attribute files.

   Add the deviceNode information to the **device_info.hcs** file. The deviceNode information is related to the driver entry registration. The following example uses two pin controllers as an example. If there are more pin controllers, add the deviceNode information to the **device_info.hcs** file for each controller. The device attribute values configured in **pin_config.hcs** are closely related to the driver implementation and default values or value ranges of the **PinCntlr** members at the core layer.

   - **device_info.hcs** example

      Add the deviceNode information to the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file.

      ```c
      root {
          device_info {
              platform :: host {
                  hostName = "platform_host";
                  priority = 50;
                  device_pin :: device {
                      device0 :: deviceNode {                              // Used to manage pins and release services in a unified manner.
                          policy = 2;                                      // The value 2 means to publish services for both kernel- and user-mode processes. 
                          priority = 8;                                    // Driver startup priority.
                          permission = 0644;                               // Permission for the device node created.
                          moduleName = "HDF_PLATFORM_PIN_MANAGER";
                          serviceName = "HDF_PLATFORM_PIN_MANAGER";
                      }
                      device1:: deviceNode {                               // Configure an HDF device node for each pin controller.
                          policy = 0;
                          priority = 10;                                   // Driver startup priority.
                          permission = 0644;                               // Permission for the device node created.
                          moduleName = "hi35xx_pin_driver";                // (mandatory) Driver name, which must be the same as moduleName in the driver entry.
                          deviceMatchAttr = "hisilicon_hi35xx_pin_0";      // (Mandatory) Controller private data, which must be the same as that of the controller in pin_config.hcs.
                      }
                      device2 :: deviceNode {
                          policy = 0;
                          priority = 10;
                          permission = 0644;
                          moduleName = "hi35xx_pin_driver";
                          deviceMatchAttr = "hisilicon_hi35xx_pin_1";
                      }
                      ...
                  }
              }
          }
      }
      ```

   -  **pin_config.hcs** example:

      Configure the device attributes in the **//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pin/pin_config.hcs** file. The parameters are as follows:

      ```c
      root {
          platform {
              pin_config_hi35xx {
                  template pin_controller {                   // (Mandatory) Template configuration. If the template is used to configure device node information, the default values in the template will be used for the fields that are not declared for the node.
                      number = 0;                             // (Mandatory) PIN controller number.
                      regStartBasePhy = 0;                    // (Mandatory) Start address of the physical base address of the register.
                      regSize = 0;                            // (Mandatory) Register size.
                      pinCount = 0;                           // (Mandatory) Number of pins.
                      match_attr = "";
                      template pin_desc {
                          pinName = "";                       // (Mandatory) Pin name.
                              init = 0;                       // (Mandatory) Default value of the register.
                              F0 = "";                        // (Mandatory) Function 0.
                              F1 = "";                        // Function 1.
                              F2 = "";                        // Function 2.
                              F3 = "";                        // Function 3.
                              F4 = "";                        // Function 4.
                              F5 = "";                        // Function 5.
                          }
                  }
                  controller_0 :: pin_controller {
                      number = 0;
                      regStartBasePhy = 0x10FF0000;
                      regSize = 0x48;
                      pinCount = 18;
                      match_attr = "hisilicon_hi35xx_pin_0";
                      T1 :: pin_desc {
                          pinName = "T1";
                          init = 0x0600;
                          F0 = "EMMC_CLK";
                          F1 = "SFC_CLK";
                          F2 = "SFC_BOOT_MODE";
                      }
                      ...                                     // Add each pin under the pin controller.
                  }
                  ...                                         // Each pin controller corresponds to a controller node. If there are multiple pin controllers, add the controller nodes one by one.
              }
          }
      }
      ```

      After the **pin_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pin/pin_config.hcs" // Relative path of the file.
      ```

3. Instantiate the pin controller object.

   Initialize the **PinCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **PinCntlrMethod** in **PinCntlr** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **pin_config.hcs** file to initialize the members in the custom structure and passes important parameters to the object at the core layer.

      Initialize **PinCntlr** in **Hi35xxPinCntlrInit**.

      ```c
      // Custom pin description structure.
      struct Hi35xxPinDesc {
          const char *pinName;                       // Pin name.
          uint32_t init;                             // Initial value.
          uint32_t index;                            // Pin index.
          int32_t pullType;                          // Pull type of the pin.
          int32_t strength;                          // Pull strength of the pin.
          const char *func[HI35XX_PIN_FUNC_MAX];     // Array of pin function names.
      };

      /* Custom structure.
      struct Hi35xxPinCntlr {
          struct PinCntlr cntlr                      // Core layer control object.
          struct Hi35xxPinDesc *desc;                // Pointer to the pin description structure.
          volatile unsigned char *regBase;           // Register base address used for address mapping.
          uint16_t number;                           // Pin controller number.
          uint32_t regStartBasePhy;                  // Start address of the register physical base address.
          uint32_t regSize;                          // Register size.
          uint32_t pinCount;                         // Number of pins.
      };

      // PinCntlr is the controller structure at the core layer. The Init function assigns values to the members of PinCntlr.
      struct PinCntlr {
          struct IDeviceIoService service;           // Driver service.
          struct HdfDeviceObject *device;            // Driver device object.
          struct PinCntlrMethod *method;             // Hook functions.
          struct DListHead node;                     // Linked list node.
          OsalSpinlock spin;                         // Spinlock.
          uint16_t number;                           // Pin controller number.
          uint16_t pinCount;                         // Number of pins.
          struct PinDesc *pins;                      // Pin resources.
          void *priv;                                // Private data.
      };

      // Initialize the pin controller.
      static int32_t Hi35xxPinCntlrInit(struct HdfDeviceObject *device, struct Hi35xxPinCntlr *hi35xx)
      {
          struct DeviceResourceIface *drsOps = NULL;
          int32_t ret;
          // Read the pin controller attributes from the .hcs file.
          drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
          if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetUint16 == NULL) {
              HDF_LOGE("%s: invalid drs ops fail!", __func__);
              return HDF_FAILURE;
          }
          ret = drsOps->GetUint16(device->property, "number", &hi35xx->number, 0);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read number failed", __func__);
              return ret;
          }

          if (hi35xx->number > HI35XX_PIN_MAX_NUMBER) {
              HDF_LOGE("%s: invalid number:%u", __func__, hi35xx->number);
              return HDF_ERR_INVALID_PARAM;
          }
          ret = drsOps->GetUint32(device->property, "regStartBasePhy", &hi35xx->regStartBasePhy, 0);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read regStartBasePhy failed", __func__);
              return ret;
          }
          ret = drsOps->GetUint32(device->property, "regSize", &hi35xx->regSize, 0);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read regSize failed", __func__);
              return ret;
          }
          ret = drsOps->GetUint32(device->property, "pinCount", &hi35xx->pinCount, 0);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read pinCount failed", __func__);
              return ret;
          }
          if (hi35xx->pinCount > PIN_MAX_CNT_PER_CNTLR) {
              HDF_LOGE("%s: invalid number:%u", __func__, hi35xx->number);
              return HDF_ERR_INVALID_PARAM;
          }
          // Assign the values read to the members of the pin controller to initialize the pin controller.
          hi35xx->cntlr.pinCount = hi35xx->pinCount;
          hi35xx->cntlr.number = hi35xx->number;
          hi35xx->regBase = OsalIoRemap(hi35xx->regStartBasePhy, hi35xx->regSize); // Pin controller mapping.
          if (hi35xx->regBase == NULL) {
              HDF_LOGE("%s: remap Pin base failed", __func__);
              return HDF_ERR_IO;
          }
          hi35xx->desc = (struct Hi35xxPinDesc *)OsalMemCalloc(sizeof(struct Hi35xxPinDesc) * hi35xx->pinCount);
          if (hi35xx->desc == NULL) {
              HDF_LOGE("%s: memcalloc hi35xx desc failed", __func__);
              return HDF_ERR_MALLOC_FAIL;
          }
          hi35xx->cntlr.pins = (struct PinDesc *)OsalMemCalloc(sizeof(struct PinDesc) * hi35xx->pinCount);
              if (hi35xx->desc == NULL) {
              HDF_LOGE("%s: memcalloc hi35xx cntlr pins failed", __func__);
              return HDF_ERR_MALLOC_FAIL;
          }
          return HDF_SUCCESS;
      }
      ```

   - Instantiate the **PinCntlrMethod** structure in **PinCntlr**.

      ```c
      static struct PinCntlrMethod g_method = {
          .SetPinPull = Hi35xxPinSetPull,              // Set the pull type.
          .GetPinPull = Hi35xxPinGetPull,              // Obtain the pull type.
          .SetPinStrength = Hi35xxPinSetStrength,      // Set the pull strength.
          .GetPinStrength = Hi35xxPinGetStrength,      // Obtain the pull strength.
          .SetPinFunc = Hi35xxPinSetFunc,              // Set the pin functions.
          .GetPinFunc = Hi35xxPinGetFunc,              // Obtain the pin functions.
      };
      ```

   - Implement the **Init** function.

      Input Parameter

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

      | **State**          | **Description**  |
      | ---------------------- | -------------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL    | Failed to allocate memory.  |
      | HDF_ERR_INVALID_PARAM  | Invalid parameter.      |
      | HDF_ERR_IO             | I/O error.      |
      | HDF_SUCCESS            | Initialization successful.    |
      | HDF_FAILURE            | Initialization failed.    |

      Function description:

      Initializes the custom structure object and **PinCntlr** members, and calls **PinCntlrAdd()** to add the pin controller to the core layer.

      ```c
      static int32_t Hi35xxPinReadFunc(struct Hi35xxPinDesc *desc, const struct DeviceResourceNode *node, struct DeviceResourceIface *drsOps)
      {
          int32_t ret;
          uint32_t funcNum = 0;
          // Read the pin function names of the pin controller child nodes from the .hcs file.
          ret = drsOps->GetString(node, "F0", &desc->func[funcNum], "NULL");
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read F0 failed", __func__);
              return ret;
          }

          funcNum++;
          ret = drsOps->GetString(node, "F1", &desc->func[funcNum], "NULL");
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read F1 failed", __func__);
              return ret;
          }

          funcNum++;
          ...
          return HDF_SUCCESS;
      }

      static int32_t Hi35xxPinParsePinNode(const struct DeviceResourceNode *node, struct Hi35xxPinCntlr *hi35xx, int32_t index)
      {
          int32_t ret;
          struct DeviceResourceIface *drsOps = NULL;
          // Read the pin attributes of the pin controller child nodes from the .hcs file.
          drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
          if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {
              HDF_LOGE("%s: invalid drs ops fail!", __func__);
              return HDF_FAILURE;
          }
          ret = drsOps->GetString(node, "pinName", &hi35xx->desc[index].pinName, "NULL");
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read pinName failed", __func__);
              return ret;
          }
          ...
          ret = Hi35xxPinReadFunc(&hi35xx->desc[index], node, drsOps);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s:Pin read Func failed", __func__);
              return ret;
          }
          hi35xx->cntlr.pins[index].pinName = hi35xx->desc[index].pinName;
          hi35xx->cntlr.pins[index].priv = (void *)node;
          ...
          return HDF_SUCCESS;
      }

      static int32_t Hi35xxPinInit(struct HdfDeviceObject *device)
      {
          ...
          struct Hi35xxPinCntlr *hi35xx = NULL;
          ...
          ret = Hi35xxPinCntlrInit(device, hi35xx);                         // Initialize the pin controller.
          ...
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {   // Traverse each child node of the pin controller.
              ret = Hi35xxPinParsePinNode(childNode, hi35xx, index);        // Parse child nodes.
              ...
          }

          hi35xx->cntlr.method = &g_method;                                 // Attach the PinCntlrMethod instance.
          ret = PinCntlrAdd(&hi35xx->cntlr);                                // Add the controller.
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: add Pin cntlr: failed", __func__);
              ret = HDF_FAILURE;
          }
          return HDF_SUCCESS;
      }
      ```

   - Implement the **Release** function.

      Input parameters:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      No value is returned.

      Function description:

      Releases the memory and deletes the controller. This function needs to assign values to **Release()** in the driver entry structure. If the HDF fails to call **Init()** to initialize the driver, **Release()** is called to release driver resources.

      ```c
      static void Hi35xxPinRelease(struct HdfDeviceObject *device)
      {
          int32_t ret;
          uint16_t number;
          struct PinCntlr *cntlr = NULL;
          struct Hi35xxPinCntlr *hi35xx = NULL;
          struct DeviceResourceIface *drsOps = NULL;

          if (device == NULL || device->property == NULL) {
              HDF_LOGE("%s: device or property is null", __func__);
              return;
          }
          // Read the pin controller number from the .hcs file.
          drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
          if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {   
              HDF_LOGE("%s: invalid drs ops", __func__);
              return;
          }
          ret = drsOps->GetUint16(device->property, "number", &number, 0);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("%s: read cntlr number failed", __func__);
              return;
          }

          cntlr = PinCntlrGetByNumber(number);            // Obtain the pin controller based on the controller number. 
          PinCntlrRemove(cntlr);
          hi35xx = (struct Hi35xxPinCntlr *)cntlr;
          if (hi35xx != NULL) {
              if (hi35xx->regBase != NULL) {
                  OsalIoUnmap((void *)hi35xx->regBase);
              }
              OsalMemFree(hi35xx);
          }
      }
      ```

4. Debug the driver.

   (Optional) Verify basic functionalities of new drivers. For example, verify the information returned when the driver is loaded and whether data is successfully transmitted.
