# Real-Time Preview (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4b8b43a88b44fcb4b54b0589eeb40da7c2fbb748 translatedAt=2026-08-06T01:48:53.334Z pushedAt=2026-08-06T08:27:58.025Z -->

Starting from API version 22, [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) provides the real-time preview capability for audio authoring (API version 22 supports only the equalizer effect, while API version 23 and later support other effects). For example, you can use the preset sound effects in the equalizer to change the style of music.

## Basic Development Configuration

To use the real-time preview capability provided by [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md), include the corresponding header files.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so libohaudiosuite.so)
```

### Adding Header Files

To use APIs related to audio creation and playback, include the <[native_audio_suite_base.h](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md)>, <[native_audio_suite_engine.h](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md)>, <[native_audiostreambuilder.h](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md)>, and <[native_audiorenderer.h](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md)> header files.

<!-- @[audioSuite_RealTimeRenderingInclude](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

``` C++
#include <ohaudiosuite/native_audio_suite_base.h>
#include <ohaudiosuite/native_audio_suite_engine.h>
#include <ohaudio/native_audiorenderer.h>
#include <ohaudio/native_audiostreambuilder.h>
```

## How to Develop

### Calling Interfaces

For details on the APIs, see [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md).

### Equalizer Effect

**Figure 1** Real-time preview diagram

   ![OHAudioSuite realtime play](figures/audiosuite-audio-separation-time.png)

You can implement a simple equalizer effect node for real-time preview by following the steps below.

1. Initialize and create an [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) pipeline (including the input node, equalizer node, and output node).

   <!-- @[audioSuite_AudioDataInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/pcm_file_utils.h) -->

   ``` C
   struct AudioDataInfo {
       uint8_t *buffer = nullptr;   // Audio data.
       int32_t bufferSize = 0;      // Total size of the audio data.
       int32_t totalWriteSize = 0;  // Total size of the processed audio data.
       int32_t totalReadSize = 0;  // Total size of the audio data that has been read.
   };
   ```

   <!-- @[audioSuite_RealTimeRenderingInputNodeWriteDataCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value verification. Add verification logic in actual use.
   // Callback used by the input node to request data.
   static int32_t InputNodeWriteDataCallBack(OH_AudioNode *audioNode, void *userData, void *audioData,
                                             int32_t audioDataSize, bool *finished)
   {
       if ((audioNode == nullptr) || (userData == nullptr) || (audioData == nullptr) || (audioDataSize <= 0) ||
           (finished == nullptr)) {
           return -1;
       }
   
       struct AudioDataInfo *info = static_cast<struct AudioDataInfo *>(userData);
       // Size of the audio data to be processed.
       int32_t actualDataSize = std::min(audioDataSize, info->bufferSize - info->totalWriteSize);
       // Write the PCM audio data to audioData.
       if (actualDataSize > 0) {
           std::copy(info->buffer + info->totalWriteSize, info->buffer + info->totalWriteSize + actualDataSize,
                     static_cast<uint8_t *>(audioData));
       }
       info->totalWriteSize += actualDataSize;
   
       // All audio data has been processed.
       if (info->totalWriteSize >= info->bufferSize) {
           *finished = true;
       }
       return actualDataSize;
   }
   ```

   <!-- @[audioSuite_CreateRealTimeRendering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value verification. Add verification logic in actual use.
   // Create the engine.
   OH_AudioSuiteEngine_Create(&audioSuiteEngine);
   
   // Create a pipeline for real-time preview.
   OH_AudioSuiteEngine_CreatePipeline(audioSuiteEngine, &audioSuitePipeline,
                                      OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_REALTIME_MODE);
   // Create a node builder.
   OH_AudioNodeBuilder *nodeBuilder = nullptr;
   OH_AudioSuiteNodeBuilder_Create(&nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   
   // Configure the audio data format. Set the sampling rate, channel layout, number of channels, bit depth, and encoding format based on the audio data to be processed.
   OH_AudioFormat audioFormatInput;
   audioFormatInput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatInput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatInput.channelCount = CHANNEL_COUNT;
   audioFormatInput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatInput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   // Set the audio stream callback.
   void *userData = static_cast<void *>(audioInfo);
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   // Create the input node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &inputNode);
   
   // Reset the builder configuration and set the node type to equalizer.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::EFFECT_NODE_TYPE_EQUALIZER);
   // Create the equalizer node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &eqNode);
   // Set the equalizer node effect to default.
   OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(eqNode, OH_EQUALIZER_PARAM_DEFAULT);
   
   // Reset the builder configuration and set the node type to output.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::OUTPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sampling rate, channel layout, number of channels, bit depth, and encoding format based on the expected output audio format.
   OH_AudioFormat audioFormatOutput;
   audioFormatOutput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatOutput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatOutput.channelCount = CHANNEL_COUNT;
   audioFormatOutput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatOutput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatOutput);
   // Create the output node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &outputNode);
   
   // Destroy the node builder.
   OH_AudioSuiteNodeBuilder_Destroy(nodeBuilder);
   
   // Connect the nodes to form a network.
   OH_AudioSuiteEngine_ConnectNodes(inputNode, eqNode);
   OH_AudioSuiteEngine_ConnectNodes(eqNode, outputNode);
   ```

> **NOTE**
>
> Offline editing and real-time preview differ in how the pipeline is created.
> + Real-time preview: OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_REALTIME_MODE
> + Offline editing: OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_EDIT_MODE

2. Create an [OH_AudioRendererStruct](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorendererstruct.md) instance, and call [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe) of the [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) pipeline in its **AudioRendererOnWriteData()** callback function to process the data.

> **NOTE**
>
> The processing duration of [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe) depends on the number of effect nodes connected in the pipeline. Pay attention to the processing duration to avoid stuttering during real-time preview.

Refer to [Using OHAudio for Audio Playback (C/C++)](./using-ohaudio-for-playback.md) to complete the audio playback development.

3. In the player callback function, copy the processed data to the buffer of the `OH_AudioRenderer` instance to enable real-time preview during audio playback.

   <!-- @[audioSuite_AudioRendererOnWriteData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic in actual use.
   static OH_AudioData_Callback_Result AudioRendererOnWriteData(OH_AudioRenderer *renderer, void *userData,
                                                                void *audioData, int32_t audioDataSize)
   {
       bool finishedFlag = false;
       int32_t writeSize = 0;
       OH_AudioSuite_Result result = OH_AudioSuiteEngine_RenderFrame(static_cast<OH_AudioSuitePipeline *>(userData),
                                                                     audioData, audioDataSize, &writeSize, &finishedFlag);
       if (result != OH_AudioSuite_Result::AUDIOSUITE_SUCCESS) {
           // The audio creation rendering fails.
           return AUDIO_DATA_CALLBACK_RESULT_INVALID;
       }
       // The audio creation rendering is complete.
       if (finishedFlag) {
           // Developer-defined behavior.
       }

       return AUDIO_DATA_CALLBACK_RESULT_VALID;
   }
   ```

   <!-- @[audioSuite_StartRealTimeRenderingPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value verification. Add verification logic in actual use.
   // Create the builder.
   OH_AudioStreamBuilder_Create(&rendererBuilder, OH_AudioStream_Type::AUDIOSTREAM_TYPE_RENDERER);
   OH_AudioStreamBuilder_SetSamplingRate(rendererBuilder, OH_Audio_SampleRate::SAMPLE_RATE_48000);
   OH_AudioStreamBuilder_SetChannelCount(rendererBuilder, CHANNEL_COUNT);
   OH_AudioStreamBuilder_SetSampleFormat(rendererBuilder, AUDIOSTREAM_SAMPLE_S16LE);
   OH_AudioStreamBuilder_SetEncodingType(rendererBuilder, AUDIOSTREAM_ENCODING_TYPE_RAW);
   OH_AudioStreamBuilder_SetRendererInfo(rendererBuilder, AUDIOSTREAM_USAGE_MUSIC);
   
   // If the sampling rate is 11025, use 40 ms for calculation.
   int32_t frameSize = RENDER_FRAME_DURATION_MS * audioFormatOutput.samplingRate * audioFormatOutput.channelCount *
                       SAMPLE_FORMAT_S16LE_BYTE_SIZE / MS_PER_SECOND;
   // Set the audioDataSize length (size of the data to be played).
   OH_AudioStreamBuilder_SetFrameSizeInCallback(rendererBuilder, frameSize);
   // Configure the callback for writing audio data.
   OH_AudioStreamBuilder_SetRendererWriteDataCallback(rendererBuilder, AudioRendererOnWriteData,
                                                      static_cast<void *>(audioSuitePipeline));
   
   // Start the pipeline.
   OH_AudioSuiteEngine_StartPipeline(audioSuitePipeline);
   
   // You can create a renderer stream to play audio.
   // ...
   
   // ...
   // Stop the pipeline.
   OH_AudioSuiteEngine_StopPipeline(audioSuitePipeline);
   ```

4. Destroy resources.

   <!-- @[audioSuite_DestroyRealTimeRendering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic in actual use.
   // Destroy the stream builder.
   OH_AudioStreamBuilder_Destroy(rendererBuilder);

   // Destroy the nodes.
   OH_AudioSuiteEngine_DestroyNode(inputNode);
   OH_AudioSuiteEngine_DestroyNode(eqNode);
   OH_AudioSuiteEngine_DestroyNode(outputNode);

   // Destroy the pipeline.
   OH_AudioSuiteEngine_DestroyPipeline(audioSuitePipeline);

   // Destroy the engine.
   OH_AudioSuiteEngine_Destroy(audioSuiteEngine);
   ```

## Precautions

- During real-time audio preview, you cannot create new effect nodes. You can only modify the parameters of existing effect nodes.

- For details about error codes, see [OH_AudioSuite_Result](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_result).

<!--RP1-->

## Samples

- [AudioSuiteSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)

<!--RP1End-->