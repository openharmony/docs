# ArkUI_NodeAttributeType（XComponent组件相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置或获取的XComponent组件相关属性集合。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_XCOMPONENT_ID

```c
NODE_XCOMPONENT_ID = MAX_NODE_SCOPE_NUM * ARKUI_NODE_XCOMPONENT = 12000
```

XComponent组件的ID，支持属性设置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | XComponent组件的ID内容，用于唯一标识该组件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | XComponent组件的ID内容，用于唯一标识该组件。 |

## NODE_XCOMPONENT_TYPE

```c
NODE_XCOMPONENT_TYPE = 12001
```

XComponent组件的类型，仅支持属性获取接口。<br>
XComponent组件的类型需要在组件创建时通过[ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype)中的`ARKUI_NODE_XCOMPONENT`或者`ARKUI_NODE_XCOMPONENT_TEXTURE`明确，不允许后续修改。<br>
使用[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)接口尝试修改XComponent组件的类型时会发生绘制内容异常。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | XComponent组件的类型，参数类型为[ArkUI_XComponentType](capi-xcomponent-h.md#arkui_xcomponenttype)，具体枚举值及其与数字的对应关系请参见该枚举定义。 |

## NODE_XCOMPONENT_SURFACE_SIZE

```c
NODE_XCOMPONENT_SURFACE_SIZE = 12002
```

XComponent组件所持有的Surface的宽高，仅支持属性获取接口。<br>
使用[setAttribute](capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute)接口尝试修改Surface的宽高时，该设置不会生效。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 宽度数值，单位为px。 |
| .value[1].u32 | 高度数值，单位为px。 |

## NODE_XCOMPONENT_SURFACE_RECT

```c
NODE_XCOMPONENT_SURFACE_RECT = 12003
```

XComponent组件所持有的Surface显示区域，支持属性设置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | Surface显示区域相对于XComponent组件左上角的x轴坐标，单位为px。 |
| .value[1].i32 | Surface显示区域相对于XComponent组件左上角的y轴坐标，单位为px。 |
| .value[2].i32 | Surface显示区域的宽度，单位为px，取值必须为正整数。传入0或负数时设置不生效。 |
| .value[3].i32 | Surface显示区域的高度，单位为px，取值必须为正整数。传入0或负数时设置不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | Surface显示区域相对于XComponent组件左上角的x轴坐标，单位为px。 |
| .value[1].i32 | Surface显示区域相对于XComponent组件左上角的y轴坐标，单位为px。 |
| .value[2].i32 | Surface显示区域的宽度，单位为px，取值应为非负整数。 |
| .value[3].i32 | Surface显示区域的高度，单位为px。 |

## NODE_XCOMPONENT_ENABLE_ANALYZER

```c
NODE_XCOMPONENT_ENABLE_ANALYZER = 12004
```

XComponent组件是否支持图像分析的属性，支持属性设置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否支持图像分析，`1`表示支持图像分析，`0`表示不支持图像分析，默认值：`0`。传入非0和非1的值时按`0`处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否支持图像分析，`1`表示支持图像分析，`0`表示不支持图像分析。 |
