# Introduction to Audio Kit

Audio Kit provides scenario-specific audio playback and recording APIs to help you quickly build HD audio collection and immersive playback capabilities.

## Highlights

- Low-latency playback
  
   Unified low-latency and non-low-latency audio playback APIs are provided to achieve the lowest audio output latency on various hardware devices. For example, low-latency APIs can be used to implement fast and smooth audio playback in scenarios such as gaming, prompt/alarm tones, and Karaoke.

- Low-power playback

   In long-duration audio playback scenarios such as music playing and audiobook listening, a differentiated audio buffer processing mechanism is used for the screen-off scene. This helps audio playback consume less power by reducing the CPU wake-up frequency.

- Audio effect mode

   Applications can enable or disable the system audio effects as required to deliver the optimal audio effect output.

   The system provides scenario-specific audio effects, for example, audio effects for music playing, audiobook listening, and movie watching. If your application requires custom audio effects, you can disable the system audio effects.

- Spatial audio

   Spatial audio APIs are provided. Applications can play audio sources in different formats (stereo, multi-channel, and AudioVivid), and users can get a sense of space and direction while wearing TWS earbuds for listening.

- Audio-haptic

   Provides AudioHaptic APIs to implement low-delay synchronous control of audio and haptic streams. When the audio-haptic effect is enabled, users can get rhythmic auditory and haptic feedback while typing or having incoming calls.

## Development Description

For every functionality provided by the multimedia subsystem, you will learn multiple implementation modes, each of which corresponds to a specific usage scenario. You will also learn the sub-functionalities in these scenarios. For example, in the **Audio Playback** chapter, you will learn audio concurrency policies, volume management, and output device processing methods. All these will help you develop an application with more comprehensive features.

This development guide applies only to audio playback or recording, which are implemented by Audio Kit. The UI, image processing, media storage, or other related capabilities are not covered.

Before developing an audio feature, especially before implementing audio data processing, you are advised to understand the following acoustic concepts. This will help you understand how the APIs control the audio module and how to develop audio and video applications that are easier to use and deliver better experience.  

- Audio quantization process: sampling > quantization > encoding

- Concepts related to audio quantization: analog signal, digital signal, sampling rate, audio channel, sample format, bit width, bit rate, common encoding formats (such as AAC, MP3, PCM, and WMA), and common container formats (such as WAV, MPA, FLAC, AAC, and OGG)

## Introduction to Audio Streams

An audio stream is an independent audio data processing unit that has a specific audio format and audio usage scenario information. The audio stream can be used in playback and recording scenarios, and supports independent volume adjustment and audio device routing.

The basic audio stream information is defined by [AudioStreamInfo](../../reference/apis-audio-kit/js-apis-audio.md#audiostreaminfo8), which includes the sampling, audio channel, bit width, and encoding information. It describes the basic attributes of audio data and is mandatory for creating an audio playback or recording stream. To enable the audio module to correctly process audio data, the configured basic information must match the transmitted audio data.

### Audio Stream Usage Scenario Information

In addition to the basic information (which describes only audio data), an audio stream has usage scenario information. This is because audio streams differ in the volume, device routing, and concurrency policy. The system chooses an appropriate processing policy for an audio stream based on the usage scenario information, thereby delivering better user experience.

- Playback scenario

  Information about the audio playback scenario is defined by [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage).

  **StreamUsage** specifies the usage type of an audio stream, for example, used for media, voice communication, voice assistant, notification, and ringtone.

- Recording scenario

  Information about the audio stream recording scenario is defined by [SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8).

  **SourceType** specifies the recording source type of an audio stream, including the mic source, voice recognition source, and voice communication source.

For details, see [Selecting an Appropriate Audio Stream Type](using-right-streamusage-and-sourcetype.md).

## Supported Audio Formats

The APIs of the audio module support PCM encoding, including AudioRenderer, AudioCapturer, TonePlayer, and OpenSL ES.

Be familiar with the following about the audio format:

- The common audio sampling rates are supported: 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200<sup>12+</sup>, 96000, 176400<sup>12+</sup>, and 192000<sup>12+</sup>, in units of Hz. For details, see [AudioSamplingRate](../../reference/apis-audio-kit/js-apis-audio.md#audiosamplingrate8).
  
  The sampling rate varies according to the device type.

- Mono and stereo are supported. For details, see [AudioChannel](../../reference/apis-audio-kit/js-apis-audio.md#audiochannel8).

- The following sampling formats are supported: U8 (unsigned 8-bit integer), S16LE (signed 16-bit integer, little endian), S24LE (signed 24-bit integer, little endian), S32LE (signed 32-bit integer, little endian), and F32LE (signed 32-bit floating point number, little endian). For details, see [AudioSampleFormat](../../reference/apis-audio-kit/js-apis-audio.md#audiosampleformat8).
  
  Due to system restrictions, only some devices support the sampling formats S24LE, S32LE, and F32LE.

  Little endian means that the most significant byte is stored at the largest memory address and the least significant byte of data is stored at the smallest. This storage mode effectively combines the memory address with the bit weight of the data. Specifically, the largest memory address has a high weight, and the smallest memory address has a low weight.
