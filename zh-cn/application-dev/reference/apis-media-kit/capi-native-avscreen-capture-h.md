# native_avscreen_capture.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## 概述

声明用于构造屏幕录制对象的API。

**引用文件：** <multimedia/player_framework/native_avscreen_capture.h>

**库：** libnative_avscreen_capture.so

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**相关示例：** [NativeAvScreenCapture](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)](#oh_avscreencapture_create) | 实例化对象，创建OH_AVScreenCapture。<br> 可以通过调用[OH_AVScreenCapture_Release](#oh_avscreencapture_release)释放实例。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)](#oh_avscreencapture_init) | 初始化[OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)相关参数，包括下发的音频麦克风采样相关参数（可选）、音频内录采样相关参数、视频分辨率相关参数。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreencapture) | 开始录屏，采集原始码流。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreencapture) | 结束录屏，与[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_startscreenrecording) | 启动录屏，调用此接口，可保存录屏文件。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_stopscreenrecording) | 停止录屏，与[OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording)配合使用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)](#oh_avscreencapture_acquireaudiobuffer) | 获取音频buffer。应用调用时需分配audiobuffer对应结构体大小的内存，否则影响音频buffer的获取。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture,int32_t *fence, int64_t *timestamp, struct OH_Rect *region)](#oh_avscreencapture_acquirevideobuffer) | 获取视频buffer。应用通过此接口获取视频缓存区及时间戳等信息。<br> buffer使用完成后，调用OH_AVScreenCapture_ReleaseVideoBuffer接口进行视频buffer的释放。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)](#oh_avscreencapture_releaseaudiobuffer) | 根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_releasevideobuffer) | 根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口释放对应的视频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)](#oh_avscreencapture_setcallback) | 设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback)、[OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback)替代。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)](#oh_avscreencapture_release) | 释放创建的OH_AVScreenCapture实例，对应[OH_AVScreenCapture_Create](#oh_avscreencapture_create)。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)](#oh_avscreencapture_setmicrophoneenabled) | 设置麦克风开关。<br> 当isMicrophone为true时，则打开麦克风，通过调用[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)和[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。<br> 默认麦克风开关为开启。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)](#oh_avscreencapture_setstatecallback) | 设置状态变更处理回调方法，在开始录制前调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)](#oh_avscreencapture_setdatacallback) | 设置数据处理回调方法，在开始录制前调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)](#oh_avscreencapture_seterrorcallback) | 设置错误处理回调方法，在开始录制前调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface(struct OH_AVScreenCapture *capture,OHNativeWindow *window)](#oh_avscreencapture_startscreencapturewithsurface) | 使用Surface模式录屏。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)](#oh_avscreencapture_setcanvasrotation) | 设置录屏屏幕数据旋转。<br> 调用该方法可以设置录屏屏幕数据是否旋转，当canvasRotation为true时，打开录屏屏幕数据旋转功能，录制的屏幕数据保持正向。<br> 默认为false。 |
| [struct OH_AVScreenCapture_ContentFilter *OH_AVScreenCapture_CreateContentFilter(void)](#oh_avscreencapture_createcontentfilter) | 创建ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter(struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_releasecontentfilter) | 释放ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent(struct OH_AVScreenCapture_ContentFilter *filter, OH_AVScreenCaptureFilterableAudioContent content)](#oh_avscreencapture_contentfilter_addaudiocontent) | 向ContentFilter实例添加可过滤的声音类型。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent(struct OH_AVScreenCapture *capture,struct OH_AVScreenCapture_ContentFilter *filter)](#oh_avscreencapture_excludecontent) | 设置OH_AVScreenCapture实例的内容过滤器ContentFilter。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_contentfilter_addwindowcontent) | 向ContentFilter实例添加可被过滤的窗口ID列表。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)](#oh_avscreencapture_resizecanvas) | 调整屏幕的分辨率。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)](#oh_avscreencapture_skipprivacymode) | 录屏时豁免隐私窗口。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)](#oh_avscreencapture_setmaxvideoframerate) | 设置录屏时的最大帧率。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)](#oh_avscreencapture_showcursor) | 设置光标显示开关。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnDisplaySelected callback, void *userData)](#oh_avscreencapture_setdisplaycallback) | 设置获取录屏屏幕Id的回调。 |
| [OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)](#oh_avscreencapture_createcapturestrategy) | 创建录屏策略对象。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)](#oh_avscreencapture_releasecapturestrategy) | 释放录屏策略对象。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)](#oh_avscreencapture_setcapturestrategy) | 给指定的OH_AVScreenCapture实例设置捕获策略。<br> 该接口应在录屏启动之前被调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)](#oh_avscreencapture_strategyforkeepcaptureduringcall) | 向CaptureStrategy实例设置蜂窝通话时是否保持录屏。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureContentChangedCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnCaptureContentChanged callback, void *userData)](#oh_avscreencapture_setcapturecontentchangedcallback) | 设置录屏内容变更回调事件，需在录屏启动前被调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureArea(struct OH_AVScreenCapture \*capture,uint64_t displayId, OH_Rect\* area)](#oh_avscreencapture_setcapturearea) | 设置或更新捕获区域。<br> 接口在开始录屏前后都可以设置，设置的坐标和宽高不能为负数，捕获区域不能跨屏幕，区域位置设置失败后仍按照上一次的区域进行捕获。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPrivacyMaskMode(OH_AVScreenCapture_CaptureStrategy *strategy, int32_t value)](#oh_avscreencapture_strategyforprivacymaskmode) | 设置隐私窗口屏蔽模式。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetSelectionCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnUserSelected callback, void *userData)](#oh_avscreencapture_setselectioncallback) | 注册手工确认界面用户选择结果的回调，需在录屏启动前被调用。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetCaptureTypeSelected(OH_AVScreenCapture_UserSelectionInfo \*selection,int32_t\* type)](#oh_avscreencapture_getcapturetypeselected) | 获取用户在确认界面选择的屏幕捕获对象类型。在[OH_AVScreenCapture_OnUserSelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onuserselected)回调中使用，selection指针在回调结束后销毁。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetDisplayIdSelected(OH_AVScreenCapture_UserSelectionInfo \*selection,uint64_t\* displayId)](#oh_avscreencapture_getdisplayidselected) | 获取确认页面，用户选择录制的屏幕ID。在[OH_AVScreenCapture_OnUserSelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onuserselected)回调中使用，selection指针在回调结束后销毁。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForBFramesEncoding(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)](#oh_avscreencapture_strategyforbframesencoding) | 向CaptureStrategy实例设置是否使能B帧编码，用于减小录制文件的大小。<br>B帧视频编码相关的约束和限制可以参考文档[B帧视频编码约束和限制](../../media/avcodec/video-encoding-b-frame.md#约束和限制)。如果当前不符合B帧视频编码的约束和限制，则正常录制不含B帧的视频，不会返回错误。 |
| [OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPickerPopUp(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)](#oh_avscreencapture_strategyforpickerpopup) | 设置是否弹出屏幕捕获Picker。 |

## 函数说明

### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void)
```

**描述**

实例化对象，创建OH_AVScreenCapture。<br> 可以通过调用[OH_AVScreenCapture_Release](#oh_avscreencapture_release)释放实例。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**返回：**

| 类型 | 说明 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) * | 返回一个指向OH_AVScreenCapture实例的指针。 |

### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureConfig config)
```

**描述**

初始化[OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)相关参数，包括下发的音频麦克风采样相关参数（可选）、音频内录采样相关参数、视频分辨率相关参数。<br> 录屏存文件场景，应用需要保证视频编码参数、视频采样参数、音频编码参数、音频内录采样参数均合法，音频麦克风采样参数合法（可选）。<br> 录屏出码流场景，应用需要保证音频内录采样参数、视频采样参数至少一个合法，音频麦克风采样参数合法（可选）。<br> 由于结构体变量在初始化时不会对成员进行初始化，应用必须根据使用场景正确设置各项参数。建议应用先将OH_AVScreenCaptureConfig结构体变量的所有内存字节均设置为0，然后再根据录屏场景设置合法参数。<br> 音频采样参数结构体[OH_AudioCaptureInfo](capi-avscreencapture-oh-audiocaptureinfo.md)，若audioSampleRate和audioChannels同时为0，则录屏实例OH_AVScreenCapture将忽略该类型的音频参数，且不采集该类型的音频数据。<br> 视频采样参数结构体[OH_VideoCaptureInfo](capi-avscreencapture-oh-videocaptureinfo.md)，若videoFrameWidth和videoFrameHeight同时为0，则录屏实例OH_AVScreenCapture将忽略对应视频参数，且不采集屏幕数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureConfig](capi-avscreencapture-oh-avscreencaptureconfig.md) config | 录屏初始化相关参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，初始化配置失败。 |

### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture)
```

**描述**

开始录屏，采集原始码流。<br> 调用后可以通过回调的监听（[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)）来监听当前是否有码流的产生,通过回调的监听（[OH_AVScreenCapture_OnStateChange](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onstatechange)）来监听启动状态。<br> 通过调用获取音频buffer（[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)）和视频buffer（[OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer)）的接口来获取录屏的原始码流。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启动录屏失败。 |

### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture)
```

**描述**

结束录屏，与[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，结束录屏失败。 |

### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording(struct OH_AVScreenCapture *capture)
```

**描述**

启动录屏，调用此接口，可保存录屏文件。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启用屏幕录制失败。 |

### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording(struct OH_AVScreenCapture *capture)
```

**描述**

停止录屏，与[OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording)配合使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，停止屏幕录制失败。 |

### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type)
```

**描述**

获取音频buffer。应用调用时需分配audiobuffer对应结构体大小的内存，否则影响音频buffer的获取。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AudioBuffer](capi-avscreencapture-oh-audiobuffer.md) **audiobuffer | 保存音频buffer的结构体，通过该结构体获取到音频buffer以及buffer的时间戳等信息。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | 音频buffer的类型，区分是麦克风录制的外部流还是系统内部播放音频的内录流。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数audiobuffer为空指针。<br>         AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，audiobuffer分配失败。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或获取音频buffer失败。 |

### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture,int32_t *fence, int64_t *timestamp, struct OH_Rect *region)
```

**描述**

获取视频buffer。应用通过此接口获取视频缓存区及时间戳等信息。<br> buffer使用完成后，调用OH_AVScreenCapture_ReleaseVideoBuffer接口进行视频buffer的释放。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t *fence | 用于同步的显示相关参数信息。 |
| int64_t *timestamp | 视频帧的时间戳。 |
| [struct OH_Rect](capi-avscreencapture-oh-rect.md) *region | 视频显示相关的坐标信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NativeBuffer](capi-avscreencapture-avscreencapture-oh-nativebuffer.md)* | 执行成功返回OH_NativeBuffer对象，通过OH_NativeBuffer对象相关接口可以获取到视频buffer和分辨率等信息参数。 |

### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture,OH_AudioCaptureSourceType type)
```

**描述**

根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | 音频buffer的类型，区分麦克风录制的外部流还是系统内部播放音频的内录流。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，不允许用于已设置过DataCallback或释放音频buffer失败。 |

### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture)
```

**描述**

根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口释放对应的视频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，不允许用于已设置过DataCallback或释放视频buffer失败。 |

### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture,struct OH_AVScreenCaptureCallback callback)
```

**描述**

设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。<br> 从API 12开始，推荐使用接口[OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback)、[OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [struct OH_AVScreenCaptureCallback](capi-avscreencapture-oh-avscreencapturecallback.md) callback | OH_AVScreenCaptureCallback的结构体，保存相关回调函数指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置监听接口失败。 |

### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture)
```

**描述**

释放创建的OH_AVScreenCapture实例，对应[OH_AVScreenCapture_Create](#oh_avscreencapture_create)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，OH_AVScreenCapture实例释放失败。 |

### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture,bool isMicrophone)
```

**描述**

设置麦克风开关。<br> 当isMicrophone为true时，则打开麦克风，通过调用[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)和[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。<br> 默认麦克风开关为开启。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool isMicrophone | 麦克风开关参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置麦克风开关失败。 |

### OH_AVScreenCapture_SetStateCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnStateChange callback, void *userData)
```

**描述**

设置状态变更处理回调方法，在开始录制前调用。<br> 调用该方法设置状态变更处理回调方法，当OH_AVScreenCapture实例发生状态变更时，该状态变更处理回调方法将会被调用。<br> 调用该设置方法成功后，在启动录屏时将通过隐私弹窗方式征求用户同意：<br> 1. 如果用户同意则开始启动录屏流程，在启动录屏成功后，通过该状态处理回调方法上报[OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_STARTED状态，告知应用启动录屏成功，并在屏幕显示录屏通知。如果启动录屏失败，则通过该状态处理回调方法上报失败状态信息（如，若麦克风不可用则上报[OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE状态），或通过错误处理回调方法[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)上报错误信息。<br> 2. 如果用户拒绝，则终止启动录屏，通过该状态处理回调方法上报[OH_AVScreenCaptureStateCode](capi-native-avscreen-capture-base-h.md#oh_avscreencapturestatecode).OH_SCREEN_CAPTURE_STATE_CANCELED状态，告知应用用户拒绝启动录屏，启动录屏失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_OnStateChange](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onstatechange) callback | 指向状态处理回调方法实例的指针。 |
| void *userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置StateCallback失败。 |

### OH_AVScreenCapture_SetDataCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnBufferAvailable callback, void *userData)
```

**描述**

设置数据处理回调方法，在开始录制前调用。<br> 调用该方法设置数据处理回调方法，当OH_AVScreenCapture操作期间有音频或视频数据缓存区可用时，将调用该数据处理回调方法。<br> 应用需要在该数据处理回调方法中根据数据类型完成处理麦克风音频、内录音频、视频数据，当该数据处理回调方法返回后数据缓存区将不再有效。<br> 调用该方法成功后：<br> 1. 当OH_AVScreenCapture操作期间有音视频缓存区可用时，将不再调用通过[OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback)设置的数据回调方法[OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable)和[OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable)。<br> 2. 不允许应用调用如下4个方法[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)、[OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer)、[OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer)和[OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer)，直接返回失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) callback | 指向数据处理回调方法实例的指针。 |
| void *userData | 指向应用提供的自定义数据的指针，在数据处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置DataCallback失败。 |

### OH_AVScreenCapture_SetErrorCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnError callback, void *userData)
```

**描述**

设置错误处理回调方法，在开始录制前调用。<br> 调用该方法设置错误处理回调方法，当OH_AVScreenCapture实例发生错误时，该错误处理回调方法将会被调用。<br> 调用该设置方法成功后，当OH_AVScreenCapture实例发生错误时，将不再调用通过[OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback)设置的错误处理回调方法[OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror) callback | 指向错误处理回调方法实例的指针。 |
| void *userData | 指向应用提供的自定义数据的指针，在错误处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置ErrorCallback失败。 |

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
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) *window | 指向OHNativeWindow实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数window为空指针或window指向的windowSurface为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启动ScreenCaptureWithSurface失败。 |

### OH_AVScreenCapture_SetCanvasRotation()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation(struct OH_AVScreenCapture *capture,bool canvasRotation)
```

**描述**

设置录屏屏幕数据旋转。<br> 调用该方法可以设置录屏屏幕数据是否旋转，当canvasRotation为true时，打开录屏屏幕数据旋转功能，录制的屏幕数据保持正向。<br> 默认为false。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool canvasRotation | 指示屏幕数据旋转参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置录屏屏幕数据旋转失败。 |

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
| [struct OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) * | 执行成功返回OH_AVScreenCapture_ContentFilter实例，否则返回空指针。 |

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
| [struct OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数filter为空指针。 |

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
| [struct OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |
| [OH_AVScreenCaptureFilterableAudioContent](capi-native-avscreen-capture-base-h.md#oh_avscreencapturefilterableaudiocontent) content | OH_AVScreenCaptureFilterableAudioContent实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数filter为空指针或输入参数content无效。 |

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
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [struct OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数filter为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT：操作不支持。对于流，启动时应该调用AudioCapturer接口。<br>         对于capture文件，启动时调用Recorder接口。 |

### OH_AVScreenCapture_ContentFilter_AddWindowContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent(struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)
```

**描述**

向ContentFilter实例添加可被过滤的窗口ID列表。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) *filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。 |
| int32_t *windowIDs | 指向窗口ID的指针。 |
| int32_t windowCount | 窗口ID列表的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | 执行成功返回AV_SCREEN_CAPTURE_ERR_OK，否则返回具体错误码。 |

### OH_AVScreenCapture_ResizeCanvas()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas(struct OH_AVScreenCapture *capture,int32_t width, int32_t height)
```

**描述**

调整屏幕的分辨率。<br> 调用该方法可以设置录屏屏幕数据的分辨率，width为屏幕的宽度，height为屏幕的高度。<br> 该接口目前仅支持录屏取码流的场景，不支持录屏存文件的场景。并且调用该接口的调用者以及视频数据的消费者需要确保自身能够支持收到的视频数据分辨率发生变化。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t width | 录屏屏幕的宽度。 |
| int32_t height | 录屏屏幕的高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作。 |

### OH_AVScreenCapture_SkipPrivacyMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode(struct OH_AVScreenCapture *capture,int32_t *windowIDs, int32_t windowCount)
```

**描述**

录屏时豁免隐私窗口。<br> 调用该方法可以豁免隐私窗口，windowIDs为需要豁免的隐私窗口ID指针，windowCount 为隐私窗口ID列表的长度，目前豁免需要传入所有隐私子窗口和主窗口ID。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t *windowIDs | 向隐私窗口ID的指针。 |
| int32_t windowCount | 隐私窗口ID列表的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作。 |

### OH_AVScreenCapture_SetMaxVideoFrameRate()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate(struct OH_AVScreenCapture *capture,int32_t frameRate)
```

**描述**

设置录屏时的最大帧率。<br> 该接口应在录屏启动之后被调用。<br> 调用该方法可以设置录屏时的最大帧率，frameRate为想要设置的最大帧率。<br> 该接口设置最大帧率时，实际设置的帧率受限设备的能力，由底层的系统能力决定。<br> 调用该接口设置录屏最大帧率时，实际帧率将受限于设备能力。目前接口入参的最大值不设限制，但当前支持的最高帧率为60FPS，当入参设置超过60FPS，将以60FPS处理。不超过上限时，则按照实际入参值处理。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| int32_t frameRate | 录屏的最大帧率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或者输入参数frameRate不支持。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作。 |

### OH_AVScreenCapture_ShowCursor()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture,bool showCursor)
```

**描述**

设置光标显示开关。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| bool showCursor | 光标显示参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。<br>         AV_SCREEN_CAPTURE_ERR_UNSUPPORT（API 20新增）：设备不支持该操作。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置光标失败。 |

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
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_OnDisplaySelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_ondisplayselected) callback | 指向录屏屏幕Id回调方法实例的指针。 |
| void *userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_STATE：回调必须在start方法前调用。 |

### OH_AVScreenCapture_CreateCaptureStrategy()

```
OH_AVScreenCapture_CaptureStrategy* OH_AVScreenCapture_CreateCaptureStrategy(void)
```

**描述**

创建录屏策略对象。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md)* | 执行成功返回OH_AVScreenCapture_CaptureStrategy实例，否则返回空指针。 |

### OH_AVScreenCapture_ReleaseCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseCaptureStrategy(OH_AVScreenCapture_CaptureStrategy* strategy)
```

**描述**

释放录屏策略对象。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md)* strategy | 指向录屏策略对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数strategy为空指针。 |

### OH_AVScreenCapture_SetCaptureStrategy()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureStrategy(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_CaptureStrategy *strategy)
```

**描述**

给指定的OH_AVScreenCapture实例设置捕获策略。<br> 该接口应在录屏启动之前被调用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) *strategy | 指向捕获策略对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture或strategy为空指针。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_STATE：在录屏启动之后调用该接口。 |

### OH_AVScreenCapture_StrategyForKeepCaptureDuringCall()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)
```

**描述**

向CaptureStrategy实例设置蜂窝通话时是否保持录屏。<br> value设置为true时并且录屏时接听蜂窝通话的过程中，出于隐私要求，双方通话的声音（本地麦克风和对方说话声音）不会被录制，其他系统音录制正常。电话挂断之后，录屏框架恢复麦克风录制。注意，如果挂断电话时录屏应用在后台运行，麦克风录制会启动失败，原因是音频模块不允许后台应用启动麦克风录制。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) *strategy | 指向OH_AVScreenCapture_CaptureStrategy对象的指针。 |
| bool value | 蜂窝通话时是否可以进行屏幕录制。<br> true表示蜂窝通话时可以录屏，false表示蜂窝通话时不允许录屏。<br> 默认是false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数strategy为空指针。 |

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
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_OnCaptureContentChanged](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_oncapturecontentchanged) callback | 指向录屏内容变更回调方法实例的指针。 |
| void *userData | 指向应用提供的自定义数据的指针，在错误处理回调方法被调用时作为入参回传。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：操作成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：参数无效，输入参数capture或callback为空指针。<br>         AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置录屏内容回调失败。 |

### OH_AVScreenCapture_SetCaptureArea()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCaptureArea(struct OH_AVScreenCapture *capture,uint64_t displayId, OH_Rect* area)
```

**描述**

设置或更新捕获区域。<br> 接口在开始录屏前后都可以设置，设置的坐标和宽高不能为负数，捕获区域不能跨屏幕，区域位置设置失败后仍按照上一次的区域进行捕获。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture的指针。 |
| uint64_t displayId | 需要执行屏幕捕获的屏幕ID。 |
| [OH_Rect](capi-avscreencapture-oh-rect.md)* area | 指定捕获的区域。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针、输入displayId不存在或输入的捕获区域异常。 |

### OH_AVScreenCapture_StrategyForPrivacyMaskMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPrivacyMaskMode(OH_AVScreenCapture_CaptureStrategy *strategy, int32_t value)
```

**描述**

设置隐私窗口屏蔽模式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) *strategy | 指向OH_AVScreenCapture_CaptureStrategy实例的指针。 |
| int32_t value | 设置为0，表示存在隐私窗口时，采用全屏屏蔽模式。<br> 设置为1，表示存在隐私窗口时，采用隐私窗口屏蔽模式，设置为其他值时返回错误。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数strategy为空指针或输入value为无效值。 |

### OH_AVScreenCapture_SetSelectionCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetSelectionCallback(struct OH_AVScreenCapture *capture,OH_AVScreenCapture_OnUserSelected callback, void *userData)
```

**描述**

注册手工确认界面用户选择结果的回调，需在录屏启动前被调用。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 需要注册该回调的屏幕捕获对象。 |
| [OH_AVScreenCapture_OnUserSelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onuserselected) callback | 用户在界面确认后，通过该函数通知应用进行逻辑处理。 |
| void *userData | 应用传入的控制块指针，在返回时携带给应用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。 |

### OH_AVScreenCapture_GetCaptureTypeSelected()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetCaptureTypeSelected(OH_AVScreenCapture_UserSelectionInfo *selection,int32_t* type)
```

**描述**

获取用户在确认界面选择的屏幕捕获对象类型。在[OH_AVScreenCapture_OnUserSelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onuserselected)回调中使用，selection指针在回调结束后销毁。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_UserSelectionInfo](capi-avscreencapture-oh-avscreencapture-userselectioninfo.md) *selection | 指向OH_AVScreenCapture_UserSelectionInfo实例的指针。 |
| int32_t* type | 用户选择的捕获对象类型，0：代表屏幕，1：代表窗口。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数selection为空指针。 |

### OH_AVScreenCapture_GetDisplayIdSelected()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_GetDisplayIdSelected(OH_AVScreenCapture_UserSelectionInfo *selection,uint64_t* displayId)
```

**描述**

获取确认页面，用户选择录制的屏幕ID。在[OH_AVScreenCapture_OnUserSelected](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onuserselected)回调中使用，selection指针在回调结束后销毁。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_UserSelectionInfo](capi-avscreencapture-oh-avscreencapture-userselectioninfo.md) *selection | 指向OH_AVScreenCapture_UserSelectionInfo实例的指针。 |
| uint64_t* displayId | 返回用户选择的屏幕ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数selection为空指针。 |

### OH_AVScreenCapture_StrategyForBFramesEncoding()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForBFramesEncoding(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)
```

**描述**

向CaptureStrategy实例设置是否使能B帧编码，用于减小录制文件的大小。<br> B帧视频编码相关的约束和限制可以参考文档[B帧视频编码约束和限制](../../media/avcodec/video-encoding-b-frame.md#约束和限制)。如果当前不符合B帧视频编码的约束和限制，则正常录制不含B帧的视频，不会返回错误。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) *strategy | 指向OH_AVScreenCapture_CaptureStrategy对象的指针。 |
| bool value | 录屏文件是否使能B帧编码。<br> true表示录屏文件使能B帧编码，false表示录屏文件禁用B帧编码。<br> 默认是false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数strategy为空指针。 |

### OH_AVScreenCapture_StrategyForPickerPopUp()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StrategyForPickerPopUp(OH_AVScreenCapture_CaptureStrategy *strategy, bool value)
```

**描述**

设置是否弹出屏幕捕获Picker。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) *strategy | 指向OH_AVScreenCapture_CaptureStrategy对象的指针。 |
| bool value | 设置为false，代表APP已经指定了录屏内容，录屏启动后无需弹出Picker；设置为true代表录屏启动后统一弹出Picker；不设置，代表使用系统推荐行为。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode) | AV_SCREEN_CAPTURE_ERR_OK：执行成功。<br>         AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数strategy为空指针或输入value为无效值。 |


