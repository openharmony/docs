# avplayer.h

## 概述

定义avplayer接口。使用AVPlayer提供的Native API播放媒体源。

**引用文件：** <multimedia/player_framework/avplayer.h>

**库：** libavplayer.so

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**相关模块：** [AVPlayer](capi-avplayer.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [MediaKeySession](capi-mediakeysession.md) | MediaKeySession | MediaKeySession类型。 |
| [DRM_MediaKeySystemInfo](capi-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | DRM_MediaKeySystemInfo类型。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*Player_MediaKeySystemInfoCallback)(OH_AVPlayer \*player, DRM_MediaKeySystemInfo* mediaKeySystemInfo)](#player_mediakeysysteminfocallback) | Player_MediaKeySystemInfoCallback | 播放器DRM信息更新时调用。 |
| [OH_AVPlayer *OH_AVPlayer_Create(void)](#oh_avplayer_create) | - | 创建播放器。<br>推荐单个应用创建的音视频播放器实例（即音频、视频、音视频三类相加）不超过16个。<br>可创建的音视频播放器实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放器实例。 |
| [OH_AVErrCode OH_AVPlayer_SetURLSource(OH_AVPlayer *player, const char *url)](#oh_avplayer_seturlsource) | - | 设置播放器的播放源。对应的源可以是http url。 |
| [OH_AVErrCode OH_AVPlayer_SetFDSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)](#oh_avplayer_setfdsource) | - | 设置播放器的媒体文件描述符来源。 |
| [OH_AVErrCode OH_AVPlayer_Prepare(OH_AVPlayer *player)](#oh_avplayer_prepare) | - | 准备播放环境，异步缓存媒体数据。<br>此函数必须在SetSource之后调用。 |
| [OH_AVErrCode OH_AVPlayer_Play(OH_AVPlayer *player)](#oh_avplayer_play) | - | 开始播放。<br>此函数必须在[OH_AVPlayer_Prepare](capi-avplayer-h.md#oh_avplayer_prepare)之后调用。<br>如果播放器状态为\<Prepared>，调用此函数开始播放。 |
| [OH_AVErrCode OH_AVPlayer_Pause(OH_AVPlayer *player)](#oh_avplayer_pause) | - | 暂停播放。 |
| [OH_AVErrCode OH_AVPlayer_Stop(OH_AVPlayer *player)](#oh_avplayer_stop) | - | 停止播放。 |
| [OH_AVErrCode OH_AVPlayer_Reset(OH_AVPlayer *player)](#oh_avplayer_reset) | - | 将播放器恢复到初始状态。<br>函数调用完成后，调用SetSource添加播放源。调用[OH_AVPlayer_Prepare](capi-avplayer-h.md#oh_avplayer_prepare)后，再调用[OH_AVPlayer_Play](capi-avplayer-h.md#oh_avplayer_play)重新开始播放。 |
| [OH_AVErrCode OH_AVPlayer_Release(OH_AVPlayer *player)](#oh_avplayer_release) | - | 异步释放播放器资源。异步释放可以提升性能，但不能确保播放画面的SurfaceBuffer已释放。调用者需要确保播放画面窗口的生命周期安全。 |
| [OH_AVErrCode OH_AVPlayer_ReleaseSync(OH_AVPlayer *player)](#oh_avplayer_releasesync) | - | 同步释放播放器资源。<br>同步过程保证了播放画面的SurfaceBuffer释放，但该过程耗时较长，建议调用者自行设计异步机制。 |
| [OH_AVErrCode OH_AVPlayer_SetVolume(OH_AVPlayer *player, float leftVolume, float rightVolume)](#oh_avplayer_setvolume) | - | 设置播放器的音量。<br>可以在播放或暂停的过程中使用。0表示无声音，1为原始值。 |
| [OH_AVErrCode OH_AVPlayer_Seek(OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)](#oh_avplayer_seek) | - | 改变播放位置。<br>此函数可以在播放或暂停时使用。 |
| [OH_AVErrCode OH_AVPlayer_GetCurrentTime(OH_AVPlayer *player, int32_t *currentTime)](#oh_avplayer_getcurrenttime) | - | 获取播放位置，精确到毫秒。 |
| [OH_AVErrCode OH_AVPlayer_GetVideoWidth(OH_AVPlayer *player, int32_t *videoWidth)](#oh_avplayer_getvideowidth) | - | 获取视频宽度。 |
| [OH_AVErrCode OH_AVPlayer_GetVideoHeight(OH_AVPlayer *player, int32_t *videoHeight)](#oh_avplayer_getvideoheight) | - | 获取视频高度。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed speed)](#oh_avplayer_setplaybackspeed) | - | 根据指定的{AVPlaybackSpeed}，设置播放器的播放速率。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackRate(OH_AVPlayer *player, float rate)](#oh_avplayer_setplaybackrate) | - | 在有效范围内，设置播放器的播放速率。<br>支持的状态：已准备/正在播放/已暂停/已完成。 |
| [OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed *speed)](#oh_avplayer_getplaybackspeed) | - | 获取当前播放器的播放速率。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo(OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)](#oh_avplayer_setaudiorendererinfo) | - | 设置player音频流类型。 |
| [OH_AVErrCode OH_AVPlayer_SetVolumeMode(OH_AVPlayer *player, OH_AudioStream_VolumeMode volumeMode)](#oh_avplayer_setvolumemode) | - | 设置player音频流音量模式。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode(OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)](#oh_avplayer_setaudiointerruptmode) | - | 设置player音频流的打断模式。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioEffectMode(OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)](#oh_avplayer_setaudioeffectmode) | - | 设置player音频流的音效模式。 |
| [OH_AVErrCode OH_AVPlayer_SelectBitRate(OH_AVPlayer *player, uint32_t bitRate)](#oh_avplayer_selectbitrate) | - | 设置hls播放器使用的码率。仅对HLS协议网络流有效。<br>默认情况下，播放器会根据网络连接情况选择合适的码率和速度。<br>通过INFO_TYPE_BITRATE_COLLECT上报有效码率链表，设置并选择指定的码率，选择小于和最接近的码率。准备好后，读取以查询当前选择的比特率。 |
| [OH_AVErrCode OH_AVPlayer_SetVideoSurface(OH_AVPlayer *player, OHNativeWindow *window)](#oh_avplayer_setvideosurface) | - | 设置播放画面窗口。<br>此函数必须在SetSource之后，Prepare之前调用。 |
| [OH_AVErrCode OH_AVPlayer_GetDuration(OH_AVPlayer *player, int32_t *duration)](#oh_avplayer_getduration) | - | 获取媒体文件的总时长，精确到毫秒。 |
| [OH_AVErrCode OH_AVPlayer_GetState(OH_AVPlayer *player, AVPlayerState *state)](#oh_avplayer_getstate) | - | 获取当前播放状态。 |
| [bool OH_AVPlayer_IsPlaying(OH_AVPlayer *player)](#oh_avplayer_isplaying) | - | 判断播放器是否在播放。 |
| [bool OH_AVPlayer_IsLooping(OH_AVPlayer *player)](#oh_avplayer_islooping) | - | 判断是否循环播放。 |
| [OH_AVErrCode OH_AVPlayer_SetLooping(OH_AVPlayer *player, bool loop)](#oh_avplayer_setlooping) | - | 设置循环播放。 |
| [OH_AVErrCode OH_AVPlayer_SetPlayerCallback(OH_AVPlayer *player, AVPlayerCallback callback)](#oh_avplayer_setplayercallback) | - | 设置播放器回调函数。<br>由于通过此方法设置的信息监听回调函数[OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo)和错误监听回调函数[OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)可以传递的信息有限，也不便于应用区分多个播放器实例。从API 12开始，应使用[OH_AVPlayer_SetOnInfoCallback](capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback](capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback)。 |
| [OH_AVErrCode OH_AVPlayer_SelectTrack(OH_AVPlayer *player, int32_t index)](#oh_avplayer_selecttrack) | - | 选择音频或字幕轨道。<br>默认播放第一个带数据的音轨，不播放字幕轨迹。<br>设置生效后，原音轨将失效。请设置字幕处于准备/播放/暂停/完成状态，并将音轨设置为准备状态。<br>该接口在当前版本暂不支持，将在后续版本开放能力。 |
| [OH_AVErrCode OH_AVPlayer_DeselectTrack(OH_AVPlayer *player, int32_t index)](#oh_avplayer_deselecttrack) | - | 取消选择当前音频或字幕轨道。<br>该接口在当前版本暂不支持，将在后续版本开放能力。 |
| [OH_AVErrCode OH_AVPlayer_GetCurrentTrack(OH_AVPlayer *player, int32_t trackType, int32_t *index)](#oh_avplayer_getcurrenttrack) | - | 获取当前有效的轨道索引。请将状态设置为准备/正在播放/暂停/完成状态。<br>该接口在当前版本暂不支持，将在后续版本开放能力。 |
| [OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback(OH_AVPlayer *player,Player_MediaKeySystemInfoCallback callback)](#oh_avplayer_setmediakeysysteminfocallback) | - | 设置播放器媒体密钥系统信息回调的方法。 |
| [OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo(OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#oh_avplayer_getmediakeysysteminfo) | - | 获取媒体密钥系统信息以创建媒体密钥会话。 |
| [OH_AVErrCode OH_AVPlayer_SetDecryptionConfig(OH_AVPlayer *player, MediaKeySession *mediaKeySession,bool secureVideoPath)](#oh_avplayer_setdecryptionconfig) | - | 设置解密信息。 |
| [OH_AVErrCode OH_AVPlayer_SetOnInfoCallback(OH_AVPlayer *player, OH_AVPlayerOnInfoCallback callback, void *userData)](#oh_avplayer_setoninfocallback) | - | 设置播放器消息回调监听函数。 |
| [OH_AVErrCode OH_AVPlayer_SetOnErrorCallback(OH_AVPlayer *player, OH_AVPlayerOnErrorCallback callback, void *userData)](#oh_avplayer_setonerrorcallback) | - | 设置播放器错误回调监听函数。 |

## 函数说明

### Player_MediaKeySystemInfoCallback()

```
typedef void (*Player_MediaKeySystemInfoCallback)(OH_AVPlayer *player, DRM_MediaKeySystemInfo* mediaKeySystemInfo)
```

**描述**

播放器DRM信息更新时调用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [DRM_MediaKeySystemInfo](capi-drm-mediakeysysteminfo.md)* mediaKeySystemInfo | DRM信息。 |

### OH_AVPlayer_Create()

```
OH_AVPlayer *OH_AVPlayer_Create(void)
```

**描述**

创建播放器。<br>推荐单个应用创建的音视频播放器实例（即音频、视频、音视频三类相加）不超过16个。

<!--Del-->可创建的音视频播放器实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放器实例。<!--DelEnd-->

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) | 如果创建成功返回指向OH_AVPlayer实例的指针，否则返回空指针。<br> 可能的失败原因：<br> 1.PlayerFactory::CreatePlayer执行失败。<br> 2.new PlayerObject执行失败。 |

### OH_AVPlayer_SetURLSource()

```
OH_AVErrCode OH_AVPlayer_SetURLSource(OH_AVPlayer *player, const char *url)
```

**描述**

设置播放器的播放源。对应的源可以是http url。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| const char *url | 播放源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：设置成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，url为空或者player SetUrlSource执行失败。 |

### OH_AVPlayer_SetFDSource()

```
OH_AVErrCode OH_AVPlayer_SetFDSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
```

**描述**

设置播放器的媒体文件描述符来源。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t fd | 媒体源的文件描述符。 |
| int64_t offset | 媒体源在文件描述符中的偏移量。 |
| int64_t size | 表示媒体源的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：fd设置成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetFdSource执行失败。 |

### OH_AVPlayer_Prepare()

```
OH_AVErrCode OH_AVPlayer_Prepare(OH_AVPlayer *player)
```

**描述**

准备播放环境，异步缓存媒体数据。<br>此函数必须在SetSource之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Prepare执行失败。 |

### OH_AVPlayer_Play()

```
OH_AVErrCode OH_AVPlayer_Play(OH_AVPlayer *player)
```

**描述**

开始播放。<br>此函数必须在[OH_AVPlayer_Prepare](capi-avplayer-h.md#oh_avplayer_prepare)之后调用。<br>如果播放器状态为\<Prepared>，调用此函数开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Play执行失败。 |

### OH_AVPlayer_Pause()

```
OH_AVErrCode OH_AVPlayer_Pause(OH_AVPlayer *player)
```

**描述**

暂停播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Pause执行失败。 |

### OH_AVPlayer_Stop()

```
OH_AVErrCode OH_AVPlayer_Stop(OH_AVPlayer *player)
```

**描述**

停止播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Stop执行失败。 |

### OH_AVPlayer_Reset()

```
OH_AVErrCode OH_AVPlayer_Reset(OH_AVPlayer *player)
```

**描述**

将播放器恢复到初始状态。<br>函数调用完成后，调用SetSource添加播放源。调用[OH_AVPlayer_Prepare](capi-avplayer-h.md#oh_avplayer_prepare)后，再调用[OH_AVPlayer_Play](capi-avplayer-h.md#oh_avplayer_play)重新开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Reset执行失败。 |

### OH_AVPlayer_Release()

```
OH_AVErrCode OH_AVPlayer_Release(OH_AVPlayer *player)
```

**描述**

异步释放播放器资源。<br>异步释放可以提升性能，但不能确保播放画面的SurfaceBuffer已释放。调用者需要确保播放画面窗口的生命周期安全。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Release执行失败。 |

### OH_AVPlayer_ReleaseSync()

```
OH_AVErrCode OH_AVPlayer_ReleaseSync(OH_AVPlayer *player)
```

**描述**

同步释放播放器资源。<br>同步过程保证了播放画面的SurfaceBuffer释放，但该过程耗时较长，建议调用者自行设计异步机制。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player ReleaseSync执行失败。 |

### OH_AVPlayer_SetVolume()

```
OH_AVErrCode OH_AVPlayer_SetVolume(OH_AVPlayer *player, float leftVolume, float rightVolume)
```

**描述**

设置播放器的音量。<br>可以在播放或暂停的过程中使用。0表示无声音，1为原始值。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| float leftVolume | 要设置的左声道目标音量。 |
| float rightVolume | 要设置的右声道目标音量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置音量。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetVolume执行失败。 |

### OH_AVPlayer_Seek()

```
OH_AVErrCode OH_AVPlayer_Seek(OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)
```

**描述**

改变播放位置。<br>此函数可以在播放或暂停时使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t mSeconds | 播放目标位置，精确到毫秒。 |
| [AVPlayerSeekMode](capi-avplayer-base-h.md#avplayerseekmode) mode | 播放器的跳转模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Seek执行失败。 |

### OH_AVPlayer_GetCurrentTime()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTime(OH_AVPlayer *player, int32_t *currentTime)
```

**描述**

获取播放位置，精确到毫秒。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *currentTime | 播放位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取当前播放位置。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetCurrentTime执行失败。 |

### OH_AVPlayer_GetVideoWidth()

```
OH_AVErrCode OH_AVPlayer_GetVideoWidth(OH_AVPlayer *player, int32_t *videoWidth)
```

**描述**

获取视频宽度。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *videoWidth | 视频宽度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取视频宽度。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_GetVideoHeight()

```
OH_AVErrCode OH_AVPlayer_GetVideoHeight(OH_AVPlayer *player, int32_t *videoHeight)
```

**描述**

获取视频高度。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *videoHeight | 视频高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取视频高度。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_SetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed speed)
```

**描述**

根据指定的[AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed)，设置播放器的播放速率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed) speed | 速率模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置播放速率。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_SetPlaybackRate()

```
OH_AVErrCode OH_AVPlayer_SetPlaybackRate(OH_AVPlayer *player, float rate)
```

**描述**

在有效范围内，设置播放器的播放速率。<br>支持的状态：已准备/正在播放/已暂停/已完成。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| float rate | 播放速率，有效范围是0.125~4。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置播放速率。<br>         AV_ERR_OPERATE_NOT_PERMIT：如果在不支持的状态下调用或在直播期间调用。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者速率超出范围。 |

### OH_AVPlayer_GetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed *speed)
```

**描述**

获取当前播放器的播放速率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed) *speed | 速率模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取播放速率。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetPlaybackSpeed执行失败。 |

### OH_AVPlayer_SetAudioRendererInfo()

```
OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo(OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)
```

**描述**

设置player音频流类型。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage) streamUsage | player音频流设置的类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置音频流类型。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者streamUsage值无效。 |

### OH_AVPlayer_SetVolumeMode()

```
OH_AVErrCode OH_AVPlayer_SetVolumeMode(OH_AVPlayer *player, OH_AudioStream_VolumeMode volumeMode)
```

**描述**

设置player音频流音量模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_VolumeMode](../apis-audio-kit/capi-native-audiostream-base-h.md) volumeMode | 指定音频流音量模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置音频流音量模式。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者volumeMode值无效。<br>         AV_ERR_INVALID_STATE：函数在无效状态下调用，应先处于准备状态。<br>         AV_ERR_SERVICE_DIED：系统错误。 |

### OH_AVPlayer_SetAudioInterruptMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode(OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)
```

**描述**

设置player音频流的打断模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioInterrupt_Mode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_mode) interruptMode | player音频流使用的打断模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置音频流的打断模式。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者interruptMode值无效。 |

### OH_AVPlayer_SetAudioEffectMode()

```
OH_AVErrCode OH_AVPlayer_SetAudioEffectMode(OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)
```

**描述**

设置player音频流的音效模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_AudioEffectMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode) effectMode | player音频流使用的音效模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置音频流的音效模式。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者effectMode值无效。 |

### OH_AVPlayer_SelectBitRate()

```
OH_AVErrCode OH_AVPlayer_SelectBitRate(OH_AVPlayer *player, uint32_t bitRate)
```

**描述**

设置hls播放器使用的码率。仅对HLS协议网络流有效。<br>默认情况下，播放器会根据网络连接情况选择合适的码率和速度。<br>通过INFO_TYPE_BITRATE_COLLECT上报有效码率链表，设置并选择指定的码率，选择小于和最接近的码率。准备好后，读取以查询当前选择的比特率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| uint32_t bitRate | 码率，单位为bps。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置码率。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SelectBitRate执行失败。 |

### OH_AVPlayer_SetVideoSurface()

```
OH_AVErrCode OH_AVPlayer_SetVideoSurface(OH_AVPlayer *player, OHNativeWindow *window)
```

**描述**

设置播放画面窗口。<br>此函数必须在SetSource之后，Prepare之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| OHNativeWindow *window | 指向OHNativeWindow实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置播放画面窗口。<br>         AV_ERR_INVALID_VAL：输入player为空指针，输入window为空指针或者player SetVideoSurface执行失败。 |

### OH_AVPlayer_GetDuration()

```
OH_AVErrCode OH_AVPlayer_GetDuration(OH_AVPlayer *player, int32_t *duration)
```

**描述**

获取媒体文件的总时长，精确到毫秒。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *duration | 媒体文件的总时长。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取媒体文件时长。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetDuration执行失败。 |

### OH_AVPlayer_GetState()

```
OH_AVErrCode OH_AVPlayer_GetState(OH_AVPlayer *player, AVPlayerState *state)
```

**描述**

获取当前播放状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlayerState](capi-avplayer-base-h.md#avplayerstate) *state | 当前播放状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取当前播放状态。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetState执行失败。 |

### OH_AVPlayer_IsPlaying()

```
bool OH_AVPlayer_IsPlaying(OH_AVPlayer *player)
```

**描述**

判断播放器是否在播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果正在播放，则返回true；如果不在播放或者输入player为空指针则返回false。 |

### OH_AVPlayer_IsLooping()

```
bool OH_AVPlayer_IsLooping(OH_AVPlayer *player)
```

**描述**

判断是否循环播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果是循环播放，则返回true；如果不是循环播放或者输入player为空指针则返回false。 |

### OH_AVPlayer_SetLooping()

```
OH_AVErrCode OH_AVPlayer_SetLooping(OH_AVPlayer *player, bool loop)
```

**描述**

设置循环播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| bool loop | 循环播放开关。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置循环播放。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetLooping执行失败。 |

### OH_AVPlayer_SetPlayerCallback()

```
OH_AVErrCode OH_AVPlayer_SetPlayerCallback(OH_AVPlayer *player, AVPlayerCallback callback)
```

**描述**

设置播放器回调函数。<br>由于通过此方法设置的信息监听回调函数[OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo)和错误监听回调函数[OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)可以传递的信息有限，也不便于应用区分多个播放器实例。

从API 12开始，应使用[OH_AVPlayer_SetOnInfoCallback](capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback](capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlayerCallback](capi-avplayercallback.md) callback | 回调对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功设置播放器回调。<br>         AV_ERR_INVALID_VAL：输入player为空指针，callback.onInfo或onError为空，或者player SetPlayerCallback执行失败。 |

### OH_AVPlayer_SelectTrack()

```
OH_AVErrCode OH_AVPlayer_SelectTrack(OH_AVPlayer *player, int32_t index)
```

**描述**

选择音频或字幕轨道。<br>默认播放第一个带数据的音轨，不播放字幕轨迹。<br>设置生效后，原音轨将失效。请设置字幕处于准备/播放/暂停/完成状态，并将音轨设置为准备状态。

该接口在当前版本暂不支持，将在后续版本开放能力。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t index | 索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SelectTrack执行失败。 |

### OH_AVPlayer_DeselectTrack()

```
OH_AVErrCode OH_AVPlayer_DeselectTrack(OH_AVPlayer *player, int32_t index)
```

**描述**

取消选择当前音频或字幕轨道。

该接口在当前版本暂不支持，将在后续版本开放能力。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t index | 索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player DeselectTrack执行失败。 |

### OH_AVPlayer_GetCurrentTrack()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTrack(OH_AVPlayer *player, int32_t trackType, int32_t *index)
```

**描述**

获取当前有效的轨道索引。请将状态设置为准备/正在播放/暂停/完成状态。

该接口在当前版本暂不支持，将在后续版本开放能力。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t trackType | 媒体类型。0：音频，1：视频。 |
| int32_t *index | 索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：成功获取轨道索引。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetCurrentTrack执行失败。 |

### OH_AVPlayer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback(OH_AVPlayer *player,Player_MediaKeySystemInfoCallback callback)
```

**描述**

设置播放器媒体密钥系统信息回调的方法。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [Player_MediaKeySystemInfoCallback](#player_mediakeysysteminfocallback) callback | 对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，callback为空指针，player SetDrmSystemInfoCallback，<br> SetDrmSystemInfoCallback或SetDrmSystemInfoCallback执行失败。 |

### OH_AVPlayer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo(OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

获取媒体密钥系统信息以创建媒体密钥会话。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [DRM_MediaKeySystemInfo](capi-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | 媒体密钥系统信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者内存不足。 |

### OH_AVPlayer_SetDecryptionConfig()

```
OH_AVErrCode OH_AVPlayer_SetDecryptionConfig(OH_AVPlayer *player, MediaKeySession *mediaKeySession,bool secureVideoPath)
```

**描述**

设置解密信息。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [MediaKeySession](capi-mediakeysession.md) *mediaKeySession | 具有解密功能的媒体密钥会话实例。 |
| bool secureVideoPath | 是否需要安全解码器。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者player SetDecryptionConfig执行失败。 |

### OH_AVPlayer_SetOnInfoCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnInfoCallback(OH_AVPlayer *player, OH_AVPlayerOnInfoCallback callback, void *userData)
```

**描述**

设置播放器消息回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) callback | 执行回调监听函数的指针，空指针表示取消设置播放器消息回调监听。 |
| void *userData | 指向应用调用者设置的实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入分配内存失败。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者函数执行失败。 |

### OH_AVPlayer_SetOnErrorCallback()

```
OH_AVErrCode OH_AVPlayer_SetOnErrorCallback(OH_AVPlayer *player, OH_AVPlayerOnErrorCallback callback, void *userData)
```

**描述**

设置播放器错误回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback) callback | 执行回调监听函数的指针，空指针表示取消设置播放器错误回调监听。 |
| void *userData | 指向应用调用者设置的实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入分配内存失败。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者函数执行失败。 |


