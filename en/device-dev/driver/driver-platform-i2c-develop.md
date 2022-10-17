# I2C


## Overview

The Inter-Integrated Circuit (I2C) bus is a simple and bidirectional two-wire synchronous serial bus developed by Philips. In the Hardware Driver Foundation (HDF), the I2C module uses the unified service mode for API adaptation. In this mode, a device service is used as the I2C manager to handle external access requests in a unified manner, which is reflected in the configuration file. The unified service mode applies to the scenario where there are many device objects of the same type, for example, when the I2C module has more than 10 controllers. If the independent service mode is used, more device nodes need to be configured and memory resources will be consumed by services.

**Figure 1** Unified service mode

  ![image](figures/unified-service-mode.png "I2C Unified Service Mode")


## Available APIs

**I2cMethod** and **I2cLockMethod**


```
struct I2cMethod {
int32_t (*transfer)(struct I2cCntlr *cntlr, struct I2cMsg *msgs, int16_t count);
};
struct I2cLockMethod {// Lock mechanism operation structure
    int32_t (*lock)(struct I2cCntlr *cntlr); // Add a lock.
    void (*unlock)(struct I2cCntlr *cntlr);  // Release the lock.
};
```

  **Table 1** Description of the callback functions in I2cMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| transfer | **cntlr**: structure pointer to the I2C controller at the core layer.<br><br>**msgs**: structure pointer to the messages to transfer.<br>**count**: number of messages. The value is of the uint16_t type.| –| HDF_STATUS| Transfers user messages.|


## How to Develop

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
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
      >
      > For details, see [Available APIs](#available-apis).
   
4. Debug the driver.<br>
   (Optional) For new drivers, verify basic functions, for example, check whether data is successfully transmitted and the information returned after the virtual file system (VFS) is mounted.


## Development Example

The following uses **i2c_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.
   
   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   
   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init()** fails to be called, the HDF calls **Release()** to release driver resources and exit.
   
   I2C driver entry example:
   
   An I2C controller may be connected with multiple devices. You need to create a manager object in the HDF and publish a manager service to handle external access requests in a unified manner. Before a device is used, the manager service must be obtained first. Then, the manager service locates the target device based on the specified parameters.
   
   The driver of the I2C manager is implemented by the core layer. Vendors do not need to care about the implementation of this part. However, the **Init** function must call the **I2cCntlrAdd** function of the core layer to implement corresponding features.
   
   ```
   struct HdfDriverEntry g_i2cDriverEntry = {
       .moduleVersion = 1,
       .Init = Hi35xxI2cInit,
       .Release = Hi35xxI2cRelease,
       .moduleName = "hi35xx_i2c_driver",        // (Mandatory) The value must be the same as that in the config.hcs file.
   };
   HDF_INIT(g_i2cDriverEntry);                   // Call HDF_INIT to register the driver entry with the HDF.
      
   // Driver entry of the i2c_core.c manager service at the core layer
   struct HdfDriverEntry g_i2cManagerEntry = {
       .moduleVersion = 1,
       .Bind = I2cManagerBind,
       .Init = I2cManagerInit,
       .Release = I2cManagerRelease,
       .moduleName = "HDF_PLATFORM_I2C_MANAGER", // This parameter corresponds to device0 in the device_info file.
   };
   HDF_INIT(g_i2cManagerEntry);
   ```
   
      

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **i2c_config.hcs** file. 

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the driver implementation and the default values or value ranges of the **I2cCntlr** members at the core layer.

   In the unified service mode, the first device node in the **device_info** file must be the I2C manager. The table below lists the settings of its parameters.

   **Table 2** Settings of the I2C manager   

   | Parameter| Value|
   | -------- | -------- |
   | moduleName | **HDF_PLATFORM_I2C_MANAGER**|
   | serviceName | **HDF_PLATFORM_I2C_MANAGER**|
   | policy | **1** or **2**, depending on whether the service is published to the user mode.|
   | deviceMatchAttr | Reserved|

   Configure I2C controller information from the second node. This node specifies a type of I2C controllers rather than a specific I2C controller. The controllers are distinguishes by **busID** and **reg_pbase**, which can be seen in the **i2c_config** file.

   - **device_info.hcs** configuration example

     
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
             policy = 0;                               // The value 0 indicates that no service needs to be published.
             priority = 55;                             // Driver startup priority.
             permission = 0644;                         // Permission for the driver to create a device node.
             moduleName = "hi35xx_i2c_driver";          // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
             serviceName = "HI35XX_I2C_DRIVER";         // (Mandatory) Unique name of the service published by the driver.
             deviceMatchAttr = "hisilicon_hi35xx_i2c"; // (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller information in i2c_config.hcs.
                                                        //The specific controller information is stored in i2c_config.hcs.
         }
         }
     }
     }
     ```

   - **i2c_config.hcs** configuration example

     
     ```
     root {
     platform {
         i2c_config {
         match_attr = "hisilicon_hi35xx_i2c";  // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
         template i2c_controller {             // Template configuration. In the template, you can configure the common parameters shared by service nodes.
             bus = 0;                          // (Mandatory) I2C identifier.
             reg_pbase = 0x120b0000;           // (Mandatory) Physical base address.
             reg_size = 0xd1;                  // (Mandatory) Register bit width.
             irq = 0;                          // (Optional) Configured based on your requirements.
             freq = 400000;                    // (Optional) Configured based on your requirements.
             clk = 50000000;                   // (Optional) Configured based on your requirements.
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

3. Initialize the **I2cCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **I2cMethod** in **I2cCntlr** (so that the underlying driver functions can be called).
   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **i2c_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the device number and bus number, to the **I2cCntlr** object at the core layer.

      
      ```
      // Custom structure
      struct Hi35xxI2cCntlr {
          struct I2cCntlr cntlr;            // (Mandatory) Control object at the core layer. For details, see the following description.
          OsalSpinlock spin;                // (Mandatory) You need to implement lock() and unlock() based on this variable.
          volatile unsigned char *regBase;  // (Mandatory) Register base address.
          uint16_t regSize;                 // (Mandatory) Register bit width.
          int16_t bus;                      // (Mandatory) The value can be read from the i2c_config.hcs file.
          uint32_t clk;                     // (Optional) Customized.
          uint32_t freq;                    // (Optional) Customized.
          uint32_t irq;                     // (Optional) Customized.
          uint32_t regBasePhy;              // (Mandatory) Physical base address of the register.
      };
      
      // I2cCntlr is a controller structure at the core layer. The Init function assigns values to the members of I2cCntlr.
      struct I2cCntlr {
          struct OsalMutex lock;
          void *owner;
          int16_t busId;
          void *priv;
          const struct I2cMethod *ops;
          const struct I2cLockMethod *lockOps;
      };
      ```
   - Instantiating **I2cMethod** and **I2cLockMethod** (other members are initialized by **Init**)

     
      ```
      // Example in i2c_hi35xx.c
      static const struct I2cMethod g_method = {
          .transfer = Hi35xxI2cTransfer,
      };
      
      static const struct I2cLockMethod g_lockOps = {
          .lock = Hi35xxI2cLock,     // Lock function
          .unlock = Hi35xxI2cUnlock, // Unlock function
      };
      ```
   - **Init** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

      **Table 3** HDF_STATUS
      
      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Transmission successful.|
      | HDF_FAILURE | Transmission failed.|

      **Function description**:

      Initializes the custom structure object and **I2cCntlr**, calls the **I2cCntlrAdd** function at the core layer, and mounts the VFS (optional).

      
      ```
      static int32_t Hi35xxI2cInit(struct HdfDeviceObject *device)
      {
          ...
          // Traverse and parse all nodes in i2c_config.hcs and call Hi35xxI2cParseAndInit to initialize the devices separately.
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              ret = Hi35xxI2cParseAndInit(device, childNode);// The function is defined as follows.
          ...
          }
          ...
      }
      
      static int32_t Hi35xxI2cParseAndInit(struct HdfDeviceObject *device, const struct DeviceResourceNode *node)
      {
          struct Hi35xxI2cCntlr *hi35xx = NULL;
          ... 
          hi35xx = (struct Hi35xxI2cCntlr *)OsalMemCalloc(sizeof(*hi35xx));   // Allocate memory.
          ... 
          hi35xx->regBase = OsalIoRemap(hi35xx->regBasePhy, hi35xx->regSize); // Address mapping.
          ... 
          Hi35xxI2cCntlrInit(hi35xx);           // (Mandatory) Initialize the I2C device.
          
          hi35xx->cntlr.priv = (void *)node;    // (Mandatory) Device attributes.
          hi35xx->cntlr.busId = hi35xx->bus;    // (Mandatory) Initialize busId in I2cCntlr.
          hi35xx->cntlr.ops = &g_method;       // (Mandatory) Hook the I2cMethod instance.
          hi35xx->cntlr.lockOps = &g_lockOps;  // (Mandatory) Hook the I2cLockMethod instance.
          (void)OsalSpinInit(&hi35xx->spin);    // (Mandatory) Initialize the lock.
          ret = I2cCntlrAdd(&hi35xx->cntlr);  // (Mandatory) Call this function to set the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
          ...
      #ifdef USER_VFS_SUPPORT
          (void)I2cAddVfsById(hi35xx->cntlr.busId);// (Optional) Mount the user-level VFS if required.
      #endif
          return HDF_SUCCESS;
       __ERR__:                                    // If the operation fails, execute the initialization functions reversely.
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
   - **Release** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      No value is returned.

      **Function description**:

      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

      
      ```
      static void Hi35xxI2cRelease(struct HdfDeviceObject *device)
      {
          ...
          // Release each node separately, like Hi35xxI2cInit.
          DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
              Hi35xxI2cRemoveByNode(childNode);// The function is defined as follows:
          }
      }
      
      static void Hi35xxI2cRemoveByNode(const struct DeviceResourceNode *node)
      {
          ... 
          // (Mandatory) Call the I2cCntlrGet function to obtain the I2cCntlr object based on bus ID of the device, and call the I2cCntlrRemove function to release the I2cCntlr object.
          cntlr = I2cCntlrGet(bus);
          if (cntlr != NULL && cntlr->priv == node) {
              ...
              I2cCntlrRemove(cntlr); 
              // (Mandatory) Unmap the addresses and release the lock and memory.
              hi35xx = (struct Hi35xxI2cCntlr *)cntlr; 
              OsalIoUnmap((void *)hi35xx->regBase);
              (void)OsalSpinDestroy(&hi35xx->spin);
              OsalMemFree(hi35xx);
          }
          return;
      }
      ```
