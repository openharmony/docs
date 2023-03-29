# UART

## Overview

### Function

The Universal Asynchronous Receiver/Transmitter (UART) is a universal serial data bus used for asynchronous communication. It enables bi-directional communication between devices in full-duplex mode.

A UART is connected to other modules through two wires (as shown in Figure 1) or four wires (as shown in Figure 2).

  - TX: UART transmitter. It is connected to the RX of the peer UART.
  - RX: UART receiver. It is connected to the TX of the peer UART.
  - RTS: Request to Send signal, indicating whether the local UART is ready to receive data. It is connected to the CTS of the peer UART.
  - CTS: Clear to Send signal, indicating whether the local UART is allowed to send data to the peer end. It is connected to the RTS of the peer UART.

**Figure 1** Two-wire UART communication

![image1](figures/2-wire-uart-communication.png "2-wire-uart-communication")

**Figure 2** Four-wire UART communication

 ![image2](figures/4-wire-uart-communication.png "4-wire-uart-communication")

The UART transmitter and receiver must have the same settings on particular attributes, such as the baud rate and data format (start bit, data bits, parity bit, and stop bit) before they start to communicate. A UART sends data to the peer end over the TX and receives data from the peer end over the RX. When the size of the buffer used by a UART for storing received data reaches the preset threshold, the RTS signal of the UART changes to **1** (data cannot be received), and the peer UART stops sending data to it because its CTS signal does not allow it to send data.

### Basic Concepts

- Asynchronous communication

  In asynchronous communication, data is transmitted in frames of characters or bytes. Frames are sent and received one by one through the transmission line. The transmitter and receiver have their own clocks to control data sending and receiving. The two clock sources are independent and not synchronized with each other. 

  When data is sent one character at a time, the time interval between two characters is not fixed, but the time interval between two adjacent bits in a character frame is fixed.

- Full-duplex transmission

  A duplex communication mode allows data to be transmitted in both directions at the same time. A duplex communication channel is equivalent to two simplex communication channels operating in opposite directions at the same time. In full-duplex mode, signals can be transmitted bidirectionally at the same time.

### Working Principles

In the Hardware Driver Foundation (HDF), the UART uses the independent service mode (see Figure 3) for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

In the independent service mode, the core layer does not publish a service for the upper layer. Therefore, a service must be published for each controller. To achieve this purpose:

- You need to implement the **Bind()** function in **HdfDriverEntry** to bind services.
- The **policy** field of **deviceNode** in the **device_info.hcs** file can be **1** or **2**, but not **0**.

The UART module is divided into the following layers:

- Interface layer: provides APIs for opening or closing a UART device, reading or writing data of the specified length, setting or obtaining the baud rate or attributes of a UART device, and setting the transmission mode.
- Core layer: provides the capabilities of adding or removing a UART controller, and managing UART devices. The core layer interacts with the adaptation layer through hook functions.
- Adaptation layer: instantiates the hook functions to implement specific features.

**Figure 3** Independent service mode

![image3](figures/independent-service-mode.png)

## Development Guidelines

### When to Use

The UART module is widely used to implement low-speed serial communication between devices, for example, output the printing information. It can also connect to a variety of external GPS and Bluetooth devices. Before using your UART devices with OpenHarmony, you need to perform UART driver adaptation.

### Available APIs

To enable the upper layer to successfully operate the PWM controller by calling the UART APIs, hook functions are defined in **//drivers/hdf_core/framework/support/platform/include/uart/uart_core.h** for the core layer. You need to implement these hook functions at the adaptation layer and hook them to implement the interaction between the interface layer and the core layer.

**UartHostMethod**:

```c
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

**Table 1** Hook functions in UartHostMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| Init | **host**: structure pointer to the UART controller at the core layer.| –| HDF_STATUS| Initializes a UART device.|
| Deinit | **host**: structure pointer to the UART controller at the core layer.| –| HDF_STATUS| Deinitializes a UART device.|
| Read | **host**: structure pointer to the UART controller at the core layer.<br>**size**: size of the data to read, which is of the uint32_t type.| **data**: pointer to the data read, which is of the uint8_t type. | HDF_STATUS| Reads data.|
| Write | **host**: structure pointer to the UART controller at the core layer.<br>**data**: pointer to the data to write, which is of the uint8_t type.<br>**size**: size of the data to write, which is of the uint32_t type.| –| HDF_STATUS| Writes data.|
| SetBaud | **host**: structure pointer to the UART controller at the core layer.<br>**baudRate**: baud rate to set, which is of the uint32_t type.| –| HDF_STATUS| Sets the baud rate.|
| GetBaud | **host**: structure pointer to the UART controller at the core layer.| **baudRate**: pointer to the baud rate obtained, which is of the uint32_t type.| HDF_STATUS| Obtains the baud rate.|
| GetAttribute | **host**: structure pointer to the UART controller at the core layer.| **attribute**: structure pointer to the attributes obtained. For details, see **UartAttribute** in **uart_if.h**.| HDF_STATUS| Obtains UART attributes.|
| SetAttribute | **host**: structure pointer to the UART controller at the core layer.<br>**attribute**: structure pointer to the attributes to set.| –| HDF_STATUS| Sets UART attributes.|
| SetTransMode | **host**: structure pointer to the UART controller at the core layer.<br>**mode**: transmission mode to set. For details, see **UartTransMode** in **uart_if.h**.| –| HDF_STATUS| Sets the UART transmission mode.|
| PollEvent | **host**: structure pointer to the UART controller at the core layer.<br>**filep**: void pointer to a file.<br>**table**: void pointer to the poll_table.| –| HDF_STATUS| Polls for the pending events.|

### How to Develop

The UART module adaptation procedure is as follows:

1. Instantiate the driver entry.
2. Configure attribute files.
3. Instantiate the UART controller object.
4. Debug the driver.

### Example

The following uses the **//device_soc_hisilicon/common/platform/uart/uart_hi35xx.c** driver of the Hi3516D V300 development board as an example to describe the UART driver adaptation.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**. In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.
   Generally, the HDF calls **Bind()** and then **Init()** to load a driver. If **Init()** fails to be called, the HDF calls **Release()** to release driver resources and exit.

   UART driver entry example:

   ```c
   struct HdfDriverEntry g_hdfUartDevice = {
       .moduleVersion = 1,
       .moduleName = "HDF_PLATFORM_UART",   // (Mandatory) The value must be the same as that of moduleName in the .hcs file.
       .Bind = HdfUartDeviceBind,           // See the Bind function.
       .Init = HdfUartDeviceInit,           // See the Init function.
       .Release = HdfUartDeviceRelease,     // See the Release function.
   };
   HDF_INIT(g_hdfUartDevice);               // Call HDF_INIT to register the driver entry with the HDF.
   ```

2. Configure attribute files.

   Add the deviceNode information to the **device_info.hcs** file. The deviceNode information is related to the driver entry registration. The following example uses two UART controllers as an example. If there are more UART controllers, add the deviceNode information to the **device_info.hcs** file for each controller. The device attribute values configured in **uart_config.hcs** are closely related to default values or value ranges of the **UartHost** members at the core layer.

   - **device_info.hcs** example:

      Add the deviceNode information to the **//vendor/hisilicon/hispark_taurus/hdf_config/device_info/device_info.hcs** file.

      ```c
      root {
          device_info {
              match_attr = "hdf_manager";
              platform :: host {
                  hostName = "platform_host";
                  priority = 50;
                  device_uart :: device {
                      device0 :: deviceNode {
                          policy = 1;                                 // The value 1 means to publish services only to the kernel-mode processes.
                          priority = 40;                              // Driver startup priority.
                          permission = 0644;                          // Permission for the device node created.
                          moduleName = "HDF_PLATFORM_UART";           // Driver name, which must be the same as moduleName in the HdfDriverEntry structure.
                          serviceName = "HDF_PLATFORM_UART_0";        // Unique name of the service published by the driver. The name is in the HDF_PLATFORM_UART_X format. X indicates the UART controller number.
                          deviceMatchAttr = "hisilicon_hi35xx_uart_0";// Keyword for matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
                      }
                      device1 :: deviceNode {
                        policy = 2;                                   // The value 2 means to publish services for both kernel- and user-mode processes.
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

   - **uart_config.hcs** example

      Configure the device attributes in the **//device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/uart/uart_config.hcs** file. The parameters are as follows:

      ```c
      root {
          platform {
              template uart_controller {                   // Template configuration. If the template is used to configure device node information, the default values in the template will be used for the fields that are not declared for the node.
                  match_attr = "";
                  num = 0;                                 // (Mandatory) Port number.
                  baudrate = 115200;                       // (Mandatory) Baud rate.
                  fifoRxEn = 1;                            // (Mandatory) Enable RX FIFO.
                  fifoTxEn = 1;                            // (Mandatory) Enable TX FIFO.
                  flags = 4;                               // (Mandatory) flag signal.
                  regPbase = 0x120a0000;                   // (Mandatory) Register physical base address used for address mapping.
                  interrupt = 38;                          // (Mandatory) Interrupt number.
                  iomemCount = 0x48;                       // (Mandatory) Used for address mapping.
              }
              controller_0x120a0000 :: uart_controller {
                  match_attr = "hisilicon_hi35xx_uart_0";  // (Mandatory) The value must be the same as that of deviceMatchAttr of the device in device_info.hcs.
              }
              controller_0x120a1000 :: uart_controller {
                  num = 1;
                  baudrate = 9600;
                  regPbase = 0x120a1000;
                  interrupt = 39;
                  match_attr = "hisilicon_hi35xx_uart_1";
              }
              ...                                          // Add node information for more UART devices.
          }
      }
      ```

      After the **uart_config.hcs** file is configured, include the file in the **hdf.hcs** file. Otherwise, the configuration file cannot take effect.

      ```c
      #include "../../../../device/soc/hisilicon/hi3516dv300/sdk_liteos/hdf_config/uart/uart_config.hcs" // Relative path of the file.
      ```

3. Instantiate the UART controller object.

   Initialize the **UartHost** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init** and **Release**) to instantiate **UartHostMethod** in **UartHost** (so that the underlying driver functions can be called).

   - Define a custom structure.

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **uart_config.hcs** file to initialize the members in the custom structure and passes important parameters, such as the UART port number, to the object at the core layer.

      ```c
      struct UartPl011Port {                       // Pin description structure customized.
          int32_t enable;
          unsigned long physBase;                  // Physical base address.
          uint32_t irqNum;                         // IRQ number.
          uint32_t defaultBaudrate;                // Default baud rate.
          uint32_t flags;                          // Flag signals related to the following three macros.
      #define PL011_FLG_IRQ_REQUESTED    (1 << 0)
      #define PL011_FLG_DMA_RX_REQUESTED (1 << 1)
      #define PL011_FLG_DMA_TX_REQUESTED (1 << 2)
          struct UartDmaTransfer *rxUdt;           // DMA transfer.
          struct UartDriverData *udd;
      };
      struct UartDriverData {                      // Structure related to data transfer
          uint32_t num;                            // Port number.
          uint32_t baudrate;                       // Baud rate (configurable).
          struct UartAttribute attr;               // Attributes, such as the data bits and stop bit of the data to transfer.
          struct UartTransfer *rxTransfer;         // Buffer structure (FIFO structure)
          wait_queue_head_t wait;                  // Queuing signal related to conditional variables
          int32_t count;                           // Data count.
          int32_t state;                           // UART controller state.
      #define UART_STATE_NOT_OPENED 0
      #define UART_STATE_OPENING    1
      #define UART_STATE_USEABLE    2
      #define UART_STATE_SUSPENDED  3
          uint32_t flags;                          // Status flags.
      #define UART_FLG_DMA_RX       (1 << 0)
      #define UART_FLG_DMA_TX       (1 << 1)
      #define UART_FLG_RD_BLOCK     (1 << 2)
          RecvNotify recv;                         // Pointer to the function that receives serial port data.
          struct UartOps *ops;                     // Custom function pointer structure.
          void *private;                           // Private data.
      };
      
      // UartHost is the controller structure at the core layer. The Init function assigns values to the members of UartHost.
      struct UartHost {
          struct IDeviceIoService service;         // Driver service.
          struct HdfDeviceObject *device;          // Driver device object.
          uint32_t num;                            // Port number.
          OsalAtomic atom;                         // Atomic quantity.
          void *priv;                              // Private data.
          struct UartHostMethod *method;           // Callback functions.
      };
      ```

   - Instantiate **UartHostMethod** in **UartHost**.

      ```c
      // Instantiate the hook functions in uart_hi35xx.c.
      struct UartHostMethod g_uartHostMethod = {
          .Init = Hi35xxInit,                     // Initialize the device.
          .Deinit = Hi35xxDeinit,                 // Deinitialize the device.
          .Read = Hi35xxRead,                     // Receive data.
          .Write = Hi35xxWrite,                   // Write data.
          .SetBaud = Hi35xxSetBaud,               // Set the baud rate.
          .GetBaud = Hi35xxGetBaud,               // Obtain the baud rate.
          .SetAttribute = Hi35xxSetAttribute,     // Set device attributes.
          .GetAttribute = Hi35xxGetAttribute,     //Obtain device attributes.
          .SetTransMode = Hi35xxSetTransMode,     // Set the transmission mode.
          .pollEvent = Hi35xxPollEvent,           // Polling for pending events.
      };
      ```

   - Implement the **Bind** function.

      Input parameter:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      **HDF_STATUS**<br/>The table below describes some status. For more information, see **HDF_STATUS** in the **//drivers/hdf_core/framework/include/utils/hdf_base.h** file.

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

      Initializes the custom structure object and **UartHost**.

      ```c
      //uart_hi35xx.c
      static int32_t HdfUartDeviceBind(struct HdfDeviceObject *device)
      {
          ...
          return (UartHostCreate(device) == NULL) ? HDF_FAILURE : HDF_SUCCESS; // (Mandatory) Call UartHostCreate.
      }

      // Description of UartHostCreate() in uart_core.c
      struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL                                         // Create UartHost.
          ...                                                                  
          host = (struct UartHost *)OsalMemCalloc(sizeof(*host));              // Allocate memory.
          ...
          host->device = device;                                               // (Mandatory) Prerequisites for conversion between HdfDeviceObject and UartHost.
          device->service = &(host->service);                                  // (Mandatory) Prerequisites for conversion between HdfDeviceObject and UartHost.
          host->device->service->Dispatch = UartIoDispatch;                    // Assign values to Dispatch() of service.
          OsalAtomicSet(&host->atom, 0);                                       // Initialize or set the atomic service.
          host->priv = NULL;
          host->method = NULL;
          return host;
      }
      ```

   - Implement the **Init** function.

      Input parameter:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      HDF_STATUS

      Function description:

      Initialize the custom structure and **UartHost**, calls **UartAddDev()** at the core layer to add the UART controller, and accesses the VFS.

      ```c
      int32_t HdfUartDeviceInit(struct HdfDeviceObject *device)
      {
          int32_t ret;
          struct UartHost *host = NULL;
          HDF_LOGI("%s: entry", __func__);
          ...
          host = UartHostFromDevice(device);                                           // Forcibly convert to UartHost by using service. The values are assigned by Bind().
          ...                                    
          ret = Hi35xxAttach(host, device);                                            // Initialize the UartHost object.
          ...                                    
          host->method = &g_uartHostMethod;                                            // Attach the UartHostMethod instance.
          return ret;
      }
      // Initialize UartHost.
      static int32_t Hi35xxAttach(struct UartHost *host, struct HdfDeviceObject *device)
      {
          int32_t ret;
          struct UartDriverData *udd = NULL;                                           // udd and port are custom structure objects. You can implement features as required.
          struct UartPl011Port *port = NULL;
          ...
          // Steps 1 to 7 assign values to the udd object and then UartHost.
          udd = (struct UartDriverData *)OsalMemCalloc(sizeof(*udd));                  // Step 1
          ...
          port = (struct UartPl011Port *)OsalMemCalloc(sizeof(struct UartPl011Port));  // Step 2
          ...
          udd->ops = Pl011GetOps();                                                    // Step 3 Hook the functions for opening or closing a device, setting device attributes, and sending data.
          udd->recv = PL011UartRecvNotify;                                             // Step 4 Hook the data receiving notification function (conditional lock mechanism).
          udd->count = 0;                                                              // Step 5.
          port->udd = udd;                                                             // Step 6 Prerequisites for conversion between UartPl011Port and UartDriverData.
          ret = UartGetConfigFromHcs(port, device->property);                          // Pass the attributes of HdfDeviceObject to the custom structure to perform related operations. The sample code is as follows:
          ...
          udd->private = port;                                                         // Step 7
          host->priv = udd;                                                            // (Mandatory) Prerequisites for conversion between UartHost and UartDriverData.
          host->num = udd->num;                                                        // (Mandatory) UART device number.
          UartAddDev(host);                                                            // (Mandatory) Function in uart_dev.c at the core layer used to register a character device node to the VFS so that the UART can be accessed through the virtual file node in user mode. 
          return HDF_SUCCESS;
      }
      
      static int32_t UartGetConfigFromHcs(struct UartPl011Port *port, const struct DeviceResourceNode *node)
      {
          uint32_t tmp, regPbase, iomemCount;
          struct UartDriverData *udd = port->udd;
          struct DeviceResourceIface *iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); 
          ...
          // Extract the values based on the request and assign the values to the custom structures.
          if (iface->GetUint32(node, "num", &udd->num, 0) != HDF_SUCCESS) {
              HDF_LOGE("%s: read busNum fail", __func__);
              return HDF_FAILURE;
          }
          ...
          return 0;
          }
      ```

   - Implement the **Release** function.

      Input parameter:

      **HdfDeviceObject**, a device object created by the HDF for each driver, holds device-related private data and service APIs.

      Return value:

      No value is returned.

      Function description:

      Releases the memory and deletes the controller. This function assigns values to **Release()** in the driver entry structure. When the HDF fails to call **Init()** to initialize the driver, **Release()** is called to release driver resources.

      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
      > All forced conversion operations for obtaining the corresponding object can be successful only when **Init()** has the corresponding value assignment operations.

      ```c
      void HdfUartDeviceRelease(struct HdfDeviceObject *device)
      {
          struct UartHost *host = NULL;
          ...
          host = UartHostFromDevice(device);           // Forcible conversion from HdfDeviceObject to UartHost through the service member. For details about the value assignment, see the Bind function.
          ...                                          
          if (host->priv != NULL) {                    
              Hi35xxDetach(host);                      // Customized memory release function. For details, see the following.
          }                                            
          UartHostDestroy(host);                       // Call the core layer function to release the host.
      }
      
      static void Hi35xxDetach(struct UartHost *host)
      {
          struct UartDriverData *udd = NULL;
          struct UartPl011Port *port = NULL;
          ...
          udd = host->priv;                            // The conversion from UartHost to UartDriverData is involved.
          ...                                          
          UartRemoveDev (host);                        // Remove the VFS.
          port = udd->private;                         // The conversion from UartDriverData to UartPl011Port is involved.
          if (port != NULL) {                          
              if (port->physBase != 0) {               
                  OsalIoUnmap((void *)port->physBase); // Unmap addresses.
              }
              OsalMemFree(port);
              udd->private = NULL;
          }
          OsalMemFree (udd);                           // Release UartDriverData.
          host->priv = NULL;
      }
      ```

4. Debug the driver.

   (Optional) For new drivers, verify basic functions, for example, check the information returned after the driver is attached and whether data is successfully transmitted.
