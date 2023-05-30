# Audio Recording Development

## Selecting an Audio Recording Development Mode

OpenHarmony provides multiple classes for you to develop audio recording applications. You can select them based on the recording output formats, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AVRecorder](using-avrecorder-for-recording.md): provides ArkTS and JS APIs to implement audio and video recording. It also supports audio input, audio encoding, and media encapsulation. You can directly call device hardware, such as microphone, for recording and generate M4A audio files.

- [AudioCapturer](using-audiocapturer-for-recording.md): provides ArkTS and JS API to implement audio input. It supports only the PCM format and requires applications to continuously read audio data. The application can perform data processing after audio output. This class can be used to develop more professional and diverse recording applications. To use this class, you must have basic audio processing knowledge.

- [OpenSL ES](using-opensl-es-for-recording.md): provides a set of standard, cross-platform, yet unique native audio APIs. It supports audio input in PCM format and is applicable to recording applications that are ported from other embedded platforms or that implements audio input at the native layer.

## Precautions for Developing Audio Recording Applications

The application must request the **ohos.permission.MICROPHONE** permission from the user before invoking the microphone to record audio.

For details about how to request the permission, see [Permission Application Guide](../security/accesstoken-guidelines.md). For details about how to use and manage microphones, see [Microphone Management](mic-management.md).
