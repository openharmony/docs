# Telephony_NetworkState


## Overview

Network status.

**Since**: 13

**Related module**:[Telephony Radio](ndk-apis-telephony-radio.md)

## Summary


### Member Variables

| Name                                                         | Description                                   |
| -------- | -------- |
| [longOperatorName_](#longoperatorname_) [TELEPHONY_MAX_OPERATOR_LEN] | Long carrier name of the registered network. |
| [shortOperatorName_](#shortoperatorname_)[TELEPHONY_MAX_OPERATOR_LEN] | Short carrier name of the registered network. |
| [plmnNumeric_](#plmnnumeric_)[TELEPHONY_MAX_PLMN_NUMERIC_LEN] | PLMN code of the registered network. |
| [isRoaming_](#isroaming_) | Whether in roaming. |
| [regState_](#regstate_) | Network registration status. |
| [cfgTech_](#cfgtech_) | Radio technology. |
| [nsaState_](#nsastate_) | NSA state. |
| [isCaActive_](#iscaactive_) | Whether Carrier Aggregation(CA) is active. |
| [isEmergency_](#isemergency_) | Whether in emergency call only. |


## Member Variable Description


### longOperatorName_

```
char Telephony_NetworkState::longOperatorName_[TELEPHONY_MAX_OPERATOR_LEN]
```

**Description**

Long carrier name of the registered network.


### shortOperatorName_

```
char Telephony_NetworkState::shortOperatorName_[TELEPHONY_MAX_OPERATOR_LEN]
```

**Description**

  Short carrier name of the registered network.


### plmnNumeric_

```
char Telephony_NetworkState::plmnNumeric_[TELEPHONY_MAX_PLMN_NUMERIC_LEN]
```

**Description**

PLMN code of the registered network.


### isRoaming_

```
bool Telephony_NetworkState::isRoaming_
```

**Description**

Whether in roaming.

### regState_

```
Telephony_RegState Telephony_NetworkState::regState_
```

**Description**

Network registration status.

### cfgTech_

```
Telephony_RadioTechnology Telephony_NetworkState::cfgTech_
```

**Description**

Radio technology.

### nsaState_

```
Telephony_NsaState Telephony_NetworkState::nsaState_
```

**Description**

NSA state.

### isCaActive_

```
bool Telephony_NetworkState::isCaActive_
```

**Description**

Whether Carrier Aggregation(CA) is active.

### isEmergency_

```
bool Telephony_NetworkState::isEmergency_
```

**Description**

Whether in emergency call only.
