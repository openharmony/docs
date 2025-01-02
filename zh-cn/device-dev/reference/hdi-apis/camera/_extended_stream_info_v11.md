# ExtendedStreamInfo


## 概述

扩展流信息。

**起始版本：** 4.0

**相关模块：**[Camera](_camera_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [ExtendedStreamInfoType](_camera_v11.md#extendedstreaminfotype)[type](#type) | 扩展流信息类型。  | 
| int [width](#width) | 图像宽度。  | 
| int [height](#height) | 图像高度。  | 
| int [format](#format) | 图像格式。  | 
| int [dataspace](#dataspace) | 图像颜色空间。  | 
| BufferProducerSequenceable [bufferQueue](#bufferqueue) | 图形提供的生产者句柄，用于快速缩略图。  | 


## 类成员变量说明


### bufferQueue

```
BufferProducerSequenceable ExtendedStreamInfo::bufferQueue
```
**描述**

图形提供的生产者句柄，用于快速缩略图。


### dataspace

```
int ExtendedStreamInfo::dataspace
```
**描述**

图像颜色空间。


### format

```
int ExtendedStreamInfo::format
```
**描述**

图像格式。


### height

```
int ExtendedStreamInfo::height
```
**描述**

图像高度。


### type

```
enum ExtendedStreamInfoType ExtendedStreamInfo::type
```
**描述**

扩展流信息类型。


### width

```
int ExtendedStreamInfo::width
```
**描述**

图像宽度。
