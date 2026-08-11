# ArkUI_NodeAttributeType（布局类组件相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的布局类组件相关属性集合，支持Stack、Column、Row、Flex、RelativeContainer等容器组件的布局属性配置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_STACK_ALIGN_CONTENT

```c
NODE_STACK_ALIGN_CONTENT = MAX_NODE_SCOPE_NUM * ARKUI_NODE_STACK = 1000000
```

设置子组件在容器内的对齐方式，支持属性设置，属性重置和属性获取接口。该属性与通用属性NODE_ALIGNMENT（用于设置子组件在容器内的对齐方式）同时设置时，后设置的属性生效。适用于在Stack容器中需要控制子组件对齐位置时使用，如将子组件居中、左上角、右下角等对齐，解决Stack容器内子组件默认对齐方式不满足需求的问题，提供灵活的子组件对齐控制能力，满足各种布局需求。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 对齐方式，数据类型[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)。可选取值包括TOP（顶部对齐）、BOTTOM（底部对齐）、LEFT（左侧对齐）、RIGHT（右侧对齐）、TOP_START（左上角对齐）、TOP_END（右上角对齐）、BOTTOM_START（左下角对齐）、BOTTOM_END（右下角对齐）、CENTER（居中对齐）、START（起始端对齐）、END（结束端对齐）。具体枚举值与数字对应关系请参考[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)定义。当需要子组件在容器内的特定位置对齐时选择相应的对齐方式。默认值：ARKUI_ALIGNMENT_CENTER（居中对齐）。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 对齐方式的枚举值，数据类型[ArkUI_Alignment](capi-layout-h.md#arkui_alignment)。具体取值及含义参见参数说明。 |

## NODE_COLUMN_ALIGN_ITEMS

```c
NODE_COLUMN_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM * ARKUI_NODE_COLUMN = 1006000
```

设置Column子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。适用于在Column容器中需要控制子组件水平对齐方式时使用，如左对齐、居中对齐、右对齐等，解决Column容器内子组件默认水平对齐方式不满足需求的问题，提供灵活的子组件水平对齐控制能力，满足各种垂直布局场景的需求。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 子组件在水平方向上的对齐格式，数据类型[ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）。具体枚举值与数字对应关系请参考[ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment)定义。当需要子组件在Column容器内水平方向特定位置对齐时选择相应的对齐格式。默认值：ARKUI_HORIZONTAL_ALIGNMENT_CENTER（居中对齐）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在水平方向上的对齐格式的枚举值，数据类型[ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment)。具体取值及含义参见参数说明。 |

## NODE_COLUMN_JUSTIFY_CONTENT

```c
NODE_COLUMN_JUSTIFY_CONTENT = 1006001
```

设置Column子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。适用于在Column容器中需要控制子组件垂直分布方式时使用，如顶部对齐、底部对齐、居中分布、两端对齐等，解决Column容器内子组件默认垂直对齐方式不满足需求的问题，提供灵活的子组件垂直对齐控制能力，实现多样化的垂直布局效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 子组件在垂直方向上的对齐格式，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）、SPACE_BETWEEN（两端对齐）、SPACE_AROUND（环绕对齐）、SPACE_EVENLY（均匀对齐）。具体枚举值与数字对应关系请参考[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)定义。当需要子元素在Column容器内垂直方向特定分布方式时选择相应的对齐格式。默认值：ARKUI_FLEX_ALIGNMENT_START（起始端对齐）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在垂直方向上的对齐格式的枚举值，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。具体取值及含义参见参数说明。 |

## NODE_LINEAR_LAYOUT_SPACE

```c
NODE_LINEAR_LAYOUT_SPACE = 1006002
```

设置Column或Row子组件的间距，支持属性设置，属性重置和属性获取接口。适用于在Column或Row容器中需要控制子组件之间的间距时使用，如卡片列表项之间的间距、按钮之间的间距等，解决Column或Row容器内子组件间距需要统一控制的问题，提供便捷的子组件间距设置方式，避免为每个子组件单独设置margin，简化开发。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 子组件之间的间距，单位：vp，默认值：0。<br>取值范围：`[0, +∞)`。当需要为Column或Row容器的子组件之间添加间隔时设置此参数，设置为0表示无间距。<br>设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 子组件之间的间距，单位：vp。 |

## NODE_LINEAR_LAYOUT_REVERSE

```c
NODE_LINEAR_LAYOUT_REVERSE = 1006003
```

设置Column或Row中沿主轴方向的子组件排列是否反向，支持属性设置，属性重置和属性获取接口。适用于在Column或Row容器中需要反转子组件排列顺序时使用，如聊天消息列表（最新消息在底部）、倒序显示列表项等，解决Column或Row容器内子组件需要反向排列的问题，无需修改数据源顺序即可实现反向排列效果，简化开发逻辑。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 主轴方向的子组件排列是否反向，默认值：0（false）。值为非零整数时，子组件沿主轴方向反转排列（适用于从右到左或从下到上的布局需求）；值为0时，子组件沿主轴方向正序排列（适用于常规布局）。当需要实现反向排列效果（如列表倒序显示）时设置为非零值，否则设置为0。<br>设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 主轴方向的子组件排列是否反向。返回非零值表示反向排列，返回0表示正序排列。 |

## NODE_ROW_ALIGN_ITEMS

```c
NODE_ROW_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM * ARKUI_NODE_ROW = 1007000
```

设置Row子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。适用于在Row容器中需要控制子组件垂直对齐方式时使用，如顶部对齐、居中对齐、底部对齐等，解决Row容器内子组件默认垂直对齐方式不满足需求的问题，提供灵活的子组件垂直对齐控制能力，满足各种水平布局场景的需求。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 子组件在垂直方向上的对齐格式，数据类型[ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment)。可选取值包括TOP（顶部对齐）、CENTER（居中对齐）、BOTTOM（底部对齐）。具体枚举值与数字对应关系请参考[ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment)定义。当需要子组件在Row容器内垂直方向特定位置对齐时选择相应的对齐格式。默认值：ARKUI_VERTICAL_ALIGNMENT_CENTER（居中对齐）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在垂直方向上的对齐格式的枚举值，数据类型[ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment)。具体取值及含义参见参数说明。 |

## NODE_ROW_JUSTIFY_CONTENT

```c
NODE_ROW_JUSTIFY_CONTENT = 1007001
```

设置Row子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。适用于在Row容器中需要控制子组件水平分布方式时使用，如左对齐、右对齐、居中分布、两端对齐等，解决Row容器内子组件默认水平对齐方式不满足需求的问题，提供灵活的子组件水平对齐控制能力，实现多样化的水平布局效果。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 子组件在水平方向上的对齐格式，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）、SPACE_BETWEEN（两端对齐）、SPACE_AROUND（环绕对齐）、SPACE_EVENLY（均匀对齐）。具体枚举值与数字对应关系请参考[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)定义。当需要子元素在Row容器内水平方向特定分布方式时选择相应的对齐格式。默认值：ARKUI_FLEX_ALIGNMENT_START（起始端对齐）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在水平方向上的对齐格式的枚举值，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。具体取值及含义参见参数说明。 |

## NODE_FLEX_OPTION

```c
NODE_FLEX_OPTION = MAX_NODE_SCOPE_NUM * ARKUI_NODE_FLEX = 1008000
```

设置Flex属性，支持属性设置，属性重置和属性获取接口。适用于在Flex容器中需要灵活配置子组件排列方向、换行方式、对齐方式时使用，如响应式布局、自适应布局等复杂布局场景，解决Flex容器需要统一配置多个布局参数的问题，提供一次调用即可设置Flex容器的多个布局参数，简化开发流程，提高代码可维护性。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为5。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.i32 | 子组件在Flex容器上排列的方向[ArkUI_FlexDirection](capi-layout-h.md#arkui_flexdirection)。可选取值包括ROW（水平方向从左到右排列）、ROW_REVERSE（水平方向从右到左排列）、COLUMN（垂直方向从上到下排列）、COLUMN_REVERSE（垂直方向从下到上排列）。具体枚举值与数字对应关系请参考[ArkUI_FlexDirection](capi-layout-h.md#arkui_flexdirection)定义。当需要实现水平布局时选择ROW或ROW_REVERSE，需要实现垂直布局时选择COLUMN或COLUMN_REVERSE。默认值为ARKUI_FLEX_DIRECTION_ROW（水平方向从左到右排列）。设置异常值时，按默认值显示。 |
| .value[1]?.i32 | 排列规则[ArkUI_FlexWrap](capi-layout-h.md#arkui_flexwrap)。可选取值包括NO_WRAP（不换行，子元素超出容器时压缩显示）、WRAP（正向换行，子元素超出容器时自动换行）、WRAP_REVERSE（反向换行，换行方向与正向相反）。具体枚举值与数字对应关系请参考[ArkUI_FlexWrap](capi-layout-h.md#arkui_flexwrap)定义。当需要子元素在单行/单列显示时选择NO_WRAP，需要自动换行显示时选择WRAP或WRAP_REVERSE。默认值为ARKUI_FLEX_WRAP_NO_WRAP（不换行）。设置异常值时，按默认值显示。 |
| .value[2]?.i32 | 主轴上的对齐格式[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）、SPACE_BETWEEN（两端对齐，元素间间距相等）、SPACE_AROUND（环绕对齐，元素两侧间距相等）、SPACE_EVENLY（均匀对齐，元素间及两端间距相等）。具体枚举值与数字对应关系请参考[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)定义。当需要子元素在主轴上特定分布方式时选择相应的对齐格式。默认值为ARKUI_FLEX_ALIGNMENT_START（起始端对齐）。设置异常值时，按默认值显示。 |
| .value[3]?.i32 | 交叉轴上的对齐格式[ArkUI_ItemAlignment](capi-layout-h.md#arkui_itemalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）、STRETCH（拉伸填充）、BASELINE（基线对齐）。具体枚举值与数字对应关系请参考[ArkUI_ItemAlignment](capi-layout-h.md#arkui_itemalignment)定义。当需要子元素在交叉轴上特定对齐方式时选择相应的对齐格式。默认值为ARKUI_ITEM_ALIGNMENT_START（起始端对齐）。设置异常值时，按默认值显示。 |
| .value[4]?.i32 | 交叉轴中有额外的空间时，多行内容的对齐方式[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。可选取值包括START（起始端对齐）、CENTER（居中对齐）、END（结束端对齐）、SPACE_BETWEEN（两端对齐，行间距相等）、SPACE_AROUND（环绕对齐，行两侧间距相等）、SPACE_EVENLY（均匀对齐，行间及两端间距相等）。具体枚举值与数字对应关系请参考[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)定义。当Flex容器换行时，需要控制多行在交叉轴上的分布方式时选择相应的对齐格式。默认值为ARKUI_FLEX_ALIGNMENT_START（起始端对齐）。设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 子组件在Flex容器上排列的方向的枚举值，数据类型[ArkUI_FlexDirection](capi-layout-h.md#arkui_flexdirection)。具体取值及含义参见参数说明。 |
| .value[1].i32 | 排列规则的枚举值，数据类型[ArkUI_FlexWrap](capi-layout-h.md#arkui_flexwrap)。具体取值及含义参见参数说明。 |
| .value[2].i32 | 主轴上的对齐格式的枚举值，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。具体取值及含义参见参数说明。 |
| .value[3].i32 | 交叉轴上的对齐格式的枚举值，数据类型[ArkUI_ItemAlignment](capi-layout-h.md#arkui_itemalignment)。具体取值及含义参见参数说明。 |
| .value[4].i32 | 交叉轴中有额外的空间时，多行内容的对齐方式的枚举值，数据类型[ArkUI_FlexAlignment](capi-layout-h.md#arkui_flexalignment)。具体取值及含义参见参数说明。 |

## NODE_FLEX_SPACE

```c
NODE_FLEX_SPACE = 1008001
```

设置Flex容器内子组件的间距，支持属性设置，属性重置和属性获取接口。适用于在Flex容器中需要分别控制主轴和交叉轴方向的子组件间距时使用，如网格布局中行间距和列间距需要分别设置，解决Flex容器内子组件在主轴和交叉轴方向需要不同间距的问题，提供灵活的双向间距控制能力，实现更精细的布局效果，避免为每个子组件单独设置margin。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>
属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)中size为无效值，实际返回的value数组长度恒为5。<br>

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | Flex容器主轴方向的间距，单位：vp，默认值：0。<br>取值范围：`[0, +∞)`。当需要为Flex容器内的子元素在主轴方向添加间距时设置此参数，设置为0表示无间距。<br>设置异常值时，按默认值显示。 |
| .value[1].f32 | Flex容器交叉轴方向的间距，单位：vp，默认值：0。<br>取值范围：`[0, +∞)`。当Flex容器换行时，需要为不同行之间在交叉轴方向添加间距时设置此参数，设置为0表示无间距。<br>设置异常值时，按默认值显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | Flex容器主轴方向的间距，单位：vp。 |
| .value[1].f32 | Flex容器交叉轴方向的间距，单位：vp。 |

## NODE_RELATIVE_CONTAINER_GUIDE_LINE

```c
NODE_RELATIVE_CONTAINER_GUIDE_LINE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_RELATIVE_CONTAINER = 1012000
```

设置RelativeContainer容器内的辅助线，支持属性设置，属性重置和属性获取接口。适用于在RelativeContainer容器中需要基于辅助线对齐子组件时使用，如创建水平或垂直的参考线用于子组件定位，解决RelativeContainer容器内子组件需要基于特定参考线进行精确定位的问题，提供辅助线能力，简化RelativeContainer布局中对齐逻辑，提高布局的精确性和可维护性。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | RelativeContainer容器内的辅助线，用于辅助子组件定位，参数类型为[ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)。当需要在RelativeContainer中定义辅助定位线，用于子组件相对辅助线定位时设置此参数。不传入时不设置辅助线。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | RelativeContainer容器内的辅助线，参数类型为[ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)。未设置辅助线时，获取接口返回NULL。 |

## NODE_RELATIVE_CONTAINER_BARRIER

```c
NODE_RELATIVE_CONTAINER_BARRIER = 1012001
```

设置RelativeContainer容器内的屏障，支持属性设置，属性重置和属性获取接口。适用于在RelativeContainer容器中需要创建屏障约束子组件位置时使用，如确保某个组件始终位于其他组件的左侧或右侧，解决RelativeContainer容器内需要基于其他组件位置创建动态约束边界的问题，提供屏障能力，实现更灵活的相对布局约束，满足复杂的界面布局需求。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | RelativeContainer容器内的屏障，用于约束子组件的布局边界，参数类型为[ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)。当需要在RelativeContainer中定义屏障，用于约束子组件的布局边界时设置此参数。不传入时不设置屏障。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | RelativeContainer容器内的屏障，参数类型为[ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)。未设置屏障时，获取接口返回NULL。 |
