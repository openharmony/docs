# 使用OHAudio开发音频播放功能(C/C++)

OHAudio是系统在API version 10中引入的一套C API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。仅支持PCM格式，适用于依赖Native层实现音频输出功能的场景。

OHAudio音频播放状态变化示意图：
![OHAudioRenderer status change](figures/ohaudiorenderer-status-change.png)

## 使用入门

开发者要使用OHAudio提供的播放能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### 添加头文件

开发者通过引入<[native_audiostreambuilder.h](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md)>和<[native_audiorenderer.h](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md)>头文件，使用音频播放相关API。

```cpp
#include <ohaudio/native_audiorenderer.h>
#include <ohaudio/native_audiostreambuilder.h>
```

## 音频流构造器

OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，用于构建音频流。开发者需要根据业务场景，指定对应的[OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type)。

`OH_AudioStream_Type`包含两种类型：

- AUDIOSTREAM_TYPE_RENDERER
- AUDIOSTREAM_TYPE_CAPTURER

使用[OH_AudioStreamBuilder_Create](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create)创建构造器示例：

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, streamType);
```

在音频业务结束之后，开发者应该执行[OH_AudioStreamBuilder_Destroy](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_destroy)接口来销毁构造器。

```cpp
OH_AudioStreamBuilder_Destroy(builder);
```

## 开发步骤及注意事项

详细的API说明请参考[OHAudio API参考](../../reference/apis-audio-kit/capi-ohaudio.md)。

开发者可以通过以下几个步骤来实现一个简单的播放功能。

1. 创建构造器。

    ```cpp
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
    ```

2. 配置音频流参数。

    关于音频采样率可参考[配置合适的音频采样率](using-audiorenderer-for-playback.md#配置合适的音频采样率)。<br>
    创建音频播放构造器后，可以设置音频流所需要的参数，可以参考下面的案例。

    ```cpp
    // 设置音频采样率。
    OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
    // 设置音频声道。
    OH_AudioStreamBuilder_SetChannelCount(builder, 2);
    // 设置音频采样格式。
    OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
    // 设置音频流的编码类型。
    OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
    // 设置输出音频流的工作场景。
    OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
    ```

    注意，播放的音频数据要通过回调接口写入，开发者要实现回调接口，使用`OH_AudioStreamBuilder_SetRendererCallback`设置回调函数。回调函数的声明请查看[OH_AudioRenderer_Callbacks](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md)。

3. 设置音频回调函数。

    多音频并发处理可参考文档[处理音频焦点事件](audio-playback-concurrency.md)，仅接口语言差异。

    在设置音频回调函数时API version 12新增回调函数[OH_AudioRenderer_OnWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback)用于写入音频数据。

    - API version 12开始**推荐**使用[OH_AudioRenderer_OnWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback)代替[OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md#oh_audiorenderer_onwritedata)用于写入音频数据。

      > **注意：**
      > 
      > - 能填满回调所需长度数据的情况下，返回AUDIO_DATA_CALLBACK_RESULT_VALID，系统会取用完整长度的数据缓冲进行播放。请不要在未填满数据的情况下返回AUDIO_DATA_CALLBACK_RESULT_VALID，否则会导致杂音、卡顿等现象。
      > 
      > - 在无法填满回调所需长度数据的情况下，建议开发者返回AUDIO_DATA_CALLBACK_RESULT_INVALID，系统不会处理该段音频数据，然后会再次向应用请求数据，确认数据填满后返回AUDIO_DATA_CALLBACK_RESULT_VALID。
      > 
      > - 回调函数结束后，音频服务会把缓冲中数据放入队列里等待播放，因此请勿在回调外再次更改缓冲中的数据。对于最后一帧，如果数据不够填满缓冲长度，开发者需要使用剩余数据拼接空数据的方式，将缓冲填满，避免缓冲内的历史脏数据对播放效果产生不良的影响。

      从API version 12开始可通过[OH_AudioStreamBuilder_SetFrameSizeInCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback)设置audioDataSize的大小。

      ```cpp
      // 自定义写入数据函数。
      static OH_AudioData_Callback_Result NewAudioRendererOnWriteData(
          OH_AudioRenderer* renderer,
          void* userData,
          void* audioData,
          int32_t audioDataSize)
      {
          // 将待播放的数据，按audioDataSize长度写入audioData。
          // 如果开发者不希望播放某段audioData，返回AUDIO_DATA_CALLBACK_RESULT_INVALID即可。
          return AUDIO_DATA_CALLBACK_RESULT_VALID;
      }
      // 自定义音频流事件函数。
      int32_t MyOnStreamEvent(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioStream_Event event)
      {
          // 根据event表示的音频流事件信息，更新播放器状态和界面。
          return 0;
      }
      // 自定义音频中断事件函数。
      int32_t MyOnInterruptEvent(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioInterrupt_ForceType type,
          OH_AudioInterrupt_Hint hint)
      {
          // 根据type和hint表示的音频中断信息，更新播放器状态和界面。
          return 0;
      }
      // 自定义异常回调函数。
      int32_t MyOnError(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioStream_Result error)
      {
          // 根据error表示的音频异常信息，做出相应的处理。
          return 0;
      }

      OH_AudioRenderer_Callbacks callbacks;

      // 配置回调函数。
      callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent;
      callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
      callbacks.OH_AudioRenderer_OnError = MyOnError;
      callbacks.OH_AudioRenderer_OnWriteData = nullptr;

      // 设置输出音频流的回调。
      OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);

      // 配置写入音频数据回调函数。
      OH_AudioRenderer_OnWriteDataCallback writeDataCb = NewAudioRendererOnWriteData;
      OH_AudioStreamBuilder_SetRendererWriteDataCallback(builder, writeDataCb, nullptr);
      ```

    - API version 11使用回调函数[OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md#oh_audiorenderer_onwritedata)用于写入音频数据。

      > **注意：**
      > 
      > - 该函数不支持返回回调结果，系统默认回调中的数据均为有效数据。请确保填满回调所需长度数据，否则会导致杂音、卡顿等现象。
      > 
      > - 在无法填满回调所需长度数据的情况下，建议开发者选择暂时停止写入数据（不暂停音频流），阻塞回调函数，等待数据充足时，再继续写入数据，确保数据填满。在阻塞回调函数后，如需调用AudioRenderer相关接口，需先解阻塞。
      > 
      > - 开发者如果不希望播放本次回调中的音频数据，可以主动将回调中的数据块置空（置空后，也会被系统统计到已写入的数据，播放静音帧）。
      > 
      > - 回调函数结束后，音频服务会把缓冲中数据放入队列里等待播放，因此请勿在回调外再次更改缓冲中的数据。对于最后一帧，如果数据不够填满缓冲长度，开发者需要使用剩余数据拼接空数据的方式，将缓冲填满，避免缓冲内的历史脏数据对播放效果产生不良的影响。

      ```cpp
      // 自定义写入数据函数。
      int32_t MyOnWriteData(
          OH_AudioRenderer* renderer,
          void* userData,
          void* buffer,
          int32_t length)
      {
          // 将待播放的数据，按length长度写入buffer。
          // 如果开发者不希望播放某段buffer，可在此处对buffer进行置空处理。
          return 0;
      }
      // 自定义音频流事件函数。
      int32_t MyOnStreamEvent(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioStream_Event event)
      {
          // 根据event表示的音频流事件信息，更新播放器状态和界面。
          return 0;
      }
      // 自定义音频中断事件函数。
      int32_t MyOnInterruptEvent(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioInterrupt_ForceType type,
          OH_AudioInterrupt_Hint hint)
      {
          // 根据type和hint表示的音频中断信息，更新播放器状态和界面。
          return 0;
      }
      // 自定义异常回调函数。
      int32_t MyOnError(
          OH_AudioRenderer* renderer,
          void* userData,
          OH_AudioStream_Result error)
      {
          // 根据error表示的音频异常信息，做出相应的处理。
          return 0;
      }

      OH_AudioRenderer_Callbacks callbacks;

      // 配置回调函数。
      callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
      callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent;
      callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
      callbacks.OH_AudioRenderer_OnError = MyOnError;

      // 设置输出音频流的回调。
      OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
      ```

   为了避免不可预期的行为，在设置音频回调函数时，可以通过下面两种方式中的任意一种来设置音频回调函数：

   - 请确保[OH_AudioRenderer_Callbacks](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md)的每一个回调都被**自定义的回调方法**或**空指针**初始化。
   
     ```cpp
     // 自定义写入数据函数。
     int32_t MyOnWriteData(
         OH_AudioRenderer* renderer,
         void* userData,
         void* buffer,
         int32_t length)
     {
         // 将待播放的数据，按length长度写入buffer。
         return 0;
     }
     // 自定义音频中断事件函数。
     int32_t MyOnInterruptEvent(
         OH_AudioRenderer* renderer,
         void* userData,
         OH_AudioInterrupt_ForceType type,
         OH_AudioInterrupt_Hint hint)
     {
         // 根据type和hint表示的音频中断信息，更新播放器状态和界面。
         return 0;
     }

     OH_AudioRenderer_Callbacks callbacks;

     // 配置回调函数，如果需要监听，则赋值。
     callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
     callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;

     // （必选）如果不需要监听，使用空指针初始化。
     callbacks.OH_AudioRenderer_OnStreamEvent = nullptr;
     callbacks.OH_AudioRenderer_OnError = nullptr;
     ```
   
   - 使用前，初始化并清零结构体。
   
     ```cpp
     // 自定义写入数据函数。
     int32_t MyOnWriteData(
         OH_AudioRenderer* renderer,
         void* userData,
         void* buffer,
         int32_t length)
     {
         // 将待播放的数据，按length长度写入buffer。
         return 0;
     }
     // 自定义音频中断事件函数。
     int32_t MyOnInterruptEvent(
         OH_AudioRenderer* renderer,
         void* userData,
         OH_AudioInterrupt_ForceType type,
         OH_AudioInterrupt_Hint hint)
     {
         // 根据type和hint表示的音频中断信息，更新播放器状态和界面。
         return 0;
     }
     OH_AudioRenderer_Callbacks callbacks;
   
     // 使用前，初始化并清零结构体。
     memset(&callbacks, 0, sizeof(OH_AudioRenderer_Callbacks));
   
     // 配置需要的回调函数。
     callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
     callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
     ```

4. 构造播放音频流。

    ```cpp
    OH_AudioRenderer* audioRenderer;
    OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
    ```

5. 使用音频流。

    音频流包含下面接口，用来实现对音频流的控制。
    
    | 接口                                                         | 说明         |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer) | 开始播放。     |
    | OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer) | 暂停播放。     |
    | OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer) | 停止播放。     |
    | OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | 释放缓存数据。 |
    | OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | 释放播放实例。 |

6. 释放构造器。

    构造器不再使用时，需要释放相关资源。

    ```cpp
    OH_AudioStreamBuilder_Destroy(builder);
    ```

## 设置音频流音量

开发者可使用[OH_AudioRenderer_SetVolume](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_setvolume)接口设置当前音频流音量值。

```cpp
// 要设置的音量值，音量值的范围是[0.0, 1.0]。
float volume = 0.5f;

// 设置当前音频流音量值。
OH_AudioStream_Result OH_AudioRenderer_SetVolume(audioRenderer, volume);
```

## 设置低时延模式

当设备支持低时延通路且采样率设置为48000时，开发者可以使用低时延模式创建播放器，获得更高质量的音频体验。

开发流程与普通播放场景一致，仅需要在创建音频流构造器时，调用[OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode)设置低时延模式。

> **注意：**
>
> - 当音频录制场景[OH_AudioStream_Usage](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage)为`AUDIOSTREAM_USAGE_VOICE_COMMUNICATION`和`AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION`时，不支持主动设置低时延模式，系统会根据设备的能力，决策输出的音频通路。
> - 低时延通路对于数据处理性能要求较高，应用数据生成慢时容易导致卡顿，普通音乐、视频播放场景下不建议设置该模式，仅推荐游戏、K歌等对时延敏感的应用设置低时延模式。

开发示例

```cpp
OH_AudioStreamBuilder_SetLatencyMode(builder, AUDIOSTREAM_LATENCY_MODE_FAST);
```

## 设置音频声道布局

播放音频文件时，可以通过设置音频的声道布局信息，指定渲染或播放时的扬声器摆位，使得渲染和播放效果更佳，获得更高质量的音频体验。

开发流程与普通播放场景一致，仅需要在创建音频流构造器时，调用[OH_AudioStreamBuilder_SetChannelLayout()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setchannellayout)设置声道布局信息。

当声道布局与声道数不匹配时，创建音频流会失败。建议在设置声道布局时，确认下发的声道布局信息是正确的。

如果不知道准确的声道布局信息，或者开发者需要使用默认声道布局，可以不调用设置声道布局接口，或者下发CH_LAYOUT_UNKNOWN，以使用基于声道数的默认声道布局。

对于HOA格式的音频，想要获得正确的渲染和播放效果，必须指定声道布局信息。

开发示例

```cpp
OH_AudioStreamBuilder_SetChannelLayout(builder, CH_LAYOUT_STEREO);
```

## 播放AudioVivid格式音源

播放AudioVivid格式音频文件时，需要使用与普通播放不同的数据写入回调函数，该回调可以同时写入PCM数据与元数据。

开发流程与普通播放场景一致，仅需要在创建音频流构造器时，调用[OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setwritedatawithmetadatacallback)设置PCM数据与元数据同时写入的回调函数，同时调用[OH_AudioStreamBuilder_SetEncodingType()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setencodingtype)设置编码类型为AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID。

在播放AudioVivid时，帧长是固定的，不可通过[OH_AudioStreamBuilder_SetFrameSizeInCallback()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback)设置回调帧长。同时，在设置播放声道数和声道布局时，需要将写入音源的声床数和对象数相加后进行设置。

```cpp
// 自定义同时写入PCM数据和元数据函数。
int32_t MyOnWriteDataWithMetadata(
    OH_AudioRenderer* renderer,
    void* userData,
    void* audioData,
    int32_t audioDataSize,
    void* metadata,
    int32_t metadataSize)
{
    // 将待播放的PCM数据和元数据，分别按audioDataSize和metadataSize写入buffer。
    return 0;
}

// 设置编码类型。
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID);
// 配置回调函数。
OH_AudioRenderer_WriteDataWithMetadataCallback metadataCallback = MyOnWriteDataWithMetadata;
// 设置同时写入PCM数据和元数据的回调。
OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(builder, metadataCallback, nullptr);
```

## 相关实例

针对OHAudio开发音频播放，有以下相关实例可供参考：

- [OHAudio录制和播放](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/OHAudio)

<!--RP1-->
<!--RP1End-->