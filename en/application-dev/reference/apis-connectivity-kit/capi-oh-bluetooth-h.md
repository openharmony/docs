# oh_bluetooth.h

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## Overview

Defines the API for obtaining the Bluetooth switch state.

**File to include**: <ConnectivityKit/bluetooth/oh_bluetooth.h>

**Library**: libbluetooth_ndk.so

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Since**: 13

**Related module**: [Bluetooth](capi-bluetooth.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Bluetooth_SwitchState](#bluetooth_switchstate) | Bluetooth_SwitchState | Enumerates the Bluetooth switch states.|
| [Bluetooth_ResultCode](#bluetooth_resultcode) | Bluetooth_ResultCode | Defines the Bluetooth return value.|

### Functions

| Name| Description|
| -- | -- |
| [Bluetooth_ResultCode OH_Bluetooth_GetBluetoothSwitchState(Bluetooth_SwitchState *state)](#oh_bluetooth_getbluetoothswitchstate) | Obtains the Bluetooth state.|

## Enum Description

### Bluetooth_SwitchState

```
enum Bluetooth_SwitchState
```

**Description**

Enumerates the Bluetooth switch states.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| BLUETOOTH_STATE_OFF = 0 | Bluetooth is turned off.|
| BLUETOOTH_STATE_TURNING_ON = 1 | Bluetooth is being turned on.|
| BLUETOOTH_STATE_ON = 2 | Bluetooth is turned on and ready for use.|
| BLUETOOTH_STATE_TURNING_OFF = 3 | Bluetooth is being turned off.|
| BLUETOOTH_STATE_BLE_TURNING_ON = 4 | The BLE only mode is being turned on.|
| BLUETOOTH_STATE_BLE_ON = 5 | The BLE only mode is turned on.|
| BLUETOOTH_STATE_BLE_TURNING_OFF = 6 | The BLE only mode is being turned off.|

### Bluetooth_ResultCode

```
enum Bluetooth_ResultCode
```

**Description**

Defines the Bluetooth return value.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| BLUETOOTH_SUCCESS = 0 | Operation success.|
| BLUETOOTH_INVALID_PARAM = 401 | Invalid parameter. Possible causes: 1. The input parameter is a null pointer. 2. The parameter value exceeds the value range.|


## Function Description

### OH_Bluetooth_GetBluetoothSwitchState()

```
Bluetooth_ResultCode OH_Bluetooth_GetBluetoothSwitchState(Bluetooth_SwitchState *state)
```

**Description**

Obtains the Bluetooth state.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [Bluetooth_SwitchState](capi-oh-bluetooth-h.md#bluetooth_switchstate) *state | Pointer to the Bluetooth state obtained. A null pointer is prohibited. If a null pointer is passed in, an error is returned. For details, see [Bluetooth_SwitchState](capi-oh-bluetooth-h.md#bluetooth_switchstate).|

**Returns**

| Type| Description|
| -- | -- |
| [Bluetooth_ResultCode](capi-oh-bluetooth-h.md#bluetooth_resultcode) | Bluetooth switch state enumerated by [Bluetooth_ResultCode](capi-oh-bluetooth-h.md#bluetooth_resultcode).<br>     The value can be:<br>     [BLUETOOTH_SUCCESS](capi-oh-bluetooth-h.md#bluetooth_resultcode): The Bluetooth switch status is successfully obtained.<br>     [BLUETOOTH_INVALID_PARAM](capi-oh-bluetooth-h.md#bluetooth_resultcode): The input parameter is a null pointer.|
