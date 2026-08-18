# ArkUI_NodeAttributeType（动效、视效相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI（方舟UI框架）在Native侧可以设置的动效、视效相关属性样式集合，包含图形变换、渐变、阴影、模糊和转场等属性设置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)


## NODE_TRANSLATE

```c
NODE_TRANSLATE = 8
```

设置组件平移，支持属性设置，属性重置和属性获取接口。<br>
与NODE_TRANSLATE_WITH_PERCENT互斥，同一组件只能使用一种平移属性设置方式。如同时设置NODE_TRANSLATE和NODE_TRANSLATE_WITH_PERCENT，后者设置的值将覆盖前者。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | x轴移动距离，单位vp，默认值0。 |
| .value[1].f32 | y轴移动距离，单位vp，默认值0。 |
| .value[2].f32 | z轴移动距离，单位vp，默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | x轴移动距离，单位vp。 |
| .value[1].f32 | y轴移动距离，单位vp。 |
| .value[2].f32 | z轴移动距离，单位vp。 |

## NODE_SCALE

```c
NODE_SCALE = 9
```

设置组件缩放，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | x轴的缩放系数，默认值1。值为0时组件不可见，负值时组件沿x轴翻转显示。 |
| .value[1].f32 | y轴的缩放系数，默认值1。值为0时组件不可见，负值时组件沿y轴翻转显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | x轴的缩放系数。 |
| .value[1].f32 | y轴的缩放系数。 |

## NODE_ROTATE

```c
NODE_ROTATE = 10
```

设置组件旋转，支持属性设置，属性重置和属性获取接口。<br>
与NODE_ROTATE_ANGLE互斥，同一组件只能使用一种旋转属性设置方式。如同时设置NODE_ROTATE和NODE_ROTATE_ANGLE，后者设置的值将覆盖前者。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 旋转轴向量x坐标，默认值0。 |
| .value[1].f32 | 旋转轴向量y坐标，默认值0。 |
| .value[2].f32 | 旋转轴向量z坐标，默认值0。 |
| .value[3].f32 | 旋转角度，单位为度（°），默认值0。 |
| .value[4].f32 | 视距，即视点到z=0平面的距离，单位vp，默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 旋转轴向量x坐标。 |
| .value[1].f32 | 旋转轴向量y坐标。 |
| .value[2].f32 | 旋转轴向量z坐标。 |
| .value[3].f32 | 旋转角度，单位为度（°）。 |
| .value[4].f32 | 视距，即视点到z=0平面的距离，单位vp。 |

## NODE_BRIGHTNESS

```c
NODE_BRIGHTNESS = 11
```

设置组件高光效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 亮度值，默认值1.0，推荐取值范围[0, 2.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 亮度值，1.0表示原始亮度，推荐取值范围[0, 2.0]。 |

## NODE_SATURATION

```c
NODE_SATURATION = 12
```

设置组件饱和度效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 饱和度值，默认值1.0，推荐取值范围[0, 50.0)，传入负值时按0处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 饱和度值，1.0表示原始饱和度，推荐取值范围[0, 50.0)。 |

## NODE_BLUR

```c
NODE_BLUR = 13
```

设置组件内容模糊效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 模糊半径，取值范围[0, +∞)，模糊半径越大越模糊，为0时不模糊，小于0时按0处理且不会返回错误码。单位vp，默认值0.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 模糊半径，模糊半径越大越模糊，为0时不模糊。单位vp。 |

## NODE_LINEAR_GRADIENT

```c
NODE_LINEAR_GRADIENT = 14
```

设置组件颜色渐变效果，支持属性设置，属性重置和属性获取接口。<br>
与NODE_SWEEP_GRADIENT、NODE_RADIAL_GRADIENT互斥，同一组件只能设置一种渐变类型。如同时设置多种渐变属性，后设置的渐变类型将覆盖先前设置的渐变效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 线性渐变的起始角度，单位度（°），0点方向顺时针旋转为正向角度，默认值180。当[ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)为ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM时，angle属性生效，否则按direction为主要布局方式。 |
| .value[1].i32 | 线性渐变的方向，参数类型为[ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)。设置为非ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM时，angle不生效。枚举值包括：ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT（从左到右）、ARKUI_LINEAR_GRADIENT_DIRECTION_TOP（从上到下）、ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT（从右到左）、ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM（从下到上）、ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP（从左上到右下）、ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP（从右上到左下）、ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM（从左下到右上）、ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM（从右下到左上）、ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM（自定义方向）。 |
| .value[2].i32 | 为渐变的颜色重复着色，0表示不重复着色，1表示重复着色，默认值0。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 线性渐变的起始角度，单位为度（°）。当为ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM时，angle为设置值，其他情况均为默认值。 |
| .value[1].i32 | 线性渐变的方向，取[ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)枚举值。 |
| .value[2].i32 | 为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

## NODE_OPACITY

```c
NODE_OPACITY = 16
```

透明度属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 透明度数值，默认值为1，取值范围为[0, 1]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 透明度数值，取值范围为0到1。 |

## NODE_Z_INDEX

```c
NODE_Z_INDEX = 21
```

组件的堆叠顺序属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 堆叠顺序数值，数值越大组件层级越高，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 堆叠顺序数值，默认值0。 |

## NODE_VISIBILITY

```c
NODE_VISIBILITY = 22
```

组件是否可见属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 控制当前组件显示或隐藏，参数类型[ArkUI_Visibility](capi-common-attributes-h.md#arkui_visibility)，默认值为ARKUI_VISIBILITY_VISIBLE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 控制当前组件显示或隐藏，参数类型[ArkUI_Visibility](capi-common-attributes-h.md#arkui_visibility)，默认值为ARKUI_VISIBILITY_VISIBLE。各枚举值含义及对应数字：ARKUI_VISIBILITY_VISIBLE(0)表示可见，ARKUI_VISIBILITY_HIDDEN(1)表示隐藏但占位，ARKUI_VISIBILITY_NONE(2)表示隐藏且不占位。 |

## NODE_CLIP

```c
NODE_CLIP = 23
```

组件裁剪属性，控制是否对子组件超出当前组件范围外的区域进行裁剪，支持属性设置，属性重置和属性获取接口。<br>
与NODE_CLIP_SHAPE互斥，同一组件只能使用一种裁剪属性设置方式。NODE_CLIP提供简单的布尔裁剪，NODE_CLIP_SHAPE提供指定形状的裁剪，同时设置时后者将覆盖前者。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 控制是否对子组件超出当前组件范围外的区域进行裁剪，0表示不裁剪，1表示裁剪。默认为不裁剪。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 控制是否对子组件超出当前组件范围外的区域进行裁剪，0表示不裁剪，1表示裁剪。 |

## NODE_CLIP_SHAPE

```c
NODE_CLIP_SHAPE = 24
```

组件上指定形状的裁剪，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

1.rect类型：<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型[ArkUI_ClipType](capi-native-type-visual-h.md#arkui_cliptype)，rect类型需设置为ARKUI_CLIP_TYPE_RECTANGLE。 |
| .value[1].f32 | 矩形宽度，单位为vp。 |
| .value[2].f32 | 矩形高度，单位为vp。 |
| .value[3].f32 | 矩形圆角宽度，单位为vp。 |
| .value[4].f32 | 矩形圆角高度，单位为vp。 |
| .value[5]?.f32 | 矩形形状的左上圆角半径，单位为vp，默认值0。 |
| .value[6]?.f32 | 矩形形状的左下圆角半径，单位为vp，默认值0。 |
| .value[7]?.f32 | 矩形形状的右上圆角半径，单位为vp，默认值0。 |
| .value[8]?.f32 | 矩形形状的右下圆角半径，单位为vp，默认值0。 |
| .object | 参数类型为[ArkUI_RenderNodeClipOption](capi-arkui-nativemodule-arkui-rendernodeclipoption.md)，矩形形状的坐标偏移量，在仅传入.object参数时生效。 |

2.circle类型：<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型ArkUI_ClipType，circle类型需设置为ARKUI_CLIP_TYPE_CIRCLE。 |
| .value[1].f32 | 圆形宽度，单位为vp。 |
| .value[2].f32 | 圆形高度，单位为vp。 |
| .object | 参数类型为[ArkUI_RenderNodeClipOption](capi-arkui-nativemodule-arkui-rendernodeclipoption.md)，圆形坐标偏移量，在仅传入.object参数时生效。 |

3.ellipse类型：<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型ArkUI_ClipType，ellipse类型需设置为ARKUI_CLIP_TYPE_ELLIPSE。 |
| .value[1].f32 | 椭圆形宽度，单位为vp。 |
| .value[2].f32 | 椭圆形高度，单位为vp。 |
| .object | 参数类型为[ArkUI_RenderNodeClipOption](capi-arkui-nativemodule-arkui-rendernodeclipoption.md)，椭圆形坐标偏移量，在仅传入.object参数时生效。 |

4.path类型：<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型ArkUI_ClipType，path类型需设置为ARKUI_CLIP_TYPE_PATH。 |
| .value[1].f32 | 路径宽度，单位为vp。 |
| .value[2].f32 | 路径高度，单位为vp。 |
| .string | 路径绘制的命令字符串，格式遵循SVG path数据语法，如'M0 0 L100 100 Z'。 |
| .object | 参数类型为[ArkUI_RenderNodeClipOption](capi-arkui-nativemodule-arkui-rendernodeclipoption.md)，路径绘制的命令，在仅传入.object参数时生效。 |

**返回：**

1.rect类型：<br>

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型为[ArkUI_ClipType](capi-native-type-visual-h.md#arkui_cliptype)，rect类型返回ARKUI_CLIP_TYPE_RECTANGLE。 |
| .value[1].f32 | 矩形宽度，单位为vp。 |
| .value[2].f32 | 矩形高度，单位为vp。 |
| .value[3].f32 | 矩形圆角宽度，单位为vp。 |
| .value[4].f32 | 矩形圆角高度，单位为vp。 |
| .value[5]?.f32 | 矩形形状的左上圆角半径，单位为vp。 |
| .value[6]?.f32 | 矩形形状的左下圆角半径，单位为vp。 |
| .value[7]?.f32 | 矩形形状的右上圆角半径，单位为vp。 |
| .value[8]?.f32 | 矩形形状的右下圆角半径，单位为vp。 |
| .value[9]?.f32 | 矩形形状的横坐标偏移，单位为vp。 |
| .value[10]?.f32 | 矩形形状的纵坐标偏移，单位为vp。 |

2.circle类型：<br>

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型为[ArkUI_ClipType](capi-native-type-visual-h.md#arkui_cliptype)，circle类型返回ARKUI_CLIP_TYPE_CIRCLE。 |
| .value[1].f32 | 圆形宽度，单位为vp。 |
| .value[2].f32 | 圆形高度，单位为vp。 |
| .value[3]?.f32 | 圆形横坐标偏移，单位为vp。 |
| .value[4]?.f32 | 圆形纵坐标偏移，单位为vp。 |

3.ellipse类型：<br>

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型为[ArkUI_ClipType](capi-native-type-visual-h.md#arkui_cliptype)，ellipse类型返回ARKUI_CLIP_TYPE_ELLIPSE。 |
| .value[1].f32 | 椭圆形宽度，单位为vp。 |
| .value[2].f32 | 椭圆形高度，单位为vp。 |
| .value[3]?.f32 | 椭圆形横坐标偏移，单位为vp。 |
| .value[4]?.f32 | 椭圆形纵坐标偏移，单位为vp。 |

4.path类型：<br>

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 裁剪类型，参数类型为[ArkUI_ClipType](capi-native-type-visual-h.md#arkui_cliptype)，path类型返回ARKUI_CLIP_TYPE_PATH。 |
| .value[1].f32 | 路径宽度，单位为vp。 |
| .value[2].f32 | 路径高度，单位为vp。 |
| .string | 路径绘制的命令字符串。 |


## NODE_TRANSFORM

```c
NODE_TRANSFORM = 25
```

矩阵变换功能，可对图形进行平移、旋转和缩放等，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0...15].f32 | 4x4变换矩阵的16个浮点数，用于对图形进行平移、旋转和缩放等矩阵变换，按行优先顺序排列。此时[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中的size取值不应为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0...15].f32 | 4x4矩阵变换的16个浮点数元素值。 |

## NODE_SHADOW

```c
NODE_SHADOW = 28
```

阴影效果属性，支持属性设置，属性重置和属性获取接口。<br>
与NODE_CUSTOM_SHADOW互斥，同一组件只能使用一种阴影属性设置方式，同时设置时后者将覆盖前者。如需使用预定义阴影样式请使用NODE_SHADOW，如需自定义阴影参数请使用NODE_CUSTOM_SHADOW。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置当前组件阴影效果，参数类型[ArkUI_ShadowStyle](capi-native-type-visual-h.md#arkui_shadowstyle)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 设置当前组件阴影效果，参数类型[ArkUI_ShadowStyle](capi-native-type-visual-h.md#arkui_shadowstyle)。 |

## NODE_CUSTOM_SHADOW

```c
NODE_CUSTOM_SHADOW = 29
```

自定义阴影效果，与NODE_SHADOW互斥，同一组件只能使用一种阴影属性设置方式，同时设置时后者将覆盖前者。如需使用预定义阴影样式请使用NODE_SHADOW，如需自定义阴影参数请使用NODE_CUSTOM_SHADOW。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.f32 | 阴影模糊半径，取值范围[0, +∞)，传入负值时返回参数校验失败。单位为px，默认值0.0。 |
| .value[1]?.i32 | 是否开启智能取色，0代表不开启（使用固定颜色），1代表开启（自动从组件周围取色适配背景），默认不开启。当需要阴影颜色自动适配周围背景时传入1。 |
| .value[2]?.f32 | 阴影X轴偏移量，单位为px，默认值0.0。 |
| .value[3]?.f32 | 阴影Y轴偏移量，单位为px，默认值0.0。 |
| .value[4]?.i32 | 阴影类型，参数类型为[ArkUI_ShadowType](capi-native-type-visual-h.md#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR。 |
| .value[5]?.u32 | 智能取色关闭（.value[1]为0）时表示阴影颜色，0xARGB格式，形如0xFFFF0000表示红色，不传入时默认值为0xFF000000（黑色）；智能取色开启（.value[1]为1）时表示颜色策略，取[ArkUI_ColorStrategy](capi-native-type-visual-h.md#arkui_colorstrategy)枚举值。 |
| .value[6]?.u32 | 阴影是否内部填充，0表示不填充，1表示填充。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 阴影模糊半径，单位为px。 |
| .value[1].i32 | 是否开启智能取色，0代表不开启，1代表开启。 |
| .value[2].f32 | 阴影X轴偏移量，单位为px。 |
| .value[3].f32 | 阴影Y轴偏移量，单位为px。 |
| .value[4].i32 | 阴影类型，参数类型为[ArkUI_ShadowType](capi-native-type-visual-h.md#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR。枚举值包括：ARKUI_SHADOW_TYPE_COLOR（颜色阴影）、ARKUI_SHADOW_TYPE_BLUR（模糊阴影）。 |
| .value[5].u32 | 阴影颜色，0xARGB格式，形如0xFFFF0000表示红色。 |
| .value[6].u32 | 阴影是否内部填充，0表示不填充，1表示填充。 |

## NODE_BACKGROUND_BLUR_STYLE

```c
NODE_BACKGROUND_BLUR_STYLE = 32
```

设置组件背景模糊样式，模糊效果应用于组件背景层与内容层之间，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示模糊类型，取[ArkUI_BlurStyle](capi-native-type-visual-h.md#arkui_blurstyle)枚举值。 |
| .value[1]?.i32 | 表示深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。不传入时默认跟随系统深浅色模式设置。 |
| .value[2]?.i32 | 表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。不传入时默认取色模式为自适应取色，当需要指定固定取色方式时传入此参数。 |
| .value[3]?.f32 | 表示模糊效果程度，取[0.0,1.0]范围内的值。0.0表示无模糊，1.0表示最大模糊效果。不传入时默认值为1.0，当需要调整内容模糊强度时传入此参数。 |
| .value[4]?.f32 | 表示灰阶模糊起始边界，对黑色提亮到哪个位置，有效值范围0-127。参数值越大调整效果越明显。 |
| .value[5]?.f32 | 表示灰阶模糊终点边界，对白色压暗到哪个位置，有效值范围0-127。参数值越大调整效果越明显。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示模糊类型，取[ArkUI_BlurStyle](capi-native-type-visual-h.md#arkui_blurstyle)枚举值。 |
| .value[1].i32 | 表示深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。枚举值包括：ARKUI_COLOR_MODE_LIGHT（浅色模式）、ARKUI_COLOR_MODE_DARK（深色模式）。 |
| .value[2].i32 | 表示取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。 |
| .value[3].f32 | 表示模糊效果程度，取[0.0,1.0]范围内的值。 |
| .value[4].f32 | 表示灰阶模糊起始边界。 |
| .value[5].f32 | 表示灰阶模糊终点边界。 |

## NODE_TRANSFORM_CENTER

```c
NODE_TRANSFORM_CENTER = 33
```

图形变换和转场的中心点属性，影响旋转（NODE_ROTATE/NODE_ROTATE_ANGLE/NODE_ROTATE_TRANSITION）、缩放（NODE_SCALE/NODE_SCALE_TRANSITION）、平移（NODE_TRANSLATE/NODE_TRANSLATE_TRANSITION）等变换和转场属性的中心点行为，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
注：如果设置坐标百分比位置，属性获取方法返回计算后的以vp为单位的值。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.f32 | 表示中心点X轴坐标值，单位为vp，默认值0.0。 |
| .value[1]?.f32 | 表示中心点Y轴坐标，单位为vp，默认值0.0。 |
| .value[2]?.f32 | 表示中心点Z轴坐标，单位为vp，默认值0.0。 |
| .value[3]?.f32 | 表示中心点X轴坐标的百分比位置，取值范围[0, 1]，如0.2表示百分之20的位置，该属性覆盖value[0].f32，默认值：0.5f。<br>超出范围时返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| .value[4]?.f32 | 表示中心点Y轴坐标的百分比位置，取值范围[0, 1]，如0.2表示百分之20的位置，该属性覆盖value[1].f32，默认值：0.5f。<br>超出范围时返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| .value[5]?.f32 | 表示中心点Z轴坐标的百分比位置，取值范围[0, 1]，如0.2表示百分之20的位置，该属性覆盖value[2].f32，默认值：0.0f。<br>超出范围时返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示中心点X轴坐标，单位为vp。 |
| .value[1].f32 | 表示中心点Y轴坐标，单位为vp。 |
| .value[2].f32 | 表示中心点Z轴坐标，单位为vp。 |

## NODE_MOTION_PATH

```c
NODE_MOTION_PATH = 111
```

设置组件的运动路径属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 指向路径动画的运动路径配置项的指针；参数类型为[ArkUI_MotionPathOptions](capi-arkui-nativemodule-arkui-motionpathoptions.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 指向路径动画的运动路径配置项的指针；参数类型为[ArkUI_MotionPathOptions](capi-arkui-nativemodule-arkui-motionpathoptions.md)。 |

## NODE_OPACITY_TRANSITION

```c
NODE_OPACITY_TRANSITION = 34
```

转场时的透明度效果属性，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示转场结束时（即终点）的透明度值，转场将从当前透明度过渡到该值。 |
| .value[1].i32 | 表示动画时长，单位ms，取值需大于0。 |
| .value[2].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[3]?.i32 | 表示动画延迟时长，单位ms。不传入时默认值为0（无延迟），当需要在动画开始前等待一段时间时传入此参数。 |
| .value[4]?.i32 | 表示动画播放次数。不传入时默认值为1（单次播放），当需要动画重复播放时传入此参数。 |
| .value[5]?.i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。默认值为ARKUI_ANIMATION_PLAY_MODE_NORMAL，当需要反向播放、循环播放等特殊播放模式时传入此参数。 |
| .value[6]?.f32 | 表示动画播放速度。不传入时默认值为1.0（正常速度），当需要加速或减速播放动画时传入此参数，大于1.0为加速，小于1.0为减速。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示起始和终点的透明度值，取值范围[0, 1]。超出范围时自动修正为边界值。 |
| .value[1].i32 | 表示动画时长，单位ms。 |
| .value[2].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[3].i32 | 表示动画延迟时长，单位ms。 |
| .value[4].i32 | 表示动画播放次数。 |
| .value[5].i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。 |
| .value[6].f32 | 表示动画播放速度。 |

## NODE_ROTATE_TRANSITION

```c
NODE_ROTATE_TRANSITION = 35
```

转场时的旋转效果属性，仅在组件插入和删除时生效。支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示横向旋转分量。 |
| .value[1].f32 | 表示纵向的旋转分量。 |
| .value[2].f32 | 表示竖向的旋转分量。 |
| .value[3].f32 | 表示角度，单位为度（°）。 |
| .value[4].f32 | 表示视距，即视点到z=0平面的距离，取值范围[0, +∞)，传入负值时按0处理。单位vp，默认值0.0。 |
| .value[5].i32 | 表示动画时长，单位ms。 |
| .value[6].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[7]?.i32 | 表示动画延迟时长，单位ms。不传入时默认值为0（无延迟），当需要在动画开始前等待一段时间时传入此参数。 |
| .value[8]?.i32 | 表示动画播放次数。 |
| .value[9]?.i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。默认值为ARKUI_ANIMATION_PLAY_MODE_NORMAL。 |
| .value[10]?.f32 | 表示动画播放速度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示横向旋转分量。 |
| .value[1].f32 | 表示纵向的旋转分量。 |
| .value[2].f32 | 表示竖向的旋转分量。 |
| .value[3].f32 | 表示角度，单位为度（°）。 |
| .value[4].f32 | 表示视距，单位为vp。 |
| .value[5].i32 | 表示动画时长，单位ms。 |
| .value[6].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[7].i32 | 表示动画延迟时长，单位ms。 |
| .value[8].i32 | 表示动画播放次数。 |
| .value[9].i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。 |
| .value[10].f32 | 表示动画播放速度。 |

## NODE_SCALE_TRANSITION

```c
NODE_SCALE_TRANSITION = 36
```

转场时的缩放效果属性，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 横向放大倍数，默认值1.0。 |
| .value[1].f32 | 纵向放大倍数，默认值1.0。 |
| .value[2].f32 | 竖向放大倍数，默认值1.0。 |
| .value[3].i32 | 表示动画时长，单位ms。 |
| .value[4].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[5]?.i32 | 表示动画延迟时长，单位ms。不传入时默认值为0（无延迟），当需要在动画开始前等待一段时间时传入此参数。 |
| .value[6]?.i32 | 表示动画播放次数。 |
| .value[7]?.i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。默认值为ARKUI_ANIMATION_PLAY_MODE_NORMAL。 |
| .value[8]?.f32 | 表示动画播放速度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 横向放大倍数。 |
| .value[1].f32 | 纵向放大倍数。 |
| .value[2].f32 | 竖向放大倍数。 |
| .value[3].i32 | 表示动画时长，单位ms。 |
| .value[4].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[5].i32 | 表示动画延迟时长，单位ms。 |
| .value[6].i32 | 表示动画播放次数。 |
| .value[7].i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。 |
| .value[8].f32 | 表示动画播放速度。 |

## NODE_TRANSLATE_TRANSITION

```c
NODE_TRANSLATE_TRANSITION = 37
```

转场时的平移效果属性，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示横向平移距离值，单位为vp。默认值为0.0vp。 |
| .value[1].f32 | 表示纵向平移距离值，单位为vp。默认值为0.0vp。 |
| .value[2].f32 | 表示竖向平移距离值，单位为vp。默认值为0.0vp。 |
| .value[3].i32 | 表示动画时长，单位ms。 |
| .value[4].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[5]?.i32 | 表示动画延迟时长，单位ms。不传入时默认值为0（无延迟），当需要在动画开始前等待一段时间时传入此参数。 |
| .value[6]?.i32 | 表示动画播放次数。 |
| .value[7]?.i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。默认值为ARKUI_ANIMATION_PLAY_MODE_NORMAL。 |
| .value[8]?.f32 | 表示动画播放速度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示横向平移距离值，单位为vp。 |
| .value[1].f32 | 表示纵向平移距离值，单位为vp。 |
| .value[2].f32 | 表示竖向平移距离值，单位为vp。 |
| .value[3].i32 | 表示动画时长，单位ms。 |
| .value[4].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[5].i32 | 表示动画延迟时长，单位ms。 |
| .value[6].i32 | 表示动画播放次数。 |
| .value[7].i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。 |
| .value[8].f32 | 表示动画播放速度。 |

## NODE_MOVE_TRANSITION

```c
NODE_MOVE_TRANSITION = 38
```

转场时从屏幕边缘滑入和滑出的效果属性，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 转场时组件滑入滑出的方向，参数类型[ArkUI_TransitionEdge](capi-native-type-visual-h.md#arkui_transitionedge)，不同枚举值决定组件从屏幕的哪个边缘滑入和滑出。 |
| .value[1].i32 | 表示动画时长，单位ms。 |
| .value[2].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[3]?.i32 | 表示动画延迟时长，单位ms。不传入时默认值为0（无延迟），当需要在动画开始前等待一段时间时传入此参数。 |
| .value[4]?.i32 | 表示动画播放次数。 |
| .value[5]?.i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。默认值为ARKUI_ANIMATION_PLAY_MODE_NORMAL。 |
| .value[6]?.f32 | 表示动画播放速度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 参数类型[ArkUI_TransitionEdge](capi-native-type-visual-h.md#arkui_transitionedge)。 |
| .value[1].i32 | 表示动画时长，单位ms。 |
| .value[2].i32 | 表示动画曲线类型，取[ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve)枚举值。 |
| .value[3].i32 | 表示动画延迟时长，单位ms。 |
| .value[4].i32 | 表示动画播放次数。 |
| .value[5].i32 | 表示动画播放模式，取[ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode)枚举值。 |
| .value[6].f32 | 表示动画播放速度。 |

## NODE_SWEEP_GRADIENT

```c
NODE_SWEEP_GRADIENT = 43
```

角度渐变效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.f32 | 为角度渐变的中心点，即相对于当前组件左上角的X轴坐标，单位为vp，默认值为组件宽度的50%。 |
| .value[1]?.f32 | 为角度渐变的中心点，即相对于当前组件左上角的Y轴坐标，单位为vp。不传入时默认为组件垂直中心位置，当需要将渐变中心偏移到特定位置时传入此参数。 |
| .value[2]?.f32 | 角度渐变的起点，单位为度（°），默认值0。 |
| .value[3]?.f32 | 角度渐变的终点，单位为度（°），默认值0。 |
| .value[4]?.f32 | 角度渐变的旋转角度，单位为度（°），默认值0。 |
| .value[5]?.i32 | 是否对渐变颜色重复着色，0表示不重复着色，1表示重复着色。不传入时默认值为0（不重复着色），当需要颜色循环重复填充时传入1。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 为角度渐变的中心点，即相对于当前组件左上角的坐标，X轴坐标。 |
| .value[1].f32 | 为角度渐变的中心点，即相对于当前组件左上角的坐标，Y轴坐标。 |
| .value[2].f32 | 角度渐变的起点，单位为度（°），默认值0。 |
| .value[3].f32 | 角度渐变的终点，单位为度（°），默认值0。 |
| .value[4].f32 | 角度渐变的旋转角度，单位为度（°），默认值0。 |
| .value[5].i32 | 是否对渐变颜色重复着色，0表示不重复着色，1表示重复着色。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置不符合颜色格式要求的颜色值会被跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

## NODE_RADIAL_GRADIENT

```c
NODE_RADIAL_GRADIENT = 44
```

径向渐变效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.f32 | 为径向渐变的中心点，即相对于当前组件左上角的X轴坐标。 |
| .value[1]?.f32 | 为径向渐变的中心点，即相对于当前组件左上角的Y轴坐标。 |
| .value[2]?.f32 | 径向渐变的半径，取值范围[0, +∞)，默认值0。 |
| .value[3]?.i32 | 为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。不传入时默认值为0（不重复着色）。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 为径向渐变的中心点，即相对于当前组件左上角的坐标，X轴坐标。 |
| .value[1].f32 | 为径向渐变的中心点，即相对于当前组件左上角的坐标，Y轴坐标。 |
| .value[2].f32 | 径向渐变的半径，默认值0。 |
| .value[3].i32 | 为渐变的颜色重复着色，false（0）表示不重复着色，true（1）表示重复着色。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色。 |
| stops | 渐变位置。 |
| size | 颜色个数。 |

## NODE_MASK

```c
NODE_MASK = 45
```

组件上加上指定形状的遮罩，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| 1.rect类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](capi-native-type-visual-h.md#arkui_masktype)，遮罩类型枚举值为ARKUI_MASK_TYPE_RECTANGLE；<br>.value[4].f32：矩形宽度，单位为vp；<br>.value[5].f32：矩形高度，单位为vp；<br>.value[6].f32：矩形圆角宽度，单位为vp；<br>.value[7].f32：矩形圆角高度，单位为vp；<br>.value[8]?.f32：矩形形状的左上圆角半径，单位为vp，默认值0；<br>.value[9]?.f32：矩形形状的左下圆角半径，单位为vp，默认值0；<br>.value[10]?.f32：矩形形状的右上圆角半径，单位为vp，默认值0；<br>.value[11]?.f32：矩形形状的右下圆角半径，单位为vp，默认值0。 |
| 2.circle类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](capi-native-type-visual-h.md#arkui_masktype)，遮罩类型枚举值为ARKUI_MASK_TYPE_CIRCLE；<br>.value[4].f32：圆形宽度，单位为vp；<br>.value[5].f32：圆形高度，单位为vp。 |
| 3.ellipse类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](capi-native-type-visual-h.md#arkui_masktype)，遮罩类型枚举值为ARKUI_MASK_TYPE_ELLIPSE；<br>.value[4].f32：椭圆形宽度，单位为vp；<br>.value[5].f32：椭圆形高度，单位为vp。 |
| 4.path类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](capi-native-type-visual-h.md#arkui_masktype)，遮罩类型枚举值为ARKUI_MASK_TYPE_PATH；<br>.value[4].f32：路径宽度，单位为vp；<br>.value[5].f32：路径高度，单位为vp；<br>.string：路径绘制的命令字符串，格式遵循SVG path数据语法，如'M0 0 L100 100 Z'。 |
| 5.progress类型 | .value[0].i32：遮罩类型，参数类型[ArkUI_MaskType](capi-native-type-visual-h.md#arkui_masktype)，遮罩类型枚举值为ARKUI_MASK_TYPE_PROGRESS；<br>.value[1].f32：进度遮罩的当前值；<br>.value[2].f32：进度遮罩的最大值；<br>.value[3].u32：进度遮罩的颜色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| 1.rect类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型；<br>.value[4].f32：矩形宽度，单位为vp；<br>.value[5].f32：矩形高度，单位为vp；<br>.value[6].f32：矩形圆角宽度，单位为vp；<br>.value[7].f32：矩形圆角高度，单位为vp；<br>.value[8]?.f32：矩形形状的左上圆角半径，单位为vp；<br>.value[9]?.f32：矩形形状的左下圆角半径，单位为vp；<br>.value[10]?.f32：矩形形状的右上圆角半径，单位为vp；<br>.value[11]?.f32：矩形形状的右下圆角半径，单位为vp。 |
| 2.circle类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型；<br>.value[4].f32：圆形宽度，单位为vp；<br>.value[5].f32：圆形高度，单位为vp。 |
| 3.ellipse类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型；<br>.value[4].f32：椭圆形宽度，单位为vp；<br>.value[5].f32：椭圆形高度，单位为vp。 |
| 4.path类型 | .value[0].u32：填充颜色，0xargb类型；<br>.value[1].u32：描边颜色，0xargb类型；<br>.value[2].f32：描边宽度，单位为vp；<br>.value[3].i32：遮罩类型；<br>.value[4].f32：路径宽度，单位为vp；<br>.value[5].f32：路径高度，单位为vp；<br>.string：路径绘制的命令字符串，格式遵循SVG path数据语法，如'M0,0 L100,100 Z'。 |
| 5.progress类型 | .value[0].i32：遮罩类型；<br>.value[1].f32：进度遮罩的当前值；<br>.value[2].f32：进度遮罩的最大值；<br>.value[3].u32：进度遮罩的颜色。 |

## NODE_BLEND_MODE

```c
NODE_BLEND_MODE = 46
```

当前控件背景与子节点内容进行混合，用于实现叠加透明效果、颜色混合等视觉合成场景，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 控制当前组件的混合模式类型，参数类型为[ArkUI_BlendMode](capi-native-type-visual-h.md#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。 |
| .value[1]?.i32 | blendMode实现方式是否离屏，参数类型[ArkUI_BlendApplyType](capi-native-type-visual-h.md#arkui_blendapplytype)，默认值为BLEND_APPLY_TYPE_FAST。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 控制当前组件的混合模式类型，参数类型[ArkUI_BlendMode](capi-native-type-visual-h.md#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。 |
| .value[1].i32 | blendMode实现方式是否离屏，参数类型为[ArkUI_BlendApplyType](capi-native-type-visual-h.md#arkui_blendapplytype)，默认值为BLEND_APPLY_TYPE_FAST。枚举值包括：BLEND_APPLY_TYPE_FAST（快速实现，非离屏）、BLEND_APPLY_TYPE_OFFSCREEN（离屏实现）。 |

## NODE_GRAY_SCALE

```c
NODE_GRAY_SCALE = 49
```

灰度效果属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 灰度转换比例，范围0-1之间，默认值为0，比如0.5指按照50%进行灰度处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 灰度转换比例，范围0-1之间。 |

## NODE_INVERT

```c
NODE_INVERT = 50
```

反转输入的图像比例属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 图像反转比例，范围0-1之间，默认值为0，比如0.5指按照50%进行反转处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 图像反转比例，范围0-1之间。 |

## NODE_SEPIA

```c
NODE_SEPIA = 51
```

图像转换为深褐色比例属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 图像转换为深褐色比例，范围0-1之间，默认值为0，比如0.5指按照50%进行深褐色处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 图像转换为深褐色比例，范围0-1之间。 |

## NODE_CONTRAST

```c
NODE_CONTRAST = 52
```

对比度属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 对比度，等于1时为原图，越大则对比度越高，默认值为1，取值范围：[0, 10)，超出范围时返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 对比度，取值范围：[0, 10)。 |

## NODE_FOREGROUND_COLOR

```c
NODE_FOREGROUND_COLOR = 53
```

前景颜色属性，支持属性设置和属性获取接口。属性重置接口无效果，因前景颜色为不可自动恢复默认值的属性类型，重置操作不会改变已设置的前景颜色。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 颜色数值，0xAARRGGBB类型，如0xFFFF0000表示红色，默认值为0xFF000000。用于直接指定颜色值。 |
| .value[0].i32 | 颜色数值枚举[ArkUI_ColorStrategy](capi-native-type-visual-h.md#arkui_colorstrategy)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 颜色数值，0xargb类型。 |

## NODE_OUTLINE_WIDTH

```c
NODE_OUTLINE_WIDTH = 70
```

设置元素的外描边宽度，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 左侧外描边宽度，单位为vp。 |
| .value[1].f32 | 上侧外描边宽度，单位为vp。 |
| .value[2].f32 | 右侧外描边宽度，单位为vp。 |
| .value[3].f32 | 下侧外描边宽度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 左侧外描边宽度，单位为vp。 |
| .value[1].f32 | 上侧外描边宽度，单位为vp。 |
| .value[2].f32 | 右侧外描边宽度，单位为vp。 |
| .value[3].f32 | 下侧外描边宽度，单位为vp。 |

## NODE_GEOMETRY_TRANSITION

```c
NODE_GEOMETRY_TRANSITION = 75
```

组件内隐式共享元素转场（转场在组件插入和删除时自动触发），支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.i32 | 参数类型为1或者0。共享元素绑定的2个组件，针对出场元素未进行删除时是否要继续参与共享元素动画，默认为false，不参与保持原始位置不动。 |
| .string | 用于设置绑定关系，id置""清除绑定关系避免参与共享行为，id可更换重新建立绑定关系。同一个id只能有两个组件绑定，且两个组件必须分别为in和out两种不同类型的角色，不能多个组件绑定同一个id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 取值为1或0。共享元素绑定的2个组件，针对出场元素未进行删除时是否要继续参与共享元素动画，默认为false，不参与共享元素动画，保持原始位置不动。 |
| .string | 用于设置绑定关系，id置""清除绑定关系避免参与共享行为，id可更换重新建立绑定关系。同一个id只能有两个组件绑定，且两个组件必须分别扮演进入(in)和退出(out)两种不同角色，不能多个组件绑定同一个id。 |

## NODE_RENDER_FIT

```c
NODE_RENDER_FIT = 77
```

设置宽高动画过程中的组件内容填充方式，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 内容填充方式，使用[ArkUI_RenderFit](capi-native-type-visual-h.md#arkui_renderfit)枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 内容填充方式，使用[ArkUI_RenderFit](capi-native-type-visual-h.md#arkui_renderfit)枚举值。 |

## NODE_OUTLINE_COLOR

```c
NODE_OUTLINE_COLOR = 78
```

外描边颜色属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 统一设置四条边的边框颜色，使用0xargb表示，如0xFFFF11FF。仅传入.value[0]时生效。 |
| .value[0].u32 | 设置上侧边框颜色，使用0xargb表示，如0xFFFF11FF。传入.value[0]至.value[3]四个值时生效。 |
| .value[1].u32 | 设置右侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |
| .value[2].u32 | 设置下侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |
| .value[3].u32 | 设置左侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 设置上侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |
| .value[1].u32 | 设置右侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |
| .value[2].u32 | 设置下侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |
| .value[3].u32 | 设置左侧边框颜色，使用0xargb表示，如0xFFFF11FF。 |

## NODE_COLOR_BLEND

```c
NODE_COLOR_BLEND = 81
```

为组件添加颜色叠加效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 叠加的颜色，使用0xargb表示，默认值为0x00000000。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 叠加的颜色，使用0xargb表示，如0xFFFF11FF。 |

## NODE_FOREGROUND_BLUR_STYLE

```c
NODE_FOREGROUND_BLUR_STYLE = 82
```

为当前组件提供内容模糊能力，支持属性设置，属性重置，属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示内容模糊样式，取[ArkUI_BlurStyle](capi-native-type-visual-h.md#arkui_blurstyle)枚举值。 |
| .value[1]?.i32 | 表示内容模糊效果使用的深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。不传入时默认值为ARKUI_COLOR_MODE_SYSTEM。 |
| .value[2]?.i32 | 表示内容模糊效果使用的取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。 |
| .value[3]?.f32 | 表示模糊效果程度，取[0.0,1.0]范围内的值。 |
| .value[4]?.f32 | 表示灰阶模糊参数，对黑色的提亮程度，取值范围为[0,127]。不传入时默认值为0。 |
| .value[5]?.f32 | 表示灰阶模糊参数，对白色的压暗程度，取值范围为[0,127]。不传入时默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示内容模糊样式，取[ArkUI_BlurStyle](capi-native-type-visual-h.md#arkui_blurstyle)枚举值。 |
| .value[1].i32 | 表示内容模糊效果使用的深浅色模式，取[ArkUI_ColorMode](capi-native-type-h.md#arkui_colormode)枚举值。 |
| .value[2].i32 | 表示内容模糊效果使用的取色模式，取[ArkUI_AdaptiveColor](capi-native-type-h.md#arkui_adaptivecolor)枚举值。 |
| .value[3].f32 | 表示模糊效果程度，取[0.0,1.0]范围内的值。 |
| .value[4].f32 | 表示灰阶模糊参数，对黑色的提亮程度，取值范围为[0,127]。 |
| .value[5].f32 | 表示灰阶模糊参数，对白色的压暗程度，取值范围为[0,127]。 |

## NODE_TRANSITION

```c
NODE_TRANSITION = 94
```

定义组件插入和删除时显示过渡动效，支持属性设置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 组件插入和删除时的过渡动效配置，参数类型为[ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)，不同TransitionEffect决定组件出现和消失时的动画效果类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 表示组件插入和删除时的过渡动效配置，参数类型为[ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)。 |

## NODE_BACKDROP_BLUR

```c
NODE_BACKDROP_BLUR = 99
```

设置背景模糊效果，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示背景模糊半径，取值范围[0,+∞)，超出范围时返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。单位px，默认值0.0。 |
| .value[1]?.f32 | 表示灰阶模糊参数，对黑色的提亮程度，取值范围为[0,127]。不传入时默认值为0，当需要精细调整模糊效果中黑色区域的提亮程度时传入此参数。 |
| .value[2]?.f32 | 表示灰阶模糊参数，对白色的压暗程度，取值范围为[0,127]。不传入时默认值为0，当需要精细调整模糊效果中白色区域的压暗程度时传入此参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示背景模糊半径，取值范围[0,+∞)，单位为px。 |
| .value[1].f32 | 表示灰阶模糊参数，对黑色的提亮程度，取值范围为[0,127]。 |
| .value[2].f32 | 表示灰阶模糊参数，对白色的压暗程度，取值范围为[0,127]。 |

## NODE_BACKGROUND_IMAGE_RESIZABLE_WITH_SLICE

```c
NODE_BACKGROUND_IMAGE_RESIZABLE_WITH_SLICE = 100
```

设置背景图在拉伸时可调整大小的属性，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 图片左部拉伸时，图片的像素值保持不变，单位为vp，默认值0。 |
| .value[1].f32 | 图片顶部拉伸时，图片的像素值保持不变，单位为vp，默认值0。 |
| .value[2].f32 | 图片右部拉伸时，图片的像素值保持不变，单位为vp，默认值0。 |
| .value[3].f32 | 图片底部拉伸时，图片的像素值保持不变，单位为vp，默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 图片左部拉伸时，图片的像素值保持不变，单位为vp。 |
| .value[1].f32 | 图片顶部拉伸时，图片的像素值保持不变，单位为vp。 |
| .value[2].f32 | 图片右部拉伸时，图片的像素值保持不变，单位为vp。 |
| .value[3].f32 | 图片底部拉伸时，图片的像素值保持不变，单位为vp。 |

## NODE_TRANSLATE_WITH_PERCENT

```c
NODE_TRANSLATE_WITH_PERCENT = 103
```

设置组件平移，支持百分比形式的平移入参，与NODE_TRANSLATE互斥，同一组件只能使用一种平移属性设置方式，同时设置时后者将覆盖前者。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | x轴移动距离，默认单位为百分比，除非value[3]存在且value[3]为0时单位为vp，默认值0。 |
| .value[1].f32 | y轴移动距离，默认单位为百分比，除非value[4]存在且value[4]为0时单位为vp，默认值0。 |
| .value[2].f32 | z轴移动距离，单位vp，默认值0。 |
| .value[3]?.i32 | x轴移动距离是否为百分比形式指定，取值范围：0或1。为1时表示以百分比形式指定，例如value[0].f32=0.1且value[3].i32=1时表示x方向平移10%。默认值1。 |
| .value[4]?.i32 | y轴移动距离是否为百分比形式指定，取值范围：0或1。为1时表示以百分比形式指定，例如value[1].f32=0.1且value[4].i32=1时表示y方向平移10%，默认值1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | x轴移动距离，单位取决于value[3]。 |
| .value[1].f32 | y轴移动距离，单位取决于value[4]。 |
| .value[2].f32 | z轴移动距离，单位vp。 |
| .value[3].i32 | x轴移动距离的单位是否为百分比，当value[3].i32为0时x轴移动距离单位为vp，当value[3].i32为1时x轴移动距离单位为百分比。 |
| .value[4].i32 | y轴移动距离的单位是否为百分比，当value[4].i32为0时y轴移动距离单位为vp，当value[4].i32为1时y轴移动距离单位为百分比。 |

## NODE_ROTATE_ANGLE

```c
NODE_ROTATE_ANGLE = 104
```

设置组件旋转，支持各轴旋转角属性设置，属性重置和属性获取接口。与NODE_ROTATE互斥，同一组件只能使用一种旋转属性设置方式，同时设置时后者将覆盖前者。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | x轴方向旋转角度，单位为度（°），默认值0。 |
| .value[1].f32 | y轴方向旋转角度，单位为度（°），默认值0。 |
| .value[2].f32 | z轴方向旋转角度，单位为度（°），默认值0。 |
| .value[3].f32 | 视距，即视点到z=0平面的距离，单位px，默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | x轴方向旋转角度，单位为度（°），默认值0。 |
| .value[1].f32 | y轴方向旋转角度，单位为度（°），默认值0。 |
| .value[2].f32 | z轴方向旋转角度，单位为度（°），默认值0。 |
| .value[3].f32 | 视距，即视点到z=0平面的距离，单位px，默认值0。 |

## NODE_PIXEL_ROUND

```c
NODE_PIXEL_ROUND = 109
```

设置组件的像素取整策略，用于避免组件在缩放或非整数像素位置渲染时出现视觉锯齿等问题，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 设置组件的像素取整策略；参数类型为[ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 组件的像素取整策略；参数类型为[ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)。 |

## NODE_SYSTEM_MATERIAL

```c
NODE_SYSTEM_MATERIAL = 127
```

定义系统材质属性，支持属性设置，属性重置和属性获取接口。

仅支持系统材质的设备可使用此属性。否则，当设置此属性时，将返回错误码[ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED](./capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。设备是否支持系统材质可通过调用[OH_ArkUI_NativeModule_GetSystemMaterialSupported](./capi-native-material-h.md#oh_arkui_nativemodule_getsystemmaterialsupported)获取。遇到此错误码时，建议先确认设备是否支持系统材质，若不支持则不应使用此属性。设备是否支持系统材质可通过调用[OH_ArkUI_NativeModule_GetSystemMaterialSupported](capi-native-material-h.md#oh_arkui_nativemodule_getsystemmaterialsupported)获取。

材质效果在不同算力的设备上表现不同。算力等级由[ArkUI_MaterialLevel](./capi-native-material-h.md#arkui_materiallevel)定义，可通过[OH_ArkUI_NativeModule_GetGlobalMaterialLevel](./capi-native-material-h.md#oh_arkui_nativemodule_getglobalmateriallevel)获取。在算力等级为[ARKUI_MATERIAL_LEVEL_SMOOTH](./capi-native-material-h.md#arkui_materiallevel)的设备上，设置NODE_SYSTEM_MATERIAL会覆盖NODE_SHADOW/NODE_CUSTOM_SHADOW的阴影效果、NODE_OUTLINE_COLOR的外描边颜色、NODE_OUTLINE_WIDTH的外描边宽度，并改变组件背景颜色。在算力等级为[ARKUI_MATERIAL_LEVEL_EXQUISITE](./capi-native-material-h.md#arkui_materiallevel)或[ARKUI_MATERIAL_LEVEL_GENTLE](./capi-native-material-h.md#arkui_materiallevel)的设备上，会影响阴影属性并在系统材质层添加滤镜效果，可产生类似玻璃的效果。

作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 系统材质对象。参数类型为[ArkUI_ImmersiveMaterialHandle](./capi-arkui-nativemodule-arkui-immersivematerialhandle.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 系统材质对象。参数类型为[ArkUI_ImmersiveMaterialHandle](capi-arkui-nativemodule-arkui-immersivematerialhandle.md)。返回值中的ArkUI_ImmersiveMaterialHandle对象是指向静态成员的指针，因此无需也禁止通过[OH_ArkUI_NativeModule_ImmersiveMaterial_Destroy](capi-native-material-h.md#oh_arkui_nativemodule_immersivematerial_destroy)释放返回对象。 |
