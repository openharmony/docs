# Audio Playback Development

## Selecting an Audio Playback Development Mode

The system provides a variety of APIs for you to develop audio playback applications. You can select them based on the audio data formats, audio sources, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AudioRenderer](using-audiorenderer-for-playback.md): provides ArkTS and JS APIs to implement audio output. It supports only the PCM format and requires applications to continuously write audio data. The applications can perform data preprocessing, for example, setting the sampling rate and bit width of audio files, before audio input. This class can be used to develop more professional and diverse playback applications. To use this class, you must have basic audio processing knowledge.

- [AudioHaptic](using-audiohaptic-for-playback.md): provides ArkTS and JS APIs for audio playback with audio-haptic effect. It applies to scenarios where haptic feedback needs to be initiated synchronously during audio playback, for example, when there are incoming calls or messages or users are typing.

- [OpenSL ES](using-opensl-es-for-playback.md): provides a set of standard, cross-platform native audio APIs. It supports audio output in PCM format and is suitable for playback applications that are ported from other embedded platforms or that implement audio output at the native layer.

- [Using OHAudio for Audio Playback](using-ohaudio-for-playback.md): provides a set of native APIs for audio output. These APIs are normalized in design and support both common and low-latency audio channels. They support the PCM format only. They are suitable for playback applications that implement audio output at the native layer.<!--Del-->

- [TonePlayer](using-toneplayer-for-playback.md): provides ArkTS and JS APIs to implement the playback of dialing tones and ringback tones. It can be used to play the content selected from a fixed type range, without requiring the input of media assets or audio data. This class is applicable to specific scenarios where dialing tones and ringback tones are played. It is available only to system applications.<!--DelEnd-->

In addition to the preceding classes, you can also use Media Kit to implement audio playback.

- [AVPlayer](../media/using-avplayer-for-playback.md): provides ArkTS and JS APIs to implement audio playback. It also supports parsing streaming media and local assets, decapsulating media assets, decoding audio, and outputting audio. It can play audio files in MP3 and M4A formats, but not in PCM format.

- [SoundPool](../media/using-soundpool-for-playback.md): provides ArkTS and JS APIs to implement short sound playback in low latency mode. It can be used to play short sound effects, such as camera shutter sound effect, key press sound effect, and game shooting sound effect.

## Precautions for Developing Audio Playback Applications

To enable your application to play a video in the background or when the screen is off, the application must meet the following conditions:

1. The application is registered with the system for unified management through the **AVSession** APIs. Otherwise, the playback will be forcibly stopped when the application switches to the background. For details, see [AVSession Kit Development](../avsession/avsession-overview.md).

2. The application must request a continuous task to prevent from being suspended. For details, see [Continuous Task](../../task-management/continuous-task.md).

If the playback is interrupted when the application switches to the background, you can view the log to see whether the application has requested a continuous task. If the application has requested a continuous task, there is no log recording **pause id**; otherwise, there is a log recording **pause id**.
