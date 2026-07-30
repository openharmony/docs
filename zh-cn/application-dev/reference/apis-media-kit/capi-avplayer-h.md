# avplayer.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chennotfound-->
<!--Designer: @chennotfound-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

AVPlayer是音视频播放组件，提供完整的播放控制和高级功能（多轨道、字幕、DRM等），适用于视频播放器、音频播放器、直播应用等场景，为开发者提供高性能、低延迟的媒体播放能力，降低开发复杂度。

**引用文件：** <multimedia/player_framework/avplayer.h>

**库：** libavplayer.so

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**相关模块：** [AVPlayer](capi-avplayer.md)

**相关示例：** [AVPlayerNDKVideo](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerNDK)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [MediaKeySession](capi-avplayer-mediakeysession.md) | MediaKeySession | MediaKeySession类型。 |
| [DRM_MediaKeySystemInfo](capi-avplayer-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | DRM_MediaKeySystemInfo类型。 |
| [OH_AVPlayerVideoOutput](capi-avplayer-oh-avplayervideooutput.md) | OH_AVPlayerVideoOutput | OH_AVPlayerVideoOutput字段。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*Player_MediaKeySystemInfoCallback)(OH_AVPlayer *player, DRM_MediaKeySystemInfo* mediaKeySystemInfo)](#player_mediakeysysteminfocallback) | Player_MediaKeySystemInfoCallback | 播放器DRM信息更新时调用。 |
| [OH_AVPlayer *OH_AVPlayer_Create(void)](#oh_avplayer_create) | - | 创建播放器。<br> 推荐单个应用创建的音视频播放器实例总数不超过16个。<!--Del--><br> 可创建的音视频播放器实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放器实例。<!--DelEnd--> |
| [OH_AVErrCode OH_AVPlayer_SetURLSource(OH_AVPlayer *player, const char *url)](#oh_avplayer_seturlsource) | - | 设置播放器的播放源。对应的源可以是HTTP URL或HTTPS URL。 |
| [OH_AVErrCode OH_AVPlayer_SetFDSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)](#oh_avplayer_setfdsource) | - | 设置播放器的媒体文件描述符来源。 |
| [OH_AVErrCode OH_AVPlayer_SetDataSource(OH_AVPlayer \*player, OH_AVDataSourceExt\* datasrc, void* userData)](#oh_avplayer_setdatasource) | - | 设置播放器的媒体源，该媒体源的数据由应用程序提供。 |
| [OH_AVErrCode OH_AVPlayer_Prepare(OH_AVPlayer *player)](#oh_avplayer_prepare) | - | 准备播放环境，异步缓存媒体数据。<br> 此函数必须在SetSource之后调用。 |
| [OH_AVErrCode OH_AVPlayer_Play(OH_AVPlayer *player)](#oh_avplayer_play) | - | 开始播放。<br> 此函数必须在[OH_AVPlayer_Prepare](#oh_avplayer_prepare)之后调用。<br> 如果播放器状态为\<Prepared>，调用此函数开始播放。 |
| [OH_AVErrCode OH_AVPlayer_Pause(OH_AVPlayer *player)](#oh_avplayer_pause) | - | 暂停播放。播放器处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_Stop(OH_AVPlayer *player)](#oh_avplayer_stop) | - | 停止播放。播放器处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_Reset(OH_AVPlayer *player)](#oh_avplayer_reset) | - | 将播放器恢复到初始状态。<br> 函数调用完成后，调用SetSource添加播放源。调用[OH_AVPlayer_Prepare](#oh_avplayer_prepare)后，再调用[OH_AVPlayer_Play](#oh_avplayer_play)重新开始播放。 |
| [OH_AVErrCode OH_AVPlayer_Release(OH_AVPlayer *player)](#oh_avplayer_release) | - | 异步释放播放器资源。<br> 异步释放可以提升性能，但不能确保播放画面的SurfaceBuffer已释放。调用者需要确保播放画面窗口的生命周期安全。 |
| [OH_AVErrCode OH_AVPlayer_ReleaseSync(OH_AVPlayer *player)](#oh_avplayer_releasesync) | - | 同步释放播放器资源。<br> 同步过程保证了播放画面的SurfaceBuffer释放，但该过程耗时较长，建议调用者自行设计异步机制。 |
| [OH_AVErrCode OH_AVPlayer_SetVolume(OH_AVPlayer *player, float leftVolume, float rightVolume)](#oh_avplayer_setvolume) | - | 设置播放器的音量。<br> 可以在播放或暂停的过程中使用。0表示无声音，1为原始值。默认音量为1。 |
| [OH_AVErrCode OH_AVPlayer_SetLoudnessGain(OH_AVPlayer *player, float loudnessGain)](#oh_avplayer_setloudnessgain) | - | 设置播放器的响度。当播放处于prepared、playing、paused、completed或stopped状态时，可调用该接口。<br> 默认响度增益0.0dB。播放器流的usage参数必须是以下枚举值之一：[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC、[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MOVIE和[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK。<br> 音频渲染器的延迟模式必须是[OH_AudioStream_LatencyMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL。<br> 如果通过高分辨率管道播放，则不支持此操作。 |
| [OH_AVErrCode OH_AVPlayer_Seek(OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)](#oh_avplayer_seek) | - | 改变播放位置。<br> 此函数可以在播放或暂停时使用。 |
| [OH_AVErrCode OH_AVPlayer_GetCurrentTime(OH_AVPlayer *player, int32_t *currentTime)](#oh_avplayer_getcurrenttime) | - | 获取当前播放时间（通过参数返回），精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_GetVideoWidth(OH_AVPlayer *player, int32_t *videoWidth)](#oh_avplayer_getvideowidth) | - | 获取视频宽度。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_GetVideoHeight(OH_AVPlayer *player, int32_t *videoHeight)](#oh_avplayer_getvideoheight) | - | 获取视频高度。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed speed)](#oh_avplayer_setplaybackspeed) | - | 根据指定的[AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed)，设置播放器的播放速率。默认播放速率为1.0倍速（正常速度）。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackRate(OH_AVPlayer *player, float rate)](#oh_avplayer_setplaybackrate) | - | 在有效范围内，设置播放器的播放速率。<br> 支持的状态包括prepared、playing、paused、completed。默认播放速率为1.0倍速（正常速度）。 |
| [OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed *speed)](#oh_avplayer_getplaybackspeed) | - | 获取当前播放器的播放速率。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_GetPlaybackRate(OH_AVPlayer *player, float *rate)](#oh_avplayer_getplaybackrate) | - | 获取当前播放器播放速率。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo(OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)](#oh_avplayer_setaudiorendererinfo) | - | 设置player音频流类型。 |
| [OH_AVErrCode OH_AVPlayer_SetVolumeMode(OH_AVPlayer *player, OH_AudioStream_VolumeMode volumeMode)](#oh_avplayer_setvolumemode) | - | 设置player音频流音量模式。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode(OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)](#oh_avplayer_setaudiointerruptmode) | - | 设置player音频流的打断模式。 |
| [OH_AVErrCode OH_AVPlayer_SetAudioEffectMode(OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)](#oh_avplayer_setaudioeffectmode) | - | 设置player音频流的音效模式。 |
| [OH_AVErrCode OH_AVPlayer_SelectBitRate(OH_AVPlayer *player, uint32_t bitRate)](#oh_avplayer_selectbitrate) | - | 设置HLS播放器使用的码率。仅对HLS协议网络流有效。此接口仅可在AVPlayer处于prepared、playing或者paused状态时调用。<br> 默认情况下，播放器会根据网络连接情况选择合适的码率和速度。<br> 通过INFO_TYPE_BITRATE_COLLECT上报有效码率列表，如果用户指定的码率不在此列表中，播放器将从可用码率列表中选择最接近的码率。 |
| [OH_AVErrCode OH_AVPlayer_SetVideoSurface(OH_AVPlayer *player, OHNativeWindow *window)](#oh_avplayer_setvideosurface) | - | 设置播放画面窗口。<br> 此函数必须在SetSource之后，Prepare之前调用。 |
| [OH_AVErrCode OH_AVPlayer_GetDuration(OH_AVPlayer *player, int32_t *duration)](#oh_avplayer_getduration) | - | 获取媒体文件的总时长，精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_GetState(OH_AVPlayer *player, AVPlayerState *state)](#oh_avplayer_getstate) | - | 获取当前播放状态。 |
| [bool OH_AVPlayer_IsPlaying(OH_AVPlayer *player)](#oh_avplayer_isplaying) | - | 判断播放器是否在播放。此接口可在AVPlayer处于任何状态下调用，但返回结果的有效性依赖于当前状态。 |
| [bool OH_AVPlayer_IsLooping(OH_AVPlayer *player)](#oh_avplayer_islooping) | - | 判断是否循环播放。此接口可在AVPlayer处于任何状态下调用。 |
| [OH_AVErrCode OH_AVPlayer_SetLooping(OH_AVPlayer *player, bool loop)](#oh_avplayer_setlooping) | - | 设置循环播放。默认不循环播放。 |
| [OH_AVErrCode OH_AVPlayer_SetPlayerCallback(OH_AVPlayer *player, AVPlayerCallback callback)](#oh_avplayer_setplayercallback) | - | 设置播放器回调函数。<br> 由于通过此方法设置的信息监听回调函数[OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo)和错误监听回调函数[OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)可以传递的信息有限，也不便于应用区分多个播放器实例。<br> 从API version 12开始，应使用[OH_AVPlayer_SetOnInfoCallback](#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback](#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback)。<br>从API version 12开始废弃。 |
| [OH_AVErrCode OH_AVPlayer_SelectTrack(OH_AVPlayer *player, int32_t index)](#oh_avplayer_selecttrack) | - | 选择音频或字幕轨道。<br> 默认播放第一个带数据的音轨，不播放字幕轨道。<br> 设置生效后，原音轨将失效。选择字幕轨道时，播放器应处于prepared、playing、paused或completed状态；选择音轨时，播放器应处于prepared状态。 |
| [OH_AVErrCode OH_AVPlayer_DeselectTrack(OH_AVPlayer *player, int32_t index)](#oh_avplayer_deselecttrack) | - | 取消选择当前音频或字幕轨道。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_GetCurrentTrack(OH_AVPlayer *player, int32_t trackType, int32_t *index)](#oh_avplayer_getcurrenttrack) | - | 获取当前有效的轨道索引。调用该接口时，播放器应处于prepared、playing、paused或completed状态。 |
| [OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback(OH_AVPlayer *player, Player_MediaKeySystemInfoCallback callback)](#oh_avplayer_setmediakeysysteminfocallback) | - | 设置播放器媒体密钥系统信息回调的方法。适用于播放DRM加密媒体内容的场景，如监听DRM信息更新、获取加密内容密钥、处理版权保护内容等。 |
| [OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo(OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#oh_avplayer_getmediakeysysteminfo) | - | 获取媒体密钥系统信息以创建媒体密钥会话。 |
| [OH_AVErrCode OH_AVPlayer_SetDecryptionConfig(OH_AVPlayer *player, MediaKeySession *mediaKeySession, bool secureVideoPath)](#oh_avplayer_setdecryptionconfig) | - | 设置解密信息。适用于DRM加密媒体内容的场景，如播放加密视频、播放付费内容、播放受版权保护的媒体资源等。 |
| [OH_AVErrCode OH_AVPlayer_SetOnInfoCallback(OH_AVPlayer *player, OH_AVPlayerOnInfoCallback callback, void *userData)](#oh_avplayer_setoninfocallback) | - | 设置播放器消息回调监听函数。 |
| [OH_AVErrCode OH_AVPlayer_SetOnErrorCallback(OH_AVPlayer *player, OH_AVPlayerOnErrorCallback callback, void *userData)](#oh_avplayer_setonerrorcallback) | - | 设置播放器错误回调监听函数。 |
| [OH_AVFormat *OH_AVPlayer_GetMediaDescription(OH_AVPlayer *player)](#oh_avplayer_getmediadescription) | - | 获取播放器媒体源信息。设置完播放资源并且播放处于initialized/prepared/playing/paused/completed/stopped状态，可调用该接口。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。 |
| [OH_AVFormat *OH_AVPlayer_GetTrackDescription(OH_AVPlayer *player, uint32_t index)](#oh_avplayer_gettrackdescription) | - | 通过索引下标获取播放器媒体源轨道信息。设置完播放资源并且播放处于initialized/prepared/playing/paused/completed/stopped状态，可调用该接口。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。 |
| [OH_AVErrCode OH_AVPlayer_AddFdSubtitleSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)](#oh_avplayer_addfdsubtitlesource) | - | 将文件描述符字幕资源添加到播放器。目前，外挂字幕必须在AVPlayer设置完视频资源的fdSrc之后再设置。 |
| [OH_AVErrCode OH_AVPlayer_AddUrlSubtitleSource(OH_AVPlayer *player, const char *url)](#oh_avplayer_addurlsubtitlesource) | - | 将URL字幕资源添加到播放器。外挂字幕必须在AVPlayer设置完URL之后再设置。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackRange(OH_AVPlayer *player, int32_t mSecondsStart, int32_t mSecondsEnd, bool closestRange)](#oh_avplayer_setplaybackrange) | - | 设置播放起始位置和结束位置。仅播放指定范围内的内容。可在初始化、已准备、暂停、停止或完成状态下调用。 |
| [OH_AVErrCode OH_AVPlayer_SetMediaMuted(OH_AVPlayer *player, OH_MediaType mediaType, bool muted)](#oh_avplayer_setmediamuted) | - | 静音媒体流。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [int32_t OH_AVPlayer_GetPlaybackPosition(OH_AVPlayer *player)](#oh_avplayer_getplaybackposition) | - | 获取播放位置，精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [bool OH_AVPlayer_IsSeekContinuousSupported(OH_AVPlayer *player)](#oh_avplayer_isseekcontinuoussupported) | - | 检查媒体源是否支持连续跳转。在prepared、playing、paused或completed状态下调用时返回实际值；在其他状态下调用时返回false。对于不支持[AV_SEEK_CONTINUOUS](capi-avplayer-base-h.md#avplayerseekmode)模式跳转操作的设备，返回false。 |
| [OH_AVErrCode OH_AVPlayer_SelectTrackWithMode(OH_AVPlayer *player, int32_t index, AVPlayerTrackSwitchMode mode)](#oh_avplayer_selecttrackwithmode) | - | 在播放包含多个音视频轨道的资源时，使用指定的切换模式选择轨道。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVErrCode OH_AVPlayer_SetAmplitudeUpdateCallback(OH_AVPlayer *player, OH_AVPlayerOnAmplitudeUpdateCallback callback, void *userData)](#oh_avplayer_setamplitudeupdatecallback) | - | 订阅最大音频电平值的更新事件，该值在播放音频资源时周期性上报。适用于需要音频可视化或音频强度检测的场景，如音频波形显示、音频强度可视化、音频能量检测等。 |
| [OH_AVErrCode OH_AVPlayer_SetSeiReceivedCallback(OH_AVPlayer *player, const int32_t *payloadTypes, uint32_t typeNum, OH_AVPlayerOnSeiMessageReceivedCallback callback, void *userData)](#oh_avplayer_setseireceivedcallback) | - | 订阅接收到补充增强信息（SEI）消息的事件。仅适用于HTTP-FLV直播流，当视频流中存在SEI消息时触发。必须在调用prepare之前发起订阅。 |
| [uint32_t OH_AVSeiMessage_GetSeiCount(OH_AVSeiMessageArray *message)](#oh_avseimessage_getseicount) | - | 获取SEI消息数组中的消息项数量。 |
| [OH_AVFormat *OH_AVSeiMessage_GetSei(OH_AVSeiMessageArray *message, uint32_t index)](#oh_avseimessage_getsei) | - | 通过索引获取SEI（Supplemental Enhancement Information）消息数组中某一项的SEI。需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。 |
| [OH_AVErrCode OH_AVPlayer_SetTargetVideoWindowSize(OH_AVPlayer *player, int32_t width, int32_t height)](#oh_avplayer_settargetvideowindowsize) | - | 为超分辨率设置视频窗口大小。此接口可在AVPlayer处于idle、prepared、playing、paused、completed或stopped状态时调用。输入参数值必须在320x320至1920x1080范围内。单位为像素（px）。适用于超分辨率视频显示的场景，如低分辨率视频画质提升、视频增强显示等。 |
| [OH_AVErrCode OH_AVPlayer_SetVideoSuperResolutionEnable(OH_AVPlayer *player, bool enabled)](#oh_avplayer_setvideosuperresolutionenable) | - | 动态启用或禁用超分辨率。此接口可在AVPlayer处于idle、prepared、playing、paused、completed或stopped状态时调用。必须在调用prepare之前在[OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md)中启用超分辨率功能。适用于需要动态控制视频画质增强的场景，如根据设备性能动态调整、根据网络状态切换画质等。 |
| [OH_AVPlaybackStrategy *OH_AVPlaybackStrategy_Create(void)](#oh_avplaybackstrategy_create) | - | 创建一个播放策略实例。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_Destroy(OH_AVPlaybackStrategy *strategy)](#oh_avplaybackstrategy_destroy) | - | 释放一个播放策略实例。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredWidth(OH_AVPlaybackStrategy *strategy, int32_t width)](#oh_avplaybackstrategy_setpreferredwidth) | - | 选择接近指定宽度的流。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHeight(OH_AVPlaybackStrategy *strategy, int32_t height)](#oh_avplaybackstrategy_setpreferredheight) | - | 选择接近指定高度的流。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDuration(OH_AVPlaybackStrategy *strategy, int32_t ms)](#oh_avplaybackstrategy_setpreferredbufferduration) | - | 选择接近指定值的首选缓冲时长。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHdr(OH_AVPlaybackStrategy *strategy, bool enabled)](#oh_avplaybackstrategy_setpreferredhdr) | - | 启用或禁用首选HDR模式。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredSubtitleLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)](#oh_avplaybackstrategy_setpreferredsubtitlelanguage) | - | 设置首选字幕语言。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredAudioLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)](#oh_avplaybackstrategy_setpreferredaudiolanguage) | - | 设置首选音频语言。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetMutedMediaType(OH_AVPlaybackStrategy *strategy, OH_MediaType mediaType)](#oh_avplaybackstrategy_setmutedmediatype) | - | 设置播放时要静音的媒体类型。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetShowFirstFrameOnPrepare(OH_AVPlaybackStrategy *strategy, bool enabled)](#oh_avplaybackstrategy_setshowfirstframeonprepare) | - | 设置是否在prepare时显示首帧。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetThresholdForAutoQuickPlay(OH_AVPlaybackStrategy *strategy, double seconds)](#oh_avplaybackstrategy_setthresholdforautoquickplay) | - | 设置自动快速播放的阈值。当缓冲数据不足导致播放可能卡顿时，播放器会自动提高播放速率快速播放已缓存内容，该阈值是控制触发此行为的条件。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetSuperResolutionEnable(OH_AVPlaybackStrategy *strategy, bool enabled)](#oh_avplaybackstrategy_setsuperresolutionenable) | - | 启用或禁用超分辨率。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDurationForPlaying(OH_AVPlaybackStrategy *strategy, double seconds)](#oh_avplaybackstrategy_setpreferredbufferdurationforplaying) | - | 设置播放时的首选缓冲时长（秒，double类型）。 |
| [OH_AVErrCode OH_AVPlaybackStrategy_SetKeepDecodingOnMute(OH_AVPlaybackStrategy *strategy, bool enabled)](#oh_avplaybackstrategy_setkeepdecodingonmute) | - | 设置静音时是否继续解码。 |
| [OH_AVErrCode OH_AVPlayer_SetPlaybackStrategy(OH_AVPlayer *player, OH_AVPlaybackStrategy *strategy)](#oh_avplayer_setplaybackstrategy) | - | 将播放策略设置给AVPlayer。此接口仅可在AVPlayer处于初始化状态时调用。 |
| [OH_AVFormat* OH_AVPlayer_GetPlaybackInfo(OH_AVPlayer *player)](#oh_avplayer_getplaybackinfo) | - | 获取当前播放器的统计信息。此接口仅可在AVPlayer处于prepared、playing或者paused状态时调用。需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。 |
| [OH_AVErrCode OH_AVPlayer_SetMediaSource(OH_AVPlayer *player, OH_AVMediaSource *source)](#oh_avplayer_setmediasource) | - | 将OH_AVMediaSource设置给播放器。 |
| [uint32_t OH_AVPlayer_GetTrackCount(OH_AVPlayer *player)](#oh_avplayer_gettrackcount) | - | 获取播放器媒体源的轨道数量。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。 |
| [OH_AVFormat *OH_AVPlayer_GetTrackFormat(OH_AVPlayer *player, uint32_t trackIndex)](#oh_avplayer_gettrackformat) | - | 通过索引获取播放器轨道信息。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。 |
| [OH_AVFormat *OH_AVPlayer_GetPlaybackStatisticMetrics(OH_AVPlayer *player)](#oh_avplayer_getplaybackstatisticmetrics) | - | 获取当前播放器的统计指标信息。设置完播放资源，并且当播放处于prepared、playing、paused、completed或stopped状态时，可调用该接口。<br> 需要注意返回值[OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md)指针对象的生命周期需要用户手动释放。 |
| [OH_AVErrCode OH_AVPlayer_SetPCMOutputCallback(OH_AVPlayer *player, OH_AVPlayerPCMOutputCallback callback, void *userData)](#oh_avplayer_setpcmoutputcallback) | - | 设置音频PCM数据输出回调。当播放处于idle或initialized状态时，可调用此接口。适用于需要获取音频原始数据的场景，如音频数据分析、音频录制、音频处理、音频可视化等。 |
| [OH_AVPlayerVideoOutput* OH_AVPlayer_SetVideoSideOutput(OH_AVPlayer *player, OHNativeWindow *window)](#oh_avplayer_setvideosideoutput) | - | 设置视频解码帧输出回调。当播放处于idle或initialized状态时，可调用此接口。适用于需要获取视频解密帧的场景，如视频帧分析、视频滤镜处理、视频截图、视频特效处理等。 |
| [OH_VideoOutputResult OH_AVPlayerVideoOutput_GetNewestVideoSample(OH_AVPlayerVideoOutput *videoOutput)](#oh_avplayervideooutput_getnewestvideosample) | - | 获得一个视频解码帧。当播放处于paused或playing状态时，可调用此接口。适用于需要获取当前视频帧的场景，如视频帧捕获、视频帧分析、视频截图、视频帧处理等。 |
| [OH_AVErrCode OH_AVPlayer_SetPCMProcessorCallback(OH_AVPlayer *player, OH_AVPlayerPCMProcessorCallback callback, void *userData)](#oh_avplayer_setpcmprocessorcallback) | - | 设置音频PCM数据后处理回调。当播放处于idle或initialized状态时，可调用此接口。 |
| [OH_AVErrCode OH_AVPlayer_SetPCMProcessorMaxLen(OH_AVPlayer *player, int32_t maxProcessedPCMLen)](#oh_avplayer_setpcmprocessormaxlen) | - | 设置音频后处理回调函数单次可返回的最大数据量。允许缓存部分数据，并与下一次返回的PCM数据一并输出。<br> 当播放处于idle或initialized状态时，可调用此接口。 |

## 函数说明

### Player_MediaKeySystemInfoCallback()

```c
typedef void (*Player_MediaKeySystemInfoCallback)(OH_AVPlayer *player, DRM_MediaKeySystemInfo* mediaKeySystemInfo)
```

**描述**

播放器DRM信息更新时调用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [DRM_MediaKeySystemInfo](capi-avplayer-drm-mediakeysysteminfo.md)* mediaKeySystemInfo | DRM媒体密钥系统信息，包含密钥系统ID、会话ID等DRM相关数据。用于播放加密内容时接收并传递DRM信息。 |

### OH_AVPlayer_Create()

```c
OH_AVPlayer *OH_AVPlayer_Create(void)
```

**描述**

创建播放器。<br> 推荐单个应用创建的音视频播放器实例总数不超过16个。<br> <!--Del-->可创建的音视频播放器实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放器实例。<!--DelEnd-->

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) * | 如果创建成功返回指向OH_AVPlayer实例的指针，否则返回空指针。<br> 可能的失败原因：<br> 1.PlayerFactory::CreatePlayer执行失败。<br> 2.new PlayerObject执行失败。 |

### OH_AVPlayer_SetURLSource()

```c
OH_AVErrCode OH_AVPlayer_SetURLSource(OH_AVPlayer *player, const char *url)
```

**描述**

设置播放器的播放源。对应的源可以是HTTP URL或HTTPS URL。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| const char *url | 播放源的URL地址，支持HTTP/HTTPS协议的网络URL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：设置成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，url为空或者player SetUrlSource执行失败。 |

### OH_AVPlayer_SetFDSource()

```c
OH_AVErrCode OH_AVPlayer_SetFDSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
```

**描述**

设置播放器的媒体文件描述符来源。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t fd | 媒体源的文件描述符。 |
| int64_t offset | 媒体源在文件描述符中的偏移量。 |
| int64_t size | 表示媒体源的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：fd设置成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetFdSource执行失败。 |

### OH_AVPlayer_SetDataSource()

```c
OH_AVErrCode OH_AVPlayer_SetDataSource(OH_AVPlayer *player, OH_AVDataSourceExt* datasrc, void* userData)
```

**描述**

设置播放器的媒体源，该媒体源的数据由应用程序提供。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVDataSourceExt](../apis-avcodec-kit/capi-codecbase-oh-avdatasourceext.md)* datasrc | 指向自定义媒体数据的指针。 |
| void* userData | 用户传入的句柄，用于回调中传入。userData若为空，不支持AVPlayer的多实例播放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：设置成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者输入datasrc为空指针。 |

### OH_AVPlayer_Prepare()

```c
OH_AVErrCode OH_AVPlayer_Prepare(OH_AVPlayer *player)
```

**描述**

准备播放环境，异步缓存媒体数据。<br> 此函数必须在SetSource之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Prepare执行失败。 |

### OH_AVPlayer_Play()

```c
OH_AVErrCode OH_AVPlayer_Play(OH_AVPlayer *player)
```

**描述**

开始播放。<br> 此函数必须在[OH_AVPlayer_Prepare](#oh_avplayer_prepare)之后调用。<br> 如果播放器状态为\<Prepared>，调用此函数开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Play执行失败。 |

### OH_AVPlayer_Pause()

```c
OH_AVErrCode OH_AVPlayer_Pause(OH_AVPlayer *player)
```

**描述**

暂停播放。播放器处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Pause执行失败。 |

### OH_AVPlayer_Stop()

```c
OH_AVErrCode OH_AVPlayer_Stop(OH_AVPlayer *player)
```

**描述**

停止播放。播放器处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Stop执行失败。 |

### OH_AVPlayer_Reset()

```c
OH_AVErrCode OH_AVPlayer_Reset(OH_AVPlayer *player)
```

**描述**

将播放器恢复到初始状态。<br> 函数调用完成后，调用SetSource添加播放源。调用[OH_AVPlayer_Prepare](#oh_avplayer_prepare)后，再调用[OH_AVPlayer_Play](#oh_avplayer_play)重新开始播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Reset执行失败。 |

### OH_AVPlayer_Release()

```c
OH_AVErrCode OH_AVPlayer_Release(OH_AVPlayer *player)
```

**描述**

异步释放播放器资源。<br> 异步释放可以提升性能，但不能确保播放画面的SurfaceBuffer已释放。调用者需要确保播放画面窗口的生命周期安全。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Release执行失败。 |

### OH_AVPlayer_ReleaseSync()

```c
OH_AVErrCode OH_AVPlayer_ReleaseSync(OH_AVPlayer *player)
```

**描述**

同步释放播放器资源。<br> 同步过程保证了播放画面的SurfaceBuffer释放，但该过程耗时较长，建议调用者自行设计异步机制。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player ReleaseSync执行失败。 |

### OH_AVPlayer_SetVolume()

```c
OH_AVErrCode OH_AVPlayer_SetVolume(OH_AVPlayer *player, float leftVolume, float rightVolume)
```

**描述**

设置播放器的音量。<br> 可以在播放或暂停的过程中使用。0表示无声音，1为原始值。默认音量为1。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| float leftVolume | 要设置的左声道目标音量，取值范围[0.0,1.0]，0表示无声音，1表示原始音量。 |
| float rightVolume | 要设置的右声道目标音量，取值范围[0.0,1.0]，0表示无声音，1表示原始音量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置音量。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetVolume执行失败。 |

### OH_AVPlayer_SetLoudnessGain()

```c
OH_AVErrCode OH_AVPlayer_SetLoudnessGain(OH_AVPlayer *player, float loudnessGain)
```

**描述**

设置播放器的响度。当播放处于prepared、playing、paused、completed或stopped状态时，可调用该接口。<br> 默认响度增益0.0dB。播放器流的usage参数必须是以下枚举值之一：[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC、[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MOVIE和[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK。<br> 音频渲染器的延迟模式必须是[OH_AudioStream_LatencyMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL。<br> 如果通过高分辨率管道播放，则不支持此操作。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在prepared/playing/paused/completed/stopped状态时使用。 |
| float loudnessGain | 设置播放器的响度值，单位为dB，响度范围为[-90.0, 24.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置响度。<br>AV_ERR_INVALID_VAL：输入player为空指针，或者输入的loudnessGain是无效参数。<br>AV_ERR_INVALID_STATE：函数在不正常的状态下调用，或者audioRendererInfo的usage参数不是<br>[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC，<br>[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MOVIE和<br>[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK之一。<br>AV_ERR_SERVICE_DIED：系统错误。 |

### OH_AVPlayer_Seek()

```c
OH_AVErrCode OH_AVPlayer_Seek(OH_AVPlayer *player, int32_t mSeconds, AVPlayerSeekMode mode)
```

**描述**

改变播放位置。<br> 此函数可以在播放或暂停时使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t mSeconds | 播放目标位置，精确到毫秒。 |
| [AVPlayerSeekMode](capi-avplayer-base-h.md#avplayerseekmode) mode | 播放器的跳转模式。可选值及适用场景请参考[AVPlayerSeekMode](capi-avplayer-base-h.md#avplayerseekmode)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player Seek执行失败。 |

### OH_AVPlayer_GetCurrentTime()

```c
OH_AVErrCode OH_AVPlayer_GetCurrentTime(OH_AVPlayer *player, int32_t *currentTime)
```

**描述**

获取当前播放时间（通过参数返回），精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *currentTime | 用于获取当前播放位置（输出参数），精确到毫秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取当前播放位置。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetCurrentTime执行失败。 |

### OH_AVPlayer_GetVideoWidth()

```c
OH_AVErrCode OH_AVPlayer_GetVideoWidth(OH_AVPlayer *player, int32_t *videoWidth)
```

**描述**

获取视频宽度。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *videoWidth | 用于获取视频宽度（输出参数），单位为像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取视频宽度。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_GetVideoHeight()

```c
OH_AVErrCode OH_AVPlayer_GetVideoHeight(OH_AVPlayer *player, int32_t *videoHeight)
```

**描述**

获取视频高度。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *videoHeight | 用于获取视频高度（输出参数），单位为像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取视频高度。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_SetPlaybackSpeed()

```c
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed speed)
```

**描述**

根据指定的[AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed)，设置播放器的播放速率。默认播放速率为1.0倍速（正常速度）。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed) speed | 速率模式。可选值及适用场景请参考[AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置播放速率。<br>         AV_ERR_INVALID_VAL：输入player为空指针。 |

### OH_AVPlayer_SetPlaybackRate()

```c
OH_AVErrCode OH_AVPlayer_SetPlaybackRate(OH_AVPlayer *player, float rate)
```

**描述**

在有效范围内，设置播放器的播放速率。<br> 支持的状态包括prepared、playing、paused、completed。默认播放速率为1.0倍速（正常速度）。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| float rate | 播放速率，在API版本26.0.0及以上的取值范围是[0.125, 8.0]，API版本26.0.0以下的取值范围是[0.125, 4.0]。小于1.0适合慢速播放（如学习、分析），1.0为正常速度，大于1.0适合快速浏览。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置播放速率。<br>         AV_ERR_OPERATE_NOT_PERMIT：在不支持的状态下或在直播期间调用这个方法。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者设置速率超出范围。 |

### OH_AVPlayer_GetPlaybackSpeed()

```c
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed(OH_AVPlayer *player, AVPlaybackSpeed *speed)
```

**描述**

获取当前播放器的播放速率。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlaybackSpeed](capi-avplayer-base-h.md#avplaybackspeed) *speed | 速率模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取播放速率。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetPlaybackSpeed执行失败。 |

### OH_AVPlayer_GetPlaybackRate()

```c
OH_AVErrCode OH_AVPlayer_GetPlaybackRate(OH_AVPlayer *player, float *rate)
```

**描述**

获取当前播放器播放速率。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| float *rate | 用于接收播放速率值的指针，返回当前播放器的播放速率倍数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取当前播放器的播放速率；<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者GetPlaybackRate执行失败。 |

### OH_AVPlayer_SetAudioRendererInfo()

```c
OH_AVErrCode OH_AVPlayer_SetAudioRendererInfo(OH_AVPlayer *player, OH_AudioStream_Usage streamUsage)
```

**描述**

设置player音频流类型。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage) streamUsage | player音频流设置的类型。可选值及适用场景请参考[OH_AudioStream_Usage](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置音频流类型。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者streamUsage值无效。 |

### OH_AVPlayer_SetVolumeMode()

```c
OH_AVErrCode OH_AVPlayer_SetVolumeMode(OH_AVPlayer *player, OH_AudioStream_VolumeMode volumeMode)
```

**描述**

设置player音频流音量模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_VolumeMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_volumemode) volumeMode | 指定音频流音量模式。可选值及适用场景请参考[OH_AudioStream_VolumeMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_volumemode)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置音频流音量模式。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者volumeMode值无效。<br>         AV_ERR_INVALID_STATE：函数在无效状态下调用，应先处于准备状态。<br>         AV_ERR_SERVICE_DIED：系统错误。 |

### OH_AVPlayer_SetAudioInterruptMode()

```c
OH_AVErrCode OH_AVPlayer_SetAudioInterruptMode(OH_AVPlayer *player, OH_AudioInterrupt_Mode interruptMode)
```

**描述**

设置player音频流的打断模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioInterrupt_Mode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_mode) interruptMode | player音频流使用的打断模式。可选值及适用场景请参考[OH_AudioInterrupt_Mode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_mode)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置音频流的打断模式。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者interruptMode值无效。 |

### OH_AVPlayer_SetAudioEffectMode()

```c
OH_AVErrCode OH_AVPlayer_SetAudioEffectMode(OH_AVPlayer *player, OH_AudioStream_AudioEffectMode effectMode)
```

**描述**

设置player音频流的音效模式。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AudioStream_AudioEffectMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode) effectMode | player音频流使用的音效模式。可选值及适用场景请参考[OH_AudioStream_AudioEffectMode](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置音频流的音效模式。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者effectMode值无效。 |

### OH_AVPlayer_SelectBitRate()

```c
OH_AVErrCode OH_AVPlayer_SelectBitRate(OH_AVPlayer *player, uint32_t bitRate)
```

**描述**

设置HLS播放器使用的码率。仅对HLS协议网络流有效。此接口仅可在AVPlayer处于prepared、playing或者paused状态时调用。<br> 默认情况下，播放器会根据网络连接情况选择合适的码率和速度。<br> 通过INFO_TYPE_BITRATE_COLLECT上报有效码率列表，如果用户指定的码率不在此列表中，播放器将从可用码率列表中选择最接近的码率。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| uint32_t bitRate | 码率，单位为比特率（bps）。可根据网络带宽选择合适的码率值，低带宽环境可选择较低码率值，高带宽环境可选择较低高码率值。默认情况下播放器会自动选择合适的码率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置码率。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SelectBitRate执行失败。 |

### OH_AVPlayer_SetVideoSurface()

```c
OH_AVErrCode OH_AVPlayer_SetVideoSurface(OH_AVPlayer *player, OHNativeWindow *window)
```

**描述**

设置播放画面窗口。<br> 此函数必须在SetSource之后，Prepare之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OHNativeWindow](../apis-avcodec-kit/capi-codecbase-nativewindow.md) *window | 指向OHNativeWindow实例的指针，需在SetSource之后、Prepare之前调用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置播放画面窗口。<br>         AV_ERR_INVALID_VAL：输入player为空指针，输入window为空指针或者player SetVideoSurface执行失败。 |

### OH_AVPlayer_GetDuration()

```c
OH_AVErrCode OH_AVPlayer_GetDuration(OH_AVPlayer *player, int32_t *duration)
```

**描述**

获取媒体文件的总时长，精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t *duration | 用于获取媒体文件的总时长（输出参数），精确到毫秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取媒体文件时长。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetDuration执行失败。 |

### OH_AVPlayer_GetState()

```c
OH_AVErrCode OH_AVPlayer_GetState(OH_AVPlayer *player, AVPlayerState *state)
```

**描述**

获取当前播放状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlayerState](capi-avplayer-base-h.md#avplayerstate) *state | 当前播放状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取当前播放状态。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetState执行失败。 |

### OH_AVPlayer_IsPlaying()

```c
bool OH_AVPlayer_IsPlaying(OH_AVPlayer *player)
```

**描述**

判断播放器是否在播放。此接口可在AVPlayer处于任何状态下调用，但返回结果的有效性依赖于当前状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果正在播放，则返回true；如果不在播放或者输入player为空指针则返回false。 |

### OH_AVPlayer_IsLooping()

```c
bool OH_AVPlayer_IsLooping(OH_AVPlayer *player)
```

**描述**

判断是否循环播放。此接口可在AVPlayer处于任何状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果是循环播放，则返回true；如果不是循环播放或者输入player为空指针则返回false。 |

### OH_AVPlayer_SetLooping()

```c
OH_AVErrCode OH_AVPlayer_SetLooping(OH_AVPlayer *player, bool loop)
```

**描述**

设置循环播放。默认不循环播放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| bool loop | 循环播放开关。true表示开启循环播放，false表示关闭循环播放。  |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置循环播放。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SetLooping执行失败。 |

### OH_AVPlayer_SetPlayerCallback()

```c
OH_AVErrCode OH_AVPlayer_SetPlayerCallback(OH_AVPlayer *player, AVPlayerCallback callback)
```

**描述**

设置播放器回调函数。<br> 由于通过此方法设置的信息监听回调函数[OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo)和错误监听回调函数[OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)可以传递的信息有限，也不便于应用区分多个播放器实例。<br> 从API version 12开始，应使用[OH_AVPlayer_SetOnInfoCallback](#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback](#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**废弃版本：** 12

**替代接口：** [OH_AVPlayer_SetOnInfoCallback](#oh_avplayer_setoninfocallback),[OH_AVPlayer_SetOnErrorCallback](#oh_avplayer_setonerrorcallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [AVPlayerCallback](capi-avplayer-avplayercallback.md) callback | 回调对象指针，用于接收播放器事件回调。包含onInfo、onError等回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功设置播放器回调。<br>         AV_ERR_INVALID_VAL：输入player为空指针，callback.onInfo或onError为空，或者player SetPlayerCallback执行失败。 |

### OH_AVPlayer_SelectTrack()

```c
OH_AVErrCode OH_AVPlayer_SelectTrack(OH_AVPlayer *player, int32_t index)
```

**描述**

选择音频或字幕轨道。<br> 默认播放第一个带数据的音轨，不播放字幕轨道。<br> 设置生效后，原音轨将失效。选择字幕轨道时，播放器应处于prepared、playing、paused或completed状态；选择音轨时，播放器应处于prepared状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t index | 索引。音频或字幕轨道的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player SelectTrack执行失败。 |

### OH_AVPlayer_DeselectTrack()

```c
OH_AVErrCode OH_AVPlayer_DeselectTrack(OH_AVPlayer *player, int32_t index)
```

**描述**

取消选择当前音频或字幕轨道。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t index | 索引。音频或字幕轨道的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player DeselectTrack执行失败。 |

### OH_AVPlayer_GetCurrentTrack()

```c
OH_AVErrCode OH_AVPlayer_GetCurrentTrack(OH_AVPlayer *player, int32_t trackType, int32_t *index)
```

**描述**

获取当前有效的轨道索引。调用该接口时，播放器应处于prepared、playing、paused或completed状态。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t trackType | 媒体类型。0：音频，1：视频。 |
| int32_t *index | 索引。用于获取当前轨道索引（输出参数）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：成功获取轨道索引。<br>         AV_ERR_INVALID_VAL：输入player为空指针，或者player GetCurrentTrack执行失败。 |

### OH_AVPlayer_SetMediaKeySystemInfoCallback()

```c
OH_AVErrCode OH_AVPlayer_SetMediaKeySystemInfoCallback(OH_AVPlayer *player, Player_MediaKeySystemInfoCallback callback)
```

**描述**

设置播放器媒体密钥系统信息回调的方法。适用于播放DRM加密媒体内容的场景，如监听DRM信息更新、获取加密内容密钥、处理版权保护内容等。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [Player_MediaKeySystemInfoCallback](capi-avplayer-h.md#player_mediakeysysteminfocallback) callback | DRM信息更新回调函数指针，用于接收播放器DRM密钥系统信息的更新事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player/callback为空指针，或者SetDrmSystemInfoCallback执行失败。 |

### OH_AVPlayer_GetMediaKeySystemInfo()

```c
OH_AVErrCode OH_AVPlayer_GetMediaKeySystemInfo(OH_AVPlayer *player, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

获取媒体密钥系统信息以创建媒体密钥会话。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [DRM_MediaKeySystemInfo](capi-avplayer-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | 媒体密钥系统信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者内存不足。 |

### OH_AVPlayer_SetDecryptionConfig()

```c
OH_AVErrCode OH_AVPlayer_SetDecryptionConfig(OH_AVPlayer *player, MediaKeySession *mediaKeySession, bool secureVideoPath)
```

**描述**

设置解密信息。适用于DRM加密媒体内容的场景，如播放加密视频、播放付费内容、播放受版权保护的媒体资源等。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [MediaKeySession](capi-avplayer-mediakeysession.md) *mediaKeySession | 具有解密功能的媒体密钥会话实例。 |
| bool secureVideoPath | 是否需要安全解码器。true表示需要安全解码器，false表示不需要安全解码器。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入player为空指针或者player SetDecryptionConfig执行失败。 |

### OH_AVPlayer_SetOnInfoCallback()

```c
OH_AVErrCode OH_AVPlayer_SetOnInfoCallback(OH_AVPlayer *player, OH_AVPlayerOnInfoCallback callback, void *userData)
```

**描述**

设置播放器消息回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) callback | 执行回调监听函数的指针，空指针表示取消设置播放器消息回调监听。 |
| void *userData | 指向应用调用者设置的实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：内存分配失败。请释放内存后重试。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者函数执行失败。 |

### OH_AVPlayer_SetOnErrorCallback()

```c
OH_AVErrCode OH_AVPlayer_SetOnErrorCallback(OH_AVPlayer *player, OH_AVPlayerOnErrorCallback callback, void *userData)
```

**描述**

设置播放器错误回调监听函数。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback) callback | 执行回调监听函数的指针，空指针表示取消设置播放器错误回调监听。 |
| void *userData | 指向应用调用者设置的实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：内存分配失败。<br>         AV_ERR_INVALID_VAL： 输入player为空指针或者函数执行失败。 |

### OH_AVPlayer_GetMediaDescription()

```c
OH_AVFormat *OH_AVPlayer_GetMediaDescription(OH_AVPlayer *player)
```

**描述**

获取播放器媒体源信息。设置完播放资源并且播放处于initialized/prepared/playing/paused/completed/stopped状态，可调用该接口。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 执行成功返回播放器媒体信息，否则返回nullptr。<br> 可能故障原因：<br>   1. 传入player指针不合法。<br>   2. 设置的播放资源不合法。 |

### OH_AVPlayer_GetTrackDescription()

```c
OH_AVFormat *OH_AVPlayer_GetTrackDescription(OH_AVPlayer *player, uint32_t index)
```

**描述**

通过索引下标获取播放器媒体源轨道信息。设置完播放资源并且播放处于initialized/prepared/playing/paused/completed/stopped状态，可调用该接口。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| uint32_t index | 轨道索引下标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 执行成功按索引下标返回轨道信息，否则返回nullptr。<br> 可能故障原因：<br>   1. 传入player指针不合法。<br>   2. 设置的播放资源不合法。<br>   3. 轨道索引下标超出播放源文件数组界限。 |

### OH_AVPlayer_AddFdSubtitleSource()

```c
OH_AVErrCode OH_AVPlayer_AddFdSubtitleSource(OH_AVPlayer *player, int32_t fd, int64_t offset, int64_t size)
```

**描述**

将文件描述符字幕资源添加到播放器。目前，外挂字幕必须在AVPlayer设置完视频资源的fdSrc之后再设置。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t fd | 字幕源的文件描述符。 |
| int64_t offset | 文件描述符中媒体源的偏移量。 |
| int64_t size | 媒体源的大小，单位为字节（Byte），用于指定从文件描述符中读取的媒体数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。 |

### OH_AVPlayer_AddUrlSubtitleSource()

```c
OH_AVErrCode OH_AVPlayer_AddUrlSubtitleSource(OH_AVPlayer *player, const char *url)
```

**描述**

将URL字幕资源添加到播放器。外挂字幕必须在AVPlayer设置完URL之后再设置。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| const char *url | 字幕源的URL，支持HTTP/HTTPS协议。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。 |

### OH_AVPlayer_SetPlaybackRange()

```c
OH_AVErrCode OH_AVPlayer_SetPlaybackRange(OH_AVPlayer *player, int32_t mSecondsStart, int32_t mSecondsEnd, bool closestRange)
```

**描述**

设置播放起始位置和结束位置。仅播放指定范围内的内容。可在初始化、已准备、暂停、停止或完成状态下调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t mSecondsStart | 播放起始位置，应在[0, duration)范围内，-1表示未设置起始位置，将从0开始播放。超出范围时返回错误码AV_ERR_INVALID_VAL（参数错误）或自动修正为边界值。 |
| int32_t mSecondsEnd | 播放结束位置，应在(mSecondsStart, duration]范围内，-1表示未设置结束位置，将在流末尾结束播放。 |
| bool closestRange | 是否同步到距离指定时间点最近的帧。传入true时同步到最近的帧（适合需要精确播放位置的场景），传入false时不同步到最近的帧（适合不需要精确播放位置的场景）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。 |

### OH_AVPlayer_SetMediaMuted()

```c
OH_AVErrCode OH_AVPlayer_SetMediaMuted(OH_AVPlayer *player, OH_MediaType mediaType, bool muted)
```

**描述**

静音媒体流。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_MediaType](../apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_mediatype) mediaType | 指定的媒体类型。可选值：MEDIA_TYPE_AUD（音频类型，用于静音音频流）、MEDIA_TYPE_VID（视频类型，用于静音视频流）。详情请参考[OH_MediaType](../apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_mediatype)。 |
| bool muted | true表示静音，false表示取消静音。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。 |

### OH_AVPlayer_GetPlaybackPosition()

```c
int32_t OH_AVPlayer_GetPlaybackPosition(OH_AVPlayer *player)
```

**描述**

获取播放位置，精确到毫秒。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回以毫秒为单位的播放位置。<br>         若player为空指针或无效，则返回-1。 |

### OH_AVPlayer_IsSeekContinuousSupported()

```c
bool OH_AVPlayer_IsSeekContinuousSupported(OH_AVPlayer *player)
```

**描述**

检查媒体源是否支持连续跳转。在prepared、playing、paused或completed状态下调用时返回实际值；在其他状态下调用时返回false。对于不支持[AV_SEEK_CONTINUOUS](capi-avplayer-base-h.md#avplayerseekmode)模式跳转操作的设备，返回false。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true表示支持连续跳转。<br>          false表示不支持连续跳转或支持状态不确定。 |

### OH_AVPlayer_SelectTrackWithMode()

```c
OH_AVErrCode OH_AVPlayer_SelectTrackWithMode(OH_AVPlayer *player, int32_t index, AVPlayerTrackSwitchMode mode)
```

**描述**

在播放包含多个音视频轨道的资源时，使用指定的切换模式选择轨道。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t index | 所选轨道的索引。 |
| [AVPlayerTrackSwitchMode](capi-avplayer-base-h.md#avplayertrackswitchmode) mode | 切换模式。可选值及适用场景请参考[AVPlayerTrackSwitchMode](capi-avplayer-base-h.md#avplayertrackswitchmode)定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。 |

### OH_AVPlayer_SetAmplitudeUpdateCallback()

```c
OH_AVErrCode OH_AVPlayer_SetAmplitudeUpdateCallback(OH_AVPlayer *player, OH_AVPlayerOnAmplitudeUpdateCallback callback, void *userData)
```

**描述**

订阅最大音频电平值的更新事件，该值在播放音频资源时周期性上报。适用于需要音频可视化或音频强度检测的场景，如音频波形显示、音频强度可视化、音频能量检测等。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerOnAmplitudeUpdateCallback](capi-avplayer-base-h.md#oh_avplayeronamplitudeupdatecallback) callback | 回调函数指针，nullptr表示取消注册回调。 |
| void *userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。 |

### OH_AVPlayer_SetSeiReceivedCallback()

```c
OH_AVErrCode OH_AVPlayer_SetSeiReceivedCallback(OH_AVPlayer *player, const int32_t *payloadTypes, uint32_t typeNum, OH_AVPlayerOnSeiMessageReceivedCallback callback, void *userData)
```

**描述**

订阅接收到补充增强信息（SEI）消息的事件。仅适用于HTTP-FLV直播流，当视频流中存在SEI消息时触发。必须在调用prepare之前发起订阅。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在prepare之前调用。 |
| const int32_t *payloadTypes | SEI消息负载类型数组，用于指定要订阅的SEI消息类型。数组大小由typeNum参数指定。 |
| uint32_t typeNum | 负载类型数组的大小。 |
| [OH_AVPlayerOnSeiMessageReceivedCallback](capi-avplayer-base-h.md#oh_avplayeronseimessagereceivedcallback) callback | 回调函数指针，nullptr表示取消注册回调。 |
| void *userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。 |

### OH_AVSeiMessage_GetSeiCount()

```c
uint32_t OH_AVSeiMessage_GetSeiCount(OH_AVSeiMessageArray *message)
```

**描述**

获取SEI消息数组中的消息项数量。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSeiMessageArray](capi-avplayer-oh-avseimessagearray.md) *message | 指向OH_AVSeiMessageArray实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | SEI消息数组中的消息项数量。 |

### OH_AVSeiMessage_GetSei()

```c
OH_AVFormat *OH_AVSeiMessage_GetSei(OH_AVSeiMessageArray *message, uint32_t index)
```

**描述**

通过索引获取SEI（Supplemental Enhancement Information）消息数组中某一项的SEI。需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSeiMessageArray](capi-avplayer-oh-avseimessagearray.md) *message | 指向OH_AVSeiMessageArray实例的指针。 |
| uint32_t index | 消息项的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 返回该消息项的SEI。若message为空指针或index无效，则返回空指针。 |

### OH_AVPlayer_SetTargetVideoWindowSize()

```c
OH_AVErrCode OH_AVPlayer_SetTargetVideoWindowSize(OH_AVPlayer *player, int32_t width, int32_t height)
```

**描述**

为超分辨率设置视频窗口大小。此接口可在AVPlayer处于idle、prepared、playing、paused、completed或stopped状态时调用。输入参数值必须在320x320至1920x1080范围内。单位为像素（px）。适用于超分辨率视频显示的场景，如低分辨率视频画质提升、视频增强显示等。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t width | 窗口宽度，取值范围[320-1920]，单位为像素（px）。超出范围时返回错误码AV_ERR_INVALID_VAL（参数错误）。 |
| int32_t height | 窗口高度，取值范围[320-1080]，单位为像素（px）。超出范围时返回错误码AV_ERR_INVALID_VAL（参数错误）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针或参数错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。<br>         AV_ERR_SUPER_RESOLUTION_UNSUPPORTED：表示不支持超分辨率。<br>         AV_ERR_SUPER_RESOLUTION_NOT_ENABLED：表示未在[OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md)中启用超分辨率功能。 |

### OH_AVPlayer_SetVideoSuperResolutionEnable()

```c
OH_AVErrCode OH_AVPlayer_SetVideoSuperResolutionEnable(OH_AVPlayer *player, bool enabled)
```

**描述**

动态启用或禁用超分辨率。此接口可在AVPlayer处于idle、prepared、playing、paused、completed或stopped状态时调用。必须在调用prepare之前在[OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md)中启用超分辨率功能。适用于需要动态控制视频画质增强的场景，如根据设备性能动态调整、根据网络状态切换画质等。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| bool enabled | true：启用超分辨率；false：禁用超分辨率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针或参数错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。<br>         AV_ERR_SUPER_RESOLUTION_UNSUPPORTED：表示不支持超分辨率。<br>         AV_ERR_SUPER_RESOLUTION_NOT_ENABLED：表示未在[OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md)中启用超分辨率功能。 |

### OH_AVPlaybackStrategy_Create()

```c
OH_AVPlaybackStrategy *OH_AVPlaybackStrategy_Create(void)
```

**描述**

创建一个播放策略实例。

**起始版本：** 23

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVPlaybackStrategy *](capi-avplayer-oh-avplaybackstrategy.md) | 一个播放策略实例，失败时返回空指针。 |

### OH_AVPlaybackStrategy_Destroy()

```c
OH_AVErrCode OH_AVPlaybackStrategy_Destroy(OH_AVPlaybackStrategy *strategy)
```

**描述**

释放一个播放策略实例。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy播放策略实例的指针，用于指定要释放的播放策略对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredWidth()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredWidth(OH_AVPlaybackStrategy *strategy, int32_t width)
```

**描述**

选择接近指定宽度的流。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | AVPlayer使用的OH_AVPlaybackStrategy。 |
| int32_t width | AVPlayer启动时选择播放的首选宽度，单位为像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredHeight()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHeight(OH_AVPlaybackStrategy *strategy, int32_t height)
```

**描述**

选择接近指定高度的流。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | avplayer使用的OH_AVPlaybackStrategy。 |
| int32_t height | avplayer启动时选择播放的首选高度，单位为像素。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredBufferDuration()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDuration(OH_AVPlaybackStrategy *strategy, int32_t ms)
```

**描述**

选择接近指定值的首选缓冲时长。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | avplayer使用的OH_AVPlaybackStrategy。 |
| int32_t ms | AVPlayer启动时选择播放的首选缓冲时长，单位为毫秒（ms）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredHdr()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredHdr(OH_AVPlaybackStrategy *strategy, bool enabled)
```

**描述**

启用或禁用首选HDR模式。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| bool enabled | true表示启用HDR，false表示禁用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredSubtitleLanguage()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredSubtitleLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)
```

**描述**

设置首选字幕语言。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| const char *lang | 字幕语言代码，采用ISO639-1标准，长度为2-3个字符（例如"zh"、"en"）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredAudioLanguage()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredAudioLanguage(OH_AVPlaybackStrategy *strategy, const char *lang)
```

**描述**

设置首选音频语言。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| const char *lang | 音频语言代码，采用ISO639-1标准，长度为2-3个字符（例如"zh"、"en"）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetMutedMediaType()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetMutedMediaType(OH_AVPlaybackStrategy *strategy, OH_MediaType mediaType)
```

**描述**

设置播放时要静音的媒体类型。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| [OH_MediaType](../apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_mediatype) mediaType | 要静音的媒体类型。可选值：MEDIA_TYPE_AUD（音频类型，用于静音音频流）、MEDIA_TYPE_VID（视频类型，用于静音视频流）。详情请参考[OH_MediaType](../apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_mediatype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetShowFirstFrameOnPrepare()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetShowFirstFrameOnPrepare(OH_AVPlaybackStrategy *strategy, bool enabled)
```

**描述**

设置是否在prepare时显示首帧。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| bool enabled | true表示显示，false表示不显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetThresholdForAutoQuickPlay()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetThresholdForAutoQuickPlay(OH_AVPlaybackStrategy *strategy, double seconds)
```

**描述**

设置自动快速播放的阈值。当缓冲数据不足导致播放可能卡顿时，播放器会自动提高播放速率快速播放已缓存内容，该阈值是控制触发此行为的条件。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| double seconds | 自动快速播放的阈值，单位为秒（s）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetSuperResolutionEnable()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetSuperResolutionEnable(OH_AVPlaybackStrategy *strategy, bool enabled)
```

**描述**

启用或禁用超分辨率。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| bool enabled | true表示启用，false表示禁用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetPreferredBufferDurationForPlaying()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetPreferredBufferDurationForPlaying(OH_AVPlaybackStrategy *strategy, double seconds)
```

**描述**

设置播放时的首选缓冲时长（秒，double类型）。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| double seconds | 缓冲时长（秒）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlaybackStrategy_SetKeepDecodingOnMute()

```c
OH_AVErrCode OH_AVPlaybackStrategy_SetKeepDecodingOnMute(OH_AVPlaybackStrategy *strategy, bool enabled)
```

**描述**

设置静音时是否继续解码。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy的指针。 |
| bool enabled | true表示继续解码，false表示静音时暂停解码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的strategy为空指针。 |

### OH_AVPlayer_SetPlaybackStrategy()

```c
OH_AVErrCode OH_AVPlayer_SetPlaybackStrategy(OH_AVPlayer *player, OH_AVPlaybackStrategy *strategy)
```

**描述**

将播放策略设置给AVPlayer。此接口仅可在AVPlayer处于初始化状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在初始化状态时调用。 |
| [OH_AVPlaybackStrategy](capi-avplayer-oh-avplaybackstrategy.md) *strategy | 指向OH_AVPlaybackStrategy播放策略实例的指针，用于为播放器设置播放策略配置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示操作不允许。 |

### OH_AVPlayer_GetPlaybackInfo()

```c
OH_AVFormat* OH_AVPlayer_GetPlaybackInfo(OH_AVPlayer *player)
```

**描述**

获取当前播放器的统计信息。此接口仅可在AVPlayer处于prepared、playing或者paused状态时调用。需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在prepared、playing或者paused状态时调用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 返回指向OH_AVFormat实例的指针。<br>         若player为空指针或无效，则返回空指针。 |

### OH_AVPlayer_SetMediaSource()

```c
OH_AVErrCode OH_AVPlayer_SetMediaSource(OH_AVPlayer *player, OH_AVMediaSource *source)
```

**描述**

将OH_AVMediaSource设置给播放器。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVMediaSource](capi-avmedia-source-oh-avmediasource.md) *source | 指向OH_AVMediaSource媒体源实例的指针，包含媒体URL、DRM配置等信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player或者source为空指针，或player设置URL源失败。 |

### OH_AVPlayer_GetTrackCount()

```c
uint32_t OH_AVPlayer_GetTrackCount(OH_AVPlayer *player)
```

**描述**

获取播放器媒体源的轨道数量。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回播放器媒体源的轨道数量。若player为空指针或无效，则返回0。 |

### OH_AVPlayer_GetTrackFormat()

```c
OH_AVFormat *OH_AVPlayer_GetTrackFormat(OH_AVPlayer *player, uint32_t trackIndex)
```

**描述**

通过索引获取播放器轨道信息。此接口仅可在AVPlayer处于prepared、playing、paused或completed状态时调用。<br> 需要注意返回值OH_AVFormat指针对象的生命周期需要用户手动释放。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| uint32_t trackIndex | 轨道数组索引，取值范围[0, trackCount-1]，其中trackCount可通过OH_AVPlayer_GetTrackCount获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 返回指向OH_AVFormat实例的指针。<br>         若player为空指针或无效，或trackIndex无效，则返回空指针。 |

### OH_AVPlayer_GetPlaybackStatisticMetrics()

```c
OH_AVFormat *OH_AVPlayer_GetPlaybackStatisticMetrics(OH_AVPlayer *player)
```

**描述**

获取当前播放器的统计指标信息。设置完播放资源，并且当播放处于prepared、playing、paused、completed或stopped状态时，可调用该接口。<br> 需要注意返回值[OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md)指针对象的生命周期需要用户手动释放。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat *](../apis-avcodec-kit/capi-core-oh-avformat.md) | 执行成功返回播放器的统计指标信息（键值详情请参考avplayer_base.h中的[变量](../apis-media-kit/capi-avplayer-base-h.md#变量)信息），否则返回nullptr。<br> 可能的失败原因：传入player指针不合法。 |

### OH_AVPlayer_SetPCMOutputCallback()

```c
OH_AVErrCode OH_AVPlayer_SetPCMOutputCallback(OH_AVPlayer *player, OH_AVPlayerPCMOutputCallback callback, void *userData)
```

**描述**

设置音频PCM数据输出回调。当播放处于idle或initialized状态时，可调用此接口。适用于需要获取音频原始数据的场景，如音频数据分析、音频录制、音频处理、音频可视化等。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在idle或initialized状态时调用。 |
| [OH_AVPlayerPCMOutputCallback](capi-avplayer-base-h.md#oh_avplayerpcmoutputcallback) callback | 回调函数指针，nullptr表示取消注册回调。 |
| void *userData | 指向用户指定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针，或player SetPCMOutputCallback失败。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示在不支持的状态下调用。 |

### OH_AVPlayer_SetVideoSideOutput()

```c
OH_AVPlayerVideoOutput* OH_AVPlayer_SetVideoSideOutput(OH_AVPlayer *player, OHNativeWindow *window)
```

**描述**

设置视频解码帧输出回调。当播放处于idle或initialized状态时，可调用此接口。适用于需要获取视频解密帧的场景，如视频帧分析、视频滤镜处理、视频截图、视频特效处理等。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针，需在idle或initialized状态时调用。 |
| [OHNativeWindow](../apis-avcodec-kit/capi-codecbase-nativewindow.md) *window | 指向OHNativeWindow实例的指针，具体请参阅OHNativeWindow。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVPlayerVideoOutput*](capi-avplayer-oh-avplayervideooutput.md) | 返回指向OH_AVPlayerVideoOutput实例的指针，nullptr表示失败。<br> 可能故障原因：<br> 1. 传入player指针不合法。<br> 2. 传入window指针不合法。 |

### OH_AVPlayerVideoOutput_GetNewestVideoSample()

```c
OH_VideoOutputResult OH_AVPlayerVideoOutput_GetNewestVideoSample(OH_AVPlayerVideoOutput *videoOutput)
```

**描述**

获得一个视频解码帧。当播放处于paused或playing状态时，可调用此接口。适用于需要获取当前视频帧的场景，如视频帧捕获、视频帧分析、视频截图、视频帧处理等。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayerVideoOutput](capi-avplayer-oh-avplayervideooutput.md) *videoOutput | 指向OH_AVPlayer_SetVideoSideOutput返回的OH_AVPlayerVideoOutput实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_VideoOutputResult](capi-avplayer-base-h.md#oh_videooutputresult) | OH_VIDEO_OUTPUT_OK（对应数值）：获得一个视频解码帧。<br>         OH_VIDEO_OUTPUT_NO_IMAGE（对应数值）：没有可渲染的帧。 |

### OH_AVPlayer_SetPCMProcessorCallback()

```c
OH_AVErrCode OH_AVPlayer_SetPCMProcessorCallback(OH_AVPlayer *player, OH_AVPlayerPCMProcessorCallback callback, void *userData)
```

**描述**

设置音频PCM数据后处理回调。当播放处于idle或initialized状态时，可调用此接口。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| [OH_AVPlayerPCMProcessorCallback](capi-avplayer-base-h.md#oh_avplayerpcmprocessorcallback) callback | 回调函数指针，nullptr表示取消注册回调。 |
| void *userData | 指向用户指定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针，或player SetPCMProcessorCallback失败。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示在不支持的状态下调用。 |

### OH_AVPlayer_SetPCMProcessorMaxLen()

```c
OH_AVErrCode OH_AVPlayer_SetPCMProcessorMaxLen(OH_AVPlayer *player, int32_t maxProcessedPCMLen)
```

**描述**

设置音频后处理回调函数单次可返回的最大数据量。允许缓存部分数据，并与下一次返回的PCM数据一并输出。<br> 当播放处于idle或initialized状态时，可调用此接口。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVPlayer](capi-avplayer-oh-avplayer.md) *player | 指向OH_AVPlayer实例的指针。 |
| int32_t maxProcessedPCMLen | 单次可返回的最大数据量。单位为字节（Byte），范围为(0, 5MB]。<br> OH_AVPlayerPCMProcessorCallback保证返回的AVBuffer的容量不小于该值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数执行结果。<br>         AV_ERR_OK：表示执行成功。<br>         AV_ERR_INVALID_VAL：表示输入的player为空指针，或maxProcessedPCMLen参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：表示在不支持的状态下调用。 |


