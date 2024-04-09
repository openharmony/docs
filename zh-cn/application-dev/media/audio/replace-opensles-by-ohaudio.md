# 从OpenSL ES切换到OHAudio(C/C++)

由于OpenSL ES无法满足音频系统的能力拓展，建议开发者使用OHAudio替代OpenSL ES开发音频业务。本文将介绍如何从使用OpenSL ES接口开发音频业务，切换为使用OHAudio接口。

## 支持的功能差异

两者支持的功能范围略有差异，OHAudio增加支持低时延播放/录制、监听业务变化等功能。

具体差异如下表所示。

| | OpenSL ES| OHAudio |
| --- | --- | --- |
| 音频流式播放 | √ | √ |
| 音频流式录制 | √ | √ |
| 音频低时延播放 | × | √ |
| 音频低时延录制 | × | √ |
| 播放对象状态切换 | √ | √ |
| 录制对象状态切换 | √ | √ |
| 获取音频流对象状态 | √ | √ |
| 清理播放缓存 | × | √ |
| 监听音频打断事件 | × | √ |
| 监听音频流事件 | × | √ |
| 监听流异常事件 | × | √ |
| 监听播放设备变化事件 | × | √ |

## 开发模式差异

此小节将结合开发步骤，对比介绍OHAudio和OpenSL ES在开发模式上的差异。

音频播放和录制的实现类似，此处以音频播放为例说明。

### 构造实例

OpenSL ES:

通过全局接口获取到Engine对象，基于Engine结合不同输入输出配置参数，构造出不同音频播放对象。

```c++
// 生成Engine Inteface对象
SLEngineItf engine;
// ...

// 按需配置音频输入slSource
SLDataSource slSource;
// ...

// 按需配置音频输出slSink
SLDataSink slSink;
// ...

// 生成音频播放对象
SLObjectItf playerObject;
(*engine)->CreateAudioPlayer(engine,
                             &playerObject,
                             &slSource,
                             &slSink,
                             0,
                             nullptr,
                             nullptr);

(*playerObject)->Realize(playerObject,
                         SL_BOOLEAN_FALSE);
```

OHAudio:

采用建造器模式，通过建造器，配合自定义参数设置，生成音频播放对象。

```c++
// 创建建造器
OH_AudioStreamBuilder *builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);

// 设置自定义参数，否则会使用默认参数
OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
OH_AudioStreamBuilder_SetChannelCount(builder, 2);
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// 关键参数，仅OHAudio支持，根据音频用途设置，系统会根据此参数实现音频策略自适应
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
// ...

// 生成音频播放对象
OH_AudioRenderer *audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### 状态切换

OpenSL ES:

基于Object获取状态切换Interface，使用Interface接口切换状态，只有SL_PLAYSTATE_STOPPED、SL_PLAYSTATE_PAUSED、SL_PLAYSTATE_PLAYING三种状态。

```c++
// 基于播放对象，获取播放操作Interface
SLPlayItf playItf = nullptr;
(*playerObject)->GetInterface(playerObject, SL_IID_PLAY, &playItf);
// 状态切换
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PAUSED);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
```

OHAudio:

有独立的状态切换接口，基于状态机进行状态切换，共6个OH_AudioStream_State状态，主要在AUDIOSTREAM_STATE_PREPARED、AUDIOSTREAM_STATE_RUNNING、AUDIOSTREAM_STATE_STOPPED、AUDIOSTREAM_STATE_PAUSED、AUDIOSTREAM_STATE_RELEASED状态间切换。

```c++
// 状态切换
OH_AudioRenderer_Start(audioRenderer);
OH_AudioRenderer_Pause(audioRenderer);
OH_AudioRenderer_Stop(audioRenderer);
```

### 数据处理

OpenSL ES:

基于扩展的OHBufferQueue接口，通过注册自定义的Callback函数，根据数据请求时机，将待播放数据填入系统内提供的缓冲区中。

```c++
static void MyBufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
{
    SLuint8 *buffer = nullptr;
    SLuint32 bufferSize;
    // 获取系统内提供的buffer
    (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &bufferSize);
    // 将待播放音频数据写入buffer
    // ...
    // 将buffer输入系统
    (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, bufferSize);
}

// 获取OHBufferQueue接口
SLOHBufferQueueItf bufferQueueItf;
(*playerObject)->GetInterface(playerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
// 可传入自定义的上下文信息，会在Callback内收到
void *pContext;
(*bufferQueueItf)->RegisterCallback(bufferQueueItf, MyBufferQueueCallback, pContext);
```

OHAudio:

统一使用回调模式，在构造时注册数据输入回调，实现自定义的数据填充函数，在播放过程中会跟随系统调度和时延配置情况，自动在合适时机触发数据请求回调。

```c++
static int32_t MyOnWriteData(
    OH_AudioRenderer *renderer,
    void *userData,
    void *buffer,
    int32_t bufferLen)
{
    // 将待播放数据按照请求的bufferLen长度，填入buffer
    // 函数返回后，系统会自动从buffer取出数据输出
}

OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;

// 设置输出音频流的回调，在生成音频播放对象时自动注册
void *userData = nullptr;
OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, userData);
```

### 资源释放

OpenSL ES:

使用SLObjectItf接口实现对象资源释放。

```c++
// 释放播放对象资源
(*playerObject)->Destroy(playerObject);
```

OHAudio:

使用对应模块的释放接口实现对象资源释放。

```c++
// 释放建造器资源
OH_AudioStreamBuilder_Destroy(builder);

// 释放播放对象资源
OH_AudioRenderer_Release(audioRenderer);
```