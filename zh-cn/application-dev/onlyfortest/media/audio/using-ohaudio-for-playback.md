# 使用OHAudio开发音频播放功能(C/C++)（验证一级标题不规范）

OHAudio是OpenHarmony在API version 10中引入的一套全新Native API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。

## 使用入门

开发者要使用OHAudio提供的播放或者录制能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```
### 添加头文件
开发者通过引入[native_audiostreambuilder.h]<!--Del-->(../../reference/apis-audio-kit/native__audiostreambuilder_8h.md)<!--DelEnd-->和<!--Del-->[native_audiorenderer.h](../../reference/apis-audio-kit/native__audiorenderer_8h.md)<!--DelEnd-->头文件，使用音频播放相关API。

```cpp
#include <ohaudio/native_audiorenderer.h>
#include <ohaudio/native_audiostreambuilder.h>
```

## 音频流构造器

OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，用于构建音频流。开发者需要根据业务场景，指定对应的[OH_AudioStream_Type]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_type) <!--DelEnd-->。

`OH_AudioStream_Type`包含两种类型：

- AUDIOSTREAM_TYPE_RENDERER
- AUDIOSTREAM_TYPE_CAPTURER

使用[OH_AudioStreamBuilder_Create]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_create)<!--DelEnd-->创建构造器示例：

```
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, streamType);
```

在音频业务结束之后，开发者应该执行[OH_AudioStreamBuilder_Destroy]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_destroy)<!--DelEnd-->接口来销毁构造器。

```
OH_AudioStreamBuilder_Destroy(builder);
```

## 开发步骤及注意事项

详细的API说明请参考[OHAudio API参考]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md)<!--DelEnd-->。

开发者可以通过以下几个步骤来实现一个简单的播放功能。

1. 创建构造器

    ```c++
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
    ```

2. 配置音频流参数

    创建音频播放构造器后，可以设置音频流所需要的参数，可以参考下面的案例。

    ```c++
    // 设置音频采样率
    OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
    // 设置音频声道
    OH_AudioStreamBuilder_SetChannelCount(builder, 2);
    // 设置音频采样格式
    OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
    // 设置音频流的编码类型
    OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
    // 设置输出音频流的工作场景
    OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
    ```

    注意，播放的音频数据要通过回调接口写入，开发者要实现回调接口，使用`OH_AudioStreamBuilder_SetRendererCallback`设置回调函数。回调函数的声明请查看[OH_AudioRenderer_Callbacks]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_callbacks) <!--DelEnd-->。


3. 设置音频回调函数

    多音频并发处理可参考多音频播放的并发策略，仅接口语言差异。

    ```c++
    // 自定义写入数据函数
    int32_t MyOnWriteData(
        OH_AudioRenderer* renderer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // 将待播放的数据，按length长度写入buffer
        return 0;
    }
    // 自定义音频流事件函数
    int32_t MyOnStreamEvent(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioStream_Event event)
    {
        // 根据event表示的音频流事件信息，更新播放器状态和界面
        return 0;
    }
    // 自定义音频中断事件函数
    int32_t MyOnInterruptEvent(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint)
    {
        // 根据type和hint表示的音频中断信息，更新播放器状态和界面
        return 0;
    }
    // 自定义异常回调函数
    int32_t MyOnError(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioStream_Result error)
    {
        // 根据error表示的音频异常信息，做出相应的处理
        return 0;
    }

    OH_AudioRenderer_Callbacks callbacks;
    // 配置回调函数
    callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
    callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent;
    callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
    callbacks.OH_AudioRenderer_OnError = MyOnError;

    //设置输出音频流的回调
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
    ```

    为了避免不可预期的行为，在设置音频回调函数时，请确认[OH_AudioRenderer_Callbacks]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_callbacks)<!--DelEnd-->的每一个回调都被**自定义的回调方法**或**空指针**初始化。

    ```c++
    // （可选）使用空指针初始化OnError回调
    callbacks.OH_AudioRenderer_OnError = nullptr;
    ```

4. 构造播放音频流

    ```c++
    OH_AudioRenderer* audioRenderer;
    OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
    ```

5. 使用音频流

    音频流包含下面接口，用来实现对音频流的控制。
    
    | 接口                                                         | 说明         |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer) | 开始播放     |
    | OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer) | 暂停播放     |
    | OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer) | 停止播放     |
    | OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | 释放缓存数据 |
    | OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | 释放播放实例 |

6. 释放构造器

    构造器不再使用时，需要释放相关资源。

    ```c++
    OH_AudioStreamBuilder_Destroy(builder);
    ```

## 设置低时延模式

当设备支持低时延通路时，开发者可以使用低时延模式创建播放器，获得更高质量的音频体验。

开发流程与普通播放场景一致，仅需要在创建音频流构造器时，调用[OH_AudioStreamBuilder_SetLatencyMode()]<!--Del-->(../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setlatencymode)<!--DelEnd-->设置低时延模式。

开发示例

```C
OH_AudioStreamBuilder_SetLatencyMode(builder, AUDIOSTREAM_LATENCY_MODE_FAST);
```

## 相关实例

针对音频通话开发，有以下相关实例可供参考：

- [录制和播放（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/Audio)