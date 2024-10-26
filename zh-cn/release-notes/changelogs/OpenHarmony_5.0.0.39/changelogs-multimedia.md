# 媒体子系统Changelog

## cl.multimedia.1 OH_AVCodecBufferAttr 接口行为变更

**访问级别**

公开接口

**变更原因**

针对视频轨获取的 OH_AVCodecBufferAttr 中 `pts` 属性，会在文件实际封装信息的基础上减去轨道起始时间，使其从0开始，
导致音视频轨道 `pts` 处理不一致，调用方依赖 `pts` 实现音画同步时，部分视频效果异常。

**变更影响**

该变更为非兼容性变更，用户获取的视频轨 `pts` 属性值变更，不再统一从0开始，统一提供文件实际封装的原始 `pts` 信息。

**起始 API Level**

API10

**变更发生版本**

从OpenHarmony SDK 5.0.0.39版本开始。

**变更的接口/组件**

| 名称                      | 描述                        |
| ------------------------- | --------------------------- |
| OH_AVCodecBufferAttr | 定义OH_AVCodec的缓冲区描述信息 |

**适配指导**

变更后 `pts` 获取方式不变，内部不再进行额外处理，为文件实际封装的时间戳信息，调用方可使用变更后 `pts`，结合业务逻辑进行使用和处理，
获取方式如下所示：
```c++
OH_AVBuffer *buffer = OH_AVBuffer_Create(w * h * 3 >> 1);
if (buffer == nullptr) {
    // 处理异常
}
int32_t ret = OH_AVDemuxer_ReadSampleBuffer(demuxer, trackIndex, buffer);
if (ret != AV_ERR_OK) {
    // 处理异常
}

OH_AVCodecBufferAttr info;
ret = OH_AVBuffer_GetBufferAttr(buffer, &info);
if (ret != AV_ERR_OK) {
    // 处理异常
}
int64_t newPts = info.pts;
```

并且从API12开始，支持获取轨道起始时间信息 `OH_MD_KEY_TRACK_START_TIME`，用户也可通过变更后 `pts`，结合轨道起始时间，转换为变更前 `pts`，代码如下：
```c++
OH_AVFormat *trackFormat = OH_AVSource_GetTrackFormat(source, trackIndex);
if (trackFormat == nullptr) {
    // 处理异常
}
int64_t startTime = 0;
if (!OH_AVFormat_GetLongValue(trackFormat, OH_MD_KEY_TRACK_START_TIME, &startTime)) {
    // 处理异常
}
int64_t oldPts = newPts - startTime;
```

## cl.multimedia.2 EffectSuggestionType行为变更

**访问级别**

系统接口

**变更原因**

效果推荐功能相关的枚举类，只有系统接口来获取/更新这些属性，无需开放。

**变更影响**

该变更为不兼容性变更。

变更前：该枚举为公开接口。

变更后：该枚举为系统接口。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.39 版本开始。

**变更的接口/组件**

EffectSuggestionType/camera组件

**适配指导**

无需适配，相关接口没有开放，修改只是为了与相关接口的访问级别保持一致。

## cl.multimedia.3 EffectSuggestionStatus行为变更

**访问级别**

系统接口

**变更原因**

效果推荐功能相关的类，只有系统接口来获取/更新这些属性，无需开放。

**变更影响**

该变更为不兼容性变更。

变更前：该类为公开接口。

变更后：该类为系统接口。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.39 版本开始。

**变更的接口/组件**

EffectSuggestionStatus/camera组件

**适配指导**

无需适配，相关接口没有开放，修改只是为了与相关接口的访问级别保持一致。
