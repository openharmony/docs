# avrecorder.h

## 概述

定义AVRecorder接口。应用可使用媒体 AVRecorder 提供的接口录制媒体数据。

**引用文件：** avrecorder.h

**库：** libavrecorder.so

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVRecorder *OH_AVRecorder_Create(void)](#oh_avrecorder_create) | 创建AVRecorder实例。调用成功之后进入AVRECORDER_IDLE状态。 |
| [OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)](#oh_avrecorder_prepare) | 配置AVRecorder参数，准备录制。必须在[OH_AVRecorder_Create](capi-avrecorder-h.md#oh_avrecorder_create)成功触发之后调用，调用成功之后进入AVRECORDER_PREPARED状态。若只录制音频，则无需配置视频相关参数；同理，若只录制视频，则无需配置音频相关参数。 |
| [OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)](#oh_avrecorder_getavrecorderconfig) | 获取当前的录制参数。此接口必须在录制准备完成后调用。传入的config 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 |
| [OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)](#oh_avrecorder_getinputsurface) | 获取输入Surface。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)之前调用。此Surface提供给调用者，调用者从此Surface中获取Surface Buffer，填入相应的视频数据。 |
| [OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)](#oh_avrecorder_updaterotation) | 更新视频旋转角度。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)之前调用。 |
| [OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)](#oh_avrecorder_start) | 开始录制。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后调用，调用成功之后进入AVRECORDER_STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)](#oh_avrecorder_pause) | 暂停录制。必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)成功触发之后，处于AVRECORDER_STARTED状态时调用，调用成功之后进入AVRECORDER_PAUSED状态。之后可以通过调用[OH_AVRecorder_Resume](capi-avrecorder-h.md#oh_avrecorder_resume)恢复录制，重新进入AVRECORDER_STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)](#oh_avrecorder_resume) | 恢复录制。必须在[OH_AVRecorder_Pause](capi-avrecorder-h.md#oh_avrecorder_pause)成功触发之后，处于PAUSED状态时调用，调用成功之后重新进入AVRECORDER_STARTED状态。 |
| [OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)](#oh_avrecorder_stop) | 停止录制。必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_STOPPED状态。纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](capi-avrecorder-h.md#oh_avrecorder_getinputsurface)接口才能重新录制。 |
| [OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)](#oh_avrecorder_reset) | 重置录制状态。必须在非AVRECORDER_RELEASED状态下调用，调用成功之后进入AVRECORDER_IDLE状态。纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](capi-avrecorder-h.md#oh_avrecorder_getinputsurface)接口才能重新录制。 |
| [OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)](#oh_avrecorder_release) | 释放录制资源。调用成功之后进入AVRECORDER_RELEASED状态。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。释放音视频录制资源之后，该 OH_AVRecorder 实例不能再进行任何操作。 |
| [OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info,int32_t *length)](#oh_avrecorder_getavailableencoder) | 获取 AVRecorder 可用的编码器和编码器信息。参数info 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。 |
| [OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)](#oh_avrecorder_setstatecallback) | 设置状态回调函数，使应用能够响应AVRecorder生成的状态变化事件。此接口必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)调用之前调用。 |
| [OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)](#oh_avrecorder_seterrorcallback) | 设置错误回调函数，使应用能够响应AVRecorder生成的错误事件。此接口必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)调用之前调用。 |
| [OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)](#oh_avrecorder_seturicallback) | 设置 URI 回调函数，使应用能够响应AVRecorder生成的 URI 事件。此接口必须在 [OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start) 调用之前调用。 |

## 函数说明

### OH_AVRecorder_Create()

```
OH_AVRecorder *OH_AVRecorder_Create(void)
```

**描述**

创建AVRecorder实例。调用成功之后进入AVRECORDER_IDLE状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) | 成功时返回指向 OH_AVRecorder 实例的指针，失败时返回 nullptr。 |

### OH_AVRecorder_Prepare()

```
OH_AVErrCode OH_AVRecorder_Prepare(OH_AVRecorder *recorder, OH_AVRecorder_Config *config)
```

**描述**

配置AVRecorder参数，准备录制。必须在[OH_AVRecorder_Create](capi-avrecorder-h.md#oh_avrecorder_create)成功触发之后调用，调用成功之后进入AVRECORDER_PREPARED状态。若只录制音频，则无需配置视频相关参数；同理，若只录制视频，则无需配置音频相关参数。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| [OH_AVRecorder_Config](capi-oh-avrecorder-config.md) *config | 指向 OH_AVRecorder_Config 实例的指针，见 [OH_AVRecorder_Config](capi-oh-avrecorder-config.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或者准备失败。 |

### OH_AVRecorder_GetAVRecorderConfig()

```
OH_AVErrCode OH_AVRecorder_GetAVRecorderConfig(OH_AVRecorder *recorder, OH_AVRecorder_Config **config)
```

**描述**

获取当前的录制参数。此接口必须在录制准备完成后调用。传入的config 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| [OH_AVRecorder_Config](capi-oh-avrecorder-config.md) **config | 指向 OH_AVRecorder_Config 实例的指针，见 [OH_AVRecorder_Config](capi-oh-avrecorder-config.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或 config 不为 nullptr；<br>         [AV_ERR_NO_MEMORY](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 内存不足，config 内存分配失败。 |

### OH_AVRecorder_GetInputSurface()

```
OH_AVErrCode OH_AVRecorder_GetInputSurface(OH_AVRecorder *recorder, OHNativeWindow **window)
```

**描述**

获取输入Surface。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)之前调用。此Surface提供给调用者，调用者从此Surface中获取Surface Buffer，填入相应的视频数据。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| [OHNativeWindow](../ArkGraphics2D/capi-nativewindow.md) **window | 指向 OHNativeWindow 实例的指针，见 {@link OHNativeWindow}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr。 |

### OH_AVRecorder_UpdateRotation()

```
OH_AVErrCode OH_AVRecorder_UpdateRotation(OH_AVRecorder *recorder, int32_t rotation)
```

**描述**

更新视频旋转角度。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后，[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| int32_t rotation | 视频旋转角度，必须是整数 [0, 90, 180, 270] 中的一个。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或输入的 rotation 不符合要求或更新方向失败。 |

### OH_AVRecorder_Start()

```
OH_AVErrCode OH_AVRecorder_Start(OH_AVRecorder *recorder)
```

**描述**

开始录制。必须在[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)成功触发之后调用，调用成功之后进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或启动失败。 |

### OH_AVRecorder_Pause()

```
OH_AVErrCode OH_AVRecorder_Pause(OH_AVRecorder *recorder)
```

**描述**

暂停录制。必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)成功触发之后，处于AVRECORDER_STARTED状态时调用，调用成功之后进入AVRECORDER_PAUSED状态。之后可以通过调用[OH_AVRecorder_Resume](capi-avrecorder-h.md#oh_avrecorder_resume)恢复录制，重新进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或暂停失败。 |

### OH_AVRecorder_Resume()

```
OH_AVErrCode OH_AVRecorder_Resume(OH_AVRecorder *recorder)
```

**描述**

恢复录制。必须在[OH_AVRecorder_Pause](capi-avrecorder-h.md#oh_avrecorder_pause)成功触发之后，处于PAUSED状态时调用，调用成功之后重新进入AVRECORDER_STARTED状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或恢复失败。 |

### OH_AVRecorder_Stop()

```
OH_AVErrCode OH_AVRecorder_Stop(OH_AVRecorder *recorder)
```

**描述**

停止录制。必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)成功触发之后调用，调用成功之后进入AVRECORDER_STOPPED状态。纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](capi-avrecorder-h.md#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或停止失败。 |

### OH_AVRecorder_Reset()

```
OH_AVErrCode OH_AVRecorder_Reset(OH_AVRecorder *recorder)
```

**描述**

重置录制状态。必须在非AVRECORDER_RELEASED状态下调用，调用成功之后进入AVRECORDER_IDLE状态。纯音频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口才能重新录制。纯视频录制、音视频录制时，需要重新调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)和[OH_AVRecorder_GetInputSurface](capi-avrecorder-h.md#oh_avrecorder_getinputsurface)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或重置失败。 |

### OH_AVRecorder_Release()

```
OH_AVErrCode OH_AVRecorder_Release(OH_AVRecorder *recorder)
```

**描述**

释放录制资源。调用成功之后进入AVRECORDER_RELEASED状态。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。调用此接口释放录制资源后，recorder 内存将释放，应用层需要显式地将 recorder 指针置空，避免访问野指针。释放音视频录制资源之后，该 OH_AVRecorder 实例不能再进行任何操作。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或释放失败。 |

### OH_AVRecorder_GetAvailableEncoder()

```
OH_AVErrCode OH_AVRecorder_GetAvailableEncoder(OH_AVRecorder *recorder, OH_AVRecorder_EncoderInfo **info,int32_t *length)
```

**描述**

获取 AVRecorder 可用的编码器和编码器信息。参数info 必须为 nullptr，由框架层统一分配和释放内存，以避免内存管理混乱，防止内存泄漏或重复释放等问题。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| [OH_AVRecorder_EncoderInfo](capi-oh-avrecorder-encoderinfo.md) **info | 指向 OH_AVRecorder_EncoderInfo 实例的指针，见 [OH_AVRecorder_EncoderInfo](capi-oh-avrecorder-encoderinfo.md)。 |
| int32_t *length | 可用编码器的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr；<br>         [AV_ERR_NO_MEMORY](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 内存不足，info 内存分配失败。 |

### OH_AVRecorder_SetStateCallback()

```
OH_AVErrCode OH_AVRecorder_SetStateCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnStateChange callback, void *userData)
```

**描述**

设置状态回调函数，使应用能够响应AVRecorder生成的状态变化事件。此接口必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| OH_AVRecorder_OnStateChange callback | 状态回调函数，见 [OH_AVRecorder_OnStateChange](capi-avrecorder-base-h.md#oh_avrecorder_onstatechange)。 |
| void *userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或回调函数为 nullptr。 |

### OH_AVRecorder_SetErrorCallback()

```
OH_AVErrCode OH_AVRecorder_SetErrorCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnError callback, void *userData)
```

**描述**

设置错误回调函数，使应用能够响应AVRecorder生成的错误事件。此接口必须在[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| OH_AVRecorder_OnError callback | 错误回调函数，见 [OH_AVRecorder_OnError](capi-avrecorder-base-h.md#oh_avrecorder_onerror)。 |
| void *userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或回调函数为 nullptr。 |

### OH_AVRecorder_SetUriCallback()

```
OH_AVErrCode OH_AVRecorder_SetUriCallback(OH_AVRecorder *recorder, OH_AVRecorder_OnUri callback, void *userData)
```

**描述**

设置 URI 回调函数，使应用能够响应AVRecorder生成的 URI 事件。此接口必须在 [OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start) 调用之前调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-oh-avrecorder.md) *recorder | 指向 OH_AVRecorder 实例的指针。 |
| OH_AVRecorder_OnUri callback | URI 回调函数，见 [OH_AVRecorder_OnUri](capi-avrecorder-base-h.md#oh_avrecorder_onuri)。 |
| void *userData | 指向用户特定数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功；<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的 recorder 为 nullptr 或回调函数为 nullptr。 |


