# Interfaces (Others)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AudioStreamInfo<sup>8+</sup>

Describes audio stream information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name        | Type                                              | Read-Only| Optional| Description              |
| ------------ | ------------------------------------------------- | ---- |---| ------------------ |
| samplingRate | [AudioSamplingRate](arkts-apis-audio-e.md#audiosamplingrate8)          | No| No| Audio sampling rate.|
| channels     | [AudioChannel](arkts-apis-audio-e.md#audiochannel8)                    | No| No| Number of audio channels.|
| sampleFormat | [AudioSampleFormat](arkts-apis-audio-e.md#audiosampleformat8)          | No| No| Audio sample format.    |
| encodingType | [AudioEncodingType](arkts-apis-audio-e.md#audioencodingtype8)          | No| No| Audio encoding type.    |
| channelLayout<sup>11+</sup> | [AudioChannelLayout](arkts-apis-audio-e.md#audiochannellayout11)  | No| Yes| Audio channel layout. The default value is **0x0**.|

## AudioRendererInfo<sup>8+</sup>

Describes audio renderer information.

| Name         | Type                       | Read-Only| Optional| Description           |
| ------------- | --------------------------- | ---- |---| --------------- |
| content       | [ContentType](arkts-apis-audio-e.md#contenttypedeprecated) | No| Yes| Audio content type.<br>**System capability**: SystemCapability.Multimedia.Audio.Core<br>This parameter is mandatory in API versions 8 and 9 and optional since API version 10. The default value is **CONTENT_TYPE_UNKNOWN**.<br>This API is supported since API version 7 and deprecated since API version 10. You are advised to use [StreamUsage](arkts-apis-audio-e.md#streamusage) instead.|
| usage         | [StreamUsage](arkts-apis-audio-e.md#streamusage) | No| No| Audio stream usage.<br>**System capability**: SystemCapability.Multimedia.Audio.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| rendererFlags | number                      | No| No| Audio renderer flags.<br>The value **0** means an audio renderer.<br>**System capability**: SystemCapability.Multimedia.Audio.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| volumeMode<sup>19+</sup> | [AudioVolumeMode](arkts-apis-audio-e.md#audiovolumemode19) | No| Yes| Audio volume mode. The default value is **SYSTEM_GLOBAL**.<br>**System capability**: SystemCapability.Multimedia.Audio.Volume|

## AudioRendererOptions<sup>8+</sup>

Describes audio renderer configurations.

| Name        | Type                                    | Read-Only| Optional| Description            |
| ------------ | ---------------------------------------- | ---- |---| ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)     | No| No| Audio stream information.<br>**System capability**: SystemCapability.Multimedia.Audio.Renderer|
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | No| No| Audio renderer information.<br>**System capability**: SystemCapability.Multimedia.Audio.Renderer|
| privacyType<sup>10+</sup> | [AudioPrivacyType](arkts-apis-audio-e.md#audioprivacytype10) | No| Yes| Whether the audio stream can be recorded by other applications. The default value is **0**.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture|

## InterruptEvent<sup>9+</sup>

Describes the interruption event received by the application when the audio is interrupted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name     | Type                                      | Read-Only| Optional| Description                                |
| --------- | ------------------------------------------ | ---- |---| ------------------------------------ |
| eventType | [InterruptType](arkts-apis-audio-e.md#interrupttype)            | No| No| Whether the audio interruption has started or ended.        |
| forceType | [InterruptForceType](arkts-apis-audio-e.md#interruptforcetype9) | No| No| Whether the audio interruption is forcibly taken by the system or taken by an application.|
| hintType  | [InterruptHint](arkts-apis-audio-e.md#interrupthint)            | No| No| Hint provided along the interruption to provide information related to the interruption event.|

## DeviceBlockStatusInfo<sup>13+</sup>

Describes the audio device blocked status and device information.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                             | Read-Only| Optional| Description              |
| :---------------- | :------------------------------------------------ | :--- |---| :----------------- |
| blockStatus       | [DeviceBlockStatus](arkts-apis-audio-e.md#deviceblockstatus13)           | No| No| Blocked status of the audio device.|
| devices | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | No| No| Device information.        |

## AudioSessionStrategy<sup>12+</sup>

Describes an audio session strategy.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                                             | Read-Only| Optional| Description            |
| :------------ |:------------------------------------------------| :--- |---| :--------------- |
| concurrencyMode        | [AudioConcurrencyMode](arkts-apis-audio-e.md#audioconcurrencymode12) | No| No| Audio concurrency mode.      |

## AudioSessionDeactivatedEvent<sup>12+</sup>

Describes the event indicating that an audio session is deactivated.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                                                               | Read-Only| Optional| Description            |
| :------------ |:------------------------------------------------------------------| :--- |---| :--------------- |
| reason        | [AudioSessionDeactivatedReason](arkts-apis-audio-e.md#audiosessiondeactivatedreason12) | No| No| Reason for deactivating an audio session.      |

## AudioSessionStateChangedEvent<sup>20+</sup>

Describes the event indicating that the audio session state changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                                             | Read-Only| Optional| Description            |
| :------------ |:------------------------------------------------| :--- |---| :--------------- |
| stateChangeHint        | [AudioSessionStateChangeHint](arkts-apis-audio-e.md#audiosessionstatechangehint20) | No| No| Hint for the audio session state change.|

## AudioRendererChangeInfo<sup>9+</sup>

Describes the audio renderer change event.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Type                                      | Read-Only| Optional| Description                         |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| streamId           | number                                    | Yes  | No  | Unique ID of an audio stream.               |
| rendererInfo       | [AudioRendererInfo](#audiorendererinfo8)  | Yes  | No  | Audio renderer information.              |
| deviceDescriptors  | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)      | Yes  | No  | Audio device description.|

## AudioCapturerChangeInfo<sup>9+</sup>

Describes the audio capturer change event.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name              | Type                                      | Read-Only| Optional| Description                         |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| streamId           | number                                    | Yes  | No  | Unique ID of an audio stream.               |
| capturerInfo       | [AudioCapturerInfo](#audiocapturerinfo8)  | Yes  | No  | Audio capturer information.              |
| deviceDescriptors  | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)      | Yes  | No  | Audio device information.|
| muted<sup>11+</sup>  | boolean    | Yes  | Yes| Whether the audio capturer is muted. **true** if muted, **false** otherwise.|

## AudioDeviceDescriptor

Describes an audio device.

| Name                         | Type                      | Read-Only| Optional| Description      |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| deviceRole                    | [DeviceRole](arkts-apis-audio-e.md#devicerole)  | Yes  | No  | Device role.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| deviceType                    | [DeviceType](arkts-apis-audio-e.md#devicetype)  | Yes  | No  | Device type.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| id<sup>9+</sup>               | number                     | Yes  | No  | Unique device ID.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| name<sup>9+</sup>             | string                     | Yes  | No  | Device name.<br>For a Bluetooth device, you must request the ohos.permission.USE_BLUETOOTH permission.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| address<sup>9+</sup>          | string                     | Yes  | No  | Device address.<br>For a Bluetooth device, you must request the ohos.permission.USE_BLUETOOTH permission.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| sampleRates<sup>9+</sup>      | Array&lt;number&gt;        | Yes  | No  | Supported sampling rates.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| channelCounts<sup>9+</sup>    | Array&lt;number&gt;        | Yes  | No  | Number of channels supported.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| channelMasks<sup>9+</sup>     | Array&lt;number&gt;        | Yes  | No  | Supported channel masks.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| displayName<sup>10+</sup>     | string                     | Yes  | No  | Display name of the device.<br> **System capability**: SystemCapability.Multimedia.Audio.Device<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| encodingTypes<sup>11+</sup>    | Array&lt;[AudioEncodingType](arkts-apis-audio-e.md#audioencodingtype8)&gt;                     | Yes  | Yes| Supported encoding types.<br> **System capability**: SystemCapability.Multimedia.Audio.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| spatializationSupported<sup>18+</sup>     | boolean                     | Yes  | Yes| Whether the device supports spatial audio rendering. **true** if supported, **false** otherwise.<br> **System capability**: SystemCapability.Multimedia.Audio.Spatialization|

## VolumeEvent<sup>9+</sup>

Describes the event received by the application when the volume is changed.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name      | Type                               | Read-Only| Optional| Description                                       |
| ---------- | ----------------------------------- | ---- |---|-------------------------------------------|
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | No| No| Audio stream type.                                   |
| volume     | number                              | No| No|Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**. |
| updateUi   | boolean                             | No| No|  Whether to show the volume change in UI. **true** to show, **false** otherwise.            |
| volumeMode<sup>19+</sup> | [AudioVolumeMode](arkts-apis-audio-e.md#audiovolumemode19) | No| Yes| Audio volume mode. The default value is **SYSTEM_GLOBAL**.|


## MicStateChangeEvent<sup>9+</sup>

Describes the event received by the application when the microphone mute status is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Type                               | Read-Only| Optional| Description                                                    |
| ---------- | ----------------------------------- | ---- |---|-------------------------------------------------------- |
| mute | boolean | No| No| Mute status of the microphone **true** if muted, **false** otherwise.         |


## StreamVolumeEvent<sup>20+</sup>

Describes the event received by the application when the audio stream volume is changed.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name      | Type                               | Read-Only| Optional| Description                                                    |
| ---------- | ----------------------------------- | ---- |---|-------------------------------------------------------- |
| streamUsage | [StreamUsage](arkts-apis-audio-e.md#streamusage) | No| No| Audio stream for which the volume changes.         |
| volume | number | No| No| Volume.         |
| updateUi | boolean | No| No| Whether to show the volume change in UI. **true** to show, **false** otherwise.         |

## DeviceChangeAction

Describes the device connection status and device information.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                             | Read-Only| Optional| Description              |
| :---------------- | :------------------------------------------------ | :--- |---| :----------------- |
| type              | [DeviceChangeType](arkts-apis-audio-e.md#devicechangetype)             | No| No| Device connection status.|
| deviceDescriptors | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | No| No| Device information.        |

## AudioStreamDeviceChangeInfo<sup>11+</sup>

Describes the event received by the application when the audio stream device is changed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                                               | Read-Only| Optional| Description              |
| :---------------- |:------------------------------------------------------------------| :--- |---| :----------------- |
| devices              | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)                 | No| No| Device information.|
| changeReason | [AudioStreamDeviceChangeReason](arkts-apis-audio-e.md#audiostreamdevicechangereason11) | No| No| Reason for the change.|

## CurrentOutputDeviceChangedEvent<sup>20+</sup>

Describes the event indicating that the output device changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name             | Type                                                               | Read-Only| Optional| Description              |
| :---------------- |:------------------------------------------------------------------| :--- |---| :----------------- |
| devices              | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)                 | No| No| Device information.|
| changeReason | [AudioStreamDeviceChangeReason](arkts-apis-audio-e.md#audiostreamdevicechangereason11) | No| No| Reason for the device change.|
| recommendedAction | [OutputDeviceChangeRecommendedAction](arkts-apis-audio-e.md#outputdevicechangerecommendedaction20) | No| No| Recommended action after the device change.|

## AudioTimestampInfo<sup>19+</sup>

Describes the information about the audio stream timestamp and the current data frame position.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name| Type| Read-Only| Optional| Description                               |
| ---------| ------ | ---- | ---- |-----------------------------------|
| framePos | number | Yes  | No  | Position of the current data frame for playback or recording.                  |
| timestamp | number | Yes  | No  | Timestamp corresponding to the current data frame position during playback or recording.|

## AudioCapturerInfo<sup>8+</sup>

Describes audio capturer information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                     | Read-Only| Optional| Description            |
| :------------ | :------------------------ | :--- |---| :--------------- |
| source        | [SourceType](arkts-apis-audio-e.md#sourcetype8) | No| No| Audio source type.      |
| capturerFlags | number                    | No| No| Audio capturer flags.<br>The value **0** means an audio capturer.|

## AudioCapturerOptions<sup>8+</sup>

Describes audio capturer configurations.

| Name                               | Type                                                     | Read-Only| Optional| Description                                                        |
| ----------------------------------- | --------------------------------------------------------- | ---- |---| ------------------------------------------------------------ |
| streamInfo                          | [AudioStreamInfo](#audiostreaminfo8)                      | No| No| Audio stream information.<br>**System capability**: SystemCapability.Multimedia.Audio.Capturer  |
| capturerInfo                        | [AudioCapturerInfo](#audiocapturerinfo8)                   | No| No| Audio capturer information.<br>**System capability**: SystemCapability.Multimedia.Audio.Capturer       |
| playbackCaptureConfig<sup>(deprecated)</sup> | [AudioPlaybackCaptureConfig](#audioplaybackcaptureconfigdeprecated) | No| Yes| Configuration of internal audio recording.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture<br> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [AVScreenCapture](../apis-media-kit/capi-avscreencapture.md) instead. |

## AudioInterrupt<sup>(deprecated)</sup>

Describes input parameters of audio interruption events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. No substitute is provided.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           | Type                       | Read-Only| Optional| Description                                                        |
| --------------- | --------------------------- | ----|---| ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage) | No| No| Audio stream usage.                                            |
| contentType     | [ContentType](arkts-apis-audio-e.md#contenttypedeprecated) | No| No| Audio content type.                                          |
| pauseWhenDucked | boolean                     | No| No| Whether audio playback can be paused during an audio interruption. **true** if audio playback can be paused, **false** otherwise.|

## CaptureFilterOptions<sup>(deprecated)</sup>

Defines the options for filtering the played audio streams to be recorded.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [AVScreenCapture](../apis-media-kit/capi-avscreencapture.md) instead.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name  | Type                              | Read-Only| Optional| Description                                                        |
| ------ | ---------------------------------- | ---- |---| ------------------------------------------------------------ |
| usages | Array\<[StreamUsage](arkts-apis-audio-e.md#streamusage)> | No| No| **StreamUsage** of the audio stream to be recorded. You can specify zero or more stream usages. If the array is empty, the audio stream for which **StreamUsage** is **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, **STREAM_USAGE_GAME**, or **STREAM_USAGE_AUDIOBOOK** is recorded by default.<br>In API version 10, **CaptureFilterOptions** supports **StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION**, and therefore the ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO permission is required. Only system applications can request this permission.<br>Since API version 11, **CaptureFilterOptions** does not support **StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION**. Therefore, no permission is required for calling this API.|

## AudioPlaybackCaptureConfig<sup>(deprecated)</sup>

Defines the configuration of internal audio recording.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [AVScreenCapture](../apis-media-kit/capi-avscreencapture.md) instead.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name         | Type                                         | Read-Only| Optional| Description                            |
| ------------- | --------------------------------------------- | ---- |---| -------------------------------- |
| filterOptions | [CaptureFilterOptions](#capturefilteroptionsdeprecated) | No| No| Options for filtering the played audio streams to be recorded.|

## InterruptAction<sup>(deprecated)</sup>

Describes the callback invoked for audio interruption or focus gain events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [InterruptEvent](#interruptevent9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name      | Type                                       | Read-Only| Optional| Description                                                        |
| ---------- | ------------------------------------------- | ---- |---| ------------------------------------------------------------ |
| actionType | [InterruptActionType](arkts-apis-audio-e.md#interruptactiontypedeprecated) | No| No| Returned event type. The value **TYPE_ACTIVATED** means the focus gain event, and **TYPE_INTERRUPT** means the audio interruption event.|
| type       | [InterruptType](arkts-apis-audio-e.md#interrupttype)             | No| Yes| Type of the audio interruption event.                                              |
| hint       | [InterruptHint](arkts-apis-audio-e.md#interrupthint)             | No| Yes| Hint provided along with the audio interruption event.                                              |
| activated  | boolean                                     | No| Yes| Whether the focus is gained or released. **true** if the focus is gained or released, **false** if the focus fails to be gained or released.|
