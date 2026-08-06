# Glossary

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwell-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1b1b94feed3af845145362c5e1bb426b82c90b85 translatedAt=2026-08-06T01:42:04.329Z pushedAt=2026-08-06T03:32:58.169Z -->

## A

### Acoustic Echo Cancellation (AEC)

An algorithm that eliminates echo interference during recording. It is enabled by specifying a specific audio source type, and can effectively improve the audio capture quality in VoIP calls and live streaming scenarios.

### Audio Capturer

An ArkTS/C API for recording PCM audio data. It supports configuring audio capture parameters and managing capture states, and is suitable for developers with audio development experience to implement flexible recording capabilities.

### Audio Focus

A mechanism for unified management of all playback and recording audio streams in the system. It determines whether each audio stream runs, pauses, or stops based on the stream type and the order of initiation, ensuring a consistent user experience when multiple apps are running concurrently.

### Audio Haptic

A feature that enables synchronized playback of audio and vibration, suitable for scenarios requiring low-latency synchronized control of audio and vibration, such as vibration-synced ringtones, keyboard feedback, and message notification feedback.

### Audio Kit

A system-provided audio development framework that offers scenario-based audio playback and recording APIs, helping you quickly build immersive playback and high-definition audio capture capabilities.

### Audio Loopback

A feature that transmits recorded audio to earphones for immediate playback, allowing users to hear their own voice in real time. It is commonly used in karaoke apps.

### Audio Renderer

An ArkTS/C API used to play PCM audio data. It supports manual control of audio data buffering and is suitable for developers with audio development experience who need to implement more flexible playback features.

### Audio Scene

A predefined audio processing scenario provided by the system, such as default, ringtone, cellular call, and voice chat. The system applies different audio processing policies for different audio scenes. For example, the cellular call scene uses 3A algorithms to enhance voice quality.

### Audio Session

A mechanism for managing audio streams within an entire app. Based on sessions, an app can customize focus policies, adjust the timing of focus release to meet specific requirements in concurrent multi-audio-stream scenarios, or set preferred input and output devices for audio streams within the app.

### Audio Stream

An independent audio data processing unit in the audio system that carries audio format and usage scenario information. It can represent playback or recording, and has independent volume adjustment and audio device routing capabilities.

### Audio Stream Info

Information that describes the basic properties of audio data, including sampling rate, channels, bit depth, and encoding type. It serves as a required parameter for creating an audio playback or capture stream.

### Audio Suite

A set of C APIs for professional audio processing. It provides engines, pipelines, and nodes, and supports audio effects such as noise reduction, equalization, and vocal separation for offline editing and real-time rendering scenarios.

### Audio Timestamp

The time at which an audio frame is actually played by or captured from the audio hardware. It is commonly used for playback progress tracking and audio/video synchronization.

### Audio Vivid

An AI-powered audio coding standard jointly developed and released by the UHD World Association (UWA) and the Audio and Video Coding Standard (AVS) Workgroup. Audio Vivid combines PCM audio data with metadata. Compared with conventional stereo audio, it carries metadata that describes the audio content, enabling more realistic sound reproduction and delivering an immersive spatial audio experience.

### AudioVolumeType

A category of audio volume defined by the system based on the purpose of an audio stream, such as media, ringtone, call, and alarm volumes. Each volume type can be adjusted independently without affecting the others.

## B

### Bluetooth A2DP

A Bluetooth data transmission profile (Advanced Audio Distribution Profile, A2DP) used for high-quality audio streaming. It is commonly used for music and video playback on Bluetooth headsets, speakers, and other audio devices.

### Bluetooth SCO

A Bluetooth data transmission protocol (Synchronous Connection-Oriented, SCO) used for real-time bidirectional audio transmission in voice calls. It is commonly used for Bluetooth headset communication.

## C

### Cellular Call

A traditional telephony service provided by mobile carriers. The related APIs are currently available only to system apps.

## H

### Hardware Abstraction Layer (HAL)

An intermediate layer between the operating system kernel and hardware drivers, which abstracts away vendor-specific implementations and provides standardized hardware operation interfaces to upper layers.

### Hardware Driver Foundation (HDF)

A unified driver framework provided by the system for managing and standardizing the development, deployment, and operation of hardware drivers.

### Hardware Device Interface (HDI)

A standardized interface provided by the HAL to upper layers. The audio service interacts with different types of audio hardware by calling the audio HDI to implement playback and recording functions.

## L

### Little-endian (LE)

A data storage method in which the low-order byte of the data is stored at the low memory address, and the high-order byte is stored at the high memory address.

### Low Latency

One of the key performance metrics for audio playback and recording. It is achieved through hardware-software co-design by reducing buffer sizes and optimizing the audio data pipeline, resulting in lower playback and recording latency. Low latency is suitable for latency-sensitive scenarios such as gaming and karaoke.

### Low Power

An audio rendering mode that reduces power consumption by increasing the internal buffer size of the audio renderer, allowing the main processor to remain in a low-power state for longer periods and reducing the frequency of audio data processing. It is suitable for long-duration playback scenarios such as music and audiobooks.

## O

### OHAudio

A set of C APIs introduced in API version 10. By using different configurations with the same APIs, you can achieve different playback and recording modes, including standard, low-latency, and low-power modes. **OHAudio** is widely used for audio development at the Native layer.

### Open Sound Library for Embedded Systems (OpenSL ES)

A free, cross-platform audio API for embedded systems that provides standardized, high-performance, and low-latency audio processing capabilities. The system implements a subset of playback and recording APIs based on this specification. **OHAudio** is recommended for new development.

## P

### Pulse Code Modulation (PCM)

An encoding format that converts analog audio signals into digital signals.

## R

### Resampling

A process of increasing the number of samples through interpolation (upsampling) or decreasing the number of samples through decimation (downsampling), based on the difference between input and output audio sampling rates.

### Ringer Mode

A system-defined mode that controls ringtone volume and device vibration, including silent, vibration, and normal modes. Applications can query the current mode to determine an appropriate notification strategy.

## S

### Sample Format

The bit depth representation of audio samples, including formats such as U8, S16LE, S24LE, S32LE, and F32LE.

### Sampling Rate

The number of samples per channel per second in audio, measured in Hertz (Hz). Common sampling rates include 16000 Hz, 44100 Hz, and 48000 Hz.

### Source Type

The usage scenario type of a recorded audio stream, including microphone, speech recognition, voice call, voice short message, camera recording, live streaming, and more. The system configures audio optimization processing policies based on this type.

### Spatial Audio

An audio technology that extends the traditional stereo experience into three-dimensional space. By adding height perception on top of mono, stereo, and surround sound, it creates an all-encompassing listening experience. Spatial audio provides users with an immersive, interactive, and spatial audio experience.

### Stream Usage

The usage type of an audio stream for playback, including media, movie, audiobook, game, navigation, voice short message, voice call, alarm, ringtone, and notification. It determines the volume type, focus policy, and default output device.

### System Volume

A volume setting managed globally by the system, applicable to all apps and devices. Each type of audio stream has independent system volume control, which can be adjusted via physical volume keys or the settings screen.

## T

### True Wireless Stereo (TWS)

A type of Bluetooth stereo headset in which the left and right earbuds are not physically connected. It pairs with devices such as smartphones over Bluetooth to provide a wireless stereo listening experience.

### 3A Algorithm

A combination of Acoustic Echo Cancellation (AEC), Automatic Noise Cancellation (ANC), and Automatic Gain Control (AGC) algorithms for improving voice clarity during calls.

## V

### Voice over IP (VoIP)

A technology that enables voice communication over Internet Protocol (IP) networks. It is a typical audio usage scenario recognized by the system, which applies audio processing such as noise suppression and voice enhancement to optimize call quality.