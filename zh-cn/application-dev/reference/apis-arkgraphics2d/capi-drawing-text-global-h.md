# drawing_text_global.h

## 概述

提供文本全局信息的相关接口，比如设置文本渲染高对比度模式等。

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_TextHighContrast](#oh_drawing_texthighcontrast) | OH_Drawing_TextHighContrast | 文本渲染高对比度模式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [void OH_Drawing_SetTextHighContrast(OH_Drawing_TextHighContrast action)](#oh_drawing_settexthighcontrast) | 设置文本渲染高对比度模式。 |

## 枚举类型说明

### OH_Drawing_TextHighContrast

```
enum OH_Drawing_TextHighContrast
```

**描述**

文本渲染高对比度模式枚举。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| TEXT_FOLLOW_SYSTEM_HIGH_CONTRAST | 跟随系统设置中的高对比度文字配置。 |
| TEXT_APP_DISABLE_HIGH_CONTRAST | 关闭APP的文本渲染高对比度配置，该模式的优先级要高于系统设置中的高对比度文字配置。 |
| TEXT_APP_ENABLE_HIGH_CONTRAST | 开启APP的文本渲染高对比度配置，该模式的优先级要高于系统设置中的高对比度文字配置。 |


## 函数说明

### OH_Drawing_SetTextHighContrast()

```
void OH_Drawing_SetTextHighContrast(OH_Drawing_TextHighContrast action)
```

**描述**

设置文本渲染高对比度模式。

该接口设置后整个进程都会生效，进程内所有页面共用相同模式。

可调用此接口设置，也可通过系统设置界面中高对比度文字配置开关进行开启/关闭。使用此接口设置开启/关闭文本渲染高对比度配置的优先级高于系统开关设置。

该接口针对应用的文字自绘制场景不生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextHighContrast](#oh_drawing_texthighcontrast) action | 表示文本渲染高对比度模式，为[OH_Drawing_TextHighContrast](capi-drawing-text-global-h.md#oh_drawing_texthighcontrast)类型的枚举值。 |


