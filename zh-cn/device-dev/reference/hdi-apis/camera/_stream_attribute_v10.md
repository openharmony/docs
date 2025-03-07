# StreamAttribute


## 概述

流的属性。

**起始版本：** 3.2

**相关模块：**[Camera](_camera_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId_](#streamid_) | 流的ID，用于在设备内唯一标识一条流。  | 
| int [width_](#width_) | 图像宽度。  | 
| int [height_](#height_) | 图像高度。  | 
| int [overrideFormat_](#overrideformat_) | 重写的图像格式。  | 
| int [overrideDataspace_](#overridedataspace_) | 重写的图像颜色空间。  | 
| int [producerUsage_](#producerusage_) | 重写后的生产者的使用方式。  | 
| int [producerBufferCount_](#producerbuffercount_) | 重写后的生产者缓存数量。  | 
| int [maxBatchCaptureCount_](#maxbatchcapturecount_) | 连拍支持的最大捕获帧数量。  | 
| int [maxCaptureCount_](#maxcapturecount_) | 最大的并发捕获请求个数，默认为1。  | 


## 类成员变量说明


### height_

```
int StreamAttribute::height_
```
**描述**

图像高度。


### maxBatchCaptureCount_

```
int StreamAttribute::maxBatchCaptureCount_
```
**描述**

连拍支持的最大捕获帧数量。


### maxCaptureCount_

```
int StreamAttribute::maxCaptureCount_
```
**描述**

最大的并发捕获请求个数，默认为1。


### overrideDataspace_

```
int StreamAttribute::overrideDataspace_
```
**描述**

重写的图像颜色空间。


### overrideFormat_

```
int StreamAttribute::overrideFormat_
```
**描述**

重写的图像格式。


### producerBufferCount_

```
int StreamAttribute::producerBufferCount_
```
**描述**

重写后的生产者缓存数量。


### producerUsage_

```
int StreamAttribute::producerUsage_
```
**描述**

重写后的生产者的使用方式。


### streamId_

```
int StreamAttribute::streamId_
```
**描述**

流的ID，用于在设备内唯一标识一条流。


### width_

```
int StreamAttribute::width_
```
**描述**

图像宽度。
