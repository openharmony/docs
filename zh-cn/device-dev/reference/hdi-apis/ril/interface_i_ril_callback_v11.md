# IRilCallback


## 概述

Ril模块的回调接口。

回调接口提供打电话、发短彩信、激活SIM卡、上网等回调函数，回调函数由调用者实现。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [CallEmergencyNotice](#callemergencynotice) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [EmergencyInfoList](_emergency_info_list_v11.md) emergencyInfoList) | 紧急呼叫号码上报。 | 
| [CallStateUpdated](#callstateupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 通话状态更新上报。 | 
| [CallRingbackVoiceNotice](#callringbackvoicenotice) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [RingbackVoice](_ringback_voice_v11.md) ringbackVoice) | 通话回铃音上报。 | 
| [CallSrvccStatusNotice](#callsrvccstatusnotice) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SrvccStatus](_srvcc_status_v11.md) srvccStatus) | SRVCC（Single Radio Voice Call Continuity）状态上报。 | 
| [CallUssdNotice](#callussdnotice) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [UssdNoticeInfo](_ussd_notice_info_v11.md) ussdNoticeInfo) | USSD业务信息上报。 | 
| [CallSsNotice](#callssnotice) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SsNoticeInfo](_ss_notice_info_v11.md) ssNoticeInfo) | 补充业务信息上报。 | 
| [CallRsrvccStatusNotify](#callrsrvccstatusnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | RSRVCC（Reverse Single Radio Voice Call Continuity）状态上报。 | 
| [SetEmergencyCallListResponse](#setemergencycalllistresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置紧急呼叫号码列表响应。 | 
| [GetEmergencyCallListResponse](#getemergencycalllistresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [EmergencyInfoList](_emergency_info_list_v11.md) emergencyInfoList) | 查询紧急呼叫号码列表响应。 | 
| [GetCallListResponse](#getcalllistresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CallInfoList](_call_info_list_v11.md) callList) | 查询通话状态列表响应。 | 
| [DialResponse](#dialresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 拨打电话响应。 | 
| [HangupResponse](#hangupresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 挂断电话响应。 | 
| [RejectResponse](#rejectresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 拒接电话响应。 | 
| [AnswerResponse](#answerresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 接听电话响应。 | 
| [HoldCallResponse](#holdcallresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 保持通话响应。 | 
| [UnHoldCallResponse](#unholdcallresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 取消保持通话响应。 | 
| [SwitchCallResponse](#switchcallresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 切换通话响应。 | 
| [GetClipResponse](#getclipresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [GetClipResult](_get_clip_result_v11.md) getClipResult) | 查询主叫号码显示响应。 | 
| [SetClipResponse](#setclipresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置主叫号码显示响应。 | 
| [CombineConferenceResponse](#combineconferenceresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 合并为会议电话响应。 | 
| [SeparateConferenceResponse](#separateconferenceresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 与会议电话分离响应。 | 
| [CallSupplementResponse](#callsupplementresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 挂断前台、恢复后台响应。 | 
| [GetCallWaitingResponse](#getcallwaitingresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CallWaitResult](_call_wait_result_v11.md) callWaitResult) | 查询呼叫等待响应。 | 
| [SetCallWaitingResponse](#setcallwaitingresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置呼叫等待响应。 | 
| [GetCallTransferInfoResponse](#getcalltransferinforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CallForwardQueryInfoList](_call_forward_query_info_list_v11.md) cFQueryList) | 查询呼叫转移响应。 | 
| [SetCallTransferInfoResponse](#setcalltransferinforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置呼叫转移响应。 | 
| [GetCallRestrictionResponse](#getcallrestrictionresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CallRestrictionResult](_call_restriction_result_v11.md) result) | 查询呼叫限制响应。 | 
| [SetCallRestrictionResponse](#setcallrestrictionresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置呼叫限制响应。 | 
| [GetClirResponse](#getclirresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [GetClirResult](_get_clir_result_v11.md) getClirResult) | 查询主叫号码显示限制响应。 | 
| [SetClirResponse](#setclirresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置主叫号码显示限制响应。 | 
| [StartDtmfResponse](#startdtmfresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 开启DTMF响应。 | 
| [SendDtmfResponse](#senddtmfresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 发送DTMF响应。 | 
| [StopDtmfResponse](#stopdtmfresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 关闭DTMF响应。 | 
| [GetCallPreferenceModeResponse](#getcallpreferencemoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int mode) | 查询通话偏好模式响应。 | 
| [SetCallPreferenceModeResponse](#setcallpreferencemoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置通话偏好模式响应。 | 
| [SetUssdResponse](#setussdresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置USSD业务响应。 | 
| [GetUssdResponse](#getussdresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int cusd) | 查询USSD业务响应。 | 
| [SetMuteResponse](#setmuteresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置静音响应。 | 
| [GetMuteResponse](#getmuteresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int mute) | 查询静音响应。 | 
| [GetCallFailReasonResponse](#getcallfailreasonresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int callFail) | 查询通话失败原因响应。 | 
| [SetBarringPasswordResponse](#setbarringpasswordresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置呼叫限制密码响应。 | 
| [SetVonrSwitchResponse](#setvonrswitchresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置Vonr开关的响应。 | 
| [PdpContextListUpdated](#pdpcontextlistupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [DataCallResultList](_data_call_result_list_v11.md) dataCallResultList) | 数据业务建立与断开等状态变化上报。 | 
| [DataLinkCapabilityUpdated](#datalinkcapabilityupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [DataLinkCapability](_data_link_capability_v11.md) capability) | 报告数据链路功能。 | 
| [ActivatePdpContextResponse](#activatepdpcontextresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SetupDataCallResultInfo](_setup_data_call_result_info_v11.md) setupDataCallResultInfo) | 激活数据业务响应。 | 
| [DeactivatePdpContextResponse](#deactivatepdpcontextresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 断开数据业务响应。 | 
| [GetPdpContextListResponse](#getpdpcontextlistresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [DataCallResultList](_data_call_result_list_v11.md) dataCallResultList) | 获取当前所有数据连接状态响应。 | 
| [SetInitApnInfoResponse](#setinitapninforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置初始化默认网络接入技术(APN)信息响应。 | 
| [GetLinkBandwidthInfoResponse](#getlinkbandwidthinforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [DataLinkBandwidthInfo](_data_link_bandwidth_info_v11.md) dataLinkBandwidthInfo) | 获取当前链路信息响应。 | 
| [GetLinkCapabilityResponse](#getlinkcapabilityresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [DataLinkCapability](_data_link_capability_v11.md) capability) | Callback for the response of get link capability. | 
| [SetLinkBandwidthReportingRuleResponse](#setlinkbandwidthreportingruleresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置当前链路信息的上报规则响应。 | 
| [SetDataPermittedResponse](#setdatapermittedresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 使能SIM卡槽数据业务响应。 | 
| [RadioStateUpdated](#radiostateupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int state) | Radio状态上报。 | 
| [VoiceRadioTechUpdated](#voiceradiotechupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [VoiceRadioTechnology](_voice_radio_technology_v11.md) voiceRadioTechnology) | 语音接入技术变化上报。 | 
| [DsdsModeUpdated](#dsdsmodeupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int state) | Reporting the dsds mode. | 
| [ShutDownResponse](#shutdownresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | Modem收到手机正在关机响应。 | 
| [SetRadioStateResponse](#setradiostateresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置Modem状态响应。 | 
| [GetRadioStateResponse](#getradiostateresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo,[in] int state) | 查询Modem状态响应。 | 
| [GetImeiResponse](#getimeiresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String imei) | 获取国际移动设备识别码响应。 | 
| [GetMeidResponse](#getmeidresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String meid) | 获取移动设备识别码响应。 | 
| [GetVoiceRadioTechnologyResponse](#getvoiceradiotechnologyresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [VoiceRadioTechnology](_voice_radio_technology_v11.md) voiceRadioTechnology) | 获取电路域接入技术响应。 | 
| [GetBasebandVersionResponse](#getbasebandversionresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String basebandVersion) | 查询基带版本响应。 | 
| [SimStateUpdated](#simstateupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | SIM卡状态变化上报。 | 
| [SimStkSessionEndNotify](#simstksessionendnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | STK SessionEnd指令上报。 | 
| [SimStkProactiveNotify](#simstkproactivenotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String response) | STK Proactive指令上报。 | 
| [SimStkAlphaNotify](#simstkalphanotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String response) | STK Alpha指令上报。 | 
| [SimStkEventNotify](#simstkeventnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String response) | STK事件上报。 | 
| [SimStkCallSetupNotify](#simstkcallsetupnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | STK CallSetup指令上报。 | 
| [SimRefreshNotify](#simrefreshnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | SIM状态刷新上报。 | 
| [SimRadioProtocolUpdated](#simradioprotocolupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [RadioProtocol](_radio_protocol_v11.md) radioProtocol) | STK Radio协议更新上报。 | 
| [GetSimIOResponse](#getsimioresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [IccIoResultInfo](_icc_io_result_info_v11.md) result) | 获取SIM卡数据响应。 | 
| [GetSimStatusResponse](#getsimstatusresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CardStatusInfo](_card_status_info_v11.md) result) | 获取SIM卡状态响应。 | 
| [GetImsiResponse](#getimsiresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String response) | 获取SIM卡IMSI响应。 | 
| [GetSimLockStatusResponse](#getsimlockstatusresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int simLockStatus) | 获取SIM卡锁状态响应。 | 
| [SetSimLockResponse](#setsimlockresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | 设置SIM卡锁响应。 | 
| [ChangeSimPasswordResponse](#changesimpasswordresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | 修改SIM卡密码响应。 | 
| [UnlockPinResponse](#unlockpinresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | PIN解锁响应。 | 
| [UnlockPukResponse](#unlockpukresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | PUK解锁响应。 | 
| [UnlockPin2Response](#unlockpin2response) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | PIN2解锁响应。 | 
| [UnlockPuk2Response](#unlockpuk2response) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | PUK2解锁响应。 | 
| [SetActiveSimResponse](#setactivesimresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 激活去激活SIM卡响应。 | 
| [SimStkSendTerminalResponseResponse](#simstksendterminalresponseresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 发送STK TerminalResponse指令响应。 | 
| [SimStkSendEnvelopeResponse](#simstksendenveloperesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 发送STK Envelope指令响应。 | 
| [SimStkSendCallSetupRequestResultResponse](#simstksendcallsetuprequestresultresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 发送STK CallSetup指令响应。 | 
| [SimStkIsReadyResponse](#simstkisreadyresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 获取STK是否Ready状态响应。 | 
| [GetRadioProtocolResponse](#getradioprotocolresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo,[in] struct [RadioProtocol](_radio_protocol_v11.md) radioProtocol) | 获取主副卡协议栈响应。 | 
| [SetRadioProtocolResponse](#setradioprotocolresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo,[in] struct [RadioProtocol](_radio_protocol_v11.md) radioProtocol) | 设置主副卡协议栈响应。 | 
| [SimOpenLogicalChannelResponse](#simopenlogicalchannelresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [OpenLogicalChannelResponse](_open_logical_channel_response_v11.md) pOpenLogicalChannelResponse) | APDU打开逻辑通道响应。 | 
| [SimCloseLogicalChannelResponse](#simcloselogicalchannelresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | APDU关闭逻辑通道响应。 | 
| [SimTransmitApduLogicalChannelResponse](#simtransmitapdulogicalchannelresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [IccIoResultInfo](_icc_io_result_info_v11.md) result) | APDU逻辑通道数据传输响应。 | 
| [SimTransmitApduBasicChannelResponse](#simtransmitapdubasicchannelresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [IccIoResultInfo](_icc_io_result_info_v11.md) result) | APDU基础通道数据传输响应。 | 
| [SimAuthenticationResponse](#simauthenticationresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [IccIoResultInfo](_icc_io_result_info_v11.md) result) | SIM卡鉴权响应。 | 
| [UnlockSimLockResponse](#unlocksimlockresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [LockStatusResp](_lock_status_resp_v11.md) lockStatus) | 解锁SIM卡响应。 | 
| [NetworkCsRegStatusUpdated](#networkcsregstatusupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CsRegStatusInfo](_cs_reg_status_info_v11.md) csRegStatusInfo) | CS域网络注册状态变化上报。 | 
| [NetworkPsRegStatusUpdated](#networkpsregstatusupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [PsRegStatusInfo](_ps_reg_status_info_v11.md) psRegStatusInfo) | PS域网络注册状态变化上报。 | 
| [SignalStrengthUpdated](#signalstrengthupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [Rssi](_rssi_v11.md) rssi) | 信号强度变化上报。 | 
| [NetworkTimeZoneUpdated](#networktimezoneupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String timeZoneStr) | NITZ时区变化上报。 | 
| [NetworkTimeUpdated](#networktimeupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] String timeStr) | NITZ时间更新上报。 | 
| [NetworkPhyChnlCfgUpdated](#networkphychnlcfgupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [ChannelConfigInfoList](_channel_config_info_list_v11.md) channelConfigInfoList) | 物理通道配置消息上报。 | 
| [NetworkCurrentCellUpdated](#networkcurrentcellupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CellListCurrentInfo](_cell_list_current_info_v11.md) cellListCurrentInfo) | 小区信息上报。 | 
| [NetworkCurrentCellUpdated_1_1](#networkcurrentcellupdated_1_1) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CellListCurrentInfo_1_1](_cell_list_current_info__1__1_v11.md) cellListCurrentInfo) | 小区信息上报。 | 
| [GetSignalStrengthResponse](#getsignalstrengthresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [Rssi](_rssi_v11.md) rssi) | 获取信号强度响应。 | 
| [GetCsRegStatusResponse](#getcsregstatusresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CsRegStatusInfo](_cs_reg_status_info_v11.md) csRegStatusInfo) | 获取语音(CS)域注册状态响应。 | 
| [GetPsRegStatusResponse](#getpsregstatusresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [PsRegStatusInfo](_ps_reg_status_info_v11.md) psRegStatusInfo) | 获取分组(PS)域注册状态响应。 | 
| [GetOperatorInfoResponse](#getoperatorinforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [OperatorInfo](_operator_info_v11.md) psRegStatusInfo) | 获取运营商名称信息响应。 | 
| [GetNetworkSearchInformationResponse](#getnetworksearchinformationresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [AvailableNetworkList](_available_network_list_v11.md) availableNetworkList) | 获取可用网络信息响应。 | 
| [GetNetworkSelectionModeResponse](#getnetworkselectionmoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SetNetworkModeInfo](_set_network_mode_info_v11.md) setNetworkModeInfo) | 获取选网模式响应。 | 
| [SetNetworkSelectionModeResponse](#setnetworkselectionmoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置选网模式响应。 | 
| [GetNeighboringCellInfoListResponse](#getneighboringcellinfolistresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CellListNearbyInfo](_cell_list_nearby_info_v11.md) cellListNearbyInfo) | 获取相邻小区信息响应。 | 
| [GetCurrentCellInfoResponse](#getcurrentcellinforesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CellListCurrentInfo](_cell_list_current_info_v11.md) cellListCurrentInfo) | 获取小区信息响应。 | 
| [GetCurrentCellInfoResponse_1_1](#getcurrentcellinforesponse_1_1) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CellListCurrentInfo_1_1](_cell_list_current_info__1__1_v11.md) cellListCurrentInfo) | 获取小区信息响应。 | 
| [SetPreferredNetworkResponse](#setpreferrednetworkresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置首选网络类型响应。 | 
| [GetPreferredNetworkResponse](#getpreferrednetworkresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [PreferredNetworkTypeInfo](_preferred_network_type_info_v11.md) preferredNetworkTypeInfo) | 获取首选网络类型响应。 | 
| [GetPhysicalChannelConfigResponse](#getphysicalchannelconfigresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [ChannelConfigInfoList](_channel_config_info_list_v11.md) channelConfigInfoList) | 获取物理通道配置响应。 | 
| [SetLocateUpdatesResponse](#setlocateupdatesresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 开启或关闭小区位置更新导致的网络状态通知响应。 | 
| [SetNotificationFilterResponse](#setnotificationfilterresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置通知过滤器响应。 | 
| [SetDeviceStateResponse](#setdevicestateresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置设备状态响应。 | 
| [NewSmsNotify](#newsmsnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SmsMessageInfo](_sms_message_info_v11.md) smsMessageInfo) | GSM新短信通知上报。 | 
| [NewCdmaSmsNotify](#newcdmasmsnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo,[in] struct [SmsMessageInfo](_sms_message_info_v11.md) smsMessageInfo) | CDMA新短信通知上报。 | 
| [SmsStatusReportNotify](#smsstatusreportnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SmsMessageInfo](_sms_message_info_v11.md) smsMessageInfo) | 新短信状态通知上报。 | 
| [NewSmsStoredOnSimNotify](#newsmsstoredonsimnotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int recordNumber, [in] int indicationType) | 收到SIM卡短信上报。 | 
| [CBConfigNotify](#cbconfignotify) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CBConfigReportInfo](_c_b_config_report_info_v11.md) cellBroadConfigReportInfo) | 小区广播配置上报。 | 
| [SendGsmSmsResponse](#sendgsmsmsresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SendSmsResultInfo](_send_sms_result_info_v11.md) sendSmsResultInfo) | 发送GSM短信响应。 | 
| [SendCdmaSmsResponse](#sendcdmasmsresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SendSmsResultInfo](_send_sms_result_info_v11.md) sendSmsResultInfo) | 发送CDMA短信响应。 | 
| [AddSimMessageResponse](#addsimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 写入GSM SIM卡短信响应。 | 
| [DelSimMessageResponse](#delsimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 删除GSM SIM卡短信响应。 | 
| [UpdateSimMessageResponse](#updatesimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 更新GSM SIM卡短信响应。 | 
| [AddCdmaSimMessageResponse](#addcdmasimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 写入CDMA SIM卡短信响应。 | 
| [DelCdmaSimMessageResponse](#delcdmasimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 删除CDMA SIM卡短信响应。 | 
| [UpdateCdmaSimMessageResponse](#updatecdmasimmessageresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 更新CDMA SIM卡短信响应。 | 
| [SetSmscAddrResponse](#setsmscaddrresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置短信中心地址响应。 | 
| [GetSmscAddrResponse](#getsmscaddrresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [ServiceCenterAddress](_service_center_address_v11.md) serviceCenterAddress) | 获取短信中心地址响应。 | 
| [SetCBConfigResponse](#setcbconfigresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 激活GSM小区广播响应。 | 
| [GetCBConfigResponse](#getcbconfigresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CBConfigInfo](_c_b_config_info_v11.md) cellBroadcastInfo) | 获取GSM小区广播配置响应。 | 
| [SetCdmaCBConfigResponse](#setcdmacbconfigresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 激活CDMA小区广播响应。 | 
| [GetCdmaCBConfigResponse](#getcdmacbconfigresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [CdmaCBConfigInfo](_cdma_c_b_config_info_v11.md) cdmaCBConfigInfo) | 获取CDMA小区广播配置响应。 | 
| [SendSmsMoreModeResponse](#sendsmsmoremoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] struct [SendSmsResultInfo](_send_sms_result_info_v11.md) sendSmsResultInfo) | 发送GSM长短信响应。 | 
| [SendSmsAckResponse](#sendsmsackresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 确认接收新短信响应。 | 
| [CommonErrorResponse](#commonerrorresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 通用错误响应。 | 
| [GetRrcConnectionStateResponse](#getrrcconnectionstateresponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int state) | 获取RRC连接状态响应。 | 
| [SetNrOptionModeResponse](#setnroptionmoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo) | 设置NR选项模式响应。 | 
| [GetNrOptionModeResponse](#getnroptionmoderesponse) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int mode) | 获取NR选项模式响应。 | 
| [GetRrcConnectionStateUpdated](#getrrcconnectionstateupdated) ([in] struct [RilRadioResponseInfo](_ril_radio_response_info_v11.md) responseInfo, [in] int state) | RRC连接状态更新上报。 | 


## 成员函数说明


### ActivatePdpContextResponse()

```
IRilCallback::ActivatePdpContextResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SetupDataCallResultInfo setupDataCallResultInfo )
```

**描述**


激活数据业务响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| setupDataCallResultInfo | 表示数据业务激活结果信息，详见[SetupDataCallResultInfo](_setup_data_call_result_info_v11.md)。 | 


### AddCdmaSimMessageResponse()

```
IRilCallback::AddCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


写入CDMA SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### AddSimMessageResponse()

```
IRilCallback::AddSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


写入GSM SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### AnswerResponse()

```
IRilCallback::AnswerResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


接听电话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### CallEmergencyNotice()

```
IRilCallback::CallEmergencyNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct EmergencyInfoList emergencyInfoList )
```

**描述**


紧急呼叫号码上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list_v11.md)。 | 


### CallRingbackVoiceNotice()

```
IRilCallback::CallRingbackVoiceNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct RingbackVoice ringbackVoice )
```

**描述**


通话回铃音上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| ringbackVoice | 表示回铃音信息，详见[RingbackVoice](_ringback_voice_v11.md)。 | 


### CallRsrvccStatusNotify()

```
IRilCallback::CallRsrvccStatusNotify ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


RSRVCC（Reverse Single Radio Voice Call Continuity）状态上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### CallSrvccStatusNotice()

```
IRilCallback::CallSrvccStatusNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct SrvccStatus srvccStatus )
```

**描述**


SRVCC（Single Radio Voice Call Continuity）状态上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| srvccStatus | 表示SRVCC（Single Radio Voice Call Continuity）状态，详见[SrvccStatus](_srvcc_status_v11.md)。 | 


### CallSsNotice()

```
IRilCallback::CallSsNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct SsNoticeInfo ssNoticeInfo )
```

**描述**


补充业务信息上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| ssNoticeInfo | 表示补充业务信息，详见[SsNoticeInfo](_ss_notice_info_v11.md)。 | 


### CallStateUpdated()

```
IRilCallback::CallStateUpdated ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


通话状态更新上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### CallSupplementResponse()

```
IRilCallback::CallSupplementResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


挂断前台、恢复后台响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### CallUssdNotice()

```
IRilCallback::CallUssdNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct UssdNoticeInfo ussdNoticeInfo )
```

**描述**


USSD业务信息上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| ussdNoticeInfo | 表示USSD业务信息，详见[UssdNoticeInfo](_ussd_notice_info_v11.md)。 | 


### CBConfigNotify()

```
IRilCallback::CBConfigNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct CBConfigReportInfo cellBroadConfigReportInfo )
```

**描述**


小区广播配置上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellBroadConfigReportInfo | 表示小区广播上报信息，详见[CBConfigReportInfo](_c_b_config_report_info_v11.md)。 | 


### ChangeSimPasswordResponse()

```
IRilCallback::ChangeSimPasswordResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


修改SIM卡密码响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### CombineConferenceResponse()

```
IRilCallback::CombineConferenceResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


合并为会议电话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### CommonErrorResponse()

```
IRilCallback::CommonErrorResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


通用错误响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### DataLinkCapabilityUpdated()

```
IRilCallback::DataLinkCapabilityUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataLinkCapability capability )
```

**描述**


报告数据链路功能。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| capability | 表示数据链路能力。 | 


### DeactivatePdpContextResponse()

```
IRilCallback::DeactivatePdpContextResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


断开数据业务响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### DelCdmaSimMessageResponse()

```
IRilCallback::DelCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


删除CDMA SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### DelSimMessageResponse()

```
IRilCallback::DelSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


删除GSM SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### DialResponse()

```
IRilCallback::DialResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


拨打电话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### DsdsModeUpdated()

```
IRilCallback::DsdsModeUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```

**描述**


Reporting the dsds mode.

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| state | 表示Dsds模式。 | 


### GetBasebandVersionResponse()

```
IRilCallback::GetBasebandVersionResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String basebandVersion )
```

**描述**


查询基带版本响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| basebandVersion | 表示基带版本。 | 


### GetCallFailReasonResponse()

```
IRilCallback::GetCallFailReasonResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int callFail )
```

**描述**


查询通话失败原因响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| callFail | 表示通话失败原因。 | 


### GetCallListResponse()

```
IRilCallback::GetCallListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallInfoList callList )
```

**描述**


查询通话状态列表响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| callList | 表示通话状态信息列表，详见[CallInfoList](_call_info_list_v11.md)。 | 


### GetCallPreferenceModeResponse()

```
IRilCallback::GetCallPreferenceModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int mode )
```

**描述**


查询通话偏好模式响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| mode | 表示CallPreference模式。 | 


### GetCallRestrictionResponse()

```
IRilCallback::GetCallRestrictionResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallRestrictionResult result )
```

**描述**


查询呼叫限制响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| result | 表示呼叫限制结果信息，详见[CallRestrictionResult](_call_restriction_result_v11.md)。 | 


### GetCallTransferInfoResponse()

```
IRilCallback::GetCallTransferInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallForwardQueryInfoList cFQueryList )
```

**描述**


查询呼叫转移响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cFQueryList | 表示呼叫转移信息列表，详见[CallForwardQueryInfoList](_call_forward_query_info_list_v11.md)。 | 


### GetCallWaitingResponse()

```
IRilCallback::GetCallWaitingResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallWaitResult callWaitResult )
```

**描述**


查询呼叫等待响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| callWaitResult | 表示呼叫等待结果信息，详见[CallWaitResult](_call_wait_result_v11.md)。 | 


### GetCBConfigResponse()

```
IRilCallback::GetCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CBConfigInfo cellBroadcastInfo )
```

**描述**


获取GSM小区广播配置响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellBroadcastInfo | 表示GSM小区广播配置信息，详见[CBConfigInfo](_c_b_config_info_v11.md)。 | 


### GetCdmaCBConfigResponse()

```
IRilCallback::GetCdmaCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CdmaCBConfigInfo cdmaCBConfigInfo )
```

**描述**


获取CDMA小区广播配置响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cdmaCBConfigInfo | 表示CDMA小区广播配置信息，详见[CdmaCBConfigInfo](_cdma_c_b_config_info_v11.md)。 | 


### GetClipResponse()

```
IRilCallback::GetClipResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct GetClipResult getClipResult )
```

**描述**


查询主叫号码显示响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| getClipResult | 表示主叫号码显示结果信息，详见[GetClipResult](_get_clip_result_v11.md)。 | 


### GetClirResponse()

```
IRilCallback::GetClirResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct GetClirResult getClirResult )
```

**描述**


查询主叫号码显示限制响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| getClirResult | 表示主叫号码显示限制结果信息，详见[GetClirResult](_get_clir_result_v11.md)。 | 


### GetCsRegStatusResponse()

```
IRilCallback::GetCsRegStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CsRegStatusInfo csRegStatusInfo )
```

**描述**


获取语音(CS)域注册状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| csRegStatusInfo | 表示CS注册状态信息，详见[CsRegStatusInfo](_cs_reg_status_info_v11.md)。 | 


### GetCurrentCellInfoResponse()

```
IRilCallback::GetCurrentCellInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo cellListCurrentInfo )
```

**描述**


获取小区信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellListCurrentInfo | 表示附近的小区信息列表，详见[CellListCurrentInfo](_cell_list_current_info_v11.md)。 | 


### GetCurrentCellInfoResponse_1_1()

```
IRilCallback::GetCurrentCellInfoResponse_1_1 ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo_1_1 cellListCurrentInfo )
```

**描述**


获取小区信息响应。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | responseInfo 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellListCurrentInfo | 表示附近的小区信息列表，详见[CellListCurrentInfo_1_1](_cell_list_current_info__1__1_v11.md)。 | 


### GetEmergencyCallListResponse()

```
IRilCallback::GetEmergencyCallListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct EmergencyInfoList emergencyInfoList )
```

**描述**


查询紧急呼叫号码列表响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list_v11.md)。 | 


### GetImeiResponse()

```
IRilCallback::GetImeiResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String imei )
```

**描述**


获取国际移动设备识别码响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| imei | 表示IMEI。 | 


### GetImsiResponse()

```
IRilCallback::GetImsiResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```

**描述**


获取SIM卡IMSI响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| response | 表示获取到的IMSI文本。 | 


### GetLinkBandwidthInfoResponse()

```
IRilCallback::GetLinkBandwidthInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataLinkBandwidthInfo dataLinkBandwidthInfo )
```

**描述**


获取当前链路信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| dataLinkBandwidthInfo | 表示网络频率信息，详见[DataLinkBandwidthInfo](_data_link_bandwidth_info_v11.md)。 | 


### GetLinkCapabilityResponse()

```
IRilCallback::GetLinkCapabilityResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataLinkCapability capability )
```

**描述**


Callback for the response of get link capability.

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| capability | 数据链路能力。 | 


### GetMeidResponse()

```
IRilCallback::GetMeidResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String meid )
```

**描述**


获取移动设备识别码响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| meid | 表示MEID。 | 


### GetMuteResponse()

```
IRilCallback::GetMuteResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int mute )
```

**描述**


查询静音响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| mute | 表示静音状态，0表示非静音，1表示静音。 | 


### GetNeighboringCellInfoListResponse()

```
IRilCallback::GetNeighboringCellInfoListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListNearbyInfo cellListNearbyInfo )
```

**描述**


获取相邻小区信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellListNearbyInfo | 表示附近的小区信息列表，详见[CellListNearbyInfo](_cell_list_nearby_info_v11.md)。 | 


### GetNetworkSearchInformationResponse()

```
IRilCallback::GetNetworkSearchInformationResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct AvailableNetworkList availableNetworkList )
```

**描述**


获取可用网络信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| availableNetworkList | 表示可用网络列表，详见[AvailableNetworkList](_available_network_list_v11.md)。 | 


### GetNetworkSelectionModeResponse()

```
IRilCallback::GetNetworkSelectionModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SetNetworkModeInfo setNetworkModeInfo )
```

**描述**


获取选网模式响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| setNetworkModeInfo | 表示可选择的网络模式，详见[SetNetworkModeInfo](_set_network_mode_info_v11.md)。 | 


### GetNrOptionModeResponse()

```
IRilCallback::GetNrOptionModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int mode )
```

**描述**


获取NR选项模式响应。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| mode | 表示NR选项模式。 | 


### GetOperatorInfoResponse()

```
IRilCallback::GetOperatorInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct OperatorInfo psRegStatusInfo )
```

**描述**


获取运营商名称信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| psRegStatusInfo | 表示运营商信息，详见[OperatorInfo](_operator_info_v11.md)。 | 


### GetPdpContextListResponse()

```
IRilCallback::GetPdpContextListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataCallResultList dataCallResultList )
```

**描述**


获取当前所有数据连接状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| dataCallResultList | 表示数据业务激活结果列表，详见[DataCallResultList](_data_call_result_list_v11.md)。 | 


### GetPhysicalChannelConfigResponse()

```
IRilCallback::GetPhysicalChannelConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct ChannelConfigInfoList channelConfigInfoList )
```

**描述**


获取物理通道配置响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| channelConfigInfoList | 表示物理通道配置信息列表，详见[ChannelConfigInfoList](_channel_config_info_list_v11.md)。 | 


### GetPreferredNetworkResponse()

```
IRilCallback::GetPreferredNetworkResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct PreferredNetworkTypeInfo preferredNetworkTypeInfo )
```

**描述**


获取首选网络类型响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| preferredNetworkTypeInfo | 表示首选网络类型信息，详见[PreferredNetworkTypeInfo](_preferred_network_type_info_v11.md)。 | 


### GetPsRegStatusResponse()

```
IRilCallback::GetPsRegStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct PsRegStatusInfo psRegStatusInfo )
```

**描述**


获取分组(PS)域注册状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| psRegStatusInfo | 表示PS注册状态信息，详见[PsRegStatusInfo](_ps_reg_status_info_v11.md)。 | 


### GetRadioProtocolResponse()

```
IRilCallback::GetRadioProtocolResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```

**描述**


获取主副卡协议栈响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [RadioProtocol](_radio_protocol_v11.md) | 表示获取到的Radio协议，详见[RadioProtocol](_radio_protocol_v11.md)。 | 


### GetRadioStateResponse()

```
IRilCallback::GetRadioStateResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```

**描述**


查询Modem状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### GetRrcConnectionStateResponse()

```
IRilCallback::GetRrcConnectionStateResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```

**描述**


获取RRC连接状态响应。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| state | 表示RRC连接状态。 | 


### GetRrcConnectionStateUpdated()

```
IRilCallback::GetRrcConnectionStateUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```

**描述**


RRC连接状态更新上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| state | 表示RRC连接状态。 | 


### GetSignalStrengthResponse()

```
IRilCallback::GetSignalStrengthResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct Rssi rssi )
```

**描述**


获取信号强度响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| rssi | 表示信号强度，详见[Rssi](_rssi_v11.md)。 | 


### GetSimIOResponse()

```
IRilCallback::GetSimIOResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```

**描述**


获取SIM卡数据响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| result | 表示SIM卡IO响应结果信息，详见[IccIoResultInfo](_icc_io_result_info_v11.md)。 | 


### GetSimLockStatusResponse()

```
IRilCallback::GetSimLockStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int simLockStatus )
```

**描述**


获取SIM卡锁状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| simLockStatus | 表示SIM卡锁状态。 | 


### GetSimStatusResponse()

```
IRilCallback::GetSimStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CardStatusInfo result )
```

**描述**


获取SIM卡状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [CardStatusInfo](_card_status_info_v11.md) | 表示卡状态信息，详见[CardStatusInfo](_card_status_info_v11.md)。 | 


### GetSmscAddrResponse()

```
IRilCallback::GetSmscAddrResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct ServiceCenterAddress serviceCenterAddress )
```

**描述**


获取短信中心地址响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| serviceCenterAddress | 表示短信中心地址信息，详见[ServiceCenterAddress](_service_center_address_v11.md)。 | 


### GetUssdResponse()

```
IRilCallback::GetUssdResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int cusd )
```

**描述**


查询USSD业务响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cusd | 表示USSD业务信息。 | 


### GetVoiceRadioTechnologyResponse()

```
IRilCallback::GetVoiceRadioTechnologyResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct VoiceRadioTechnology voiceRadioTechnology )
```

**描述**


获取电路域接入技术响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [VoiceRadioTechnology](_voice_radio_technology_v11.md) | 表示语音接入技术，详见[VoiceRadioTechnology](_voice_radio_technology_v11.md)。 | 


### HangupResponse()

```
IRilCallback::HangupResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


挂断电话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### HoldCallResponse()

```
IRilCallback::HoldCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


保持通话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### NetworkCsRegStatusUpdated()

```
IRilCallback::NetworkCsRegStatusUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct CsRegStatusInfo csRegStatusInfo )
```

**描述**


CS域网络注册状态变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| csRegStatusInfo | 表示CS注册状态信息，详见[CsRegStatusInfo](_cs_reg_status_info_v11.md)。 | 


### NetworkCurrentCellUpdated()

```
IRilCallback::NetworkCurrentCellUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo cellListCurrentInfo )
```

**描述**


小区信息上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellListCurrentInfo | 表示当前小区信息，详见[CellListCurrentInfo](_cell_list_current_info_v11.md)。 | 


### NetworkCurrentCellUpdated_1_1()

```
IRilCallback::NetworkCurrentCellUpdated_1_1 ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo_1_1 cellListCurrentInfo )
```

**描述**


小区信息上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| cellListCurrentInfo | 表示当前小区信息，详见[CellListCurrentInfo_1_1](_cell_list_current_info__1__1_v11.md). | 


### NetworkPhyChnlCfgUpdated()

```
IRilCallback::NetworkPhyChnlCfgUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct ChannelConfigInfoList channelConfigInfoList )
```

**描述**


物理通道配置消息上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| channelConfigInfoList | 表示通道配置信息列表，详见[ChannelConfigInfoList](_channel_config_info_list_v11.md)。 | 


### NetworkPsRegStatusUpdated()

```
IRilCallback::NetworkPsRegStatusUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct PsRegStatusInfo psRegStatusInfo )
```

**描述**


PS域网络注册状态变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| psRegStatusInfo | 表示PS注册状态信息，详见[PsRegStatusInfo](_ps_reg_status_info_v11.md)。 | 


### NetworkTimeUpdated()

```
IRilCallback::NetworkTimeUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] String timeStr )
```

**描述**


NITZ时间更新上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| timeStr | 表示时间。 | 


### NetworkTimeZoneUpdated()

```
IRilCallback::NetworkTimeZoneUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] String timeZoneStr )
```

**描述**


NITZ时区变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| timeZoneStr | 表示时区。 | 


### NewCdmaSmsNotify()

```
IRilCallback::NewCdmaSmsNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```

**描述**


CDMA新短信通知上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info_v11.md)。 | 


### NewSmsNotify()

```
IRilCallback::NewSmsNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```

**描述**


GSM新短信通知上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info_v11.md)。 | 


### NewSmsStoredOnSimNotify()

```
IRilCallback::NewSmsStoredOnSimNotify ([in] struct RilRadioResponseInfo responseInfo, [in] int recordNumber, [in] int indicationType )
```

**描述**


收到SIM卡短信上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| recordNumber | 表示SIM卡短信数量。 | 
| indicationType | 表示响应类型。 | 


### PdpContextListUpdated()

```
IRilCallback::PdpContextListUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataCallResultList dataCallResultList )
```

**描述**


数据业务建立与断开等状态变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| dataCallResultList | 表示数据业务激活结果列表，详见[DataCallResultList](_data_call_result_list_v11.md)。 | 


### RadioStateUpdated()

```
IRilCallback::RadioStateUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```

**描述**


Radio状态上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| state | 表示Radio状态，0表示OFF，1表示ON。 | 


### RejectResponse()

```
IRilCallback::RejectResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


拒接电话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SendCdmaSmsResponse()

```
IRilCallback::SendCdmaSmsResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```

**描述**


发送CDMA短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info_v11.md)。 | 


### SendDtmfResponse()

```
IRilCallback::SendDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


发送DTMF响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SendGsmSmsResponse()

```
IRilCallback::SendGsmSmsResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```

**描述**


发送GSM短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info_v11.md)。 | 


### SendSmsAckResponse()

```
IRilCallback::SendSmsAckResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


确认接收新短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SendSmsMoreModeResponse()

```
IRilCallback::SendSmsMoreModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```

**描述**


发送GSM长短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info_v11.md)。 | 


### SeparateConferenceResponse()

```
IRilCallback::SeparateConferenceResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


与会议电话分离响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetActiveSimResponse()

```
IRilCallback::SetActiveSimResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


激活去激活SIM卡响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetBarringPasswordResponse()

```
IRilCallback::SetBarringPasswordResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置呼叫限制密码响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCallPreferenceModeResponse()

```
IRilCallback::SetCallPreferenceModeResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置通话偏好模式响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCallRestrictionResponse()

```
IRilCallback::SetCallRestrictionResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置呼叫限制响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCallTransferInfoResponse()

```
IRilCallback::SetCallTransferInfoResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置呼叫转移响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCallWaitingResponse()

```
IRilCallback::SetCallWaitingResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置呼叫等待响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCBConfigResponse()

```
IRilCallback::SetCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


激活GSM小区广播响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetCdmaCBConfigResponse()

```
IRilCallback::SetCdmaCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


激活CDMA小区广播响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetClipResponse()

```
IRilCallback::SetClipResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置主叫号码显示响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetClirResponse()

```
IRilCallback::SetClirResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置主叫号码显示限制响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetDataPermittedResponse()

```
IRilCallback::SetDataPermittedResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


使能SIM卡槽数据业务响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetDeviceStateResponse()

```
IRilCallback::SetDeviceStateResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置设备状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetEmergencyCallListResponse()

```
IRilCallback::SetEmergencyCallListResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置紧急呼叫号码列表响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetInitApnInfoResponse()

```
IRilCallback::SetInitApnInfoResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置初始化默认网络接入技术(APN)信息响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetLinkBandwidthReportingRuleResponse()

```
IRilCallback::SetLinkBandwidthReportingRuleResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置当前链路信息的上报规则响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetLocateUpdatesResponse()

```
IRilCallback::SetLocateUpdatesResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


开启或关闭小区位置更新导致的网络状态通知响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetMuteResponse()

```
IRilCallback::SetMuteResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置静音响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetNetworkSelectionModeResponse()

```
IRilCallback::SetNetworkSelectionModeResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置选网模式响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetNotificationFilterResponse()

```
IRilCallback::SetNotificationFilterResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置通知过滤器响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetNrOptionModeResponse()

```
IRilCallback::SetNrOptionModeResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置NR选项模式响应。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetPreferredNetworkResponse()

```
IRilCallback::SetPreferredNetworkResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置首选网络类型响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetRadioProtocolResponse()

```
IRilCallback::SetRadioProtocolResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```

**描述**


设置主副卡协议栈响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [RadioProtocol](_radio_protocol_v11.md) | 表示获取到的响应Radio协议，详见[RadioProtocol](_radio_protocol_v11.md)。 | 


### SetRadioStateResponse()

```
IRilCallback::SetRadioStateResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置Modem状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetSimLockResponse()

```
IRilCallback::SetSimLockResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


设置SIM卡锁响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### SetSmscAddrResponse()

```
IRilCallback::SetSmscAddrResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置短信中心地址响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetUssdResponse()

```
IRilCallback::SetUssdResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置USSD业务响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SetVonrSwitchResponse()

```
IRilCallback::SetVonrSwitchResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


设置Vonr开关的响应。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### ShutDownResponse()

```
IRilCallback::ShutDownResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


Modem收到手机正在关机响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SignalStrengthUpdated()

```
IRilCallback::SignalStrengthUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct Rssi rssi )
```

**描述**


信号强度变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| rssi | 表示信号强度，详见[Rssi](_rssi_v11.md)。 | 


### SimAuthenticationResponse()

```
IRilCallback::SimAuthenticationResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```

**描述**


SIM卡鉴权响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| result | 表示SIM卡鉴权的结果信息，详见[IccIoResultInfo](_icc_io_result_info_v11.md)。 | 


### SimCloseLogicalChannelResponse()

```
IRilCallback::SimCloseLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


APDU关闭逻辑通道响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimOpenLogicalChannelResponse()

```
IRilCallback::SimOpenLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct OpenLogicalChannelResponse pOpenLogicalChannelResponse )
```

**描述**


APDU打开逻辑通道响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [OpenLogicalChannelResponse](_open_logical_channel_response_v11.md) | 表示打开逻辑通道的响应信息，详见[OpenLogicalChannelResponse](_open_logical_channel_response_v11.md)。 | 


### SimRadioProtocolUpdated()

```
IRilCallback::SimRadioProtocolUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```

**描述**


STK Radio协议更新上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimRefreshNotify()

```
IRilCallback::SimRefreshNotify ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


SIM状态刷新上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStateUpdated()

```
IRilCallback::SimStateUpdated ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


SIM卡状态变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkAlphaNotify()

```
IRilCallback::SimStkAlphaNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```

**描述**


STK Alpha指令上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkCallSetupNotify()

```
IRilCallback::SimStkCallSetupNotify ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


STK CallSetup指令上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkEventNotify()

```
IRilCallback::SimStkEventNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```

**描述**


STK事件上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkIsReadyResponse()

```
IRilCallback::SimStkIsReadyResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


获取STK是否Ready状态响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkProactiveNotify()

```
IRilCallback::SimStkProactiveNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```

**描述**


STK Proactive指令上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkSendCallSetupRequestResultResponse()

```
IRilCallback::SimStkSendCallSetupRequestResultResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


发送STK CallSetup指令响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkSendEnvelopeResponse()

```
IRilCallback::SimStkSendEnvelopeResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


发送STK Envelope指令响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkSendTerminalResponseResponse()

```
IRilCallback::SimStkSendTerminalResponseResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


发送STK TerminalResponse指令响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimStkSessionEndNotify()

```
IRilCallback::SimStkSessionEndNotify ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


STK SessionEnd指令上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SimTransmitApduBasicChannelResponse()

```
IRilCallback::SimTransmitApduBasicChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```

**描述**


APDU基础通道数据传输响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| result | 表示数据传输结果信息，详见[IccIoResultInfo](_icc_io_result_info_v11.md)。 | 


### SimTransmitApduLogicalChannelResponse()

```
IRilCallback::SimTransmitApduLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```

**描述**


APDU逻辑通道数据传输响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| result | 表示数据传输结果信息，详见[IccIoResultInfo](_icc_io_result_info_v11.md)。 | 


### SmsStatusReportNotify()

```
IRilCallback::SmsStatusReportNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```

**描述**


新短信状态通知上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info_v11.md)。 | 


### StartDtmfResponse()

```
IRilCallback::StartDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


开启DTMF响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### StopDtmfResponse()

```
IRilCallback::StopDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


关闭DTMF响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### SwitchCallResponse()

```
IRilCallback::SwitchCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


切换通话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### UnHoldCallResponse()

```
IRilCallback::UnHoldCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


取消保持通话响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### UnlockPin2Response()

```
IRilCallback::UnlockPin2Response ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


PIN2解锁响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### UnlockPinResponse()

```
IRilCallback::UnlockPinResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


PIN解锁响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### UnlockPuk2Response()

```
IRilCallback::UnlockPuk2Response ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


PUK2解锁响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### UnlockPukResponse()

```
IRilCallback::UnlockPukResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


PUK解锁响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### UnlockSimLockResponse()

```
IRilCallback::UnlockSimLockResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```

**描述**


解锁SIM卡响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| [LockStatusResp](_lock_status_resp_v11.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp_v11.md)。 | 


### UpdateCdmaSimMessageResponse()

```
IRilCallback::UpdateCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


更新CDMA SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### UpdateSimMessageResponse()

```
IRilCallback::UpdateSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```

**描述**


更新GSM SIM卡短信响应。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 


### VoiceRadioTechUpdated()

```
IRilCallback::VoiceRadioTechUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct VoiceRadioTechnology voiceRadioTechnology )
```

**描述**


语音接入技术变化上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info_v11.md)。 | 
| voiceRadioTechnology | 表示变化后的电路域接入技术，详见[VoiceRadioTechnology](_voice_radio_technology_v11.md)。 | 
