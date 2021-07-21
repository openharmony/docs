<<<<<<< HEAD
# 标准系统移植指南

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [定义开发板](#定义开发板)
  - [1. 定义SOC](#1-定义soc)
  - [2. 定义产品](#2-定义产品)
  - [3. 移植验证](#3-移植验证)
- [内核移植](#内核移植)
  - [1. 为SOC添加内核构建的子系统](#1-为soc添加内核构建的子系统)
  - [2. 编译内核](#2-编译内核)
  - [3. 移植验证](#3-移植验证-1)
- [HDF驱动移植](#hdf驱动移植)
  - [1. LCD](#1-lcd)
  - [2. 触摸屏](#2-触摸屏)
  - [3. WLAN](#3-wlan)

<!-- /code_chunk_output -->



## 定义开发板

本文以移植名为MyProduct的开发板为例讲解移植过程，假定MyProduct是MyProductVendor公司的开发板，使用MySoCVendor公司生产的MySOC芯片作为处理器。

### 1. 定义SOC

在`//productdefine/common/device`目录下创建以SOC名字命名的json文件，并指定CPU的架构。

如要移植一个叫MySOC的SOC，这个SOC采用32位ARM内核。配置如下：

`//productdefine/common/device/MySOC.json`
```json
{
    "target_os": "ohos",
    "target_cpu": "arm"
}
```
根据实际情况，这里的target_cpu也可能是arm64 、riscv、 x86等。当前仅支持arm作为target_cpu。

### 2. 定义产品

在`//productdefine/common/products`目录下创建以产品名命名的json文件。该文件用于描述产品所使用的SOC 以及 所需的子系统。
配置如下
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
主要的配置内容包括：

1. `product_device`：配置所使用的SOC
2. `type`： 配置系统的级别， 这里直接standard即可
3. `parts`： 系统需要启用的子系统。子系统可以简单理解位一块独立构建的功能块。

已定义的子系统可以在`//build/subsystem_config.json`中找到。当然你也可以定制子系统。

这里建议先拷贝Hi3516DV300 开发板的配置文件，删除掉 hisilicon_products 这个子系统。这个子系统为Hi3516DV300 SOC编译内核，显然不适合MySOC。

### 3. 移植验证

至此，你可以使用如下命令，启动你产品的构建了：

`./build.sh --product-name MyProduct `

构建完成后，可以在如下目录看到构建出来的OpenHarmony镜像文件

`//out/ohos-arm-release/packages/phone/images`

## 内核移植

这一步需要移植Linux内核，让Linux内核可以成功运行起来。

### 1. 为SOC添加内核构建的子系统

修改文件 `//build/subsystem_config.json` 增加一个子系统. 配置如下：

```json
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

接着需要修改定义产品的配置文件`//productdefine/common/products/MyProduct.json`。将刚刚定义的子系统加入到产品中

### 2. 编译内核

在上一节定义subsystem的时候，定义了构建的路径path，即`//device/MySOCVendor/MySOC/build`。这一节会在这个目录创建构建脚本，告诉构建系统如何构建内核。

目前OpenHarmony源码中提供了Linux 4.19的内核，归档在`//kernel/linux-4.19`。请尽可能使用这个内核。
每个SOC必然需要对内核做一些修改或扩展，建议采用补丁的方式。

建议的目录结构
```
├── build
│   ├── kernel
│   │     ├── linux
│   │           ├──standard_patch_for_4_19.patch
│   ├── BUILD.gn
│   ├── ohos.build
```
BUILD.gn是subsystem构建的唯一入口。

期望的构建结果

| 文件 | 文件说明|
|------|------|
|$root_build_dir/packages/phone/images/uImage| 内核镜像|
|$root_build_dir/packages/phone/images/uboot | bootloader镜像|

### 3. 移植验证

启动编译，验证预期的kernel镜像是否成功生成。

## HDF驱动移植

### 1. LCD
HDF为LCD设计了驱动模型。支持一块新的LCD，需要编写一个驱动，在驱动中生成模型的实例，并完成注册。

这些LCD的驱动被放置在`//drivers/framework/model/display/driver/panel`目录中。

- 创建Panel驱动

在驱动的Init方法中，需要调用RegisterPanel接口注册模型实例。如:
```C
int32_t XXXInit(struct HdfDeviceObject *object)
{
    struct PanelData *panel = CreateYourPanel();

    // 注册
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

- 配置加载panel驱动
产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在display的host中，名为device_lcd的device中增加配置。
注意：moduleName 要与panel驱动中的moduleName相同。

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

更详细的驱动开发指导，请参考 [LCD](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/LCD.md)

### 2. 触摸屏
本节描述如何移植触摸屏驱动。触摸屏的驱动被放置在`//drivers/framework/model/input/driver/touchscreen`目录中。移植触摸屏驱动主要工作是向系统注册ChipDevice模型实例。

- 创建触摸屏器件驱动

在目录中创建名为`touch_ic_name.c`的文件。代码模板如下：
注意：请替换ic_name为你所适配芯片的名称

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

其中ChipDevice中要提供若干方法
| 方法| 实现说明|
|------|------|
|int32_t (*Init)(ChipDevice *device)| 器件初始化|
|int32_t (*Detect)(ChipDevice *device)| 器件探测|
|int32_t (*Suspend)(ChipDevice *device)| 器件休眠|
|int32_t (*Resume)(ChipDevice *device)| 器件唤醒|
|int32_t (*DataHandle)(ChipDevice *device)| 从器件读取数据，将触摸点数据填写入device->driver->frameData中|
|int32_t (*UpdateFirmware)(ChipDevice *device)| 固件升级|

- 配置产品，加载器件驱动

产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为input的host中，名为device_touch_chip的device中增加配置。
注意：moduleName 要与触摸屏驱动中的moduleName相同。

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

更详细的驱动开发指导，请参考 [TOUCHSCREEN](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/TOUCHSCREEN.md)


### 3. WLAN

![tu](./figures/HDF_WIFI.png)

Wi-Fi驱动分为两部分，一部分负责管理WLAN设备，另一个部分负责处理WLAN流量。`HDF WLAN`分别为这两部分做了抽象。目前支持SDIO接口的WLAN芯片

主要需要实现的接口有:

| 接口| 定义头文件| 说明|
|------|------|------|
| HdfChipDriverFactory| `//drivers/framework/include/wifi/hdf_wlan_chipdriver_manager.h`| ChipDriver的Factory，用于支持一个芯片多个Wi-Fi端口|
| HdfChipDriver | `//drivers/framework/include/wifi/wifi_module.h`| 每个WLAN端口对应一个HdfChipDriver，用来管理一个特定的WLAN端口|
|NetDeviceInterFace| `//drivers/framework/include/wifi/net_device.h`| 与协议栈之间的接口，如发送数据、设置网络接口状态等|

建议适配按如下步骤操作：

1. 创建HDF驱动
建议将代码放置在`//device/MySoCVendor/peripheral/wifi/chip_name/`

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

在CreateChipDriverFactory中，需要创建一个HdfChipDriverFactory
| 接口| 说明|
|------|------|
|const char *driverName| 当前driverName |
|int32_t (*InitChip)(struct HdfWlanDevice *device)| 初始化芯片|
|int32_t (*DeinitChip)(struct HdfWlanDevice *device)| 去初始化芯片|
|void (*ReleaseFactory)(struct HdfChipDriverFactory *factory)| 释放HdfChipDriverFactory对象|
|struct HdfChipDriver *(*Build)(struct HdfWlanDevice *device, uint8_t ifIndex)|创建一个HdfChipDriver；输入参数中，device是设备信息，ifIndex是当前创建的接口在这个芯片中的序号|
|void (*Release)(struct HdfChipDriver *chipDriver)| 释放chipDriver
|uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)| 获取当前芯片支持的最大接口数|

HdfChipDriver需要实现的接口有

|接口| 说明|
|------|------|
|int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| 初始化当前网络接口，这里需要向netDev提供接口NetDeviceInterFace|
|int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| 去初始化当前网络接口|
|struct HdfMac80211BaseOps *ops| WLAN基础能力接口集|
|struct HdfMac80211STAOps *staOps| 支持STA模式所需的接口集|
|struct HdfMac80211APOps *apOps| 支持AP模式所需要的接口集|



2. 编写配置文件，描述驱动支持的设备
在产品配置目录下创建芯片的配置文件`//vendor/MyProductVendor/MyProduct/config/wifi/wlan_chip_chip_name.hcs`

注意： 路径中的vendor_name、product_name、chip_name请替换成实际名称
```hcs
root {
    wlan_config {
        chip_name :& chipList {
            chip_name :: chipInst {
                match_attr = "hdf_wlan_chips_chip_name"; /* 这是配置匹配属性，用于提供驱动的配置根 */
                driverName = "driverName"; /* 需要与HdfChipDriverFactory中的driverName相同*/
                sdio {
                    vendorId = 0x0296;
                    deviceId = [0x5347];
                }
            }
        }
    }
}
```

3. 编写配置文件，加载驱动

产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为network的host中，名为device_wlan_chips的device中增加配置。
注意：moduleName 要与触摸屏驱动中的moduleName相同。

```hcs
                deviceN :: deviceNode {
                    policy = 0;
                    preload = 2;
                    moduleName = "HDF_WLAN_CHIPS";
                    deviceMatchAttr = "hdf_wlan_chips_chip_name";
                    serviceName = "driverName";
                }
```

4. 构建驱动

- 创建内核菜单
在 `//device/MySoCVendor/peripheral` 目录中创建Kconfig文件，内容模板如下：
```
config DRIVERS_WLAN_XXX
    bool "Enable XXX WLAN Host driver"
    default n
    depends on DRIVERS_HDF_WIFI
    help
      Answer Y to enable XXX Host driver. Support chip xxx
```

接着修改文件 `//drivers/adapter/khdf/linux/model/network/wifi/Kconfig`,在文件末尾加入如下代码将配置菜单加入内核中
```
source "../../../../../device/MySoCVendor/peripheral/Kconfig"
```

- 创建构建脚本

在`//drivers/adapter/khdf/linux/model/network/wifi/Makefile` 文件末尾增加配置，模板如下

```
HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
```

当在内核中开启`DRIVERS_WLAN_XXX`开关时，会调用`//device/MySoCVendor/peripheral/build/standard/`中的makefile


更多详细的开发手册，请参考[WLAN开发](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/WLAN.md)
=======
# 标准系统移植指南

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [定义开发板](#定义开发板)
  - [1. 定义SOC](#1-定义soc)
  - [2. 定义产品](#2-定义产品)
  - [3. 移植验证](#3-移植验证)
- [内核移植](#内核移植)
  - [1. 为SOC添加内核构建的子系统](#1-为soc添加内核构建的子系统)
  - [2. 编译内核](#2-编译内核)
  - [3. 移植验证](#3-移植验证-1)
- [HDF驱动移植](#hdf驱动移植)
  - [1. LCD](#1-lcd)
  - [2. 触摸屏](#2-触摸屏)
  - [3. WLAN](#3-wlan)

<!-- /code_chunk_output -->



## 定义开发板

本文以移植名为MyProduct的开发板为例讲解移植过程，假定MyProduct是MyProductVendor公司的开发板，使用MySoCVendor公司生产的MySOC芯片作为处理器。

### 1. 定义SOC

在`//productdefine/common/device`目录下创建以SOC名字命名的json文件，并指定CPU的架构。

如要移植一个叫MySOC的SOC，这个SOC采用32位ARM内核。配置如下：

`//productdefine/common/device/MySOC.json`
```json
{
    "target_os": "ohos",
    "target_cpu": "arm"
}
```
根据实际情况，这里的target_cpu也可能是arm64 、riscv、 x86等。当前仅支持arm作为target_cpu。

### 2. 定义产品

在`//productdefine/common/products`目录下创建以产品名命名的json文件。该文件用于描述产品所使用的SOC 以及 所需的子系统。
配置如下
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
主要的配置内容包括：

1. `product_device`：配置所使用的SOC
2. `type`： 配置系统的级别， 这里直接standard即可
3. `parts`： 系统需要启用的子系统。子系统可以简单理解位一块独立构建的功能块。

已定义的子系统可以在`//build/subsystem_config.json`中找到。当然你也可以定制子系统。

这里建议先拷贝Hi3516DV300 开发板的配置文件，删除掉 hisilicon_products 这个子系统。这个子系统为Hi3516DV300 SOC编译内核，显然不适合MySOC。

### 3. 移植验证

至此，你可以使用如下命令，启动你产品的构建了：

`./build.sh --product-name MyProduct `

构建完成后，可以在如下目录看到构建出来的OpenHarmony镜像文件

`//out/ohos-arm-release/packages/phone/images`

## 内核移植

这一步需要移植Linux内核，让Linux内核可以成功运行起来。

### 1. 为SOC添加内核构建的子系统

修改文件 `//build/subsystem_config.json` 增加一个子系统. 配置如下：

```json
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

接着需要修改定义产品的配置文件`//productdefine/common/products/MyProduct.json`。将刚刚定义的子系统加入到产品中

### 2. 编译内核

在上一节定义subsystem的时候，定义了构建的路径path，即`//device/MySOCVendor/MySOC/build`。这一节会在这个目录创建构建脚本，告诉构建系统如何构建内核。

目前OpenHarmony源码中提供了Linux 4.19的内核，归档在`//kernel/linux-4.19`。请尽可能使用这个内核。
每个SOC必然需要对内核做一些修改或扩展，建议采用补丁的方式。

建议的目录结构
```
├── build
│   ├── kernel
│   │     ├── linux
│   │           ├──standard_patch_for_4_19.patch
│   ├── BUILD.gn
│   ├── ohos.build
```
BUILD.gn是subsystem构建的唯一入口。

期望的构建结果

| 文件 | 文件说明|
|------|------|
|$root_build_dir/packages/phone/images/uImage| 内核镜像|
|$root_build_dir/packages/phone/images/uboot | bootloader镜像|

### 3. 移植验证

启动编译，验证预期的kernel镜像是否成功生成。

## HDF驱动移植

### 1. LCD
HDF为LCD设计了驱动模型。支持一块新的LCD，需要编写一个驱动，在驱动中生成模型的实例，并完成注册。

这些LCD的驱动被放置在`//drivers/framework/model/display/driver/panel`目录中。

- 创建Panel驱动

在驱动的Init方法中，需要调用RegisterPanel接口注册模型实例。如:
```C
int32_t XXXInit(struct HdfDeviceObject *object)
{
    struct PanelData *panel = CreateYourPanel();

    // 注册
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

- 配置加载panel驱动
产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在display的host中，名为device_lcd的device中增加配置。
注意：moduleName 要与panel驱动中的moduleName相同。

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

更详细的驱动开发指导，请参考 [LCD](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/LCD.md)

### 2. 触摸屏
本节描述如何移植触摸屏驱动。触摸屏的驱动被放置在`//drivers/framework/model/input/driver/touchscreen`目录中。移植触摸屏驱动主要工作是向系统注册ChipDevice模型实例。

- 创建触摸屏器件驱动

在目录中创建名为`touch_ic_name.c`的文件。代码模板如下：
注意：请替换ic_name为你所适配芯片的名称

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

其中ChipDevice中要提供若干方法
| 方法| 实现说明|
|------|------|
|int32_t (*Init)(ChipDevice *device)| 器件初始化|
|int32_t (*Detect)(ChipDevice *device)| 器件探测|
|int32_t (*Suspend)(ChipDevice *device)| 器件休眠|
|int32_t (*Resume)(ChipDevice *device)| 器件唤醒|
|int32_t (*DataHandle)(ChipDevice *device)| 从器件读取数据，将触摸点数据填写入device->driver->frameData中|
|int32_t (*UpdateFirmware)(ChipDevice *device)| 固件升级|

- 配置产品，加载器件驱动

产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为input的host中，名为device_touch_chip的device中增加配置。
注意：moduleName 要与触摸屏驱动中的moduleName相同。

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

更详细的驱动开发指导，请参考 [TOUCHSCREEN](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/TOUCHSCREEN.md)


### 3. WLAN

![tu](./figures/HDF_WIFI.png)

Wi-Fi驱动分为两部分，一部分负责管理WLAN设备，另一个部分负责处理WLAN流量。`HDF WLAN`分别为这两部分做了抽象。目前支持SDIO接口的WLAN芯片

主要需要实现的接口有:

| 接口| 定义头文件| 说明|
|------|------|------|
| HdfChipDriverFactory| `//drivers/framework/include/wifi/hdf_wlan_chipdriver_manager.h`| ChipDriver的Factory，用于支持一个芯片多个Wi-Fi端口|
| HdfChipDriver | `//drivers/framework/include/wifi/wifi_module.h`| 每个WLAN端口对应一个HdfChipDriver，用来管理一个特定的WLAN端口|
|NetDeviceInterFace| `//drivers/framework/include/wifi/net_device.h`| 与协议栈之间的接口，如发送数据、设置网络接口状态等|

建议适配按如下步骤操作：

1. 创建HDF驱动
建议将代码放置在`//device/MySoCVendor/peripheral/wifi/chip_name/`

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

在CreateChipDriverFactory中，需要创建一个HdfChipDriverFactory
| 接口| 说明|
|------|------|
|const char *driverName| 当前driverName |
|int32_t (*InitChip)(struct HdfWlanDevice *device)| 初始化芯片|
|int32_t (*DeinitChip)(struct HdfWlanDevice *device)| 去初始化芯片|
|void (*ReleaseFactory)(struct HdfChipDriverFactory *factory)| 释放HdfChipDriverFactory对象|
|struct HdfChipDriver *(*Build)(struct HdfWlanDevice *device, uint8_t ifIndex)|创建一个HdfChipDriver；输入参数中，device是设备信息，ifIndex是当前创建的接口在这个芯片中的序号|
|void (*Release)(struct HdfChipDriver *chipDriver)| 释放chipDriver
|uint8_t (*GetMaxIFCount)(struct HdfChipDriverFactory *factory)| 获取当前芯片支持的最大接口数|

HdfChipDriver需要实现的接口有

|接口| 说明|
|------|------|
|int32_t (*init)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| 初始化当前网络接口，这里需要向netDev提供接口NetDeviceInterFace|
|int32_t (*deinit)(struct HdfChipDriver *chipDriver, NetDevice *netDev)| 去初始化当前网络接口|
|struct HdfMac80211BaseOps *ops| WLAN基础能力接口集|
|struct HdfMac80211STAOps *staOps| 支持STA模式所需的接口集|
|struct HdfMac80211APOps *apOps| 支持AP模式所需要的接口集|



2. 编写配置文件，描述驱动支持的设备
在产品配置目录下创建芯片的配置文件`//vendor/MyProductVendor/MyProduct/config/wifi/wlan_chip_chip_name.hcs`

注意： 路径中的vendor_name、product_name、chip_name请替换成实际名称
```hcs
root {
    wlan_config {
        chip_name :& chipList {
            chip_name :: chipInst {
                match_attr = "hdf_wlan_chips_chip_name"; /* 这是配置匹配属性，用于提供驱动的配置根 */
                driverName = "driverName"; /* 需要与HdfChipDriverFactory中的driverName相同*/
                sdio {
                    vendorId = 0x0296;
                    deviceId = [0x5347];
                }
            }
        }
    }
}
```

3. 编写配置文件，加载驱动

产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为network的host中，名为device_wlan_chips的device中增加配置。
注意：moduleName 要与触摸屏驱动中的moduleName相同。

```hcs
                deviceN :: deviceNode {
                    policy = 0;
                    preload = 2;
                    moduleName = "HDF_WLAN_CHIPS";
                    deviceMatchAttr = "hdf_wlan_chips_chip_name";
                    serviceName = "driverName";
                }
```

4. 构建驱动

- 创建内核菜单
在 `//device/MySoCVendor/peripheral` 目录中创建Kconfig文件，内容模板如下：
```
config DRIVERS_WLAN_XXX
    bool "Enable XXX WLAN Host driver"
    default n
    depends on DRIVERS_HDF_WIFI
    help
      Answer Y to enable XXX Host driver. Support chip xxx
```

接着修改文件 `//drivers/adapter/khdf/linux/model/network/wifi/Kconfig`,在文件末尾加入如下代码将配置菜单加入内核中
```
source "../../../../../device/MySoCVendor/peripheral/Kconfig"
```

- 创建构建脚本

在`//drivers/adapter/khdf/linux/model/network/wifi/Makefile` 文件末尾增加配置，模板如下

```
HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
```

当在内核中开启`DRIVERS_WLAN_XXX`开关时，会调用`//device/MySoCVendor/peripheral/build/standard/`中的makefile


更多详细的开发手册，请参考[WLAN开发](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/driver/WLAN.md)
>>>>>>> 2969611b3e2a25755ebcd7f632c8fe3f7f0c615f
