# 媒体子系统Changelog

## cl.multimedia.1 @ohos.multimedia.audio AudioSpatializationManager内部空间音频和头动跟踪开关查询、设置和监听接口废弃

**访问级别**

系统接口

**废弃原因**

业务特性变更，使用带有指定设备的空间音频和头动跟踪开关状态的查询、设置和监听接口替代原来的不带指定设备参数的查询、设置和监听接口。并且为了与新的业务特性相匹配，也不建议后续开发者再使用老接口。

**废弃影响**

该变更为不兼容变更。
使用AudioSpatializationManager内部不带指定设备描述参数的空间音频和头动跟踪开关状态的查询、设置和监听接口会有废弃提示。建议迁移使用替代接口。

**废弃发生版本**

从OpenHarmony SDK 5.0.0.36开始。

**废弃的接口/组件**

|            接口声明          |           替代接口            |
| :----------------------------: | :---------------------------: |
| audio.AudioSpatializationManager#setSpatializationEnabled(enable: boolean, callback: AsyncCallback<void>): void | audio.AudioSpatializationManager#setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise<void> |
| audio.AudioSpatializationManager#setSpatializationEnabled(enable: boolean): Promise<void> | audio.AudioSpatializationManager#setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise<void> |
| audio.AudioSpatializationManager#isSpatializationEnabled(): boolean | audio.AudioSpatializationManager#isSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean |
| audio.AudioSpatializationManager#on(type: 'spatializationEnabledChange', callback: Callback<boolean>): void | audio.AudioSpatializationManager#on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#off(type: 'spatializationEnabledChange', callback?: Callback<boolean>): void | audio.AudioSpatializationManager#off(type: 'spatializationEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#setHeadTrackingEnabled(enable: boolean, callback: AsyncCallback<void>): void | audio.AudioSpatializationManager#setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise<void> |
| audio.AudioSpatializationManager#setHeadTrackingEnabled(enable: boolean): Promise<void> | audio.AudioSpatializationManager#setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise<void> |
| audio.AudioSpatializationManager#isHeadTrackingEnabled(): boolean | audio.AudioSpatializationManager#isHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean |
| audio.AudioSpatializationManager#on(type: 'headTrackingEnabledChange', callback: Callback<boolean>): void | audio.AudioSpatializationManager#on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#off(type: 'headTrackingEnabledChange', callback?: Callback<boolean>): void | audio.AudioSpatializationManager#off(type: 'headTrackingEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice>): void |

**适配指导**

开发者需将使用@ohos.multimedia.audio模块内AudioSpatializationManager内部不带指定设备参数的查询、设置和监听接口的地方，适配修改为带指定设备参数的查询、设置和监听对应接口。