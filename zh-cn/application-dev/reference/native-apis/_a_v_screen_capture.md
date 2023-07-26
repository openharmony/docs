# AVScreenCapture


## 概述

AVScreenCapture模块提供用于屏幕录制的函数。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avscreen_capture.h](native__avscreen_capture_8h.md) | 声明用于构造屏幕录制对象的Native API。<br>引用文件：<multimedia/player_framework/native_avscreen_capture.h> |
| [native_avscreen_capture_base.h](native__avscreen_capture_base_8h.md) | 声明用于运行屏幕录制通用的结构体、字符常量、枚举。<br>引用文件：<multimedia/player_framework/native_avscreen_capture_base.h> |
| [native_avscreen_capture_errors.h](native__avscreen_capture_errors_8h.md) | 声明用于运行屏幕录制过程中接口调用的错误码说明。<br>引用文件：<multimedia/player_framework/native_avscreen_capture_errors.h> |

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVScreenCapture_Create](#oh_avscreencapture_create) (void) | 实例化对象，创建OH_AVScreenCapture。 | 
| [OH_AVScreenCapture_Init](#oh_avscreencapture_init) (OH_AVScreenCapture  \*capture, OH_AVScreenCaptureConfig config) | 初始化录屏实例相关参数，实现对图形子系统和音频子系统相关初始化工作。 | 
| [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) (OH_AVScreenCapture \*capture) | 开始录屏，调用后可以通过相关接口拿到视频和音频的原始码流 | 
| [OH_AVScreenCapture_StopScreenCapture](#oh_avscreencapture_stopscreencapture) (OH_AVScreenCapture \*capture) | 结束录屏 | 
| [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) (OH_AVScreenCapture \*capture, OH_AudioBuffer \*\*audiobuffer, OH_AudioCaptureSourceType type) | 获取音频原始码流接口，包括音频流的类型和长度相关信息 | 
| \*[OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer) (OH_AVScreenCapture \*capture, int32_t \*fence, int64_t \*timestamp, struct OH_Rect \*region) | 获取视频原始码流接口，通过此接口可以获取视频码流以及每帧视频的信息 | 
| [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer) (OH_AVScreenCapture \*capture, OH_AudioCaptureSourceType type) | 释放根据音频类型释放音频buffer，用于用完的音频的buffer的释放 | 
| [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) (OH_AVScreenCapture \*capture) | 释放视频的buffer，用于用完的视频的buffer的释放 | 
| [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) (OH_AVScreenCapture \*capture, OH_AVScreenCaptureCallback callback) | 设置回调的接口，用于回调相关事件的监听 |
| [OH_AVScreenCapture_SetMicrophoneEnabled](#oh_avscreencapture_setmicrophoneenabled) (OH_AVScreenCapture \*capture, bool isMicrophone) | 设置麦克风开关，关闭时，将获得无声的音频数据 |
| [OH_AVScreenCapture_Release](#oh_avscreencapture_release) (OH_AVScreenCapture \*capture) | 用于录屏实例对象的释放 |

## 函数说明

### OH_AVScreenCapture_Create()


```
struct OH_AVScreenCapture *OH_AVScreenCapture_Create(void);
```

**描述：**

实例化对象，创建OH_AVScreenCapture。可以通过调用 OH_AVScreenCapture_Release 释放实例。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| void | 无需入参函数 | 

**返回：**

返回一个指向OH_AVScreenCapture实例的指针。

**起始版本：**

10


### OH_AVScreenCapture_Init()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureConfig config);
```

**描述：**

初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样信息参数，音频内录相关参数(可选)，视频分辨率相关参数

调用此函数，需要向申请麦克风权限(ohos.permission.MICROPHONE)和截屏权限(ohos.permission.CAPTURE_SCREEN),否则会初始化失败导致无法正常录屏

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| config | 录屏初始化相关参数。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10

### OH_AVScreenCapture_StartScreenCapture()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture(struct OH_AVScreenCapture *capture);
```

**描述：**

开始录屏接口,调用该接口后,可以通过回调的监听(OH_AVScreenCaptureOnAudioBufferAvailable，OH_AVScreenCaptureOnVideoBufferAvailable)来监听当前是否有码流的产生。

通过调用获取音频buffer(OH_AVScreenCapture_AcquireAudioBuffer)和视频buffer(OH_AVScreenCapture_ReleaseVideoBuffer)的接口来获取录屏的原始码流

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_StopScreenCapture()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture(struct OH_AVScreenCapture *capture);
```

**描述：**

停止录屏接口, 主要用于停止录屏数据的继续生产

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_AcquireAudioBuffer()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer(struct OH_AVScreenCapture *capture, OH_AudioBuffer **audiobuffer, OH_AudioCaptureSourceType type);
```

**描述：**

获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响拿到音频buffer的获取

buffer使用完成后，调用OH_AVScreenCapture_ReleaseAudioBuffer接口进行音频buffer的释放

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| audiobuffer | 保存音频buffer的结构体，通过该结构体获取到音频buffer以及buffer的时间戳等信息。 | 
| type | 音频buffer的类型，区分mic流还是内录流。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_AcquireVideoBuffer()

  
```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer(struct OH_AVScreenCapture *capture, int32_t *fence, int64_t *timestamp, struct OH_Rect *region);
```

**描述：**

获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息

buffer使用完成后，调用OH_AVScreenCapture_ReleaseVideoBuffer接口进行视频buffer的释放

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| fence | 用于同步的显示相关参数信息。| 
| timestamp | 视频帧的时间戳 | 
| region | 视频显示相关的坐标信息 | 

**返回：**

执行成功返回OH_NativeBuffer对象, 通过OH_NativeBuffer对象相关接口可以获取到视频buffer和粉分辨率等信息参数。

**起始版本：**

10


### OH_AVScreenCapture_ReleaseAudioBuffer()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer(struct OH_AVScreenCapture *capture, OH_AudioCaptureSourceType type);
```

**描述：**

释放音频buffer, 与OH_AVScreenCapture_AcquireAudioBuffer相对应，当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| type | 音频buffer的类型，区分mic流还是内录流。| 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_ReleaseVideoBuffer()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer(struct OH_AVScreenCapture *capture);
```

**描述：**

释放视频buffer, 与OH_AVScreenCapture_AcquireVideoBuffer相对应，当某一帧视频buffer使用完成后，调用此接口进行释放对应的视频buffer

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_SetCallback()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback(struct OH_AVScreenCapture *capture, struct OH_AVScreenCaptureCallback callback);
```

**描述：**

设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| callback | OH_AVScreenCaptureCallback的结构体，保存相关回调函数指针。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_SetMicrophoneEnabled()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled(struct OH_AVScreenCapture *capture, bool isMicrophone);
```

**描述：**

设置mic开关，isMicrophone为true时，则打开麦克风，通过调用OH_AVScreenCapture_StartScreenRecording和OH_AVScreenCapture_AcquireAudioBuffer可以正常获取到音频的麦克风原始pcm数据，为false时，获取到的音频数据为无声数据

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| isMicrophone | 麦克风开关参数 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10


### OH_AVScreenCapture_Release()

  
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release(struct OH_AVScreenCapture *capture);
```

**描述：**

将创建的OH_AVScreenCapture实例进行释放，对应OH_AVScreenCapture_Create

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](native__avscreen_capture_errors_8h.md#oh_avscreen_capture_errcode)。

**起始版本：**

10
