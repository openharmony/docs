# Audio Playback Development

## Selecting an Audio Playback Development Mode

OpenHarmony provides multiple classes for you to develop audio playback applications. You can select them based on the audio data formats, audio sources, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AVPlayer](using-avplayer-for-playback.md): provides ArkTS and JS APIs to implement audio and video playback. It also supports parsing streaming media and local assets, decapsulating media assets, decoding audio, and outputting audio. It can play audio files in MP3 and M4A formats, but not in PCM format.

- [AudioRenderer](using-audiorenderer-for-playback.md): provides ArkTS and JS API to implement audio output. It supports only the PCM format and requires applications to continuously write audio data. The applications can perform data preprocessing, for example, setting the sampling rate and bit width of audio files, before audio input. This class can be used to develop more professional and diverse playback applications. To use this class, you must have basic audio processing knowledge.

- [OpenSL ES](using-opensl-es-for-playback.md): provides a set of standard, cross-platform, yet unique native audio APIs. It supports audio output in PCM format and is applicable to playback applications that are ported from other embedded platforms or that implements audio output at the native layer.

- [TonePlayer](using-toneplayer-for-playback.md): provides ArkTS and JS API to implement the playback of dialing tones and ringback tones. It can be used to play the content selected from a fixed type range, without requiring the input of media assets or audio data. This class is application to specific scenarios where dialing tones and ringback tones are played. is available only to system applications.

- Applications often need to use short sound effects, such as camera shutter sound effect, key press sound effect, and game shooting sound effect. Currently, only the **AVPlayer** class can implement audio file playback. More APIs will be provided to support this scenario in later versions.

## Precautions for Developing Audio Playback Applications

To enable your application to play a video in the background or when the screen is off, the application must meet the following conditions:

1. The application is registered with the system for unified management through the **AVSession** APIs. Otherwise, the playback will be forcibly stopped when the application switches to the background. For details, see [AVSession Development](avsession-overview.md).

2. The application must request a continuous task to prevent from being suspended. For details, see [Continuous Task](../task-management/continuous-task.md).

If the playback is interrupted when the application switches to the background, you can view the log to see whether the application has requested a continuous task. If the application has requested a continuous task, there is no log recording **pause id**; otherwise, there is a log recording **pause id**.
