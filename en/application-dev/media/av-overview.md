# Audio and Video Overview

You will learn how to use the audio and video APIs provided by the multimedia subsystem to develop a wealth of audio and video playback or recording scenarios. For example, you can use the **TonePlayer** class to implement simple prompt tones so that a drip sound is played upon the receipt of a new message, or use the **AVPlayer** class to develop a music player, which can loop a piece of music.

For every functionality provided by the multimedia subsystem, you will learn multiple implementation modes, each of which corresponds to a specific usage scenario. You will also learn the sub-functionalities in these scenarios. For example, in the **Audio Playback** chapter, you will learn audio concurrency policies, volume management, and output device processing methods. All these will help you develop an application with more comprehensive features.

This development guide applies only to audio and video playback and recording, which are implemented by the [@ohos.multimedia.audio](../reference/apis/js-apis-audio.md) and [@ohos.multimedia.media](../reference/apis/js-apis-media.md) modules. The UI, image processing, media storage, or other related capabilities are not covered.

## Development Description

Before developing an audio feature, especially before implementing audio data processing, you are advised to understand the following acoustic concepts. This will help you understand how the OpenHarmony APIs control the audio module and how to develop audio and video applications that are easier to use and deliver better experience.  

- Audio quantization process: sampling > quantization > encoding

- Concepts related to audio quantization: analog signal, digital signal, sampling rate, audio channel, sample format, bit width, bit rate, common encoding formats (such as AAC, MP3, PCM, and WMA), and common encapsulation formats (such as WAV, MPA, FLAC, AAC, and OGG)

Before developing features related to audio and video playback, you are advised to understand the following concepts:

- Playback process: network protocol > container format > audio and video codec > graphics/audio rendering

- Network protocols: HLS, HTTP, HTTPS, and more

- Container formats: MP4, MKV, MPEG-TS, WebM, and more

- Encoding formats: H.263/H.264/H.265, MPEG4/MPEG2, and more

## Introduction to Audio Streams 

An audio stream is an independent audio data processing unit that has a specific audio format and audio usage scenario information. The audio stream can be used in playback and recording scenarios, and supports independent volume adjustment and audio device routing.

The basic audio stream information is defined by [AudioStreamInfo](../reference/apis/js-apis-audio.md#audiostreaminfo8), which includes the sampling, audio channel, bit width, and encoding information. It describes the basic attributes of audio data and is mandatory for creating an audio playback or recording stream. To enable the audio module to correctly process audio data, the configured basic information must match the transmitted audio data.

### Audio Stream Usage Scenario Information

In addition to the basic information (which describes only audio data), an audio stream has usage scenario information. This is because audio streams differ in the volume, device routing, and concurrency policy. The system chooses an appropriate processing policy for an audio stream based on the usage scenario information, thereby delivering better user experience.

- Playback scenario

  Information about the audio playback scenario is defined by using [StreamUsage](../reference/apis/js-apis-audio.md#streamusage) and [ContentType](../reference/apis/js-apis-audio.md#contenttype).

-  **StreamUsage** specifies the usage type of an audio stream, for example, used for media, voice communication, voice assistant, notification, and ringtone.

-  **ContentType** specifies the content type of data in an audio stream, for example, speech, music, movie, notification tone, and ringtone.

- Recording scenario

  Information about the audio stream recording scenario is defined by [SourceType](../reference/apis/js-apis-audio.md#sourcetype8).

  **SourceType** specifies the recording source type of an audio stream, including the mic source, voice recognition source, and voice communication source.

## Supported Audio Formats

The APIs of the audio module support PCM encoding, including AudioRenderer, AudioCapturer, TonePlayer, and OpenSL ES.

Be familiar with the following about the audio format:

- The common audio sampling rates are supported: 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, and 96000, in units of Hz. For details, see [AudioSamplingRate](../reference/apis/js-apis-audio.md#audiosamplingrate8).
  
The sampling rate varies according to the device type.
  
- Mono and stereo are supported. For details, see [AudioChannel](../reference/apis/js-apis-audio.md#audiochannel8).

- The following sampling formats are supported: U8 (unsigned 8-bit integer), S16LE (signed 16-bit integer, little endian), S24LE (signed 24-bit integer, little endian), S32LE (signed 32-bit integer, little endian), and F32LE (signed 32-bit floating point number, little endian). For details, see [AudioSampleFormat](../reference/apis/js-apis-audio.md#audiosampleformat8).

  Due to system restrictions, only some devices support the sampling formats S24LE, S32LE, and F32LE.

  Little endian means that the most significant byte is stored at the largest memory address and the least significant byte of data is stored at the smallest. This storage mode effectively combines the memory address with the bit weight of the data. Specifically, the largest memory address has a high weight, and the smallest memory address has a low weight.

The audio and video formats supported by the APIs of the media module are described in [AVPlayer and AVRecorder](avplayer-avrecorder-overview.md).
