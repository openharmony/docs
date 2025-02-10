# Selecting an Appropriate Audio Stream Type

[Audio stream](audio-kit-intro.md#introduction-to-audio-streams) types are crucial for determining the mode of audio playback and recording. For audio playback streams, the stream type is determined by [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage). For audio recording streams, the stream type is determined by [SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8). These types pose a significant impact on volume control, audio focus management, and input/output device selection.

To ensure that the audio behavior meets expectations and delivers a superior user experience, you need to select an appropriate audio stream type based on the use cases and requirements.

This topic describes [typical audio stream types and their use cases](#typical-audio-stream-types-and-use-cases) and [their effects on audio services](#effects-of-audio-stream-types-on-audio-services). It also describes how to [set the audio stream type](#setting-the-audio-stream-type) when you use different methods to implement audio playback and recording.

## Typical Audio Stream Types and Use Cases

### Stream Types for Audio Playback

The following table describes the typical stream types used for audio playback. The type is specified by [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage).

| Stream Type| Use Case|
| ---------- | ---------- |
| STREAM_USAGE_MUSIC | Music playback and other media scenarios, for example, using [SoundPool](../media/using-soundpool-for-playback.md) to play short sounds.|
| STREAM_USAGE_MOVIE |  Playing various video content such as short videos, movies, and TV series.|
| STREAM_USAGE_AUDIOBOOK | Playing audiobooks, news, and podcasts.|
| STREAM_USAGE_GAME | In-game background scores and character dubbing, ensuring uninterrupted background music. It is recommended that you use **STREAM_USAGE_VOICE_COMMUNICATION** for in-game voice.|
| STREAM_USAGE_NAVIGATION | Voice broadcast in navigation scenarios.|
| STREAM_USAGE_VOICE_MESSAGE | Playing voice short messages.|
| STREAM_USAGE_VOICE_COMMUNICATION | VoIP voice calls.|
| STREAM_USAGE_ALARM | Playing alarms.|
| STREAM_USAGE_RINGTONE | Playing ringtones for VoIP calls.|
| STREAM_USAGE_NOTIFICATION | Playing notification tones and prompt tones.|

### Stream Types for Audio Recording

The following table describes the typical stream types used for audio recording. The type is specified by [SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8).

| Stream Type| Use Case|
| ---------- | ---------- |
| SOURCE_TYPE_MIC | Common audio recording.|
| SOURCE_TYPE_VOICE_COMMUNICATION | VoIP voice calls.|
| SOURCE_TYPE_VOICE_MESSAGE | Recording voice short messages.|

## Effects of Audio Stream Types on Audio Services

Different stream types affect user experience in volume control and system performance in adjusting the audio focus and selecting input/output devices.

### Volume Control

The audio playback stream type (specified by [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)) determines the volume type (specified by [AudioVolumeType](../../reference/apis-audio-kit/js-apis-audio.md#audiovolumetype)) to which the audio stream belongs. Each volume type (such as **MEDIA**, **RINGTONE**, **ALARM**, and **VOICE_CALL**) has an independent volume value, which can be adjusted independently on the UI.

The table below lists the mappings between the typical audio playback stream types and volume types.

| Stream Type| Volume Type|
| ---------- | ---------- |
|  MUSIC, MOVIE, AUDIOBOOK, GAME| MEDIA|
|  RINGTONE, NOTIFICATION| RINGTONE|
| VOICE_COMMUNICATION | VOICE_CALL|
| ALARM | ALARM|

### Adjusting the Audio Focus

The audio stream type plays a key role in audio focus management. Different types of audio streams have different default priorities and processing modes for the audio focus.

When an application starts audio playback or recording, the system automatically applies for focus based on the audio stream type. This may interrupt or duck other audio streams. For details about the audio focus, see [Introduction to Audio Focus and Audio Session](audio-playback-concurrency.md).

This section describes only how the typical audio stream types affect the audio focus.

- When a Navigation stream starts playing, the Music stream that is playing will be ducked. After the Navigation stream ends, the volume of the Music stream will be restored.

- When a Movie stream starts playing, the Music stream that is playing will be stopped. When the Movie stream ends, the Music stream will not be automatically resumed, and the corresponding application will not receive any resume notification.

- When a VoiceCommunication stream starts, the Music stream that is playing will be paused. When the VoiceCommunication stream ends, the music application will receive a notification to resume the playback.

- The Music stream and Game stream can be mixed and played concurrently without affecting each other.

- When a VoiceMessage stream starts, the Music stream that is playing will be paused. When the VoiceMessage stream ends, the music application will receive a notification to resume the playback.

### Selecting Input/Output Devices

The system selects an input/output device based on the audio stream type.

The following lists the input/output devices selected for the typical audio stream types.

- For a MUSIC stream, the default output device is a speaker.

- For a VoiceCommunication stream, the default input device is a microphone, and the default output device is an earpiece.

- For an Alarm stream, the default output device is a speaker. If a Bluetooth headset is connected before an ALARM stream is played, the audio is output from both the speaker and Bluetooth headset.

If the default input/output devices do not meet service requirements, you can call related APIs to change the devices. When [using AudioRenderer to develop audio playback](using-audiorenderer-for-playback.md), you can call [setDefaultOutputDevice](../../reference/apis-audio-kit/js-apis-audio.md#setdefaultoutputdevice12) to set the default sound device.

## Setting the Audio Stream Type

The application can implement audio playback or recording by using a plurality of methods. Therefore, manners of setting the audio stream type are also different.

Common methods for setting the audio playback stream type are as follows:

- **[Using AudioRenderer for Audio Playback](using-audiorenderer-for-playback.md)**

   Pass [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage) in [createAudioRenderer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8) to specify the stream type.

   The **options** parameter in **createAudioRenderer** is of the **AudioRendererOptions** type and contains the **AudioRendererInfo** struct, in which **AudioRendererInfo.usage** specifies the stream type.

- **[Using OHAudio for Audio Playback](using-ohaudio-for-playback.md)**
  
  Pass [OH_AudioStream_Usage](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_usage) in [OH_AudioStreamBuilder_SetRendererInfo](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrendererinfo) to specify the stream type.

- **[Using AVPlayer for Audio Playback (ArkTS)](../media/using-avplayer-for-playback.md)**
  
  Set the **audioRendererInfo** [property](../../reference/apis-media-kit/js-apis-media.md#properties) of the AVPlayer. **AVPlayer.audioRendererInfo** is of the **audio.AudioRendererInfo** type. You can use **AudioRendererInfo.usage** to specify [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage).

  > **NOTE**
  >
  > The **audioRendererInfo** property of the AVPlayer can be set only in the initialized state.
  >
  > If the application does not set this property, the AVPlayer performs default processing. If the media source contains videos, the default value of **usage** is **STREAM_USAGE_MOVIE**. Otherwise, the default value of **usage** is **STREAM_USAGE_MUSIC**.

- **[Using AVPlayer for Audio Playback (C/C++)](../media/using-ndk-avplayer-for-playback.md)**
  
  Pass [OH_AudioStream_Usage](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_usage) in [OH_AVPlayer_SetAudioRendererInfo](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiorendererinfo) to specify the stream type.

- **[Using SoundPool for Audio Playback](../media/using-soundpool-for-playback.md)**
  
  Pass [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage) in [createSoundPool](../../reference/apis-media-kit/js-apis-media.md#mediacreatesoundpool10) to specify the stream type.

Common methods for setting the audio recording stream type are as follows:

- **[Using AudioCapturer for Audio Recording](using-audiocapturer-for-recording.md)**
  
  Pass [SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8) in [createAudioCapturer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiocapturer8) to specify the stream type.

   The **options** parameter in **createAudioCapturer** is of the **AudioCapturerOptions** type and contains **AudioCapturerInfo**, in which **AudioCapturerInfo.source** specifies the source type.

- **[Using OHAudio for Audio Recording](using-ohaudio-for-recording.md)**
  
  Pass [OH_AudioStream_SourceType](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_sourcetype) in [OH_AudioStreamBuilder_SetCapturerInfo](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setcapturerinfo) to specify the stream type.

- **[Using AVRecorder for Audio Recording](../media/using-avrecorder-for-recording.md)**
  
  Pass [AudioSourceType](../../reference/apis-media-kit/js-apis-media.md#audiosourcetype9) [AVRecorder.prepare](../../reference/apis-media-kit/js-apis-media.md#prepare9-3) to specify the stream type.

  The **config** parameter in **AVRecorder.prepare** is of the **AVRecorderConfig** type, in which **AVRecorderConfig.audioSourceType** specifies the audio source type.
