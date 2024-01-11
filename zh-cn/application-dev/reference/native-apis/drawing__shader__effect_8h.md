# drawing_shader_effect.h


## 概述

声明与绘图模块中的着色器对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_shader_effect.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode) {<br/>CLAMP, REPEAT, MIRROR, DECAL<br/>} | 着色器效果平铺模式的枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](_drawing.md#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*startPt, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | 创建着色器，在两个指定点之间生成线性渐变。 |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](_drawing.md#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | 创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。 |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](_drawing.md#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode)) | 创建着色器，在给定中心的情况下生成扇形渐变。 |
| void [OH_Drawing_ShaderEffectDestroy](_drawing.md#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) \*) | 销毁着色器对象，并收回该对象占用的内存。 |
