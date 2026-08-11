# Core

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=189acb88a2b58d67d571cf891eda253bc3c80967 translatedAt=2026-08-01T07:18:33.104Z pushedAt=2026-08-01T09:11:58.114Z -->

## Overview

As the backbone of the multimedia framework, this module defines the organization of media data in memory, the standardized description of audio and video parameters, and a unified error code specification, providing common basic capabilities for upper-layer services such as audio/video encoding/decoding and muxing/demuxing.

The main capabilities provided by this module include:

- **Media format description**: Creates and manages OH_AVFormat instances to store audio and video parameters in key-value pairs, supporting multiple data types such as int, long, float, double, string, and buffer, and providing quick creation APIs for audio and video formats.

- **Media buffer management**: Creates and manages OH_AVBuffer instances to carry audio and video data and related metadata, supporting read/write operations on buffer attributes (timestamp, size, offset, flags) and the passing of extended parameters.

- **Audio channel layout**: Defines a complete channel layout scheme from mono to 22.2 channels, supporting stereo, surround sound, Ambisonics 3D audio, and other configurations.

- **Audio vivid metadata construction**: Constructs the metadata required for Audio Vivid 3D audio encoding, supporting audio object position management, gain control, object addition and removal, and metadata merging.

- **Media type definitions**: Defines common media type enums such as HDR types.

- **Error code specifications**: Defines unified media framework error codes, covering various error scenarios such as memory, I/O, timeout, DRM decryption, and network errors.

Applicable scenarios include all scenarios involving audio and video data processing, such as configuring codec parameters, managing input and output buffers, processing 3D audio, parsing HDR video information, and handling codec exceptions.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

## Files

| Name| Description|
| -- | -- |
| [media_types.h](capi-media-types-h.md) | Declares the common media types.|
| [native_audio_channel_layout.h](capi-native-audio-channel-layout-h.md) | Declares the speaker layout for recording and playback. |
| [native_audio_vivid.h](capi-native-audio-vivid-h.md) | Declares the functions and enums related to Audio Vivid. |
| [native_avbuffer.h](capi-native-avbuffer-h.md) | Declares the functions of the media struct AVBuffer.|
| [native_avbuffer_info.h](capi-native-avbuffer-info-h.md) | Declares the attribute definition of the media struct AVBuffer.|
| [native_averrors.h](capi-native-averrors-h.md) | Declares the error codes used by the media framework.|
| [native_avformat.h](capi-native-avformat-h.md) | Declares the functions and enums related to OH_AVFormat.|
| [native_avmemory.h](capi-native-avmemory-h.md) | Declares the attribute definition of the media struct AVMemory.|