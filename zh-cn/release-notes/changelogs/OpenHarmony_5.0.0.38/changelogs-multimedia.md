# 媒体子系统Changelog

## cl.multimedia.1 AVMetadata.hdrType 只读属性补齐

**访问级别**

公开接口。

**变更原因**

补充标记hdrType字段为readonly属性，对齐JsDoc描述。

**变更影响**

该变更为不兼容变更。
若对AVMetadata.hdrType进行过赋值的代码，会在编译时报错。之前的版本虽然赋值成功，但无法生效。建议删除赋值的代码。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|            接口声明            |               变更前                 |            变更后             |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| hdrType | 可赋值，不生效 | readonly, 不可赋值 |

**适配指导**

开发者需将使用@ohos.multimedia.media.d.ts模块中对AVMetadata.hdrType赋值的代码行删除。

## c1.multimedia.1 OH_AVCodecBufferAttr 接口行为变更

**访问级别**

公开接口

**变更原因**

针对视频轨获取的 OH_AVCodecBufferAttr中 `pts` 属性，会在文件实际封装信息的基础上减去轨道起始时间，使其从0开始，
导致部分音视频轨道 `pts` 处理不一致，调用方依赖 `pts` 实现音画同步出错。

**变更影响**

该变更为非兼容性变更，用户获取的视频轨 `pts` 属性值变更，不再统一从0开始，统一提供文件实际封装的原始 `pts` 信息。

**起始 API Level**

API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.38版本开始。

**变更的接口/组件**

| 名称                      | 描述                        |
| ------------------------- | --------------------------- |
| OH_AVCodecBufferAttr | 定义OH_AVCodec的缓冲区描述信息 |

**适配指导**

开发者需要通过轨道信息获取轨道起始时间属性，根据应用实际场景的需求，对获取到的pts进行处理，pts - start_time 相当于变更前 pts。
具体获取轨道信息可参考 [获取轨道信息](../../../application-dev/media/avcodec/audio-video-demuxer.md#轨道级别属性支持范围)。