# Image_Region


## 概述

待解码的图像源区域结构体。

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [x](#x) | 区域横坐标，不能大于原图的宽度。  | 
| uint32_t [y](#y) | 区域纵坐标，不能大于原图的高度。  | 
| uint32_t [width](#width) | 输出图片的宽，单位：像素。  | 
| uint32_t [height](#height) | 输出图片的高，单位：像素。  | 


## 结构体成员变量说明


### height

```
uint32_t Image_Region::height
```
**描述**
输出图片的高，单位：像素。


### width

```
uint32_t Image_Region::width
```
**描述**
输出图片的宽，单位：像素。


### x

```
uint32_t Image_Region::x
```
**描述**
区域横坐标，不能大于原图的宽度。


### y

```
uint32_t Image_Region::y
```
**描述**
区域纵坐标，不能大于原图的高度。
