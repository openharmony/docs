# CodecJpegDecInfo


## 概述

定义jpeg图像解码信息。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [imageWidth](#imagewidth) | 图像宽度  | 
| unsigned int [imageHeight](#imageheight) | 图像高度  | 
| unsigned int [dataPrecision](#dataprecision) | 像素位宽  | 
| unsigned int [numComponents](#numcomponents) | jpeg图像中颜色分量的数量  | 
| unsigned int [restartInterval](#restartinterval) | 在一次扫描中作为独立序列处理的MCU的个数  | 
| boolean [arithCode](#arithcode) | Huffman编码为false，arithmetic编码为true  | 
| boolean [progressiveMode](#progressivemode) | 是否SOF指定渐进模式  | 
| struct [CodecJpegCompInfo](_codec_jpeg_comp_info_v20.md)[] [compInfo](#compinfo) | Jpeg压缩信息  | 
| struct [CodecJpegHuffTable](_codec_jpeg_huff_table_v20.md)[] [dcHuffTbl](#dchufftbl) | Dc huffman表信息  | 
| struct [CodecJpegHuffTable](_codec_jpeg_huff_table_v20.md)[] [acHuffTbl](#achufftbl) | Ac huffman表信息  | 
| struct [CodecJpegQuantTable](_codec_jpeg_quant_table_v20.md)[] [quantTbl](#quanttbl) | Quant表信息  | 
| struct [CodecImageRegion](_codec_image_region_v20.md)[region](#region) | 图像区域信息  | 
| unsigned int [sampleSize](#samplesize) | 图像样本大小  | 
| unsigned int [compressPos](#compresspos) | Jpeg压缩数据的偏移量  | 


## 类成员变量说明


### acHuffTbl

```
struct CodecJpegHuffTable [] CodecJpegDecInfo::acHuffTbl
```
**描述**

Ac huffman表信息


### arithCode

```
boolean CodecJpegDecInfo::arithCode
```
**描述**

Huffman编码为false，arithmetic编码为true


### compInfo

```
struct CodecJpegCompInfo [] CodecJpegDecInfo::compInfo
```
**描述**

Jpeg压缩信息


### compressPos

```
unsigned int CodecJpegDecInfo::compressPos
```
**描述**

Jpeg压缩数据的偏移量。


### dataPrecision

```
unsigned int CodecJpegDecInfo::dataPrecision
```
**描述**

像素位宽


### dcHuffTbl

```
struct CodecJpegHuffTable [] CodecJpegDecInfo::dcHuffTbl
```
**描述**

Dc huffman表信息


### imageHeight

```
unsigned int CodecJpegDecInfo::imageHeight
```
**描述**

图像高度


### imageWidth

```
unsigned int CodecJpegDecInfo::imageWidth
```
**描述**

图像宽度


### numComponents

```
unsigned int CodecJpegDecInfo::numComponents
```
**描述**

jpeg图像中颜色分量的数量。


### progressiveMode

```
boolean CodecJpegDecInfo::progressiveMode
```
**描述**

是否SOF指定渐进模式。


### quantTbl

```
struct CodecJpegQuantTable [] CodecJpegDecInfo::quantTbl
```
**描述**

Quant表信息


### region

```
struct CodecImageRegion CodecJpegDecInfo::region
```
**描述**

图像区域信息。


### restartInterval

```
unsigned int CodecJpegDecInfo::restartInterval
```
**描述**

在一次扫描中作为独立序列处理的MCU的个数


### sampleSize

```
unsigned int CodecJpegDecInfo::sampleSize
```
**描述**

图像样本大小
