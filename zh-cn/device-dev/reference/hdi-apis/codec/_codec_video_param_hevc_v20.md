# CodecVideoParamHevc


## 概述

定义HEVC视频编码格式信息。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [size](#size) | 结构体大小 | 
| union CodecVersionType [version](#version) | 组件版本 | 
| unsigned int [portIndex](#portindex) | 端口序列 | 
| enum [CodecHevcProfile](_codec_v20.md#codechevcprofile)[profile](#profile) | Hevc profile。 详见 [CodecHevcProfile](_codec_v20.md#codechevcprofile). | 
| enum [CodecHevcLevel](_codec_v20.md#codechevclevel)[level](#level) | Hevc级别。 详见 [CodecHevcLevel](_codec_v20.md#codechevclevel). | 
| unsigned int [keyFrameInterval](#keyframeinterval) | 连续I帧（包括其中一个I帧）之间的距离。 | 


## 类成员变量说明


### keyFrameInterval

```
unsigned int CodecVideoParamHevc::keyFrameInterval
```

**描述**


连续I帧（包括其中一个I帧）之间的距离。

0表示间隔未指定，可由编解码器自由选择， 1表示一个仅存在I帧的流，其他值表示实际值。


### level

```
enum CodecHevcLevel CodecVideoParamHevc::level
```

**描述**


Hevc级别。 详见 [CodecHevcLevel](_codec_v20.md#codechevclevel).


### portIndex

```
unsigned int CodecVideoParamHevc::portIndex
```

**描述**


端口序列


### profile

```
enum CodecHevcProfile CodecVideoParamHevc::profile
```

**描述**


Hevc profile。 详见 [CodecHevcProfile](_codec_v20.md#codechevcprofile).


### size

```
unsigned int CodecVideoParamHevc::size
```

**描述**


结构体大小


### version

```
union CodecVersionType CodecVideoParamHevc::version
```

**描述**


组件版本
