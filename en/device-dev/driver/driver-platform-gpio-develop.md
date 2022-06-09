# GPIO


## Overview

In the Hardware Driver Foundation (HDF), the general-purpose input/output (GPIO) module uses the service-free mode for API adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the operating system (OS) that does not distinguish the user mode and the kernel mode. In the service-free mode, **DevHandle** (a void pointer) directly points to the kernel-mode address of the device object.

  **Figure 1** Service-free mode

  ![](figures/service-free-mode.png "service-free-mode")


## Available APIs

**GpioMethod**:


```
struct GpioMethod {
  int32_t (*request)(struct GpioCntlr *cntlr, uint16_t local);// Reserved
  int32_t (*release)(struct GpioCntlr *cntlr, uint16_t local);// Reserved
  int32_t (*write)(struct GpioCntlr *cntlr, uint16_t local, uint16_t val);
  int32_t (*read)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *val);
  int32_t (*setDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t dir);
  int32_t (*getDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *dir);
  int32_t (*toIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *irq);// Reserved
  int32_t (*setIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t mode, GpioIrqFunc func, void *arg);
  int32_t (*unsetIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*enableIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*disableIrq)(struct GpioCntlr *cntlr, uint16_t local);
}
```

  **Table 1** Description of the callback functions in GpioMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| write | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type.<br>**val**: input level, which is of the uint16_t type. | – | HDF_STATUS| Writes the level of a GPIO pin.|
| read | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type. | **val**: pointer to the output level, which is of the uint16_t type.| HDF_STATUS| Reads the level of a GPIO pin.|
| setDir | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type.<br>**dir**: pin direction to set, which is of the uint16_t type. | – | HDF_STATUS| Sets the direction (input or output) for a GPIO pin.|
| getDir | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type. | **dir**: pointer to the pin direction obtained, which is of the uint16_t type.| HDF_STATUS| Obtains the input or output direction of a GPIO pin.|
| setIrq | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type.<br>**mode**: trigger mode, which can be edge or level of the uint16_t type. <br>**func**: pointer to the interrupt request (IRQ) handler.<br>**arg**: void pointer to the input parameters of the IRQ handler. | – | HDF_STATUS| Sets an IRQ for a GPIO pin.|
| unsetIrq | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type. | – | HDF_STATUS| Cancels the IRQ settings for a GPIO pin.|
| enableIrq | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type. | – | HDF_STATUS| Enables interrupts for a GPIO pin.|
| disableIrq | **cntlr**: structure pointer to the GPIO controller at the core layer.<br>**local**: GPIO port number, which is of the uint16_t type. | – | HDF_STATUS| Disables interrupts for a GPIO pin.|


## How to Develop

The GPIO controller manages all pins by group. The related parameters are defined in attribute files. You need to instantiate the driver entry and APIs for the vendor driver to access the HDF.

The GPIO module adaptation involves the following steps: 

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **gpio_config.hcs** file.

3. Instantiate the GPIO controller object.
   - Initialize **GpioCntlr**.
   - Instantiate **GpioMethod** in the **GpioCntlr** object.
     
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/> For details about the functions in **GpioMethod**, see [Available APIs](#available-apis).
   
4. Debug the driver.
   
   (Optional) For new drivers, verify the basic functions, such as the GPIO status control and response to interrupts.


## Development Example

The following uses **gpio_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry. 
   
   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf\_device\_desc.h**), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.
   
     GPIO driver entry example:
   
   ```
   struct HdfDriverEntry g_gpioDriverEntry = {
     .moduleVersion = 1,
     .Bind = Pl061GpioBind, // Bind does not need to be implemented for GPIO. It is an empty method in this example. You can add related operations as required.
     .Init = Pl061GpioInit,            // See the Init function.
     .Release = Pl061GpioRelease,      // See the Release function.
     .moduleName = "hisi_pl061_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_gpioDriverEntry);
   ```
   
2. Add the **deviceNode** information to the **device_info.hcs** file, and configure the device attributes in the **gpio_config.hcs** file. 
   
   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **GpioCntlr** members at the core layer.
   In this example, there is only one GPIO controller. If there are multiple GPIO controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **gpio_config** file for each controller.
   
   - **device_info.hcs** configuration example
     
      ```
      root {
      device_info {
          platform :: host {
          hostName = "platform_host";
          priority = 50;
          device_gpio :: device {
              device0 :: deviceNode {
              policy = 0;        // No service is published.
              priority = 10;     // Driver startup priority.
              permission = 0644; // Permission to create device nodes for the driver.
              moduleName = "hisi_pl061_driver";         // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
              deviceMatchAttr = "hisilicon_hi35xx_pl061";// (Mandatory) Private data of the controller. The value must be the same as the controller information in gpio_config.hcs.
                                                          // Add private information about all controllers in this file.
              }
          }
          }
      }
      }
      ```
   - **gpio_config.hcs** configuration example
     
      ```
      root {
      platform {
          gpio_config {
          controller_0x120d0000 {
              match_attr = "hisilicon_hi35xx_pl061"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
              groupNum = 12;       // (Mandatory) GPIO group number.
              bitNum = 8;          // (Mandatory) Number of GPIO pins in each group.
              regBase = 0x120d0000;// (Mandatory) Physical base address.
              regStep = 0x1000; // (Mandatory) Register offset step.
              irqStart = 48;       // (Mandatory) Enable interrupts.
              irqShare = 0;        // (Mandatory) Whether to share an interrupt.
          }
          }
      }
      } 
      ```
   
3. Initialize the **GpioCntlr** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Init** and **Release**) to instantiate **GpioMethod** in **GpioCntlr** (so that the underlying driver functions can be called).
   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **gpio_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the GPIO group number and the number of pins, to the **GpioCntlr** object at the core layer.

      
      ```
      struct Pl061GpioCntlr {
        struct GpioCntlr cntlr;// (Mandatory) Control object at the core layer. The details are as follows:
        volatile unsigned char *regBase;// (Mandatory) Register base address.
        uint32_t phyBase;      // (Mandatory) Physical base address.
        uint32_t regStep;      // (Mandatory) Register offset step.
        uint32_t irqStart;     // (Mandatory) Enable interrupts.
        uint16_t groupNum;     // (Mandatory) Parameter of the GPIO port number.
        uint16_t bitNum;       // (Mandatory) Parameter of the GPIO port number.
        uint8_t irqShare;      // (Mandatory) Whether to share an interrupt.
        struct Pl061GpioGroup *groups; // (Optional) Set based on the actual requirements.
      };
      struct Pl061GpioGroup {// Register address, IRQ number and function, and lock.
        volatile unsigned char *regBase;
        unsigned int index;
        unsigned int irq;
        OsalIRQHandle irqFunc;
        OsalSpinlock lock;
      };
      
      // GpioCntlr is the controller structure at the core layer. The Init function assigns values to the members of GpioCntlr.
      struct GpioCntlr {
        struct IDeviceIoService service;
        struct HdfDeviceObject *device;
        struct GpioMethod *ops;
        struct DListHead list;
        OsalSpinlock spin;
        uint16_t start;
        uint16_t count;
        struct GpioInfo *ginfos;
        void *priv;
      };
      ```
      
   - Instantiating the **GpioMethod** structure in **GpioCntlr** (other members are initialized by **Init**)
   
     
      ```
      // The members of the GpioMethod structure are all callbacks. You need to implement the functions listed in Table 1.
      static struct GpioMethod g_method = {
          .request = NULL,
          .release = NULL,
          .write = Pl061GpioWrite, // Write the pin level.
          .read = Pl061GpioRead, // Read the pin level.
              .setDir = Pl061GpioSetDir, // Set the pin direction.
          .getDir = Pl061GpioGetDir,        // Obtain the pin direction.
          .toIrq = NULL,
          .setIrq = Pl061GpioSetIrq,        // Set an IRQ for a pin. Skip it if this capability is not available.
          .unsetIrq = Pl061GpioUnsetIrq, // Cancel the IRQ settings for a pin. Skip it if this capability is not available.
          .enableIrq = Pl061GpioEnableIrq,  // Enable interrupts for a pin. Skip it if this capability is not available.
          .disableIrq = Pl061GpioDisableIrq,// Disable interrupts for a pin. Skip it if this capability is not available.
      };
      ```
   
   - **Init** function
   
      Input parameter:
   
      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.
   
      Return value:
   
      HDF_STATUS
   
      The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.
      
        **Table 2** HDF_STATUS
      
      | Status| Description| 
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.| 
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.| 
      | HDF_ERR_INVALID_PARAM | Invalid parameter.| 
      | HDF_ERR_IO | I/O error.| 
      | HDF_SUCCESS | Initialization successful.| 
      | HDF_FAILURE | Initialization failed.| 
   
      Function description:
   
      Initializes the custom structure object and **GpioCntlr**, calls the **GpioCntlrAdd** function at the core layer, and (optional) connects to the virtual file system (VFS).
      
      
      ```
      static int32_t Pl061GpioInit(struct HdfDeviceObject *device)
      {
        ...
        struct Pl061GpioCntlr *pl061 = &g_pl061;// Use static global variables to complete initialization.
                                                // static struct Pl061GpioCntlr g_pl061 = {
                                                //    .groups = NULL,
                                                //    .groupNum = PL061_GROUP_MAX,
                                                //    .bitNum = PL061_BIT_MAX,
                                                //};
        ret = Pl061GpioReadDrs(pl061, device->property);// Use the attribute values read from the gpio_config.hcs file to initialize the members of the custom structure object.
        ...
        pl061->regBase = OsalIoRemap(pl061->phyBase, pl061->groupNum * pl061->regStep);// Create address mapping.
        ...
        ret = Pl061GpioInitCntlrMem(pl061); // Allocate memory.
        ...
        pl061->cntlr.count = pl061->groupNum x pl061->bitNum;// (Mandatory) Calculate the number of pins.
        pl061->cntlr.priv = (void *)device->property; // (Mandatory) Store device attributes.
        pl061->cntlr.ops = &g_method;           // (Mandatory) Attach the GpioMethod instance.
        pl061->cntlr.device = device;           // (Mandatory) Prerequisites for conversion between HdfDeviceObject and GpioCntlr.
        ret = GpioCntlrAdd(&pl061->cntlr);    // (Mandatory) Call this function to fill the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
        ...
        Pl061GpioDebugCntlr(pl061);
        #ifdef PL061_GPIO_USER_SUPPORT            // (Optional) Access the user-level VFS if it is supported.
        if (GpioAddVfs(pl061->bitNum) != HDF_SUCCESS) {
            HDF_LOGE("%s: add vfs fail!", __func__);
        }
        #endif
        ...
      }
      ```
      
   - **Release** function

      Input parameter:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

      Return value:

      No value is returned.

      Function description:
   
      Releases the memory and deletes the controller. This function assigns values to the **Release** function in the driver entry structure. If the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the value assignment operations.
   
      
      ```
      static void Pl061GpioRelease(struct HdfDeviceObject *device)
      {
         struct GpioCntlr *cntlr = NULL;
         struct Pl061GpioCntlr *pl061 = NULL;
         ...
         cntlr = GpioCntlrFromDevice(device);// (Mandatory) Obtain the control object at the core layer through forced conversion.
                                             // return (device == NULL) ? NULL : (struct GpioCntlr *)device->service;
         ...
         #ifdef PL061_GPIO_USER_SUPPORT
         GpioRemoveVfs();// Reverse operation of GpioAddVfs in Init.
         #endif
         GpioCntlrRemove(cntlr);             // (Mandatory) Remove the device information and services from the core layer.
         pl061 = ToPl061GpioCntlr(cntlr);    // return (struct Pl061GpioCntlr *)cntlr;
         Pl061GpioRleaseCntlrMem(pl061);     // (Mandatory) Release the lock and memory.
         OsalIoUnmap((void *)pl061->regBase);// (Mandatory) Unmap the addresses.
         pl061->regBase = NULL;
      }
      ```
