# HAL层实现


HAL层主要功能是实现轻OpenHarmony与芯片的解耦，以下模块描述的是轻OpenHarmony系统对芯片接口的依赖情况。


## UTILS

**基本介绍：**

公共基础提供通用的基础组件，这些基础组件可被各业务子系统及上层应用所使用。基础组件依赖芯片文件系统实现，需要芯片平台提供实现文件的打开、关闭、读写、获取大小等功能。

**公共基础HAL层接口说明：**

需要芯片适配相关接口的实现，对芯片文件系统接口依赖请参考[utils的HAL头文件](https://gitee.com/openharmony/utils_native_lite/tree/master/hals/file)。


## IOT外设子系统

**基本介绍**

提供轻OpenHarmony专有的外部设备操作接口。本模块提供设备操作接口有：FLASH, GPIO, I2C, PWM, UART, WATCHDOG等。

**IOT外设子系统HAL层接口说明**:

需要芯片适配相关接口的实现，对芯片设备外设接口依赖请参考[IOT外设子系统的HAL头文件](https://gitee.com/openharmony/iothardware_peripheral/tree/master/interfaces/kits)。


## WLAN服务

**基本介绍：**

WLAN服务适用于设备接入WLAN无线局域网场景，包括：

- 使用STA模式，作为接入方接入其他设备、路由器开启的WLAN无线局域网接入点；

- 使用AP模式，开启无线局域网接入点，允许其他设备连接。

借助WLAN服务，开发者可以实现对系统中WLAN的控制，包括开启关闭、扫描发现、连接断开等功能。

此外，WLAN服务还包括事件listen功能，开发者可以listen  WLAN的状态，并在状态发生变化时立刻感知。

**WLAN服务HAL层接口说明：**

代码路径及接口定义如下：

  
```
foundation/communication/interfaces/kits/wifi_lite/wifiservice/
├── station_info.h
├── wifi_device_config.h
├── wifi_device.h
├── wifi_error_code.h
├── wifi_event.h
├── wifi_hotspot_config.h
├── wifi_hotspot.h
├── wifi_linked_info.h
└── wifi_scan_info.h
```

具体的实现需要各厂家按照定义的接口在vendor/\*\*\*/\*\*\*/\*\*\*_adapter中实现，例如hi3861中具体实现在

  
```
vendor/hisi/hi3861/hi3861_adapter/hals/communication/wifi_lite/wifiservice/
├── BUILD.gn
└── source
├── wifi_device.c
├── wifi_device_util.c
├── wifi_device_util.h
└── wifi_hotspot.c
```

需要芯片适配相关接口的实现，对芯片设备外设接口依赖请参考[WLAN服务的头文件](https://gitee.com/openharmony/communication_wifi_lite/tree/master/interfaces/wifiservice)。
