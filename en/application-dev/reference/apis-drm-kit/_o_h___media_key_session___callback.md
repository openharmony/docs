# OH_MediaKeySession_Callback


## Overview

The OH_MediaKeySession_Callback struct describes the callback used to listen for events such as media key expiry or change, with media key session instances returned. It applies to the scenario where multiple media key sessions need to be decrypted.

**Since**: 12

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_MediaKeySession_EventCallback](_drm.md#oh_mediakeysession_eventcallback)[eventCallback](_drm.md#eventcallback-22) | Event callback, for example, a media key expiry event.| 
| [OH_MediaKeySession_KeyChangeCallback](_drm.md#oh_mediakeysession_keychangecallback)[keyChangeCallback](_drm.md#keychangecallback-22) | Callback of the media key change event.| 
