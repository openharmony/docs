# IRil


## 概述

Ril模块的请求接口。

请求接口包括打电话、发短信彩信、激活SIM卡、上网等。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetCallback](#setcallback) ([in] [IRilCallback](interface_i_ril_callback_v10.md) rilCallback) | 设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback_v10.md)。  | 
| [SetEmergencyCallList](#setemergencycalllist) ([in] int slotId, [in] int serialId, [in] struct [EmergencyInfoList](_emergency_info_list_v10.md) emergencyInfoList) | 设置紧急呼叫号码。  | 
| [GetEmergencyCallList](#getemergencycalllist) ([in] int slotId, [in] int serialId) | 获取紧急号码。  | 
| [GetCallList](#getcalllist) ([in] int slotId, [in] int serialId) | 获取通话状态列表。  | 
| [Dial](#dial) ([in] int slotId, [in] int serialId, [in] struct [DialInfo](_dial_info_v10.md) dialInfo) | 拨打电话。  | 
| [Reject](#reject) ([in] int slotId, [in] int serialId) | 拒接电话。  | 
| [Hangup](#hangup) ([in] int slotId, [in] int serialId, [in] int callId) | 挂断电话。  | 
| [Answer](#answer) ([in] int slotId, [in] int serialId) | 接听电话。  | 
| [HoldCall](#holdcall) ([in] int slotId, [in] int serialId) | 保持通话。  | 
| [UnHoldCall](#unholdcall) ([in] int slotId, [in] int serialId) | 取消保持通话。  | 
| [SwitchCall](#switchcall) ([in] int slotId, [in] int serialId) | 切换通话。  | 
| [CombineConference](#combineconference) ([in] int slotId, [in] int serialId, [in] int callType) | 合并为会议电话。  | 
| [SeparateConference](#separateconference) ([in] int slotId, [in] int serialId, [in] int callId, [in] int callType) | 与会议电话分离。  | 
| [GetCallWaiting](#getcallwaiting) ([in] int slotId, [in] int serialId) | 获取呼叫等待。  | 
| [SetCallWaiting](#setcallwaiting) ([in] int slotId, [in] int serialId, [in] int activate) | 设置呼叫等待。  | 
| [GetCallTransferInfo](#getcalltransferinfo) ([in] int slotId, [in] int serialId, [in] int reason) | 获取呼叫转移。  | 
| [SetCallTransferInfo](#setcalltransferinfo) ([in] int slotId, [in] int serialId, [in] struct [CallForwardSetInfo](_call_forward_set_info_v10.md) callForwardSetInfo) | 设置呼叫转移。  | 
| [GetCallRestriction](#getcallrestriction) ([in] int slotId, [in] int serialId, [in] String fac) | 获取呼叫限制。  | 
| [SetCallRestriction](#setcallrestriction) ([in] int slotId, [in] int serialId, [in] struct [CallRestrictionInfo](_call_restriction_info_v10.md) callRestrictionInfo) | 设置呼叫限制。  | 
| [GetClip](#getclip) ([in] int slotId, [in] int serialId) | 获取主叫号码显示(CLIP)。  | 
| [SetClip](#setclip) ([in] int slotId, [in] int serialId, [in] int action) | 设置主叫号码显示。  | 
| [GetClir](#getclir) ([in] int slotId, [in] int serialId) | 获取主叫号码显示限制(CLIR)。  | 
| [SetClir](#setclir) ([in] int slotId, [in] int serialId, [in] int action) | 设置主叫号码显示限制。  | 
| [SetCallPreferenceMode](#setcallpreferencemode) ([in] int slotId, [in] int serialId, [in] int mode) | 设置通话偏好模式。  | 
| [GetCallPreferenceMode](#getcallpreferencemode) ([in] int slotId, [in] int serialId) | 获取通话偏好模式。  | 
| [SetUssd](#setussd) ([in] int slotId, [in] int serialId, [in] String str) | 设置非结构化补充数据业务（USSD）。  | 
| [GetUssd](#getussd) ([in] int slotId, [in] int serialId) | 获取Ussd业务。  | 
| [SetMute](#setmute) ([in] int slotId, [in] int serialId, [in] int mute) | 设置静音。  | 
| [GetMute](#getmute) ([in] int slotId, [in] int serialId) | 获取静音。  | 
| [GetCallFailReason](#getcallfailreason) ([in] int slotId, [in] int serialId) | 获取通话失败原因。  | 
| [CallSupplement](#callsupplement) ([in] int slotId, [in] int serialId, [in] int type) | 通话保持和恢复。  | 
| [SendDtmf](#senddtmf) ([in] int slotId, [in] int serialId, [in] struct [DtmfInfo](_dtmf_info_v10.md) dtmfInfo) | 发送双音多频（DTMF）。  | 
| [StartDtmf](#startdtmf) ([in] int slotId, [in] int serialId, [in] struct [DtmfInfo](_dtmf_info_v10.md) dtmfInfo) | 开启DTMF。  | 
| [StopDtmf](#stopdtmf) ([in] int slotId, [in] int serialId, [in] struct [DtmfInfo](_dtmf_info_v10.md) dtmfInfo) | 关闭DTMF。  | 
| [SetBarringPassword](#setbarringpassword) ([in] int slotId, [in] int serialId, [in] struct [SetBarringInfo](_set_barring_info_v10.md) setBarringInfo) | 设置呼叫限制密码。  | 
| [ActivatePdpContext](#activatepdpcontext) ([in] int slotId, [in] int serialId, [in] struct [DataCallInfo](_data_call_info_v10.md) dataCallInfo) | 激活数据业务。  | 
| [DeactivatePdpContext](#deactivatepdpcontext) ([in] int slotId, [in] int serialId, [in] struct [UniInfo](_uni_info_v10.md) uniInfo) | 断开数据业务。  | 
| [GetPdpContextList](#getpdpcontextlist) ([in] int slotId, [in] int serialId, [in] struct [UniInfo](_uni_info_v10.md) uniInfo) | 获取当前所有数据连接状态。  | 
| [SetInitApnInfo](#setinitapninfo) ([in] int slotId, [in] int serialId, [in] struct [DataProfileDataInfo](_data_profile_data_info_v10.md) dataProfileDataInfo) | 设置初始化默认网络接入技术(APN)信息。  | 
| [GetLinkBandwidthInfo](#getlinkbandwidthinfo) ([in] int slotId, [in] int serialId, [in] int cid) | 获取当前链路信息。  | 
| [SetLinkBandwidthReportingRule](#setlinkbandwidthreportingrule) ([in] int slotId, [in] int serialId, [in] struct [DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule_v10.md) dataLinkBandwidthReportingRule) | 设置当前链路信息的上报规则。  | 
| [SetDataPermitted](#setdatapermitted) ([in] int slotId, [in] int serialId, [in] int dataPermitted) | 使能SIM卡槽数据业务。  | 
| [SetDataProfileInfo](#setdataprofileinfo) ([in] int slotId, [in] int serialId, [in] struct [DataProfilesInfo](_data_profiles_info_v10.md) dataProfilesInfo) | 设置数据业务使用的PDP上下文信息。  | 
| [SendDataPerformanceMode](#senddataperformancemode) ([in] int slotId, [in] int serialId, [in] struct [DataPerformanceInfo](_data_performance_info_v10.md) dataPerformanceInfo) | 发送数据业务性能模式。  | 
| [SendDataSleepMode](#senddatasleepmode) ([in] int slotId, [in] int serialId, [in] struct [DataSleepInfo](_data_sleep_info_v10.md) dataSleepInfo) | 发送数据业务睡眠模式。  | 
| [SetRadioState](#setradiostate) ([in] int slotId, [in] int serialId, [in] int fun, [in] int rst) | 设置Modem状态。  | 
| [GetRadioState](#getradiostate) ([in] int slotId, [in] int serialId) | 获取Modem状态。  | 
| [GetImei](#getimei) ([in] int slotId, [in] int serialId) | 获取国际移动设备识别码。  | 
| [GetMeid](#getmeid) ([in] int slotId, [in] int serialId) | 获取移动设备识别码。  | 
| [GetVoiceRadioTechnology](#getvoiceradiotechnology) ([in] int slotId, [in] int serialId) | 获取电路（CS）域接入技术。  | 
| [GetBasebandVersion](#getbasebandversion) ([in] int slotId, [in] int serialId) | 获取基带版本。  | 
| [ShutDown](#shutdown) ([in] int slotId, [in] int serialId) | 发送手机正在关机状态到Modem。  | 
| [GetSimIO](#getsimio) ([in] int slotId, [in] int serialId, [in] struct [SimIoRequestInfo](_sim_io_request_info_v10.md) simIO) | 获取SIM卡数据。  | 
| [GetSimStatus](#getsimstatus) ([in] int slotId, [in] int serialId) | 获取SIM卡状态。  | 
| [GetImsi](#getimsi) ([in] int slotId, [in] int serialId) | 获取SIM卡国际移动用户识别码。  | 
| [GetSimLockStatus](#getsimlockstatus) ([in] int slotId, [in] int serialId, [in] struct [SimLockInfo](_sim_lock_info_v10.md) simLockInfo) | 获取SIM卡锁状态。  | 
| [SetSimLock](#setsimlock) ([in] int slotId, [in] int serialId, [in] struct [SimLockInfo](_sim_lock_info_v10.md) simLockInfo) | 设置SIM卡锁。  | 
| [ChangeSimPassword](#changesimpassword) ([in] int slotId, [in] int serialId, [in] struct [SimPasswordInfo](_sim_password_info_v10.md) simPassword) | 修改SIM卡密码。  | 
| [UnlockPin](#unlockpin) ([in] int slotId, [in] int serialId, [in] String pin) | PIN解锁。  | 
| [UnlockPuk](#unlockpuk) ([in] int slotId, [in] int serialId, [in] String puk, [in] String pin) | PUK解锁。  | 
| [UnlockPin2](#unlockpin2) ([in] int slotId, [in] int serialId, [in] String pin2) | PIN2解锁。  | 
| [UnlockPuk2](#unlockpuk2) ([in] int slotId, [in] int serialId, [in] String puk2, [in] String pin2) | PUK2解锁。  | 
| [SetActiveSim](#setactivesim) ([in] int slotId, [in] int serialId, [in] int index, [in] int enable) | 激活去激活SIM卡。  | 
| [SimStkSendTerminalResponse](#simstksendterminalresponse) ([in] int slotId, [in] int serialId, [in] String strCmd) | 发送SIM卡应用开发工具箱(STK) TerminalResponse指令。  | 
| [SimStkSendEnvelope](#simstksendenvelope) ([in] int slotId, [in] int serialId, [in] String strCmd) | 发送STK Envelope指令。  | 
| [SimStkSendCallSetupRequestResult](#simstksendcallsetuprequestresult) ([in] int slotId, [in] int serialId, [in] int accept) | 发送STK CallSetup指令。  | 
| [SimStkIsReady](#simstkisready) ([in] int slotId, [in] int serialId) | 获取STK是否Ready状态。  | 
| [GetRadioProtocol](#getradioprotocol) ([in] int slotId,[in] int serialId) | 获取主副卡协议栈。  | 
| [SetRadioProtocol](#setradioprotocol) ([in] int slotId,[in] int serialId,[in] struct [RadioProtocol](_radio_protocol_v10.md) radioProtocol) | 设置主副卡协议栈。  | 
| [SimOpenLogicalChannel](#simopenlogicalchannel) ([in] int slotId, [in] int serialId, [in] String appID, [in] int p2) | 打开应用协议数据单元（APDU）逻辑通道。  | 
| [SimCloseLogicalChannel](#simcloselogicalchannel) ([in] int slotId, [in] int serialId, [in] int channelId) | 关闭应用协议数据单元（APDU）逻辑通道。  | 
| [SimTransmitApduLogicalChannel](#simtransmitapdulogicalchannel) ([in] int slotId, [in] int serialId, [in] struct [ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v10.md) apduSimIO) | 应用协议数据单元（APDU）逻辑通道数据传输，由应用主动发起连接和关闭。  | 
| [SimTransmitApduBasicChannel](#simtransmitapdubasicchannel) ([in] int slotId, [in] int serialId, [in] struct [ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v10.md) apduSimIO) | 应用协议数据单元（APDU）基础通道数据传输，默认打开的传输通道。  | 
| [SimAuthentication](#simauthentication) ([in] int slotId, [in] int serialId, [in] struct [SimAuthenticationRequestInfo](_sim_authentication_request_info_v10.md) simAuthInfo) | SIM卡鉴权。  | 
| [UnlockSimLock](#unlocksimlock) ([in] int slotId, [in] int serialId, [in] int lockType, [in] String key) | 解锁SIM卡。  | 
| [GetSignalStrength](#getsignalstrength) ([in] int slotId, [in] int serialId) | 获取信号强度。  | 
| [GetCsRegStatus](#getcsregstatus) ([in] int slotId, [in] int serialId) | 获取电路(CS)域注册状态。  | 
| [GetPsRegStatus](#getpsregstatus) ([in] int slotId, [in] int serialId) | 获取分组(PS)域注册状态。  | 
| [GetOperatorInfo](#getoperatorinfo) ([in] int slotId, [in] int serialId) | 获取运营商名称信息。  | 
| [GetNetworkSearchInformation](#getnetworksearchinformation) ([in] int slotId, [in] int serialId) | 获取可用网络信息。  | 
| [GetNetworkSelectionMode](#getnetworkselectionmode) ([in] int slotId, [in] int serialId) | 获取选网模式。  | 
| [SetNetworkSelectionMode](#setnetworkselectionmode) ([in] int slotId, [in] int serialId, [in] struct [SetNetworkModeInfo](_set_network_mode_info_v10.md) networkModeInfo) | 设置选网模式。  | 
| [GetNeighboringCellInfoList](#getneighboringcellinfolist) ([in] int slotId, [in] int serialId) | 获取相邻小区信息。  | 
| [GetCurrentCellInfo](#getcurrentcellinfo) ([in] int slotId, [in] int serialId) | 获取小区信息。  | 
| [SetPreferredNetwork](#setpreferrednetwork) ([in] int slotId, [in] int serialId, [in] int preferredNetworkType) | 设置首选网络类型。  | 
| [GetPreferredNetwork](#getpreferrednetwork) ([in] int slotId, [in] int serialId) | 获取首选网络类型。  | 
| [GetPhysicalChannelConfig](#getphysicalchannelconfig) ([in] int slotId, [in] int serialId) | 获取物理通道配置。  | 
| [SetLocateUpdates](#setlocateupdates) ([in] int slotId, [in] int serialId, [in] enum [RilRegNotifyMode](_ril_v10.md#rilregnotifymode) mode) | 设置小区位置更新通知模式。  | 
| [SetNotificationFilter](#setnotificationfilter) ([in] int slotId, [in] int serialId, [in] int newFilter) | 设置Modem主动上报消息过滤器。  | 
| [SetDeviceState](#setdevicestate) ([in] int slotId, [in] int serialId, [in] int deviceStateType, [in] int deviceStateOn) | 设置设备状态。  | 
| [SendGsmSms](#sendgsmsms) ([in] int slotId, [in] int serialId, [in] struct [GsmSmsMessageInfo](_gsm_sms_message_info_v10.md) gsmSmsMessageInfo) | 发送全球移动通信系统 (GSM)短信。  | 
| [SendCdmaSms](#sendcdmasms) ([in] int slotId, [in] int serialId, [in] struct [SendCdmaSmsMessageInfo](_send_cdma_sms_message_info_v10.md) cdmaSmsMessageInfo) | 发送码分多址(CDMA)短信。  | 
| [AddSimMessage](#addsimmessage) ([in] int slotId, [in] int serialId, [in] struct [SmsMessageIOInfo](_sms_message_i_o_info_v10.md) gsmSmsMessageInfo) | 写入GSM SIM卡短信。  | 
| [DelSimMessage](#delsimmessage) ([in] int slotId, [in] int serialId, [in] int index) | 删除GSM SIM卡短信。  | 
| [UpdateSimMessage](#updatesimmessage) ([in] int slotId, [in] int serialId, [in] struct [SmsMessageIOInfo](_sms_message_i_o_info_v10.md) gsmSmsMessageInfo) | 更新GSM SIM卡短信。  | 
| [AddCdmaSimMessage](#addcdmasimmessage) ([in] int slotId, [in] int serialId, [in] struct [SmsMessageIOInfo](_sms_message_i_o_info_v10.md) cdmaSmsMessageInfo) | 写入CDMA SIM卡短信。  | 
| [DelCdmaSimMessage](#delcdmasimmessage) ([in] int slotId, [in] int serialId, [in] int index) | 删除CDMA SIM卡短信。  | 
| [UpdateCdmaSimMessage](#updatecdmasimmessage) ([in] int slotId, [in] int serialId, [in] struct [SmsMessageIOInfo](_sms_message_i_o_info_v10.md) cdmaSmsMessageInfo) | 更新CDMA SIM卡短信。  | 
| [SetSmscAddr](#setsmscaddr) ([in] int slotId, [in] int serialId, [in] struct [ServiceCenterAddress](_service_center_address_v10.md) serviceCenterAddress) | 设置短信中心地址。  | 
| [GetSmscAddr](#getsmscaddr) ([in] int slotId, [in] int serialId) | 获取短信中心地址。  | 
| [SetCBConfig](#setcbconfig) ([in] int slotId, [in] int serialId, [in] struct [CBConfigInfo](_c_b_config_info_v10.md) cellBroadcastInfo) | 激活GSM小区广播。  | 
| [GetCBConfig](#getcbconfig) ([in] int slotId, [in] int serialId) | 获取GSM小区广播配置。  | 
| [SetCdmaCBConfig](#setcdmacbconfig) ([in] int slotId, [in] int serialId, [in] struct [CdmaCBConfigInfoList](_cdma_c_b_config_info_list_v10.md) cdmaCBConfigInfoList) | 激活CDMA小区广播。  | 
| [GetCdmaCBConfig](#getcdmacbconfig) ([in] int slotId, [in] int serialId) | 获取CDMA小区广播配置。  | 
| [SendSmsMoreMode](#sendsmsmoremode) ([in] int slotId, [in] int serialId, [in] struct [GsmSmsMessageInfo](_gsm_sms_message_info_v10.md) gsmSmsMessageInfo) | 发送GSM长短信。  | 
| [SendSmsAck](#sendsmsack) ([in] int slotId, [in] int serialId, [in] struct [ModeData](_mode_data_v10.md) modeData) | 确认接收新短信。  | 
| [SendRilAck](#sendrilack) () | 发送应答给无线接口层（RIL）。  | 


## 成员函数说明


### ActivatePdpContext()

```
IRil::ActivatePdpContext ([in] int slotId, [in] int serialId, [in] struct DataCallInfo dataCallInfo )
```
**描述**

激活数据业务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataCallInfo | 表示数据业务信息，详见[DataCallInfo](_data_call_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### AddCdmaSimMessage()

```
IRil::AddCdmaSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo cdmaSmsMessageInfo )
```
**描述**

写入CDMA SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cdmaSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### AddSimMessage()

```
IRil::AddSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo gsmSmsMessageInfo )
```
**描述**

写入GSM SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| gsmSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### Answer()

```
IRil::Answer ([in] int slotId, [in] int serialId )
```
**描述**

接听电话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### CallSupplement()

```
IRil::CallSupplement ([in] int slotId, [in] int serialId, [in] int type )
```
**描述**

通话保持和恢复。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| type | 表示挂断的通话类型，0表示直接挂断，1表示挂断前台和后台，2表示挂断前台、恢复后台，3表示挂断所有通话。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### ChangeSimPassword()

```
IRil::ChangeSimPassword ([in] int slotId, [in] int serialId, [in] struct SimPasswordInfo simPassword )
```
**描述**

修改SIM卡密码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| simPassword | 表示SIM卡密码信息，详见[SimPasswordInfo](_sim_password_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### CombineConference()

```
IRil::CombineConference ([in] int slotId, [in] int serialId, [in] int callType )
```
**描述**

合并为会议电话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| callType | 表示通话类型，当前只能为0（即语音通话）。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### DeactivatePdpContext()

```
IRil::DeactivatePdpContext ([in] int slotId, [in] int serialId, [in] struct UniInfo uniInfo )
```
**描述**

断开数据业务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| uniInfo | 表示通用信息，详见[UniInfo](_uni_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### DelCdmaSimMessage()

```
IRil::DelCdmaSimMessage ([in] int slotId, [in] int serialId, [in] int index )
```
**描述**

删除CDMA SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| index | 表示消息索引。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### DelSimMessage()

```
IRil::DelSimMessage ([in] int slotId, [in] int serialId, [in] int index )
```
**描述**

删除GSM SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| index | 表示消息索引。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### Dial()

```
IRil::Dial ([in] int slotId, [in] int serialId, [in] struct DialInfo dialInfo )
```
**描述**

拨打电话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dialInfo | 表示拨号信息，详见[DialInfo](_dial_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetBasebandVersion()

```
IRil::GetBasebandVersion ([in] int slotId, [in] int serialId )
```
**描述**

获取基带版本。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallFailReason()

```
IRil::GetCallFailReason ([in] int slotId, [in] int serialId )
```
**描述**

获取通话失败原因。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallList()

```
IRil::GetCallList ([in] int slotId, [in] int serialId )
```
**描述**

获取通话状态列表。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallPreferenceMode()

```
IRil::GetCallPreferenceMode ([in] int slotId, [in] int serialId )
```
**描述**

获取通话偏好模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallRestriction()

```
IRil::GetCallRestriction ([in] int slotId, [in] int serialId, [in] String fac )
```
**描述**

获取呼叫限制。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| fac | 表示呼叫限制操作对象。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallTransferInfo()

```
IRil::GetCallTransferInfo ([in] int slotId, [in] int serialId, [in] int reason )
```
**描述**

获取呼叫转移。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| reason | 表示呼叫转移的类型，0表示无条件转移，1表示用户忙时转移，2表示无回复时转移，3表示无法接通时转移。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCallWaiting()

```
IRil::GetCallWaiting ([in] int slotId, [in] int serialId )
```
**描述**

获取呼叫等待。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCBConfig()

```
IRil::GetCBConfig ([in] int slotId, [in] int serialId )
```
**描述**

获取GSM小区广播配置。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCdmaCBConfig()

```
IRil::GetCdmaCBConfig ([in] int slotId, [in] int serialId )
```
**描述**

获取CDMA小区广播配置。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetClip()

```
IRil::GetClip ([in] int slotId, [in] int serialId )
```
**描述**

获取主叫号码显示(CLIP)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetClir()

```
IRil::GetClir ([in] int slotId, [in] int serialId )
```
**描述**

获取主叫号码显示限制(CLIR)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCsRegStatus()

```
IRil::GetCsRegStatus ([in] int slotId, [in] int serialId )
```
**描述**

获取电路(CS)域注册状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetCurrentCellInfo()

```
IRil::GetCurrentCellInfo ([in] int slotId, [in] int serialId )
```
**描述**

获取小区信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetEmergencyCallList()

```
IRil::GetEmergencyCallList ([in] int slotId, [in] int serialId )
```
**描述**

获取紧急号码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetImei()

```
IRil::GetImei ([in] int slotId, [in] int serialId )
```
**描述**

获取国际移动设备识别码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetImsi()

```
IRil::GetImsi ([in] int slotId, [in] int serialId )
```
**描述**

获取SIM卡国际移动用户识别码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetLinkBandwidthInfo()

```
IRil::GetLinkBandwidthInfo ([in] int slotId, [in] int serialId, [in] int cid )
```
**描述**

获取当前链路信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cid | PDP上下文标识符。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetMeid()

```
IRil::GetMeid ([in] int slotId, [in] int serialId )
```
**描述**

获取移动设备识别码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetMute()

```
IRil::GetMute ([in] int slotId, [in] int serialId )
```
**描述**

获取静音。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetNeighboringCellInfoList()

```
IRil::GetNeighboringCellInfoList ([in] int slotId, [in] int serialId )
```
**描述**

获取相邻小区信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetNetworkSearchInformation()

```
IRil::GetNetworkSearchInformation ([in] int slotId, [in] int serialId )
```
**描述**

获取可用网络信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetNetworkSelectionMode()

```
IRil::GetNetworkSelectionMode ([in] int slotId, [in] int serialId )
```
**描述**

获取选网模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetOperatorInfo()

```
IRil::GetOperatorInfo ([in] int slotId, [in] int serialId )
```
**描述**

获取运营商名称信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetPdpContextList()

```
IRil::GetPdpContextList ([in] int slotId, [in] int serialId, [in] struct UniInfo uniInfo )
```
**描述**

获取当前所有数据连接状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| uniInfo | 表示通用信息，详见[UniInfo](_uni_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetPhysicalChannelConfig()

```
IRil::GetPhysicalChannelConfig ([in] int slotId, [in] int serialId )
```
**描述**

获取物理通道配置。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetPreferredNetwork()

```
IRil::GetPreferredNetwork ([in] int slotId, [in] int serialId )
```
**描述**

获取首选网络类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetPsRegStatus()

```
IRil::GetPsRegStatus ([in] int slotId, [in] int serialId )
```
**描述**

获取分组(PS)域注册状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetRadioProtocol()

```
IRil::GetRadioProtocol ([in] int slotId, [in] int serialId )
```
**描述**

获取主副卡协议栈。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetRadioState()

```
IRil::GetRadioState ([in] int slotId, [in] int serialId )
```
**描述**

获取Modem状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetSignalStrength()

```
IRil::GetSignalStrength ([in] int slotId, [in] int serialId )
```
**描述**

获取信号强度。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetSimIO()

```
IRil::GetSimIO ([in] int slotId, [in] int serialId, [in] struct SimIoRequestInfo simIO )
```
**描述**

获取SIM卡数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| [SimIoRequestInfo](_sim_io_request_info_v10.md) | 表示SIM卡数据请求信息，详见[SimIoRequestInfo](_sim_io_request_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetSimLockStatus()

```
IRil::GetSimLockStatus ([in] int slotId, [in] int serialId, [in] struct SimLockInfo simLockInfo )
```
**描述**

获取SIM卡锁状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| [SimLockInfo](_sim_lock_info_v10.md) | 表示SIM卡锁信息，详见[SimLockInfo](_sim_lock_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetSimStatus()

```
IRil::GetSimStatus ([in] int slotId, [in] int serialId )
```
**描述**

获取SIM卡状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetSmscAddr()

```
IRil::GetSmscAddr ([in] int slotId, [in] int serialId )
```
**描述**

获取短信中心地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetUssd()

```
IRil::GetUssd ([in] int slotId, [in] int serialId )
```
**描述**

获取Ussd业务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### GetVoiceRadioTechnology()

```
IRil::GetVoiceRadioTechnology ([in] int slotId, [in] int serialId )
```
**描述**

获取电路（CS）域接入技术。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### Hangup()

```
IRil::Hangup ([in] int slotId, [in] int serialId, [in] int callId )
```
**描述**

挂断电话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| callId | 表示通话ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### HoldCall()

```
IRil::HoldCall ([in] int slotId, [in] int serialId )
```
**描述**

保持通话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### Reject()

```
IRil::Reject ([in] int slotId, [in] int serialId )
```
**描述**

拒接电话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendCdmaSms()

```
IRil::SendCdmaSms ([in] int slotId, [in] int serialId, [in] struct SendCdmaSmsMessageInfo cdmaSmsMessageInfo )
```
**描述**

发送码分多址(CDMA)短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cdmaSmsMessageInfo | 表示CDMA短信信息，详见[SendCdmaSmsMessageInfo](_send_cdma_sms_message_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendDataPerformanceMode()

```
IRil::SendDataPerformanceMode ([in] int slotId, [in] int serialId, [in] struct DataPerformanceInfo dataPerformanceInfo )
```
**描述**

发送数据业务性能模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataPerformanceInfo | 表示数据业务性能模式，详见[DataPerformanceInfo](_data_performance_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendDataSleepMode()

```
IRil::SendDataSleepMode ([in] int slotId, [in] int serialId, [in] struct DataSleepInfo dataSleepInfo )
```
**描述**

发送数据业务睡眠模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataSleepInfo | 表示数据业务睡眠模式，详见[DataSleepInfo](_data_sleep_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendDtmf()

```
IRil::SendDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述**

发送双音多频（DTMF）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendGsmSms()

```
IRil::SendGsmSms ([in] int slotId, [in] int serialId, [in] struct GsmSmsMessageInfo gsmSmsMessageInfo )
```
**描述**

发送全球移动通信系统 (GSM)短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| gsmSmsMessageInfo | 表示GSM短信信息，详见[GsmSmsMessageInfo](_gsm_sms_message_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendRilAck()

```
IRil::SendRilAck ()
```
**描述**

发送应答给无线接口层（RIL）。

**起始版本：** 3.2

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendSmsAck()

```
IRil::SendSmsAck ([in] int slotId, [in] int serialId, [in] struct ModeData modeData )
```
**描述**

确认接收新短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| modeData | 表示接收短信处理模式，详见[ModeData](_mode_data_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SendSmsMoreMode()

```
IRil::SendSmsMoreMode ([in] int slotId, [in] int serialId, [in] struct GsmSmsMessageInfo gsmSmsMessageInfo )
```
**描述**

发送GSM长短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| gsmSmsMessageInfo | 表示GSM短信信息，详见[GsmSmsMessageInfo](_gsm_sms_message_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SeparateConference()

```
IRil::SeparateConference ([in] int slotId, [in] int serialId, [in] int callId, [in] int callType )
```
**描述**

与会议电话分离。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| callId | 表示通话ID。  | 
| callType | 表示通话类型，当前只能为0（即语音通话）。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetActiveSim()

```
IRil::SetActiveSim ([in] int slotId, [in] int serialId, [in] int index, [in] int enable )
```
**描述**

激活去激活SIM卡。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| index | 表示索引值。  | 
| enable | 表示激活状态，0为去激活，1为激活。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetBarringPassword()

```
IRil::SetBarringPassword ([in] int slotId, [in] int serialId, [in] struct SetBarringInfo setBarringInfo )
```
**描述**

设置呼叫限制密码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| setBarringInfo | 表示设置呼叫限制密码的信息，详见[SetBarringInfo](_set_barring_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallback()

```
IRil::SetCallback ([in] IRilCallback rilCallback)
```
**描述**

设置IRil回调接口，回调函数参考[IRilCallback](interface_i_ril_callback_v10.md)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rilCallback | 要设置的回调函数。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallPreferenceMode()

```
IRil::SetCallPreferenceMode ([in] int slotId, [in] int serialId, [in] int mode )
```
**描述**

设置通话偏好模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| mode | 表示通话偏好模式，1表示仅电路（CS)域通话，2表示电路（CS)域通话优先，3表示IP多媒体系统（IMS）通话优先，4表示仅IP多媒体系统（IMS）通话。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallRestriction()

```
IRil::SetCallRestriction ([in] int slotId, [in] int serialId, [in] struct CallRestrictionInfo callRestrictionInfo )
```
**描述**

设置呼叫限制。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| callRestrictionInfo | 表示呼叫限制信息，详见[CallRestrictionInfo](_call_restriction_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallTransferInfo()

```
IRil::SetCallTransferInfo ([in] int slotId, [in] int serialId, [in] struct CallForwardSetInfo callForwardSetInfo )
```
**描述**

设置呼叫转移。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| callForwardSetInfo | 表示呼叫转移信息，详见[CallForwardSetInfo](_call_forward_set_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCallWaiting()

```
IRil::SetCallWaiting ([in] int slotId, [in] int serialId, [in] int activate )
```
**描述**

设置呼叫等待。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| activate | 表示禁止或使能呼叫等待功能，0表示禁止，1表示使能。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCBConfig()

```
IRil::SetCBConfig ([in] int slotId, [in] int serialId, [in] struct CBConfigInfo cellBroadcastInfo )
```
**描述**

激活GSM小区广播。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cellBroadcastInfo | 表示GSM小区广播配置信息，详见[CBConfigInfo](_c_b_config_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetCdmaCBConfig()

```
IRil::SetCdmaCBConfig ([in] int slotId, [in] int serialId, [in] struct CdmaCBConfigInfoList cdmaCBConfigInfoList )
```
**描述**

激活CDMA小区广播。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cdmaCBConfigInfoList | 表示CDMA小区广播配置信息列表，详见[CdmaCBConfigInfoList](_cdma_c_b_config_info_list_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetClip()

```
IRil::SetClip ([in] int slotId, [in] int serialId, [in] int action )
```
**描述**

设置主叫号码显示。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| action | 表示禁止或使能主叫号码显示功能，0表示禁止，1表示使能。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetClir()

```
IRil::SetClir ([in] int slotId, [in] int serialId, [in] int action )
```
**描述**

设置主叫号码显示限制。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| action | 表示禁止或使能主叫号码显示限制功能，0表示禁止，1表示使能。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetDataPermitted()

```
IRil::SetDataPermitted ([in] int slotId, [in] int serialId, [in] int dataPermitted )
```
**描述**

使能SIM卡槽数据业务。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataPermitted | 表示是否使能，0表示不使能，1表示使能。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetDataProfileInfo()

```
IRil::SetDataProfileInfo ([in] int slotId, [in] int serialId, [in] struct DataProfilesInfo dataProfilesInfo )
```
**描述**

设置数据业务使用的PDP上下文信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataProfilesInfo | 表示PDP上下文信息列表，详见[DataProfilesInfo](_data_profiles_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetDeviceState()

```
IRil::SetDeviceState ([in] int slotId, [in] int serialId, [in] int deviceStateType, [in] int deviceStateOn )
```
**描述**

设置设备状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| deviceStateType | 表示设备状态类型，0表示省电模式，1表示充电模式，2表示低数据模式。  | 
| deviceStateOn | 表示设备状态开关，0表示关闭，1表示开启。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetEmergencyCallList()

```
IRil::SetEmergencyCallList ([in] int slotId, [in] int serialId, [in] struct EmergencyInfoList emergencyInfoList )
```
**描述**

设置紧急呼叫号码。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| emergencyInfoList | 表示紧急号码列表，详见[EmergencyInfoList](_emergency_info_list_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetInitApnInfo()

```
IRil::SetInitApnInfo ([in] int slotId, [in] int serialId, [in] struct DataProfileDataInfo dataProfileDataInfo )
```
**描述**

设置初始化默认网络接入技术(APN)信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataProfileDataInfo | 表示分组报文协议(PDP)上下文信息，详见[DataProfileDataInfo](_data_profile_data_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetLinkBandwidthReportingRule()

```
IRil::SetLinkBandwidthReportingRule ([in] int slotId, [in] int serialId, [in] struct DataLinkBandwidthReportingRule dataLinkBandwidthReportingRule )
```
**描述**

设置当前链路信息的上报规则。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dataLinkBandwidthReportingRule | 表示网络频率上报规则，详见[DataLinkBandwidthReportingRule](_data_link_bandwidth_reporting_rule_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetLocateUpdates()

```
IRil::SetLocateUpdates ([in] int slotId, [in] int serialId, [in] enum RilRegNotifyMode mode )
```
**描述**

设置小区位置更新通知模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| mode | 表示通知模式，详见[RilRegNotifyMode](_ril_v10.md#rilregnotifymode)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetMute()

```
IRil::SetMute ([in] int slotId, [in] int serialId, [in] int mute )
```
**描述**

设置静音。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| mute | 表示禁止或使能静音，0表示禁止，1表示使能。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetNetworkSelectionMode()

```
IRil::SetNetworkSelectionMode ([in] int slotId, [in] int serialId, [in] struct SetNetworkModeInfo networkModeInfo )
```
**描述**

设置选网模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| networkModeInfo | 表示选网模式信息，详见[SetNetworkModeInfo](_set_network_mode_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetNotificationFilter()

```
IRil::SetNotificationFilter ([in] int slotId, [in] int serialId, [in] int newFilter )
```
**描述**

设置Modem主动上报消息过滤器。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| newFilter | 表示消息类型过滤器，使用二进制标志位表示不同的消息类型，0表示关闭， 1表示信号强度，2表示网络注册状态，4表示数据连接状态，8表示链路容量，16表示物理通道配置。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetPreferredNetwork()

```
IRil::SetPreferredNetwork ([in] int slotId, [in] int serialId, [in] int preferredNetworkType )
```
**描述**

设置首选网络类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| preferredNetworkType | 表示首选网络类型，详见[PreferredNetworkTypeInfo](_preferred_network_type_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetRadioProtocol()

```
IRil::SetRadioProtocol ([in] int slotId, [in] int serialId, [in] struct RadioProtocol radioProtocol )
```
**描述**

设置主副卡协议栈。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| radioProtocol | 表示Radio协议信息，详见[RadioProtocol](_radio_protocol_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetRadioState()

```
IRil::SetRadioState ([in] int slotId, [in] int serialId, [in] int fun, [in] int rst )
```
**描述**

设置Modem状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| fun | 表示功能模式，0表示最小模式，1表示online模式，4表示offline模式，其他模式由芯片自定义。  | 
| rst | 表示Modem是否自动复位，0表示不复位，1表示复位。 | 

**返回：**

0 表示执行成功

非零值 表示操作失败。


### SetSimLock()

```
IRil::SetSimLock ([in] int slotId, [in] int serialId, [in] struct SimLockInfo simLockInfo )
```
**描述**

设置SIM卡锁。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| [SimLockInfo](_sim_lock_info_v10.md) | 表示SIM卡锁信息，详见[SimLockInfo](_sim_lock_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetSmscAddr()

```
IRil::SetSmscAddr ([in] int slotId, [in] int serialId, [in] struct ServiceCenterAddress serviceCenterAddress )
```
**描述**

设置短信中心地址。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| serviceCenterAddress | 表示短信中心地址信息，详见[ServiceCenterAddress](_service_center_address_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SetUssd()

```
IRil::SetUssd ([in] int slotId, [in] int serialId, [in] String str )
```
**描述**

设置非结构化补充数据业务（USSD）。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| str | 表示USSD信息，最大长度为160个字符。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### ShutDown()

```
IRil::ShutDown ([in] int slotId, [in] int serialId )
```
**描述**

发送手机正在关机状态到Modem。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimAuthentication()

```
IRil::SimAuthentication ([in] int slotId, [in] int serialId, [in] struct SimAuthenticationRequestInfo simAuthInfo )
```
**描述**

SIM卡鉴权。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| simAuthInfo | 表示SIM卡鉴权请求信息，详见[SimAuthenticationRequestInfo](_sim_authentication_request_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimCloseLogicalChannel()

```
IRil::SimCloseLogicalChannel ([in] int slotId, [in] int serialId, [in] int channelId )
```
**描述**

关闭应用协议数据单元（APDU）逻辑通道。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| channelId | 表示请求关闭的逻辑通道ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimOpenLogicalChannel()

```
IRil::SimOpenLogicalChannel ([in] int slotId, [in] int serialId, [in] String appID, [in] int p2 )
```
**描述**

打开应用协议数据单元（APDU）逻辑通道。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| appID | 表示应用标识符。  | 
| p2 | 表示AT指令码的参数2。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimStkIsReady()

```
IRil::SimStkIsReady ([in] int slotId, [in] int serialId )
```
**描述**

获取STK是否Ready状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendCallSetupRequestResult()

```
IRil::SimStkSendCallSetupRequestResult ([in] int slotId, [in] int serialId, [in] int accept )
```
**描述**

发送STK CallSetup指令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| accept | 表示是否接受CallSetup请求，0为不接受，1为接受。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendEnvelope()

```
IRil::SimStkSendEnvelope ([in] int slotId, [in] int serialId, [in] String strCmd )
```
**描述**

发送STK Envelope指令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| strCmd | 表示指令的字串文本。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimStkSendTerminalResponse()

```
IRil::SimStkSendTerminalResponse ([in] int slotId, [in] int serialId, [in] String strCmd )
```
**描述**

发送SIM卡应用开发工具箱(STK) TerminalResponse指令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| strCmd | 表示指令的字串文本。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimTransmitApduBasicChannel()

```
IRil::SimTransmitApduBasicChannel ([in] int slotId, [in] int serialId, [in] struct ApduSimIORequestInfo apduSimIO )
```
**描述**

应用协议数据单元（APDU）基础通道数据传输，默认打开的传输通道。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| apduSimIO | 表示通过应用协议数据单元（APDU）传输的SIM数据请求信息，详见[ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SimTransmitApduLogicalChannel()

```
IRil::SimTransmitApduLogicalChannel ([in] int slotId, [in] int serialId, [in] struct ApduSimIORequestInfo apduSimIO )
```
**描述**

应用协议数据单元（APDU）逻辑通道数据传输，由应用主动发起连接和关闭。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| apduSimIO | 表示通过应用协议数据单元（APDU）传输的SIM数据请求信息，详见[ApduSimIORequestInfo](_apdu_sim_i_o_request_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### StartDtmf()

```
IRil::StartDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述**

开启DTMF。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### StopDtmf()

```
IRil::StopDtmf ([in] int slotId, [in] int serialId, [in] struct DtmfInfo dtmfInfo )
```
**描述**

关闭DTMF。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| dtmfInfo | 表示DTMF信息，详见[DtmfInfo](_dtmf_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### SwitchCall()

```
IRil::SwitchCall ([in] int slotId, [in] int serialId )
```
**描述**

切换通话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnHoldCall()

```
IRil::UnHoldCall ([in] int slotId, [in] int serialId )
```
**描述**

取消保持通话。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPin()

```
IRil::UnlockPin ([in] int slotId, [in] int serialId, [in] String pin )
```
**描述**

PIN解锁。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| pin | 表示用于解锁的PIN码。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPin2()

```
IRil::UnlockPin2 ([in] int slotId, [in] int serialId, [in] String pin2 )
```
**描述**

PIN2解锁。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| pin2 | 表示用于解锁的PIN2码。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPuk()

```
IRil::UnlockPuk ([in] int slotId, [in] int serialId, [in] String puk, [in] String pin )
```
**描述**

PUK解锁。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| puk | 表示用于解锁的PUK码。  | 
| pin | 表示用于解锁的PIN码。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnlockPuk2()

```
IRil::UnlockPuk2 ([in] int slotId, [in] int serialId, [in] String puk2, [in] String pin2 )
```
**描述**

PUK2解锁。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| puk2 | 表示用于解锁的PUK2码。  | 
| pin2 | 表示用于解锁的PIN2码。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UnlockSimLock()

```
IRil::UnlockSimLock ([in] int slotId, [in] int serialId, [in] int lockType, [in] String key )
```
**描述**

解锁SIM卡。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| lockType | 表示锁类型，参考3GPP TS 22.022 [33]。  | 
| key | 表示用于解锁的密码，参考3GPP TS 22.022 [33]。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UpdateCdmaSimMessage()

```
IRil::UpdateCdmaSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo cdmaSmsMessageInfo )
```
**描述**

更新CDMA SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| cdmaSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。


### UpdateSimMessage()

```
IRil::UpdateSimMessage ([in] int slotId, [in] int serialId, [in] struct SmsMessageIOInfo gsmSmsMessageInfo )
```
**描述**

更新GSM SIM卡短信。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| slotId | 表示卡槽ID。  | 
| serialId | 表示请求的序列化ID。  | 
| gsmSmsMessageInfo | 表示SIM卡短信信息，详见[SmsMessageIOInfo](_sms_message_i_o_info_v10.md)。 | 

**返回：**

0 表示执行成功。

非零值 表示操作失败。
