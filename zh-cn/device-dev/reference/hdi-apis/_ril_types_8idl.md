# Types.idl


## 概述

Ril模块HDI接口使用的数据类型。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[Ril](_ril.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [EmergencyCall](_emergency_call.md) | struct<br/>紧急呼叫号码。 | 
| [EmergencyInfoList](_emergency_info_list.md) | struct<br/>紧急呼叫号码列表。 | 
| [RilRadioResponseInfo](_ril_radio_response_info.md) | struct<br/>响应通用信息。 | 
| [SetupDataCallResultInfo](_setup_data_call_result_info.md) | struct<br/>数据业务激活结果信息。 | 
| [DataCallResultList](_data_call_result_list.md) | struct<br/>数据业务激活结果列表。 | 
| [DataProfileDataInfo](_data_profile_data_info.md) | struct<br/>PDP上下文信息。 | 
| [DataProfilesInfo](_data_profiles_info.md) | struct<br/>PDP上下文信息列表。 | 
| [DataCallInfo](_data_call_info.md) | struct<br/>数据业务信息。 | 
| [DataLinkBandwidthInfo](_data_link_bandwidth_info.md) | struct<br/>网络频率信息。 | 
| [DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule.md) | struct<br/>网络频率上报规则。 | 
| [DataPerformanceInfo](_data_performance_info.md) | struct<br/>数据业务性能模式。 | 
| [DataSleepInfo](_data_sleep_info.md) | struct<br/>数据业务睡眠模式。 | 
| [UniInfo](_uni_info.md) | struct<br/>通用信息。 | 
| [VoiceRadioTechnology](_voice_radio_technology.md) | struct<br/>电路域接入技术。 | 
| [DialInfo](_dial_info.md) | struct<br/>拨号信息。 | 
| [CallInfo](_call_info.md) | struct<br/>通话状态信息。 | 
| [CallInfoList](_call_info_list.md) | struct<br/>通话状态信息列表。 | 
| [GetClipResult](_get_clip_result.md) | struct<br/>主叫号码显示结果信息。 | 
| [GetClirResult](_get_clir_result.md) | struct<br/>主叫号码显示限制结果信息。 | 
| [CallWaitResult](_call_wait_result.md) | struct<br/>呼叫等待结果信息。 | 
| [CallRestrictionInfo](_call_restriction_info.md) | struct<br/>呼叫限制信息。 | 
| [CallRestrictionResult](_call_restriction_result.md) | struct<br/>呼叫限制结果信息。 | 
| [CallForwardSetInfo](_call_forward_set_info.md) | struct<br/>呼叫转移信息。 | 
| [CallForwardQueryResult](_call_forward_query_result.md) | struct<br/>呼叫转移查询结果信息。 | 
| [CallForwardQueryInfoList](_call_forward_query_info_list.md) | struct<br/>呼叫转移信息列表。 | 
| [UssdNoticeInfo](_ussd_notice_info.md) | struct<br/>非结构化补充数据业务(USSD)业务信息。 | 
| [SsNoticeInfo](_ss_notice_info.md) | struct<br/>补充业务信息。 | 
| [SrvccStatus](_srvcc_status.md) | struct<br/>SRVCC（Single&nbsp;Radio&nbsp;Voice&nbsp;Call&nbsp;Continuity）状态信息。 | 
| [RingbackVoice](_ringback_voice.md) | struct<br/>回铃音信息。 | 
| [DtmfInfo](_dtmf_info.md) | struct<br/>发送双音多频(DTMF)信息。 | 
| [SetBarringInfo](_set_barring_info.md) | struct<br/>设置呼叫限制密码的信息。 | 
| [CardStatusInfo](_card_status_info.md) | struct<br/>SIM卡状态信息。 | 
| [SimIoRequestInfo](_sim_io_request_info.md) | struct<br/>SIM数据请求信息。 | 
| [IccIoResultInfo](_icc_io_result_info.md) | struct<br/>SIM数据的响应结果信息。 | 
| [SimLockInfo](_sim_lock_info.md) | struct<br/>SIM卡锁信息。 | 
| [SimPasswordInfo](_sim_password_info.md) | struct<br/>SIM卡密码信息。 | 
| [SimPinInputTimes](_sim_pin_input_times.md) | struct<br/>SIM密码输入次数信息。 | 
| [ApduSimIORequestInfo](_apdu_sim_i_o_request_info.md) | struct<br/>APDU数据传输请求信息。 | 
| [SimAuthenticationRequestInfo](_sim_authentication_request_info.md) | struct<br/>SIM卡鉴权请求信息。 | 
| [OpenLogicalChannelResponse](_open_logical_channel_response.md) | struct<br/>APDU打开逻辑通道响应信息。 | 
| [LockStatusResp](_lock_status_resp.md) | struct<br/>SIM卡解锁响应 | 
| [RadioProtocol](_radio_protocol.md) | struct<br/>主副卡协议栈信息。 | 
| [GsmRssi](_gsm_rssi.md) | struct<br/>GSM信号强度。 | 
| [CdmaRssi](_cdma_rssi.md) | struct<br/>CDMA信号强度。 | 
| [WcdmaRssi](_wcdma_rssi.md) | struct<br/>WCDMA信号强度。 | 
| [LteRssi](_lte_rssi.md) | struct<br/>LTE信号强度。 | 
| [TdScdmaRssi](_td_scdma_rssi.md) | struct<br/>TDSCDMA信号强度。 | 
| [NrRssi](_nr_rssi.md) | struct<br/>NR信号强度。 | 
| [Rssi](_rssi.md) | struct<br/>接收信号强度信息。 | 
| [CsRegStatusInfo](_cs_reg_status_info.md) | struct<br/>CS注册状态信息。 | 
| [PsRegStatusInfo](_ps_reg_status_info.md) | struct<br/>PS注册状态信息。 | 
| [OperatorInfo](_operator_info.md) | struct<br/>运营商信息。 | 
| [AvailableNetworkInfo](_available_network_info.md) | struct<br/>可用网络信息。 | 
| [AvailableNetworkList](_available_network_list.md) | struct<br/>可用网络列表。 | 
| [SetNetworkModeInfo](_set_network_mode_info.md) | struct<br/>设置网络模式信息。 | 
| [CellListRatGsm](_cell_list_rat_gsm.md) | struct<br/>GSM小区信息。 | 
| [CellListRatLte](_cell_list_rat_lte.md) | struct<br/>LTE小区信息。 | 
| [CellListRatWcdma](_cell_list_rat_wcdma.md) | struct<br/>WCDMA小区信息。 | 
| [CellListRatCdma](_cell_list_rat_cdma.md) | struct<br/>CDMA小区信息。 | 
| [CellListRatTdscdma](_cell_list_rat_tdscdma.md) | struct<br/>TDSCDMA小区信息。 | 
| [CellListRatNr](_cell_list_rat_nr.md) | struct<br/>NR小区信息。 | 
| [ServiceCellParas](union_service_cell_paras.md) | union<br/>多种网络模式的小区信息。 | 
| [CellNearbyInfo](_cell_nearby_info.md) | struct<br/>相邻小区信息。 | 
| [CellListNearbyInfo](_cell_list_nearby_info.md) | struct<br/>附近小区信息列表。 | 
| [CellRatGsm](_cell_rat_gsm.md) | struct<br/>GSM蜂窝信息。 | 
| [CellRatLte](_cell_rat_lte.md) | struct<br/>LTE蜂窝信息。 | 
| [CellRatWcdma](_cell_rat_wcdma.md) | struct<br/>WCDMA蜂窝信息。 | 
| [CellRatCdma](_cell_rat_cdma.md) | struct<br/>CDMA蜂窝信息。 | 
| [CellRatTdscdma](_cell_rat_tdscdma.md) | struct<br/>TDSCDMA蜂窝信息。 | 
| [CellRatNr](_cell_rat_nr.md) | struct<br/>NR蜂窝信息。 | 
| [CurrentServiceCellParas](union_current_service_cell_paras.md) | union<br/>当前蜂窝数据信息。 | 
| [CurrentCellInfo](_current_cell_info.md) | struct<br/>当前小区信息。 | 
| [CellListCurrentInfo](_cell_list_current_info.md) | struct<br/>当前小区信息列表。 | 
| [PreferredNetworkTypeInfo](_preferred_network_type_info.md) | struct<br/>首选网络类型信息。 | 
| [PhysicalChannelConfig](_physical_channel_config.md) | struct<br/>物理通道配置。 | 
| [ChannelConfigInfoList](_channel_config_info_list.md) | struct<br/>通道配置信息列表。 | 
| [GsmSmsMessageInfo](_gsm_sms_message_info.md) | struct<br/>发送GSM短信信息。 | 
| [SendCdmaSmsMessageInfo](_send_cdma_sms_message_info.md) | struct<br/>发送CDMA短信信息。 | 
| [SmsMessageIOInfo](_sms_message_i_o_info.md) | struct<br/>SIM卡短信信息 | 
| [ServiceCenterAddress](_service_center_address.md) | struct<br/>短信中心地址信息。 | 
| [CBConfigInfo](_c_b_config_info.md) | struct<br/>GSM小区广播配置信息。 | 
| [CdmaCBConfigInfo](_cdma_c_b_config_info.md) | struct<br/>CDMA小区广播配置信息。 | 
| [CdmaCBConfigInfoList](_cdma_c_b_config_info_list.md) | struct<br/>CDMA小区广播配置信息列表。 | 
| [CBConfigReportInfo](_c_b_config_report_info.md) | struct<br/>小区广播上报信息。 | 
| [SmsMessageInfo](_sms_message_info.md) | struct<br/>上报短信信息。 | 
| [ModeData](_mode_data.md) | struct<br/>接收短信处理模式。 | 
| [SendSmsResultInfo](_send_sms_result_info.md) | struct<br/>发送短信响应信息。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [EccType](_ril.md#ecctype)&nbsp;{<br/>TYPE_CATEGORY&nbsp;=&nbsp;0&nbsp;,&nbsp;TYPE_POLICE&nbsp;=&nbsp;1&nbsp;,&nbsp;TYPE_AMBULANCE&nbsp;=&nbsp;2&nbsp;,&nbsp;TYPE_FIRE&nbsp;=&nbsp;4&nbsp;,TYPE_SEA&nbsp;=&nbsp;8&nbsp;,&nbsp;TYPE_MOUNTAIN&nbsp;=&nbsp;16<br/>} | 紧急呼叫类型。 | 
| [SimpresentType](_ril.md#simpresenttype)&nbsp;{&nbsp;TYPE_NO_CARD&nbsp;=&nbsp;0&nbsp;,&nbsp;TYPE_HAS_CARD&nbsp;=&nbsp;1&nbsp;} | 表示号码是有卡时有效还是无卡时有效。 | 
| [AbnormalServiceType](_ril.md#abnormalservicetype)&nbsp;{&nbsp;TYPE_ALL&nbsp;=&nbsp;0&nbsp;,&nbsp;TYPE_ONLY_CS&nbsp;=&nbsp;1&nbsp;} | 表示号码有效性是否区分电路(CS)域非正常服务状态。 | 
| [RilErrType](_ril.md#rilerrtype)&nbsp;{<br/>NONE&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_ERR_GENERIC_FAILURE&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_ERR_INVALID_PARAMETER&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_ERR_MEMORY_FULL&nbsp;=&nbsp;3&nbsp;,<br/>RIL_ERR_CMD_SEND_FAILURE&nbsp;=&nbsp;4&nbsp;,&nbsp;RIL_ERR_CMD_NO_CARRIER&nbsp;=&nbsp;5&nbsp;,&nbsp;RIL_ERR_INVALID_RESPONSE&nbsp;=&nbsp;6&nbsp;,&nbsp;RIL_ERR_REPEAT_STATUS&nbsp;=&nbsp;7&nbsp;,<br/>RIL_ERR_NETWORK_SEARCHING&nbsp;=&nbsp;8&nbsp;,&nbsp;RIL_ERR_NETWORK_SEARCHING_INTERRUPTED&nbsp;=&nbsp;9&nbsp;,&nbsp;RIL_ERR_MODEM_DEVICE_CLOSE&nbsp;=&nbsp;10&nbsp;,&nbsp;RIL_ERR_NO_SIMCARD_INSERTED&nbsp;=&nbsp;11&nbsp;,&nbsp;RIL_ERR_NEED_PIN_CODE&nbsp;=&nbsp;12&nbsp;,&nbsp;RIL_ERR_NEED_PUK_CODE&nbsp;=&nbsp;13&nbsp;,&nbsp;RIL_ERR_NETWORK_SEARCH_TIMEOUT&nbsp;=&nbsp;14&nbsp;,&nbsp;RIL_ERR_PINPUK_PASSWORD_NOCORRECT&nbsp;=&nbsp;15&nbsp;,<br/>RIL_ERR_INVALID_MODEM_PARAMETER&nbsp;=&nbsp;50&nbsp;,&nbsp;RIL_ERR_HDF_IPC_FAILURE&nbsp;=&nbsp;300&nbsp;,&nbsp;RIL_ERR_NULL_POINT&nbsp;=&nbsp;301&nbsp;,&nbsp;RIL_ERR_VENDOR_NOT_IMPLEMENT&nbsp;=&nbsp;302<br/>} | Ril错误码。 | 
| [RilResponseTypes](_ril.md#rilresponsetypes)&nbsp;{<br/>RIL_RESPONSE_REQUEST&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_RESPONSE_NOTICE&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_RESPONSE_REQUEST_ACK&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_RESPONSE_REQUEST_MUST_ACK&nbsp;=&nbsp;3&nbsp;,&nbsp;RIL_RESPONSE_NOTICE_MUST_ACK&nbsp;=&nbsp;4<br/>} | 响应类型。 | 
| [RilSrvStatus](_ril.md#rilsrvstatus)&nbsp;{<br/>RIL_NO_SRV_SERVICE&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_RESTRICTED_SERVICE&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_SERVICE_VALID&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_REGIONAL_SERVICE&nbsp;=&nbsp;3&nbsp;,&nbsp;RIL_ENERGY_SAVING_SERVICE&nbsp;=&nbsp;4<br/>} | Ril系统服务状态。 | 
| [RilSrvDomain](_ril.md#rilsrvdomain)&nbsp;{<br/>RIL_NO_DOMAIN_SERVICE&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_CS_SERVICE&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_PS_SERVICE&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_CS_PS_SERVICE&nbsp;=&nbsp;3&nbsp;,&nbsp;RIL_CS_PS_SEARCHING&nbsp;=&nbsp;4&nbsp;,&nbsp;RIL_CDMA_NOT_SUPPORT&nbsp;=&nbsp;255<br/>} | 系统服务域。 | 
| [RilRoamStatus](_ril.md#rilroamstatus)&nbsp;{&nbsp;RIL_NO_ROAM&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_ROAMING&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_ROAM_UNKNOWN&nbsp;=&nbsp;2&nbsp;} | 漫游状态。 | 
| [RilSimLockStatus](_ril.md#rilsimlockstatus)&nbsp;{&nbsp;RIL_SIM_CARD_UNLOCK&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_SIM_CARD_LOCK&nbsp;=&nbsp;1&nbsp;} | SIM卡锁定状态。 | 
| [RilSysMode](_ril.md#rilsysmode)&nbsp;{<br/>RIL_NO_SYSMODE_SERVICE&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_GSM_MODE&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_CDMA_MODE&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_WCDMA_MODE&nbsp;=&nbsp;3&nbsp;,&nbsp;RIL_TDSCDMA_MODE&nbsp;=&nbsp;4&nbsp;,&nbsp;RIL_WIMAX_MODE&nbsp;=&nbsp;5&nbsp;,&nbsp;RIL_LTE_MODE&nbsp;=&nbsp;6&nbsp;,&nbsp;RIL_LTE_CA_MODE&nbsp;=&nbsp;7&nbsp;,&nbsp;RIL_NR_MODE&nbsp;=&nbsp;8<br/>} | 系统制式。 | 
| [RilRadioTech](_ril.md#rilradiotech)&nbsp;{<br/>RADIO_TECHNOLOGY_INVALID&nbsp;=&nbsp;65535&nbsp;,&nbsp;RADIO_TECHNOLOGY_UNKNOWN&nbsp;=&nbsp;0&nbsp;,&nbsp;RADIO_TECHNOLOGY_GSM&nbsp;=&nbsp;1&nbsp;,&nbsp;RADIO_TECHNOLOGY_1XRTT&nbsp;=&nbsp;2&nbsp;,&nbsp;RADIO_TECHNOLOGY_WCDMA&nbsp;=&nbsp;3&nbsp;,&nbsp;RADIO_TECHNOLOGY_HSPA&nbsp;=&nbsp;4&nbsp;,&nbsp;RADIO_TECHNOLOGY_HSPAP&nbsp;=&nbsp;5&nbsp;,&nbsp;RADIO_TECHNOLOGY_TD_SCDMA&nbsp;=&nbsp;6&nbsp;,&nbsp;RADIO_TECHNOLOGY_EVDO&nbsp;=&nbsp;7&nbsp;,&nbsp;RADIO_TECHNOLOGY_EHRPD&nbsp;=&nbsp;8&nbsp;,&nbsp;RADIO_TECHNOLOGY_LTE&nbsp;=&nbsp;9&nbsp;,&nbsp;RADIO_TECHNOLOGY_LTE_CA&nbsp;=&nbsp;10&nbsp;,&nbsp;RADIO_TECHNOLOGY_IWLAN&nbsp;=&nbsp;11&nbsp;,&nbsp;RADIO_TECHNOLOGY_NR&nbsp;=&nbsp;12<br/>} | 语音接入技术类型。 | 
| [RilSimStatus](_ril.md#rilsimstatus)&nbsp;{<br/>RIL_USIM_INVALID&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_USIM_VALID&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_USIM_CS_INVALID&nbsp;=&nbsp;2&nbsp;,&nbsp;RIL_USIM_PS_INVALID&nbsp;=&nbsp;3&nbsp;,&nbsp;RIL_USIM_CS_PS_INVALID&nbsp;=&nbsp;4&nbsp;,&nbsp;RIL_ROM_SIM&nbsp;=&nbsp;240&nbsp;,&nbsp;RIL_NO_USIM&nbsp;=&nbsp;255<br/>} | SIM卡状态。 | 
| [RilRegStatus](_ril.md#rilregstatus)&nbsp;{<br/>NO_REG_MT_NO_SEARCH&nbsp;=&nbsp;0&nbsp;,&nbsp;REG_MT_HOME&nbsp;=&nbsp;1&nbsp;,&nbsp;NO_REG_MT_SEARCHING&nbsp;=&nbsp;2&nbsp;,&nbsp;REG_MT_REJECTED&nbsp;=&nbsp;3&nbsp;,&nbsp;REG_MT_UNKNOWN&nbsp;=&nbsp;4&nbsp;,&nbsp;REG_MT_ROAMING&nbsp;=&nbsp;5&nbsp;,&nbsp;REG_MT_EMERGENCY&nbsp;=&nbsp;6<br/>} | 描述网络注册状态。 | 
| [RilCellConnectionStatus](_ril.md#rilcellconnectionstatus)&nbsp;{&nbsp;RIL_SERVING_CELL_UNKNOWN&nbsp;=&nbsp;0&nbsp;,&nbsp;RIL_SERVING_CELL_PRIMARY&nbsp;=&nbsp;1&nbsp;,&nbsp;RIL_SERVING_CELL_SECONDARY&nbsp;=&nbsp;2&nbsp;} | 小区连接状态。 | 
| [RilRegNotifyMode](_ril.md#rilregnotifymode)&nbsp;{&nbsp;REG_NOT_NOTIFY&nbsp;=&nbsp;0&nbsp;,&nbsp;REG_NOTIFY_STAT_ONLY&nbsp;=&nbsp;1&nbsp;,&nbsp;REG_NOTIFY_STAT_LAC_CELLID&nbsp;=&nbsp;2&nbsp;} | 上报模式。 | 
| [RadioProtocolPhase](_ril.md#radioprotocolphase)&nbsp;{<br/>RADIO_PROTOCOL_PHASE_INITIAL&nbsp;,&nbsp;RADIO_PROTOCOL_PHASE_CHECK&nbsp;,&nbsp;RADIO_PROTOCOL_PHASE_UPDATE&nbsp;,&nbsp;RADIO_PROTOCOL_PHASE_NOTIFY&nbsp;,&nbsp;RADIO_PROTOCOL_PHASE_COMPLETE<br/>} | 设置Radio协议动作参数。 | 
| [RadioProtocolStatus](_ril.md#radioprotocolstatus)&nbsp;{&nbsp;RADIO_PROTOCOL_STATUS_NONE&nbsp;,&nbsp;RADIO_PROTOCOL_STATUS_SUCCESS&nbsp;,&nbsp;RADIO_PROTOCOL_STATUS_FAIL&nbsp;} | Radio协议状态。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.ril.v1_0 | Ril模块接口的包路径。 | 
