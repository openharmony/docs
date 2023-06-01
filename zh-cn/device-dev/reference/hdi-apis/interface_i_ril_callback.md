# IRilCallback


## 概述

Ril模块的回调接口。

回调接口提供打电话、发短彩信、激活SIM卡、上网等回调函数，回调函数由调用者实现。

**Since:**
3.2
**Version:**
1.0
**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [CallEmergencyNotice](#callemergencynotice)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[EmergencyInfoList](_emergency_info_list.md)&nbsp;emergencyInfoList) | 紧急呼叫号码上报。&nbsp; | 
| [CallStateUpdated](#callstateupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 通话状态更新上报。&nbsp; | 
| [CallRingbackVoiceNotice](#callringbackvoicenotice)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[RingbackVoice](_ringback_voice.md)&nbsp;ringbackVoice) | 通话回铃音上报。&nbsp; | 
| [CallSrvccStatusNotice](#callsrvccstatusnotice)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SrvccStatus](_srvcc_status.md)&nbsp;srvccStatus) | SRVCC（Single&nbsp;Radio&nbsp;Voice&nbsp;Call&nbsp;Continuity）状态上报。&nbsp; | 
| [CallUssdNotice](#callussdnotice)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[UssdNoticeInfo](_ussd_notice_info.md)&nbsp;ussdNoticeInfo) | USSD业务信息上报。&nbsp; | 
| [CallSsNotice](#callssnotice)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SsNoticeInfo](_ss_notice_info.md)&nbsp;ssNoticeInfo) | 补充业务信息上报。&nbsp; | 
| [CallRsrvccStatusNotify](#callrsrvccstatusnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | RSRVCC（Reverse&nbsp;Single&nbsp;Radio&nbsp;Voice&nbsp;Call&nbsp;Continuity）状态上报。&nbsp; | 
| [SetEmergencyCallListResponse](#setemergencycalllistresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置紧急呼叫号码列表响应。&nbsp; | 
| [GetEmergencyCallListResponse](#getemergencycalllistresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[EmergencyInfoList](_emergency_info_list.md)&nbsp;emergencyInfoList) | 查询紧急呼叫号码列表响应。&nbsp; | 
| [GetCallListResponse](#getcalllistresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CallInfoList](_call_info_list.md)&nbsp;callList) | 查询通话状态列表响应。&nbsp; | 
| [DialResponse](#dialresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 拨打电话响应。&nbsp; | 
| [HangupResponse](#hangupresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 挂断电话响应。&nbsp; | 
| [RejectResponse](#rejectresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 拒接电话响应。&nbsp; | 
| [AnswerResponse](#answerresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 接听电话响应。&nbsp; | 
| [HoldCallResponse](#holdcallresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 保持通话响应。&nbsp; | 
| [UnHoldCallResponse](#unholdcallresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 取消保持通话响应。&nbsp; | 
| [SwitchCallResponse](#switchcallresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 切换通话响应。&nbsp; | 
| [GetClipResponse](#getclipresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[GetClipResult](_get_clip_result.md)&nbsp;getClipResult) | 查询主叫号码显示响应。&nbsp; | 
| [SetClipResponse](#setclipresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置主叫号码显示响应。&nbsp; | 
| [CombineConferenceResponse](#combineconferenceresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 合并为会议电话响应。&nbsp; | 
| [SeparateConferenceResponse](#separateconferenceresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 与会议电话分离响应。&nbsp; | 
| [CallSupplementResponse](#callsupplementresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 挂断前台、恢复后台响应。&nbsp; | 
| [GetCallWaitingResponse](#getcallwaitingresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CallWaitResult](_call_wait_result.md)&nbsp;callWaitResult) | 查询呼叫等待响应。&nbsp; | 
| [SetCallWaitingResponse](#setcallwaitingresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置呼叫等待响应。&nbsp; | 
| [GetCallTransferInfoResponse](#getcalltransferinforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CallForwardQueryInfoList](_call_forward_query_info_list.md)&nbsp;cFQueryList) | 查询呼叫转移响应。&nbsp; | 
| [SetCallTransferInfoResponse](#setcalltransferinforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置呼叫转移响应。&nbsp; | 
| [GetCallRestrictionResponse](#getcallrestrictionresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CallRestrictionResult](_call_restriction_result.md)&nbsp;result) | 查询呼叫限制响应。&nbsp; | 
| [SetCallRestrictionResponse](#setcallrestrictionresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置呼叫限制响应。&nbsp; | 
| [GetClirResponse](#getclirresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[GetClirResult](_get_clir_result.md)&nbsp;getClirResult) | 查询主叫号码显示限制响应。&nbsp; | 
| [SetClirResponse](#setclirresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置主叫号码显示限制响应。&nbsp; | 
| [StartDtmfResponse](#startdtmfresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 开启DTMF响应。&nbsp; | 
| [SendDtmfResponse](#senddtmfresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 发送DTMF响应。&nbsp; | 
| [StopDtmfResponse](#stopdtmfresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 关闭DTMF响应。&nbsp; | 
| [GetCallPreferenceModeResponse](#getcallpreferencemoderesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;mode) | 查询通话偏好模式响应。&nbsp; | 
| [SetCallPreferenceModeResponse](#setcallpreferencemoderesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置通话偏好模式响应。&nbsp; | 
| [SetUssdResponse](#setussdresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置USSD业务响应。&nbsp; | 
| [GetUssdResponse](#getussdresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;cusd) | 查询USSD业务响应。&nbsp; | 
| [SetMuteResponse](#setmuteresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置静音响应。&nbsp; | 
| [GetMuteResponse](#getmuteresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;mute) | 查询静音响应。&nbsp; | 
| [GetCallFailReasonResponse](#getcallfailreasonresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;callFail) | 查询通话失败原因响应。&nbsp; | 
| [SetBarringPasswordResponse](#setbarringpasswordresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置呼叫限制密码响应。&nbsp; | 
| [PdpContextListUpdated](#pdpcontextlistupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[DataCallResultList](_data_call_result_list.md)&nbsp;dataCallResultList) | 数据业务建立与断开等状态变化上报。&nbsp; | 
| [ActivatePdpContextResponse](#activatepdpcontextresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SetupDataCallResultInfo](_setup_data_call_result_info.md)&nbsp;setupDataCallResultInfo) | 激活数据业务响应。&nbsp; | 
| [DeactivatePdpContextResponse](#deactivatepdpcontextresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 断开数据业务响应。&nbsp; | 
| [GetPdpContextListResponse](#getpdpcontextlistresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[DataCallResultList](_data_call_result_list.md)&nbsp;dataCallResultList) | 获取当前所有数据连接状态响应。&nbsp; | 
| [SetInitApnInfoResponse](#setinitapninforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置初始化默认网络接入技术(APN)信息响应。&nbsp; | 
| [GetLinkBandwidthInfoResponse](#getlinkbandwidthinforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[DataLinkBandwidthInfo](_data_link_bandwidth_info.md)&nbsp;dataLinkBandwidthInfo) | 获取当前链路信息响应。&nbsp; | 
| [SetLinkBandwidthReportingRuleResponse](#setlinkbandwidthreportingruleresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置当前链路信息的上报规则响应。&nbsp; | 
| [SetDataPermittedResponse](#setdatapermittedresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 使能SIM卡槽数据业务响应。&nbsp; | 
| [RadioStateUpdated](#radiostateupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;state) | Radio状态上报。&nbsp; | 
| [VoiceRadioTechUpdated](#voiceradiotechupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[VoiceRadioTechnology](_voice_radio_technology.md)&nbsp;voiceRadioTechnology) | 语音接入技术变化上报。&nbsp; | 
| [ShutDownResponse](#shutdownresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | Modem收到手机正在关机响应。&nbsp; | 
| [SetRadioStateResponse](#setradiostateresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置Modem状态响应。&nbsp; | 
| [GetRadioStateResponse](#getradiostateresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,[in]&nbsp;int&nbsp;state) | 查询Modem状态响应。&nbsp; | 
| [GetImeiResponse](#getimeiresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;imei) | 获取国际移动设备识别码响应。&nbsp; | 
| [GetMeidResponse](#getmeidresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;meid) | 获取移动设备识别码响应。&nbsp; | 
| [GetVoiceRadioTechnologyResponse](#getvoiceradiotechnologyresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[VoiceRadioTechnology](_voice_radio_technology.md)&nbsp;voiceRadioTechnology) | 获取电路域接入技术响应。&nbsp; | 
| [GetBasebandVersionResponse](#getbasebandversionresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;basebandVersion) | 查询基带版本响应。&nbsp; | 
| [SimStateUpdated](#simstateupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | SIM卡状态变化上报。&nbsp; | 
| [SimStkSessionEndNotify](#simstksessionendnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | STK&nbsp;SessionEnd指令上报。&nbsp; | 
| [SimStkProactiveNotify](#simstkproactivenotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;response) | STK&nbsp;Proactive指令上报。&nbsp; | 
| [SimStkAlphaNotify](#simstkalphanotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;response) | STK&nbsp;Alpha指令上报。&nbsp; | 
| [SimStkEventNotify](#simstkeventnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;response) | STK事件上报。&nbsp; | 
| [SimStkCallSetupNotify](#simstkcallsetupnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | STK&nbsp;CallSetup指令上报。&nbsp; | 
| [SimRefreshNotify](#simrefreshnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | SIM状态刷新上报。&nbsp; | 
| [SimRadioProtocolUpdated](#simradioprotocolupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[RadioProtocol](_radio_protocol.md)&nbsp;radioProtocol) | STK&nbsp;Radio协议更新上报。&nbsp; | 
| [GetSimIOResponse](#getsimioresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[IccIoResultInfo](_icc_io_result_info.md)&nbsp;result) | 获取SIM卡数据响应。&nbsp; | 
| [GetSimStatusResponse](#getsimstatusresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CardStatusInfo](_card_status_info.md)&nbsp;result) | 获取SIM卡状态响应。&nbsp; | 
| [GetImsiResponse](#getimsiresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;response) | 获取SIM卡IMSI响应。&nbsp; | 
| [GetSimLockStatusResponse](#getsimlockstatusresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;simLockStatus) | 获取SIM卡锁状态响应。&nbsp; | 
| [SetSimLockResponse](#setsimlockresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | 设置SIM卡锁响应。&nbsp; | 
| [ChangeSimPasswordResponse](#changesimpasswordresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | 修改SIM卡密码响应。&nbsp; | 
| [UnlockPinResponse](#unlockpinresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | PIN解锁响应。&nbsp; | 
| [UnlockPukResponse](#unlockpukresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | PUK解锁响应。&nbsp; | 
| [UnlockPin2Response](#unlockpin2response)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | PIN2解锁响应。&nbsp; | 
| [UnlockPuk2Response](#unlockpuk2response)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | PUK2解锁响应。&nbsp; | 
| [SetActiveSimResponse](#setactivesimresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 激活去激活SIM卡响应。&nbsp; | 
| [SimStkSendTerminalResponseResponse](#simstksendterminalresponseresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 发送STK&nbsp;TerminalResponse指令响应。&nbsp; | 
| [SimStkSendEnvelopeResponse](#simstksendenveloperesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 发送STK&nbsp;Envelope指令响应。&nbsp; | 
| [SimStkSendCallSetupRequestResultResponse](#simstksendcallsetuprequestresultresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 发送STK&nbsp;CallSetup指令响应。&nbsp; | 
| [SimStkIsReadyResponse](#simstkisreadyresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 获取STK是否Ready状态响应。&nbsp; | 
| [GetRadioProtocolResponse](#getradioprotocolresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,[in]&nbsp;struct&nbsp;[RadioProtocol](_radio_protocol.md)&nbsp;radioProtocol) | 获取主副卡协议栈响应。&nbsp; | 
| [SetRadioProtocolResponse](#setradioprotocolresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,[in]&nbsp;struct&nbsp;[RadioProtocol](_radio_protocol.md)&nbsp;radioProtocol) | 设置主副卡协议栈响应。&nbsp; | 
| [SimOpenLogicalChannelResponse](#simopenlogicalchannelresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[OpenLogicalChannelResponse](_open_logical_channel_response.md)&nbsp;pOpenLogicalChannelResponse) | APDU打开逻辑通道响应。&nbsp; | 
| [SimCloseLogicalChannelResponse](#simcloselogicalchannelresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | APDU关闭逻辑通道响应。&nbsp; | 
| [SimTransmitApduLogicalChannelResponse](#simtransmitapdulogicalchannelresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[IccIoResultInfo](_icc_io_result_info.md)&nbsp;result) | APDU逻辑通道数据传输响应。&nbsp; | 
| [SimTransmitApduBasicChannelResponse](#simtransmitapdubasicchannelresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[IccIoResultInfo](_icc_io_result_info.md)&nbsp;result) | APDU基础通道数据传输响应。&nbsp; | 
| [SimAuthenticationResponse](#simauthenticationresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[IccIoResultInfo](_icc_io_result_info.md)&nbsp;result) | SIM卡鉴权响应。&nbsp; | 
| [UnlockSimLockResponse](#unlocksimlockresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[LockStatusResp](_lock_status_resp.md)&nbsp;lockStatus) | 解锁SIM卡响应。&nbsp; | 
| [NetworkCsRegStatusUpdated](#networkcsregstatusupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CsRegStatusInfo](_cs_reg_status_info.md)&nbsp;csRegStatusInfo) | CS域网络注册状态变化上报。&nbsp; | 
| [NetworkPsRegStatusUpdated](#networkpsregstatusupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[PsRegStatusInfo](_ps_reg_status_info.md)&nbsp;psRegStatusInfo) | PS域网络注册状态变化上报。&nbsp; | 
| [SignalStrengthUpdated](#signalstrengthupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[Rssi](_rssi.md)&nbsp;rssi) | 信号强度变化上报。&nbsp; | 
| [NetworkTimeZoneUpdated](#networktimezoneupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;timeZoneStr) | NITZ时区变化上报。&nbsp; | 
| [NetworkTimeUpdated](#networktimeupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;String&nbsp;timeStr) | NITZ时间更新上报。&nbsp; | 
| [NetworkPhyChnlCfgUpdated](#networkphychnlcfgupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[ChannelConfigInfoList](_channel_config_info_list.md)&nbsp;channelConfigInfoList) | 物理通道配置消息上报。&nbsp; | 
| [NetworkCurrentCellUpdated](#networkcurrentcellupdated)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CellListCurrentInfo](_cell_list_current_info.md)&nbsp;cellListCurrentInfo) | 小区信息上报。&nbsp; | 
| [GetSignalStrengthResponse](#getsignalstrengthresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[Rssi](_rssi.md)&nbsp;rssi) | 获取信号强度响应。&nbsp; | 
| [GetCsRegStatusResponse](#getcsregstatusresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CsRegStatusInfo](_cs_reg_status_info.md)&nbsp;csRegStatusInfo) | 获取语音(CS)域注册状态响应。&nbsp; | 
| [GetPsRegStatusResponse](#getpsregstatusresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[PsRegStatusInfo](_ps_reg_status_info.md)&nbsp;psRegStatusInfo) | 获取分组(PS)域注册状态响应。&nbsp; | 
| [GetOperatorInfoResponse](#getoperatorinforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[OperatorInfo](_operator_info.md)&nbsp;psRegStatusInfo) | 获取运营商名称信息响应。&nbsp; | 
| [GetNetworkSearchInformationResponse](#getnetworksearchinformationresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[AvailableNetworkList](_available_network_list.md)&nbsp;availableNetworkList) | 获取可用网络信息响应。&nbsp; | 
| [GetNetworkSelectionModeResponse](#getnetworkselectionmoderesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SetNetworkModeInfo](_set_network_mode_info.md)&nbsp;setNetworkModeInfo) | 获取选网模式响应。&nbsp; | 
| [SetNetworkSelectionModeResponse](#setnetworkselectionmoderesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置选网模式响应。&nbsp; | 
| [GetNeighboringCellInfoListResponse](#getneighboringcellinfolistresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CellListNearbyInfo](_cell_list_nearby_info.md)&nbsp;cellListNearbyInfo) | 获取相邻小区信息响应。&nbsp; | 
| [GetCurrentCellInfoResponse](#getcurrentcellinforesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CellListCurrentInfo](_cell_list_current_info.md)&nbsp;cellListCurrentInfo) | 获取小区信息响应。&nbsp; | 
| [SetPreferredNetworkResponse](#setpreferrednetworkresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置首选网络类型响应。&nbsp; | 
| [GetPreferredNetworkResponse](#getpreferrednetworkresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[PreferredNetworkTypeInfo](_preferred_network_type_info.md)&nbsp;preferredNetworkTypeInfo) | 获取首选网络类型响应。&nbsp; | 
| [GetPhysicalChannelConfigResponse](#getphysicalchannelconfigresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[ChannelConfigInfoList](_channel_config_info_list.md)&nbsp;channelConfigInfoList) | 获取物理通道配置响应。&nbsp; | 
| [SetLocateUpdatesResponse](#setlocateupdatesresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 开启或关闭小区位置更新导致的网络状态通知响应。&nbsp; | 
| [SetNotificationFilterResponse](#setnotificationfilterresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置通知过滤器响应。&nbsp; | 
| [SetDeviceStateResponse](#setdevicestateresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置设备状态响应。&nbsp; | 
| [NewSmsNotify](#newsmsnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageInfo](_sms_message_info.md)&nbsp;smsMessageInfo) | GSM新短信通知上报。&nbsp; | 
| [NewCdmaSmsNotify](#newcdmasmsnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,[in]&nbsp;struct&nbsp;[SmsMessageInfo](_sms_message_info.md)&nbsp;smsMessageInfo) | CDMA新短信通知上报。&nbsp; | 
| [SmsStatusReportNotify](#smsstatusreportnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageInfo](_sms_message_info.md)&nbsp;smsMessageInfo) | 新短信状态通知上报。&nbsp; | 
| [NewSmsStoredOnSimNotify](#newsmsstoredonsimnotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;int&nbsp;recordNumber,&nbsp;[in]&nbsp;int&nbsp;indicationType) | 收到SIM卡短信上报。&nbsp; | 
| [CBConfigNotify](#cbconfignotify)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CBConfigReportInfo](_c_b_config_report_info.md)&nbsp;cellBroadConfigReportInfo) | 小区广播配置上报。&nbsp; | 
| [SendGsmSmsResponse](#sendgsmsmsresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SendSmsResultInfo](_send_sms_result_info.md)&nbsp;sendSmsResultInfo) | 发送GSM短信响应。&nbsp; | 
| [SendCdmaSmsResponse](#sendcdmasmsresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SendSmsResultInfo](_send_sms_result_info.md)&nbsp;sendSmsResultInfo) | 发送CDMA短信响应。&nbsp; | 
| [AddSimMessageResponse](#addsimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 写入GSM&nbsp;SIM卡短信响应。&nbsp; | 
| [DelSimMessageResponse](#delsimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 删除GSM&nbsp;SIM卡短信响应。&nbsp; | 
| [UpdateSimMessageResponse](#updatesimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 更新GSM&nbsp;SIM卡短信响应。&nbsp; | 
| [AddCdmaSimMessageResponse](#addcdmasimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 写入CDMA&nbsp;SIM卡短信响应。&nbsp; | 
| [DelCdmaSimMessageResponse](#delcdmasimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 删除CDMA&nbsp;SIM卡短信响应。&nbsp; | 
| [UpdateCdmaSimMessageResponse](#updatecdmasimmessageresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 更新CDMA&nbsp;SIM卡短信响应。&nbsp; | 
| [SetSmscAddrResponse](#setsmscaddrresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 设置短信中心地址响应。&nbsp; | 
| [GetSmscAddrResponse](#getsmscaddrresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[ServiceCenterAddress](_service_center_address.md)&nbsp;serviceCenterAddress) | 获取短信中心地址响应。&nbsp; | 
| [SetCBConfigResponse](#setcbconfigresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 激活GSM小区广播响应。&nbsp; | 
| [GetCBConfigResponse](#getcbconfigresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CBConfigInfo](_c_b_config_info.md)&nbsp;cellBroadcastInfo) | 获取GSM小区广播配置响应。&nbsp; | 
| [SetCdmaCBConfigResponse](#setcdmacbconfigresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 激活CDMA小区广播响应。&nbsp; | 
| [GetCdmaCBConfigResponse](#getcdmacbconfigresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[CdmaCBConfigInfo](_cdma_c_b_config_info.md)&nbsp;cdmaCBConfigInfo) | 获取CDMA小区广播配置响应。&nbsp; | 
| [SendSmsMoreModeResponse](#sendsmsmoremoderesponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo,&nbsp;[in]&nbsp;struct&nbsp;[SendSmsResultInfo](_send_sms_result_info.md)&nbsp;sendSmsResultInfo) | 发送GSM长短信响应。&nbsp; | 
| [SendSmsAckResponse](#sendsmsackresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 确认接收新短信响应。&nbsp; | 
| [CommonErrorResponse](#commonerrorresponse)&nbsp;([in]&nbsp;struct&nbsp;[RilRadioResponseInfo](_ril_radio_response_info.md)&nbsp;responseInfo) | 通用错误响应。&nbsp; | 


## 成员函数说明


### ActivatePdpContextResponse()

  
```
IRilCallback::ActivatePdpContextResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SetupDataCallResultInfo setupDataCallResultInfo )
```
**描述:**
激活数据业务响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| setupDataCallResultInfo | 表示数据业务激活结果信息，详见[SetupDataCallResultInfo](_setup_data_call_result_info.md)。 | 


### AddCdmaSimMessageResponse()

  
```
IRilCallback::AddCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
写入CDMA SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### AddSimMessageResponse()

  
```
IRilCallback::AddSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
写入GSM SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### AnswerResponse()

  
```
IRilCallback::AnswerResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
接听电话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### CallEmergencyNotice()

  
```
IRilCallback::CallEmergencyNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct EmergencyInfoList emergencyInfoList )
```
**描述:**
紧急呼叫号码上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list.md)。 | 


### CallRingbackVoiceNotice()

  
```
IRilCallback::CallRingbackVoiceNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct RingbackVoice ringbackVoice )
```
**描述:**
通话回铃音上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| ringbackVoice | 表示回铃音信息，详见[RingbackVoice](_ringback_voice.md)。 | 


### CallRsrvccStatusNotify()

  
```
IRilCallback::CallRsrvccStatusNotify ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
RSRVCC（Reverse Single Radio Voice Call Continuity）状态上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### CallSrvccStatusNotice()

  
```
IRilCallback::CallSrvccStatusNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct SrvccStatus srvccStatus )
```
**描述:**
SRVCC（Single Radio Voice Call Continuity）状态上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| srvccStatus | 表示SRVCC（Single&nbsp;Radio&nbsp;Voice&nbsp;Call&nbsp;Continuity）状态，详见[SrvccStatus](_srvcc_status.md)。 | 


### CallSsNotice()

  
```
IRilCallback::CallSsNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct SsNoticeInfo ssNoticeInfo )
```
**描述:**
补充业务信息上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| ssNoticeInfo | 表示补充业务信息，详见[SsNoticeInfo](_ss_notice_info.md)。 | 


### CallStateUpdated()

  
```
IRilCallback::CallStateUpdated ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
通话状态更新上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### CallSupplementResponse()

  
```
IRilCallback::CallSupplementResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
挂断前台、恢复后台响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### CallUssdNotice()

  
```
IRilCallback::CallUssdNotice ([in] struct RilRadioResponseInfo responseInfo, [in] struct UssdNoticeInfo ussdNoticeInfo )
```
**描述:**
USSD业务信息上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| ussdNoticeInfo | 表示USSD业务信息，详见[UssdNoticeInfo](_ussd_notice_info.md)。 | 


### CBConfigNotify()

  
```
IRilCallback::CBConfigNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct CBConfigReportInfo cellBroadConfigReportInfo )
```
**描述:**
小区广播配置上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cellBroadConfigReportInfo | 表示小区广播上报信息，详见[CBConfigReportInfo](_c_b_config_report_info.md)。 | 


### ChangeSimPasswordResponse()

  
```
IRilCallback::ChangeSimPasswordResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
修改SIM卡密码响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### CombineConferenceResponse()

  
```
IRilCallback::CombineConferenceResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
合并为会议电话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### CommonErrorResponse()

  
```
IRilCallback::CommonErrorResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
通用错误响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### DeactivatePdpContextResponse()

  
```
IRilCallback::DeactivatePdpContextResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
断开数据业务响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### DelCdmaSimMessageResponse()

  
```
IRilCallback::DelCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
删除CDMA SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### DelSimMessageResponse()

  
```
IRilCallback::DelSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
删除GSM SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### DialResponse()

  
```
IRilCallback::DialResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
拨打电话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### GetBasebandVersionResponse()

  
```
IRilCallback::GetBasebandVersionResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String basebandVersion )
```
**描述:**
查询基带版本响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| basebandVersion | 表示基带版本。 | 


### GetCallFailReasonResponse()

  
```
IRilCallback::GetCallFailReasonResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int callFail )
```
**描述:**
查询通话失败原因响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| callFail | 表示通话失败原因。 | 


### GetCallListResponse()

  
```
IRilCallback::GetCallListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallInfoList callList )
```
**描述:**
查询通话状态列表响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| callList | 表示通话状态信息列表，详见[CallInfoList](_call_info_list.md)。 | 


### GetCallPreferenceModeResponse()

  
```
IRilCallback::GetCallPreferenceModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int mode )
```
**描述:**
查询通话偏好模式响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| mode | 表示CallPreference模式。 | 


### GetCallRestrictionResponse()

  
```
IRilCallback::GetCallRestrictionResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallRestrictionResult result )
```
**描述:**
查询呼叫限制响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| result | 表示呼叫限制结果信息，详见[CallRestrictionResult](_call_restriction_result.md)。 | 


### GetCallTransferInfoResponse()

  
```
IRilCallback::GetCallTransferInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallForwardQueryInfoList cFQueryList )
```
**描述:**
查询呼叫转移响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cFQueryList | 表示呼叫转移信息列表，详见[CallForwardQueryInfoList](_call_forward_query_info_list.md)。 | 


### GetCallWaitingResponse()

  
```
IRilCallback::GetCallWaitingResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CallWaitResult callWaitResult )
```
**描述:**
查询呼叫等待响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| callWaitResult | 表示呼叫等待结果信息，详见[CallWaitResult](_call_wait_result.md)。 | 


### GetCBConfigResponse()

  
```
IRilCallback::GetCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CBConfigInfo cellBroadcastInfo )
```
**描述:**
获取GSM小区广播配置响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cellBroadcastInfo | 表示GSM小区广播配置信息，详见[CBConfigInfo](_c_b_config_info.md)。 | 


### GetCdmaCBConfigResponse()

  
```
IRilCallback::GetCdmaCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CdmaCBConfigInfo cdmaCBConfigInfo )
```
**描述:**
获取CDMA小区广播配置响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cdmaCBConfigInfo | 表示CDMA小区广播配置信息，详见[CdmaCBConfigInfo](_cdma_c_b_config_info.md)。 | 


### GetClipResponse()

  
```
IRilCallback::GetClipResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct GetClipResult getClipResult )
```
**描述:**
查询主叫号码显示响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| getClipResult | 表示主叫号码显示结果信息，详见[GetClipResult](_get_clip_result.md)。 | 


### GetClirResponse()

  
```
IRilCallback::GetClirResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct GetClirResult getClirResult )
```
**描述:**
查询主叫号码显示限制响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| getClirResult | 表示主叫号码显示限制结果信息，详见[GetClirResult](_get_clir_result.md)。 | 


### GetCsRegStatusResponse()

  
```
IRilCallback::GetCsRegStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CsRegStatusInfo csRegStatusInfo )
```
**描述:**
获取语音(CS)域注册状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| csRegStatusInfo | 表示CS注册状态信息，详见[CsRegStatusInfo](_cs_reg_status_info.md)。 | 


### GetCurrentCellInfoResponse()

  
```
IRilCallback::GetCurrentCellInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo cellListCurrentInfo )
```
**描述:**
获取小区信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cellListCurrentInfo | 表示附近的小区信息列表，详见[CellListCurrentInfo](_cell_list_current_info.md)。 | 


### GetEmergencyCallListResponse()

  
```
IRilCallback::GetEmergencyCallListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct EmergencyInfoList emergencyInfoList )
```
**描述:**
查询紧急呼叫号码列表响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list.md)。 | 


### GetImeiResponse()

  
```
IRilCallback::GetImeiResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String imei )
```
**描述:**
获取国际移动设备识别码响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| imei | 表示IMEI。 | 


### GetImsiResponse()

  
```
IRilCallback::GetImsiResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```
**描述:**
获取SIM卡IMSI响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| response | 表示获取到的IMSI文本。 | 


### GetLinkBandwidthInfoResponse()

  
```
IRilCallback::GetLinkBandwidthInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataLinkBandwidthInfo dataLinkBandwidthInfo )
```
**描述:**
获取当前链路信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| dataLinkBandwidthInfo | 表示网络频率信息，详见[DataLinkBandwidthInfo](_data_link_bandwidth_info.md)。 | 


### GetMeidResponse()

  
```
IRilCallback::GetMeidResponse ([in] struct RilRadioResponseInfo responseInfo, [in] String meid )
```
**描述:**
获取移动设备识别码响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| meid | 表示MEID。 | 


### GetMuteResponse()

  
```
IRilCallback::GetMuteResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int mute )
```
**描述:**
查询静音响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| mute | 表示静音状态，0表示非静音，1表示静音。 | 


### GetNeighboringCellInfoListResponse()

  
```
IRilCallback::GetNeighboringCellInfoListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListNearbyInfo cellListNearbyInfo )
```
**描述:**
获取相邻小区信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cellListNearbyInfo | 表示附近的小区信息列表，详见[CellListNearbyInfo](_cell_list_nearby_info.md)。 | 


### GetNetworkSearchInformationResponse()

  
```
IRilCallback::GetNetworkSearchInformationResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct AvailableNetworkList availableNetworkList )
```
**描述:**
获取可用网络信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| availableNetworkList | 表示可用网络列表，详见[AvailableNetworkList](_available_network_list.md)。 | 


### GetNetworkSelectionModeResponse()

  
```
IRilCallback::GetNetworkSelectionModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SetNetworkModeInfo setNetworkModeInfo )
```
**描述:**
获取选网模式响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| setNetworkModeInfo | 表示可选择的网络模式，详见[SetNetworkModeInfo](_set_network_mode_info.md)。 | 


### GetOperatorInfoResponse()

  
```
IRilCallback::GetOperatorInfoResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct OperatorInfo psRegStatusInfo )
```
**描述:**
获取运营商名称信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| psRegStatusInfo | 表示运营商信息，详见[OperatorInfo](_operator_info.md)。 | 


### GetPdpContextListResponse()

  
```
IRilCallback::GetPdpContextListResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataCallResultList dataCallResultList )
```
**描述:**
获取当前所有数据连接状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| dataCallResultList | 表示数据业务激活结果列表，详见[DataCallResultList](_data_call_result_list.md)。 | 


### GetPhysicalChannelConfigResponse()

  
```
IRilCallback::GetPhysicalChannelConfigResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct ChannelConfigInfoList channelConfigInfoList )
```
**描述:**
获取物理通道配置响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| channelConfigInfoList | 表示物理通道配置信息列表，详见[ChannelConfigInfoList](_channel_config_info_list.md)。 | 


### GetPreferredNetworkResponse()

  
```
IRilCallback::GetPreferredNetworkResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct PreferredNetworkTypeInfo preferredNetworkTypeInfo )
```
**描述:**
获取首选网络类型响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| preferredNetworkTypeInfo | 表示首选网络类型信息，详见[PreferredNetworkTypeInfo](_preferred_network_type_info.md)。 | 


### GetPsRegStatusResponse()

  
```
IRilCallback::GetPsRegStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct PsRegStatusInfo psRegStatusInfo )
```
**描述:**
获取分组(PS)域注册状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| psRegStatusInfo | 表示PS注册状态信息，详见[PsRegStatusInfo](_ps_reg_status_info.md)。 | 


### GetRadioProtocolResponse()

  
```
IRilCallback::GetRadioProtocolResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```
**描述:**
获取主副卡协议栈响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [RadioProtocol](_radio_protocol.md) | 表示获取到的Radio协议，详见[RadioProtocol](_radio_protocol.md)。 | 


### GetRadioStateResponse()

  
```
IRilCallback::GetRadioStateResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```
**描述:**
查询Modem状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### GetSignalStrengthResponse()

  
```
IRilCallback::GetSignalStrengthResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct Rssi rssi )
```
**描述:**
获取信号强度响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| rssi | 表示信号强度，详见[Rssi](_rssi.md)。 | 


### GetSimIOResponse()

  
```
IRilCallback::GetSimIOResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```
**描述:**
获取SIM卡数据响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| result | 表示SIM卡IO响应结果信息，详见[IccIoResultInfo](_icc_io_result_info.md)。 | 


### GetSimLockStatusResponse()

  
```
IRilCallback::GetSimLockStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int simLockStatus )
```
**描述:**
获取SIM卡锁状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| simLockStatus | 表示SIM卡锁状态，详见**simLockStatus**。 | 


### GetSimStatusResponse()

  
```
IRilCallback::GetSimStatusResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct CardStatusInfo result )
```
**描述:**
获取SIM卡状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [CardStatusInfo](_card_status_info.md) | 表示卡状态信息，详见[CardStatusInfo](_card_status_info.md)。 | 


### GetSmscAddrResponse()

  
```
IRilCallback::GetSmscAddrResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct ServiceCenterAddress serviceCenterAddress )
```
**描述:**
获取短信中心地址响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 
| serviceCenterAddress | 表示短信中心地址信息，详见[ServiceCenterAddress](_service_center_address.md)。&nbsp; | 


### GetUssdResponse()

  
```
IRilCallback::GetUssdResponse ([in] struct RilRadioResponseInfo responseInfo, [in] int cusd )
```
**描述:**
查询USSD业务响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cusd | 表示USSD业务信息。 | 


### GetVoiceRadioTechnologyResponse()

  
```
IRilCallback::GetVoiceRadioTechnologyResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct VoiceRadioTechnology voiceRadioTechnology )
```
**描述:**
获取电路域接入技术响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [VoiceRadioTechnology](_voice_radio_technology.md) | 表示语音接入技术，详见[VoiceRadioTechnology](_voice_radio_technology.md)。 | 


### HangupResponse()

  
```
IRilCallback::HangupResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
挂断电话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### HoldCallResponse()

  
```
IRilCallback::HoldCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
保持通话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### NetworkCsRegStatusUpdated()

  
```
IRilCallback::NetworkCsRegStatusUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct CsRegStatusInfo csRegStatusInfo )
```
**描述:**
CS域网络注册状态变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| csRegStatusInfo | 表示CS注册状态信息，详见[CsRegStatusInfo](_cs_reg_status_info.md)。 | 


### NetworkCurrentCellUpdated()

  
```
IRilCallback::NetworkCurrentCellUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct CellListCurrentInfo cellListCurrentInfo )
```
**描述:**
小区信息上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| cellListCurrentInfo | 表示当前小区信息，详见[CellListCurrentInfo](_cell_list_current_info.md)。 | 


### NetworkPhyChnlCfgUpdated()

  
```
IRilCallback::NetworkPhyChnlCfgUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct ChannelConfigInfoList channelConfigInfoList )
```
**描述:**
物理通道配置消息上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| channelConfigInfoList | 表示通道配置信息列表，详见[ChannelConfigInfoList](_channel_config_info_list.md)。 | 


### NetworkPsRegStatusUpdated()

  
```
IRilCallback::NetworkPsRegStatusUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct PsRegStatusInfo psRegStatusInfo )
```
**描述:**
PS域网络注册状态变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| psRegStatusInfo | 表示PS注册状态信息，详见[PsRegStatusInfo](_ps_reg_status_info.md)。 | 


### NetworkTimeUpdated()

  
```
IRilCallback::NetworkTimeUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] String timeStr )
```
**描述:**
NITZ时间更新上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| timeStr | 表示时间。 | 


### NetworkTimeZoneUpdated()

  
```
IRilCallback::NetworkTimeZoneUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] String timeZoneStr )
```
**描述:**
NITZ时区变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| timeZoneStr | 表示时区。 | 


### NewCdmaSmsNotify()

  
```
IRilCallback::NewCdmaSmsNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```
**描述:**
CDMA新短信通知上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info.md)。 | 


### NewSmsNotify()

  
```
IRilCallback::NewSmsNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```
**描述:**
GSM新短信通知上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info.md)。 | 


### NewSmsStoredOnSimNotify()

  
```
IRilCallback::NewSmsStoredOnSimNotify ([in] struct RilRadioResponseInfo responseInfo, [in] int recordNumber, [in] int indicationType )
```
**描述:**
收到SIM卡短信上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| recordNumber | 表示SIM卡短信数量。&nbsp; | 
| indicationType | 表示响应类型，详见**HRilNotiType**。 | 


### PdpContextListUpdated()

  
```
IRilCallback::PdpContextListUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct DataCallResultList dataCallResultList )
```
**描述:**
数据业务建立与断开等状态变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| dataCallResultList | 表示数据业务激活结果列表，详见[DataCallResultList](_data_call_result_list.md)。 | 


### RadioStateUpdated()

  
```
IRilCallback::RadioStateUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] int state )
```
**描述:**
Radio状态上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| state | 表示Radio状态，0表示OFF，1表示ON。 | 


### RejectResponse()

  
```
IRilCallback::RejectResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
拒接电话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SendCdmaSmsResponse()

  
```
IRilCallback::SendCdmaSmsResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```
**描述:**
发送CDMA短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info.md)。 | 


### SendDtmfResponse()

  
```
IRilCallback::SendDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
发送DTMF响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SendGsmSmsResponse()

  
```
IRilCallback::SendGsmSmsResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```
**描述:**
发送GSM短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info.md)。 | 


### SendSmsAckResponse()

  
```
IRilCallback::SendSmsAckResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
确认接收新短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SendSmsMoreModeResponse()

  
```
IRilCallback::SendSmsMoreModeResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct SendSmsResultInfo sendSmsResultInfo )
```
**描述:**
发送GSM长短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| sendSmsResultInfo | 表示发送短信响应信息，详见[SendSmsResultInfo](_send_sms_result_info.md)。 | 


### SeparateConferenceResponse()

  
```
IRilCallback::SeparateConferenceResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
与会议电话分离响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetActiveSimResponse()

  
```
IRilCallback::SetActiveSimResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
激活去激活SIM卡响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetBarringPasswordResponse()

  
```
IRilCallback::SetBarringPasswordResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置呼叫限制密码响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCallPreferenceModeResponse()

  
```
IRilCallback::SetCallPreferenceModeResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置通话偏好模式响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCallRestrictionResponse()

  
```
IRilCallback::SetCallRestrictionResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置呼叫限制响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCallTransferInfoResponse()

  
```
IRilCallback::SetCallTransferInfoResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置呼叫转移响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCallWaitingResponse()

  
```
IRilCallback::SetCallWaitingResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置呼叫等待响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCBConfigResponse()

  
```
IRilCallback::SetCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
激活GSM小区广播响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetCdmaCBConfigResponse()

  
```
IRilCallback::SetCdmaCBConfigResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
激活CDMA小区广播响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetClipResponse()

  
```
IRilCallback::SetClipResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置主叫号码显示响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetClirResponse()

  
```
IRilCallback::SetClirResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置主叫号码显示限制响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetDataPermittedResponse()

  
```
IRilCallback::SetDataPermittedResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
使能SIM卡槽数据业务响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetDeviceStateResponse()

  
```
IRilCallback::SetDeviceStateResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置设备状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetEmergencyCallListResponse()

  
```
IRilCallback::SetEmergencyCallListResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置紧急呼叫号码列表响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetInitApnInfoResponse()

  
```
IRilCallback::SetInitApnInfoResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置初始化默认网络接入技术(APN)信息响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetLinkBandwidthReportingRuleResponse()

  
```
IRilCallback::SetLinkBandwidthReportingRuleResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置当前链路信息的上报规则响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetLocateUpdatesResponse()

  
```
IRilCallback::SetLocateUpdatesResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
开启或关闭小区位置更新导致的网络状态通知响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetMuteResponse()

  
```
IRilCallback::SetMuteResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置静音响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetNetworkSelectionModeResponse()

  
```
IRilCallback::SetNetworkSelectionModeResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置选网模式响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetNotificationFilterResponse()

  
```
IRilCallback::SetNotificationFilterResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置通知过滤器响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetPreferredNetworkResponse()

  
```
IRilCallback::SetPreferredNetworkResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置首选网络类型响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetRadioProtocolResponse()

  
```
IRilCallback::SetRadioProtocolResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```
**描述:**
设置主副卡协议栈响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [RadioProtocol](_radio_protocol.md) | 表示获取到的响应Radio协议，详见[RadioProtocol](_radio_protocol.md)。 | 


### SetRadioStateResponse()

  
```
IRilCallback::SetRadioStateResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置Modem状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetSimLockResponse()

  
```
IRilCallback::SetSimLockResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
设置SIM卡锁响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### SetSmscAddrResponse()

  
```
IRilCallback::SetSmscAddrResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置短信中心地址响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SetUssdResponse()

  
```
IRilCallback::SetUssdResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
设置USSD业务响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### ShutDownResponse()

  
```
IRilCallback::ShutDownResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
Modem收到手机正在关机响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SignalStrengthUpdated()

  
```
IRilCallback::SignalStrengthUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct Rssi rssi )
```
**描述:**
信号强度变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| rssi | 表示信号强度，详见[Rssi](_rssi.md)。 | 


### SimAuthenticationResponse()

  
```
IRilCallback::SimAuthenticationResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```
**描述:**
SIM卡鉴权响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| result | 表示SIM卡鉴权的结果信息，详见[IccIoResultInfo](_icc_io_result_info.md)。 | 


### SimCloseLogicalChannelResponse()

  
```
IRilCallback::SimCloseLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
APDU关闭逻辑通道响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimOpenLogicalChannelResponse()

  
```
IRilCallback::SimOpenLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct OpenLogicalChannelResponse pOpenLogicalChannelResponse )
```
**描述:**
APDU打开逻辑通道响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [OpenLogicalChannelResponse](_open_logical_channel_response.md) | 表示打开逻辑通道的响应信息，详见[OpenLogicalChannelResponse](_open_logical_channel_response.md)。 | 


### SimRadioProtocolUpdated()

  
```
IRilCallback::SimRadioProtocolUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct RadioProtocol radioProtocol )
```
**描述:**
STK Radio协议更新上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimRefreshNotify()

  
```
IRilCallback::SimRefreshNotify ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
SIM状态刷新上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStateUpdated()

  
```
IRilCallback::SimStateUpdated ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
SIM卡状态变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkAlphaNotify()

  
```
IRilCallback::SimStkAlphaNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```
**描述:**
STK Alpha指令上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkCallSetupNotify()

  
```
IRilCallback::SimStkCallSetupNotify ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
STK CallSetup指令上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkEventNotify()

  
```
IRilCallback::SimStkEventNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```
**描述:**
STK事件上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkIsReadyResponse()

  
```
IRilCallback::SimStkIsReadyResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
获取STK是否Ready状态响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkProactiveNotify()

  
```
IRilCallback::SimStkProactiveNotify ([in] struct RilRadioResponseInfo responseInfo, [in] String response )
```
**描述:**
STK Proactive指令上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkSendCallSetupRequestResultResponse()

  
```
IRilCallback::SimStkSendCallSetupRequestResultResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
发送STK CallSetup指令响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkSendEnvelopeResponse()

  
```
IRilCallback::SimStkSendEnvelopeResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
发送STK Envelope指令响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkSendTerminalResponseResponse()

  
```
IRilCallback::SimStkSendTerminalResponseResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
发送STK TerminalResponse指令响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimStkSessionEndNotify()

  
```
IRilCallback::SimStkSessionEndNotify ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
STK SessionEnd指令上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SimTransmitApduBasicChannelResponse()

  
```
IRilCallback::SimTransmitApduBasicChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```
**描述:**
APDU基础通道数据传输响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| result | 表示数据传输结果信息，详见[IccIoResultInfo](_icc_io_result_info.md)。 | 


### SimTransmitApduLogicalChannelResponse()

  
```
IRilCallback::SimTransmitApduLogicalChannelResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct IccIoResultInfo result )
```
**描述:**
APDU逻辑通道数据传输响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| result | 表示数据传输结果信息，详见[IccIoResultInfo](_icc_io_result_info.md)。 | 


### SmsStatusReportNotify()

  
```
IRilCallback::SmsStatusReportNotify ([in] struct RilRadioResponseInfo responseInfo, [in] struct SmsMessageInfo smsMessageInfo )
```
**描述:**
新短信状态通知上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| smsMessageInfo | 表示上报短信信息，详见[SmsMessageInfo](_sms_message_info.md)。 | 


### StartDtmfResponse()

  
```
IRilCallback::StartDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
开启DTMF响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### StopDtmfResponse()

  
```
IRilCallback::StopDtmfResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
关闭DTMF响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### SwitchCallResponse()

  
```
IRilCallback::SwitchCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
切换通话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### UnHoldCallResponse()

  
```
IRilCallback::UnHoldCallResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
取消保持通话响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### UnlockPin2Response()

  
```
IRilCallback::UnlockPin2Response ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
PIN2解锁响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### UnlockPinResponse()

  
```
IRilCallback::UnlockPinResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
PIN解锁响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### UnlockPuk2Response()

  
```
IRilCallback::UnlockPuk2Response ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
PUK2解锁响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### UnlockPukResponse()

  
```
IRilCallback::UnlockPukResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
PUK解锁响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### UnlockSimLockResponse()

  
```
IRilCallback::UnlockSimLockResponse ([in] struct RilRadioResponseInfo responseInfo, [in] struct LockStatusResp lockStatus )
```
**描述:**
解锁SIM卡响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| [LockStatusResp](_lock_status_resp.md) | 表示获取到的SIM卡锁状态响应，详见[LockStatusResp](_lock_status_resp.md)。 | 


### UpdateCdmaSimMessageResponse()

  
```
IRilCallback::UpdateCdmaSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
更新CDMA SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### UpdateSimMessageResponse()

  
```
IRilCallback::UpdateSimMessageResponse ([in] struct RilRadioResponseInfo responseInfo)
```
**描述:**
更新GSM SIM卡短信响应。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。 | 


### VoiceRadioTechUpdated()

  
```
IRilCallback::VoiceRadioTechUpdated ([in] struct RilRadioResponseInfo responseInfo, [in] struct VoiceRadioTechnology voiceRadioTechnology )
```
**描述:**
语音接入技术变化上报。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| responseInfo | 表示通用响应信息，例如卡槽ID，请求序列ID等，详见[RilRadioResponseInfo](_ril_radio_response_info.md)。&nbsp; | 
| voiceRadioTechnology | 表示变化后的电路域接入技术，详见[VoiceRadioTechnology](_voice_radio_technology.md)。 | 
