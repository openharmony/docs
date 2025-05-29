# 标准系统移植指南


本文描述了移植一块开发板的通用步骤，和具体芯片相关的详细移植过程无法在此一一列举。后续社区还会陆续发布开发板移植的实例供开发者参考。


## 定义开发板

本文以移植名为MyProduct的开发板为例讲解移植过程，假定MyProduct是MyProductVendor公司的开发板，使用MySoCVendor公司生产的MySOC芯片作为处理器。


### 定义产品

在`//vendor/MyProductVendor/{product_name}`名称的目录下创建一个config.json文件，该文件用于描述产品所使用的SOC 以及所需的子系统。配置如下：

//vendor/MyProductVendor/MyProduct/config.json


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
          { "component": "ace_engine_lite", "features":[] }
        ]
      },
	...
    ]
}


```
主要的配置内容

| 配置项 | 说明 |
|-------|----------|
|product_name |（必填）产品名称。|
|version|（必填）版本。 |
|type|（必填）配置的系统级别，包含（small、standard等)。 |
|target_cpu |（必填）设备的CPU类型（根据实际情况，这里的target_cpu也可能是arm64 、riscv、 x86等）。|
|ohos_version|（选填）操作系统版本。|
|device_company|（必填）device厂商名。|
|board|（必填）开发板名称。|
|enable_ramdisk|（必填）是否启动ramdisk。|
|kernel_type|（选填）内核类型。|
|kernel_version|（选填）kernel_type与kernel_version在standard是固定的不需要写。|
|subsystems|（必填）系统需要启用的子系统。子系统可以简单理解为一块独立构建的功能块。|
|product_company|不体现在配置中，而是目录名，vendor下一级目录就是product_company，BUILD.gn脚本依然可以访问。|


已定义的子系统可以在“//build/subsystem_config.json”中找到。当然你也可以定制子系统。

这里建议先拷贝Hi3516DV300 开发板的配置文件，删除掉 hisilicon_products 这个子系统。这个子系统为Hi3516DV300 SOC编译内核，显然不适合MySOC。


### 移植验证

  至此，你可以使用如下命令，启动你产品的构建了：

```
./build.sh --product-name MyProduct 
```

构建完成后，可以在`//out/{device_name}/packages/phone/images`目录下看到构建出来的OpenHarmony镜像文件。


## 内核移植

这一步需要移植Linux内核，让Linux内核可以成功运行起来。


### 为SOC添加内核构建的子系统

修改文件`//build/subsystem_config.json`增加一个子系统。配置如下：


```
  "MySOCVendor_products": {
    "project": "hmf/MySOCVendor_products",
    "path": "device/MySOCVendor/MySOC/build",
    "name": "MySOCVendor_products",
    "dir": "device/MySOCVendor"
  },
```

接着需要修改定义产品的配置文件`//vendor/MyProductVendor/MyProduct/config.json`，将刚刚定义的子系统加入到产品中。


### 编译内核

源码中提供了Linux 4.19的内核，归档在`//kernel/linux-4.19`。本节以该内核版本为例，讲解如何编译内核。

在子系统的定义中，描述了子系统构建的路径path，即`//device/MySOCVendor/MySOC/build`。这一节会在这个目录创建构建脚本，告诉构建系统如何构建内核。

建议的目录结构：


```
├── build
│ ├── kernel
│ │     ├── linux
│ │           ├──standard_patch_for_4_19.patch // 基于4.19版本内核的补丁
│ ├── BUILD.gn
│ ├── ohos.build
```

BUILD.gn是subsystem构建的唯一入口。

期望的构建结果

| 文件 | 文件说明 | 
| -------- | -------- |
| $root_build_dir/packages/phone/images/uImage | 内核镜像。 | 
| $root_build_dir/packages/phone/images/uboot | bootloader镜像。 | 


### 移植验证

启动编译，验证预期的kernel镜像是否成功生成。

## 用户态启动引导

1. 用户态进程启动引导总览。

   ![zh-cn_image_0000001199805369](figures/zh-cn_image_0000001199805369.png)


   系统上电加载内核后，按照以下流程完成系统各个服务和应用的启动：

   1. 内核启动init进程，一般在bootloader启动内核时通过设置内核的cmdline来指定init的位置；如上图所示的"init=/init root/dev/xxx"。
   2. init进程启动后，会挂载tmpfs，procfs，创建基本的dev设备节点，提供最基本的根文件系统。
   3. init继续启动ueventd监听内核热插拔事件，为这些设备创建dev设备节点；包括block设备各个分区设备都是通过此事件创建。
   4. init进程挂载block设备各个分区（system，vendor），开始扫描各个系统服务的init启动脚本，并拉起各个SA服务。
   5. samgr是各个SA的服务注册中心，每个SA启动时，都需要向samgr注册，每个SA会分配一个ID，应用可以通过该ID访问SA。
   6. foundation是一个特殊的SA服务进程，提供了用户程序管理框架及基础服务；由该进程负责应用的生命周期管理。
   7. 由于应用都需要加载JS的运行环境，涉及大量准备工作，因此appspawn作为应用的孵化器，在接收到foundation里的应用启动请求时，可以直接孵化出应用进程，减少应用启动时间。

2. init。

   init启动引导组件配置文件包含了所有需要由init进程启动的系统关键服务的服务名、可执行文件路径、权限和其他信息。每个系统服务各自安装其启动脚本到`/system/etc/init`目录下。

   新芯片平台移植时，平台相关的初始化配置需要增加平台相关的初始化配置文件`/vendor/etc/init/init.{hardware}.cfg`；该文件完成平台相关的初始化设置，如安装ko驱动，设置平台相关的`/proc`节点信息。

   init相关进程代码在`//base/startup/init_lite`目录下，该进程是系统第一个进程，无其它依赖。

   初始化配置文件具体的开发指导请参考 [init启动子系统概述](../subsystems/subsys-boot-overview.md)。


## HDF驱动移植


### LCD

HDF为LCD设计了驱动模型。支持一块新的LCD，需要编写一个驱动，在驱动中生成模型的实例，并完成注册。

这些LCD的驱动被放置在`//drivers/hdf_core/framework/model/display/driver/panel`目录中。

1. 创建Panel驱动。

   在驱动的Init方法中，需要调用RegisterPanel接口注册模型实例。如：


   ```
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

2. 配置加载panel驱动产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在display的host中，名为device_lcd的device中增加配置。

   注意：moduleName要与panel驱动中的moduleName相同。

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

   更详细的驱动开发指导，请参考[LCD](../driver/driver-peripherals-lcd-des.md)。


### 触摸屏

本节描述如何移植触摸屏驱动。触摸屏的驱动被放置在`//drivers/hdf_core/framework/model/input/driver/touchscreen`目录中。移植触摸屏驱动主要工作是向系统注册ChipDevice模型实例。

1. 创建触摸屏器件驱动。

   在目录中创建名为touch_ic_name.c的文件。代码模板如下：注意：请替换ic_name为你所适配芯片的名称。


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

   其中ChipDevice中要提供若干方法。

   | 方法 | 实现说明 | 
   | -------- | -------- |
   | int32_t&nbsp;(\*Init)(ChipDevice&nbsp;\*device) | 器件初始化。 | 
   | int32_t&nbsp;(\*Detect)(ChipDevice&nbsp;\*device) | 器件探测。 | 
   | int32_t&nbsp;(\*Suspend)(ChipDevice&nbsp;\*device) | 器件休眠。| 
   | int32_t&nbsp;(\*Resume)(ChipDevice&nbsp;\*device) | 器件唤醒。 | 
   | int32_t&nbsp;(\*DataHandle)(ChipDevice&nbsp;\*device) | 从器件读取数据，将触摸点数据填写入device-&gt;driver-&gt;frameData中。 | 
   | int32_t&nbsp;(\*UpdateFirmware)(ChipDevice&nbsp;\*device) | 固件升级。 | 

2. 配置产品，加载器件驱动
  
   产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为input的host中，名为device_touch_chip的device中增加配置。注意：moduleName 要与触摸屏驱动中的moduleName相同。

  
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

   更详细的驱动开发指导，请参考[TOUCHSCREEN](../driver/driver-peripherals-touch-des.md)。


### WLAN

Wi-Fi驱动分为两部分，一部分负责管理WLAN设备，另一个部分负责处理WLAN流量。HDF WLAN分别为这两部分做了抽象。目前支持SDIO接口的WLAN芯片。

  **图1** WLAN芯片

  ![zh-cn_image_0000001188241031](figures/zh-cn_image_0000001188241031.png)

支持一款芯片的主要工作是实现一个ChipDriver驱动。实现HDF_WLAN_CORE和NetDevice提供的接口。主要需要实现的接口有：

| 接口 | 定义头文件 | 说明 |
| -------- | -------- | -------- |
| HdfChipDriverFactory | //drivers/hdf_core/framework/include/wifi/hdf_wlan_chipdriver_manager.h | ChipDriver的Factory，用于支持一个芯片多个Wi-Fi端口。 |
| HdfChipDriver | //drivers/hdf_core/framework/include/wifi/wifi_module.h | 每个WLAN端口对应一个HdfChipDriver，用来管理一个特定的WLAN端口。 |
| NetDeviceInterFace | //drivers/hdf_core/framework/include/net/net_device.h | 与协议栈之间的接口，如发送数据、设置网络接口状态等。 |

建议适配按如下步骤操作：

1. 创建HDF驱动建议将代码放置在`//device/MySoCVendor/peripheral/wifi/chip_name/`，文件模板如下：


   ```
   static int32_t HdfWlanXXXChipDriverInit(struct HdfDeviceObject *device) {
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

   在CreateChipDriverFactory中，需要创建一个HdfChipDriverFactory，接口如下：



   | 接口 | 说明 | 
   | -------- | -------- |
   | const&nbsp;char&nbsp;\*driverName | 当前driverName | 
   | int32_t&nbsp;(\*InitChip)(struct&nbsp;HdfWlanDevice&nbsp;\*device) | 初始化芯片。 | 
   | int32_t&nbsp;(\*DeinitChip)(struct&nbsp;HdfWlanDevice&nbsp;\*device) | 去初始化芯片。 | 
   | void&nbsp;(_ReleaseFactory)(struct&nbsp;HdfChipDriverFactory&nbsp;_factory) | 释放HdfChipDriverFactory对象。 | 
   | struct&nbsp;HdfChipDriver&nbsp;_(_Build)(struct&nbsp;HdfWlanDevice&nbsp;\*device,&nbsp;uint8_t&nbsp;ifIndex) | 创建一个HdfChipDriver；输入参数中，device是设备信息，ifIndex是当前创建的接口在这个芯片中的序号。 | 
   | void&nbsp;(_Release)(struct&nbsp;HdfChipDriver&nbsp;_chipDriver) | 释放chipDriver。 | 
   | uint8_t&nbsp;(\*GetMaxIFCount)(struct&nbsp;HdfChipDriverFactory&nbsp;\*factory) | 获取当前芯片支持的最大接口数。 | 

   HdfChipDriver需要实现的接口有：

   | 接口 | 说明 | 
   | -------- | -------- |
   | int32_t&nbsp;(\*init)(struct&nbsp;HdfChipDriver&nbsp;\*chipDriver,&nbsp;NetDevice&nbsp;\*netDev) | 初始化当前网络接口，这里需要向netDev提供接口NetDeviceInterFace。 | 
   | int32_t&nbsp;(\*deinit)(struct&nbsp;HdfChipDriver&nbsp;\*chipDriver,&nbsp;NetDevice&nbsp;\*netDev) | 去初始化当前网络接口。 | 
   | struct&nbsp;HdfMac80211BaseOps&nbsp;\*ops | WLAN基础能力接口集。 | 
   | struct&nbsp;HdfMac80211STAOps&nbsp;\*staOps | 支持STA模式所需的接口集。 | 
   | struct&nbsp;HdfMac80211APOps&nbsp;\*apOps | 支持AP模式所需要的接口集。 | 

2. 编写配置文件，描述驱动支持的设备。

   在产品配置目录下创建芯片的配置文件`//vendor/MyProductVendor/MyProduct/config/wifi/wlan_chip_chip_name.hcs`。

   注意： 路径中的vendor_name、product_name、chip_name请替换成实际名称。

   模板如下：

   ```
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

3. 编写配置文件，加载驱动。

   产品的所有设备信息被定义在文件`//vendor/MyProductVendor/MyProduct/config/device_info/device_info.hcs`中。修改该文件，在名为network的host中，名为device_wlan_chips的device中增加配置。

   注意：moduleName 要与触摸屏驱动中的moduleName相同。

   ```
   deviceN :: deviceNode {
       policy = 0;
       preload = 2;
       moduleName = "HDF_WLAN_CHIPS";
       deviceMatchAttr = "hdf_wlan_chips_chip_name";
       serviceName = "driverName";
   }
   ```

4. 构建驱动。

   - 创建内核菜单在`//device/MySoCVendor/peripheral`目录中创建Kconfig文件，内容模板如下：
  
     ```
     config DRIVERS_WLAN_XXX
         bool "Enable XXX WLAN Host driver"
         default n
         depends on DRIVERS_HDF_WIFI
         help
           Answer Y to enable XXX Host driver. Support chip xxx
     ```

     接着修改文件`//drivers/hdf_core/adapter/khdf/linux/model/network/wifi/Kconfig`，在文件末尾加入如下代码将配置菜单加入内核中，如：


     ```
     source "../../../../../device/MySoCVendor/peripheral/Kconfig"
     ```

   - 创建构建脚本
  
     在`//drivers/hdf_core/adapter/khdf/linux/model/network/wifi/Makefile`文件末尾增加配置，模板如下：

  
     ```
     HDF_DEVICE_ROOT := $(HDF_DIR_PREFIX)/../device
     obj-$(CONFIG_DRIVERS_WLAN_XXX) += $(HDF_DEVICE_ROOT)/MySoCVendor/peripheral/build/standard/
     ```

     当在内核中开启DRIVERS_WLAN_XXX开关时，会调用`//device/MySoCVendor/peripheral/build/standard/`中的makefile。更多详细的开发手册，请参考[WLAN开发](../guide/device-wlan-led-control.md)。


### 开发移植示例

开发移植示例请参考[DAYU开发板](https://gitee.com/openharmony-sig/devboard_device_hihope_build/blob/master/DAYU%20%E5%B9%B3%E5%8F%B0OpenHarmony%20%E9%80%82%E9%85%8D%E6%8C%87%E5%AF%BC%20-202108.pdf)。
