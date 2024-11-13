# HdfLightFlashEffect


## 概述

定义灯的闪烁参数。

这些参数包括闪烁模式以及闪烁期间指示灯的打开和关闭时间。

**起始版本：** 3.1

**相关模块：**[Light](_light.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [flashMode](#flashmode) | 闪烁模式。详见[HdfLightFlashMode](_light.md#hdflightflashmode)。 | 
| int [onTime](#ontime) | 表示在一个闪烁周期内灯持续点亮的时间，单位毫秒。 | 
| int [offTime](#offtime) | 表示在一个闪烁周期内灯持续熄灭的时间，单位毫秒。 | 


## 类成员变量说明


### flashMode

```
int HdfLightFlashEffect::flashMode
```

**描述**


闪烁模式。详见[HdfLightFlashMode](_light.md#hdflightflashmode)。


### offTime

```
int HdfLightFlashEffect::offTime
```

**描述**


表示在一个闪烁周期内灯持续熄灭的时间，单位毫秒。


### onTime

```
int HdfLightFlashEffect::onTime
```

**描述**


表示在一个闪烁周期内灯持续点亮的时间，单位毫秒。
