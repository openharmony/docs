# StreamDescription


## 概述

流描述信息，使用于[IVideoProcessSession::Prepare](interface_i_video_process_session_v13.md#prepare)。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [streamId](#streamid) | 流id。  | 
| enum [MediaStreamType](_camera_v13.md#mediastreamtype)[type](#type) | 媒体流类型。  | 
| int [pixelFormat](#pixelformat) | pixel格式。  | 
| int [width](#width) | 图片宽。  | 
| int [height](#height) | 图片高。  | 
| int [dataspace](#dataspace) | 图片色域。  | 


## 结构体成员变量说明


### dataspace

```
int StreamDescription::dataspace
```
**描述**

图片色域。

**起始版本：** 5.0


### height

```
int StreamDescription::height
```
**描述**

图片高。

**起始版本：** 5.0


### pixelFormat

```
int StreamDescription::pixelFormat
```
**描述**

pixel格式。

**起始版本：** 5.0


### streamId

```
int StreamDescription::streamId
```
**描述**

流id。

**起始版本：** 5.0


### type

```
enum MediaStreamType StreamDescription::type
```
**描述**

媒体流类型。

**起始版本：** 5.0


### width

```
int StreamDescription::width
```
**描述**

图片宽。

**起始版本：** 5.0
