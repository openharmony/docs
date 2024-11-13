# HdiAGnss


## 概述

定义AGNSS模块的接口。

上层可以使用该模块提供的接口设置AGNSS回调、AGNSS服务器地址、AGNSS参考信息、setId等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [AGnssTypes.idl](_a_gnss_types_8idl.md) | 定义AGNSS模块接口中使用到的数据结构。 | 
| [IAGnssCallback.idl](_i_a_gnss_callback_8idl.md) | 定义AGNSS回调，用于请求上层建立或释放数据业务连接、请求上层下发setId、请求上层下发AGNSS参考信息。 | 
| [IAGnssInterface.idl](_i_a_gnss_interface_8idl.md) | 定义AGNSS接口，用于设置AGNSS回调、AGNSS服务器地址、AGNSS参考信息和setId。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AGnssRefCellId](_a_gnss_ref_cell_id.md) | 定义AGNSS参考信息中cellId的结构体。 | 
| struct&nbsp;&nbsp;[AGnssServerInfo](_a_gnss_server_info.md) | 定义AGNSS服务器信息结构体。 | 
| struct&nbsp;&nbsp;[SubscriberSetId](_subscriber_set_id.md) | 定义setId结构体。 | 
| struct&nbsp;&nbsp;[AGnssRefMac](_a_gnss_ref_mac.md) | 定义AGNSS参考信息中MAC的结构体。 | 
| struct&nbsp;&nbsp;[AGnssRefInfo](_a_gnss_ref_info.md) | 定义AGNSS参考信息结构体。 | 
| struct&nbsp;&nbsp;[AGnssDataLinkRequest](_a_gnss_data_link_request.md) | 定义操作数据业务连接请求的结构体。 | 
| interface&nbsp;&nbsp;[IAGnssCallback](interface_i_a_gnss_callback.md) | 定义AGNSS回调，用于请求上层建立或释放数据业务连接、请求上层下发setId、请求上层下发AGNSS参考信息。 | 
| interface&nbsp;&nbsp;[IAGnssInterface](interface_i_a_gnss_interface.md) | 定义AGNSS接口，用于设置AGNSS回调、AGNSS服务器地址、AGNSS参考信息和setId。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AGnssRefInfoType](#agnssrefinfotype) { ANSS_REF_INFO_TYPE_CELLID = 1 , ANSS_REF_INFO_TYPE_MAC = 2 } | 定义AGNSS参考信息类型。 | 
| [AGnssUserPlaneProtocol](#agnssuserplaneprotocol) { AGNSS_TYPE_SUPL = 1 , AGNSS_TYPE_C2K = 2 , AGNSS_TYPE_SUPL_IMS = 3 , AGNSS_TYPE_SUPL_EIMS = 4 } | 定义AGNSS用户面的协议类型。 | 
| [DataLinkSetUpType](#datalinksetuptype) { ESTABLISH_DATA_CONNECTION = 1 , RELEASE_DATA_CONNECTION = 2 } | 定义数据链路的操作类型。 | 
| [CellIdType](#cellidtype) { CELLID_TYPE_GSM = 1 , CELLID_TYPE_UMTS = 2 , CELLID_TYPE_LTE = 3 , CELLID_TYPE_NR = 4 } | 定义cell id类型。 | 
| [SubscriberSetIdType](#subscribersetidtype) { SETID_TYPE_NONE = 0 , SETID_TYPE_IMSI = 1 , SETID_TYPE_MSISDM = 2 } | 定义setid类型。 | 


## 枚举类型说明


### AGnssRefInfoType

```
enum AGnssRefInfoType
```

**描述**


定义AGNSS参考信息类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ANSS_REF_INFO_TYPE_CELLID | 小区ID | 
| ANSS_REF_INFO_TYPE_MAC | MAC地址 | 


### AGnssUserPlaneProtocol

```
enum AGnssUserPlaneProtocol
```

**描述**


定义AGNSS用户面的协议类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| AGNSS_TYPE_SUPL | SUPL类型 | 
| AGNSS_TYPE_C2K | C2K类型 | 
| AGNSS_TYPE_SUPL_IMS | IMS类型 | 
| AGNSS_TYPE_SUPL_EIMS | EIMS类型 | 


### CellIdType

```
enum CellIdType
```

**描述**


定义cell id类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CELLID_TYPE_GSM | GSM小区 | 
| CELLID_TYPE_UMTS | UMTS小区 | 
| CELLID_TYPE_LTE | LTE小区 | 
| CELLID_TYPE_NR | NR小区 | 


### DataLinkSetUpType

```
enum DataLinkSetUpType
```

**描述**


定义数据链路的操作类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ESTABLISH_DATA_CONNECTION | 请求建立数据业务连接。 | 
| RELEASE_DATA_CONNECTION | 请求释放数据业务连接。 | 


### SubscriberSetIdType

```
enum SubscriberSetIdType
```

**描述**


定义setid类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SETID_TYPE_NONE | 未知类型 | 
| SETID_TYPE_IMSI | IMSI类型 | 
| SETID_TYPE_MSISDM | MSISDM类型 | 
