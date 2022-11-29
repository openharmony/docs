# Porting the Driver Subsystem


The driver subsystem provides OpenHarmony-dedicated APIs for peripheral device operations, including FLASH, GPIO, I2C, PWM, UART, and WATCHDOG APIs.


OpenHarmony provides two driver adaptation modes: using the driver subsystem and using the HDF driver framework. Because the resources of the mini system are limited, the IoT subsystem mode is recommended.


## Procedure

Vendors need to implement their functions based on the interface definitions provided by OpenHarmony. The header files defined by the interfaces of the IoT subsystem are as follows:

  
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

The content of the **base/iot_hardware/peripheral/BUILD.gn** file is as follows:

  
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
      "$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite:hal_iothardware", # Vendor dependent adaptation.
    ]
    head_files = [ "//base/iot_hardware/peripheral/interfaces/kits" ]
  }
}
```

As shown above, the directory for storing vendor adaptation interfaces is **$ohos_vendor_adapter_dir/hals/iot_hardware/wifiiot_lite**, where the target in the **BUILD.gn file** is **hal_iothardware**.


## Example

1. Add the iot_hardware subsystem to the **config.json** file.
  
   Path: **vendor/MyVendorCompany/MyProduct/config.json**

   The sample code is as follows:

     
   ```
   { 
       subsystem": "iot_hardware", 
       components": [ 
           { "component": "iot_controller", "features":[] }
       ] 
   },
   ```

2. Add an adaptation file.

   In the **vendor/MyVendorCompany/MyProduct/config.json** file, set **vendor_adapter_dir** to **//device/MyDeviceCompany/MyBoard/adapter**.

   Perform adaptation in the **vendor_adapter_dir** directory.

     
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

   The content of **BUILD.gn** is as follows:

     
   ```
   static_library("hal_iothardware") {   # Target name
       sources = [                       # Source file adapted by the vendor
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

   In the preceding example, **include_dirs** must contain two paths based on the site requirements:

   - Path to the header file of the IoT subsystem

   - Path to the SDK header file used by the IoT subsystem
