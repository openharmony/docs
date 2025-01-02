# StreamInfo


## 概述

流信息，用于创建流时传入相关的配置参数。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流的ID，用于在设备内唯一标识一条流。  | 
| int [width_](#width_) | 图像宽度。  | 
| int [height_](#height_) | 图像高度。  | 
| int [format_](#format_) | 图像格式。  | 
| int [dataspace_](#dataspace_) | 图像颜色空间。  | 
| enum [StreamIntent](_camera_v10.md#streamintent)[intent_](#intent_) | 流类型。  | 
| boolean [tunneledMode_](#tunneledmode_) | 隧道模式，值为true时开启，false关闭。 开启隧道模式后，HAL不直接和上层交互，通过图形提供的生产者句柄来传递帧数据， 对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，此时需要关闭隧道模式。  | 
| BufferProducerSequenceable [bufferQueue_](#bufferqueue_) | 图形提供的生产者句柄。  | 
| int [minFrameDuration_](#minframeduration_) | 最小帧间隔。  | 
| enum [EncodeType](_camera_v10.md#encodetype)[encodeType_](#encodetype_) | 编码类型。  | 


## 类成员变量说明


### bufferQueue_

```
BufferProducerSequenceable StreamInfo::bufferQueue_
```
**描述**

图形提供的生产者句柄。


### dataspace_

```
int StreamInfo::dataspace_
```
**描述**

图像颜色空间。


### encodeType_

```
enum EncodeType StreamInfo::encodeType_
```
**描述**

编码类型。


### format_

```
int StreamInfo::format_
```
**描述**

图像格式。


### height_

```
int StreamInfo::height_
```
**描述**

图像高度。


### intent_

```
enum StreamIntent StreamInfo::intent_
```
**描述**

流类型。


### minFrameDuration_

```
int StreamInfo::minFrameDuration_
```
**描述**

最小帧间隔。


### streamId_

```
int StreamInfo::streamId_
```
**描述**

流的ID，用于在设备内唯一标识一条流。


### tunneledMode_

```
boolean StreamInfo::tunneledMode_
```
**描述**

隧道模式，值为true时开启，false关闭。 开启隧道模式后，HAL不直接和上层交互，通过图形提供的生产者句柄来传递帧数据， 对于一些IOT设备，可能不需要或者不支持预览流的图像数据缓存流转，此时需要关闭隧道模式。


### width_

```
int StreamInfo::width_
```
**描述**

图像宽度。
