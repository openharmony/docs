# ArkUI_NodeAttributeType（文本显示类组件相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiangyuan6-->
<!--Designer: @xiangyuan6; @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的文本显示类组件相关属性样式集合，包含Text、Span、ImageSpan等组件属性设置。用于在Native开发场景中通过属性设置、属性获取接口配置文本组件的样式属性，如字体大小、颜色、行高、装饰线等，实现对文本显示效果的精细化控制和自定义。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)


## NODE_TEXT_CONTENT

```c
NODE_TEXT_CONTENT = MAX_NODE_SCOPE_NUM * ARKUI_NODE_TEXT = 1000
```

Text组件设置文本内容属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 表示文本内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 表示文本内容。 |

## NODE_FONT_COLOR

```c
NODE_FONT_COLOR = 1001
```

组件字体颜色属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 字体颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 字体颜色数值，0xargb格式。 |

## NODE_FONT_SIZE

```c
NODE_FONT_SIZE = 1002
```

组件字体大小属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 字体大小数值，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。默认值：16fp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 字体大小数值，单位为fp。 |

## NODE_FONT_STYLE

```c
NODE_FONT_STYLE = 1003
```

组件字体样式属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 字体样式，具体枚举值请参考[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。默认值为ARKUI_FONT_STYLE_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 字体样式[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。 |

## NODE_FONT_WEIGHT

```c
NODE_FONT_WEIGHT = 1004
```

组件字体粗细属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 字体粗细样式[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。取值越大字体越粗。默认值为ARKUI_FONT_WEIGHT_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 字体粗细样式[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。 |

## NODE_TEXT_LINE_HEIGHT

```c
NODE_TEXT_LINE_HEIGHT = 1005
```

文本行高属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示行高值，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示行高值，单位为fp。 |

## NODE_TEXT_DECORATION

```c
NODE_TEXT_DECORATION = 1006
```

文本装饰线样式及其颜色属性，支持属性设置、属性重置和属性获取接口。适用于添加文本装饰效果，如下划线表示链接、删除线表示已删除内容、或上划线表示强调。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本装饰线类型，具体枚举值请参考[ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)。默认值为ARKUI_TEXT_DECORATION_TYPE_NONE，无装饰线。 |
| .value[1]?.u32 | 可选值，装饰线颜色，0xargb格式，形如 0xFFFF0000 表示红色。默认值：0xFF000000，表示黑色。 |
| .value[2]?.i32 | 文本装饰线样式，具体枚举值请参考[ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)。默认值为ARKUI_TEXT_DECORATION_STYLE_SOLID，实线装饰线。 |
| .value[3]?.f32 | 可选值，文本装饰线粗细比例，默认值：1.0，取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本装饰线类型[ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)。 |
| .value[1].u32 | 装饰线颜色，0xargb格式。 |
| .value[2].i32 | 文本装饰线样式[ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)。 |
| .value[3].f32 | 文本装饰线粗细比例。 |

## NODE_TEXT_CASE

```c
NODE_TEXT_CASE = 1007
```

文本大小写属性，支持属性设置、属性重置和属性获取接口。适用于控制文本显示格式，如显示标题时自动大写、或格式化用户输入为统一大小写。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示文本大小写类型，具体枚举值请参考[ArkUI_TextCase](capi-text-common-h.md#arkui_textcase)。默认值为ARKUI_TEXT_CASE_NORMAL，表示保持原样。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本大小写类型[ArkUI_TextCase](capi-text-common-h.md#arkui_textcase)。 |

## NODE_TEXT_LETTER_SPACING

```c
NODE_TEXT_LETTER_SPACING = 1008
```

文本字符间距属性，支持属性设置、属性重置和属性获取接口。适用于调整文本排版效果，如设置标题字符间距以增强视觉效果、或调整特殊文本样式的排版美观度。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示字符间距值，单位为fp。取值范围：(-∞, +∞)。当取值为负值时，文字会被压缩。负值过小时会将组件内容区大小压缩为0，导致内容无法显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示字符间距值，单位为fp。 |

## NODE_TEXT_MAX_LINES

```c
NODE_TEXT_MAX_LINES = 1009
```

文本最大行数属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示最大行数，取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示最大行数。 |

## NODE_TEXT_ALIGN

```c
NODE_TEXT_ALIGN = 1010
```

文本水平对齐方式，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示文本水平对齐方式，具体枚举值请参考[ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)。默认值为ARKUI_TEXT_ALIGNMENT_START，表示水平对齐首部。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本水平对齐方式，取[ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)枚举值。 |

## NODE_TEXT_OVERFLOW

```c
NODE_TEXT_OVERFLOW = 1011
```

文本超长时的显示方式属性，支持属性设置、属性重置和属性获取接口。适用于处理文本内容超出显示区域的场景，如单行标题显示时使用省略号、或卡片内容截断显示等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示文本超长时的显示方式，具体枚举值请参考[ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow)。默认值为ARKUI_TEXT_OVERFLOW_NONE，表示文本超长时不裁剪显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本超长时的显示方式[ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow)。 |

## NODE_FONT_FAMILY

```c
NODE_FONT_FAMILY = 1012
```

Text字体列表属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 字体字符串，多个字体用英文逗号(,)分隔。不传入时使用系统默认字体。 |
**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 字体字符串，多个字体用英文逗号(,)分隔。 |

## NODE_TEXT_COPY_OPTION

```c
NODE_TEXT_COPY_OPTION = 1013
```

文本复制粘贴属性，支持属性设置、属性重置和属性获取接口。适用于控制文本复制粘贴行为，如密码输入框禁止复制、或敏感信息保护。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 复制粘贴方式，具体枚举值请参考[ArkUI_CopyOptions](capi-native-type-h.md#arkui_copyoptions)。默认值为ARKUI_COPY_OPTIONS_NONE，表示不支持复制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 复制粘贴方式[ArkUI_CopyOptions](capi-native-type-h.md#arkui_copyoptions)。 |

## NODE_TEXT_BASELINE_OFFSET

```c
NODE_TEXT_BASELINE_OFFSET = 1014
```

文本基线的偏移量属性，支持属性设置、属性重置和属性获取接口。适用于调整文本基线位置，如显示上下标时调整偏移量、或图文混排时实现文本与图片的精确对齐。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。 |

## NODE_TEXT_TEXT_SHADOW

```c
NODE_TEXT_TEXT_SHADOW = 1015
```

文字阴影效果属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 阴影模糊半径，单位为vp。取值范围：[0, +∞)。默认值为0，表示无模糊效果。 |
| .value[1].i32 | 阴影类型，具体枚举值请参考[ArkUI_ShadowType](capi-native-type-visual-h.md#arkui_shadowtype)。默认值为ARKUI_SHADOW_TYPE_COLOR，表示颜色阴影。 |
| .value[2].u32 | 阴影颜色，0xargb格式，形如 0xFFFF0000 表示红色。 |
| .value[3].f32 | 阴影X轴偏移量，单位为vp。 |
| .value[4].f32 | 阴影Y轴偏移量，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 阴影模糊半径，单位为vp。 |
| .value[1].i32 | 阴影类型[ArkUI_ShadowType](capi-native-type-visual-h.md#arkui_shadowtype)。 |
| .value[2].u32 | 阴影颜色，0xargb格式。 |
| .value[3].f32 | 阴影X轴偏移量，单位为vp。 |
| .value[4].f32 | 阴影Y轴偏移量，单位为vp。 |

## NODE_TEXT_MIN_FONT_SIZE

```c
NODE_TEXT_MIN_FONT_SIZE = 1016
```

Text最小显示字号，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 文本最小显示字号，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 文本最小显示字号，单位为fp。 |

## NODE_TEXT_MAX_FONT_SIZE

```c
NODE_TEXT_MAX_FONT_SIZE = 1017
```

Text最大显示字号，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 文本最大显示字号，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 文本最大显示字号，单位为fp。 |

## NODE_TEXT_FONT

```c
NODE_TEXT_FONT = 1018
```

Text样式，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string? | 可选值：字体列表，多个字体使用','进行分隔。不传入时使用系统默认字体。 |
| .value[0].f32 | 文本尺寸，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |
| .value[1]?.i32 | 可选值，文本的字体粗细，具体枚举值请参考[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。取值越大字体越粗。默认值为ARKUI_FONT_WEIGHT_NORMAL。 |
| .value[2]?.i32 | 可选值，字体样式，具体枚举值请参考[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。默认值为ARKUI_FONT_STYLE_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 字体列表，使用多个字体，使用','进行分隔。 |
| .value[0].f32 | 文本尺寸，单位为fp。取值范围：[0, +∞)。 |
| .value[1].i32 | 文本的字体粗细，具体枚举值请参考[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。默认值为ARKUI_FONT_WEIGHT_NORMAL。 |
| .value[2].i32 | 字体样式，具体枚举值请参考[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。默认值为ARKUI_FONT_STYLE_NORMAL。 |

## NODE_TEXT_HEIGHT_ADAPTIVE_POLICY

```c
NODE_TEXT_HEIGHT_ADAPTIVE_POLICY = 1019
```

Text自适应高度的方式，支持属性设置、属性重置和属性获取。适用于文本内容动态变化的场景，如优先按最大行数限制高度、或优先按最小字号确保文本可读性等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 参数类型，具体枚举值请参考[ArkUI_TextHeightAdaptivePolicy](capi-text-h.md#arkui_textheightadaptivepolicy)。默认值为ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST，表示以MaxLines优先。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 获取的文本自适应高度方式的枚举值，参数类型[ArkUI_TextHeightAdaptivePolicy](capi-text-h.md#arkui_textheightadaptivepolicy)。 |

## NODE_TEXT_INDENT

```c
NODE_TEXT_INDENT = 1020
```

文本首行缩进属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示首行缩进值，入参单位为fp，返回值单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示首行缩进值，入参单位为fp，返回值单位为vp。 |

## NODE_TEXT_WORD_BREAK

```c
NODE_TEXT_WORD_BREAK = 1021
```

文本断行规则属性，支持属性设置、属性重置和属性获取接口。适用于控制文本换行方式，如英文单词完整断行、或中文任意字符断行等不同排版需求。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 参数类型，具体枚举值请参考[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)。默认值为ARKUI_WORD_BREAK_BREAK_WORD，对于Non-CJK的文本可在任意2个字符间断行，一行文本中有断行破发点（如空白符）时，优先按破发点换行。对于CJK的文本，换行效果与NORMAL效果保持一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 获取的文本断行规则枚举值，参数类型[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)。 |

## NODE_TEXT_ELLIPSIS_MODE

```c
NODE_TEXT_ELLIPSIS_MODE = 1022
```

设置文本省略位置，支持属性设置、属性重置和属性获取接口。适用于控制文本省略号显示位置，如尾部省略适合常规文本、头部省略适合路径显示、中间省略适合长标题等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 参数类型，具体枚举值请参考[ArkUI_EllipsisMode](capi-text-common-h.md#arkui_ellipsismode)。默认值为ARKUI_ELLIPSIS_MODE_END，表示省略行末内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 获取的文本省略位置枚举值，参数类型[ArkUI_EllipsisMode](capi-text-common-h.md#arkui_ellipsismode)。 |

## NODE_TEXT_LINE_SPACING

```c
NODE_TEXT_LINE_SPACING = 1023
```

文本行间距属性，支持属性设置、属性重置和属性获取接口。适用于调整多行文本的间距，如优化阅读体验、或实现特定的排版风格效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示行间距值，单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 表示行间距值，单位为fp。 |

## NODE_FONT_FEATURE

```c
NODE_FONT_FEATURE = 1024
```

设置文本特性效果。NODE_FONT_FEATURE是OpenType字体的高级排版能力，如支持连字、数字等宽等特性，一般用在自定义字体中，其能力需要字体本身支持。支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 符合文本特性格式的字符串，格式为normal \| &lt;feature-tag-value&gt;。<br>&lt;feature-tag-value&gt;的格式为：&lt;string&gt; [ &lt;integer&gt; \| on \| off ]。<br>&lt;feature-tag-value&gt;的个数可以有多个，中间用','隔开，例如，使用等宽数字的输入格式为：ss01 on。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 表示文本特性的内容，多个文本特性之间使用逗号分隔。 |

## NODE_TEXT_ENABLE_DATA_DETECTOR

```c
NODE_TEXT_ENABLE_DATA_DETECTOR = 1025
```

设置是否启用文本实体识别，识别的实体类型可通过NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG属性配置。适用于识别文本中的特定实体类型（如电话号码、邮箱地址、网址链接等），实现点击跳转、智能交互等功能。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用文本实体识别，1表示文本可实体识别，0表示不可识别。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用文本实体识别。1表示文本可实体识别，0表示不可识别。 |

## NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG

```c
NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG = 1026
```

设置文本识别配置。适用于自定义需要识别的实体类型（如电话号码、邮箱地址、网址链接等），实现精准的文本智能识别和交互功能。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0...].i32 | 实体类型数组，参数类型[ArkUI_TextDataDetectorType](capi-text-h.md#arkui_textdatadetectortype)。数组中可包含电话号码、URL、邮箱等实体类型，具体取值请参考枚举定义。本参数仅在NODE_TEXT_ENABLE_DATA_DETECTOR设置为1（开启文本实体识别）时生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0...].i32 | 实体类型数组，参数类型[ArkUI_TextDataDetectorType](capi-text-h.md#arkui_textdatadetectortype)。 |

## NODE_TEXT_SELECTED_BACKGROUND_COLOR

```c
NODE_TEXT_SELECTED_BACKGROUND_COLOR = 1027
```

文本选中时的背景色属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 颜色数值，0xargb格式。 |

## NODE_TEXT_CONTENT_WITH_STYLED_STRING

```c
NODE_TEXT_CONTENT_WITH_STYLED_STRING = 1028
```

Text组件使用格式化字符串对象设置文本内容属性，支持属性设置、属性重置和属性获取接口。配置自定义[OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)对象到Text组件，会跳过文本控件的布局测算阶段。注意事项：<br>1. 需要保证OH_ArkUI_StyledString对象、OH_Drawing_Typography对象的生命周期跟随Text组件生命周期，Text组件析构时重置OH_ArkUI_StyledString对象，否则会导致应用出现空指针崩溃。<br>2. 保证OH_Drawing_TypographyLayout方法调用时序在Text组件的布局测算之前。<br>3. 释放OH_ArkUI_StyledString对象、OH_Drawing_Typography对象时，需要同步调用Text组件的reset方法，否则会导致应用出现空指针崩溃。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 表示 ArkUI_StyledString 格式化字符串数据，参数类型为[ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 表示 ArkUI_StyledString 格式化字符串数据，参数类型为[ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)。 |

## NODE_TEXT_HALF_LEADING

```c
NODE_TEXT_HALF_LEADING = 1029
```

Text组件设置文本纵向居中显示。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本是否纵向居中显示，默认值：0。<br>1表示文本是纵向居中显示，0表示文本不是纵向居中显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本是否纵向居中显示。1表示文本纵向居中显示，0表示文本不纵向居中显示。 |

## NODE_IMMUTABLE_FONT_WEIGHT

```c
NODE_IMMUTABLE_FONT_WEIGHT = 1030
```

组件字体粗细属性，支持属性设置、属性重置和属性获取接口。通过此接口设置的粗细属性不会跟随系统字体粗细变化。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 字体粗细样式[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。取值越大字体越粗，默认值为ARKUI_FONT_WEIGHT_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 字体粗细样式[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。 |

## NODE_TEXT_LINE_COUNT

```c
NODE_TEXT_LINE_COUNT = 1031
```

文本行数属性，支持属性获取接口。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本行数。 |

## NODE_TEXT_OPTIMIZE_TRAILING_SPACE

```c
NODE_TEXT_OPTIMIZE_TRAILING_SPACE = 1032
```

设置文本排版时是否优化每行结尾的空格，支持属性设置、属性重置和属性获取接口。适用于优化文本排版效果，如去除结尾多余空格以实现更好的文本对齐。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置文本排版时是否优化每行结尾的空格，默认值：0。<br>1表示设置文本排版时优化每行结尾的空格，0表示不优化。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本排版时是否优化每行结尾的空格。1表示已开启优化，0表示未开启优化。 |

## NODE_TEXT_LINEAR_GRADIENT

```c
NODE_TEXT_LINEAR_GRADIENT = 1033
```

设置文本线性渐变效果，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 线性渐变的起始角度，单位为deg。当direction属性设置为ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM时，angle属性生效；否则，以direction属性为主要布局方式。0点方向顺时针旋转为正向角度，默认值：180。 |
| .value[1].i32 | 线性渐变的方向[ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)。设置除ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM之外的线性渐变方向后，angle不生效。默认值：ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM。 |
| .value[2].i32 | 是否为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。默认值：0。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色数组，数组元素为0xargb格式，形如0xFFFF0000表示红色。 |
| stops | stops表示指定颜色所处位置的数组，数组元素取值范围为[0,1.0]，0表示需要设置渐变色的容器的开始处，1.0表示容器的结尾处。想要实现多个颜色渐变效果时，数组元素建议递增设置，如后一个数组元素比前一个数组元素小的话，按照等于前一个数组元素的值处理。 |
| size | 颜色个数，若小于colors数组长度则仅生效前size个颜色，不建议设置大于colors数组长度或小于等于0的值以及异常值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 线性渐变的起始角度。当为ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM时，angle为设置值，其他情况均为默认值0。 |
| .value[1].i32 | 线性渐变的方向[ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)。 |
| .value[2].i32 | 为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。默认值：0。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色数组，数组元素为0xargb格式，形如0xFFFF0000表示红色。 |
| stops | stops表示指定颜色所处位置的数组，数组元素取值范围为[0,1.0]，0表示需要设置渐变色的容器的开始处，1.0表示容器的结尾处。 |
| size | 生效后渐变色的颜色个数。 |

## NODE_TEXT_RADIAL_GRADIENT

```c
NODE_TEXT_RADIAL_GRADIENT = 1034
```

设置文本径向渐变效果，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.f32 | 为径向渐变的中心点，即相对于当前文本框左上角的X轴坐标，单位为vp。默认值：0。 |
| .value[1]?.f32 | 为径向渐变的中心点，即相对于当前文本框左上角的Y轴坐标，单位为vp。文本框左上角的坐标为[0,0]。默认值：0。 |
| .value[2]?.f32 | 径向渐变的半径，默认值0。取值范围：[0, +∞)。传入负数时参数不生效。 |
| .value[3]?.i32 | 是否为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。默认值：0。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色数组，数组元素为0xargb格式，形如0xFFFF0000表示红色。 |
| stops | stops表示指定颜色所处位置的数组，数组元素取值范围为[0,1.0]，0表示需要设置渐变色的容器的开始处，1.0表示容器的结尾处。想要实现多个颜色渐变效果时，数组元素建议递增设置，如后一个数组元素比前一个数组元素小的话，按照等于前一个数组元素的值处理。 |
| size | 颜色个数，若小于colors数组长度则仅生效前size个颜色，不建议设置大于colors数组长度或小于等于0的值以及异常值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0]?.f32 | 为径向渐变的中心点，即相对于当前文本框左上角的X轴坐标，单位为vp。 |
| .value[1]?.f32 | 为径向渐变的中心点，即相对于当前文本框左上角的Y轴坐标，单位为vp。文本框左上角的坐标为[0,0]。 |
| .value[2]?.f32 | 径向渐变的半径，单位为vp。默认值0。 |
| .value[3]?.i32 | 为渐变的颜色重复着色，0表示不重复着色，1表示重复着色。默认值：0。 |
| .object | 参数类型为[ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md)。指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过。 |
| colors | 渐变色颜色数组，数组元素为0xargb格式，形如0xFFFF0000表示红色。 |
| stops | stops表示指定颜色所处位置的数组，数组元素取值范围为[0,1.0]，0表示需要设置渐变色的容器的开始处，1.0表示容器的结尾处。 |
| size | 生效后渐变色的颜色个数。 |

## NODE_TEXT_VERTICAL_ALIGN

```c
NODE_TEXT_VERTICAL_ALIGN = 1035
```

设置文本内容垂直对齐方式，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本内容垂直对齐方式[ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)，默认值：ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本内容垂直对齐方式[ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)。 |

## NODE_TEXT_CONTENT_ALIGN

```c
NODE_TEXT_CONTENT_ALIGN = 1036
```

设置文本内容区垂直对齐方式，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本内容区垂直对齐方式[ArkUI_TextContentAlign](capi-text-common-h.md#arkui_textcontentalign)，默认值：ARKUI_TEXT_CONTENT_ALIGN_CENTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本内容区垂直对齐方式[ArkUI_TextContentAlign](capi-text-common-h.md#arkui_textcontentalign)。 |

## NODE_TEXT_MIN_LINES

```c
NODE_TEXT_MIN_LINES = 1037
```

文本最小行数属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示文本最小行数，取值范围：正整数。传入0或负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本最小行数，取值范围：正整数。 |

## NODE_TEXT_ENABLE_SELECTED_DATA_DETECTOR

```c
NODE_TEXT_ENABLE_SELECTED_DATA_DETECTOR = 1038
```

开启选中词的文本实体识别，用于在用户选中文本时识别其中的特定类型数据（如电话号码、邮箱、网址等）。适用于用户选中文本后进行智能识别，如识别选中词的语义类型、实现智能搜索推荐或上下文分析等功能。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 开启选中词文本识别，1表示开启识别，0表示关闭识别。默认值：1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否开启选中词文本识别。1表示已开启识别，0表示已关闭识别。 |

## NODE_TEXT_MIN_LINE_HEIGHT

```c
NODE_TEXT_MIN_LINE_HEIGHT = 1040
```

设置文本最小行高，支持属性设置、属性重置和属性获取接口。适用于限制文本行高的最小值，如确保文本可读性、或防止行高过小导致文字重叠显示。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 文本最小行高，默认值：0。单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 文本最小行高。单位为fp。 |

## NODE_TEXT_MAX_LINE_HEIGHT

```c
NODE_TEXT_MAX_LINE_HEIGHT = 1041
```

设置文本最大行高，支持属性设置、属性重置和属性获取接口。适用于限制文本行高的最大值，如控制文本布局紧凑度、或防止行高过大导致显示空间浪费。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 文本最大行高，默认值：0，表示最大行高不受限制。单位为fp。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 文本最大行高。单位为fp。 |

## NODE_TEXT_LINE_HEIGHT_MULTIPLE

```c
NODE_TEXT_LINE_HEIGHT_MULTIPLE = 1042
```

设置倍数行高模式的倍数值，支持属性设置、属性重置和属性获取接口。适用于相对字号设置行高，如实现动态排版、或字号变化时自动调整行高。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 倍数行高模式的倍数值，默认值：0，表示使用默认行高高度。取值范围：[0, +∞)。传入负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 倍数行高模式的倍数值。 |

## NODE_TEXT_LAYOUT_MANAGER

```c
NODE_TEXT_LAYOUT_MANAGER = 1043
```

文本布局管理器，支持属性获取接口。适用于获取文本布局信息，如查询文本行数、字符位置、测量文本尺寸等。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 文本布局管理器对象，参数类型为[ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)。 |

## NODE_TEXT_EDIT_MENU_OPTIONS

```c
NODE_TEXT_EDIT_MENU_OPTIONS = 1044
```

文本菜单扩展项，支持属性设置接口。适用于扩展文本编辑菜单，如添加自定义操作项、或扩展复制粘贴等功能。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 文本菜单扩展项配置数据，参数类型为[ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)。 |

## NODE_TEXT_BIND_SELECTION_MENU

```c
NODE_TEXT_BIND_SELECTION_MENU = 1045
```

自定义文本选择菜单，支持属性设置接口。适用于定制文本选择菜单，如添加特定操作按钮、或定制菜单UI风格。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 自定义文本选择菜单配置数据，参数类型为[ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)。 |

## NODE_TEXT_TEXT_SELECTION

```c
NODE_TEXT_TEXT_SELECTION = 1046
```

设置文本选择区域，设置后选中区域将被高亮显示，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本选择的起始位置。取值范围：[0, 文本长度]，必须是有效的文本索引。 |
| .value[1].i32 | 文本选择的结束位置。取值范围：[0, 文本长度]，必须是有效的文本索引。 |
| .object | 选择选项。参数类型为[ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本选择的起始位置。 |
| .value[1].i32 | 文本选择的结束位置。 |
| .object | 选择选项。参数类型为[ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)。 |

## NODE_TEXT_ORPHAN_CHAR_OPTIMIZATION

```c
NODE_TEXT_ORPHAN_CHAR_OPTIMIZATION = 1047
```

设置Text文本排版时是否使能孤字优化，设置后通过更高效地处理孤立字符（段落尾行首字符）来改善文本布局。使能后，它会调整换行点以尽可能避免孤立字符。孤字优化特性需在[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)属性为非ARKUI_WORD_BREAK_BREAK_ALL时生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否使能孤字优化，1表示使能，0表示不使能。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否使能孤字优化。1表示已使能孤字优化，0表示未使能孤字优化。 |

## NODE_TEXT_COMPRESS_LEADING_PUNCTUATION

```c
NODE_TEXT_COMPRESS_LEADING_PUNCTUATION = 1048
```

文本行首标点压缩开关，支持属性设置、属性重置和属性获取接口。适用于中文排版场景，压缩行首标点以提升排版美观度和阅读体验。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否打开行首标点压缩开关。<br>1表示开启行首标点压缩，0表示关闭行首标点压缩。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否打开行首标点压缩开关。1表示已开启行首标点压缩，0表示已关闭行首标点压缩。 |

## NODE_TEXT_INCLUDE_FONT_PADDING

```c
NODE_TEXT_INCLUDE_FONT_PADDING = 1049
```

设置是否在首行和尾行增加间距以避免文字截断。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 设置是否在首行和尾行增加间距以避免文字截断。<br>1表示开启增加间距，0表示关闭增加间距。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否在首行和尾行增加间距。1表示增加间距，0表示不增加间距。 |

## NODE_TEXT_FALLBACK_LINE_SPACING

```c
NODE_TEXT_FALLBACK_LINE_SPACING = 1050
```

针对多行文字叠加，支持行高基于文字实际高度自适应。此接口仅当行高小于文字实际高度时生效。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 支持行高基于文字实际高度自适应。<br>1表示开启自适应，0表示关闭自适应。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否开启行高基于文字实际高度自适应。1表示开启自适应，0表示关闭自适应。 |

## NODE_TEXT_MARQUEE_OPTIONS

```c
NODE_TEXT_MARQUEE_OPTIONS = 1051
```

文本跑马灯模式配置项，支持属性设置、属性重置和属性获取接口。适用于长文本滚动显示场景，如通知提醒、标题滚动显示等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 文本跑马灯模式配置，参数类型为[ArkUI_TextMarqueeOptions](capi-arkui-nativemodule-arkui-textmarqueeoptions.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 文本跑马灯模式配置，参数类型为[ArkUI_TextMarqueeOptions](capi-arkui-nativemodule-arkui-textmarqueeoptions.md)。 |

## NODE_TEXT_DIRECTION

```c
NODE_TEXT_DIRECTION = 1052
```

文本排版方向。适用于支持不同语言的排版需求，如阿拉伯语、希伯来语等从右向左（RTL）的语言显示。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示文本的排版方向，取[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)枚举值。默认值为ARKUI_TEXT_DIRECTION_DEFAULT，表示文本排版方向遵循组件布局。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示文本的排版方向，对应取值及含义请参考[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)枚举值。 |

## NODE_TEXT_SELECTED_DRAG_PREVIEW_STYLE

```c
NODE_TEXT_SELECTED_DRAG_PREVIEW_STYLE = 1053
```

用于设置文本选中状态下的拖拽预览样式。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 文本选中状态下的拖拽预览样式。参数类型为[ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 文本选中状态下的拖拽预览样式。参数类型为[ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)。 |

## NODE_TEXT_CONTROLLER

```c
NODE_TEXT_CONTROLLER = 1054
```

设置文本的控制器。适用于管理文本编辑行为，如控制文本显示、管理格式化字符串等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 文本的控制器，参数类型为[OH_ArkUI_TextController](capi-arkui-nativemodule-oh-arkui-textcontroller.md)。 |

## NODE_TEXT_PUNCTUATION_OVERFLOW

```c
NODE_TEXT_PUNCTUATION_OVERFLOW = 1055
```

设置Text组件是否启用行尾标点符号悬挂，支持属性设置、属性重置和属性获取。适用于中文排版场景，将行尾标点符号外挂显示以优化排版效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用行尾标点符号悬挂。<br>1表示启用标点符号悬挂，0表示不启用标点符号悬挂。默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用行尾标点符号悬挂。<br>1表示启用标点符号悬挂，0表示不启用标点符号悬挂。 |

## NODE_TEXT_TAIL_INDENTS

```c
NODE_TEXT_TAIL_INDENTS = 1056
```

定义文本块中每行的尾部缩进。适用于实现特殊排版效果，如诗歌排版、引用文本对齐等需要控制每行尾部空间。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[i].f32 | 表示第i行文本的尾部缩进值，单位为vp。取值范围：[0, +∞)，传入负数时按默认值0处理。当.size大小为1时，所有行共享相同的尾部缩进.value[0].f32；当.size大于1时，第i行使用.value[i].f32；当文本行数超过.size，则超出部分复用.value[.size - 1].f32。 |
| .size | 表示有效缩进值的数量，即 .value 数组中实际使用的元素个数。取值范围：正整数（大于0）。传入0或负数时参数不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[i].f32 | 第i个尾部缩进值，单位为vp。 |
| .size | 表示有效缩进值的数量，即.value数组中实际使用的元素个数。 |

## NODE_SPAN_CONTENT

```c
NODE_SPAN_CONTENT = MAX_NODE_SCOPE_NUM * ARKUI_NODE_SPAN = 2000
```

文本内容属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 表示[span](arkui-ts/ts-basic-components-span.md)的文本内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 表示span的文本内容。 |

## NODE_SPAN_TEXT_BACKGROUND_STYLE

```c
NODE_SPAN_TEXT_BACKGROUND_STYLE = 2001
```

文本背景色属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 表示文本背景颜色，0xargb格式，形如0xFFFF0000表示红色。 |
| .value[1].f32 | 文本背景圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时参数不生效。支持两种设置方式：<br>1）仅设置.value[1].f32，未设置.value[2].f32~.value[4].f32时，表示四个方向的圆角半径统一设置；<br>2）设置了.value[2].f32~.value[4].f32中任意项时，.value[1].f32仅表示左上角圆角半径。 |
| .value[2].f32 | 设置右上角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时参数不生效。 |
| .value[3].f32 | 设置左下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时参数不生效。 |
| .value[4].f32 | 设置右下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时参数不生效。 |
**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 文本背景颜色，0xargb格式。 |
| .value[1].f32 | 左上角圆角半径，单位为vp。 |
| .value[2].f32 | 右上角圆角半径，单位为vp。 |
| .value[3].f32 | 左下角圆角半径，单位为vp。 |
| .value[4].f32 | 右下角圆角半径，单位为vp。 |

## NODE_SPAN_BASELINE_OFFSET

```c
NODE_SPAN_BASELINE_OFFSET = 2002
```

文本基线的偏移量属性，支持属性设置、属性重置和属性获取接口。适用于调整Span文本的基线位置，如显示上下标、或实现特殊排版效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。 |

## NODE_SPAN_FONT

```c
NODE_SPAN_FONT = 2003
```

定义文本样式属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string? | 字体列表，多个字体使用`,`进行分隔。可选。 |
| .value[0].f32 | 文本尺寸，单位为fp。取值范围：[0, +∞)。 |
| .value[1]?.i32 | 文本的字体粗细。可选。取值为`[100, 900]`，默认为`400`。取值越大，字体越粗。 |
| .value[2]?.i32 | 字体样式。可选。参数类型为[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。默认值为`ARKUI_FONT_STYLE_NORMAL`。 |
| .object? | 字体配置。可选，不设置时使用系统默认配置。参数类型为[OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 字体列表，多个字体使用`,`进行分隔。 |
| .value[0].f32 | 文本尺寸，单位为fp。取值范围：[0, +∞)。 |
| .value[1].i32 | 文本的字体粗细，无单位。取值越大，字体越粗。 |
| .value[2].i32 | 字体样式。参数类型为[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)。 |
| .object | 字体配置。参数类型为[OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md)。 |

## NODE_SPAN_FONT_WEIGHT

```c
NODE_SPAN_FONT_WEIGHT = 2004
```

定义文本字体粗细属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 文本的字体粗细。取值为`[100, 900]`，默认为`400`。取值越大，字体越粗。超出范围时按默认值400处理。 |
| .object? | 可选，文本字体粗细配置，不设置时使用默认字体粗细配置。参数类型为[OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 文本字体粗细，无单位。取值越大，字体越粗。 |
| .object | 文本字体粗细配置。参数类型为[OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)。 |

## NODE_IMAGE_SPAN_SRC

```c
NODE_IMAGE_SPAN_SRC = MAX_NODE_SCOPE_NUM * ARKUI_NODE_IMAGE_SPAN = 3000
```

imageSpan组件图片地址属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 表示imageSpan的图片地址。 |
| .object | 表示 PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)。<br>.object参数和.string参数二选一，不可同时设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 表示imageSpan的图片地址。 |
| .object | 表示 PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)。 |

## NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT

```c
NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT = 3001
```

图片基于文本的对齐方式属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment)枚举值。默认值为ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM，图片下边沿与文本下边沿对齐。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment)枚举值。 |

## NODE_IMAGE_SPAN_ALT

```c
NODE_IMAGE_SPAN_ALT = 3002
```

imageSpan组件占位图地址属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 表示imageSpan组件占位图地址（不支持gif类型图源）。 |
| .object | 表示 PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)；<br>.object参数和.string参数二选一，不可同时设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 表示imageSpan组件占位图地址。 |
| .object | 表示 PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)。 |

## NODE_IMAGE_SPAN_BASELINE_OFFSET

```c
NODE_IMAGE_SPAN_BASELINE_OFFSET = 3003
```

imageSpan组件的基线偏移量属性，支持属性设置、属性重置和属性获取接口。偏移量数值为正数时向上偏移，负数时向下偏移，默认值0，单位为fp。适用于图文混排时调整图片与文本的相对位置，实现精确的排版对齐效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。取值范围：(-∞, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 偏移量数值，单位为fp。 |

## NODE_IMAGE_SPAN_COLOR_FILTER

```c
NODE_IMAGE_SPAN_COLOR_FILTER = 3004
```

图片滤镜效果属性，支持属性设置、属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 ~ .value[19].f32 | 表示5x4颜色滤镜矩阵数组，共20个浮点数元素，按行优先顺序排列。矩阵前4列分别对应红（R）、绿（G）、蓝（B）、透明度（A）通道的颜色变换系数，第5列为各通道的偏移量。用于对图片进行颜色变换处理，如亮度、对比度、色调调整等。 |
| .size | 表示滤镜数组大小为5x4。 |
| .object | 颜色滤波器指针，参数类型为[OH_Drawing_ColorFilter](../apis-arkgraphics2d/capi-drawing-oh-drawing-colorfilter.md)。<br>.object和.size参数只能二选一，不可同时设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 ~ .value[19].f32 | 表示滤镜矩阵数组。 |
| .size | 表示滤镜数组大小为5x4。 |
| .object | 颜色滤波器指针，参数类型为[OH_Drawing_ColorFilter](../apis-arkgraphics2d/capi-drawing-oh-drawing-colorfilter.md)。 |

## NODE_IMAGE_SPAN_SUPPORT_SVG2

```c
NODE_IMAGE_SPAN_SUPPORT_SVG2 = 3005
```

通过启用SVG新解析能力开关设置SVG解析功能支持的范围，支持属性设置、属性重置和属性获取接口。ImageSpan组件创建后，不支持动态修改该属性的值。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用SVG新解析能力开关。1表示支持SVG解析新能力；0表示保持原有SVG解析能力。<br>默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用SVG新解析能力开关。1表示支持SVG解析新能力，0表示保持原有SVG解析能力。 |
