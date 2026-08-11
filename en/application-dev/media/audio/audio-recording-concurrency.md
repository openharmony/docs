# Recording Concurrency Strategy Description

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29aa363c8c07cd0d943043ae209ad0a85fcdc3c5 translatedAt=2026-08-06T01:44:50.879Z pushedAt=2026-08-06T07:16:37.879Z -->

The audio source of an audio input is typically audio data captured by a built-in microphone, an external device, or a remote distributed device, but it may also be audio data sent by other apps to the system for playback. Based on the audio source, audio inputs are classified into two categories: internal recording audio input and external recording audio input.

- Internal recording audio input: This type uses audio data within the system as the source, commonly referred to as internal recording. The corresponding stream is known as the internal recording stream.

  Common examples of internal recording audio include audio data captured during screen recording (such as sounds played by other applications) and audio data intended for playback on other devices.

- External recording audio input: This type captures external sounds through audio interfaces as the source, commonly referred to as external recording. The corresponding stream is known as the external recording stream.

  Typical examples of external recording include audio recording with a voice recorder, voice activation and recognition for voice assistants, and audio recording transmitted to the other end during a VoIP call.

Usually, when an app requests audio recording, it exclusively occupies the audio input. However, in some scenarios, two or more apps may request recording simultaneously or in succession, all expecting to obtain data from the audio input within the same time period. This situation is referred to as recording concurrency, which is further divided into two types: concurrent existence and concurrent operation.

- Concurrent existence refers to the state where one or more different audio recording clients ([AudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md)) created by apps exist simultaneously within the same time frame.

- Concurrent operation refers to the state where, on the basis of concurrent existence, the audio streams initiated by different audio recording clients (AudioCapturer) are all in the running state within the same time frame, meaning these clients are recording audio simultaneously.

When concurrent recording occurs, each application requesting audio recording wants to obtain the audio input data. This presents the challenge of transmitting the same audio source to multiple applications simultaneously.

## Concurrent Recording

Previously, recording concurrency across different recording stream types between different apps in the system was subject to strict [audio focus policy control](audio-playback-concurrency.md#audio-focus-strategy), and simultaneous recording was generally not supported.

Concurrent recording between internal and external audio inputs is not subject to this limitation if permitted by security and privacy strategies. For example, when an internal recording stream is enabled in a screen recording application, it is possible to simultaneously use a voice recorder for recording or a voice assistant for voice recognition.

The current system version has relaxed the restrictions on concurrent recording between certain recording stream types, allowing multiple recording streams to obtain audio data simultaneously. However, because this data originates from the same audio source, the audio effect is identical, which may only meet some concurrent recording requirements.

### Priority Adjustment Scheme

In most cases, the quality of audio data depends on the optimization processing strategy of the system for audio input data.

When an application initiates audio recording, the system identifies the audio scenario based on the audio stream type and other related parameters sent by the application, and selects an appropriate strategy to handle the input data. For instance, when an application initiates a VoIP call, the system performs noise reduction and voice enhancement optimizations on the VoIP audio stream.

For some recording stream types, audio recording only requires obtaining audio input data, while for others, it heavily depends on the system's optimization processing. If an inappropriate system optimization strategy is selected during concurrency, it may lead to a poor experience. Therefore, for audio recording of such stream types, it is necessary to ensure that the system can still configure an appropriate optimization processing strategy during concurrent recording. To this end, the system assigns priorities to these recording stream types and adds a priority adjustment scheme on top of the existing [audio focus policy](audio-playback-concurrency.md#audio-focus-strategy) control scheme.

The principle of this adjustment is to **prioritize the optimization strategies corresponding to high-priority audio recording stream types for processing audio input data**.

### Recording Concurrency Strategy

The current concurrent recording strategy generally follows the following principles:

1. Whether multiple audio streams can obtain audio input data simultaneously during concurrent recording depends on the [audio focus strategies](audio-playback-concurrency.md#audio-focus-strategy) of the respective audio stream types. You need to ensure proper focus adaptation.

2. The quality of audio input data is determined by the optimization processing strategy selected by the system based on the current priority adjustment scheme. It is recommended that you inform users that the quality of the recording data may be affected during concurrent recording.

## Usage Suggestion

The system has implemented preliminary management for concurrent recording scenarios through a dual mechanism of [audio focus strategies](audio-playback-concurrency.md#audio-focus-strategy) and priority adjustment. Although the system now allows limited concurrent recording for certain different audio stream types, the following key points should be noted:

### Limitations of Concurrent Recording

- Uncontrollable audio effects: During concurrent recording, the audio input data of multiple recording streams comes from the same audio source, which may affect audio effects.

- System overhead: Concurrent recording may increase system overhead.

### Recommendations

- Understand [audio focus strategies](audio-playback-concurrency.md#audio-focus-strategy) and ensure proper focus adaptation, [handling audio focus changes](audio-playback-concurrency.md#handling-audio-focus-changes) promptly.

- Avoid concurrent recording scenarios whenever possible. Design applications to minimize overlap with other recording tasks. If necessary, display a message to users such as "Another recording task is currently in progress."

  If concurrent recording is unavoidable, clearly inform users that audio quality may be affected.

- Different recording stream types correspond to different system optimization processing strategies. You are advised to select an appropriate [SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) based on your requirements. For details, see [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md).

- If recording is no longer required, stop and release recording resources promptly to avoid impacting other audio streams and to reduce unnecessary system overhead.

- Application implementation should not overly rely on fixed concurrent recording rules but should adapt based on the status returned by system interfaces.