# OH_Pixelmap_HdrGainmapMetadata


## 概述

HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)

**所在头文件：**[pixelmap_native.h](pixelmap__native_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint16_t [writerVersion](#writerversion) | 元数据编写器使用的版本。  | 
| uint16_t [miniVersion](#miniversion) | 元数据解析需要理解的最小版本。  | 
| uint8_t [gainmapChannelNum](#gainmapchannelnum) | Gainmap的颜色通道数，值为3时RGB通道的元数据值不同，值为1时各通道元数据值相同。  | 
| bool [useBaseColorFlag](#usebasecolorflag) | 是否使用基础图的色彩空间，参考ISO 21496-1。  | 
| float [baseHeadroom](#baseheadroom) | 基础图提亮比，参考ISO 21496-1。  | 
| float [alternateHeadroom](#alternateheadroom) | 提取的可选择图像提亮比，参考ISO 21496-1。  | 
| float [gainmapMax](#gainmapmax)[3] | 增强图像的最大值，参考ISO 21496-1。  | 
| float [gainmapMin](#gainmapmin)[3] | 增强图像的最小值，参考ISO 21496-1。  | 
| float [gamma](#gamma)[3] | gamma值，参考ISO 21496-1。  | 
| float [baselineOffset](#baselineoffset)[3] | 基础图的偏移，参考ISO 21496-1。  | 
| float [alternateOffset](#alternateoffset)[3] | 提取的可选择图像偏移量，参考ISO 21496-1。  | 


## 结构体成员变量说明


### alternateHeadroom

```
float OH_Pixelmap_HdrGainmapMetadata::alternateHeadroom
```
**描述**
提取的可选择图像提亮比，参考ISO 21496-1。


### alternateOffset

```
float OH_Pixelmap_HdrGainmapMetadata::alternateOffset[3]
```
**描述**
提取的可选择图像偏移量，参考ISO 21496-1。


### baseHeadroom

```
float OH_Pixelmap_HdrGainmapMetadata::baseHeadroom
```
**描述**
基础图提亮比，参考ISO 21496-1。


### baselineOffset

```
float OH_Pixelmap_HdrGainmapMetadata::baselineOffset[3]
```
**描述**
基础图的偏移，参考ISO 21496-1。


### gainmapChannelNum

```
uint8_t OH_Pixelmap_HdrGainmapMetadata::gainmapChannelNum
```
**描述**
Gainmap的颜色通道数，值为3时RGB通道的元数据值不同，值为1时各通道元数据值相同。


### gainmapMax

```
float OH_Pixelmap_HdrGainmapMetadata::gainmapMax[3]
```
**描述**
增强图像的最大值，参考ISO 21496-1。


### gainmapMin

```
float OH_Pixelmap_HdrGainmapMetadata::gainmapMin[3]
```
**描述**
增强图像的最小值，参考ISO 21496-1。


### gamma

```
float OH_Pixelmap_HdrGainmapMetadata::gamma[3]
```
**描述**
gamma值，参考ISO 21496-1。


### miniVersion

```
uint16_t OH_Pixelmap_HdrGainmapMetadata::miniVersion
```
**描述**
元数据解析需要理解的最小版本。


### useBaseColorFlag

```
bool OH_Pixelmap_HdrGainmapMetadata::useBaseColorFlag
```
**描述**
是否使用基础图的色彩空间，参考ISO 21496-1。


### writerVersion

```
uint16_t OH_Pixelmap_HdrGainmapMetadata::writerVersion
```
**描述**
元数据编写器使用的版本。
