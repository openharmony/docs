# ImageBufferInfoExt


## 概述

图片流信息，使用于[IImageProcessCallback::OnProcessDoneExt](interface_i_image_process_callback_v13.md#onprocessdoneext)。

**起始版本：** 5.0

**相关模块：**[Camera](_camera_v13.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| MapDataSequenceable [metadata](#metadata) | metadata信息。  | 
| BufferHandleSequenceable [imageHandle](#imagehandle) | 图片处理信息。  | 
| boolean [isGainMapValid](#isgainmapvalid) | gainMap是否上报。  | 
| BufferHandleSequenceable [gainMapHandle](#gainmaphandle) | gainMap信息。  | 
| boolean [isDepthMapValid](#isdepthmapvalid) | depthmap是否上报。  | 
| BufferHandleSequenceable [depthMapHandle](#depthmaphandle) | depthmap处理信息。  | 
| boolean [isUnrefocusImageValid](#isunrefocusimagevalid) | 人像模式是否上报unrefocusImage。  | 
| BufferHandleSequenceable [unrefocusImageHandle](#unrefocusimagehandle) | unrefocusImage处理信息。  | 
| boolean [isHighBitDepthLinearImageValid](#ishighbitdepthlinearimagevalid) | 是否上报高位深度线性图像。  | 
| BufferHandleSequenceable [highBitDepthLinearImageHandle](#highbitdepthlinearimagehandle) | 高位深度线性图像处理信息。  | 
| boolean [isExifValid](#isexifvalid) | 是否上报exif信息。  | 
| BufferHandleSequenceable [exifHandle](#exifhandle) | exif处理信息。  | 
| boolean [isMakerInfoValid](#ismakerinfovalid) | 维测信息是否上报。  | 
| BufferHandleSequenceable [makerInfoHandle](#makerinfohandle) | 维测处理信息。  | 


## 结构体成员变量说明


### depthMapHandle

```
BufferHandleSequenceable ImageBufferInfoExt::depthMapHandle
```
**描述**

depthmap处理信息。

**起始版本：** 5.0


### exifHandle

```
BufferHandleSequenceable ImageBufferInfoExt::exifHandle
```
**描述**

exif处理信息。

**起始版本：** 5.0


### gainMapHandle

```
BufferHandleSequenceable ImageBufferInfoExt::gainMapHandle
```
**描述**

gainMap信息。

**起始版本：** 5.0


### highBitDepthLinearImageHandle

```
BufferHandleSequenceable ImageBufferInfoExt::highBitDepthLinearImageHandle
```
**描述**

高位深度线性图像处理信息。

**起始版本：** 5.0


### imageHandle

```
BufferHandleSequenceable ImageBufferInfoExt::imageHandle
```
**描述**

图片处理信息。

**起始版本：** 5.0


### isDepthMapValid

```
boolean ImageBufferInfoExt::isDepthMapValid
```
**描述**

depthmap是否上报。

**起始版本：** 5.0


### isExifValid

```
boolean ImageBufferInfoExt::isExifValid
```
**描述**

是否上报exif信息。

**起始版本：** 5.0


### isGainMapValid

```
boolean ImageBufferInfoExt::isGainMapValid
```
**描述**

gainMap是否上报。

**起始版本：** 5.0


### isHighBitDepthLinearImageValid

```
boolean ImageBufferInfoExt::isHighBitDepthLinearImageValid
```
**描述**

是否上报高位深度线性图像。

**起始版本：** 5.0


### isMakerInfoValid

```
boolean ImageBufferInfoExt::isMakerInfoValid
```
**描述**

维测信息是否上报。

**起始版本：** 5.0


### isUnrefocusImageValid

```
boolean ImageBufferInfoExt::isUnrefocusImageValid
```
**描述**

人像模式是否上报unrefocusImage。

**起始版本：** 5.0


### makerInfoHandle

```
BufferHandleSequenceable ImageBufferInfoExt::makerInfoHandle
```
**描述**

维测处理信息。

**起始版本：** 5.0


### metadata

```
MapDataSequenceable ImageBufferInfoExt::metadata
```
**描述**

metadata信息。

**起始版本：** 5.0


### unrefocusImageHandle

```
BufferHandleSequenceable ImageBufferInfoExt::unrefocusImageHandle
```
**描述**

unrefocusImage处理信息。

**起始版本：** 5.0
