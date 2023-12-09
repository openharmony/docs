# 媒体子系统音频接口变更说明

## c1.multimedia.1 ohos.multimedia.audio AudioManager接口setAudioParameter/getAudioParameter废弃

**访问级别**

公开接口

**废弃原因**

不再开放三方应用与音频芯片通过定制参数直接修改配置的通道，收归系统内部管控，通用功能由专有接口替代

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**废弃的接口**

接口属于AudioManager

setAudioParameter(key: string, value: string, callback: AsyncCallback<void>): void;

setAudioParameter(key: string, value: string): Promise<void>;

getAudioParameter(key: string, callback: AsyncCallback<string>): void;

getAudioParameter(key: string): Promise<string>;

**适配指导**

对于系统应用，根据废弃接口提示，使用替代接口：

setExtraParameters(mainKey: string, kvpairs: Record<string, string>): Promise<void>;

getExtraParameters(mainKey: string, subKeys?: Array<string>): Promise<Record<string, string>>;

mainKey与原接口参数key保持一致，kvpairs是原有value字符串内多个key-value配对的拆分写法。

对于三方应用，本接口提供的功能本身不对三方开放，请按需使用系统在AudioManager模块中提供的公开音频管理接口。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。


## c1.multimedia.2 ohos.multimedia.audio AudioRenderer接口setRenderRate/getRenderRate废弃

**访问级别**

公开接口

**废弃原因**

被功能更全面的新接口SetSpeed/GetSpeed替代

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**废弃的接口**

接口属于AudioRenderer

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback<void>): void;

setRenderRate(rate: AudioRendererRate): Promise<void>;

getRenderRate(callback: AsyncCallback<AudioRendererRate>): void;

getRenderRate(): Promise<AudioRendererRate>;

**适配指导**

根据废弃接口提示，使用AudioRenderer内的新接口即可，新接口支持通过浮点数调节播放速度，而非固定倍数。

setSpeed(speed: number): void;

getSpeed(): number;

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划

## c1.multimedia.3 ohos.multimedia.audio AudioVolumeGroupManager接口setMicrophoneMute废弃

**访问级别**

公开接口

**废弃原因**

虽然本接口是公开接口，但使用本接口需要获取权限ohos.permission.MANAGE_AUDIO_CONFIG。
本权限未开放给三方应用申请，因此三方应用实际无法使用本接口提供的能力。根据SDK规范，进行废弃，调整为系统接口，不对外可见。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**废弃的接口**

接口属于AudioVolumeGroupManager

setMicrophoneMute(mute: boolean, callback: AsyncCallback<void>): void;

setMicrophoneMute(mute: boolean): Promise<void>;

**适配指导**

系统应用，根据废弃接口提示，使用替代接口，功能完全一致：

setMicMute(mute: boolean): Promise<void>;

三方应用，由于原本就无法获取ohos.permission.MANAGE_AUDIO_CONFIG权限授权，原接口处于无效状态，因此对三方应用无实际影响。

废弃接口会在至少5个SDK版本内保持兼容，请应用按需规划适配计划。

## c1.multimedia.4 ohos.multimedia.audio CaptureFilterOptions属性usages行为变更

**访问级别**

公开接口

**变更原因**

本属性用于在音频内录功能中，对录制的音频usage进行筛选，当筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标时，
应用需要具备ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限。
但这个权限并不对三方应用开放授权，按照SDK规范，需要将权限剥离出公开接口。

**变更影响**

非兼容性变更，需要开发者进行适配。

**变更发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**变更的接口/组件**

变更前：
/**
 * Filter by stream usages. If you want to capture voice streams, additional permission is needed.
 * @permission ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 10
 */
接口允许调用者筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，但需要获取ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限。

变更后：
/**
 * Filter by stream usages. But not allow to capture voice streams.
 * @syscap SystemCapability.Multimedia.Audio.PlaybackCapture
 * @since 11
 */
接口不再允许调用者筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，权限声明删除。

**适配指导**

三方应用，由于本身无法获取权限授权，此变更无任何影响，无需适配

系统应用，即使拥有ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO权限，也不再能够筛选STREAM_USAGE_VOICE_COMMUNICATION作为录制目标，需将此类型从筛选中删除。
