# Audio Call Overview
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

Typically, audio calls are classified into VoIP calls and cellular calls.

- Voice over Internet Protocol (VoIP) is a technology that enables you to make voice calls using a broadband Internet connection. During a VoIP call, call information is packed into data packets and transmitted over the network. Therefore, the VoIP call has high requirements on the network quality, and the call quality is closely related to the network connection speed.
  
- Cellular call refers to the traditional telephony service provided by carriers. Currently, APIs for developing cellular calling are available only for system applications.

When developing the audio call service, you must use a proper audio processing strategy based on the [audio scene](#audio-scene) and [ringer mode](#ringer-mode).

## Audio Scene

When an application uses the audio call service, the system switches to the call-related audio scene (specified by [AudioScene](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioscene8)). The system has preset multiple audio scenes, including ringing, cellular call, and voice chat, and uses a scene-specific strategy to process audio.
<!--Del-->
For example, in the cellular call audio scene, the system prioritizes voice clarity. To deliver a crystal clear voice during calls, the system uses the 3A algorithm to preprocess audio data, suppress echoes, eliminates background noise, and adjusts the volume range. The 3A algorithm refers to three audio processing algorithms: Acoustic Echo Cancellation (AEC), Active Noise Control (ANC), and Automatic Gain Control (AGC).<!--DelEnd-->

Currently, the following audio scenes are preset:

- **AUDIO_SCENE_DEFAULT**: default audio scene, which can be used in all scenarios except audio calls.<!--Del-->

- **AUDIO_SCENE_RINGING**: ringing audio scene, which is used when a call is coming and is open only to system applications.

- **AUDIO_SCENE_PHONE_CALL**: cellular call audio scene, which is used for cellular calls and is open only to system applications.<!--DelEnd-->

- **AUDIO_SCENE_VOICE_CHAT**: voice chat scene, which is used for VoIP calls.

The application can call **getAudioScene** in the [AudioManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md) class to obtain the audio scene in use. Before starting or stopping using the audio call service, the application can call this API to check whether the system has switched to the suitable audio scene.

## Ringer Mode

When an audio call is coming, the application notifies the user by playing a ringtone or vibrating, depending on the setting of [AudioRingMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioringmode).

The system has preset the following ringer modes:

- **RINGER_MODE_SILENT**: silent mode, in which no sound is played when a call is coming in.

- **RINGER_MODE_VIBRATE**: vibration mode, in which no sound is played but the device vibrates when a call is coming in.

- **RINGER_MODE_NORMAL**: normal mode, in which a ringtone is played when a call is coming in.

The application can call **getRingerMode** in the [AudioVolumeGroupManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md) class to obtain the ringer mode in use so as to use a proper strategy to notify the user.

If the application wants to obtain the ringer mode changes in time, it can call **on('ringerModeChange')** in the **AudioVolumeGroupManager** class to listen for the changes. When the ringer mode changes, it will receive a notification and can make adjustment accordingly.

## Audio Device Switching During a Call

When a call is coming, the system selects an appropriate audio device based on the default priority. The application can switch the call to another audio device as required.

For details, see [Using the Call Device Switching Component](../avsession/using-switch-call-devices.md).
