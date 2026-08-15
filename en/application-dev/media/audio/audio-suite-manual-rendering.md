# Offline Editing (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=7916f8e417a52f266eb8609e7aa226ddb0132eda translatedAt=2026-08-15T01:56:16.767Z pushedAt=2026-08-15T08:59:33.475Z -->

Starting from API version 22, [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md) provides offline audio editing capability, allowing you to process audio data in non-real-time preview scenarios. You can combine multiple audio nodes to implement complex audio processing pipelines.

## Basic Development Configuration

To use the offline editing capabilities provided by [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md), add the corresponding header files.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudiosuite.so)
```

### Adding Header Files

To use APIs related to audio creation, include the <[native_audio_suite_base.h](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md)> and <[native_audio_suite_engine.h](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md)> header files.

<!-- @[audioSuite_ManualRenderingInclude](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

``` C++
#include <ohaudiosuite/native_audio_suite_base.h>
#include <ohaudiosuite/native_audio_suite_engine.h>
```

## How to Develop

For details on the APIs, see [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md).

This section describes how to implement offline audio editing.

### Specifying the Audio Node Type

Call [OH_AudioSuiteNodeBuilder_SetNodeType()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_setnodetype) to specify the [OH_AudioNode_Type](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audionode_type) based on the service scenario.

### Specifying the Audio Node Format

Based on your service scenario, call [OH_AudioSuiteNodeBuilder_SetFormat()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_setformat) or [OH_AudioSuiteEngine_SetAudioFormat()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_setaudioformat) to set the audio format, including bit depth ([OH_Audio_SampleFormat](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_sampleformat)), sample rate ([OH_Audio_SampleRate](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audio_samplerate)), and channel count ([OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout)).

### Basic Offline Editing

Use an effect node (such as an equalizer effect node) to process the input PCM (Pulse Code Modulation) audio data and output PCM audio data with the corresponding sound effect. This section uses the equalizer effect as an example to demonstrate the offline editing process. For details about other effect nodes, see [Audio Effects (C/C++)](audio-suite-effects.md).

**Figure 1** Basic offline editing

![single_in_single_out](figures/audiosuite-eq-edit.png)

1. Create an engine and pipeline.

   <!-- @[audioSuite_CreateEngineAndPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample code does not include return value verification. Add verification logic when using in production.
   // Create an engine.
   OH_AudioSuiteEngine *audioSuiteEngine = nullptr;
   OH_AudioSuiteEngine_Create(&audioSuiteEngine);

   // Create a pipeline.
   OH_AudioSuitePipeline *audioSuitePipeline = nullptr;
   OH_AudioSuiteEngine_CreatePipeline(audioSuiteEngine, &audioSuitePipeline,
                                      OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_EDIT_MODE);
   ```

2. Create input, output, and equalizer nodes and connect them.

   To create an input node, implement a custom callback function **InputNodeWriteDataCallBack** of the type [OH_InputNode_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_inputnode_requestdatacallback), and set the callback function using [OH_AudioSuiteNodeBuilder_SetRequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_setrequestdatacallback).

   <!-- @[audioSuite_AudioDataInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/pcm_file_utils.h) -->

   ``` C
   struct AudioDataInfo {
       uint8_t *buffer = nullptr;   // Audio data.
       int32_t bufferSize = 0;      // Total size of the audio data.
       int32_t totalWriteSize = 0;  // Total size of the processed audio data.
       int32_t totalReadSize = 0;  // Total size of the audio data that has been read.
   };
   ```

   <!-- @[audioSuite_InputNodeWriteDataCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Callback function for the input node to request data.
   static int32_t InputNodeWriteDataCallBack(OH_AudioNode *audioNode, void *userData, void *audioData,
                                             int32_t audioDataSize, bool *finished)
   {
       if ((audioNode == nullptr) || (userData == nullptr) || (audioData == nullptr) || (audioDataSize <= 0) ||
           (finished == nullptr)) {
           return -1;
       }
       struct AudioDataInfo *info = static_cast<struct AudioDataInfo *>(userData);
       // Size of the audio to be processed.
       int32_t actualDataSize = std::min(audioDataSize, info->bufferSize - info->totalWriteSize);
       // Write PCM audio data to audioData.
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

   <!-- @[audioSuite_CreateBaseNodeOne](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Create a node builder.
   OH_AudioNodeBuilder *nodeBuilder = nullptr;
   OH_AudioSuiteNodeBuilder_Create(&nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the audio data format to be processed.
   OH_AudioFormat audioFormatInput;
   audioFormatInput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatInput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatInput.channelCount = CHANNEL_COUNT;
   audioFormatInput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatInput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   // Set the callback for the audio stream.
   void *userData = static_cast<void *>(audioInfo);
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   // Create an input node.
   OH_AudioSuiteEngine_CreateNode(audioSuiteEngine, nodeBuilder, &nodes.inputNode);
   
   // Reset the builder configuration and create an effect node.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   // Different effect node types can be set as needed.
   ```

   Set the equalizer effect.

   <!-- @[audioSuite_SetEqualizerType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/audio_effect/audio_effect.h) -->

   ``` C
   // Set to the equalizer node type.
   OH_AudioSuiteNodeBuilder_SetNodeType(builder, OH_AudioNode_Type::EFFECT_NODE_TYPE_EQUALIZER);
   // Create an equalizer node.
   OH_AudioSuiteEngine_CreateNode(pipeline, builder, node);
   // ...
   // Set the equalizer node effect.
   OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(*node, gains);
   ```

   <!-- @[audioSuite_CreateBaseNodeTwo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // Reset the builder configuration and set to the output node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::OUTPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the expected output audio format.
   OH_AudioFormat audioFormatOutput;
   audioFormatOutput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatOutput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatOutput.channelCount = CHANNEL_COUNT;
   audioFormatOutput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatOutput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatOutput);
   // Create an output node.
   OH_AudioSuiteEngine_CreateNode(audioSuiteEngine, nodeBuilder, &nodes.outputNode);
   
   // Destroy the node builder.
   OH_AudioSuiteNodeBuilder_Destroy(nodeBuilder);
   
   // Connect the nodes to form a network.
   OH_AudioSuiteEngine_ConnectNodes(nodes.inputNode, nodes.eqNode);
   OH_AudioSuiteEngine_ConnectNodes(nodes.eqNode, nodes.outputNode);
   ```

3. Render audio data.

   Call [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe) to render and obtain PCM audio data.

   <!-- @[audioSuite_StartBasePipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic in actual use.
   // Calculate the single-frame processing data size based on the output node format. If samplingRate is 11025, use 40 ms for calculation.
   int32_t frameSize = RENDER_FRAME_DURATION_MS * OH_Audio_SampleRate::SAMPLE_RATE_48000 * CHANNEL_COUNT *
                       SAMPLE_FORMAT_S16LE_BYTE_SIZE / MS_PER_SECOND;
   // Buffer used to receive the output audio data after rendering.
   uint8_t *audioData = (uint8_t *)malloc(frameSize);
   int32_t responseSize = 0;
   bool finished = false;
   // Start rendering.
   OH_AudioSuiteEngine_StartPipeline(audioSuitePipeline);
   // ...
   do {
       OH_AudioSuite_Result result = OH_AudioSuiteEngine_RenderFrame(
           audioSuitePipeline, static_cast<void *>(audioData), frameSize, &responseSize, &finished);
       if ((result != OH_AudioSuite_Result::AUDIOSUITE_SUCCESS) || (responseSize <= 0)) {
           // The audio creation rendering fails.
           break;
       } else {
           // audioData is the rendered audio data. responseSize is the audio data length. You can use or save it as required.
           // ...
       }
   } while (!finished);
   // ...
   OH_AudioSuiteEngine_StopPipeline(audioSuitePipeline);
   free(audioData);
   audioData = nullptr;
   ```

4. Destroy resources.

   <!-- @[audioSuite_DestroyBase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic in actual use.
   // Destroy the node.
   OH_AudioSuiteEngine_DestroyNode(nodes.inputNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.eqNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.outputNode);
   
   // Destroy the pipeline.
   OH_AudioSuiteEngine_DestroyPipeline(audioSuitePipeline);
   
   // Destroy the engine.
   OH_AudioSuiteEngine_Destroy(audioSuiteEngine);
   ```

### Source Separation

Use a source separation node to separate input PCM audio data into vocal and background tracks, and then use an output node to output these tracks separately.

Before creating a source separation node, call [OH_AudioSuiteEngine_IsNodeTypeSupported()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_isnodetypesupported) to check whether the node type is supported to avoid node creation failure.

**Figure 2** Source separation editing

![single_in_multi_out](figures/audiosuite-audio-separation-edit.png)

The sample code is as follows:

1. Create an engine and pipeline.

   <!-- @[audioSuite_CreateSeparationEngineAndPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic in actual use.
   // Create an engine.
   OH_AudioSuiteEngine *audioSuiteEngine = nullptr;
   OH_AudioSuiteEngine_Create(&audioSuiteEngine);

   // Create a pipeline.
   OH_AudioSuitePipeline *audioSuitePipeline = nullptr;
   OH_AudioSuiteEngine_CreatePipeline(audioSuiteEngine, &audioSuitePipeline,
                                      OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_EDIT_MODE);
   ```

2. Create input, output, and source separation nodes and connect them.

   To create an input node, implement a custom callback function **InputNodeWriteDataCallBack** of the type [OH_InputNode_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_inputnode_requestdatacallback), and set the callback function using [OH_AudioSuiteNodeBuilder_SetRequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuitenodebuilder_setrequestdatacallback).

   <!-- @[audioSuite_AudioDataInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/pcm_file_utils.h) -->

   ``` C
   struct AudioDataInfo {
       uint8_t *buffer = nullptr;   // Audio data.
       int32_t bufferSize = 0;      // Total size of the audio data.
       int32_t totalWriteSize = 0;  // Total size of the processed audio data.
       int32_t totalReadSize = 0;  // Total size of the read audio data.
   };
   ```

   <!-- @[audioSuite_InputNodeWriteDataCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Callback function for the input node to request data.
   static int32_t InputNodeWriteDataCallBack(OH_AudioNode *audioNode, void *userData, void *audioData,
                                             int32_t audioDataSize, bool *finished)
   {
       if ((audioNode == nullptr) || (userData == nullptr) || (audioData == nullptr) || (audioDataSize <= 0) ||
           (finished == nullptr)) {
           return -1;
       }
       struct AudioDataInfo *info = static_cast<struct AudioDataInfo *>(userData);
       // Size of the audio to be processed.
       int32_t actualDataSize = std::min(audioDataSize, info->bufferSize - info->totalWriteSize);
       // Write PCM audio data to audioData.
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

   <!-- @[audioSuite_IsSupportedSeparationNode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // Determine whether the source separation node is supported.
   bool isSupported = false;
   OH_AudioSuiteEngine_IsNodeTypeSupported(OH_AudioNode_Type::EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION,
                                           &isSupported);
   if (!isSupported) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, GLOBAL_RESMGR, TAG, "Audio separation node is not supported on this device.");
       nodes.isNodeSupported = false;
       return nodes;
   }
   ```

   <!-- @[audioSuite_CreateSeparationNode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Create a node builder.
   OH_AudioNodeBuilder *nodeBuilder = nullptr;
   OH_AudioSuiteNodeBuilder_Create(&nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the audio data format to be processed.
   OH_AudioFormat audioFormatInput;
   audioFormatInput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatInput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatInput.channelCount = CHANNEL_COUNT;
   audioFormatInput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatInput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   void *userData = static_cast<void *>(audioInfo);
   // Set the callback for the audio stream.
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   
   // Create an input node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.inputNode);
   
   // Reset the builder configuration and set to the audio source separation node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder,
                                        OH_AudioNode_Type::EFFECT_MULTII_OUTPUT_NODE_TYPE_AUDIO_SEPARATION);
   
   // Create an audio source separation node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.aissNode);
   
   // Reset the builder configuration and set to the output node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::OUTPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the expected output audio format.
   OH_AudioFormat audioFormatOutput;
   audioFormatOutput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatOutput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatOutput.channelCount = CHANNEL_COUNT;
   audioFormatOutput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatOutput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatOutput);
   
   // Create an output node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.outputNode);
   
   // Destroy the node builder.
   OH_AudioSuiteNodeBuilder_Destroy(nodeBuilder);
   
   // Connect the nodes to form a network.
   OH_AudioSuiteEngine_ConnectNodes(nodes.inputNode, nodes.aissNode);
   OH_AudioSuiteEngine_ConnectNodes(nodes.aissNode, nodes.outputNode);
   ```

3. Render audio data.

   For the pipeline that contains the source separation node, use [OH_AudioSuiteEngine_MultiRenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_multirenderframe) to render and obtain two streams of PCM audio data.

   <!-- @[audioSuite_StartSeparationPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Calculate the single-frame processing data size based on the output node format. If samplingRate is 11025, use 40ms for calculation.
   int32_t frameSize = RENDER_FRAME_DURATION_MS * OH_Audio_SampleRate::SAMPLE_RATE_48000 * CHANNEL_COUNT *
                       SAMPLE_FORMAT_S16LE_BYTE_SIZE / MS_PER_SECOND;
   // Buffer used to receive the output audio data after rendering.
   OH_AudioDataArray audioDataArray;
   int32_t outputNum = 2;
   audioDataArray.audioDataArray = (void **)malloc(outputNum * sizeof(void *));
   for (int32_t i = 0; i < outputNum; i++) {
       audioDataArray.audioDataArray[i] = (void *)malloc(frameSize);
   }
   audioDataArray.arraySize = outputNum;
   audioDataArray.requestFrameSize = frameSize;
   int32_t responseSize = 0;
   bool finished = false;

   // Start rendering.
   OH_AudioSuiteEngine_StartPipeline(audioSuitePipeline);
   // ...
   do {
       OH_AudioSuite_Result result =
           OH_AudioSuiteEngine_MultiRenderFrame(audioSuitePipeline, &audioDataArray, &responseSize, &finished);
       if ((result != OH_AudioSuite_Result::AUDIOSUITE_SUCCESS) || (responseSize <= 0)) {
           // The audio creation rendering fails.
           break;
       } else {
           // audioDataArray.audioDataArray[0] is the extracted vocal track.
           // audioDataArray.audioDataArray[1] is the extracted background track.
           // responseSize is the audio data length. You can use or save it as required.
           // ...
       }
   } while (!finished);
   // ...
   OH_AudioSuiteEngine_StopPipeline(audioSuitePipeline);

   for (int32_t i = 0; i < outputNum; i++) {
       free(audioDataArray.audioDataArray[i]);
       audioDataArray.audioDataArray[i] = nullptr;
   }
   free(audioDataArray.audioDataArray);
   audioDataArray.audioDataArray = nullptr;
   ```

4. Destroy resources.

   <!-- @[audioSuite_DestroySeparation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample code does not include return value verification. Add verification logic in actual use.
   // Destroy the nodes.
   OH_AudioSuiteEngine_DestroyNode(nodes.inputNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.aissNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.outputNode);

   // Destroy the pipeline.
   OH_AudioSuiteEngine_DestroyPipeline(audioSuitePipeline);

   // Destroy the engine.
   OH_AudioSuiteEngine_Destroy(audioSuiteEngine);
   ```

### Mixing and Cascading

Input multiple PCM audio data streams, mix them using an audio mixer node, and output the mixed PCM audio data.

**Figure 3** Cascading editing

![multi_in_single_out](figures/audiosuite-mix-edit.png)

The sample code is as follows:

1. Create an engine and pipeline.

   <!-- @[audioSuite_CreateMixingEngineAndPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Add validation logic when using it in practice.
   // Create an engine.
   OH_AudioSuiteEngine *audioSuiteEngine = nullptr;
   OH_AudioSuiteEngine_Create(&audioSuiteEngine);

   // Create a pipeline.
   OH_AudioSuitePipeline *audioSuitePipeline = nullptr;
   OH_AudioSuiteEngine_CreatePipeline(audioSuiteEngine, &audioSuitePipeline,
                                      OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_EDIT_MODE);
   ```

2. Create input, output, and effect nodes and connect them.

   The audio mixing functionality has multiple input nodes. You need to set the **userData** parameter in the callback function **InputNodeWriteDataCallBack** to distinguish between multiple input nodes, thereby enabling the input of multiple PCM audio data streams. The **InputNodeWriteDataCallBack** function type is [OH_InputNode_RequestDataCallback()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_inputnode_requestdatacallback).

   <!-- @[audioSuite_AudioDataInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/pcm_file_utils.h) -->

   ``` C
   struct AudioDataInfo {
       uint8_t *buffer = nullptr;   // Audio data.
       int32_t bufferSize = 0;      // Total size of the audio data.
       int32_t totalWriteSize = 0;  // Total size of the processed audio data.
       int32_t totalReadSize = 0;  // Total size of the audio data that has been read.
   };
   ```

   <!-- @[audioSuite_InputNodeWriteDataCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Callback function for the input node to request data.
   static int32_t InputNodeWriteDataCallBack(OH_AudioNode *audioNode, void *userData, void *audioData,
                                             int32_t audioDataSize, bool *finished)
   {
       if ((audioNode == nullptr) || (userData == nullptr) || (audioData == nullptr) || (audioDataSize <= 0) ||
           (finished == nullptr)) {
           return -1;
       }
       struct AudioDataInfo *info = static_cast<struct AudioDataInfo *>(userData);
       // Size of the audio to be processed.
       int32_t actualDataSize = std::min(audioDataSize, info->bufferSize - info->totalWriteSize);
       // Write PCM audio data to audioData.
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

   <!-- @[audioSuite_CreateMixingNode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample API does not include return value validation. Be sure to add validation logic in actual use.
   // Create a node builder.
   OH_AudioNodeBuilder *nodeBuilder = nullptr;
   OH_AudioSuiteNodeBuilder_Create(&nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the audio data format to be processed.
   OH_AudioFormat audioFormatInput;
   audioFormatInput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatInput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatInput.channelCount = CHANNEL_COUNT;
   audioFormatInput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatInput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   // Set the callback for the first audio stream.
   void *userData = static_cast<void *>(audioInfoForField);
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   // Create the first input node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.inputNodeForField);
   
   // Reset the builder configuration and set to the input node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   // Set the callback for the second audio stream.
   userData = static_cast<void *>(audioInfoForMix);
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   // Create the second input node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.inputNodeForMix);
   
   // Reset the builder configuration and set to the sound field node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::EFFECT_NODE_TYPE_SOUND_FIELD);
   // Create a sound field node and set the sound field mode to listening.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.fieldNode);
   OH_AudioSuiteEngine_SetSoundFieldType(nodes.fieldNode, SOUND_FIELD_FRONT_FACING);
   
   // Reset the builder configuration and set to the mixer node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::EFFECT_NODE_TYPE_AUDIO_MIXER);
   // Create a mixer node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.mixerNode);
   
   // Reset the builder configuration and set to the output node type.
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::OUTPUT_NODE_TYPE_DEFAULT);
   // Configure the audio data format. Set the sample rate, channel layout, channel count, bit depth, and encoding format parameters based on the expected output audio format.
   OH_AudioFormat audioFormatOutput;
   audioFormatOutput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatOutput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatOutput.channelCount = CHANNEL_COUNT;
   audioFormatOutput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatOutput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatOutput);
   // Create an output node.
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &nodes.outputNode);
   
   // Destroy the output node builder.
   OH_AudioSuiteNodeBuilder_Destroy(nodeBuilder);
   
   // Connect the nodes to form a network.
   OH_AudioSuiteEngine_ConnectNodes(nodes.inputNodeForField, nodes.fieldNode);
   OH_AudioSuiteEngine_ConnectNodes(nodes.fieldNode, nodes.mixerNode);
   OH_AudioSuiteEngine_ConnectNodes(nodes.inputNodeForMix, nodes.mixerNode);
   OH_AudioSuiteEngine_ConnectNodes(nodes.mixerNode, nodes.outputNode);
   ```

3. Render audio data.

   Call [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe) to render and obtain PCM audio data.

   <!-- @[audioSuite_StartMixingPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample code does not include return value validation. Ensure to add validation logic in actual use.
   // Calculate the single-frame processing data size based on the output node format. If the samplingRate is 11025, use 40 ms for calculation.
   int32_t frameSize = RENDER_FRAME_DURATION_MS * OH_Audio_SampleRate::SAMPLE_RATE_48000 * CHANNEL_COUNT *
                       SAMPLE_FORMAT_S16LE_BYTE_SIZE / MS_PER_SECOND;
   // Buffer used to receive the output audio data after rendering.
   uint8_t *audioData = (uint8_t *)malloc(frameSize);
   int32_t responseSize = 0;
   bool finished = false;

   // Start rendering.
   OH_AudioSuiteEngine_StartPipeline(audioSuitePipeline);
   // ...
   do {
       OH_AudioSuite_Result result = OH_AudioSuiteEngine_RenderFrame(
           audioSuitePipeline, static_cast<void *>(audioData), frameSize, &responseSize, &finished);
       if ((result != OH_AudioSuite_Result::AUDIOSUITE_SUCCESS) || (responseSize <= 0)) {
           // The audio creation rendering fails.
           break;
       } else {
           // audioData is the rendered audio data. responseSize is the audio data length. You can use or save it as required.
           // ...
       }
   } while (!finished);
   // ...
   OH_AudioSuiteEngine_StopPipeline(audioSuitePipeline);
   free(audioData);
   audioData = nullptr;
   ```

4. Destroy resources.

   <!-- @[audioSuite_DestroyMixing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/manual_rendering.cpp) -->

   ``` C++
   // The sample code does not include return value validation. Add validation logic in actual use.
   // Destroy the nodes.
   OH_AudioSuiteEngine_DestroyNode(nodes.inputNodeForMix);
   OH_AudioSuiteEngine_DestroyNode(nodes.inputNodeForField);
   OH_AudioSuiteEngine_DestroyNode(nodes.fieldNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.mixerNode);
   OH_AudioSuiteEngine_DestroyNode(nodes.outputNode);

   // Destroy the pipeline.
   OH_AudioSuiteEngine_DestroyPipeline(audioSuitePipeline);

   // Destroy the engine.
   OH_AudioSuiteEngine_Destroy(audioSuiteEngine);
   ```

<!--RP1-->

## Samples

- [AudioSuiteSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)

<!--RP1End-->