# AGnssTypes.idl


## 概述

定义AGNSS模块接口中使用到的数据结构。

模块包路径：ohos.hdi.location.agnss.v1_0

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AGnssRefCellId](_a_gnss_ref_cell_id.md) | 定义AGNSS参考信息中CellId的结构体。 | 
| struct&nbsp;&nbsp;[AGnssServerInfo](_a_gnss_server_info.md) | 定义AGNSS服务器信息结构体。 | 
| struct&nbsp;&nbsp;[SubscriberSetId](_subscriber_set_id.md) | 定义setId结构体。 | 
| struct&nbsp;&nbsp;[AGnssRefMac](_a_gnss_ref_mac.md) | 定义AGNSS参考信息中MAC的结构体。 | 
| struct&nbsp;&nbsp;[AGnssRefInfo](_a_gnss_ref_info.md) | 定义AGNSS参考信息结构体。 | 
| struct&nbsp;&nbsp;[AGnssDataLinkRequest](_a_gnss_data_link_request.md) | 定义操作数据业务连接请求的结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AGnssRefInfoType](_hdi_a_gnss.md#agnssrefinfotype) { ANSS_REF_INFO_TYPE_CELLID = 1 , ANSS_REF_INFO_TYPE_MAC = 2 } | 定义AGNSS参考信息类型。 | 
| [AGnssUserPlaneProtocol](_hdi_a_gnss.md#agnssuserplaneprotocol) { AGNSS_TYPE_SUPL = 1 , AGNSS_TYPE_C2K = 2 , AGNSS_TYPE_SUPL_IMS = 3 , AGNSS_TYPE_SUPL_EIMS = 4 } | 定义AGNSS用户面的协议类型。 | 
| [DataLinkSetUpType](_hdi_a_gnss.md#datalinksetuptype) { ESTABLISH_DATA_CONNECTION = 1 , RELEASE_DATA_CONNECTION = 2 } | 定义数据链路的操作类型。 | 
| [CellIdType](_hdi_a_gnss.md#cellidtype) { CELLID_TYPE_GSM = 1 , CELLID_TYPE_UMTS = 2 , CELLID_TYPE_LTE = 3 , CELLID_TYPE_NR = 4 } | 定义CellId类型。 | 
| [SubscriberSetIdType](_hdi_a_gnss.md#subscribersetidtype) { SETID_TYPE_NONE = 0 , SETID_TYPE_IMSI = 1 , SETID_TYPE_MSISDM = 2 } | 定义setId类型。 | 
