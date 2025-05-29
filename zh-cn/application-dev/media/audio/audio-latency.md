# 音频时延管理

音频时延指从用户触发点击到声音从设备播放所经过的时间。

从音频数据传输的角度，指从触发回调写入开始，到最终播放出声的耗时，包括数据写入、算法处理、硬件传输延迟，以及在蓝牙场景下的蓝牙传输延迟。

当前OHAudio支持两种模式：普通模式（AUDIOSTREAM_LATENCY_MODE_NORMAL）和低时延模式（AUDIOSTREAM_LATENCY_MODE_FAST）。

开发者通过调用[OH_AudioStreamBuilder_SetLatencyMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setlatencymode)，设置[OH_AudioStream_LatencyMode](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_latencymode)，来决定音频流使用哪种模式。

低时延模式通过读写数据架构优化，使得该模式下音频播放和录制具有更低的时延。

为使用低时延模式，开发者需要使用OHAudio进行音频开发，可参考[使用OHAudio开发音频播放功能](using-ohaudio-for-playback.md)和[使用OHAudio开发音频录制功能](using-ohaudio-for-recording.md)。设置低时延模式开发示例：

```cpp
OH_AudioStream_LatencyMode latencyMode = AUDIOSTREAM_LATENCY_MODE_FAST;
OH_AudioStreamBuilder_SetLatencyMode(builder, latencyMode);
```

应用可以通过[GetLatencyMode](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_getlatencymode)查询当前时延模式，开发示例：

```cpp
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer *renderer, OH_AudioStream_LatencyMode *latencyMode)
```

在低时延模式下，应用需要每5ms提供一次数据，如果送数据不及时可能导致杂音等问题。

但在以下场景中，即使设置了低时延模式，系统仍会使用普通模式：

- 当前设备不支持低时延模式。
- 采样率设置为非48K。
- 系统低时延资源已被全部占用。

游戏类应用对时延要求较高，建议使用低时延模式。