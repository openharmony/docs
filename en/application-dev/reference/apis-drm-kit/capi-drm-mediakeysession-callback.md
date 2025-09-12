# MediaKeySession_Callback

## Overview

The struct describes the callback used to listen for events such as media key expiry or change, without returning media key session instances. It applies to the scenario where a single media key session needs to be decrypted.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_mediakeysession.h](capi-native-mediakeysession-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [MediaKeySession_EventCallback](capi-native-mediakeysession-h.md#mediakeysession_eventcallback) eventCallback | Event callback, for example, a media key expiry event.|
| [MediaKeySession_KeyChangeCallback](capi-native-mediakeysession-h.md#mediakeysession_keychangecallback) keyChangeCallback | Callback of the media key change event.|
