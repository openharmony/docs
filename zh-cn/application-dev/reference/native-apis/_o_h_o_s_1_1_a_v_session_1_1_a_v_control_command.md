# OHOS::AVSession::AVControlCommand


## 概述

用于描述音视频播控命令工具类，播控命令的封装对象，支持设置和获取控制命令。


## 汇总


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| {<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1557819891182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4](#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref957310214182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594ab2f281fa4a18e5c8bd9b831018b057ef](#a70e121e9dba2777559ffceb1fae31594ab2f281fa4a18e5c8bd9b831018b057ef)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref948744425182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594adb703270c367b65bf64f46f5b0855888](#a70e121e9dba2777559ffceb1fae31594adb703270c367b65bf64f46f5b0855888)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref339339467182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594ae98353b7b0d3aec0bca22aed43e2169f](#a70e121e9dba2777559ffceb1fae31594ae98353b7b0d3aec0bca22aed43e2169f)&nbsp;=&nbsp;2,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1609917467182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a37929ecb5b825db52dcae66b02bdc910](#a70e121e9dba2777559ffceb1fae31594a37929ecb5b825db52dcae66b02bdc910)&nbsp;=&nbsp;3,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref632351639182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a37dc7117f0e98c82fb7eec13fa38a9d1](#a70e121e9dba2777559ffceb1fae31594a37dc7117f0e98c82fb7eec13fa38a9d1)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref492540746182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a4d8e14277e60f21ae57ff8f7ea3c04a5](#a70e121e9dba2777559ffceb1fae31594a4d8e14277e60f21ae57ff8f7ea3c04a5)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1632801306182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594ae4df51a5f95af9e6ef930ae7761703a1](#a70e121e9dba2777559ffceb1fae31594ae4df51a5f95af9e6ef930ae7761703a1)&nbsp;=&nbsp;6,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref156243149182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a78e852734c4705b75ccce11578fe8c87](#a70e121e9dba2777559ffceb1fae31594a78e852734c4705b75ccce11578fe8c87)&nbsp;=&nbsp;7,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref852749458182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a162fd0034aa477101e8f6dd79d889767](#a70e121e9dba2777559ffceb1fae31594a162fd0034aa477101e8f6dd79d889767)&nbsp;=&nbsp;8,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref993868989182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a26b5ba56cb80a7860574ef59d1c9f9f9](#a70e121e9dba2777559ffceb1fae31594a26b5ba56cb80a7860574ef59d1c9f9f9)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref2078543504182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594ae5dba902041c4be005915c72f9585c01](#a70e121e9dba2777559ffceb1fae31594ae5dba902041c4be005915c72f9585c01)&nbsp;=&nbsp;10,<br/>[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1270995147182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa](#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa)&nbsp;=&nbsp;11<br/>} | 操作指令。&nbsp; | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Marshalling](#marshalling)&nbsp;(Parcel&nbsp;&amp;parcel)&nbsp;const&nbsp;override | IPC通信数据序列化。&nbsp; | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling)&nbsp;(Parcel&nbsp;&amp;data) | IPC通信数据反序列化。&nbsp; | 
| [localCapability](#localcapability) | 命令数组，用于分布式业务，判断是否支持某个命令。&nbsp; | 
| [IsValid](#isvalid)&nbsp;()&nbsp;const | 判断当前指令是否在有效范围内。&nbsp; | 
| [SetCommand](#setcommand)&nbsp;(int32_t&nbsp;cmd) | 设置操作指令。&nbsp; | 
| [GetCommand](#getcommand)&nbsp;()&nbsp;const | 获取操作指令。&nbsp; | 
| [SetSpeed](#setspeed)&nbsp;(double&nbsp;speed) | 设置媒体播放倍数。&nbsp; | 
| [GetSpeed](#getspeed)&nbsp;(double&nbsp;&amp;speed)&nbsp;const | 获取媒体播放倍数&nbsp; | 
| [SetSeekTime](#setseektime)&nbsp;(int64_t&nbsp;time) | 设置媒体跳播时间。&nbsp; | 
| [GetSeekTime](#getseektime)&nbsp;(int64_t&nbsp;&amp;time)&nbsp;const | 获取媒体跳播时间。&nbsp; | 
| [SetLoopMode](#setloopmode)&nbsp;(int32_t&nbsp;mode) | 设置媒体循环模式。&nbsp; | 
| [GetLoopMode](#getloopmode)&nbsp;(int32_t&nbsp;&amp;mode)&nbsp;const | 获取媒体循环模式。&nbsp; | 
| [SetAssetId](#setassetid)&nbsp;(const&nbsp;std::string&nbsp;&amp;assetId) | 设置媒体id。&nbsp; | 
| [GetAssetId](#getassetid)&nbsp;(std::string&nbsp;&amp;assetId)&nbsp;const | 获取媒体id。&nbsp; | 


## 成员枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
操作指令。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_CMD_INVALID&nbsp; | 无效指令，内部用于判断指令是否有效 | 
| SESSION_CMD_PLAY&nbsp; | 播放 | 
| SESSION_CMD_PAUSE&nbsp; | 暂停 | 
| SESSION_CMD_STOP&nbsp; | 停止 | 
| SESSION_CMD_PLAY_NEXT&nbsp; | 播放下一首 | 
| SESSION_CMD_PLAY_PREVIOUS&nbsp; | 播放上一首 | 
| SESSION_CMD_FAST_FORWARD&nbsp; | 快进 | 
| SESSION_CMD_REWIND&nbsp; | 快退 | 
| SESSION_CMD_SEEK&nbsp; | 跳播 | 
| SESSION_CMD_SET_SPEED&nbsp; | 设置播放倍数 | 
| SESSION_CMD_SET_LOOP_MODE&nbsp; | 设置循环模式 | 
| SESSION_CMD_TOGGLE_FAVORITE&nbsp; | 收藏 | 
| SESSION_CMD_MAX&nbsp; | 无效指令，内部用于判断指令是否有效 | 


## 成员函数说明


### GetAssetId()

  
```
int32_t OHOS::AVSession::AVControlCommand::GetAssetId (std::string & assetId) const
```
**描述:**
获取媒体id。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| assetId | 保存媒体id。&nbsp; | 

**参见:**

[SetAssetId](#setassetid)

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetCommand()

  
```
int32_t OHOS::AVSession::AVControlCommand::GetCommand () const
```
**描述:**
获取操作指令。

**返回:**

返回操作指令，范围在[ERROR:Invalid link:zh-cn_topic_0000001423933494.xml#xref867896173182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4](#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4)到[ERROR:Invalid link:zh-cn_topic_0000001423933494.xml#xref1402234096182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa](#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa)之间。

**参见:**

[SetCommand](#setcommand)


### GetLoopMode()

  
```
int32_t OHOS::AVSession::AVControlCommand::GetLoopMode (int32_t & mode) const
```
**描述:**
获取媒体循环模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mode | 保存媒体循环模式。&nbsp;取值在&nbsp;[AVPlaybackState#LOOP_MODE_SEQUENCE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfa85feb6afb637e762bc97d938f74c5f08)到[AVPlaybackState#LOOP_MODE_SHUFFLE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfaeaa9c517ca402e56c594c6b17d566203)之间。&nbsp; | 

**参见:**

[SetLoopMode](#setloopmode)

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### GetSeekTime()

  
```
int32_t OHOS::AVSession::AVControlCommand::GetSeekTime (int64_t & time) const
```
**描述:**
获取媒体跳播时间。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[SetSeekTime](#setseektime)


### GetSpeed()

  
```
int32_t OHOS::AVSession::AVControlCommand::GetSpeed (double & speed) const
```
**描述:**
获取媒体播放倍数

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| speed | 媒体播放倍数，返回值。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[SetSpeed](#setspeed)


### IsValid()

  
```
bool OHOS::AVSession::AVControlCommand::IsValid () const
```
**描述:**
判断当前指令是否在有效范围内。

**返回:**

如果cmd_在有效范围内，范围在[ERROR:Invalid link:zh-cn_topic_0000001423933494.xml#xref1266392772182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4](#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4)到link [ERROR:Invalid link:zh-cn_topic_0000001423933494.xml#xref1099549702182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa](#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa)}之间， 返回true；否则，返回false。


### Marshalling()

  
```
bool OHOS::AVSession::AVControlCommand::Marshalling (Parcel & parcel) const
```
**描述:**
IPC通信数据序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| parcel | 保存序列化值的对象**Parcel**。&nbsp; | 

**返回:**

成功返回true；否则，返回false。

**参见:**

[Unmarshalling](#unmarshalling)


### SetAssetId()

  
```
int32_t OHOS::AVSession::AVControlCommand::SetAssetId (const std::string & assetId)
```
**描述:**
设置媒体id。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| assetId | 媒体id，不可为空。&nbsp; | 

**参见:**

[GetAssetId](#getassetid)

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SetCommand()

  
```
int32_t OHOS::AVSession::AVControlCommand::SetCommand (int32_t cmd)
```
**描述:**
设置操作指令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cmd | 操作指令，范围在[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1872259712182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4](#a70e121e9dba2777559ffceb1fae31594a14f680be4361ff8e2549e333702f52c4)到[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001423933494.xml#xref1870164484182348,link:zh-cn_topic_0000001423933494.xml#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa](#a70e121e9dba2777559ffceb1fae31594a8c54e1ceeb536744dd43e4c3a0a2aafa)之间。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetCommand](#getcommand)


### SetLoopMode()

  
```
int32_t OHOS::AVSession::AVControlCommand::SetLoopMode (int32_t mode)
```
**描述:**
设置媒体循环模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mode | 媒体循环模式，&nbsp;取值在&nbsp;[AVPlaybackState#LOOP_MODE_SEQUENCE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfa85feb6afb637e762bc97d938f74c5f08)到[AVPlaybackState#LOOP_MODE_SHUFFLE](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md#a12c2de6b9e2d86a6d2fe5bec88f90abfaeaa9c517ca402e56c594c6b17d566203)之间。&nbsp; | 

**参见:**

[GetLoopMode](#getloopmode)

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。


### SetSeekTime()

  
```
int32_t OHOS::AVSession::AVControlCommand::SetSeekTime (int64_t time)
```
**描述:**
设置媒体跳播时间。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetSeekTime](#getseektime)


### SetSpeed()

  
```
int32_t OHOS::AVSession::AVControlCommand::SetSpeed (double speed)
```
**描述:**
设置媒体播放倍数。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| speed | 媒体播放倍数，需大于0。&nbsp; | 

**返回:**

成功返回**AVSESSION_SUCCESS**；失败则返回对应错误码。

**参见:**

[GetSpeed](#getspeed)


### Unmarshalling()

  
```
static AVControlCommand* OHOS::AVSession::AVControlCommand::Unmarshalling (Parcel & data)
```
**描述:**
IPC通信数据反序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| data | 序列化对象**Parcel**。&nbsp; | 

**返回:**

返回AVControlCommand的函数指针。

**参见:**

[Marshalling](#marshalling)


## 结构体成员变量说明


### localCapability

  
```
const std::vector<int32_t> OHOS::AVSession::AVControlCommand::localCapability
```
**Value:**
  
```
{
 SESSION_CMD_PLAY,
 SESSION_CMD_PAUSE,
 SESSION_CMD_STOP,
 SESSION_CMD_PLAY_NEXT,
 SESSION_CMD_PLAY_PREVIOUS,
 SESSION_CMD_FAST_FORWARD,
 SESSION_CMD_REWIND,
 SESSION_CMD_SEEK,
 SESSION_CMD_SET_SPEED,
 SESSION_CMD_SET_LOOP_MODE,
 SESSION_CMD_TOGGLE_FAVORITE,
 }
```
**描述:**
命令数组，用于分布式业务，判断是否支持某个命令。
