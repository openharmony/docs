# telephony_radio_type.h


## Overview

Declares the structs for the C APIs of the radio module.

**Library**: libtelephony_radio.so

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Related module**: [Telephony Radio](ndk-apis-telephony-radio.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [Telephony_NetworkState](_telephony__network_state.md) | Network status structure.|


### Enums

| Name| Description|
| -------- | -------- |
| [Telephony_RadioResult](ndk-apis-telephony-radio.md#telephony_radioresult) { <br>TEL_RADIO_SUCCESS = 0,<br>TEL_RADIO_PERMISSION_DENIED = 201,<br>TEL_RADIO_ERR_INVALID_PARAM = 401,<br>TEL_RADIO_ERR_MARSHALLING_FAILED = 8300001,<br>TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED = 8300002,<br>TEL_RADIO_ERR_OPERATION_FAILED = 8300003,<br>} | Result codes.|
| [Telephony_RegState](ndk-apis-telephony-radio.md#telephony_regstate) {<br>TEL_REG_STATE_NO_SERVICE = 0,<br>TEL_REG_STATE_IN_SERVICE = 1,<br>TEL_REG_STATE_EMERGENCY_CALL_ONLY = 2,<br>TEL_REG_STATE_POWER_OFF = 3,<br>} | Network registration status of the device.|
| [Telephony_RadioTechnology](ndk-apis-telephony-radio.md#telephony_radiotechnology) {<br>TEL_RADIO_TECHNOLOGY_UNKNOWN = 0,<br>TEL_RADIO_TECHNOLOGY_GSM = 1,<br>TEL_RADIO_TECHNOLOGY_1XRTT = 2,<br>TEL_RADIO_TECHNOLOGY_WCDMA = 3,<br>TEL_RADIO_TECHNOLOGY_HSPA = 4,<br>TEL_RADIO_TECHNOLOGY_HSPAP = 5,<br>TEL_RADIO_TECHNOLOGY_TD_SCDMA = 6,<br>TEL_RADIO_TECHNOLOGY_EVDO = 7,<br>TEL_RADIO_TECHNOLOGY_EHRPD = 8,<br>TEL_RADIO_TECHNOLOGY_LTE = 9,<br>TEL_RADIO_TECHNOLOGY_LTE_CA = 10,<br>TEL_RADIO_TECHNOLOGY_IWLAN = 11,<br>TEL_RADIO_TECHNOLOGY_NR = 12,<br>} | Radio access technology (RAT) type of the device.|
| [Telephony_NsaState](ndk-apis-telephony-radio.md#telephony_nsastate) {<br>TEL_NSA_STATE_NOT_SUPPORTED = 1,<br>TEL_NSA_STATE_NO_DETECTED= 2,<br>TEL_NSA_STATE_CONNECTED_DETECTED = 3,<br>TEL_NSA_STATE_IDLE_DETECTED = 4,<br>TEL_NSA_STATE_DUAL_CONNECTED = 5,<br>TEL_NSA_STATE_SA_ATTACHED = 6,<br>} | NSA network registration status of the device.|
