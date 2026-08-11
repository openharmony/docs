# native_audio_converter.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明输入音频格式、输出音频格式底层数据结构和格式转换接口。

**引用文件：** <ohaudiosuite/native_audio_converter.h>

**库：** libohaudiosuite.so

**系统能力：** SystemCapability.Multimedia.Audio.SuiteEngine

**起始版本：** 26.0.0

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md) | OH_AudioConverter_Format | 定义音频转换器的数据结构，用于描述音频格式。|
| [OH_AudioConverterStruct](capi-audioconverter-oh-audioconverterstruct.md) | OH_AudioConverter | 声明音频格式转换器。<br> 音频转换器的句柄用于执行与音频转换器相关的功能。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioConverter_Result](#oh_audioconverter_result) | OH_AudioConverter_Result | 定义函数执行的返回结果。 |
| [OH_AudioConverter_InputStatus](#oh_audioconverter_inputstatus) | OH_AudioConverter_InputStatus | 定义回调函数[OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback)提供的输入音频数据的状态。转换器使用此状态来确定如何处理后续的转换逻辑。例如，继续提取数据，暂停或清除缓存数据。<br> 注意：即使回调返回AUDIOCONVERTER_INPUT_DATA_FINISHED，也必须重复调用OH_AudioConverter_Process，直到[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)返回AUDIOCONVERTER_SUCCESS，并且outputSize=0（表示所有缓存数据均已处理完成）。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioConverter_Result OH_AudioConverter_Create(const OH_AudioConverter_Format* inputFormat, const OH_AudioConverter_Format* outputFormat, OH_AudioConverter** converter)](#oh_audioconverter_create) | - | 创建音频转换器。 |
| [void OH_AudioConverter_Destroy(OH_AudioConverter* converter)](#oh_audioconverter_destroy) | - | 请求释放转换器。 |
| [typedef int32_t (\*OH_AudioConverter_RequestDataCallback)(void* userData, const void** outInputData, OH_AudioConverter_InputStatus* outStatus)](#oh_audioconverter_requestdatacallback) | OH_AudioConverter_RequestDataCallback | 请求数据的回调函数。转换器在[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)期间调用此回调函数以主动请求输入音频数据。<br> 调用者必须填充输出参数（outInputData，outStatus），并返回通过回调函数读取的数据大小。<br> 单个回调返回的最大数据大小为400KB。<br> outInputData指向的内存必须保持有效，直到OH_AudioConverter_Process返回处理完成为止。 |
| [OH_AudioConverter_Result OH_AudioConverter_SetInputCallback(OH_AudioConverter* converter, OH_AudioConverter_RequestDataCallback callback, void* userData)](#oh_audioconverter_setinputcallback) | - | 设置转换器请求数据回调函数。此函数绑定音频转换器的输入数据回调函数。回调函数由[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)调用，获取输入音频数据并进行处理。 |
| [OH_AudioConverter_Result OH_AudioConverter_Process(OH_AudioConverter* converter, void* outputData, int32_t outputCapacity, int32_t* outputSize)](#oh_audioconverter_process) | - | 执行音频格式转换处理函数。该函数执行音频转换过程，将输入音频转换为目标格式，需要注意：该函数必须在[OH_AudioConverter_SetInputCallback](capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback)之后调用，并且最终转换结果写入的输出缓冲区必须由调用方分配和管理。 |

## 枚举类型说明

### OH_AudioConverter_Result

```c
enum OH_AudioConverter_Result
```

**描述**

定义函数执行的返回结果。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| AUDIOCONVERTER_SUCCESS = 0 |  函数调用成功。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_INVALID_PARAM = 1 |  函数输入参数无效。例如传入的格式转换器指针为nullptr。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_UNSUPPORTED_FORMAT = 2 |  不支持的音频格式。例如不支持的编码类型、采样格式等。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_SYSTEM = 3 |  系统错误。例如使用已销毁的格式转换器执行格式转换。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_MEMORY_ALLOC_FAILED = 4 |  内存分配失败。例如内部输出数据缓冲区内存分配失败。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_BUFFER_TOO_SMALL = 5 |  输出缓存容量不足。例如设置的存储输出数据的容量不足以存储一帧输出数据量。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_NOT_INITIALIZED = 6 |  音频转换器实例未初始化。例如未创建格式转换器直接执行格式转换处理函数。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_CALLBACK_INVALID = 7 |  输入回调函数无效。例如输入回调函数返回数据量小于0或大于最大值400KB。<br>**起始版本：** 26.0.0 |
| AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET = 8 |  未设置回调函数。例如输入回调函数指针为nullptr。<br>**起始版本：** 26.0.0 |

### OH_AudioConverter_InputStatus

```c
enum OH_AudioConverter_InputStatus
```

**描述**

定义回调函数[OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback)提供的输入音频数据的状态。转换器使用此状态来确定如何处理后续的转换逻辑。例如，继续提取数据，暂停或清除缓存数据。<br> 注意：即使回调返回AUDIOCONVERTER_INPUT_DATA_FINISHED，也必须重复调用OH_AudioConverter_Process，直到[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)返回AUDIOCONVERTER_SUCCESS，并且outputSize=0（表示所有缓存数据均已处理完成）。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| AUDIOCONVERTER_INPUT_HAVE_DATA = 1 | 提供的输入数据有效。 |
| AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA = 2 | 暂时没有可用的输入数据。 |
| AUDIOCONVERTER_INPUT_DATA_FINISHED = 3 | 输入数据流已完成。 |


## 函数说明

### OH_AudioConverter_Create()

```c
OH_AudioConverter_Result OH_AudioConverter_Create(const OH_AudioConverter_Format* inputFormat, const OH_AudioConverter_Format* outputFormat, OH_AudioConverter** converter)
```

**描述**

创建音频转换器。

> **说明：** 
>
> - 此函数创建的转换器实例必须通过[OH_AudioConverter_Destroy](capi-native-audio-converter-h.md#oh_audioconverter_destroy)的显式方式销毁。
> - 支持的音频格式规范（适用于输入/输出）：
> 该转换器仅支持PCM（脉冲编码调制）音频格式。
> - 支持采样率：8000 Hz、11025 Hz、12000 Hz、16000 Hz、22050 Hz、24000 Hz、32000 Hz、44100 Hz、48000 Hz、
> 64000 Hz、88200 Hz、96000 Hz、176400 Hz和192000 Hz。
> - 支持声道布局：CH_LAYOUT_MONO、CH_LAYOUT_STEREO、CH_LAYOUT_STEREO_DOWNMIX、
> CH_LAYOUT_2POINT1、CH_LAYOUT_3POINT0、CH_LAYOUT_SURROUND、CH_LAYOUT_3POINT1、CH_LAYOUT_4POINT0、CH_LAYOUT_QUAD_SIDE、
> CH_LAYOUT_QUAD、CH_LAYOUT_2POINT0POINT2、CH_LAYOUT_4POINT1、CH_LAYOUT_5POINT0、CH_LAYOUT_5POINT0_BACK、
> CH_LAYOUT_2POINT1POINT2、CH_LAYOUT_3POINT0POINT2、CH_LAYOUT_5POINT1、CH_LAYOUT_5POINT1_BACK、CH_LAYOUT_6POINT0、
> CH_LAYOUT_3POINT1POINT2、CH_LAYOUT_6POINT0_FRONT、CH_LAYOUT_HEXAGONAL、CH_LAYOUT_6POINT1、CH_LAYOUT_6POINT1_BACK、
> CH_LAYOUT_6POINT1_FRONT、CH_LAYOUT_7POINT0、CH_LAYOUT_7POINT0_FRONT、CH_LAYOUT_7POINT1、CH_LAYOUT_OCTAGONAL、
> CH_LAYOUT_5POINT1POINT2、CH_LAYOUT_7POINT1_WIDE和CH_LAYOUT_7POINT1_WIDE_BACK。
> - 支持采样格式（位深）：SAMPLE_U8 （Unsigned 8位 PCM）、
> SAMPLE_S16LE（Short 16位小端 PCM）、SAMPLE_S24LE（Short 24位小端 PCM）、
> SAMPLE_S32LE（Short 32位小端 PCM）和SAMPLE_F32LE（Float 32位小端 PCM）。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| --- | --- |
| const [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md)* inputFormat | 指向输入音频格式的指针。 |
| const [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md)* outputFormat | 指向输出音频格式的指针。 |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)** converter | 指向可用的音频转换器的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | AUDIOCONVERTER_SUCCESS：创建格式转换器成功，可以正常执行后续流程。<br>         AUDIOCONVERTER_ERROR_INVALID_PARAM：函数输入参数无效，需要检查传入的格式转换器指针是否非nullptr。<br>         AUDIOCONVERTER_ERROR_UNSUPPORTED_FORMAT：音频输入/输出格式组合不支持，输入或输出格式超出允许范围，需要检查配置的音频格式。<br>          AUDIOCONVERTER_ERROR_SYSTEM：系统错误，需要检查是否使用已销毁的格式转换器执行格式转换。 |

### OH_AudioConverter_Destroy()

```c
void OH_AudioConverter_Destroy(OH_AudioConverter* converter)
```

**描述**

请求释放转换器。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | 由[OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create)函数创建的转换器。 |

### OH_AudioConverter_RequestDataCallback()

```c
typedef int32_t (*OH_AudioConverter_RequestDataCallback)(void* userData, const void** outInputData, OH_AudioConverter_InputStatus* outStatus
)
```

**描述**

请求数据的回调函数。转换器在[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)期间调用此回调函数以主动请求输入音频数据。<br> 调用者必须填充输出参数（outInputData，outStatus），并返回通过回调函数读取的数据大小。<br> 单个回调返回的最大数据大小为400KB。<br> outInputData指向的内存必须保持有效，直到OH_AudioConverter_Process返回处理完成为止。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void\* userData | 传递给回调函数的用户自定义数据。 |
| const void\*\* outInputData | 指向回调函数设置的指向输入音频数据缓冲区的指针。 |
| [OH_AudioConverter_InputStatus](capi-native-audio-converter-h.md#oh_audioconverter_inputstatus)\* outStatus | 通过回调函数设置，用于通知转换器输入数据的状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 通过outInputData指针指向有效的输入数据的大小。 |

### OH_AudioConverter_SetInputCallback()

```c
OH_AudioConverter_Result OH_AudioConverter_SetInputCallback(OH_AudioConverter* converter, OH_AudioConverter_RequestDataCallback callback, void* userData
)
```

**描述**

设置转换器请求数据回调函数。此函数绑定音频转换器的输入数据回调函数。回调函数由[OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process)调用，获取输入音频数据并进行处理。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | 由[OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create)函数创建转换器。 |
| [OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback) callback | 回调函数用于写入音频数据。 |
| userData | 指向将传递给回调函数的应用程序数据结构的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | AUDIOCONVERTER_SUCCESS：设置输入回调函数成功，可以正常执行后续流程。<br>         AUDIOCONVERTER_ERROR_INVALID_PARAM：函数输入参数无效，需要检查传入的格式转换器指针是否非nullptr。<br>         AUDIOCONVERTER_ERROR_NOT_INITIALIZED：格式转换器未初始化，需要检查当前格式转换器是否有效。<br>         AUDIOCONVERTER_ERROR_CALLBACK_INVALID：回调函数无效，需要检查输入回调函数返回数据量是否在允许范围内。<br>         AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET：回调函数未设置，需要检查回调函数指针是否非空。<br>         AUDIOCONVERTER_ERROR_SYSTEM：系统错误，需要检查是否使用已销毁的格式转换器执行格式转换。 |

### OH_AudioConverter_Process()

```c
OH_AudioConverter_Result OH_AudioConverter_Process(OH_AudioConverter* converter, void* outputData, int32_t outputCapacity, int32_t* outputSize
)
```

**描述**

执行音频格式转换处理函数。该函数执行音频转换过程，将输入音频转换为目标格式，需要注意：该函数必须在[OH_AudioConverter_SetInputCallback](capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback)之后调用，并且最终转换结果写入的输出缓冲区必须由调用方分配和管理。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | 由[OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create)函数创建转换器。 |
| void* outputData | 指向调用者分配的输出缓冲区的指针。 |
| int32_t outputCapacity | 调用者指定的输出缓冲区大小。 |
| outputSize | 系统实际写入输出缓冲区数据的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | AUDIOCONVERTER_SUCCESS：PCM音频数据格式转换成功，可以正常执行后续流程。<br>         AUDIOCONVERTER_ERROR_INVALID_PARAM：函数输入参数无效，需要检查传入的格式转换器指针是否非nullptr。<br>         AUDIOCONVERTER_ERROR_NOT_INITIALIZED：格式转换器未初始化，需要检查当前格式转换器是否有效。<br>         AUDIOCONVERTER_ERROR_CALLBACK_INVALID：输入回调函数无效，需要检查输入回调函数返回数据量是否在允许范围内。<br>         AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET：回调函数未设置，需要检查回调函数是否已成功设置并且函数指针是否非空。<br>         AUDIOCONVERTER_ERROR_BUFFER_TOO_SMALL：输出缓冲区容量不足，需要检查设置的存储输出数据的缓冲区容量是否足够存放一帧输出数据。<br>          AUDIOCONVERTER_ERROR_SYSTEM：系统错误，需要检查是否使用已销毁的格式转换器执行格式转换。 |
