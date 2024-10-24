# ImageBufferInfo


## 概述

定义 ImageBufferInfo，它由[IImageProcessCallback::OnProcessDone](interface_i_image_process_callback_v12.md#onprocessdone) 使用。

**起始版本：** 4.1

**相关模块：**[Camera](_camera_v12.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [isMetaDataValid](#ismetadatavalid) | metadata是否有效。  | 
| MapDataSequenceable [metadata](#metadata) | metadata的数据。  | 
| BufferHandleSequenceable [imageHandle](#imagehandle) | ImageHandle的数据。  | 
| boolean [isGainMapValid](#isgainmapvalid) | gainMapHandle是否有效。  | 
| BufferHandleSequenceable [gainMapHandle](#gainmaphandle) | gainMapHandle的数据。  | 
| boolean [isDepthMapValid](#isdepthmapvalid) | depthMapHandle是否有效。  | 
| BufferHandleSequenceable [depthMapHandle](#depthmaphandle) | depthMapHandle的数据。  | 


## 类成员变量说明


### depthMapHandle

```
BufferHandleSequenceable ImageBufferInfo::depthMapHandle
```
**描述**

depthMapHandle的数据。


### gainMapHandle

```
BufferHandleSequenceable ImageBufferInfo::gainMapHandle
```
**描述**

gainMapHandle的数据。


### imageHandle

```
BufferHandleSequenceable ImageBufferInfo::imageHandle
```
**描述**

ImageHandle的数据。


### isDepthMapValid

```
boolean ImageBufferInfo::isDepthMapValid
```
**描述**

depthMapHandle是否有效。


### isGainMapValid

```
boolean ImageBufferInfo::isGainMapValid
```
**描述**

gainMapHandle是否有效。


### isMetaDataValid

```
boolean ImageBufferInfo::isMetaDataValid
```
**描述**

metadata是否有效。


### metadata

```
MapDataSequenceable ImageBufferInfo::metadata
```
**描述**

metadata的数据。
