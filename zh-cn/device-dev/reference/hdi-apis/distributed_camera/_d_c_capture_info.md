# DCCaptureInfo


## 概述

分布式相机内部捕获请求的信息。

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int[] [streamIds_](#streamids_) | 捕获的流ID集合。  | 
| int [width_](#width_) | 捕获的图像宽度。  | 
| int [height_](#height_) | 捕获的图像高度。  | 
| int [stride_](#stride_) | 捕获的图像步幅。  | 
| int [format_](#format_) | 捕获的图像格式。  | 
| int [dataspace_](#dataspace_) | 捕获的图像颜色空间。  | 
| boolean [isCapture_](#iscapture_) | 是否触发接收捕获。  | 
| enum [DCEncodeType](_distributed.md#dcencodetype)[encodeType_](#encodetype_) | 捕获的编码类型，具体类型查看[DCEncodeType](_distributed.md#dcencodetype)。  | 
| enum [DCStreamType](_distributed.md#dcstreamtype)[type_](#type_) | 捕获的流类型，具体类型查看[DCStreamType](_distributed.md#dcstreamtype)。  | 
| struct [DCameraSettings](_d_camera_settings.md)[] [captureSettings_](#capturesettings_) | 捕获的配置信息，具体定义查看[DCameraSettings](_d_camera_settings.md)。  | 


## 类成员变量说明


### captureSettings_

```
struct DCameraSettings [] DCCaptureInfo::captureSettings_
```
**描述**

捕获的配置信息，具体定义查看[DCameraSettings](_d_camera_settings.md)。


### dataspace_

```
int DCCaptureInfo::dataspace_
```
**描述**

捕获的图像颜色空间。


### encodeType_

```
enum DCEncodeType DCCaptureInfo::encodeType_
```
**描述**

捕获的编码类型，具体类型查看[DCEncodeType](_distributed.md#dcencodetype)。


### format_

```
int DCCaptureInfo::format_
```
**描述**

捕获的图像格式。


### height_

```
int DCCaptureInfo::height_
```
**描述**

捕获的图像高度。


### isCapture_

```
boolean DCCaptureInfo::isCapture_
```
**描述**

是否触发接收捕获。


### streamIds_

```
int [] DCCaptureInfo::streamIds_
```
**描述**

捕获的流ID集合。


### stride_

```
int DCCaptureInfo::stride_
```
**描述**

捕获的图像步幅。


### type_

```
enum DCStreamType DCCaptureInfo::type_
```
**描述**

捕获的流类型，具体类型查看[DCStreamType](_distributed.md#dcstreamtype)。


### width_

```
int DCCaptureInfo::width_
```
**描述**

捕获的图像宽度。
