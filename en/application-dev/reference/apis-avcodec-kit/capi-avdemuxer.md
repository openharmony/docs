# AVDemuxer

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650-->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=468f9f7e01b90eea98f2271cd60ae40b7d520cd7 translatedAt=2026-08-01T07:17:36.843Z pushedAt=2026-08-01T07:25:23.133Z -->

## Overview

The AVDemuxer module provides the APIs for extracting [samples](../../media/avcodec/audio-video-demuxer.md) from media streams.

The main capabilities provided by this module include:

- **Demuxer creation and destruction**: Creates a demuxer instance from a media source (OH_AVSource) and destroys the demuxer instance to release resources.

- **Track selection**: Selects or deselects tracks from which data is to be read. Multiple track selection is supported.

- **Frame data reading**: Reads compressed frame data (samples) from selected tracks and obtains frame-related information such as timestamps, sizes, and flags.

- **Seek**: Seeks to a specified position based on timestamps, supporting seek forward, seek backward, and seek to nearest modes.

- **DRM information processing**: Sets a DRM information callback to obtain decryption information for DRM-protected media content.

Applicable scenarios include media player development, video editing, audio and video data analysis, media file parsing, demuxing of DRM-protected media content, and other scenarios that require extracting compressed data from media files.

This module is typically used together with the AVSource module. A media source is first created through AVSource, and then demuxing is performed through AVDemuxer. The demuxed compressed data can be fed into video/audio decoders for decoding.

For details about the development guide and sample, see [Media Data Demultiplexing](../../media/avcodec/audio-video-demuxer.md).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

## Files

| Name| Description|
| -- | -- |
| [native_avdemuxer.h](capi-native-avdemuxer-h.md) | Declares the APIs for parsing audio and video media data.|