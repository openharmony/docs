# Standard System Porting Guide<a name="EN-US_TOPIC_0000001180064129"></a>

This document describes the general process for porting a development board, rather than the porting process specific to a System on Chip \(SoC\). In the future, the community will provide more development board porting examples for your reference.

## Defining a Development Board<a name="section132mcpsimp"></a>

This document uses the process of porting a development board named **MyProduct** as an example. This development board is provided by **MyProductVendor** and uses the SoC **MySOC** produced by **MySoCVendor**.

### Defining a Product<a name="section145mcpsimp"></a>

Create a **config.json** file in the directory **//vendor/MyProductVendor/*{product_name}***. This file is used to describe the SoC used by the product and the required subsystems.

For example, if **product_name** is **MyProduct**, configure the **//vendor/MyProductVendor/MyProduct/config.json** file as follows:


```
{
    "product_name": "MyProduct",
    "version": "3.0",
    "type": "standard",
    "target_cpu": "arm",
    "ohos_version": "OpenHarmony 1.0",
    "device_company": "MyProductVendor",
    "board": "MySOC",
    "enable_ramdisk": true,
    "subsystems": [
      {
        "subsystem": "ace",
        "components": [
          { "component": "ace_engine_lite", "features":[""] }
        ]
      }，
	    …
    ]
}


```

The main configurations are as follows:

**product_name**: product name. This parameter is required.

**version**: version. This parameter is required.

**type**: system level, which can be **mini**, **small**, or **standard**. This parameter is required.

**target_cpu**: CPU type of the device (depending on the actual situation, the target_cpu here may also be arm64, riscv, x86, etc..). This parameter is required.

**ohos_version**: operating system version. This parameter is optional.

**device_company**: device manufacturer name. This parameter is required.

**board**: board name. This parameter is required.

**enable_ramdisk**: whether to enable the RAM disk. This parameter is required.

**kernel_type** and **kernel_version**: fixed in the standard system. They are optional.

**subsystems**: subsystem to enable. A subsystem can be treated as an independently built functional block. This parameter is required.

**product_company**: device manufacturer name. It is not set in the configuration, but in the directory name, next to the vendor name. It can be accessed from **build.gn script**.

You can find predefined subsystems in **//build/subsystem\_config.json**. You can also customize subsystems.

You are advised to copy the configuration file of Hi3516D V300 and delete the **hisilicon\_products** subsystem, which is used to compile the kernel for Hi3516D V300.

### Verifying the Porting<a name="section163mcpsimp"></a>

Run the following command to start the build of your product:

```
./build.sh --product-name MyProduct 
```

After the build is complete, you can view the built OpenHarmony image file in **//out/{device_name}/packages/phone/images**.

## Porting the Kernel<a name="section171mcpsimp"></a>

Now, you need to port the Linux kernel to enable it to run successfully.

### 1. Adding a Kernel-built Subsystem to the SoC<a name="section174mcpsimp"></a>

Add the following subsystem configuration to the **//build/subsystem\_config.json** file:

```
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

Then, open the configuration file **//vendor/MyProductVendor/MyProduct/config.json**, which is used to define the product, and add the new subsystem to the product.

### 2. Building the Kernel<a name="section182mcpsimp"></a>

The OpenHarmony source code provides the Linux kernel 4.19, which is archived in **//kernel/linux-4.19**. This section uses this kernel version as an example to describe how to build the kernel.

The path for building the subsystem is defined when you define the subsystem in the previous step. The path is **//device/MySOCVendor/MySOC/build**. Now, you need to create a build script in this path to instruct the build system to build the kernel.

The recommended directory structure is as follows:

```
├── build
│ ├── kernel
│ │     ├── linux
│ │           ├──standard_patch_for_4_19.patch // Patch for the Linux kernel 4.19
│ ├── BUILD.gn
│ ├── ohos.build
```

The **BUILD.gn** file is the only entry for building the subsystem.

The expected build result is as follows:

<a name="table193mcpsimp"></a>
<table><tbody><tr id="row198mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry199mcpsimpp0"><a name="entry199mcpsimpp0"></a><a name="entry199mcpsimpp0"></a>File</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry200mcpsimpp0"><a name="entry200mcpsimpp0"></a><a name="entry200mcpsimpp0"></a>Description</p>
</td>
</tr>
<tr id="row201mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry202mcpsimpp0"><a name="entry202mcpsimpp0"></a><a name="entry202mcpsimpp0"></a>$root_build_dir/packages/phone/images/uImage</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry203mcpsimpp0"><a name="entry203mcpsimpp0"></a><a name="entry203mcpsimpp0"></a>Kernel image</p>
</td>
</tr>
<tr id="row204mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry205mcpsimpp0"><a name="entry205mcpsimpp0"></a><a name="entry205mcpsimpp0"></a>$root_build_dir/packages/phone/images/uboot</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry206mcpsimpp0"><a name="entry206mcpsimpp0"></a><a name="entry206mcpsimpp0"></a>Bootloader image</p>
</td>
</tr>
</tbody>
</table>

### 3. Verifying the Porting<a name="section207mcpsimp"></a>

Now start build, and check whether the kernel image is generated as expected.

## Porting the HDF Driver<a name="section210mcpsimp"></a>

### 1. LCD<a name="section212mcpsimp"></a>

This section describes how to port a Liquid Crystal Display \(LCD\) driver. The hardware driver framework \(HDF\) designs a driver model for the LCD. To support an LCD, you must compile a driver, generate a model instance in the driver, and register the instance.

The LCD drivers are stored in the **//drivers/framework/model/display/driver/panel** directory.

-   Create a panel driver.

In the **Init** method of the driver, call **RegisterPanel** to register the model instance.

```
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

-   Configure and load the panel driver. All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs** file. Modify the file by adding configurations for the device named **device\_lcd** to the host named **display**. Note: The value of **moduleName** must be the same as that in the panel driver.

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

For details about driver development, see [LCD](../driver/driver-peripherals-lcd-des.md).

### 2. Touchscreen<a name="section229mcpsimp"></a>

This section describes how to port a touchscreen driver. The touchscreen driver is stored in the **//drivers/framework/model/input/driver/touchscreen** directory. To port a touchscreen driver, register a **ChipDevice** model instance.

-   Create a touchscreen driver.

Create the **touch\_ic\_name.c** file in the directory. Replace **ic\_name** with the name of your chip. The file template is as follows:

```
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

<a name="table240mcpsimp"></a>
<table><tbody><tr id="row245mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry246mcpsimpp0"><a name="entry246mcpsimpp0"></a><a name="entry246mcpsimpp0"></a>Interface</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry247mcpsimpp0"><a name="entry247mcpsimpp0"></a><a name="entry247mcpsimpp0"></a>Description</p>
</td>
</tr>
<tr id="row248mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry249mcpsimpp0"><a name="entry249mcpsimpp0"></a><a name="entry249mcpsimpp0"></a>int32_t (*Init)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry250mcpsimpp0"><a name="entry250mcpsimpp0"></a><a name="entry250mcpsimpp0"></a>Initializes a touchscreen.</p>
</td>
</tr>
<tr id="row251mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry252mcpsimpp0"><a name="entry252mcpsimpp0"></a><a name="entry252mcpsimpp0"></a>int32_t (*Detect)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry253mcpsimpp0"><a name="entry253mcpsimpp0"></a><a name="entry253mcpsimpp0"></a>Detects a touchscreen.</p>
</td>
</tr>
<tr id="row254mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry255mcpsimpp0"><a name="entry255mcpsimpp0"></a><a name="entry255mcpsimpp0"></a>int32_t (*Suspend)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry256mcpsimpp0"><a name="entry256mcpsimpp0"></a><a name="entry256mcpsimpp0"></a>Suspends a touchscreen.</p>
</td>
</tr>
<tr id="row257mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry258mcpsimpp0"><a name="entry258mcpsimpp0"></a><a name="entry258mcpsimpp0"></a>int32_t (*Resume)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry259mcpsimpp0"><a name="entry259mcpsimpp0"></a><a name="entry259mcpsimpp0"></a>Resumes a touchscreen.</p>
</td>
</tr>
<tr id="row260mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry261mcpsimpp0"><a name="entry261mcpsimpp0"></a><a name="entry261mcpsimpp0"></a>int32_t (*DataHandle)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry262mcpsimpp0"><a name="entry262mcpsimpp0"></a><a name="entry262mcpsimpp0"></a>Reads data from a touchscreen and writes the touch point data to <strong id="b109171435105216"><a name="b109171435105216"></a><a name="b109171435105216"></a>device</strong> &gt; <strong id="b103219389526"><a name="b103219389526"></a><a name="b103219389526"></a>driver</strong> &gt; <strong id="b0459173945212"><a name="b0459173945212"></a><a name="b0459173945212"></a>frameData</strong>.</p>
</td>
</tr>
<tr id="row263mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry264mcpsimpp0"><a name="entry264mcpsimpp0"></a><a name="entry264mcpsimpp0"></a>int32_t (*UpdateFirmware)(ChipDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry265mcpsimpp0"><a name="entry265mcpsimpp0"></a><a name="entry265mcpsimpp0"></a>Upgrades the firmware.</p>
</td>
</tr>
</tbody>
</table>

-   Configure the product and load the driver.

    All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs** file. Modify the file by adding configurations for the device named **device\_touch\_chip** to the host named **input**. Note: The value of **moduleName** must be the same as that in the touchscreen driver.


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

For details about driver development, see [TOUCHSCREEN](../driver/driver-peripherals-touch-des.md).

### 3. WLAN<a name="section274mcpsimp"></a>

The WLAN driver is divided into two parts. One of the parts manages WLAN devices, and the other part manages WLAN traffic. HDF WLAN provides abstraction for the two parts. Currently, only the WLAN with the SDIO interface is supported.

**Figure 1** WLAN chip<a name="fig16997123013494"></a>  
![](figures/wlan-chip.png "wlan-chip")

To support a chip, implement a **ChipDriver** for it. The major task is to implement the following interfaces provided by **HDF\_WLAN\_CORE** and **NetDevice**.

<a name="table280mcpsimp"></a>
<table><tbody><tr id="row286mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry287mcpsimpp0"><a name="entry287mcpsimpp0"></a><a name="entry287mcpsimpp0"></a>Interface</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry288mcpsimpp0"><a name="entry288mcpsimpp0"></a><a name="entry288mcpsimpp0"></a>Header File</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry289mcpsimpp0"><a name="entry289mcpsimpp0"></a><a name="entry289mcpsimpp0"></a>Description</p>
</td>
</tr>
<tr id="row290mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry291mcpsimpp0"><a name="entry291mcpsimpp0"></a><a name="entry291mcpsimpp0"></a>HdfChipDriverFactory</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p136856366385"><a name="p136856366385"></a><a name="p136856366385"></a>//drivers/framework/include/wifi/hdf_wlan_chipdriver_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry294mcpsimpp0"><a name="entry294mcpsimpp0"></a><a name="entry294mcpsimpp0"></a>Factory of the <strong id="b0602182913593"><a name="b0602182913593"></a><a name="b0602182913593"></a>ChipDriver</strong>, which is used to support multiple WLAN interfaces of a chip.</p>
</td>
</tr>
<tr id="row295mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry296mcpsimpp0"><a name="entry296mcpsimpp0"></a><a name="entry296mcpsimpp0"></a>HdfChipDriver</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p714312457389"><a name="p714312457389"></a><a name="p714312457389"></a>//drivers/framework/include/wifi/wifi_module.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry299mcpsimpp0"><a name="entry299mcpsimpp0"></a><a name="entry299mcpsimpp0"></a>Manages a specific WLAN interface. Each WLAN interface corresponds to an <strong id="b1364875755918"><a name="b1364875755918"></a><a name="b1364875755918"></a>HdfChipDriver</strong>.</p>
</td>
</tr>
<tr id="row300mcpsimp"><td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry301mcpsimpp0"><a name="entry301mcpsimpp0"></a><a name="entry301mcpsimpp0"></a>NetDeviceInterFace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="p015815313819"><a name="p015815313819"></a><a name="p015815313819"></a>//drivers/framework/include/net/net_device.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%"><p id="entry304mcpsimpp0"><a name="entry304mcpsimpp0"></a><a name="entry304mcpsimpp0"></a>Communicates with the protocol stack, such as sending data and setting the status of network interfaces.</p>
</td>
</tr>
</tbody>
</table>

To port a WLAN driver, perform the following steps:

1. Create an HDF driver. You are advised to place the code file in the **//device/MySoCVendor/peripheral/wifi/chip\_name/** directory. The file template is as follows:

```
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

<a name="table312mcpsimp"></a>
<table><tbody><tr id="row317mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry318mcpsimpp0"><a name="entry318mcpsimpp0"></a><a name="entry318mcpsimpp0"></a>Interface</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry319mcpsimpp0"><a name="entry319mcpsimpp0"></a><a name="entry319mcpsimpp0"></a>Description</p>
</td>
</tr>
<tr id="row320mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry321mcpsimpp0"><a name="entry321mcpsimpp0"></a><a name="entry321mcpsimpp0"></a>const char *driverName</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry322mcpsimpp0"><a name="entry322mcpsimpp0"></a><a name="entry322mcpsimpp0"></a>Indicates the driver name.</p>
</td>
</tr>
<tr id="row323mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry324mcpsimpp0"><a name="entry324mcpsimpp0"></a><a name="entry324mcpsimpp0"></a>int32_t (*InitChip)(struct HdfWlanDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry325mcpsimpp0"><a name="entry325mcpsimpp0"></a><a name="entry325mcpsimpp0"></a>Initializes a chip.</p>
</td>
</tr>
<tr id="row326mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry327mcpsimpp0"><a name="entry327mcpsimpp0"></a><a name="entry327mcpsimpp0"></a>int32_t (*DeinitChip)(struct HdfWlanDevice *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry328mcpsimpp0"><a name="entry328mcpsimpp0"></a><a name="entry328mcpsimpp0"></a>Deinitializes a chip.</p>
</td>
</tr>
<tr id="row329mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry330mcpsimpp0"><a name="entry330mcpsimpp0"></a><a name="entry330mcpsimpp0"></a>void (_ReleaseFactory)(struct HdfChipDriverFactory _factory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry331mcpsimpp0"><a name="entry331mcpsimpp0"></a><a name="entry331mcpsimpp0"></a>Releases the <strong id="b088418304215"><a name="b088418304215"></a><a name="b088418304215"></a>HdfChipDriverFactory</strong> object.</p>
</td>
</tr>
<tr id="row332mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry333mcpsimpp0"><a name="entry333mcpsimpp0"></a><a name="entry333mcpsimpp0"></a>struct HdfChipDriver _(_Build)(struct HdfWlanDevice *device, uint8_t ifIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry334mcpsimpp0"><a name="entry334mcpsimpp0"></a><a name="entry334mcpsimpp0"></a>Creates an <strong id="b1253415231438"><a name="b1253415231438"></a><a name="b1253415231438"></a>HdfChipDriver</strong>. In the input parameters, <strong id="b45408231539"><a name="b45408231539"></a><a name="b45408231539"></a>device</strong> indicates the device information, and <strong id="b1154116231432"><a name="b1154116231432"></a><a name="b1154116231432"></a>ifIndex</strong> indicates the sequence number of this interface in the chip.</p>
</td>
</tr>
<tr id="row335mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry336mcpsimpp0"><a name="entry336mcpsimpp0"></a><a name="entry336mcpsimpp0"></a>void (_Release)(struct HdfChipDriver _chipDriver)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry337mcpsimpp0"><a name="entry337mcpsimpp0"></a><a name="entry337mcpsimpp0"></a>Releases the <strong id="b155367141846"><a name="b155367141846"></a><a name="b155367141846"></a>HdfChipDriver</strong>.</p>
</td>
</tr>
<tr id="row338mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry339mcpsimpp0"><a name="entry339mcpsimpp0"></a><a name="entry339mcpsimpp0"></a>uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry340mcpsimpp0"><a name="entry340mcpsimpp0"></a><a name="entry340mcpsimpp0"></a>Obtains the maximum number of interfaces supported by the current chip.</p>
</td>
</tr>
</tbody>
</table>

Implement the following interfaces in the **HdfChipDriver**.

<a name="table342mcpsimp"></a>
<table><tbody><tr id="row347mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry348mcpsimpp0"><a name="entry348mcpsimpp0"></a><a name="entry348mcpsimpp0"></a>Interface</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry349mcpsimpp0"><a name="entry349mcpsimpp0"></a><a name="entry349mcpsimpp0"></a>Description</p>
</td>
</tr>
<tr id="row350mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry351mcpsimpp0"><a name="entry351mcpsimpp0"></a><a name="entry351mcpsimpp0"></a>int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry352mcpsimpp0"><a name="entry352mcpsimpp0"></a><a name="entry352mcpsimpp0"></a>Initializes the current network interface. The <strong id="b936614441419"><a name="b936614441419"></a><a name="b936614441419"></a>NetDeviceInterFace</strong> needs to be provided for the <strong id="b1237215441347"><a name="b1237215441347"></a><a name="b1237215441347"></a>netDev</strong>.</p>
</td>
</tr>
<tr id="row353mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry354mcpsimpp0"><a name="entry354mcpsimpp0"></a><a name="entry354mcpsimpp0"></a>int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry355mcpsimpp0"><a name="entry355mcpsimpp0"></a><a name="entry355mcpsimpp0"></a>Deinitializes the current network interface.</p>
</td>
</tr>
<tr id="row356mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry357mcpsimpp0"><a name="entry357mcpsimpp0"></a><a name="entry357mcpsimpp0"></a>struct HdfMac80211BaseOps *ops</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry358mcpsimpp0"><a name="entry358mcpsimpp0"></a><a name="entry358mcpsimpp0"></a>Provides the WLAN basic capability interface set.</p>
</td>
</tr>
<tr id="row359mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry360mcpsimpp0"><a name="entry360mcpsimpp0"></a><a name="entry360mcpsimpp0"></a>struct HdfMac80211STAOps *staOps</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry361mcpsimpp0"><a name="entry361mcpsimpp0"></a><a name="entry361mcpsimpp0"></a>Provides the interface set required for supporting the standalone (STA) mode.</p>
</td>
</tr>
<tr id="row362mcpsimp"><td class="cellrowborder" valign="top" width="50%"><p id="entry363mcpsimpp0"><a name="entry363mcpsimpp0"></a><a name="entry363mcpsimpp0"></a>struct HdfMac80211APOps *apOps</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="entry364mcpsimpp0"><a name="entry364mcpsimpp0"></a><a name="entry364mcpsimpp0"></a>Provides the interface set required for supporting the access point (AP) mode.</p>
</td>
</tr>
</tbody>
</table>

2. Compile the configuration file to describe the devices supported by the driver.

Create the chip configuration file **//vendor/MyProductVendor/MyProduct/config/wifi/wlan\_chip\_chip\_name.hcs** in the product configuration directory.

Replace **MyProductVendor**, **MyProduct**, and **chip\_name** in the path with the actual names.

The sample code is as follows:

```
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

All device information about the product is defined in the **//vendor/MyProductVendor/MyProduct/config/device\_info/device\_info.hcs** file. Modify the file by adding configurations for the device named **device\_wlan\_chips** to the host named **network**. Note: The value of **moduleName** must be the same as that in the touchscreen driver.

```
                deviceN :: deviceNode {
                    policy = 0;
                    preload = 2;
                    moduleName = "HDF_WLAN_CHIPS";
                    deviceMatchAttr = "hdf_wlan_chips_chip_name";
                    serviceName = "driverName";
                }
```

4. Build the driver.

-   Create a kernel configuration menu. Create a **Kconfig** file in the **//device/MySoCVendor/peripheral** directory. The file template is as follows:

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

-   Create a build script.

    Add the following configuration to the end of the **//drivers/adapter/khdf/linux/model/network/wifi/Makefile** file:


```
HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
```

When **DRIVERS\_WLAN\_XXX** is enabled in the kernel, **makefile** in **//device/MySoCVendor/peripheral/build/standard/** is called. For more details, see [WLAN Development](../guide/device-wlan-led-control.md).

### 4. Samples<a name="section11253153018415"></a>

For details about the porting sample, see the DAYU development board adaptation guide.

