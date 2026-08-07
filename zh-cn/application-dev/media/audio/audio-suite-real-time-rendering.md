# 实时预览(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API version 22开始，[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)给开发者提供音频编创的实时预览能力（API version 22只支持均衡器效果，API version 23及以后支持其他效果）。例如，可以使用均衡器中预置的音效，改变音乐的风格。

## 开发基础配置

开发者使用[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)提供的实时预览能力，添加对应的头文件。

### 在CMake脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so libohaudiosuite.so)
```

### 添加头文件
开发者通过引入头文件<[native_audio_suite_base.h](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md)>、<[native_audio_suite_engine.h](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md)>、<[native_audiostreambuilder.h](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md)>和<[native_audiorenderer.h](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md)>使用音频编创和音频播放相关API。

<!-- @[audioSuite_RealTimeRenderingInclude](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
``` C++
#include <ohaudiosuite/native_audio_suite_base.h>
#include <ohaudiosuite/native_audio_suite_engine.h>
#include <ohaudio/native_audiorenderer.h>
#include <ohaudio/native_audiostreambuilder.h>
```

## 开发步骤

### 接口调用

详细的API说明请参考[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)。

### 均衡器效果

**图1**：实时预览示意图

   ![OHAudioSuite realtime play](figures/audiosuite-audio-separation-time.png)

开发者可以通过以下步骤来实现一个简单的均衡器效果节点实时预览功能。此处以均衡器效果为例演示实时预览流程，其他效果节点的详细说明请参考[音频效果(C/C++)](audio-suite-effects.md)。

1. 在初始化时，创建[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)管线（包括输入节点、均衡器节点、输出节点）。
  
   <!-- @[audioSuite_AudioDataInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/pcm_file_utils.h) -->
   
   ``` C
   struct AudioDataInfo {
       uint8_t *buffer = nullptr;   // 音频数据。
       int32_t bufferSize = 0;      // 音频数据总大小。
       int32_t totalWriteSize = 0;  // 处理过的音频数据总大小。
       int32_t totalReadSize = 0;  // 已读取的音频数据总大小。
   };
   ```
   <!-- @[audioSuite_RealTimeRenderingInputNodeWriteDataCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
   ``` C++
   // 示例接口未包含返回值校验，实际使用时请务必添加校验逻辑。
   // 输入节点请求数据的回调函数。
   static int32_t InputNodeWriteDataCallBack(OH_AudioNode *audioNode, void *userData, void *audioData,
                                             int32_t audioDataSize, bool *finished)
   {
       if ((audioNode == nullptr) || (userData == nullptr) || (audioData == nullptr) || (audioDataSize <= 0) ||
           (finished == nullptr)) {
           return -1;
       }
   
       struct AudioDataInfo *info = static_cast<struct AudioDataInfo *>(userData);
       // 要处理的音频大小。
       int32_t actualDataSize = std::min(audioDataSize, info->bufferSize - info->totalWriteSize);
       // 将PCM音频数据写入audioData。
       if (actualDataSize > 0) {
           std::copy(info->buffer + info->totalWriteSize, info->buffer + info->totalWriteSize + actualDataSize,
                     static_cast<uint8_t *>(audioData));
       }
       info->totalWriteSize += actualDataSize;
   
       // 音频数据全部处理完。
       if (info->totalWriteSize >= info->bufferSize) {
           *finished = true;
       }
       return actualDataSize;
   }
   ```
   <!-- @[audioSuite_CreateRealTimeRendering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
   ``` C++
   // 示例接口未包含返回值校验，实际使用时请务必添加校验逻辑。
   // 创建引擎。
   OH_AudioSuiteEngine_Create(&audioSuiteEngine);
   
   // 创建实时预览的管线。
   OH_AudioSuiteEngine_CreatePipeline(audioSuiteEngine, &audioSuitePipeline,
                                      OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_REALTIME_MODE);
   // 创建节点构造器。
   OH_AudioNodeBuilder *nodeBuilder = nullptr;
   OH_AudioSuiteNodeBuilder_Create(&nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::INPUT_NODE_TYPE_DEFAULT);
   
   // 配置音频数据格式，开发者根据要处理的音频数据格式设置采样率、声道分布、声道数、位深、编码格式参数。
   OH_AudioFormat audioFormatInput;
   audioFormatInput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatInput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatInput.channelCount = CHANNEL_COUNT;
   audioFormatInput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatInput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatInput);
   // 设置音频流的回调。
   void *userData = static_cast<void *>(audioInfo);
   OH_AudioSuiteNodeBuilder_SetRequestDataCallback(nodeBuilder, InputNodeWriteDataCallBack, userData);
   // 创建输入节点。
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &inputNode);
   
   // 重置构造器配置并设置为均衡器节点类型。
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::EFFECT_NODE_TYPE_EQUALIZER);
   // 创建均衡器节点。
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &eqNode);
   // 设置均衡器节点效果为默认。
   OH_AudioSuiteEngine_SetEqualizerFrequencyBandGains(eqNode, OH_EQUALIZER_PARAM_DEFAULT);
   
   // 重置构造器配置并设置为输出节点类型。
   OH_AudioSuiteNodeBuilder_Reset(nodeBuilder);
   OH_AudioSuiteNodeBuilder_SetNodeType(nodeBuilder, OH_AudioNode_Type::OUTPUT_NODE_TYPE_DEFAULT);
   // 配置音频数据格式，开发者根据预期输出的音频格式设置采样率、声道分布、声道数、位深、编码格式参数。
   OH_AudioFormat audioFormatOutput;
   audioFormatOutput.samplingRate = OH_Audio_SampleRate::SAMPLE_RATE_48000;
   audioFormatOutput.channelLayout = OH_AudioChannelLayout::CH_LAYOUT_STEREO;
   audioFormatOutput.channelCount = CHANNEL_COUNT;
   audioFormatOutput.sampleFormat = OH_Audio_SampleFormat::AUDIO_SAMPLE_S16LE;
   audioFormatOutput.encodingType = OH_Audio_EncodingType::AUDIO_ENCODING_TYPE_RAW;
   OH_AudioSuiteNodeBuilder_SetFormat(nodeBuilder, audioFormatOutput);
   // 创建输出节点。
   OH_AudioSuiteEngine_CreateNode(audioSuitePipeline, nodeBuilder, &outputNode);
   
   // 销毁节点构造器。
   OH_AudioSuiteNodeBuilder_Destroy(nodeBuilder);
   
   // 连接各个节点组成组网。
   OH_AudioSuiteEngine_ConnectNodes(inputNode, eqNode);
   OH_AudioSuiteEngine_ConnectNodes(eqNode, outputNode);
   ```


   > **注意：** 
   >
   > 离线编辑和实时预览在创建管线时有区别。
   > + 实时预览：OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_REALTIME_MODE
   > + 离线编辑：OH_AudioSuite_PipelineWorkMode::AUDIOSUITE_PIPELINE_EDIT_MODE


2. 创建[OH_AudioRendererStruct](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorendererstruct.md)实例，并在其`AudioRendererOnWriteData()`回调函数中调用[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)管线的[OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe)接口来处理数据。

   > **注意：**
   >
   > [OH_AudioSuiteEngine_RenderFrame()](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuiteengine_renderframe)接口的处理时长和管线中连接的效果节点数量有关，需要注意接口处理时长，以避免实时预览卡顿。

   请参考[使用OHAudio开发音频播放功能(C/C++)](./using-ohaudio-for-playback.md)完成音频播放功能开发。


3. 在播放器的回调函数中，将处理后的数据复制到OH_AudioRenderer实例的缓冲区中，实现音频播放过程中实时预览。
 
   <!-- @[audioSuite_AudioRendererOnWriteData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
   ``` C++
   // 示例接口未包含返回值校验，实际使用时请务必添加校验逻辑。
   static OH_AudioData_Callback_Result AudioRendererOnWriteData(OH_AudioRenderer *renderer, void *userData,
                                                                void *audioData, int32_t audioDataSize)
   {
       bool finishedFlag = false;
       int32_t writeSize = 0;
       OH_AudioSuite_Result result = OH_AudioSuiteEngine_RenderFrame(static_cast<OH_AudioSuitePipeline *>(userData),
                                                                     audioData, audioDataSize, &writeSize, &finishedFlag);
       if (result != OH_AudioSuite_Result::AUDIOSUITE_SUCCESS) {
           // 音频编创渲染失败。
           return AUDIO_DATA_CALLBACK_RESULT_INVALID;
       }
       // 音频编创渲染完成。
       if (finishedFlag) {
           // 开发者自定义的行为。
       }
   
       return AUDIO_DATA_CALLBACK_RESULT_VALID;
   }
   ```
   <!-- @[audioSuite_StartRealTimeRenderingPipeline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
   ``` C++
   // 示例接口未包含返回值校验，实际使用时请务必添加校验逻辑。
   // 创建构建器。
   OH_AudioStreamBuilder_Create(&rendererBuilder, OH_AudioStream_Type::AUDIOSTREAM_TYPE_RENDERER);
   OH_AudioStreamBuilder_SetSamplingRate(rendererBuilder, OH_Audio_SampleRate::SAMPLE_RATE_48000);
   OH_AudioStreamBuilder_SetChannelCount(rendererBuilder, CHANNEL_COUNT);
   OH_AudioStreamBuilder_SetSampleFormat(rendererBuilder, AUDIOSTREAM_SAMPLE_S16LE);
   OH_AudioStreamBuilder_SetEncodingType(rendererBuilder, AUDIOSTREAM_ENCODING_TYPE_RAW);
   OH_AudioStreamBuilder_SetRendererInfo(rendererBuilder, AUDIOSTREAM_USAGE_MUSIC);
   
   // 如果samplingRate为11025请使用40ms来计算。
   int32_t frameSize = RENDER_FRAME_DURATION_MS * audioFormatOutput.samplingRate * audioFormatOutput.channelCount *
                       SAMPLE_FORMAT_S16LE_BYTE_SIZE / MS_PER_SECOND;
   // 设置audioDataSize长度（待播放的数据大小）。
   OH_AudioStreamBuilder_SetFrameSizeInCallback(rendererBuilder, frameSize);
   // 配置写入音频数据回调函数。
   OH_AudioStreamBuilder_SetRendererWriteDataCallback(rendererBuilder, AudioRendererOnWriteData,
                                                      static_cast<void *>(audioSuitePipeline));
   
   // 启动管线。
   OH_AudioSuiteEngine_StartPipeline(audioSuitePipeline);
   
   // 开发者可以自行创建renderer流，播放音频。
   // ...
   
   // ...
   // 停止管线。
   OH_AudioSuiteEngine_StopPipeline(audioSuitePipeline);
   ```

4. 资源销毁。

   <!-- @[audioSuite_DestroyRealTimeRendering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/real_time_rendering.cpp) -->
   
   ``` C++
   // 示例接口未包含返回值校验，实际使用时请务必添加校验逻辑。
   // 销毁流构造器。
   OH_AudioStreamBuilder_Destroy(rendererBuilder);
   
   // 销毁节点。
   OH_AudioSuiteEngine_DestroyNode(inputNode);
   OH_AudioSuiteEngine_DestroyNode(eqNode);
   OH_AudioSuiteEngine_DestroyNode(outputNode);
   
   // 销毁管线。
   OH_AudioSuiteEngine_DestroyPipeline(audioSuitePipeline);
   
   // 销毁引擎。
   OH_AudioSuiteEngine_Destroy(audioSuiteEngine);
   ```

## 注意事项

- 音频实时预览过程中，不支持重新创建新的效果节点，只支持修改效果节点的参数。

- 音频编创错误码具体报错信息请参考：[OH_AudioSuite_Result](../../reference/apis-audio-kit/capi-native-audio-suite-base-h.md#oh_audiosuite_result)。

<!--RP1-->
## 完整示例代码

- [音频编创示例代码](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSuiteSample)
<!--RP1End-->
