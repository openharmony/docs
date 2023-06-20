# Resize


## 概述

按给定的参数对输入的张量进行变形。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_RESIZE。

参数指导：该算子的参数组合可以实现常用的Resize函数。 例如，实现精确对齐图像的4个角的双线性插值则设置： method = RESIZE_METHOD_LINEAR coordinateTransformMode = COORDINATE_TRANSFORM_MODE_ALIGN_CORNERS

输入：

- x，一个4维tensor，tensor排布必须是[batchSize，height，width，channels](NHWC)。

输出：

- output，n维输出tensor，它的的shape和数据类型与x相同。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [method](#method) | enum&nbsp;[ResizeMethod](_n_n_rt.md#resizemethod)<br/>调整尺寸的方法，详情请参考：[ResizeMethod](_n_n_rt.md#resizemethod)。&nbsp; | 
| [newHeight](#newheight) | long<br/>resize之后4维tensor的height值。&nbsp; | 
| [newWidth](#newwidth) | long<br/>resize之后4维tensor的width值。&nbsp; | 
| [preserveAspectRatio](#preserveaspectratio) | boolean<br/>一个布尔值，指示resize操作是否保持x张量的height/width比例。&nbsp; | 
| [coordinateTransformMode](#coordinatetransformmode) | enum&nbsp;[CoordinateTransformMode](_n_n_rt.md#coordinatetransformmode)<br/>坐标变换方法，详情请参考：[CoordinateTransformMode](_n_n_rt.md#coordinatetransformmode)。&nbsp; | 
| [cubicCoeff](#cubiccoeff) | float<br/>立方系数，当method为RESIZE_METHOD_CUBIC时使用。&nbsp; | 
| [excludeOutside](#excludeoutside) | long<br/>当excludeOutside==1时，超出x的边界的采样权重被置为0，其余权重重新归一化处理。&nbsp; | 
| [extrapolationValue](#extrapolationvalue) | float<br/>外插值，当仅用于裁剪x的时候使用，超出边界的采样权重被置为extrapolationValue。&nbsp; | 
| [nearestMode](#nearestmode) | enum&nbsp;[NearestMode](_n_n_rt.md#nearestmode)<br/>最近邻近算法，当method==RESIZE_METHOD_NEAREST时使用，详情请参考：[NearestMode](_n_n_rt.md#nearestmode)。&nbsp; | 


## 类成员变量说明


### coordinateTransformMode

  
```
enum CoordinateTransformMode Resize::coordinateTransformMode
```
**描述:**
坐标变换方法，详情请参考：[CoordinateTransformMode](_n_n_rt.md#coordinatetransformmode)。


### cubicCoeff

  
```
float Resize::cubicCoeff
```
**描述:**
立方系数，当method为RESIZE_METHOD_CUBIC时使用。


### excludeOutside

  
```
long Resize::excludeOutside
```
**描述:**
当excludeOutside==1时，超出x的边界的采样权重被置为0，其余权重重新归一化处理。


### extrapolationValue

  
```
float Resize::extrapolationValue
```
**描述:**
外插值，当仅用于裁剪x的时候使用，超出边界的采样权重被置为extrapolationValue。


### method

  
```
enum ResizeMethod Resize::method
```
**描述:**
调整尺寸的方法，详情请参考：[ResizeMethod](_n_n_rt.md#resizemethod)。


### nearestMode

  
```
enum NearestMode Resize::nearestMode
```
**描述:**
最近邻近算法，当method==RESIZE_METHOD_NEAREST时使用，详情请参考：[NearestMode](_n_n_rt.md#nearestmode)。


### newHeight

  
```
long Resize::newHeight
```
**描述:**
resize之后4维tensor的height值。


### newWidth

  
```
long Resize::newWidth
```
**描述:**
resize之后4维tensor的width值。


### preserveAspectRatio

  
```
boolean Resize::preserveAspectRatio
```
**描述:**
一个布尔值，指示resize操作是否保持x张量的height/width比例。
