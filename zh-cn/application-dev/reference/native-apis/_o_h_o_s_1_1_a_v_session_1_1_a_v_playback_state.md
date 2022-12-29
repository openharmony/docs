# OHOS::AVSession::AVPlaybackState


## 概述

音视频播放状态类，提供获取和设置播放界面的信息。


## 汇总


### 结构体

  | 名称 | 描述 | 
| -------- | -------- |
| [Position](_1_a_v_session_1_1_a_v_playback_state_1_1_position.md) | struct<br/>播放位置的相关信息。  | 


### Public 类型

  | 名称 | 描述 | 
| -------- | -------- |
| {<br/>**PLAYBACK_STATE_INITIAL** = 0, **PLAYBACK_STATE_PREPARING** = 1, **PLAYBACK_STATE_PLAYING** = 2, **PLAYBACK_STATE_PAUSED** = 3, **PLAYBACK_STATE_FAST_FORWARD** = 4, **PLAYBACK_STATE_REWIND** = 5, **PLAYBACK_STATE_STOP** = 6, **PLAYBACK_STATE_MAX** = 7<br/>} | 描述播放状态的枚举。  | 
| {<br/>**PLAYBACK_KEY_STATE** = 0, **PLAYBACK_KEY_SPEED** = 1, **PLAYBACK_KEY_POSITION** = 2, **PLAYBACK_KEY_BUFFERED_TIME** = 3, **PLAYBACK_KEY_LOOP_MODE** = 4, **PLAYBACK_KEY_IS_FAVORITE** = 5, **PLAYBACK_KEY_MAX** = 6<br/>} | 播放界面信息的枚举。  | 
| { **LOOP_MODE_SEQUENCE** = 0, **LOOP_MODE_SINGLE** = 1, **LOOP_MODE_LIST** = 2, **LOOP_MODE_SHUFFLE** = 3 } | 循环模式的枚举。  | 
| **PlaybackStateMaskType** = std::bitset&lt; PLAYBACK_KEY_MAX &gt; |  | 


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Marshalling](#marshalling) (Parcel &amp;parcel) const override | IPC通信数据序列化。  | 
| [IsValid](#isvalid) () const | 验证当前信息的有效性。  | 
| [SetState](#setstate) (int32_t state) | 设置音视频的播放状态。  | 
| [GetState](#getstate) () const | 获取当前音视频的播放状态。  | 
| [SetSpeed](#setspeed) (double speed) | 设置播放倍速。  | 
| [GetSpeed](#getspeed) () const | 获取当前播放倍速。  | 
| [SetPosition](#setposition) (const [Position](_1_a_v_session_1_1_a_v_playback_state_1_1_position.md) &amp;position) | 设置播放位置，通过更新时间与经过时间来计算，单位ms。  | 
| [GetPosition](#getposition) () const | 获取播放位置。  | 
| [SetBufferedTime](#setbufferedtime) (int64_t time) | 设置缓冲时间，单位为ms。  | 
| [GetBufferedTime](#getbufferedtime) () const | 获取当前缓冲时间，单位为ms。  | 
| [SetLoopMode](#setloopmode) (int32_t mode) | 设置循环模式。  | 
| [GetLoopMode](#getloopmode) () const | 获取当前循环模式。  | 
| [SetFavorite](#setfavorite) (bool isFavorite) | 设置是否收藏。  | 
| [GetFavorite](#getfavorite) () const | 获取是否收藏。  | 
| [GetMask](#getmask) () const | 获取掩码。  | 


### 静态 Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Unmarshalling](#unmarshalling) (Parcel &amp;parcel) | IPC通信数据反序列化。  | 
| [localCapability](#localcapability) | 内联函数指针数组AVPlaybackState，用于分布式业务，设置播放界面信息。  | 
| [CopyToByMask](#copytobymask) (PlaybackStateMaskType &amp;mask, AVPlaybackState &amp;out) const | 通过掩码拷贝信息到新的AVPlaybackState对象。  | 
| [CopyFrom](#copyfrom) (const AVPlaybackState &amp;in) | 根据当前对象的mask_掩码，将输入的AVPlaybackState类型的信息复制到当前对象。  | 


## 成员枚举类型说明


### anonymous enum

  
```
anonymous enum
```
**描述:**
描述播放状态的枚举。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PLAYBACK_STATE_INITIAL  | 初始状态 | 
| PLAYBACK_STATE_PREPARING  | 缓冲状态 | 
| PLAYBACK_STATE_PLAYING  | 播放状态 | 
| PLAYBACK_STATE_PAUSED  | 暂停状态 | 
| PLAYBACK_STATE_FAST_FORWARD  | 快进状态 | 
| PLAYBACK_STATE_REWIND  | 快退状态 | 
| PLAYBACK_STATE_STOP  | 停止状态 | 
| PLAYBACK_STATE_MAX  | 无效类型，内部用于判断状态是否有效 | 


### anonymous enum

  
```
anonymous enum
```
**描述:**
播放界面信息的枚举。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PLAYBACK_KEY_STATE  | 播放状态，包括正在播放、暂停、快进等 | 
| PLAYBACK_KEY_SPEED  | 播放倍数 | 
| PLAYBACK_KEY_POSITION  | 播放位置 | 
| PLAYBACK_KEY_BUFFERED_TIME  | 缓冲时间 | 
| PLAYBACK_KEY_LOOP_MODE  | 循环模式 | 
| PLAYBACK_KEY_IS_FAVORITE  | 设置喜欢(收藏) | 
| PLAYBACK_KEY_MAX  | 无效类型，内部用于判断key是否有效 | 


### anonymous enum

  
```
anonymous enum
```
**描述:**
循环模式的枚举。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LOOP_MODE_SEQUENCE  | 顺序播放 | 
| LOOP_MODE_SINGLE  | 单曲循环 | 
| LOOP_MODE_LIST  | 列表循环 | 
| LOOP_MODE_SHUFFLE  | 随机播放 | 


## 成员函数说明


### CopyFrom()

  
```
bool OHOS::AVSession::AVPlaybackState::CopyFrom (const AVPlaybackState & in)
```
**描述:**
根据当前对象的mask_掩码，将输入的AVPlaybackState类型的信息复制到当前对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| in | AVPlaybackState类型。  | 

**返回:**

如果有至少一个播放界面信息被拷贝，返回true；如果一个播放界面信息都没有被拷贝，返回false。

**参见:**

[CopyToByMask](#copytobymask)

[GetMask](#getmask)


### CopyToByMask()

  
```
bool OHOS::AVSession::AVPlaybackState::CopyToByMask (PlaybackStateMaskType & mask, AVPlaybackState & out ) const
```
**描述:**
通过掩码拷贝信息到新的AVPlaybackState对象。

mask对应位上有值的对象拷贝给out。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mask | 输入的掩码**}。 out 输出的音视频的播放状态 AVPlaybackState}。 如果有至少一个播放界面信息被拷贝，返回true；如果一个播放界面信息都没有被拷贝，返回false。 CopyFrom 9 1.0 ** | 


### GetBufferedTime()

  
```
int64_t OHOS::AVSession::AVPlaybackState::GetBufferedTime () const
```
**描述:**
获取当前缓冲时间，单位为ms。

**返回:**

返回缓冲时间。

**参见:**

[SetBufferedTime](#setbufferedtime)


### GetFavorite()

  
```
bool OHOS::AVSession::AVPlaybackState::GetFavorite () const
```
**描述:**
获取是否收藏。

**返回:**

是否收藏，是则返回true，否则返回false。

**参见:**

[SetFavorite](#setfavorite)


### GetLoopMode()

  
```
int32_t OHOS::AVSession::AVPlaybackState::GetLoopMode () const
```
**描述:**
获取当前循环模式。

**返回:**

返回循环模式，范围**LOOP_MODE_SEQUENCE**到**LOOP_MODE_SHUFFLE**之间。

**参见:**

[SetLoopMode](#setloopmode)


### GetMask()

  
```
PlaybackStateMaskType OHOS::AVSession::AVPlaybackState::GetMask () const
```
**描述:**
获取掩码。

**返回:**

返回播放界面信息的掩码**PlaybackStateMaskType**。

**参见:**

[CopyFrom](#copyfrom)


### GetPosition()

  
```
Position OHOS::AVSession::AVPlaybackState::GetPosition () const
```
**描述:**
获取播放位置。

**返回:**

返回播放位置[Position](_1_a_v_session_1_1_a_v_playback_state_1_1_position.md)。

**参见:**

[SetPosition](#setposition)


### GetSpeed()

  
```
double OHOS::AVSession::AVPlaybackState::GetSpeed () const
```
**描述:**
获取当前播放倍速。

**返回:**

返回当前播放倍速。

**参见:**

[SetSpeed](#setspeed)


### GetState()

  
```
int32_t OHOS::AVSession::AVPlaybackState::GetState () const
```
**描述:**
获取当前音视频的播放状态。

**返回:**

返回当前音视频的播放状态，范围**PLAYBACK_STATE_INITIAL**到**PLAYBACK_STATE_MAX**之间。

**参见:**

[SetState](#setstate)


### IsValid()

  
```
bool OHOS::AVSession::AVPlaybackState::IsValid () const
```
**描述:**
验证当前信息的有效性。

**返回:**

有效返回true；无效则返回false。


### Marshalling()

  
```
bool OHOS::AVSession::AVPlaybackState::Marshalling (Parcel & parcel) const
```
**描述:**
IPC通信数据序列化。

将AVPlaybackState类型的信息，序列化为**Parcel**类型的信息，用来进行IPC通信。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| parcel | 保存序列化值的对象**Parcel**。  | 

**返回:**

成功返回true；失败返回false。

**参见:**

[Unmarshalling](#unmarshalling)


### SetBufferedTime()

  
```
void OHOS::AVSession::AVPlaybackState::SetBufferedTime (int64_t time)
```
**描述:**
设置缓冲时间，单位为ms。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| time | 缓冲时间。  | 

**参见:**

[GetBufferedTime](#getbufferedtime)


### SetFavorite()

  
```
void OHOS::AVSession::AVPlaybackState::SetFavorite (bool isFavorite)
```
**描述:**
设置是否收藏。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| isFavorite | 是否收藏，是则为true，否则false。  | 

**参见:**

[GetFavorite](#getfavorite)


### SetLoopMode()

  
```
void OHOS::AVSession::AVPlaybackState::SetLoopMode (int32_t mode)
```
**描述:**
设置循环模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mode | 循环模式，范围**LOOP_MODE_SEQUENCE**到**LOOP_MODE_SHUFFLE**之间。 | 

**参见:**

[GetLoopMode](#getloopmode)


### SetPosition()

  
```
void OHOS::AVSession::AVPlaybackState::SetPosition (const Position & position)
```
**描述:**
设置播放位置，通过更新时间与经过时间来计算，单位ms。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| position | 播放位置[Position](_1_a_v_session_1_1_a_v_playback_state_1_1_position.md)。  | 

**参见:**

[GetPosition](#getposition)


### SetSpeed()

  
```
void OHOS::AVSession::AVPlaybackState::SetSpeed (double speed)
```
**描述:**
设置播放倍速。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| speed | 播放倍速。  | 

**参见:**

[SetSpeed](#setspeed)


### SetState()

  
```
void OHOS::AVSession::AVPlaybackState::SetState (int32_t state)
```
**描述:**
设置音视频的播放状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| state | 音视频的播放状态，范围**PLAYBACK_STATE_INITIAL**到**PLAYBACK_STATE_MAX**之间。  | 

**参见:**

[GetState](#getstate)


### Unmarshalling()

  
```
static AVPlaybackState* OHOS::AVSession::AVPlaybackState::Unmarshalling (Parcel & parcel)
```
**描述:**
IPC通信数据反序列化。

将通过IPC接收的**Parcel**类型的信息，反序列化为AVPlaybackState类型的信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| parcel | 序列化对象**Parcel**。  | 

**返回:**

如果反序列化成功，则返回AVPlaybackState对象; 如果反序列化失败，则返回nullptr。

**参见:**

[Marshalling](#marshalling)


## 结构体成员变量说明


### localCapability

  
```
const std::vector<int32_t> OHOS::AVSession::AVPlaybackState::localCapability
```
**Value:**
  
```
{
 PLAYBACK_KEY_STATE,
 PLAYBACK_KEY_SPEED,
 PLAYBACK_KEY_POSITION,
 PLAYBACK_KEY_BUFFERED_TIME,
 PLAYBACK_KEY_LOOP_MODE,
 PLAYBACK_KEY_IS_FAVORITE,
 }
```
**描述:**
内联函数指针数组AVPlaybackState，用于分布式业务，设置播放界面信息。
