# Ril (V1_0)


## 概述

Ril模块接口定义。

Ril模块为上层电话服务提供相关调用接口，涉及电话、短信、彩信、网络搜索、SIM卡等功能接口及各种回调等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IRil.idl](_i_ril_8idl_v10.md) | Ril模块的请求接口。 | 
| [IRilCallback.idl](_i_ril_callback_8idl_v10.md) | Ril模块的回调接口 | 
| [Types.idl](ril_types_8idl_v10.md) | Ril模块HDI接口使用的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IRil](interface_i_ril_v10.md) | Ril模块的请求接口。 | 
| interface&nbsp;&nbsp;[IRilCallback](interface_i_ril_callback_v10.md) | Ril模块的回调接口。 | 
| struct&nbsp;&nbsp;[EmergencyCall](_emergency_call_v10.md) | 紧急呼叫号码。 | 
| struct&nbsp;&nbsp;[EmergencyInfoList](_emergency_info_list_v10.md) | 紧急呼叫号码列表。 | 
| struct&nbsp;&nbsp;[RilRadioResponseInfo](_ril_radio_response_info_v10.md) | 响应通用信息。 | 
| struct&nbsp;&nbsp;[SetupDataCallResultInfo](_setup_data_call_result_info_v10.md) | 数据业务激活结果信息。 | 
| struct&nbsp;&nbsp;[DataCallResultList](_data_call_result_list_v10.md) | 数据业务激活结果列表。 | 
| struct&nbsp;&nbsp;[DataProfileDataInfo](_data_profile_data_info_v10.md) | PDP上下文信息。 | 
| struct&nbsp;&nbsp;[DataProfilesInfo](_data_profiles_info_v10.md) | PDP上下文信息列表。 | 
| struct&nbsp;&nbsp;[DataCallInfo](_data_call_info_v10.md) | 数据业务信息。 | 
| struct&nbsp;&nbsp;[DataLinkBandwidthInfo](_data_link_bandwidth_info_v10.md) | 网络频率信息。 | 
| struct&nbsp;&nbsp;[DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule_v10.md) | 网络频率上报规则。 | 
| struct&nbsp;&nbsp;[DataPerformanceInfo](_data_performance_info_v10.md) | 数据业务性能模式。 | 
| struct&nbsp;&nbsp;[DataSleepInfo](_data_sleep_info_v10.md) | 数据业务睡眠模式。 | 
| struct&nbsp;&nbsp;[UniInfo](_uni_info_v10.md) | 通用信息。 | 
| struct&nbsp;&nbsp;[VoiceRadioTechnology](_voice_radio_technology_v10.md) | 电路域接入技术。 | 
| struct&nbsp;&nbsp;[DialInfo](_dial_info_v10.md) | 拨号信息。 | 
| struct&nbsp;&nbsp;[CallInfo](_call_info_v10.md) | 通话状态信息。 | 
| struct&nbsp;&nbsp;[CallInfoList](_call_info_list_v10.md) | 通话状态信息列表。 | 
| struct&nbsp;&nbsp;[GetClipResult](_get_clip_result_v10.md) | 主叫号码显示结果信息。 | 
| struct&nbsp;&nbsp;[GetClirResult](_get_clir_result_v10.md) | 主叫号码显示限制结果信息。 | 
| struct&nbsp;&nbsp;[CallWaitResult](_call_wait_result_v10.md) | 呼叫等待结果信息。 | 
| struct&nbsp;&nbsp;[CallRestrictionInfo](_call_restriction_info_v10.md) | 呼叫限制信息。 | 
| struct&nbsp;&nbsp;[CallRestrictionResult](_call_restriction_result_v10.md) | 呼叫限制结果信息。 | 
| struct&nbsp;&nbsp;[CallForwardSetInfo](_call_forward_set_info_v10.md) | 呼叫转移信息。 | 
| struct&nbsp;&nbsp;[CallForwardQueryResult](_call_forward_query_result_v10.md) | 呼叫转移查询结果信息。 | 
| struct&nbsp;&nbsp;[CallForwardQueryInfoList](_call_forward_query_info_list_v10.md) | 呼叫转移信息列表。 | 
| struct&nbsp;&nbsp;[UssdNoticeInfo](_ussd_notice_info_v10.md) | 非结构化补充数据业务(USSD)业务信息。 | 
| struct&nbsp;&nbsp;[SsNoticeInfo](_ss_notice_info_v10.md) | 补充业务信息。 | 
| struct&nbsp;&nbsp;[SrvccStatus](_srvcc_status_v10.md) | SRVCC（Single Radio Voice Call Continuity）状态信息。 | 
| struct&nbsp;&nbsp;[RingbackVoice](_ringback_voice_v10.md) | 回铃音信息。 | 
| struct&nbsp;&nbsp;[DtmfInfo](_dtmf_info_v10.md) | 发送双音多频(DTMF)信息。 | 
| struct&nbsp;&nbsp;[SetBarringInfo](_set_barring_info_v10.md) | 设置呼叫限制密码的信息。 | 
| struct&nbsp;&nbsp;[CardStatusInfo](_card_status_info_v10.md) | SIM卡状态信息。 | 
| struct&nbsp;&nbsp;[SimIoRequestInfo](_sim_io_request_info_v10.md) | SIM数据请求信息。 | 
| struct&nbsp;&nbsp;[IccIoResultInfo](_icc_io_result_info_v10.md) | SIM数据的响应结果信息。 | 
| struct&nbsp;&nbsp;[SimLockInfo](_sim_lock_info_v10.md) | SIM卡锁信息。 | 
| struct&nbsp;&nbsp;[SimPasswordInfo](_sim_password_info_v10.md) | SIM卡密码信息。 | 
| struct&nbsp;&nbsp;[SimPinInputTimes](_sim_pin_input_times_v10.md) | SIM密码输入次数信息。 | 
| struct&nbsp;&nbsp;[ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v10.md) | APDU数据传输请求信息。 | 
| struct&nbsp;&nbsp;[SimAuthenticationRequestInfo](_sim_authentication_request_info_v10.md) | SIM卡鉴权请求信息。 | 
| struct&nbsp;&nbsp;[OpenLogicalChannelResponse](_open_logical_channel_response_v10.md) | APDU打开逻辑通道响应信息。 | 
| struct&nbsp;&nbsp;[LockStatusResp](_lock_status_resp_v10.md) | SIM卡解锁响应 | 
| struct&nbsp;&nbsp;[RadioProtocol](_radio_protocol_v10.md) | 主副卡协议栈信息。 | 
| struct&nbsp;&nbsp;[GsmRssi](_gsm_rssi_v10.md) | GSM信号强度。 | 
| struct&nbsp;&nbsp;[CdmaRssi](_cdma_rssi_v10.md) | CDMA信号强度。 | 
| struct&nbsp;&nbsp;[WcdmaRssi](_wcdma_rssi_v10.md) | WCDMA信号强度。 | 
| struct&nbsp;&nbsp;[LteRssi](_lte_rssi_v10.md) | LTE信号强度。 | 
| struct&nbsp;&nbsp;[TdScdmaRssi](_td_scdma_rssi_v10.md) | TDSCDMA信号强度。 | 
| struct&nbsp;&nbsp;[NrRssi](_nr_rssi_v10.md) | NR信号强度。 | 
| struct&nbsp;&nbsp;[Rssi](_rssi_v10.md) | 接收信号强度信息。 | 
| struct&nbsp;&nbsp;[CsRegStatusInfo](_cs_reg_status_info_v10.md) | CS注册状态信息。 | 
| struct&nbsp;&nbsp;[PsRegStatusInfo](_ps_reg_status_info_v10.md) | PS注册状态信息。 | 
| struct&nbsp;&nbsp;[OperatorInfo](_operator_info_v10.md) | 运营商信息。 | 
| struct&nbsp;&nbsp;[AvailableNetworkInfo](_available_network_info_v10.md) | 可用网络信息。 | 
| struct&nbsp;&nbsp;[AvailableNetworkList](_available_network_list_v10.md) | 可用网络列表。 | 
| struct&nbsp;&nbsp;[SetNetworkModeInfo](_set_network_mode_info_v10.md) | 设置网络模式信息。 | 
| struct&nbsp;&nbsp;[CellListRatGsm](_cell_list_rat_gsm_v10.md) | GSM小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatLte](_cell_list_rat_lte_v10.md) | LTE小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatWcdma](_cell_list_rat_wcdma_v10.md) | WCDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatCdma](_cell_list_rat_cdma_v10.md) | CDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatTdscdma](_cell_list_rat_tdscdma_v10.md) | TDSCDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatNr](_cell_list_rat_nr_v10.md) | NR小区信息。 | 
| union&nbsp;&nbsp;[ServiceCellParas](union_service_cell_paras_v10.md) | 多种网络模式的小区信息。 | 
| struct&nbsp;&nbsp;[CellNearbyInfo](_cell_nearby_info_v10.md) | 相邻小区信息。 | 
| struct&nbsp;&nbsp;[CellListNearbyInfo](_cell_list_nearby_info_v10.md) | 附近小区信息列表。 | 
| struct&nbsp;&nbsp;[CellRatGsm](_cell_rat_gsm_v10.md) | GSM蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatLte](_cell_rat_lte_v10.md) | LTE蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatWcdma](_cell_rat_wcdma_v10.md) | WCDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatCdma](_cell_rat_cdma_v10.md) | CDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatTdscdma](_cell_rat_tdscdma_v10.md) | TDSCDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatNr](_cell_rat_nr_v10.md) | NR蜂窝信息。 | 
| union&nbsp;&nbsp;[CurrentServiceCellParas](union_current_service_cell_paras_v10.md) | 当前蜂窝数据信息。 | 
| struct&nbsp;&nbsp;[CurrentCellInfo](_current_cell_info_v10.md) | 当前小区信息。 | 
| struct&nbsp;&nbsp;[CellListCurrentInfo](_cell_list_current_info_v10.md) | 当前小区信息列表。 | 
| struct&nbsp;&nbsp;[PreferredNetworkTypeInfo](_preferred_network_type_info_v10.md) | 首选网络类型信息。 | 
| struct&nbsp;&nbsp;[PhysicalChannelConfig](_physical_channel_config_v10.md) | 物理通道配置。 | 
| struct&nbsp;&nbsp;[ChannelConfigInfoList](_channel_config_info_list_v10.md) | 通道配置信息列表。 | 
| struct&nbsp;&nbsp;[GsmSmsMessageInfo](_gsm_sms_message_info_v10.md) | 发送GSM短信信息。 | 
| struct&nbsp;&nbsp;[SendCdmaSmsMessageInfo](_send_cdma_sms_message_info_v10.md) | 发送CDMA短信信息。 | 
| struct&nbsp;&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info_v10.md) | SIM卡短信信息 | 
| struct&nbsp;&nbsp;[ServiceCenterAddress](_service_center_address_v10.md) | 短信中心地址信息。 | 
| struct&nbsp;&nbsp;[CBConfigInfo](_c_b_config_info_v10.md) | GSM小区广播配置信息。 | 
| struct&nbsp;&nbsp;[CdmaCBConfigInfo](_cdma_c_b_config_info_v10.md) | CDMA小区广播配置信息。 | 
| struct&nbsp;&nbsp;[CdmaCBConfigInfoList](_cdma_c_b_config_info_list_v10.md) | CDMA小区广播配置信息列表。 | 
| struct&nbsp;&nbsp;[CBConfigReportInfo](_c_b_config_report_info_v10.md) | 小区广播上报信息。 | 
| struct&nbsp;&nbsp;[SmsMessageInfo](_sms_message_info_v10.md) | 上报短信信息。 | 
| struct&nbsp;&nbsp;[ModeData](_mode_data_v10.md) | 接收短信处理模式。 | 
| struct&nbsp;&nbsp;[SendSmsResultInfo](_send_sms_result_info_v10.md) | 发送短信响应信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EccType](#ecctype) {<br/>TYPE_CATEGORY = 0 , TYPE_POLICE = 1 , TYPE_AMBULANCE = 2 , TYPE_FIRE = 4 ,TYPE_SEA = 8 , TYPE_MOUNTAIN = 16<br/>} | 紧急呼叫类型。 | 
| [SimpresentType](#simpresenttype) { TYPE_NO_CARD = 0 , TYPE_HAS_CARD = 1 } | 表示号码是有卡时有效还是无卡时有效。 | 
| [AbnormalServiceType](#abnormalservicetype) { TYPE_ALL = 0 , TYPE_ONLY_CS = 1 } | 表示号码有效性是否区分电路(CS)域非正常服务状态。 | 
| [RilErrType](#rilerrtype) {<br/>NONE = 0 , RIL_ERR_GENERIC_FAILURE = 1 , RIL_ERR_INVALID_PARAMETER = 2 , RIL_ERR_MEMORY_FULL = 3 , RIL_ERR_CMD_SEND_FAILURE = 4 , RIL_ERR_CMD_NO_CARRIER = 5 , RIL_ERR_INVALID_RESPONSE = 6 , RIL_ERR_REPEAT_STATUS = 7 , RIL_ERR_NETWORK_SEARCHING = 8 , RIL_ERR_NETWORK_SEARCHING_INTERRUPTED = 9 , RIL_ERR_MODEM_DEVICE_CLOSE = 10 , RIL_ERR_NO_SIMCARD_INSERTED = 11 , RIL_ERR_NEED_PIN_CODE = 12 , RIL_ERR_NEED_PUK_CODE = 13 , RIL_ERR_NETWORK_SEARCH_TIMEOUT = 14 , RIL_ERR_PINPUK_PASSWORD_NOCORRECT = 15 , RIL_ERR_INVALID_MODEM_PARAMETER = 50 , RIL_ERR_HDF_IPC_FAILURE = 300 , RIL_ERR_NULL_POINT = 301 , RIL_ERR_VENDOR_NOT_IMPLEMENT = 302<br/>} | Ril错误码。 | 
| [RilResponseTypes](#rilresponsetypes) {<br/>RIL_RESPONSE_REQUEST = 0 , RIL_RESPONSE_NOTICE = 1 , RIL_RESPONSE_REQUEST_ACK = 2 , RIL_RESPONSE_REQUEST_MUST_ACK = 3 , RIL_RESPONSE_NOTICE_MUST_ACK = 4<br/>} | 响应类型。 | 
| [RilSrvStatus](#rilsrvstatus) {<br/>RIL_NO_SRV_SERVICE = 0 , RIL_RESTRICTED_SERVICE = 1 , RIL_SERVICE_VALID = 2 , RIL_REGIONAL_SERVICE = 3 , RIL_ENERGY_SAVING_SERVICE = 4<br/>} | Ril系统服务状态。 | 
| [RilSrvDomain](#rilsrvdomain) {<br/>RIL_NO_DOMAIN_SERVICE = 0 , RIL_CS_SERVICE = 1 , RIL_PS_SERVICE = 2 , RIL_CS_PS_SERVICE = 3 , RIL_CS_PS_SEARCHING = 4 , RIL_CDMA_NOT_SUPPORT = 255<br/>} | 系统服务域。 | 
| [RilRoamStatus](#rilroamstatus) { RIL_NO_ROAM = 0 , RIL_ROAMING = 1 , RIL_ROAM_UNKNOWN = 2 } | 漫游状态。 | 
| [RilSimLockStatus](#rilsimlockstatus) { RIL_SIM_CARD_UNLOCK = 0 , RIL_SIM_CARD_LOCK = 1 } | SIM卡锁定状态。 | 
| [RilSysMode](#rilsysmode) {<br/>RIL_NO_SYSMODE_SERVICE = 0 , RIL_GSM_MODE = 1 , RIL_CDMA_MODE = 2 , RIL_WCDMA_MODE = 3 , RIL_TDSCDMA_MODE = 4 , RIL_WIMAX_MODE = 5 , RIL_LTE_MODE = 6 , RIL_LTE_CA_MODE = 7 , RIL_NR_MODE = 8<br/>} | 系统制式。 | 
| [RilRadioTech](#rilradiotech) {<br/>RADIO_TECHNOLOGY_INVALID = 65535 , RADIO_TECHNOLOGY_UNKNOWN = 0 , RADIO_TECHNOLOGY_GSM = 1 , RADIO_TECHNOLOGY_1XRTT = 2 , RADIO_TECHNOLOGY_WCDMA = 3 , RADIO_TECHNOLOGY_HSPA = 4 , RADIO_TECHNOLOGY_HSPAP = 5 , RADIO_TECHNOLOGY_TD_SCDMA = 6 , RADIO_TECHNOLOGY_EVDO = 7 , RADIO_TECHNOLOGY_EHRPD = 8 , RADIO_TECHNOLOGY_LTE = 9 , RADIO_TECHNOLOGY_LTE_CA = 10 , RADIO_TECHNOLOGY_IWLAN = 11 , RADIO_TECHNOLOGY_NR = 12<br/>} | 语音接入技术类型。 | 
| [RilSimStatus](#rilsimstatus) {<br/>RIL_USIM_INVALID = 0 , RIL_USIM_VALID = 1 , RIL_USIM_CS_INVALID = 2 , RIL_USIM_PS_INVALID = 3 , RIL_USIM_CS_PS_INVALID = 4 , RIL_ROM_SIM = 240 , RIL_NO_USIM = 255<br/>} | SIM卡状态。 | 
| [RilRegStatus](#rilregstatus) {<br/>NO_REG_MT_NO_SEARCH = 0 , REG_MT_HOME = 1 , NO_REG_MT_SEARCHING = 2 , REG_MT_REJECTED = 3 , REG_MT_UNKNOWN = 4 , REG_MT_ROAMING = 5 , REG_MT_EMERGENCY = 6<br/>} | 描述网络注册状态。 | 
| [RilCellConnectionStatus](#rilcellconnectionstatus) { RIL_SERVING_CELL_UNKNOWN = 0 , RIL_SERVING_CELL_PRIMARY = 1 , RIL_SERVING_CELL_SECONDARY = 2 } | 小区连接状态。 | 
| [RilRegNotifyMode](#rilregnotifymode) { REG_NOT_NOTIFY = 0 , REG_NOTIFY_STAT_ONLY = 1 , REG_NOTIFY_STAT_LAC_CELLID = 2 } | 上报模式。 | 
| [RadioProtocolPhase](#radioprotocolphase) {<br/>RADIO_PROTOCOL_PHASE_INITIAL , RADIO_PROTOCOL_PHASE_CHECK , RADIO_PROTOCOL_PHASE_UPDATE , RADIO_PROTOCOL_PHASE_NOTIFY , RADIO_PROTOCOL_PHASE_COMPLETE<br/>} | 设置Radio协议动作参数。 | 
| [RadioProtocolStatus](#radioprotocolstatus) { RADIO_PROTOCOL_STATUS_NONE , RADIO_PROTOCOL_STATUS_SUCCESS , RADIO_PROTOCOL_STATUS_FAIL } | Radio协议状态。 | 


## 枚举类型说明


### AbnormalServiceType

```
enum AbnormalServiceType
```

**描述**


表示号码有效性是否区分电路(CS)域非正常服务状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_ALL | 所有状态均有效 | 
| TYPE_ONLY_CS | 仅在CS域非正常服务时有效 | 


### EccType

```
enum EccType
```

**描述**


紧急呼叫类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_CATEGORY | 默认 | 
| TYPE_POLICE | 匪警 | 
| TYPE_AMBULANCE | 救护 | 
| TYPE_FIRE | 火警 | 
| TYPE_SEA | 海警 | 
| TYPE_MOUNTAIN | 高山营救 | 


### RadioProtocolPhase

```
enum RadioProtocolPhase
```

**描述**


设置Radio协议动作参数。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RADIO_PROTOCOL_PHASE_INITIAL | 初始化 | 
| RADIO_PROTOCOL_PHASE_CHECK | 检查 | 
| RADIO_PROTOCOL_PHASE_UPDATE | 更新 | 
| RADIO_PROTOCOL_PHASE_NOTIFY | 上报 | 
| RADIO_PROTOCOL_PHASE_COMPLETE | 结束 | 


### RadioProtocolStatus

```
enum RadioProtocolStatus
```

**描述**


Radio协议状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RADIO_PROTOCOL_STATUS_NONE | 无状态 | 
| RADIO_PROTOCOL_STATUS_SUCCESS | 成功 | 
| RADIO_PROTOCOL_STATUS_FAIL | 失败 | 


### RilCellConnectionStatus

```
enum RilCellConnectionStatus
```

**描述**


小区连接状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_SERVING_CELL_UNKNOWN | 未知连接状态 | 
| RIL_SERVING_CELL_PRIMARY | 主要连接状态 | 
| RIL_SERVING_CELL_SECONDARY | 次要连接状态 | 


### RilErrType

```
enum RilErrType
```

**描述**


Ril错误码。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| NONE | 调用成功 | 
| RIL_ERR_GENERIC_FAILURE | 通用错误 | 
| RIL_ERR_INVALID_PARAMETER | 参数错误 | 
| RIL_ERR_MEMORY_FULL | 内存满载 | 
| RIL_ERR_CMD_SEND_FAILURE | 命令发送失败 | 
| RIL_ERR_CMD_NO_CARRIER | 命令连接终止 | 
| RIL_ERR_INVALID_RESPONSE | 非法响应 | 
| RIL_ERR_REPEAT_STATUS | 状态已存在 | 
| RIL_ERR_NETWORK_SEARCHING | 网络搜索中 | 
| RIL_ERR_NETWORK_SEARCHING_INTERRUPTED | 网络搜索中断 | 
| RIL_ERR_MODEM_DEVICE_CLOSE | Modem设备关闭 | 
| RIL_ERR_NO_SIMCARD_INSERTED | SIM卡未插入 | 
| RIL_ERR_NEED_PIN_CODE | 需要输入PIN码 | 
| RIL_ERR_NEED_PUK_CODE | 需要输入PUK码 | 
| RIL_ERR_NETWORK_SEARCH_TIMEOUT | 搜网超时 | 
| RIL_ERR_PINPUK_PASSWORD_NOCORRECT | PIN码或PUK码错误 | 
| RIL_ERR_INVALID_MODEM_PARAMETER | Modem参数错误 | 
| RIL_ERR_HDF_IPC_FAILURE | IPC错误 | 
| RIL_ERR_NULL_POINT | 空指针 | 
| RIL_ERR_VENDOR_NOT_IMPLEMENT | 厂商库未实现 | 


### RilRadioTech

```
enum RilRadioTech
```

**描述**


语音接入技术类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RADIO_TECHNOLOGY_INVALID | 非法 | 
| RADIO_TECHNOLOGY_UNKNOWN | 未知 | 
| RADIO_TECHNOLOGY_GSM | GSM | 
| RADIO_TECHNOLOGY_1XRTT | 无线电传输技术(1XRTT) | 
| RADIO_TECHNOLOGY_WCDMA | WCDMA | 
| RADIO_TECHNOLOGY_HSPA | 高速分组接入(HSPA) | 
| RADIO_TECHNOLOGY_HSPAP | 高速下行分组接入(HSPAP) | 
| RADIO_TECHNOLOGY_TD_SCDMA | 同步码分多址的无线接入技术(SCDMA) | 
| RADIO_TECHNOLOGY_EVDO | 仅演进数据(EVDO) | 
| RADIO_TECHNOLOGY_EHRPD | 演进的高速分组网络(EHRPD) | 
| RADIO_TECHNOLOGY_LTE | LTE | 
| RADIO_TECHNOLOGY_LTE_CA | CA | 
| RADIO_TECHNOLOGY_IWLAN | 工业无线局域网(IWLAN) | 
| RADIO_TECHNOLOGY_NR | NR | 


### RilRegNotifyMode

```
enum RilRegNotifyMode
```

**描述**


上报模式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| REG_NOT_NOTIFY | 禁止主动上报 | 
| REG_NOTIFY_STAT_ONLY | 网络注册状态发生改变时上报 | 
| REG_NOTIFY_STAT_LAC_CELLID | 小区信息发生改变时上报 | 


### RilRegStatus

```
enum RilRegStatus
```

**描述**


描述网络注册状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| NO_REG_MT_NO_SEARCH | 没有注册，MT（Mobile Terminal）现在没有搜索和注册新的运营商 | 
| REG_MT_HOME | 注册了归属网络 | 
| NO_REG_MT_SEARCHING | 没有注册，MT正在搜索并注册新的运营商 | 
| REG_MT_REJECTED | 注册被拒绝 | 
| REG_MT_UNKNOWN | 未知状态 | 
| REG_MT_ROAMING | 注册了漫游网络 | 
| REG_MT_EMERGENCY | 处于紧急模式 | 


### RilResponseTypes

```
enum RilResponseTypes
```

**描述**


响应类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_RESPONSE_REQUEST | 请求响应 | 
| RIL_RESPONSE_NOTICE | 通知响应 | 
| RIL_RESPONSE_REQUEST_ACK | 应答请求响应 | 
| RIL_RESPONSE_REQUEST_MUST_ACK | 必须应答请求响应 | 
| RIL_RESPONSE_NOTICE_MUST_ACK | 必须应答通知响应 | 


### RilRoamStatus

```
enum RilRoamStatus
```

**描述**


漫游状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_NO_ROAM | 非漫游状态 | 
| RIL_ROAMING | 漫游状态 | 
| RIL_ROAM_UNKNOWN | 未知 | 


### RilSimLockStatus

```
enum RilSimLockStatus
```

**描述**


SIM卡锁定状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_SIM_CARD_UNLOCK | 未被CardLock功能锁定 | 
| RIL_SIM_CARD_LOCK | 被CardLock功能锁定 | 


### RilSimStatus

```
enum RilSimStatus
```

**描述**


SIM卡状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_USIM_INVALID | USIM卡状态无效 | 
| RIL_USIM_VALID | USIM卡状态有效 | 
| RIL_USIM_CS_INVALID | USIM卡在CS下无效 | 
| RIL_USIM_PS_INVALID | USIM卡在PS下无效 | 
| RIL_USIM_CS_PS_INVALID | USIM卡在CS+PS下均无效 | 
| RIL_ROM_SIM | 仿真SIM卡 | 
| RIL_NO_USIM | USIM卡不存在 | 


### RilSrvDomain

```
enum RilSrvDomain
```

**描述**


系统服务域。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_NO_DOMAIN_SERVICE | 无服务 | 
| RIL_CS_SERVICE | 仅CS服务 | 
| RIL_PS_SERVICE | 仅分组(PS)服务 | 
| RIL_CS_PS_SERVICE | CS+PS服务 | 
| RIL_CS_PS_SEARCHING | CS、PS均未注册 | 
| RIL_CDMA_NOT_SUPPORT | CDMA不支持 | 


### RilSrvStatus

```
enum RilSrvStatus
```

**描述**


Ril系统服务状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_NO_SRV_SERVICE | 无服务 | 
| RIL_RESTRICTED_SERVICE | 有限制服务 | 
| RIL_SERVICE_VALID | 服务有效 | 
| RIL_REGIONAL_SERVICE | 有限制的区域服务 | 
| RIL_ENERGY_SAVING_SERVICE | 省电和睡眠状态 | 


### RilSysMode

```
enum RilSysMode
```

**描述**


系统制式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| RIL_NO_SYSMODE_SERVICE | 服务不存在 | 
| RIL_GSM_MODE | 全球移动通信系统 (GSM) | 
| RIL_CDMA_MODE | 码分多址(CDMA) | 
| RIL_WCDMA_MODE | 宽带码分多址(WCDMA) | 
| RIL_TDSCDMA_MODE | 时分同步码分多址(TDSCDMA) | 
| RIL_WIMAX_MODE | 全球微波接入互操作性(WIMAX) | 
| RIL_LTE_MODE | 长期演进(LTE) | 
| RIL_LTE_CA_MODE | 载波聚合(CA) | 
| RIL_NR_MODE | 5G新空口(NR) | 


### SimpresentType

```
enum SimpresentType
```

**描述**


表示号码是有卡时有效还是无卡时有效。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| TYPE_NO_CARD | 无卡时有效 | 
| TYPE_HAS_CARD | 有卡时有效 | 
