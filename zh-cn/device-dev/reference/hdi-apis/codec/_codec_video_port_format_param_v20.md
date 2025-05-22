# CodecVideoPortFormatParam


## 概述

设置输入输出端口的编解码格式。

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [size](#size) | 结构体大小  | 
| union CodecVersionType [version](#version) | 组件版本  | 
| unsigned int [portIndex](#portindex) | 端口序列  | 
| unsigned int [codecColorIndex](#codeccolorindex) | 已废弃  | 
| unsigned int [codecColorFormat](#codeccolorformat) | 像素格式  | 
| unsigned int [codecCompressFormat](#codeccompressformat) | 压缩格式  | 
| unsigned int [framerate](#framerate) | Q16 format  | 


## 类成员变量说明


### codecColorFormat

```
unsigned int CodecVideoPortFormatParam::codecColorFormat
```
**描述**

像素格式


### codecColorIndex

```
unsigned int CodecVideoPortFormatParam::codecColorIndex
```
**描述**

已废弃


### codecCompressFormat

```
unsigned int CodecVideoPortFormatParam::codecCompressFormat
```
**描述**

压缩格式


### framerate

```
unsigned int CodecVideoPortFormatParam::framerate
```
**描述**

Q16 format


### portIndex

```
unsigned int CodecVideoPortFormatParam::portIndex
```
**描述**

端口序列


### size

```
unsigned int CodecVideoPortFormatParam::size
```
**描述**

结构体大小


### version

```
union CodecVersionType CodecVideoPortFormatParam::version
```
**描述**

组件版本
