# oh_wifi.h


## Overview

Defines APIs for obtaining Wi-Fi switch state.

**Library**: libwifi_ndk.so

**System capability**: SystemCapability.Communication.WiFi.STA

**Since**: 13

**Related module**: [Wifi](_wifi.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Wifi_ResultCode](_wifi.md#wifi_resultcode) [Wifi_ResultCode](_wifi.md#wifi_resultcode) | Enumerates the error codes returned by Wi-Fi APIs.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Wifi_ResultCode](_wifi.md#wifi_resultcode) {<br>[WIFI_SUCCESS] = 0,<br>[WIFI_PERMISSION_DENIED] = 201,<br>[WIFI_INVALID_PARAM] = 401,<br>[WIFI_NOT_SUPPORTED] = 801,<br>[WIFI_OPERATION_FAILED] = 2501000<br>} | Enumerates the error codes returned by Wi-Fi APIs.|


### Functions

| Name| Description| 
| -------- | -------- |
| [Wifi_ResultCode](_wifi.md#wifi_resultcode) [OH_Wifi_IsWifiEnabled](_wifi.md#oh_wifi_iswifienabled) (bool \*enabled) | Checks whether Wi-Fi is enabled.| 
