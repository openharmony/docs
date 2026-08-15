# Audio Format Conversion (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9d1897fa3dab6fc356e7d2cd6662301d7b025cb1 translatedAt=2026-08-15T01:55:56.092Z pushedAt=2026-08-15T08:58:39.185Z -->

Starting from API version 26.0.0, [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) provides PCM (Pulse Code Modulation) audio format conversion capabilities. In scenarios such as pure audio transcoding, you can use the format conversion APIs to convert PCM audio data from one format to another, including conversion of sample rate, channel layout, and sample format (bit depth).

## How to Develop

To use the PCM audio format conversion capability provided by [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md), include the corresponding header file.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudiosuite.so)
```

### Including Header Files

Include the header file &lt;[native_audio_converter.h](../../reference/apis-audio-kit/capi-native-audio-converter-h.md)&gt; to use audio format conversion APIs.

<!-- @[format_conversion_header_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

``` C++
#include <ohaudiosuite/native_audio_converter.h>
```

For return values of these APIs, see [OH_AudioConverter_Result](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_result).

For detailed API descriptions, see [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md).

**Features**

The core capabilities provided by the format converter are as follows:

- Sample rate conversion: Supports mutual conversion between 14 standard sample rates, including common rates from 8000 Hz to 192000 Hz.

- Channel layout conversion: Supports conversion between 32 channel layouts, covering various audio configurations from 1 to 8 channels, such as stereo to mono, 5.1 surround to 7.1 surround, and more.

- Sample format conversion: Supports mutual conversion between five PCM sample formats, including 8-bit unsigned, 16/24/32-bit signed, and 32-bit float formats.

**Constraints**

- Only PCM audio data is supported for conversion.

- Callback data size limit: A single callback can return a maximum of 400 KB of data. Data exceeding this limit must be returned in multiple callbacks.

- Output buffer capacity: The output buffer must be able to hold at least one complete audio frame (sample rate × number of channels × sample format byte size).

- End-of-stream handling: When the input callback function returns `AUDIOCONVERTER_INPUT_DATA_FINISHED`, indicating that all input data has been provided, you must continue calling [OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process) until `outputSize` reaches 0 to ensure that all buffered converted data is output.

- Data pointer validity: The data pointer returned by the callback function must remain valid until [OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process) returns. Do not release it immediately after the callback returns.

**Data Processing Flow**

The format converter uses a stream-based data processing model. The complete data processing flow is as follows:

1. Initialization phase:

   - Call [OH_AudioConverter_Create()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_create) to create a converter instance.

   - Call [OH_AudioConverter_SetInputCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback) to set the input data callback function.

2. Data input phase:

   - The converter internally maintains an input data buffer.

   - When the buffered data is insufficient, the converter automatically invokes the callback function to request more data.

   - The callback function returns data based on the current state:

     - `AUDIOCONVERTER_INPUT_HAVE_DATA`: Data is available. Returns the size of the data provided this time (must be greater than 0).

     - `AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA`: No data is available at the moment. Returns 0, and the converter stops the current processing.

     - `AUDIOCONVERTER_INPUT_DATA_FINISHED`: The data stream ends. Returns 0, and the converter continues processing the buffered data.

3. Data conversion phase:

   - The converter calculates the required amount of input data based on the input and output formats.

   - The converter performs operations such as resampling, channel conversion, and format conversion on the input data.

   - The converted data is stored in the output buffer.

4. Data output phase:

   - Call [OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process) to obtain the converted data.

   - The `outputSize` returned by each call indicates the actual size of the output data.

   - Call [OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process) in a loop to perform format conversion until `outputSize` is 0 and the input callback function returns the `AUDIOCONVERTER_INPUT_DATA_FINISHED` status, ensuring that all buffered conversion data is output.

5. Cleanup phase:

   - Call [OH_AudioConverter_Destroy()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_destroy) to destroy the converter instance.

   - Release all related resources.

**Supported Audio Formats**

The format conversion APIs support the following PCM audio formats:

- Sample rate: [SAMPLE_RATE_8000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_11025](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_12000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_16000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_22050](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_24000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_32000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_44100](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_48000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_64000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_88200](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_96000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_176400](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate), [SAMPLE_RATE_192000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)

- Channel layout: [CH_LAYOUT_MONO](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_STEREO](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_STEREO_DOWNMIX](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_2POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_3POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_SURROUND](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_3POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_4POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_QUAD_SIDE](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_QUAD](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_2POINT0POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_4POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_5POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_5POINT0_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_2POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_3POINT0POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_5POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_5POINT1_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_6POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_3POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_6POINT0_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_HEXAGONAL](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_6POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_6POINT1_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_6POINT1_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_7POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_7POINT0_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_7POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_OCTAGONAL](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_5POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_7POINT1_WIDE](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout), [CH_LAYOUT_7POINT1_WIDE_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)

- Sample format: [AUDIO_SAMPLE_U8](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat), [AUDIO_SAMPLE_S16LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat), [AUDIO_SAMPLE_S24LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat), [AUDIO_SAMPLE_S32LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat), [AUDIO_SAMPLE_F32LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)

### Creating a Format Converter

   <!-- @[converter_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

   ``` C++
   // Set the input format based on the actual situation.
   OH_AudioConverter_Format inputFormat = {
       .encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW,
       .samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000,
       .channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO,
       .sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE
   };
   
   // Set the output format based on the actual situation.
   OH_AudioConverter_Format outputFormat = {
       .encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW,
       .samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_192000,
       .channelLayout = OH_AudioChannelLayout::CH_LAYOUT_6POINT0_FRONT,
       .sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S24LE
   };
   
   // Create the converter.
   OH_AudioConverter_Result result = OH_AudioConverter_Create(&inputFormat, &outputFormat, &converter);
   if (result != AUDIOCONVERTER_SUCCESS) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to create converter: %{public}d", result);
       return false;
   }
   ```

### Setting the Input Data Callback Function

   Create the input data callback function `RequestDataCallback` of type [OH_AudioConverter_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback), and call [OH_AudioConverter_SetInputCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback) to set the callback function.

   Set the input data callback.

   <!-- @[input_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

   ``` C++
   // Set the output data pointer.
   // Note: The value of the data pointer does not necessarily have to come from userData; it can also be the address of a buffer that stores data.
   // For example, read data from a file into a buffer, and then assign the buffer address to the output data pointer.
   // Just ensure that the data pointer remains valid until OH_AudioConverter_Process() returns.
   *outInputData = dataInfo->buffer + dataInfo->readDataOffset;
   
   // Calculate the data size available this time (a single callback returns at most 400 KB).
   // bufferSize: total number of bytes in the file.
   // readDataOffset: byte offset of the data already read.
   int32_t remainingSize = dataInfo->bufferSize - dataInfo->readDataOffset;
   if (remainingSize < 0) {
       return -1;
   }
   int32_t actualDataSize = (remainingSize < MAX_DATA_SIZE) ? remainingSize : MAX_DATA_SIZE;
   
   // Update the read position.
   dataInfo->readDataOffset += actualDataSize;
   
   // Set the input data status.
   if (dataInfo->readDataOffset >= dataInfo->bufferSize) {
       *outStatus = OH_AudioConverter_InputStatus::AUDIOCONVERTER_INPUT_DATA_FINISHED;
       dataInfo->readDataFinish = true;
   } else {
       *outStatus = OH_AudioConverter_InputStatus::AUDIOCONVERTER_INPUT_HAVE_DATA;
   }
   ```

   Set the input data callback.

   <!-- @[set_input_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

   ``` C++
   // Set the input callback.
   result = OH_AudioConverter_SetInputCallback(converter, AudioConverterRequestDataCallback, dataInfo);
   if (result != AUDIOCONVERTER_SUCCESS) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to set input callback: %{public}d", result);
       OH_AudioConverter_Destroy(converter);
       return false;
   }
   ```

### Executing Format Conversion

   Call [OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process) to perform format conversion.

   > **NOTE**
   >
   > - To determine whether data processing is complete, all three of the following conditions must be met simultaneously:
   >   - `OH_AudioConverter_Process()` returns `AUDIOCONVERTER_SUCCESS`.
   >   - `outputSize` is `0`.
   >   - All input data has ended (the callback function has returned `AUDIOCONVERTER_INPUT_DATA_FINISHED`).
   > - In the `AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA` and `AUDIOCONVERTER_INPUT_DATA_FINISHED` states, `OH_AudioConverter_Process()` returns [AUDIOCONVERTER_SUCCESS](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_result) and `outputSize = 0`. Therefore, you cannot determine that data processing is complete based solely on `outputSize = 0` or `result = AUDIOCONVERTER_SUCCESS`. The caller must also ensure that all data input has ended.

   <!-- @[converter_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

   ``` C++
   // Allocate the processing buffer.
   const int32_t processBufferSize = 4096 * 4; // 16 KB.
   uint8_t *processBuffer = new uint8_t[processBufferSize];
   int32_t outputSize = 0;
   int32_t totalOutputSize = 0;
   OH_AudioConverter_Result result;
   
   do {
       result = OH_AudioConverter_Process(converter, processBuffer, processBufferSize, &outputSize);
       if (result != AUDIOCONVERTER_SUCCESS) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Audio data processing failed: %{public}d", result);
           delete[] processBuffer;
           SafeCloseConverterFile(outputFile, outputFilePath);
           return false;
       }
           
       if (outputSize > 0) {
           // You can perform corresponding processing based on your own business requirements.
           size_t written = fwrite(processBuffer, 1, outputSize, outputFile);
           if (written != static_cast<size_t>(outputSize)) {
               OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to write output data");
               delete[] processBuffer;
               SafeCloseConverterFile(outputFile, outputFilePath);
               return false;
           }
           totalOutputSize += outputSize;
       }
       // outputSize returns 0, and the user has finished writing data.
   } while (outputSize > 0 || !dataInfo->readDataFinish);
   
   delete[] processBuffer;
   processBuffer = nullptr;
   SafeCloseConverterFile(outputFile, outputFilePath);
   ```

### Destroying the Format Converter

   <!-- @[converter_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->

   ``` C++
   OH_AudioConverter_Destroy(converter);
   ```

<!--RP1-->

## Samples

- [AudioSuiteSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)

<!--RP1End-->