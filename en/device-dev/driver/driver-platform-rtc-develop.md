# RTC


## Overview

The real-time clock (RTC) is a real-time clock device in the operating system. In the Hardware Driver Foundation (HDF), the RTC uses the independent service mode for API adaptation. In this mode, each device independently publishes a service to process external access requests. When receiving an access request, the HDF DeviceManager extracts parameters from the request to call the internal APIs of the target device. In the independent service mode, the HDF DeviceManager provides service management capabilities. However, you need to configure a node for each device, which increases memory usage.

  **Figure 1** Independent service mode

  ![image](figures/independent-service-mode.png "RTC independent service mode")


## Available APIs

**RtcMethod**:


```
struct RtcMethod {
    int32_t (*ReadTime)(struct RtcHost *host, struct RtcTime *time);
    int32_t (*WriteTime)(struct RtcHost *host, const struct RtcTime *time);
    int32_t (*ReadAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, struct RtcTime *time);
    int32_t (*WriteAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, const struct RtcTime *time);
    int32_t (*RegisterAlarmCallback)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, RtcAlarmCallback cb);
    int32_t (*AlarmInterruptEnable)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, uint8_t enable);
    int32_t (*GetFreq)(struct RtcHost *host, uint32_t *freq);
    int32_t (*SetFreq)(struct RtcHost *host, uint32_t freq);
    int32_t (*Reset)(struct RtcHost *host);
    int32_t (*ReadReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t *value);
    int32_t (*WriteReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t value);
};
```

  **Table 1** Description of the callback functions in RtcMethod

| Function| Input Parameter| Output Parameter| Return Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| ReadTime | **host**: structure pointer to the RTC controller at the core layer.| **time**: structure pointer to the time read.| HDF_STATUS| Reads the RTC time.|
| WriteTime | **host**: structure pointer to the RTC controller at the core layer.<br>**time**: structure pointer to the time to write.| –| HDF_STATUS| Writes the RTC time (including the year, month, day, day of week, hour, minute, second, and millisecond).|
| ReadAlarm | **host**: structure pointer to the RTC controller at the core layer.<br>**alarmIndex**: RTC alarm index, which is an enumerated value.| **time**: structure pointer to the time read.| HDF_STATUS| Reads the RTC alarm time.|
| WriteAlarm | **host**: structure pointer to the RTC controller at the core layer.<br>**alarmIndex**: RTC alarm index, which is an enumerated value.<br>**time**: structure pointer to the time to write.| –| HDF_STATUS| Writes the RTC alarm time.|
| RegisterAlarmCallback | **host**: structure pointer to the RTC controller at the core layer.<br>**alarmIndex**: RTC alarm index, which is an enumerated value.<br>**cb**: pointer to the callback to register.| –| HDF_STATUS| Registers a callback to be invoked when an alarm is not generated at the specified time.|
| AlarmInterruptEnable | **host**: structure pointer to the RTC controller at the core layer.<br>**alarmIndex**: RTC alarm index, which is an enumerated value.<br>**enable**: whether to enable interrupts for an RTC alarm. | –| HDF_STATUS| Enables or disables interrupts for an RTC alarm.|
| GetFreq | **host**: structure pointer to the RTC controller at the core layer.| **freq**: pointer to the frequency obtained, which is of the uint32_t type.| HDF_STATUS| Obtains the frequency of the external crystal oscillator connected to the RTC driver.|
| SetFreq | **host**: structure pointer to the RTC controller at the core layer.<br>**freq**: frequency to set, which is of the uint32_t type.| –| HDF_STATUS| Sets the frequency of the external crystal oscillator connected to the RTC driver.|
| Reset | **host**: structure pointer to the RTC controller at the core layer.| –| HDF_STATUS| Resets the RTC.|
| ReadReg | **host**: structure pointer to the RTC controller at the core layer.<br>**usrDefIndex**: index of a custom register.| **value**: pointer to the register value obtained, which is of the uint8_t type.| HDF_STATUS| Reads a custom RTC register. A register index corresponds to one byte of the register value.|
| WriteReg | **host**: structure pointer to the RTC controller at the core layer.<br>**usrDefIndex**: index of a custom register.<br>**value**: register value to write, which is of the uint8_t type.| –| HDF_STATUS| Writes a custom RTC register. A register index corresponds to one byte of the register value.|


## How to Develop

The RTC module adaptation involves the following steps:

1. Instantiate the driver entry.
   - Instantiate the **HdfDriverEntry** structure.
   - Call **HDF_INIT** to register the **HdfDriverEntry** instance with the HDF.

2. Configure attribute files.
   - Add the **deviceNode** information to the **device_info.hcs** file.
   - (Optional) Add the **rtc_config.hcs** file.

3. Instantiate the RTC controller object.
   - Initialize **RtcHost**.
   - Instantiate **RtcMethod** in the **RtcHost** object.
      > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
      > For details about the functions in **RtcMethod**, see [Available APIs](#available-apis).

4. Debug the driver.

   (Optional) For new drivers, verify the basic functions, such as the RTC status control and response to interrupts.


## Development Example

The following uses **rtc_hi35xx.c** as an example to present the information required for implementing device functions.

1. Instantiate the driver entry.

   The driver entry must be a global variable of the **HdfDriverEntry** type (defined in **hdf_device_desc.h**), and the value of **moduleName** must be the same as that in **device_info.hcs**.

   In the HDF, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

   Generally, the HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, the HDF calls **Release** to release driver resources and exit.

   RTC driver entry example:
   
   ```
   struct HdfDriverEntry g_rtcDriverEntry = {
     .moduleVersion = 1,
     .Bind = HiRtcBind,                // See the Bind function.
     .Init = HiRtcInit,                // See the Init function.
     .Release = HiRtcRelease,          //See the Release function.
     .moduleName = "HDF_PLATFORM_RTC", // (Mandatory) The value must be the same as that in the .hcs file.
   };
   // Call HDF_INIT to register the driver entry with the HDF.
   HDF_INIT(g_rtcDriverEntry);
   ```

2. Add the **deviceNode** information to the **device_info.hcs** file and configure the device attributes in the **rtc_config.hcs** file.

   The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **RtcHost** members at the core layer.

   In this example, there is only one RTC controller. If there are multiple RTC controllers, you need to add the **deviceNode** information to the **device_info** file and add the corresponding device attributes to the **rtc_config** file for each controller.

   - **device_info.hcs** configuration example
   
     
     ```
     root {
       device_info {
         platform :: host {
           device_rtc :: device {
             device0 :: deviceNode {
               policy = 1;                              // The driver publishes services for kernel-mode processes only.
               priority = 30;                           // A smaller value indicates a higher priority.
               permission = 0644;                       // Permission for the driver to create a device node
               moduleName = "HDF_PLATFORM_RTC";         // (Mandatory) Driver name, which must be the same as moduleName in the driver entry.
               serviceName = "HDF_PLATFORM_RTC";        // (Mandatory) Unique name of the service published by the driver.
               deviceMatchAttr = "hisilicon_hi35xx_rtc";// The value must be the same as that of match_attr in the .hcs file.
             }
           }
         }
       }
     }
     ```
   
   - **rtc_config.hcs** configuration example
   
     
     ```
     root {
       platform {
         rtc_config {
           controller_0x12080000 {
             match_attr = "hisilicon_hi35xx_rtc";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
             rtcSpiBaseAddr = 0x12080000;        // Used for address mapping.
             regAddrLength = 0x100;              // Used for address mapping.
             irq = 37;                           // Interrupt number.
             supportAnaCtrl = false;
             supportLock = false;
             anaCtrlAddr = 0xff;
             lock0Addr = 0xff;
             lock1Addr = 0xff;
             lock2Addr = 0xff;
             lock3Addr = 0xff;
           }
         }
       }
     }
     ```

3. Initialize the **RtcHost** object at the core layer, including defining a custom structure (to pass parameters and data) and implementing the **HdfDriverEntry** member functions (**Bind**, **Init**, and **Release**) to instantiate **RtcMethod** in **RtcHost** (so that the underlying driver functions can be called).

   - Defining a custom structure

      To the driver, the custom structure holds parameters and data. The **DeviceResourceIface** method provided by the HDF reads the values in the **rtc_config.hcs** file to initialize the members in the custom structure.

      ```
      struct RtcConfigInfo {
        uint32_t           spiBaseAddr;     // Used for address mapping.
        volatile void      *remapBaseAddr;  // Used for address mapping.
        uint16_t           regAddrLength;   // Used for address mapping.
        uint8_t            supportAnaCtrl;  // Whether ANACTRL is supported.
        uint8_t            supportLock;     // Whether lock is supported.
        uint8_t            irq;             // Interrupt number.
        uint8_t            alarmIndex;      // RTC alarm index.
        uint8_t            anaCtrlAddr;     // ANACTRL address.
        struct RtcLockAddr lockAddr;        // Lock address.
        RtcAlarmCallback   cb;              // Callback.
        struct OsalMutex   mutex;           // Mutex.
      };
      
      // RtcHost is the controller structure at the core layer. The Init function assigns values to the members of RtcHost.
      struct RtcHost {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          struct RtcMethod *method;
          void *data;
      };
      ```

   - Instantiating **RtcMethod** in **RtcHost** (other members are initialized by **Init**)

      ```
       // Example in rtc_hi35xx.c: instantiate the hook.
       static struct RtcMethod g_method = {
      .ReadTime   = HiRtcReadTime,
      .WriteTime  = HiRtcWriteTime,
      .ReadAlarm  = HiReadAlarm,
      .WriteAlarm = HiWriteAlarm,
      .RegisterAlarmCallback  = HiRegisterAlarmCallback,
      .AlarmInterruptEnable   = HiAlarmInterruptEnable,
      .GetFreq  = HiGetFreq,
      .SetFreq  = HiSetFreq,
      .Reset       = HiReset,
      .ReadReg  = HiReadReg,
      .WriteReg = HiWriteReg,
       };
      ```

   - **Bind** function
   
     **Input parameter**:
     
     **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.
     
     **Return value**:
     
     **HDF_STATUS**
     
     The table below describes some status. For more information, see **HDF_STATUS** in the **/drivers/framework/include/utils/hdf_base.h** file.
     
      **Table 2** Description of HDF_STATUS
     
     | Status                 | Description                |
     | ---------------------- | -------------------------- |
     | HDF_ERR_INVALID_OBJECT | Invalid controller object. |
     | HDF_ERR_MALLOC_FAIL    | Failed to allocate memory. |
     | HDF_ERR_INVALID_PARAM  | Invalid parameter.         |
     | HDF_ERR_IO             | I/O error.                 |
     | HDF_SUCCESS            | Initialization successful. |
     | HDF_FAILURE            | Initialization failed.     |
     
     **Function description**:
     
      Binds the **HdfDeviceObject** object and **RtcHost**.
     
     ```
     static int32_t HiRtcBind(struct HdfDeviceObject *device)
        {
          struct RtcHost *host = NULL;  
          host = RtcHostCreate(device);    // Allocate memory and attach the device host with the device.
                                           // Prerequisite for conversion between HdfDeviceObject and RtcHost.
          ...
          device->service = &host->service; // Prerequisite for conversion between HdfDeviceObject and RtcHost.
                                           // It helps implement a global host by calling RtcHostFromDevice.
       return HDF_SUCCESS;
        }
     ```
     
   - **Init** function
     
     **Input parameter**:
     
     **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs information.
     
     **Return value**:
     
     **HDF_STATUS**
     
      **Function description**:
     
     Initializes the custom structure object and **RtcHost**.
     
     ```
     static int32_t HiRtcInit(struct HdfDeviceObject *device)
         {
           struct RtcHost *host = NULL;
           struct RtcConfigInfo *rtcInfo = NULL;
           ...
           host = RtcHostFromDevice(device);// Forcibly convert HdfDeviceObject to RtcHost.
           rtcInfo = OsalMemCalloc(sizeof(*rtcInfo));
           ...
           // HiRtcConfigData reads attributes from the device configuration tree and fills in supportAnaCtrl, supportLock, spiBaseAddr, regAddrLength and irq of RTCInfo.
           // Provide parameters for HiRtcSwInit and HiRtcSwInit. When HiRtcSwInit and HiRtcSwInit fail to be executed internally, Release() can be called to release memory.
           if (HiRtcConfigData(rtcInfo, device->property) != 0) {
             ...
           }
           if (HiRtcSwInit(rtcInfo)! = 0) {// Address mapping and interrupt registration.
             ...
           }
           if (HiRtcHwInit(rtcInfo)! = 0) {// Initialize ANACTRL and lockAddr.
             ...
           }
         
           host->method = &g_method; // Attach the RtcMethod instance.
           host->data = rtcInfo;     // Prerequisites for conversion between RtcConfigInfo and RtcHost.
           HDF_LOGI("Hdf dev service:%s init success!", HdfDeviceGetServiceName(device));
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
	
	
     > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
	 > All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** or **Bind** function has the corresponding value assignment operations.
   
   
     ```
     static void HiRtcRelease(struct HdfDeviceObject *device)
         {
          struct RtcHost *host = NULL;
          struct RtcConfigInfo *rtcInfo = NULL;
          ...
          host = RtcHostFromDevice(device);            // Forcibly convert HdfDeviceObject to RtcHost.
          rtcInfo = (struct RtcConfigInfo *)host->data;// Forcibly convert RtcHost to RtcConfigInfo.
          if (rtcInfo != NULL) {
              HiRtcSwExit(rtcInfo);
              OsalMemFree(rtcInfo);                    // Release RtcConfigInfo.
              host->data = NULL;
          }
          RtcHostDestroy(host);                        // Release RtcHost.
         }
     ```
