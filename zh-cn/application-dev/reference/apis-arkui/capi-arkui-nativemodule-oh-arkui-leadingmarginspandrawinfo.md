# OH_ArkUI_LeadingMarginSpanDrawInfo
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_LeadingMarginSpanDrawInfo OH_ArkUI_LeadingMarginSpanDrawInfo
```

## 概述

定义段首缩进的自定义绘制信息，包含当前行的绘制上下文信息（如绘制区域、偏移量等），开发者可在回调函数中基于该信息实现自定义的段首缩进绘制逻辑，适用于需要在段落首行添加自定义图标、装饰元素或实现特殊缩进样式等场景，使段落排版更加灵活丰富。例如，在阅读应用中为段落首行绘制书签图标，或在文档编辑器中为特定段落绘制自定义缩进标记。<br>调用[OH_ArkUI_LeadingMarginSpanDrawInfo_Create](capi-styled-string-h.md#oh_arkui_leadingmarginspandrawinfo_create)接口创建对应的段首缩进的自定义绘制信息对象。<br>调用[OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy](capi-styled-string-h.md#oh_arkui_leadingmarginspandrawinfo_destroy)接口销毁该对象。<br>该对象用于在[OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback](capi-styled-string-h.md#oh_arkui_paragraphstyle_registerondrawleadingmargincallback)注册的回调函数中，提供当前行的绘制上下文和自定义绘制信息对象。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)