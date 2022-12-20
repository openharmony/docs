# OHOS::AVSession::AVSessionDescriptor


## 概述

会话的相关描述信息。

**Since:**
9
**Version:**
1.0
**相关模块:**

[Avsession](avsession.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [WriteToParcel](avsession.md#writetoparcel)&nbsp;(Parcel&nbsp;&amp;out)&nbsp;const | 将会话相关描述信息写进包里。&nbsp; | 
| [ReadFromParcel](avsession.md#readfromparcel)&nbsp;(Parcel&nbsp;&amp;in) | 对会话相关描述信息进行解包。&nbsp; | 


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| [sessionId_](avsession.md#sessionid) | std::string | 
| [sessionType_](avsession.md#sessiontype)&nbsp;{} | int32_t | 
| [sessionTag_](avsession.md#sessiontag) | std::string | 
| [elementName_](avsession.md#elementname) | AppExecFwk::ElementName | 
| [pid_](avsession.md#pid)&nbsp;{} | pid_t | 
| [uid_](avsession.md#uid)&nbsp;{} | pid_t | 
| [isActive_](avsession.md#isactive)&nbsp;{} | bool | 
| [isTopSession_](avsession.md#istopsession)&nbsp;{} | bool | 
| [isThirdPartyApp_](avsession.md#isthirdpartyapp)&nbsp;{} | bool | 
| [outputDeviceInfo_](avsession.md#outputdeviceinfo) | [OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md) | 
