# Audio Recording Development

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=4dfa24a542ccee7a1c9b2c3754cdfa7d26fb53ff translatedAt=2026-08-15T01:55:38.994Z pushedAt=2026-08-15T08:47:37.454Z -->

## Selecting an Audio Recording Development Mode

The system provides a variety of APIs for you to develop audio recording applications. You can select them based on the recording output formats, audio usage scenarios, and even the programming language you use. Selecting a suitable class helps you reduce development workload and your application deliver a better effect.

- [AudioCapturer](using-audiocapturer-for-recording.md): an ArkTS/JS API for audio input. It only supports PCM format and requires the app to continuously read audio data to work. You can add data processing after audio capture, which requires basic knowledge of audio processing. It is suitable for developing more professional and diverse media recording apps.

- [Using OHAudio for Audio Recording](using-ohaudio-for-recording.md): provides a set of native APIs for audio input. These APIs are normalized in design and support both common and low-latency audio channels. They support the PCM format only. They are suitable for applications that implement audio input at the native layer.

If you need to capture audio played by the device, refer to [Implementing System Audio Recording](implement-system-audio-recording.md).

In addition to the preceding classes, you can also use **AVRecorder** in Media Kit to implement audio recording.

- [AVRecorder](../media/using-avrecorder-for-recording.md): an ArkTS/JS API for audio recording. It integrates audio capture, audio encoding, and media encapsulation. You can directly call device hardware such as the microphone to record audio and generate m4a audio files.

## Precautions for Developing Audio Recording Applications

- The application must request the **ohos.permission.MICROPHONE** permission from the user before invoking the microphone to record audio. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

  For details on how to manage the microphone mute state, refer to [Managing Microphone Mute State](mic-management.md).

- If continuous recording or background recording is required, the application must request a continuous task to prevent it from being suspended. For details, see [Continuous Task (ArkTS)](../../task-management/continuous-task.md).

- The application must start recording when it runs in the foreground. It can switch to the background after the recording is started. Recording cannot be started in the background.

- When recording audio, the app must use an appropriate recording stream type. For details, refer to [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md).

- To check whether the microphone is occupied, refer to [Determining Whether the Microphone Is Occupied](audio-recording-stream-management.md#determining-whether-the-microphone-is-occupied).

- If the application is required to record the screen, refer to [Using AVScreenCaptureRecorder to Record Screens and Write Them to Files (ArkTS)](../media/using-avscreencapture-ArkTs.md) and [Using AVScreenCapture to Capture Screens and Write Them to Files (C/C++)](../media/using-avscreencapture-for-file.md).