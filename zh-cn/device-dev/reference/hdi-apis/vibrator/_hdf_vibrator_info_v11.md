# HdfVibratorInfo


## 概述

定义马达参数。

参数包括设置马达振幅和频率以及振幅和频率的范围。

**起始版本：** 3.2

**相关模块：**[Vibrator](_vibrator_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [isSupportIntensity](#issupportintensity) | 设置马达振幅。1表示支持，0表示不支持。  | 
| int [isSupportFrequency](#issupportfrequency) | 设置马达频率。1表示支持，0表示不支持。  | 
| int [intensityMaxValue](#intensitymaxvalue) | 最大振幅。  | 
| int [intensityMinValue](#intensityminvalue) | 最小振幅。  | 
| int [frequencyMaxValue](#frequencymaxvalue) | 最大频率。  | 
| int [frequencyMinValue](#frequencyminvalue) | 最小频率。  | 


## 类成员变量说明


### frequencyMaxValue

```
int HdfVibratorInfo::frequencyMaxValue
```
**描述**

最大频率。


### frequencyMinValue

```
int HdfVibratorInfo::frequencyMinValue
```
**描述**

最小频率。


### intensityMaxValue

```
int HdfVibratorInfo::intensityMaxValue
```
**描述**

最大振幅。


### intensityMinValue

```
int HdfVibratorInfo::intensityMinValue
```
**描述**

最小振幅。


### isSupportFrequency

```
int HdfVibratorInfo::isSupportFrequency
```
**描述**

设置马达频率。1表示支持，0表示不支持。


### isSupportIntensity

```
int HdfVibratorInfo::isSupportIntensity
```
**描述**

设置马达振幅。1表示支持，0表示不支持。
