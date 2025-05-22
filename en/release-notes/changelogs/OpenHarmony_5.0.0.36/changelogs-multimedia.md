# Media Subsystem Changelog

## cl.multimedia.1 AudioSpatializationManager APIs in @ohos.multimedia.audio for Querying, Setting, and Listening for Spatial Audio and Head Tracking Status Are Deprecated

**Access Level**

System API

**Reason for Change**

The service feature is changed. Previously, the APIs for querying, setting, and listening for the status of spatial audio and head tracking do not contain a device parameter, so that you cannot use the APIs for a specified device. The new APIs introduce a device parameter. To match new service features, you are not advised to use the old APIs.

**Change Impact**

This change is a non-compatible change.

When you use the old APIs, a message is displayed, indicating that they are deprecated. You are advised to use the substitute APIs.

**Change Since**

OpenHarmony SDK 5.0.0.36

**Deprecated APIs/Components**

|         Deprecated API         |           Substitute API           |
| :----------------------------: | :---------------------------: |
| audio.AudioSpatializationManager#setSpatializationEnabled(enable: boolean, callback: AsyncCallback\<void>): void | audio.AudioSpatializationManager#setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void> |
| audio.AudioSpatializationManager#setSpatializationEnabled(enable: boolean): Promise\<void> | audio.AudioSpatializationManager#setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void> |
| audio.AudioSpatializationManager#isSpatializationEnabled(): boolean | audio.AudioSpatializationManager#isSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean |
| audio.AudioSpatializationManager#on(type: 'spatializationEnabledChange', callback: Callback\<boolean>): void | audio.AudioSpatializationManager#on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback\<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#off(type: 'spatializationEnabledChange', callback?: Callback\<boolean>): void | audio.AudioSpatializationManager#off(type: 'spatializationEnabledChangeForAnyDevice', callback?: Callback\<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#setHeadTrackingEnabled(enable: boolean, callback: AsyncCallback\<void>): void | audio.AudioSpatializationManager#setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void> |
| audio.AudioSpatializationManager#setHeadTrackingEnabled(enable: boolean): Promise\<void> | audio.AudioSpatializationManager#setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void> |
| audio.AudioSpatializationManager#isHeadTrackingEnabled(): boolean | audio.AudioSpatializationManager#isHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean |
| audio.AudioSpatializationManager#on(type: 'headTrackingEnabledChange', callback: Callback\<boolean>): void | audio.AudioSpatializationManager#on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback\<AudioSpatialEnabledStateForDevice>): void |
| audio.AudioSpatializationManager#off(type: 'headTrackingEnabledChange', callback?: Callback\<boolean>): void | audio.AudioSpatializationManager#off(type: 'headTrackingEnabledChangeForAnyDevice', callback?: Callback\<AudioSpatialEnabledStateForDevice>): void |

**Adaptation Guide**

Replace the old APIs in the code with the new APIs.
