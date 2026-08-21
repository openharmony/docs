# ArkUI_NodeAttributeType（EmbeddedComponent组件相关属性）
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

定义ArkUI在Native侧可以设置的EmbeddedComponent组件相关属性样式集合，支持配置启动EmbeddedAbility的want参数以及控制嵌入式Ability的UI显示行为等运行选项，适用于需要在Native侧对嵌入式组件进行属性设置的场景。EmbeddedComponent适用于需要在当前应用页面内嵌入其他Ability（如系统设置、地图等）提供的UI页面的场景。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_EMBEDDED_COMPONENT_WANT

```c
NODE_EMBEDDED_COMPONENT_WANT = MAX_NODE_SCOPE_NUM * ARKUI_NODE_EMBEDDED_COMPONENT = 1016000
```

定义用于启动嵌入式Ability的want参数。支持属性设置。使用场景：当应用需要在当前页面嵌入指定Ability（如嵌入系统设置页面、嵌入地图组件等）时，通过该属性指定目标Ability。<br>
作为属性设置方法参数时，[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | EmbeddedComponent的want参数，用于指定启动EmbeddedAbility所需的目标信息。参数类型为[AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md)。默认值为nullptr。 |

## NODE_EMBEDDED_COMPONENT_OPTION

```c
NODE_EMBEDDED_COMPONENT_OPTION = 1016001
```

定义EmbeddedComponent的运行选项，用于控制EmbeddedAbility的UI显示行为。支持属性设置。<br>
作为属性设置方法参数时，[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | EmbeddedComponent的选项列表。参数类型为[ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)。默认值为nullptr。 |
