# CodecJpegHuffTable


## 概述

定义jpeg图像Huffman表信息。

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned char[] [bits](#bits) | 比特值, bits[0]未使用  | 
| unsigned char[] [huffVal](#huffval) | Huffman表值  | 
| boolean [tableFlag](#tableflag) | Huffman表有效时为true  | 


## 类成员变量说明


### bits

```
unsigned char [] CodecJpegHuffTable::bits
```
**描述**

比特值, bits[0]未使用


### huffVal

```
unsigned char [] CodecJpegHuffTable::huffVal
```
**描述**

Huffman表值


### tableFlag

```
boolean CodecJpegHuffTable::tableFlag
```
**描述**

Huffman表有效时为true
