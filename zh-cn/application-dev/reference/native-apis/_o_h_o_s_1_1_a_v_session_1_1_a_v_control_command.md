# OHOS::AVSession::AVControlCommand


## 概述

用于描述音视频播控命令工具类，播控命令的封装对象，支持设置和获取控制命令。


## 汇总


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| {<br/>**SESSION_CMD_INVALID** = -1, **SESSION_CMD_PLAY** = 0, **SESSION_CMD_PAUSE** = 1, **SESSION_CMD_STOP** = 2, **SESSION_CMD_PLAY_NEXT** = 3, **SESSION_CMD_PLAY_PREVIOUS** = 4, **SESSION_CMD_FAST_FORWARD** = 5, **SESSION_CMD_REWIND** = 6, **SESSION_CMD_SEEK** = 7, **SESSION_CMD_SET_SPEED** = 8, **SESSION_CMD_SET_LOOP_MODE** = 9, **SESSION_CMD_TOGGLE_FAVORITE** = 10, **SESSION_CMD_MAX** = 11<br/>} | 操作指令。  | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Marshalling](#marshalling) (Parcel &amp;parcel) const override | IPC通信数据序列化。  | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling) (Parcel &amp;data) | IPC通信数据反序列化。  | 
| [localCapability](#localcapability) | 命令数组，用于分布式业务，判断是否支持某个命令。  | 
| [IsValid](#isvalid) () const | 判断当前指令是否在有效范围内。  | 
| [SetCommand](#setcommand) (int32_t cmd) | 设置操作指令。  | 
| [GetCommand](#getcommand) () const | 获取操作指令。  | 
| [SetSpeed](#setspeed) (double speed) | 设置媒体播放倍数。  | 
| [GetSpeed](#getspeed) (double &amp;speed) const | 获取媒体播放倍数  | 
| [SetSeekTime](#setseektime) (int64_t time) | 设置媒体跳播时间。  | 
| [GetSeekTime](#getseektime) (int64_t &amp;time) const | 获取媒体跳播时间。  | 
| [SetLoopMode](#setloopmode) (int32_t mode) | 设置媒体循环模式。  | 
| [GetLoopMode](#getloopmode) (int32_t &amp;mode) const | 获取媒体循环模式。  | 
| [SetAssetId](#setassetid) (const std::string &amp;assetId) | 设置媒体id。  | 
| [GetAssetId](#getassetid) (std::string &amp;assetId) const | 获取媒体id。  | 


## 成员枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
操作指令。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SESSION_CMD_INVALID  | 无效指令，内部用于判断指令是否有效 | 
| SESSION_CMD_PLAY  | 播放 | 
| SESSION_CMD_PAUSE  | 暂停 | 
| SESSION_CMD_STOP  | 停止 | 
| SESSION_CMD_PLAY_NEXT  | 播放下一首 | 
| SESSION_CMD_PLAY_PREVIOUS  | 播放上一首 | 
| SESSION_CMD_FAST_FORWARD  | 快进 | 
| SESSION_CMD_REWIND  | 快退 | 
| SESSION_CMD_SEEK  | 跳播 | 
| SESSION_CMD_SET_SPEED  | 设置播放倍数 | 
| SESSION_CMD_SET_LOOP_MODE  | 设置循环模式 | 
| SESSION_CMD_TOGGLE_FAVORITE  | 收藏 | 
| SESSION_CMD_MAX  | 无效指令，内部用于判断指令是否有效 | 


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
| assetId | 保存媒体id。  | 

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

返回操作指令，范围在**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**之间。

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
| mode | 保存媒体循环模式。 取值在[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)的**LOOP_MODE_SEQUENCE**到**LOOP_MODE_SHUFFLE**之间。  | 

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
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。  | 

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
| speed | 媒体播放倍数，返回值。  | 

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

如果cmd_在有效范围内，范围在**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**之间， 返回true；否则，返回false。


### Marshalling()

  
```
bool OHOS::AVSession::AVControlCommand::Marshalling (Parcel & parcel) const
```
**描述:**
IPC通信数据序列化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| parcel | 保存序列化值的对象**Parcel**。  | 

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
| assetId | 媒体id，不可为空。  | 

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
| cmd | 操作指令，范围在**SESSION_CMD_INVALID**到**SESSION_CMD_MAX**之间。  | 

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
| mode | 媒体循环模式， 取值在[AVPlaybackState](_o_h_o_s_1_1_a_v_session_1_1_a_v_playback_state.md)的**LOOP_MODE_SEQUENCE**到**LOOP_MODE_SHUFFLE**之间。  | 

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
| time | 媒体资源的位置，从媒体资源开头开始计算，单位为ms。取值需大于等于0。  | 

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
| speed | 媒体播放倍数，需大于0。  | 

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
| data | 序列化对象**Parcel**。  | 

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
