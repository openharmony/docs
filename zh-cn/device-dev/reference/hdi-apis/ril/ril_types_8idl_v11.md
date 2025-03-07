# Types.idl


## 概述

Ril模块HDI接口使用的数据类型。

模块包路径：ohos.hdi.ril.v1_1

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[EmergencyCall](_emergency_call_v11.md) | 紧急呼叫号码。 | 
| struct&nbsp;&nbsp;[EmergencyInfoList](_emergency_info_list_v11.md) | 紧急呼叫号码列表。 | 
| struct&nbsp;&nbsp;[RilRadioResponseInfo](_ril_radio_response_info_v11.md) | 响应通用信息。 | 
| struct&nbsp;&nbsp;[SetupDataCallResultInfo](_setup_data_call_result_info_v11.md) | 数据业务激活结果信息。 | 
| struct&nbsp;&nbsp;[DataCallResultList](_data_call_result_list_v11.md) | 数据业务激活结果列表。 | 
| struct&nbsp;&nbsp;[DataLinkCapability](_data_link_capability_v11.md) | 定义数据链路功能。 | 
| struct&nbsp;&nbsp;[DataProfileDataInfo](_data_profile_data_info_v11.md) | PDP上下文信息。 | 
| struct&nbsp;&nbsp;[DataProfilesInfo](_data_profiles_info_v11.md) | PDP上下文信息列表。 | 
| struct&nbsp;&nbsp;[DataCallInfo](_data_call_info_v11.md) | 数据业务信息。 | 
| struct&nbsp;&nbsp;[DataLinkBandwidthInfo](_data_link_bandwidth_info_v11.md) | 网络频率信息。 | 
| struct&nbsp;&nbsp;[DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule_v11.md) | 网络频率上报规则。 | 
| struct&nbsp;&nbsp;[DataPerformanceInfo](_data_performance_info_v11.md) | 数据业务性能模式。 | 
| struct&nbsp;&nbsp;[DataSleepInfo](_data_sleep_info_v11.md) | 数据业务睡眠模式。 | 
| struct&nbsp;&nbsp;[UniInfo](_uni_info_v11.md) | 通用信息。 | 
| struct&nbsp;&nbsp;[VoiceRadioTechnology](_voice_radio_technology_v11.md) | 电路域接入技术。 | 
| struct&nbsp;&nbsp;[DialInfo](_dial_info_v11.md) | 拨号信息。 | 
| struct&nbsp;&nbsp;[CallInfo](_call_info_v11.md) | 通话状态信息。 | 
| struct&nbsp;&nbsp;[CallInfoList](_call_info_list_v11.md) | 通话状态信息列表。 | 
| struct&nbsp;&nbsp;[GetClipResult](_get_clip_result_v11.md) | 主叫号码显示结果信息。 | 
| struct&nbsp;&nbsp;[GetClirResult](_get_clir_result_v11.md) | 主叫号码显示限制结果信息。 | 
| struct&nbsp;&nbsp;[CallWaitResult](_call_wait_result_v11.md) | 呼叫等待结果信息。 | 
| struct&nbsp;&nbsp;[CallRestrictionInfo](_call_restriction_info_v11.md) | 呼叫限制信息。 | 
| struct&nbsp;&nbsp;[CallRestrictionResult](_call_restriction_result_v11.md) | 呼叫限制结果信息。 | 
| struct&nbsp;&nbsp;[CallForwardSetInfo](_call_forward_set_info_v11.md) | 呼叫转移信息。 | 
| struct&nbsp;&nbsp;[CallForwardQueryResult](_call_forward_query_result_v11.md) | 呼叫转移查询结果信息。 | 
| struct&nbsp;&nbsp;[CallForwardQueryInfoList](_call_forward_query_info_list_v11.md) | 呼叫转移信息列表。 | 
| struct&nbsp;&nbsp;[UssdNoticeInfo](_ussd_notice_info_v11.md) | 非结构化补充数据业务(USSD)业务信息。 | 
| struct&nbsp;&nbsp;[SsNoticeInfo](_ss_notice_info_v11.md) | 补充业务信息。 | 
| struct&nbsp;&nbsp;[SrvccStatus](_srvcc_status_v11.md) | SRVCC（Single Radio Voice Call Continuity）状态信息。 | 
| struct&nbsp;&nbsp;[RingbackVoice](_ringback_voice_v11.md) | 回铃音信息。 | 
| struct&nbsp;&nbsp;[DtmfInfo](_dtmf_info_v11.md) | 发送双音多频(DTMF)信息。 | 
| struct&nbsp;&nbsp;[SetBarringInfo](_set_barring_info_v11.md) | 设置呼叫限制密码的信息。 | 
| struct&nbsp;&nbsp;[CardStatusInfo](_card_status_info_v11.md) | SIM卡状态信息。 | 
| struct&nbsp;&nbsp;[SimIoRequestInfo](_sim_io_request_info_v11.md) | SIM数据请求信息。 | 
| struct&nbsp;&nbsp;[IccIoResultInfo](_icc_io_result_info_v11.md) | SIM数据的响应结果信息。 | 
| struct&nbsp;&nbsp;[SimLockInfo](_sim_lock_info_v11.md) | SIM卡锁信息。 | 
| struct&nbsp;&nbsp;[SimPasswordInfo](_sim_password_info_v11.md) | SIM卡密码信息。 | 
| struct&nbsp;&nbsp;[SimPinInputTimes](_sim_pin_input_times_v11.md) | SIM密码输入次数信息。 | 
| struct&nbsp;&nbsp;[ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v11.md) | APDU数据传输请求信息。 | 
| struct&nbsp;&nbsp;[SimAuthenticationRequestInfo](_sim_authentication_request_info_v11.md) | SIM卡鉴权请求信息。 | 
| struct&nbsp;&nbsp;[OpenLogicalChannelResponse](_open_logical_channel_response_v11.md) | APDU打开逻辑通道响应信息。 | 
| struct&nbsp;&nbsp;[LockStatusResp](_lock_status_resp_v11.md) | SIM卡解锁响应。 | 
| struct&nbsp;&nbsp;[RadioProtocol](_radio_protocol_v11.md) | 主副卡协议栈信息。 | 
| struct&nbsp;&nbsp;[GsmRssi](_gsm_rssi_v11.md) | GSM信号强度。 | 
| struct&nbsp;&nbsp;[CdmaRssi](_cdma_rssi_v11.md) | CDMA信号强度。 | 
| struct&nbsp;&nbsp;[WcdmaRssi](_wcdma_rssi_v11.md) | WCDMA信号强度。 | 
| struct&nbsp;&nbsp;[LteRssi](_lte_rssi_v11.md) | LTE信号强度。 | 
| struct&nbsp;&nbsp;[TdScdmaRssi](_td_scdma_rssi_v11.md) | TDSCDMA信号强度。 | 
| struct&nbsp;&nbsp;[NrRssi](_nr_rssi_v11.md) | NR信号强度。 | 
| struct&nbsp;&nbsp;[Rssi](_rssi_v11.md) | 接收信号强度信息。 | 
| struct&nbsp;&nbsp;[CsRegStatusInfo](_cs_reg_status_info_v11.md) | CS注册状态信息。 | 
| struct&nbsp;&nbsp;[PsRegStatusInfo](_ps_reg_status_info_v11.md) | PS注册状态信息。 | 
| struct&nbsp;&nbsp;[OperatorInfo](_operator_info_v11.md) | 运营商信息。 | 
| struct&nbsp;&nbsp;[AvailableNetworkInfo](_available_network_info_v11.md) | 可用网络信息。 | 
| struct&nbsp;&nbsp;[AvailableNetworkList](_available_network_list_v11.md) | 可用网络列表。 | 
| struct&nbsp;&nbsp;[SetNetworkModeInfo](_set_network_mode_info_v11.md) | 设置网络模式信息。 | 
| struct&nbsp;&nbsp;[CellListRatGsm](_cell_list_rat_gsm_v11.md) | GSM小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatLte](_cell_list_rat_lte_v11.md) | LTE小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatWcdma](_cell_list_rat_wcdma_v11.md) | WCDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatCdma](_cell_list_rat_cdma_v11.md) | CDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatTdscdma](_cell_list_rat_tdscdma_v11.md) | TDSCDMA小区信息。 | 
| struct&nbsp;&nbsp;[CellListRatNr](_cell_list_rat_nr_v11.md) | NR小区信息。 | 
| union&nbsp;&nbsp;[ServiceCellParas](union_service_cell_paras_v11.md) | 多种网络模式的小区信息。 | 
| struct&nbsp;&nbsp;[CellNearbyInfo](_cell_nearby_info_v11.md) | 相邻小区信息。 | 
| struct&nbsp;&nbsp;[CellListNearbyInfo](_cell_list_nearby_info_v11.md) | 附近小区信息列表。 | 
| struct&nbsp;&nbsp;[CellRatGsm](_cell_rat_gsm_v11.md) | GSM蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatLte](_cell_rat_lte_v11.md) | LTE蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatWcdma](_cell_rat_wcdma_v11.md) | WCDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatCdma](_cell_rat_cdma_v11.md) | CDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatTdscdma](_cell_rat_tdscdma_v11.md) | TDSCDMA蜂窝信息。 | 
| struct&nbsp;&nbsp;[CellRatNr](_cell_rat_nr_v11.md) | NR蜂窝信息。 | 
| union&nbsp;&nbsp;[CurrentServiceCellParas](union_current_service_cell_paras_v11.md) | 当前蜂窝数据信息。 | 
| struct&nbsp;&nbsp;[CellRatNr_1_1](_cell_rat_nr__1__1_v11.md) | NR蜂窝信息。 | 
| union&nbsp;&nbsp;[CurrentServiceCellParas_1_1](union_current_service_cell_paras__1__1_v11.md) | 当前蜂窝数据信息。 | 
| struct&nbsp;&nbsp;[CurrentCellInfo_1_1](_current_cell_info__1__1_v11.md) | 当前小区信息。 | 
| struct&nbsp;&nbsp;[CellListCurrentInfo_1_1](_cell_list_current_info__1__1_v11.md) | 当前小区信息列表。 | 
| struct&nbsp;&nbsp;[CurrentCellInfo](_current_cell_info_v11.md) | 当前小区信息。 | 
| struct&nbsp;&nbsp;[CellListCurrentInfo](_cell_list_current_info_v11.md) | 当前小区信息列表。 | 
| struct&nbsp;&nbsp;[PreferredNetworkTypeInfo](_preferred_network_type_info_v11.md) | 首选网络类型信息。 | 
| struct&nbsp;&nbsp;[PhysicalChannelConfig](_physical_channel_config_v11.md) | 物理通道配置。 | 
| struct&nbsp;&nbsp;[ChannelConfigInfoList](_channel_config_info_list_v11.md) | 通道配置信息列表。 | 
| struct&nbsp;&nbsp;[GsmSmsMessageInfo](_gsm_sms_message_info_v11.md) | 发送GSM短信信息。 | 
| struct&nbsp;&nbsp;[SendCdmaSmsMessageInfo](_send_cdma_sms_message_info_v11.md) | 发送CDMA短信信息。 | 
| struct&nbsp;&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info_v11.md) | SIM卡短信信息。 | 
| struct&nbsp;&nbsp;[ServiceCenterAddress](_service_center_address_v11.md) | 短信中心地址信息。 | 
| struct&nbsp;&nbsp;[CBConfigInfo](_c_b_config_info_v11.md) | GSM小区广播配置信息。 | 
| struct&nbsp;&nbsp;[CdmaCBConfigInfo](_cdma_c_b_config_info_v11.md) | CDMA小区广播配置信息。 | 
| struct&nbsp;&nbsp;[CdmaCBConfigInfoList](_cdma_c_b_config_info_list_v11.md) | CDMA小区广播配置信息列表。 | 
| struct&nbsp;&nbsp;[CBConfigReportInfo](_c_b_config_report_info_v11.md) | 小区广播上报信息。 | 
| struct&nbsp;&nbsp;[SmsMessageInfo](_sms_message_info_v11.md) | 上报短信信息。 | 
| struct&nbsp;&nbsp;[ModeData](_mode_data_v11.md) | 接收短信处理模式。 | 
| struct&nbsp;&nbsp;[SendSmsResultInfo](_send_sms_result_info_v11.md) | 发送短信响应信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EccType](_ril_v11.md#ecctype) {<br/>TYPE_CATEGORY = 0 , TYPE_POLICE = 1 , TYPE_AMBULANCE = 2 , TYPE_FIRE = 4 ,TYPE_SEA = 8 , TYPE_MOUNTAIN = 16<br/>} | 紧急呼叫类型。 | 
| [SimpresentType](_ril_v11.md#simpresenttype) { TYPE_NO_CARD = 0 , TYPE_HAS_CARD = 1 } | 表示号码是有卡时有效还是无卡时有效。 | 
| [AbnormalServiceType](_ril_v11.md#abnormalservicetype) { TYPE_ALL = 0 , TYPE_ONLY_CS = 1 } | 表示号码有效性是否区分电路(CS)域非正常服务状态。 | 
| [RilErrType](_ril_v11.md#rilerrtype) {<br/>NONE = 0 , RIL_ERR_GENERIC_FAILURE = 1 , RIL_ERR_INVALID_PARAMETER = 2 , RIL_ERR_MEMORY_FULL = 3 ,<br/>RIL_ERR_CMD_SEND_FAILURE = 4 , RIL_ERR_CMD_NO_CARRIER = 5 , RIL_ERR_INVALID_RESPONSE = 6 , RIL_ERR_REPEAT_STATUS = 7 ,<br/>RIL_ERR_NETWORK_SEARCHING = 8 , RIL_ERR_NETWORK_SEARCHING_INTERRUPTED = 9 , RIL_ERR_MODEM_DEVICE_CLOSE = 10 , RIL_ERR_NO_SIMCARD_INSERTED = 11 , RIL_ERR_NEED_PIN_CODE = 12 , RIL_ERR_NEED_PUK_CODE = 13 , RIL_ERR_NETWORK_SEARCH_TIMEOUT = 14 , RIL_ERR_PINPUK_PASSWORD_NOCORRECT = 15 ,<br/>RIL_ERR_INVALID_MODEM_PARAMETER = 50 , RIL_ERR_HDF_IPC_FAILURE = 300 , RIL_ERR_NULL_POINT = 301 , RIL_ERR_VENDOR_NOT_IMPLEMENT = 302<br/>} | Ril错误码。 | 
| [RilResponseTypes](_ril_v11.md#rilresponsetypes) {<br/>RIL_RESPONSE_REQUEST = 0 , RIL_RESPONSE_NOTICE = 1 , RIL_RESPONSE_REQUEST_ACK = 2 , RIL_RESPONSE_REQUEST_MUST_ACK = 3 , RIL_RESPONSE_NOTICE_MUST_ACK = 4<br/>} | 响应类型。 | 
| [RilSrvStatus](_ril_v11.md#rilsrvstatus) {<br/>RIL_NO_SRV_SERVICE = 0 , RIL_RESTRICTED_SERVICE = 1 , RIL_SERVICE_VALID = 2 , RIL_REGIONAL_SERVICE = 3 , RIL_ENERGY_SAVING_SERVICE = 4<br/>} | Ril系统服务状态。 | 
| [RilSrvDomain](_ril_v11.md#rilsrvdomain) {<br/>RIL_NO_DOMAIN_SERVICE = 0 , RIL_CS_SERVICE = 1 , RIL_PS_SERVICE = 2 , RIL_CS_PS_SERVICE = 3 , RIL_CS_PS_SEARCHING = 4 , RIL_CDMA_NOT_SUPPORT = 255<br/>} | 系统服务域。 | 
| [RilRoamStatus](_ril_v11.md#rilroamstatus) { RIL_NO_ROAM = 0 , RIL_ROAMING = 1 , RIL_ROAM_UNKNOWN = 2 } | 漫游状态。 | 
| [RilSimLockStatus](_ril_v11.md#rilsimlockstatus) { RIL_SIM_CARD_UNLOCK = 0 , RIL_SIM_CARD_LOCK = 1 } | SIM卡锁定状态。 | 
| [RilSysMode](_ril_v11.md#rilsysmode) {<br/>RIL_NO_SYSMODE_SERVICE = 0 , RIL_GSM_MODE = 1 , RIL_CDMA_MODE = 2 , RIL_WCDMA_MODE = 3 , RIL_TDSCDMA_MODE = 4 , RIL_WIMAX_MODE = 5 , RIL_LTE_MODE = 6 , RIL_LTE_CA_MODE = 7 , RIL_NR_MODE = 8<br/>} | 系统制式。 | 
| [RilRadioTech](_ril_v11.md#rilradiotech) {<br/>RADIO_TECHNOLOGY_INVALID = 65535 , RADIO_TECHNOLOGY_UNKNOWN = 0 , RADIO_TECHNOLOGY_GSM = 1 , RADIO_TECHNOLOGY_1XRTT = 2 , RADIO_TECHNOLOGY_WCDMA = 3 , RADIO_TECHNOLOGY_HSPA = 4 , RADIO_TECHNOLOGY_HSPAP = 5 , RADIO_TECHNOLOGY_TD_SCDMA = 6 , RADIO_TECHNOLOGY_EVDO = 7 , RADIO_TECHNOLOGY_EHRPD = 8 , RADIO_TECHNOLOGY_LTE = 9 , RADIO_TECHNOLOGY_LTE_CA = 10 , RADIO_TECHNOLOGY_IWLAN = 11 , RADIO_TECHNOLOGY_NR = 12<br/>} | 语音接入技术类型。 | 
| [RilSimStatus](_ril_v11.md#rilsimstatus) {<br/>RIL_USIM_INVALID = 0 , RIL_USIM_VALID = 1 , RIL_USIM_CS_INVALID = 2 , RIL_USIM_PS_INVALID = 3 , RIL_USIM_CS_PS_INVALID = 4 , RIL_ROM_SIM = 240 , RIL_NO_USIM = 255<br/>} | SIM卡状态。 | 
| [RilRegStatus](_ril_v11.md#rilregstatus) {<br/>NO_REG_MT_NO_SEARCH = 0 , REG_MT_HOME = 1 , NO_REG_MT_SEARCHING = 2 , REG_MT_REJECTED = 3 , REG_MT_UNKNOWN = 4 , REG_MT_ROAMING = 5 , REG_MT_EMERGENCY = 6<br/>} | 描述网络注册状态。 | 
| [RilCellConnectionStatus](_ril_v11.md#rilcellconnectionstatus) { RIL_SERVING_CELL_UNKNOWN = 0 , RIL_SERVING_CELL_PRIMARY = 1 , RIL_SERVING_CELL_SECONDARY = 2 } | 小区连接状态。 | 
| [RilRegNotifyMode](_ril_v11.md#rilregnotifymode) { REG_NOT_NOTIFY = 0 , REG_NOTIFY_STAT_ONLY = 1 , REG_NOTIFY_STAT_LAC_CELLID = 2 } | 上报模式。 | 
| [RadioProtocolPhase](_ril_v11.md#radioprotocolphase) {<br/>RADIO_PROTOCOL_PHASE_INITIAL , RADIO_PROTOCOL_PHASE_CHECK , RADIO_PROTOCOL_PHASE_UPDATE , RADIO_PROTOCOL_PHASE_NOTIFY , RADIO_PROTOCOL_PHASE_COMPLETE<br/>} | 设置Radio协议动作参数。 | 
| [RadioProtocolStatus](_ril_v11.md#radioprotocolstatus) { RADIO_PROTOCOL_STATUS_NONE , RADIO_PROTOCOL_STATUS_SUCCESS , RADIO_PROTOCOL_STATUS_FAIL } | Radio协议状态。 | 
