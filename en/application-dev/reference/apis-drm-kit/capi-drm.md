# Drm

## Overview

The Digital Rights Management (DRM) module provides APIs to implement digital rights protection.

You can refer to the corresponding development guide and samples based on your development requirements.

- [DRM Development (C/C++)](../../media/drm/drm-c-dev-guide.md)
- [Using AVCodec to Play DRM Content (C/C++)](../../media/drm/drm-avcodec-integration.md)


**Since**: 11

## Files

| Name| Description|
| -- | -- |
| [native_drm_common.h](capi-native-drm-common-h.md) | Declares the DRM data types.|
| [native_drm_err.h](capi-native-drm-err-h.md) | Declares the DRM error codes.|
| [native_mediakeysession.h](capi-native-mediakeysession-h.md) | Declares the MediaKeySession APIs.<br>The APIs can be used to generate media key requests, process responses to media key requests, listen for events, obtain content protection levels, check media key status, and delete media keys.|
| [native_mediakeysystem.h](capi-native-mediakeysystem-h.md) | Declares the MediaKeySystem APIs.<br>The APIs can be used to check whether a specific DRM is supported, create a media key session, obtain and set configurations, obtain statistics information, obtain the content protection level, generate media key system requests, process responses to media key system requests, listen for events, and manage offline media keys.|
