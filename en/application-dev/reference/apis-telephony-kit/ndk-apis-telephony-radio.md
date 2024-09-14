# Telephony Radio


## Overview

Provides C interface for the telephony radio.

**Since**: 13


## Summary


### File

| Name                                                   | Description                                                  |
| -------- | -------- |
| [telephony_radio.h](telephony__radio_8h.md) | Provides C interface for the telephony radio. |
| [telephony_radio_type.h](telephony__radio__type_8h.md) | Provides the data structures for the C APIs of the the telephony radio. |


### Structs

| Name                                                   | Description     |
| -------- | -------- |
| [Telephony_NetworkState](_telephony__network_state.md) | Network status. |

### Macros

| Name                               | Description |
| ---------------------------------- | ----------- |
| **TELEPHONY_MAX_OPERATOR_LEN**     | 64          |
| **TELEPHONY_MAX_PLMN_NUMERIC_LEN** | 6           |

### Enums

| Name                                                         | Description                  |
| -------- | -------- |
| [Telephony_RadioResult](#telephony_radioresult) { <br/>TEL_RADIO_SUCCESS = 0,<br />TEL_RADIO_PERMISSION_DENIED = 201,<br />TEL_RADIO_ERR_INVALID_PARAM = 401,<br />TEL_RADIO_ERR_MARSHALLING_FAILED = 8300001,<br />TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED = 8300002,<br />TEL_RADIO_ERR_OPERATION_FAILED = 8300003,<br />} | Result code. |
| [Telephony_RegState](#telephony_regstate) {<br />TEL_REG_STATE_NO_SERVICE = 0,<br />TEL_REG_STATE_IN_SERVICE = 1,<br />TEL_REG_STATE_EMERGENCY_CALL_ONLY = 2,<br />TEL_REG_STATE_POWER_OFF = 3,<br />} | network registration status. |
| [Telephony_RadioTechnology](#telephony_radiotechnology) {<br />TEL_RADIO_TECHNOLOGY_UNKNOWN = 0,<br />TEL_RADIO_TECHNOLOGY_GSM = 1,<br />TEL_RADIO_TECHNOLOGY_1XRTT = 2,<br />TEL_RADIO_TECHNOLOGY_WCDMA = 3,<br />TEL_RADIO_TECHNOLOGY_HSPA = 4,<br />TEL_RADIO_TECHNOLOGY_HSPAP = 5,<br />TEL_RADIO_TECHNOLOGY_TD_SCDMA = 6,<br />TEL_RADIO_TECHNOLOGY_EVDO = 7,<br />TEL_RADIO_TECHNOLOGY_EHRPD = 8,<br />TEL_RADIO_TECHNOLOGY_LTE = 9,<br />TEL_RADIO_TECHNOLOGY_LTE_CA = 10,<br />TEL_RADIO_TECHNOLOGY_IWLAN = 11,<br />TEL_RADIO_TECHNOLOGY_NR = 12,<br />} | radio access technologies. |
| [Telephony_NsaState](#telephony_nsastate) {<br />TEL_NSA_STATE_NOT_SUPPORTED = 1,<br />TEL_NSA_STATE_NO_DETECTED = 2,<br />TEL_NSA_STATE_CONNECTED_DETECTED = 3,<br />TEL_NSA_STATE_IDLE_DETECTED = 4,<br />TEL_NSA_STATE_DUAL_CONNECTED = 5,<br />TEL_NSA_STATE_SA_ATTACHED = 6,<br />} | NSA network state. |

### Functions

| Name                                                         | Description                                        |
| -------- | -------- |
| [OH_Telephony_GetNetworkState](#oh_telephony_getnetworkstate) | Obtains the radio network state. |
| [OH_Telephony_GetNetworkStateForSlot](#oh_telephony_getnetworkstateforslot) | Obtains the radio network state for given slot id. |

## Enum Description


### Telephony_RadioResult

```
enum Telephony_RadioResult
```

**Description**

Result code.

**Since**: 13

| Value                                   | Description                                                  |
| -------- | -------- |
| TEL_RADIO_SUCCESS | success. |
| TEL_RADIO_PERMISSION_DENIED | permission denied. |
| TEL_RADIO_ERR_INVALID_PARAM | invalid parameter. |
| TEL_RADIO_ERR_MARSHALLING_FAILED | marshalling failed, this is a low probability error, try again later when get this error. |
| TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED | unable to connect to telephony service, try again later when get this error. |
| TEL_RADIO_ERR_OPERATION_FAILED | operation failed in telephony service, try again later when get this error. |


### Telephony_RegState

```
enum Telephony_RegState
```
**Description**
network registration status.

**Since**: 13

| Value                             | Description                  |
| -------- | -------- |
| TEL_REG_STATE_NO_SERVICE | can not use any services. |
| TEL_REG_STATE_IN_SERVICE | can use services properly. |
| TEL_REG_STATE_EMERGENCY_CALL_ONLY | can use emergency call only. |
| TEL_REG_STATE_POWER_OFF | radio power off. |

### Telephony_RadioTechnology

```
enum Telephony_RadioTechnology
```

**Description**

radio access technologies.

**Since**: 13

| Value                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| TEL_RADIO_TECHNOLOGY_UNKNOWN  | Unknown radio technology.                                    |
| TEL_RADIO_TECHNOLOGY_GSM      | Global System for Mobile Communication (GSM).                |
| TEL_RADIO_TECHNOLOGY_1XRTT    | Single-Carrier Radio Transmission Technology (1XRTT).        |
| TEL_RADIO_TECHNOLOGY_WCDMA    | Wideband Code Division Multiple Access (WCDMA).              |
| TEL_RADIO_TECHNOLOGY_HSPA     | High Speed Packet Access (HSPA).                             |
| TEL_RADIO_TECHNOLOGY_HSPAP    | Evolved High Speed Packet Access (HSPA+).                    |
| TEL_RADIO_TECHNOLOGY_TD_SCDMA | Time Division-Synchronous Code Division Multiple Access(TD-SCDMA). |
| TEL_RADIO_TECHNOLOGY_EVDO     | Evolution-Data Optimized (EVDO).                             |
| TEL_RADIO_TECHNOLOGY_EHRPD    | Evolved High Rate Package Data (EHRPD).                      |
| TEL_RADIO_TECHNOLOGY_LTE      | Long Term Evolution (LTE).                                   |
| TEL_RADIO_TECHNOLOGY_LTE_CA   | Long Term Evolution_Carrier Aggregation (LTE_CA).            |
| TEL_RADIO_TECHNOLOGY_IWLAN    | Industrial Wireless LAN (IWLAN).                             |
| TEL_RADIO_TECHNOLOGY_NR       | New Radio (NR).                                              |

### Telephony_NsaState

```
enum Telephony_NsaState
```

**Description**

NSA network state.

**Since**: 13

| Value                            | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| TEL_NSA_STATE_NOT_SUPPORTED      | The device is in idle or connected state in an LTE cell that does not support NSA. |
| TEL_NSA_STATE_NO_DETECTED        | The device is in the idle state in an LTE cell that supports NSA but not NR coverage detection. |
| TEL_NSA_STATE_CONNECTED_DETECTED | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection. |
| TEL_NSA_STATE_IDLE_DETECTED      | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection. |
| TEL_NSA_STATE_DUAL_CONNECTED     | The device is connected to the LTE/NR network in an LTE cell that supports NSA. |
| TEL_NSA_STATE_SA_ATTACHED        | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core. |

## Function Description


### OH_Telephony_GetNetworkState()

```
Telephony_RadioResult OH_Telephony_GetNetworkState(Telephony_NetworkState * state)
```

**Description**

Obtains the radio network state.

**System capability** :SystemCapability.Telephony.CoreService

**Since**: 13

**Parameters**

| Name  | Description                   |
| -------- | -------- |
| state | Pointer to the network state. |

**Returns**

**0**: success.

**201**: permission denied.

**401**: invalid parameter.

**8300001**: low probability Marshalling failed, try again later.

**8300002**: unable to connect to telephony service, try again later.

**8300003**: operation failed in telephony service, try again later.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO

### OH_Telephony_GetNetworkStateForSlot()

```
Telephony_RadioResult OH_Telephony_GetNetworkStateForSlot(int32_t slotId, Telephony_NetworkState *state)
```

**Description**

Obtains the radio network state for given slot id.

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Parameters**

| Name   | Description                                               |
| ------ | --------------------------------------------------------- |
| slotId | the number of slot, 0 for card slot 1, 1 for card slot 2. |
| state  | Pointer to the network state.                             |

**Returns**

**0**: success.

**201**: permission denied.

**401**: invalid parameter.

**8300001**: low probability Marshalling failed, try again later.

**8300002**: unable to connect to telephony service, try again later.

**8300003**: operation failed in telephony service, try again later.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO

