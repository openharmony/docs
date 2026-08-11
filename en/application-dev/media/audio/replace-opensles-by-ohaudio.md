# Switching from OpenSL ES to OHAudio (C/C++)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T01:52:15.578Z pushedAt=2026-08-06T08:58:40.036Z -->

As OpenSL ES cannot accommodate the capability expansion of the audio system, you are advised to use OHAudio instead of OpenSL ES for audio service development. This document describes how to switch from developing audio services with OpenSL ES APIs to using OHAudio APIs.

## Differences in Features Supported

The feature scopes supported by the two differ slightly. OHAudio additionally supports low-latency playback/recording, monitoring service changes, and other features.

The specific differences are shown in the following table.

| Feature | OpenSL ES | OHAudio |
| --- | --- | --- |
| Audio streaming playback | √ | √ |
| Audio streaming recording | √ | √ |
| Low-latency audio playback | × | √ |
| Low-latency audio recording | × | √ |
| Playback object state switching | √ | √ |
| Recording object state switching | √ | √ |
| Obtaining audio stream object state | √ | √ |
| Clearing playback buffer | × | √ |
| Monitoring audio interruption events | × | √ |
| Monitoring audio stream events | × | √ |
| Monitoring stream exception events | × | √ |
| Monitoring playback device change events | × | √ |

## Differences in Development Modes

This section compares the development mode differences between OHAudio and OpenSL ES in the context of development steps.

Audio playback and recording follow similar implementation patterns. This section uses audio playback as an example.

### Constructing Instances

OpenSL ES:

Obtain the Engine object through the global interface, and construct different audio playback objects based on the Engine with various input and output configuration parameters.

```cpp
// Obtain the Engine Interface object.
SLEngineItf engine;
// ...

// Configure the audio input slSource as needed.
SLDataSource slSource;
// ...

// Configure the audio output slSink as needed.
SLDataSink slSink;
// ...

// Create an audio playback object.
SLObjectItf playerObject;
(*engine)->CreateAudioPlayer(engine,
                             &playerObject,
                             &slSource,
                             &slSink,
                             0,
                             nullptr,
                             nullptr);

(*playerObject)->Realize(playerObject,
                         SL_BOOLEAN_FALSE);
```

OHAudio:

Use the builder pattern to create an audio playback object through a builder with custom parameter settings.

```cpp
// Create a builder.
OH_AudioStreamBuilder *builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);

// Set custom parameters. Otherwise, default parameters are used.
OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
OH_AudioStreamBuilder_SetChannelCount(builder, 2);
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// Key parameter supported only by OHAudio. Set it based on the audio usage, and the system adapts the audio policy accordingly.
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
// ...

// Create the audio playback object.
OH_AudioRenderer *audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### State Switching

OpenSL ES:

Obtain the state switching Interface based on the Object, and use this interface to switch states. Only three states are available: `SL_PLAYSTATE_STOPPED`, `SL_PLAYSTATE_PAUSED`, and `SL_PLAYSTATE_PLAYING`.

```cpp
// Obtain the play operation Interface based on the player object.
SLPlayItf playItf = nullptr;
(*playerObject)->GetInterface(playerObject, SL_IID_PLAY, &playItf);
// Switch the state.
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PAUSED);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
```

OHAudio:

Provides independent state switching APIs and performs state switching based on a state machine. There are six `OH_AudioStream_State` states in total, with transitions mainly among `AUDIOSTREAM_STATE_PREPARED`, `AUDIOSTREAM_STATE_RUNNING`, `AUDIOSTREAM_STATE_STOPPED`, `AUDIOSTREAM_STATE_PAUSED`, and `AUDIOSTREAM_STATE_RELEASED`.

```cpp
// Switch the state.
OH_AudioRenderer_Start(audioRenderer);
OH_AudioRenderer_Pause(audioRenderer);
OH_AudioRenderer_Stop(audioRenderer);
```

### Data Processing

OpenSL ES:

Based on the extended `OHBufferQueue` interface, a custom callback function is registered to fill the audio data to be played into the buffer provided by the system when data is requested.

```cpp
static void MyBufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
{
    SLuint8 *buffer = nullptr;
    SLuint32 bufferSize;
    // Obtain the buffer provided by the system.
    (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &bufferSize);
    // Write the audio data to be played into the buffer.
    // ...
    // Enqueue the buffer into the system.
    (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, bufferSize);
}

// Obtain the OHBufferQueue interface.
SLOHBufferQueueItf bufferQueueItf;
(*playerObject)->GetInterface(playerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
// You can pass custom context information, which will be received in the callback.
void *pContext;
(*bufferQueueItf)->RegisterCallback(bufferQueueItf, MyBufferQueueCallback, pContext);
```

OHAudio:

It uniformly uses the callback mode. You register a data write callback during construction and implement a custom data filling function. During playback, the system automatically triggers the data request callback at the appropriate time based on system scheduling and latency configuration.

```cpp
static int32_t MyOnWriteData(
    OH_AudioRenderer *renderer,
    void *userData,
    void *buffer,
    int32_t bufferLen)
{
    // Fill the buffer with the data to be played based on the requested bufferLen length.
    // After the function returns, the system automatically retrieves data from the buffer for output.
}

OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;

// Set the callback for the output audio stream. It is automatically registered when the audio playback object is created.
void *userData = nullptr;
OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, userData);
```

### Releasing Resources

OpenSL ES:

Use the `SLObjectItf` interface to release object resources.

```cpp
// Release the player object resources.
(*playerObject)->Destroy(playerObject);
```

OHAudio:

Use the release API of the corresponding module to release object resources.

```cpp
// Release the builder resources.
OH_AudioStreamBuilder_Destroy(builder);

// Release the audio renderer resources.
OH_AudioRenderer_Release(audioRenderer);
```