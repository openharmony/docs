# OHAudio

OHAudio是OpenHarmony在API10中引入的一套全新C API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。

## 使用入门

开发者要使用OHAudio提供的播放或者录制能力，需要添加对应的头文件。

开发者通过引入<[native_audiostreambuilder.h](../reference/native-apis/native__audiostreambuilder_8h.md)>和<[native_audiorenderer.h](../reference/native-apis/native__audiorenderer_8h.md)>头文件，使用音频播放相关API。

## 音频流构造器

OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，用于构建音频流。开发者需要根据业务场景，指定对应的[OH_AudioStream_Type](../reference/native-apis/_o_h_audio.md#oh_audiostream_type) 。

`OH_AudioStream_Type`包含两种类型：

- AUDIOSTREAM_TYPE_RERNDERER
- AUDIOSTREAM_TYPE_CAPTURER

使用[OH_AudioStreamBuilder_Create](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_create)创建构造器示例：

```
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, streamType);
```

在音频业务结束之后，开发者应该执行[OH_AudioStreamBuilder_Destroy](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_destroy)接口来销毁构造器。

```
OH_AudioStreamBuilder_Destroy(builder);
```

## 开发步骤及注意事项
详细的API说明请参考OHAudio API参考。
开发者可以通过以下几个步骤来实现一个简单的播放功能。

**1. 创建构造器**

```
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RERNDERER);
```

**2. 配置音频流参数**

创建音频播放构造器后，可以设置音频流所需要的参数，可以参考下面的案例。

```
OH_AudioStreamBuilder_SetSamplingRate(builder, rate);
OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
OH_AudioStreamBuilder_SetSampleFormat(builder, format);
OH_AudioStreamBuilder_SetEncodingType(builder, encodingType);
OH_AudioStreamBuilder_SetRendererInfo(builder, usage, content);
```

注意，播放的音频数据要通过回调接口写入，开发者要实现回调接口，使用`OH_AudioStreamBuilder_SetRendererCallback`设置回调函数。回调函数接口声明如下。

```
typedef struct OH_AudioRenderer_Callbacks_Struct {
    /**
     * This function pointer will point to the callback function that
     * is used to write audio data
     */
    int32_t (*OH_AudioRenderer_OnWriteData)(
            OH_AudioRenderer* renderer,
            void* userData,
            void* buffer,
            int32_t lenth);
} OH_AudioRenderer_Callbacks;
```

**3. 设置回调函数**

```
OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
```

**4. 构造播放音频流**

```
OH_AudioRenderer* audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

**5. 使用音频流**

音频流包含下面接口，用来实现对音频流的控制。

| 接口                                                         | 说明         |
| ------------------------------------------------------------ | ------------ |
| OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer) | 开始播放     |
| OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer) | 暂停播放     |
| OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer) | 停止播放     |
| OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | 释放缓存数据 |
| OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | 释放播放实例 |

## 完整示例
参考以下示例，完成一次播放音频的完整流程。
```
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <thread>
#include <chrono>
#include "common/native_audiostreambuilder.h"
#include "native_audiorenderer.h"

#ifdef __cplusplus
extern "C" {
#endif
namespace AudioTestConstants {
    constexpr int32_t FIRST_ARG_IDX = 1;
    constexpr int32_t SECOND_ARG_IDX = 2;
    constexpr int32_t THIRD_ARG_IDX = 3;
    constexpr int32_t WAIT_INTERVAL = 1000;
}

std::string g_filePath = "/data/data/oh_test_audio.pcm";
FILE* g_file = nullptr;
bool g_readEnd = false;
int32_t g_samplingRate = 48000;
int32_t g_channelCount = 2;

static int32_t AudioRendererOnWriteData(OH_AudioRenderer* capturer,
    void* userData,
    void* buffer,
    int32_t bufferLen)
{
    size_t readCount = fread(buffer, bufferLen, 1, g_file);
    if (!readCount) {
        g_readEnd = true;
        if (ferror(g_file)) {
            printf("Error reading file");
        } else if (feof(g_file)) {
            printf("EOF found");
        }
    }

    return 0;
}

void PlayerTest(char *argv[])
{
    OH_AudioStream_Result ret;

    // 1. create builder
    OH_AudioStreamBuilder* builder;
    OH_AudioStream_Type type = AUDIOSTREAM_TYPE_RERNDERER;
    ret = OH_AudioStreamBuilder_Create(&builder, type);
    printf("createcallback ret: %d \n", ret);

    // 2. set params and callbacks
    OH_AudioStreamBuilder_SetSamplingRate(builder, g_samplingRate);
    OH_AudioStreamBuilder_SetChannelCount(builder, g_channelCount);

    OH_AudioRenderer_Callbacks callbacks;
    callbacks.OH_AudioRenderer_OnWriteData = AudioRendererOnWriteData;
    ret = OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
    printf("setcallback ret: %d \n", ret);

    // 3. create OH_AudioRenderer
    OH_AudioRenderer* audioRenderer;
    ret = OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
    printf("create renderer client, ret: %d \n", ret);

    // 4. start
    ret = OH_AudioRenderer_Start(audioRenderer);
    printf("start ret: %d \n", ret);

    int timer = 0;
    while (!g_readEnd) {
        std::this_thread::sleep_for(std::chrono::milliseconds(AudioTestConstants::WAIT_INTERVAL));
        printf("Wait for the audio to finish playing.(..%d s)\n", ++timer);
    }

    // 5. stop and release client
    ret = OH_AudioRenderer_Stop(audioRenderer);
    printf("stop ret: %d \n", ret);
    ret = OH_AudioRenderer_Release(audioRenderer);
    printf("release ret: %d \n", ret);

    // 6. destroy the builder
    ret = OH_AudioStreamBuilder_Destroy(builder);
    printf("destroy builder ret: %d \n", ret);
}

int main(int argc, char *argv[])
{
    printf("start \n");
    if ((argv == nullptr) || (argc < AudioTestConstants::THIRD_ARG_IDX)) {
        printf("input parms wrong. input format: filePath samplingRate channelCount \n");
        printf("input demo: ./oh_audio_renderer_test ./oh_test_audio.pcm 48000 2 \n");
        return 0;
    }
    printf("argc=%d ", argc);
    printf("argv[1]=%s ", argv[AudioTestConstants::FIRST_ARG_IDX]);
    printf("argv[2]=%s ", argv[AudioTestConstants::SECOND_ARG_IDX]);
    printf("argv[3]=%s \n", argv[AudioTestConstants::THIRD_ARG_IDX]);

    g_samplingRate = atoi(argv[AudioTestConstants::SECOND_ARG_IDX]);
    g_channelCount = atoi(argv[AudioTestConstants::THIRD_ARG_IDX]);
    g_filePath = argv[AudioTestConstants::FIRST_ARG_IDX];
    printf("filePATH: %s \n", g_filePath.c_str());

    g_file = fopen(g_filePath.c_str(), "rb");
    if (g_file == nullptr) {
        printf("OHAudioRendererTest: Unable to open file \n");
        return 0;
    }

    PlayerTest(argv);

    fclose(g_file);
    g_file = nullptr;
    return 0;
}

#ifdef __cplusplus
}
#endif
```
