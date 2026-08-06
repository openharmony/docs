# OH_ArkUI_UrlStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_UrlStyle OH_ArkUI_UrlStyle
```

## 概述

定义链接样式，用于为属性字符串中的文本设置可点击的URL链接效果，适用于需要在文本内容中嵌入可交互链接的场景，可提升文本的交互性和用户体验。<br>调用[OH_ArkUI_UrlStyle_Create](capi-styled-string-h.md#oh_arkui_urlstyle_create)接口创建链接样式对象。<br>调用[OH_ArkUI_UrlStyle_Destroy](capi-styled-string-h.md#oh_arkui_urlstyle_destroy)接口销毁链接样式对象。<br>创建链接样式对象后，调用[OH_ArkUI_UrlStyle_SetUrl](capi-styled-string-h.md#oh_arkui_urlstyle_seturl)接口设置链接地址。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)