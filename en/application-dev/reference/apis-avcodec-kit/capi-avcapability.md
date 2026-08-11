# AVCapability

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=189acb88a2b58d67d571cf891eda253bc3c80967 translatedAt=2026-08-01T07:17:23.535Z pushedAt=2026-08-01T07:21:22.033Z -->

## Overview

The AVCapability module provides functions for querying codec capabilities. With this module, you can obtain information about the codecs supported by the system at runtime, including basic codec information, supported parameter ranges, profile and level combinations, and optional codec features, so as to dynamically select appropriate codecs and configure parameters correctly.

The main capabilities provided by this module include:

- **Obtaining codec capability instances**: Queries the codec capabilities supported by the system based on the MIME type or codec type, with support for filtering by hardware or software category.

- **Querying basic codec information**: Obtains the codec name, MIME type, and maximum number of instances, and distinguishes between hardware and software codecs as well as secure and non-secure decoders.

- **Querying encoder parameter ranges**: Obtains the supported bitrate range, quality range, and complexity range of the encoder, and checks the support for bitrate modes.

- **Querying audio codec capabilities**: Obtains audio-related parameters such as the sample rate list, sample rate range, and channel count range.

- **Querying video codec capabilities**: Obtains video-related parameters such as the resolution alignment value, resolution range, frame rate range, pixel format, and NativeBuffer format, with support for checking whether specific resolution and frame rate combinations are supported.

- **Querying profiles and levels**: Obtains the list of profiles supported by the codec and the list of levels under a specified profile, and checks whether specific profile and level combinations are supported.

- **Querying codec features**: Checks whether the codec supports optional features such as temporal scalability, B-frames, low latency, long-term reference frames, and pre-encoding downsampling/cropping, and obtains feature properties.

Applicable scenarios include: checking whether the system supports a specified format before creating a codec, distinguishing between hardware and software codecs, obtaining parameter ranges for configuring codec sessions, and querying the support for profiles, levels, and optional features.

For details about the development guide and sample, see [Obtaining Supported Codecs](../../media/avcodec/obtain-supported-codecs.md).

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

## Files

| Name| Description|
| -- | -- |
| [native_avcapability.h](capi-native-avcapability-h.md) | Declares the native APIs used to query the codec capability.|