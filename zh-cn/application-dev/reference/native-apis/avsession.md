# Avsession


## 概述

音视频媒体会话，提供系统内媒体的统一控制能力。

功能包括媒体会话，媒体会话管理，媒体会话控制。

@syscap SystemCapability.Multimedia.AVSession.Core

**Since:**

9

**Version:**

1.0


## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [av_session.h](av__session_8h.md) | 会话的设置、获取等声明。 | 
| [avcontrol_command.h](avcontrol__command_8h.md) | 音视频控制指令的设置、获取、拷贝等声明。 | 
| [avmeta_data.h](avmeta__data_8h.md) | 会话元数据设置、获取、拷贝等接口声明。 | 
| [avplayback_state.h](avplayback__state_8h.md) | 音视频播放状态声明。 | 
| [avsession_controller.h](avsession__controller_8h.md) | 控制器对象的描述，可获取会话的播放状态和会话元数据，远程发送控制命令到会话端也可以通过订阅监听会话段的更新事件。 | 
| [avsession_descriptor.h](avsession__descriptor_8h.md) | 会话的相关描述信息。 | 
| [avsession_errors.h](avsession__errors_8h.md) | 定义了avsession错误码。 | 
| [avsession_info.h](avsession__info_8h.md) | 定义了与avsession相关的监听器以及回调功能的实现。 | 
| [avsession_manager.h](avsession__manager_8h.md) | 定义了会话管理器对外接口的功能的实现。 | 
| [avsession_pixel_map.h](avsession__pixel__map_8h.md) | 读取、设置图片及图片信息。 | 


### 结构体

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md) | struct<br/>描述分布式设备的相关信息。 | 
| [OHOS::AVSession::AVSessionDescriptor](o_h_o_s_1_1_a_v_session_1_1_a_v_session_descriptor.md) | struct<br/>会话的相关描述信息。 | 
| [OHOS::AVSession::AVSessionBasicInfo](o_h_o_s_1_1_a_v_session_1_1_a_v_session_basic_info.md) | struct<br/>会话基础信息描述。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::AVSessionDescriptor::WriteToParcel](#writetoparcel)&nbsp;(Parcel&nbsp;&amp;out)&nbsp;const | bool<br/>将会话相关描述信息写进包里。 | 
| [OHOS::AVSession::AVSessionDescriptor::ReadFromParcel](#readfromparcel)&nbsp;(Parcel&nbsp;&amp;in) | bool<br/>对会话相关描述信息进行解包。 | 


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| [OHOS::AVSession::OutputDeviceInfo::isRemote_](#isremote)&nbsp;{} | bool<br/>是否连接 | 
| [OHOS::AVSession::OutputDeviceInfo::deviceIds_](#deviceids) | std::vector&lt;&nbsp;std::string&nbsp;&gt;<br/>分布式设备的id集合 | 
| [OHOS::AVSession::OutputDeviceInfo::deviceNames_](#devicenames) | std::vector&lt;&nbsp;std::string&nbsp;&gt;<br/>分布式设备的名称集合 | 
| [OHOS::AVSession::AVSessionDescriptor::sessionId_](#sessionid) | std::string<br/>会话的id | 
| [OHOS::AVSession::AVSessionDescriptor::sessionType_](#sessiontype)&nbsp;{} | int32_t<br/>会话的类型 | 
| [OHOS::AVSession::AVSessionDescriptor::sessionTag_](#sessiontag) | std::string<br/>会话的自定义名称 | 
| [OHOS::AVSession::AVSessionDescriptor::elementName_](#elementname) | AppExecFwk::ElementName<br/>会话所属应用的信息包含bundleName，abilityName等 | 
| [OHOS::AVSession::AVSessionDescriptor::pid_](#pid)&nbsp;{} | pid_t<br/>进程id | 
| [OHOS::AVSession::AVSessionDescriptor::uid_](#uid)&nbsp;{} | pid_t<br/>用户id | 
| [OHOS::AVSession::AVSessionDescriptor::isActive_](#isactive)&nbsp;{} | bool<br/>会话是否为激活状态 | 
| [OHOS::AVSession::AVSessionDescriptor::isTopSession_](#istopsession)&nbsp;{} | bool<br/>会话是否是最新的会话 | 
| [OHOS::AVSession::AVSessionDescriptor::isThirdPartyApp_](#isthirdpartyapp)&nbsp;{} | bool<br/>是否是第三方应用 | 
| [OHOS::AVSession::AVSessionDescriptor::outputDeviceInfo_](#outputdeviceinfo) | [OutputDeviceInfo](_o_h_o_s_1_1_a_v_session_1_1_output_device_info.md)<br/>分布式设备相关信息 | 
| [OHOS::AVSession::AVSessionBasicInfo::deviceName_](#devicename)&nbsp;{} | std::string<br/>设备名称 | 
| [OHOS::AVSession::AVSessionBasicInfo::networkId_](#networkid)&nbsp;{} | std::string<br/>设备id | 
| [OHOS::AVSession::AVSessionBasicInfo::vendorId_](#vendorid)&nbsp;{} | std::string<br/>供应商id | 
| [OHOS::AVSession::AVSessionBasicInfo::deviceType_](#devicetype)&nbsp;{} | std::string<br/>设备类型 | 
| [OHOS::AVSession::AVSessionBasicInfo::systemVersion_](#systemversion)&nbsp;{} | std::string<br/>系统版本 | 
| [OHOS::AVSession::AVSessionBasicInfo::sessionVersion_](#sessionversion)&nbsp;{} | int32_t<br/>会话版本 | 
| [OHOS::AVSession::AVSessionBasicInfo::reserve_](#reserve)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>备注信息 | 
| [OHOS::AVSession::AVSessionBasicInfo::feature_](#feature)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>特征信息 | 
| [OHOS::AVSession::AVSessionBasicInfo::metaDataCap_](#metadatacap)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>会话元数据 | 
| [OHOS::AVSession::AVSessionBasicInfo::playBackStateCap_](#playbackstatecap)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>支持播放状态数组 | 
| [OHOS::AVSession::AVSessionBasicInfo::controlCommandCap_](#controlcommandcap)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>系统控制命令 | 
| [OHOS::AVSession::AVSessionBasicInfo::extendCapability_](#extendcapability)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>扩展能力 | 
| [OHOS::AVSession::AVSessionBasicInfo::systemTime_](#systemtime)&nbsp;{} | int32_t<br/>系统时间 | 
| [OHOS::AVSession::AVSessionBasicInfo::extend_](#extend)&nbsp;{} | std::vector&lt;&nbsp;int32_t&nbsp;&gt;<br/>扩展信息 | 


## 函数说明


### ReadFromParcel()

  
```
bool OHOS::AVSession::AVSessionDescriptor::ReadFromParcel (Parcel & in)
```

**描述:**

对会话相关描述信息进行解包。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| in | 读出的会话相关描述信息对象**Parcel**。 | 

**返回:**

成功返回true；失败则返回false。

**参见:**

[WriteToParcel](#writetoparcel)


### WriteToParcel()

  
```
bool OHOS::AVSession::AVSessionDescriptor::WriteToParcel (Parcel & out) const
```

**描述:**

将会话相关描述信息写进包里。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| out | 写入的会话相关描述信息对象**Parcel**。 | 

**返回:**

成功返回true；失败则返回false。

**参见:**

[ReadFromParcel](#readfromparcel)


## 变量说明


### controlCommandCap_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::controlCommandCap_ {}
```

**描述:**

系统控制命令


### deviceIds_

  
```
std::vector<std::string> OHOS::AVSession::OutputDeviceInfo::deviceIds_
```

**描述:**

分布式设备的id集合


### deviceName_

  
```
std::string OHOS::AVSession::AVSessionBasicInfo::deviceName_ {}
```

**描述:**

设备名称


### deviceNames_

  
```
std::vector<std::string> OHOS::AVSession::OutputDeviceInfo::deviceNames_
```

**描述:**

分布式设备的名称集合


### deviceType_

  
```
std::string OHOS::AVSession::AVSessionBasicInfo::deviceType_ {}
```

**描述:**

设备类型


### elementName_

  
```
AppExecFwk::ElementName OHOS::AVSession::AVSessionDescriptor::elementName_
```

**描述:**

会话所属应用的信息包含bundleName，abilityName等


### extend_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::extend_ {}
```

**描述:**

扩展信息


### extendCapability_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::extendCapability_ {}
```

**描述:**

扩展能力


### feature_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::feature_ {}
```

**描述:**

特征信息


### isActive_

  
```
bool OHOS::AVSession::AVSessionDescriptor::isActive_ {}
```

**描述:**

会话是否为激活状态


### isRemote_

  
```
bool OHOS::AVSession::OutputDeviceInfo::isRemote_ {}
```

**描述:**

是否连接


### isThirdPartyApp_

  
```
bool OHOS::AVSession::AVSessionDescriptor::isThirdPartyApp_ {}
```

**描述:**

是否是第三方应用


### isTopSession_

  
```
bool OHOS::AVSession::AVSessionDescriptor::isTopSession_ {}
```

**描述:**

会话是否是最新的会话


### metaDataCap_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::metaDataCap_ {}
```

**描述:**

会话元数据


### networkId_

  
```
std::string OHOS::AVSession::AVSessionBasicInfo::networkId_ {}
```

**描述:**

设备id


### outputDeviceInfo_

  
```
OutputDeviceInfo OHOS::AVSession::AVSessionDescriptor::outputDeviceInfo_
```

**描述:**

分布式设备相关信息


### pid_

  
```
pid_t OHOS::AVSession::AVSessionDescriptor::pid_ {}
```

**描述:**

进程id


### playBackStateCap_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::playBackStateCap_ {}
```

**描述:**

支持播放状态数组


### reserve_

  
```
std::vector<int32_t> OHOS::AVSession::AVSessionBasicInfo::reserve_ {}
```

**描述:**

备注信息


### sessionId_

  
```
std::string OHOS::AVSession::AVSessionDescriptor::sessionId_
```

**描述:**

会话的id


### sessionTag_

  
```
std::string OHOS::AVSession::AVSessionDescriptor::sessionTag_
```

**描述:**

会话的自定义名称


### sessionType_

  
```
int32_t OHOS::AVSession::AVSessionDescriptor::sessionType_ {}
```

**描述:**

会话的类型


### sessionVersion_

  
```
int32_t OHOS::AVSession::AVSessionBasicInfo::sessionVersion_ {}
```

**描述:**

会话版本


### systemTime_

  
```
int32_t OHOS::AVSession::AVSessionBasicInfo::systemTime_ {}
```

**描述:**

系统时间


### systemVersion_

  
```
std::string OHOS::AVSession::AVSessionBasicInfo::systemVersion_ {}
```

**描述:**

系统版本


### uid_

  
```
pid_t OHOS::AVSession::AVSessionDescriptor::uid_ {}
```

**描述:**

用户id


### vendorId_

  
```
std::string OHOS::AVSession::AVSessionBasicInfo::vendorId_ {}
```

**描述:**

供应商id
