# HdfLightEffect


## 概述

定义灯的效果参数。

参数包括设置灯的亮度、闪烁模式。

**Since:**

3.1

**Version:**

1.0

**相关模块:**

[Light](_light.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [lightBrightness](#lightbrightness) | int<br/>亮度值：Bits&nbsp;24–31为扩展位，Bits&nbsp;16–23为红色，Bits&nbsp;8–15为绿色，Bits&nbsp;0–7为蓝色。&nbsp;如果字节段等于0时，灯的亮度根据HCS配置的默认亮度进行设置。 | 
| [flashEffect](#flasheffect) | struct&nbsp;[HdfLightFlashEffect](_hdf_light_flash_effect.md)<br/>闪烁模式。 | 


## 类成员变量说明


### flashEffect

  
```
struct HdfLightFlashEffect HdfLightEffect::flashEffect
```

**描述:**

闪烁模式。详见[HdfLightFlashEffect](_hdf_light_flash_effect.md)。


### lightBrightness

  
```
int HdfLightEffect::lightBrightness
```

**描述:**

亮度值：Bits 24–31为扩展位，Bits 16–23为红色，Bits 8–15为绿色，Bits 0–7为蓝色。 如果字节段等于0时，灯的亮度根据HCS配置的默认亮度进行设置。
