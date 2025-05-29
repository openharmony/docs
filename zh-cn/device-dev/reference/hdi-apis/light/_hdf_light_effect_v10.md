# HdfLightEffect

## 概述

定义灯的效果参数。

参数包括设置灯的亮度、闪烁模式。

**起始版本：** 3.1

**相关模块：**[Light](_light.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [lightBrightness](#lightbrightness) | 亮度值：Bits 24–31为扩展位，Bits 16–23为红色，Bits 8–15为绿色，Bits 0–7为蓝色。如果字节段等于0时，灯的亮度根据HCS配置的默认亮度进行设置。 | 
| struct [HdfLightFlashEffect](_hdf_light_flash_effect_v10.md) [flashEffect](#flasheffect) | 闪烁模式。详见[HdfLightFlashEffect](_hdf_light_flash_effect_v10.md)。 | 

## 类成员变量说明

### flashEffect

```
struct HdfLightFlashEffect HdfLightEffect::flashEffect
```

**描述**

闪烁模式。详见[HdfLightFlashEffect](_hdf_light_flash_effect_v10.md)。

### lightBrightness

```
int HdfLightEffect::lightBrightness
```

**描述**

亮度值：Bits 24–31为扩展位，Bits 16–23为红色，Bits 8–15为绿色，Bits 0–7为蓝色。如果字节段等于0时，灯的亮度根据HCS配置的默认亮度进行设置。
