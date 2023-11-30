# 使用OHAudio开发音频录制功能

OHAudio是OpenHarmony在API version 10中引入的一套全新Naitve API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。

## 使用入门

开发者要使用OHAudio提供的播放或者录制能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```
### 添加头文件
开发者通过引入<[native_audiostreambuilder.h](../reference/native-apis/native__audiostreambuilder_8h.md)>和<[native_audiocapturer.h](../reference/native-apis/native__audiocapturer_8h.md)>头文件，使用音频录制相关API。

```cpp
#include "ohaudio/native_audiocapturer.h"
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

开发者可以通过以下几个步骤来实现一个简单的录制功能。


1. 创建构造器

    ```c++
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
    ```

2. 配置音频流参数

    创建音频录制构造器后，可以设置音频流所需要的参数，可以参考下面的案例。

    ```c++
    OH_AudioStreamBuilder_SetSamplingRate(builder, rate);
    OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
    OH_AudioStreamBuilder_SetSampleFormat(builder, format);
    OH_AudioStreamBuilder_SetEncodingType(builder, encodingType);
    OH_AudioStreamBuilder_SetCapturerInfo(builder, sourceType);
    ```

    同样，音频录制的音频数据要通过回调接口写入，开发者要实现回调接口，使用`OH_AudioStreamBuilder_SetCapturerCallback`设置回调函数。回调函数的声明请查看[OH_AudioCapturer_Callbacks](../reference/native-apis/_o_h_audio.md#oh_audiocapturer_callbacks) 。

3. 设置音频回调函数

    ```c++
    OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
    ```

4. 构造录制音频流

    ```c++
    OH_AudioCapturer* audioCapturer;
    OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
    ```

5. 使用音频流

    录制音频流包含下面接口，用来实现对音频流的控制。

    | 接口                                                         | 说明         |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer) | 开始录制     |
    | OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer) | 暂停录制     |
    | OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer) | 停止录制     |
    | OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer) | 释放缓存数据 |
    | OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer) | 释放录制实例 |

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
#include "ohaudio/native_audiocapturer.h"
#include "ohaudio/native_audiostreambuilder.h"
#include <thread>
#include <chrono>

#ifdef __cplusplus
extern "C" {
#endif
namespace AudioTestConstants {
constexpr int32_t RECODER_TIME = 10000;
constexpr int32_t COUNTDOWN_INTERVAL = 1000;
constexpr int32_t CONVERT_RATE = 1000;
} // namespace AudioTestConstants

// 确保该目录下有该文件或者应用有权限在该目录下创建文件
std::string g_filePath = "/data/data/oh_test_audio.pcm";
FILE *g_file = nullptr;
// 音频采样率
int32_t g_samplingRate = 48000;
// 音频声道数
int32_t g_channelCount = 2;
// 音频场景：0代表正常场景，1代表低时延场景
int32_t g_latencyMode = 0;
// 音频采样格式
int32_t g_sampleFormat = 1;

// 回调函数, 音频录制的音频数据要通过回调接口写入
static int32_t AudioCapturerOnReadData(OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t bufferLen) {
    size_t count = 1;
    if (fwrite(buffer, bufferLen, count, g_file) != count) {
        printf("buffer fwrite err");
    }

    return 0;
}

void SleepWaitRecoder(bool *stop) {
    std::this_thread::sleep_for(std::chrono::milliseconds(AudioTestConstants::RECODER_TIME));
    *stop = true;
}

void RecorderTest() {
    OH_AudioStream_Result ret;

    // 1. 创建构造器
    OH_AudioStreamBuilder *builder;
    OH_AudioStream_Type type = AUDIOSTREAM_TYPE_CAPTURER;
    ret = OH_AudioStreamBuilder_Create(&builder, type);

    // 2. 设置音频流所需要的参数
    OH_AudioStreamBuilder_SetSamplingRate(builder, g_samplingRate);
    OH_AudioStreamBuilder_SetChannelCount(builder, g_channelCount);
    OH_AudioStreamBuilder_SetLatencyMode(builder, (OH_AudioStream_LatencyMode)g_latencyMode);
    OH_AudioStreamBuilder_SetSampleFormat(builder, (OH_AudioStream_SampleFormat)g_sampleFormat);

    // 设置回调函数, 音频录制的音频数据要通过回调接口写入
    OH_AudioCapturer_Callbacks callbacks;
    callbacks.OH_AudioCapturer_OnReadData = AudioCapturerOnReadData;
    ret = OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);

    // 3. 构造录制音频流
    OH_AudioCapturer *audioCapturer;
    ret = OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);

    // 4. 开始录制
    ret = OH_AudioCapturer_Start(audioCapturer);

    bool stop = false;
    std::thread stopthread(SleepWaitRecoder, &stop);
    stopthread.detach();

    int timeLeft = AudioTestConstants::RECODER_TIME;
    while (!stop) {
        std::this_thread::sleep_for(std::chrono::milliseconds(AudioTestConstants::COUNTDOWN_INTERVAL));
        timeLeft = timeLeft - AudioTestConstants::COUNTDOWN_INTERVAL;
    }

    // 5. 停止录制
    ret = OH_AudioCapturer_Stop(audioCapturer);
    // 释放录制实例
    ret = OH_AudioCapturer_Release(audioCapturer);

    // 6. 释放构造器
    ret = OH_AudioStreamBuilder_Destroy(builder);
}


int main() {
    // 录制前需要先打开文件
    g_file = fopen(g_filePath.c_str(), "wb");
    if (g_file == nullptr) {
        printf("OHAudioCapturerTest: Unable to open file \n");
        return 0;
    }
    // 开始录制
    RecorderTest();
    // 录制完成后关闭文件资源
    fclose(g_file);
    g_file = nullptr;
    return 0;
}
#ifdef __cplusplus
}
#endif
```

## 设置低时延模式

当设备支持低时延通路时，开发者可以使用低时延模式创建音频录制构造器，获得更高质量的音频体验。

开发流程与普通录制场景一致，仅需要在创建音频录制构造器时，调用[OH_AudioStreamBuilder_SetLatencyMode()](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_setlatencymode)设置低时延模式。

开发示例

```C
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```
