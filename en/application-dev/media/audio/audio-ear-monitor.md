# Implementing Custom Audio Monitoring

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @tom_guo-->
<!--Designer: @trytocalm-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=cc1631b0a685b25b8a7c643aeb7d2e2b37b2f675 translatedAt=2026-08-06T01:41:14.182Z pushedAt=2026-08-06T03:44:36.892Z -->

Audio monitoring enables real-time transmission of audio to headphones, allowing users to hear themselves or other relevant sounds in real time.

This feature is commonly used in karaoke applications, where the recorded vocals and background music are sent to the headphones in real time. This allows users to adjust their performance based on the feedback, enhancing their experience.

## Prerequisites

- You can use the playback and recording capabilities provided by OHAudio to implement audio monitoring. The audio data captured during recording is used as the input for playback.

  For details, please refer to [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md) and [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

- Currently, audio monitoring is only supported through wired headphones, where audio is both captured and played back.

## When to Use

By combining the system playback and recording capabilities, you can implement audio monitoring within an app. This is suitable for scenarios where the app needs to process recorded data on its own. For example, the app can apply custom audio effect algorithms to the recorded data before playback to achieve specific sound effects. Since the data must be processed by the app, the latency is higher than that of the system audio monitoring.

## How to Develop

The examples in the following steps are code snippets. You can access the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioCapturerSampleC) via the link at the bottom right of each sample code.

### Creating an Audio Recording Builder

Use `OH_AudioStreamBuilder` provided by OHAudio, following the builder design pattern, to construct an audio recording stream. Specify the corresponding [OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type) and set it to `AUDIOSTREAM_TYPE_CAPTURER`.

<!-- @[Create_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
```

### Creating an Audio Playback Builder

Use the `OH_AudioStreamBuilder` interface provided by OHAudio, following the builder design pattern, to construct an audio playback stream. Specify the corresponding [OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type) and set it to `AUDIOSTREAM_TYPE_RENDERER`.

<!-- @[Create_Renderer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```

### Setting the Low Latency Mode

To achieve better audio monitoring, it is essential to maintain low latency from recording to playback. When the device supports low-latency channels, you should use the low latency mode for both recording and playback.

When creating the audio recording builder, call [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode) to set the low latency mode, and apply it to both recording and playback as follows:

<!-- @[latencyMode_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

To implement real-time audio monitoring, you need to create a shared buffer for storing recorded data and promptly retrieve data from this buffer to write to the playback builder.

### Defining the Shared Buffer and Recording/Playback Functions

<!-- @[public_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

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
int32_t MyOnWriteData(
    OH_AudioRenderer* renderer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // Read data from the shared buffer and write it to the buffer based on the specified length.
    return 0;
}
```

> **NOTE**
>
> Do not set the shared buffer too large, as it can increase audio monitor latency and degrade user experience. Select an appropriate buffer size based on latency and anti-jitter requirements to ensure a good user experience.

### Setting Audio Stream Parameters

The following provides an example of setting parameters for the audio recording stream:

<!-- @[Configure_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
// Set the audio sampling rate.
const int SAMPLING_RATE_48K = 48000;
OH_AudioStreamBuilder_SetSamplingRate(builder, SAMPLING_RATE_48K);
// Set the number of audio channels.
const int channelCount = 2;
OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
// Set the audio sampling format.
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
// Set the encoding type of the audio stream.
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// Set the usage scenario of the audio capturer.
OH_AudioStreamBuilder_SetCapturerInfo(builder, AUDIOSTREAM_SOURCE_TYPE_MIC);
```

For the playback stream, set the same parameters as the recording stream, except for the working scenario.

Set the working scenario parameter as follows:

<!-- @[SetRendererInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
```

### Setting Recording Callback Functions

<!-- @[SetCapturerCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

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
int32_t MyOnInterruptEvent_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // Update the capturer status and UI based on the audio interruption information indicated by type and hint.
    return 0;
}

int32_t MyOnStreamEvent_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Event event)
{
    // Update the capturer status and UI based on the audio stream event information indicated by the event.
    return 0;
}

int32_t MyOnError_Legacy(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Result error)
{
    // Perform operations based on the audio exception information indicated by error.
    return 0;
}
// ...
    OH_AudioCapturer_Callbacks callbacks;
    // Set the callbacks.
    callbacks.OH_AudioCapturer_OnReadData = MyOnReadData_Legacy;
    callbacks.OH_AudioCapturer_OnStreamEvent = MyOnStreamEvent_Legacy;
    callbacks.OH_AudioCapturer_OnInterruptEvent = MyOnInterruptEvent_Legacy;
    callbacks.OH_AudioCapturer_OnError = MyOnError_Legacy;

    OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
```

### Setting Playback Callback Functions

<!-- @[SetRendererCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->  

``` C++
int32_t MyOnWriteData(
    OH_AudioRenderer* renderer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // Read data from the shared buffer and write it into the buffer based on the length.
    return 0;
}
int32_t MyOnStreamEvent_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioStream_Event event)
{
    // Update the player status and UI based on the audio stream event information indicated by the event.
    return 0;
}

int32_t MyOnInterruptEvent_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // Update the player status and UI based on the audio interruption information indicated by type and hint.
    return 0;
}

int32_t MyOnError_Renderer(
    OH_AudioRenderer* renderer,
    void* userData,
    OH_AudioStream_Result error)
{
    // Perform operations based on the audio exception information indicated by error.
    return 0;
}
// ...
    OH_AudioRenderer_Callbacks callbacks;
    
    // Set the callbacks.
    callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
    callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent_Renderer;
    callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent_Renderer;
    callbacks.OH_AudioRenderer_OnError = MyOnError_Renderer;

    // Set callbacks for the audio renderer.
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
```

### Creating an Audio Capturer

<!-- @[GenerateCapturer_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioCapturer* audioCapturer;
OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
```

### Creating an Audio Renderer

<!-- @[GenerateRenderer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioRenderer* audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### Using Audio Streams

Taking playback as an example, you can use the following APIs to control the start, pause, stop, and release of an audio stream.

> **NOTE**
> 
> When implementing audio monitoring, you need to control both the recording and playback streams to ensure their synchronization.

| API                                                    | Description        |
| ------------------------------------------------------------ | ------------ |
| OH_AudioStream_Result [OH_AudioRenderer_Start](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_start)(OH_AudioRenderer* renderer) | Starts the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Pause](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_pause)(OH_AudioRenderer* renderer) | Pauses the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Stop](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_stop)(OH_AudioRenderer* renderer) | Stops the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Flush](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_flush)(OH_AudioRenderer* renderer) | Flushes obtained audio data.|
| OH_AudioStream_Result [OH_AudioRenderer_Release](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_release)(OH_AudioRenderer* renderer) | Releases the audio renderer.|

### Releasing the Builder

When the builder is no longer required, release the resources as follows:

<!-- @[Destroy_Capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

``` C++
OH_AudioStreamBuilder_Destroy(builder);
```