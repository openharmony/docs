# UART


## Overview

In the Hardware Driver Foundation (HDF), the Universal Asynchronous Receiver/Transmitter (UART) uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png)


## Available APIs

**UartHostMethod**:


```
struct UartHostMethod {
  int32_t (*Init)(struct UartHost *host);
  int32_t (*Deinit)(struct UartHost *host);
  int32_t (*Read)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*Write)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*GetBaud)(struct UartHost *host, uint32_t *baudRate);
  int32_t (*SetBaud)(struct UartHost *host, uint32_t baudRate);
  int32_t (*GetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetTransMode)(struct UartHost *host, enum UartTransMode mode);
  int32_t (*pollEvent)(struct UartHost *host, void *filep, void *table);
};
```

  **Table 1** Description of the callback functions in UartHostMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| Init | **host**: structure pointer to the UART controller at the core layer.| –| HDF_STATUS| Initializes a UART device.|
| Deinit | **host**: structure pointer to the UART controller at the core layer.| –| HDF_STATUS| Deinitializes a UART device.|
| Read | **host**: structure pointer to the UART controller at the core layer.<br>**size**: data size, which is of the uint32_t type.| **data**: pointer to the data read. The value is of the uint8_t type. | HDF_STATUS| Reads data.|
| Write | **host**: structure pointer to the UART controller at the core layer.<br>**data**: pointer to the data to write. The value is of the uint8_t type.<br>**size**: data size, which is of the uint32_t type. | –| HDF_STATUS| Writes data.|
| SetBaud | **host**: structure pointer to the UART controller at the core layer.<br>**baudRate**: pointer to the baud rate to set. The value is of the uint32_t type. | –| HDF_STATUS| Sets the baud rate.|
| GetBaud | **host**: structure pointer to the UART controller at the core layer.| **baudRate**: pointer to the baud rate obtained. The value is of the uint32_t type. | HDF_STATUS| Obtains the current baud rate.|
| GetAttribute | **host**: structure pointer to the UART controller at the core layer.| **attribute**: structure pointer to the attribute obtained. For details, see **UartAttribute** in **uart_if.h**. | HDF_STATUS| Obtains UART attributes.|
| SetAttribute | **host**: structure pointer to the UART controller at the core layer.<br>**attribute**: structure pointer to the attribute to set. | –| HDF_STATUS| Sets UART attributes.|
| SetTransMode | **host**: structure pointer to the UART controller at the core layer.<br>**mode**: transfer mode to set. For details, see **UartTransMode** in **uart_if.h**.| –| HDF_STATUS| Sets the UART transfer mode.|
| PollEvent | **host**: structure pointer to the UART controller at the core layer.<br>**filep**: void pointer to a file.<br>**table**: void pointer to poll_table.| –| HDF_STATUS| Polls for pending events.|


## How to Develop

The UART module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **uart_config.hcs** file.

3. Instantiate the UART controller object.
   - Initialize **UartHost**.
   - Instantiate **UartHostMethod** in the **UartHost** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **UartHostMethod**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify the basic functions, such as the UART status control and response to interrupts.


## Development Example

The following uses **uart_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**.

   In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   UART driver entry example:
   
   ```
   struct HdfDriverEntry g_hdfUartDevice = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_UART", // (Mandatory) The value must be the same as that in the .hcs file.
       .Bind = HdfUartDeviceBind, // See the Bind function.
       .Init = HdfUartDeviceInit,  // See the Init function.
       .Release = HdfUartDeviceRelease, //See the Release function.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_hdfUartDevice);
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **uart_config.hcs** file.

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **UartHost** members at the core layer.

   In this example, there is only one UART controller. If there are multiple UART controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **uart_config** file for each controller.

   - **device_info.hcs** configuration example:
   
     
     ```
     root {
       device_info {
         match_attr = "hdf_manager";
         platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_uart :: device {
             device0 :: deviceNode {
               policy = 1;                                 // The driver publishes services only for kernel-mode processes.
               priority = 40;                              // Driver startup priority.
               permission = 0644;                         // Permission for the driver to create a device node.
               moduleName = "HDF_PLATFORM_UART";           // Driver name, which must be the same as moduleName in the HdfDriverEntry structure.
               serviceName = "HDF_PLATFORM_UART_0";        // Unique name of the service published by the driver. The name is in the HDF_PLATFORM_UART_X format. X indicates the UART controller number.
               deviceMatchAttr = "hisilicon_hi35xx_uart_0"; // Keyword for matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
             }
             device1 :: deviceNode {
               policy = 2;    // The driver publishes services for both kernel- and user-mode processes.
               permission = 0644;
               priority = 40;
               moduleName = "HDF_PLATFORM_UART"; 
               serviceName = "HDF_PLATFORM_UART_1";
               deviceMatchAttr = "hisilicon_hi35xx_uart_1";
             }
             ...
           }
         }
       }
     }
     ```
   
   - **uart_config.hcs** configuration example
   
     
     ```
     root {
       platform {
         template uart_controller { // Template configuration. In the template, you can configure the common parameters shared by device nodes.
           match_attr = "";
           num = 0;                 // (Mandatory) Device number.
           baudrate = 115200;       // (Mandatory) Baud rate. Set the value based on service requirements.
           fifoRxEn = 1;            // (Mandatory) Enable FIFOs to be received.
           fifoTxEn = 1;            // (Mandatory) Enable FIFOs to be transferred.
           flags = 4;               // (Mandatory) Flag signal.
           regPbase = 0x120a0000;   // (Mandatory) Used for address mapping.
           interrupt = 38;          // (Mandatory) Interrupt number.
           iomemCount = 0x48;       // (Mandatory) Used for address mapping.
         }
         controller_0x120a0000 :: uart_controller {
           match_attr = "hisilicon_hi35xx_uart_0";// (Mandatory) The value must be the same as that of deviceMatchAttr of the corresponding device in device_info.hcs.
         }
         controller_0x120a1000 :: uart_controller {
           num = 1;
           baudrate = 9600;
           regPbase = 0x120a1000;
           interrupt = 39;
           match_attr = "hisilicon_hi35xx_uart_1";
         }
         ...
         //(Optional) Add more controller data. The node information must have been added in the device_info.hcs file.
       }
     }
     ```

3. Initialize the **UartHost** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **UartHostMethod** in **UartHost** (so that the underlying driver functions can be called).

   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **uart_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the device number, to the **UartHost** object at the core layer.

      
      ```
      struct UartPl011Port {                   // Interface structure
          int32_t             enable;
          unsigned long       physBase;        // Physical address
          uint32_t            irqNum;          // Interrupt number
          uint32_t            defaultBaudrate; // Default baud rate
          uint32_t            flags;           // Flags related to the following three macros
      #define PL011_FLG_IRQ_REQUESTED    (1 << 0)
      #define PL011_FLG_DMA_RX_REQUESTED (1 << 1)
      #define PL011_FLG_DMA_TX_REQUESTED (1 << 2)
          struct UartDmaTransfer *rxUdt;       // DMA transfer
          struct UartDriverData *udd;          // The data structure is defined as follows:
      };
      struct UartDriverData {                  // Structure related to data transfer
          uint32_t num;
          uint32_t baudrate;                   // Baud rate (configurable)
          struct UartAttribute attr;           // Attributes, such as the data bit and stop bit, related to data transfer.
          struct UartTransfer *rxTransfer;     // Buffer (FIFO structure)
          wait_queue_head_t wait;              // Queuing signal related to conditional variables
          int32_t count;                       // Data count
          int32_t state;                       // UART controller state
      #define UART_STATE_NOT_OPENED 0
      #define UART_STATE_OPENING    1
      #define UART_STATE_USEABLE    2
      #define UART_STATE_SUSPENDED  3
          uint32_t flags;                      // Status flags
      #define UART_FLG_DMA_RX       (1 << 0)
      #define UART_FLG_DMA_TX       (1 << 1)
      #define UART_FLG_RD_BLOCK     (1 << 2)
          RecvNotify recv;                     // Pointer to the function that receives serial port data.
          struct UartOps *ops;                 // Custom function pointer structure. For details, see device/hisilicon/drivers/uart/uart_pl011.c.
          void *private;                       // It stores the pointer to the start address of UartPl011Port for easy invocation.
      };
      
      // UartHost is the controller structure at the core layer. The Init function assigns values to the members of UartHost.
      struct UartHost {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          uint32_t num;
          OsalAtomic atom;
          void *priv;                         // It stores the pointer to the start address of the vendor's custom structure for easy invocation.
          struct UartHostMethod *method;      // Hook at the core layer. You need to implement and instantiate its member functions.
      };
      ```

   - Instantiating **UartHostMethod** in **UartHost** (other members are initialized by **Bind**)

     
      ```
      // Example in uart_hi35xx.c: instantiate the hook.
      struct UartHostMethod g_uartHostMethod = {
        .Init = Hi35xxInit,
        .Deinit = Hi35xxDeinit,
        .Read = Hi35xxRead,
        .Write = Hi35xxWrite,
        .SetBaud = Hi35xxSetBaud,
        .GetBaud = Hi35xxGetBaud,
        .SetAttribute = Hi35xxSetAttribute,
        .GetAttribute = Hi35xxGetAttribute,
        .SetTransMode = Hi35xxSetTransMode,
        .pollEvent = Hi35xxPollEvent,
      };
      ```

   - **Bind** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.

        **Table 2** Description of HDF_STATUS
      
      | Status| Description|
      | -------- | -------- |
      | HDF_ERR_INVALID_OBJECT | Invalid controller object.|
      | HDF_ERR_MALLOC_FAIL | Failed to allocate memory.|
      | HDF_ERR_INVALID_PARAM | Invalid parameter.|
      | HDF_ERR_IO | I/O error.|
      | HDF_SUCCESS | Initialization successful.|
      | HDF_FAILURE | Initialization failed.|

      **Function description**:

      Initializes the custom structure object and **UartHost**.

      
      ```
      //uart_hi35xx.c
      static int32_t HdfUartDeviceBind(struct HdfDeviceObject *device)
      {
          ...
          return (UartHostCreate(device) == NULL)? HDF_FAILURE: HDF_SUCCESS;// (Mandatory) Call UartHostCreate.
      }
      // Description of UartHostCreate() in uart_core.c
      struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL;                          // Create UartHost.
          ...
          host = (struct UartHost *)OsalMemCalloc(sizeof(*host));// Allocate memory.
          ...
          host->device = device;                           // (Mandatory) Prerequisites for conversion between HdfDeviceObject and UartHost.
          device->service = &(host->service;              // (Mandatory) Prerequisites for conversion between HdfDeviceObject and UartHost.
          host->device->service->Dispatch = UartIoDispatch;      // Assign values to Dispatch of service.   
          OsalAtomicSet(&host->atom, 0);                          // Initialize or set the atomic services.
          host->priv = NULL;
          host->method = NULL;
          return host;
      }
      ```

   - **Init** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      **HDF_STATUS**

      **Function description**:

      Initializes the custom structure object and **UartHost**, calls the **artAddDev** function at the core layer, and connects to the VFS.

      
      ```
      int32_t HdfUartDeviceInit(struct HdfDeviceObject *device)
      {
          int32_t ret;
          struct UartHost *host = NULL;
          HDF_LOGI("%s: entry", __func__);
          ...
          host = UartHostFromDevice(device);// Forcibly convert to UartHost by using service. The values are assigned by Bind().
          ...
          ret = Hi35xxAttach(host, device); // Initialize the UartHost object.
          ...
          host->method = &g_uartHostMethod; // Attach the UartHostMethod instance.
          return ret;
      }
      // Initialize UartHost.
      static int32_t Hi35xxAttach(struct UartHost *host, struct HdfDeviceObject *device)
      {
          int32_t ret;
          // udd and port are customized structure objects. Implement the related functions as required.
          struct UartDriverData *udd = NULL;
          struct UartPl011Port *port = NULL;
          ...
          // Steps 1 to 7 instantiate and assign values to the udd object, and then assign values to UartHost.
          udd = (struct UartDriverData *)OsalMemCalloc(sizeof(*udd));// Step 1 
          ...
          port = (struct UartPl011Port *)OsalMemCalloc(sizeof(struct UartPl011Port));// Step 2
          ...
          udd->ops = Pl011GetOps();     // Step 3 Hook the functions for starting or stopping a device, setting attributes, and sending data.
          udd->recv = PL011UartRecvNotify;// Step 4 Hook the data receiving notification function (conditional lock mechanism).
          udd->count = 0;          // Step 5 
          port->udd = udd;          // Step 6  Enable conversion between UartPl011Port and UartDriverData.
          ret = UartGetConfigFromHcs(port, device->property);// Pass the attributes of HdfDeviceObject to the custom structure.
                                                             // The sample code is as follows:
          ...
          udd->private = port;     // Step 7 
          
          host->priv = udd;        // (Mandatory) Enable conversion between UartHost and UartDriverData.
          host->num = udd->num; // (Mandatory) UART device number
          UartAddDev(host);        // (Mandatory) Function (in uart_dev.c) used to register a character device node to the VFS so that the UART can be accessed through the virtual file node in user mode.   
          return HDF_SUCCESS;
      }
      
      static int32_t UartGetConfigFromHcs(struct UartPl011Port *port, const struct DeviceResourceNode *node)
      {
          uint32_t tmp, regPbase, iomemCount;
          struct UartDriverData *udd = port->udd;
          struct DeviceResourceIface *iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); 
          ...
          // Extract the values based on the request and assign the values to the custom structure.
          if (iface->GetUint32(node, "num", &udd->num, 0) != HDF_SUCCESS) {
              HDF_LOGE("%s: read busNum fail", __func__);
              return HDF_FAILURE;
          }
          ...
          return 0;
          }
      ```
   - **Release** function

      **Input parameter**:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.

      **Return value**:

      No value is returned.

      **Function description**:

      Releases the memory and deletes the controller. This function assigns values to the **Release** API in the driver entry structure. When the HDF fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
      > 
      > All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.

      
      ```
      void HdfUartDeviceRelease(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL;
          ...
          host = UartHostFromDevice(device); // Forcibly convert HdfDeviceObject to UartHost by using service. For details about the value assignment, see the Bind function.
          ...
          if (host->priv != NULL) {
              Hi35xxDetach(host);            // Customized memory release function.
          }
          UartHostDestroy(host);             // Call the function of the core layer to release the host.
      }
      
      static void Hi35xxDetach(struct UartHost *host)
      {
          struct UartDriverData *udd = NULL;
          struct UartPl011Port *port = NULL;
          ...
          udd = host->priv;                  // The conversion from UartHost to UartDriverData is involved.
          ...
          UartRemoveDev (host);              // Remove the VFS.
          port = udd->private;               // The conversion from UartDriverData to UartPl011Port is involved.
          if (port != NULL) {
              if (port->physBase != 0) {
                  OsalIoUnmap((void *)port->physBase);// Unmap addresses.
              }
              OsalMemFree(port);
              udd->private = NULL;
          }
          OsalMemFree (udd);                           // Release UartDriverData.
          host->priv = NULL;
      }
      ```
