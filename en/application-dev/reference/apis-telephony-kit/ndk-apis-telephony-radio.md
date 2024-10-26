# Telephony Radio


## Overview

Provides C APIs for the radio module.

**Since**: 13


## Summary


### File

| Name| Description|
| -------- | -------- |
| [telephony_radio.h](telephony__radio_8h.md) | Defines C APIs for the SSL/TLS certificate chain verification module.|
| [telephony_radio_type.h](telephony__radio__type_8h.md) | Defines data structures for the C APIs of the SSL/TLS certificate chain verification module.|


### Structs

| Name| Description|
| -------- | -------- |
| [Telephony_NetworkState](_telephony__network_state.md) | Network status structure.|

### Macros

| Name                              | Description|
| ---------------------------------- | ---- |
| **TELEPHONY_MAX_OPERATOR_LEN**     | 64   |
| **TELEPHONY_MAX_PLMN_NUMERIC_LEN** | 6    |

### Enums

| Name| Description|
| -------- | -------- |
| [Telephony_RadioResult](#telephony_radioresult) { <br>TEL_RADIO_SUCCESS = 0,<br>TEL_RADIO_PERMISSION_DENIED = 201,<br>TEL_RADIO_ERR_INVALID_PARAM = 401,<br>TEL_RADIO_ERR_MARSHALLING_FAILED = 8300001,<br>TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED = 8300002,<br>TEL_RADIO_ERR_OPERATION_FAILED = 8300003,<br>} | Result codes.|
| [Telephony_RegState](#telephony_regstate) {<br>TEL_REG_STATE_NO_SERVICE = 0,<br>TEL_REG_STATE_IN_SERVICE = 1,<br>TEL_REG_STATE_EMERGENCY_CALL_ONLY = 2,<br>TEL_REG_STATE_POWER_OFF = 3,<br>} | Network registration status of the device. |
| [Telephony_RadioTechnology](#telephony_radiotechnology) {<br>TEL_RADIO_TECHNOLOGY_UNKNOWN = 0,<br>TEL_RADIO_TECHNOLOGY_GSM = 1,<br>TEL_RADIO_TECHNOLOGY_1XRTT = 2,<br>TEL_RADIO_TECHNOLOGY_WCDMA = 3,<br>TEL_RADIO_TECHNOLOGY_HSPA = 4,<br>TEL_RADIO_TECHNOLOGY_HSPAP = 5,<br>TEL_RADIO_TECHNOLOGY_TD_SCDMA = 6,<br>TEL_RADIO_TECHNOLOGY_EVDO = 7,<br>TEL_RADIO_TECHNOLOGY_EHRPD = 8,<br>TEL_RADIO_TECHNOLOGY_LTE = 9,<br>TEL_RADIO_TECHNOLOGY_LTE_CA = 10,<br>TEL_RADIO_TECHNOLOGY_IWLAN = 11,<br>TEL_RADIO_TECHNOLOGY_NR = 12,<br>} | Radio access technology (RAT) type of the device.  |
| [Telephony_NsaState](#telephony_nsastate) {<br>TEL_NSA_STATE_NOT_SUPPORTED = 1,<br>TEL_NSA_STATE_NO_DETECTED = 2,<br>TEL_NSA_STATE_CONNECTED_DETECTED = 3,<br>TEL_NSA_STATE_IDLE_DETECTED = 4,<br>TEL_NSA_STATE_DUAL_CONNECTED = 5,<br>TEL_NSA_STATE_SA_ATTACHED = 6,<br>} | NSA network registration status of the device.|

### Functions

| Name| Description|
| -------- | -------- |
| [OH_Telephony_GetNetworkState](#oh_telephony_getnetworkstate) | Obtains the network status.            |
| [OH_Telephony_GetNetworkStateForSlot](#oh_telephony_getnetworkstateforslot) | Obtains the network status of the SIM card in the specified slot.|

## Enum Description


### Telephony_RadioResult

```
enum Telephony_RadioResult
```

**Description**

Result codes.

**Since**: 13

| Value| Description|
| -------- | -------- |
| TEL_RADIO_SUCCESS | Success.|
| TEL_RADIO_PERMISSION_DENIED | Invalid permission.|
| TEL_RADIO_ERR_INVALID_PARAM | Invalid parameter.|
| TEL_RADIO_ERR_MARSHALLING_FAILED | Marshalling failure.|
| TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED | Telephony service connection failure.|
| TEL_RADIO_ERR_OPERATION_FAILED | Telephony service operation failure.|


### Telephony_RegState

```
enum Telephony_RegState
```
**Description**
 Network registration status of the device.

**Since**: 13

| Value| Description|
| -------- | -------- |
| TEL_REG_STATE_NO_SERVICE | The device cannot use any services, including data, SMS, and call services.|
| TEL_REG_STATE_IN_SERVICE | The device can use services properly, including data, SMS, and call services.|
| TEL_REG_STATE_EMERGENCY_CALL_ONLY | The device can use only the emergency call service.|
| TEL_REG_STATE_POWER_OFF | The device cannot communicate with the network because the cellular radio service is disabled or the modem is powered off.|

### Telephony_RadioTechnology

```
enum Telephony_RadioTechnology
```

**Description**

  RAT type of the device.

**Since**: 13

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| TEL_RADIO_TECHNOLOGY_UNKNOWN  | Unknown RAT                                   |
| TEL_RADIO_TECHNOLOGY_GSM      | Global System for Mobile Communication (GSM) |
| TEL_RADIO_TECHNOLOGY_1XRTT    | Single-Carrier Radio Transmission Technology (1XRTT)|
| TEL_RADIO_TECHNOLOGY_WCDMA    | Wideband Code Division Multiple Access (WCDMA)|
| TEL_RADIO_TECHNOLOGY_HSPA     | High Speed Packet Access (HSPA)              |
| TEL_RADIO_TECHNOLOGY_HSPAP    | Evolved High Speed Packet Access (HSPA+)    |
| TEL_RADIO_TECHNOLOGY_TD_SCDMA | Time Division Synchronous Code Division Multiple Access (TD-SCDMA)|
| TEL_RADIO_TECHNOLOGY_EVDO     | Evolution-Data Optimized (EVDO)                   |
| TEL_RADIO_TECHNOLOGY_EHRPD    | Evolved High Rate Package Data (EHRPD)       |
| TEL_RADIO_TECHNOLOGY_LTE      | Long Term Evolution (LTE)                    |
| TEL_RADIO_TECHNOLOGY_LTE_CA   | Long Term Evolution_Carrier Aggregation (LTE_CA)|
| TEL_RADIO_TECHNOLOGY_IWLAN    | Industrial Wireless LAN (IWLAN)              |
| TEL_RADIO_TECHNOLOGY_NR       | New Radio (NR)                               |

### Telephony_NsaState

```
enum Telephony_NsaState
```

**Description**

NSA network registration status of the device.

**Since**: 13

| Value                          | Description                                                      |
| -------------------------------- | ---------------------------------------------------------- |
| TEL_NSA_STATE_NOT_SUPPORTED      | The device is in idle or connected state in an LTE cell that does not support NSA.        |
| TEL_NSA_STATE_NO_DETECTED        | The device is in the idle state in an LTE cell that supports NSA but not NR coverage detection.|
| TEL_NSA_STATE_CONNECTED_DETECTED | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection.         |
| TEL_NSA_STATE_IDLE_DETECTED      | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection.          |
| TEL_NSA_STATE_DUAL_CONNECTED     | The device is connected to the LTE/NR network in an LTE cell that supports NSA.              |
| TEL_NSA_STATE_SA_ATTACHED        | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core.     |

## Function Description


### OH_Telephony_GetNetworkState()

```
Telephony_RadioResult OH_Telephony_GetNetworkState(Telephony_NetworkState * state)
```

**Description**

Obtains the network status.

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Structure of the network status information received by the user.|

**Returns**

**0**: success.

**201**: invalid permission.

**401**: invalid parameter.

**8300001**: marshalling failure.

**8300002**: telephony service connection failure.

**8300003**: telephony service operation failure.

**Required Permissions**

ohos.permission.GET_NETWORK_INFO

### OH_Telephony_GetNetworkStateForSlot()

```
Telephony_RadioResult OH_Telephony_GetNetworkStateForSlot(int32_t slotId, Telephony_NetworkState *state)
```

**Description**

Obtains the network status of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Parameters**

| Name  | Description                          |
| ------ | ------------------------------ |
| slotId | Card slot ID.                        |
| state  | Structure of the network status information received by the user.|

**Returns**

**0**: success.

**201**: invalid permission.

**401**: invalid parameter.

8300001: marshalling failure.

**8300002**: telephony service connection failure.

**8300003**: telephony service operation failure.

**Required Permissions**

ohos.permission.GET_NETWORK_INFO
