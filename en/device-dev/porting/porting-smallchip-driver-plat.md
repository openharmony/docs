# Platform Driver Porting


Create a platform driver in the source code directory **//device/vendor_name/soc_name/drivers**. If there is no repository for the vendor of your SoC, contact the [device SIG](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md) to create one.


The recommended directory structure is as follows:

```
device
├── vendor_name
│   ├── drivers
│   │   │   ├── common
│   │   │   ├── Kconfig # Entry of the vendor driver kernel menu
│   │   │   └── lite.mk # Build entry
│   ├── soc_name
│   │   ├── drivers
│   │   │   ├── dmac
│   │   │   ├── gpio
│   │   │   ├── i2c
│   │   │   ├── LICENSE
│   │   │   ├── mipi_dsi
│   │   │   ├── mmc
│   │   │   ├── pwm
│   │   │   ├── README.md # docs Add documentation information as needed.
│   │   │   ├── README_zh.md
│   │   │   ├── rtc
│   │   │   ├── spi
│   │   │   ├── uart
│   │   │   └── watchdog
│   ├── board_name
```

The HDF creates driver models for all platform drivers. The main task of porting platform drivers is to inject instances into the models. You can find the definitions of these models in the source code directory **//drivers/hdf_core/framework/support/platform/include**.


The following uses the GPIO as an example to describe how to port the platform driver:


1. Create a GPIO driver.

   Create the **soc_name_gpio.c** file in the **//device/vendor_name/soc_name/drivers/gpio** directory. The sample code is as follows:
   
   ```
   #include "gpio_core.h"
   
   // Define the GPIO structure if necessary.
   struct SocNameGpioCntlr {
       struct GpioCntlr cntlr; // Structure required by the HDF GPIO driver framework.
       int myData; // The following information is required by the current driver.
   };
   
   // The Bind method is mainly used to release services in the HDF driver. As this method is not needed here, simply return a success message.
   static int32_t GpioBind(struct HdfDeviceObject *device)
   {
       (void)device;
       return HDF_SUCCESS;
   }
   
   // Entry for initializing the driver when the Init method is used. You need to register the model instance in the Init method.
   static int32_t GpioInit(struct HdfDeviceObject *device)
   {
       SocNameGpioCntlr *impl = CreateGpio(); // Implement the CreateGpio method.
       ret = GpioCntlrAdd(&impl->cntlr);  // Register a GPIO model instance.
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: err add controller:%d", __func__, ret);
           return ret;
       }
       return HDF_SUCCESS;
   }
   
   // The Release method is called when the driver is uninstalled to reclaim resources.
   static void GpioRelease(struct HdfDeviceObject *device)
   {
       // The GpioCntlrFromDevice method obtains the model instance registered in the init method from the abstract device object.
       struct GpioCntlr *cntlr = GpioCntlrFromDevice(device);
       // Release resources.
   }
   
   struct HdfDriverEntry g_gpioDriverEntry = {
       .moduleVersion = 1,
       .Bind = GpioBind,
       .Init = GpioInit,
       .Release = GpioRelease,
       .moduleName = "SOC_NAME_gpio_driver", // Name to be used in the configuration file to load the driver.
   };
   HDF_INIT(g_gpioDriverEntry); // Register a GPIO driver entry.
   ```

2. Create a build entry for the vendor driver.

   As described above, **device/vendor_name/drivers/lite.mk** is the entry for building vendor drivers. We need to start building from this entry.

   
   ```
   #File: device/vendor_name/drivers/lite.mk
   
   SOC_VENDOR_NAME := $(subst $/",,$(LOSCFG_DEVICE_COMPANY))
   SOC_NAME := $(subst $/",,$(LOSCFG_PLATFORM))
   BOARD_NAME := $(subst $/",,$(LOSCFG_PRODUCT_NAME))
   
   # Specify the SoC for building.
   LIB_SUBDIRS += $(LITEOSTOPDIR)/../../device/$(SOC_VENDOR_NAME)/$(SOC_NAME)/drivers/
   ```

3. Create a build entry for the SoC driver.
   
   ```
   # File: device/vendor_name/soc_name/drivers/lite.mk
   
   SOC_DRIVER_ROOT := $(LITEOSTOPDIR)/../../device/$(SOC_VENDOR_NAME)/$(SOC_NAME)/drivers/
   
   # Check whether the kernel compilation switch of the GPIO is enabled.
   ifeq ($(LOSCFG_DRIVERS_HDF_PLATFORM_GPIO), y)
       # After the construction is complete, an object named hdf_gpio needs to be linked.
       LITEOS_BASELIB += -lhdf_gpio
       # Add the build directory gpio.
       LIB_SUBDIRS    += $(SOC_DRIVER_ROOT)/gpio 
   endif
   
   # Add other drivers here.
   ```

4. Create a build entry for the GPIO driver.
   
   
   ```
   include $(LITEOSTOPDIR)/config.mk
   include $(LITEOSTOPDIR)/../../drivers/adapter/khdf/liteos/lite.mk
   
   # Specify the name of the output object. Ensure that the name is the same as LITEOS_BASELIB in the SoC driver build entry.
   MODULE_NAME := hdf_gpio
   
   # Add the INCLUDE of the HDF framework.
   LOCAL_CFLAGS += $(HDF_INCLUDE)
   
   # Specify the file to be compiled.
   LOCAL_SRCS += soc_name_gpio.c
   
   # Compiling parameters
   LOCAL_CFLAGS += -fstack-protector-strong -Wextra -Wall -Werror -fsigned-char -fno-strict-aliasing -fno-common
   
   include $(HDF_DRIVER)
   ```

5. Configure the product loading driver.
   
   All device information of the product is defined in the source code file **//vendor/vendor_name/product_name/config/device_info/device_info.hcs**.

   Add the platform driver to the host of the platform.

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > The value of **moduleName** must be the same as that defined in the driver.

   ```
   root {
       ...
       platform :: host {
           device_gpio :: device {
                   device0 :: deviceNode {
                       policy = 0;
                       priority = 10;
                       permission = 0644;
                       moduleName = "SOC_NAME_gpio_driver"; 
                   }
           }
       }
   }
   ```
