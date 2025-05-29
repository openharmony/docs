# drawing_shadow_layer.h

## 概述

声明与绘图模块中的阴影层对象相关的函数。

**引用文件：** drawing_shadow_layer.h

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate(float blurRadius, float x, float y, uint32_t color)](#oh_drawing_shadowlayercreate) | 创建一个阴影层对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>blurRadius小于0等于时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_ShadowLayerDestroy(OH_Drawing_ShadowLayer* shadowLayer)](#oh_drawing_shadowlayerdestroy) | 销毁阴影层对象，并收回该对象占用的内存。 |

## 函数说明

### OH_Drawing_ShadowLayerCreate()

```
OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate(float blurRadius, float x, float y, uint32_t color)
```

**描述**

创建一个阴影层对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>blurRadius小于0等于时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float blurRadius | 表示阴影的半径，必须大于零。 |
| float x | 表示x轴上的偏移点。 |
| float y | 表示y轴上的偏移点。 |
| uint32_t color | 表示阴影的颜色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ShadowLayer](capi-oh-drawing-shadowlayer.md)* | 返回创建的阴影层对象的指针。 |

### OH_Drawing_ShadowLayerDestroy()

```
void OH_Drawing_ShadowLayerDestroy(OH_Drawing_ShadowLayer* shadowLayer)
```

**描述**

销毁阴影层对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_ShadowLayer](capi-oh-drawing-shadowlayer.md)* shadowLayer | 表示指向阴影层对象的指针。 |


