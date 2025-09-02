# Switching from OpenSL ES to OHAudio (C/C++)

You are advised to use OHAudio APIs instead of OpenSL ES APIs to develop audio services, since the latter may fail to provide extended audio capabilities. This topic describes how to switch the audio service code from the OpenSL ES APIs to the OHAudio APIs.

## Differences in Features Supported

Different from the OpenSL ES APIs, the OHAudio APIs support low-latency playback/recording and service change listening.

The table below lists the differences in the features supported by the APIs.

| | OpenSL ES| OHAudio |
| --- | --- | --- |
| Audio streaming playback| Supported| Supported|
| Audio streaming recording| Supported| Supported|
| Low-latency audio playback| Not supported| Supported|
| Low-latency audio recording| Not supported| Supported|
| Switching the state of a playback object| Supported| Supported|
| Switching the state of a recording object| Supported| Supported|
| Obtaining the state of an audio stream object| Supported| Supported|
| Clearing the playback cache| Not supported| Supported|
| Listening for audio interruption events| Not supported| Supported|
| Listening for audio stream events| Not supported| Supported|
| Listening for stream exception events| Not supported| Supported|
| Listening for output device update events| Not supported| Supported|

## Differences in Development Modes

This section describes the differences between OHAudio and OpenSL ES APIs in development modes based on the development procedure of audio playback. The implementation of audio recording is similar.

### Constructing Instances

OpenSL ES:

Obtain an Engine object through the global interface, and construct an audio playback object based on the Engine object and the input and output parameters.

```cpp
// Generate an Engine object.
SLEngineItf engine;
// ...

// Configure audio input slSource as required.
SLDataSource slSource;
// ...

// Configure audio output slSink as required.
SLDataSink slSink;
// ...

// Generate an audio playback object.
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

Use the builder mode to generate an audio playback object based on custom parameters.

```cpp
// Create a builder.
OH_AudioStreamBuilder *builder;
OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_RENDERER);

// Set custom parameters. Otherwise, the default parameters will be used.
OH_AudioStreamBuilder_SetSamplingRate(builder, 48000);
OH_AudioStreamBuilder_SetChannelCount(builder, 2);
OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
// This parameter specifies the audio usage and is supported only by OHAudio. The system implements audio policy adaptation based on the parameter.
OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
// ...

// Generate an audio playback object.
OH_AudioRenderer *audioRenderer;
OH_AudioStreamBuilder_GenerateRenderer(builder, &audioRenderer);
```

### State Switching

OpenSL ES:

Obtain the state switching interface based on the audio playback object and use the interface to switch the state. There are three states: **SL_PLAYSTATE_STOPPED**, **SL_PLAYSTATE_PAUSED**, and **SL_PLAYSTATE_PLAYING**.

```cpp
// Obtain the playback operation interface based on the audio playback object.
SLPlayItf playItf = nullptr;
(*playerObject)->GetInterface(playerObject, SL_IID_PLAY, &playItf);
// Switch the state.
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PLAYING);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_PAUSED);
(*playItf)->SetPlayState(playItf, SL_PLAYSTATE_STOPPED);
```

OHAudio:

There are independent state switching interfaces. The state is switched based on the state machine. There are six states, which are mainly switched between **AUDIOSTREAM_STATE_PREPARED**, **AUDIOSTREAM_STATE_RUNNING**, **AUDIOSTREAM_STATE_STOPPED**, **AUDIOSTREAM_STATE_PAUSED**, and **AUDIOSTREAM_STATE_RELEASED**.

```cpp
// Switch the state.
OH_AudioRenderer_Start(audioRenderer);
OH_AudioRenderer_Pause(audioRenderer);
OH_AudioRenderer_Stop(audioRenderer);
```

### Data Processing

OpenSL ES:

Based on the extended **OHBufferQueue** APIs, you can register a custom callback function to write audio data to be played to the system buffer.

```cpp
static void MyBufferQueueCallback(SLOHBufferQueueItf bufferQueueItf, void *pContext, SLuint32 size)
{
    SLuint8 *buffer = nullptr;
    SLuint32 bufferSize;
    // Obtain the buffer provided by the system.
    (*bufferQueueItf)->GetBuffer(bufferQueueItf, &buffer, &bufferSize);
    // Write the audio data to be played to the buffer.
    // ...
    // Enqueue the buffer.
    (*bufferQueueItf)->Enqueue(bufferQueueItf, buffer, bufferSize);
}

// Obtain the OHBufferQueue APIs.
SLOHBufferQueueItf bufferQueueItf;
(*playerObject)->GetInterface(playerObject, SL_IID_OH_BUFFERQUEUE, &bufferQueueItf);
// This callback can be used to obtain the custom context information passed in.
void *pContext;
(*bufferQueueItf)->RegisterCallback(bufferQueueItf, MyBufferQueueCallback, pContext);
```

OHAudio:

The callback mode is used. When the audio playback object is constructed, a data input callback is registered to implement custom data filling. During playback, a data request callback is automatically triggered at a proper time based on the system scheduling and delay configuration.

```cpp
static int32_t MyOnWriteData(
    OH_AudioRenderer *renderer,
    void *userData,
    void *buffer,
    int32_t bufferLen)
{
    // Write the data to be played to the buffer based on the requested buffer length.
    // After the function is returned, the system automatically fetches data from the buffer.
}

OH_AudioRenderer_Callbacks callbacks;
callbacks.OH_AudioRenderer_OnWriteData = MyOnWriteData;

// Set the callback function for outputting audio streams. The callback function is automatically registered when the audio playback object is generated.
void *userData = nullptr;
OH_AudioStreamBuilder_SetRendererCallback(builder, callbacks, userData);
```

### Releasing Resources

OpenSL ES:

Call **SLObjectItf** to release object resources.

```cpp
// Release the playback object resources.
(*playerObject)->Destroy(playerObject);
```

OHAudio:

Call the release interface of the module to release object resources.

```cpp
// Release the builder resources.
OH_AudioStreamBuilder_Destroy(builder);

// Release the playback object resources.
OH_AudioRenderer_Release(audioRenderer);
```
