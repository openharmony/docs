# Introduction to Media Kit

Media Kit is used to develop audio and video playback or recording features. The Media Kit development guide provides comprehensive instructions on how to develop various audio and video modules, assisting you in utilizing the system's audio and video APIs to achieve desired functionalities. For example, you can use the SoundPool to implement simple prompt tones so that a drip sound is played upon the receipt of a new message; you can use the AVPlayer to develop a music player, which can loop a piece of music.

Media Kit provides the following modules:

- [AVPlayer](#avplayer): plays audio and video clips.
- [SoundPool](#soundpool): plays short sounds.
- [AVRecorder](#avrecorder): records audio and video clips.
- [AVScreenCapture](#avscreencapture): captures the screen.
- [AVMetadataExtractor](#avmetadataextractor): obtains audio and video metadata.
- [AVImageGenerator](#avimagegenerator): obtains video thumbnails.
- [AVTranscoder](#avtranscoder): video transcoding.

## Highlights

- Lightweight media engine
  
   Less system resources (threads and memory) are required. Audio and video playback and recording, flexible pipeline assembly, and source, demuxer, and codec plugins are supported.

- HDR video

   The data structures and interfaces are provided to support the capture and playback of HDR VIVID. Third-party applications can deliver a more immersive experience by leveraging the HDR capability of the system.

- Sound pool

   Short sound effects (such as the camera shutter sound effect and system notification sound effect) are often required during application development. You can call the SoundPool APIs to implement one-time loading of short sounds and multiple times of low-latency playback.

## Development Description

This development guide applies only to audio and video playback or recording, which are implemented by Media Kit. The UI, image processing, media storage, or other related capabilities are not covered.

Before developing features related to audio and video playback or recording, you are advised to understand the following concepts:

- Playback process: network protocol > container format > audio and video codec > graphics/audio rendering

- Network protocols: HLS, HTTP-FLV, HTTP, HTTPS, and more

- Container formats: mp4, mkv, mpeg-ts, and more

- Encoding format: H.264, H.265, and more

For details about the streaming media development process, see [Using AVPlayer to Play Streaming Media](streaming-media-playback-development-guide.md).

## AVPlayer

The AVPlayer transcodes audio and video media assets (such as MP4, MP3, MKV, and MPEG-TS) into renderable images and hearable audio analog signals, and plays the audio and video through output devices.

The AVPlayer provides the integrated playback capability. This means that your application only needs to provide streaming media sources to implement media playback. It does not need to parse or decode data.

### Audio Playback

The figure below shows the interaction between the AVPlayer and external modules when it is used to develop a music application.

![Audio Playback Interaction Diagram](figures/audio-playback-interaction-diagram.png)

When a music application calls the AVPlayer APIs at the JS interface layer to implement audio playback, the player framework at the framework layer parses the media asset into audio data streams (in PCM format). The audio data streams are then decoded by software and output to the audio framework. The audio framework outputs the audio data streams to the audio HDI for rendering. A complete audio playback process requires the cooperation of the application, player framework, audio framework, and audio HDI.

In this figure, the numbers indicate the process where data is transferred to external modules.

1. The application transfers the media asset to the AVPlayer instance.

2. The player framework outputs the audio PCM data streams to the audio framework, which then outputs the data streams to the audio HDI.

### Video Playback

The figure below shows the interaction between the AVPlayer and external modules when it is used to develop a video playback application.

![Video playback interaction diagram](figures/video-playback-interaction-diagram.png)

When a video playback application calls the AVPlayer APIs at the JS interface layer to implement audio and video playback, the player framework at the framework layer parses the media asset into separate audio data streams and video data streams. The audio data streams are then decoded by software and output to the audio framework. The audio framework outputs the audio data streams to the audio HDI at the hardware interface layer to implement audio playback. The video data streams are then decoded by hardware (recommended) or software and output to the graphic framework. The graphic framework outputs the video data streams to the display HDI at the hardware interface layer to implement graphics rendering.

A complete video playback process requires the cooperation of the application, XComponent, player framework, graphic framework, audio framework, display HDI, and audio HDI.

In this figure, the numbers indicate the process where data is transferred to external modules.

1. The application obtains a window surface ID from the XComponent. For details about how to obtain the window surface ID, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

2. The application transfers the media asset and surface ID to the AVPlayer instance.

3. The player framework outputs the video elementary streams (ESs) to the decoding HDI to obtain video frames (NV12/NV21/RGBA).

4. The player framework outputs the audio PCM data streams to the audio framework, which then outputs the data streams to the audio HDI.

5. The player framework outputs the video frames (NV12/NV21/RGBA) to the graphic framework, which then outputs the video frames to the display HDI.

### Supported Formats and Protocols

Audio and video containers and codecs are domains specific to content creators. You are advised to use the mainstream playback formats, rather than custom ones to avoid playback failures, stutters, and artifacts. The system will not be affected by incompatibility issues. If such an issue occurs, you can exit playback.

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
| ape | Audio format: APE |

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

## SoundPool

The SoundPool transcodes audio assets (such as MP3, M4A, and WAV) into audio analog signals and plays the signals through output devices.

The SoundPool provides the capability of playing short sounds. This means that your application only needs to provide audio asset sources to implement sound playback. It does not need to parse or decode data.

The figure below shows the interaction between the SoundPool and external modules when it is used to develop an audio playback application.

![SoundPool Interaction Diagram](figures/soundpool-interaction-diagram.png)

When an audio playback application calls the SoundPool APIs at the JS interface layer to implement sound playback, the player framework at the framework layer parses the media asset into audio data streams (in PCM format). The audio data streams are then decoded by software and output to the audio framework. The audio framework outputs the audio data streams to the audio HDI for rendering. A complete audio playback process requires the cooperation of the application, player framework, audio framework, and audio HDI.

In this figure, the numbers indicate the process where data is transferred to external modules.

1. The application transfers the media asset to the SoundPool instance.

2. The player framework outputs the audio PCM data streams to the audio framework, which then outputs the data streams to the audio HDI.

### Supported Formats and Protocols

Audio containers, video containers, and audio codecs are domains specific to content creators. You are advised to use the mainstream playback formats, rather than custom ones to avoid playback failures and stutters. The system will not be affected by incompatibility issues. If such an issue occurs, you can exit playback.

The table below lists the supported protocols.

| Scenario| Description| 
| -------- | -------- |
| Local VOD| The file descriptor is supported, but the file path is not.|

The table below lists the supported audio playback formats.

| Audio Container Format| Description| 
| -------- | -------- |
| m4a | Audio format: AAC| 
| aac | Audio format: AAC| 
| mp3 | Audio format: MP3| 
| ogg | Audio format: VORBIS | 
| wav | Audio format: PCM| 

## AVRecorder

The AVRecorder captures audio signals, receives video signals, encodes the audio and video signals, and saves them to files. With the AVRecorder, you can easily implement audio and video recording, including starting, pausing, resuming, and stopping recording, and releasing resources. You can also specify parameters such as the encoding format, container format, and file path for recording.

The following figure shows the interaction between the AVRecorder and external modules when it is used to develop a video recording application.

![Video recording interaction diagram](figures/video-recording-interaction-diagram.png)

- Audio recording: When an application calls the AVRecorder APIs at the JS interface layer to implement audio recording, the player framework at the framework layer invokes the audio framework to capture audio data through the audio HDI. The audio data is then encoded by software and saved into a file.

- Video recording: When an application calls the AVRecorder APIs at the JS interface layer to implement video recording, the camera framework is first invoked to capture image data. Through the video encoding HDI, the camera framework sends the data to the player framework at the framework layer. The player framework encodes the image data through the video HDI and saves the encoded image data into a file.

With the AVRecorder, you can implement pure audio recording, pure video recording, and audio and video recording.

In this figure, the numbers indicate the process where data is transferred to external modules.

1. The application obtains a surface ID from the player framework through the AVRecorder instance.

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
| audio/3gpp | Audio in AMR-NB format.| 
| audio/amr-wb | Audio in AMR-WB format.| 

The table below lists the supported output file formats.

| Format| Description| 
| -------- | -------- |
| mp4 | Video container format MP4.| 
| m4a | Audio container format M4A.| 
| mp3 | Audio container format MP3.| 
| wav | Audio container format WAV.| 
| amr | Audio container format AMR.| 

## AVScreenCapture

The AVScreenCapture captures audio and video signals and saves screen data to files by means of encoding, helping you easily implement screen capture. It consists of two sets of APIs: one for storing screen recordings and the other for obtaining streams during screen capture. It allows the caller to specify parameters such as the encoding format, container format, and file path for screen capture.

The following figure shows the interaction between the AVScreenCapture and external modules when it is used to develop a screen capture application.

![AvScreenCapture interaction diagram](figures/avscreencapture-interaction-diagram.png)

- Audio capture: When an application calls the AVScreenCapture APIs at the JS or native interface layer to implement audio capture, the player framework at the framework layer invokes the audio framework to capture audio data through the audio HDI. The audio data is then encoded by software and saved into a file.
- Screen capture: When an application calls the AVScreenCapture APIs at the JS or native interface layer to implement screen capture, the player framework at the framework layer invokes the graphic framework to capture screen data. The screen data is then encoded by software and saved into a file.

### Supported Formats

The table below lists the supported audio sources.

| Type| Description| 
| -------- | -------- |
| MIC | The system microphone is used as the audio source input.| 
| ALL_PLAYBACK | Internal recording is used as the audio source input.| 

The table below lists the supported video sources.

| Type| Description| 
| -------- | -------- |
| SURFACE_RGBA | The output buffer is RGBA data.| 

The table below lists the supported audio encoding formats.

| Audio Encoding Format| Description| 
| -------- | -------- |
| AAC_LC | AAC_LC.|

The table below lists the supported video encoding formats.

| Video Encoding Format| Description| 
| -------- | -------- |
| H264 | H.264.|

The table below lists the supported output file formats.

| Format| Description| 
| -------- | -------- |
| mp4 | Video container format MP4.| 
| m4a | Audio container format M4A.| 

## AVMetadataExtractor

The AVMetadataExtractor is used to obtain audio and video metadata. With the AVMetadataExtractor, you can extract rich metadata information from original media assets. For example, for an audio asset, you can obtain its details, such as the title, artist, album name, and duration. The process of obtaining the metadata of a video asset is similar. The only difference is that the process of obtaining the album cover is not required for a video asset, because no album cover is available in the video asset.

The full process of obtaining the metadata of an audio asset includes creating an AVMetadataExtractor instance, setting resources, obtaining the metadata, obtaining the album cover (optional), and releasing the instance.

### Supported Formats

For details about the supported audio and video sources, see [Media Data Demultiplexing](../avcodec/audio-video-demuxer.md).

## AVImageGenerator

The AVImageGenerator is used to obtain video thumbnails. With the AVImageGenerator, you can obtain video frames at a specified time from original media assets.

### Supported Formats

For details about the supported video sources, see [Video Decoding](../avcodec/video-decoding.md).

## AVTranscoder

The AVTranscoder is used to convert a compressed video file into a video in another format based on specified parameters.

### Supported Formats

The AVTranscoder provides the following services:

The encoding parameters (format and bit rate) and container format of the source video file can be modified. The audio and video encoding and container formats of the source video are compatible with the AVCodec for decoding and demultiplexing purposes, whereas those of the target video are compatible with the AVCodec for encoding and multiplexing purposes.

<!--RP1--><!--RP1End-->
- The following source video formats are supported:

   | Container Format | Video Encoding Type  | Audio Encoding Type  |
   | -------- | :----------------------------| :----------------------------|
   | mp4      | AVC (H.264)<!--RP2--><!--RP2End-->, MPEG4| AAC, MPEG (MP3)|
   | mkv      | AVC(H.264)<!--RP3--><!--RP3End--> | AAC, MPEG (MP3), OPUS|
   | mpeg-ts  | AVC (H.264)<!--RP4--><!--RP4End-->, MPEG2, MPEG4| AAC, MPEG (MP3)<!--RP5--><!--RP5End-->|
   | flv      | AVC (H.264)<!--RP6--><!--RP6End--> |  AAC  |
   | mpeg-ps  | AVC (H.264), MPEG2|    MPEG (MP2, MP3)|
   | avi      | H.263, AVC (H.264), MPEG2, MPEG4 | AAC, MPEG (MP2, MP3), PCM|

   For details about the source video formats supported by transcoding, see [AVCodec Supported Formats](../avcodec/avcodec-support-formats.md#media-data-multiplexing).

- The following target video formats are supported:

   | Container Format | Video Encoding Type  | Audio Encoding Type  |
   | -------- | :------------------| :---------------- |
   | mp4      | AVC (H.264)<!--RP7--><!--RP7End--> | AAC |

- The support for tracks is as follows:
  - Subtitle tracks are not supported. If the original video has subtitle tracks, they are discarded after transcoding.
  - Only one video track can be output. If the original video has multiple video tracks, the first one is selected for transcoding.
  - Only one audio track can be output. If the original video has multiple audio tracks, the first one is selected for transcoding.
