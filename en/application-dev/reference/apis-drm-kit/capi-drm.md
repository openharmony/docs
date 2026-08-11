# Drm

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9ed00b617c87c511eeed0752811e64aa5c2daa83 translatedAt=2026-07-31T02:12:58.050Z pushedAt=2026-07-31T03:50:30.580Z -->

## Overview

The Digital Rights Management (DRM) module provides APIs for digital rights protection.

You can refer to the corresponding development guide and samples based on your development requirements.

- [DRM Development (C/C++)](../../media/drm/drm-c-dev-guide.md)

- [DRM Playback with AVCodec (C/C++)](../../media/drm/drm-avcodec-integration.md)

**Since**: 11

## Files

| Name| Description|
| -- | -- |
| [native_drm_common.h](capi-native-drm-common-h.md) | Declares the DRM data types.|
| [native_drm_err.h](capi-native-drm-err-h.md) | Declares the DRM error codes.|
| [native_mediakeysession.h](capi-native-mediakeysession-h.md) | Defines the DRM MediaKeySession API. Provides the following functions:<br> Generates media key requests, processes media key responses, listens for events, obtains content protection levels, checks media key status, deletes media keys, and more. |
| [native_mediakeysystem.h](capi-native-mediakeysystem-h.md) | Defines the DRM MediaKeySystem API. The following functions are provided:<br> Querying whether a specific DRM is supported, creating media key sessions, obtaining and setting configurations, obtaining statistics, obtaining content protection levels, generating provisioning requests, processing provisioning responses, listening for events, managing offline media keys, and more. |