# 实现音频耳返

实现音频耳返的功能，可将音频实时传输到耳机中，让用户可以实时听到自己或者其他相关声音。

常用于K歌类应用，将录制的人声和背景音乐实时送到耳机中，使用户通过反馈即时调整，获得更好的使用体验。

## 使用前提

- 开发者可使用OHAudio提供的播放和录制能力相结合，将录制获取的音频数据作为播放的音频输入，实现耳返功能。

  实现参考[使用OHAudio开发音频播放功能](using-ohaudio-for-playback.md)、[使用OHAudio开发音频录制功能](using-ohaudio-for-recording.md)。

- 当前仅支持通过有线耳机实现耳返功能。音频由有线耳机采集并播放。

## 开发指导

### 创建音频录制

通过OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，构建录制音频流。指定对应的[OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type), 设置为AUDIOSTREAM_TYPE_CAPTURER。

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
```

### 创建音频播放

通过OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，构建播放音频流。指定对应的[OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type), AUDIOSTREAM_TYPE_RENDERER。

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```

### 设置低时延模式

为了实现更好的耳返功能，需要使得音频从录制到播放保持较低的时延，当设备支持低时延通路时，开发者需要使用低时延模式来进行录制和播放。

在创建音频录制构造器时调用[OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode)设置低时延模式，播放和录制均按如下方式设置为低时延模式。

```cpp
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

为实现实时耳返功能，需创建一个公共缓存区用于存储录制的数据，并及时从该缓存区获取数据写入播放构造器。

### 定义公共缓存和录制、播放函数

```cpp
// 创建一块公共缓存BUFFER，用于及时写入录制录制和读取播放数据

// 自定义读入录制数据函数。
    int32_t MyOnReadData(
        OH_AudioCapturer* capturer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // 从buffer中取出length长度的录音数据，放在创建好的公共缓存BUFFER中，用于供renderer进行读取
        return 0;
    }

    // 自定义写入数据函数。
    int32_t MyOnWriteData(
        OH_AudioRenderer* renderer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // 从公共缓存BUFFER中读取数据，并按length长度写入buffer。
        return 0;
    }
```

### 设置音频流参数

以录制流参数设置为例：

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
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_SOURCE_TYPE_MIC);
```

对于播放流，除了音频流的工作场景外，其余设置为和录制流相同的参数。

工作场景参数设置如下：

```cpp
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
```

### 设置录制回调函数

```cpp
// 自定义读入数据函数。
int32_t MyOnReadData(
    OH_AudioCapturer* capturer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // 从buffer中取出length长度的录音数据。
    return 0;
}
// 自定义音频流事件函数。
int32_t MyOnStreamEvent(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Event event)
{
    // 根据event表示的音频流事件信息，更新录制器状态和界面。
    return 0;
}
// 自定义音频中断事件函数。
int32_t MyOnInterruptEvent(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // 根据type和hint表示的音频中断信息，更新录制器状态和界面。
    return 0;
}
// 自定义异常回调函数。
int32_t MyOnError(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Result error)
{
    // 根据error表示的音频异常信息，做出相应的处理。
    return 0;
}

OH_AudioCapturer_Callbacks callbacks;

// 配置回调函数。
callbacks.OH_AudioCapturer_OnReadData = MyOnReadData;
callbacks.OH_AudioCapturer_OnStreamEvent = MyOnStreamEvent;
callbacks.OH_AudioCapturer_OnInterruptEvent = MyOnInterruptEvent;
callbacks.OH_AudioCapturer_OnError = MyOnError;

// 设置音频输入流的回调。
OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
```

### 设置播放回调函数

```cpp
    // 自定义写入数据函数。
    int32_t MyOnWriteData(
        OH_AudioRenderer* renderer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // 从公共缓存BUFFER中读取数据，并按length长度写入buffer。
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

### 构造录制音频流

```cpp
OH_AudioCapturer* audioCapturer;
OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
```

### 构造播放音频流

```cpp
OH_AudioRenderer* audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### 使用音频流

以录制为例，开发者可以使用以下接口控制音频流的开始、暂停、停止和释放。

> **注意:**
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

```cpp
OH_AudioStreamBuilder_Destroy(builder);
```