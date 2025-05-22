# Telephony Radio


## 概述

为网络搜索模块提供C接口。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [telephony_radio.h](telephony__radio_8h.md) | 为SSL/TLS证书链校验模块定义C接口。<br>**引用文件：** \<telephony\/core_service\/telephony_radio.h\> |
| [telephony_radio_type.h](telephony__radio__type_8h.md) | 定义SSL/TLS证书链校验模块的C接口需要的数据结构。<br>**引用文件：** \<telephony\/core_service\/telephony_radio_type.h\> |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Telephony_NetworkState](_telephony__network_state.md) | 网络状态结构体。 |

### 宏定义

| 名称                               | 描述 |
| ---------------------------------- | ---- |
| TELEPHONY_MAX_OPERATOR_LEN     | 64   |
| TELEPHONY_MAX_PLMN_NUMERIC_LEN | 6    |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Telephony_RadioResult](#telephony_radioresult) { <br/>TEL_RADIO_SUCCESS = 0,<br />TEL_RADIO_PERMISSION_DENIED = 201,<br />TEL_RADIO_ERR_INVALID_PARAM = 401,<br />TEL_RADIO_ERR_MARSHALLING_FAILED = 8300001,<br />TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED = 8300002,<br />TEL_RADIO_ERR_OPERATION_FAILED = 8300003,<br />} | 错误码类型枚举。 |
| [Telephony_RegState](#telephony_regstate) {<br />TEL_REG_STATE_NO_SERVICE = 0,<br />TEL_REG_STATE_IN_SERVICE = 1,<br />TEL_REG_STATE_EMERGENCY_CALL_ONLY = 2,<br />TEL_REG_STATE_POWER_OFF = 3,<br />} | 设备的网络注册状态类型。  |
| [Telephony_RadioTechnology](#telephony_radiotechnology) {<br />TEL_RADIO_TECHNOLOGY_UNKNOWN = 0,<br />TEL_RADIO_TECHNOLOGY_GSM = 1,<br />TEL_RADIO_TECHNOLOGY_1XRTT = 2,<br />TEL_RADIO_TECHNOLOGY_WCDMA = 3,<br />TEL_RADIO_TECHNOLOGY_HSPA = 4,<br />TEL_RADIO_TECHNOLOGY_HSPAP = 5,<br />TEL_RADIO_TECHNOLOGY_TD_SCDMA = 6,<br />TEL_RADIO_TECHNOLOGY_EVDO = 7,<br />TEL_RADIO_TECHNOLOGY_EHRPD = 8,<br />TEL_RADIO_TECHNOLOGY_LTE = 9,<br />TEL_RADIO_TECHNOLOGY_LTE_CA = 10,<br />TEL_RADIO_TECHNOLOGY_IWLAN = 11,<br />TEL_RADIO_TECHNOLOGY_NR = 12,<br />} | 设备的无线接入技术类型。   |
| [Telephony_NsaState](#telephony_nsastate) {<br />TEL_NSA_STATE_NOT_SUPPORTED = 1,<br />TEL_NSA_STATE_NO_DETECTED = 2,<br />TEL_NSA_STATE_CONNECTED_DETECTED = 3,<br />TEL_NSA_STATE_IDLE_DETECTED = 4,<br />TEL_NSA_STATE_DUAL_CONNECTED = 5,<br />TEL_NSA_STATE_SA_ATTACHED = 6,<br />} | 设备的NSA网络注册状态类型。 |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Telephony_GetNetworkState](#oh_telephony_getnetworkstate) | 获取网络状态。             |
| [OH_Telephony_GetNetworkStateForSlot](#oh_telephony_getnetworkstateforslot) | 获取给定卡槽ID的网络状态。 |

## 枚举类型说明


### Telephony_RadioResult

```
enum Telephony_RadioResult
```

**描述**

错误码类型枚举。

**起始版本：** 13

| 枚举值 | 描述 |
| -------- | -------- |
| TEL_RADIO_SUCCESS | 成功。 |
| TEL_RADIO_PERMISSION_DENIED | 权限错误。 |
| TEL_RADIO_ERR_INVALID_PARAM | 参数错误。 |
| TEL_RADIO_ERR_MARSHALLING_FAILED | 编组错误。 |
| TEL_RADIO_ERR_SERVICE_CONNECTION_FAILED | 连接电话服务错误。 |
| TEL_RADIO_ERR_OPERATION_FAILED | 操作电话服务错误。 |


### Telephony_RegState

```
enum Telephony_RegState
```
**描述**
 设备的网络注册状态类型。

**起始版本：** 13

| 枚举值 | 描述 |
| -------- | -------- |
| TEL_REG_STATE_NO_SERVICE | 设备不能使用任何服务，包括数据业务、短信、通话等。 |
| TEL_REG_STATE_IN_SERVICE | 设备可以正常使用服务，包括数据业务、短信、通话等。 |
| TEL_REG_STATE_EMERGENCY_CALL_ONLY | 设备只能使用紧急呼叫业务。 |
| TEL_REG_STATE_POWER_OFF | 蜂窝无线电已关闭，modem下电，无法和网侧进行通信。 |

### Telephony_RadioTechnology

```
enum Telephony_RadioTechnology
```

**描述**

  设备的无线接入技术类型。

**起始版本：** 13

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| TEL_RADIO_TECHNOLOGY_UNKNOWN  | 未知无线接入技术（RAT）。                                    |
| TEL_RADIO_TECHNOLOGY_GSM      | 无线接入技术GSM（Global System For Mobile Communication）。  |
| TEL_RADIO_TECHNOLOGY_1XRTT    | 无线接入技术1XRTT（Single-Carrier Radio Transmission Technology）。 |
| TEL_RADIO_TECHNOLOGY_WCDMA    | 无线接入技术WCDMA（Wideband Code Division Multiple Access）。 |
| TEL_RADIO_TECHNOLOGY_HSPA     | 无线接入技术HSPA（High Speed Packet Access）。               |
| TEL_RADIO_TECHNOLOGY_HSPAP    | 无线接入技术HSPAP（High Speed packet access (HSPA+) ）。     |
| TEL_RADIO_TECHNOLOGY_TD_SCDMA | 无线接入技术TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。 |
| TEL_RADIO_TECHNOLOGY_EVDO     | 无线接入技术EVDO（Evolution Data Only）。                    |
| TEL_RADIO_TECHNOLOGY_EHRPD    | 无线接入技术EHRPD（Evolved High Rate Package Data）。        |
| TEL_RADIO_TECHNOLOGY_LTE      | 无线接入技术LTE（Long Term Evolution）。                     |
| TEL_RADIO_TECHNOLOGY_LTE_CA   | 无线接入技术LTE_CA（Long Term Evolution_Carrier Aggregation）。 |
| TEL_RADIO_TECHNOLOGY_IWLAN    | 无线接入技术IWLAN（Industrial Wireless LAN）。               |
| TEL_RADIO_TECHNOLOGY_NR       | 无线接入技术NR（New Radio）。                                |

### Telephony_NsaState

```
enum Telephony_NsaState
```

**描述**

设备的NSA网络注册状态类型。

**起始版本：** 13

| 枚举值                           | 描述                                                       |
| -------------------------------- | ---------------------------------------------------------- |
| TEL_NSA_STATE_NOT_SUPPORTED      | 设备在不支持NSA的LTE小区下处于空闲状态或连接状态。         |
| TEL_NSA_STATE_NO_DETECTED        | 在支持NSA但不支持NR覆盖检测的LTE小区下，设备处于空闲状态。 |
| TEL_NSA_STATE_CONNECTED_DETECTED | 设备在LTE小区下连接到LTE网络支持NSA和NR覆盖检测。          |
| TEL_NSA_STATE_IDLE_DETECTED      | 支持NSA和NR覆盖检测的LTE小区下设备处于空闲状态。           |
| TEL_NSA_STATE_DUAL_CONNECTED     | 设备在支持NSA的LTE小区下连接到LTE + NR网络。               |
| TEL_NSA_STATE_SA_ATTACHED        | 设备在5GC附着时在NG-RAN小区下空闲或连接到NG-RAN小区。      |

## 函数说明


### OH_Telephony_GetNetworkState()

```
Telephony_RadioResult OH_Telephony_GetNetworkState(Telephony_NetworkState * state)
```

**描述**

获取网络状态。

**系统能力：** SystemCapability.Telephony.CoreService

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| state | 用户接收网络状态信息的结构体。 |

**返回：**

0 - 成功.

201 - 权限错误.

401 - 参数错误.

8300001 -   编组错误.

8300002 -  连接电话服务错误.

8300003 -  操作电话服务错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO

### OH_Telephony_GetNetworkStateForSlot()

```
Telephony_RadioResult OH_Telephony_GetNetworkStateForSlot(int32_t slotId, Telephony_NetworkState *state)
```

**描述**

获取给定卡槽ID的网络状态。

**系统能力：** SystemCapability.Telephony.CoreService

**起始版本：** 13

**参数:**

| 名称   | 描述                           |
| ------ | ------------------------------ |
| slotId | 卡槽ID。                         |
| state  | 用户接收网络状态信息的结构体。 |

**返回：**

0 - 成功.

201 - 权限错误.

401 - 参数错误.

8300001 -   编组错误.

8300002 -  连接电话服务错误.

8300003 -  操作电话服务错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO