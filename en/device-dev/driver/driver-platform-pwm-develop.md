# PWM

## Overview

### Function

Pulse Width Modulation (PWM) is a technology that performs digital coding on analog signal levels and converts them into pulses. It is widely used in fields, such as measurement, communication, and power control and conversion. The PWM module is used for controlling vibrators and adjusting backlight brightness in smart devices.

### Basic Concepts

A pulse (electrical pulse) is a burst of current or voltage, characterized by sudden change and discontinuity. There are many types of pulses. Common pulses include triangular, sharp, rectangular, square, trapezoidal, and zigzag pulses. Main pulse parameters include the repetition period **T** (**T** = 1/**F**, where **F** is the pulse repetition frequency), pulse amplitude **U**, rise time **ts** at the leading edge, fall time **t** at the trailing edge, and pulse width **tk**.

### Working Principles

In the Hardware Driver Foundation (HDF), the PWM uses the independent service mode (see Figure 1) for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

In the independent service mode, the core layer does not publish a service for the upper layer. Therefore, a service must be published for each controller. To achieve this purpose:

- You need to implement the **Bind()** function in **HdfDriverEntry** to bind services.
- The **policy** field of **deviceNode** in the **device_info.hcs** file can be **1** or **2**, but not **0**.

The PWM module is divided into the following layers:

- Interface layer: provides APIs for opening or closing a PWM device, setting the PWM period, signal ON-state time, PWM device polarity, or PWM device parameters, obtaining PWM device parameters, and enabling or disabling a PWM device
- Core layer: provides the capabilities of adding or removing a PWM controller and managing PWM devices. The core layer interacts with the adaptation layer through hook functions.
- Adaptation layer: instantiates the hook functions to implement specific features.

**Figure 1** Independent service mode

![image](figures/independent-service-mode.png "PWM independent service mode")

## Development Guidelines

### When to Use

Before using your PWM device with OpenHarmony, you need to perform PWM driver adaptation.

### Available APIs

To enable the upper layer to successfully operate the PWM controller by calling the PWM APIs, hook functions are defined in **//drivers/hdf_core/framework/support/platform/include/pwm/pwm_core.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

**PwmMethod**:

```c
struct PwmMethod {
    int32_t (*setConfig)(struct PwmDev *pwm, struct PwmConfig *config);
    int32_t (*open)(struct PwmDev *pwm);
    int32_t (*close)(struct PwmDev *pwm);
};
```

**Table 1** Hook functions in **PwmMethod**

| Function| Input Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- |
| setConfig | **pwm**: structure pointer to the PWM controller at the core layer.<br>**config**: structure pointer to the device attributes to set.| HDF_STATUS| Sets device attributes.|
| open | **pwm**: structure pointer to the PWM controller at the core layer.| HDF_STATUS| Opens a PWM device.|
| close | **pwm**: structure pointer to the PWM controller at the core layer.| HDF_STATUS| Closes a PWM device.|

### How to Develop

The PWM module adaptation procedure is as follows:

1. Instantiate the driver entry.
2. Configure attribute files.
3. Instantiate the PWM controller object.
4. Debug the driver.

### Example

The following uses the **//device_soc_hisilicon/common/platform/pwm/pwm_hi35xx.c** driver of the Hi3516D V300 development board as an example to describe the PWM driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls **Bind()** and then **Init()** to load a driver. If **Init()** fails to be called, the HDF calls **Release()** to release driver resources and exit.

   PWM driver entry example:

   ```c
   struct HdfDriverEntry g_hdfPwm = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_PWM",   // (Mandatory) The value must be the same as that of moduleName in the .hcs file.
       .Bind = HdfPwmBind,                  // See the Bind function.
       .Init = HdfPwmInit,                  // See the Init function.
       .Release = HdfPwmRelease,            // See the Release function.
   };
   HDF_INIT(g_hdfPwm);                      // Call HDF_INIT to register the driver entry with the HDF.
   ```

2. Configure attribute files.

   Add the deviceNode information to the **device_info.hcs** file. The deviceNode information is related to the driver entry registration. The following example uses two PWM controllers as an example. If there are more PWM controllers, add the deviceNode information to the **device_info.hcs** file for each controller. The device attribute values configured in **pwm_config.hcs** are closely related to default values or value ranges of the **PwmDev** members at the core layer.

   - **device_info.hcs** example

      Add the deviceNode information to the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file.

      ```c
      root {
          device_info { 
              platform :: host {
                  hostName = "platform_host";
                  priority = 50;
                  device_pwm ::device {                               // Configure an HDF device node for each PWM controller.
                      device0 :: deviceNode {
                          policy = 1;                                 // The value 1 means to publish services only to the kernel-mode processes.
                          priority = 80;                              // Driver startup priority.
                          permission = 0644;                          // Permission for the device node created.
                          moduleName = "HDF_PLATFORM_PWM";            // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                          serviceName = "HDF_PLATFORM_PWM_0";         // (Mandatory) Unique name of the service published by the driver.
                          deviceMatchAttr = "hisilicon_hi35xx_pwm_0"; // Controller private data, which must be the same as that of the controller in pwm_config.hcs.
                      }
                      device1 :: deviceNode {
                          policy = 1;
                          priority = 80;
                          permission = 0644;
                          moduleName = "HDF_PLATFORM_PWM";
                          serviceName = "HDF_PLATFORM_PWM_1";
                          deviceMatchAttr = "hisilicon_hi35xx_pwm_1";
                      }
                      ...
                  }
              }
          }
      }
      ```

   - **pwm_config.hcs** example

      Configure the device attributes in the **//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pwm/pwm_config.hcs** file. The parameters are as follows:

      ```c
      root {
          platform {
              pwm_config {
                  template pwm_device {                       // (Mandatory) Template configuration. If the template is used to configure device node information, the default values in the template will be used for the fields that are not declared for the node.
                      serviceName = "";
                      match_attr = "";
                      num = 0;                                // (Mandatory) Device number.
                      base = 0x12070000;                      // (Mandatory) Base address used for address mapping.
                  }
                  device_0x12070000 :: pwm_device {           // Add the HDF node and device node information for each device.
                      match_attr = "hisilicon_hi35xx_pwm_0";  // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                  }
                  device_0x12070020 :: pwm_device {
                      match_attr = "hisilicon_hi35xx_pwm_1";
                      num = 1;
                      base = 0x12070020;                      // (Mandatory) Base address used for address mapping.
                  }
              }
          }
      }
      ```

      After the **pwm_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/pwm/pwm_config.hcs" // Relative path of the file.
      ```

3. Instantiate the PWM controller object.

   Initialize the **PwmDev** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **PwmMethod** in **PwmDev** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **pwm_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the PWM device number, to the object at the core layer.

      ```c
      struct HiPwm {
          struct PwmDev dev;                // (Mandatory) Control object at the core layer.
          volatile unsigned char *base;     // (Mandatory) Register base address used for address mapping.
          struct HiPwmRegs *reg;            // Device attribute structure, which can be customized.
          bool supportPolarity;             // Whether polarity is supported.
      };

      struct PwmDev {                       // PwmDev is the core layer controller structure. The Bind function assigns values to the members of PwmDev.
          struct IDeviceIoService service;  // Driver service.
          struct HdfDeviceObject *device;   // Driver device object.
          struct PwmConfig cfg;             // Device attribute structure. For details, see the following definition.
          struct PwmMethod *method;         // Hook functions.
          bool busy;                        // Whether the device is busy.
          uint32_t num;                     // Device number.
          OsalSpinlock lock;                // Spinlock.
          void *priv;                       // Private data.
      };

      struct PwmConfig {                    // PWM device attributes.
          uint32_t duty;                    // Time that a signal is in the ON state, in ns.
          uint32_t period;                  // Time for a signal to complete an on-and-off cycle, in ns.
          uint32_t number;                  // Number of square waves to generate.
          uint8_t polarity;                 // Polarity
                                            // ------------------- | --------------
                                            // PWM_NORMAL_POLARITY | Normal polarity
                                            // PWM_INVERTED_POLARITY | Inverted polarity
                                            //
          uint8_t status;                   // Running status.
                                            // ------------------ | -----------------
                                            // PWM_DISABLE_STATUS | Disabled
                                            // PWM_ENABLE_STATUS  | Enabled
      };
      ```

   - Instantiate the **PwmMethod** structure in **PwmDev**.

      ```c
      struct PwmMethod g_pwmOps = {         // Instantiate the hook functions in pwm_hi35xx.c.
          .setConfig = HiPwmSetConfig,      // Set device attributes.
      };
      ```

   - Implement the **Init** function.

      **Input parameter**:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      **Function description**:

      Initializes the custom structure object and **PwmDev** members, and calls **PwmDeviceAdd()** to add the PWM controller to the core layer.

      ```c
      // In this example, Bind() is an empty function. You can add operations as required or implement related features in Init().
      static int32_t HdfPwmBind(struct HdfDeviceObject *obj)
      {
          (void)obj;
          return HDF_SUCCESS;
      }

      static int32_t HdfPwmInit(struct HdfDeviceObject *obj)
      {
          int ret;
          struct HiPwm *hp = NULL;
          ...
          hp = (struct HiPwm *)OsalMemCalloc(sizeof(*hp));
          ...
          ret = HiPwmProbe(hp, obj);                                 // (Mandatory) The implementation is as follows.
          ...
          return ret;
      }

      static int32_t HiPwmProbe(struct HiPwm *hp, struct HdfDeviceObject *obj)
      {
          uint32_t tmp;
          struct DeviceResourceIface *iface = NULL;
      
          iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); // Initialize the custom structure HiPwm.
          ...
          
          hp->reg = (struct HiPwmRegs *)hp->base;                    // Initialize the custom structure HiPwm.
          hp->supportPolarity = false;                               // Initialize the custom structure HiPwm.
          hp->dev.method = &g_pwmOps;                                // Attach the PwmMethod instance.
          hp->dev.cfg.duty = PWM_DEFAULT_DUTY_CYCLE;                 // Initialize PwmDev.
          hp->dev.cfg.period = PWM_DEFAULT_PERIOD;                   // Initialize PwmDev.
          hp->dev.cfg.polarity = PWM_DEFAULT_POLARITY;               // Initialize PwmDev.
          hp->dev.cfg.status = PWM_DISABLE_STATUS;                   // Initialize PwmDev.
          hp->dev.cfg.number = 0;                                    // Initialize PwmDev.
          hp->dev.busy = false;                                      // Initialize PwmDev.
          if (PwmDeviceAdd(obj, &(hp->dev)) ) != HDF_SUCCESS) {      // Call the core layer function to initialize devices and services.
              OsalIoUnmap((void *)hp->base);
              return HDF_FAILURE;
          }
          return HDF_SUCCESS;
      }
      ```

   - Implement the **Release** function.

      **Input parameter**:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      **Return value**:

      No value is returned.

      **Function description**:

      Releases the memory and deletes the controller. This function assigns values to **Release()** in the driver entry structure. If the HDF fails to call **Init()** to initialize the driver, **Release()** is called to release driver resources.

      ```c
      static void HdfPwmRelease(struct HdfDeviceObject *obj)
      {
          struct HiPwm *hp = NULL;
          ...
          hp = (struct HiPwm *)obj->service;        // A forced conversion from HdfDeviceObject to HiPwm is involved.
          ...                                       
          PwmDeviceRemove(obj, &(hp->dev));         // (Mandatory) Call the core layer functions to release PwmDev devices and services. A forced conversion from HiPwm to PwmDev is involved in the process.
          HiPwmRemove(hp);                          // Release HiPwm.
      }
      ```

4. Debug the driver.

    (Optional) For new drivers, verify the basic functions, such as the PWM status control and response to interrupts.
