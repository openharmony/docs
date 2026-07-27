# 移植外设驱动子系统


外设驱动子系统提供OpenHarmony专有的外部设备操作接口。本模块提供设备操作接口有：FLASH, GPIO, I2C, PWM, UART, WATCHDOG等。


OpenHarmony提供了两种驱动适配方式：使用外设驱动子系统、使用HDF驱动框架。由于轻量级系统的资源有限，这里建议使用IOT子系统方式。


## 移植指导

厂商需要根据OpenHarmony提供的接口定义实现其功能，IOT子系统接口定义的头文件如下：

  
```text
base/iothardware/peripheral/
├── BUILD.gn                              # 模块的构建规则（依赖关系、条件编译等）
├── bundle.json                           # 模块的元数据（如名称、版本、权限等）
└── interfaces
    └── inner_api                         # 内部API头文件
        ├── iot_errno.h                   # 错误码定义
        ├── iot_flash.h                   # 闪存操作接口
        ├── iot_gpio.h                    # GPIO（通用输入输出）控制接口
        ├── iot_i2c.h                     # I²C总线通信接口
        ├── iot_pwm.h                     # pwm接口
        ├── iot_uart.h                    # UART（通用异步收发器）通信接口
        ├── iot_watchdog.h                # 看门狗定时器接口
        ├── lowpower.h                    # 低功耗管理接口
        └── reset.h                       # 系统重置相关接口
```

其中“base/iothardware/peripheral/BUILD.gn”文件如下：

  
```gn
import("//build/lite/ndk/ndk.gni")
       
group("iothardware") {      
  deps = [
  "$ohos_board_adapter_dir/hals/iot_hardware/wifiiot_lite:hal_iothardware",    # 定义逻辑分组
  ]
}
if (ohos_kernel_type == "liteos_m") {
  ndk_lib("iothardware_ndk") {
    deps = [
      "$ohos_board_adapter_dir/hals/iot_hardware/wifiiot_lite:hal_iothardware", #依赖厂商的适配。
    ]
    head_files = [ "//base/iothardware/peripheral/interfaces/inner_api" ]
  }
}
```

从中可以看到厂商适配相关接口的存放目录应为“$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite”，且该目录下BUILD.gn文件中的目标应为hal_iothardware。


## 移植实例

1. 在“config.json”中添加iothardware子系统。

   路径：“vendor/MyVendorCompany/MyProduct/config.json”

   修改如下：


   ```json
   {
      "subsystem": "iothardware",
      "components": [
        { "component": "peripheral", "features":[] }
      ]
   }
   ```

2. 添加适配文件。

   在“vendor/MyVendorCompany/MyProduct/config.json”文件中，通常将配置“vendor_adapter_dir”配置为 “//device/soc/MyDeviceCompany/MyBoard/adapter”。

   在“vendor_adapter_dir”目录下进行适配：

     
   ```text
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

     
   ```gn
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
