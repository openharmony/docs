# CodecJpegCompInfo


## 概述

定义jpeg图像的颜色分量信息。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [componentId](#componentid) | 颜色分量ID | 
| unsigned int [componentIndex](#componentindex) | 颜色分量索引 | 
| unsigned int [hSampFactor](#hsampfactor) | 水平采样因子 | 
| unsigned int [vSampFactor](#vsampfactor) | 垂直采样因子 | 
| unsigned int [quantTableNo](#quanttableno) | Quant表值 | 
| unsigned int [dcTableNo](#dctableno) | Dc表索引 | 
| unsigned int [acTableNo](#actableno) | Ac表索引 | 
| boolean [infoFlag](#infoflag) | 信息标签 | 


## 类成员变量说明


### acTableNo

```
unsigned int CodecJpegCompInfo::acTableNo
```

**描述**


Ac表索引


### componentId

```
unsigned int CodecJpegCompInfo::componentId
```

**描述**


颜色分量ID


### componentIndex

```
unsigned int CodecJpegCompInfo::componentIndex
```

**描述**


颜色分量索引


### dcTableNo

```
unsigned int CodecJpegCompInfo::dcTableNo
```

**描述**


Dc表索引


### hSampFactor

```
unsigned int CodecJpegCompInfo::hSampFactor
```

**描述**


水平采样因子


### infoFlag

```
boolean CodecJpegCompInfo::infoFlag
```

信息标签


### quantTableNo

```
unsigned int CodecJpegCompInfo::quantTableNo
```

**描述**


Quant表值


### vSampFactor

```
unsigned int CodecJpegCompInfo::vSampFactor
```

**描述**


垂直采样因子
