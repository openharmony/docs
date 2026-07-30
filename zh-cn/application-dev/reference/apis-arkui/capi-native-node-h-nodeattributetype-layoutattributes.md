# ArkUI_NodeAttributeType（布局属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3; @zju_ljz; @camlostshi-->
<!--Designer: @hehongyang3; @lanshouren-->
<!--Tester: @liuli0427; @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的布局相关属性集合，包含尺寸、百分比尺寸、内外边距、边框、位置、对齐、方向、约束、Flex参数、布局规则及布局类组件相关属性设置。适用于需要在Native侧进行精细化的组件布局控制、响应式布局适配、复杂布局场景等。通过这些属性，开发者可以灵活控制组件的位置、尺寸、对齐方式等，解决组件布局定位、尺寸适配、对齐调整等布局问题，提升布局效率和灵活性。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_WIDTH

```c
NODE_WIDTH = 0
```

宽度属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置宽度数值，单位为vp。取值范围：[0, +∞)。设置异常值时，按默认值显示或组件尺寸异常。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 宽度数值，单位为vp。 |

## NODE_HEIGHT

```c
NODE_HEIGHT = 1
```

高度属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置高度数值，单位为vp。取值范围：[0, +∞)。设置异常值时，按默认值显示或组件尺寸异常。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 高度数值，单位为vp。 |

## NODE_PADDING

```c
NODE_PADDING = 4
```

内边距属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置上下左右四个位置的内间距值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置上下左右四个位置的内间距值，单位为vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |

2：传入四个参数，表示分别设置上下左右四个位置的内间距值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上内间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[1].f32 | 设置右内间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[2].f32 | 设置下内间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[3].f32 | 设置左内间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上内间距数值，单位为vp。 |
| .value[1].f32 | 右内间距数值，单位为vp。 |
| .value[2].f32 | 下内间距数值，单位为vp。 |
| .value[3].f32 | 左内间距数值，单位为vp。 |

## NODE_MARGIN

```c
NODE_MARGIN = 7
```

外边距属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置上下左右四个位置的外间距值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置上下左右四个位置的外间距值，单位为vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |

2：传入四个参数，表示分别设置上下左右四个位置的外间距值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上外间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[1].f32 | 设置右外间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[2].f32 | 设置下外间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |
| .value[3].f32 | 设置左外间距数值，单位为vp，默认值为0vp。取值范围：[0, +∞)。设置异常值时，按默认值0vp显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上外间距数值，单位为vp。 |
| .value[1].f32 | 右外间距数值，单位为vp。 |
| .value[2].f32 | 下外间距数值，单位为vp。 |
| .value[3].f32 | 左外间距数值，单位为vp。 |

## NODE_ALIGNMENT

```c
NODE_ALIGNMENT = 15
```

设置组件内容在元素绘制区域内的对齐方式，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置对齐方式，参数类型[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)，默认值为ARKUI_ALIGNMENT_CENTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 对齐方式，类型为[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)。 |

## NODE_BORDER_WIDTH

```c
NODE_BORDER_WIDTH = 17
```

边框宽度属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置四条边的边框宽度。<br>
| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置四条边的边框宽度，单位为vp。取值范围：[0, +∞)。默认值为0vp。 |

2：传入四个参数，表示分别设置四条边的边框宽度。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上边框的边框宽度，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[1].f32 | 设置右边框的边框宽度，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[2].f32 | 设置下边框的边框宽度，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[3].f32 | 设置左边框的边框宽度，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上边框的边框宽度，单位为vp。 |
| .value[1].f32 | 右边框的边框宽度，单位为vp。 |
| .value[2].f32 | 下边框的边框宽度，单位为vp。 |
| .value[3].f32 | 左边框的边框宽度，单位为vp。 |

## NODE_BORDER_RADIUS

```c
NODE_BORDER_RADIUS = 18
```

边框圆角属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置四个角的边框圆角半径。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置四个角的边框圆角半径，单位为vp。取值范围：[0, +∞)。默认值为0vp。 |

2：传入四个参数，表示分别设置四个角的边框圆角半径。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置左上角圆角半径，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[1].f32 | 设置右上角圆角半径，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[2].f32 | 设置左下角圆角半径，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |
| .value[3].f32 | 设置右下角圆角半径，单位为vp，默认值为0vp。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 左上角圆角半径，单位为vp。 |
| .value[1].f32 | 右上角圆角半径，单位为vp。 |
| .value[2].f32 | 左下角圆角半径，单位为vp。 |
| .value[3].f32 | 右下角圆角半径，单位为vp。 |

## NODE_BORDER_COLOR

```c
NODE_BORDER_COLOR = 19
```

边框颜色属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：统一设置四条边的边框颜色。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 统一设置四条边的边框颜色，使用0xargb表示，如`0xFFFF11FF`。 |

2：分别设置四条边的边框颜色。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 设置上侧边框颜色，使用0xargb表示，默认值为`0xFF000000`。 |
| .value[1].u32 | 设置右侧边框颜色，使用0xargb表示，默认值为`0xFF000000`。 |
| .value[2].u32 | 设置下侧边框颜色，使用0xargb表示，默认值为`0xFF000000`。 |
| .value[3].u32 | 设置左侧边框颜色，使用0xargb表示，默认值为`0xFF000000`。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 上侧边框颜色，使用0xargb表示，如`0xFFFF11FF`。 |
| .value[1].u32 | 右侧边框颜色，使用0xargb表示，如`0xFFFF11FF`。 |
| .value[2].u32 | 下侧边框颜色，使用0xargb表示，如`0xFFFF11FF`。 |
| .value[3].u32 | 左侧边框颜色，使用0xargb表示，如`0xFFFF11FF`。 |

## NODE_BORDER_STYLE

```c
NODE_BORDER_STYLE = 20
```

边框线条样式属性，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置四条边的边框线条样式。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 统一设置四条边的边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。 |

2：传入四个参数，表示分别设置四条边的边框线条样式。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置上侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| .value[1].i32 | 设置右侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| .value[2].i32 | 设置下侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。 |
| .value[3].i32 | 设置左侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 上侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)。 |
| .value[1].i32 | 右侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)。 |
| .value[2].i32 | 下侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)。 |
| .value[3].i32 | 左侧边框线条样式，参数类型[ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle)。 |

## NODE_POSITION

```c
NODE_POSITION = 27
```

元素左上角相对于父容器左上角偏移位置，支持属性设置（通过[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)）、属性重置（通过[resetAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#resetattribute)）和属性获取（通过[getAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)）接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置x轴坐标，单位为vp。取值范围：(-∞, +∞)。 |
| .value[1].f32 | 设置y轴坐标，单位为vp。取值范围：(-∞, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | x轴坐标，单位为vp。 |
| .value[1].f32 | y轴坐标，单位为vp。 |

## NODE_DIRECTION

```c
NODE_DIRECTION = 47
```

设置容器元素内主轴方向上的布局，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 主轴方向，设置容器内子组件的排列方向。参数类型[ArkUI_Direction](capi-layout-h.md#arkui_direction)，默认值为ARKUI_DIRECTION_AUTO。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 主轴方向，类型为[ArkUI_Direction](capi-layout-h.md#arkui_direction)。 |

## NODE_CONSTRAINT_SIZE

```c
NODE_CONSTRAINT_SIZE = 48
```

约束尺寸属性，组件布局时，进行尺寸范围限制，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置最小宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |
| .value[1].f32 | 设置最大宽度，单位为vp。取值范围：[0, +∞)。默认值：无限制。 |
| .value[2].f32 | 设置最小高度，单位为vp。取值范围：[0, +∞)。默认值：0。 |
| .value[3].f32 | 设置最大高度，单位为vp。取值范围：[0, +∞)。默认值：无限制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 最小宽度，单位为vp。 |
| .value[1].f32 | 最大宽度，单位为vp。 |
| .value[2].f32 | 最小高度，单位为vp。 |
| .value[3].f32 | 最大高度，单位为vp。 |

## NODE_OFFSET

```c
NODE_OFFSET = 54
```

组件子元素相对组件自身的额外偏移属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置x轴偏移量，单位为vp。取值范围：(-∞, +∞)。默认值：0。 |
| .value[1].f32 | 设置y轴偏移量，单位为vp。取值范围：(-∞, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 相对于组件自身的x轴偏移量，单位为vp。 |
| .value[1].f32 | 相对于组件自身的y轴偏移量，单位为vp。 |

## NODE_MARK_ANCHOR

```c
NODE_MARK_ANCHOR = 55
```

组件子元素在位置定位时的锚点属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置锚点x轴坐标，单位为vp。取值范围：(-∞, +∞)。默认值：0。 |
| .value[1].f32 | 设置锚点y轴坐标，单位为vp。取值范围：(-∞, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 锚点在组件坐标系中的x轴坐标，单位为vp。 |
| .value[1].f32 | 锚点在组件坐标系中的y轴坐标，单位为vp。 |

## NODE_ALIGN_RULES

```c
NODE_ALIGN_RULES = 57
```

相对容器中子组件的对齐规则属性，支持属性设置、属性重置和属性获取接口。仅当父容器为RelativeContainer时生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 设置相对容器中子组件的对齐规则，参数类型为[ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 相对容器中子组件的对齐规则，参数类型为[ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)。 |

## NODE_ALIGN_SELF

```c
NODE_ALIGN_SELF = 58
```

设置子组件在父容器交叉轴的对齐格式，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置子组件在父容器交叉轴上的对齐方式，改变子组件在交叉轴方向的位置。参数类型[ArkUI_ItemAlignment](capi-layout-h.md#arkui_itemalignment)，默认值为ARKUI_ITEM_ALIGNMENT_AUTO。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在父容器交叉轴上的对齐方式，类型为[ArkUI_ItemAlignment](capi-layout-h.md#arkui_itemalignment)。 |

## NODE_FLEX_GROW

```c
NODE_FLEX_GROW = 59
```

设置组件在父容器的剩余空间所占比例，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置组件在父容器剩余空间中所占比例。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 组件在父容器剩余空间中所占比例。 |

## NODE_FLEX_SHRINK

```c
NODE_FLEX_SHRINK = 60
```

设置父容器压缩尺寸分配给此属性所在组件的比例，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置父容器压缩尺寸分配给当前组件的比例。取值范围：[0, +∞)。默认值：1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 父容器压缩尺寸分配给当前组件的比例。 |

## NODE_FLEX_BASIS

```c
NODE_FLEX_BASIS = 61
```

设置组件的基准尺寸，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置组件在父容器主轴上的基准尺寸，单位为vp。取值范围：[0, +∞)。默认值：auto。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 组件在父容器主轴上的基准尺寸，单位为vp。 |

## NODE_ASPECT_RATIO

```c
NODE_ASPECT_RATIO = 67
```

设置组件的宽高比，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置组件宽高比，格式为宽度/高度。取值范围：(0, +∞)。默认值：不设置宽高比约束。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 组件宽高比，格式为宽度/高度。设置后组件将按此比例调整尺寸。 |

## NODE_LAYOUT_WEIGHT

```c
NODE_LAYOUT_WEIGHT = 68
```

Row/Column/Flex布局下的子组件布局权重参数，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 设置组件在主轴上的布局权重，决定组件在剩余空间中的分配比例。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 组件在主轴上的布局权重，决定组件在剩余空间中的分配比例。 |

## NODE_DISPLAY_PRIORITY

```c
NODE_DISPLAY_PRIORITY = 69
```

Row/Column/Flex（单行）布局下的子组件在布局容器中显示的优先级，支持属性设置、属性重置和属性获取接口。<br>
当displayPriority大于1时，值越大优先级越高。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 设置组件在布局容器中的显示优先级。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 组件在布局容器中的显示优先级。值越大优先级越高，空间不足时优先显示高优先级组件。 |

## NODE_OUTLINE_WIDTH

```c
NODE_OUTLINE_WIDTH = 70
```

设置元素的外描边宽度，外描边不参与组件布局计算且不影响组件尺寸，与边框宽度不同。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 左侧外描边宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |
| .value[1].f32 | 上侧外描边宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |
| .value[2].f32 | 右侧外描边宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |
| .value[3].f32 | 下侧外描边宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 左侧外描边宽度，单位为vp。 |
| .value[1].f32 | 上侧外描边宽度，单位为vp。 |
| .value[2].f32 | 右侧外描边宽度，单位为vp。 |
| .value[3].f32 | 下侧外描边宽度，单位为vp。 |

## NODE_WIDTH_PERCENT

```c
NODE_WIDTH_PERCENT = 71
```

宽度属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置宽度数值，单位为百分比。取值范围：[0, +∞)。默认值：0。设置异常值时，按默认值0显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 宽度数值，单位为百分比。 |

## NODE_HEIGHT_PERCENT

```c
NODE_HEIGHT_PERCENT = 72
```

高度属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置高度数值，单位为百分比。取值范围：[0, +∞)。默认值：0。设置异常值时，按默认值0显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 高度数值，单位为百分比。 |

## NODE_PADDING_PERCENT

```c
NODE_PADDING_PERCENT = 73
```

内边距属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置上下左右四个位置的内间距百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置上下左右四个位置的内间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |

2：传入四个参数，表示分别设置上下左右四个位置的内间距百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上内间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[1].f32 | 设置右内间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[2].f32 | 设置下内间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[3].f32 | 设置左内间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上内间距数值，单位为百分比。 |
| .value[1].f32 | 右内间距数值，单位为百分比。 |
| .value[2].f32 | 下内间距数值，单位为百分比。 |
| .value[3].f32 | 左内间距数值，单位为百分比。 |

## NODE_MARGIN_PERCENT

```c
NODE_MARGIN_PERCENT = 74
```

外边距属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置上下左右四个位置的外间距百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置上下左右四个位置的外间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |

2：传入四个参数，表示分别设置上下左右四个位置的外间距百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上外间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[1].f32 | 设置右外间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[2].f32 | 设置下外间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[3].f32 | 设置左外间距数值，单位为百分比。默认值为0。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上外间距数值，单位为百分比。 |
| .value[1].f32 | 右外间距数值，单位为百分比。 |
| .value[2].f32 | 下外间距数值，单位为百分比。 |
| .value[3].f32 | 左外间距数值，单位为百分比。 |

## NODE_RELATIVE_LAYOUT_CHAIN_MODE

```c
NODE_RELATIVE_LAYOUT_CHAIN_MODE = 76
```

指定以该组件为链头所构成的链的参数，用于控制链中多个子组件在RelativeContainer中沿主轴或交叉轴方向上的分布方式。常用于实现多个组件沿同一方向均匀分布、保持固定间距或对齐的场景。支持属性设置、属性重置和属性获取接口。仅当父容器为RelativeContainer时生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 链的方向，设置链在水平或垂直方向上排列。枚举[ArkUI_Axis](capi-layout-h.md#arkui_axis)。 |
| .value[1].i32 | 链的样式，设置链内组件的分布方式。枚举[ArkUI_RelativeLayoutChainStyle](capi-layout-h.md#arkui_relativelayoutchainstyle)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 链的方向，类型为[ArkUI_Axis](capi-layout-h.md#arkui_axis)。 |
| .value[1].i32 | 链的样式，类型为[ArkUI_RelativeLayoutChainStyle](capi-layout-h.md#arkui_relativelayoutchainstyle)。 |

## NODE_SIZE

```c
NODE_SIZE = 79
```

设置高宽尺寸，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置宽度数值，单位为vp。取值范围：[0, +∞)。 |
| .value[1].f32 | 设置高度数值，单位为vp。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 宽度数值，单位为vp。 |
| .value[1].f32 | 高度数值，单位为vp。 |

## NODE_LAYOUT_RECT

```c
NODE_LAYOUT_RECT = 83
```

组件布局大小位置属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置组件x轴坐标，单位为px。取值范围：(-∞, +∞)。 |
| .value[1].i32 | 设置组件y轴坐标，单位为px。取值范围：(-∞, +∞)。 |
| .value[2].i32 | 设置组件宽度，单位为px。取值范围：[0, +∞)。 |
| .value[3].i32 | 设置组件高度，单位为px。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件x轴坐标，单位为px。 |
| .value[1].i32 | 组件y轴坐标，单位为px。 |
| .value[2].i32 | 组件宽度，单位为px。 |
| .value[3].i32 | 组件高度，单位为px。 |

## NODE_BORDER_WIDTH_PERCENT

```c
NODE_BORDER_WIDTH_PERCENT = 85
```

边框宽度属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置四条边的边框宽度百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置四条边的边框宽度数值，单位为百分比。取值范围：[0, +∞)。默认值：0。 |

2：传入四个参数，表示分别设置四条边的边框宽度百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上边框的边框宽度，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[1].f32 | 设置右边框的边框宽度，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[2].f32 | 设置下边框的边框宽度，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[3].f32 | 设置左边框的边框宽度，单位为百分比。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上边框的边框宽度，单位为百分比。 |
| .value[1].f32 | 右边框的边框宽度，单位为百分比。 |
| .value[2].f32 | 下边框的边框宽度，单位为百分比。 |
| .value[3].f32 | 左边框的边框宽度，单位为百分比。 |

## NODE_BORDER_RADIUS_PERCENT

```c
NODE_BORDER_RADIUS_PERCENT = 86
```

边框圆角属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 12

**参数：**

支持传入一个或四个参数：

1：只传入一个参数，表示统一设置四个角的边框圆角半径百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 统一设置四个角的边框圆角半径数值，单位为百分比。取值范围：[0, +∞)。默认值：0。 |

2：传入四个参数，表示分别设置四个角的边框圆角半径百分比数值。<br>

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置左上角圆角半径，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[1].f32 | 设置右上角圆角半径，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[2].f32 | 设置左下角圆角半径，单位为百分比。取值范围：[0, +∞)。默认值：0。 |
| .value[3].f32 | 设置右下角圆角半径，单位为百分比。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 左上角圆角半径，单位为百分比。 |
| .value[1].f32 | 右上角圆角半径，单位为百分比。 |
| .value[2].f32 | 左下角圆角半径，单位为百分比。 |
| .value[3].f32 | 右下角圆角半径，单位为百分比。 |

## NODE_WIDTH_LAYOUTPOLICY

```c
NODE_WIDTH_LAYOUTPOLICY = 105
```

设置组件宽度布局策略，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置组件宽度布局策略，参数类型[ArkUI_LayoutPolicy](capi-layout-h.md#arkui_layoutpolicy)，默认值：ARKUI_LAYOUT_POLICY_WRAP_CONTENT。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件宽度布局策略，参数类型[ArkUI_LayoutPolicy](capi-layout-h.md#arkui_layoutpolicy)，默认值：ARKUI_LAYOUT_POLICY_WRAP_CONTENT。设置异常值时，按默认值显示。 |

## NODE_HEIGHT_LAYOUTPOLICY

```c
NODE_HEIGHT_LAYOUTPOLICY = 106
```

设置组件高度布局策略，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置组件高度布局策略，参数类型[ArkUI_LayoutPolicy](capi-layout-h.md#arkui_layoutpolicy)，默认值：ARKUI_LAYOUT_POLICY_WRAP_CONTENT。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件高度布局策略，参数类型[ArkUI_LayoutPolicy](capi-layout-h.md#arkui_layoutpolicy)，默认值：ARKUI_LAYOUT_POLICY_WRAP_CONTENT。设置异常值时，按默认值显示。 |

## NODE_POSITION_EDGES

```c
NODE_POSITION_EDGES = 107
```

设置组件相对容器内容区边界的位置，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 设置组件相对容器内容区边界的位置，参数类型为[ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 组件相对容器内容区边界的位置，参数类型为[ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)。 |

## NODE_CHAIN_WEIGHT

```c
NODE_CHAIN_WEIGHT = 118
```

仅当父组件为RelativeContainer时生效。设置已形成链的组件的布局位置。用于控制链中各个组件沿链方向占据的空间比例，常用于实现同一链中组件按权重比例分配剩余空间的场景。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置组件在水平方向的布局权重，默认值：0。权重值越大，组件在链中占据的空间比例越大。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |
| .value[1].f32 | 设置组件在竖直方向的布局权重，默认值：0。权重值越大，组件在链中占据的空间比例越大。取值范围：[0, +∞)。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 组件在水平方向的布局权重，权重值越大，组件在链中占据的空间比例越大。 |
| .value[1].f32 | 组件在竖直方向的布局权重，权重值越大，组件在链中占据的空间比例越大。 |

## NODE_IGNORE_LAYOUT_SAFE_AREA

```c
NODE_IGNORE_LAYOUT_SAFE_AREA = 119
```

设置扩展组件布局时的安全区域，使组件可以延伸到系统状态栏、导航条等系统UI区域。常用于沉浸式视频播放、全屏游戏、图片查看器等需要全屏显示的场景。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 设置扩展安全区域的类型。参数类型为[ArkUI_LayoutSafeAreaType](capi-layout-h.md#arkui_layoutsafeareatype)，默认值：ARKUI_LAYOUT_SAFE_AREA_TYPE_SYSTEM。设置异常值时，按默认值显示。 |
| .value[1].u32 | 设置扩展安全区域的方向。参数类型为[ArkUI_LayoutSafeAreaEdge](capi-layout-h.md#arkui_layoutsafeareaedge)，默认值：ARKUI_LAYOUT_SAFE_AREA_EDGE_ALL，例如：ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP \| ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 扩展安全区域的类型，类型为[ArkUI_LayoutSafeAreaType](capi-layout-h.md#arkui_layoutsafeareatype)。 |
| .value[1].u32 | 扩展安全区域的方向，类型为[ArkUI_LayoutSafeAreaEdge](capi-layout-h.md#arkui_layoutsafeareaedge)。 |

## NODE_DASH_WIDTH

```c
NODE_DASH_WIDTH = 120
```

当边框样式设置为虚线（ArkUI_BorderStyle为ARKUI_BORDER_STYLE_DASHED）时，用于设置边框虚线的长度。默认值：NODE_BORDER_WIDTH属性的边框宽度值。仅当边框样式为虚线时生效。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上边框虚线的长度，单位vp，控制虚线段的长度。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[1].f32 | 设置右边框虚线的长度，单位vp，控制虚线段的长度。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[2].f32 | 设置下边框虚线的长度，单位vp，控制虚线段的长度。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[3].f32 | 设置左边框虚线的长度，单位vp，控制虚线段的长度。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上边框虚线的长度，单位vp。 |
| .value[1].f32 | 右边框虚线的长度，单位vp。 |
| .value[2].f32 | 下边框虚线的长度，单位vp。 |
| .value[3].f32 | 左边框虚线的长度，单位vp。 |

## NODE_DASH_GAP

```c
NODE_DASH_GAP = 121
```

当边框样式设置为虚线（ArkUI_BorderStyle为ARKUI_BORDER_STYLE_DASHED）时，用于设置边框虚线的间隙。默认值：NODE_BORDER_WIDTH属性的边框宽度值。仅当边框样式为虚线时生效。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为4。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置上边框虚线的间隙，单位vp，控制虚线段之间的间隔。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[1].f32 | 设置右边框虚线的间隙，单位vp，控制虚线段之间的间隔。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[2].f32 | 设置下边框虚线的间隙，单位vp，控制虚线段之间的间隔。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |
| .value[3].f32 | 设置左边框虚线的间隙，单位vp，控制虚线段之间的间隔。取值范围：[0, +∞)。默认值：NODE_BORDER_WIDTH属性的边框宽度值。设置异常值时，按默认的虚线效果显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 上边框虚线的间隙，单位vp。 |
| .value[1].f32 | 右边框虚线的间隙，单位vp。 |
| .value[2].f32 | 下边框虚线的间隙，单位vp。 |
| .value[3].f32 | 左边框虚线的间隙，单位vp。 |

## NODE_LAYOUT_GRAVITY

```c
NODE_LAYOUT_GRAVITY = 122
```

设置Stack（堆叠）容器中子组件的对齐规则，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置Stack容器中子组件的对齐规则，决定子组件在Stack容器中的位置。参数类型为[ArkUI_LocalizedAlignment](capi-layout-h.md#arkui_localizedalignment)，默认值：ARKUI_ALIGNMENT_CENTER。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | Stack容器中子组件的对齐规则，类型为[ArkUI_LocalizedAlignment](capi-layout-h.md#arkui_localizedalignment)。 |

## NODE_BORDER_RADIUS_TYPE

```c
NODE_BORDER_RADIUS_TYPE = 123
```

设置组件绘制圆角的模式，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置组件绘制圆角的模式，影响圆角的渲染效果和性能。参数类型为[ArkUI_RenderStrategy](capi-native-type-h.md#arkui_renderstrategy)，默认值：ARKUI_RENDERSTRATEGY_FAST。FAST模式直接裁剪圆角，渲染性能优先；OFFSCREEN模式使用离屏渲染优化圆角效果，可能影响性能。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件绘制圆角的模式，类型为[ArkUI_RenderStrategy](capi-native-type-h.md#arkui_renderstrategy)。 |

## NODE_ACCESSIBILITY_NEXT_FOCUS_ID

```c
NODE_ACCESSIBILITY_NEXT_FOCUS_ID = 124
```

定义当前组件的无障碍下一个焦点组件的[NODE_ID](capi-native-node-h-nodeattributetype-base.md#node_id)。设置该组件NODE_ID后，无障碍会查找当前页面中NODE_ID与当前组件设置的无障碍下一个焦点组件的NODE_ID相同的组件，若不存在则设置无效。支持属性设置、属性重置和属性获取接口。

作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 无障碍下一个焦点组件的NODE_ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 无障碍下一个焦点组件的NODE_ID。 |

## NODE_ACCESSIBILITY_DEFAULT_FOCUS

```c
NODE_ACCESSIBILITY_DEFAULT_FOCUS = 125
```

设置无障碍默认焦点标志，用于无障碍服务查找默认焦点组件。支持属性设置、属性重置和属性获取接口。

作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 无障碍默认焦点。取值为0或1，取值为1表示该组件被定义为无障碍服务中的默认焦点，取值为0表示组件不被定义为无障碍服务中的默认焦点。传入其他值时，按默认值0处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 无障碍默认焦点。取值为0或1，取值为1表示该组件被定义为无障碍服务中的默认焦点，取值为0表示组件不被定义为无障碍服务中的默认焦点。传入其他值时，按默认值0处理。 |
