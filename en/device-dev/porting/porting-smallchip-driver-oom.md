# Device Driver Porting

This section describes how to port device drivers.

## LCD Driver Porting

To port an LCD driver, write the driver, create an instance of the corresponding model in the driver, and complete the registration.

The LCD drivers are stored in **//drivers/hdf_core/framework/model/display/driver/panel**.

1.  Create a panel driver.

    Create an HDF driver and call the **RegisterPanel** method to register a model instance during driver initialization.


       ```
       int32_t LCDxxEntryInit(struct HdfDeviceObject *object)
       {
           struct PanelData *panel = CreateYourPanel();
           // Register a model instance.
           if (RegisterPanel(panel) != HDF_SUCCESS) {
               HDF_LOGE("%s: RegisterPanel failed", __func__);
               return HDF_FAILURE;
           }
           return HDF_SUCCESS;
       }
       
       struct HdfDriverEntry g_xxxxDevEntry = {
           .moduleVersion = 1,
           .moduleName = "LCD_XXXX",
           .Init = LCDxxEntryInit,
       };
       
       HDF_INIT(g_xxxxDevEntry);
       ```

2.  Configure and load the panel driver.

    Modify the source code file **//vendor/vendor_name/product_name/config/device_info/device_info.hcs**. Add configurations for the device named **device\_lcd**  for the display host.

    > ![icon-caution.gif](public_sys-resources/icon-caution.gif) **CAUTION**
    >
    > Make sure the value of **moduleName** is the same as that of **moduleName** in the panel driver.


       ```
       root {
           ...
           display :: host {
               device_lcd :: device {
                       deviceN :: deviceNode {
                           policy = 0;
                           priority = 100;
                           preload = 2;
                           moduleName = "LCD_XXXX";
                       }
               }
           }
       }
       ```


## Touchscreen Driver Porting

This section describes how to port a touchscreen driver. The touchscreen drivers are stored in the source code directory **//drivers/hdf_core/framework/model/input/driver/touchscreen**. To port a touchscreen driver, register a **ChipDevice** model instance with the system.

For details about how to develop a touchscreen driver, see  [Touchscreen Development Guidelines](../driver/driver-peripherals-touch-des.md).

1.  Create a touchscreen driver.

    Create the **touch_ic_name.c** file in the **touchscreen** directory. Write the following content:


       ```
       #include "hdf_touch.h"
       
       static int32_t HdfXXXXChipInit(struct HdfDeviceObject *device)
       {
           ChipDevice *tpImpl = CreateXXXXTpImpl();
           if(RegisterChipDevice(tpImpl) != HDF_SUCCESS) { // Register the ChipDevice model instance.
               ReleaseXXXXTpImpl(tpImpl);
               return HDF_FAILURE;
           }
           return HDF_SUCCESS;
       }
       
       struct HdfDriverEntry g_touchXXXXChipEntry = {
           .moduleVersion = 1,
           .moduleName = "HDF_TOUCH_XXXX", // Make sure the value is the same as that in the subsequent configuration.
           .Init = HdfXXXXChipInit,
       };
       
       HDF_INIT(g_touchXXXXChipEntry);
       ```

    The following methods need to be implemented in **ChipDevice**.
    
    | Method | Description |
    | -------- | -------- |
    | int32_t&nbsp;(\*Init)(ChipDevice&nbsp;\*device) | Initializes the device. |
    | int32_t&nbsp;(\*Detect)(ChipDevice&nbsp;\*device) | Detects the device. |
    | int32_t&nbsp;(\*Suspend)(ChipDevice&nbsp;\*device) | Places the device in sleep mode. |
    | int32_t&nbsp;(\*Resume)(ChipDevice&nbsp;\*device) | Wakes up the device. |
    | int32_t&nbsp;(\*DataHandle)(ChipDevice&nbsp;\*device) | Reads data from the device and writes touch point data to device > driver > frameData. |
    | int32_t&nbsp;(\*UpdateFirmware)(ChipDevice&nbsp;\*device) | Updates the firmware. |

2.  Configure the product and load the driver.

    All device information of the product is defined in the source code file **//vendor/vendor_name/product_name/config/device_info/device_info.hcs**. Modify the file and add configurations to the **device** named **device\_touch\_chip**  in the **host** of the **input** command.

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
       >
       > Make sure the value of **moduleName**  is the same as that of **moduleName** in the touchscreen driver.


       ```
       deviceN :: deviceNode {
           policy = 0;
           priority = 130;
           preload = 0;
           permission = 0660;
           moduleName = "HDF_TOUCH_XXXX";
           deviceMatchAttr = "touch_XXXX_configs";
       }
       ```


## WLAN Driver Porting

The WLAN driver is divided into two parts. One of the parts manages WLAN devices, and the other part manages WLAN traffic.

**Figure 1** OpenHarmony WLAN driver architecture<a name="fig155920160203"></a>  

  ![hdf_wifi](figures/hdf_wifi.png)

As shown in Figure 1, the part on the left manages WLAN devices, and the part on the right manages WLAN traffic. The HDF WLAN framework abstracts these two parts. The porting process of the driver can be considered as the implementation of the APIs required by the two parts. These APIs are described in the table below.

| API | Header File | Description |
| -------- | -------- | -------- |
| HdfChipDriverFactory | drivers\hdf_core\framework\include\wifi\hdf_wlan_chipdriver_manager.h | Factory of the ChipDriver, which is used to support multiple WLAN interfaces of a chip. |
| HdfChipDriver | drivers\hdf_core\framework\include\wifi\wifi_module.h | Manages a specific WLAN interface. |
| NetDeviceInterFace | drivers\hdf_core\framework\include\wifi\net_device.h | Communicates with the protocol stack, such as sending data and setting the status of network interfaces. |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> For details about the API development, see  [WLAN Development Guidelines](../driver/driver-peripherals-external-des.md).

The porting procedure is as follows:

1.  Create a WLAN chip driver.

    Create the **hdf_wlan_chip_name.c** file in **/device/vendor_name/peripheral/wifi/chip_name/**. The sample code is as follows:

       ```
       static int32_t HdfWlanXXXChipDriverInit(struct HdfDeviceObject *device) {
           static struct HdfChipDriverFactory factory = CreateChipDriverFactory(); // Implement the method.
           struct HdfChipDriverManager *driverMgr = HdfWlanGetChipDriverMgr();
           if (driverMgr->RegChipDriver(&factory) != HDF_SUCCESS) { // Register the driver factory.
               HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
               return HDF_FAILURE;
           }
           return HDF_SUCCESS;
       }
       
       struct HdfDriverEntry g_hdfXXXChipEntry = {
           .moduleVersion = 1,
           .Init = HdfWlanXXXChipDriverInit,
           .Release = HdfWlanXXXChipRelease,
           .moduleName = "HDF_WIFI_CHIP_XXX" // Make sure the name is the same as the configured one.
       };
       
       HDF_INIT(g_hdfXXXChipEntry);
       ```

    In the **CreateChipDriverFactory** method, create an object of the **HdfChipDriverFactory**  type. This object provides the methods listed below.
    
       | Method | Description |
       | -------- | -------- |
       | const&nbsp;char&nbsp;\*driverName | Indicates the driver name. |
       | int32_t&nbsp;(\*InitChip)(struct&nbsp;HdfWlanDevice&nbsp;\*device) | Initializes the chip. |
       | int32_t&nbsp;(\*DeinitChip)(struct&nbsp;HdfWlanDevice&nbsp;\*device) | Deinitializes the chip. |
       | void&nbsp;(\*ReleaseFactory)(struct&nbsp;HdfChipDriverFactory&nbsp;\*factory) | Releases the **HdfChipDriverFactory** object. |
       | struct&nbsp;HdfChipDriver&nbsp;\*(\*Build)(struct&nbsp;HdfWlanDevice&nbsp;\*device,&nbsp;uint8_t&nbsp;ifIndex) | Creates an **HdfChipDriver**. In the input parameters, **device** indicates the device information, and **ifIndex** indicates the sequence number of this interface in the chip. |
       | void&nbsp;(\*Release)(struct&nbsp;HdfChipDriver&nbsp;\*chipDriver) | Releases the chip driver. |
       | uint8_t&nbsp;(\*GetMaxIFCount)(struct&nbsp;HdfChipDriverFactory&nbsp;\*factory) | Obtains the maximum number of interfaces supported by the current chip. |

    The **Build** method creates an **HdfChipDriver** object that manages the specified network interface. This object needs to provide the following methods:

       | Method | Description |
       | -------- | -------- |
       | int32_t&nbsp;(\*init)(struct&nbsp;HdfChipDriver&nbsp;\*chipDriver,&nbsp;NetDevice&nbsp;\*netDev) | Initializes the current network interface. The **NetDeviceInterFace** needs to be provided for the **netDev**. |
       | int32_t&nbsp;(\*deinit)(struct&nbsp;HdfChipDriver&nbsp;\*chipDriver,&nbsp;NetDevice&nbsp;\*netDev) | Deinitializes the current network interface. |
       | struct&nbsp;HdfMac80211BaseOps&nbsp;\*ops | Provides the WLAN basic capability interface set. |
       | struct&nbsp;HdfMac80211STAOps&nbsp;\*staOps | Provides the interface set required for supporting the STA mode. |
       | struct&nbsp;HdfMac80211APOps&nbsp;\*apOps | Provides the interface set required for supporting the AP mode. |

2.  Create a configuration file to describe the chips supported by the driver.

    Create a chip configuration file in the product configuration directory and save it to the source code path **//vendor/vendor\_name/product\_name/config/wifi/wlan\_chip\_chip\_name.hcs**.

    


       ```
       root {
           wlan_config {
               chip_name :& chipList {
                   chip_name :: chipInst {
                       match_attr = "hdf_wlan_chips_chip_name"; /* Indicates the configuration matching attribute, which is used to provide the configuration root of the driver. */
                       driverName = "driverName"; /* Indicates the driver name, which must be the same as that of driverName in HdfChipDriverFactory.*/
                       sdio {
                           vendorId = 0xXXXX; /* your vendor id */
                           deviceId = [0xXXXX]; /*your supported devices */
                       }
                   }
               }
           }
       }
       ```

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
       >
       > Replace the values of **vendor\_name**, **product\_name**, and **chip\_name** in the path and file with the actual names.
       > 
       > Set **vendorId** and **deviceId** to the actual vendor ID and chip ID, respectively.

3.  Edit the configuration file and load the driver.

    All device information of the product is defined in the source code file **//vendor/vendor\_name/product\_name/config/device\_info/device\_info.hcs**. Modify the file and add configurations to the **device** named **device\_wlan\_chips** in the **host** of the **network** command. The sample code is as follows:


       ```
       deviceN :: deviceNode {
           policy = 0;
           preload = 2;
           moduleName = "HDF_WLAN_CHIPS";
           deviceMatchAttr = "hdf_wlan_chips_chip_name";
           serviceName = "driverName";
       }
       ```

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
       >
       > Make sure the value of **moduleName** is the same as that of **moduleName** in the WLAN driver.

4.  Modify the **Kconfig** file to make the ported WLAN driver appear in the kernel configuration.

    Add configurations to **device/vendor\_name/drivers/Kconfig**. The sample code is as follows:


       ```
       config DRIVERS_HDF_WIFI_chip_name
           bool "Enable chip_name Host driver"
           default n
           depends on DRIVERS_HDF_WLAN   help
             Answer Y to enable chip_name Host driver.
       ```

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
       >
       > Replace **chip\_name** with the actual chip name.

5.  Modify the build script to enable the driver to participate in the kernel build.

    Add the following content to the end of the source code file **//device/vendor\_name/drivers/lite.mk**:


       ```
       ifeq ($(LOSCFG_DRIVERS_HDF_WIFI_chip_name), y)
           # After the build is complete, an object named hdf_wlan_chipdriver_chip_name needs to be linked. You are advised to use this name to prevent conflicts.
           LITEOS_BASELIB += -lhdf_wlan_chipdriver_chip_name
           # Add the build directory gpio.
           LIB_SUBDIRS    += ../peripheral/wifi/chip_name
       endif
       ```

       > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
       >
       > Replace **chip_name**  with the actual chip name.


