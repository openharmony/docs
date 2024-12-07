# CodecImageCapability


## 概述

定义图像编解码器功能。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 图像编解码器的名称。 | 
| enum [CodecImageRole](_codec_v10.md#codecimagerole)[role](#role) | 图像编解码器的格式。 | 
| enum [CodecImageType](_codec_v10.md#codecimagetype)[type](#type) | 图像编解码器的类型。 | 
| unsigned int [widthAlignment](#widthalignment) | 宽度的对齐值。 | 
| unsigned int [heightAlignment](#heightalignment) | 高度的对齐值。 | 
| unsigned int [maxSample](#maxsample) | 最大采样值 | 
| unsigned int [maxWidth](#maxwidth) | 最大宽度。 | 
| unsigned int [maxHeight](#maxheight) | 最大高度 | 
| unsigned int [minWidth](#minwidth) | 最小宽度。 | 
| unsigned int [minHeight](#minheight) | 最小高度。 | 
| unsigned int [maxInst](#maxinst) | 最大实例数。 | 
| unsigned int[] [supportPixFmts](#supportpixfmts) | 支持PixFormat。 | 
| boolean [isSoftwareCodec](#issoftwarecodec) | 是否软件编解码 | 


## 类成员变量说明


### heightAlignment

```
unsigned int CodecImageCapability::heightAlignment
```

**描述**


高度的对齐值。


### isSoftwareCodec

```
boolean CodecImageCapability::isSoftwareCodec
```

**描述**


是否软件编解码


### maxHeight

```
unsigned int CodecImageCapability::maxHeight
```

**描述**


最大高度


### maxInst

```
unsigned int CodecImageCapability::maxInst
```

**描述**


最大实例数。


### maxSample

```
unsigned int CodecImageCapability::maxSample
```

**描述**


最大采样值


### maxWidth

```
unsigned int CodecImageCapability::maxWidth
```

**描述**


最大宽度。


### minHeight

```
unsigned int CodecImageCapability::minHeight
```

**描述**


最小高度。


### minWidth

```
unsigned int CodecImageCapability::minWidth
```

**描述**


最小宽度。


### name

```
String CodecImageCapability::name
```

**描述**


图像编解码器的名称。


### role

```
enum CodecImageRole CodecImageCapability::role
```

**描述**


图像编解码器的格式。


### supportPixFmts

```
unsigned int [] CodecImageCapability::supportPixFmts
```

**描述**


支持PixFormat。


### type

```
enum CodecImageType CodecImageCapability::type
```

**描述**


图像编解码器的类型。


### widthAlignment

```
unsigned int CodecImageCapability::widthAlignment
```

**描述**


宽度的对齐值。
