# Media Subsystem Changelog

## cl.multimedia.1 OH_AVCodecBufferAttr Behavior Changed

**Access Level**

Public API

**Reason for Change**

For a video track, **pts** in the obtained **OH_AVCodecBufferAttr** struct is the timestamp encapsulated in the file minus the track start time so that it starts from 0. However, the **pts** processing is different for the audio and video tracks. When **pts** is used for audio and video synchronization, abnormal video effects occur.

**Change Impact**

This change is a non-compatible change. The **pts** value of the video track obtained is no longer starting from 0. Specifically, the **pts** information encapsulated in the file is used.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

| Name                     | Description                       |
| ------------------------- | --------------------------- |
| OH_AVCodecBufferAttr | Description information about the buffer of an **OH_AVCodec** instance.|

**Adaptation Guide**

The method of obtaining **pts** remains unchanged. However, no additional processing is performed internally. As such, **pts** is the timestamp encapsulated in the file. You can use and process **pts** based on your service logic. The sample code is as follows:

```c++
OH_AVBuffer *buffer = OH_AVBuffer_Create(w * h * 3 >> 1);
if (buffer == nullptr) {
    // Exception handling.
}
int32_t ret = OH_AVDemuxer_ReadSampleBuffer(demuxer, trackIndex, buffer);
if (ret != AV_ERR_OK) {
    // Exception handling.
}

OH_AVCodecBufferAttr info;
ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
if (ret != AV_ERR_OK) {
    // Exception handling.
}
int64_t newPts = info.pts;
```

You can also convert the obtained **pts** to **pts** before the change based on the track start time, **OH_MD_KEY_TRACK_START_TIME**, which can be obtained since API version 12. The code is as follows:
```c++
OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, trackIndex);
if (trackFormat == nullptr) {
    // Exception handling.
}
int64_t startTime = 0;
if (!OH_AVFormat_GetLongValue(trackFormat, OH_MD_KEY_TRACK_START_TIME, &startTime)) {
    // Exception handling.
}
int64_t oldPts = newPts - startTime;
```

## cl.multimedia.2 EffectSuggestionType Behavior Changed

**Access Level**

System API

**Reason for Change**

Only system APIs can obtain or update the enums related to effect recommendation.

**Change Impact**

This change is a non-compatible change.

Before change: The enum is a public interface.

After change: The enum is a system interface.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

EffectSuggestionType/camera component

**Adaptation Guide**

No adaptation is required. Related APIs are not opened. The change is only to keep the access level consistent with that of related APIs.

## cl.multimedia.3 EffectSuggestionStatus Behavior Changed

**Access Level**

System API

**Reason for Change**

Only system APIs can obtain or update the classes related to effect recommendation.

**Change Impact**

This change is a non-compatible change.

Before change: The class is a public interface.

After change: The class is a system interface.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

EffectSuggestionStatus/camera component

**Adaptation Guide**

No adaptation is required. Related APIs are not opened. The change is only to keep the access level consistent with that of related APIs.
