# OH_MediaKeySession_Callback

## Overview

The OH_MediaKeySession_Callback struct describes the callback used to listen for events such as media key expiry or change, with media key session instances returned. It applies to the scenario where multiple media key sessions need to be decrypted.

**Since**: 12

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_mediakeysession.h](capi-native-mediakeysession-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_MediaKeySession_EventCallback](capi-native-mediakeysession-h.md#oh_mediakeysession_eventcallback) eventCallback | Event callback, for example, a media key expiry event.|
| [OH_MediaKeySession_KeyChangeCallback](capi-native-mediakeysession-h.md#oh_mediakeysession_keychangecallback) keyChangeCallback | Callback of the media key change event.|
