# IRil


## 概述

Ril模块的请求接口。

请求接口包括打电话、发短信彩信、激活SIM卡、上网等。

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
| [SetCallback](#setcallback)&nbsp;([in]&nbsp;[IRilCallback](interface_i_ril_callback.md)&nbsp;rilCallback) | 设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback.md)。&nbsp; | 
| [SetEmergencyCallList](#setemergencycalllist)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[EmergencyInfoList](_emergency_info_list.md)&nbsp;emergencyInfoList) | 设置紧急呼叫号码。&nbsp; | 
| [GetEmergencyCallList](#getemergencycalllist)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取紧急号码。&nbsp; | 
| [GetCallList](#getcalllist)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取通话状态列表。&nbsp; | 
| [Dial](#dial)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DialInfo](_dial_info.md)&nbsp;dialInfo) | 拨打电话。&nbsp; | 
| [Reject](#reject)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 拒接电话。&nbsp; | 
| [Hangup](#hangup)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;callId) | 挂断电话。&nbsp; | 
| [Answer](#answer)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 接听电话。&nbsp; | 
| [HoldCall](#holdcall)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 保持通话。&nbsp; | 
| [UnHoldCall](#unholdcall)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 取消保持通话。&nbsp; | 
| [SwitchCall](#switchcall)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 切换通话。&nbsp; | 
| [CombineConference](#combineconference)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;callType) | 合并为会议电话。&nbsp; | 
| [SeparateConference](#separateconference)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;callId,&nbsp;[in]&nbsp;int&nbsp;callType) | 与会议电话分离。&nbsp; | 
| [GetCallWaiting](#getcallwaiting)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取呼叫等待。&nbsp; | 
| [SetCallWaiting](#setcallwaiting)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;activate) | 设置呼叫等待。&nbsp; | 
| [GetCallTransferInfo](#getcalltransferinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;reason) | 获取呼叫转移。&nbsp; | 
| [SetCallTransferInfo](#setcalltransferinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[CallForwardSetInfo](_call_forward_set_info.md)&nbsp;callForwardSetInfo) | 设置呼叫转移。&nbsp; | 
| [GetCallRestriction](#getcallrestriction)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;fac) | 获取呼叫限制。&nbsp; | 
| [SetCallRestriction](#setcallrestriction)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[CallRestrictionInfo](_call_restriction_info.md)&nbsp;callRestrictionInfo) | 设置呼叫限制。&nbsp; | 
| [GetClip](#getclip)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取主叫号码显示(CLIP)。&nbsp; | 
| [SetClip](#setclip)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;action) | 设置主叫号码显示。&nbsp; | 
| [GetClir](#getclir)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取主叫号码显示限制(CLIR)。&nbsp; | 
| [SetClir](#setclir)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;action) | 设置主叫号码显示限制。&nbsp; | 
| [SetCallPreferenceMode](#setcallpreferencemode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;mode) | 设置通话偏好模式。&nbsp; | 
| [GetCallPreferenceMode](#getcallpreferencemode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取通话偏好模式。&nbsp; | 
| [SetUssd](#setussd)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;str) | 设置非结构化补充数据业务（USSD）。&nbsp; | 
| [GetUssd](#getussd)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取Ussd业务。&nbsp; | 
| [SetMute](#setmute)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;mute) | 设置静音。&nbsp; | 
| [GetMute](#getmute)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取静音。&nbsp; | 
| [GetCallFailReason](#getcallfailreason)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取通话失败原因。&nbsp; | 
| [CallSupplement](#callsupplement)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;type) | 通话保持和恢复。&nbsp; | 
| [SendDtmf](#senddtmf)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DtmfInfo](_dtmf_info.md)&nbsp;dtmfInfo) | 发送双音多频（DTMF）。&nbsp; | 
| [StartDtmf](#startdtmf)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DtmfInfo](_dtmf_info.md)&nbsp;dtmfInfo) | 开启DTMF。&nbsp; | 
| [StopDtmf](#stopdtmf)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DtmfInfo](_dtmf_info.md)&nbsp;dtmfInfo) | 关闭DTMF。&nbsp; | 
| [SetBarringPassword](#setbarringpassword)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SetBarringInfo](_set_barring_info.md)&nbsp;setBarringInfo) | 设置呼叫限制密码。&nbsp; | 
| [ActivatePdpContext](#activatepdpcontext)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataCallInfo](_data_call_info.md)&nbsp;dataCallInfo) | 激活数据业务。&nbsp; | 
| [DeactivatePdpContext](#deactivatepdpcontext)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[UniInfo](_uni_info.md)&nbsp;uniInfo) | 断开数据业务。&nbsp; | 
| [GetPdpContextList](#getpdpcontextlist)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[UniInfo](_uni_info.md)&nbsp;uniInfo) | 获取当前所有数据连接状态。&nbsp; | 
| [SetInitApnInfo](#setinitapninfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataProfileDataInfo](_data_profile_data_info.md)&nbsp;dataProfileDataInfo) | 设置初始化默认网络接入技术(APN)信息。&nbsp; | 
| [GetLinkBandwidthInfo](#getlinkbandwidthinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;cid) | 获取当前链路信息。&nbsp; | 
| [SetLinkBandwidthReportingRule](#setlinkbandwidthreportingrule)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule.md)&nbsp;dataLinkBandwidthReportingRule) | 设置当前链路信息的上报规则。&nbsp; | 
| [SetDataPermitted](#setdatapermitted)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;dataPermitted) | 使能SIM卡槽数据业务。&nbsp; | 
| [SetDataProfileInfo](#setdataprofileinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataProfilesInfo](_data_profiles_info.md)&nbsp;dataProfilesInfo) | 设置数据业务使用的PDP上下文信息。&nbsp; | 
| [SendDataPerformanceMode](#senddataperformancemode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataPerformanceInfo](_data_performance_info.md)&nbsp;dataPerformanceInfo) | 发送数据业务性能模式。&nbsp; | 
| [SendDataSleepMode](#senddatasleepmode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[DataSleepInfo](_data_sleep_info.md)&nbsp;dataSleepInfo) | 发送数据业务睡眠模式。&nbsp; | 
| [SetRadioState](#setradiostate)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;fun,&nbsp;[in]&nbsp;int&nbsp;rst) | 设置Modem状态。&nbsp; | 
| [GetRadioState](#getradiostate)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取Modem状态。&nbsp; | 
| [GetImei](#getimei)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取国际移动设备识别码。&nbsp; | 
| [GetMeid](#getmeid)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取移动设备识别码。&nbsp; | 
| [GetVoiceRadioTechnology](#getvoiceradiotechnology)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取电路（CS）域接入技术。&nbsp; | 
| [GetBasebandVersion](#getbasebandversion)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取基带版本。&nbsp; | 
| [ShutDown](#shutdown)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 发送手机正在关机状态到Modem。&nbsp; | 
| [GetSimIO](#getsimio)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SimIoRequestInfo](_sim_io_request_info.md)&nbsp;simIO) | 获取SIM卡数据。&nbsp; | 
| [GetSimStatus](#getsimstatus)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取SIM卡状态。&nbsp; | 
| [GetImsi](#getimsi)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取SIM卡国际移动用户识别码。&nbsp; | 
| [GetSimLockStatus](#getsimlockstatus)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SimLockInfo](_sim_lock_info.md)&nbsp;simLockInfo) | 获取SIM卡锁状态。&nbsp; | 
| [SetSimLock](#setsimlock)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SimLockInfo](_sim_lock_info.md)&nbsp;simLockInfo) | 设置SIM卡锁。&nbsp; | 
| [ChangeSimPassword](#changesimpassword)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SimPasswordInfo](_sim_password_info.md)&nbsp;simPassword) | 修改SIM卡密码。&nbsp; | 
| [UnlockPin](#unlockpin)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;pin) | PIN解锁。&nbsp; | 
| [UnlockPuk](#unlockpuk)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;puk,&nbsp;[in]&nbsp;String&nbsp;pin) | PUK解锁。&nbsp; | 
| [UnlockPin2](#unlockpin2)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;pin2) | PIN2解锁。&nbsp; | 
| [UnlockPuk2](#unlockpuk2)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;puk2,&nbsp;[in]&nbsp;String&nbsp;pin2) | PUK2解锁。&nbsp; | 
| [SetActiveSim](#setactivesim)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;index,&nbsp;[in]&nbsp;int&nbsp;enable) | 激活去激活SIM卡。&nbsp; | 
| [SimStkSendTerminalResponse](#simstksendterminalresponse)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;strCmd) | 发送SIM卡应用开发工具箱(STK)&nbsp;TerminalResponse指令。&nbsp; | 
| [SimStkSendEnvelope](#simstksendenvelope)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;strCmd) | 发送STK&nbsp;Envelope指令。&nbsp; | 
| [SimStkSendCallSetupRequestResult](#simstksendcallsetuprequestresult)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;accept) | 发送STK&nbsp;CallSetup指令。&nbsp; | 
| [SimStkIsReady](#simstkisready)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取STK是否Ready状态。&nbsp; | 
| [GetRadioProtocol](#getradioprotocol)&nbsp;([in]&nbsp;int&nbsp;slotId,[in]&nbsp;int&nbsp;serialId) | 获取主副卡协议栈。&nbsp; | 
| [SetRadioProtocol](#setradioprotocol)&nbsp;([in]&nbsp;int&nbsp;slotId,[in]&nbsp;int&nbsp;serialId,[in]&nbsp;struct&nbsp;[RadioProtocol](_radio_protocol.md)&nbsp;radioProtocol) | 设置主副卡协议栈。&nbsp; | 
| [SimOpenLogicalChannel](#simopenlogicalchannel)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;String&nbsp;appID,&nbsp;[in]&nbsp;int&nbsp;p2) | 打开应用协议数据单元（APDU）逻辑通道。&nbsp; | 
| [SimCloseLogicalChannel](#simcloselogicalchannel)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;channelId) | 关闭应用协议数据单元（APDU）逻辑通道。&nbsp; | 
| [SimTransmitApduLogicalChannel](#simtransmitapdulogicalchannel)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[ApduSimIORequestInfo](_apdu_sim_i_o_request_info.md)&nbsp;apduSimIO) | 应用协议数据单元（APDU）逻辑通道数据传输，由应用主动发起连接和关闭。&nbsp; | 
| [SimTransmitApduBasicChannel](#simtransmitapdubasicchannel)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[ApduSimIORequestInfo](_apdu_sim_i_o_request_info.md)&nbsp;apduSimIO) | 应用协议数据单元（APDU）基础通道数据传输，默认打开的传输通道。&nbsp; | 
| [SimAuthentication](#simauthentication)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SimAuthenticationRequestInfo](_sim_authentication_request_info.md)&nbsp;simAuthInfo) | SIM卡鉴权。&nbsp; | 
| [UnlockSimLock](#unlocksimlock)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;lockType,&nbsp;[in]&nbsp;String&nbsp;key) | 解锁SIM卡。&nbsp; | 
| [GetSignalStrength](#getsignalstrength)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取信号强度。&nbsp; | 
| [GetCsRegStatus](#getcsregstatus)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取电路(CS)域注册状态。&nbsp; | 
| [GetPsRegStatus](#getpsregstatus)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取分组(PS)域注册状态。&nbsp; | 
| [GetOperatorInfo](#getoperatorinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取运营商名称信息。&nbsp; | 
| [GetNetworkSearchInformation](#getnetworksearchinformation)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取可用网络信息。&nbsp; | 
| [GetNetworkSelectionMode](#getnetworkselectionmode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取选网模式。&nbsp; | 
| [SetNetworkSelectionMode](#setnetworkselectionmode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SetNetworkModeInfo](_set_network_mode_info.md)&nbsp;networkModeInfo) | 设置选网模式。&nbsp; | 
| [GetNeighboringCellInfoList](#getneighboringcellinfolist)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取相邻小区信息。&nbsp; | 
| [GetCurrentCellInfo](#getcurrentcellinfo)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取小区信息。&nbsp; | 
| [SetPreferredNetwork](#setpreferrednetwork)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;preferredNetworkType) | 设置首选网络类型。&nbsp; | 
| [GetPreferredNetwork](#getpreferrednetwork)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取首选网络类型。&nbsp; | 
| [GetPhysicalChannelConfig](#getphysicalchannelconfig)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取物理通道配置。&nbsp; | 
| [SetLocateUpdates](#setlocateupdates)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;enum&nbsp;[RilRegNotifyMode](_ril.md#rilregnotifymode)&nbsp;mode) | 设置小区位置更新通知模式。&nbsp; | 
| [SetNotificationFilter](#setnotificationfilter)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;newFilter) | 设置Modem主动上报消息过滤器。&nbsp; | 
| [SetDeviceState](#setdevicestate)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;deviceStateType,&nbsp;[in]&nbsp;int&nbsp;deviceStateOn) | 设置设备状态。&nbsp; | 
| [SendGsmSms](#sendgsmsms)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[GsmSmsMessageInfo](_gsm_sms_message_info.md)&nbsp;gsmSmsMessageInfo) | 发送全球移动通信系统&nbsp;(GSM)短信。&nbsp; | 
| [SendCdmaSms](#sendcdmasms)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SendCdmaSmsMessageInfo](_send_cdma_sms_message_info.md)&nbsp;cdmaSmsMessageInfo) | 发送码分多址(CDMA)短信。&nbsp; | 
| [AddSimMessage](#addsimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info.md)&nbsp;gsmSmsMessageInfo) | 写入GSM&nbsp;SIM卡短信。&nbsp; | 
| [DelSimMessage](#delsimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;index) | 删除GSM&nbsp;SIM卡短信。&nbsp; | 
| [UpdateSimMessage](#updatesimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info.md)&nbsp;gsmSmsMessageInfo) | 更新GSM&nbsp;SIM卡短信。&nbsp; | 
| [AddCdmaSimMessage](#addcdmasimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info.md)&nbsp;cdmaSmsMessageInfo) | 写入CDMA&nbsp;SIM卡短信。&nbsp; | 
| [DelCdmaSimMessage](#delcdmasimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;int&nbsp;index) | 删除CDMA&nbsp;SIM卡短信。&nbsp; | 
| [UpdateCdmaSimMessage](#updatecdmasimmessage)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[SmsMessageIOInfo](_sms_message_i_o_info.md)&nbsp;cdmaSmsMessageInfo) | 更新CDMA&nbsp;SIM卡短信。&nbsp; | 
| [SetSmscAddr](#setsmscaddr)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[ServiceCenterAddress](_service_center_address.md)&nbsp;serviceCenterAddress) | 设置短信中心地址。&nbsp; | 
| [GetSmscAddr](#getsmscaddr)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取短信中心地址。&nbsp; | 
| [SetCBConfig](#setcbconfig)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[CBConfigInfo](_c_b_config_info.md)&nbsp;cellBroadcastInfo) | 激活GSM小区广播。&nbsp; | 
| [GetCBConfig](#getcbconfig)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取GSM小区广播配置。&nbsp; | 
| [SetCdmaCBConfig](#setcdmacbconfig)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[CdmaCBConfigInfoList](_cdma_c_b_config_info_list.md)&nbsp;cdmaCBConfigInfoList) | 激活CDMA小区广播。&nbsp; | 
| [GetCdmaCBConfig](#getcdmacbconfig)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId) | 获取CDMA小区广播配置。&nbsp; | 
| [SendSmsMoreMode](#sendsmsmoremode)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[GsmSmsMessageInfo](_gsm_sms_message_info.md)&nbsp;gsmSmsMessageInfo) | 发送GSM长短信。&nbsp; | 
| [SendSmsAck](#sendsmsack)&nbsp;([in]&nbsp;int&nbsp;slotId,&nbsp;[in]&nbsp;int&nbsp;serialId,&nbsp;[in]&nbsp;struct&nbsp;[ModeData](_mode_data.md)&nbsp;modeData) | 确认接收新短信。&nbsp; | 
| [SendRilAck](#sendrilack)&nbsp;() | 发送应答给无线接口层（RIL）。&nbsp; | 


## 成员函数说明


### ActivatePdpContext()

  
```
IRil::ActivatePdpContext ([in] int slotId, [in] int serialId, [in] struct DataCallInfo dataCallInfo )
```
**描述:**
激活数据业务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataCallInfo | 表示数据业务信息，详见[DataCallInfo](_data_call_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### AddCdmaSimMessage()

  
```
IRil::AddCdmaSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo cdmaSmsMessageInfo )
```
**描述:**
写入CDMA SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cdmaSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### AddSimMessage()

  
```
IRil::AddSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo gsmSmsMessageInfo )
```
**描述:**
写入GSM SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| gsmSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### Answer()

  
```
IRil::Answer ([in] int slotId, [in] int serialId )
```
**描述:**
接听电话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### CallSupplement()

  
```
IRil::CallSupplement ([in] int slotId, [in] int serialId, [in] int type )
```
**描述:**
通话保持和恢复。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| type | 表示挂断的通话类型，0表示直接挂断，1表示挂断前台和后台，2表示挂断前台、恢复后台，3表示挂断所有通话。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### ChangeSimPassword()

  
```
IRil::ChangeSimPassword ([in] int slotId, [in] int serialId, [in] struct SimPasswordInfo simPassword )
```
**描述:**
修改SIM卡密码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| simPassword | 表示SIM卡密码信息，详见[SimPasswordInfo](_sim_password_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### CombineConference()

  
```
IRil::CombineConference ([in] int slotId, [in] int serialId, [in] int callType )
```
**描述:**
合并为会议电话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| callType | 表示通话类型，当前只能为0（即语音通话）。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### DeactivatePdpContext()

  
```
IRil::DeactivatePdpContext ([in] int slotId, [in] int serialId, [in] struct UniInfo uniInfo )
```
**描述:**
断开数据业务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| uniInfo | 表示通用信息，详见[UniInfo](_uni_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### DelCdmaSimMessage()

  
```
IRil::DelCdmaSimMessage ([in] int slotId, [in] int serialId, [in] int index )
```
**描述:**
删除CDMA SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| index | 表示消息索引。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### DelSimMessage()

  
```
IRil::DelSimMessage ([in] int slotId, [in] int serialId, [in] int index )
```
**描述:**
删除GSM SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| index | 表示消息索引。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### Dial()

  
```
IRil::Dial ([in] int slotId, [in] int serialId, [in] struct DialInfo dialInfo )
```
**描述:**
拨打电话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dialInfo | 表示拨号信息，详见[DialInfo](_dial_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetBasebandVersion()

  
```
IRil::GetBasebandVersion ([in] int slotId, [in] int serialId )
```
**描述:**
获取基带版本。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallFailReason()

  
```
IRil::GetCallFailReason ([in] int slotId, [in] int serialId )
```
**描述:**
获取通话失败原因。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallList()

  
```
IRil::GetCallList ([in] int slotId, [in] int serialId )
```
**描述:**
获取通话状态列表。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallPreferenceMode()

  
```
IRil::GetCallPreferenceMode ([in] int slotId, [in] int serialId )
```
**描述:**
获取通话偏好模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallRestriction()

  
```
IRil::GetCallRestriction ([in] int slotId, [in] int serialId, [in] String fac )
```
**描述:**
获取呼叫限制。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| fac | 表示呼叫限制操作对象。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallTransferInfo()

  
```
IRil::GetCallTransferInfo ([in] int slotId, [in] int serialId, [in] int reason )
```
**描述:**
获取呼叫转移。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| reason | 表示呼叫转移的类型，0表示无条件转移，1表示用户忙时转移，2表示无回复时转移，3表示无法接通时转移。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCallWaiting()

  
```
IRil::GetCallWaiting ([in] int slotId, [in] int serialId )
```
**描述:**
获取呼叫等待。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCBConfig()

  
```
IRil::GetCBConfig ([in] int slotId, [in] int serialId )
```
**描述:**
获取GSM小区广播配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCdmaCBConfig()

  
```
IRil::GetCdmaCBConfig ([in] int slotId, [in] int serialId )
```
**描述:**
获取CDMA小区广播配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetClip()

  
```
IRil::GetClip ([in] int slotId, [in] int serialId )
```
**描述:**
获取主叫号码显示(CLIP)。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetClir()

  
```
IRil::GetClir ([in] int slotId, [in] int serialId )
```
**描述:**
获取主叫号码显示限制(CLIR)。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCsRegStatus()

  
```
IRil::GetCsRegStatus ([in] int slotId, [in] int serialId )
```
**描述:**
获取电路(CS)域注册状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetCurrentCellInfo()

  
```
IRil::GetCurrentCellInfo ([in] int slotId, [in] int serialId )
```
**描述:**
获取小区信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetEmergencyCallList()

  
```
IRil::GetEmergencyCallList ([in] int slotId, [in] int serialId )
```
**描述:**
获取紧急号码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetImei()

  
```
IRil::GetImei ([in] int slotId, [in] int serialId )
```
**描述:**
获取国际移动设备识别码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetImsi()

  
```
IRil::GetImsi ([in] int slotId, [in] int serialId )
```
**描述:**
获取SIM卡国际移动用户识别码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetLinkBandwidthInfo()

  
```
IRil::GetLinkBandwidthInfo ([in] int slotId, [in] int serialId, [in] int cid )
```
**描述:**
获取当前链路信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cid | PDP上下文标识符。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetMeid()

  
```
IRil::GetMeid ([in] int slotId, [in] int serialId )
```
**描述:**
获取移动设备识别码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetMute()

  
```
IRil::GetMute ([in] int slotId, [in] int serialId )
```
**描述:**
获取静音。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetNeighboringCellInfoList()

  
```
IRil::GetNeighboringCellInfoList ([in] int slotId, [in] int serialId )
```
**描述:**
获取相邻小区信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetNetworkSearchInformation()

  
```
IRil::GetNetworkSearchInformation ([in] int slotId, [in] int serialId )
```
**描述:**
获取可用网络信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetNetworkSelectionMode()

  
```
IRil::GetNetworkSelectionMode ([in] int slotId, [in] int serialId )
```
**描述:**
获取选网模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetOperatorInfo()

  
```
IRil::GetOperatorInfo ([in] int slotId, [in] int serialId )
```
**描述:**
获取运营商名称信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetPdpContextList()

  
```
IRil::GetPdpContextList ([in] int slotId, [in] int serialId, [in] struct UniInfo uniInfo )
```
**描述:**
获取当前所有数据连接状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| uniInfo | 表示通用信息，详见[UniInfo](_uni_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetPhysicalChannelConfig()

  
```
IRil::GetPhysicalChannelConfig ([in] int slotId, [in] int serialId )
```
**描述:**
获取物理通道配置。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetPreferredNetwork()

  
```
IRil::GetPreferredNetwork ([in] int slotId, [in] int serialId )
```
**描述:**
获取首选网络类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetPsRegStatus()

  
```
IRil::GetPsRegStatus ([in] int slotId, [in] int serialId )
```
**描述:**
获取分组(PS)域注册状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetRadioProtocol()

  
```
IRil::GetRadioProtocol ([in] int slotId, [in] int serialId )
```
**描述:**
获取主副卡协议栈。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetRadioState()

  
```
IRil::GetRadioState ([in] int slotId, [in] int serialId )
```
**描述:**
获取Modem状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetSignalStrength()

  
```
IRil::GetSignalStrength ([in] int slotId, [in] int serialId )
```
**描述:**
获取信号强度。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetSimIO()

  
```
IRil::GetSimIO ([in] int slotId, [in] int serialId, [in] struct SimIoRequestInfo simIO )
```
**描述:**
获取SIM卡数据。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| [SimIoRequestInfo](_sim_io_request_info.md) | 表示SIM卡数据请求信息，详见[SimIoRequestInfo](_sim_io_request_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetSimLockStatus()

  
```
IRil::GetSimLockStatus ([in] int slotId, [in] int serialId, [in] struct SimLockInfo simLockInfo )
```
**描述:**
获取SIM卡锁状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| [SimLockInfo](_sim_lock_info.md) | 表示SIM卡锁信息，详见[SimLockInfo](_sim_lock_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetSimStatus()

  
```
IRil::GetSimStatus ([in] int slotId, [in] int serialId )
```
**描述:**
获取SIM卡状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetSmscAddr()

  
```
IRil::GetSmscAddr ([in] int slotId, [in] int serialId )
```
**描述:**
获取短信中心地址。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetUssd()

  
```
IRil::GetUssd ([in] int slotId, [in] int serialId )
```
**描述:**
获取Ussd业务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### GetVoiceRadioTechnology()

  
```
IRil::GetVoiceRadioTechnology ([in] int slotId, [in] int serialId )
```
**描述:**
获取电路（CS）域接入技术。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### Hangup()

  
```
IRil::Hangup ([in] int slotId, [in] int serialId, [in] int callId )
```
**描述:**
挂断电话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| callId | 表示通话ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### HoldCall()

  
```
IRil::HoldCall ([in] int slotId, [in] int serialId )
```
**描述:**
保持通话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### Reject()

  
```
IRil::Reject ([in] int slotId, [in] int serialId )
```
**描述:**
拒接电话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendCdmaSms()

  
```
IRil::SendCdmaSms ([in] int slotId, [in] int serialId, [in] struct SendCdmaSmsMessageInfo cdmaSmsMessageInfo )
```
**描述:**
发送码分多址(CDMA)短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cdmaSmsMessageInfo | 表示CDMA短信信息，详见[SendCdmaSmsMessageInfo](_send_cdma_sms_message_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendDataPerformanceMode()

  
```
IRil::SendDataPerformanceMode ([in] int slotId, [in] int serialId, [in] struct DataPerformanceInfo dataPerformanceInfo )
```
**描述:**
发送数据业务性能模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataPerformanceInfo | 表示数据业务性能模式，详见[DataPerformanceInfo](_data_performance_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendDataSleepMode()

  
```
IRil::SendDataSleepMode ([in] int slotId, [in] int serialId, [in] struct DataSleepInfo dataSleepInfo )
```
**描述:**
发送数据业务睡眠模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataSleepInfo | 表示数据业务睡眠模式，详见[DataSleepInfo](_data_sleep_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendDtmf()

  
```
IRil::SendDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述:**
发送双音多频（DTMF）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendGsmSms()

  
```
IRil::SendGsmSms ([in] int slotId, [in] int serialId, [in] struct GsmSmsMessageInfo gsmSmsMessageInfo )
```
**描述:**
发送全球移动通信系统 (GSM)短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| gsmSmsMessageInfo | 表示GSM短信信息，详见[GsmSmsMessageInfo](_gsm_sms_message_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendRilAck()

  
```
IRil::SendRilAck ()
```
**描述:**
发送应答给无线接口层（RIL）。

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendSmsAck()

  
```
IRil::SendSmsAck ([in] int slotId, [in] int serialId, [in] struct ModeData modeData )
```
**描述:**
确认接收新短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| modeData | 表示接收短信处理模式，详见[ModeData](_mode_data.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SendSmsMoreMode()

  
```
IRil::SendSmsMoreMode ([in] int slotId, [in] int serialId, [in] struct GsmSmsMessageInfo gsmSmsMessageInfo )
```
**描述:**
发送GSM长短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| gsmSmsMessageInfo | 表示GSM短信信息，详见[GsmSmsMessageInfo](_gsm_sms_message_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SeparateConference()

  
```
IRil::SeparateConference ([in] int slotId, [in] int serialId, [in] int callId, [in] int callType )
```
**描述:**
与会议电话分离。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| callId | 表示通话ID。&nbsp; | 
| callType | 表示通话类型，当前只能为0（即语音通话）。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetActiveSim()

  
```
IRil::SetActiveSim ([in] int slotId, [in] int serialId, [in] int index, [in] int enable )
```
**描述:**
激活去激活SIM卡。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| index | 表示索引值。&nbsp; | 
| enable | 表示激活状态，0为去激活，1为激活。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetBarringPassword()

  
```
IRil::SetBarringPassword ([in] int slotId, [in] int serialId, [in] struct SetBarringInfo setBarringInfo )
```
**描述:**
设置呼叫限制密码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| setBarringInfo | 表示设置呼叫限制密码的信息，详见[SetBarringInfo](_set_barring_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCallback()

  
```
IRil::SetCallback ([in] IRilCallback rilCallback)
```
**描述:**
设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback.md)。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| rilCallback | 要设置的回调函数。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCallPreferenceMode()

  
```
IRil::SetCallPreferenceMode ([in] int slotId, [in] int serialId, [in] int mode )
```
**描述:**
设置通话偏好模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| mode | 表示通话偏好模式，1表示仅电路（CS)域通话，2表示电路（CS)域通话优先，3表示IP多媒体系统（IMS）通话优先，4表示仅IP多媒体系统（IMS）通话。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCallRestriction()

  
```
IRil::SetCallRestriction ([in] int slotId, [in] int serialId, [in] struct CallRestrictionInfo callRestrictionInfo )
```
**描述:**
设置呼叫限制。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| callRestrictionInfo | 表示呼叫限制信息，详见[CallRestrictionInfo](_call_restriction_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCallTransferInfo()

  
```
IRil::SetCallTransferInfo ([in] int slotId, [in] int serialId, [in] struct CallForwardSetInfo callForwardSetInfo )
```
**描述:**
设置呼叫转移。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| callForwardSetInfo | 表示呼叫转移信息，详见[CallForwardSetInfo](_call_forward_set_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCallWaiting()

  
```
IRil::SetCallWaiting ([in] int slotId, [in] int serialId, [in] int activate )
```
**描述:**
设置呼叫等待。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| activate | 表示禁止或使能呼叫等待功能，0表示禁止，1表示使能。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCBConfig()

  
```
IRil::SetCBConfig ([in] int slotId, [in] int serialId, [in] struct CBConfigInfo cellBroadcastInfo )
```
**描述:**
激活GSM小区广播。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cellBroadcastInfo | 表示GSM小区广播配置信息，详见[CBConfigInfo](_c_b_config_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetCdmaCBConfig()

  
```
IRil::SetCdmaCBConfig ([in] int slotId, [in] int serialId, [in] struct CdmaCBConfigInfoList cdmaCBConfigInfoList )
```
**描述:**
激活CDMA小区广播。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cdmaCBConfigInfoList | 表示CDMA小区广播配置信息列表，详见[CdmaCBConfigInfoList](_cdma_c_b_config_info_list.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetClip()

  
```
IRil::SetClip ([in] int slotId, [in] int serialId, [in] int action )
```
**描述:**
设置主叫号码显示。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| action | 表示禁止或使能主叫号码显示功能，0表示禁止，1表示使能。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetClir()

  
```
IRil::SetClir ([in] int slotId, [in] int serialId, [in] int action )
```
**描述:**
设置主叫号码显示限制。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| action | 表示禁止或使能主叫号码显示限制功能，0表示禁止，1表示使能。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetDataPermitted()

  
```
IRil::SetDataPermitted ([in] int slotId, [in] int serialId, [in] int dataPermitted )
```
**描述:**
使能SIM卡槽数据业务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataPermitted | 表示是否使能，0表示不使能，1表示使能。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetDataProfileInfo()

  
```
IRil::SetDataProfileInfo ([in] int slotId, [in] int serialId, [in] struct DataProfilesInfo dataProfilesInfo )
```
**描述:**
设置数据业务使用的PDP上下文信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataProfilesInfo | 表示PDP上下文信息列表，详见[DataProfilesInfo](_data_profiles_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetDeviceState()

  
```
IRil::SetDeviceState ([in] int slotId, [in] int serialId, [in] int deviceStateType, [in] int deviceStateOn )
```
**描述:**
设置设备状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| deviceStateType | 表示设备状态类型，0表示省电模式，1表示充电模式，2表示低数据模式。&nbsp; | 
| deviceStateOn | 表示设备状态开关，0表示关闭，1表示开启。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetEmergencyCallList()

  
```
IRil::SetEmergencyCallList ([in] int slotId, [in] int serialId, [in] struct EmergencyInfoList emergencyInfoList )
```
**描述:**
设置紧急呼叫号码。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetInitApnInfo()

  
```
IRil::SetInitApnInfo ([in] int slotId, [in] int serialId, [in] struct DataProfileDataInfo dataProfileDataInfo )
```
**描述:**
设置初始化默认网络接入技术(APN)信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataProfileDataInfo | 表示分组报文协议(PDP)上下文信息，详见[DataProfileDataInfo](_data_profile_data_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetLinkBandwidthReportingRule()

  
```
IRil::SetLinkBandwidthReportingRule ([in] int slotId, [in] int serialId, [in] struct DataLinkBandwidthReportingRule dataLinkBandwidthReportingRule )
```
**描述:**
设置当前链路信息的上报规则。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dataLinkBandwidthReportingRule | 表示网络频率上报规则，详见[DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetLocateUpdates()

  
```
IRil::SetLocateUpdates ([in] int slotId, [in] int serialId, [in] enum RilRegNotifyMode mode )
```
**描述:**
设置小区位置更新通知模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| mode | 表示通知模式，详见[RilRegNotifyMode](_ril.md#rilregnotifymode)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetMute()

  
```
IRil::SetMute ([in] int slotId, [in] int serialId, [in] int mute )
```
**描述:**
设置静音。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| mute | 表示禁止或使能静音，0表示禁止，1表示使能。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetNetworkSelectionMode()

  
```
IRil::SetNetworkSelectionMode ([in] int slotId, [in] int serialId, [in] struct SetNetworkModeInfo networkModeInfo )
```
**描述:**
设置选网模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| networkModeInfo | 表示选网模式信息，详见[SetNetworkModeInfo](_set_network_mode_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetNotificationFilter()

  
```
IRil::SetNotificationFilter ([in] int slotId, [in] int serialId, [in] int newFilter )
```
**描述:**
设置Modem主动上报消息过滤器。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| newFilter | 表示消息类型过滤器，使用二进制标志位表示不同的消息类型，0表示关闭，&nbsp;1表示信号强度，2表示网络注册状态，4表示数据连接状态，8表示链路容量，16表示物理通道配置。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetPreferredNetwork()

  
```
IRil::SetPreferredNetwork ([in] int slotId, [in] int serialId, [in] int preferredNetworkType )
```
**描述:**
设置首选网络类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| preferredNetworkType | 表示首选网络类型，详见[PreferredNetworkTypeInfo](_preferred_network_type_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetRadioProtocol()

  
```
IRil::SetRadioProtocol ([in] int slotId, [in] int serialId, [in] struct RadioProtocol radioProtocol )
```
**描述:**
设置主副卡协议栈。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| radioProtocol | 表示Radio协议信息，详见[RadioProtocol](_radio_protocol.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetRadioState()

  
```
IRil::SetRadioState ([in] int slotId, [in] int serialId, [in] int fun, [in] int rst )
```
**描述:**
设置Modem状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| fun | 表示功能模式，0表示最小模式，1表示online模式，4表示offline模式，其他模式由芯片自定义。&nbsp; | 
| rst | 表示Modem是否自动复位，0表示不复位，1表示复位。 | 

**返回:**

0 表示执行成功

非零值 表示操作失败。


### SetSimLock()

  
```
IRil::SetSimLock ([in] int slotId, [in] int serialId, [in] struct SimLockInfo simLockInfo )
```
**描述:**
设置SIM卡锁。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| [SimLockInfo](_sim_lock_info.md) | 表示SIM卡锁信息，详见[SimLockInfo](_sim_lock_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetSmscAddr()

  
```
IRil::SetSmscAddr ([in] int slotId, [in] int serialId, [in] struct ServiceCenterAddress serviceCenterAddress )
```
**描述:**
设置短信中心地址。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| serviceCenterAddress | 表示短信中心地址信息，详见[ServiceCenterAddress](_service_center_address.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SetUssd()

  
```
IRil::SetUssd ([in] int slotId, [in] int serialId, [in] String str )
```
**描述:**
设置非结构化补充数据业务（USSD）。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| str | 表示USSD信息，最大长度为160个字符。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### ShutDown()

  
```
IRil::ShutDown ([in] int slotId, [in] int serialId )
```
**描述:**
发送手机正在关机状态到Modem。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimAuthentication()

  
```
IRil::SimAuthentication ([in] int slotId, [in] int serialId, [in] struct SimAuthenticationRequestInfo simAuthInfo )
```
**描述:**
SIM卡鉴权。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| simAuthInfo | 表示SIM卡鉴权请求信息，详见[SimAuthenticationRequestInfo](_sim_authentication_request_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimCloseLogicalChannel()

  
```
IRil::SimCloseLogicalChannel ([in] int slotId, [in] int serialId, [in] int channelId )
```
**描述:**
关闭应用协议数据单元（APDU）逻辑通道。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| channelId | 表示请求关闭的逻辑通道ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimOpenLogicalChannel()

  
```
IRil::SimOpenLogicalChannel ([in] int slotId, [in] int serialId, [in] String appID, [in] int p2 )
```
**描述:**
打开应用协议数据单元（APDU）逻辑通道。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| appID | 表示应用标识符。&nbsp; | 
| p2 | 表示AT指令码的参数2。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimStkIsReady()

  
```
IRil::SimStkIsReady ([in] int slotId, [in] int serialId )
```
**描述:**
获取STK是否Ready状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendCallSetupRequestResult()

  
```
IRil::SimStkSendCallSetupRequestResult ([in] int slotId, [in] int serialId, [in] int accept )
```
**描述:**
发送STK CallSetup指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| accept | 表示是否接受CallSetup请求，0为不接受，1为接受。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendEnvelope()

  
```
IRil::SimStkSendEnvelope ([in] int slotId, [in] int serialId, [in] String strCmd )
```
**描述:**
发送STK Envelope指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| strCmd | 表示指令的字串文本。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendTerminalResponse()

  
```
IRil::SimStkSendTerminalResponse ([in] int slotId, [in] int serialId, [in] String strCmd )
```
**描述:**
发送SIM卡应用开发工具箱(STK) TerminalResponse指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| strCmd | 表示指令的字串文本。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimTransmitApduBasicChannel()

  
```
IRil::SimTransmitApduBasicChannel ([in] int slotId, [in] int serialId, [in] struct ApduSimIORequestInfo apduSimIO )
```
**描述:**
应用协议数据单元（APDU）基础通道数据传输，默认打开的传输通道。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| apduSimIO | 表示通过应用协议数据单元（APDU）传输的SIM数据请求信息，详见[ApduSimIORequestInfo](_apdu_sim_i_o_request_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SimTransmitApduLogicalChannel()

  
```
IRil::SimTransmitApduLogicalChannel ([in] int slotId, [in] int serialId, [in] struct ApduSimIORequestInfo apduSimIO )
```
**描述:**
应用协议数据单元（APDU）逻辑通道数据传输，由应用主动发起连接和关闭。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| apduSimIO | 表示通过应用协议数据单元（APDU）传输的SIM数据请求信息，详见[ApduSimIORequestInfo](_apdu_sim_i_o_request_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### StartDtmf()

  
```
IRil::StartDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述:**
开启DTMF。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### StopDtmf()

  
```
IRil::StopDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述:**
关闭DTMF。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### SwitchCall()

  
```
IRil::SwitchCall ([in] int slotId, [in] int serialId )
```
**描述:**
切换通话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnHoldCall()

  
```
IRil::UnHoldCall ([in] int slotId, [in] int serialId )
```
**描述:**
取消保持通话。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPin()

  
```
IRil::UnlockPin ([in] int slotId, [in] int serialId, [in] String pin )
```
**描述:**
PIN解锁。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| pin | 表示用于解锁的PIN码。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPin2()

  
```
IRil::UnlockPin2 ([in] int slotId, [in] int serialId, [in] String pin2 )
```
**描述:**
PIN2解锁。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| pin2 | 表示用于解锁的PIN2码。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPuk()

  
```
IRil::UnlockPuk ([in] int slotId, [in] int serialId, [in] String puk, [in] String pin )
```
**描述:**
PUK解锁。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| puk | 表示用于解锁的PUK码。&nbsp; | 
| pin | 表示用于解锁的PIN码。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPuk2()

  
```
IRil::UnlockPuk2 ([in] int slotId, [in] int serialId, [in] String puk2, [in] String pin2 )
```
**描述:**
PUK2解锁。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| puk2 | 表示用于解锁的PUK2码。&nbsp; | 
| pin2 | 表示用于解锁的PIN2码。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UnlockSimLock()

  
```
IRil::UnlockSimLock ([in] int slotId, [in] int serialId, [in] int lockType, [in] String key )
```
**描述:**
解锁SIM卡。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| lockType | 表示锁类型，参考3GPP&nbsp;TS&nbsp;22.022&nbsp;[33]。&nbsp; | 
| key | 表示用于解锁的密码，参考3GPP&nbsp;TS&nbsp;22.022&nbsp;[33]。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UpdateCdmaSimMessage()

  
```
IRil::UpdateCdmaSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo cdmaSmsMessageInfo )
```
**描述:**
更新CDMA SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| cdmaSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。


### UpdateSimMessage()

  
```
IRil::UpdateSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo gsmSmsMessageInfo )
```
**描述:**
更新GSM SIM卡短信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。&nbsp; | 
| serialId | 表示请求的序列化ID。&nbsp; | 
| gsmSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info.md)。 | 

**返回:**

0 表示执行成功。

非零值 表示操作失败。
