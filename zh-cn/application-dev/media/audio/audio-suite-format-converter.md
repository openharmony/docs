# 音频格式转换(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API版本26.0.0开始，[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)给开发者提供PCM音频格式转换能力，在纯音频转码等场景下支持开发者使用格式转换接口将PCM（Pulse Code Modulation）音频数据从一种格式转换为另一种格式，包括采样率、声道布局、采样格式（位深）的转换。

## 开发步骤

开发者使用[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)提供的PCM音频格式转换能力，添加对应的头文件。

### 在CMake脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudiosuite.so)
```
### 添加头文件
开发者通过引入头文件<[native_audio_converter.h](../../reference/apis-audio-kit/capi-native-audio-converter-h.md)>，使用音频格式转换相关API。

```cpp
#include <ohaudiosuite/native_audio_converter.h>
```
音频格式转换相关接口返回值请参考：[OH_AudioConverter_Result](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_result)。

详细的API说明请参考：[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)。

**功能特性**

格式转换器提供的核心功能如下所示：

- 采样率转换：支持14种标准采样率之间的相互转换，包括8000Hz至192000Hz的常用采样率。
- 声道布局转换：支持32种声道布局之间的转换，覆盖1-8声道的各种音频配置。如立体声转单声道、5.1环绕声转7.1环绕声等。
- 采样格式转换：支持5种PCM采样格式之间的相互转换，包括8-bit无符号、16/24/32-bit有符号和32-bit浮点格式。

**使用限制**

- 仅支持PCM格式的音频数据进行转换。
- 回调数据大小限制：单次回调最多返回400KB数据，超出部分需要分多次返回。
- 输出缓冲区容量：输出缓冲区容量必须至少能容纳一个完整音频帧（采样率 × 声道数 × 采样格式字节数）。
- 数据流结束处理：当输入回调函数返回`AUDIOCONVERTER_INPUT_DATA_FINISHED`表示输入数据已经输入完成时，仍需要继续调用[OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process)直到`outputSize`为0，以确保所有缓存的转换数据都被输出。
- 数据指针有效性：回调函数返回的数据指针在[OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process)返回前必须保持有效，不能在回调返回后立即释放。

**数据流处理流程**

格式转换器采用流式数据处理模式，完整的数据处理流程如下所示：

1. 初始化阶段。
   - 调用[OH_AudioConverter_Create()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_create)创建转换器实例。
   - 调用[OH_AudioConverter_SetInputCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback)设置输入数据回调函数。

2. 数据输入阶段。
   - 转换器内部维护输入数据缓存。
   - 当缓存数据不足时，转换器会自动调用回调函数请求更多数据。
   - 回调函数根据当前状态返回数据：
     - `AUDIOCONVERTER_INPUT_HAVE_DATA`：有数据可用，返回本次提供的数据大小（必须大于0）。
     - `AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA`：暂无数据可用，返回0，转换器停止本次处理。
     - `AUDIOCONVERTER_INPUT_DATA_FINISHED`：数据流结束，返回0，转换器继续处理缓存数据。

3. 数据转换阶段。
   - 转换器根据输入和输出格式计算需要的输入数据量。
   - 对输入数据进行重采样、声道转换、格式转换等操作。
   - 将转换后的数据存入输出缓存。

4. 数据输出阶段。
   - 调用[OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process)获取转换后的数据。
   - 每次调用返回的`outputSize`表示实际输出的数据大小。
   - 需要循环调用[OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process)接口执行格式转换，直到`outputSize`为0，且输入回调函数返回`AUDIOCONVERTER_INPUT_DATA_FINISHED`状态，确保所有缓存的转换数据都被输出。

5. 清理阶段。
   - 调用[OH_AudioConverter_Destroy()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_destroy)销毁转换器实例。
   - 释放所有相关资源。

**支持的音频格式**

格式转换接口支持以下PCM音频格式：

- 采样率：[SAMPLE_RATE_8000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_11025](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_12000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_16000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_22050](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_24000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_32000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_44100](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_48000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_64000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_88200](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_96000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_176400](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)、[SAMPLE_RATE_192000](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)。

- 声道布局：[CH_LAYOUT_MONO](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_STEREO](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_STEREO_DOWNMIX](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_2POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_3POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_SURROUND](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_3POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_4POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_QUAD_SIDE](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_QUAD](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_2POINT0POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_4POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_5POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_5POINT0_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_2POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_3POINT0POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_5POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_5POINT1_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_6POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_3POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_6POINT0_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_HEXAGONAL](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_6POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_6POINT1_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_6POINT1_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_7POINT0](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_7POINT0_FRONT](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_7POINT1](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_OCTAGONAL](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_5POINT1POINT2](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_7POINT1_WIDE](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)、[CH_LAYOUT_7POINT1_WIDE_BACK](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)。
- 采样格式：[AUDIO_SAMPLE_U8](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)、[AUDIO_SAMPLE_S16LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)、[AUDIO_SAMPLE_S24LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)、[AUDIO_SAMPLE_S32LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)、[AUDIO_SAMPLE_F32LE](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)。

### 创建格式转换器

   <!-- @[converter_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->
   
   ``` C++
   // 用户需按照实际情况设置输入格式。
   OH_AudioConverter_Format inputFormat = {
       .encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW,
       .samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000,
       .channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO,
       .sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE
   };
   
   // 用户需按照实际情况设置输出格式。
   OH_AudioConverter_Format outputFormat = {
       .encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW,
       .samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_192000,
       .channelLayout = OH_AudioChannelLayout::CH_LAYOUT_6POINT0_FRONT,
       .sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S24LE
   };
   
   // 创建转换器。
   OH_AudioConverter_Result result = OH_AudioConverter_Create(&inputFormat, &outputFormat, &converter);
   if (result != AUDIOCONVERTER_SUCCESS) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to create converter: %{public}d", result);
       return false;
   }
   ```

### 设置输入数据回调函数

   创建输入数据回调函数`RequestDataCallback`，函数类型为[OH_AudioConverter_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_requestdatacallback)，调用[OH_AudioConverter_SetInputCallback()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_setinputcallback)接口设置回调函数。

   输入数据回调函数。

   <!-- @[input_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->
   
   ``` C++
   // 设置输出数据指针。
   // 注意：数据指针的值并不一定要从userData中获取，也可以是存储数据的缓存地址。
   // 例如：从文件中读取数据放入缓存，然后将该缓存地址赋值给输出数据指针。
   // 只要确保数据指针在OH_AudioConverter_Process()返回前保持有效即可。
   *outInputData = dataInfo->buffer + dataInfo->readDataOffset;
   
   // 计算本次可提供的数据大小（单次回调最多返回400KB）。
   // bufferSize：文件的总字节数。
   // readDataOffset：已读取的字节数偏移量。
   int32_t remainingSize = dataInfo->bufferSize - dataInfo->readDataOffset;
   if (remainingSize < 0) {
       return -1;
   }
   int32_t actualDataSize = (remainingSize < MAX_DATA_SIZE) ? remainingSize : MAX_DATA_SIZE;
   
   // 更新已读取位置。
   dataInfo->readDataOffset += actualDataSize;
   
   // 设置输入数据状态。
   if (dataInfo->readDataOffset >= dataInfo->bufferSize) {
       *outStatus = OH_AudioConverter_InputStatus::AUDIOCONVERTER_INPUT_DATA_FINISHED;
       dataInfo->readDataFinish = true;
   } else {
       *outStatus = OH_AudioConverter_InputStatus::AUDIOCONVERTER_INPUT_HAVE_DATA;
   }
   ```

   设置输入数据回调。

   <!-- @[set_input_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->
   
   ``` C++
   // 设置输入回调。
   result = OH_AudioConverter_SetInputCallback(converter, AudioConverterRequestDataCallback, dataInfo);
   if (result != AUDIOCONVERTER_SUCCESS) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to set input callback: %{public}d", result);
       OH_AudioConverter_Destroy(converter);
       return false;
   }
   ```

### 执行格式转换

   调用[OH_AudioConverter_Process()](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_process)接口执行格式转换。

   > **注意：**
   >
   > - 判断数据处理是否完成需要同时满足以下三个条件：
   >   - `OH_AudioConverter_Process()`返回`AUDIOCONVERTER_SUCCESS`。
   >   - `outputSize`为0。
   >   - 所有输入数据已经结束（回调函数已经返回了`AUDIOCONVERTER_INPUT_DATA_FINISHED`）。
   > - `AUDIOCONVERTER_INPUT_NO_AVAILABLE_DATA`和`AUDIOCONVERTER_INPUT_DATA_FINISHED`状态下，`OH_AudioConverter_Process()`会返回[AUDIOCONVERTER_SUCCESS](../../reference/apis-audio-kit/capi-native-audio-converter-h.md#oh_audioconverter_result)和`outputSize = 0`。因此，不能仅凭`outputSize = 0`或`result = AUDIOCONVERTER_SUCCESS`判断数据处理已经完成，还需要调用方确保所有数据已经输入结束。

   <!-- @[converter_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->
   
   ``` C++
   // 分配处理缓冲区。
   const int32_t processBufferSize = 4096 * 4; // 16KB。
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
           // 用户可以根据自己的业务要求做相应的处理。
           size_t written = fwrite(processBuffer, 1, outputSize, outputFile);
           if (written != static_cast<size_t>(outputSize)) {
               OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Failed to write output data");
               delete[] processBuffer;
               SafeCloseConverterFile(outputFile, outputFilePath);
               return false;
           }
           totalOutputSize += outputSize;
       }
       // outputSize返回0，且用户写入数据完成。
   } while (outputSize > 0 || !dataInfo->readDataFinish);
   
   delete[] processBuffer;
   processBuffer = nullptr;
   SafeCloseConverterFile(outputFile, outputFilePath);
   ```

### 销毁格式转换器

   <!-- @[converter_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_format_converter.cpp) -->
   
   ``` C++
   OH_AudioConverter_Destroy(converter);
   ```
   
<!--RP1-->
## 完整示例代码

- [音频编创示例代码](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)
<!--RP1End-->