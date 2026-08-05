# ArkUI_NodeAttributeType（无障碍相关属性）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的无障碍相关属性集合，包含无障碍文本、说明、模式、状态、值等属性设置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_ACCESSIBILITY_GROUP

```c
NODE_ACCESSIBILITY_GROUP = 62
```

无障碍组属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 为1时表示该组件及其所有子组件为一整个可以选中的组件，无障碍服务将不再关注其子组件内容；为0时表示子组件各自独立可被选中，无障碍服务将分别关注其各子组件内容。参数取值为1或0，传入非法值时该设置不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 为1时表示该组件及其所有子组件合并为一个可被无障碍服务整体聚焦的组件，无障碍服务将不再单独关注其子组件内容；为0时表示不启用无障碍分组，各子组件可被无障碍服务单独关注。参数取值为1或0。 |

## NODE_ACCESSIBILITY_TEXT

```c
NODE_ACCESSIBILITY_TEXT = 63
```

无障碍文本属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 无障碍文本，无长度限制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 组件的无障碍文本内容，用于在无障碍服务中朗读或展示该组件的文本描述。 |

## NODE_ACCESSIBILITY_MODE

```c
NODE_ACCESSIBILITY_MODE = 64
```

无障碍辅助服务模式，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 辅助服务模式，参数类型为[ArkUI_AccessibilityMode](capi-native-type-h.md#arkui_accessibilitymode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 辅助服务模式，参数类型[ArkUI_AccessibilityMode](capi-native-type-h.md#arkui_accessibilitymode)。 |

## NODE_ACCESSIBILITY_DESCRIPTION

```c
NODE_ACCESSIBILITY_DESCRIPTION = 65
```

无障碍说明属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 无障碍说明，无长度限制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 组件的无障碍说明内容，用于向无障碍服务补充描述该组件的详细用途或操作指引。 |

## NODE_ACCESSIBILITY_ID

```c
NODE_ACCESSIBILITY_ID = 87
```

无障碍自定义标识ID，支持属性获取。<br>
作为属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 无障碍自定义标识ID。 |

## NODE_ACCESSIBILITY_ACTIONS

```c
NODE_ACCESSIBILITY_ACTIONS = 88
```

无障碍操作类型属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 配置无障碍操作类型，参数类型[ArkUI_AccessibilityActionType](capi-native-type-h.md#arkui_accessibilityactiontype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 配置无障碍操作类型，参数类型[ArkUI_AccessibilityActionType](capi-native-type-h.md#arkui_accessibilityactiontype)。 |

## NODE_ACCESSIBILITY_ROLE

```c
NODE_ACCESSIBILITY_ROLE = 89
```

定义无障碍角色属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 无障碍角色，参数类型[ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 无障碍组件类型，参数类型[ArkUI_NodeType](capi-native-node-h.md#arkui_nodetype)。 |

## NODE_ACCESSIBILITY_STATE

```c
NODE_ACCESSIBILITY_STATE = 90
```

定义无障碍状态属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 无障碍状态信息，参数类型[ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 返回值类型为[ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)。 |

## NODE_ACCESSIBILITY_VALUE

```c
NODE_ACCESSIBILITY_VALUE = 91
```

定义无障碍值属性，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 无障碍值信息，参数类型为[ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 返回值类型为[ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)。 |
