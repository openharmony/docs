# Telephony_NetworkState


## 概述

网络状态信息。

**起始版本：** 13

**相关模块：**[Telephony Radio](ndk-apis-telephony-radio.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [longOperatorName_](#longoperatorname_) [TELEPHONY_MAX_OPERATOR_LEN] | 注册网络的长运营商名称。 |
| [shortOperatorName_](#shortoperatorname_)[TELEPHONY_MAX_OPERATOR_LEN] | 注册网络的短运营商名称。 |
| [plmnNumeric_](#plmnnumeric_)[TELEPHONY_MAX_PLMN_NUMERIC_LEN] | 注册网络的PLMN码。 |
| [isRoaming_](#isroaming_) | 是否处于漫游状态。 |
| [regState_](#regstate_) | 设备的网络注册状态。 |
| [cfgTech_](#cfgtech_) | 设备的无线接入技术。 |
| [nsaState_](#nsastate_) | 设备的NSA网络注册状态。 |
| [isCaActive_](#iscaactive_) | CA的状态。 |
| [isEmergency_](#isemergency_) | 此设备是否只允许拨打紧急呼叫。 |


## 结构体成员变量说明


### longOperatorName_

```
char Telephony_NetworkState::longOperatorName_[TELEPHONY_MAX_OPERATOR_LEN]
```

**描述**

注册网络的长运营商名称。


### shortOperatorName_

```
char Telephony_NetworkState::shortOperatorName_[TELEPHONY_MAX_OPERATOR_LEN]
```

**描述**

注册网络的短运营商名称。


### plmnNumeric_

```
char Telephony_NetworkState::plmnNumeric_[TELEPHONY_MAX_PLMN_NUMERIC_LEN]
```

**描述**

注册网络的PLMN码。


### isRoaming_

```
bool Telephony_NetworkState::isRoaming_
```

**描述**

是否处于漫游状态。

### regState_

```
Telephony_RegState Telephony_NetworkState::regState_
```

**描述**

设备的网络注册状态。

### cfgTech_

```
Telephony_RadioTechnology Telephony_NetworkState::cfgTech_
```

**描述**

设备的无线接入技术。

### nsaState_

```
Telephony_NsaState Telephony_NetworkState::nsaState_
```

**描述**

设备的NSA网络注册状态。

### isCaActive_

```
bool Telephony_NetworkState::isCaActive_
```

**描述**

CA的状态。

### isEmergency_

```
bool Telephony_NetworkState::isEmergency_
```

**描述**

此设备是否只允许拨打紧急呼叫。
