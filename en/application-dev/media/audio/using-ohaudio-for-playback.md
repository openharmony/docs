# Using OHAudio for Audio Playback (C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

OHAudio is a set of C APIs introduced in API version 10. These APIs are normalized in design and support both common and low-latency audio channels. They support the PCM format only and are suitable for playback applications that implement audio output at the native layer.

OHAudio audio playback state transition

![OHAudioRenderer status change](figures/ohaudiorenderer-status-change.png)

## Prerequisites

To use the playback capability of OHAudio, you must first import the corresponding header files.

### Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### Adding Header Files

Include the <[native_audiostreambuilder.h](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md)> and <[native_audiorenderer.h](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md)> header files so that the application can use the functions related to audio playback.

```cpp
#include <ohaudio/native_audiorenderer.h>
#include <ohaudio/native_audiostreambuilder.h>
```

## Building Audio Streams

OHAudio provides the **OH_AudioStreamBuilder** class, which complies with the builder design pattern and is used to build audio streams. You need to specify [OH_AudioStream_Type](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_type) based on your service scenarios.

**OH_AudioStream_Type** can be set to either of the following:

- AUDIOSTREAM_TYPE_RENDERER
- AUDIOSTREAM_TYPE_CAPTURER

The following code snippet shows how to use [OH_AudioStreamBuilder_Create](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create) to create a builder:

```cpp
OH_AudioStreamBuilder* builder;
OH_AudioStreamBuilder_Create(&builder, streamType);
```

After the audio service is complete, call [OH_AudioStreamBuilder_Destroy](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_destroy) to destroy the builder.

```cpp
OH_AudioStreamBuilder_Destroy(builder);
```

## How to Develop

Read [OHAudio](../../reference/apis-audio-kit/capi-ohaudio.md) for the API reference.

The following walks you through how to implement simple playback:

1. Create an audio stream builder.

    ```cpp
    OH_AudioStreamBuilder* builder;
    OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);
    ```

2. Set audio stream parameters.

    For details about the audio sampling rate, see [Configuring the Appropriate Audio Sampling Rate](using-audiorenderer-for-playback.md#configuring-the-appropriate-audio-sampling-rate).<br>
    After creating the builder for audio playback, set the parameters required.

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
    OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
    ```

    Note that the audio data to play is written through callbacks. You must call **OH_AudioStreamBuilder_SetRendererCallback** to implement the callbacks. For details about the declaration of the callback functions, see [OH_AudioRenderer_Callbacks](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md).

3. Set the callback functions.

    For details about concurrent processing of multiple audio streams, see [Processing Audio Interruption Events](audio-playback-concurrency.md). The procedure is similar, and the only difference is the API programming language in use.

    The callback function [OH_AudioRenderer_OnWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback) is introduced in API version 12 for writing audio data.

    - Since API version 12, you are advised to use [OH_AudioRenderer_OnWriteDataCallback](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback) instead of [OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md#oh_audiorenderer_onwritedata) to write audio data.

      > **NOTE**
      > 
      > - When the amount of data is sufficient to meet the required buffer length of the callback, you should return **AUDIO_DATA_CALLBACK_RESULT_VALID**, and the system uses the entire data buffer for playback. Do not return **AUDIO_DATA_CALLBACK_RESULT_VALID** in this case, as this leads to audio artifacts such as noise and playback stuttering.
      > 
      > - When the amount of data is insufficient to meet the required buffer length of the callback, you are advised to return **AUDIO_DATA_CALLBACK_RESULT_INVALID**. In this case, the system does not process this portion of audio data but requests data from the application again. Once the buffer is adequately filled, you can return **AUDIO_DATA_CALLBACK_RESULT_VALID**.
      > 
      > - Once the callback function finishes its execution, the audio service queues the data in the buffer for playback. Therefore, do not change the buffered data outside the callback. Regarding the last frame, if there is insufficient data to completely fill the buffer, you must concatenate the available data with padding to ensure that the buffer is full. This prevents any residual dirty data in the buffer from adversely affecting the playback effect.

      Since API version 12, you can call [OH_AudioStreamBuilder_SetFrameSizeInCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback) to set **audioDataSize**.

      ```cpp
      // Customize a data writing function.
      static OH_AudioData_Callback_Result NewAudioRendererOnWriteData(
          OH_AudioRenderer* renderer,
          void* userData,
          void* audioData,
          int32_t audioDataSize)
      {
          // Write the data to be played to audioData by audioDataSize.
          // If you do not want to play a segment of audioData, return AUDIO_DATA_CALLBACK_RESULT_INVALID.
          return AUDIO_DATA_CALLBACK_RESULT_VALID;
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
      callbacks.OH_AudioRenderer_OnStreamEvent = MyOnStreamEvent;
      callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
      callbacks.OH_AudioRenderer_OnError = MyOnError;
      callbacks.OH_AudioRenderer_OnWriteData = nullptr;

      // Set callbacks for the audio renderer.
      OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, nullptr);

      // Configure the callback function for writing audio data.
      OH_AudioRenderer_OnWriteDataCallback writeDataCb = NewAudioRendererOnWriteData;
      OH_AudioStreamBuilder_SetRendererWriteDataCallback(builder, writeDataCb, nullptr);
      ```

    - In API version 11, you can use the callback function [OH_AudioRenderer_Callbacks_Struct.OH_AudioRenderer_OnWriteData](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md#oh_audiorenderer_onwritedata) to write audio data.

      > **NOTE**
      > 
      > - This callback function does not return a callback result, and the system treats all data in the callback as valid by default. Ensure that the callback's data buffer is completely filled to the necessary length to prevent issues such as audio noise and playback stuttering.
      > 
      > - If the amount of data is insufficient to fill the data buffer, you are advised to temporarily halt data writing (without pausing the audio stream), block the callback function, and wait until enough data accumulates before resuming writing, thereby ensuring that the buffer is fully filled. If you need to call AudioRenderer APIs after the callback function is blocked, unblock the callback function first.
      > 
      > - If you do not want to play the audio data in this callback function, you can nullify the data block in the callback function. (Once nullified, the system still regards this as part of the written data, leading to silent frames during playback).
      > 
      > - Once the callback function finishes its execution, the audio service queues the data in the buffer for playback. Therefore, do not change the buffered data outside the callback. Regarding the last frame, if there is insufficient data to completely fill the buffer, you must concatenate the available data with padding to ensure that the buffer is full. This prevents any residual dirty data in the buffer from adversely affecting the playback effect.

      ```cpp
      // Customize a data writing function.
      int32_t MyOnWriteData(
          OH_AudioRenderer* renderer,
          void* userData,
          void* buffer,
          int32_t length)
      {
          // Write the data to be played to the buffer by length.
          // If you do not want to play a particular portion of the buffer, you can clear that specific section of the buffer.
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

   To avoid unexpected behavior, you can set the audio callback functions in either of the following ways:

   - Initialize each callback in [OH_AudioRenderer_Callbacks](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md) by a custom callback method or a null pointer.
   
     ```cpp
     // Customize a data writing function.
     int32_t MyOnWriteData(
         OH_AudioRenderer* renderer,
         void* userData,
         void* buffer,
         int32_t length)
     {
         // Write the data to be played to the buffer by length.
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

     OH_AudioRenderer_Callbacks callbacks;

     // Configure a callback function. If listening is required, assign a value.
     callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
     callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;

     // (Mandatory) For scenarios where no callback is triggered, initialize with a null pointer. Starting from API version 11, if you need to listen for device changes, use OH_AudioRenderer_OutputDeviceChangeCallback instead.
     callbacks.OH_AudioRenderer_OnStreamEvent = nullptr;
     // (Mandatory) If listening is not required, use a null pointer for initialization.
     callbacks.OH_AudioRenderer_OnError = nullptr;
     ```
   
   - Initialize and clear the struct before using it.
   
     ```cpp
     // Customize a data writing function.
     int32_t MyOnWriteData(
         OH_AudioRenderer* renderer,
         void* userData,
         void* buffer,
         int32_t length)
     {
         // Write the data to be played to the buffer by length.
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
     OH_AudioRenderer_Callbacks callbacks;
   
     // Initialize and clear the struct before using it.
     memset(&callbacks, 0, sizeof(OH_AudioRenderer_Callbacks));
   
     // Configure the required callback functions.
     callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;
     callbacks.OH_AudioRenderer_OnInterruptEvent = MyOnInterruptEvent;
     ```

4. Create an audio renderer instance.

    ```cpp
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
    | OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer) | Flushes obtained audio data.|
    | OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer) | Releases the audio renderer instance.|

6. Destroy the audio stream builder.

    When the builder is no longer used, release related resources.

    ```cpp
    OH_AudioStreamBuilder_Destroy(builder);
    ```

## Setting the Volume for an Audio Stream

You can use [OH_AudioRenderer_SetVolume](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_setvolume) to set the volume for the current audio stream.

```cpp
// Volume to set. The value range is [0.0, 1.0].
float volume = 0.5f;

// Set the volume for the audio stream.
OH_AudioStream_Result OH_AudioRenderer_SetVolume(audioRenderer, volume);
```

## Setting the Low Latency Mode

If the device supports the low-latency channel and the sampling rate is set to 48000, you can use the low-latency mode to create a player for a higher-quality audio experience.

The development process is similar to that in the common playback scenario. The only difference is that you need to set the low-latency mode by calling [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode) when creating an audio stream builder.

> **NOTE**
> - In audio recording scenarios, if [OH_AudioStream_Usage](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage) is set to **AUDIOSTREAM_USAGE_VOICE_COMMUNICATION** or **AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION**, the low-latency mode cannot be set. The system determines the output audio channel based on the device capability.
> - The low-latency mode requires robust data processing capabilities. If your application generates data slowly, it may lead to lag. Therefore, for typical music and video playback, this mode is not recommended. It is best suited for applications that are sensitive to latency, such as gaming and karaoke.

The code snippet is as follows:

```cpp
OH_AudioStreamBuilder_SetLatencyMode(builder, AUDIOSTREAM_LATENCY_MODE_FAST);
```

## Setting the Audio Channel Layout

In the case of audio file playback, you can set the audio channel layout to specify the speaker position during rendering or playing for a better audio experience.

The development process is similar to that in the common playback scenario. The only difference is that you need to set the audio channel layout by calling [OH_AudioStreamBuilder_SetChannelLayout()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setchannellayout) when creating an audio stream builder.

If the audio channel layout does not match the number of audio channels, audio streams fail to be created. Therefore, you must ensure that the audio channel layout setting is correct.

If you do not know the accurate audio channel layout or you want to use the default audio channel layout, do not call the API to set the audio channel layout. Alternatively, deliver **CH_LAYOUT_UNKNOWN** to use the default audio channel layout, which is specific to the number of audio channels.

For audio in HOA format, to obtain the correct rendering and playback effect, you must specify the audio channel layout.

The code snippet is as follows:

```cpp
OH_AudioStreamBuilder_SetChannelLayout(builder, CH_LAYOUT_STEREO);
```

## Playing Audio Files in Audio Vivid Format

In the case of audio file playback in Audio Vivid format, the callback function used for writing data is different from that in the common playback scenario. This callback function can write PCM data and metadata at the same time.

The development process is similar to that in the common playback scenario. The only difference is that you need to call [OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setwritedatawithmetadatacallback) to set the callback function and call [OH_AudioStreamBuilder_SetEncodingType()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setencodingtype) to set the encoding type to **AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID** when creating an audio stream builder.

When an audio file in Audio Vivid format is played, the frame size is fixed. Therefore, do not call [OH_AudioStreamBuilder_SetFrameSizeInCallback()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback) to set the frame size in the callback. In addition, when setting the number of audio channels and the audio channel layout, use the sum of the number of sound beds written into the audio source and the number of objects.

```cpp
// Customize a callback function for simultaneously writing PCM data and metadata.
int32_t MyOnWriteDataWithMetadata(
    OH_AudioRenderer* renderer,
    void* userData,
    void* audioData,
    int32_t audioDataSize,
    void* metadata,
    int32_t metadataSize)
{
    // Write the PCM data and metadata to be played to the buffer by audioDataSize and metadataSize, respectively.
    return 0;
}

// Set the encoding type.
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID);
// Set the callbacks.
OH_AudioRenderer_WriteDataWithMetadataCallback metadataCallback = MyOnWriteDataWithMetadata;
// Set the callback function for writing both PCM data and metadata.
OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(builder, metadataCallback, nullptr);
```

<!--RP1-->
<!--RP1End-->
