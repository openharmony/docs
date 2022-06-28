# PWM


## Overview

In the Hardware Driver Foundation (HDF), the Pulse Width Modulator (PWM) uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png "PWM independent service mode")


## Available APIs

**PwmMethod**:

  
```
struct PwmMethod {
  int32_t (*setConfig)(struct PwmDev *pwm, struct PwmConfig *config);
  int32_t (*open)(struct PwmDev *pwm);
  int32_t (*close)(struct PwmDev *pwm);
};
```

  **Table 1** Description of callback functions in PwmMethod

| Function| Input Parameter| Return Value| Description| 
| -------- | -------- | -------- | -------- |
| setConfig | -**pwm**: structure pointer to the PWM controller at the core layer.<br>-**config**: structure pointer to the attributes to set.| HDF_STATUS| Sets attributes.| 
| open | **pwm**: structure pointer to the PWM controller at the core layer.| HDF_STATUS| Opens a device.| 
| close | **pwm**: structure pointer to the PWM controller at the core layer.| HDF_STATUS| Closes a device.| 


## How to Develop

The PWM module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** description to the **device_info.hcs** file.
   - (Optional) Add the **pwm_config.hcs** file.

3. Instantiate the PWM controller object.
   - Initialize **PwmDev**.
   - Instantiate **PwmMethod** in the **PwmDev** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
      > For details about the functions in **PwmMethod**, see [Available APIs](#available-apis).

4. Debug the driver.
   (Optional) For new drivers, verify the basic functions, such as the PWM status control and response to interrupts.


## Development Example

The following uses **pwm_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.<br/>The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

     PWM driver entry example:
     
   ```
   struct HdfDriverEntry g_hdfPwm = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_PWM",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
       .Bind = HdfPwmBind,
       .Init = HdfPwmInit,
       .Release = HdfPwmRelease,
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_hdfPwm);
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **pwm_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **PwmDev** members at the core layer. If there are multiple devices, you need to add the **deviceNode** information to the **device_info** file and add the device attributes to the **pwm_config** file for each device.
   - **device_info.hcs** configuration example

        
      ```
      root {
        device_info { 
          platform :: host {
            hostName = "platform_host";
            priority = 50;
            device_pwm :: device {// Configure an HDF device node for each PWM controller.
              device0 :: deviceNode {
                policy = 1;      // Publish kernel-mode services.
                priority = 80;  // Driver startup priority
                permission = 0644; // Permission to create device nodes for the driver.
                moduleName = "HDF_PLATFORM_PWM";   // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
                serviceName = "HDF_PLATFORM_PWM_0";   // (Mandatory) Unique name of the service published by the driver.
                deviceMatchAttr = "hisilicon_hi35xx_pwm_0";// (Mandatory) Used to configure the private data of the controller.
                                                           // The value must be the same as the controller information in pwm_config.hcs.
              }
              device1 :: deviceNode {
                policy = 1;
                priority = 80;
                permission = 0644;
                moduleName = "HDF_PLATFORM_PWM";
                serviceName = "HDF_PLATFORM_PWM_1";
                deviceMatchAttr = "hisilicon_hi35xx_pwm_1";
              }
            }
          }
        }
      }
      ```
   - **pwm_config.hcs** configuration example

        
      ```
      root {
        platform {
          pwm_config {
            template pwm_device {                   // (Mandatory) Template configuration. In the template, you can configure the common parameters shared by service nodes.
              serviceName = "";
              match_attr = "";
              num = 0;                              // (Mandatory) Device number
              base = 0x12070000;                    // (Mandatory) Used for address mapping
            }
            device_0x12070000 :: pwm_device {       // Add the HDF node and device node information for each device.
              match_attr = "hisilicon_hi35xx_pwm_0";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
            }
            device_0x12070020 :: pwm_device {      
              match_attr = "hisilicon_hi35xx_pwm_1";
              num = 1;
              base = 0x12070020;                    // (Mandatory) Used for address mapping
            }
          }
        }
      }
      ```

3. Initialize the **PwmDev** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **PwmMethod** in **PwmDev** (so that the underlying driver functions can be called).
   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **pwm_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the device number, to the **GpioCntlr** object at the core layer.

        
      ```
      struct HiPwm {
          struct PwmDev dev;          // (Mandatory) Core layer structure
          volatile unsigned char *base;
          struct HiPwmRegs *reg;      // Device attribute structure, which can be customized.
          bool supportPolarity;
      };
      
      // PwmDev is the controller structure at the core layer. The Init function assigns values to the members of PwmDev.
      struct PwmDev {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          struct PwmConfig cfg;       // Attribute structure. For details, see the description of PwmConfig.
          struct PwmMethod *method; // Hook function template
          bool busy;
          uint32_t num;               // Device number
          OsalSpinlock lock;
          void *priv;               // Private data. Generally, the start address of the custom structure is stored to facilitate invoking of the structure.
      };
      struct PwmConfig {
          uint32_t duty              // Time that a signal is in the ON state, in ns.
          uint32_t period;            // Time for a signal to complete an on-and-off cycle, in ns.
          uint32_t number;            // Number of square waves to generate.
          uint8_t polarity;           // Polarity 
                                      // ------------------- | --------------
                                      // PWM_NORMAL_POLARITY | Normal polarity
                                      // PWM_INVERTED_POLARITY | Inverted polarity
                                      //
          uint8_t status;    // Running status
                                      // ------------------ | -----------------
                                      // PWM_DISABLE_STATUS | Disabled
                                      // PWM_ENABLE_STATUS  | Enabled
      };
      ```

   - Instantiating **PwmMethod** in **PwmDev** (other members are initialized by **Init**)

        
      ```
      // The following uses pwm_hi35xx.c as an example. Fill the hook function.
      struct PwmMethod g_pwmOps = {
          .setConfig = HiPwmSetConfig,// Set attributes.
      };
      ```
   - **Init** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      HDF_STATUS<br>The table below lists some status. For more information, see HDF_STATUS in the /drivers/framework/include/utils/hdf_base.h file.

        | Status| Description| 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.| 
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.| 
      | HDF_ERR_INVALID_PARAM | Invalid parameter.| 
      | HDF_ERR_IO | I/O error.| 
      | HDF_SUCCESS | Initialization successful.| 
      | HDF_FAILURE | Initialization failed.| 

      **Function description**:

      Initializes the custom structure object and **PwmDev**, and calls the **PwmDeviceAdd** function at the core layer.

        
      ```
      // The bind function is empty. It can be combined with the init function or implement related operations based on the vendor's requirements.
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
        ret = HiPwmProbe(hp, obj); // (Mandatory) The implementation is as follows:
        ...
        return ret;
      }
      
      static int32_t HiPwmProbe(struct HiPwm *hp, struct HdfDeviceObject *obj)
      {
          uint32_t tmp;
          struct DeviceResourceIface *iface = NULL;
      
          iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE);// Initialize the custom structure HiPwm.
          ...
          
          hp->reg = (struct HiPwmRegs *)hp->base;       // Initialize the custom structure HiPwm.
          hp->supportPolarity = false;                    // Initialize the custom structure HiPwm.
          hp->dev.method = &g_pwmOps;                    // Attach the PwmMethod instance.
          hp->dev.cfg.duty = PWM_DEFAULT_DUTY_CYCLE;     // Initialize PwmDev.
          hp->dev.cfg.period = PWM_DEFAULT_PERIOD;       // Initialize PwmDev.
          hp->dev.cfg.polarity = PWM_DEFAULT_POLARITY;   // Initialize PwmDev.
          hp->dev.cfg.status = PWM_DISABLE_STATUS;       // Initialize PwmDev.
          hp->dev.cfg.number = 0;                        // Initialize PwmDev.
          hp->dev.busy = false;                          // Initialize PwmDev.
          if (PwmDeviceAdd(obj, &(hp->dev)) ) != HDF_SUCCESS) {// (Important) Call the core layer function to initialize hp->dev devices and services.
              OsalIoUnmap((void *)hp->base);
              return HDF_FAILURE;
          }
          return HDF_SUCCESS;
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
      static void HdfPwmRelease(struct HdfDeviceObject *obj)
      {
          struct HiPwm *hp = NULL;
          ...
          hp = (struct HiPwm *)obj->service;// A forced conversion from HdfDeviceObject to HiPwm is involved.
          ...
          PwmDeviceRemove(obj, &(hp->dev));// (Mandatory) Call the core layer functions to release PwmDev devices and services. A forced conversion from HiPwm to PwmDev is involved in the process.
          HiPwmRemove(hp);                 // Release HiPwm.
      }
      ```
