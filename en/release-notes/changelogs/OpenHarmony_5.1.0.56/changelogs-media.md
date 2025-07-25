# Media Subsystem Changelog

## cl.media.1 Behavior Changed for media.createSoundPool When Creating SoundPool

**Access Level**

Public API

**Reason for Change**

Previously, an application can create only one SoundPool instance within a process, adhering to a singleton pattern, resulting in a failure to meet various use cases. For example, applications using SoundPool often also use the **TimePicker** component, which internally uses SoundPool. The singleton pattern causes interference between SoundPool objects, negatively impacting user experience.

**Impact of the Change**

This change does not require application adaptation.

Before the change, the underlying implementation of SoundPool is a singleton pattern, allowing only one instance per application process.

After the change, the underlying implementation of SoundPool supports multiple instances, allowing up to 128 instances per application process.

**Start API Level**

API 10

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

No adaptation is required.

## cl.media.2 	Behavior Changed for getTrackDescription

**Access Level**

Public API

**Reason for Change**

When the **getTrackDescription** API is used to query track information in scenarios with multiple video, audio, or subtitle tracks, the API returns inaccurate information for non-active tracks, including incorrect video HDR types, audio/subtitle language fields, and non-intuitive default MIME types. The behavior of the API has been modified to return more accurate track information in these cases.

**Impact of the Change**

This change does not require application adaptation.

Before the change, when the API is called to query the track information, non-active tracks had fixed values: hdr_type=0, language=undefined, and MIME types of audio/xxx or video/xxx.

After the change, when the API is called to query the track information, non-active tracks now have hdr_type and language values consistent with the resource, and MIME types of audio/unknown or video/unknown.
|                       API                       |           Before Change           |           After Change        |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| getTrackDescription  |        Non-active tracks have<br>hdr_type=0, language=undefined, and MIME types of audio/xxx or video/xxx.       |    Non-active tracks have<br>have hdr_type and language consistent with the resource, and MIME types of audio/unknown or video/unknown.   |

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

APIs in [@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md):
- getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription\>\>): void
- getTrackDescription(): Promise\<Array\<MediaDescription\>\>

**Adaptation Guide**

No adaptation is required.

## cl.media.3 	Behavior Changed for setPlaybackStrategy

**Access Level**

Public API

**Reason for Change**

Previously, when the **setPlaybackStrategy** API is used, other parameters can take effect only when **mutedMediaType** is set to **MediaType.MEDIA_TYPE_AUD**. The API behavior has been modified to allow setting other properties without setting **mutedMediaType**. For details, see [PlaybackStrategy](../../../application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12).

**Impact of the Change**

This change does not require application adaptation.

Before the change, when this API is used to configure a playback strategy, only parameters set alongside **mutedMediaType** as **MediaType.MEDIA_TYPE_AUD** take effect.

After the change, any combination of parameters set using this API takes effect.
|                       API                       |           Before Change           |           After Change        |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| setPlaybackStrategy  |      Parameters take effect only when **mutedMediaType** is set to<br>**MediaType.MEDIA_TYPE_AUD**.         |    Any parameter combination takes effect.   |

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

APIs in [@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md):

setPlaybackStrategy(strategy: PlaybackStrategy): Promise\<void\>

**Adaptation Guide**

No adaptation is required.

## cl.media.4 	Behavior Changed for setMediaSource

**Access Level**

Public API

**Reason for Change**

Previously, setting **mutedMediaType** using **setMediaSource** does not take effect. This behavior has been modified to ensure that parameter settings are effective. For details, see [PlaybackStrategy](../../../application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12).

**Impact of the Change**

This change does not require application adaptation.

Before the change, when this API is used to set **mutedMediaType**, the setting does not take effect.

After the change, when this API is used to set **mutedMediaType**, the setting takes effect.
|                       API                       |           Before Change           |           After Change        |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| setMediaSource  |      Setting **mutedMediaType** does not take effect.         |    Setting **mutedMediaType** takes effect.   |

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.1.0.56

**Key API/Component Changes**

APIs in [@ohos.multimedia.media](../../../application-dev/reference/apis-media-kit/js-apis-media.md):

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void\>

**Adaptation Guide**

No adaptation is required.
