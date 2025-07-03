# lowpower_video_sink_base.h

## 概述

定义LowPowerVideoSink的结构体和枚举。

**引用文件：** <multimedia/player_framework/lowpower_video_sink_base.h>

**库：** liblowpower_avsink.so

**系统能力：** SystemCapability.Multimedia.Media.LowPowerAVSink

**起始版本：** 20

**相关模块：** [LowPowerVideoSink](capi-lowpowervideosink.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md) | OH_LowPowerVideoSink | LowPowerVideoSink声明。 |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md) | OH_LowPowerVideoSinkCallback | 包含了LowPowerVideoSink回调函数指针的集合。<br> 应用需注册此实例结构体到[OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)实例中，并对回调上报的信息进行处理，保证LowPowerVideoSink的正常运行。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_LowPowerVideoSink_OnDataNeeded)(OH_LowPowerVideoSink* sink,OH_AVSamplesBuffer* buffer,void *userData)](#oh_lowpowervideosink_ondataneeded) | OH_LowPowerVideoSink_OnDataNeeded | LowPowerVideoSink需要数据时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |
| [typedef void (\*OH_LowPowerVideoSink_OnError)(OH_LowPowerVideoSink* sink,OH_AVErrCode errCode,const char* errMsg,void* userData)](#oh_lowpowervideosink_onerror) | OH_LowPowerVideoSink_OnError | LowPowerVideoSink发生错误时调用该方法。 |
| [typedef void (\*OH_LowPowerVideoSink_OnTargetArrived)(OH_LowPowerVideoSink* sink,const int64_t targetPts,const bool isTimeout,void* userData)](#oh_lowpowervideosink_ontargetarrived) | OH_LowPowerVideoSink_OnTargetArrived | LowPowerVideoSink到达目标点时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |
| [typedef void (\*OH_LowPowerVideoSink_OnRenderStarted)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_onrenderstarted) | OH_LowPowerVideoSink_OnRenderStarted | LowPowerVideoSink开始渲染时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |
| [typedef void (\*OH_LowPowerVideoSink_OnStreamChanged)(OH_LowPowerVideoSink* sink, OH_AVFormat* format, void* userData)](#oh_lowpowervideosink_onstreamchanged) | OH_LowPowerVideoSink_OnStreamChanged | LowPowerVideoSink流切换调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |
| [typedef void (\*OH_LowPowerVideoSink_OnFirstFrameDecoded)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_onfirstframedecoded) | OH_LowPowerVideoSink_OnFirstFrameDecoded | LowPowerVideoSink第一帧解码成功时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |
| [typedef void (\*OH_LowPowerVideoSink_OnEos)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_oneos) | OH_LowPowerVideoSink_OnEos | LowPowerVideoSink播放完成时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。 |

## 函数说明

### OH_LowPowerVideoSink_OnDataNeeded()

```
typedef void (*OH_LowPowerVideoSink_OnDataNeeded)(OH_LowPowerVideoSink* sink,OH_AVSamplesBuffer* buffer,void *userData)
```

**描述**

LowPowerVideoSink需要数据时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* buffer | 指向OH_AVSamplesBuffer实例的指针。 |
| void *userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnError()

```
typedef void (*OH_LowPowerVideoSink_OnError)(OH_LowPowerVideoSink* sink,OH_AVErrCode errCode,const char* errMsg,void* userData)
```

**描述**

LowPowerVideoSink发生错误时调用该方法。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) errCode | 业务操作过程中发生错误时返回的错误码。 |
| const char* errMsg | 业务操作过程中发生错误时返回的错误描述信息。 |
| void* userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnTargetArrived()

```
typedef void (*OH_LowPowerVideoSink_OnTargetArrived)(OH_LowPowerVideoSink* sink,const int64_t targetPts,const bool isTimeout,void* userData)
```

**描述**

LowPowerVideoSink到达目标点时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const int64_t targetPts | 目标点的pts。 |
| const bool isTimeout | 如果等待目标点超时，则为false。 |
| void* userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnRenderStarted()

```
typedef void (*OH_LowPowerVideoSink_OnRenderStarted)(OH_LowPowerVideoSink* sink, void* userData)
```

**描述**

LowPowerVideoSink开始渲染时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
|  void* userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnStreamChanged()

```
typedef void (*OH_LowPowerVideoSink_OnStreamChanged)(OH_LowPowerVideoSink* sink, OH_AVFormat* format, void* userData)
```

**描述**

LowPowerVideoSink流切换调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | 包含变化的参数和对应的值。 |
|  void* userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnFirstFrameDecoded()

```
typedef void (*OH_LowPowerVideoSink_OnFirstFrameDecoded)(OH_LowPowerVideoSink* sink, void* userData)
```

**描述**

LowPowerVideoSink第一帧解码成功时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
|  void* userData | 用户执行回调所依赖的数据。 |

### OH_LowPowerVideoSink_OnEos()

```
typedef void (*OH_LowPowerVideoSink_OnEos)(OH_LowPowerVideoSink* sink, void* userData)
```

**描述**

LowPowerVideoSink播放完成时调用该方法，包含在[OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)中。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
|  void* userData | 用户执行回调所依赖的数据。 |


