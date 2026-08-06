# Audio Call Overview

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=da1d0d010fa40411f768d0582071256c8a017697 translatedAt=2026-08-06T01:40:29.120Z pushedAt=2026-08-06T02:22:48.397Z -->

Typically, audio calls are classified into VoIP calls and cellular calls.

- Voice over Internet Protocol (VoIP) call:

A VoIP call is a voice communication technology based on the Internet Protocol (IP). VoIP calls package audio data into packets and transmit them over the network. As a result, VoIP calls have high network requirements, and call quality is closely related to network connection speed.

- Cellular call (for system applications only):

  Traditional telephony service provided by carriers. Currently, APIs for developing cellular calling are available only for system applications.

When developing the audio call service, you must use a proper audio processing strategy based on the [audio scene](#audio-scene) and [ringer mode](#ringer-mode).

## Audio Scene

When an application uses the audio call service, the system switches to the call-related audio scene (specified by [AudioScene](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioscene8)). The system has preset multiple audio scenes, including ringing, cellular call, and voice chat, and uses a scene-specific strategy to process audio.

For example, in a call scenario, greater emphasis is placed on voice clarity. The system uses 3A algorithms to preprocess audio data, suppressing call echo, eliminating background noise, and adjusting the volume range to achieve clear voice output. The 3A algorithms refer to three audio processing algorithms: Acoustic Echo Cancellation (AEC), Active Noise Suppression (ANS), and Automatic Gain Control (AGC).

Currently, the following audio scenes are preset:

- **AUDIO_SCENE_DEFAULT**: default audio scene, which can be used in all scenarios except audio calls.<!--Del-->

- **AUDIO_SCENE_RINGING**: ringing audio scene, which is used when a call is coming and is open only to system applications.

- **AUDIO_SCENE_PHONE_CALL**: cellular call audio scene, which is used for cellular calls and is open only to system applications.<!--DelEnd-->

- **AUDIO_SCENE_VOICE_CHAT**: voice chat scene, which is used for VoIP calls.

The application can call **getAudioScene** in the [AudioManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md) class to obtain the audio scene in use. Before starting or stopping using the audio call service, the application can call this API to check whether the system has switched to the suitable audio scene.

## Ringer Mode

When a user enters an audio call, the app can use ringtone or vibration to alert the user. The system manages the ringtone volume and adjusts the device vibration mode conveniently through the ring mode ([AudioRingMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioringmode)).

The system has preset the following ringer modes:

- **RINGER_MODE_SILENT**: silent mode, in which no sound is played when a call is coming in.

- **RINGER_MODE_VIBRATE**: vibration mode, in which no sound is played but the device vibrates when a call is coming in.

- **RINGER_MODE_NORMAL**: normal mode, in which a ringtone is played when a call is coming in.

The application can call **getRingerMode** in the [AudioVolumeGroupManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md) class to obtain the ringer mode in use so as to use a proper strategy to notify the user.

If the application wants to obtain the ringer mode changes in time, it can call **on('ringerModeChange')** in the **AudioVolumeGroupManager** class to listen for the changes. When the ringer mode changes, it will receive a notification and can make adjustment accordingly.

## Audio Device Switching During a Call

When a call is coming, the system selects an appropriate audio device based on the default priority. The application can switch the call to another audio device as required.

For details, see [Using the Call Device Switching Component](../avsession/using-switch-call-devices.md).