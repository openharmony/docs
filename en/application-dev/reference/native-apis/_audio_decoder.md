# AudioDecoder

## Overview

The **AudioDecoder** module provides the functions for audio decoding. This module may not be supported on some devices. You can call [CanIUse](../syscap.md) to check whether your device supports this module.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Since**

9

## Summary

### Files

| Name                                                                | Description                                                                                                       |
| -------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| [native_avcodec_audiodecoder.h](native__avcodec__audiodecoder_8h.md)    | Declares the native APIs used for audio decoding.<br>**File to include**: <multimedia/player_framework/native_avcodec_audiodecoder.h><br>**Library**: libnative_media_adec.so|
| [avcodec_audio_channel_layout.h](avcodec__audio__channel__layout_8h.md) | Declares the enums used for audio codec.<br>**File to include**: <multimedia/player_framework/avcodec_audio_channel_layout.h><br>**Library**: libnative_media_codecbase.so                  |

### Enums

| Name                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Description                                                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| [AudioChannelSet](#audiochannelset) : uint64_t {<br>**FRONT_LEFT** = 1ULL &lt;&lt; 0U, <br>**FRONT_RIGHT** = 1ULL &lt;&lt; 1U, <br>**FRONT_CENTER** = 1ULL &lt;&lt; 2U, <br>**LOW_FREQUENCY** = 1ULL &lt;&lt; 3U,<br>**BACK_LEFT** = 1ULL &lt;&lt; 4U, <br>**BACK_RIGHT** = 1ULL &lt;&lt; 5U, <br>**FRONT_LEFT_OF_CENTER** = 1ULL &lt;&lt; 6U, <br>**FRONT_RIGHT_OF_CENTER** = 1ULL &lt;&lt; 7U,<br>**BACK_CENTER** = 1ULL &lt;&lt; 8U, <br>**SIDE_LEFT** = 1ULL &lt;&lt; 9U, <br>**SIDE_RIGHT** = 1ULL &lt;&lt; 10U, <br>**TOP_CENTER** = 1ULL &lt;&lt; 11U,<br>**TOP_FRONT_LEFT** = 1ULL &lt;&lt; 12U, <br>**TOP_FRONT_CENTER** = 1ULL &lt;&lt; 13U, <br>**TOP_FRONT_RIGHT** = 1ULL &lt;&lt; 14U, <br>**TOP_BACK_LEFT** = 1ULL &lt;&lt; 15U,<br>**TOP_BACK_CENTER** = 1ULL &lt;&lt; 16U, <br>**TOP_BACK_RIGHT** = 1ULL &lt;&lt; 17U, <br>**STEREO_LEFT** = 1ULL &lt;&lt; 29U, <br>**STEREO_RIGHT** = 1ULL &lt;&lt; 30U,<br>**WIDE_LEFT** = 1ULL &lt;&lt; 31U, <br>**WIDE_RIGHT** = 1ULL &lt;&lt; 32U, <br>**SURROUND_DIRECT_LEFT** = 1ULL &lt;&lt; 33U, <br>**SURROUND_DIRECT_RIGHT** = 1ULL &lt;&lt; 34U,<br>**LOW_FREQUENCY_2** = 1ULL &lt;&lt; 35U, <br>**TOP_SIDE_LEFT** = 1ULL &lt;&lt; 36U, <br>**TOP_SIDE_RIGHT** = 1ULL &lt;&lt; 37U, <br>**BOTTOM_FRONT_CENTER** = 1ULL &lt;&lt; 38U,<br>**BOTTOM_FRONT_LEFT** = 1ULL &lt;&lt; 39U, <br>**BOTTOM_FRONT_RIGHT** = 1ULL &lt;&lt; 40U, <br>**AMBISONICS_ACN0** = 1ULL &lt;&lt; 41U, <br>**AMBISONICS_ACN1** = 1ULL &lt;&lt; 42U,<br>**AMBISONICS_ACN2** = 1ULL &lt;&lt; 43U, <br>**AMBISONICS_ACN3** = 1ULL &lt;&lt; 44U, <br>**AMBISONICS_W** = AMBISONICS_ACN0, <br>**AMBISONICS_Y** = AMBISONICS_ACN1,<br>**AMBISONICS_Z** = AMBISONICS_ACN2, <br>**AMBISONICS_X** = AMBISONICS_ACN3, <br>**AMBISONICS_ACN4** = 1ULL &lt;&lt; 45U, <br>**AMBISONICS_ACN5** = 1ULL &lt;&lt; 46U,<br>**AMBISONICS_ACN6** = 1ULL &lt;&lt; 47U, <br>**AMBISONICS_ACN7** = 1ULL &lt;&lt; 48U, <br>**AMBISONICS_ACN8** = 1ULL &lt;&lt; 49U, <br>**AMBISONICS_ACN9** = 1ULL &lt;&lt; 50U,<br>**AMBISONICS_ACN10** = 1ULL &lt;&lt; 51U, <br>**AMBISONICS_ACN11** = 1ULL &lt;&lt; 52U, <br>**AMBISONICS_ACN12** = 1ULL &lt;&lt; 53U, <br>**AMBISONICS_ACN13** = 1ULL &lt;&lt; 54U, <br>**AMBISONICS_ACN14** = 1ULL &lt;&lt; 55U, <br>**AMBISONICS_ACN15** = 1ULL &lt;&lt; 56U}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | Enumerates the audio channel numbers. Each channel number is mapped to a variable of int64.                   |
| [AudioChannelLayout](#audiochannellayout) : uint64_t {<br>**UNKNOWN_CHANNEL_LAYOUT** = 0, <br>**MONO** = (AudioChannelSet::FRONT_CENTER), <br>**STEREO** = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT), <br>**CH_2POINT1** = (STEREO \| AudioChannelSet::LOW_FREQUENCY),<br>**CH_2_1** = (STEREO \| AudioChannelSet::BACK_CENTER), <br>**SURROUND** = (STEREO \| AudioChannelSet::FRONT_CENTER), <br>**CH_3POINT1** = (SURROUND \| AudioChannelSet::LOW_FREQUENCY), <br>**CH_4POINT0** = (SURROUND \| AudioChannelSet::BACK_CENTER),<br>**CH_4POINT1** = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY), <br>**CH_2_2** = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT), <br>**QUAD** = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT), <br>**CH_5POINT0** = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT),<br>**CH_5POINT1** = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY), <br>**CH_5POINT0_BACK** = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT), <br>**CH_5POINT1_BACK** = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY), <br>**CH_6POINT0** = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER),<br>**CH_6POINT0_FRONT** = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER), <br>**HEXAGONAL** = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER), <br>**CH_6POINT1** = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER), <br>**CH_6POINT1_BACK** = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER),<br>**CH_6POINT1_FRONT** = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY), <br>**CH_7POINT0** = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT), <br>**CH_7POINT0_FRONT** = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER), <br>**CH_7POINT1** = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT),<br>**CH_7POINT1_WIDE** = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER), <br>**CH_7POINT1_WIDE_BACK**, <br>**CH_3POINT1POINT2** = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT), <br>**CH_5POINT1POINT2** = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT),<br>**CH_5POINT1POINT4**, <br>**CH_7POINT1POINT2** = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT), <br>**CH_7POINT1POINT4**, <br>**CH_9POINT1POINT4** = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT),<br>**CH_9POINT1POINT6** = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT), <br>**CH_10POINT2**, <br>**CH_22POINT2**, <br>**OCTAGONAL** = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::BACK_RIGHT),<br>**HEXADECAGONAL**, <br>**STEREO_DOWNMIX** = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT), <br>**HOA_FIRST**, <br>**HOA_SECOND** <br>**HOA_THIRD**} | Enumerates the types of the audio channel numbers. The output format of the decoder is represented as the channel type of the codec.|

### Functions

| Name                                                                                                                                         | Description                                                                                                |
| --------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| \*[OH_AudioDecoder_CreateByMime](#oh_audiodecoder_createbymime) (const char \*mime)                                                 | Creates an audio decoder instance based on a Multipurpose Internet Mail Extension (MIME) type. This function is recommended in most cases.                                        |
| \*[OH_AudioDecoder_CreateByName](#oh_audiodecoder_createbyname) (const char \*name)                                                 | Creates an audio decoder instance based on a decoder name. To use this function, you must know the exact name of the decoder.                      |
| [OH_AudioDecoder_Destroy](#oh_audiodecoder_destroy) (OH_AVCodec \*codec)                                                            | Clears the internal resources of an audio decoder and destroys the decoder instance.                                                                |
| [OH_AudioDecoder_SetCallback](#oh_audiodecoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | Sets an asynchronous callback so that your application can respond to events generated by an audio decoder.                                      |
| [OH_AudioDecoder_Configure](#oh_audiodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format)                                  | Configures an audio decoder. Typically, you need to configure the audio description information that can be extracted from the container.                                          |
| [OH_AudioDecoder_Prepare](#oh_audiodecoder_prepare) (OH_AVCodec \*codec)                                                            | Prepares internal resources for an audio decoder. This function must be called after **Configure**.                                       |
| [OH_AudioDecoder_Start](#oh_audiodecoder_start) (OH_AVCodec \*codec)                                                                | Starts an audio decoder. This function can be called only after the decoder is prepared successfully.                                                                 |
| [OH_AudioDecoder_Stop](#oh_audiodecoder_stop) (OH_AVCodec \*codec)                                                                  | Stops an audio decoder.                                                                                        |
| [OH_AudioDecoder_Flush](#oh_audiodecoder_flush) (OH_AVCodec \*codec)                                                                | Clears the input and output data in the internal buffer of an audio decoder.                                                                  |
| [OH_AudioDecoder_Reset](#oh_audiodecoder_reset) (OH_AVCodec \*codec)                                                                | Resets an audio decoder. To continue decoding, you must call **Configure** to configure the decoder again.                              |
| \*[OH_AudioDecoder_GetOutputDescription](#oh_audiodecoder_getoutputdescription) (OH_AVCodec \*codec)                                | Obtains the description information about the output data of an audio decoder. For details, see **OH_AVFormat**.                                 |
| [OH_AudioDecoder_SetParameter](#oh_audiodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format)                            | Sets dynamic parameters for an audio decoder. This function can be called only after the decoder is started. Incorrect parameter settings may cause decoding failure.|
| [OH_AudioDecoder_PushInputData](#oh_audiodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr)     | Pushes the input buffer filled with data to an audio decoder.                                                          |
| [OH_AudioDecoder_FreeOutputData](#oh_audiodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index)                              | Frees an output buffer of an audio decoder.                                                                  |
| [OH_AudioDecoder_IsValid](#oh_audiodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid)                                            | Checks whether an audio decoder instance is valid.                                                                        |

## Enum Description

### AudioChannelLayout

```
enum AudioChannelLayout : uint64_t
```

**Description**

Enumerates the types of the audio channel numbers. The output format of the decoder is represented as the channel type of the codec.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10

### AudioChannelSet

```
enum AudioChannelSet : uint64_t
```

**Description**

Enumerates the audio channel numbers. Each channel number is mapped to a variable of int64.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

10

| Value          | Description                  |
| ---------------- | ---------------------- |
| AMBISONICS_ACN1  | Channel 0 for the zero-order stereo.    |
| AMBISONICS_ACN2  | Channel 1 for the first-order stereo.    |
| AMBISONICS_ACN3  | Channel 2 for the first-order stereo.    |
| AMBISONICS_W     | Channel 3 for the first-order stereo.    |
| AMBISONICS_Y     | Equivalent to channel 0 for the zero-order stereo.|
| AMBISONICS_Z     | Equivalent to channel 1 for the first-order stereo.|
| AMBISONICS_X     | Equivalent to channel 2 for the first-order stereo.|
| AMBISONICS_ACN4  | Equivalent to channel 3 for the first-order stereo.|
| AMBISONICS_ACN5  | Channel 4 for the second-order stereo.    |
| AMBISONICS_ACN6  | Channel 5 for the second-order stereo.    |
| AMBISONICS_ACN7  | Channel 6 for the second-order stereo.    |
| AMBISONICS_ACN8  | Channel 7 for the second-order stereo.    |
| AMBISONICS_ACN9  | Channel 8 for the second-order stereo.    |
| AMBISONICS_ACN10 | Channel 9 for the third-order stereo.    |
| AMBISONICS_ACN11 | Channel 10 for the third-order stereo.   |
| AMBISONICS_ACN12 | Channel 11 for the third-order stereo.   |
| AMBISONICS_ACN13 | Channel 12 for the third-order stereo.   |
| AMBISONICS_ACN14 | Channel 13 for the third-order stereo.   |
| AMBISONICS_ACN15 | Channel 14 for the third-order stereo.   |

## Function Description

### OH_AudioDecoder_Configure()

```
OH_AVErrCode OH_AudioDecoder_Configure (OH_AVCodec * codec, OH_AVFormat * format )
```

**Description**

Configures an audio decoder. Typically, you need to configure the audio description information that can be extracted from the container.

This function must be called prior to **Prepare**.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name  | Description                                               |
| ------ | --------------------------------------------------- |
| codec  | Pointer to an **OH_AVCodec** instance.                         |
| format | Pointer to the **OH_AVFormat** instance, which provides the description information about the audio track to be decoded.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_CreateByMime()

```
OH_AVCodec* OH_AudioDecoder_CreateByMime (const char * mime)
```

**Description**

Creates an audio decoder instance based on a MIME type. This function is recommended in most cases.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name| Description                                                   |
| ---- | ------------------------------------------------------- |
| mime | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).|

**Returns**

Returns the pointer to an **OH_AVCodec** instance.

**Since**

9

### OH_AudioDecoder_CreateByName()

```
OH_AVCodec* OH_AudioDecoder_CreateByName (const char * name)
```

**Description**

Creates an audio decoder instance based on a decoder name. To use this function, you must know the exact name of the decoder.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name| Description            |
| ---- | ---------------- |
| name | Pointer to an audio decoder name.|

**Returns**

Returns the pointer to an **OH_AVCodec** instance.

**Since**

9

### OH_AudioDecoder_Destroy()

```
OH_AVErrCode OH_AudioDecoder_Destroy (OH_AVCodec * codec)
```

**Description**

Clears the internal resources of an audio decoder and destroys the decoder instance.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_Flush()

```
OH_AVErrCode OH_AudioDecoder_Flush (OH_AVCodec * codec)
```

**Description**

Clears the input and output data in the internal buffer of an audio decoder.

This function invalidates the indexes of all buffers previously reported through the asynchronous callback. Therefore, before calling this function, ensure that the buffers with the specified indexes are no longer required.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_FreeOutputData()

```
OH_AVErrCode OH_AudioDecoder_FreeOutputData (OH_AVCodec * codec, uint32_t index )
```

**Description**

Frees an output buffer of an audio decoder.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                          |
| ----- | ------------------------------ |
| codec | Pointer to an **OH_AVCodec** instance.    |
| index | Index of the output buffer.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_GetOutputDescription()

```
OH_AVFormat* OH_AudioDecoder_GetOutputDescription (OH_AVCodec * codec)
```

**Description**

Obtains the description information about the output data of an audio decoder. For details, see **OH_AVFormat**. The caller must manually release the **OH_AVFormat** instance in the return value.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns the handle to an **OH_AVFormat** instance. The lifecycle of this instance is refreshed when **GetOutputDescription** is called again and destroyed when the **OH_AVCodec** instance is destroyed.

**Since**

9

### OH_AudioDecoder_IsValid()

```
OH_AVErrCode OH_AudioDecoder_IsValid (OH_AVCodec * codec, bool * isValid )
```

**Description**

Checks whether an audio decoder instance is valid.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name   | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| codec   | Pointer to an **OH_AVCodec** instance.                                       |
| isValid | Pointer to an instance of the Boolean type. The value **true** means that the decoder instance is valid and **false** means the opposite.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10

### OH_AudioDecoder_Prepare()

```
OH_AVErrCode OH_AudioDecoder_Prepare (OH_AVCodec * codec)
```

**Description**

Prepares internal resources for an audio decoder. This function must be called after **Configure**.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_PushInputData()

```
OH_AVErrCode OH_AudioDecoder_PushInputData (OH_AVCodec * codec, uint32_t index, OH_AVCodecBufferAttr attr )
```

**Description**

Pushes the input buffer filled with data to an audio decoder.

The **OH_AVCodecOnNeedInputData** callback reports the available input buffer and the index. After being pushed to the decoder, a buffer is not accessible until the buffer with the same index is reported again through the **OH_AVCodecOnNeedInputData** callback. In addition, some decoders require the input of specific data to initialize the decoding process.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                          |
| ----- | ------------------------------ |
| codec | Pointer to an **OH_AVCodec** instance.    |
| index | Index of the input buffer.|
| attr  | Description information about the data in the buffer.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_Reset()

```
OH_AVErrCode OH_AudioDecoder_Reset (OH_AVCodec * codec)
```

**Description**

Resets an audio decoder. To continue decoding, you must call **Configure** to configure the decoder again.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_SetCallback()

```
OH_AVErrCode OH_AudioDecoder_SetCallback (OH_AVCodec * codec, OH_AVCodecAsyncCallback callback, void * userData )
```

**Description**

Sets an asynchronous callback so that your application can respond to events generated by an audio decoder.

This function must be called prior to **Prepare**.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name    | Description                                                         |
| -------- | ------------------------------------------------------------- |
| codec    | Pointer to an **OH_AVCodec** instance.                                   |
| callback | Callback function to set. For details, see **OH_AVCodecAsyncCallback**.|
| userData | User-specific data.                                               |

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_SetParameter()

```
OH_AVErrCode OH_AudioDecoder_SetParameter (OH_AVCodec * codec, OH_AVFormat * format )
```

**Description**

Sets dynamic parameters for an audio decoder.

This function can be called only after the decoder is started. Incorrect parameter settings may cause decoding failure.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name  | Description                      |
| ------ | -------------------------- |
| codec  | Pointer to an **OH_AVCodec** instance.|
| format | Handle to an **OH_AVFormat** instance.     |

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_Start()

```
OH_AVErrCode OH_AudioDecoder_Start (OH_AVCodec * codec)
```

**Description**

Starts an audio decoder. This function can be called only after the decoder is prepared successfully.

After being started, the decoder starts to report the **OH_AVCodecOnNeedInputData** event.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9

### OH_AudioDecoder_Stop()

```
OH_AVErrCode OH_AudioDecoder_Stop (OH_AVCodec * codec)
```

**Description**

Stops an audio decoder.

After the decoder is stopped, you can call **Start** to start it again. If you have passed specific data in the previous **Start** for the decoder, you must pass it again.

\@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Parameters**

| Name | Description                      |
| ----- | -------------------------- |
| codec | Pointer to an **OH_AVCodec** instance.|

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

9
