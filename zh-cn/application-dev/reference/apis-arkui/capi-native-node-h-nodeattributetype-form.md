# ArkUI_NodeAttributeType（表单类组件相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao; @liyi0309-->
<!--Designer: @houguobiao; @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的表单类组件相关属性样式集合，包含Toggle、Button、CheckBox、CheckBoxGroup、Slider、Radio等组件属性设置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_TOGGLE_SELECTED_COLOR

```c
NODE_TOGGLE_SELECTED_COLOR = MAX_NODE_SCOPE_NUM * ARKUI_NODE_TOGGLE = 5000
```

组件打开状态的背景颜色属性。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式。 |

## NODE_TOGGLE_SWITCH_POINT_COLOR

```c
NODE_TOGGLE_SWITCH_POINT_COLOR = 5001
```

Switch类型的圆形滑块颜色属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 圆形滑块颜色数值，0xARGB格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 圆形滑块颜色数值，0xARGB格式。 |

## NODE_TOGGLE_VALUE

```c
NODE_TOGGLE_VALUE = 5002
```

Switch类型的开关值，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置开关的值，true表示开启。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 设置开关的值。 |

## NODE_TOGGLE_UNSELECTED_COLOR

```c
NODE_TOGGLE_UNSELECTED_COLOR = 5003
```

组件关闭状态的背景颜色属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式。 |

## NODE_BUTTON_LABEL

```c
NODE_BUTTON_LABEL = MAX_NODE_SCOPE_NUM * ARKUI_NODE_BUTTON = 9000
```

button按钮的文本内容属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 默认文本的内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 默认文本的内容。 |

## NODE_BUTTON_TYPE

```c
NODE_BUTTON_TYPE = 9001
```

Button按钮的类型属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置Button按钮的类型，参数类型[ArkUI_ButtonType](capi-button-h.md#arkui_buttontype)，默认值为ARKUI_BUTTON_TYPE_CAPSULE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 获取Button按钮的类型，参数类型[ArkUI_ButtonType](capi-button-h.md#arkui_buttontype)，默认值为ARKUI_BUTTON_TYPE_CAPSULE。 |

## NODE_BUTTON_MIN_FONT_SCALE

```c
NODE_BUTTON_MIN_FONT_SCALE = 9002
```

Button按钮的最小字体缩放倍数属性，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置Button按钮的最小字体缩放倍数，默认单位fp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 获取Button按钮的最小字体缩放倍数，默认单位fp。 |

## NODE_BUTTON_MAX_FONT_SCALE

```c
NODE_BUTTON_MAX_FONT_SCALE = 9003
```

Button按钮的最大字体缩放倍数属性，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置Button按钮的最大字体缩放倍数，默认单位fp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 获取Button按钮的最大字体缩放倍数，默认单位fp。 |

## NODE_CHECKBOX_SELECT

```c
NODE_CHECKBOX_SELECT = MAX_NODE_SCOPE_NUM * ARKUI_NODE_CHECKBOX = 11000
```

[CheckBox](arkui-ts/ts-basic-components-checkbox.md)多选框是否选中，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 1表示选中，0表示不选中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 1表示选中，0表示不选中。 |

## NODE_CHECKBOX_SELECT_COLOR

```c
NODE_CHECKBOX_SELECT_COLOR = 11001
```

[CheckBox](arkui-ts/ts-basic-components-checkbox.md)多选框选中状态颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 多选框选中状态颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 多选框选中状态颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_CHECKBOX_UNSELECT_COLOR

```c
NODE_CHECKBOX_UNSELECT_COLOR = 11002
```

[CheckBox](arkui-ts/ts-basic-components-checkbox.md)多选框非选中状态边框颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_CHECKBOX_MARK

```c
NODE_CHECKBOX_MARK = 11003
```

[CheckBox](arkui-ts/ts-basic-components-checkbox.md)多选框内部图标样式，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |
| .value[1]?.f32 | 可选，内部图标大小，单位vp。 |
| .value[2]?.f32 | 可选，内部图标粗细，单位vp，默认值2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |
| .value[1].f32 | 内部图标大小，单位vp。 |
| .value[2].f32 | 内部图标粗细，单位vp，默认值2。 |

## NODE_CHECKBOX_SHAPE

```c
NODE_CHECKBOX_SHAPE = 11004
```

CheckBox组件形状，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 组件形状，参数类型[ArkUI_CheckboxShape](capi-checkbox-h.md#arkui_checkboxshape)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件形状，参数类型[ArkUI_CheckboxShape](capi-checkbox-h.md#arkui_checkboxshape)。 |

## NODE_CHECKBOX_NAME

```c
NODE_CHECKBOX_NAME = 11005
```

定义复选框的名称，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 组件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 组件名称。 |

## NODE_CHECKBOX_GROUP

```c
NODE_CHECKBOX_GROUP = 11006
```

定义复选框的组的名称，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 组名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 组名称。 |

## NODE_SLIDER_BLOCK_COLOR

```c
NODE_SLIDER_BLOCK_COLOR = MAX_NODE_SCOPE_NUM * ARKUI_NODE_SLIDER = 17000
```

Slider滑块的颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 滑块的颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 滑块的颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_SLIDER_TRACK_COLOR

```c
NODE_SLIDER_TRACK_COLOR = 17001
```

Slider滑轨的背景颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 背景颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 背景颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_SLIDER_SELECTED_COLOR

```c
NODE_SLIDER_SELECTED_COLOR = 17002
```

Slider滑轨的已滑动部分颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 已滑动部分颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 已滑动部分颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_SLIDER_SHOW_STEPS

```c
NODE_SLIDER_SHOW_STEPS = 17003
```

设置是否显示步长刻度值，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否显示步长刻度值，1表示显示，0表示不显示，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否显示步长刻度值，1表示显示，0表示不显示，默认值为0。 |

## NODE_SLIDER_BLOCK_STYLE

```c
NODE_SLIDER_BLOCK_STYLE = 17004
```

Slider滑块形状参数，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 形状参数。参数类型[ArkUI_SliderBlockStyle](capi-slider-h.md#arkui_sliderblockstyle)。 |
| .string? | 可选值，根据形状参数而定。<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: 滑块图片资源。如/pages/common/icon.png。<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: 滑块使用自定义形状，此时设置的滑块形状中的宽高值并不代表滑块的实际大小，而是由设置的宽高值按比例缩放，以确保滑块可以正常显示。<br>共有4种类型。path类型下，.string表示路径绘制的命令字符串。 |
| .value[1].i32 | 裁剪类型，参数类型[ArkUI_ShapeType](capi-native-type-visual-h.md#arkui_shapetype)。rect类型为ARKUI_SHAPE_TYPE_RECTANGLE；circle类型为ARKUI_SHAPE_TYPE_CIRCLE；ellipse类型为ARKUI_SHAPE_TYPE_ELLIPSE；path类型为ARKUI_SHAPE_TYPE_PATH。 |
| .value[2].f32 | rect、circle、ellipse、path类型的宽度。 |
| .value[3].f32 | rect、circle、ellipse、path类型的高度。 |
| .value[4].f32 | rect类型的矩形圆角宽度。 |
| .value[5].f32 | rect类型的矩形圆角高度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 形状参数。参数类型[ArkUI_SliderBlockStyle](capi-slider-h.md#arkui_sliderblockstyle)。 |
| .string? | 可选值，根据形状参数而定。<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: 滑块图片资源。如/pages/common/icon.png。<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: 滑块使用的自定义形状。<br>共有4种类型。path类型下，.string表示路径绘制的命令字符串。 |
| .value[1].i32 | 裁剪类型，参数类型[ArkUI_ShapeType](capi-native-type-visual-h.md#arkui_shapetype)。rect类型为ARKUI_SHAPE_TYPE_RECTANGLE；circle类型为ARKUI_SHAPE_TYPE_CIRCLE；ellipse类型为ARKUI_SHAPE_TYPE_ELLIPSE；path类型为ARKUI_SHAPE_TYPE_PATH。 |
| .value[2].f32 | rect、circle、ellipse、path类型的宽度。 |
| .value[3].f32 | rect、circle、ellipse、path类型的高度。 |
| .value[4].f32 | rect类型的矩形圆角宽度。 |
| .value[5].f32 | rect类型的矩形圆角高度。 |

## NODE_SLIDER_VALUE

```c
NODE_SLIDER_VALUE = 17005
```

slider进度值，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 进度值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 进度值。 |

## NODE_SLIDER_MIN_VALUE

```c
NODE_SLIDER_MIN_VALUE = 17006
```

slider最小值，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 进度值的最小值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 进度值的最小值。 |

## NODE_SLIDER_MAX_VALUE

```c
NODE_SLIDER_MAX_VALUE = 17007
```

slider最大值，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 进度值的最大值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 进度值的最大值。 |

## NODE_SLIDER_STEP

```c
NODE_SLIDER_STEP = 17008
```

Slider滑动步长，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 滑动步长，取值范围：[0.01, 100]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 滑动步长，取值范围：[0.01, 100]。 |

## NODE_SLIDER_DIRECTION

```c
NODE_SLIDER_DIRECTION = 17009
```

Slider滑动条滑动方向，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 滑动方向，参数类型[ArkUI_SliderDirection](capi-slider-h.md#arkui_sliderdirection)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 滑动方向，参数类型[ArkUI_SliderDirection](capi-slider-h.md#arkui_sliderdirection)。 |

## NODE_SLIDER_REVERSE

```c
NODE_SLIDER_REVERSE = 17010
```

Slider滑动条取值范围是否反向，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否反向，1表示反向，0表示不反向。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否反向，1表示反向，0表示不反向。 |

## NODE_SLIDER_STYLE

```c
NODE_SLIDER_STYLE = 17011
```

Slider的滑块与滑轨显示样式，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 显示样式，参数类型[ArkUI_SliderStyle](capi-slider-h.md#arkui_sliderstyle)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 显示样式，参数类型[ArkUI_SliderStyle](capi-slider-h.md#arkui_sliderstyle)。 |

## NODE_SLIDER_TRACK_THICKNESS

```c
NODE_SLIDER_TRACK_THICKNESS = 17012
```

Slider滑块的滑轨粗细属性，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 滑轨的粗细，单位为vp；当参数NODE_SLIDER_STYLE的值设置为ARKUI_SLIDER_STYLE_OUT_SET时为4.0vp，设置为ARKUI_SLIDER_STYLE_IN_SET时为20.0vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 滑轨的粗细，单位为vp。 |

## NODE_SLIDER_ENABLE_HAPTIC_FEEDBACK

```c
NODE_SLIDER_ENABLE_HAPTIC_FEEDBACK = 17013
```

设置是否开启触控反馈。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
开启触控反馈时，需要在工程的module.json5的requestPermissions字段中增加"name": "ohos.permission.VIBRATE"，开启振动权限。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 是否开启触控反馈。默认值：true，true表示开启触控反馈，false则表示不开启触控反馈。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 是否开启触控反馈。 |

## NODE_SLIDER_PREFIX

```c
NODE_SLIDER_PREFIX = 17014
```

在Slider组件的前端设置自定义组件。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型 [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。前缀组件将放置在Slider组件的起始位置，通常在LTR布局的左侧。 |

## NODE_SLIDER_SUFFIX

```c
NODE_SLIDER_SUFFIX = 17015
```

在Slider组件的后端设置自定义组件。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型 [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。后缀组件将放置在Slider组件的尾侧位置，通常在LTR布局的右侧。 |

## NODE_SLIDER_BLOCK_LINEAR_GRADIENT_COLOR

```c
NODE_SLIDER_BLOCK_LINEAR_GRADIENT_COLOR = 17016
```

Slider滑块的线性渐变颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色，设置非法颜色直接跳过：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

## NODE_SLIDER_TRACK_LINEAR_GRADIENT_COLOR

```c
NODE_SLIDER_TRACK_LINEAR_GRADIENT_COLOR = 17017
```

Slider滑轨的背景线性渐变颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色，设置非法颜色直接跳过：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

## NODE_SLIDER_SELECTED_LINEAR_GRADIENT_COLOR

```c
NODE_SLIDER_SELECTED_LINEAR_GRADIENT_COLOR = 17018
```

Slider滑轨的已滑动部分线性渐变颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色，设置非法颜色直接跳过：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定相对比例位置处的渐变色颜色：<br>- colors：渐变色颜色。<br>- stops：渐变位置。<br>- size：颜色个数。 |

## NODE_RADIO_CHECKED

```c
NODE_RADIO_CHECKED = MAX_NODE_SCOPE_NUM * ARKUI_NODE_RADIO = 18000
```

设置单选框的选中状态，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 单选框的选中状态，默认值false。值为true时，单选框被选中。值为false时，单选框不被选中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 单选框的选中状态。 |

## NODE_RADIO_STYLE

```c
NODE_RADIO_STYLE = 18001
```

设置单选框选中状态和非选中状态的样式，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.u32 | 开启状态底板颜色，类型为0xARGB，默认值为0xFF007DFF。 |
| .value[1]?.u32 | 关闭状态描边颜色，类型为0xARGB，默认值为0xFF182431。 |
| .value[2]?.u32 | 开启状态内部圆饼颜色，类型为0xARGB，默认值为0xFFFFFFFF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 开启状态底板颜色，类型为0xARGB，默认值为0xFF007DFF。 |
| .value[1].u32 | 关闭状态描边颜色，类型为0xARGB，默认值为0xFF182431。 |
| .value[2].u32 | 开启状态内部圆饼颜色，类型为0xARGB，默认值为0xFFFFFFFF。 |

## NODE_RADIO_VALUE

```c
NODE_RADIO_VALUE = 18002
```

设置当前单选框的值，支持属性设置、重置和获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 单选框的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 单选框的值。 |

## NODE_RADIO_GROUP

```c
NODE_RADIO_GROUP = 18003
```

设置当前单选框的所属群组名称，相同group的Radio只能有一个被选中，支持属性设置、重置和获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 当前单选框的所属群组名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 当前单选框的所属群组名称。 |

## NODE_CHECKBOX_GROUP_NAME

```c
NODE_CHECKBOX_GROUP_NAME = MAX_NODE_SCOPE_NUM * ARKUI_NODE_CHECKBOX_GROUP = 21000
```

定义复选框组的名称，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 组件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 组件名称。 |

## NODE_CHECKBOX_GROUP_SELECT_ALL

```c
NODE_CHECKBOX_GROUP_SELECT_ALL = 21001
```

[CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)多选框组是否全选，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否设置全选1表示选中，0表示不选中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 1表示选中，0表示不选中。 |

## NODE_CHECKBOX_GROUP_SELECTED_COLOR

```c
NODE_CHECKBOX_GROUP_SELECTED_COLOR = 21002
```

[CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)多选框选中状态颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | CheckBoxGroup多选框选中状态颜色，0xARGB格式。例如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | [CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)多选框选中状态颜色，0xARGB格式。例如0xFF1122FF。 |

## NODE_CHECKBOX_GROUP_UNSELECTED_COLOR

```c
NODE_CHECKBOX_GROUP_UNSELECTED_COLOR = 21003
```

[CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)多选框未选中边框颜色，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |

## NODE_CHECKBOX_GROUP_MARK

```c
NODE_CHECKBOX_GROUP_MARK = 21004
```

[CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)多选框内部图标样式，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |
| .value[1]?.f32 | 可选，内部图标大小，单位vp。 |
| .value[2]?.f32 | 可选，内部图标粗细，单位vp，默认值2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 边框颜色，类型为0xARGB，如0xFF1122FF。 |
| .value[1]?.f32 | 可选，内部图标大小，单位vp。 |
| .value[2]?.f32 | 可选，内部图标粗细，单位vp，默认值2。 |

## NODE_CHECKBOX_GROUP_SHAPE

```c
NODE_CHECKBOX_GROUP_SHAPE = 21005
```

[CheckBoxGroup](arkui-ts/ts-basic-components-checkboxgroup.md)组件形状，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 组件形状，参数类型[ArkUI_CheckboxShape](capi-checkbox-h.md#arkui_checkboxshape)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 组件形状，参数类型[ArkUI_CheckboxShape](capi-checkbox-h.md#arkui_checkboxshape)。 |
