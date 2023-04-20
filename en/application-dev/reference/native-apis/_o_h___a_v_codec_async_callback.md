# OH_AVCodecAsyncCallback


## Overview

Defines a collection of asynchronous callback functions for an **OH_AVCodec** instance. You must register this struct instance for an **OH_AVCodec** instance and process the information reported through these callbacks to ensure the normal running of the instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since:**
9

**Related Modules:**

[CodecBase](_codec_base.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| **onError** | Indicates the callback used to report errors occurred during the running of the instance. For details, see [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) | 
| **onStreamChanged** | Indicates the callback used to report stream information. For details, see [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) | 
| **onNeedInputData** | Indicates the callback used to report input data needed. For details, see [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) | 
| **onNeedOutputData** | Indicates the callback used to report output data needed. For details, see [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) | 
