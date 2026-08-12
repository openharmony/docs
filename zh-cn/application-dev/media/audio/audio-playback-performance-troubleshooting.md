# 播放卡顿、杂音定位指导
 <!--Kit: Audio Kit-->
 <!--Subsystem: Multimedia-->
 <!--Owner: @boxwell-->
 <!--Designer: @magekkkk-->
 <!--Tester: @Filger-->
 <!--Adviser: @w_Machine_cc-->

开发者在实现音频播放功能时，可能会遇到播放声音卡顿、杂音、破音等问题。本文将介绍播放卡顿、杂音现象的常见问题以及定位方法，并给出可直接对照的示例代码和定位流程。 

## 问题现象

进行应用播放时，常见的卡顿、杂音情况表现如下：

- 播放时出现持续的杂音。
- 播放时突然卡顿/出现破音、杂音。
- 在播放开始/结束时出现破音、杂音。
- 在执行进度跳转时出现破音、杂音。

## 问题原因

**1. 应用创建的音频实例参数和实际音源格式不匹配。**

   开发者需参考当前系统[支持的音频格式](audio-kit-intro.md#支持的音频格式)进行参数设置。若实际音源格式和传入的音频格式不相符，会导致出现播放持续杂音、异常倍速播放等非预期的行为。

**2. 音源数据本身异常。**

   音源数据的异常除音源文件本身包含的杂音、卡顿等情况外，还包括应用通过`OH_AudioRenderer_OnWriteDataCallback`回调函数中的`audioData`传递给系统侧数据包含杂音、卡顿的情况。例如未填满`audioData`、填充脏数据或填入了全0数据等。

**3. 整机高负载，数据传递不及时。**

   在整机高负载的情况下，系统内的进程会按照进程的优先级进行CPU资源的调度。若此时应用内部进程的优先级较低，可能会出现数据生产不及时、数据下发不及时等一系列情况，造成卡顿。

**4. 音频播放实例状态异常。**

   在正常播放场景中，预期不会频繁调用Start/Stop/Pause等接口修改音频实例的状态。如果存在短时间的快速启停（Pause--Start--Pause），或对音频接口的异常调用，也会造成听感上的卡顿异常。

## 问题定位流程

音频数据的处理，通常采用生产者消费者模型。生产端生成音频数据写入公共缓冲区，消费端按需从缓冲区取数据进行下一步处理。当消费端取数据时，如发现数据不足，为了避免影响后续流程，不会阻塞等待，而是直接使用静音帧数据处理。在播放过程中，间歇性出现静音帧时，听感上表现为电流杂音；大量静音帧出现时，听感表现为卡顿。

建议按照以下顺序逐步排查。每一步先确认一个可观察结果，再根据结果进入下一步或跳转到对应文档。

1. 确认音源文件本身是否存在异常。

   检查项如下：

   - 文件格式：当前系统内部仅支持传输PCM（Pulse Code Modulation）格式的音源数据；请确认当前传递给系统的音源数据是否为PCM格式。
   - 文件解码：若开发者自行进行了其他音频格式的解码，请确认解码后的数据为可播放、无杂音的正常PCM数据。开发者可将音源数据拷贝给`OH_AudioRenderer_OnWriteDataCallback`回调函数中的`audioData`后，自行在本地文件中写入一份，以确认是否是音源异常导致的杂音。
   - 参数配置：请检查创建时设置的采样率、声道数、采样格式、编码格式等参数和音源文件的实际格式是否一致。
   - 网络传输：由于网络传输不稳定导致应用客户端音频数据生产不及时，开发者可在缺少数据时打印相关日志，以进一步明确阻塞点。

   可参考下方示例进行音频参数的设置。

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
   
2. 确认`OH_AudioRenderer_OnWriteDataCallback`回调函数中的数据传输行为。

   检查项如下：

   - 回调间隔：音频播放采用流式传输的模式，请勿在回调函数中执行过于耗时的处理逻辑（建议单次耗时不超过15ms，在低时延模式下会有更短间隔的要求），避免因当次回调长时间未返回导致系统侧无数据可播放。推荐开发者在复杂函数逻辑中，增加时间戳记录以观察当前函数在实际播放场景下的耗时情况。
   - 是否返回0数据：请勿在数据未及时生成时，在回调函数的`audioData`中填充0数据，并且返回`AUDIO_DATA_CALLBACK_RESULT_VALID`；系统会认为这是有效的音频数据并正常播放，造成听感上的卡顿、破音。
   - 是否未填满数据：在因数据未及时生成，导致无法填满回调所需长度数据的情况下，建议开发者返回`AUDIO_DATA_CALLBACK_RESULT_INVALID`，系统不会处理该段音频数据，然后会再次向应用请求数据。当播放结束，最后的音频数据不足以完整填充`audioData`时，开发者需将剩余区域填充静音数据。当使用音频位宽格式为`SAMPLE_FORMAT_U8`时，`0x80`为静音数据，使用其他采样格式时0为静音数据；系统支持的位宽格式可参考[AudioSampleFormat](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosampleformat8)。

3. 确认当前整机负载情况。

   检查项如下：

   当前系统整体负载较重：请确认当前卡顿、杂音是否主要出现在前后台切换、多应用在后台、打开相机等负载场景下。若确认为当前场景，开发者在优化应用整体处理流程性能的同时，也可通过接入[音频工作组管理](audio-workgroup.md)能力，由系统保障线程资源分配满足预期时间要求。

4. 确认当前是否异常调用音频接口。

   系统会在播放/暂停接口被调用时，对开头/结尾的一帧音频进行淡出/淡入处理；开发者也可以在此场景下对送入系统的音频数据进行淡出和淡入的优化，以进一步提升播放体验。

   检查项如下：

   - 短时间的快速启停：当系统快速响应应用的启停操作时，系统按照预期行为在运行/暂停期间短暂的送/未送有效的音频数据，造成听感上的杂音/破音。开发者可通过`OH_AudioRenderer_GetCurrentState`获取当前音频流状态来排查这种情况。
   - 调用了Flush后未送数据，马上调用Pause/Stop：正常情况下，系统内部在收到Pause/Stop时会对收到指令的下一帧进行淡出处理，以削弱听感上形成的杂音/破音。当开发者先调用Flush后，马上调用Pause/Stop，此时框架内部由于执行了Flush命令，已经将缓存清空；此时在Pause/Stop场景下无缓存数据做淡出操作，导致听感上会存在短暂的截断杂音。推荐开发者在Pause后调用Flush接口。
   - 在执行进度跳转操作后未调用Flush接口：系统内部的缓存数据在未收到Flush时不会清空。因此当上一次进度跳转操作的Pause执行完成后，底层会存在几帧已经送到系统、但是未播出的缓存。当跳转至新位置时，会将上次未播放出的缓存数据继续播放，因此听感上会存在短暂的杂音数据。推荐进度跳转操作时，先执行Pause，调用Flush清空缓存后，再调用Start。
   - 系统的淡入淡出操作未处理在有效数据上：当前系统仅在调用Pause/Stop接口时会进行淡出处理。如果在调用Pause/Stop接口前，应用未送数据导致无数据可写，系统填充了静音数据；或者音源数据最后一帧为空帧且与前面的有效数据不连续，也会造成淡入淡出处理的失效。

## 相关文档参考

- 使用OHAudio播放的示例代码，请参考[推荐使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)。
- 使用AudioRenderer播放的示例代码，请参考[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)。
- 推荐抓取Trace日志，进行进一步的性能分析，具体操作请参考[音频性能分析方法](audio-performance.md#音频性能分析方法)。
- 在负载场景下，开发者可通过接入[音频工作组管理](audio-workgroup.md)能力提升应用的调度优先级，由系统保障线程资源分配满足预期时间要求。