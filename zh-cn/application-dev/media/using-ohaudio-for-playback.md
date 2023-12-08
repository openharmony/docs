# 使用OHAudio开发音频播放功能

OHAudio是OpenHarmony在API version 10中引入的一套全新Native API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。

## 使用入门

开发者要使用OHAudio提供的播放或者录制能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```
### 添加头文件
开发者通过引入<[native_audiostreambuilder.h](../reference/native-apis/native__audiostreambuilder_8h.md)>和<[native_audiorenderer.h](../reference/native-apis/native__audiorenderer_8h.md)>头文件，使用音频播放相关API。

```cpp
#include "ohaudio/native_audiorenderer.h"
#include "ohaudio/native_audiostreambuilder.h"
```

## 音频流构造器

OHAudio提供OH_AudioStreamBuilder接口，遵循构造器设计模式，用于构建音频流。开发者需要根据业务场景，指定对应的[OH_AudioStream_Type](../reference/native-apis/_o_h_audio.md#oh_audiostream_type) 。

`OH_AudioStream_Type`包含两种类型：

- AUDIOSTREAM_TYPE_RENDERER
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

详细的API说明请参考[OHAudio API参考](../reference/native-apis/_o_h_audio.md)。

开发者可以通过以下几个步骤来实现一个简单的播放功能。

1. 创建构造器

    ```c++
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
    ```

2. 配置音频流参数

    创建音频播放构造器后，可以设置音频流所需要的参数，可以参考下面的案例。

    ```c++
    OH_AudioStreamBuilder_SetSamplingRate(builder, rate);
    OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
    OH_AudioStreamBuilder_SetSampleFormat(builder, format);
    OH_AudioStreamBuilder_SetEncodingType(builder, encodingType);
    OH_AudioStreamBuilder_SetRendererInfo(builder, usage);
    ```

    注意，播放的音频数据要通过回调接口写入，开发者要实现回调接口，使用`OH_AudioStreamBuilder_SetRendererCallback`设置回调函数。回调函数的声明请查看[OH_AudioRenderer_Callbacks](../reference/native-apis/_o_h_audio.md#oh_audiorenderer_callbacks) 。


3. 设置回调函数

    ```c++
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
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
## 完整示例

```cpp
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <thread>
#include <chrono>
#include <ctime>
#include "ohaudio/native_audiorenderer.h"
#include "ohaudio/native_audiostreambuilder.h"

#ifdef __cplusplus
extern "C" {
#endif
namespace AudioTestConstants {
constexpr int32_t WAIT_INTERVAL = 1000;
} // namespace AudioTestConstants

// 确保该目录下有对应的资源可以播放
std::string g_filePath = "/data/data/oh_test_audio.pcm";
FILE *g_file = nullptr;
bool g_readEnd = false;
// 音频采样率
int32_t g_samplingRate = 48000;
// 音频声道数
int32_t g_channelCount = 2;
// 音频场景：0代表正常场景，1代表低时延场景
int32_t g_latencyMode = 0;
// 音频采样格式
int32_t g_sampleFormat = 1;

// 回调函数, 播放的音频数据要通过回调接口写入
static int32_t AudioRendererOnWriteData(OH_AudioRenderer *capturer, void *userData, void *buffer, int32_t bufferLen) {
    size_t readCount = fread(buffer, bufferLen, 1, g_file);
    if (!readCount) {
        if (ferror(g_file)) {
            printf("Error reading myfile");
        } else if (feof(g_file)) {
            printf("EOF found");
            g_readEnd = true;
        }
    }
    return 0;
}

void PlayerTest() {
    OH_AudioStream_Result ret;

    // 1. 创建构造器
    OH_AudioStreamBuilder *builder;
    OH_AudioStream_Type type = AUDIOSTREAM_TYPE_RENDERER;
    ret = OH_AudioStreamBuilder_Create(&builder, type);

    // 2. 设置音频流所需要的参数
    OH_AudioStreamBuilder_SetSamplingRate(builder, g_samplingRate);
    OH_AudioStreamBuilder_SetChannelCount(builder, g_channelCount);
    OH_AudioStreamBuilder_SetLatencyMode(builder, (OH_AudioStream_LatencyMode)g_latencyMode);
    OH_AudioStreamBuilder_SetSampleFormat(builder, (OH_AudioStream_SampleFormat)g_sampleFormat);

    // 设置回调函数, 播放的音频数据要通过回调接口写入
    OH_AudioRenderer_Callbacks callbacks;
    callbacks.OH_AudioRenderer_OnWriteData = AudioRendererOnWriteData;
    ret = OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);

    // 3. 构造播放音频流
    OH_AudioRenderer *audioRenderer;
    ret = OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);

    // 4. 开始播放
    ret = OH_AudioRenderer_Start(audioRenderer);

    int timer = 0;
    while (!g_readEnd) {
        std::this_thread::sleep_for(std::chrono::milliseconds(AudioTestConstants::WAIT_INTERVAL));
        int64_t frames;
        OH_AudioRenderer_GetFramesWritten(audioRenderer, &frames);
        printf("Wait for the audio to finish playing.(..%d s) frames:%ld\n", ++timer, frames);
        int64_t framePosition;
        int64_t timestamp;
        OH_AudioRenderer_GetTimestamp(audioRenderer, CLOCK_MONOTONIC, &framePosition, &timestamp);
        printf("framePosition %ld timestamp:%ld\n", framePosition, timestamp);
    }
    // 5. 停止播放
    ret = OH_AudioRenderer_Stop(audioRenderer);
    
    // 释放播放实例
    ret = OH_AudioRenderer_Release(audioRenderer);

    // 6. 释放构造器
    ret = OH_AudioStreamBuilder_Destroy(builder);
}

int main() {
    // 播放前需要先打开文件
    g_file = fopen(g_filePath.c_str(), "rb");
    if (g_file == nullptr) {
        printf("OHAudioRendererTest: Unable to open file \n");
        return 0;
    }
    // 开始播放
    PlayerTest();
    // 播放完成后关闭文件资源
    fclose(g_file);
    g_file = nullptr;
    return 0;
}

#ifdef __cplusplus
}
#endif
```

## 设置低时延模式

当设备支持低时延通路时，开发者可以使用低时延模式创建播放器，获得更高质量的音频体验。

开发流程与普通播放场景一致，仅需要在创建音频流构造器时，调用[OH_AudioStreamBuilder_SetLatencyMode()](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_setlatencymode)设置低时延模式。

开发示例

```C
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```
