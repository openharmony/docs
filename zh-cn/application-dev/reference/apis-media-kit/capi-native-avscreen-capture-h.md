# native_avscreen_capture.h

## 概述

声明用于构造屏幕录制对象的API。

**库：** libnative_avscreen_capture.so

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)](#oh_avscreencapture_create) | 创建OH_AVScreenCapture。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)](#oh_avscreencapture_init) | 初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样相关参数（可选）、音频内录采样相关参数、视频分辨率相关参数。录屏存文件场景，应用需要保证视频编码参数、视频采样参数、音频编码参数、音频内录采样参数均合法，音频麦克风采样参数合法（可选）。录屏出码流场景，应用需要保证音频内录采样参数、视频采样参数至少一个合法，音频麦克风采样参数合法（可选）。由于结构体变量在初始化时不会对成员进行初始化，应用必须根据使用场景正确设置各项参数。建议应用先将OH_AVScreenCaptureConfig结构体变量的所有内存字节均设置为0，然后再根据录屏场景设置合法参数。音频采样参数结构体[OH_AudioCaptureInfo](capi-oh-audiocaptureinfo.md)，若audioSampleRate和audioChannels同时为0，则录屏实例OH_AVScreenCapture将忽略该类型的音频参数，且不采集该类型的音频数据。视频采样参数结构体[OH_VideoCaptureInfo](capi-oh-videocaptureinfo.md)，若videoFrameWidth和videoFrameHeight同时为0，则录屏实例OH_AVScreenCapture将忽略对应视频参数，且不采集屏幕数据。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreencapture) | 启动录屏，调用此接口，可采集编码后的码流。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreencapture) | 结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreenrecording) | 启动录屏，调用此接口，可将录屏文件保存。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreenrecording) | 停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)](#oh_avscreencapture_acquireaudiobuffer) | 获取音频buffer。应用调用时需分配audiobuffer对应结构体大小的内存，否则影响音频buffer的获取。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)](#oh_avscreencapture_releaseaudiobuffer) | 根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_releasevideobuffer) | 根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口释放对应的视频buffer。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)](#oh_avscreencapture_setcallback) | 设置监听接口，通过设置监听，可监听调用过程中的错误信息及视频、音频buffer的可用状态。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_release) | 释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)](#oh_avscreencapture_setmicrophoneenabled) | 设置麦克风开关。当isMicrophone为true时，则打开麦克风，通过调用OH_AVScreenCapture_StartScreenCapture和OH_AVScreenCapture_AcquireAudioBuffer可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。 默认麦克风开关为开启。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)](#oh_avscreencapture_setstatecallback) | 设置状态变更处理回调方法，在开始录制前调用。调用该方法设置状态变更处理回调方法，当OH_AVScreenCapture实例发生状态变更时，该状态变更处理回调方法将会被调用。调用该设置方法成功后，在启动录屏时将通过隐私弹窗方式征求用户同意：1. 如果用户同意则开始启动录屏流程，在启动录屏成功后，通过该状态处理回调方法上报{@Link OH_SCREEN_CAPTURE_STATE_STARTED}状态，告知应用启动录屏成功，并在屏幕显示录屏通知。如果启动录屏失败，则通过该状态处理回调方法上报失败状态信息（如，若麦克风不可用则上报[OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode)状态），或通过错误处理回调方法[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)上报错误信息。2. 如果用户拒绝，则终止启动录屏，通过该状态处理回调方法上报[OH_SCREEN_CAPTURE_STATE_CANCELED](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode)状态，告知应用用户拒绝启动录屏，启动录屏失败。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)](#oh_avscreencapture_setdatacallback) | 设置数据处理回调方法，在开始录制前调用。调用该方法设置数据处理回调方法，当OH_AVScreenCapture操作期间有音频或视频数据缓存区可用时，将调用该数据处理回调方法。应用需要在该数据处理回调方法中根据数据类型完成处理麦克风音频、内录音频、视频数据，当该数据处理回调方法返回后数据缓存区将不再有效。调用该方法成功后：1. 当OH_AVScreenCapture操作期间有音视频缓存区可用时，将不再调用通过[OH_AVScreenCapture_SetCallback](capi-native-avscreen-capture-h.md#oh_avscreencapture_setcallback)设置的数据回调方法[OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable)和[OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable)。2. 不允许应用调用如下4个方法[OH_AVScreenCapture_AcquireAudioBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_acquireaudiobuffer)、[OH_AVScreenCapture_ReleaseAudioBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_releaseaudiobuffer)、{@link OH_AVScreenCapture_AcquireVideoBuffer}和[OH_AVScreenCapture_ReleaseVideoBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_releasevideobuffer)，直接返回失败。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)](#oh_avscreencapture_seterrorcallback) | 设置错误处理回调方法，在开始录制前调用。调用该方法设置错误处理回调方法，当OH_AVScreenCapture实例发生错误时，该错误处理回调方法将会被调用。调用该设置方法成功后，当OH_AVScreenCapture实例发生错误时，将不再调用通过[OH_AVScreenCapture_SetCallback](capi-native-avscreen-capture-h.md#oh_avscreencapture_setcallback)设置的错误处理回调方法[OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror)。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,OHNativeWindow *window)](#oh_avscreencapture_startscreencapturewithsurface) | 使用Surface模式录屏。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)](#oh_avscreencapture_setcanvasrotation) | 设置录屏屏幕数据旋转。调用该方法可以设置录屏屏幕数据是否旋转，当canvasRotation为true时，打开录屏屏幕数据旋转功能，录制的屏幕数据保持正向。默认为false。 |
| [struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void)](#oh_avscreencapture_createcontentfilter) | 创建ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_releasecontentfilter) | 释放ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content)](#oh_avscreencapture_contentfilter_addaudiocontent) | 向ContentFilter实例添加可过滤的声音类型。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_excludecontent) | 设置OH_AVScreenCapture实例的内容过滤器ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_contentfilter_addwindowcontent) | 向ContentFilter实例添加可被过滤的窗口ID列表 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)](#oh_avscreencapture_resizecanvas) | 调整屏幕的分辨率 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_skipprivacymode) | 录屏时豁免隐私窗口 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)](#oh_avscreencapture_setmaxvideoframerate) | 设置录屏时的最大帧率 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)](#oh_avscreencapture_showcursor) | 设置光标显示开关 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnDisplaySelected callback, void *userData)](#oh_avscreencapture_setdisplaycallback) | 设置获取录屏屏幕Id的回调。 |
| [OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)](#oh_avscreencapture_createcapturestrategy) | 创建录屏策略对象 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)](#oh_avscreencapture_releasecapturestrategy) | 释放录屏策略对象 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)](#oh_avscreencapture_setcapturestrategy) | 给指定的录屏对象设置捕获策略 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)](#oh_avscreencapture_strategyforkeepcaptureduringcall) | 设置蜂窝通话时是否允许进行录屏的策略值 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData)](#oh_avscreencapture_setcapturecontentchangedcallback) | 设置录屏内容变更回调事件，需在录屏启动前被调用。 |

## 函数说明

### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)
```

**描述**

创建OH_AVScreenCapture。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 返回一个capture 指向OH_AVScreenCapture实例的指针。 |

### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)
```

**描述**

初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样相关参数（可选）、音频内录采样相关参数、视频分辨率相关参数。录屏存文件场景，应用需要保证视频编码参数、视频采样参数、音频编码参数、音频内录采样参数均合法，音频麦克风采样参数合法（可选）。录屏出码流场景，应用需要保证音频内录采样参数、视频采样参数至少一个合法，音频麦克风采样参数合法（可选）。由于结构体变量在初始化时不会对成员进行初始化，应用必须根据使用场景正确设置各项参数。建议应用先将OH_AVScreenCaptureConfig结构体变量的所有内存字节均设置为0，然后再根据录屏场景设置合法参数。音频采样参数结构体[OH_AudioCaptureInfo](capi-oh-audiocaptureinfo.md)，若audioSampleRate和audioChannels同时为0，则录屏实例OH_AVScreenCapture将忽略该类型的音频参数，且不采集该类型的音频数据。视频采样参数结构体[OH_VideoCaptureInfo](capi-oh-videocaptureinfo.md)，若videoFrameWidth和videoFrameHeight同时为0，则录屏实例OH_AVScreenCapture将忽略对应视频参数，且不采集屏幕数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureConfig](capi-oh-avscreencaptureconfig.md) config | 录屏初始化相关参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，初始化配置失败。 |

### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)
```

**描述**

启动录屏，调用此接口，可采集编码后的码流。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置隐私权限启用失败或启动录屏失败。 |

### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)
```

**描述**

结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，结束录屏失败。 |

### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)
```

**描述**

启动录屏，调用此接口，可将录屏文件保存。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置隐私权限启用失败或启用屏幕录制失败。 |

### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)
```

**描述**

停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，停止屏幕录制失败。 |

### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)
```

**描述**

获取音频buffer。应用调用时需分配audiobuffer对应结构体大小的内存，否则影响音频buffer的获取。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：** [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AudioBuffer](capi-oh-audiobuffer.md) **audiobuffer | 保存音频buffer的结构体，通过该结构体获取到音频buffer以及buffer的时间戳等信息。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | 音频buffer的类型，区分是麦克风录制的外部流还是系统内部播放音频的内录流，详情请参阅OH_AudioCaptureSourceType |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数audiobuffer为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY}内存不足，audiobuffer分配失败；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置隐私权限启用失败或获取音频buffer失败。 |

### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)
```

**描述**

根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | 音频buffer的类型，区分麦克风录制的外部流还是系统内部播放音频的内录流。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，不允许用于已设置过DataCallback或释放音频buffer失败。 |

### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)
```

**描述**

根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口释放对应的视频buffer。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，不允许用于已设置过DataCallback或释放视频buffer失败。 |

### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)
```

**描述**

设置监听接口，通过设置监听，可监听调用过程中的错误信息及视频、音频buffer的可用状态。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| struct OH_AVScreenCaptureCallback callback | OH_AVScreenCaptureCallback的结构体，保存相关回调函数指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数callback为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置监听接口失败。 |

### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)
```

**描述**

释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，OH_AVScreenCapture实例释放失败。 |

### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)
```

**描述**

设置麦克风开关。当isMicrophone为true时，则打开麦克风，通过调用OH_AVScreenCapture_StartScreenCapture和OH_AVScreenCapture_AcquireAudioBuffer可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。 默认麦克风开关为开启。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool isMicrophone | 麦克风开关参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置麦克风开关失败。 |

### OH_AVScreenCapture_SetStateCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)
```

**描述**

设置状态变更处理回调方法，在开始录制前调用。调用该方法设置状态变更处理回调方法，当OH_AVScreenCapture实例发生状态变更时，该状态变更处理回调方法将会被调用。调用该设置方法成功后，在启动录屏时将通过隐私弹窗方式征求用户同意：1. 如果用户同意则开始启动录屏流程，在启动录屏成功后，通过该状态处理回调方法上报{@Link OH_SCREEN_CAPTURE_STATE_STARTED}状态，告知应用启动录屏成功，并在屏幕显示录屏通知。如果启动录屏失败，则通过该状态处理回调方法上报失败状态信息（如，若麦克风不可用则上报[OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode)状态），或通过错误处理回调方法[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)上报错误信息。2. 如果用户拒绝，则终止启动录屏，通过该状态处理回调方法上报[OH_SCREEN_CAPTURE_STATE_CANCELED](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode)状态，告知应用用户拒绝启动录屏，启动录屏失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| OH_AVScreenCapture_OnStateChange callback | 指向状态处理回调方法实例的指针[OH_AVScreenCapture_OnStateChange](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onstatechange)。 |
| void *userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数callback为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY}内存不足，内存分配失败；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置StateCallback失败。 |

### OH_AVScreenCapture_SetDataCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)
```

**描述**

设置数据处理回调方法，在开始录制前调用。调用该方法设置数据处理回调方法，当OH_AVScreenCapture操作期间有音频或视频数据缓存区可用时，将调用该数据处理回调方法。应用需要在该数据处理回调方法中根据数据类型完成处理麦克风音频、内录音频、视频数据，当该数据处理回调方法返回后数据缓存区将不再有效。调用该方法成功后：1. 当OH_AVScreenCapture操作期间有音视频缓存区可用时，将不再调用通过[OH_AVScreenCapture_SetCallback](capi-native-avscreen-capture-h.md#oh_avscreencapture_setcallback)设置的数据回调方法[OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable)和[OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable)。2. 不允许应用调用如下4个方法[OH_AVScreenCapture_AcquireAudioBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_acquireaudiobuffer)、[OH_AVScreenCapture_ReleaseAudioBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_releaseaudiobuffer)、{@link OH_AVScreenCapture_AcquireVideoBuffer}和[OH_AVScreenCapture_ReleaseVideoBuffer](capi-native-avscreen-capture-h.md#oh_avscreencapture_releasevideobuffer)，直接返回失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| OH_AVScreenCapture_OnBufferAvailable callback | 指向数据处理回调方法实例的指针[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)。 |
| void *userData | 指向应用提供的自定义数据的指针，在数据处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数callback为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY}内存不足，内存分配失败；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置DataCallback失败。 |

### OH_AVScreenCapture_SetErrorCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)
```

**描述**

设置错误处理回调方法，在开始录制前调用。调用该方法设置错误处理回调方法，当OH_AVScreenCapture实例发生错误时，该错误处理回调方法将会被调用。调用该设置方法成功后，当OH_AVScreenCapture实例发生错误时，将不再调用通过[OH_AVScreenCapture_SetCallback](capi-native-avscreen-capture-h.md#oh_avscreencapture_setcallback)设置的错误处理回调方法[OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| OH_AVScreenCapture_OnError callback | 指向错误处理回调方法实例的指针[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)。 |
| void *userData | 指向应用提供的自定义数据的指针，在错误处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数callback为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY}内存不足，内存分配失败；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置ErrorCallback失败。 |

### OH_AVScreenCapture_StartScreenCaptureWithSurface()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,OHNativeWindow *window)
```

**描述**

使用Surface模式录屏。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OHNativeWindow](../ArkGraphics2D/capi-nativewindow.md) *window | 指向OHNativeWindow实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数window为空指针或window指向的windowSurface为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置隐私权限启用失败或启动ScreenCaptureWithSurface失败。 |

### OH_AVScreenCapture_SetCanvasRotation()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)
```

**描述**

设置录屏屏幕数据旋转。调用该方法可以设置录屏屏幕数据是否旋转，当canvasRotation为true时，打开录屏屏幕数据旋转功能，录制的屏幕数据保持正向。默认为false。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool canvasRotation | 指示屏幕数据旋转参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置录屏屏幕数据旋转失败。 |

### OH_AVScreenCapture_CreateContentFilter()

```
struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void)
```

**描述**

创建ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 执行成功返回OH_AVScreenCapture_ContentFilter实例，否则返回空指针。 |

### OH_AVScreenCapture_ReleaseContentFilter()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter)
```

**描述**

释放ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture_ContentFilter *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数filter为空指针。 |

### OH_AVScreenCapture_ContentFilter_AddAudioContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content)
```

**描述**

向ContentFilter实例添加可过滤的声音类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture_ContentFilter *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |
| [OH_AVScreenCaptureFilterableAudioContent](capi-native-avscreen-capture-base-h.md#oh_avscreencapturefilterableaudiocontent) content | OH_AVScreenCaptureFilterableAudioContent实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数filter为空指针或输入参数content无效。 |

### OH_AVScreenCapture_ExcludeContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,struct OH_AVScreenCapture_ContentFilter *filter)
```

**描述**

设置OH_AVScreenCapture实例的内容过滤器ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| struct OH_AVScreenCapture_ContentFilter *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数filter为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT}操作不支持。对于流，启动时应该调用AudioCapturer接口；<br>         对于capture文件，启动时调用Recorder接口。 |

### OH_AVScreenCapture_ContentFilter_AddWindowContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)
```

**描述**

向ContentFilter实例添加可被过滤的窗口ID列表

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture_ContentFilter *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |
| int32_t *windowIDs | 指向窗口ID的指针。 |
| int32_t windowCount | 窗口ID列表的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 执行成功返回AV_SCREEN_CAPTURE_ERR_OK，否则返回具体错误码，请参阅OH_AVSCREEN_CAPTURE_ErrCode。 |

### OH_AVScreenCapture_ResizeCanvas()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)
```

**描述**

调整屏幕的分辨率

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t width | 录屏屏幕的宽度。 |
| int32_t height | 录屏屏幕的高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作。 |

### OH_AVScreenCapture_SkipPrivacyMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)
```

**描述**

录屏时豁免隐私窗口

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t *windowIDs | 向隐私窗口ID的指针。 |
| int32_t windowCount | 隐私窗口ID列表的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作。 |

### OH_AVScreenCapture_SetMaxVideoFrameRate()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)
```

**描述**

设置录屏时的最大帧率

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t frameRate | 录屏的最大帧率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或者输入参数frameRate不支持；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作。 |

### OH_AVScreenCapture_ShowCursor()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)
```

**描述**

设置光标显示开关

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool showCursor | 光标显示参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：   <br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT}不允许操作，设置光标失败。 |

### OH_AVScreenCapture_SetDisplayCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnDisplaySelected callback, void *userData)
```

**描述**

设置获取录屏屏幕Id的回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | OH_AVScreenCapture实例的指针。 |
| OH_AVScreenCapture_OnDisplaySelected callback | 指向录屏屏幕Id回调方法实例的指针, see [OH_AVScreenCapture_OnDisplaySelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_ondisplayselected)。 |
| void *userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK}执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL}输入参数capture为空指针或输入参数callback为空指针；<br>         {@link AV_SCREEN_CAPTURE_ERR_NO_MEMORY}内存不足，内存分配失败；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_STATE}回调必须在start方法前调用。 |

### OH_AVScreenCapture_CreateCaptureStrategy()

```
OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)
```

**描述**

创建录屏策略对象

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVScreenCapture_CaptureStrategy* | 返回录屏策略对象指针，若失败返回空值 |

### OH_AVScreenCapture_ReleaseCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)
```

**描述**

释放录屏策略对象

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| {OH_AVScreenCapture_CaptureStrategy} | strategy 指向录屏策略对象的指针 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK} 执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} 输入参数strategy为空指针。 |

### OH_AVScreenCapture_SetCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)
```

**描述**

给指定的录屏对象设置捕获策略

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| {OH_AVScreenCapture} | capture 指向需要设置捕获策略的录屏对象。 |
| {OH_AVScreenCapture_CaptureStrategy} | strategy 指向捕获策略对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK} 执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} 输入参数capture或strategy为空指针。<br>         {@link AV_SCREEN_CAPTURE_ERR_UNSUPPORT} 录屏启动之后调用该接口。 |

### OH_AVScreenCapture_StrategyForKeepCaptureDuringCall()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)
```

**描述**

设置蜂窝通话时是否允许进行录屏的策略值

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| {OH_AVScreenCapture_CaptureStrategy} | strategy 指向 OH_AVScreenCapture_CaptureStrategy对象的指针 |
| {bool} | value 默认为false，即蜂窝通话时不允许进行屏幕录制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | 函数结果代码：<br>         {@link AV_SCREEN_CAPTURE_ERR_OK} 执行成功；<br>         {@link AV_SCREEN_CAPTURE_ERR_INVALID_VAL} 输入参数strategy为空指针。 |

### OH_AVScreenCapture_SetCaptureContentChangedCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData)
```

**描述**

设置录屏内容变更回调事件，需在录屏启动前被调用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OH_AVScreenCapture *capture | 指向OH_AVScreenCapture实例的指针。 |
| OH_AVScreenCapture_OnCaptureContentChanged callback | 指向录屏内容变更回调方法实例的指针[OH_AVScreenCapture_OnCaptureContentChanged](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_oncapturecontentchanged)。 |
| void *userData | 指向应用提供的自定义数据的指针，在错误处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVSCREEN_CAPTURE_ErrCode | {@link OH_AVSCREEN_CAPTURE_ErrCode}：<br>         AV_SCREEN_CAPTURE_ERR_OK = 0：操作成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL = 3：参数无效，输入参数capture或callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = 2：不允许操作，设置录屏内容回调失败。 |


