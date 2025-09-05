# OH_AVCodecAsyncCallback


## Overview

The struct defines all the asynchronous callback function pointers of an OH_AVCodec instance. To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Related module**: [CodecBase](_codec_base.md)

**Header file**: [native_avcodec_base.h](native__avcodec__base_8h.md)

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVCodecCallback](_o_h___a_v_codec_callback.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) [onError](#onerror) | Defines the callback used to report a codec operation error.| 
| [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) [onStreamChanged](#onstreamchanged) | Defines the callback used to report a codec stream change.| 
| [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) [onNeedInputData](#onneedinputdata) | Defines the callback used to report input data required.| 
| [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) [onNewOutputData](#onnewoutputdata) | Defines the callback used to report output data generated.| 


## Member Variable Description


### onError

**Description**

Defines the callback used to report a codec operation error.

**Since**: 9


### onNeedInputData

**Description**

Defines the callback used to report input data required.

**Since**: 9


### onNewOutputData

**Description**

Defines the callback used to report output data generated.

**Since**: 9


### onStreamChanged

**Description**

Defines the callback used to report a codec stream change.

**Since**: 9
