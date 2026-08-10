# Audio Latency Management

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T01:42:46.236Z pushedAt=2026-08-06T03:50:00.147Z -->

Audio latency is the time it takes from the moment a user clicks or triggers an action until the sound is emitted from the device.

In terms of audio data transmission, audio latency encompasses the entire process from initiating the callback for data writing to the moment the sound is produced. This includes the time taken for data writing, algorithm processing, hardware transmission delays, and, in the case of Bluetooth, the additional delay of Bluetooth transmission.

Currently, OHAudio supports two modes: normal mode (**AUDIOSTREAM_LATENCY_MODE_NORMAL**) and low-latency mode (**AUDIOSTREAM_LATENCY_MODE_FAST**).

You can specify which mode the audio stream should use by calling [OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode) to set [OH_AudioStream_LatencyMode](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode).

The low-latency mode optimizes the data read/write architecture to achieve lower latency for audio playback and recording.

The examples in the steps below are code snippets. For the complete sample, see [AudioRendererSampleC](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRendererSampleC).

To use the low-latency mode, you need to use OHAudio for audio development. For details, please refer to [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md) and [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md). The following is an example of setting the low-latency mode:

<!-- @[OH_AudioStreamBuilder_SetLatencyMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

An app can query the current latency mode through [OH_AudioRenderer_GetLatencyMode](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_getlatencymode). Development example:

<!-- @[Render_CheckLatencyMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->  

``` C++
OH_AudioRenderer_GetLatencyMode(audioRenderer, &latencyMode);
```

In low-latency mode, the app must provide data every 5 ms. If data is not written in time, issues such as audio noise may occur.

However, even if the low-latency mode is set, the system uses the normal mode under the following conditions:

- The current device does not support the low-latency mode.

- The sampling rate is not set to 48 kHz.

- All low-latency resources are already in use.

For applications like gaming, which have stringent latency requirements, the low-latency mode is recommended.