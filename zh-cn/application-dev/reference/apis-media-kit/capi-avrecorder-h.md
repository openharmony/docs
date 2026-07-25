# avrecorder.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

## 概述

定义AVRecorder接口。AVRecorder提供媒体录制能力，支持音视频数据的采集与录制、完整的状态管理与回调监听、灵活的编码器选择与参数配置等，适用于需要将音视频内容录制保存为文件的场景。

**引用文件：** <multimedia/player_framework/avrecorder.h>

**库：** libavrecorder.so

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVRecorder *OH_AVRecorder_Create(void)](#oh_avrecorder_create) | 创建AVRecorder实例。调用成功之后进入IDLE状态。必须在使用完毕后调用[OH_AVRecorder_Release](#oh_avrecorder_release)释放资源，否则会导致录制资源泄漏。 |
| [OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)](#oh_avrecorder_prepare) | 配置AVRecorder参数，准备录制。<br>若未配置视频相关参数，则只录制音频；同理，若未配置音频相关参数，则只录制视频。<br>需在IDLE状态下调用，调用成功后进入PREPARED状态。 |
| [OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)](#oh_avrecorder_getavrecorderconfig) | 获取当前的录制参数。典型使用场景包括：录制开始前确认配置参数是否正确、在UI界面上展示当前录制设置信息等。<br>传入的\*config必须为nullptr，由框架层统一分配和释放内存，防止内存泄漏或重复释放等问题。<br>需在PREPARED状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)](#oh_avrecorder_getinputsurface) | 获取输入Surface。<br>传入的*window必须为nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。<br>此Surface提供给调用者，调用者从此Surface中获取Surface Buffer，填入待录制的视频数据。<br>需在PREPARED状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)](#oh_avrecorder_updaterotation) | 更新视频旋转角度。典型使用场景包括：设备横竖屏切换时调整视频方向、根据摄像头采集方向设置视频旋转角度等。<br>需在PREPARED状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)](#oh_avrecorder_start) | 开始录制。<br>需在PREPARED状态下调用，调用成功后进入STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)](#oh_avrecorder_pause) | 暂停录制。<br>需在STARTED状态下调用，调用成功后进入PAUSED状态。<br>之后可以通过调用[OH_AVRecorder_Resume](#oh_avrecorder_resume)恢复录制，重新进入STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)](#oh_avrecorder_resume) | 恢复录制。<br>需在PAUSED状态下调用，调用成功后进入STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)](#oh_avrecorder_stop) | 停止录制。<br>需在STARTED/PAUSED状态下调用，调用成功后进入STOPPED状态。<br>纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。<br>纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。 |
| [OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)](#oh_avrecorder_reset) | 重置录制状态。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED/ERROR状态下调用，调用成功后进入IDLE状态。<br>纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。<br>纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。 |
| [OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)](#oh_avrecorder_release) | 释放录制资源。<br>调用此接口释放录制资源后，recorder内存将释放。应用层需要显式地将recorder指针置空，以避免访问野指针。释放录制资源之后，该OH_AVRecorder实例不能再进行任何操作。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED/ERROR状态下调用，调用成功后进入RELEASED状态。 |
| [OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info, int32_t *length)](#oh_avrecorder_getavailableencoder) | 获取AVRecorder可用的编码器信息。典型使用场景包括：应用启动时查询设备支持的编码器、根据可用编码器选择合适的编码格式、在编码器选择界面展示可选列表等。<br>参数\*info必须为nullptr，由框架层统一分配和释放内存，防止内存泄漏或重复释放等问题。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)](#oh_avrecorder_setstatecallback) | 设置状态变化回调函数，以便应用能够响应AVRecorder生成的状态变化事件。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个状态变化回调函数，当用户重复设置时，以最后一次设置的回调函数为准。 |
| [OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)](#oh_avrecorder_seterrorcallback) | 设置错误回调函数，以便应用能够响应AVRecorder生成的错误事件。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个错误回调函数，当用户重复设置时，以最后一次设置的回调函数为准。 |
| [OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)](#oh_avrecorder_seturicallback) | 设置URI回调函数，当[OH_AVRecorder_FileGenerationMode](capi-avrecorder-base-h.md#oh_avrecorder_filegenerationmode)枚举设置为系统创建媒体文件时，会在[OH_AVRecorder_Stop](#oh_avrecorder_stop)操作结束后把[OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md)对象回调给应用。典型使用场景包括：录制完成后获取输出文件的URI路径用于文件分享或展示、根据URI更新应用内的文件列表等。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个URI回调函数，当用户重复设置时，以最后一次设置的回调函数为准。 |
| [OH_AVErrCode OH_AVRecorder_SetWillMuteWhenInterrupted(OH_AVRecorder *recorder, bool muteWhenInterrupted)](#oh_avrecorder_setwillmutewheninterrupted) | 设置是否开启静音打断模式，用于控制音频流被打断时的处理行为。设置成true表示音频流被打断时录制静音，设置成false表示音频流被打断时停止录制，默认值为false。此接口必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口之前调用。<br>需在IDLE状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_GetAudioCapturerMaxAmplitude(OH_AVRecorder *recorder, int32_t *amplitude)](#oh_avrecorder_getaudiocapturermaxamplitude) | 获取当前音频最大振幅，典型使用场景包括：音频录制时实时显示音量级别、音频波形可视化、检测录制是否处于静音状态等。获取到的值为最近两次调用之间的最大振幅。例如，在1s时获取过一次最大振幅，然后在2s时再次调用该接口，那么返回值是1s到2s之间的最大振幅值。<br>需在PREPARED/STARTED/PAUSED状态下调用。 |
| [OH_AVErrCode OH_AVRecorder_SetMetadata(OH_AVRecorder *recorder, const OH_AVFormat *metadata)](#oh_avrecorder_setmetadata) | 设置录制的元数据信息。典型使用场景包括：在录制的视频或音频文件中添加作者信息、版权信息、地理位置、录制时间等自定义元数据。如果metadata参数与config.metadata.customInfo（参考[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md)）中存在相同的键，前者的对应值将覆盖后者。<br>需在PREPARED/STARTED/PAUSED状态下调用。 |

## 函数说明

### OH_AVRecorder_Create()

```c
OH_AVRecorder *OH_AVRecorder_Create(void)
```

**描述**

创建AVRecorder实例。调用成功之后进入IDLE状态。必须在使用完毕后调用[OH_AVRecorder_Release](#oh_avrecorder_release)释放资源，否则会导致录制资源泄漏。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) | 成功时返回指向OH_AVRecorder实例的指针，用于后续的录制操作（如Prepare、Start、Pause等）；失败时返回nullptr。 |

### OH_AVRecorder_Prepare()

```c
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)
```

**描述**

配置AVRecorder参数，准备录制。<br>若未配置视频相关参数，则只录制音频；同理，若未配置音频相关参数，则只录制视频。<br>需在IDLE状态下调用，调用成功后进入PREPARED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) *config | 指向OH_AVRecorder_Config实例的指针，用于配置录制的音视频参数，包括音频和视频的编码格式、采样率、分辨率等配置信息。若未配置视频相关参数，则只录制音频；若未配置音频相关参数，则只录制视频。不可为nullptr，否则返回AV_ERR_INVALID_VAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的recorder/config为nullptr或准备失败。 |

### OH_AVRecorder_GetAVRecorderConfig()

```c
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)
```

**描述**

获取当前的录制参数。典型使用场景包括：录制开始前确认配置参数是否正确、在UI界面上展示当前录制设置信息等。<br>传入的\*config必须为nullptr，由框架层统一分配和释放内存，防止内存泄漏或重复释放等问题。<br>需在PREPARED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) **config | 指向OH_AVRecorder_Config实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的recorder为nullptr或\*config不为nullptr。<br>AV_ERR_NO_MEMORY（1）：内存不足，\*config内存分配失败，请释放资源后重试。 |

### OH_AVRecorder_GetInputSurface()

```c
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)
```

**描述**

获取输入Surface。<br>传入的*window必须为nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。<br>此Surface提供给调用者，调用者从此Surface中获取Surface Buffer，填入待录制的视频数据。<br>需在PREPARED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) **window | 指向OHNativeWindow实例指针的指针，用于获取输入Surface。\*window必须为nullptr，由框架层统一分配和释放内存，防止内存泄漏或重复释放等问题。调用成功后，\*window指向框架层分配的OHNativeWindow实例，调用者可从此实例中获取Surface填入视频数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr。 |

### OH_AVRecorder_UpdateRotation()

```c
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)
```

**描述**

更新视频旋转角度。典型使用场景包括：设备横竖屏切换时调整视频方向、根据摄像头采集方向设置视频旋转角度等。<br>需在PREPARED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| int32_t rotation | 视频旋转角度，单位为度（°）。可选值：0°（无旋转，适用于正常方向录制）、90°（旋转90°，适用于设备顺时针横屏切换时调整视频方向）、180°（旋转180°，适用于倒置方向录制）、270°（旋转270°，适用于设备逆时针横屏切换时调整视频方向）。必须是上述值中的一个，传入其他角度值时返回AV_ERR_INVALID_VAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或输入的rotation不符合要求或更新视频旋转角度失败。 |

### OH_AVRecorder_Start()

```c
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)
```

**描述**

开始录制。<br>需在PREPARED状态下调用，调用成功后进入STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或启动失败。 |

### OH_AVRecorder_Pause()

```c
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)
```

**描述**

暂停录制。<br>需在STARTED状态下调用，调用成功后进入PAUSED状态。<br>之后可以通过调用[OH_AVRecorder_Resume](#oh_avrecorder_resume)恢复录制，重新进入STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或暂停失败。 |

### OH_AVRecorder_Resume()

```c
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)
```

**描述**

恢复录制。<br>需在PAUSED状态下调用，调用成功后进入STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或恢复失败。 |

### OH_AVRecorder_Stop()

```c
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)
```

**描述**

停止录制。<br>需在STARTED/PAUSED状态下调用，调用成功后进入STOPPED状态。<br>纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。<br>纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或停止失败。 |

### OH_AVRecorder_Reset()

```c
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)
```

**描述**

重置录制状态。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED/ERROR状态下调用，调用成功后进入IDLE状态。<br>纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口才能重新录制。<br>纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或重置失败。 |

### OH_AVRecorder_Release()

```c
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)
```

**描述**

释放录制资源。<br>调用此接口释放录制资源后，recorder内存将释放。应用层需要显式地将recorder指针置空，以避免访问野指针。释放录制资源之后，该OH_AVRecorder实例不能再进行任何操作。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED/ERROR状态下调用，调用成功后进入RELEASED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或释放失败。 |

### OH_AVRecorder_GetAvailableEncoder()

```c
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info, int32_t *length)
```

**描述**

获取AVRecorder可用的编码器信息。典型使用场景包括：应用启动时查询设备支持的编码器、根据可用编码器选择合适的编码格式、在编码器选择界面展示可选列表等。<br>参数\*info必须为nullptr，由框架层统一分配和释放内存，防止内存泄漏或重复释放等问题。<br>需在IDLE/PREPARED/STARTED/PAUSED/STOPPED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_EncoderInfo](capi-avrecorder-oh-avrecorder-encoderinfo.md) **info | 指向OH_AVRecorder_EncoderInfo实例指针的指针，用于获取可用编码器信息数组。传入时\*info必须为nullptr，调用成功后，\*info指向框架层分配的编码器信息数组，由框架层统一释放。 |
| int32_t *length | 输出参数，用于返回可用编码器数组的元素个数。调用成功后，\*length的值表示\*info数组中编码器信息的数量，与info参数配合使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的recorder为nullptr或\*info不为nullptr。<br>AV_ERR_NO_MEMORY（1）：内存不足，\*info内存分配失败，请释放资源后重试。 |

### OH_AVRecorder_SetStateCallback()

```c
OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)
```

**描述**

设置状态变化回调函数，以便应用能够响应AVRecorder生成的状态变化事件。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个状态变化回调函数，当用户重复设置时，以最后一次设置的回调函数为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_OnStateChange](capi-avrecorder-base-h.md#oh_avrecorder_onstatechange) callback | 状态回调函数，用于接收AVRecorder状态变化事件。当AVRecorder状态发生切换时（如开始录制、暂停录制、停止录制等状态变更）触发此回调。必须为有效的函数指针，不能为nullptr。 |
| void *userData | 用户自定义数据指针，将在状态变化回调函数被触发时传递给回调函数，供应用层使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或回调函数为nullptr。 |

### OH_AVRecorder_SetErrorCallback()

```c
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)
```

**描述**

设置错误回调函数，以便应用能够响应AVRecorder生成的错误事件。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个错误回调函数，当用户重复设置时，以最后一次设置的回调函数为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_OnError](capi-avrecorder-base-h.md#oh_avrecorder_onerror) callback | 错误回调函数，用于接收AVRecorder错误事件。当录制过程中发生错误时（如编码器异常、文件写入失败等）触发此回调。必须为有效的函数指针，不能为nullptr。 |
| void *userData | 用户自定义数据指针，将在错误回调函数被触发时传递给回调函数，供应用层使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或回调函数为nullptr。 |

### OH_AVRecorder_SetUriCallback()

```c
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)
```

**描述**

设置URI回调函数，当[OH_AVRecorder_FileGenerationMode](capi-avrecorder-base-h.md#oh_avrecorder_filegenerationmode)枚举设置为系统创建媒体文件时，会在[OH_AVRecorder_Stop](#oh_avrecorder_stop)操作结束后把[OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md)对象回调给应用。典型使用场景包括：录制完成后获取输出文件的URI路径用于文件分享或展示、根据URI更新应用内的文件列表等。<br>需在IDLE/PREPARED状态下调用。<br>用户只能设置一个URI回调函数，当用户重复设置时，以最后一次设置的回调函数为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_OnUri](capi-avrecorder-base-h.md#oh_avrecorder_onuri) callback | URI回调函数，用于接收系统创建的资源文件。需在录制配置中将FileGenerationMode设置为系统创建媒体文件模式，录制完成后才会触发此回调。必须为有效的函数指针，不能为nullptr。 |
| void *userData | 用户自定义数据指针，将在URI回调函数被触发时传递给回调函数，供应用层使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>        AV_ERR_INVALID_VAL：输入的recorder为nullptr或回调函数为nullptr。 |

### OH_AVRecorder_SetWillMuteWhenInterrupted()

```c
OH_AVErrCode OH_AVRecorder_SetWillMuteWhenInterrupted(OH_AVRecorder *recorder, bool muteWhenInterrupted)
```

**描述**

设置是否开启静音打断模式，用于控制音频流被打断时的处理行为。设置成true表示音频流被打断时录制静音，设置成false表示音频流被打断时停止录制，默认值为false。此接口必须在[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)接口之前调用。<br>需在IDLE状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| bool muteWhenInterrupted | 是否开启静音打断模式。true表示开启静音打断模式，音频流被打断时录制静音；false表示关闭静音打断模式，音频流被打断时停止录制，默认值为false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的recorder为nullptr。<br>AV_ERR_INVALID_STATE（8）：函数不支持在当前状态下调用，应当在准备状态之前调用。 |

### OH_AVRecorder_GetAudioCapturerMaxAmplitude()

```c
OH_AVErrCode OH_AVRecorder_GetAudioCapturerMaxAmplitude(OH_AVRecorder *recorder, int32_t *amplitude)
```

**描述**

获取当前音频最大振幅，典型使用场景包括：音频录制时实时显示音量级别、音频波形可视化、检测录制是否处于静音状态等。获取到的值为最近两次调用之间的最大振幅。例如，在1s时获取过一次最大振幅，然后在2s时再次调用该接口，那么返回值是1s到2s之间的最大振幅值。<br>需在PREPARED/STARTED/PAUSED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| int32_t *amplitude | 输出参数，用于返回获取到的音频最大振幅值，表示最近两次调用之间音频信号的最大振幅。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的参数recorder或amplitude为nullptr。<br>         AV_ERR_INVALID_STATE（8）：不支持在当前状态下调用，应当在OH_AVRecorder_Prepare之后和OH_AVRecorder_Stop之前调用此接口。<br>AV_ERR_NO_MEMORY（1）：内存不足，请释放资源后重试。<br>AV_ERR_UNKNOWN（6）：未知错误，请查看日志获取详细信息。 |

### OH_AVRecorder_SetMetadata()

```c
OH_AVErrCode OH_AVRecorder_SetMetadata(OH_AVRecorder *recorder, const OH_AVFormat *metadata)
```

**描述**

设置录制的元数据信息。典型使用场景包括：在录制的视频或音频文件中添加作者信息、版权信息、地理位置、录制时间等自定义元数据。如果metadata参数与config.metadata.customInfo（参考[OH_AVRecorder_Prepare](#oh_avrecorder_prepare)和[OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md)）中存在相同的键，前者的对应值将覆盖后者。<br>需在PREPARED/STARTED/PAUSED状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | 指向OH_AVRecorder实例的指针。 |
| const [OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md) *metadata | 设置的元数据信息。格式为字符串键值对，其中，键需要以"com.openharmony."开头，且值的长度不能超过256个字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK（0）：执行成功。<br>AV_ERR_INVALID_VAL（3）：输入的参数recorder或metadata为nullptr，或者metadata中的值长度超过256字节。<br>AV_ERR_INVALID_STATE（8）：不支持在当前状态下调用，应当在OH_AVRecorder_Prepare之后和OH_AVRecorder_Stop之前调用此接口。<br>AV_ERR_NO_MEMORY（1）：内存不足，请释放资源后重试。<br>AV_ERR_UNKNOWN（6）：未知错误，请查看日志获取详细信息。 |


