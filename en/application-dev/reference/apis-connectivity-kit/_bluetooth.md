# Bluetooth


## Overview

Provides APIs for obtaining the Bluetooth switch state.

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_bluetooth.h](oh__bluetooth_8h.md) | Defines the API for obtaining the Bluetooth switch state.<br>**File to include**: \<ConnectivityKit\/bluetooth\/oh_bluetooth.h\>|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [Bluetooth_SwitchState](#bluetooth_switchstate) [Bluetooth_SwitchState](#bluetooth_switchstate) | Defines an enum for Bluetooth switch states.|
| typedef enum [Bluetooth_ResultCode](#bluetooth_resultcode) [Bluetooth_ResultCode](#bluetooth_resultcode) | Defines an enum for the error codes returned by Bluetooth APIs.|


### Enums

| Name| Description|
| -------- | -------- |
| [Bluetooth_SwitchState](#bluetooth_switchstate) {<br>BLUETOOTH_STATE_OFF = 0,<br>BLUETOOTH_STATE_TURNING_ON = 1,<br>BLUETOOTH_STATE_ON = 2,<br>BLUETOOTH_STATE_TURNING_OFF = 3,<br>BLUETOOTH_STATE_BLE_TURNING_ON = 4,<br>BLUETOOTH_STATE_BLE_ON = 5,<br>BLUETOOTH_STATE_BLE_TURNING_OFF = 6<br>} | Enumerates the Bluetooth switch states.|
| [Bluetooth_ResultCode](#bluetooth_resultcode) {<br>BLUETOOTH_SUCCESS = 0,<br>BLUETOOTH_INVALID_PARAM = 401<br>} | Enumerates the error codes returned by Bluetooth APIs.|


### Functions

| Name| Description|
| -------- | -------- |
| [Bluetooth_ResultCode](#bluetooth_resultcode) [OH_Bluetooth_GetBluetoothSwitchState](#oh_bluetooth_getbluetoothswitchstate) ([Bluetooth_SwitchState](#bluetooth_switchstate) \*state) | Obtains the Bluetooth state.|


## Type Description


### Bluetooth_ResultCode

```
typedef enum Bluetooth_ResultCode Bluetooth_ResultCode
```

**Description**

Defines an enum for the error codes returned by Bluetooth APIs.

**Since**: 13


### Bluetooth_SwitchState

```
typedef enum Bluetooth_SwitchState Bluetooth_SwitchState
```

**Description**

Defines an enum for Bluetooth switch states.

**Since**: 13


## Enum Description


### Bluetooth_ResultCode

```
enum Bluetooth_ResultCode
```

**Description**

Enumerates the error codes returned by Bluetooth APIs.

**Since**: 13

| Value| Description|
| -------- | -------- |
| BLUETOOTH_SUCCESS | The operation is successful.|
| BLUETOOTH_INVALID_PARAM | Invalid parameter. Possible causes: 1. The input parameter is a null pointer. 2. The parameter value exceeds the value range.|


### Bluetooth_SwitchState

```
enum Bluetooth_SwitchState
```

**Description**

Enumerates Bluetooth switch states.

**Since**: 13

| Value| Description|
| -------- | -------- |
| BLUETOOTH_STATE_OFF | Bluetooth is turned off.|
| BLUETOOTH_STATE_TURNING_ON | Bluetooth is being turned on.|
| BLUETOOTH_STATE_ON | Bluetooth is turned on and ready for use.|
| BLUETOOTH_STATE_TURNING_OFF | Bluetooth is being turned off.|
| BLUETOOTH_STATE_BLE_TURNING_ON | The BLE only mode is being turned on.|
| BLUETOOTH_STATE_BLE_ON | The BLE only mode is turned on.|
| BLUETOOTH_STATE_BLE_TURNING_OFF | The BLE only mode is being turned off.|


## Function Description


### OH_Bluetooth_GetBluetoothSwitchState()

```
Bluetooth_ResultCode OH_Bluetooth_GetBluetoothSwitchState (Bluetooth_SwitchState * state)
```

**Description**

Obtains the Bluetooth state.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to the Bluetooth state obtained. A non-null pointer must be passed in. Otherwise, an error is returned. For details, see [Bluetooth_SwitchState](#bluetooth_switchstate).|

**Returns**

Returns a result code. For details, see [Bluetooth_ResultCode](#bluetooth_resultcode).<br>**BLUETOOTH_SUCCESS** indicates that the operation is successful. <br>**BLUETOOTH_INVALID_PARAM** indicates that the input parameter is a null pointer.

