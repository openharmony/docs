# Implementation of APIs at the HAL<a name="EN-US_TOPIC_0000001062862633"></a>

-   [Utils](#section1394788286)
-   [IoT Peripheral Subsystem](#section958113200811)
-   [WLAN](#section1331917210911)

The HAL mainly aims to decouple OpenHarmony from the SoC. The following modules describe the dependency of OpenHarmony on the SoC APIs.

## Utils<a name="section1394788286"></a>

**Introduction**

The Utils subsystem provides common basic components that can be used by other subsystems and upper-layer applications. These basic components are implemented based on the file system of the SoC. The SoC platform must implement file operations such as opening, closing, reading data from, and writing data to a file, as well as obtaining the file size.

**Description for HAL APIs of the Utils subsystem**

The SoC needs to implement related APIs. For details about the dependency of OpenHarmony on the SoC file system APIs, see  [HAL Header Files of Utils](https://gitee.com/openharmony/utils_native_lite/tree/master/hals/file).

## IoT Peripheral Subsystem<a name="section958113200811"></a>

**Introduction**

The IoT peripheral subsystem provides dedicated peripheral operation interfaces for OpenHarmony, including FLASH, GPIO, I2C, PWM, UART, and WATCHDOG APIs.

**Description for HAL APIs of the IoT peripheral subsystem**

The SoC needs to implement related APIs. For details about the dependency of OpenHarmony on the chip peripheral APIs, see  [HAL Header Files of wifiiot](https://gitee.com/openharmony/iothardware_hals_wifiiot_lite/tree/master).

## WLAN<a name="section1331917210911"></a>

**Introduction**

The WLAN service enables devices to access the WLAN in the following modes:

-   **Station \(STA\) mode**: allows your device to connect to the WLAN access point enabled on other devices and routers.

-   **Access point \(AP\) mode**: enables your device to function as a WLAN access point for other devices to connect to.


The WLAN service enables you to control the WLAN in the system, including enabling, disabling, scanning for, connecting to, and disconnecting from WLAN access points.

In addition, it supports event listening. You can listen to the WLAN status and immediately detect the status change.

**Description for HAL APIs of the WLAN subsystem**

The code path and API definition are as follows:

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

The vendor needs to implement defined APIs in the  **vendor/\*\*\*/\*\*\*/\*\*\*\_adapter**  directory. The following example shows how to implement these APIs for the Hi3861 chip:

```
vendor/hisi/hi3861/hi3861_adapter/hals/communication/wifi_lite/wifiservice/
├── BUILD.gn
└── source
├── wifi_device.c
├── wifi_device_util.c
├── wifi_device_util.h
└── wifi_hotspot.c
```

The SoC needs to implement related APIs. For details about the dependency of OpenHarmony on the chip peripheral APIs, see  [Header Files of WLAN](https://gitee.com/openharmony/communication_interfaces_kits_wifi_lite/tree/master/wifiservice).

