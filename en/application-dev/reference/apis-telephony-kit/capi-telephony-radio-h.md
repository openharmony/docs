# telephony_radio.h

## Overview

Defines C APIs for the radio module.

**Library**: libtelephony_radio.so

**System capability**: SystemCapability.Telephony.CoreService

**Since**: 13

**Related module**: [Telephony](capi-telephony.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [Telephony_RadioResult OH_Telephony_GetNetworkState(Telephony_NetworkState *state)](#oh_telephony_getnetworkstate) | Obtains the network status.|
| [Telephony_RadioResult OH_Telephony_GetNetworkStateForSlot(int32_t slotId, Telephony_NetworkState *state)](#oh_telephony_getnetworkstateforslot) | Obtains the network status of the SIM card in the specified slot.|

## Function Description

### OH_Telephony_GetNetworkState()

```
Telephony_RadioResult OH_Telephony_GetNetworkState(Telephony_NetworkState *state)
```

**Description**

Obtains the network status.

**System capability**: SystemCapability.Telephony.CoreService

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [Telephony_NetworkState](capi-telephony-telephony-networkstate.md) *state | Structure of the network status information received by the user.|

**Returns**

| Type| Description|
| -- | -- |
| [Telephony_RadioResult](capi-telephony-radio-type-h.md#telephony_radioresult) | Result code. For details, see [Telephony_RadioResult](capi-telephony-radio-type-h.md#telephony_radioresult).<br>         [TEL_RADIO_SUCCESS](capi-telephony-radio-type-h.md#telephony_radioresult): Operation succeeded.<br>         [TEL_RADIO_PERMISSION_DENIED](capi-telephony-radio-type-h.md#telephony_radioresult): Permission denied.<br>         [TEL_RADIO_ERR_MARSHALLING_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Marshalling failed.<br>         [TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Telephony service connection failed.<br>         [TEL_RADIO_ERR_OPERATION_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Telephony service operation failed.<br>         [TEL_RADIO_ERR_INVALID_PARAM](capi-telephony-radio-type-h.md#telephony_radioresult): Invalid parameter.|

### OH_Telephony_GetNetworkStateForSlot()

```
Telephony_RadioResult OH_Telephony_GetNetworkStateForSlot(int32_t slotId, Telephony_NetworkState *state)
```

**Description**

Obtains the network status of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| int32_t slotId | Card slot ID.|
| [Telephony_NetworkState](capi-telephony-telephony-networkstate.md) *state | Structure of the network status information received by the user.|

**Returns**

| Type| Description|
| -- | -- |
| [Telephony_RadioResult](capi-telephony-radio-type-h.md#telephony_radioresult) | Result code. For details, see [Telephony_RadioResult](capi-telephony-radio-type-h.md#telephony_radioresult).<br>         [TEL_RADIO_SUCCESS](capi-telephony-radio-type-h.md#telephony_radioresult): Operation succeeded.<br>         [TEL_RADIO_PERMISSION_DENIED](capi-telephony-radio-type-h.md#telephony_radioresult): Permission denied.<br>         [TEL_RADIO_ERR_MARSHALLING_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Marshalling failed.<br>         [TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Telephony service connection failed.<br>         [TEL_RADIO_ERR_OPERATION_FAILED](capi-telephony-radio-type-h.md#telephony_radioresult): Telephony service operation failed.<br>         [TEL_RADIO_ERR_INVALID_PARAM](capi-telephony-radio-type-h.md#telephony_radioresult): Invalid parameter.|
