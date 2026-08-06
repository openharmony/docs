# OH_ArkUI_ParagraphStyle
 <!--Kit: ArkUI-->
 <!--Subsystem: ArkUI-->
 <!--Owner: @carnivore233-->
 <!--Designer: @carnivore233-->
 <!--Tester: @mateng_Holtens-->
 <!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_ParagraphStyle OH_ArkUI_ParagraphStyle
```

## 概述

定义段落样式，用于在构建富文本段落时统一设置文本对齐、换行、截断等排版行为，适用于需要对段落进行精细化排版控制的场景，例如在富文本编辑器中设置段落对齐方式、在新闻阅读应用中控制长文本的换行与截断显示等。<br>调用[OH_ArkUI_ParagraphStyle_Create](capi-styled-string-h.md#oh_arkui_paragraphstyle_create)接口创建对应的段落样式对象。<br>调用[OH_ArkUI_ParagraphStyle_Destroy](capi-styled-string-h.md#oh_arkui_paragraphstyle_destroy)接口销毁段落样式对象。<br>对象创建后，调用OH_ArkUI_ParagraphStyle_SetXXX系列接口设置具体样式。例如，调用[OH_ArkUI_ParagraphStyle_SetTextAlign](capi-styled-string-h.md#oh_arkui_paragraphstyle_settextalign)设置文本对齐方式。若创建对象失败（返回空指针）或对象已销毁，调用SetXXX系列接口将不会生效。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [styled_string.h](capi-styled-string-h.md)