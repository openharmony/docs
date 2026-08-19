# ArkUI_NodeAttributeType（其他）
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置的其他属性样式集合，包含组件交互、获焦、离屏渲染和点击距离等属性设置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_ENABLED

```c
NODE_ENABLED = 6
```

设置组件是否可交互，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 0表示不可交互，1表示可交互。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 返回值为0表示不可交互，返回值为1表示可交互。 |

## NODE_FOCUSABLE

```c
NODE_FOCUSABLE = 39
```

设置组件是否可获焦，支持属性设置、属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 取值为0或1，参数值为1表示可获焦，为0表示不可获焦。默认为不可获焦。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 返回值为1表示可获焦，为0表示不可获焦。 |

## NODE_RENDER_GROUP

```c
NODE_RENDER_GROUP = 80
```

设置当前组件和子组件是否先整体离屏渲染绘制后再与父控件融合绘制，支持属性设置，属性重置和属性获取。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 参数值为1表示当前组件与子组件需要先整体离屏渲染绘制后再与父控件融合绘制，参数值为0表示不需要整体离屏渲染绘制后再与父控件融合绘制。默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 返回值为1表示当前组件与子组件完成整体离屏渲染绘制，返回值为0表示当前组件与子组件未完成整体离屏渲染绘制。 |

## NODE_CLICK_DISTANCE

```c
NODE_CLICK_DISTANCE = 97
```

设置组件点击手势的移动距离限制，支持属性设置。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 表示识别点击手势时允许手指在设定的距离阈值内移动，取值范围为[0, +∞)，单位为vp。 |

## NODE_ALLOW_FORCE_DARK

```c
NODE_ALLOW_FORCE_DARK = 108
```

设置组件是否启用反色能力，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 反色能力；参数取值为0或1，取值为0表示不启用反色能力，取值为1表示启用反色能力。 |
