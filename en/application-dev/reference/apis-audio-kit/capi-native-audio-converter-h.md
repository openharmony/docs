# native_audio_converter.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## Overview

This file declares the underlying data structures for input and output audio formats and the definitions of format conversion APIs.

**File to include**: <ohaudiosuite/native_audio_converter.h>

**Library**: libohaudiosuite.so

**System capability**: SystemCapability.Multimedia.Audio.SuiteEngine

**Since**: 26.0.0

**Related module**: [OHAudioSuite](capi-ohaudiosuite.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md) | OH_AudioConverter_Format | Defines the data structure of the audio converter, which is used to describe the audio format.|
| [OH_AudioConverterStruct](capi-audioconverter-oh-audioconverterstruct.md) | OH_AudioConverter | Describes the audio converter.<br> The handle to the audio converter is used to perform functions related to the audio converter.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioConverter_Result](#oh_audioconverter_result) | OH_AudioConverter_Result | Enumerates the return results of function execution.|
| [OH_AudioConverter_InputStatus](#oh_audioconverter_inputstatus) | OH_AudioConverter_InputStatus | Enumerates the statuses of input audio data provided by the [OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback) callback function. The converter uses the statuses to determine how to handle subsequent conversion logic, for example, continuing data extraction, or pausing or clearing cache data.<br> Note: Even if the callback returns **AUDIOCONVERTER_INPUT_DATA_FINISHED**, you must repeatedly call **OH_AudioConverter_Process** until [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) returns **AUDIOCONVERTER_SUCCESS** and **outputSize** is **0** (indicating that all cache data has been processed).|

### Function

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioConverter_Result OH_AudioConverter_Create(const OH_AudioConverter_Format* inputFormat, const OH_AudioConverter_Format* outputFormat, OH_AudioConverter** converter)](#oh_audioconverter_create) | - | Creates an audio converter.|
| [void OH_AudioConverter_Destroy(OH_AudioConverter* converter)](#oh_audioconverter_destroy) | - | Destroys an audio converter.|
| [typedef int32_t (\*OH_AudioConverter_RequestDataCallback)(void* userData, const void** outInputData, OH_AudioConverter_InputStatus* outStatus)](#oh_audioconverter_requestdatacallback) | OH_AudioConverter_RequestDataCallback | Data request callback function. An audio converter calls this callback function to proactively request input audio data during the [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) call.<br> The caller must fill in the output parameters (**outInputData** and **outStatus**) and return the size of the data read through the callback function.<br> The maximum size of data returned by a single callback is 400 KB.<br> The memory to which **outInputData** points must remain valid until **OH_AudioConverter_Process** returns a message indicating that the processing is complete.|
| [OH_AudioConverter_Result OH_AudioConverter_SetInputCallback(OH_AudioConverter* converter, OH_AudioConverter_RequestDataCallback callback, void* userData)](#oh_audioconverter_setinputcallback) | - | Sets the data request callback function for a converter. This function binds the audio converter's input data callback function. The callback function is called by [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) to obtain the input audio data for processing.|
| [OH_AudioConverter_Result OH_AudioConverter_Process(OH_AudioConverter* converter, void* outputData, int32_t outputCapacity, int32_t* outputSize)](#oh_audioconverter_process) | - | Executes audio format conversion. This function converts the input audio to the target format. Note that this function must be called after [OH_AudioConverter_SetInputCallback](capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback), and the output buffer to which the final conversion result is written must be allocated and managed by the caller.|

## Enum Description

### OH_AudioConverter_Result

```c
enum OH_AudioConverter_Result
```

**Description**

Enumerates the return results of function execution.

**Since**: 26.0.0

| Enum Item| Description|
| -- | -- |
| AUDIOCONVERTER_SUCCESS = 0 |  The function is successfully called.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_INVALID_PARAM = 1 |  The function input parameter is invalid. For example, the input format converter pointer is nullptr.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_UNSUPPORTED_FORMAT = 2 |  Unsupported audio format, for example, unsupported encoding type or sampling format.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_SYSTEM = 3 |  A system error occurs. For example, a destroyed format converter is used to perform format conversion.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_MEMORY_ALLOC_FAILED = 4 |  Memory allocation failed. For example, the memory of the internal output data buffer fails to be allocated.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_BUFFER_TOO_SMALL = 5 |  Insufficient output buffer capacity. For example, the configured capacity for storing output data is insufficient to store one frame of output data.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_NOT_INITIALIZED = 6 |  The audio converter instance is not initialized. For example, the format conversion function is directly executed without creating a format converter.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_CALLBACK_INVALID = 7 |  Invalid input callback function. For example, the amount of data returned by the input callback function is less than 0 or greater than the maximum value of 400 KB.<br>**Since**: 26.0.0|
| AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET = 8 |  The callback function is not set. For example, the input callback function pointer is nullptr.<br>**Since**: 26.0.0|

### OH_AudioConverter_InputStatus

```c
enum OH_AudioConverter_InputStatus
```

**Description**

Enumerates the statuses of input audio data provided by the [OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback) callback function. The converter uses the statuses to determine how to handle subsequent conversion logic, for example, continuing data extraction, or pausing or clearing cache data.<br> Note: Even if the callback returns **AUDIOCONVERTER_INPUT_DATA_FINISHED**, you must repeatedly call **OH_AudioConverter_Process** until [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) returns **AUDIOCONVERTER_SUCCESS** and **outputSize** is **0** (indicating that all cache data has been processed).

**Since**: 26.0.0

| Enum Item| Description|
| -- | -- |
| AUDIOCONVERTER_INPUT_HAVE_DATA = 1 | The provided input data is valid.|
| AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA = 2 | No input data is available temporarily.|
| AUDIOCONVERTER_INPUT_DATA_FINISHED = 3 | The input data stream is complete.|


## Function Description

### OH_AudioConverter_Create()

```c
OH_AudioConverter_Result OH_AudioConverter_Create(const OH_AudioConverter_Format* inputFormat, const OH_AudioConverter_Format* outputFormat, OH_AudioConverter** converter)
```

**Description**

Creates an audio converter.

> **NOTE**
>
> - The converter instance created by this function must be explicitly destroyed using [OH_AudioConverter_Destroy](capi-native-audio-converter-h.md#oh_audioconverter_destroy).
> - Supported audio formats (applicable to input/output):
> Pulse code modulation (PCM) audio format
> - Supported sampling rates: 8,000 Hz, 11,025 Hz, 12,000 Hz, 16,000 Hz, 22,050 Hz, 24,000 Hz, 32,000 Hz, 44,100 Hz, 48,000 Hz,
> 64,000 Hz, 88,200 Hz, 96,000 Hz, 176,400 Hz, and 192,000 Hz.
> - Supported channel layouts: CH_LAYOUT_MONO, CH_LAYOUT_STEREO, CH_LAYOUT_STEREO_DOWNMIX,
> CH_LAYOUT_2POINT1, CH_LAYOUT_3POINT0, CH_LAYOUT_SURROUND, CH_LAYOUT_3POINT1, CH_LAYOUT_4POINT0, CH_LAYOUT_QUAD_SIDE,
> CH_LAYOUT_QUAD, CH_LAYOUT_2POINT0POINT2, CH_LAYOUT_4POINT1, CH_LAYOUT_5POINT0, CH_LAYOUT_5POINT0_BACK,
> CH_LAYOUT_2POINT1POINT2, CH_LAYOUT_3POINT0POINT2, CH_LAYOUT_5POINT1, CH_LAYOUT_5POINT1_BACK, CH_LAYOUT_6POINT0,
> CH_LAYOUT_3POINT1POINT2, CH_LAYOUT_6POINT0_FRONT, CH_LAYOUT_HEXAGONAL, CH_LAYOUT_6POINT1, CH_LAYOUT_6POINT1_BACK,
> CH_LAYOUT_6POINT1_FRONT, CH_LAYOUT_7POINT0, CH_LAYOUT_7POINT0_FRONT, CH_LAYOUT_7POINT1, CH_LAYOUT_OCTAGONAL,
> CH_LAYOUT_5POINT1POINT2, CH_LAYOUT_7POINT1_WIDE, and CH_LAYOUT_7POINT1_WIDE_BACK.
> - Supported sampling formats (bit depth): SAMPLE_U8 (8-bit unsigned PCM),
> SAMPLE_S16LE (16-bit little-endian short PCM), SAMPLE_S24LE (24-bit little-endian short PCM),
> SAMPLE_S32LE (32-bit little-endian short PCM), and SAMPLE_F32LE (32-bit little-endian float PCM)

**Since**: 26.0.0

**Parameters**

| Name| Description|
| --- | --- |
| const [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md)* inputFormat | Pointer to the input audio format.|
| const [OH_AudioConverter_Format](capi-audioconverter-oh-audioconverter-format.md)* outputFormat | Pointer to the output audio format.|
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)** converter | Pointer to an available audio converter.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | **AUDIOCONVERTER_SUCCESS**: The format converter is successfully created, and the subsequent process can be performed normally.<br>         **AUDIO_CONVERTER_ERROR_INVALID_PARAM**: The input parameter is invalid. Check whether the passed format converter pointer is not nullptr. <br>         **AUDIO_CONVERTER_ERROR_UNSUPPORTED_FORMAT**: The audio input/output format combination is not supported. The input/output format is out of the allowed range. Verify the configured audio formats. <br>          **AUDIO_CONVERTER_ERROR_SYSTEM**: A system error occurred. Check whether you are performing format conversion using a destroyed converter.|

### OH_AudioConverter_Destroy()

```c
void OH_AudioConverter_Destroy(OH_AudioConverter* converter)
```

**Description**

Destroys an audio converter.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | Audio converter created by the [OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create) function.|

### OH_AudioConverter_RequestDataCallback()

```c
typedef int32_t (*OH_AudioConverter_RequestDataCallback)(void* userData, const void** outInputData, OH_AudioConverter_InputStatus* outStatus
)
```

**Description**

Data request callback function. An audio converter calls this callback function to proactively request input audio data during the [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) call.<br> The caller must fill in the output parameters (**outInputData** and **outStatus**) and return the size of the data read through the callback function.<br> The maximum size of data returned by a single callback is 400 KB.<br> The memory to which **outInputData** points must remain valid until **OH_AudioConverter_Process** returns a message indicating that the processing is complete.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| void\* userData | Pointer to the user-defined data passed to the callback function.|
| const void\*\* outInputData | Pointer to the input audio data buffer set by the callback function.|
| [OH_AudioConverter_InputStatus](capi-native-audio-converter-h.md#oh_audioconverter_inputstatus)\* outStatus | Pointer to the input data status to be sent to the converter, which is set by the callback function.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Size of the valid input data pointed to by the **outInputData** pointer.|

### OH_AudioConverter_SetInputCallback()

```c
OH_AudioConverter_Result OH_AudioConverter_SetInputCallback(OH_AudioConverter* converter, OH_AudioConverter_RequestDataCallback callback, void* userData
)
```

**Description**

Sets the data request callback function for a converter. This function binds the audio converter's input data callback function. The callback function is called by [OH_AudioConverter_Process](capi-native-audio-converter-h.md#oh_audioconverter_process) to obtain the input audio data for processing.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | Audio converter created by the [OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create) function.|
| [OH_AudioConverter_RequestDataCallback](capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback) callback | Callback function used to write audio data.|
| userData | Pointer to the application data structure to be passed to the callback function.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | **AUDIOCONVERTER_SUCCESS**: The input callback function is set successfully, and the subsequent process can be performed normally.<br>         **AUDIO_CONVERTER_ERROR_INVALID_PARAM**: The input parameter is invalid. Check whether the passed format converter pointer is not nullptr. <br>         **AUDIOCONVERTER_ERROR_NOT_INITIALIZED**: The format converter is not initialized. Check whether the current format converter is valid.<br>         **AUDIO_CONVERTER_ERROR_CALLBACK_INVALID**: The callback function is invalid. Check whether the amount of data returned by the input callback function is within the allowed range.<br>         **AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET**: The callback function is not set. Check whether the callback function pointer is not null.<br>         **AUDIO_CONVERTER_ERROR_SYSTEM**: A system error occurred. Check whether you are performing format conversion using a destroyed converter.|

### OH_AudioConverter_Process()

```c
OH_AudioConverter_Result OH_AudioConverter_Process(OH_AudioConverter* converter, void* outputData, int32_t outputCapacity, int32_t* outputSize
)
```

**Description**

Executes audio format conversion. This function converts the input audio to the target format. Note that this function must be called after [OH_AudioConverter_SetInputCallback](capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback), and the output buffer to which the final conversion result is written must be allocated and managed by the caller.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioConverter](capi-audioconverter-oh-audioconverterstruct.md)* converter | Audio converter created by the [OH_AudioConverter_Create](capi-native-audio-converter-h.md#oh_audioconverter_create) function.|
| void* outputData | Pointer to the output buffer allocated by the caller.|
| int32_t outputCapacity | Size of the output buffer specified by the caller.|
| outputSize | Size of the data actually written to the output buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioConverter_Result](capi-native-audio-converter-h.md#oh_audioconverter_result) | **AUDIOCONVERTER_SUCCESS**: The PCM audio data is successfully converted, and the subsequent process can be performed normally.<br>         **AUDIO_CONVERTER_ERROR_INVALID_PARAM**: The input parameter is invalid. Check whether the passed format converter pointer is not nullptr. <br>         **AUDIOCONVERTER_ERROR_NOT_INITIALIZED**: The format converter is not initialized. Check whether the current format converter is valid.<br>         **AUDIO_CONVERTER_ERROR_CALLBACK_INVALID**: The input callback function is invalid. Check whether the amount of data returned by the input callback function is within the allowed range.<br>         **AUDIOCONVERTER_ERROR_CALLBACK_NOT_SET**: The callback function is not set. Check whether the callback function is successfully set and whether the function pointer is not null.<br>         **AUDIOCONVERTER_ERROR_BUFFER_TOO_SMALL**: The output buffer capacity is insufficient. Check whether the capacity of the buffer for storing the output data is sufficient to store one frame of output data.<br>          **AUDIO_CONVERTER_ERROR_SYSTEM**: A system error occurred. Check whether you are performing format conversion using a destroyed converter.|
