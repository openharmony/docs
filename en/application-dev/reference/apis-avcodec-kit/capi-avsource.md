# AVSource

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=468f9f7e01b90eea98f2271cd60ae40b7d520cd7 translatedAt=2026-08-01T07:17:32.437Z pushedAt=2026-08-01T07:28:43.803Z -->

## Overview

The AVSource module provides functions for constructing media resource objects. Through this module, you can create media source instances based on URIs, file descriptors, or custom data sources, obtain basic information and track information of media files, and provide a data source for subsequent demuxing operations.

The main capabilities provided by this module include:

- **Media source creation and destruction**: Creates a media source instance based on a URI, file descriptor, or user-defined data source, and destroys the media source instance to release resources.

- **Basic file information acquisition**: Obtains basic information of a media resource file, including the file duration, number of tracks, and latitude and longitude information.

- **Track information acquisition**: Obtains basic information of a specified track, including the track type, encoding format, resolution, frame rate, sampling rate, and number of audio channels.

- **Custom metadata acquisition**: Obtains custom metadata information from a media file.

Applicable scenarios include media player development, video editing, audio and video data analysis, media file parsing, and other scenarios that require access to media file metadata and track information.

This module typically serves as the entry point of the media processing pipeline and works in conjunction with the AVDemuxer module. First, create a media source through AVSource and obtain the track information, and then use AVDemuxer to demux and read the compressed data.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

## Files

| Name| Description|
| -- | -- |
| [native_avsource.h](capi-native-avsource-h.md) | Declares the APIs for parsing audio and video media data.|