# VideoPortCap


## 概述

定义视频编解码能力。

**相关模块:**

[Codec](_codec.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [minSize](#minsize) | [Rect](_rect.md)<br/>支持的最小分辨率。 | 
| [maxSize](#maxsize) | [Rect](_rect.md)<br/>支持的最大分辨率。 | 
| [whAlignment](#whalignment) | [Alignment](_alignment.md)<br/>宽高对齐值。 | 
| [blockCount](#blockcount) | [RangeValue](_range_value.md)<br/>支持的块数量范围。 | 
| [blocksPerSecond](#blockspersecond) | [RangeValue](_range_value.md)<br/>每秒可处理的块数量范围。 | 
| [blockSize](#blocksize) | [Rect](_rect.md)<br/>支持的块大小。 | 
| [supportPixFmts](#supportpixfmts)&nbsp;[[PIX_FORMAT_NUM](_codec.md#pix_format_num)] | int32_t<br/>支持的像素格式，详见OMX_COLOR_FORMATTYPE。 | 


## 类成员变量说明


### blockCount

  
```
RangeValue VideoPortCap::blockCount
```

**描述:**

支持的块数量范围。


### blockSize

  
```
Rect VideoPortCap::blockSize
```

**描述:**

支持的块大小。


### blocksPerSecond

  
```
RangeValue VideoPortCap::blocksPerSecond
```

**描述:**

每秒可处理的块数量范围。


### maxSize

  
```
Rect VideoPortCap::maxSize
```

**描述:**

支持的最大分辨率。


### minSize

  
```
Rect VideoPortCap::minSize
```

**描述:**

支持的最小分辨率。


### supportPixFmts

  
```
int32_t VideoPortCap::supportPixFmts[PIX_FORMAT_NUM]
```

**描述:**

支持的像素格式，详见OMX_COLOR_FORMATTYPE。


### whAlignment

  
```
Alignment VideoPortCap::whAlignment
```

**描述:**

宽高对齐值。
