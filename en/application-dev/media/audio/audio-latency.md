# Audio Latency Management

Audio latency is the time it takes from the moment a user clicks or triggers an action until the sound is emitted from the device.

In terms of audio data transmission, audio latency encompasses the entire process from initiating the callback for data writing to the moment the sound is produced. This includes the time taken for data writing, algorithm processing, hardware transmission delays, and, in the case of Bluetooth, the additional delay of Bluetooth transmission.

Currently, **OHAudio** supports two modes: normal mode (**AUDIOSTREAM_LATENCY_MODE_NORMAL**) and low-latency mode (**AUDIOSTREAM_LATENCY_MODE_FAST**).

You can specify which mode the audio stream should use by calling [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setlatencymode) to set [OH_AudioStream_LatencyMode](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_latencymode).

The low-latency mode optimizes the data read/write architecture to achieve lower latency for audio playback and recording.

To use the low-latency mode, you must use **OHAudio** for audio development. For details, see [Using OHAudio for Audio Playback](using-ohaudio-for-playback.md) and [Using OHAudio for Audio Recording](using-ohaudio-for-recording.md). The following is an example of setting the low-latency mode:

```cpp
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

Applications can query the current latency mode using [GetLatencyMode](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiorenderer_getlatencymode). An example is as follows:

```cpp
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer *renderer, OH_AudioStream_LatencyMode *latencyMode)
```

In low-latency mode, applications need to provide data every 5 ms. Failure to provide data in a timely manner may result in issues such as noise.

However, even if the low-latency mode is set, the system uses the normal mode under the following conditions:

- The current device does not support the low-latency mode.
- The sampling rate is not set to 48 kHz.
- All low-latency resources are already in use.

For applications like gaming, which have stringent latency requirements, the low-latency mode is recommended.
