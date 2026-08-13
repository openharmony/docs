# ArkUI_NodeAttributeType（通用属性）
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

定义ArkUI在Native侧可以设置的通用属性样式集合。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## NODE_WIDTH

```c
NODE_WIDTH = 0
```

宽度属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 宽度数值，单位为vp，用于设置组件的宽度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 宽度数值，单位为vp。 |

## NODE_HEIGHT

```c
NODE_HEIGHT = 1
```

高度属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 高度数值，单位为vp，用于设置组件的高度。不支持负数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 高度数值，单位为vp。 |

## NODE_BACKGROUND_COLOR

```c
NODE_BACKGROUND_COLOR = 2
```

背景色属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式，形如 0xFFFF0000 表示红色。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 背景色数值，0xARGB格式，形如 0xFFFF0000 表示红色。 |

## NODE_BACKGROUND_IMAGE

```c
NODE_BACKGROUND_IMAGE = 3
```

背景图片属性，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 图片地址。API version 22及之前版本，支持网络图片资源地址、本地图片资源地址、Base64和[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)资源，不支持[svg](arkui-js/js-components-svg.md)图片、gif和webp等类型的动图。 从API version 23开始，新增支持webp和gif类型的动图，显示动图第一帧，不支持其他类型的动图。 |
| .value[0]?.i32 | 可选值，repeat参数，类型为[ArkUI_ImageRepeat](capi-image-h.md#arkui_imagerepeat)，默认值为ARKUI_IMAGE_REPEAT_NONE。 |
| .object | PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)。<br>.object参数和.string参数二选一，不可同时设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 图片地址。API version 22及之前版本，支持网络图片资源地址、本地图片资源地址、Base64和[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)资源，不支持svg图片、gif和webp等类型的动图。 从API version 23开始，新增支持webp和gif类型的动图，显示动图第一帧，不支持其他类型的动图。 |
| .value[0].i32 | repeat参数，类型为[ArkUI_ImageRepeat](capi-image-h.md#arkui_imagerepeat)。 |
| .object | PixelMap 图片数据，参数类型为[ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)。 |
