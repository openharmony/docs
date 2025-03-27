# 移植外设驱动子系统


外设驱动子系统提供OpenHarmony专有的外部设备操作接口。本模块提供设备操作接口有：FLASH, GPIO, I2C, PWM, UART, WATCHDOG等。


OpenHarmony提供了两种驱动适配方式：使用外设驱动子系统、使用HDF驱动框架。由于轻量级系统的资源有限，这里建议使用IOT子系统方式。


## 移植指导

厂商需要根据OpenHarmony提供的接口定义实现其功能，IOT子系统接口定义的头文件如下：

  
```
base/iot_hardware/peripheral/
├── BUILD.gn
└── interfaces
    └── kits
        ├── iot_errno.h
        ├── iot_flash.h
        ├── iot_gpio.h
        ├── iot_i2c.h
        ├── iot_pwm.h
        ├── iot_uart.h
        ├── iot_watchdog.h
        ├── lowpower.h
        └── reset.h
```

其中“base/iot_hardware/peripheral/BUILD.gn”文件如下：

  
```
import("//build/lite/config/subsystem/lite_subsystem.gni")
import("//build/lite/ndk/ndk.gni")
       
lite_subsystem("iothardware") {
  subsystem_components = [
    "$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite:hal_iothardware",
  ]
}
if (ohos_kernel_type == "liteos_m") {
  ndk_lib("iothardware_ndk") {
    deps = [
      "$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite:hal_iothardware", #依赖厂商的适配。
    ]
    head_files = [ "//base/iot_hardware/peripheral/interfaces/kits" ]
  }
}
```

从中可以看到厂商适配相关接口的存放目录应为“$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite”，且该目录下BUILD.gn文件中的目标应为hal_iothardware。


## 移植实例

1. 在“config.json”中添加iot_hardware子系统。
   路径：“vendor/MyVendorCompany/MyProduct/config.json”

   修改如下：

     
   ```
   { 
       subsystem": "iot_hardware", 
       components": [ 
           { "component": "iot_controller", "features":[] }
       ] 
   },
   ```

2. 添加适配文件。

   在“vendor/MyVendorCompany/MyProduct/config.json”文件中，通常将配置“vendor_adapter_dir”配置为 “//device/MyDeviceCompany/MyBoard/adapter”。

   在“vendor_adapter_dir”目录下进行适配：

     
   ```
   hals/iot_hardware/wifiiot_lite
   ├── BUILD.gn
   ├── iot_flash.c
   ├── iot_gpio.c
   ├── iot_i2c.c
   ├── iot_lowpower.c
   ├── iot_pwm.c
   ├── iot_reset.c
   ├── iot_uart.c
   └── iot_watchdog.c
   ```

   其中BUILD.gn内容如下：

     
   ```
   static_library("hal_iothardware") {   #目标名。
       sources = [                       #厂商适配的源文件。
         "iot_watchdog.c",
         "iot_reset.c",
         "iot_flash.c",
         "iot_i2c.c",
         "iot_gpio.c",
         "iot_pwm.c",
         "iot_uart.c"
       ]
       include_dirs = [ ]
   }
   ```

   其中，“include_dirs”需要根据工程实际情况包含两个路径：

   - iot子系统的头文件路径

   - 适配iot子系统所使用到的SDK的头文件路径
