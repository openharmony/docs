# 播放无声定位指导

 <!--Kit: Audio Kit-->
 <!--Subsystem: Multimedia-->
 <!--Owner: @boxwell-->
 <!--Designer: @magekkkk-->
 <!--Tester: @Filger-->
 <!--Adviser: @w_Machine_cc-->

开发者在实现音频播放功能时，可能会遇到创建或启动播放实例失败、播放无声等问题。本文将介绍播放无声场景的常见现象、相关背景知识以及定位方法，并给出可直接对照的示例代码和定位流程。

## 问题现象

进行应用播放时，常见的无声情况表现如下：

- 启动播放后始终无声。
- 启动播放后有声，一段时间后突然无声。
- 启动播放后有声，进行前后台操作、设备切换、多音频并发等操作后无声。

## 问题原因

**1. 播放实例创建失败。**

   开发者需参考当前系统[支持的音频格式](audio-kit-intro.md#支持的音频格式)进行参数设置，并合理规划播放实例的生命周期。若开发者设置无效的参数，或当前应用/系统超过了最大可创建实例数，都会导致实例创建失败。

**2. 播放实例不在运行态。**

   播放场景下，应用除了要关注`OH_AudioRenderer_Start`接口是否成功，还需要同时关注状态变化、输出设备信息以及播放流变化信息。若未正确处理这些信息，可能会导致 “多音频场景下被其他音频流打断后无声”、“设备断开后无声”等现象。

**3. 应用音频数据传递异常。**

   当前系统侧通常按流式传输的方式，通过`OH_AudioRenderer_OnWriteDataCallback`回调逐帧从应用侧获取音频数据。若应用错误传递无声数据，或阻塞当前的回调函数，会导致整个音频链路播放异常，造成无声。

**4. 音量被设置为极小值或0。**

   当流或系统的音量被设置为极小值或0时，整机会表现为无声。此外一些特殊的场景，例如免打扰模式、静音模式下，铃音、通知类型的流也会表现为无声。

**5. 未接入长时任务或并发管控限制。**

   系统中存在长时任务权限、并发管控等多种限制以避免应用对系统资源的滥用、优化系统音频体验。若未正确接入长时任务或处理并发任务，会导致退后台、熄屏、被其他音频流打断后无声等现象。

## 问题定位流程

建议按照以下顺序逐步排查。每一步先确认一个可观察结果，再根据结果进入下一步或跳转到对应文档。

1. 确认播放实例创建情况。

   检查项如下：

   - 参数配置：确认采样率、声道数、采样格式、编码格式和`StreamUsage`符合业务场景。可参考当前系统[支持的音频格式](audio-kit-intro.md#支持的音频格式)进行参数设置。
   - 创建结果：确认`OH_AudioStreamBuilder_GenerateRenderer`已成功返回播放实例。如果创建失败，先根据错误码和日志排查权限、参数配置和并发场景。
   - 异常频繁创建：系统内部的资源是有限的，应用无限制地创建音频流会将整个系统的资源占满；因此当应用创建的音频流超过一定的限度时，系统会阻止应用持续创建音频流。开发者在确认当前音频流不再使用后，请及时调用`OH_AudioStreamBuilder_Destroy`接口进行音频资源的释放。

   可参考以下示例进行音频参数的设置。
   
   <!-- @[Render_ConfigStream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->
   
   ``` C++
   // 设置音频采样率。
   // 从API版本26.0.0开始：音频渲染扩展支持8000Hz到384000Hz范围内以10Hz为步长的采样率值。具体设备支持的采样率规格会存在差异。
   const int SAMPLING_RATE_48K = 48000;
   OH_AudioStreamBuilder_SetSamplingRate(builder, SAMPLING_RATE_48K);
   // 设置音频声道。
   const int channelCount = 2;
   OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
   // 设置音频采样格式。
   OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
   // 设置音频流的编码类型。
   OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
   // 设置输出音频流的工作场景。
   OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
   ```
   
2. 确认播放实例是否为运行状态。

   检查项如下：

   - `start`结果：确认`OH_AudioRenderer_Start`接口调用成功。
   - 当前状态：开发者可调用`OH_AudioRenderer_GetCurrentState`获取当前音频流状态。
   - 状态变化：如果状态没有进入`STATE_RUNNING`，打印当前状态，并检查调用`OH_AudioRenderer_Start`启动实例前，状态是否为`STATE_PREPARED`、`STATE_PAUSED`或`STATE_STOPPED`。如果在非上述状态下启动实例，也会导致启动失败。
   - 提前释放：确认在启动实例后，没有调用`OH_AudioRenderer_Pause`、`OH_AudioRenderer_Stop`或`OH_AudioRenderer_Release`将实例转换为非运行状态。
   
3. 如果没有收到`OH_AudioRenderer_OnWriteDataCallback`播放数据回调，请检查回调注册和对象生命周期。

   检查项如下：

   - 注册时机：确认在播放实例创建成功后调用`OH_AudioStreamBuilder_SetRendererWriteDataCallback`注册回调。
   - 运行状态：确认播放实例已进入`STATE_RUNNING`。
   - 对象生命周期：如果已经为运行态但是没有收到回调，确认播放实例没有被页面生命周期、路由切换或业务清理逻辑提前释放。
   - 回调耗时：确认没有在`OH_AudioRenderer_OnWriteDataCallback`回调中执行复杂音效处理、大文件写入合并等耗时任务或长时间不返回，避免阻塞下一次数据回调。
   
   回调注册可参考AudioRendererSampleC页面代码中的`SetRendererWriteDataCallback`。
   <!-- @[Render_SetRendererWriteDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->
   
   ``` C++
   // 自定义写入数据函数。
   static OH_AudioData_Callback_Result MyOnWriteData_New(
       OH_AudioRenderer* renderer,
       void* userData,
       void* audioData,
       int32_t audioDataSize)
   {
       // 将待播放的数据，按audioDataSize长度写入audioData。
       // 如果开发者不希望播放某段audioData，返回AUDIO_DATA_CALLBACK_RESULT_INVALID即可。
       size_t readCount = fread(audioData, audioDataSize, 1, g_fp);
       if (readCount == 0) {
           return AUDIO_DATA_CALLBACK_RESULT_INVALID;
       }
       if (feof(g_fp)) {
           fseek(g_fp, 0, SEEK_SET);
       }
       return AUDIO_DATA_CALLBACK_RESULT_VALID;
   }
   // ...
       // 配置写入音频数据回调函数。
       OH_AudioRenderer_OnWriteDataCallback writeDataCb = MyOnWriteData_New;
       OH_AudioStreamBuilder_SetRendererWriteDataCallback(builder, writeDataCb, nullptr);
   ```
   
4. 如果收到`OH_AudioRenderer_OnWriteDataCallback`回调，并按正常周期写入数据但播放无声，检查数据写入和解析逻辑。

   检查项如下：

   - 数据生成：确认音源数据流正常生成，在收到播放回调时有充足的数据支撑写入操作。
   - 数据写入：确认写入时从`audioData`的首地址开始写入音频数据，并且正确地写入到返回的Buffer内存中，避免重复覆盖同一段数据。
   - 写入长度：确认写入长度与`OH_AudioRenderer_OnWriteDataCallback`回调中的`audioDataSize`一致，避免只写入部分数据或未写入数据。
   - 数据生命周期：音频播放采用流式传输的模式，请勿在回调函数中执行阻塞式操作或过于耗时的算法处理（建议单次耗时不超过15ms），避免因当次回调长时间未返回导致系统侧无数据可播放。同时在回调返回后，请勿保存`audioData`的地址并做其他内存处理操作，以避免系统读取到非预期的数据。
   - 返回长度：在无法填满回调所需长度数据的情况下，建议开发者返回`AUDIO_DATA_CALLBACK_RESULT_INVALID`。此时系统不会处理该段音频数据，会再次向应用请求数据。如果在`audioData`数据未写入的情况下返回`AUDIO_DATA_CALLBACK_RESULT_VALID`，也会导致无声问题。
   
5. 如果回调写入数据正常，但播放持续无声，请检查当前系统设置。

   检查项如下：

   - 音量设置：开发者可通过`OH_AudioRenderer_GetVolume`接口查询当前音频流的音量，也可通过`OH_AudioVolumeManager_OnStreamVolumeChangeCallback`监听当前音频流的音量变化，以确认当前是否存在音量值过小或异常的静音操作。
   - 进入免打扰模式：在免打扰模式下，若开发者设置的音频流类型为铃音、通知类型，系统会将其静音播放。开发者可参考[@ohos.intelligentScene (情景模式)](../../reference/apis-basic-services-kit/js-apis-intelligentScene.md)查询系统的免打扰功能是否开启、应用自身是否允许打扰等。
   - 前后台（亮屏息屏）播放差异：系统内部存在功耗策略，当应用未申请长时任务即切换到后台时，会导致无声。如果发现应用在前台/亮屏时播放正常，后台/灭屏时出现持续无声的情况，请检查应用是否接入AVSession或申请[长时任务(ArkTS)](../../task-management/continuous-task.md)。详细的适配指南可参考[应用接入AVSession场景介绍](../avsession/avsession-access-scene.md)和[后台播放](../avsession/avsession-background-scene.md)。


6. 如果问题与外设操作或并发场景相关，请检查输出设备和并发播放策略。

   检查项如下：

   - 设备切换：确认播放开始前后是否发生蓝牙耳机、有线耳机等设备切换，并针对回调函数做了音频流处理；例如在蓝牙设备断连时发送了设备变更回调，应用自行暂停了音频流等。
   - 并发策略：确认当前设备上是否存在其他音频任务。如果业务与VoIP通话、蜂窝通话、闹钟、语音消息等场景并发后无声，可参考[音频焦点介绍](audio-playback-concurrency.md)确认系统侧的音频策略，同时参考[处理音频焦点变化](audio-playback-concurrency.md#处理音频焦点变化)，确认正确处理了焦点回调。
   

## 相关文档参考

- 使用OHAudio播放的示例代码，请参考[推荐使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)。
- 使用AudioRenderer播放的示例代码，请参考[使用AudioRenderer开发音频播放功能(ArkTs)](using-audiorenderer-for-playback.md)。
- 如果问题与其他音频任务并发有关，优先参考[音频焦点介绍](audio-playback-concurrency.md)，同时参考[处理音频焦点变化](audio-playback-concurrency.md#处理音频焦点变化)。
- 后台播放适配指南，可参考[后台播放](../avsession/avsession-background-scene.md)。