# CodecVideoPortCap


## 概述

定义视频编解码能力。

**起始版本：** 3.2

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| struct [Rect](_rect_v10.md)[minSize](#minsize) | 支持的最小分辨率。 | 
| struct [Rect](_rect_v10.md)[maxSize](#maxsize) | 支持的最大分辨率。 | 
| struct [Alignment](_alignment_v10.md)[whAlignment](#whalignment) | 宽高对齐值。 | 
| struct [RangeValue](_range_value_v10.md)[blockCount](#blockcount) | 支持的块数量范围。 | 
| struct [RangeValue](_range_value_v10.md)[blocksPerSecond](#blockspersecond) | 每秒可处理的块数量范围。 | 
| struct [Rect](_rect_v10.md)[blockSize](#blocksize) | 支持的块大小。 | 
| int[] [supportPixFmts](#supportpixfmts) | 支持的像素格式，详见[PixeFormat](../display/_display_v10.md#pixelformat)。 | 
| enum [BitRateMode](_codec_v10.md#bitratemode)[] bitRatemode | 传输速率模式，有恒定的，有变化的等几种模式。详见[BitRateMode](_codec_v10.md#bitratemode)。 | 
| struct [RangeValue](_range_value_v10.md)[frameRate](#framerate) | 帧率的范围。 | 
| int[] [measuredFrameRate](#measuredframerate) | 实测的帧率。 | 


## 类成员变量说明


### bitRatemode

```
enum BitRateMode[] CodecVideoPortCap::bitRatemode 
```

**描述**


传输速率模式，有恒定的，有变化的等几种模式。详见[BitRateMode](_codec_v10.md#bitratemode)。


### blockCount

```
struct RangeValue CodecVideoPortCap::blockCount
```

**描述**


支持的块数量范围。


### blockSize

```
struct Rect CodecVideoPortCap::blockSize
```

**描述**


支持的块大小。


### blocksPerSecond

```
struct RangeValue CodecVideoPortCap::blocksPerSecond
```

**描述**


每秒可处理的块数量范围。


### frameRate

```
struct RangeValue CodecVideoPortCap::frameRate
```

**描述**


帧率的范围。


### maxSize

```
struct Rect CodecVideoPortCap::maxSize
```

**描述**


支持的最大分辨率。


### measuredFrameRate

```
 int [] CodecVideoPortCap::measuredFrameRate
```

**描述**


实测的帧率。


### minSize

```
struct Rect CodecVideoPortCap::minSize
```

**描述**


支持的最小分辨率。


### supportPixFmts

```
int [] CodecVideoPortCap::supportPixFmts
```

**描述**


支持的像素格式，详见**Display中display_type.h定义的[PixeFormat](../display/_display_v10.md#pixelformat)**。


### whAlignment

```
struct Alignment CodecVideoPortCap::whAlignment
```

**描述**


宽高对齐值。
