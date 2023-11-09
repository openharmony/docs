# AudioDecoder

## 概述

AudioDecoder模块提供用于音频解码的函数。该模块在部分设备上可能不支持，可以通过[CanIUse](../syscap.md)接口确认。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**起始版本：**

9

## 汇总

### 文件

| 名称                                                                 | 描述                                                                                                        |
| -------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| [native_avcodec_audiodecoder.h](native__avcodec__audiodecoder_8h.md)    | 声明用于音频解码的Native API。<br>**引用文件**：<multimedia/player_framework/native_avcodec_audiodecoder.h> <br>**库**：libnative_media_adec.so|
| [avcodec_audio_channel_layout.h](avcodec__audio__channel__layout_8h.md) | 声明用于音频编解码的枚举。<br>**引用文件**：<multimedia/player_framework/avcodec_audio_channel_layout.h> <br>**库**：libnative_media_codecbase.so                   |

### 枚举

| 名称                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | 描述                                                                  |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| [AudioChannelSet](#audiochannelset) : uint64_t {<br/>**FRONT_LEFT** = 1ULL &lt;&lt; 0U, <br/>**FRONT_RIGHT** = 1ULL &lt;&lt; 1U, <br/>**FRONT_CENTER** = 1ULL &lt;&lt; 2U, <br/>**LOW_FREQUENCY** = 1ULL &lt;&lt; 3U,<br/>**BACK_LEFT** = 1ULL &lt;&lt; 4U, <br/>**BACK_RIGHT** = 1ULL &lt;&lt; 5U, <br/>**FRONT_LEFT_OF_CENTER** = 1ULL &lt;&lt; 6U, <br/>**FRONT_RIGHT_OF_CENTER** = 1ULL &lt;&lt; 7U,<br/>**BACK_CENTER** = 1ULL &lt;&lt; 8U, <br/>**SIDE_LEFT** = 1ULL &lt;&lt; 9U, <br/>**SIDE_RIGHT** = 1ULL &lt;&lt; 10U, <br/>**TOP_CENTER** = 1ULL &lt;&lt; 11U,<br/>**TOP_FRONT_LEFT** = 1ULL &lt;&lt; 12U, <br/>**TOP_FRONT_CENTER** = 1ULL &lt;&lt; 13U, <br/>**TOP_FRONT_RIGHT** = 1ULL &lt;&lt; 14U, <br/>**TOP_BACK_LEFT** = 1ULL &lt;&lt; 15U,<br/>**TOP_BACK_CENTER** = 1ULL &lt;&lt; 16U, <br/>**TOP_BACK_RIGHT** = 1ULL &lt;&lt; 17U, <br/>**STEREO_LEFT** = 1ULL &lt;&lt; 29U, <br/>**STEREO_RIGHT** = 1ULL &lt;&lt; 30U,<br/>**WIDE_LEFT** = 1ULL &lt;&lt; 31U, <br/>**WIDE_RIGHT** = 1ULL &lt;&lt; 32U, <br/>**SURROUND_DIRECT_LEFT** = 1ULL &lt;&lt; 33U, <br/>**SURROUND_DIRECT_RIGHT** = 1ULL &lt;&lt; 34U,<br/>**LOW_FREQUENCY_2** = 1ULL &lt;&lt; 35U, <br/>**TOP_SIDE_LEFT** = 1ULL &lt;&lt; 36U, <br/>**TOP_SIDE_RIGHT** = 1ULL &lt;&lt; 37U, <br/>**BOTTOM_FRONT_CENTER** = 1ULL &lt;&lt; 38U,<br/>**BOTTOM_FRONT_LEFT** = 1ULL &lt;&lt; 39U, <br/>**BOTTOM_FRONT_RIGHT** = 1ULL &lt;&lt; 40U, <br/>**AMBISONICS_ACN0** = 1ULL &lt;&lt; 41U, <br/>**AMBISONICS_ACN1** = 1ULL &lt;&lt; 42U,<br/>**AMBISONICS_ACN2** = 1ULL &lt;&lt; 43U, <br/>**AMBISONICS_ACN3** = 1ULL &lt;&lt; 44U, <br/>**AMBISONICS_W** = AMBISONICS_ACN0, <br/>**AMBISONICS_Y** = AMBISONICS_ACN1,<br/>**AMBISONICS_Z** = AMBISONICS_ACN2, <br/>**AMBISONICS_X** = AMBISONICS_ACN3, <br/>**AMBISONICS_ACN4** = 1ULL &lt;&lt; 45U, <br/>**AMBISONICS_ACN5** = 1ULL &lt;&lt; 46U,<br/>**AMBISONICS_ACN6** = 1ULL &lt;&lt; 47U, <br/>**AMBISONICS_ACN7** = 1ULL &lt;&lt; 48U, <br/>**AMBISONICS_ACN8** = 1ULL &lt;&lt; 49U, <br/>**AMBISONICS_ACN9** = 1ULL &lt;&lt; 50U,<br/>**AMBISONICS_ACN10** = 1ULL &lt;&lt; 51U, <br/>**AMBISONICS_ACN11** = 1ULL &lt;&lt; 52U, <br/>**AMBISONICS_ACN12** = 1ULL &lt;&lt; 53U, <br/>**AMBISONICS_ACN13** = 1ULL &lt;&lt; 54U, <br/>**AMBISONICS_ACN14** = 1ULL &lt;&lt; 55U, <br/>**AMBISONICS_ACN15** = 1ULL &lt;&lt; 56U}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | 音频声道数集合， 将每一个声道数映射为int64的变量。                    |
| [OHOS::Media::AudioChannelLayout](_audio_decoder.md#audiochannellayout) : uint64_t {<br/>**UNKNOWN_CHANNEL_LAYOUT** = 0, <br/>**MONO** = (AudioChannelSet::FRONT_CENTER),<br/>**STEREO** = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT), <br/>**CH_2POINT1** = (STEREO \| AudioChannelSet::LOW_FREQUENCY),<br/>**CH_2_1** = (STEREO \| AudioChannelSet::BACK_CENTER), <br/>**SURROUND** = (STEREO \| AudioChannelSet::FRONT_CENTER), <br/>**CH_3POINT1** = (SURROUND \| AudioChannelSet::LOW_FREQUENCY), <br/>**CH_4POINT0** = (SURROUND \| AudioChannelSet::BACK_CENTER),<br/>**CH_4POINT1** = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY),<br/>**CH_2_2** = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT), <br/>**QUAD** = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT), <br/>**CH_5POINT0** = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br/>**CH_5POINT1** = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY), <br/>**CH_5POINT0_BACK** = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT), <br/>**CH_5POINT1_BACK** = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY), <br/>**CH_6POINT0** = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER),<br/>**CH_6POINT0_FRONT** = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| <br/>AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br/>**HEXAGONAL** = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER), <br/>**CH_6POINT1** = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER), <br/>**CH_6POINT1_BACK** = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER),<br/>**CH_6POINT1_FRONT** = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY),<br/>**CH_7POINT0** = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>**CH_7POINT0_FRONT** = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| <br/>AudioChannelSet::FRONT_RIGHT_OF_CENTER), <br/>**CH_7POINT1** = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br/>**CH_7POINT1_WIDE** = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| <br/>AudioChannelSet::FRONT_RIGHT_OF_CENTER),<br/> **CH_7POINT1_WIDE_BACK** = (CH_5POINT1_BACK \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER), <br/>**CH_3POINT1POINT2** = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| <br/>AudioChannelSet::TOP_FRONT_RIGHT), <br/>**CH_5POINT1POINT2** = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \|<br/> AudioChannelSet::TOP_SIDE_RIGHT),<br/>**CH_5POINT1POINT4** = (CH_5POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| <br/>AudioChannelSet::TOP_FRONT_RIGHT <br/>\| AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT), <br/>**CH_7POINT1POINT2** = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| <br/>AudioChannelSet::TOP_SIDE_RIGHT), <br/>**CH_7POINT1POINT4** = (CH_7POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| <br/>AudioChannelSet::TOP_FRONT_RIGHT<br/> \| AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT), <br/>**CH_9POINT1POINT4** = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| <br/>AudioChannelSet::WIDE_RIGHT),<br/>**CH_9POINT1POINT6** = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| <br/>AudioChannelSet::TOP_SIDE_RIGHT), <br/>**CH_10POINT2** = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT \| <br/>AudioChannelSet::FRONT_CENTER \| <br/>AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT \| AudioChannelSet::BACK_LEFT \| <br/>AudioChannelSet::BACK_RIGHT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::SIDE_LEFT \| <br/>AudioChannelSet::SIDE_RIGHT \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT), <br/>**CH_22POINT2** = (CH_7POINT1POINT4 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| <br/>AudioChannelSet::FRONT_RIGHT_OF_CENTER \| AudioChannelSet::BACK_CENTER \| <br/>AudioChannelSet::TOP_CENTER \| <br/>AudioChannelSet::TOP_FRONT_CENTER \|, AudioChannelSet::TOP_BACK_CENTER \| <br/>AudioChannelSet::TOP_SIDE_LEFT \| <br/>AudioChannelSet::TOP_SIDE_RIGHT \|AudioChannelSet::BOTTOM_FRONT_LEFT \| <br/>AudioChannelSet::BOTTOM_FRONT_RIGHT <br/>\|AudioChannelSet::BOTTOM_FRONT_CENTER \| AudioChannelSet::LOW_FREQUENCY_2),<br/>**OCTAGONAL** = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| <br/>AudioChannelSet::BACK_RIGHT),<br/>**HEXADECAGONAL** =  (OCTAGONAL \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT \| <br/>AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT \| <br/>AudioChannelSet::TOP_BACK_CENTER \| <br/>AudioChannelSet::TOP_FRONT_CENTER \| AudioChannelSet::TOP_FRONT_LEFT \| <br/>AudioChannelSet::TOP_FRONT_RIGHT), <br/>**STEREO_DOWNMIX** = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT), <br/>**HOA_FIRST** = AudioChannelSet::AMBISONICS_ACN0 \| AudioChannelSet::AMBISONICS_ACN1 \| <br/>AudioChannelSet::AMBISONICS_ACN2 \|AudioChannelSet::AMBISONICS_ACN3, <br/>**HOA_SECOND** = HOA_FIRST \| AudioChannelSet::AMBISONICS_ACN4 \| AudioChannelSet::AMBISONICS_ACN5 \| <br/>AudioChannelSet::AMBISONICS_ACN6 \| AudioChannelSet::AMBISONICS_ACN7 \| <br/>AudioChannelSet::AMBISONICS_ACN8,<br/>**HOA_THIRD** = HOA_SECOND \| AudioChannelSet::AMBISONICS_ACN9 \| <br/>AudioChannelSet::AMBISONICS_ACN10 \| <br/>AudioChannelSet::AMBISONICS_ACN11 \| AudioChannelSet::AMBISONICS_ACN12 \| <br/>AudioChannelSet::AMBISONICS_ACN13 \| AudioChannelSet::AMBISONICS_ACN14 <br/>\|AudioChannelSet::AMBISONICS_ACN15<br/>} | 音频声道数类型， 将用户申请的解码器输出格式表示为编解码器的声道类型。 |

### 函数

| 名称                                                                                                                                          | 描述                                                                                                 |
| --------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| \*[OH_AudioDecoder_CreateByMime](#oh_audiodecoder_createbymime) (const char \*mime)                                                 | 根据MIME类型创建音频解码器实例，大多数场景下建议使用此方式。                                         |
| \*[OH_AudioDecoder_CreateByName](#oh_audiodecoder_createbyname) (const char \*name)                                                 | 通过音频解码器名称创建音频解码器实例，使用此接口的前提是知道解码器的确切名称。                       |
| [OH_AudioDecoder_Destroy](#oh_audiodecoder_destroy) (OH_AVCodec \*codec)                                                            | 清理解码器内部资源，销毁解码器实例。                                                                 |
| [OH_AudioDecoder_SetCallback](#oh_audiodecoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，使您的应用程序可以响应音频解码器生成的事件。                                       |
| [OH_AudioDecoder_Configure](#oh_audiodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format)                                  | 要配置音频解码器，通常需要配置从容器中提取的音频描述信息。                                           |
| [OH_AudioDecoder_Prepare](#oh_audiodecoder_prepare) (OH_AVCodec \*codec)                                                            | 准备解码器的内部资源，在调用此接口之前必须调用Configure接口。                                        |
| [OH_AudioDecoder_Start](#oh_audiodecoder_start) (OH_AVCodec \*codec)                                                                | Prepare成功后调用此接口启动解码器。                                                                  |
| [OH_AudioDecoder_Stop](#oh_audiodecoder_stop) (OH_AVCodec \*codec)                                                                  | 停止解码器。                                                                                         |
| [OH_AudioDecoder_Flush](#oh_audiodecoder_flush) (OH_AVCodec \*codec)                                                                | 清除解码器中缓存的输入和输出数据。                                                                   |
| [OH_AudioDecoder_Reset](#oh_audiodecoder_reset) (OH_AVCodec \*codec)                                                                | 重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例 。                               |
| \*[OH_AudioDecoder_GetOutputDescription](#oh_audiodecoder_getoutputdescription) (OH_AVCodec \*codec)                                | 获取解码器输出数据的描述信息，详细信息请参见**OH_AVFormat**。                                  |
| [OH_AudioDecoder_SetParameter](#oh_audiodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format)                            | 配置解码器的动态参数。注意：该接口必须在解码器启动后才能调用。另外，参数配置错误可能会导致解码失败。 |
| [OH_AudioDecoder_PushInputData](#oh_audiodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr)     | 将填充有数据的输入缓冲区提交给音频解码器。                                                           |
| [OH_AudioDecoder_FreeOutputData](#oh_audiodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index)                              | 将处理后的输出缓冲区返回给解码器。                                                                   |
| [OH_AudioDecoder_IsValid](#oh_audiodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid)                                            | 检查当前解码器实例是否有效。                                                                         |

## 枚举类型说明

### AudioChannelLayout

```
enum AudioChannelLayout : uint64_t
```

**描述：**

音频声道数类型， 将用户申请的解码器输出格式表示为编解码器的声道类型。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10

### AudioChannelSet

```
enum AudioChannelSet : uint64_t
```

**描述：**

音频声道数集合， 将每一个声道数映射为int64的变量。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10

| 枚举值           | 描述                   |
| ---------------- | ---------------------- |
| AMBISONICS_ACN1  | 零阶立体声声道数 0     |
| AMBISONICS_ACN2  | 一阶立体声声道数 1     |
| AMBISONICS_ACN3  | 一阶立体声声道数 2     |
| AMBISONICS_W     | 一阶立体声声道数 3     |
| AMBISONICS_Y     | 同于零阶立体声声道数 0 |
| AMBISONICS_Z     | 同于一阶立体声声道数 1 |
| AMBISONICS_X     | 同于一阶立体声声道数 2 |
| AMBISONICS_ACN4  | 同于一阶立体声声道数 3 |
| AMBISONICS_ACN5  | 二阶立体声声道数 4     |
| AMBISONICS_ACN6  | 二阶立体声声道数 5     |
| AMBISONICS_ACN7  | 二阶立体声声道数 6     |
| AMBISONICS_ACN8  | 二阶立体声声道数 7     |
| AMBISONICS_ACN9  | 二阶立体声声道数 8     |
| AMBISONICS_ACN10 | 三阶立体声声道数 9     |
| AMBISONICS_ACN11 | 三阶立体声声道数 10    |
| AMBISONICS_ACN12 | 三阶立体声声道数 11    |
| AMBISONICS_ACN13 | 三阶立体声声道数 12    |
| AMBISONICS_ACN14 | 三阶立体声声道数 13    |
| AMBISONICS_ACN15 | 三阶立体声声道数 14    |

## 函数说明

### OH_AudioDecoder_Configure()

```
OH_AVErrCode OH_AudioDecoder_Configure (OH_AVCodec * codec, OH_AVFormat * format )
```

**描述：**

要配置音频解码器，通常需要配置从容器中提取的音频描述信息。

在调用Prepare之前，必须调用此接口。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称   | 描述                                                |
| ------ | --------------------------------------------------- |
| codec  | 指向OH_AVCodec实例的指针。                          |
| format | 指向OH_AVFormat的指针，给出要解码的音频轨道的描述。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_CreateByMime()

```
OH_AVCodec* OH_AudioDecoder_CreateByMime (const char * mime)
```

**描述：**

根据MIME类型创建音频解码器实例，大多数场景下建议使用此方式。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称 | 描述                                                    |
| ---- | ------------------------------------------------------- |
| mime | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 |

**返回：**

返回指向OH_AVCodec实例的指针。

**起始版本：**

9

### OH_AudioDecoder_CreateByName()

```
OH_AVCodec* OH_AudioDecoder_CreateByName (const char * name)
```

**描述：**

通过音频解码器名称创建音频解码器实例，使用此接口的前提是知道解码器的确切名称。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称 | 描述             |
| ---- | ---------------- |
| name | 音频解码器名称。 |

**返回：**

返回指向OH_AVCodec实例的指针。

**起始版本：**

9

### OH_AudioDecoder_Destroy()

```
OH_AVErrCode OH_AudioDecoder_Destroy (OH_AVCodec * codec)
```

**描述：**

清理解码器内部资源，销毁解码器实例。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_Flush()

```
OH_AVErrCode OH_AudioDecoder_Flush (OH_AVCodec * codec)
```

**描述：**

清除解码器中缓存的输入和输出数据。

调用此接口后，以前通过异步回调上报的所有缓冲区索引都将失效，请确保不要访问这些索引对应的缓冲区。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_FreeOutputData()

```
OH_AVErrCode OH_AudioDecoder_FreeOutputData (OH_AVCodec * codec, uint32_t index )
```

**描述：**

将处理后的输出缓冲区返回给解码器。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                           |
| ----- | ------------------------------ |
| codec | 指向OH_AVCodec实例的指针。     |
| index | 输出缓冲区Buffer对应的索引值。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_GetOutputDescription()

```
OH_AVFormat* OH_AudioDecoder_GetOutputDescription (OH_AVCodec * codec)
```

**描述：**

获取解码器输出数据的描述信息，详细信息请参见**OH_AVFormat**。 需要注意的是，返回值所指向的OH_AVFormat实例的生命周期需要调用者手动释放。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

返回OH_AVFormat句柄指针，生命周期将使用下一个GetOutputDescription 刷新，或使用OH_AVCodec销毁。

**起始版本：**

9

### OH_AudioDecoder_IsValid()

```
OH_AVErrCode OH_AudioDecoder_IsValid (OH_AVCodec * codec, bool * isValid )
```

**描述：**

检查当前解码器实例是否有效。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称    | 描述                                                              |
| ------- | ----------------------------------------------------------------- |
| codec   | 指向OH_AVCodec实例的指针。                                        |
| isValid | 指向布尔实例的指针，true：解码器实例有效，false：解码器实例无效。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10

### OH_AudioDecoder_Prepare()

```
OH_AVErrCode OH_AudioDecoder_Prepare (OH_AVCodec * codec)
```

**描述：**

准备解码器的内部资源，在调用此接口之前必须调用Configure接口。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_PushInputData()

```
OH_AVErrCode OH_AudioDecoder_PushInputData (OH_AVCodec * codec, uint32_t index, OH_AVCodecBufferAttr attr )
```

**描述：**

将填充有数据的输入缓冲区提交给音频解码器。

**OH_AVCodecOnNeedInputData**回调将报告可用的输入缓冲区和相应的索引值。一旦具有指定索引的缓冲区提交到音频解码器，则无法再次访问此缓冲区， 直到再次收到**OH_AVCodecOnNeedInputData**回调，收到相同索引时此缓冲区才可使用。 此外，对于某些解码器，需要在开始时向解码器输入特定配置参数，以初始化解码器的解码过程。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                           |
| ----- | ------------------------------ |
| codec | 指向OH_AVCodec实例的指针。     |
| index | 输入缓冲区Buffer对应的索引值。 |
| attr  | 描述缓冲区中包含的数据的信息。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_Reset()

```
OH_AVErrCode OH_AudioDecoder_Reset (OH_AVCodec * codec)
```

**描述：**

重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。。

**起始版本：**

9

### OH_AudioDecoder_SetCallback()

```
OH_AVErrCode OH_AudioDecoder_SetCallback (OH_AVCodec * codec, OH_AVCodecAsyncCallback callback, void * userData )
```

**描述：**

设置异步回调函数，使您的应用程序可以响应音频解码器生成的事件。

在调用Prepare之前，必须调用此接口。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称     | 描述                                                          |
| -------- | ------------------------------------------------------------- |
| codec    | 指向OH_AVCodec实例的指针。                                    |
| callback | 所有回调函数的集合，请参见**OH_AVCodecAsyncCallback**。 |
| userData | 用户特定数据。                                                |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_SetParameter()

```
OH_AVErrCode OH_AudioDecoder_SetParameter (OH_AVCodec * codec, OH_AVFormat * format )
```

**描述：**

配置解码器的动态参数。

注意，该接口必须在解码器启动后才能调用。另外，参数配置错误可能会导致解码失败。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称   | 描述                       |
| ------ | -------------------------- |
| codec  | 指向OH_AVCodec实例的指针。 |
| format | OH_AVFormat句柄指针。      |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_Start()

```
OH_AVErrCode OH_AudioDecoder_Start (OH_AVCodec * codec)
```

**描述：**

Prepare成功后调用此接口启动解码器。

启动后，解码器将开始上报OH_AVCodecOnNeedInputData事件。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9

### OH_AudioDecoder_Stop()

```
OH_AVErrCode OH_AudioDecoder_Stop (OH_AVCodec * codec)
```

**描述：**

停止解码器。

停止后，您可以通过Start重新进入已启动状态，但需要注意的是， 如果解码器之前已输入数据，则需要重新输入解码器数据。

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数：**

| 名称  | 描述                       |
| ----- | -------------------------- |
| codec | 指向OH_AVCodec实例的指针。 |

**返回：**

如果执行成功，则返回AV_ERR_OK，否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9
