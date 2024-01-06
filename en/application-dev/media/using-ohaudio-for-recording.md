# Using OHAudio for Audio Recording (C/C++)

**OHAudio** is a set of native APIs introduced in API version 10. These APIs are normalized in design and support both common and low-latency audio channels.

## Prerequisites

To use the playback or recording capability of **OHAudio**, you must first import the corresponding header files.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```
### Adding Header Files
To use APIs for audio recording, import <[native_audiostreambuilder.h](../reference/native-apis/native__audiostreambuilder_8h.md)> and <[native_audiocapturer.h](../reference/native-apis/native__audiocapturer_8h.md)>.

```cpp
#include <ohaudio/native_audiocapturer.h>
#include <ohaudio/native_audiostreambuilder.h>
```
## Audio Stream Builder

**OHAudio** provides the **OH_AudioStreamBuilder** class, which complies with the builder design pattern and is used to build audio streams. You need to specify [OH_AudioStream_Type](../reference/native-apis/_o_h_audio.md#oh_audiostream_type) based on your service scenarios.

**OH_AudioStream_Type** can be set to either of the following:

- AUDIOSTREAM_TYPE_RENDERER
- AUDIOSTREAM_TYPE_CAPTURER

The following code snippet shows how to use [OH_AudioStreamBuilder_Create](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_create) to create a builder:

```
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, streamType);
```

After the audio service is complete, call [OH_AudioStreamBuilder_Destroy](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_destroy) to destroy the builder.

```
OH_AudioStreamBuilder_Destroy(builder);
```

## How to Develop

Read [OHAudio](../reference/native-apis/_o_h_audio.md) for the API reference.

The following walks you through how to implement simple recording:


1. Create an audio stream builder.

    ```c++
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
    ```

2. Set audio stream parameters.

    After creating the builder for audio recording, set the parameters required.

    ```c++
    OH_AudioStreamBuilder_SetSamplingRate(builder, rate);
    OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
    OH_AudioStreamBuilder_SetSampleFormat(builder, format);
    OH_AudioStreamBuilder_SetEncodingType(builder, encodingType);
    OH_AudioStreamBuilder_SetCapturerInfo(builder, sourceType);
    ```

    Note that the audio data to record is written through callbacks. You must call **OH_AudioStreamBuilder_SetCapturerCallback** to implement the callbacks. For details about the declaration of the callback functions, see [OH_AudioCapturer_Callbacks](../reference/native-apis/_o_h_audio.md#oh_audiocapturer_callbacks).

3. Set the callback functions.

    ```c++
    OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
    ```

4. Create an audio capturer instance.

    ```c++
    OH_AudioCapturer* audioCapturer;
    OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
    ```

5. Use the audio capturer.

    You can use the APIs listed below to control the audio streams.

    | API                                                        | Description        |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer) | Starts the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer) | Pauses the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer) | Stops the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer) | Flushes obtained audio data.|
    | OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer) | Releases the audio capturer instance.|

6. Destroy the audio stream builder.

    When the builder is no longer used, release related resources.

    ```c++
    OH_AudioStreamBuilder_Destroy(builder);
    ```
## Example

```cpp
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <ohaudio/native_audiocapturer.h>
#include <ohaudio/native_audiostreambuilder.h>
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

// Ensure that the file exists in the directory or the application has the permission to create files in the directory.
std::string g_filePath = "/data/data/oh_test_audio.pcm";
FILE *g_file = nullptr;
// Audio sampling rate.
int32_t g_samplingRate = 48000;
// Number of audio channels.
int32_t g_channelCount = 2;
// Audio scenario. The value 0 indicates the normal scenario, and 1 indicates the low-latency scenario.
int32_t g_latencyMode = 0;
// Audio sample format.
int32_t g_sampleFormat = 1;

// Callback, through which the recorded audio data will be written.
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

    // 1. Create an audio stream builder.
    OH_AudioStreamBuilder *builder;
    OH_AudioStream_Type type = AUDIOSTREAM_TYPE_CAPTURER;
    ret = OH_AudioStreamBuilder_Create(&builder, type);

    // 2. Set the parameters required by the audio stream.
    OH_AudioStreamBuilder_SetSamplingRate(builder, g_samplingRate);
    OH_AudioStreamBuilder_SetChannelCount(builder, g_channelCount);
    OH_AudioStreamBuilder_SetLatencyMode(builder, (OH_AudioStream_LatencyMode)g_latencyMode);
    OH_AudioStreamBuilder_SetSampleFormat(builder, (OH_AudioStream_SampleFormat)g_sampleFormat);

    // Set the callback, through which the recorded audio data will be written.
    OH_AudioCapturer_Callbacks callbacks;
    callbacks.OH_AudioCapturer_OnReadData = AudioCapturerOnReadData;
    ret = OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);

    // 3. Create an audio capturer instance.
    OH_AudioCapturer *audioCapturer;
    ret = OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);

    // 4. Start recording.
    ret = OH_AudioCapturer_Start(audioCapturer);

    bool stop = false;
    std::thread stopthread(SleepWaitRecoder, &stop);
    stopthread.detach();

    int timeLeft = AudioTestConstants::RECODER_TIME;
    while (!stop) {
        std::this_thread::sleep_for(std::chrono::milliseconds(AudioTestConstants::COUNTDOWN_INTERVAL));
        timeLeft = timeLeft - AudioTestConstants::COUNTDOWN_INTERVAL;
    }

    // 5. Stop recording.
    ret = OH_AudioCapturer_Stop(audioCapturer);
    // Release the audio capturer instance.
    ret = OH_AudioCapturer_Release(audioCapturer);

    // 6. Destroy the audio stream builder.
    ret = OH_AudioStreamBuilder_Destroy(builder);
}


int main() {
    // Open the file before recording.
    g_file = fopen(g_filePath.c_str(), "wb");
    if (g_file == nullptr) {
        printf("OHAudioCapturerTest: Unable to open file \n");
        return 0;
    }
    // Start recording.
    RecorderTest();
    // Close the file after the recording is complete.
    fclose(g_file);
    g_file = nullptr;
    return 0;
}
#ifdef __cplusplus
}
#endif
```

## Setting the Low Latency Mode

If the device supports the low-latency channel, you can use the low-latency mode to create an audio capturer for a higher-quality audio experience.

The development process is similar to that in the common recording scenario. The only difference is that you need to set the low delay mode by calling [OH_AudioStreamBuilder_SetLatencyMode()](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_setlatencymode) when creating an audio stream builder.

Code snippet:

```C
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```
