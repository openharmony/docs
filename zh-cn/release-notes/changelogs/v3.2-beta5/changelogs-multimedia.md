## cl.multimedia.av_session.001 av_session所有接口更换为系统接口

所有av_session的接口变更为SystemApi。

**变更影响**

非系统应用无法调用系统接口，如调用方为非系统应用或未申请SystemApi相关权限，将无法调用接口。

**关键的接口/组件变更**

所有接口均变更为SystemApi，接口明细如下：

| 接口、枚举或变量名 | 类型 | 是否为SystemApi |
| -------- | -------- | ------- |
| SessionToken | interface | 是 |
| AVMetadata  | interface | 是 |
| AVPlaybackState  | interface | 是 |
| PlaybackPosition  | interface | 是 |
| OutputDeviceInfo  | interface | 是 |
| AVSessionDescriptor  | interface | 是 |
| AVSessionController  | interface | 是 |
| AVControlCommand  | interface | 是 |
| createAVSession | function | 是 |
| getAllSessionDescriptors | function | 是 |
| createController | function | 是 |
| castAudio | function | 是 |
| on  | function | 是 |
| off | function | 是 |
| sendSystemAVKeyEvent | function | 是 |
| sendSystemControlCommand | function | 是 |
| sessionId | variable | 是 |
| setAVMetadata | function | 是 |
| setAVPlaybackState | function | 是 |
| setLaunchAbility | function | 是 |
| getController | function | 是 |
| getOutputDevice | function | 是 |
| activate | function | 是 |
| deactivate | function | 是 |
| destroy | function | 是 |
| getAVPlaybackState | function | 是 |
| getAVMetadata | function | 是 |
| getOutputDevice | function | 是 |
| sendAVKeyEvent | function | 是 |
| getLaunchAbility | function | 是 |
| getRealPlaybackPositionSync | function | 是 |
| isActive | function | 是 |
| getValidCommands | function | 是 |
| sendControlCommand | function | 是 |
| AVSessionType  | type | 是 |
| AVControlCommandType  | type | 是 |
| LoopMode  | enum | 是 |
| PlaybackState  | enum | 是 |
| AVSessionErrorCode  | enum | 是 |
