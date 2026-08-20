# native_avcastcontroller.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

## 概述

提供播控控制器的定义。

**引用文件：** <multimedia/av_session/native_avcastcontroller.h>

**库：** libohavsession.so

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 23

**相关模块：** [OHAVSession](capi-ohavsession.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md) | OH_AVCastController | 播控控制器对象。使用[OH_AVSession_CreateAVCastController](capi-native-avsession-h.md#oh_avsession_createavcastcontroller)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_PlaybackStateChanged)(OH_AVCastController* avcastcontroller, OH_AVSession_AVPlaybackState* playbackState, void* userData)](#oh_avcastcontrollercallback_playbackstatechanged) | OH_AVCastControllerCallback_PlaybackStateChanged | 播放状态改变的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_MediaItemChange)(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avQueueItem, void* userData)](#oh_avcastcontrollercallback_mediaitemchange) | OH_AVCastControllerCallback_MediaItemChange | 媒体项目变更的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_PlayNext)(OH_AVCastController* avcastcontroller, void* userData)](#oh_avcastcontrollercallback_playnext) | OH_AVCastControllerCallback_PlayNext | 播放下一首的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_PlayPrevious)(OH_AVCastController* avcastcontroller, void* userData)](#oh_avcastcontrollercallback_playprevious) | OH_AVCastControllerCallback_PlayPrevious | 播放上一首的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_SeekDone)(OH_AVCastController* avcastcontroller, int32_t position, void* userData)](#oh_avcastcontrollercallback_seekdone) | OH_AVCastControllerCallback_SeekDone | 跳转完成的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_EndOfStream)(OH_AVCastController* avcastcontroller, void* userData)](#oh_avcastcontrollercallback_endofstream) | OH_AVCastControllerCallback_EndOfStream | 播放流结束的回调函数。 |
| [typedef AVSessionCallback_Result(\*OH_AVCastControllerCallback_Error)(OH_AVCastController* avcastcontroller, void* userData, AVSession_ErrCode error)](#oh_avcastcontrollercallback_error) | OH_AVCastControllerCallback_Error | 播放错误的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_Destroy(OH_AVCastController* avcastcontroller)](#oh_avcastcontroller_destroy) | - | 请求销毁播控控制器对象。 |
| [AVSession_ErrCode OH_AVCastController_GetPlaybackState(OH_AVCastController* avcastcontroller, OH_AVSession_AVPlaybackState** playbackState)](#oh_avcastcontroller_getplaybackstate) | - | 获取当前播放器的播放状态。不要单独释放playbackState指针。<br> 当[OH_AVCastController_Destroy](#oh_avcastcontroller_destroy)被调用时，该指针将随播控控制器一同销毁。 |
| [AVSession_ErrCode OH_AVCastController_RegisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller, int32_t filter, OH_AVCastControllerCallback_PlaybackStateChanged callback, void* userData)](#oh_avcastcontroller_registerplaybackstatechangedcallback) | - | 请求注册播放状态改变的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlaybackStateChanged callback)](#oh_avcastcontroller_unregisterplaybackstatechangedcallback) | - | 请求取消注册播放状态改变的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_MediaItemChange callback, void* userData)](#oh_avcastcontroller_registermediaitemchangedcallback) | - | 请求注册当前播放的媒体资源发生改变的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_MediaItemChange callback)](#oh_avcastcontroller_unregistermediaitemchangedcallback) | - | 请求取消注册当前播放的媒体资源发生改变的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterPlayNextCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayNext callback, void* userData)](#oh_avcastcontroller_registerplaynextcallback) | - | 请求注册由远程端或媒体中心发送的播放下一首的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterPlayNextCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayNext callback)](#oh_avcastcontroller_unregisterplaynextcallback) | - | 请求取消注册由远程端或媒体中心发送的播放下一首的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterPlayPreviousCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayPrevious callback, void* userData)](#oh_avcastcontroller_registerplaypreviouscallback) | - | 请求注册由远程端或媒体中心发送的播放上一首的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterPlayPreviousCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayPrevious callback)](#oh_avcastcontroller_unregisterplaypreviouscallback) | - | 请求取消注册由远程端或媒体中心发送的播放上一首的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterSeekDoneCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_SeekDone callback, void* userData)](#oh_avcastcontroller_registerseekdonecallback) | - | 请求注册跳转完成的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterSeekDoneCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_SeekDone callback)](#oh_avcastcontroller_unregisterseekdonecallback) | - | 请求取消注册跳转完成的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterEndOfStreamCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_EndOfStream callback, void* userData)](#oh_avcastcontroller_registerendofstreamcallback) | - | 请求注册播放流结束的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterEndOfStreamCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_EndOfStream callback)](#oh_avcastcontroller_unregisterendofstreamcallback) | - | 请求取消注册播放流结束的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_RegisterErrorCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_Error callback, void* userData)](#oh_avcastcontroller_registererrorcallback) | - | 请求注册监听播放错误事件的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_UnregisterErrorCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_Error callback)](#oh_avcastcontroller_unregistererrorcallback) | - | 请求取消注册监听播放错误事件的回调函数。 |
| [AVSession_ErrCode OH_AVCastController_SendCommonCommand(OH_AVCastController* avcastcontroller, AVSession_AVCastControlCommandType* avCastControlcommand)](#oh_avcastcontroller_sendcommoncommand) | - | 请求发送普通命令到远程端。只支持发送播放、暂停、停止、播放下一首和播放上一首等命令。 |
| [AVSession_ErrCode OH_AVCastController_SendSeekCommand(OH_AVCastController* avcastcontroller, int32_t seekTimeMS)](#oh_avcastcontroller_sendseekcommand) | - | 请求向远程端发送跳转命令。 |
| [AVSession_ErrCode OH_AVCastController_SendFastForwardCommand(OH_AVCastController* avcastcontroller, int32_t forwardTimeS)](#oh_avcastcontroller_sendfastforwardcommand) | - | 请求向远程端发送快进命令。 |
| [AVSession_ErrCode OH_AVCastController_SendRewindCommand(OH_AVCastController* avcastcontroller, int32_t rewindTimeS)](#oh_avcastcontroller_sendrewindcommand) | - | 请求向远程端发送快退命令。 |
| [AVSession_ErrCode OH_AVCastController_SendSetSpeedCommand(OH_AVCastController* avcastcontroller, AVSession_PlaybackSpeed speed)](#oh_avcastcontroller_sendsetspeedcommand) | - | 请求向远程端发送设置倍速命令。 |
| [AVSession_ErrCode OH_AVCastController_SendVolumeCommand(OH_AVCastController* avcastcontroller, int32_t volume)](#oh_avcastcontroller_sendvolumecommand) | - | 请求向远程端发送音量控制命令。 |
| [AVSession_ErrCode OH_AVCastController_Prepare(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avqueueItem)](#oh_avcastcontroller_prepare) | - | 请求准备当前音视频播放队列项，该操作是实现输出媒体信息展示的前置步骤。 |
| [AVSession_ErrCode OH_AVCastController_Start(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avqueueItem)](#oh_avcastcontroller_start) | - | 请求播放当前项，参数应包含媒体资源，否则播放失败。 |

## 函数说明

### OH_AVCastControllerCallback_PlaybackStateChanged()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlaybackStateChanged)(OH_AVCastController* avcastcontroller, OH_AVSession_AVPlaybackState* playbackState, void* userData)
```

**描述**

播放状态改变的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_MediaItemChange()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_MediaItemChange)(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avQueueItem, void* userData)
```

**描述**

媒体项目变更的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_PlayNext()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlayNext)(OH_AVCastController* avcastcontroller, void* userData)
```

**描述**

播放下一首的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_PlayPrevious()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_PlayPrevious)(OH_AVCastController* avcastcontroller, void* userData)
```

**描述**

播放上一首的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_SeekDone()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_SeekDone)(OH_AVCastController* avcastcontroller, int32_t position, void* userData)
```

**描述**

跳转完成的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_EndOfStream()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_EndOfStream)(OH_AVCastController* avcastcontroller, void* userData)
```

**描述**

播放流结束的回调函数。

**起始版本：** 23

### OH_AVCastControllerCallback_Error()

```c
typedef AVSessionCallback_Result(*OH_AVCastControllerCallback_Error)(OH_AVCastController* avcastcontroller, void* userData, AVSession_ErrCode error)
```

**描述**

播放错误的回调函数。

**起始版本：** 23

### OH_AVCastController_Destroy()

```c
AVSession_ErrCode OH_AVCastController_Destroy(OH_AVCastController* avcastcontroller)
```

**描述**

请求销毁播控控制器对象。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：参数avcastcontroller为nullptr。 |

### OH_AVCastController_GetPlaybackState()

```c
AVSession_ErrCode OH_AVCastController_GetPlaybackState(OH_AVCastController* avcastcontroller, OH_AVSession_AVPlaybackState** playbackState)
```

**描述**

获取当前播放器的播放状态。不要单独释放playbackState指针。当[OH_AVCastController_Destroy](#oh_avcastcontroller_destroy)被调用时，该指针将随播控控制器一同销毁。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVSession_AVPlaybackState](capi-ohavsession-oh-avsession-avplaybackstate.md)** playbackState | 返回的播放状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数playbackState为nullptr。 |

### OH_AVCastController_RegisterPlaybackStateChangedCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller, int32_t filter, OH_AVCastControllerCallback_PlaybackStateChanged callback, void* userData)
```

**描述**

请求注册播放状态改变的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| int32_t filter | 通过播放状态的过滤器[AVSession_PlaybackFilter](capi-native-avsession-base-h.md#avsession_playbackfilter)来决定需要包含在回调中的参数。 |
| [OH_AVCastControllerCallback_PlaybackStateChanged](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playbackstatechanged) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。<br>                                         3. 参数filter是无效的。 |

### OH_AVCastController_UnregisterPlaybackStateChangedCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterPlaybackStateChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlaybackStateChanged callback)
```

**描述**

请求取消注册播放状态改变的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_PlaybackStateChanged](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playbackstatechanged) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterMediaItemChangedCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_MediaItemChange callback, void* userData)
```

**描述**

请求注册当前播放的媒体资源发生改变的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_MediaItemChange](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_mediaitemchange) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterMediaItemChangedCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterMediaItemChangedCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_MediaItemChange callback)
```

**描述**

请求取消注册当前播放的媒体资源发生改变的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_MediaItemChange](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_mediaitemchange) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterPlayNextCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterPlayNextCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayNext callback, void* userData)
```

**描述**

请求注册由远程端或媒体中心发送的播放下一首的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_PlayNext](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playnext) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterPlayNextCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterPlayNextCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayNext callback)
```

**描述**

请求取消注册由远程端或媒体中心发送的播放下一首的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_PlayNext](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playnext) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterPlayPreviousCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterPlayPreviousCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayPrevious callback, void* userData)
```

**描述**

请求注册由远程端或媒体中心发送的播放上一首的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_PlayPrevious](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playprevious) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterPlayPreviousCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterPlayPreviousCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_PlayPrevious callback)
```

**描述**

请求取消注册由远程端或媒体中心发送的播放上一首的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_PlayPrevious](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_playprevious) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterSeekDoneCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterSeekDoneCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_SeekDone callback, void* userData)
```

**描述**

请求注册跳转完成的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_SeekDone](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_seekdone) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterSeekDoneCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterSeekDoneCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_SeekDone callback)
```

**描述**

请求取消注册跳转完成的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_SeekDone](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_seekdone) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterEndOfStreamCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterEndOfStreamCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_EndOfStream callback, void* userData)
```

**描述**

请求注册播放流结束的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_EndOfStream](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_endofstream) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterEndOfStreamCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterEndOfStreamCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_EndOfStream callback)
```

**描述**

请求取消注册播放流结束的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_EndOfStream](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_endofstream) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_RegisterErrorCallback()

```c
AVSession_ErrCode OH_AVCastController_RegisterErrorCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_Error callback, void* userData)
```

**描述**

请求注册监听播放错误事件的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_Error](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_error) callback | 要注册的回调函数。 |
| void* userData | 由用户传递的用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_UnregisterErrorCallback()

```c
AVSession_ErrCode OH_AVCastController_UnregisterErrorCallback(OH_AVCastController* avcastcontroller, OH_AVCastControllerCallback_Error callback)
```

**描述**

请求取消注册监听播放错误事件的回调函数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVCastControllerCallback_Error](capi-native-avcastcontroller-h.md#oh_avcastcontrollercallback_error) callback | 要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数callback为nullptr。 |

### OH_AVCastController_SendCommonCommand()

```c
AVSession_ErrCode OH_AVCastController_SendCommonCommand(OH_AVCastController* avcastcontroller, AVSession_AVCastControlCommandType* avCastControlcommand)
```

**描述**

请求发送普通命令到远程端。只支持发送播放、暂停、停止、播放下一首和播放上一首等命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [AVSession_AVCastControlCommandType](capi-native-avsession-base-h.md#avsession_avcastcontrolcommandtype)* avCastControlcommand | 控制命令。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：参数avcastcontroller为nullptr。<br>         AV_SESSION_ERR_CODE_COMMAND_INVALID：参数avCastControlcommand是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_SendSeekCommand()

```c
AVSession_ErrCode OH_AVCastController_SendSeekCommand(OH_AVCastController* avcastcontroller, int32_t seekTimeMS)
```

**描述**

请求向远程端发送跳转命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| int32_t seekTimeMS | 跳转时间。单位为毫秒（ms）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数seekTimeMS是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_SendFastForwardCommand()

```c
AVSession_ErrCode OH_AVCastController_SendFastForwardCommand(OH_AVCastController* avcastcontroller, int32_t forwardTimeS)
```

**描述**

请求向远程端发送快进命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| int32_t forwardTimeS | 快进时间。单位为秒（s）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数forwardTimeS是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_SendRewindCommand()

```c
AVSession_ErrCode OH_AVCastController_SendRewindCommand(OH_AVCastController* avcastcontroller, int32_t rewindTimeS)
```

**描述**

请求向远程端发送快退命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| int32_t rewindTimeS | 快退时间。单位为秒（s）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数rewindTimeS是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_SendSetSpeedCommand()

```c
AVSession_ErrCode OH_AVCastController_SendSetSpeedCommand(OH_AVCastController* avcastcontroller, AVSession_PlaybackSpeed speed)
```

**描述**

请求向远程端发送设置倍速命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [AVSession_PlaybackSpeed](capi-native-avsession-base-h.md#avsession_playbackspeed) speed | 倍速控制命令。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数speed是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_SendVolumeCommand()

```c
AVSession_ErrCode OH_AVCastController_SendVolumeCommand(OH_AVCastController* avcastcontroller, int32_t volume)
```

**描述**

请求向远程端发送音量控制命令。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| int32_t volume | 音量值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数volume是无效的。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_Prepare()

```c
AVSession_ErrCode OH_AVCastController_Prepare(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avqueueItem)
```

**描述**

请求准备当前音视频播放队列项，该操作是实现输出媒体信息展示的前置步骤。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVSession_AVQueueItem](capi-ohavsession-oh-avsession-avqueueitem.md)* avqueueItem | 音视频队列项。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数avqueueItem为nullptr。<br>         AV_SESSION_ERR_CODE_REMOTE_CONNECTION_NOT_EXIST：远程连接未建立。 |

### OH_AVCastController_Start()

```c
AVSession_ErrCode OH_AVCastController_Start(OH_AVCastController* avcastcontroller, OH_AVSession_AVQueueItem* avqueueItem)
```

**描述**

请求播放当前项，参数应包含媒体资源，否则播放失败。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCastController](capi-ohavsession-oh-avcastcontroller.md)* avcastcontroller | 播控控制器的实例对象。 |
| [OH_AVSession_AVQueueItem](capi-ohavsession-oh-avsession-avqueueitem.md)* avqueueItem | 音视频队列项。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | AV_SESSION_ERR_SUCCESS：函数执行成功。<br>         AV_SESSION_ERR_SERVICE_EXCEPTION：服务器内部错误。<br>         AV_SESSION_ERR_INVALID_PARAMETER：<br>                                         1. 参数avcastcontroller为nullptr。<br>                                         2. 参数avqueueItem为nullptr。 |


