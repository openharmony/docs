# native_avplaybackstate.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

## 概述

提供播放状态的定义。

**引用文件：** <multimedia/av_session/native_avplaybackstate.h>

**库：** libohavsession.so

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 23

**相关模块：** [OHAVSession](capi-ohavsession.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AVSession_PlaybackPosition](capi-ohavsession-avsession-playbackposition.md) | AVSession_PlaybackPosition | 播放位置的定义。 |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md) | OH_AVSession_AVPlaybackState | 播控播放状态的对象。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [AVSession_ErrCode OH_AVSession_GetPlaybackState(OH_AVSession_AVPlaybackState* playbackState, AVSession_PlaybackState* state)](#oh_avsession_getplaybackstate) | 获取播放的状态。 |
| [AVSession_ErrCode OH_AVSession_GetPlaybackPosition(OH_AVSession_AVPlaybackState* playbackState, AVSession_PlaybackPosition* position)](#oh_avsession_getplaybackposition) | 获取播放位置。 |
| [AVSession_ErrCode OH_AVSession_GetPlaybackSpeed(OH_AVSession_AVPlaybackState* playbackState, int32_t* speed)](#oh_avsession_getplaybackspeed) | 获取播放倍速。 |
| [AVSession_ErrCode OH_AVSession_GetPlaybackVolume(OH_AVSession_AVPlaybackState* playbackState, int32_t* volume)](#oh_avsession_getplaybackvolume) | 获取播放音量值。 |

## 函数说明

### OH_AVSession_GetPlaybackState()

```c
AVSession_ErrCode OH_AVSession_GetPlaybackState(OH_AVSession_AVPlaybackState* playbackState, AVSession_PlaybackState* state)
```

**描述**

获取播放的状态。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md)* playbackState | 表示播放状态实例对象。 |
| [AVSession_PlaybackState](capi-native-avsession-base-h.md#avsession_playbackstate)* state | 用于返回播放状态值的指针变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER 参数验证失败原因如下：<br>                                                         1. 参数playbackState为nullptr。<br>                                                         2. 参数state为nullptr。 |

### OH_AVSession_GetPlaybackPosition()

```c
AVSession_ErrCode OH_AVSession_GetPlaybackPosition(OH_AVSession_AVPlaybackState* playbackState, AVSession_PlaybackPosition* position)
```

**描述**

获取播放位置。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md)* playbackState | 表示播放状态实例对象。 |
| [AVSession_PlaybackPosition](capi-ohavsession-avsession-playbackposition.md)* position | 用于返回播放位置值的指针变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER 参数验证失败原因如下：<br>                                                         1. 参数playbackState为nullptr。<br>                                                         2. 参数position为nullptr。 |

### OH_AVSession_GetPlaybackSpeed()

```c
AVSession_ErrCode OH_AVSession_GetPlaybackSpeed(OH_AVSession_AVPlaybackState* playbackState, int32_t* speed)
```

**描述**

获取播放倍速。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md)* playbackState | 表示播放状态实例对象。 |
| int32_t* speed | 用于返回播放倍速值的指针变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER 参数验证失败原因如下：<br>                                                         1. 参数playbackState为nullptr。<br>                                                         2. 参数speed为nullptr。 |

### OH_AVSession_GetPlaybackVolume()

```c
AVSession_ErrCode OH_AVSession_GetPlaybackVolume(OH_AVSession_AVPlaybackState* playbackState, int32_t* volume)
```

**描述**

获取播放音量值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md)* playbackState | 表示播放状态实例对象。 |
| int32_t* volume | 用于返回播放音量值的指针变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_INVALID_PARAMETER 参数验证失败原因如下：<br>                                                         1. 参数playbackState为nullptr。<br>                                                         2. 参数volume为nullptr。 |


