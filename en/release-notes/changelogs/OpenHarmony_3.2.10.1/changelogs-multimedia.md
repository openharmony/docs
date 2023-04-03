## cl.multimedia.av_session.001 Change of All av_session APIs to System APIs

All av_session APIs are changed to system APIs.

**Change Impacts**

Non-system applications and applications without system API permission cannot call system APIs.

**Key API/Component Changes**

All APIs are changed to system APIs. The table below describes the APIs.

| API, Enumeration, or Variable| Type| Is System API|
| -------- | -------- | ------- |
| SessionToken | interface | Yes|
| AVMetadata  | interface | Yes|
| AVPlaybackState  | interface | Yes|
| PlaybackPosition  | interface | Yes|
| OutputDeviceInfo  | interface | Yes|
| AVSessionDescriptor  | interface | Yes|
| AVSessionController  | interface | Yes|
| AVControlCommand  | interface | Yes|
| createAVSession | function | Yes|
| getAllSessionDescriptors | function | Yes|
| createController | function | Yes|
| castAudio | function | Yes|
| on  | function | Yes|
| off | function | Yes|
| sendSystemAVKeyEvent | function | Yes|
| sendSystemControlCommand | function | Yes|
| sessionId | variable | Yes|
| setAVMetadata | function | Yes|
| setAVPlaybackState | function | Yes|
| setLaunchAbility | function | Yes|
| getController | function | Yes|
| getOutputDevice | function | Yes|
| activate | function | Yes|
| deactivate | function | Yes|
| destroy | function | Yes|
| getAVPlaybackState | function | Yes|
| getAVMetadata | function | Yes|
| getOutputDevice | function | Yes|
| sendAVKeyEvent | function | Yes|
| getLaunchAbility | function | Yes|
| getRealPlaybackPositionSync | function | Yes|
| isActive | function | Yes|
| getValidCommands | function | Yes|
| sendControlCommand | function | Yes|
| AVSessionType  | type | Yes|
| AVControlCommandType  | type | Yes|
| LoopMode  | enum | Yes|
| PlaybackState  | enum | Yes|
| AVSessionErrorCode  | enum | Yes|
