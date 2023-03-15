# VideoPortCap


## **概述**

定义视频编解码能力。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [minSize](#minsize) | 支持的最小分辨率 | 
| [maxSize](#maxsize) | 支持的最大分辨率 | 
| [whAlignment](#whalignment) | 宽高对齐值 | 
| [blockCount](#blockcount) | 支持的块数量范围 | 
| [blocksPerSecond](#blockspersecond) | 每秒可处理的块数量范围 | 
| [blockSize](#blocksize) | 支持的块大小 | 
| [supportPixFmts](#supportpixfmts)&nbsp;[[PIX_FORMAT_NUM](codec.md#gadb8c6478388b68c09835ebe093a8920a)] | 支持的像素格式 | 


## **类成员变量说明**


### blockCount

  
```
RangeValue VideoPortCap::blockCount
```

**描述：**

支持的块数量范围。


### blockSize

  
```
Rect VideoPortCap::blockSize
```

**描述：**

支持的块大小。


### blocksPerSecond

  
```
RangeValue VideoPortCap::blocksPerSecond
```

**描述：**

每秒可处理的块数量范围。


### maxSize

  
```
Rect VideoPortCap::maxSize
```

**描述：**

支持的最大分辨率。


### minSize

  
```
Rect VideoPortCap::minSize
```

**描述：**

支持的最小分辨率。


### supportPixFmts

  
```
int32_t VideoPortCap::supportPixFmts[PIX_FORMAT_NUM]
```

**描述：**

支持的像素格式，详见**OMX_COLOR_FORMATTYPE**。


### whAlignment

  
```
Alignment VideoPortCap::whAlignment
```

**描述：**

宽高对齐值。
