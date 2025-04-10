# OH_Pixelmap_HdrStaticMetadata


## 概述

HDR_STATIC_METADATA关键字对应的静态元数据值。

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)

**所在头文件：**[pixelmap_native.h](pixelmap__native_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| float [displayPrimariesX](#displayprimariesx)[3] | 归一化后显示设备三基色的X坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。  | 
| float [displayPrimariesY](#displayprimariesy)[3] | 归一化后显示设备三基色的Y坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。  | 
| float [whitePointX](#whitepointx) | 归一化后白点值的X坐标，以0.00002为单位，范围[0.0, 1.0]。  | 
| float [whitePointY](#whitepointy) | 归一化后白点值的Y坐标，以0.00002为单位，范围[0.0, 1.0]。  | 
| float [maxLuminance](#maxluminance) | 图像主监视器最大亮度。以1为单位，最大值为65535。  | 
| float [minLuminance](#minluminance) | 图像主监视器最小亮度。以0.0001为单位，最大值6.55535。  | 
| float [maxContentLightLevel](#maxcontentlightlevel) | 显示内容的最大亮度。以1为单位，最大值为65535。  | 
| float [maxFrameAverageLightLevel](#maxframeaveragelightlevel) | 显示内容的最大平均亮度，以1为单位，最大值为65535。  | 


## 结构体成员变量说明


### displayPrimariesX

```
float OH_Pixelmap_HdrStaticMetadata::displayPrimariesX[3]
```
**描述**
归一化后显示设备三基色的X坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。


### displayPrimariesY

```
float OH_Pixelmap_HdrStaticMetadata::displayPrimariesY[3]
```
**描述**
归一化后显示设备三基色的Y坐标，数组的长度为3，以0.00002为单位，范围[0.0, 1.0]。


### maxContentLightLevel

```
float OH_Pixelmap_HdrStaticMetadata::maxContentLightLevel
```
**描述**
显示内容的最大亮度。以1为单位，最大值为65535。


### maxFrameAverageLightLevel

```
float OH_Pixelmap_HdrStaticMetadata::maxFrameAverageLightLevel
```
**描述**
显示内容的最大平均亮度，以1为单位，最大值为65535。


### maxLuminance

```
float OH_Pixelmap_HdrStaticMetadata::maxLuminance
```
**描述**
图像主监视器最大亮度。以1为单位，最大值为65535。


### minLuminance

```
float OH_Pixelmap_HdrStaticMetadata::minLuminance
```
**描述**
图像主监视器最小亮度。以0.0001为单位，最大值6.55535。


### whitePointX

```
float OH_Pixelmap_HdrStaticMetadata::whitePointX
```
**描述**
归一化后白点值的X坐标，以0.00002为单位，范围[0.0, 1.0]。


### whitePointY

```
float OH_Pixelmap_HdrStaticMetadata::whitePointY
```
**描述**
归一化后白点值的Y坐标，以0.00002为单位，范围[0.0, 1.0]。
