# 媒体子系统Changelog

## cl.media.1 应用创建SoundPool时调用media.createSoundPool接口行为变更

**访问级别**

公开接口

**变更原因**

原来的应用创建SoundPool实例，一个应用进程只能够创建一个SoundPool实例，为单实例模式，无法满足应用的使用场景。例如很多应用在使用SoundPool的能力的同时，还需要使用TimePicker组件(该组件中封装了SoundPool的能力)，单实例模式会使得SoundPool对象之间互相干扰，影响应用的使用体验。

**变更影响**

此变更不涉及应用适配。

变更前：创建的SoundPool对象底层为单实例模式，一个应用进程只能够创建1个SoundPool实例。

变更后：创建的SoundPool对象底层为多实例模式，一个应用进程最多能够创建128个SoundPool实例。

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

无变更接口

**适配指导**

默认行为变更，无需适配。

## cl.media.2 	getTrackDescription行为变更

**访问级别**

公开接口

**变更原因**

在视频存在多个视频/音频/字幕轨的场景下，使用getTrackDescription查询轨道信息时，对于非当前播放的视频/音频/字幕轨道，接口返回了不准确的视频HDR类型、音频/字幕轨语种字段信息，以及不直观的默认mime信息。现对接口的行为修改，使其能够在这种情况下返回更加准确的轨道信息。

**变更影响**

此变更不涉及应用适配。

变更前：调用接口查询轨道信息时，其中未播放的轨道，其hdr_type值固定为0，language值为undefined，mime值为audio/xxx或video/xxx。

变更后：调用接口查询轨道信息时，其中未播放的轨道，其hdr_type值与资源一致，language值与资源一致，mime值为audio/unknown或video/unknown。
|                       接口声明                        |           变更前            |           变更后         |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| getTrackDescription  |        其中未播放的轨道<br/>hdr_type=0、language=undefined、mime=audio/xxx或video/xxx。        |    其中未播放的轨道<br/>hdr_type、language与资源信息一致、mime=audio/unknown或video/unknown。    |

**起始 API Level**

9

**变更发生的版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

[@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md)中的接口：
- getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription\>\>): void
- getTrackDescription(): Promise\<Array\<MediaDescription\>\>

**适配指导**

默认行为变更，无需适配。

## cl.media.3 	setPlaybackStrategy行为变更

**访问级别**

公开接口

**变更原因**

由于使用setPlaybackStrategy接口时，只有同时将mutedMediaType设置为MediaType.MEDIA_TYPE_AUD，一起设置的其余参数才能生效。因此将接口行为修改为不设置mutedMediaType也可以设置其他属性。参考[PlaybackStrategy](../../../application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12)说明。

**变更影响**

此变更不涉及应用适配。

变更前：使用该接口配置播放策略时，只有将mutedMediaType设置为MediaType.MEDIA_TYPE_AUD时，一起设置的其余参数才能生效。

变更后：使用该接口配置播放策略时，任意参数组合设置都能生效。
|                       接口声明                        |           变更前            |           变更后         |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| setPlaybackStrategy  |      接口入参PlaybackStrategy的mutedMediaType<br/>设置为MediaType.MEDIA_TYPE_AUD时，参数设置才能生效。          |    任意参数组合设置都能生效。    |

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

[@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md)中的接口：

setPlaybackStrategy(strategy: PlaybackStrategy): Promise\<void\>

**适配指导**

默认行为变更，无需适配。

## cl.media.4 	setMediaSource行为变更

**访问级别**

公开接口

**变更原因**

在使用setMediaSource设置mutedMediaType属性时，参数设置不生效。需要变更为参数设置可以正常生效。参考[PlaybackStrategy](../../../application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12)说明。

**变更影响**

此变更不涉及应用适配。

变更前：使用接口设置播放策略的mutedMediaType属性时，参数设置不生效。

变更后：使用接口设置播放策略的mutedMediaType属性时，参数设置生效。
|                       接口声明                        |           变更前            |           变更后         |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| setMediaSource  |      设置mutedMediaType属性不生效。          |    设置mutedMediaType属性生效。    |

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

[@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md)中的接口：

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void\>

**适配指导**

默认行为变更，无需适配。
