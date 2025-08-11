# telephony_radio_type.h

## Overview

Declares the structs for the C APIs of the radio module.

**File to include**: <telephony/core_service/telephony_radio_type.h>

**Library**: libtelephony_radio.so

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Related module**: [Telephony](capi-telephony.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Telephony_NetworkState](capi-telephony-telephony-networkstate.md) | Telephony_NetworkState | Defines network status information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Telephony_RadioResult](#telephony_radioresult) | Telephony_RadioResult | Result codes.|
| [Telephony_RegState](#telephony_regstate) | Telephony_RegState | Network registration status of the device.|
| [Telephony_RadioTechnology](#telephony_radiotechnology) | Telephony_RadioTechnology | Radio access technology (RAT) type of the device.|
| [Telephony_NsaState](#telephony_nsastate) | Telephony_NsaState | NSA network registration status of the device.|

## Enum Description

### Telephony_RadioResult

```
enum Telephony_RadioResult
```

**Description**

Result codes.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| TEL_RADIO_SUCCESS = 0 | Operation succeeded.|
| TEL_RADIO_PERMISSION_DENIED = 201 | Permission denied.|
| TEL_RADIO_ERR_INVALID_PARAM = 401 | Invalid parameter.|
| TEL_RADIO_ERR_MARSHALLING_FAILED = 8300001 | Marshaling failed, which is a low-probability error. Try again later when this error occurs.|
| TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED = 8300002 | Connection error. Try again later when this error occurs.|
| TEL_RADIO_ERR_OPERATION_FAILED = 8300003 | Operation failed. Try again later when this error occurs.|

### Telephony_RegState

```
enum Telephony_RegState
```

**Description**

Network registration status of the device.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| TEL_REG_STATE_NO_SERVICE = 0 | The device cannot use any service.|
| TEL_REG_STATE_IN_SERVICE = 1 | The device can use services normally. |
| TEL_REG_STATE_EMERGENCY_CALL_ONLY = 2 | The device can use only the emergency call service.|
| TEL_REG_STATE_POWER_OFF = 3 | The cellular radio service is disabled.|

### Telephony_RadioTechnology

```
enum Telephony_RadioTechnology
```

**Description**

RAT type of the device.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| TEL_RADIO_TECHNOLOGY_UNKNOWN = 0 | Unknown RAT|
| TEL_RADIO_TECHNOLOGY_GSM = 1 | Global System for Mobile Communication (GSM)|
| TEL_RADIO_TECHNOLOGY_1XRTT = 2 | Single-Carrier Radio Transmission Technology (1XRTT)|
| TEL_RADIO_TECHNOLOGY_WCDMA = 3 | Wideband Code Division Multiple Access (WCDMA)|
| TEL_RADIO_TECHNOLOGY_HSPA = 4 | High Speed Packet Access (HSPA)|
| TEL_RADIO_TECHNOLOGY_HSPAP = 5 |  High Speed Packet Access Plus (HSPA+)|
| TEL_RADIO_TECHNOLOGY_TD_SCDMA = 6 | Time Division-Synchronous Code Division Multiple Access (TD-SCDMA)|
| TEL_RADIO_TECHNOLOGY_EVDO = 7 | Evolution-Data Optimized (EVDO)|
| TEL_RADIO_TECHNOLOGY_EHRPD = 8 | Evolved High Rate Package Data (EHRPD)|
| TEL_RADIO_TECHNOLOGY_LTE = 9 | Long Term Evolution (LTE)|
| TEL_RADIO_TECHNOLOGY_LTE_CA = 10 | Long Term Evolution_Carrier Aggregation (LTE_CA)|
| TEL_RADIO_TECHNOLOGY_IWLAN = 11 | Industrial Wireless LAN (IWLAN)|
| TEL_RADIO_TECHNOLOGY_NR = 12 | New Radio (NR)|

### Telephony_NsaState

```
enum Telephony_NsaState
```

**Description**

NSA network registration status of the device.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| TEL_NSA_STATE_NOT_SUPPORTED = 1 | The device is in idle or connected state in an LTE cell that does not support NSA.|
| TEL_NSA_STATE_NO_DETECTED = 2 | The device is in the idle state in an LTE cell that supports NSA but not NR coverage detection.|
| TEL_NSA_STATE_CONNECTED_DETECTED = 3 | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection.|
| TEL_NSA_STATE_IDLE_DETECTED = 4 | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection.|
| TEL_NSA_STATE_DUAL_CONNECTED = 5 | The device is connected to the LTE/NR network in an LTE cell that supports NSA.|
| TEL_NSA_STATE_SA_ATTACHED = 6 | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core.|
