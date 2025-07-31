# lowpower_video_sink_base.h

## Overview

The file declares the structs and enums of the LowPowerVideoSink.

**File to include**: <multimedia/player_framework/lowpower_video_sink_base.h>

**Library**: liblowpower_avsink.so

**System capability**: SystemCapability.Multimedia.Media.LowPowerAVSink

**Since**: 20

**Related module**: [LowPowerVideoSink](capi-lowpowervideosink.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md) | OH_LowPowerVideoSink | Describes the declaration for the LowPowerVideoSink.|
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md) | OH_LowPowerVideoSinkCallback | Contains a set of callback function pointers for the LowPowerVideoSink.<br>To ensure the normal running of the LowPowerVideoSink, you must register the instance of this struct with the [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md) instance and process the information reported by the callback functions.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_LowPowerVideoSink_OnDataNeeded)(OH_LowPowerVideoSink* sink,OH_AVSamplesBuffer* buffer,void *userData)](#oh_lowpowervideosink_ondataneeded) | OH_LowPowerVideoSink_OnDataNeeded | Called when the LowPowerVideoSink needs more data. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|
| [typedef void (\*OH_LowPowerVideoSink_OnError)(OH_LowPowerVideoSink* sink,OH_AVErrCode errCode,const char* errMsg,void* userData)](#oh_lowpowervideosink_onerror) | OH_LowPowerVideoSink_OnError | Called when an error occurs in the LowPowerVideoSink.|
| [typedef void (\*OH_LowPowerVideoSink_OnTargetArrived)(OH_LowPowerVideoSink* sink,const int64_t targetPts,const bool isTimeout,void* userData)](#oh_lowpowervideosink_ontargetarrived) | OH_LowPowerVideoSink_OnTargetArrived | Called when the LowPowerVideoSink reaches the target point. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|
| [typedef void (\*OH_LowPowerVideoSink_OnRenderStarted)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_onrenderstarted) | OH_LowPowerVideoSink_OnRenderStarted | Called when the LowPowerVideoSink starts rendering. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|
| [typedef void (\*OH_LowPowerVideoSink_OnStreamChanged)(OH_LowPowerVideoSink* sink, OH_AVFormat* format, void* userData)](#oh_lowpowervideosink_onstreamchanged) | OH_LowPowerVideoSink_OnStreamChanged | Called when the stream changes in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|
| [typedef void (\*OH_LowPowerVideoSink_OnFirstFrameDecoded)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_onfirstframedecoded) | OH_LowPowerVideoSink_OnFirstFrameDecoded | Called when the first frame is successfully decoded in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|
| [typedef void (\*OH_LowPowerVideoSink_OnEos)(OH_LowPowerVideoSink* sink, void* userData)](#oh_lowpowervideosink_oneos) | OH_LowPowerVideoSink_OnEos | Called when the playback is completed in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).|

## Function Description

### OH_LowPowerVideoSink_OnDataNeeded()

```
typedef void (*OH_LowPowerVideoSink_OnDataNeeded)(OH_LowPowerVideoSink* sink,OH_AVSamplesBuffer* buffer,void *userData)
```

**Description**

Called when the LowPowerVideoSink needs more data. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* buffer | Pointer to an OH_AVSamplesBuffer instance.|
| void *userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnError()

```
typedef void (*OH_LowPowerVideoSink_OnError)(OH_LowPowerVideoSink* sink,OH_AVErrCode errCode,const char* errMsg,void* userData)
```

**Description**

Called when an error occurs in the LowPowerVideoSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) errCode | Error code returned when an error occurs during service operations.|
| const char* errMsg | Pointer to the error message returned when an error occurs during service operations.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnTargetArrived()

```
typedef void (*OH_LowPowerVideoSink_OnTargetArrived)(OH_LowPowerVideoSink* sink,const int64_t targetPts,const bool isTimeout,void* userData)
```

**Description**

Called when the LowPowerVideoSink reaches the target point. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const int64_t targetPts | Presentation timestamp (PTS) of the target point.|
| const bool isTimeout | Whether the wait for the target point has timed out. If it has timed out, this value is **false**.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnRenderStarted()

```
typedef void (*OH_LowPowerVideoSink_OnRenderStarted)(OH_LowPowerVideoSink* sink, void* userData)
```

**Description**

Called when the LowPowerVideoSink starts rendering. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
|  void* userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnStreamChanged()

```
typedef void (*OH_LowPowerVideoSink_OnStreamChanged)(OH_LowPowerVideoSink* sink, OH_AVFormat* format, void* userData)
```

**Description**

Called when the stream changes in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to the changed parameters and their values.|
|  void* userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnFirstFrameDecoded()

```
typedef void (*OH_LowPowerVideoSink_OnFirstFrameDecoded)(OH_LowPowerVideoSink* sink, void* userData)
```

**Description**

Called when the first frame is successfully decoded in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
|  void* userData | Pointer to the data on which the caller depends when executing the callback.|

### OH_LowPowerVideoSink_OnEos()

```
typedef void (*OH_LowPowerVideoSink_OnEos)(OH_LowPowerVideoSink* sink, void* userData)
```

**Description**

Called when the playback is completed in the LowPowerVideoSink. This callback is included in [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
|  void* userData | Pointer to the data on which the caller depends when executing the callback.|
