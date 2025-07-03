# lowpower_avsink_base.h

## 概述

定义OH_LowPowerAudioSink和OH_LowPowerVideoSink的基础依赖。

**引用文件：** <multimedia/player_framework/lowpower_avsink_base.h>

**库：** liblowpower_avsink.so

**系统能力：** SystemCapability.Multimedia.Media.LowPowerAVSink

**起始版本：** 20

**相关模块：** [AVSinkBase](capi-avsinkbase.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) | OH_AVSamplesBuffer | LowPowerAVSink输入数据的结构体。应用在收到DataNeeded回调后需要将数据打包装进OH_AVSamplesBuffer实例中送给对应的lowpower_avsink。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVErrCode OH_AVSamplesBuffer_AppendOneBuffer(OH_AVSamplesBuffer *samplesBuffer, OH_AVBuffer *avBuffer)](#oh_avsamplesbuffer_appendonebuffer) | 将一个OH_AVBuffer中的数据添加到OH_AVSamplesBuffer实例中。 |
| [int32_t OH_AVSamplesBuffer_GetRemainedCapacity(OH_AVSamplesBuffer *samplesBuffer)](#oh_avsamplesbuffer_getremainedcapacity) | 获取OH_AVSamplesBuffer实例的剩余可使用容量。 |

## 函数说明

### OH_AVSamplesBuffer_AppendOneBuffer()

```
OH_AVErrCode OH_AVSamplesBuffer_AppendOneBuffer(OH_AVSamplesBuffer *samplesBuffer, OH_AVBuffer *avBuffer)
```

**描述**

将一个OH_AVBuffer中的数据添加到OH_AVSamplesBuffer实例中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) *samplesBuffer | 指向OH_AVSamplesBuffer实例的指针。 |
| [OH_AVBuffer](../apis-avcodec-kit/_core.md#oh_avbuffer) *avBuffer | 指向OH_AVBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_NO_MEMORY：framePacketBuffer没有足够的剩余容量来追加一个OH_AVBuffer。<br> AV_ERR_UNKNOW：未知错误。 |

### OH_AVSamplesBuffer_GetRemainedCapacity()

```
int32_t OH_AVSamplesBuffer_GetRemainedCapacity(OH_AVSamplesBuffer *samplesBuffer)
```

**描述**

获取OH_AVSamplesBuffer实例的剩余可使用容量。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) *samplesBuffer | 指向OH_AVSamplesBuffer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | OH_AVSamplesBuffer实例剩余可使用容量，单位为字节。如果sampleBuffer或data poniter为nullptr或无效，则返回-1。 |


