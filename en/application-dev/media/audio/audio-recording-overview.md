# Audio Recording Development
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Selecting an Audio Recording Development Mode

The system provides a variety of APIs for you to develop audio recording applications. You can select them based on the recording output formats, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AudioCapturer](using-audiocapturer-for-recording.md): provides ArkTS and JS API to implement audio input. It supports only the PCM format and requires applications to continuously read audio data. The application can perform data processing after audio output. This class can be used to develop more professional and diverse recording applications. To use this class, you must have basic audio processing knowledge.

- [OpenSL ES](using-opensl-es-for-recording.md): provides a set of standard, cross-platform native audio APIs. It supports audio input in PCM format and is suitable for recording applications that are ported from other embedded platforms or that implement audio input at the native layer.

- [Using OHAudio for Audio Recording](using-ohaudio-for-recording.md): provides a set of native APIs for audio input. These APIs are normalized in design and support both common and low-latency audio channels. They support the PCM format only. They are suitable for playback applications that implement audio input at the native layer.

In addition to the preceding classes, you can also use **AVRecorder** in Media Kit to implement audio recording.

- [AVRecorder](../media/using-avrecorder-for-recording.md): provides ArkTS and JS APIs to implement audio recording. It also supports audio input, audio encoding, and media encapsulation. You can directly call device hardware, such as microphone, for recording and generate M4A audio files.

## Precautions for Developing Audio Recording Applications

The application must request the ohos.permission.MICROPHONE permission from the user before invoking the microphone to record audio. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
  
For details about how to use and manage microphones, see [Microphone Management](mic-management.md).

- If continuous recording or background recording is required, the application must request a continuous task to prevent it from being suspended. For details, see [Continuous Task](../../task-management/continuous-task.md).
- The application must start recording when it runs in the foreground. It can switch to the background after the recording is started. Recording cannot be started in the background.
- To record audio, the application must use an appropriate recording stream type. For details, see [Selecting the Appropriate Audio Stream Types](using-right-streamusage-and-sourcetype.md).
