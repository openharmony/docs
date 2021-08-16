# Standard System Porting Guide

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Defining a Development Board](#Defining-a-Development-Board)
  - [1. Defining an SoC](#1-Defining-an-SoC)
  - [2. Defining a Product](#2-Defining-a-Product)
  - [3. Verifying the Porting](#3-Verifying-the-Porting)
- [Porting the Kernel](#Porting-the-Kernel)
  - [1. Adding a Kernel-built Subsystem to the SoC](#1-Adding-a-Kernel-built-Subsystem-to-the-SoC)
  - [2. Building the Kernel](#2-Building-the-Kernel)
  - [3. Verifying the Porting](#3-Verifying-the-Porting-1)
- [Porting the HDF Driver](#Porting-the-HDF-Driver)
  - [1. LCD](#1-lcd)
  - [2. Touchscreen](#2-Touchscreen)
  - [3. WLAN](#3-wlan)

<!-- /code_chunk_output -->

This document describes the general process for porting a development board, rather than the porting process specific to a System on Chip (SoC). In the future, the community will provide more development board porting examples for your reference.

## Defining a Development Board

This document uses the process of porting a development board named **MyProduct** as an example. This development board is provided by **MyProductVendor** and uses the SoC **MySOC** produced by **MySoCVendor**.

### 1. Defining an SoC

Create a JSON file named after the SoC name in the **//productdefine/common/device** directory and specify the CPU architecture.

For example, to port **MySOC**, which uses a 32-bit ARM kernel, configure the file as follows:

`//productdefine/common/device/MySOC.json`
```json
{
    "target_os": "ohos",
    "target_cpu": "arm"
}
```
Currently, **target_cpu** can be set to **arm** only. In the future, you can set the value depending on the CPU architecture, such as **arm64**, **riscv**, or **x86**.

### 2. Defining a Product

Create a JSON file named after the product name in the **//productdefine/common/products** directory. This file is used to describe the SoC used by the product and the required subsystems.
Configure the file as follows:
`//productdefine/common/products/MyProduct.json`
```json
{
  "product_name": "MyProduct",
  "product_company" : "MyProductVendor",
  "product_device": "MySOC",
  "version": "2.0",
  "type": "standard",
  "parts":{
    "ace:ace_engine_standard":{},
    "ace:napi":{},
    ...
    "xts:phone_tests":{}
  }
}

```
The main configurations are as follows:

1. **product_device**: SoC used by the product.
2. **type**: system level. In this example, set it to **standard**.
3. **parts**: subsystems to enable. A subsystem can be treated as an independently built functional block.

You can find available subsystems in **//build/subsystem_config.json**. You can also customize subsystems.

You are advised to copy the configuration file of Hi3516D V300 and delete the **hisilicon_products** subsystem, which is used to compile the kernel for Hi3516D V300.

### 3. Verifying the Porting

Run the following command to start the build of your product:

`./build.sh --product-name MyProduct `

After the build is complete, you can view the built OpenHarmony image file in the following directory:

`//out/ohos-arm-release/packages/phone/images`

## Porting the Kernel

Now, you need to port the Linux kernel to enable it to run successfully.

### 1. Adding a Kernel-built Subsystem to the SoC

Add the following subsystem configuration to the **//build/subsystem_config.json** file:

```json
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

Then, open the configuration file **//productdefine/common/products/MyProduct.json**, which is used to define the product, and add the new subsystem to the product.

### 2. Building the Kernel

The path for building the subsystem is defined when you define the subsystem in the previous step. The path is **//device/MySOCVendor/MySOC/build**. Now, you need to create a build script in this path to instruct the build system to build the kernel.

Currently, the OpenHarmony source code provides the Linux kernel 4.19, which is archived in **//kernel/linux-4.19**. You are advised to use this kernel. However, if the SoC vendor does not provide the kernel of this version, use that provided by the vendor.
You are advised to use patches to modify or extend the SoC kernel.

The recommended directory structure is as follows:
```
├── build
│   ├── kernel
│   │     ├── linux
│   │           ├──standard_patch_for_4_19.patch
│   ├── BUILD.gn
│   ├── ohos.build
```
The **BUILD.gn** file is the only entry for building the subsystem.

The expected build result is as follows:

| File| Description|
|------|------|
|$root_build_dir/packages/phone/images/uImage| Kernel image|
|$root_build_dir/packages/phone/images/uboot | Bootloader image|

### 3. Verifying the Porting

Now start build, and check whether the kernel image is generated as expected.

## Porting the HDF Driver

### 1. LCD
This section describes how to port a Liquid Crystal Display (LCD) driver. The hardware driver framework (HDF) designs a driver model for the LCD. To support an LCD, you must compile a driver, generate a model instance in the driver, and register the instance.

The LCD drivers are stored in the **//drivers/framework/model/display/driver/panel** directory.

- Create a panel driver.

In the **Init** method of the driver, call **RegisterPanel** to register the model instance.
```C
int32_t XXXInit(struct HdfDeviceObject *object)
{
    struct PanelData *panel = CreateYourPanel();

    // Register the model instance.
    if (RegisterPanel(panel) != HDF_SUCCESS) {
        HDF_LOGE("%s: RegisterPanel failed", __func__);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_xxxxDevEntry = {
    .moduleVersion = 1,
    .moduleName = "LCD_XXXX",
    .Init = XXXInit,
};

HDF_INIT(g_xxxxDevEntry);
```

- Configure and load the panel driver.
All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs** file. Modify the file by adding configurations for the device named **device_lcd** to the host named **display**.
Note: The value of **moduleName** must be the same as that in the panel driver.

```hcs
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

For details about driver development, see [LCD](https://gitee.com/openharmony/docs/blob/master/en/device-dev/driver/driver-peripherals-lcd-des.md).

### 2. Touchscreen
This section describes how to port a touchscreen driver. The touchscreen driver is stored in the **//drivers/framework/model/input/driver/touchscreen** directory. To port a touchscreen driver, register a **ChipDevice** model instance.

- Create a touchscreen driver.

Create the **touch_ic_name.c** file in the directory. Replace **ic_name** with the name of your chip. The file template is as follows:

```C
#include "hdf_touch.h"

static int32_t HdfXXXXChipInit(struct HdfDeviceObject *device)
{
    ChipDevice *tpImpl = CreateXXXXTpImpl();
    if(RegisterChipDevice(tpImpl) != HDF_SUCCESS) {
        ReleaseXXXXTpImpl(tpImpl);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_touchXXXXChipEntry = {
    .moduleVersion = 1,
    .moduleName = "HDF_TOUCH_XXXX",
    .Init = HdfXXXXChipInit,
};

HDF_INIT(g_touchXXXXChipEntry);
```

Implement the following interfaces in **ChipDevice**:
| Interface| Description|
|------|------|
|int32_t (*Init)(ChipDevice *device)| Initializes a touchscreen.|
|int32_t (*Detect)(ChipDevice *device)| Detects a touchscreen.|
|int32_t (*Suspend)(ChipDevice *device)| Suspends a touchscreen.|
|int32_t (*Resume)(ChipDevice *device)| Resumes a touchscreen.|
|int32_t (*DataHandle)(ChipDevice *device)| Reads data from a touchscreen and writes the touch point data to **device > driver > frameData**.|
|int32_t (*UpdateFirmware)(ChipDevice *device)| Upgrades the firmware.|

- Configure the product and load the driver.

All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs** file. Modify the file by adding configurations for the device named **device_touch_chip** to the host named **input**.
Note: The value of **moduleName** must be the same as that in the touchscreen driver.

```hcs
                deviceN :: deviceNode {
                    policy = 0;
                    priority = 130;
                    preload = 0;
                    permission = 0660;
                    moduleName = "HDF_TOUCH_XXXX";
                    deviceMatchAttr = "touch_XXXX_configs";
                }
```

For details about driver development, see [TOUCHSCREEN](https://gitee.com/openharmony/docs/blob/master/en/device-dev/driver/driver-peripherals-touch-des.md).


### 3. WLAN

The WLAN driver is divided into two parts. One of the parts manages WLAN devices, and the other part manages WLAN traffic. **HDF WLAN** provides abstraction for the two parts. Currently, only the WLAN with the SDIO interface is supported.

<img src="./figure/hdf_wifi.png" alt="WLAN structure" width="800"/>

To support a chip, implement a **ChipDriver** for it. The major task is to implement the following interfaces provided by **HDF_WLAN_CORE** and **NetDevice**.

| Interface| Header File| Description|
|------|------|------|
| HdfChipDriverFactory| `//drivers/framework/include/wifi/hdf_wlan_chipdriver_manager.h`| Factory of the **ChipDriver**, which is used to support multiple WLAN interfaces of a chip.|
| HdfChipDriver | `//drivers/framework/include/wifi/wifi_module.h`| Manages a specific WLAN interface. Each WLAN interface corresponds to an **HdfChipDriver**.|
|NetDeviceInterFace| `//drivers/framework/include/wifi/net_device.h`| Communicates with the protocol stack, such as sending data and setting the status of network interfaces.|

To port a WLAN driver, perform the following steps:

1. Create an HDF driver.

You are advised to place the code file in the **//device/MySoCVendor/peripheral/wifi/chip_name/** directory.
The file template is as follows:

```C
static int32_t HdfWlanHisiChipDriverInit(struct HdfDeviceObject *device) {
    static struct HdfChipDriverFactory factory = CreateChipDriverFactory();
    struct HdfChipDriverManager *driverMgr = HdfWlanGetChipDriverMgr();
    if (driverMgr->RegChipDriver(&factory) != HDF_SUCCESS) {
        HDF_LOGE("%s fail: driverMgr is NULL!", __func__);
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}

struct HdfDriverEntry g_hdfXXXChipEntry = {
    .moduleVersion = 1,
    .Init = HdfWlanXXXChipDriverInit,
    .Release = HdfWlanXXXChipRelease,
    .moduleName = "HDF_WIFI_CHIP_XXX"
};

HDF_INIT(g_hdfXXXChipEntry);
```

Create an **HdfChipDriverFactory** in the **CreateChipDriverFactory**. The interfaces are as follows:
| Interface| Description|
|------|------|
|const char *driverName| Indicates the driver name.|
|int32_t (*InitChip)(struct HdfWlanDevice *device)| Initializes a chip.|
|int32_t (*DeinitChip)(struct HdfWlanDevice *device)| Deinitializes a chip.|
|void (*ReleaseFactory)(struct HdfChipDriverFactory *factory)| Releases the **HdfChipDriverFactory** object.|
|struct HdfChipDriver *(*Build)(struct HdfWlanDevice *device, uint8_t ifIndex)|Creates an **HdfChipDriver**. In the input parameters, **device** indicates the device information, and **ifIndex** indicates the sequence number of this interface in the chip.|
|void (*Release)(struct HdfChipDriver *chipDriver)| Releases the **HdfChipDriver**.
|uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)| Obtains the maximum number of interfaces supported by the current chip.|

Implement the following interfaces in the **HdfChipDriver**.

|Interface| Description|
|------|------|
|int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| Initializes the current network interface. The **NetDeviceInterFace** needs to be provided for the **netDev**.|
|int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| Deinitializes the current network interface.|
|struct HdfMac80211BaseOps *ops| Provides the WLAN basic capability interface set.|
|struct HdfMac80211STAOps *staOps| Provides the interface set required for supporting the standalone (STA) mode.|
|struct HdfMac80211APOps *apOps| Provides the interface set required for supporting the access point (AP) mode.|



2. Compile the configuration file to describe the devices supported by the driver.

Create the chip configuration file **//vendor/MyProductVendor/MyProduct/config/wifi/wlan_chip_chip_name.hcs** in the product configuration directory.
Replace **MyProductVendor**, **MyProduct**, and **chip_name** in the path with the actual names.
The sample code is as follows:
```hcs
root {
    wlan_config {
        chip_name :& chipList {
            chip_name :: chipInst {
                match_attr = "hdf_wlan_chips_chip_name"; /* Configure the matching attribute, which is used to provide the configuration root of the driver.*/
                driverName = "driverName"; /* The value must be the same as that of driverName in HdfChipDriverFactory.*/
                sdio {
                    vendorId = 0x0296;
                    deviceId = [0x5347];
                }
            }
        }
    }
}
```

3. Edit the configuration file and load the driver.

All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs** file. Modify the file by adding configurations for the device named **device_wlan_chips** to the host named **network**.
Note: The value of **moduleName** must be the same as that in the touchscreen driver.
The sample code is as follows:

```hcs
                deviceN :: deviceNode {
                    policy = 0;
                    preload = 2;
                    moduleName = "HDF_WLAN_CHIPS";
                    deviceMatchAttr = "hdf_wlan_chips_chip_name";
                    serviceName = "driverName";
                }
```

4. Build the driver.

- Create a kernel configuration menu.
Create a **Kconfig** file in the **//device/MySoCVendor/peripheral** directory. The file template is as follows:
```
config DRIVERS_WLAN_XXX
    bool "Enable XXX WLAN Host driver"
    default n
    depends on DRIVERS_HDF_WIFI
    help
      Answer Y to enable XXX Host driver. Support chip xxx
```

Add the following sample code to the end of the **//drivers/adapter/khdf/linux/model/network/wifi/Kconfig** file to add the configuration menu to the kernel:
```
source "../../../../../device/MySoCVendor/peripheral/Kconfig"
```

- Create a build script.

Add the following configuration to the end of the **//drivers/adapter/khdf/linux/model/network/wifi/Makefile** file:

```
HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
```

When **DRIVERS_WLAN_XXX** is enabled in the kernel, **makefile** in **//device/MySoCVendor/peripheral/build/standard/** is called.


For more details, see [WLAN Development](https://gitee.com/openharmony/docs/blob/master/en/device-dev/guide/device-wifi.md).
