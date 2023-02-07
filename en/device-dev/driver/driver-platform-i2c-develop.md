# I2C

## Overview

### Function

The Inter-Integrated Circuit (I2C) is a simple, bidirectional, and synchronous serial bus that uses merely two wires. It is widely used in short-distance communication due to simple connection and low cost.

### Working Principles

In the Hardware Driver Foundation (HDF), the I2C module uses the unified service mode for API adaptation. In this mode, a device service is used as the I2C manager to handle access requests from the devices of the same type in a unified manner. The unified service mode applies to the scenario where there are many device objects of the same type. If the independent service mode is used in this case, more device nodes need to be configured and more memory resources will be consumed. The following figure illustrates the unified service mode.

In the unified service mode, the core layer manages all controllers in a unified manner and publishes a service for the interface layer. That is, the driver does not need to publish a service for each controller.

The I2C module is divided into the following layers:

- Interface layer: provides the capabilities of opening and closing a device and transferring data.
- Core layer: binds services, initializes and releases the PlatformManager, and provides the capabilities of adding, deleting, and obtaining controllers.
- Adaptation layer: implements hardware-related functions, such as controller initialization.

**Figure 1** Unified service mode


![image](figures/unified-service-mode.png "I2C Unified Service Mode")

## Usage Guidelines

### When to Use

The I2C is used in communication with the sensors, executors, and input/output devices that support the I2C protocol. Before using I2C devices with OpenHarmony, you need to adapt the I2C driver to OpenHarmony. The following describes how to do it.

### Available APIs

To enable the upper layer to successfully operate the hardware by calling the I2C APIs, hook functions are defined in **//drivers/hdf_core/framework/support/platform/include/i2c/i2c_core.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

**I2cMethod** and **I2cLockMethod**:

```c
struct I2cMethod {
    int32_t (*transfer)(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count);
};

struct I2cLockMethod {// Structure for the lock operation.
    int32_t (*lock)(struct I2cCntlr *cntlr);
    void (*unlock)(struct I2cCntlr *cntlr);
};
```

At the adaptation layer, **I2cMethod** must be implemented, and **I2cLockMethod** can be implemented based on service requirements. The core layer provides the default **I2cLockMethod**, in which a mutex is used to protect the critical section.

```c
static int32_t I2cCntlrLockDefault(struct I2cCntlr *cntlr)
{
    if (cntlr == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalMutexLock(&cntlr->lock);
}

static void I2cCntlrUnlockDefault(struct I2cCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }
    (void)OsalMutexUnlock(&cntlr->lock);
}

static const struct I2cLockMethod g_i2cLockOpsDefault = {
    .lock = I2cCntlrLockDefault,
    .unlock = I2cCntlrUnlockDefault,
};
```

If a mutex cannot be used (for example, an I2C API is called in the interrupt context, which does not allow sleep, but a mutex may cause sleep), you can use another type of lock to implement **I2cLockMethod**. The implemented **I2cLockMethod** will replace the default **I2cLockMethod**.

  **Table 2** Function in **I2cMethod**

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| transfer | **cntlr**: structure pointer to the I2C controller at the core layer.<br>**msgs**: structure pointer to the messages to transfer.<br>**count**: number of messages. The value is of the uint16_t type.| –| HDF_STATUS| Transfers user messages.|

  **Table 2** Functions in **I2cLockMethod**

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| lock | **cntlr**: structure pointer to the I2C controller at the core layer.| –| HDF_STATUS| Acquires the critical section lock.|
| unlock | **cntlr**: structure pointer to the I2C controller at the core layer.| –| HDF_STATUS| Releases the critical section lock.|

### How to Develop

The I2C module adaptation involves the following steps:

1. Instantiate the driver entry.

   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.

   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **i2c_config.hcs** file.

3. Instantiate the I2C controller object.

   - Initialize **I2cCntlr**.
   - Instantiate **I2cMethod** and **I2cLockMethod** in **I2cCntlr**.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify basic functions, for example, check whether data is successfully transferred and the information returned after the virtual file system (VFS) is mounted.

### Example

The following uses the Hi3516D V300 driver **//device/soc/hisilicon/common/platform/i2c/i2c_hi35xx.c** as an example to describe how to perform the I2C driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls **Bind()** and then **Init()** to load a driver. If **Init()** fails to be called, the HDF calls **Release()** to release driver resources and exit.

   I2C driver entry example:

   Multiple devices may connect to the I2C controller. In the HDF, a manager object needs to be created for this type of devices, and a manager service is published to handle external access requests uniformly. When a device needs to be started, the manager service locates the target device based on the specified parameters.

   You do not need to implement the driver of the I2C manager, which is implemented by the core layer. However, the **I2cCntlrAdd** function of the core layer must be invoked in the **Init** function to implement the related features.

    ```c
    struct HdfDriverEntry g_i2cDriverEntry = {
       .moduleVersion = 1,
       .Init = Hi35xxI2cInit,
       .Release = Hi35xxI2cRelease,
       .moduleName = "hi35xx_i2c_driver",        // (Mandatory) The value must be the same as that in the config.hcs file.
    };
    HDF_INIT(g_i2cDriverEntry);                  // Call HDF_INIT to register the driver entry with the HDF.
    
    /* Driver entry of the manager service i2c_core.c at the core layer. */
    struct HdfDriverEntry g_i2cManagerEntry = {
       .moduleVersion = 1,
       .Bind = I2cManagerBind,
       .Init = I2cManagerInit,
       .Release = I2cManagerRelease,
       .moduleName = "HDF_PLATFORM_I2C_MANAGER", // The value must be the same as that of device0 in the device_info.hcs file.
    };
    HDF_INIT(g_i2cManagerEntry);
    ```

2. Add the **deviceNode** information to the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file and configure the device attributes in **i2c_config.hcs**.

   The **deviceNode** information is related to the driver entry registration. The device attribute values are closely related to the driver implementation and the default values or value ranges of the **I2cCntlr** members at the core layer.

   In the unified service mode, the first device node in the **device_info.hcs** file must be the I2C manager. The table below lists the settings of its parameters.

   **Table 3** Settings of the I2C manager
   
   | Parameter| Value|
   | -------- | -------- |
   | moduleName | **HDF_PLATFORM_I2C_MANAGER**|
   | serviceName | **HDF_PLATFORM_I2C_MANAGER**|
   | policy | **1** or **2**, depending on whether the service is published to the user mode.|
   | deviceMatchAttr | This parameter is reserved.|

    Configure I2C controller information from the second node. This node specifies a type of I2C controllers rather than a specific I2C controller. The controllers are distinguished by **busID** and **reg_pbase**, which can be seen in the **i2c_config.hcs** file.

   - **device_info.hcs** example

      ```c
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
                      policy = 0;                                // The value 0 indicates that no service is published.
                      priority = 55;                             // Driver startup priority.
                      permission = 0644;                         // Permission for the device node created.
                      moduleName = "hi35xx_i2c_driver";          // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                      serviceName = "HI35XX_I2C_DRIVER";         // (Mandatory) Unique name of the service published by the driver.
                       deviceMatchAttr = "hisilicon_hi35xx_i2c"; // (Mandatory) Private data of the controller. The value must be the same as the controller information in i2c_config.hcs.
                                                                 //The specific controller information is in i2c_config.hcs.
                  }
              }
          }
      }
      ```

   - **i2c_config.hcs** example

      ```c
      root {
          platform {
              i2c_config {
                  match_attr = "hisilicon_hi35xx_i2c";  // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                  template i2c_controller {             // Template configuration. In the template, you can configure the common parameters shared by service nodes.
                      bus = 0;                          // (Mandatory) I2C identifier.
                      reg_pbase = 0x120b0000;           // (Mandatory) Physical base address.
                      reg_size = 0xd1;                  // (Mandatory) Register bit width.
                      irq = 0;                          // (Optional) Interrupt request (IRQ) number. The interrupt feature of the controller determines whether an IRQ number is required.
                      freq = 400000;                    // (Optional) Frequency used in hardware controller initialization.
                      clk = 50000000;                   // (Optional) Controller clock. The controller clock initialization process determines whether a controller clock is required.
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

      After the **i2c_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      For example, if the path of **i2c_config.hcs** is **device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/i2c/i2c_config.hcs**, add the following statement to **hdf.hcs** of the product:

      ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/i2c/i2c_config.hcs" // Relative path of the file.
      ```

3. Initialize the **I2cCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **I2cMethod** in **I2cCntlr** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **i2c_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the device number and bus number, to the **I2cCntlr** object at the core layer.

      ```c
      /* Custom structure. */
      struct Hi35xxI2cCntlr {
          struct I2cCntlr cntlr;            // (Mandatory) Control object at the core layer. For details, see the following description.
          OsalSpinlock spin;                // (Mandatory) Lock or unlock an I2C operation function.
          volatile unsigned char *regBase;// (Mandatory) Register base address.
          uint16_t regSize;                 // (Mandatory) Register bit width.
          int16_t bus;                      // (Mandatory) The value can be read from the i2c_config.hcs file.
          uint32_t clk;                     // (Optional) Set it as required.
          uint32_t freq;                    // (Optional) Set it as required.
          uint32_t irq;                     // (Optional) Set it as required.
          uint32_t regBasePhy            // (Mandatory) Physical base address of the register.
      };
      
      /* I2cCntlr is the core layer controller structure. The **Init()** function assigns values to the members of I2cCntlr. */
      struct I2cCntlr {
          struct OsalMutex lock;
          void *owner;
          int16_t busId;
          void *priv;
          const struct I2cMethod *ops;
          const struct I2cLockMethod *lockOps;
      };
      ```

   - Instantiate **I2cMethod** and **I2cLockMethod**. Other members are initialized by **Init**.

      ```c
      /* Example in i2c_hi35xx.c */
      static const struct I2cMethod g_method = {
          .transfer = Hi35xxI2cTransfer,
      };
      
      static const struct I2cLockMethod g_lockOps = {
          .lock = Hi35xxI2cLock,     // Acquires the lock.
          .unlock = Hi35xxI2cUnlock, // Release the lock.
      };
      ```

   - Implement the **Init** function.

      Input parameter:

      **HdfDeviceObject**, an interface parameter provided by the driver, contains the .hcs information.

      Return value:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

      **Table 4** HDF_STATUS
      
      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Transmission successful.|
      | HDF_FAILURE | Transmission failed.|

      Function description:

      Initialize the custom structure object and **I2cCntlr**, call **I2cCntlrAdd()** at the core layer, and connect to the VFS (optional).

      ```c
      static int32_t Hi35xxI2cInit(struct HdfDeviceObject *device)
      {
          ...
          /* Traverse and parse all nodes in i2c_config.hcs and call Hi35xxI2cParseAndInit to initialize the devices separately. */
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              ret = Hi35xxI2cParseAndInit(device, childNode);// The function is defined as follows.
          ...
          }
          ...
      }
      
      static int32_t Hi35xxI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
      {
          struct Hi35xxI2cCntlr *hi35xx = NULL;
          ... // Check whether the input parameter is null.
          hi35xx = (struct Hi35xxI2cCntlr *)OsalMemCalloc(sizeof(*hi35xx));   // Allocate memory.
          ... // Verify the return value.
          hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); // Address mapping.
          ... // Verify the return value.
          Hi35xxI2cCntlrInit(hi35xx);         // (Mandatory) Initialize the I2C device.
          
          hi35xx->cntlr.priv = (void *)node;  // (Mandatory) Device attributes.
          hi35xx->cntlr.busId = hi35xx->bus; // (Mandatory) Initialize busId in I2cCntlr.
           hi35xx->cntlr.ops = &g_method;      // (Mandatory) Hook the I2cMethod instance.
           hi35xx->cntlr.lockOps = &g_lockOps; // (Mandatory) Hook the I2cLockMethod instance.
          (void)OsalSpinInit(&hi35xx->spin); // (Mandatory) Initialize the lock.
          ret = I2cCntlrAdd(&hi35xx->cntlr); // (Mandatory) Call this function to add the controller object to the core layer of the platform. The driver can access the core layer of the platform only after a success signal is returned.
          ...
      #ifdef USER_VFS_SUPPORT
          (void)I2cAddVfsById(hi35xx->cntlr.busId);// (Optional) Mount the user-level VFS if required.
      #endif
          return HDF_SUCCESS;
      __ERR__:                                      // If the operation fails, roll back the operations that have been performed in the function (such as unmapping I/O and releasing memory) and return an error code.
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

   - Implement the **Release** function.

      Input parameter:

      **HdfDeviceObject**, an interface parameter provided by the driver, contains the .hcs information.

      Return value:

      No value is returned.

      Function description:

      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

      ```c
      static void Hi35xxI2cRelease(struct HdfDeviceObject *device)
      {
          ...
          /* Release each node separately, like Hi35xxI2cInit. */
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              Hi35xxI2cRemoveByNode(childNode);// The function is defined as follows:
          }
      }
      
      static void Hi35xxI2cRemoveByNode(const struct DeviceResourceNode *node)
      {
          ... 
          /* (Mandatory) Call I2cCntlrGet() to obtain the pointer to the I2cCntlr object based on the bus number of the device, and call I2cCntlrRemove() to remove the I2cCntlr object from the core layer of the platform. */
          cntlr = I2cCntlrGet(bus);
          if (cntlr != NULL && cntlr->priv == node) {
              ...
              I2cCntlrRemove(cntlr); 
              /* (Mandatory) Unmap the register address and release the lock and memory. */
              hi35xx = (struct Hi35xxI2cCntlr *)cntlr; 
              OsalIoUnmap((void *)hi35xx->regBase);
              (void)OsalSpinDestroy(&hi35xx->spin);
              OsalMemFree(hi35xx);
          }
          return;
      }
      ```
