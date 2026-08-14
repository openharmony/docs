# Glossary

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @zengxi_3007-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-11T01:50:56.851Z pushedAt=2026-08-11T12:27:54.159Z -->

## A

### Audio Focus

  A policy mechanism for system audio management. When multiple apps play audio simultaneously, the system controls playback priority through audio focus to avoid audio conflicts. AVPlayer configures the focus handling policy through `AudioInterruptMode`.

### AVImageGenerator

  A tool for extracting an image at a specified time point from a video resource. By providing a video file and time parameters, it outputs a thumbnail or video frame in PixelMap format. It is suitable for scenarios such as generating video preview images and extracting key frames.

### AVMetadata

  A struct that describes the property information of audio and video assets. It contains fields such as title, artist, album name, duration, video width, and video height, and is used to obtain the basic information of media assets.

### AVMetadataExtractor

  A tool for extracting metadata and album covers from audio and video resources. It supports obtaining audio information such as the title, duration, and artist, as well as album cover images, and also supports batch extraction of video thumbnails. It is suitable for media file information display scenarios.

### AVPlayer

  A component that provides end-to-end playback capabilities, supporting playback of various audio and video formats (such as mp4, mp3, and mkv). It transcodes media resources into renderable images and audio signals, and plays them through output devices. AVPlayer supports streaming media playback (HLS, DASH, and HTTP-FLV), subtitle addition, variable-speed playback, and other features.

### AVRecorder

  A component that integrates audio capture, audio encoding, video encoding, and audio/video muxing capabilities. It is used to record audio and video and generate local media files, supporting the configuration of parameters such as encoding format, muxing format, bit rate, and resolution. It is applicable to scenarios such as camera recording and audio recording.

### AVScreenCapture

  A component used to capture audio and video data from the device screen. It supports capturing the main screen, a specified screen, or a specified window, and can collect microphone audio and system playback audio. Output formats include file saving and raw streams. It is applicable to scenarios such as screen recording, meeting sharing, and live streaming.

### AVScreenCaptureRecorder

  A screen recording component provided through ArkTS APIs. It starts screen recording by configuring recording parameters and generates audio/video files, with support for microphone and system audio capture. It is suitable for scenarios that require simple screen recording and file generation.

### AVTranscoder

  A tool used to convert a compressed and encoded video file into another format based on specified parameters. It supports modifying parameters such as audio/video encoding format, bit rate, and container format. It is applicable to scenarios such as video compression, format conversion, and compatibility adaptation.

## D

### Dynamic Adaptive Streaming over HTTP (DASH)

  An HTTP-based adaptive streaming protocol that uses a Media Presentation Description (MPD) file to describe multiple media segments at different bitrates, allowing the player to dynamically switch bitrates based on network conditions. It is suitable for on-demand streaming scenarios.

## H

### High Dynamic Range (HDR)

  A video display technology that delivers more realistic picture quality by expanding the brightness and color range. Media Kit supports the capture and playback of HDR Vivid videos, providing users with a richer visual experience.

### HTTP Live Streaming (HLS)

  An HTTP-based adaptive bitrate streaming protocol. It uses M3U8 index files to describe media segments and supports both live and on-demand streaming. The player can automatically switch between video streams of different bitrates based on network conditions. It is suitable for live streaming and on-demand scenarios.

## I

### Internal Audio Capture

  A mechanism for capturing audio data played internally by the device. The `OH_ALL_PLAYBACK` audio source is used to capture system playback audio, enabling system audio recording during screen recording.

## L

### LowPowerPlayer (LPP)

  A video playback pipeline capability that implements playback from a media source to rendering with low power consumption. It is suitable for scenarios that require long-duration video playback and are power-sensitive. It does not support video-only or audio-only playback.

### LowPowerAudioSink

  The audio rendering component of the LPP. It is responsible for low-power decoding and rendering of audio data, and supports playback control operations such as volume adjustment, speed control, and pause/resume.

### LowPowerVideoSink

  The video rendering component of the LPP. It is responsible for low-power decoding and rendering of video data, sets the display window through `Surface`, and supports playback control operations such as speed playback and pause/resume.

## M

### Media Kit

  A development kit that provides media capabilities such as audio and video playback, recording, and transcoding. It includes modules such as `AVPlayer`, `AVRecorder`, `AVScreenCapture`, `AVMetadataExtractor`, `AVImageGenerator`, `AVTranscoder`, and `SoundPool`, uses a lightweight media engine to support audio and video playback and recording, and supports features such as HDR video and audio pooling.

### MediaSource

  A structure that describes a media source, containing URL and HTTP request header information. It is used to set the source of online media resources and supports creating and configuring request headers through `createMediaSourceWithUrl`.

### Media Presentation Description (MPD)

  A media description file used in the DASH protocol. It is in XML format and describes the individual segments of media content, media streams at different bitrates, and the relationships between them. By parsing the MPD file, the player obtains available media track information and dynamically selects an appropriate bitrate for playback based on network conditions.

### Mic Audio Capture

  A mechanism for capturing external audio data through the microphone and recording ambient sound using the `OH_MIC` audio source. It is used for audio capture in scenarios such as audio recording and screen recording.

### MPEG Version 3 URL UTF-8 Encoding (M3U8)

  An M3U8 file is a media playlist file used in the HLS protocol, encoded in UTF-8. It is used to index and describe the playback sequence of multiple media segments.

## P

### PixelMap

  An object that represents image data. It contains properties such as pixel information, width, height, and format, and is used for image display and processing. Thumbnails output by `AVImageGenerator` and `AVMetadataExtractor` are returned in PixelMap format.

### Player Framework

  A system-level playback service framework. It parses media resources, decodes audio and video data, and outputs them to the audio service and graphics service. AVPlayer and SoundPool implement their playback capabilities through the player framework.

## S

### SoundPool

  A component used for playing short sound effects, supporting one-time loading and multiple low-latency playback. It is suitable for short and urgent sound effect scenarios such as camera shutter sounds and system notification sounds. Currently, it supports playing decoded audio resources under 1 MB.

### Streaming Media

  Audio and video content transmitted in real time over a network, supporting playback while downloading. It includes both live streaming and on-demand streaming. Common protocols include HLS, DASH, and HTTP-FLV.

## T

### TrackDescription

  A list that describes the information of each track in a media file. It includes the index, type, resolution, and other information of video tracks, audio tracks, and subtitle tracks. It is used for track selection and switching in DASH streams.