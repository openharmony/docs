# 平台驱动移植


在这一步，我们会在源码目录`//device/soc/vendor_name/common/platform`目录下创建平台驱动，如果你要移植的SOC的厂商还没有创建仓库的话，请联系[sig_devboard](https://gitcode.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard_cn.md)创建。


建议的目录结构：

```text
device
├── soc
│   ├── vendor_name                          # 厂商名称，例如hisilicon、rockchip、unisoc。
│   │   ├── LICENSE
│   │   ├── README.md
│   │   ├── common
│   │   │   ├── hal                          # HAL层。
│   │   │   └── platform                     # 平台驱动。
│   │   │       ├── Kconfig                  # 厂商驱动内核菜单入口。
│   │   │       ├── lite.mk                  # 构建的入口。
│   │   │       ├── BUILD.gn
│   │   │       ├── LICENSE
│   │   │       ├── README.md
│   │   │       ├── README_zh.md
│   │   │       ├── adc
│   │   │       ├── dmac
│   │   │       ├── gpio
│   │   │       │   ├── Makefile             # GPIO驱动构建入口。
│   │   │       │   └── soc_name_gpio.c
│   │   │       ├── hieth-sf
│   │   │       ├── hisi_sdk
│   │   │       ├── i2c
│   │   │       ├── i2s
│   │   │       ├── include
│   │   │       ├── libs
│   │   │       ├── mipi_csi
│   │   │       ├── mipi_dsi
│   │   │       ├── mmc
│   │   │       ├── mtd
│   │   │       ├── pin
│   │   │       ├── pwm
│   │   │       ├── rtc
│   │   │       ├── spi
│   │   │       ├── timer
│   │   │       ├── uart
│   │   │       ├── watchdog
│   │   │       └── wifi
│   │   ├── soc_name_a                       # 具体SOC芯片，例如hi3516dv300。
│   │   └── soc_name_b                       # 其他SOC芯片。
│   ├── hisilicon
│   │   ├── common
│   │   │   └── platform
│   │   ├── hi3516dv300
│   │   ├── hi3518ev300
│   │   └── hi3861v100
│   ├── rockchip
│   └── unisoc
├── board
│   └── vendor_name                          # 厂商名称。
│       └── board_name                       # 开发板名称。
```

HDF为所有的平台驱动都创建了驱动模型，移植平台驱动的主要工作是向模型注入实例。 这些模型你可以在源码目录`//drivers/hdf_core/framework/support/platform/include`中找到定义。


本节我们会以GPIO为例，讲解如何移植平台驱动，移植过程包含以下步骤：


1. 创建GPIO驱动。

   在源码目录`//device/soc/vendor_name/common/platform/gpio`中创建文件`soc_name_gpio.c`。内容模板如下：
     
   ```c
   #include "gpio/gpio_core.h"
   
   // 定义GPIO结构体，如果需要的话。
   struct SocNameGpioCntlr {
       struct GpioCntlr cntlr;  // 这是HDF GPIO驱动框架需要的结构体。
       int myData; // 以下是当前驱动自身需要的。
   };
   
   // Bind 方法在HDF驱动中主要用于对外发布服务，这里我们不需要，直接返回成功即可。
   static int32_t GpioBind(struct HdfDeviceObject *device)
   {
       (void)device;
       return HDF_SUCCESS;
   }
   
   // Init方法是驱动初始化的入口，我们需要在Init方法中完成模型实例的注册。
   static int32_t GpioInit(struct HdfDeviceObject *device)
   {
       int32_t ret;
       SocNameGpioCntlr *impl = CreateGpio(); // 你的创建代码需要自己实现。
       ret = GpioCntlrAdd(&impl->cntlr);  // 注册GPIO模型实例。
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: err add controller:%d", __func__, ret);
           return ret;
       }
       return HDF_SUCCESS;
   }
   
   // Release方法会在驱动卸载时被调用，这里主要完成资源回收。
   static void GpioRelease(struct HdfDeviceObject *device)
   {
       // GpioCntlrFromHdfDev 方法能从抽象的设备对象中获得init方法注册进去的模型实例。
       struct GpioCntlr *cntlr = GpioCntlrFromHdfDev(device);
        // 资源释放...
       if (cntlr != NULL) {
           GpioCntlrRemove(cntlr);  // 注销GPIO模型实例。
       }
   }
   
   struct HdfDriverEntry g_gpioDriverEntry = {
       .moduleVersion = 1,
       .Bind = GpioBind,
       .Init = GpioInit,
       .Release = GpioRelease,
       .moduleName = "SOC_NAME_gpio_driver", // 这个名字我们稍后会在配置文件中用到，用来加载驱动。
   };
   HDF_INIT(g_gpioDriverEntry); // 注册一个GPIO的驱动入口。
   ```

2. 创建厂商驱动构建入口。

   如前所述`device/soc/vendor_name/common/platform/lite.mk`是厂商驱动的构建的入口。我们需要从这个入口开始，进行构建。

     
   ```makefile
   #文件device/soc/vendor_name/common/platform/lite.mk。
   
   SOC_COMPANY := $(subst $\",,$(LOSCFG_DEVICE_COMPANY))
   SOC_PLATFORM := $(subst $\",,$(LOSCFG_PLATFORM))
   SOC_BOARD := $(subst $\",,$(LOSCFG_PRODUCT_NAME))
   
   # 根目录，后续各驱动按编译开关逐个加入LIB_SUBDIRS。
   SOC_DRIVER_ROOT := $(LITEOSTOPDIR)/../../device/soc/$(SOC_COMPANY)/common/platform/
   ```

3. 创建SOC驱动构建入口。
     
   ```makefile
   #文件device/soc/vendor_name/common/platform/lite.mk。
   
   SOC_DRIVER_ROOT := $(LITEOSTOPDIR)/../../device/soc/$(SOC_COMPANY)/common/platform/
   
   # 判断如果打开了GPIO的内核编译开关。
   ifeq ($(LOSCFG_DRIVERS_HDF_PLATFORM_GPIO), y)
       # 构建完成要链接一个叫hdf_gpio的对象。
       LITEOS_BASELIB += -lhdf_gpio
       # 增加构建目录gpio。
       LIB_SUBDIRS    += $(SOC_DRIVER_ROOT)/gpio 
   endif
   
   # 后续其他驱动在此基础上追加。
   ```

4. 创建GPIO构建入口。
     
     
   ```makefile
   include $(LITEOSTOPDIR)/config.mk
   include $(LITEOSTOPDIR)/../../drivers/hdf_core/adapter/khdf/liteos/lite.mk
   
   # 指定输出对象的名称，注意要与SOC驱动构建入口里的LITEOS_BASELIB 保持一致。
   MODULE_NAME := hdf_gpio

   # 增加HDF框架的INCLUDE。
   LOCAL_CFLAGS += $(HDF_INCLUDE)

   # 要编译的文件。
   LOCAL_SRCS += soc_name_gpio.c

   # 编译参数。
   LOCAL_CFLAGS += -fstack-protector-strong -Wextra -Wall -Werror -fsigned-char -fno-strict-aliasing -fno-common

   include $(HDF_DRIVER)
   ```

5. 配置产品加载驱动。
   
   产品的所有设备信息被定义在源码文件`//vendor/vendor_name/product_name/hdf_config/device_info/device_info.hcs`中。

   平台驱动请添加到platform的host中。

   > <img src="public_sys-resources/icon-note.gif" alt="说明"/> <b>说明：</b>
   > moduleName要与驱动定义中的相同，deviceMatchAttr必须与私有配置中的匹配属性保持一致。

     
   ```hcs
   root {
       ...
       platform :: host {
           hostName = "platform_host";
           priority = 50;
           device_gpio :: device {
               device0 :: deviceNode {
                   policy = 2;
                   priority = 10;
                   permission = 0644;
                   moduleName = "HDF_PLATFORM_GPIO_MANAGER";
                   serviceName = "HDF_PLATFORM_GPIO_MANAGER";
               }
               device1 :: deviceNode {
                   policy = 0;
                   priority = 10;
                   permission = 0644;
                   moduleName = "SOC_NAME_gpio_driver";
                   deviceMatchAttr = "vendor_soc_name_gpio";
               }
           }
       }
   }
   ```
