# Clock

## Overview

### Function

The clock regulates the timing and speed of all functions in a device. For example, the CPU clock is an internal time generator of the CPU. It operates in frequency and used to synchronize and control the operations within the CPU.

### Basic Concepts

The clock signal is used to synchronize and control the operations of the modules or components of an electronic device. It serves as a fundamental signal reference source to ensure proper functioning and accurate data transmission.

### Working Principles

In the Hardware Driver Foundation (HDF), the **Clock** module uses the unified service mode for API adaptation. In this mode, a service is used as the clock manager to handle external access requests in a unified manner. The unified service mode applies when the system has multiple device objects of the same type. If the independent service mode is used in this case, more device nodes need to be configured and more memory resources will be consumed. The **Clock** module uses the unified service mode (see **Figure 1**).

The **Clock** module is divided into the following layers:
- Interface layer: provides the APIs for opening a device, writing data, and closing a device.
- Core layer: binds services, initializes and releases the PlatformManager, and provides the capabilities of adding, deleting, and obtaining controllers.
- Adaptation layer: implements hardware-related functions, such as controller initialization.

In the unified service mode, the core layer manages all controllers in a unified manner and publishes a service for the interface layer. That is, the driver does not need to publish a service for each controller.

**Figure 1** Unified service mode

![](figures/unified-service-mode.png "CLOCK Unified Service Mode")


## Usage Guidelines

### When to Use

The **Clock** module provides chip-level clock management, including frequency division, frequency multiplication, clock source selection, and clock gating within the chip. Proper clock management can enhance chip efficiency while streamlining coordination and synergy among all functional components.

### Available APIs

To enable applications to successfully operate the hardware by calling the **Clock** APIs, the system provides the following hook APIs in **//drivers/hdf_core/framework/support/platform/include/clock/clock_core.h** for the core layer. You need to implement these hook APIs at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

Definitions of  **ClockMethod** and **ClockLockMethod**:

```c
struct ClockMethod {
    int32_t (*start)(struct ClockDevice *device);
    int32_t (*stop)(struct ClockDevice *device);
    int32_t (*setRate)(struct ClockDevice *device, uint32_t rate);
    int32_t (*getRate)(struct ClockDevice *device, uint32_t *rate);
    int32_t (*disable)(struct ClockDevice *device);
    int32_t (*enable)(struct ClockDevice *device);
    struct ClockDevice *(*getParent)(struct ClockDevice *device);
    int32_t (*setParent)(struct ClockDevice *device, struct ClockDevice *parent);
};

struct ClockLockMethod {
    int32_t (*lock)(struct ClockDevice *device);
    void (*unlock)(struct ClockDevice *device);
};

```

The **ClockMethod** method must be implemented at the adaptation layer, and **ClockLockMethod** can be implemented based on service requirements. The core layer provides the default **ClockLockMethod** method, in which a spinlock is used to protect the critical section.

```c
static int32_t ClockDeviceLockDefault(struct ClockDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("ClockDeviceLockDefault: device is null!");
        return HDF_ERR_INVALID_OBJECT;
    }
    return OsalSpinLock(&device->spin);
}

static void ClockDeviceUnlockDefault(struct ClockDevice *device)
{
    if (device == NULL) {
        HDF_LOGE("ClockDeviceUnlockDefault: device is null!");
        return;
    }
    (void)OsalSpinUnlock(&device->spin);
}

static const struct ClockLockMethod g_clockLockOpsDefault = {
    .lock = ClockDeviceLockDefault,
    .unlock = ClockDeviceUnlockDefault,
};

```

If spinlock cannot be used, you can use another type of lock to implement **ClockLockMethod**. The customized **ClockLockMethod** method will replace the default **ClockLockMethod** method.

  **Table 1** Hook APIs in **ClockMethod**

| API | Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| start | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Starts a clock device. |
| stop | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Stops a clock device. |
| setRate | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Sets the clock rate. |
| getRate | **device**: structure pointer to the clock controller at the core layer.| Clock rate obtained. | HDF_STATUS | Obtains the clock rate. |
| disable | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Enables clock. |
| enable | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Disables clock. |
| getParent | **device**: structure pointer to the clock controller at the core layer.| Structure pointer to the clock controller obtained. | HDF_STATUS | Obtains the parent clock. |
| setParent | **device**: structure pointer to the clock controller at the core layer.| –| HDF_STATUS | Sets the parent clock. |

**Table 2** APIs in **ClockLockMethod**

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| lock | **device**: structure pointer to the clock device object at the core layer.| –| HDF_STATUS| Acquires the critical section lock. |
| unlock | **device**: structure pointer to the clock device object at the core layer.| –| HDF_STATUS| Releases the critical section lock.|

### How to Develop

The **Clock** module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **clock_config.hcs** file.

3. Instantiate the core layer APIs.
   - Initialize **ClockDevice**.
   - Instantiate **ClockMethod** in the **ClockDevice** object.
      > **NOTE**
      >
      > For details about the functions in **ClockMethod**, see [Available APIs](#available-apis).

4. (Optional) Debug the driver.

   Verify the basic driver functionalities.


### Example

The following uses the RK3568 driver **//drivers/hdf_core/adapter/khdf/linux/platform/clock/clock_adapter.c** as an example to describe how to perform the clock driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **//drivers/hdf_core/interfaces/inner_api/host/shared/hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   Clock driver entry example:

   Multiple devices may connect to the clock controller. In the HDF, a manager object needs to be created for this type of devices. When a device needs to be started, the manager object locates the target device based on the specified parameters.

   You do not need to implement the driver of the clock manager, which is implemented by the core layer. However, the **ClockDeviceAdd** method of the core layer must be invoked in the **Init** method to implement the related features.

    ```c
    struct HdfDriverEntry g_clockLinuxDriverEntry = {
        .moduleVersion = 1,
        .Bind = NULL,
        .Init = LinuxClockInit,
        .Release = LinuxClockRelease,
        .moduleName = "linux_clock_adapter",      // (Mandatory) The value must be the same as the module name in the device_info.hcs file.
    };
    HDF_INIT(g_clockLinuxDriverEntry);            // Call HDF_INIT to register the driver entry with the HDF.

    /* Driver entry of the clock_core.c manager service at the core layer */
    struct HdfDriverEntry g_clockManagerEntry = {
        .moduleVersion = 1,
        .Bind = ClockManagerBind,                     
        .Init = ClockManagerInit,                     
        .Release = ClockManagerRelease,               
        .moduleName = "HDF_PLATFORM_CLOCK_MANAGER",   // The value must be that of device0 in the device_info.hcs file.
    };
    HDF_INIT(g_clockManagerEntry);
    ```

2. Add the **deviceNode** information to the **//vendor/hihope/rk3568/hdf_config/khdf/device_info/device_info.hcs** file and configure the device attributes in **clock_config.hcs**.

   The **deviceNode** information is related to the driver entry registration. The device attribute values are closely related to the driver implementation and the default values or value ranges of the **ClockDevice** members at the core layer.

   In the unified service mode, the first device node in the **device_info.hcs** file must be the clock manager. The parameters must be set as follows:

   | Parameter| Value|
   | -------- | -------- |
   | policy | Service publishing policy. For the clock controller, it is **2**, which means to publish services for both kernel- and user-mode processes. |
   | priority | Loading priority of the cloud driver. The value range is 0 to 200. A larger value indicates a lower priority.<br/>It is set to **59** for the clock controller. |
   | permission | Permission for the device node created. It is **0664** for the clock controller. |
   | moduleName | **HDF_PLATFORM_CLOCK_MANAGER**. |
   | serviceName | **HDF_PLATFORM_CLOCK_MANAGER**. |
   | deviceMatchAttr | Reserved.|

   Configure clock controller information from the second node. This node specifies a type of clock controllers rather than a clock controller. In this example, there is only one clock device. If there are multiple clock devices, add the **deviceNode** information to the **device_info.hcs** file and add the corresponding device attributes to the **clock_config** file for each device.

   - **device_info.hcs** example

        ```
        root {
            device_info {
                platform :: host {
                    device_clock :: device {
                        device0 :: deviceNode {
                            policy = 2;
                            priority = 59;
                            permission = 0644;
                            moduleName = "HDF_PLATFORM_CLOCK_MANAGER";
                            serviceName = "HDF_PLATFORM_CLOCK_MANAGER";
                        }
                        device1 :: deviceNode {
                            policy = 0;                                 // The value 0 indicates that no service is published.
                            priority = 65;                              // Driver startup priority.
                            permission = 0644;                          // Permission for the device node created.
                            moduleName = "linux_clock_adapter";         // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                            deviceMatchAttr = "linux_clock_adapter_0";  // (Mandatory) Private data of the controller. The value must be the same as that of the controller
                        }
                    }
                }
            }
        }
        ```

    - **clock_config.hcs** example

      The following uses RK3568 as an example. 

        ```
        root {
            platform {
                clock_config {
                    match_attr = "linux_clock_adapter_0";
                    template clock_device {
                    }
                    device_clock_0x0000 :: clock_device {
                        deviceName = "/cpus/cpu@0";
                        deviceIndex = 1;
                    }
                }
            }
        }
        ```

      After the **clock_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.
      
      For example, if the **clock_config.hcs** file is in **//vendor/hihope/rk3568/hdf_config/hdf_config/khdf/hdf.hcs**, add the following statement to **hdf.hcs** of the product:

        ```
        #include "platform/clock_config_linux.hcs" //  Relative path of the configuration file
        ```

      This example is based on RK3568 development board that runs the Standard system. The **hdf.hcs** file is in **//vendor/hihope/rk3568/hdf_config/ hdf_config/khdf/**. You can modify the file as required.

3. Initialize the **ClockDevice** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **ClocMethod** in **ClocDevice** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The DeviceResourceIface() function provided by the HDF reads **clock_config.hcs** to initialize the custom structure and passes some important parameters, such as the device number and bus number, to the **ClockDevice** object at the core layer.
        ```c
      /* ClockDevice is the core layer controller structure. The **Init()** function assigns values to the members of ClockDevice. */
        struct ClockDevice {
            const struct ClockMethod *ops;
            OsalSpinlock spin;
            const char *deviceName;
            const char *clockName;
            uint32_t deviceIndex;
            const struct ClockLockMethod *lockOps;
            void *clk;
            void *priv;
            struct ClockDevice *parent;
        };
        ```
      
- Instantiate the hook function structure **ClockMethod** of **ClockDevice**.
   
   The **ClockLockMethod** is not implemented in this example. To instantiate the structure, refer to the I2C driver development. Other members are initialized in the **Init** function.
   
        ```c
        struct ClockMethod {
            int32_t (*start)(struct ClockDevice *device);
            int32_t (*stop)(struct ClockDevice *device);
            int32_t (*setRate)(struct ClockDevice *device, uint32_t rate);
            int32_t (*getRate)(struct ClockDevice *device, uint32_t *rate);
            int32_t (*disable)(struct ClockDevice *device);
            int32_t (*enable)(struct ClockDevice *device);
            struct ClockDevice *(*getParent)(struct ClockDevice *device);
            int32_t (*setParent)(struct ClockDevice *device, struct ClockDevice *parent);
        };
     ```
   
   - Implement the **Init** function.
     
      Input parameter:
      
      **HdfDeviceObject**, an interface parameter provided by the driver, contains the .hcs information.
      
      Return value:
      
   **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/interfaces/inner_api/utils/hdf_base.h** file.
   
        **Table 4** HDF_STATUS

        | Value | Description |
        | -------- | -------- |
        | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
        | HDF_ERR_INVALID_PARAM | Invalid parameter.|
        | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
        | HDF_ERR_IO | I/O error.|
        | HDF_SUCCESS | Transmission successful.|
        | HDF_FAILURE | Transmission failed.|
   
   Function description:
   
      Initializes the custom structure object and **ClockDevice**, and calls the **ClockDeviceAdd** function at the core layer.
      
      ```c
        static int32_t LinuxClockInit(struct HdfDeviceObject *device)
          {
              int32_t ret = HDF_SUCCESS;
              struct DeviceResourceNode *childNode = NULL;
      
              if (device == NULL || device->property == NULL) {
                  HDF_LOGE("LinuxClockInit: device or property is null");
                  return HDF_ERR_INVALID_OBJECT;
              }
      
              DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                  ret = ClockParseAndDeviceAdd(device, childNode);
                  if (ret != HDF_SUCCESS) {
                      HDF_LOGE("LinuxClockInit: clock init fail!");
                      return ret;
                  }
              }
              HDF_LOGE("LinuxClockInit: clock init success!");
      
              return HDF_SUCCESS;
          }
      
          static int32_t ClockParseAndDeviceAdd(struct HdfDeviceObject *device, struct DeviceResourceNode *node)
          {
              int32_t ret;
              struct ClockDevice *clockDevice = NULL;
      
              (void)device;
              clockDevice = (struct ClockDevice *)OsalMemCalloc(sizeof(*clockDevice));
              if (clockDevice == NULL) {
                  HDF_LOGE("ClockParseAndDeviceAdd: alloc clockDevice fail!");
                  return HDF_ERR_MALLOC_FAIL;
              }
              ret = ClockReadDrs(clockDevice, node);
              if (ret != HDF_SUCCESS) {
                  HDF_LOGE("ClockParseAndDeviceAdd: read drs fail, ret: %d!", ret);
                  OsalMemFree(clockDevice);
                  return ret;
              }
      
              clockDevice->priv = (void *)node;
              clockDevice->ops = &g_method;
      
              ret = ClockDeviceAdd(clockDevice);
              if (ret != HDF_SUCCESS) {
                  HDF_LOGE("ClockParseAndDeviceAdd: add clock device:%u fail!", clockDevice->deviceIndex);
                  OsalMemFree(clockDevice);
                  return ret;
              }
      
              return HDF_SUCCESS;
          }
      
          static int32_t ClockReadDrs(struct ClockDevice *clockDevice, const struct DeviceResourceNode *node)
          {
              int32_t ret;
              struct DeviceResourceIface *drsOps = NULL;
      
              drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
              if (drsOps == NULL || drsOps->GetUint32 == NULL || drsOps->GetString == NULL) {
                  HDF_LOGE("ClockReadDrs: invalid drs ops!");
                  return HDF_ERR_NOT_SUPPORT;
              }
              ret = drsOps->GetUint32(node, "deviceIndex", &clockDevice->deviceIndex, 0);
              if (ret != HDF_SUCCESS) {
                  HDF_LOGE("ClockReadDrs: read deviceIndex fail, ret: %d!", ret);
                  return ret;
              }
      
              drsOps->GetString(node, "clockName", &clockDevice->clockName, 0);
      
              ret = drsOps->GetString(node, "deviceName", &clockDevice->deviceName, 0);
              if (ret != HDF_SUCCESS) {
                  HDF_LOGE("ClockReadDrs: read deviceName fail, ret: %d!", ret);
                  return ret;
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

        ```c
        static void LinuxClockRelease(struct HdfDeviceObject *device)
        {
            const struct DeviceResourceNode *childNode = NULL;
            if (device == NULL || device->property == NULL) {
                HDF_LOGE("LinuxClockRelease: device or property is null!");
                return;
            }
            DEV_RES_NODE_FOR_EACH_CHILD_NODE(device->property, childNode) {
                ClockRemoveByNode(childNode);
            }
        }

        static void ClockRemoveByNode(const struct DeviceResourceNode *node)
        {
            int32_t ret;
            int32_t deviceIndex;
            struct ClockDevice *device = NULL;
            struct DeviceResourceIface *drsOps = NULL;

            drsOps = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);
            if (drsOps == NULL || drsOps->GetUint32 == NULL) {
                HDF_LOGE("ClockRemoveByNode: invalid drs ops!");
                return;
            }

            ret = drsOps->GetUint32(node, "deviceIndex", (uint32_t *)&deviceIndex, 0);
            if (ret != HDF_SUCCESS) {
                HDF_LOGE("ClockRemoveByNode: read deviceIndex fail, ret: %d!", ret);
                return;
            }

            device = ClockDeviceGet(deviceIndex);
            if (device != NULL && device->priv == node) {
                ret = ClockStop(device);
                if (ret != HDF_SUCCESS) {
                    HDF_LOGE("ClockRemoveByNode: close fail, ret: %d!", ret);
                }
                if (device->parent  && device->parent->deviceName == NULL) {
                    ClockDeviceRemove(device->parent);
                    OsalMemFree(device->parent);
                }
                ClockDeviceRemove(device);
                OsalMemFree(device);
            }
        }
        ```
4. (Optional) Debug the driver.
    Verify the basic driver functionalities.
