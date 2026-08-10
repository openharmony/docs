# Low-Latency Audio Playback (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T10:46:23.786Z pushedAt=2026-08-06T10:50:08.071Z -->

Starting from API version 10, low-latency audio playback is available.

Low-latency audio playback is an audio rendering solution that leverages software-hardware-chip synergy. By reducing buffer sizes and optimizing the data read/write architecture, this mode delivers significantly lower audio playback latency.

## Prerequisites

- Audio output devices support the low-latency mode.

- You can call [OH_AudioRenderer_GetFastStatus()](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_getfaststatus) to check whether the current device supports the low-latency mode.

## Development Guidelines

  The examples below are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRendererSampleC) via the link at the bottom right of each code example.

### Overview

To use the low-latency mode, you need to develop audio playback by referring to [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

Currently, OHAudio supports two modes: normal mode (**AUDIOSTREAM_LATENCY_MODE_NORMAL**) and low-latency mode (**AUDIOSTREAM_LATENCY_MODE_FAST**).

### Setting the Low-Latency Mode

You can specify which mode the audio stream should use by calling [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode) to set [OH_AudioStream_LatencyMode](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode).

The following is an example of setting the low-latency mode:

<!-- @[OH_AudioStreamBuilder_SetLatencyMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

The following sample is provided to help you better understand how to develop audio playback with **OHAudio**:

- [OHAudio Recording and Playback](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/OHAudio)

## Precautions

### Low-Latency Mode Restrictions

The system uses the normal mode under the following conditions, even if the low-latency mode is set:

- The current device does not support the low-latency mode.

- The current stream format does not support the low-latency mode.

- All low-latency resources are already in use.

- A higher-priority stream (for example, cellular call) is active.

Starting from API version 20, low-latency query APIs are available:

- You can call [OH_AudioRenderer_GetFastStatus()](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_getfaststatus) to check whether the audio playback stream is operating in low-latency mode.

- In special scenarios (for example, a higher-priority stream is active or the current device does not support the low-latency mode), you can call [OH_AudioRenderer_OnFastStatusChange()](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_onfaststatuschange) to subscribe to low-latency status change events.

> **NOTE**
>
> The playback speed cannot be adjusted in low-latency mode.

### Recommended Use Cases

- For latency-sensitive scenarios such as gaming, karaoke, and live streaming, the low-latency mode is recommended.

- For latency-insensitive scenarios such as video playback and music playback, the low-latency mode is not recommended.

### Ensuring Timely Data Supply

In low-latency mode, the application must supply data more frequently than in normal playback mode. Delays in data transmission may cause audio artifacts such as noise. Avoid time-consuming operations in the data callback thread to ensure it returns promptly.

### Data Callback Thread

Audio data to be played is written through the callback API. Implement the callback API and call [OH_AudioStreamBuilder_SetRendererWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setrendererwritedatacallback) to set the callback function [OH_AudioRenderer_OnWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback). This function is used to write audio data and supported since API version 12.

For details about the sample code for developing audio playback, please refer to [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

The following is an example of setting the data callback function:

<!-- @[Render_SetRendererWriteDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->  

``` C++
// Customize a function to write data.
static OH_AudioData_Callback_Result MyOnWriteData_New(
    OH_AudioRenderer* renderer,
    void* userData,
    void* audioData,
    int32_t audioDataSize)
{
    // Write the data to be played to audioData by audioDataSize.
    // If you do not want to play a segment of audioData, return AUDIO_DATA_CALLBACK_RESULT_INVALID.
    size_t readCount = fread(audioData, audioDataSize, 1, g_fp);
    if (readCount == 0) {
        return AUDIO_DATA_CALLBACK_RESULT_INVALID;
    }
    if (feof(g_fp)) {
        fseek(g_fp, 0, SEEK_SET);
    }
    return AUDIO_DATA_CALLBACK_RESULT_VALID;
}
// ...
    // Configure the callback function for writing audio data.
    OH_AudioRenderer_OnWriteDataCallback writeDataCb = MyOnWriteData_New;
    OH_AudioStreamBuilder_SetRendererWriteDataCallback(builder, writeDataCb, nullptr);
```

- To prevent audio stuttering, do not perform time-consuming operations in the callback function **OH_AudioRenderer_OnWriteDataCallback**.

- To maintain independence between data writing logic and stream state control, do not call the audio stream control APIs in the callback function **OH_AudioRenderer_OnWriteData**.

    | Audio Stream Control API                                                   | Description        |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer) | Starts the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer) | Pauses the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer) | Stops the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | Flushes obtained audio data.|
    | OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | Releases the audio renderer.|

    > **NOTE**
    >
    > The execution of audio stream control APIs is time-consuming (for example, a single execution of **OH_AudioRenderer_Stop** generally takes more than 50 ms as it needs to play through the cache). Direct calls to these APIs on the main thread should be avoided to prevent interface display freezes.