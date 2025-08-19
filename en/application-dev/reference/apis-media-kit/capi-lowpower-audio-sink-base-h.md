# lowpower_audio_sink_base.h

## Overview

The file declares the structs and enums of the LowPowerAudioSink.

**File to include**: <multimedia/player_framework/lowpower_audio_sink_base.h>

**Library**: liblowpower_avsink.so

**System capability**: SystemCapability.Multimedia.Media.LowPowerAVSink

**Since**: 20

**Related module**: [LowPowerAudioSink](capi-lowpoweraudiosink.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md) | OH_LowPowerAudioSink | Describes the declaration for the LowPowerAudioSink.|
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md) | OH_LowPowerAudioSinkCallback | Contains a set of callback function pointers for the LowPowerAudioSink.<br>To ensure the normal running of the LowPowerAudioSink, you must register the instance of this struct with the [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md) instance and process the information reported by the callback functions.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_LowPowerAudioSink_OnError)(OH_LowPowerAudioSink* sink,OH_AVErrCode errCode,const char* errorMsg,void* userData)](#oh_lowpoweraudiosink_onerror) | OH_LowPowerAudioSink_OnError | Called when an error occurs in the LowPowerAudioSink.|
| [typedef void (\*OH_LowPowerAudioSink_OnPositionUpdated)(OH_LowPowerAudioSink* sink,int64_t currentPosition,void* userData)](#oh_lowpoweraudiosink_onpositionupdated) | OH_LowPowerAudioSink_OnPositionUpdated | Called when the playback position is updated in the LowPowerAudioSink.|
| [typedef void (\*OH_LowPowerAudioSink_OnDataNeeded)(OH_LowPowerAudioSink* sink,OH_AVSamplesBuffer* samples,void* userData)](#oh_lowpoweraudiosink_ondataneeded) | OH_LowPowerAudioSink_OnDataNeeded | Called when the LowPowerAudioSink needs more data.|
| [typedef void (\*OH_LowPowerAudioSink_OnInterrupted)(OH_LowPowerAudioSink* sink,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint,void* userData)](#oh_lowpoweraudiosink_oninterrupted) | OH_LowPowerAudioSink_OnInterrupted | Called when the audio focus is interrupted in the LowPowerAudioSink.|
| [typedef void (\*OH_LowPowerAudioSink_OnDeviceChanged)(OH_LowPowerAudioSink* sink,OH_AudioStream_DeviceChangeReason reason,void* userData)](#oh_lowpoweraudiosink_ondevicechanged) | OH_LowPowerAudioSink_OnDeviceChanged | Called when the audio device changes in the LowPowerAudioSink.|
| [typedef void (\*OH_LowPowerAudioSink_OnEos)(OH_LowPowerAudioSink* sink, void* userData)](#oh_lowpoweraudiosink_oneos) | OH_LowPowerAudioSink_OnEos | Called when the playback is complete in the LowPowerAudioSink. This callback is included in [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md).|

## Function Description

### OH_LowPowerAudioSink_OnError()

```
typedef void (*OH_LowPowerAudioSink_OnError)(OH_LowPowerAudioSink* sink,OH_AVErrCode errCode,const char* errorMsg,void* userData)
```

**Description**

Called when an error occurs in the LowPowerAudioSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) errorCode | Error code reported when an error occurs.|
| const char* errorMsg | Pointer to an error message.|
| void* userData | Pointer to user-defined data.|

### OH_LowPowerAudioSink_OnPositionUpdated()

```
typedef void (*OH_LowPowerAudioSink_OnPositionUpdated)(OH_LowPowerAudioSink* sink,int64_t currentPosition,void* userData)
```

**Description**

Called when the playback position is updated in the LowPowerAudioSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| int64_t currentPosition | Current playback position.|
| void* userData | Pointer to user-defined data.|

### OH_LowPowerAudioSink_OnDataNeeded()

```
typedef void (*OH_LowPowerAudioSink_OnDataNeeded)(OH_LowPowerAudioSink* sink,OH_AVSamplesBuffer* samples,void* userData)
```

**Description**

Called when the LowPowerAudioSink needs more data.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* samples | Pointer to the AVSamplesBuffer instance to be written.|
| void* userData | Pointer to user-defined data.|

### OH_LowPowerAudioSink_OnInterrupted()

```
typedef void (*OH_LowPowerAudioSink_OnInterrupted)(OH_LowPowerAudioSink* sink,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint,void* userData)
```

**Description**

Called when the audio focus is interrupted in the LowPowerAudioSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AudioInterrupt_ForceType](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | Type of force that causes the audio interruption.|
| [OH_AudioInterrupt_Hint](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | Hint provided along with audio interruption.|
| void* userData | Pointer to user-defined data.|

### OH_LowPowerAudioSink_OnDeviceChanged()

```
typedef void (*OH_LowPowerAudioSink_OnDeviceChanged)(OH_LowPowerAudioSink* sink,OH_AudioStream_DeviceChangeReason reason,void* userData)
```

**Description**

Called when the audio device changes in the LowPowerAudioSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AudioStream_DeviceChangeReason](../apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_devicechangereason) reason | Reason for the output device changes.|
| void* userData | Pointer to user-defined data.|

### OH_LowPowerAudioSink_OnEos()

```
typedef void (*OH_LowPowerAudioSink_OnEos)(OH_LowPowerAudioSink* sink, void* userData)
```

**Description**

Called when the playback is complete in the LowPowerAudioSink. This callback is included in [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
|  void* userData | Pointer to user-defined data.|
