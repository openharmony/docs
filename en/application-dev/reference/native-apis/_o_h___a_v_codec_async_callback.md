# OH_AVCodecAsyncCallback


## Overview

The **OH_AVCodecAsyncCallback** struct defines all the asynchronous callback function pointers of an **OH_AVCodec** instance. To ensure the normal running of **OH_AVCodec**, you must register the instance of this struct with the **OH_AVCodec** instance and process the information reported by the callback function.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

9

**Related Modules**

[CodecBase](_codec_base.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [onError](#onerror) | Defines the callback used to report a codec operation error. For details, see [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror).| 
| [onStreamChanged](#onstreamchanged) | Defines the callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged).| 
| [onNeedInputData](#onneedinputdata) | Defines the callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata).| 
| [onNeedOutputData](#onneedoutputdata) | Defines the callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata).| 


## Member Variable Description


### onError

  
```
OH_AVCodecOnError onError
```

**Description**

Defines the callback used to report a codec operation error. For details, see [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror).

**Since**

9


### onNeedInputData

  
```
OH_AVCodecOnNeedInputData onNeedInputData
```

**Description**

Defines the callback used to report input data required. For details, see [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata).

**Since**

9


### onNeedOutputData

  
```
OH_AVCodecOnNewOutputData onNeedOutputData
```

**Description**

Defines the callback used to report output data generated. For details, see [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata).

**Since**

9


### onStreamChanged

  
```
OH_AVCodecOnStreamChanged onStreamChanged
```

**Description**

Defines the callback used to report a codec stream change. For details, see [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged).

**Since**

9
