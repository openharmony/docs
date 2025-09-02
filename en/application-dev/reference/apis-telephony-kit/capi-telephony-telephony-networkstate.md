# Telephony_NetworkState

## Overview

Defines network status information.

**Since**: 13

**Related module**: [Telephony](capi-telephony.md)

**Header file**: [telephony_radio_type.h](capi-telephony-radio-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char longOperatorName_[TELEPHONY_MAX_OPERATOR_LEN] | Long carrier name of the registered network.|
| char shortOperatorName_[TELEPHONY_MAX_OPERATOR_LEN] | Short carrier name of the registered network.|
| char plmnNumeric_[TELEPHONY_MAX_PLMN_NUMERIC_LEN] | PLMN code of the registered network.|
| bool isRoaming_ | Whether the user is roaming.|
| Telephony_RegState regState_ | Network registration status of the device.|
| Telephony_RadioTechnology cfgTech_ | RAT of the device.|
| Telephony_NsaState nsaState_ | NSA network registration status of the device.|
| bool isCaActive_ | CA status.|
| bool isEmergency_ | Whether only emergency calls are allowed.|
