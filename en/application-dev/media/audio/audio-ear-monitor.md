# Audio Monitoring

Audio monitoring enables real-time transmission of audio to headphones, allowing users to hear themselves or other relevant sounds in real time.

This feature is commonly used in karaoke applications, where the recorded vocals and background music are sent to the headphones in real time. This allows users to adjust their performance based on the feedback, enhancing their experience.

## Prerequisites

- You can use the playback and recording capabilities provided by **OHAudio** to implement audio monitoring. The audio data captured during recording is used as the input for playback.

  For details, see [Using OHAudio for Audio Playback](using-ohaudio-for-playback.md) and [Using OHAudio for Audio Recording](using-ohaudio-for-recording.md).

- Currently, audio monitoring is only supported through wired headphones, where audio is both captured and played back.

## How to Develop

### Creating an Audio Recording Builder

Use the **OH_AudioStreamBuilder** function provided by **OHAudio** to create an audio recording builder, following the builder design pattern. Set [OH_AudioStream_Type](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_type) to **AUDIOSTREAM_TYPE_CAPTURER**.

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
```

### Creating an Audio Playback Builder

Use the **OH_AudioStreamBuilder** function provided by **OHAudio** to create an audio playback builder, following the builder design pattern. Set [OH_AudioStream_Type](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_type) to **AUDIOSTREAM_TYPE_RENDERER**.

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
```

### Setting the Low Latency Mode

To achieve better audio monitoring, it is essential to maintain low latency from recording to playback. When the device supports low-latency channels, you should use the low latency mode for both recording and playback.

When creating the audio recording builder, call [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setlatencymode) to set the low latency mode, and apply it to both recording and playback as follows:

```cpp
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

To implement real-time audio monitoring, create a shared buffer to store the captured data and promptly retrieve data from this buffer to write to the audio playback builder.

### Defining the Shared Buffer and Recording/Playback Functions

```cpp
// Create a shared buffer to store captured data and retrieve playback data in a timely manner.

// Customize a function to read captured data.
    int32_t MyOnReadData(
        OH_AudioCapturer* capturer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // Extract captured data with the specified length from the buffer and place the data in the shared buffer for the renderer to read.
        return 0;
    }

    // Customize a function to write data.
    int32_t MyOnWriteData(
        OH_AudioRenderer* renderer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // Read data from the shared buffer and write the data with the specified length into the buffer.
        return 0;
    }
```

### Setting Audio Stream Parameters

The following provides an example of setting parameters for the audio recording stream:

```cpp
// Set the audio sampling rate.
OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
// Set the number of audio channels.
OH_AudioStreamBuilder_SetChannelCount(builder, 2);
// Set the audio sampling format.
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
// Set the encoding type of the audio stream.
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// Set the usage scenario of the audio renderer.
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_SOURCE_TYPE_MIC);
```

For the playback stream, set the same parameters as the recording stream, except for the working scenario.

Set the working scenario parameter as follows:

```cpp
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
```

### Setting Recording Callback Functions

```cpp
// Customize a function to read data.
int32_t MyOnReadData(
    OH_AudioCapturer* capturer,
    void* userData,
    void* buffer,
    int32_t length)
{
    // Obtain captured data of the specified length from the buffer.
    return 0;
}
// Customize an audio stream event function.
int32_t MyOnStreamEvent(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Event event)
{
    // Update the capturer status and UI based on the audio stream event information indicated by the event.
    return 0;
}
// Customize an audio interruption event function.
int32_t MyOnInterruptEvent(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioInterrupt_ForceType type,
    OH_AudioInterrupt_Hint hint)
{
    // Update the capturer status and UI based on the audio interruption information indicated by type and hint.
    return 0;
}
// Customize an exception callback function.
int32_t MyOnError(
    OH_AudioCapturer* capturer,
    void* userData,
    OH_AudioStream_Result error)
{
    // Perform operations based on the audio exception information indicated by error.
    return 0;
}

OH_AudioCapturer_Callbacks callbacks;

// Set the callbacks.
callbacks.OH_AudioCapturer_OnReadData = MyOnReadData;
callbacks.OH_AudioCapturer_OnStreamEvent = MyOnStreamEvent;
callbacks.OH_AudioCapturer_OnInterruptEvent = MyOnInterruptEvent;
callbacks.OH_AudioCapturer_OnError = MyOnError;

// Set the callbacks for audio input streams.
OH_AudioStreamBuilder_SetCapturerCallback(builder, callbacks, nullptr);
```

### Setting Playback Callback Functions

```cpp
    // Customize a function to write data.
    int32_t MyOnWriteData(
        OH_AudioRenderer* renderer,
        void* userData,
        void* buffer,
        int32_t length)
    {
        // Read data from the shared buffer and write the data with the specified length into the buffer.
        return 0;
    }
    // Customize an audio stream event function.
    int32_t MyOnStreamEvent(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioStream_Event event)
    {
        // Update the player status and UI based on the audio stream event information indicated by the event.
        return 0;
    }
    // Customize an audio interruption event function.
    int32_t MyOnInterruptEvent(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioInterrupt_ForceType type,
        OH_AudioInterrupt_Hint hint)
    {
        // Update the player status and UI based on the audio interruption information indicated by type and hint.
        return 0;
    }
    // Customize an exception callback function.
    int32_t MyOnError(
        OH_AudioRenderer* renderer,
        void* userData,
        OH_AudioStream_Result error)
    {
        // Perform operations based on the audio exception information indicated by error.
        return 0;
    }

    OH_AudioRenderer_Callbacks callbacks;

    // Set the callbacks.
    callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
    callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent;
    callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
    callbacks.OH_AudioRenderer_OnError = MyOnError;

    // Set callbacks for the audio renderer.
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);

```

### Creating an Audio Capturer

```cpp
OH_AudioCapturer* audioCapturer;
OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
```

### Creating an Audio Renderer

```cpp
OH_AudioRenderer* audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### Using Audio Streams

The following uses recording as an example. You can use the following APIs to control the start, pause, stop, and release of audio streams.

> **NOTE**
>
> When implementing audio monitoring, you need to control both the recording and playback streams to ensure their synchronization.

| API                                                    | Description        |
| ------------------------------------------------------------ | ------------ |
| OH_AudioStream_Result [OH_AudioRenderer_Start](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_start)(OH_AudioRenderer* renderer) | Starts the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Pause](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_pause)(OH_AudioRenderer* renderer) | Pauses the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Stop](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_stop)(OH_AudioRenderer* renderer) | Stops the audio renderer.    |
| OH_AudioStream_Result [OH_AudioRenderer_Flush](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_flush)(OH_AudioRenderer* renderer) | Flushes obtained audio data.|
| OH_AudioStream_Result [OH_AudioRenderer_Release](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_release)(OH_AudioRenderer* renderer) | Releases the audio renderer.|

### Releasing the Builder

When the builder is no longer required, release the resources as follows:

```cpp
OH_AudioStreamBuilder_Destroy(builder);
```
