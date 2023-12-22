# Using OHAudio for Audio Playback (C/C++)

**OHAudio** is a set of native APIs introduced in API version 10. These APIs are normalized in design and support both common and low-latency audio channels.

## Prerequisites

To use the playback or recording capability of **OHAudio**, you must first import the corresponding header files.

Specifically, to use APIs for audio playback, import <[native_audiostreambuilder.h](../reference/native-apis/native__audiostreambuilder_8h.md)> and <[native_audiorenderer.h](../reference/native-apis/native__audiorenderer_8h.md)>.

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

The following walks you through how to implement simple playback:

1. Create an audio stream builder.

    ```c++
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
    ```

2. Set audio stream parameters.

    After creating the builder for audio playback, set the parameters required.

    ```c++
    OH_AudioStreamBuilder_SetSamplingRate(builder, rate);
    OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
    OH_AudioStreamBuilder_SetSampleFormat(builder, format);
    OH_AudioStreamBuilder_SetEncodingType(builder, encodingType);
    OH_AudioStreamBuilder_SetRendererInfo(builder, usage);
    ```

    Note that the audio data to play is written through callbacks. You must call **OH_AudioStreamBuilder_SetRendererCallback** to implement the callbacks. For details about the declaration of the callback functions, see [OH_AudioRenderer_Callbacks](../reference/native-apis/_o_h_audio.md#oh_audiorenderer_callbacks).


3. Set the callback functions.

    ```c++
    OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);
    ```

4. Create an audio renderer instance.

    ```c++
    OH_AudioRenderer* audioRenderer;
    OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
    ```

5. Use the audio renderer.

    You can use the APIs listed below to control the audio streams.

    | API                                                        | Description        |
    | ------------------------------------------------------------ | ------------ |
    | OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer) | Starts the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer) | Pauses the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer) | Stops the audio renderer.    |
    | OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | Flushes written audio data.|
    | OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | Releases the audio renderer instance.|

6. Destroy the audio stream builder.

    When the builder is no longer used, release related resources.

    ```c++
    OH_AudioStreamBuilder_Destroy(builder);
    ```

## Setting the Low Latency Mode

If the device supports the low-latency channel, you can use the low-latency mode to create a player for a higher-quality audio experience.

The development process is similar to that in the common playback scenario. The only difference is that you need to set the low delay mode by calling [OH_AudioStreamBuilder_SetLatencyMode()](../reference/native-apis/_o_h_audio.md#oh_audiostreambuilder_setlatencymode) when creating an audio stream builder.

The code snippet is as follows:

```C
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```
