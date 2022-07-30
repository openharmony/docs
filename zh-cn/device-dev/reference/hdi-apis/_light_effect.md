# LightEffect


## **概述**

**所属模块:**

[Light](_light.md)


## **汇总**


### Public 属性

| Public&nbsp;属性 | 描述 |
| -------- | -------- |
| [lightBrightness](#lightbrightness) | 亮度值。 |
| [flashEffect](#flasheffect) | 闪烁模式。 |


## **详细描述**

定义灯的效果参数。

参数包括亮度和闪烁模式。

**Since：**

3.1


## **类成员变量说明**


### flashEffect


```
struct LightFlashEffect LightEffect::flashEffect
```

**描述：**

闪烁模式。详见[LightFlashEffect](_light_flash_effect.md)。


### lightBrightness


```
int32_t LightEffect::lightBrightness
```

**描述：**

亮度值：Bits 24–31为扩展位，Bits 16–23为红色，Bits 8–15为绿色，Bits 0–7为蓝色。 如果相对应的字节段不等于0，表示打开相应颜色的灯。
