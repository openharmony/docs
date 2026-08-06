# Low-Latency Audio Recording (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=6482e1478c8300c06759225778677b39973d7297 translatedAt=2026-08-06T01:41:49.902Z pushedAt=2026-08-06T03:27:58.405Z -->

Starting from API version 10, low-latency audio recording is available.

Low-latency audio recording is an audio rendering solution that leverages software-hardware-chip synergy. By reducing buffer sizes and optimizing the data read/write architecture, this mode delivers significantly lower audio recording latency.

## Prerequisites

- Audio input devices support the low-latency mode.

- You can call [OH_AudioCapturer_GetFastStatus()](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_getfaststatus) to check whether the current device supports the low-latency mode.

## Development Guidelines

  The examples in each of the following steps are code snippets. You can click the link at the bottom right of the sample code to obtain the [complete sample codes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC).

### Overview

To use the low-latency mode, you need to develop audio recording by referring to [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

Currently, OHAudio supports two modes: normal mode (**AUDIOSTREAM_LATENCY_MODE_NORMAL**) and low-latency mode (**AUDIOSTREAM_LATENCY_MODE_FAST**).

### Setting the Low-Latency Mode

You can specify which mode the audio stream should use by calling [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode) to set [OH_AudioStream_LatencyMode](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode).

The following is an example of setting the low-latency mode:

<!-- @[latencyMode_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

The following sample is provided to help you better understand how to develop audio recording with OHAudio:

- [OHAudio Recording and Playback](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/OHAudio)

## Precautions

### Low-Latency Mode Restrictions

The system uses the normal mode under the following conditions, even if the low-latency mode is set:

- The current device does not support the low-latency mode.

- The current stream format does not support the low-latency mode.

- All low-latency resources are already in use.

- A higher-priority stream (for example, VoIP call) is active.

Starting from API version 20, low-latency query APIs are available:

- You can call [OH_AudioCapturer_GetFastStatus()](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_getfaststatus) to check whether the audio recording stream is operating in low-latency mode.

- In certain special scenarios (for example, when a higher-priority stream exists or the currently connected device does not support the mode), you can call [OH_AudioCapturer_OnFastStatusChange()](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_onfaststatuschange) to obtain low-latency status change events.

### Recommended Use Cases

- For latency-sensitive scenarios such as karaoke and live streaming, the low-latency mode is recommended.

- For non-real-time scenarios such as common audio recording, video recording, and screen capture, the low-latency mode is not recommended.

### Ensuring Timely Data Reading

In low-latency mode, the application must read data more frequently than in normal recording mode. Delays in data reading may cause audio artifacts such as noise. Avoid time-consuming operations in the data callback thread to ensure it returns promptly.

### Data Callback Thread

Audio data to be recorded is read through the callback API. Implement the callback API and call [OH_AudioStreamBuilder_SetCapturerReadDataCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setcapturerreaddatacallback) to set the callback function [OH_AudioCapturer_OnReadDataCallback](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_onreaddatacallback). This function is used to read audio data and supported since API version 12.

For details about the sample code for developing audio recording, please refer to [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

The following is an example of setting the data callback function:

<!-- @[SetCapturerReadDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
int32_t MyOnReadData_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // Obtain captured data of the specified length from the buffer.
    return 0;
}
// ...
    // Configure the callback function for reading audio data.
    OH_AudioCapturer_OnReadDataCallback readDataCb = MyOnReadData_NewAPI;
    OH_AudioStreamBuilder_SetCapturerReadDataCallback(builder, readDataCb, nullptr);
```

- To prevent audio stuttering, do not perform time-consuming operations in the callback function **OH_AudioCapturer_OnReadData**.

- To maintain independence between **OH_AudioCapturer_OnReadData** and stream state control, do not call the audio stream control APIs in the callback function **OH_AudioCapturer_OnReadData**.

    | Audio Stream Control API                                                   | Description        |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer) | Starts the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer) | Pauses the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer) | Stops the audio capturer.    |
    | OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer) | Flushes obtained audio data.|
    | OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer) | Releases the audio capturer instance.|

    > **NOTE**
    >
    > The execution of audio stream control APIs is time-consuming (for example, a single execution of **OH_AudioCapturer_Stop** generally takes more than 50 ms). Direct calls to these APIs on the main thread should be avoided to prevent interface display freezes.