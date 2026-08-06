# Audio Playback Development

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T01:44:33.235Z pushedAt=2026-08-06T07:13:02.850Z -->

## Selecting an Audio Playback Development Mode

The system provides a variety of APIs for you to develop audio playback applications. You can select them based on the audio data formats, audio sources, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AudioRenderer](using-audiorenderer-for-playback.md): an ArkTS/JS API for audio output. It supports only PCM format and requires the app to continuously write audio data to operate. The app can add data preprocessing before input, such as configuring the sampling rate and bit width of the audio stream. Developers are expected to have basic knowledge of audio processing. It is suitable for developing more professional and diverse media playback apps.

- [AudioHaptic](using-audiohaptic-for-playback.md): provides ArkTS and JS APIs for audio playback with audio-haptic effect. It applies to scenarios where haptic feedback needs to be initiated synchronously during audio playback, for example, when there are incoming calls or messages or users are typing.

- [OHAudio](using-ohaudio-for-playback.md): a Native API for audio output. This API is designed with a normalized architecture and supports both standard audio paths and low-latency paths. It supports only PCM format and is suitable for scenarios where audio output is implemented at the native layer.<!--Del-->

- [TonePlayer](using-toneplayer-for-playback-sys.md): provides ArkTS and JS APIs to implement the playback of dialing tones and ringback tones. It can be used to play the content selected from a fixed type range, without requiring the input of media assets or audio data. This class is applicable to specific scenarios where dialing tones and ringback tones are played. It is available only to system applications.<!--DelEnd-->

In addition to the preceding classes, you can also use **AVPlayer** and **SoundPool** in Media Kit to implement audio playback.

- [AVPlayer](../media/using-avplayer-for-playback.md): an ArkTS/JS API for audio playback. It integrates streaming media and local resource parsing, media resource demuxing, audio decoding, and audio output. It can be used to directly play audio files in formats such as MP3 and M4A, but does not support direct playback of PCM files.

- [SoundPool](../media/using-soundpool-for-playback.md): provides ArkTS and JS APIs to implement short sound playback in low latency mode. It can be used to play short sound effects, such as camera shutter sound effect, key press sound effect, and game shooting sound effect.

## Development Precautions for Background Playback

If you want the application to continue playing in the background (including the scenario where the screen is off), you must develop the audio playback functionality and choose either [accessing AVSession](../avsession/avsession-access-scene.md) or [requesting a continuous task](../../task-management/continuous-task.md) based on your service scenario. The specific rules are as follows:

- When an application needs to play media types (stream types **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, and **STREAM_USAGE_AUDIOBOOK**) and game types (stream type **STREAM_USAGE_GAME**) in the background, it must access AVSession and request continuous tasks.

- In addition to the aforementioned playback types, when an application needs to run other user-perceptible tasks in the background for a long time, it must request continuous tasks of the [AUDIO_PLAYBACK](./../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode) type.

If an application does not meet the above access standards, playback in the background will be muted and frozen by the system, preventing normal background playback. Playback will only be resumed and unmuted when the application is brought back to the foreground.

For details, see [Background Playback](./../avsession/avsession-background-scene.md).