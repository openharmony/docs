# Choosing the Right Recording Stream Type

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b1fa1b915ee15db082bf8f1cefb71ce8e32f9517 translatedAt=2026-08-06T13:41:14.784Z pushedAt=2026-08-07T02:12:47.054Z -->

The recording stream type is defined by [SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8), which identifies the usage scenario of the recording stream to the system. The system uses it for the [audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy) and [audio channel configuration](audio-performance.md#understanding-the-system-audio-channel). Certain types also correspond to specific audio recording processing scenarios.

When selecting a `SourceType`, first determine the actual purpose of the recorded data, and then choose the type that matches your business scenario. Use `SOURCE_TYPE_MIC` only when the service involves general audio recording and has no specific requirements such as speech recognition, calling, voice messaging, video recording, live streaming, or raw audio capture. Using this type for all recording scenarios is not recommended, because different recording stream types correspond to different system optimization policies. If the type is selected incorrectly, the corresponding optimization policies will not take effect, which affects recording quality and user experience. For example, incorrectly using `SOURCE_TYPE_MIC` in a VoIP calling scenario prevents optimization policies such as noise reduction and ambient sound suppression from taking effect, resulting in poor call quality. The actual input device, audio channel, and available processing capabilities also depend on the device capabilities and system configuration.

## Common Recording Stream Types and Their Applicable Scenarios

| Audio Stream Type (SourceType) | Applicable Scenario | Main Effect and Selection Instruction |
| ---------- | ---------- | ---------- |
| SOURCE_TYPE_MIC | General recording, such as a sound recorder. | The system configures the default input channel and recording processing based on the general recording scenario. If a more specific service type exists, prefer the corresponding type. |
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup> | Speech recognition. | Corresponds to the speech recognition processing scenario. The system can match the speech recognition input channel based on the device configuration. |
| SOURCE_TYPE_PLAYBACK_CAPTURE | Recording raw audio data that other apps send to the system for playback. | Deprecated since API version 12. Audio Kit no longer provides the internal recording API. For internal recording scenarios, use [AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture.md). |
| SOURCE_TYPE_VOICE_COMMUNICATION | VoIP voice or video calls. | Enhances human voice recording and suppresses non-human sounds such as ambient noise. According to the [SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) definition, starting recording alone enables the 3A algorithm. |
| SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup> | Recording voice short messages. | Identifies the voice message recording scenario. According to the system's default [audio focus strategy](audio-playback-concurrency.md#audio-focus-strategy), starting recording pauses the currently playing music and notifies the music app to resume playback after recording ends. |
| SOURCE_TYPE_CAMCORDER<sup>13+</sup> | Camera recording. | Indicates the recording purpose to the system. The system can match the recording input channel based on the device configuration. |
| SOURCE_TYPE_UNPROCESSED<sup>14+</sup> | Obtaining raw audio captured by the microphone. | According to the [SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) definition, the system does not apply algorithm processing to the captured data. |
| SOURCE_TYPE_LIVE<sup>20+</sup> | Live streaming. | On supported devices, the system provides [acoustic echo cancellation](using-audiocapturer-for-recording.md#echo-cancellation). Before use, call [isAcousticEchoCancelerSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isacousticechocancelersupported20) to check whether the current device supports this capability. |

## Impact of Recording Stream Type on Audio Services

The system configures the corresponding audio focus, input channel, and optimization processing strategy based on the recording stream type. Therefore, `SourceType` affects recording quality. For example, using `SOURCE_TYPE_MIC` instead of `SOURCE_TYPE_VOICE_COMMUNICATION` in a VoIP call scenario may prevent optimization strategies such as noise reduction and ambient sound suppression from taking effect, resulting in a poor call experience.

### Audio Focus Adjustment

The system makes audio focus decisions based on the recording stream type and the audio stream start order. For example, when you start recording a voice short message (`VoiceMessage`), the currently playing music (`Music`) is paused; after the recording ends, the app playing music receives a notification to resume playback. For more information, see [Audio Focus Strategy](audio-playback-concurrency.md#audio-focus-strategy).

### Input Device Selection

The system selects the appropriate input device based on the recording stream type. For example, `SOURCE_TYPE_MIC` uses the built-in microphone for recording by default, while the input device for `SOURCE_TYPE_VOICE_COMMUNICATION` follows the current output device. If the default input device does not meet your requirements, refer to [Switching Audio Input Devices](audio-input-device-switcher.md).

## Setting the Recording Stream Type

An app can implement audio recording in several ways. The methods for setting the recording stream type in each approach are as follows:

- [Using AudioCapturer for Audio Recording (ArkTS)](using-audiocapturer-for-recording.md): When calling [createAudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiocapturer8), specify SourceType through AudioCapturerInfo.source in AudioCapturerOptions.

- [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md): When calling [OH_AudioStreamBuilder_SetCapturerInfo](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setcapturerinfo), pass in [OH_AudioStream_SourceType](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).

- [Using AVRecorder to Record Audio (ArkTS)](../media/using-avrecorder-for-recording.md): When calling [AVRecorder.prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1), specify [AudioSourceType](../../reference/apis-media-kit/arkts-apis-media-e.md#audiosourcetype9) through `AVRecorderConfig.audioSourceType`.

## Using Different Recording Channels

An audio channel is the transmission and processing path of audio data within the system. The system obtains recording scenario information through SourceType and selects an appropriate audio channel based on parameters such as the sampling rate, number of channels, and encoding format. Common recording channels are as follows:

| Audio Channel Type | Characteristics | Applicable Scenarios |
| ---------- | ---------- | ---------- |
| Low-latency recording channel | Reduces latency by shortening the buffer and minimizing audio effect algorithms. | Karaoke scenarios. |
| Normal recording channel | A general-purpose channel that inputs audio in the device's default audio format. | Voice recorder, camera recording, voice messages, and more. |

You can call [isFastRecordingSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isfastrecordingsupported) to check whether the device supports low-latency recording before creating an audio stream.

> **NOTE**
>
> - The availability of audio channels depends on the device's hardware capabilities and system configuration, and varies across devices.
> - The result returned by the query API only indicates whether the system supports the corresponding audio channel under the specified parameters. The actual channel used also depends on the system's current running status and resource configuration.

<!--no_check-->