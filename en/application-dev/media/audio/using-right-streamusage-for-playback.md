# Choosing the Right Playback Stream Type

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29aa363c8c07cd0d943043ae209ad0a85fcdc3c5 translatedAt=2026-08-06T01:56:08.982Z pushedAt=2026-08-06T10:27:32.346Z -->

The playback stream type is defined by [StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage) and describes the purpose of audio playback. The system manages volume, audio focus, and output device based on the playback stream type, and selects an audio channel in combination with audio stream parameters. To ensure that audio behavior meets expectations, you should choose an appropriate `StreamUsage` based on the actual playback scenario.

## Common StreamUsage Types and Their Applicable Scenarios

| StreamUsage | Applicable Scenarios |
| ---------- | ---------- |
| STREAM_USAGE_MUSIC<sup>10+</sup> | Applicable to most media scenarios, primarily for music playback, and scenarios where other stream types are not suitable, such as [Using SoundPool to Play Short Sounds (ArkTS)](../media/using-soundpool-for-playback.md). |
| STREAM_USAGE_MOVIE<sup>10+</sup> | Applicable to playing various video content such as short videos, movies, and TV series. |
| STREAM_USAGE_AUDIOBOOK<sup>10+</sup> | Applicable to playing audiobooks, news, podcasts, and similar content. |
| STREAM_USAGE_GAME<sup>10+</sup> | Applicable to in-game background music and dubbing, where background music is not interrupted. For in-game voice chat, STREAM_USAGE_VOICE_COMMUNICATION is recommended. |
| STREAM_USAGE_NAVIGATION<sup>10+</sup> | Applicable to voice guidance in navigation scenarios. |
| STREAM_USAGE_VOICE_MESSAGE<sup>10+</sup> | Applicable to playing short voice messages. |
| STREAM_USAGE_VOICE_COMMUNICATION<sup>7+</sup> | Applicable to VoIP voice calls and two-way communication scenarios such as real-time in-game voice chat. |
| STREAM_USAGE_ALARM<sup>10+</sup> | Applicable to playing alarms. |
| STREAM_USAGE_RINGTONE<sup>10+</sup> | Applicable to VoIP incoming call ringtones. |
| STREAM_USAGE_NOTIFICATION<sup>10+</sup> | Applicable to playing notification sounds and alert tones. |

## Impact of Stream Type on Audio Services

### Volume Control

The stream type determines the volume type ([AudioVolumeType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiovolumetype)) to which the audio stream belongs. Each volume type (such as media, ringtone, alarm, and call) has an independent volume level that can be adjusted separately on the user interface without affecting one another.

The following table shows the mapping between common stream types and volume types:

| StreamUsage | AudioVolumeType |
| ---------- | ---------- |
| MUSIC, MOVIE, AUDIOBOOK, GAME | Media volume (`MEDIA`) |
| RINGTONE, NOTIFICATION | Ringtone volume (`RINGTONE`) |
| VOICE_COMMUNICATION | Call volume (`VOICE_CALL`) |
| ALARM | Alarm volume (`ALARM`) |

### Default Audio Focus Policy

The system presets a default [audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy), which makes focus decisions based on the stream type and the startup sequence of audio streams. The following are common scenarios when the default audio focus policy is used. If an app customizes the focus policy through AudioSession, the actual behavior is subject to the AudioSession configuration.

- When navigation (`Navigation`) starts, the volume of the currently playing music (`Music`) is automatically lowered, and it is restored after the navigation ends.

- When video playback (`Movie`) starts, the currently playing music (`Music`) is stopped. After the video playback ends, the music is not automatically resumed, and the corresponding app does not receive a resume notification.

- When a voice call (`VoiceCommunication`) starts, the currently playing music (`Music`) is paused. After the voice call ends, the app playing music receives a notification to resume playback.

- Music and Game audio can be mixed and played simultaneously without affecting each other.

### Output Device Selection

The system selects the appropriate output device based on the stream type. Common scenarios are as follows:

- The default output device for Music type audio streams is the speaker.

- The default output device for VoiceCommunication type audio streams is the earpiece.

- The default output device for Alarm type audio streams is the speaker. If a Bluetooth headset is connected before Alarm audio playback starts, both the speaker and the Bluetooth headset will play audio simultaneously.

When the default output device does not meet usage requirements, the app can call [setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12) to set the default output device when [developing audio playback with AudioRenderer (ArkTS)](using-audiorenderer-for-playback.md).

## Setting the StreamUsage

An app can implement audio playback in multiple ways. The methods for setting the stream type in different scenarios are as follows:

- [Using AudioRenderer for Audio Playback (ArkTS)](using-audiorenderer-for-playback.md): When calling [createAudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8), specify the StreamUsage through `AudioRendererInfo.usage` in `AudioRendererOptions`.

- [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md): When calling [OH_AudioStreamBuilder_SetRendererInfo](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setrendererinfo), pass in [OH_AudioStream_Usage](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_usage).

- [Using AVPlayer to Play Audio (ArkTS)](../media/using-avplayer-for-playback.md): Set `AudioRendererInfo.usage` through the `audioRendererInfo` property of AVPlayer. This property can only be set in the **initialized** state. If the app does not actively set it, the default value of `usage` is `STREAM_USAGE_MOVIE` when the media source contains video, and `STREAM_USAGE_MUSIC` otherwise.

- [Using AVPlayer to Play Audio (C/C++)](../media/using-ndk-avplayer-for-playback.md): When calling [OH_AVPlayer_SetAudioRendererInfo](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiorendererinfo), pass in `OH_AudioStream_Usage`.

- [Using SoundPool to Play Short Sounds (ArkTS)](../media/using-soundpool-for-playback.md): When calling [createSoundPool](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreatesoundpool10), pass in `StreamUsage`.

## Using Different Audio Channels

An audio channel is the transmission and processing path of audio data within the system. The system obtains playback scenario information through `StreamUsage` and selects an appropriate audio channel based on parameters such as the sample rate, number of channels, and encoding format. Common audio channels are as follows:

| Audio Channel Type | Characteristics | Applicable Scenarios |
| ---------- | ---------- | ---------- |
| Low-latency playback channel | Reduces latency by shortening the buffer and minimizing audio effect algorithms. | Latency-sensitive scenarios such as game sound effects, karaoke loopback, and musical instrument performance. |
| Multichannel playback channel | Supports multichannel data output, avoiding downmixing multichannel audio to stereo or mono. | Multichannel playback scenarios. |
| Direct playback channel | Audio data is sent directly to the hardware output without altering the source format in the playback link. | Playing high-quality lossless music, Hi-Fi audio, and similar scenarios. |
| Low-power playback channel | Reduces power consumption by using a large buffer to minimize interactions with hardware. | Long-duration music playback, audiobooks, and similar scenarios. |
| Normal playback channel | A general-purpose channel that outputs audio in the default audio format of the current device. | Video playback, notification sounds, navigation, and similar scenarios. |

You can use the query APIs provided by AudioStreamManager to check whether the device supports a specific playback channel before creating an audio stream.

| API | Description |
| ---------- | ---------- |
| [isFastPlaybackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isfastplaybacksupported) | Queries whether low-latency playback is supported.<br>**Since**: 26.0.0 |
| [isMultichannelPlaybackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#ismultichannelplaybacksupported) | Queries whether multichannel playback is supported.<br>**Since**: 26.0.0 |
| [isDirectPlaybackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isdirectplaybacksupported) | Queries whether direct playback is supported.<br>**Since**: 26.0.0 |
| [isOffloadPlaybackSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isoffloadplaybacksupported) | Queries whether low-power playback is supported.<br>**Since**: 26.0.0 |

> **NOTE**
>
> - Audio channel support depends on the hardware capabilities and system configuration of the device, and varies by device.
> - The result returned by the query API only indicates whether the system supports the corresponding audio channel under the specified parameters. The actual channel used must be determined based on the current running status and resource configuration of the system.