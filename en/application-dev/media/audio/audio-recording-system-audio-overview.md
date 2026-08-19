# System Audio Recording Overview and API Selection

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e927321177bf4cc8f913140aea3aa3b5b4a59784 translatedAt=2026-08-15T01:56:13.315Z pushedAt=2026-08-15T08:58:07.470Z -->

Starting from API version 26.0.0, Audio Kit supports apps in recording system audio. Recording system audio, commonly known as internal recording, means that the device uses the audio played internally by the system as the capture source for recording. Unlike external recording (microphone recording), which captures sounds from the surrounding environment through the microphone, internal recording directly obtains the audio data played by apps inside the device and is not affected by ambient noise.

## When to Use

Internal recording is applicable to the following scenarios where audio played inside the device needs to be obtained:

- Meeting sharing: Share content such as presentation audio and video sound played on the device with meeting participants.

- Live streaming: Feed the audio data played by apps such as games and videos into the live encoding and streaming pipeline.

- Audio recording: Record the audio played inside the device for saving or later editing.

- Audio analysis: Obtain the Pulse Code Modulation (PCM) data of the internally played audio for audio analysis services such as song recognition.

## Differences Between Internal and External Recording

| Feature | Internal Recording (System Audio Recording) | External Recording (Microphone Recording) |
|------|---------------------|-------------------|
| Captured content | Audio played inside the device, without capturing the surrounding environment sound. | Sound received by the microphone, which may include the surrounding environment sound. |
| Recording quality | Not affected by surrounding environment noise. | May be affected by surrounding environment noise. |
| Applicable scenarios | Live streaming, online meetings, audio recording, and audio analysis. | Voice recorder, camera recording, voice calls, and speech recognition. |

## Implementation and Authorization

For internal recording, the system obtains audio data from the audio currently being played inside the device and provides the audio data to the app that initiates the recording. This process does not capture the surrounding environment sound through the microphone.

Because system audio may contain media content, message notifications, or information played by other apps, when an app requests to start internal recording, the system performs a user authorization check to ensure that the user is informed. The authorization dialog box may behave differently on different device forms. The app should use the status returned by the asynchronous callback of the startup API as the authorization and startup result.

## Playback-Side Privacy Protection

The playback side can configure the privacy attribute of its own audio stream to control whether other apps are allowed to record it. A playback stream marked as privacy-protected will not be captured by system audio recording. For example, an audio stream containing call content, account information, or other private content can be protected from recording through this configuration. For details about the configuration method, see [Configuring the Internal Recording Policy for the Target Playback Stream](implement-system-audio-recording.md#configuring-the-internal-recording-policy-for-the-target-playback-stream).

## How to Choose an Internal Recording API

If you only need to obtain the PCM data of the system playback audio, or need to feed the audio data into custom encoding, algorithms, and transmission links, use [AudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md) (ArkTS API) or [native_audiocapturer.h](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md) (C API). If you need to record both the screen and the system audio, use [Using AVScreenCapture in Basic Scenarios](../media/avscreencapture-c-basic-process.md).

| Type | Version | Applicable Scenario | Development Guide |
| -------- | ------------ | -------- | -------- |
| AudioCapturer or native_audiocapturer.h | API version 26.0.0 | Only system audio recording is required, or the PCM data needs to be fed into custom encoding, algorithms, and transmission links, for example, live streaming, online meetings, music recognition, and audio analysis. | [Implementing System Audio Recording](implement-system-audio-recording.md) |
| AVScreenCapture Screen Recording Basics | API version 10 | Both the screen video and system audio need to be recorded, for example, screen recording, creating tutorial videos, and game recording. | [Using AVScreenCapture in Basic Scenarios](../media/avscreencapture-c-basic-process.md) |