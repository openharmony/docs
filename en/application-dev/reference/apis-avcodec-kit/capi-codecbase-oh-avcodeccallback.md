# OH_AVCodecCallback

## Overview

The struct defines all the asynchronous callback function pointers of an OH_AVCodec instance. To ensure the normal running of OH_AVCodec, you must register the instance of this struct with the OH_AVCodec instance and process the information reported by the callback function.

For details about the development guide, see step 4 in surface mode or step 3 in buffer mode in [Video Encoding](../../media/avcodec/video-encoding.md).

**Since**: 11

**Related module**: [CodecBase](capi-codecbase.md)

**Header file**: [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_AVCodecOnError](capi-native-avcodec-base-h.md#oh_avcodeconerror) onError | Callback used to report a codec operation error.|
| [OH_AVCodecOnStreamChanged](capi-native-avcodec-base-h.md#oh_avcodeconstreamchanged) onStreamChanged | Callback used to report a codec stream change.|
| [OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer) onNeedInputBuffer| Callback used to report input data required.|
| [OH_AVCodecOnNewOutputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputbuffer) onNewOutputBuffer | Callback used to report output data generated.|
