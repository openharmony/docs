# OH_ArkUI_ImageAttachment
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_ImageAttachment OH_ArkUI_ImageAttachment
```

## 概述

定义图片对象，用于在属性字符串中嵌入图片内容。图片作为属性字符串的组成部分，通过设置图片源及样式属性后，可附加到属性字符串中实现图文混排。<br>调用[OH_ArkUI_ImageAttachment_Create](capi-styled-string-h.md#oh_arkui_imageattachment_create)接口创建图片样式对象。<br>调用[OH_ArkUI_ImageAttachment_Destroy](capi-styled-string-h.md#oh_arkui_imageattachment_destroy)接口销毁图片样式对象。<br>对象创建后，调用OH_ArkUI_ImageAttachment_SetXXX系列接口设置样式属性。例如调用[OH_ArkUI_ImageAttachment_SetPixelMap](capi-styled-string-h.md#oh_arkui_imageattachment_setpixelmap)设置图片源。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)