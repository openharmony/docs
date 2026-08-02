# 实现自定义耳返
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

实现音频耳返的功能，可将音频实时传输到耳机中，让用户可以实时听到自己或者其他相关声音。

常用于K歌类应用，将录制的人声和背景音乐实时送到耳机中，使用户通过反馈即时调整，获得更好的使用体验。

## 使用前提

- 开发者可使用OHAudio提供的播放和录制能力相结合，将录制获取的音频数据作为播放的音频输入，实现耳返功能。

  实现参考[推荐使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)、[推荐使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)。

- 当前仅支持通过有线耳机实现耳返功能。音频由有线耳机采集并播放。

## 使用场景

通过组合系统播放和录制的能力，在应用内实现耳返，适用于应用需要自己处理录制数据的场景。比如，应用可以对录制上来的数据使用自定义的音效算法进行处理，再进行播放，以实现特定的音效。由于数据需要经过应用处理，时延相对于系统耳返会更高。

## 开发指导

  以下各步骤示例为片段代码，可通过示例代码右下方链接获取[完整示例](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioCapturerSampleC)。

### 创建音频录制

通过OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，构建录制音频流。指定对应的[OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type)，设置为AUDIOSTREAM_TYPE_CAPTURER。

<!-- @[Create_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
```

### 创建音频播放

通过OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，构建播放音频流。指定对应的[OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type)，设置为AUDIOSTREAM_TYPE_RENDERER。

<!-- @[Create_Renderer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```

### 设置低时延模式

为了实现更好的耳返功能，需要使得音频从录制到播放保持较低的时延，当设备支持低时延通路时，开发者需要使用低时延模式来进行录制和播放。

在创建音频录制构造器时调用[OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode)设置低时延模式，播放和录制均按如下方式设置为低时延模式。

<!-- @[latencyMode_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

为实现实时耳返功能，需创建一个公共缓冲区用于存储录制的数据，并及时从该缓冲区获取数据写入播放构造器。

### 定义公共缓冲区和录制、播放函数

<!-- @[public_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
int32_t MyOnReadData_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // 从buffer中取出length长度的录音数据。
    return 0;
}
// ...
int32_t MyOnWriteData(
    OH_AudioRenderer* renderer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // 从公共缓冲区buffer中读取数据，并按length长度写入buffer。
    return 0;
}
```

> **注意：**
>
> 应用的公共缓冲区大小不应设置过大，以避免增加耳返时延，影响用户体验。开发者应根据时延要求和抗抖动要求，选择合适的缓冲区大小，确保用户体验。

### 设置音频流参数

以录制流参数设置为例：

<!-- @[Configure_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
// 设置音频采样率。
const int SAMPLING_RATE_48K = 48000;
OH_AudioStreamBuilder_SetSamplingRate(builder, SAMPLING_RATE_48K);
// 设置音频声道。
const int channelCount = 2;
OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
// 设置音频采样格式。
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
// 设置音频流的编码类型。
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// 设置输入音频流的工作场景。
OH_AudioStreamBuilder_SetCapturerInfo(builder, AUDIOSTREAM_SOURCE_TYPE_MIC);
```

对于播放流，除了音频流的工作场景外，其余设置为和录制流相同的参数。

工作场景参数设置如下：

<!-- @[SetRendererInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
```

### 设置录制回调函数

<!-- @[SetCapturerCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
int32_t MyOnReadData_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // 从buffer中取出length长度的录音数据。
    return 0;
}
int32_t MyOnInterruptEvent_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // 根据type和hint表示的音频中断信息，更新录制器状态和界面。
    return 0;
}

int32_t MyOnStreamEvent_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Event event)
{
    // 根据event表示的音频流事件信息，更新录制器状态和界面。
    return 0;
}

int32_t MyOnError_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Result error)
{
    // 根据error表示的音频异常信息，做出相应的处理。
    return 0;
}
// ...
    OH_AudioCapturer_Callbacks callbacks;
    // 配置回调函数。
    callbacks.OH_AudioCapturer_OnReadData = MyOnReadData_Legacy;
    callbacks.OH_AudioCapturer_OnStreamEvent = MyOnStreamEvent_Legacy;
    callbacks.OH_AudioCapturer_OnInterruptEvent = MyOnInterruptEvent_Legacy;
    callbacks.OH_AudioCapturer_OnError = MyOnError_Legacy;

    OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
```

### 设置播放回调函数

<!-- @[SetRendererCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->  

``` C++
int32_t MyOnWriteData(
    OH_AudioRenderer* renderer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // 从公共缓冲区buffer中读取数据，并按length长度写入buffer。
    return 0;
}
int32_t MyOnStreamEvent_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioStream_Event event)
{
    // 根据event表示的音频流事件信息，更新播放器状态和界面。
    return 0;
}

int32_t MyOnInterruptEvent_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // 根据type和hint表示的音频中断信息，更新播放器状态和界面。
    return 0;
}

int32_t MyOnError_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioStream_Result error)
{
    // 根据error表示的音频异常信息，做出相应的处理。
    return 0;
}
// ...
    OH_AudioRenderer_Callbacks callbacks;
    
    // 配置回调函数。
    callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
    callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent_Renderer;
    callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent_Renderer;
    callbacks.OH_AudioRenderer_OnError = MyOnError_Renderer;

    // 设置输出音频流的回调。
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
```

### 构造录制音频流

<!-- @[GenerateCapturer_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioCapturer* audioCapturer;
OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
```

### 构造播放音频流

<!-- @[GenerateRenderer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioRenderer* audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### 使用音频流

以播放为例，开发者可以使用以下接口控制音频流的开始、暂停、停止和释放。

> **注意:**
> 
> 在实现耳返功能时，开发者需同时控制录制流和播放流，确保两者同步。

| 接口                                                     | 说明         |
| ------------------------------------------------------------ | ------------ |
| OH_AudioStream_Result [OH_AudioRenderer_Start](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_start)(OH_AudioRenderer* renderer) | 开始播放。     |
| OH_AudioStream_Result [OH_AudioRenderer_Pause](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_pause)(OH_AudioRenderer* renderer) | 暂停播放。     |
| OH_AudioStream_Result [OH_AudioRenderer_Stop](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_stop)(OH_AudioRenderer* renderer) | 停止播放。     |
| OH_AudioStream_Result [OH_AudioRenderer_Flush](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_flush)(OH_AudioRenderer* renderer) | 释放缓存数据。 |
| OH_AudioStream_Result [OH_AudioRenderer_Release](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_release)(OH_AudioRenderer* renderer) | 释放播放实例。 |

### 释放构造器

构造器不再使用时，采用如下方式释放资源。

<!-- @[Destroy_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder_Destroy(builder);
```