# telephony_radio_type.h


## 概述

定义网络搜索模块的C接口需要的数据结构。

**库：** libtelephony_radio.so

**系统能力：** SystemCapability.Telephony.CoreService

**起始版本：** 13

**相关模块：**[Telephony Radio](ndk-apis-telephony-radio.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Telephony_NetworkState](_telephony__network_state.md) | 网络状态结构体。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Telephony_RadioResult](ndk-apis-telephony-radio.md#telephony_radioresult) { <br>[TEL_RADIO_SUCCESS](ndk-apis-telephony-radio.md) = 0,<br />[TEL_RADIO_PERMISSION_DENIED](ndk-apis-telephony-radio.md) = 201,<br />[TEL_RADIO_ERR_INVALID_PARAM](ndk-apis-telephony-radio.md) = 401,<br />[TEL_RADIO_ERR_MARSHALLING_FAILED](ndk-apis-telephony-radio.md) = 8300001,<br />[TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED](ndk-apis-telephony-radio.md) = 8300002,<br />[TEL_RADIO_ERR_OPERATION_FAILED](ndk-apis-telephony-radio.md) = 8300003,<br />} | 错误码类型枚举。 |
| [Telephony_RegState](ndk-apis-telephony-radio.md#telephony_regstate) {<br />[TEL_REG_STATE_NO_SERVICE](ndk-apis-telephony-radio.md) = 0,<br />[TEL_REG_STATE_IN_SERVICE](ndk-apis-telephony-radio.md) = 1,<br />[TEL_REG_STATE_EMERGENCY_CALL_ONLY](ndk-apis-telephony-radio.md) = 2,<br />[TEL_REG_STATE_POWER_OFF](ndk-apis-telephony-radio.md) = 3,<br />} | 设备的网络注册状态类型 |
| [Telephony_RadioTechnology](ndk-apis-telephony-radio.md#telephony_radiotechnology) {<br />[TEL_RADIO_TECHNOLOGY_UNKNOWN](ndk-apis-telephony-radio.md) = 0,<br />[TEL_RADIO_TECHNOLOGY_GSM](ndk-apis-telephony-radio.md) = 1,<br />[TEL_RADIO_TECHNOLOGY_1XRTT](ndk-apis-telephony-radio.md) = 2,<br />[TEL_RADIO_TECHNOLOGY_WCDMA](ndk-apis-telephony-radio.md) = 3,<br />[TEL_RADIO_TECHNOLOGY_HSPA](ndk-apis-telephony-radio.md) = 4,<br />[TEL_RADIO_TECHNOLOGY_HSPAP](ndk-apis-telephony-radio.md) = 5,<br />[TEL_RADIO_TECHNOLOGY_TD_SCDMA](ndk-apis-telephony-radio.md) = 6,<br />[TEL_RADIO_TECHNOLOGY_EVDO](ndk-apis-telephony-radio.md) = 7,<br />[TEL_RADIO_TECHNOLOGY_EHRPD](ndk-apis-telephony-radio.md) = 8,<br />[TEL_RADIO_TECHNOLOGY_LTE](ndk-apis-telephony-radio.md) = 9,<br />[TEL_RADIO_TECHNOLOGY_LTE_CA](ndk-apis-telephony-radio.md) = 10,<br />[TEL_RADIO_TECHNOLOGY_IWLAN](ndk-apis-telephony-radio.md) = 11,<br />[TEL_RADIO_TECHNOLOGY_NR](ndk-apis-telephony-radio.md) = 12,<br />} | 设备的无线接入技术类型 |
| [Telephony_NsaState](ndk-apis-telephony-radio.md#telephony_nsastate) {<br />[TEL_NSA_STATE_NOT_SUPPORTED](ndk-apis-telephony-radio.md) = 1,<br />[TEL_NSA_STATE_NO_DETECTED](ndk-apis-telephony-radio.md) = 2,<br />[TEL_NSA_STATE_CONNECTED_DETECTED](ndk-apis-telephony-radio.md) = 3,<br />[TEL_NSA_STATE_IDLE_DETECTED](ndk-apis-telephony-radio.md) = 4,<br />[TEL_NSA_STATE_DUAL_CONNECTED](ndk-apis-telephony-radio.md) = 5,<br />[TEL_NSA_STATE_SA_ATTACHED](ndk-apis-telephony-radio.md) = 6,<br />} | 设备的NSA网络注册状态类型 |
