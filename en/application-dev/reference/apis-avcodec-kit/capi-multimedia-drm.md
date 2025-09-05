# Multimedia_Drm

## Overview

The module enables third-party applications to handle media decapsulation and demultiplexing on their own, rather than relying on system-provided solutions.<br>After creating a DRM instance and session, you can call the decryption API provided by the DRM to decrypt content. The decryption parameter struct describes the format for passing decryption parameters.

For details about the development guide and sample, see [Media Data Demultiplexing](../../media/avcodec/audio-video-demuxer.md).

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [native_cencinfo.h](capi-native-cencinfo-h.md) | Declares the native APIs used to set decryption parameters.|
