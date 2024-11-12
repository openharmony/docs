# Wifi


## Overview

Provides APIs for obtaining the Wi-Fi switch state.

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_wifi.h](oh__wifi_8h.md) | Defines APIs for obtaining Wi-Fi switch state.<br>**File to include**: \<ConnectivityKit\/wifi\/oh_wifi.h\> |


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [Wifi_ResultCode](#wifi_resultcode) [Wifi_ResultCode](#wifi_resultcode) | Defines an enum for the error codes returned by Wi-Fi APIs.|


### Enums

| Name| Description|
| -------- | -------- |
| [Wifi_ResultCode](#wifi_resultcode) {<br>WIFI_SUCCESS = 0,<br>WIFI_PERMISSION_DENIED = 201,<br>WIFI_INVALID_PARAM = 401,<br>WIFI_NOT_SUPPORTED = 801,<br>WIFI_OPERATION_FAILED = 2501000<br>} | Enumerates the error codes returned by Wi-Fi APIs.|


### Functions

| Name| Description|
| -------- | -------- |
| [Wifi_ResultCode](#wifi_resultcode) [OH_Wifi_IsWifiEnabled](#oh_wifi_iswifienabled) (bool \*enabled) | Checks whether Wi-Fi is enabled.|


## Type Description


### Wifi_ResultCode

```
typedef enum Wifi_ResultCode Wifi_ResultCode
```

**Description**

Defines an enum for the error codes returned by Wi-Fi APIs.

**Since**: 13


## Enum Description


### Wifi_ResultCode

```
enum Wifi_ResultCode
```

**Description**

Enumerates the error codes returned by Wi-Fi APIs.

**Since**: 13

| Value| Description|
| -------- | -------- |
| WIFI_SUCCESS | The operation is successful.|
| WIFI_PERMISSION_DENIED | Permission verification has failed.|
| WIFI_INVALID_PARAM | Invalid parameter.<br>Possible causes: 1. The input parameter is a null pointer. 2. The parameter value is out of the value range.|
| WIFI_NOT_SUPPORTED | The API cannot be called because the device does not have the required capabilities.|
| WIFI_OPERATION_FAILED | Operation failed.<br>Possible cause: The internal execution of the service fails.|


## Function Description


### OH_Wifi_IsWifiEnabled()

```
Wifi_ResultCode OH_Wifi_IsWifiEnabled (bool * enabled)
```

**Description**

Checks whether Wi-Fi is enabled.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| enabled | Pointer to the Wi-Fi state obtained.<br>The value **true** means Wi-Fi is enabled; the value **false** means the opposite.<br>A non-null pointer must be passed in. Otherwise, an error is returned.|

**Returns**

Returns the operation result. For details, see [Wifi_ResultCode](#wifi_resultcode).

**WIFI_SUCCESS** indicates that the operation is successful.

**WIFI_INVALID_PARAM** indicates that the input parameter is a null pointer.

**WIFI_OPERATION_FAILED** indicates an internal service error.
