# oh_wifi.h

## Overview

Defines APIs for obtaining Wi-Fi switch state.

**File to include**: <ConnectivityKit/wifi/oh_wifi.h>

**Library**: libwifi_ndk.so

**System capability**: SystemCapability.Communication.WiFi.STA

**Since**: 13

**Related module**: [Wifi](capi-wifi.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Wifi_ResultCode](#wifi_resultcode) | Wifi_ResultCode | Enumerates the error codes returned by Wi-Fi APIs.|

### Functions

| Name| Description|
| -- | -- |
| [Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)](#oh_wifi_iswifienabled) | Checks whether Wi-Fi is enabled.|

## Enum Description

### Wifi_ResultCode

```
enum Wifi_ResultCode
```

**Description**

Enumerates the error codes returned by Wi-Fi APIs.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| WIFI_SUCCESS = 0 | Operation success.|
| WIFI_PERMISSION_DENIED = 201 | Permission verification fails.|
| WIFI_INVALID_PARAM = 401 | Invalid parameter.<br> Possible causes: 1. The input parameter is a null pointer. 2. The parameter value is out of the value range.|
| WIFI_NOT_SUPPORTED = 801 | Unsupported function.|
| WIFI_OPERATION_FAILED = 2501000 | Operation failed.<br> Possible cause: The internal execution of the service fails.|


## Function Description

### OH_Wifi_IsWifiEnabled()

```
Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)
```

**Description**

Checks whether Wi-Fi is enabled.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| bool *enabled | Pointer to the boolean value indicating the Wi-Fi state.<br> The value **true** indicates that Wi-Fi is enabled, and the value **false** indicates the opposite.<br> A null pointer is prohibited. If a null pointer is passed in, an error is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode) | Operation result, which is specified by [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode). The value can be:<br>     [WIFI_SUCCESS](capi-oh-wifi-h.md#wifi_resultcode): The Wi-Fi switch status is obtained successfully.<br>     [WIFI_INVALID_PARAM](capi-oh-wifi-h.md#wifi_resultcode): The input parameter is a null pointer.<br>     [WIFI_OPERATION_FAILED](capi-oh-wifi-h.md#wifi_resultcode): An internal error occurs during service execution.|
