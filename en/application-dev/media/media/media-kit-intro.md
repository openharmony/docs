# Introduction to Media Kit

Media Kit provides [AVPlayer](#avplayer) and [AVRecorder](#avrecorder) for playing and recording audio and video.

You will learn how to use the APIs provided by Media Kit to develop a wealth of audio and video playback or recording scenarios. For example, you can use **SoundPool** to implement simple prompt tones so that a drip sound is played upon the receipt of a new message, or use **AVPlayer** to develop a music player, which can loop a piece of music.

## Highlights

- Lightweight media engine
  
   Less system resources (threads and memory) are required. Audio and video playback and recording, flexible pipeline assembly, and source, demuxer, and codec plugins are supported.

- HDR video

   The native data structures and interfaces are provided to support the capture and playback of HDR VIVID. Third-party applications can deliver a more immersive experience by leveraging the HDR capability of the system.

- Sound pool

   Short sound effects (such as the camera shutter sound effect and system notification sound effect) are often required during application development. You can call the APIs provided by **SoundPool** to implement one-time loading of short sounds and multiple times of low-latency playback.

## Development Description

This development guide applies only to audio and video playback or recording, which are implemented by Media Kit. The UI, image processing, media storage, or other related capabilities are not covered.

Before developing features related to audio and video playback or recording, you are advised to understand the following concepts:

- Playback process: network protocol > container format > audio and video codec > graphics/audio rendering

- Network protocols: HLS, HTTP-FLV, HTTP, HTTPS, and more

- Container formats: mp4, mkv, mpeg-ts, and more

- Encoding format: H.264, H.265, and more

## AVPlayer

The AVPlayer transcodes audio and video media assets (such as MP4, MP3, MKV, and MPEG-TS) into renderable images and hearable audio analog signals, and plays the audio and video through output devices.

The AVPlayer provides the integrated playback capability. This means that your application only needs to provide streaming media sources to implement media playback. It does not need to parse or decode data.

### Audio Playback

The figure below shows the interaction when the **AVPlayer** class is used to develop a music application.

**Figure 1** Interaction with external modules for audio playback 

![Audio Playback Interaction Diagram](figures/audio-playback-interaction-diagram.png)

When a music application calls the **AVPlayer** APIs at the JS interface layer to implement audio playback, the player framework at the framework layer parses the media asset into audio data streams (in PCM format). The audio data streams are then decoded by software and output to the audio framework. The audio framework outputs the audio data streams to the audio HDI for rendering. A complete audio playback process requires the cooperation of the application, player framework, audio framework, and audio HDI.

In Figure 1, the numbers indicate the process where data is transferred to external modules.

1. The application transfers the media asset to the **AVPlayer** instance.

2. The player framework outputs the audio PCM data streams to the audio framework, which then outputs the data streams to the audio HDI.

### Video Playback

The figure below shows the interaction when the **AVPlayer** class is used to develop a video application.

**Figure 2** Interaction with external modules for video playback 

![Video playback interaction diagram](figures/video-playback-interaction-diagram.png)

When a video application calls the **AVPlayer** APIs at the JS interface layer to implement audio and video playback, the player framework at the framework layer parses the media asset into separate audio data streams and video data streams. The audio data streams are then decoded by software and output to the audio framework. The audio framework outputs the audio data streams to the audio HDI at the hardware interface layer to implement audio playback. The video data streams are then decoded by hardware (recommended) or software and output to the graphic framework. The graphic framework outputs the video data streams to the display HDI at the hardware interface layer to implement graphics rendering.

A complete video playback process requires the cooperation of the application, XComponent, player framework, graphic framework, audio framework, display HDI, and audio HDI.

In Figure 2, the numbers indicate the process where data is transferred to external modules.

1. The application obtains a window surface ID from the XComponent. For details about how to obtain the window surface ID, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

2. The application transfers the media asset and surface ID to the **AVPlayer** instance.

3. The player framework outputs the video elementary streams (ESs) to the decoding HDI to obtain video frames (NV12/NV21/RGBA).

4. The player framework outputs the audio PCM data streams to the audio framework, which then outputs the data streams to the audio HDI.

5. The player framework outputs the video frames (NV12/NV21/RGBA) to the graphic framework, which then outputs the video frames to the display HDI.

### Supported Formats and Protocols

Audio and video containers and codecs are domains specific to content creators. You are advised to use the mainstream playback formats, rather than custom ones to avoid playback failures, frame freezing, and artifacts. The system will not be affected by incompatibility issues. If such an issue occurs, you can exit playback.

The table below lists the supported protocols.

| Scenario| Description| 
| -------- | -------- |
| Local VOD| The file descriptor is supported, but the file path is not.|
| Network VoD| HTTP, HTTPS, HLS, and DASH are supported.|
| Live webcasting| HLS and HTTP-FLV are supported.|

The table below lists the supported audio playback formats.

| Audio Container Format| Description| 
| -------- | -------- |
| m4a | Audio format: AAC| 
| aac | Audio format: AAC| 
| mp3 | Audio format: MP3| 
| ogg | Audio format: VORBIS | 
| wav | Audio format: PCM| 
| amr | Audio format: AMR| 

<!--Del-->
> **NOTE**
> 
> The supported video formats are further classified into mandatory and optional ones. All vendors must support mandatory ones and can determine whether to implement optional ones based on their service requirements. You are advised to perform compatibility processing to ensure that all the application functions are compatible on different platforms.

| Video Format| Mandatory or Not|
| -------- | -------- |
| H265<sup>10+</sup>      | Yes|
| H264      | Yes|
<!--DelEnd-->

The table below lists the supported playback formats and mainstream resolutions.

| Video Container Format| Description| Resolution| 
| -------- | -------- | -------- |
| mp4 | Video formats: H.265<sup>10+</sup> and H.264<br>Audio formats: AAC and MP3| Mainstream resolutions, such as 4K, 1080p, 720p, 480p, and 270p|
| mkv | Video formats: H.265<sup>10+</sup> and H.264<br>Audio formats: AAC and MP3| Mainstream resolutions, such as 4K, 1080p, 720p, 480p, and 270p|
| ts | Video formats: H.265<sup>10+</sup> and H.264<br>Audio formats: AAC and MP3| Mainstream resolutions, such as 4K, 1080p, 720p, 480p, and 270p|

The table below lists the supported subtitle formats.

| Subtitle Container Format| Protocol| Loading Mode|
| -------- | -------- | -------- |
| srt | File descriptor (FD) for local video on-demand (VOD), and HTTP/HTTPS/HLS/DASH for network VOD| External subtitle|
| vtt | FD for local VOD, and HTTP/HTTPS/HLS/DASH for network VOD| External subtitle|
| webvtt | DASH for network VOD| Built-in subtitle|

> **NOTE**
> 
> When DASH streams include built-in subtitles, external subtitles cannot be used.

## AVRecorder

The AVRecorder captures audio signals, receives video signals, encodes the audio and video signals, and saves them to files. With the AVRecorder, you can easily implement audio and video recording, including starting, pausing, resuming, and stopping recording, and releasing resources. You can also specify parameters such as the encoding format, container format, and file path for recording.

**Figure 3** Interaction with external modules for video recording 

![Video recording interaction diagram](figures/video-recording-interaction-diagram.png)

- Audio recording: When an application calls the **AVRecorder** APIs at the JS interface layer to implement audio recording, the player framework at the framework layer invokes the audio framework to capture audio data through the audio HDI. The audio data is then encoded by software and saved into a file.

- Video recording: When an application calls the **AVRecorder** APIs at the JS interface layer to implement video recording, the camera framework is first invoked to capture image data. Through the video encoding HDI, the camera framework sends the data to the player framework at the framework layer. The player framework encodes the image data through the video HDI and saves the encoded image data into a file.

With the AVRecorder, you can implement pure audio recording, pure video recording, and audio and video recording.

In Figure 3, the numbers indicate the process where data is transferred to external modules.

1. The application obtains a surface ID from the player framework through the **AVRecorder** instance.

2. The application sets the surface ID for the camera framework, which obtains the surface corresponding to the surface ID. The camera framework captures image data through the video HDI and sends the data to the player framework at the framework layer.

3. The camera framework transfers the video data to the player framework through the surface.

4. The player framework encodes video data through the video HDI.

5. The player framework sets the audio parameters for the audio framework and obtains the audio data from the audio framework.

### Supported Formats

The table below lists the supported audio sources.

| Type| Description| 
| -------- | -------- |
| mic | The system microphone is used as the audio source input.| 

The table below lists the supported video sources.

| Type| Description| 
| -------- | -------- |
| surface_yuv | The input surface carries raw data.| 
| surface_es | The input surface carries ES data.| 

The table below lists the supported audio and video encoding formats.

| Encoding Format| Description| 
| -------- | -------- |
| audio/mp4a-latm | Audio encoding format MP4A-LATM.|
| video/hevc | Video encoding format HEVC.| 
| video/avc | Video encoding format AVC.| 
| audio/mpeg | Audio encoding format MPEG.| 
| audio/g711mu | Audio encoding format G.711 μ-law.| 

The table below lists the supported output file formats.

| Format| Description| 
| -------- | -------- |
| mp4 | Video container format MP4.| 
| m4a | Audio container format M4A.| 
| mp3 | Audio container format MP3.| 
| wav | Audio container format WAV.| 
