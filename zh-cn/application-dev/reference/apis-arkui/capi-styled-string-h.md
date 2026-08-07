# styled_string.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

在Native侧定义[ArkUI_NodeType](../apis-arkui/capi-native-node-h.md#arkui_nodetype)为ARKUI_NODE_TEXT的组件的文本样式和文本布局管理器。提供丰富的文本样式设置能力，包括字体样式（字体颜色、大小、粗细、风格）、文本装饰线、文本阴影、基线偏移、字符间距、行高、行间距等；支持图片、超链接、自定义绘制等特殊内容嵌入；提供段落级别的布局管理，包括对齐方式、缩进、段落间距等；支持文本手势交互能力，如点击、长按、触摸事件。适用于需要丰富文本样式展示、复杂文本布局、图文混排、文本交互等场景。

**引用文件：** <arkui/styled_string.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[StyledStringSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/StyledStringSample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md) | ArkUI_StyledString | 定义文本组件支持的样式化字符串数据对象，支持为文本内容设置多种样式属性，适用于需要在Native侧构建和管理富文本展示的场景。 |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md) | OH_ArkUI_SpanStyle | 定义属性字符串样式对象。 <br> 可以通过[OH_ArkUI_SpanStyle_Create](#oh_arkui_spanstyle_create)接口创建对应的属性字符串样式对象。 <br> 可以通过[OH_ArkUI_SpanStyle_Destroy](#oh_arkui_spanstyle_destroy)接口销毁属性字符串样式对象。 <br> 对象创建后通过[OH_ArkUI_SpanStyle_SetStart](#oh_arkui_spanstyle_setstart)和[OH_ArkUI_SpanStyle_SetLength](#oh_arkui_spanstyle_setlength)指定样式作用的范围。 <br> 对象创建后通过OH_ArkUI_SpanStyle_SetXXXStyle系列接口设置生效的具体样式，例如通过[OH_ArkUI_SpanStyle_SetTextStyle](#oh_arkui_spanstyle_settextstyle)设置字体样式效果。 |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md) | OH_ArkUI_ImageAttachment | 定义图片样式对象。 <br> 可以通过[OH_ArkUI_ImageAttachment_Create](#oh_arkui_imageattachment_create)接口创建对应的图片样式对象。 <br> 可以通过[OH_ArkUI_ImageAttachment_Destroy](#oh_arkui_imageattachment_destroy)接口销毁图片样式对象。 <br> 对象创建后通过OH_ArkUI_ImageAttachment_SetXXX系列接口设置生效的具体样式，例如通过[OH_ArkUI_ImageAttachment_SetPixelMap](#oh_arkui_imageattachment_setpixelmap)设置图片源。 |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md) | OH_ArkUI_CustomSpan | 定义自定义绘制Span。 <br> 可以通过[OH_ArkUI_CustomSpan_Create](#oh_arkui_customspan_create)接口创建对应的自定义绘制Span对象。 <br> 可以通过[OH_ArkUI_CustomSpan_Destroy](#oh_arkui_customspan_destroy)接口销毁自定义绘制Span对象。 <br> 对象创建后通过[OH_ArkUI_CustomSpan_RegisterOnMeasureCallback](#oh_arkui_customspan_registeronmeasurecallback)和[OH_ArkUI_CustomSpan_RegisterOnDrawCallback](#oh_arkui_customspan_registerondrawcallback)接口注册绘制回调函数。 |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md) | OH_ArkUI_TextStyle | 定义文本字体样式。 <br> 可以通过[OH_ArkUI_TextStyle_Create](#oh_arkui_textstyle_create)接口创建对应的文本字体样式对象。 <br> 可以通过[OH_ArkUI_TextStyle_Destroy](#oh_arkui_textstyle_destroy)接口销毁文本字体样式对象。 <br> 对象创建后通过OH_ArkUI_TextStyle_SetXXX系列接口设置生效的具体样式，例如通过[OH_ArkUI_TextStyle_SetFontColor](#oh_arkui_textstyle_setfontcolor)设置字体颜色。 |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md) | OH_ArkUI_ParagraphStyle | 定义段落样式。 <br> 可以通过[OH_ArkUI_ParagraphStyle_Create](#oh_arkui_paragraphstyle_create)接口创建对应的段落样式对象。 <br> 可以通过[OH_ArkUI_ParagraphStyle_Destroy](#oh_arkui_paragraphstyle_destroy)接口销毁段落样式对象。 <br> 对象创建后通过OH_ArkUI_ParagraphStyle_SetXXX系列接口设置生效的具体样式，例如通过[OH_ArkUI_ParagraphStyle_SetTextAlign](#oh_arkui_paragraphstyle_settextalign)设置文本对齐方式。 |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md) | OH_ArkUI_GestureStyle | 定义事件手势样式。 <br> 可以通过[OH_ArkUI_GestureStyle_Create](#oh_arkui_gesturestyle_create)接口创建对应的事件手势样式对象。 <br> 可以通过[OH_ArkUI_GestureStyle_Destroy](#oh_arkui_gesturestyle_destroy)接口销毁事件手势样式对象。 <br> 对象创建后通过OH_ArkUI_GestureStyle_RegisterOnXXXCallback系列接口注册具体的事件回调，例如通过[OH_ArkUI_GestureStyle_RegisterOnClickCallback](#oh_arkui_gesturestyle_registeronclickcallback)注册点击事件回调。 |
| [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md) | OH_ArkUI_TextShadowStyle | 定义文本阴影样式。 <br> 可以通过[OH_ArkUI_TextShadowStyle_Create](#oh_arkui_textshadowstyle_create)接口创建对应的文本阴影样式对象。 <br> 可以通过[OH_ArkUI_TextShadowStyle_Destroy](#oh_arkui_textshadowstyle_destroy)接口销毁文本阴影样式对象。 <br> 对象创建后通过[OH_ArkUI_TextShadowStyle_SetTextShadow](#oh_arkui_textshadowstyle_settextshadow)接口设置生效的具体样式。 |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md) | OH_ArkUI_DecorationStyle | 定义文本装饰线样式。 <br> 可以通过[OH_ArkUI_DecorationStyle_Create](#oh_arkui_decorationstyle_create)接口创建对应的文本装饰线样式对象。 <br> 可以通过[OH_ArkUI_DecorationStyle_Destroy](#oh_arkui_decorationstyle_destroy)接口销毁文本装饰线样式对象。 <br> 对象创建后通过OH_ArkUI_DecorationStyle_SetXXX系列接口设置生效的具体样式，例如通过[OH_ArkUI_DecorationStyle_SetTextDecorationType](#oh_arkui_decorationstyle_settextdecorationtype)设置装饰线类型。 |
| [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md) | OH_ArkUI_BaselineOffsetStyle | 定义基线偏移量样式。 <br> 可以通过[OH_ArkUI_BaselineOffsetStyle_Create](#oh_arkui_baselineoffsetstyle_create)接口创建对应的基线偏移量样式对象。 <br> 可以通过[OH_ArkUI_BaselineOffsetStyle_Destroy](#oh_arkui_baselineoffsetstyle_destroy)接口销毁基线偏移量样式对象。 <br> 对象创建后通过[OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset](#oh_arkui_baselineoffsetstyle_setbaselineoffset)接口设置具体的基线偏移量值。 |
| [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md) | OH_ArkUI_LetterSpacingStyle | 定义字符间距样式。 <br> 可以通过[OH_ArkUI_LetterSpacingStyle_Create](#oh_arkui_letterspacingstyle_create)接口创建对应的字符间距样式对象。 <br> 可以通过[OH_ArkUI_LetterSpacingStyle_Destroy](#oh_arkui_letterspacingstyle_destroy)接口销毁字符间距样式对象。 <br> 对象创建后通过[OH_ArkUI_LetterSpacingStyle_SetLetterSpacing](#oh_arkui_letterspacingstyle_setletterspacing)接口设置具体的字符间距值。 |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md) | OH_ArkUI_LineHeightStyle | 定义行高样式。 <br> 可以通过[OH_ArkUI_LineHeightStyle_Create](#oh_arkui_lineheightstyle_create)接口创建对应的行高样式对象。 <br> 可以通过[OH_ArkUI_LineHeightStyle_Destroy](#oh_arkui_lineheightstyle_destroy)接口销毁行高样式对象。 <br> 对象创建后可以通过[OH_ArkUI_LineHeightStyle_SetLineHeight](#oh_arkui_lineheightstyle_setlineheight)接口设置具体的固定行高值。<br> 从API版本26.0.0开始，[OH_ArkUI_LineHeightStyle_SetLineHeightMultiple](#oh_arkui_lineheightstyle_setlineheightmultiple)接口设置具体的行高倍数值。 |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md) | OH_ArkUI_LineSpacingStyle | 定义行间距样式。 <br> 可以通过[OH_ArkUI_LineSpacingStyle_Create](#oh_arkui_linespacingstyle_create)接口创建对应的行间距样式对象。 <br> 可以通过[OH_ArkUI_LineSpacingStyle_Destroy](#oh_arkui_linespacingstyle_destroy)接口销毁行间距样式对象。 <br> 对象创建后可以通过[OH_ArkUI_LineSpacingStyle_SetLineSpacing](#oh_arkui_linespacingstyle_setlinespacing)接口设置具体的行间距值。<br> 可以通过[OH_ArkUI_LineSpacingStyle_SetOnlyBetweenLines](#oh_arkui_linespacingstyle_setonlybetweenlines)接口设置行间距是否只在行间生效。 |
| [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md) | OH_ArkUI_UrlStyle | 定义超链接样式。 <br> 可以通过[OH_ArkUI_UrlStyle_Create](#oh_arkui_urlstyle_create)接口创建对应的超链接样式对象。 <br> 可以通过[OH_ArkUI_UrlStyle_Destroy](#oh_arkui_urlstyle_destroy)接口销毁超链接样式对象。 <br> 对象创建后通过[OH_ArkUI_UrlStyle_SetUrl](#oh_arkui_urlstyle_seturl)接口设置链接地址。 |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md) | OH_ArkUI_BackgroundColorStyle | 定义背景颜色样式。 <br> 可以通过[OH_ArkUI_BackgroundColorStyle_Create](#oh_arkui_backgroundcolorstyle_create)接口创建对应的背景颜色样式对象。 <br> 可以通过[OH_ArkUI_BackgroundColorStyle_Destroy](#oh_arkui_backgroundcolorstyle_destroy)接口销毁背景颜色样式对象。 <br> 对象创建后通过[OH_ArkUI_BackgroundColorStyle_SetColor](#oh_arkui_backgroundcolorstyle_setcolor)和[OH_ArkUI_BackgroundColorStyle_SetRadius](#oh_arkui_backgroundcolorstyle_setradius)接口设置背景颜色和圆角。 |
| [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md) | OH_ArkUI_UserDataSpan | 定义用户数据Span样式。 <br> 可以通过[OH_ArkUI_UserDataSpan_Create](#oh_arkui_userdataspan_create)接口创建对应的用户数据Span样式对象。 <br> 可以通过[OH_ArkUI_UserDataSpan_Destroy](#oh_arkui_userdataspan_destroy)接口销毁用户数据Span样式对象。 <br> 对象创建后通过[OH_ArkUI_UserDataSpan_SetUserData](#oh_arkui_userdataspan_setuserdata)接口绑定用户数据。 |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md) | OH_ArkUI_LeadingMarginSpanDrawInfo | 定义段落缩进的自定义绘制信息。 <br> 可以通过[OH_ArkUI_LeadingMarginSpanDrawInfo_Create](#oh_arkui_leadingmarginspandrawinfo_create)接口创建对应的段落缩进的自定义绘制信息对象。 <br> 可以通过[OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy](#oh_arkui_leadingmarginspandrawinfo_destroy)接口销毁段落缩进的自定义绘制信息对象。 <br> 对象用于在[OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback](#oh_arkui_paragraphstyle_registerondrawleadingmargincallback)注册的回调函数中，提供当前行的绘制上下文信息。 |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md) | ArkUI_TextLayoutManager | 定义文本布局管理器对象，用于对文本进行布局处理，适用于需要精细控制文本显示和排版效果的场景，可帮助开发者实现自定义的文本布局需求。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey) | OH_ArkUI_StyledStringKey | 属性字符串的样式类型枚举。 |
| [OH_ArkUI_SuperscriptStyle](#oh_arkui_superscriptstyle) | OH_ArkUI_SuperscriptStyle | 定义文本上下角标样式枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_StyledString* OH_ArkUI_StyledString_Create(OH_Drawing_TypographyStyle* style, OH_Drawing_FontCollection* collection)](#oh_arkui_styledstring_create) | 创建指向ArkUI_StyledString对象的指针。 |
| [void OH_ArkUI_StyledString_Destroy(ArkUI_StyledString* handle)](#oh_arkui_styledstring_destroy) | 释放ArkUI_StyledString对象占用的内存。 |
| [void OH_ArkUI_StyledString_PushTextStyle(ArkUI_StyledString* handle, OH_Drawing_TextStyle* style)](#oh_arkui_styledstring_pushtextstyle) | 将新的排版风格设置到当前格式化字符串样式栈顶。 |
| [void OH_ArkUI_StyledString_AddText(ArkUI_StyledString* handle, const char* content)](#oh_arkui_styledstring_addtext) | 基于当前格式化字符串样式添加对应的文本内容。 |
| [void OH_ArkUI_StyledString_PopTextStyle(ArkUI_StyledString* handle)](#oh_arkui_styledstring_poptextstyle) | 将当前格式化字符串对象中栈顶样式出栈。 |
| [OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography(ArkUI_StyledString* handle)](#oh_arkui_styledstring_createtypography) | 基于格式化字符串对象创建指向[OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)对象的指针，用于提前进行文本测算排版。[OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)对象的生命周期由应用管理，当应用销毁该对象时，应同步调用[NODE_TEXT_CONTENT_WITH_STYLED_STRING](./capi-native-node-h-nodeattributetype-text.md#node_text_content_with_styled_string)对应的reset方法进行置空，避免野指针崩溃风险。 |
| [void OH_ArkUI_StyledString_AddPlaceholder(ArkUI_StyledString* handle, OH_Drawing_PlaceholderSpan* placeholder)](#oh_arkui_styledstring_addplaceholder) | 向格式化字符串中添加占位符。 |
| [ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_Create(void)](#oh_arkui_styledstring_descriptor_create) | 创建属性字符串数据对象。 |
| [void OH_ArkUI_StyledString_Descriptor_Destroy(ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_styledstring_descriptor_destroy) | 释放[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象占用的内存。 |
| [int32_t OH_ArkUI_UnmarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_unmarshallstyledstringdescriptor) | 将包含属性字符串信息的字节数组反序列化为属性字符串。 |
| [int32_t OH_ArkUI_MarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor, size_t* resultSize)](#oh_arkui_marshallstyledstringdescriptor) | 将属性字符串信息序列化为字节数组。 |
| [const char* OH_ArkUI_ConvertToHtml(ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_converttohtml) | 将属性字符串信息转换成HTML。 |
| [ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithString(const char* value, const OH_ArkUI_SpanStyle** styles, int32_t length)](#oh_arkui_styledstring_descriptor_createwithstring) | 创建纯文本内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。 |
| [ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithImageAttachment(const OH_ArkUI_ImageAttachment* value)](#oh_arkui_styledstring_descriptor_createwithimageattachment) | 创建图片内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。 |
| [ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithCustomSpan(const OH_ArkUI_CustomSpan* value)](#oh_arkui_styledstring_descriptor_createwithcustomspan) | 创建自定义绘制Span内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetLength(const ArkUI_StyledString_Descriptor* descriptor, int32_t* length)](#oh_arkui_styledstring_descriptor_getlength) | 获取属性字符串的字符长度。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetString(const ArkUI_StyledString_Descriptor* descriptor, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_styledstring_descriptor_getstring) | 获取属性字符串的文本内容。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_IsEqual(const ArkUI_StyledString_Descriptor* firstDescriptor, const ArkUI_StyledString_Descriptor* secondDescriptor, bool* isEqual)](#oh_arkui_styledstring_descriptor_isequal) | 判断两个属性字符串是否相同。当属性字符串的文本及样式均一致，视为相同。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SubStyledString(const ArkUI_StyledString_Descriptor* descriptor, ArkUI_StyledString_Descriptor* subDescriptor, uint32_t start, uint32_t length)](#oh_arkui_styledstring_descriptor_substyledstring) | 获取属性字符串的子属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetStyles(const ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey, OH_ArkUI_SpanStyle** styles, uint32_t stylesSize, uint32_t* writeLength)](#oh_arkui_styledstring_descriptor_getstyles) | 获取属性字符串指定范围内的样式集合。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_FromHtml(ArkUI_StyledString_Descriptor* descriptor, const char* html)](#oh_arkui_styledstring_descriptor_fromhtml) | 将HTML格式字符串转换成属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, const char* string)](#oh_arkui_styledstring_descriptor_replacestring) | 替换属性字符串指定范围的文本。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const char* string)](#oh_arkui_styledstring_descriptor_insertstring) | 在属性字符串的指定位置插入文本。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length)](#oh_arkui_styledstring_descriptor_removestring) | 移除属性字符串指定范围的文本。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyle(ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)](#oh_arkui_styledstring_descriptor_replacestyle) | 替换属性字符串指定范围内的样式。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SetStyle(ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)](#oh_arkui_styledstring_descriptor_setstyle) | 为属性字符串指定范围设置新样式。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveStyle(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey)](#oh_arkui_styledstring_descriptor_removestyle) | 清除属性字符串指定范围内的指定类型样式。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ClearStyles(ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_styledstring_descriptor_clearstyles) | 清除属性字符串对象的所有样式。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyledString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, const ArkUI_StyledString_Descriptor* other)](#oh_arkui_styledstring_descriptor_replacestyledstring) | 替换指定范围的属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertStyledString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const ArkUI_StyledString_Descriptor* other)](#oh_arkui_styledstring_descriptor_insertstyledstring) | 在属性字符串的指定位置插入新的属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_AppendStyledString(ArkUI_StyledString_Descriptor* descriptor, const ArkUI_StyledString_Descriptor* other)](#oh_arkui_styledstring_descriptor_appendstyledstring) | 在属性字符串的末尾追加新的属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InvalidateCustomSpan(const ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_styledstring_descriptor_invalidatecustomspan) | 主动刷新属性字符串中的自定义绘制Span。 |
| [OH_ArkUI_TextStyle* OH_ArkUI_TextStyle_Create()](#oh_arkui_textstyle_create) | 创建[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象。 |
| [void OH_ArkUI_TextStyle_Destroy(OH_ArkUI_TextStyle* textStyle)](#oh_arkui_textstyle_destroy) | 释放[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontColor(OH_ArkUI_TextStyle* textStyle, uint32_t fontColor)](#oh_arkui_textstyle_setfontcolor) | 设置文本字体样式中的字体颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontColor)](#oh_arkui_textstyle_getfontcolor) | 获取文本字体样式中的字体颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontFamily(OH_ArkUI_TextStyle* textStyle, const char* fontFamily)](#oh_arkui_textstyle_setfontfamily) | 设置文本字体样式中的字体族。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontFamily(const OH_ArkUI_TextStyle* textStyle, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textstyle_getfontfamily) | 获取文本字体样式中的字体族。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontSize(OH_ArkUI_TextStyle* textStyle, float fontSize)](#oh_arkui_textstyle_setfontsize) | 设置文本字体样式中的字体大小。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontSize(const OH_ArkUI_TextStyle* textStyle, float* fontSize)](#oh_arkui_textstyle_getfontsize) | 获取文本字体样式中的字体大小。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontWeight(OH_ArkUI_TextStyle* textStyle, uint32_t fontWeight)](#oh_arkui_textstyle_setfontweight) | 设置文本字体样式中的字体粗细。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontWeight(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontWeight)](#oh_arkui_textstyle_getfontweight) | 获取文本字体样式中的字体粗细。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontStyle(OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle fontStyle)](#oh_arkui_textstyle_setfontstyle) | 设置文本字体样式中的字体风格。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontStyle(const OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle* fontStyle)](#oh_arkui_textstyle_getfontstyle) | 获取文本字体样式中的字体风格。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeWidth(OH_ArkUI_TextStyle* textStyle, float strokeWidth)](#oh_arkui_textstyle_setstrokewidth) | 设置文本字体样式中的描边宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeWidth(const OH_ArkUI_TextStyle* textStyle, float* strokeWidth)](#oh_arkui_textstyle_getstrokewidth) | 获取文本字体样式中的描边宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeColor(OH_ArkUI_TextStyle* textStyle, uint32_t strokeColor)](#oh_arkui_textstyle_setstrokecolor) | 设置文本字体样式中的描边颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* strokeColor)](#oh_arkui_textstyle_getstrokecolor) | 获取文本字体样式中的描边颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_SetSuperscript(OH_ArkUI_TextStyle* textStyle, OH_ArkUI_SuperscriptStyle superscript)](#oh_arkui_textstyle_setsuperscript) | 设置文本字体样式中的上下标样式。 |
| [ArkUI_ErrorCode OH_ArkUI_TextStyle_GetSuperscript(const OH_ArkUI_TextStyle* textStyle, OH_ArkUI_SuperscriptStyle* superscript)](#oh_arkui_textstyle_getsuperscript) | 获取文本字体样式中的上下标样式。 |
| [OH_ArkUI_SpanStyle* OH_ArkUI_SpanStyle_Create()](#oh_arkui_spanstyle_create) | 创建[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象。 |
| [void OH_ArkUI_SpanStyle_Destroy(OH_ArkUI_SpanStyle* spanStyle)](#oh_arkui_spanstyle_destroy) | 释放[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStyledKey(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_StyledStringKey* styledKey)](#oh_arkui_spanstyle_getstyledkey) | 获取属性字符串样式对象的样式类型。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetStart(OH_ArkUI_SpanStyle* spanStyle, int32_t start)](#oh_arkui_spanstyle_setstart) | 设置属性字符串样式对象的起始位置。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStart(const OH_ArkUI_SpanStyle* spanStyle, int32_t* start)](#oh_arkui_spanstyle_getstart) | 获取属性字符串样式对象的起始位置。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLength(OH_ArkUI_SpanStyle* spanStyle, int32_t length)](#oh_arkui_spanstyle_setlength) | 设置属性字符串样式对象的长度。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLength(const OH_ArkUI_SpanStyle* spanStyle, int32_t* length)](#oh_arkui_spanstyle_getlength) | 获取属性字符串样式对象的长度。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextStyle* textStyle)](#oh_arkui_spanstyle_settextstyle) | 设置属性字符串样式对象的文本字体样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextStyle* textStyle)](#oh_arkui_spanstyle_gettextstyle) | 获取属性字符串样式对象的文本字体样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetParagraphStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ParagraphStyle* paragraphStyle)](#oh_arkui_spanstyle_setparagraphstyle) | 设置属性字符串样式对象的段落样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetParagraphStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ParagraphStyle* paragraphStyle)](#oh_arkui_spanstyle_getparagraphstyle) | 获取属性字符串样式对象的段落样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetGestureStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_GestureStyle* gestureStyle)](#oh_arkui_spanstyle_setgesturestyle) | 设置属性字符串样式对象的事件手势样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetGestureStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_GestureStyle* gestureStyle)](#oh_arkui_spanstyle_getgesturestyle) | 获取属性字符串样式对象的事件手势样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextShadowStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextShadowStyle* textShadowStyle)](#oh_arkui_spanstyle_settextshadowstyle) | 设置属性字符串样式对象的文本阴影样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextShadowStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextShadowStyle* textShadowStyle)](#oh_arkui_spanstyle_gettextshadowstyle) | 获取属性字符串样式对象的文本阴影样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetDecorationStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_DecorationStyle* decorationStyle)](#oh_arkui_spanstyle_setdecorationstyle) | 设置属性字符串样式对象的文本装饰线样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetDecorationStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_DecorationStyle* decorationStyle)](#oh_arkui_spanstyle_getdecorationstyle) | 获取属性字符串样式对象的文本装饰线样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBaselineOffsetStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)](#oh_arkui_spanstyle_setbaselineoffsetstyle) | 设置属性字符串样式对象的基线偏移量样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBaselineOffsetStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)](#oh_arkui_spanstyle_getbaselineoffsetstyle) | 获取属性字符串样式对象的基线偏移量样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLetterSpacingStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)](#oh_arkui_spanstyle_setletterspacingstyle) | 设置属性字符串样式对象的字符间距样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLetterSpacingStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)](#oh_arkui_spanstyle_getletterspacingstyle) | 获取属性字符串样式对象的字符间距样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLineHeightStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LineHeightStyle* lineHeightStyle)](#oh_arkui_spanstyle_setlineheightstyle) | 设置属性字符串样式对象的行高样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLineHeightStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LineHeightStyle* lineHeightStyle)](#oh_arkui_spanstyle_getlineheightstyle) | 获取属性字符串样式对象的行高样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUrlStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UrlStyle* urlStyle)](#oh_arkui_spanstyle_seturlstyle) | 设置属性字符串样式对象的超链接样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUrlStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UrlStyle* urlStyle)](#oh_arkui_spanstyle_geturlstyle) | 获取属性字符串样式对象的超链接样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBackgroundColorStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)](#oh_arkui_spanstyle_setbackgroundcolorstyle) | 设置属性字符串样式对象的背景颜色样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBackgroundColorStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)](#oh_arkui_spanstyle_getbackgroundcolorstyle) | 获取属性字符串样式对象的背景颜色样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUserDataSpan(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UserDataSpan* userDataSpan)](#oh_arkui_spanstyle_setuserdataspan) | 设置属性字符串样式对象的用户数据Span样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUserDataSpan(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UserDataSpan* userDataSpan)](#oh_arkui_spanstyle_getuserdataspan) | 获取属性字符串样式对象的用户数据Span样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetCustomSpan(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_CustomSpan* customSpan)](#oh_arkui_spanstyle_setcustomspan) | 设置属性字符串样式对象的自定义绘制Span样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetCustomSpan(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_CustomSpan* customSpan)](#oh_arkui_spanstyle_getcustomspan) | 获取属性字符串样式对象的自定义绘制Span样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetImageAttachment(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ImageAttachment* imageAttachment)](#oh_arkui_spanstyle_setimageattachment) | 设置属性字符串样式对象的图片样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetImageAttachment(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ImageAttachment* imageAttachment)](#oh_arkui_spanstyle_getimageattachment) | 获取属性字符串样式对象的图片样式。 |
| [OH_ArkUI_LeadingMarginSpanDrawInfo* OH_ArkUI_LeadingMarginSpanDrawInfo_Create()](#oh_arkui_leadingmarginspandrawinfo_create) | 创建[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象。 |
| [void OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo)](#oh_arkui_leadingmarginspandrawinfo_destroy) | 释放[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetX(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float x)](#oh_arkui_leadingmarginspandrawinfo_setx) | 设置段落缩进的自定义绘制信息对象中当前行相对于组件的水平偏移。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetX(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* x)](#oh_arkui_leadingmarginspandrawinfo_getx) | 获取段落缩进的自定义绘制信息对象中当前行相对于组件的水平偏移。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTop(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float top)](#oh_arkui_leadingmarginspandrawinfo_settop) | 设置段落缩进的自定义绘制信息对象中行顶与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTop(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* top)](#oh_arkui_leadingmarginspandrawinfo_gettop) | 获取段落缩进的自定义绘制信息对象中行顶与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBottom(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float bottom)](#oh_arkui_leadingmarginspandrawinfo_setbottom) | 设置段落缩进的自定义绘制信息对象中行底与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBottom(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* bottom)](#oh_arkui_leadingmarginspandrawinfo_getbottom) | 获取段落缩进的自定义绘制信息对象中行底与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBaseline(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float baseline)](#oh_arkui_leadingmarginspandrawinfo_setbaseline) | 设置段落缩进的自定义绘制信息对象中当前行的基线与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBaseline(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* baseline)](#oh_arkui_leadingmarginspandrawinfo_getbaseline) | 获取段落缩进的自定义绘制信息对象中当前行的基线与组件上边缘的距离。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTextDirection(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, ArkUI_TextDirection direction)](#oh_arkui_leadingmarginspandrawinfo_settextdirection) | 设置段落缩进的自定义绘制信息对象中文本内容的方向。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTextDirection(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, ArkUI_TextDirection* direction)](#oh_arkui_leadingmarginspandrawinfo_gettextdirection) | 获取段落缩进的自定义绘制信息对象中文本内容的方向。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetStart(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t start)](#oh_arkui_leadingmarginspandrawinfo_setstart) | 设置段落缩进的自定义绘制信息对象中当前行的起始索引。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetStart(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t* start)](#oh_arkui_leadingmarginspandrawinfo_getstart) | 获取段落缩进的自定义绘制信息对象中当前行的起始索引。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetEnd(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t end)](#oh_arkui_leadingmarginspandrawinfo_setend) | 设置段落缩进的自定义绘制信息对象中当前行的结束索引。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetEnd(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t* end)](#oh_arkui_leadingmarginspandrawinfo_getend) | 获取段落缩进的自定义绘制信息对象中当前行的结束索引。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetFirst(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, bool first)](#oh_arkui_leadingmarginspandrawinfo_setfirst) | 设置段落缩进的自定义绘制信息对象中当前行是否为段落的首行。 |
| [ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetFirst(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, bool* first)](#oh_arkui_leadingmarginspandrawinfo_getfirst) | 获取段落缩进的自定义绘制信息对象中当前行是否为段落的首行。 |
| [OH_ArkUI_ParagraphStyle* OH_ArkUI_ParagraphStyle_Create()](#oh_arkui_paragraphstyle_create) | 创建[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象。 |
| [void OH_ArkUI_ParagraphStyle_Destroy(OH_ArkUI_ParagraphStyle* paragraphStyle)](#oh_arkui_paragraphstyle_destroy) | 释放[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextAlign(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextAlignment align)](#oh_arkui_paragraphstyle_settextalign) | 设置段落样式中的水平方向的文本对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextAlignment* align)](#oh_arkui_paragraphstyle_gettextalign) | 获取段落样式中的水平方向的文本对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextIndent(OH_ArkUI_ParagraphStyle* paragraphStyle, float textIndent)](#oh_arkui_paragraphstyle_settextindent) | 设置段落样式中的首行文本缩进。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextIndent(const OH_ArkUI_ParagraphStyle* paragraphStyle, float* textIndent)](#oh_arkui_paragraphstyle_gettextindent) | 获取段落样式中的首行文本缩进。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetMaxLines(OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t maxLines)](#oh_arkui_paragraphstyle_setmaxlines) | 设置段落样式中的最大行数。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetMaxLines(const OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t* maxLines)](#oh_arkui_paragraphstyle_getmaxlines) | 获取段落样式中的最大行数。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetOverflow(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextOverflow overflow)](#oh_arkui_paragraphstyle_setoverflow) | 设置段落样式中的段落超长时的显示方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetOverflow(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextOverflow* overflow)](#oh_arkui_paragraphstyle_getoverflow) | 获取段落样式中的段落超长时的显示方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetWordBreak(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_WordBreak wordBreak)](#oh_arkui_paragraphstyle_setwordbreak) | 设置段落样式中的断行规则。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetWordBreak(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_WordBreak* wordBreak)](#oh_arkui_paragraphstyle_getwordbreak) | 获取段落样式中的断行规则。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginPixelMap(OH_ArkUI_ParagraphStyle* paragraphStyle, struct OH_PixelmapNative* pixelmap)](#oh_arkui_paragraphstyle_setleadingmarginpixelmap) | 设置段落样式中的段落缩进的像素图。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginPixelMap(const OH_ArkUI_ParagraphStyle* paragraphStyle, struct OH_PixelmapNative** pixelmap)](#oh_arkui_paragraphstyle_getleadingmarginpixelmap) | 获取段落样式中的段落缩进的像素图。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t width)](#oh_arkui_paragraphstyle_setleadingmarginwidth) | 设置段落样式中的段落缩进宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginWidth(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* width)](#oh_arkui_paragraphstyle_getleadingmarginwidth) | 获取段落样式中的段落缩进宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t height)](#oh_arkui_paragraphstyle_setleadingmarginheight) | 设置段落样式中的段落缩进高度。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginHeight(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* height)](#oh_arkui_paragraphstyle_getleadingmarginheight) | 获取段落样式中的段落缩进高度。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetParagraphSpacing(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t paragraphSpacing)](#oh_arkui_paragraphstyle_setparagraphspacing) | 设置段落样式中的段落间距。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetParagraphSpacing(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* paragraphSpacing)](#oh_arkui_paragraphstyle_getparagraphspacing) | 获取段落样式中的段落间距。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextVerticalAlign(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextVerticalAlignment verticalAlignment)](#oh_arkui_paragraphstyle_settextverticalalign) | 设置段落样式中的垂直方向的文本对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextVerticalAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextVerticalAlignment* verticalAlignment)](#oh_arkui_paragraphstyle_gettextverticalalign) | 获取段落样式中的垂直方向的文本对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle, void(\*onDraw)(ArkUI_DrawContext* context, OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo))](#oh_arkui_paragraphstyle_registerondrawleadingmargincallback) | 注册段落样式中绘制段落缩进时触发的回调函数。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnGetLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle, float(\*leadingMargin)())](#oh_arkui_paragraphstyle_registerongetleadingmargincallback) | 设置段落样式中获取段落缩进距离时触发的回调函数。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextDirection(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextDirection textDirection)](#oh_arkui_paragraphstyle_settextdirection) | 设置段落样式中的文本方向。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextDirection(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextDirection* textDirection)](#oh_arkui_paragraphstyle_gettextdirection) | 获取段落样式中的文本方向。 |
| [OH_ArkUI_GestureStyle* OH_ArkUI_GestureStyle_Create()](#oh_arkui_gesturestyle_create) | 创建[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象。 |
| [void OH_ArkUI_GestureStyle_Destroy(OH_ArkUI_GestureStyle* gestureStyle)](#oh_arkui_gesturestyle_destroy) | 释放[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnClickCallback(OH_ArkUI_GestureStyle* gestureStyle, void(\*onClick)(ArkUI_NodeEvent*))](#oh_arkui_gesturestyle_registeronclickcallback) | 注册事件手势样式中的点击事件回调。 |
| [ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnLongPressCallback(OH_ArkUI_GestureStyle* gestureStyle, void(\*onLongPress)(ArkUI_GestureEvent*))](#oh_arkui_gesturestyle_registeronlongpresscallback) | 注册事件手势样式中的长按事件回调。 |
| [ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnTouchCallback(OH_ArkUI_GestureStyle* gestureStyle, void(\*onTouch)(ArkUI_NodeEvent*))](#oh_arkui_gesturestyle_registerontouchcallback) | 注册事件手势样式中的触摸事件回调。 |
| [OH_ArkUI_TextShadowStyle* OH_ArkUI_TextShadowStyle_Create()](#oh_arkui_textshadowstyle_create) | 创建[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象。 |
| [void OH_ArkUI_TextShadowStyle_Destroy(OH_ArkUI_TextShadowStyle* textShadowStyle)](#oh_arkui_textshadowstyle_destroy) | 释放[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_SetTextShadow(OH_ArkUI_TextShadowStyle* textShadowStyle, const OH_ArkUI_ShadowOptions** options, uint32_t length)](#oh_arkui_textshadowstyle_settextshadow) | 设置文本阴影样式的文本阴影选项。 |
| [ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_GetTextShadow(const OH_ArkUI_TextShadowStyle* textShadowStyle, OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)](#oh_arkui_textshadowstyle_gettextshadow) | 获取文本阴影样式的文本阴影选项。 |
| [OH_ArkUI_DecorationStyle* OH_ArkUI_DecorationStyle_Create()](#oh_arkui_decorationstyle_create) | 创建[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象。 |
| [void OH_ArkUI_DecorationStyle_Destroy(OH_ArkUI_DecorationStyle* decorationStyle)](#oh_arkui_decorationstyle_destroy) | 释放[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationType(OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationType type)](#oh_arkui_decorationstyle_settextdecorationtype) | 设置文本装饰线样式的装饰线类型。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationType(const OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationType* type)](#oh_arkui_decorationstyle_gettextdecorationtype) | 获取文本装饰线样式的装饰线类型。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetColor(OH_ArkUI_DecorationStyle* decorationStyle, uint32_t color)](#oh_arkui_decorationstyle_setcolor) | 设置文本装饰线样式的装饰线颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetColor(const OH_ArkUI_DecorationStyle* decorationStyle, uint32_t* color)](#oh_arkui_decorationstyle_getcolor) | 获取文本装饰线样式的装饰线颜色。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationStyle(OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationStyle style)](#oh_arkui_decorationstyle_settextdecorationstyle) | 设置文本装饰线样式的装饰线样式。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationStyle(const OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationStyle* style)](#oh_arkui_decorationstyle_gettextdecorationstyle) | 获取文本装饰线样式的装饰线样式。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetThicknessScale(OH_ArkUI_DecorationStyle* decorationStyle, float thicknessScale)](#oh_arkui_decorationstyle_setthicknessscale) | 设置文本装饰线样式的装饰线的粗细缩放比例。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetThicknessScale(const OH_ArkUI_DecorationStyle* decorationStyle, float* thicknessScale)](#oh_arkui_decorationstyle_getthicknessscale) | 获取文本装饰线样式的装饰线的粗细缩放比例。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetEnableMultiType(OH_ArkUI_DecorationStyle* decorationStyle, bool enableMultiType)](#oh_arkui_decorationstyle_setenablemultitype) | 设置文本装饰线样式中是否开启多装饰线显示。 |
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetEnableMultiType(const OH_ArkUI_DecorationStyle* decorationStyle, bool* enableMultiType)](#oh_arkui_decorationstyle_getenablemultitype) | 获取文本装饰线样式中是否开启多装饰线显示。 |
| [OH_ArkUI_BaselineOffsetStyle* OH_ArkUI_BaselineOffsetStyle_Create()](#oh_arkui_baselineoffsetstyle_create) | 创建[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象。 |
| [void OH_ArkUI_BaselineOffsetStyle_Destroy(OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)](#oh_arkui_baselineoffsetstyle_destroy) | 释放[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset(OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float baselineOffset)](#oh_arkui_baselineoffsetstyle_setbaselineoffset) | 设置基线偏移量。 |
| [ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_GetBaselineOffset(const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float* baselineOffset)](#oh_arkui_baselineoffsetstyle_getbaselineoffset) | 获取基线偏移量。 |
| [OH_ArkUI_LetterSpacingStyle* OH_ArkUI_LetterSpacingStyle_Create()](#oh_arkui_letterspacingstyle_create) | 创建[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象。 |
| [void OH_ArkUI_LetterSpacingStyle_Destroy(OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)](#oh_arkui_letterspacingstyle_destroy) | 释放[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_SetLetterSpacing(OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float letterSpacing)](#oh_arkui_letterspacingstyle_setletterspacing) | 设置字符间距。 |
| [ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_GetLetterSpacing(const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float* letterSpacing)](#oh_arkui_letterspacingstyle_getletterspacing) | 获取字符间距。 |
| [OH_ArkUI_LineHeightStyle* OH_ArkUI_LineHeightStyle_Create()](#oh_arkui_lineheightstyle_create) | 创建[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象。 |
| [void OH_ArkUI_LineHeightStyle_Destroy(OH_ArkUI_LineHeightStyle* lineHeightStyle)](#oh_arkui_lineheightstyle_destroy) | 释放[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_SetLineHeight(OH_ArkUI_LineHeightStyle* lineHeightStyle, float lineHeight)](#oh_arkui_lineheightstyle_setlineheight) | 设置文本行高。 |
| [ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_GetLineHeight(const OH_ArkUI_LineHeightStyle* lineHeightStyle, float* lineHeight)](#oh_arkui_lineheightstyle_getlineheight) | 获取文本行高。 |
| [ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_SetLineHeightMultiple(OH_ArkUI_LineHeightStyle* lineHeightStyle, float lineHeightMultiple)](#oh_arkui_lineheightstyle_setlineheightmultiple) | 设置行高样式的行高倍数。 |
| [ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_GetLineHeightMultiple(const OH_ArkUI_LineHeightStyle* lineHeightStyle, float* lineHeightMultiple)](#oh_arkui_lineheightstyle_getlineheightmultiple) | 获取行高样式的行高倍数。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLineSpacingStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LineSpacingStyle* lineSpacingStyle)](#oh_arkui_spanstyle_setlinespacingstyle) | 设置属性字符串样式对象的行间距样式。 |
| [ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLineSpacingStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LineSpacingStyle* lineSpacingStyle)](#oh_arkui_spanstyle_getlinespacingstyle) | 获取属性字符串样式对象的行间距样式。 |
| [OH_ArkUI_LineSpacingStyle* OH_ArkUI_LineSpacingStyle_Create()](#oh_arkui_linespacingstyle_create) | 创建[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象。 |
| [void OH_ArkUI_LineSpacingStyle_Destroy(OH_ArkUI_LineSpacingStyle* lineSpacingStyle)](#oh_arkui_linespacingstyle_destroy) | 释放[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_SetLineSpacing(OH_ArkUI_LineSpacingStyle* lineSpacingStyle, float lineSpacing)](#oh_arkui_linespacingstyle_setlinespacing) | 设置行间距。 |
| [ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_GetLineSpacing(const OH_ArkUI_LineSpacingStyle* lineSpacingStyle, float* lineSpacing)](#oh_arkui_linespacingstyle_getlinespacing) | 获取行间距。|
| [ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_SetOnlyBetweenLines(OH_ArkUI_LineSpacingStyle* lineSpacingStyle, bool onlyBetweenLines)](#oh_arkui_linespacingstyle_setonlybetweenlines) | 设置行间距是否只在行间生效。 |
| [ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_GetOnlyBetweenLines(const OH_ArkUI_LineSpacingStyle* lineSpacingStyle, bool* onlyBetweenLines)](#oh_arkui_linespacingstyle_getonlybetweenlines) | 获取行间距是否只在行间生效。|
| [OH_ArkUI_BackgroundColorStyle* OH_ArkUI_BackgroundColorStyle_Create()](#oh_arkui_backgroundcolorstyle_create) | 创建[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象。 |
| [void OH_ArkUI_BackgroundColorStyle_Destroy(OH_ArkUI_BackgroundColorStyle* style)](#oh_arkui_backgroundcolorstyle_destroy) | 释放[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetColor(OH_ArkUI_BackgroundColorStyle* style, uint32_t color)](#oh_arkui_backgroundcolorstyle_setcolor) | 设置背景颜色样式的背景色。 |
| [ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetColor(const OH_ArkUI_BackgroundColorStyle* style, uint32_t* color)](#oh_arkui_backgroundcolorstyle_getcolor) | 获取背景颜色样式的背景色。 |
| [ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetRadius(OH_ArkUI_BackgroundColorStyle* style, float topLeft, float topRight, float bottomLeft, float bottomRight)](#oh_arkui_backgroundcolorstyle_setradius) | 设置背景颜色样式的背景圆角。 |
| [ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetRadius(const OH_ArkUI_BackgroundColorStyle* style, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)](#oh_arkui_backgroundcolorstyle_getradius) | 获取背景颜色样式的背景圆角。 |
| [OH_ArkUI_UrlStyle* OH_ArkUI_UrlStyle_Create()](#oh_arkui_urlstyle_create) | 创建[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象。 |
| [void OH_ArkUI_UrlStyle_Destroy(OH_ArkUI_UrlStyle* style)](#oh_arkui_urlstyle_destroy) | 释放[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_UrlStyle_SetUrl(OH_ArkUI_UrlStyle* style, const char* url)](#oh_arkui_urlstyle_seturl) | 设置超链接样式的超链接内容。 |
| [ArkUI_ErrorCode OH_ArkUI_UrlStyle_GetUrl(const OH_ArkUI_UrlStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_urlstyle_geturl) | 获取超链接样式的超链接内容。 |
| [OH_ArkUI_UserDataSpan* OH_ArkUI_UserDataSpan_Create()](#oh_arkui_userdataspan_create) | 创建[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象。 |
| [void OH_ArkUI_UserDataSpan_Destroy(OH_ArkUI_UserDataSpan* userDataSpan)](#oh_arkui_userdataspan_destroy) | 释放[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_UserDataSpan_SetUserData(OH_ArkUI_UserDataSpan* userDataSpan, void* userData)](#oh_arkui_userdataspan_setuserdata) | 设置用户数据Span样式中的用户数据。 |
| [ArkUI_ErrorCode OH_ArkUI_UserDataSpan_GetUserData(const OH_ArkUI_UserDataSpan* userDataSpan, void** userData)](#oh_arkui_userdataspan_getuserdata) | 获取用户数据Span样式中的用户数据。 |
| [OH_ArkUI_CustomSpan* OH_ArkUI_CustomSpan_Create()](#oh_arkui_customspan_create) | 创建[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象。 |
| [void OH_ArkUI_CustomSpan_Destroy(OH_ArkUI_CustomSpan* customSpan)](#oh_arkui_customspan_destroy) | 释放[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnMeasureCallback(OH_ArkUI_CustomSpan* customSpan, ArkUI_CustomSpanMetrics*(\*onMeasure)(float))](#oh_arkui_customspan_registeronmeasurecallback) | 注册自定义绘制Span获取尺寸大小时的回调函数。 |
| [ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnDrawCallback(OH_ArkUI_CustomSpan* customSpan, void(\*onDraw)(ArkUI_DrawContext*, ArkUI_CustomSpanDrawInfo*))](#oh_arkui_customspan_registerondrawcallback) | 注册自定义绘制Span绘制时的回调函数。 |
| [OH_ArkUI_ImageAttachment* OH_ArkUI_ImageAttachment_Create()](#oh_arkui_imageattachment_create) | 创建[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象。 |
| [void OH_ArkUI_ImageAttachment_Destroy(OH_ArkUI_ImageAttachment* imageAttachment)](#oh_arkui_imageattachment_destroy) | 释放[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPixelMap(OH_ArkUI_ImageAttachment* imageAttachment, struct OH_PixelmapNative* pixelmap)](#oh_arkui_imageattachment_setpixelmap) | 设置图片样式中的图片数据源。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPixelMap(const OH_ArkUI_ImageAttachment* imageAttachment, struct OH_PixelmapNative** pixelmap)](#oh_arkui_imageattachment_getpixelmap) | 获取图片样式中的图片数据源。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetResource(OH_ArkUI_ImageAttachment* imageAttachment, const char* resource)](#oh_arkui_imageattachment_setresource) | 设置图片样式中的图片资源地址。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetResource(const OH_ArkUI_ImageAttachment* imageAttachment, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_imageattachment_getresource) | 获取图片样式中的图片资源地址。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeWidth(OH_ArkUI_ImageAttachment* imageAttachment, float width)](#oh_arkui_imageattachment_setsizewidth) | 设置图片样式中的图片宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeWidth(const OH_ArkUI_ImageAttachment* imageAttachment, float* width)](#oh_arkui_imageattachment_getsizewidth) | 获取图片样式中的图片宽度。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeHeight(OH_ArkUI_ImageAttachment* imageAttachment, float height)](#oh_arkui_imageattachment_setsizeheight) | 设置图片样式中的图片高度。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeHeight(const OH_ArkUI_ImageAttachment* imageAttachment, float* height)](#oh_arkui_imageattachment_getsizeheight) | 获取图片样式中的图片高度。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetVerticalAlign(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ImageSpanAlignment verticalAlign)](#oh_arkui_imageattachment_setverticalalign) | 设置图片样式中的图片对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetVerticalAlign(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ImageSpanAlignment* verticalAlign)](#oh_arkui_imageattachment_getverticalalign) | 获取图片样式中的图片对齐方式。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetObjectFit(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit objectFit)](#oh_arkui_imageattachment_setobjectfit) | 设置图片样式中的图片缩放类型。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetObjectFit(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit* objectFit)](#oh_arkui_imageattachment_getobjectfit) | 获取图片样式中的图片缩放类型。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetMargin(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin margin)](#oh_arkui_imageattachment_setmargin) | 设置图片样式中的图片外边距。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetMargin(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin* margin)](#oh_arkui_imageattachment_getmargin) | 获取图片样式中的图片外边距。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPadding(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin padding)](#oh_arkui_imageattachment_setpadding) | 设置图片样式中的图片内边距。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPadding(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin* padding)](#oh_arkui_imageattachment_getpadding) | 获取图片样式中的图片内边距。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetBorderRadiuses(OH_ArkUI_ImageAttachment* imageAttachment, float topLeft, float topRight, float bottomLeft, float bottomRight)](#oh_arkui_imageattachment_setborderradiuses) | 设置图片样式中的图片圆角。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetBorderRadiuses(const OH_ArkUI_ImageAttachment* imageAttachment, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)](#oh_arkui_imageattachment_getborderradiuses) | 获取图片样式中的图片圆角。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetColorFilter(OH_ArkUI_ImageAttachment* imageAttachment, const float* colorFilter, uint32_t size)](#oh_arkui_imageattachment_setcolorfilter) | 设置图片样式中的图片颜色过滤器。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetColorFilter(const OH_ArkUI_ImageAttachment* imageAttachment, float** colorFilter, uint32_t colorFilterSize, uint32_t* writeLength)](#oh_arkui_imageattachment_getcolorfilter) | 获取图片样式中的图片颜色过滤器。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetDrawingColorFilter(OH_ArkUI_ImageAttachment* imageAttachment, const OH_Drawing_ColorFilter* drawingColorFilter)](#oh_arkui_imageattachment_setdrawingcolorfilter) | 设置图片样式中的图片颜色滤镜。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetDrawingColorFilter(const OH_ArkUI_ImageAttachment* imageAttachment, OH_Drawing_ColorFilter* drawingColorFilter)](#oh_arkui_imageattachment_getdrawingcolorfilter) | 获取图片样式中的图片颜色滤镜。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSyncLoad(OH_ArkUI_ImageAttachment* imageAttachment, bool syncLoad)](#oh_arkui_imageattachment_setsyncload) | 设置图片样式中是否同步加载图片。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSyncLoad(const OH_ArkUI_ImageAttachment* imageAttachment, bool* syncLoad)](#oh_arkui_imageattachment_getsyncload) | 获取图片样式中是否同步加载图片。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSupportSvg(OH_ArkUI_ImageAttachment* imageAttachment, bool supportSvg)](#oh_arkui_imageattachment_setsupportsvg) | 设置图片样式中是否开启SVG标签解析能力增强功能，开启后支持解析扩展SVG标签及属性。 |
| [ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSupportSvg(const OH_ArkUI_ImageAttachment* imageAttachment, bool* supportSvg)](#oh_arkui_imageattachment_getsupportsvg) | 获取图片样式中是否开启SVG标签解析能力增强功能。 |
| [ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetRangeBefore(const OH_ArkUI_TextEditorChangeEvent* event, uint32_t* start, uint32_t* end)](#oh_arkui_texteditorchangeevent_getrangebefore) | 获取文本变化信息中待被替换的原文本的范围。 |
| [ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetReplacementStyledString(const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_texteditorchangeevent_getreplacementstyledstring) | 获取文本变化信息中的用于替换的属性字符串。 |
| [ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetPreviewStyledString(const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_texteditorchangeevent_getpreviewstyledstring) | 获取文本变化信息中的预览内容属性字符串。 |
| [void OH_ArkUI_TextLayoutManager_Dispose(ArkUI_TextLayoutManager* layoutManager)](#oh_arkui_textlayoutmanager_dispose) | 释放文本布局管理器对象占用的内存。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineCount(ArkUI_TextLayoutManager* layoutManager, int32_t* outLineCount)](#oh_arkui_textlayoutmanager_getlinecount) | 获取文本行数。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetRectsForRange(ArkUI_TextLayoutManager* layoutManager, int32_t start, int32_t end, OH_Drawing_RectWidthStyle widthStyle, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_TextBox** outTextBoxes)](#oh_arkui_textlayoutmanager_getrectsforrange) | 获取给定的矩形区域宽度样式以及高度样式的规格下，文本中任意区间范围内的字符或占位符所占的绘制区域信息。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate(ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)](#oh_arkui_textlayoutmanager_getglyphpositionatcoordinate) | 获取距离给定坐标最近的字形的位置信息。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineMetrics(ArkUI_TextLayoutManager* layoutManager, int32_t lineNumber, OH_Drawing_LineMetrics* outMetrics)](#oh_arkui_textlayoutmanager_getlinemetrics) | 获取指定行的行信息、文本样式信息、以及字体属性信息。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterPositionAtCoordinate(ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)](#oh_arkui_textlayoutmanager_getcharacterpositionatcoordinate) | 获取距离指定坐标最近的字符的位置信息。与OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate的区别：此方法返回字符级别的位置信息，适用于文本编辑、光标定位等基于字符编码的场景；而GetGlyphPositionAtCoordinate返回字形级别的位置信息，适用于渲染相关的精确定位场景。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphRangeForCharacterRange(ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* charRange, OH_Drawing_Range** outGlyphRange, OH_Drawing_Range** outActualCharRange)](#oh_arkui_textlayoutmanager_getglyphrangeforcharacterrange) | 获取由指定字符范围所生成的字形范围。 |
| [ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterRangeForGlyphRange(ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* glyphRange, OH_Drawing_Range** outCharRange, OH_Drawing_Range** outActualGlyphRange)](#oh_arkui_textlayoutmanager_getcharacterrangeforglyphrange) | 获取由指定字形范围所生成的字符范围。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLinearGradient(OH_ArkUI_ParagraphStyle* paragraphStyle, const OH_ArkUI_LinearGradientOptions* linearGradient)](#oh_arkui_paragraphstyle_setlineargradient) | 设置段落样式的线性渐变。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLinearGradient(const OH_ArkUI_ParagraphStyle* paragraphStyle, OH_ArkUI_LinearGradientOptions* linearGradient)](#oh_arkui_paragraphstyle_getlineargradient) | 获取段落样式的线性渐变。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetRadialGradient(OH_ArkUI_ParagraphStyle* paragraphStyle, const OH_ArkUI_RadialGradientOptions* radialGradient)](#oh_arkui_paragraphstyle_setradialgradient) | 设置段落样式的径向渐变。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetRadialGradient(const OH_ArkUI_ParagraphStyle* paragraphStyle, OH_ArkUI_RadialGradientOptions* radialGradient)](#oh_arkui_paragraphstyle_getradialgradient) | 获取段落样式的径向渐变。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTailIndents(OH_ArkUI_ParagraphStyle* paragraphStyle, const float* tailIndents, uint32_t size)](#oh_arkui_paragraphstyle_settailindents) | 设置段落样式的尾部缩进。 |
| [ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTailIndents(const OH_ArkUI_ParagraphStyle* paragraphStyle, float** tailIndents, uint32_t tailIndentsSize, uint32_t* writeLength)](#oh_arkui_paragraphstyle_gettailindents) | 获取段落样式的尾部缩进。 |

## 枚举类型说明

### OH_ArkUI_StyledStringKey

```c
enum OH_ArkUI_StyledStringKey
```

**描述**

属性字符串的样式类型枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_STYLEDSTRINGKEY_UNSPECIFIED = -1 | 未指定样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_FONT = 0 | 文本字体样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_DECORATION = 1 | 文本装饰线样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_BASELINE_OFFSET = 2 | 文本基线偏移量样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_LETTER_SPACING = 3 | 文本字符间距样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_TEXT_SHADOW = 4 | 文本阴影样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_LINE_HEIGHT = 5 | 文本行高样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_BACKGROUND_COLOR = 6 | 文本背景颜色样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_URL = 7 | 超链接样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_LINE_SPACING = 8 | 文本行间距样式。**起始版本：** 26.0.0 |
| OH_ARKUI_STYLEDSTRINGKEY_GESTURE = 100 | 事件手势样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_PARAGRAPH_STYLE = 200 | 文本段落样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_IMAGE = 300 | 图片样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_CUSTOM_SPAN = 400 | 自定义绘制Span样式。 |
| OH_ARKUI_STYLEDSTRINGKEY_USER_DATA = 500 | 用户数据Span样式。 |

### OH_ArkUI_SuperscriptStyle

```c
enum OH_ArkUI_SuperscriptStyle
```

**描述**

定义文本上下角标样式枚举。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_ARKUI_SUPERSCRIPTSTYLE_NORMAL = 0 | 普通文本样式，适用于不需要上下标效果的常规文本场景。 |
| OH_ARKUI_SUPERSCRIPTSTYLE_SUPERSCRIPT = 1 | 上标文本样式，适用于数学公式中的指数表示（如x²）或脚注引用标记等场景。 |
| OH_ARKUI_SUPERSCRIPTSTYLE_SUBSCRIPT = 2 | 下标文本样式，适用于化学式中的元素下标表示（如H₂O）或数学变量下标等场景。 |

## 函数说明

### OH_ArkUI_StyledString_Create()

```c
ArkUI_StyledString* OH_ArkUI_StyledString_Create(OH_Drawing_TypographyStyle* style, OH_Drawing_FontCollection* collection)
```

**描述**

创建指向ArkUI_StyledString对象的指针。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_StyledString_Destroy](#oh_arkui_styledstring_destroy)销毁它。

**起始版本：** 12

**参数：**

| 参数项 | 描述                                                                                                                                                               |
| -- |------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [OH_Drawing_TypographyStyle](../apis-arkgraphics2d/capi-drawing-oh-drawing-typographystyle.md)* style | 指向OH_Drawing_TypographyStyle的指针，由[OH_Drawing_CreateTypographyStyle](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_createtypographystyle)获取。 |
| [OH_Drawing_FontCollection](../apis-arkgraphics2d/capi-drawing-oh-drawing-fontcollection.md)* collection | 指向OH_Drawing_FontCollection的指针，由[OH_Drawing_CreateFontCollection](../apis-arkgraphics2d/capi-drawing-font-collection-h.md#oh_drawing_createfontcollection)获取。                                                                                    |

**返回：**

| 类型                      | 说明 |
|-------------------------| -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* | 创建指向ArkUI_StyledString对象的指针。如果返回空指针，表示创建失败，可能原因包括地址空间已满或参数异常（如style、collection为空指针）。 |

### OH_ArkUI_StyledString_Destroy()

```c
void OH_ArkUI_StyledString_Destroy(ArkUI_StyledString* handle)
```

**描述**

释放ArkUI_StyledString对象占用的内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |

### OH_ArkUI_StyledString_PushTextStyle()

```c
void OH_ArkUI_StyledString_PushTextStyle(ArkUI_StyledString* handle, OH_Drawing_TextStyle* style)
```

**描述**

将新的排版风格设置到当前格式化字符串样式栈顶。

>**说明：**
>
>调用此方法压入的样式，必须在使用完毕后调用[OH_ArkUI_StyledString_PopTextStyle](#oh_arkui_styledstring_poptextstyle)将其出栈。未出栈的样式会持续影响后续添加的文本排版。典型使用流程：PushTextStyle → AddText → PopTextStyle。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |
| [OH_Drawing_TextStyle](../apis-arkgraphics2d/capi-drawing-oh-drawing-textstyle.md)* style | 指向[OH_Drawing_TextStyle](../apis-arkgraphics2d/capi-drawing-oh-drawing-textstyle.md)对象的指针，由[OH_Drawing_CreateTextStyle](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_createtextstyle)创建获取。 |

### OH_ArkUI_StyledString_AddText()

```c
void OH_ArkUI_StyledString_AddText(ArkUI_StyledString* handle, const char* content)
```

**描述**

基于当前格式化字符串样式添加对应的文本内容。所添加的文本将使用当前栈顶的排版样式，该样式由[OH_ArkUI_StyledString_PushTextStyle](#oh_arkui_styledstring_pushtextstyle)压入。当栈顶样式通过[OH_ArkUI_StyledString_PopTextStyle](#oh_arkui_styledstring_poptextstyle)出栈后，后续添加的文本将使用新的栈顶样式。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |
| const char* content | 指向文本内容的指针。 |

### OH_ArkUI_StyledString_PopTextStyle()

```c
void OH_ArkUI_StyledString_PopTextStyle(ArkUI_StyledString* handle)
```

**描述**

将当前格式化字符串对象中栈顶样式出栈。

>**说明：**
>
>此方法必须在[OH_ArkUI_StyledString_PushTextStyle](#oh_arkui_styledstring_pushtextstyle)之后调用，用于将之前压入的样式从栈中移除。对空栈调用此方法不产生效果。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |

### OH_ArkUI_StyledString_CreateTypography()

```c
OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography(ArkUI_StyledString* handle)
```

**描述**

基于格式化字符串对象创建指向[OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)对象的指针，用于提前进行文本测算排版。

>**说明：**
>
>[OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)对象的生命周期由应用管理，当应用销毁该对象时，应同步调用[NODE_TEXT_CONTENT_WITH_STYLED_STRING](./capi-native-node-h-nodeattributetype-text.md#node_text_content_with_styled_string)对应的reset方法进行置空，避免野指针崩溃风险。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| [OH_Drawing_Typography](../apis-arkgraphics2d/capi-drawing-oh-drawing-typography.md)* | 指向OH_Drawing_Typography对象的指针。如果对象返回空指针，表示创建失败，失败的原因是handle参数为空指针。 |

### OH_ArkUI_StyledString_AddPlaceholder()

```c
void OH_ArkUI_StyledString_AddPlaceholder(ArkUI_StyledString* handle, OH_Drawing_PlaceholderSpan* placeholder)
```

**描述**

添加占位符，用于在格式化字符串中预留指定宽高的空白区域或嵌入自定义内容。其尺寸等信息由[OH_Drawing_PlaceholderSpan](../apis-arkgraphics2d/capi-drawing-oh-drawing-placeholderspan.md)指定。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString](capi-arkui-nativemodule-arkui-styledstring.md)* handle | 指向ArkUI_StyledString对象的指针。 |
| [OH_Drawing_PlaceholderSpan](../apis-arkgraphics2d/capi-drawing-oh-drawing-placeholderspan.md)* placeholder | 指向OH_Drawing_PlaceholderSpan对象的指针。 |

### OH_ArkUI_StyledString_Descriptor_Create()

```c
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_Create(void)
```

**描述**

创建属性字符串数据对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_StyledString_Descriptor_Destroy](#oh_arkui_styledstring_descriptor_destroy)销毁它。

**起始版本：** 14

**返回：**

| 类型                                 | 说明 |
|------------------------------------| -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* | 指向ArkUI_StyledString_Descriptor对象的指针，用于存储属性字符串的文本和样式信息。 |

### OH_ArkUI_StyledString_Descriptor_Destroy()

```c
void OH_ArkUI_StyledString_Descriptor_Destroy(ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

释放ArkUI_StyledString_Descriptor对象占用的内存。

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向ArkUI_StyledString_Descriptor对象的指针。 |

### OH_ArkUI_UnmarshallStyledStringDescriptor()

```c
int32_t OH_ArkUI_UnmarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

将包含属性字符串信息的字节数组反序列化为属性字符串。

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* buffer | 待反序列化的字节数组。 |
| size_t bufferSize | 字节数组长度。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向ArkUI_StyledString_Descriptor对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，可能原因包括传入参数为空指针或参数值不在有效范围内，请检查参数是否有效。 |

### OH_ArkUI_MarshallStyledStringDescriptor()

```c
int32_t OH_ArkUI_MarshallStyledStringDescriptor(uint8_t* buffer, size_t bufferSize, ArkUI_StyledString_Descriptor* descriptor, size_t* resultSize)
```

**描述**

将属性字符串信息序列化为字节数组。

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t* buffer | 字节数组，用于存储属性字符串序列化后的数据。 |
| size_t bufferSize | 字节数组长度。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向ArkUI_StyledString_Descriptor对象的指针。 |
| size_t* resultSize | 属性字符串转换后的字节数组实际长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，可能原因包括传入参数为空指针或参数值不在有效范围内，请检查参数是否有效。<br>        [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效，可能原因包括属性字符串对象已被销毁或未正确创建，请确保使用有效的属性字符串对象。 |

### OH_ArkUI_ConvertToHtml()

```c
const char* OH_ArkUI_ConvertToHtml(ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

将属性字符串信息转换成HTML。

**起始版本：** 14

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向ArkUI_StyledString_Descriptor对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | HTML。该指针由内部管理，在[OH_ArkUI_StyledString_Descriptor_Destroy()](#oh_arkui_styledstring_descriptor_destroy)时释放。 |

### OH_ArkUI_StyledString_Descriptor_CreateWithString()

```c
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithString(const char* value, const OH_ArkUI_SpanStyle** styles, int32_t length)
```

**描述**

创建纯文本内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_StyledString_Descriptor_Destroy](#oh_arkui_styledstring_descriptor_destroy)销毁它。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* value | 属性字符串的纯文本内容。 |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)** styles | 属性字符串的样式集合，指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象数组的指针。数组中每个OH_ArkUI_SpanStyle对象需先调用[OH_ArkUI_SpanStyle_SetStart](#oh_arkui_spanstyle_setstart)和[OH_ArkUI_SpanStyle_SetLength](#oh_arkui_spanstyle_setlength)设置样式作用的范围。 |
| int32_t length | 样式对象数组的数量。取值范围[0, +∞)，需与传入的styles指针所指向的数组实际长度一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* | 指向创建的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 <br>         如果结果为空指针，表示创建失败，失败的原因是传入参数为空指针或参数值无效。 |

### OH_ArkUI_StyledString_Descriptor_CreateWithImageAttachment()

```c
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithImageAttachment(const OH_ArkUI_ImageAttachment* value)
```

**描述**

创建图片内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_StyledString_Descriptor_Destroy](#oh_arkui_styledstring_descriptor_destroy)销毁它。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* value | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* | 指向创建的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 <br>         如果结果为空指针，表示创建失败，失败的原因是传入参数为空指针或参数值无效。 |

### OH_ArkUI_StyledString_Descriptor_CreateWithCustomSpan()

```c
ArkUI_StyledString_Descriptor* OH_ArkUI_StyledString_Descriptor_CreateWithCustomSpan(const OH_ArkUI_CustomSpan* value)
```

**描述**

创建自定义绘制Span内容类型的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_StyledString_Descriptor_Destroy](#oh_arkui_styledstring_descriptor_destroy)销毁它。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)* value | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* | 指向创建的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 <br>         如果结果为空指针，表示创建失败，失败的原因是传入参数为空指针或参数值无效。 |

### OH_ArkUI_StyledString_Descriptor_GetLength()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetLength(const ArkUI_StyledString_Descriptor* descriptor, int32_t* length)
```

**描述**

获取属性字符串的字符长度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| int32_t* length | 输出参数，用于接收属性字符串的字符长度结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，可能原因包括descriptor为空指针或length为空指针，请检查参数是否有效。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效，可能原因包括属性字符串对象已被销毁或未正确创建，请确保使用有效的属性字符串对象。 |

### OH_ArkUI_StyledString_Descriptor_GetString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetString(const ArkUI_StyledString_Descriptor* descriptor, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取属性字符串的文本内容。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| char* buffer | 文本内容写入内存的缓冲区，内存空间需由开发者分配。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 返回值为[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示实际写入缓冲区的长度。 <br>                      返回值为[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时表示字符串完整写入缓冲区所需要的最小长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常，可能原因包括descriptor为空指针、buffer为空指针或writeLength为空指针，请检查参数是否有效。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效，可能原因包括属性字符串对象已被销毁或未正确创建，请确保使用有效的属性字符串对象。 <br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区大小不足，当提供的bufferSize小于实际需要写入的数据长度时返回此错误码。处理步骤：通过writeLength参数获取所需最小缓冲区大小，重新分配足够大小的缓冲区后再次调用。 |

### OH_ArkUI_StyledString_Descriptor_IsEqual()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_IsEqual(const ArkUI_StyledString_Descriptor* firstDescriptor, const ArkUI_StyledString_Descriptor* secondDescriptor, bool* isEqual)
```

**描述**

判断两个属性字符串是否相同。当属性字符串的文本及样式均一致，视为相同。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* firstDescriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* secondDescriptor | 指向另一个[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| bool* isEqual | 两个属性字符串是否相同。true表示相同；false表示不相同。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_SubStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SubStyledString(const ArkUI_StyledString_Descriptor* descriptor, ArkUI_StyledString_Descriptor* subDescriptor, uint32_t start, uint32_t length)
```

**描述**

获取属性字符串的子属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* subDescriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)子属性字符串对象的指针。 |
| uint32_t start | 子属性字符串的起始位置。取值范围[0, 属性字符串的字符长度]，超出范围时返回ARKUI_ERROR_CODE_PARAM_INVALID。 |
| uint32_t length | 子属性字符串的字符长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_GetStyles()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_GetStyles(const ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey, OH_ArkUI_SpanStyle** styles, uint32_t stylesSize, uint32_t* writeLength)
```

**描述**

获取属性字符串指定范围内的样式集合。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 指定范围的起始位置。取值范围[0, 属性字符串的字符长度]。 |
| uint32_t length | 指定范围的长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |
| [OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey) styledKey | 需要获取的指定样式类型，取值为[OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey)中的枚举。 |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)** styles | 指向样式对象数组的缓冲区指针。 |
| uint32_t stylesSize | 样式对象数组的缓冲区大小。 |
| uint32_t* writeLength | 属性字符串中获取到的样式对象的数组的实际大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_FromHtml()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_FromHtml(ArkUI_StyledString_Descriptor* descriptor, const char* html)
```

**描述**

将HTML格式字符串转换成属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| const char* html | 待转换为属性字符串的HTML格式字符串，当前支持转换的HTML标签范围：\<p>、\<span>、\<img>、\<br>、\<strong>、\<b>、\<a>、\<i>、\<em>、\<s>、\<u>、\<del>、\<sup>、\<sub>、\<cite>、\<dfn>、\<small>、\<h1>、\<h2>、\<h3>、\<h4>、\<h5>、\<h6>、\<ol>、\<ul>、\<li>。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_ReplaceString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, const char* string)
```

**描述**

替换属性字符串指定范围的文本。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 指定范围的起始位置。取值范围[0, 属性字符串的字符长度]。 |
| uint32_t length | 指定范围的长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |
| const char* string | 替换的新文本内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_InsertString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const char* string)
```

**描述**

在属性字符串的指定位置插入文本。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 插入位置。取值范围[0, 属性字符串的字符长度]。 |
| const char* string | 插入的新文本内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_RemoveString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length)
```

**描述**

移除属性字符串指定范围的文本。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 指定范围的起始位置。取值范围[0, 属性字符串的字符长度]。 |
| uint32_t length | 指定范围的字符长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_ReplaceStyle()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyle(ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)
```

**描述**

替换属性字符串指定范围内的样式。与[OH_ArkUI_StyledString_Descriptor_SetStyle](#oh_arkui_styledstring_descriptor_setstyle)的区别：ReplaceStyle会清除指定范围内所有类型的已有样式后设置新样式；SetStyle为指定范围设置样式，只替换同类型的已有样式，不影响其他类型的样式。建议需要完全替换已有样式时使用ReplaceStyle，需要叠加设置样式时使用SetStyle。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 <br>                  需先调用[OH_ArkUI_SpanStyle_SetStart](#oh_arkui_spanstyle_setstart)和[OH_ArkUI_SpanStyle_SetLength](#oh_arkui_spanstyle_setlength)在该对象中设置目标范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_SetStyle()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_SetStyle(ArkUI_StyledString_Descriptor* descriptor, const OH_ArkUI_SpanStyle* spanStyle)
```

**描述**

为属性字符串指定范围设置新样式。与[OH_ArkUI_StyledString_Descriptor_ReplaceStyle](#oh_arkui_styledstring_descriptor_replacestyle)的区别：SetStyle为指定范围设置样式，只替换同类型的已有样式，不影响其他类型的样式，适用于叠加设置样式的场景；ReplaceStyle会清除指定范围内所有类型的已有样式后设置新样式，适用于完全替换已有样式的场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。需先调用[OH_ArkUI_SpanStyle_SetStart](#oh_arkui_spanstyle_setstart)和[OH_ArkUI_SpanStyle_SetLength](#oh_arkui_spanstyle_setlength)在该对象中设置目标范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_RemoveStyle()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_RemoveStyle(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, OH_ArkUI_StyledStringKey styledKey)
```

**描述**

清除属性字符串指定范围内的指定类型样式。

>**说明：**
>
>被清除后属性样式取TextEditor组件对应类型属性的默认值（如清除TextStyle后取TextEditor的字体默认样式）。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 指定范围的起始位置。取值范围[0, 属性字符串的字符长度]。 |
| uint32_t length | 指定范围的长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |
| [OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey) styledKey | 样式类型枚举值，取值为[OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_ClearStyles()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ClearStyles(ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

清除属性字符串对象的所有样式。

>**说明：**
>
>被清除后属性样式取TextEditor组件对应类型属性的默认值（如清除TextStyle后取TextEditor的字体默认样式）。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_ReplaceStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_ReplaceStyledString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, uint32_t length, const ArkUI_StyledString_Descriptor* other)
```

**描述**

替换指定范围的属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 指定范围的起始位置。取值范围[0, 属性字符串的字符长度]。 |
| uint32_t length | 指定范围的长度。取值范围[0, 属性字符串的字符长度与参数start的差值]。 |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* other | 指向新的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_InsertStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InsertStyledString(ArkUI_StyledString_Descriptor* descriptor, uint32_t start, const ArkUI_StyledString_Descriptor* other)
```

**描述**

在属性字符串的指定位置插入新的属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| uint32_t start | 插入位置。取值范围[0, 属性字符串的字符长度]。 |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* other | 指向新的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_AppendStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_AppendStyledString(ArkUI_StyledString_Descriptor* descriptor, const ArkUI_StyledString_Descriptor* other)
```

**描述**

在属性字符串的末尾追加新的属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* other | 指向新的[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_StyledString_Descriptor_InvalidateCustomSpan()

```c
ArkUI_ErrorCode OH_ArkUI_StyledString_Descriptor_InvalidateCustomSpan(const ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

主动刷新属性字符串中的自定义绘制Span。

>**说明：**
>
>调用该接口会立即触发通过[OH_ArkUI_CustomSpan_RegisterOnDrawCallback](#oh_arkui_customspan_registerondrawcallback)注册在自定义绘制Span上的回调函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_INVALID_STYLED_STRING](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 属性字符串无效。 |

### OH_ArkUI_TextStyle_Create()

```c
OH_ArkUI_TextStyle* OH_ArkUI_TextStyle_Create()
```

**描述**

创建[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_TextStyle_Destroy](#oh_arkui_textstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针，用于定义文本字体样式。 |

### OH_ArkUI_TextStyle_Destroy()

```c
void OH_ArkUI_TextStyle_Destroy(OH_ArkUI_TextStyle* textStyle)
```

**描述**

释放[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |

### OH_ArkUI_TextStyle_SetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontColor(OH_ArkUI_TextStyle* textStyle, uint32_t fontColor)
```

**描述**

设置文本字体样式中的字体颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t fontColor | 字体颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontColor)
```

**描述**

获取文本字体样式中的字体颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t* fontColor | 字体颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontFamily(OH_ArkUI_TextStyle* textStyle, const char* fontFamily)
```

**描述**

设置文本字体样式中的字体族。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| const char* fontFamily | 字体族。存放待设置的字体名称，不同字体名称通过逗号拼接。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontFamily(const OH_ArkUI_TextStyle* textStyle, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取文本字体样式中的字体族。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| char* buffer | 字体族内容写入内存的缓冲区，内存空间需由开发者分配。 |
| int32_t bufferSize | 缓冲区最多可写入的字符的数量。 |
| int32_t* writeLength | 返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示实际写入缓冲区的字符串长度。 <br>                    返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示字符串完整写入缓冲区所需要的最小长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区大小不足，当提供的bufferSize小于实际需要写入的数据长度时返回此错误码。处理步骤：通过writeLength参数获取所需最小缓冲区大小，重新分配足够大小的缓冲区后再次调用。 |

### OH_ArkUI_TextStyle_SetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontSize(OH_ArkUI_TextStyle* textStyle, float fontSize)
```

**描述**

设置文本字体样式中的字体大小。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| float fontSize | 字体大小，单位为vp。取值范围[0, +∞)。传入负数时使用默认字体大小。默认值为16vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontSize(const OH_ArkUI_TextStyle* textStyle, float* fontSize)
```

**描述**

获取文本字体样式中的字体大小。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| float* fontSize | 字体大小，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontWeight(OH_ArkUI_TextStyle* textStyle, uint32_t fontWeight)
```

**描述**

设置文本字体样式中的字体粗细。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t fontWeight | 字体粗细。取值为[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)中的枚举值，默认值为ARKUI_FONT_WEIGHT_W400。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontWeight(const OH_ArkUI_TextStyle* textStyle, uint32_t* fontWeight)
```

**描述**

获取文本字体样式中的字体粗细。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t* fontWeight | 字体粗细。取值为[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)中的枚举值，默认值为ARKUI_FONT_WEIGHT_W400。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetFontStyle(OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle fontStyle)
```

**描述**

设置文本字体样式中的字体风格。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle) fontStyle | 字体风格。取值为[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetFontStyle(const OH_ArkUI_TextStyle* textStyle, ArkUI_FontStyle* fontStyle)
```

**描述**

获取文本字体样式中的字体风格。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)* fontStyle | 字体风格。取值为[ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetStrokeWidth()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeWidth(OH_ArkUI_TextStyle* textStyle, float strokeWidth)
```

**描述**

设置文本字体样式中的描边宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| float strokeWidth | 描边宽度，取值范围(-∞, +∞)，单位为vp。值小于0时为实体字，大于0时为轮廓字，等于0时无描边效果。默认值：0vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetStrokeWidth()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeWidth(const OH_ArkUI_TextStyle* textStyle, float* strokeWidth)
```

**描述**

获取文本字体样式中的描边宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| float* strokeWidth | 描边宽度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetStrokeColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetStrokeColor(OH_ArkUI_TextStyle* textStyle, uint32_t strokeColor)
```

**描述**

设置文本字体样式中的描边颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t strokeColor | 描边颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetStrokeColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetStrokeColor(const OH_ArkUI_TextStyle* textStyle, uint32_t* strokeColor)
```

**描述**

获取文本字体样式中的描边颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| uint32_t* strokeColor | 描边颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_SetSuperscript()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_SetSuperscript(OH_ArkUI_TextStyle* textStyle, OH_ArkUI_SuperscriptStyle superscript)
```

**描述**

设置文本字体样式中的上下标样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| [OH_ArkUI_SuperscriptStyle](#oh_arkui_superscriptstyle) superscript | 上下标样式。取值为[OH_ArkUI_SuperscriptStyle](#oh_arkui_superscriptstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextStyle_GetSuperscript()

```c
ArkUI_ErrorCode OH_ArkUI_TextStyle_GetSuperscript(const OH_ArkUI_TextStyle* textStyle, OH_ArkUI_SuperscriptStyle* superscript)
```

**描述**

获取文本字体样式中的上下标样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |
| [OH_ArkUI_SuperscriptStyle](#oh_arkui_superscriptstyle)* superscript | 上下标样式。取值为[OH_ArkUI_SuperscriptStyle](#oh_arkui_superscriptstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_Create()

```c
OH_ArkUI_SpanStyle* OH_ArkUI_SpanStyle_Create()
```

**描述**

创建[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_SpanStyle_Destroy](#oh_arkui_spanstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针，用于设置属性字符串样式的作用范围和具体样式。 |

### OH_ArkUI_SpanStyle_Destroy()

```c
void OH_ArkUI_SpanStyle_Destroy(OH_ArkUI_SpanStyle* spanStyle)
```

**描述**

释放[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |

### OH_ArkUI_SpanStyle_GetStyledKey()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStyledKey(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_StyledStringKey* styledKey)
```

**描述**

获取属性字符串样式对象的样式类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey)* styledKey | 样式类型的枚举值。取值为[OH_ArkUI_StyledStringKey](#oh_arkui_styledstringkey)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetStart()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetStart(OH_ArkUI_SpanStyle* spanStyle, int32_t start)
```

**描述**

设置属性字符串样式对象的起始位置。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| int32_t start | 属性字符串样式对象的起始位置，需与[OH_ArkUI_SpanStyle_SetLength](#oh_arkui_spanstyle_setlength)配合使用以指定样式作用的范围。取值范围[0, 属性字符串的长度]，超出范围时按0处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetStart()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetStart(const OH_ArkUI_SpanStyle* spanStyle, int32_t* start)
```

**描述**

获取属性字符串样式对象的起始位置。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| int32_t* start | 属性字符串样式对象的起始位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetLength()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLength(OH_ArkUI_SpanStyle* spanStyle, int32_t length)
```

**描述**

设置属性字符串样式对象的长度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| int32_t length | 属性字符串样式对象的长度，需与[OH_ArkUI_SpanStyle_SetStart](#oh_arkui_spanstyle_setstart)配合使用以指定样式作用的范围。当length的值小于0或超出字符串长度与start的差值时，按字符串长度与start的差值处理。取值范围[0, 属性字符串的长度与参数start的差值]，按字符串长度与start的差值处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetLength()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLength(const OH_ArkUI_SpanStyle* spanStyle, int32_t* length)
```

**描述**

获取属性字符串样式对象的长度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| int32_t* length | 属性字符串样式对象的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetTextStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextStyle* textStyle)
```

**描述**

设置属性字符串样式对象的文本字体样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetTextStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextStyle* textStyle)
```

**描述**

获取属性字符串样式对象的文本字体样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)* textStyle | 指向[OH_ArkUI_TextStyle](capi-arkui-nativemodule-oh-arkui-textstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetParagraphStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetParagraphStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ParagraphStyle* paragraphStyle)
```

**描述**

设置属性字符串样式对象的段落样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的TextStyle、GestureStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetParagraphStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetParagraphStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ParagraphStyle* paragraphStyle)
```

**描述**

获取属性字符串样式对象的段落样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetGestureStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetGestureStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_GestureStyle* gestureStyle)
```

**描述**

设置属性字符串样式对象的事件手势样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的TextStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetGestureStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetGestureStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_GestureStyle* gestureStyle)
```

**描述**

获取属性字符串样式对象的事件手势样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetTextShadowStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetTextShadowStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_TextShadowStyle* textShadowStyle)
```

**描述**

设置属性字符串样式对象的文本阴影样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* textShadowStyle | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetTextShadowStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetTextShadowStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_TextShadowStyle* textShadowStyle)
```

**描述**

获取属性字符串样式对象的文本阴影样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* textShadowStyle | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetDecorationStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_DecorationStyle* decorationStyle)
```

**描述**

设置属性字符串样式对象的文本装饰线样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetDecorationStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_DecorationStyle* decorationStyle)
```

**描述**

获取属性字符串样式对象的文本装饰线样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetBaselineOffsetStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBaselineOffsetStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
```

**描述**

设置属性字符串样式对象的基线偏移量样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* baselineOffsetStyle | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetBaselineOffsetStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBaselineOffsetStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
```

**描述**

获取属性字符串样式对象的基线偏移量样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* baselineOffsetStyle | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetLetterSpacingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLetterSpacingStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
```

**描述**

设置属性字符串样式对象的字符间距样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* letterSpacingStyle | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetLetterSpacingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLetterSpacingStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
```

**描述**

获取属性字符串样式对象的字符间距样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* letterSpacingStyle | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetLineHeightStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLineHeightStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LineHeightStyle* lineHeightStyle)
```

**描述**

设置属性字符串样式对象的行高样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetLineHeightStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLineHeightStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LineHeightStyle* lineHeightStyle)
```

**描述**

获取属性字符串样式对象的行高样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetUrlStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUrlStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UrlStyle* urlStyle)
```

**描述**

设置属性字符串样式对象的超链接样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* urlStyle | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetUrlStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUrlStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UrlStyle* urlStyle)
```

**描述**

获取属性字符串样式对象的超链接样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* urlStyle | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetBackgroundColorStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetBackgroundColorStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)
```

**描述**

设置属性字符串样式对象的背景颜色样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* backgroundColorStyle | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetBackgroundColorStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetBackgroundColorStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_BackgroundColorStyle* backgroundColorStyle)
```

**描述**

获取属性字符串样式对象的背景颜色样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* backgroundColorStyle | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetUserDataSpan()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetUserDataSpan(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_UserDataSpan* userDataSpan)
```

**描述**

设置属性字符串样式对象的用户数据Span样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* userDataSpan | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetUserDataSpan()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetUserDataSpan(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_UserDataSpan* userDataSpan)
```

**描述**

获取属性字符串样式对象的用户数据Span样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* userDataSpan | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetCustomSpan()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetCustomSpan(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_CustomSpan* customSpan)
```

**描述**

设置属性字符串样式对象的自定义绘制Span样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)* customSpan | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetCustomSpan()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetCustomSpan(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_CustomSpan* customSpan)
```

**描述**

获取属性字符串样式对象的自定义绘制Span样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)* customSpan | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetImageAttachment()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetImageAttachment(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_ImageAttachment* imageAttachment)
```

**描述**

设置属性字符串样式对象的图片样式。

>**说明：**
>
>此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetImageAttachment()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetImageAttachment(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_ImageAttachment* imageAttachment)
```

**描述**

获取属性字符串样式对象的图片样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_Create()

```c
OH_ArkUI_LeadingMarginSpanDrawInfo* OH_ArkUI_LeadingMarginSpanDrawInfo_Create()
```

**描述**

创建[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy](#oh_arkui_leadingmarginspandrawinfo_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针，用于定义段落缩进的自定义绘制信息。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy()

```c
void OH_ArkUI_LeadingMarginSpanDrawInfo_Destroy(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo)
```

**描述**

释放[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetX()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetX(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float x)
```

**描述**

设置段落缩进的自定义绘制信息对象中当前行相对于组件的水平偏移。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float x | 当前行相对于组件的水平偏移，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetX()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetX(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* x)
```

**描述**

获取段落缩进的自定义绘制信息对象中当前行相对于组件的水平偏移。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float* x | 当前行相对于组件的水平偏移，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetTop()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTop(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float top)
```

**描述**

设置段落缩进的自定义绘制信息对象中行顶与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float top | 行顶与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetTop()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTop(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* top)
```

**描述**

获取段落缩进的自定义绘制信息对象中行顶与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float* top | 行顶与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetBottom()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBottom(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float bottom)
```

**描述**

设置段落缩进的自定义绘制信息对象中行底与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float bottom | 行底与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetBottom()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBottom(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* bottom)
```

**描述**

获取段落缩进的自定义绘制信息对象中行底与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float* bottom | 行底与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetBaseline()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetBaseline(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float baseline)
```

**描述**

设置段落缩进的自定义绘制信息对象中当前行的基线与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float baseline | 当前行的基线与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetBaseline()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetBaseline(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, float* baseline)
```

**描述**

获取段落缩进的自定义绘制信息对象中当前行的基线与组件上边缘的距离。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| float* baseline | 当前行的基线与组件上边缘的距离，单位px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetTextDirection(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, ArkUI_TextDirection direction)
```

**描述**

设置段落缩进的自定义绘制信息对象中文本内容的方向。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection) direction | 文本内容的方向。取值为[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetTextDirection(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, ArkUI_TextDirection* direction)
```

**描述**

获取段落缩进的自定义绘制信息对象中文本内容的方向。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)* direction | 文本内容的方向。取值为[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetStart()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetStart(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t start)
```

**描述**

设置段落缩进的自定义绘制信息对象中当前行的起始索引。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| uint32_t start | 当前行的起始索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetStart()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetStart(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t* start)
```

**描述**

获取段落缩进的自定义绘制信息对象中当前行的起始索引。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| uint32_t* start | 当前行的起始索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetEnd()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetEnd(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t end)
```

**描述**

设置段落缩进的自定义绘制信息对象中当前行的结束索引。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| uint32_t end | 当前行的结束索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetEnd()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetEnd(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, uint32_t* end)
```

**描述**

获取段落缩进的自定义绘制信息对象中当前行的结束索引。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| uint32_t* end | 当前行的结束索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_SetFirst()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_SetFirst(OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, bool first)
```

**描述**

设置段落缩进的自定义绘制信息对象中当前行是否为段落的首行。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| bool first | 当前行是否为段落的首行。true表示首行；false表示非首行。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LeadingMarginSpanDrawInfo_GetFirst()

```c
ArkUI_ErrorCode OH_ArkUI_LeadingMarginSpanDrawInfo_GetFirst(const OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo, bool* first)
```

**描述**

获取段落缩进的自定义绘制信息对象中当前行是否为段落的首行。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)* drawInfo | 指向[OH_ArkUI_LeadingMarginSpanDrawInfo](capi-arkui-nativemodule-oh-arkui-leadingmarginspandrawinfo.md)对象的指针。 |
| bool* first | 当前行是否为段落的首行。true表示首行；false表示非首行。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_Create()

```c
OH_ArkUI_ParagraphStyle* OH_ArkUI_ParagraphStyle_Create()
```

**描述**

创建[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_ParagraphStyle_Destroy](#oh_arkui_paragraphstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针，用于定义段落样式。 |

### OH_ArkUI_ParagraphStyle_Destroy()

```c
void OH_ArkUI_ParagraphStyle_Destroy(OH_ArkUI_ParagraphStyle* paragraphStyle)
```

**描述**

释放[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |

### OH_ArkUI_ParagraphStyle_SetTextAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextAlign(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextAlignment align)
```

**描述**

设置段落样式中的水平方向的文本对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment) align | 水平方向的文本对齐方式。取值为[ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetTextAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextAlignment* align)
```

**描述**

获取段落样式中的水平方向的文本对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)* align | 水平方向的文本对齐方式。取值为[ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetTextIndent()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextIndent(OH_ArkUI_ParagraphStyle* paragraphStyle, float textIndent)
```

**描述**

设置段落样式中的首行文本缩进。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| float textIndent | 首行缩进值，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetTextIndent()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextIndent(const OH_ArkUI_ParagraphStyle* paragraphStyle, float* textIndent)
```

**描述**

获取段落样式中的首行文本缩进。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| float* textIndent | 首行缩进值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetMaxLines()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetMaxLines(OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t maxLines)
```

**描述**

设置段落样式中的最大行数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| int32_t maxLines | 最大行数。取值范围[0, +∞)。传入负数时不限制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetMaxLines()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetMaxLines(const OH_ArkUI_ParagraphStyle* paragraphStyle, int32_t* maxLines)
```

**描述**

获取段落样式中的最大行数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| int32_t* maxLines | 最大行数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetOverflow()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetOverflow(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextOverflow overflow)
```

**描述**

设置段落样式中的段落超长时的显示方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow) overflow | 段落超长时的显示方式。取值为[ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetOverflow()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetOverflow(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextOverflow* overflow)
```

**描述**

获取段落样式中的段落超长时的显示方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow)* overflow | 段落超长时的显示方式。取值为[ArkUI_TextOverflow](capi-text-common-h.md#arkui_textoverflow)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetWordBreak()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetWordBreak(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_WordBreak wordBreak)
```

**描述**

设置段落样式中的断行规则。不同断行策略适用于不同场景，具体请参考[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)枚举值。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak) wordBreak | 断行规则。取值为[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetWordBreak()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetWordBreak(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_WordBreak* wordBreak)
```

**描述**

获取段落样式中的断行规则。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)* wordBreak | 断行规则。取值为[ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetLeadingMarginPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginPixelMap(OH_ArkUI_ParagraphStyle* paragraphStyle, struct OH_PixelmapNative* pixelmap)
```

**描述**

设置段落样式中的段落缩进的像素图。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| struct [OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)* pixelmap | 段落缩进的像素图。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetLeadingMarginPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginPixelMap(const OH_ArkUI_ParagraphStyle* paragraphStyle, struct OH_PixelmapNative** pixelmap)
```

**描述**

获取段落样式中的段落缩进的像素图。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| struct [OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)** pixelmap | 段落缩进的像素图。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetLeadingMarginWidth()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t width)
```

**描述**

设置段落样式中的段落缩进宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t width | 段落缩进宽度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetLeadingMarginWidth()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginWidth(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* width)
```

**描述**

获取段落样式中的段落缩进宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t* width | 段落缩进宽度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetLeadingMarginHeight()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t height)
```

**描述**

设置段落样式中的段落缩进高度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t height | 段落缩进高度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetLeadingMarginHeight()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLeadingMarginHeight(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* height)
```

**描述**

获取段落样式中的段落缩进高度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t* height | 段落缩进高度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetParagraphSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetParagraphSpacing(OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t paragraphSpacing)
```

**描述**

设置段落样式中的段落间距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t paragraphSpacing | 段落间距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetParagraphSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetParagraphSpacing(const OH_ArkUI_ParagraphStyle* paragraphStyle, uint32_t* paragraphSpacing)
```

**描述**

获取段落样式中的段落间距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| uint32_t* paragraphSpacing | 段落间距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetTextVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextVerticalAlign(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextVerticalAlignment verticalAlignment)
```

**描述**

设置段落样式中的垂直方向的文本对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment) verticalAlignment | 垂直方向的文本对齐方式。取值为[ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetTextVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextVerticalAlign(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextVerticalAlignment* verticalAlignment)
```

**描述**

获取段落样式中的垂直方向的文本对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)* verticalAlignment | 垂直方向的文本对齐方式。取值为[ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnDrawLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle, void(*onDraw)(ArkUI_DrawContext* context, OH_ArkUI_LeadingMarginSpanDrawInfo* drawInfo))
```

**描述**

注册段落样式中绘制段落缩进时触发的回调函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)\* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| void(\*onDraw)(ArkUI_DrawContext\* context, OH_ArkUI_LeadingMarginSpanDrawInfo\* drawInfo) | 绘制段落缩进时触发的回调函数。回调参数：context为图形绘制上下文，drawInfo为段落缩进的自定义绘制信息对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_RegisterOnGetLeadingMarginCallback()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_RegisterOnGetLeadingMarginCallback(OH_ArkUI_ParagraphStyle* paragraphStyle, float(*leadingMargin)())
```

**描述**

设置段落样式中获取段落缩进距离时触发的回调函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)\* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| float(\*leadingMargin)() | 获取段落缩进距离时触发的回调函数。回调返回值表示段落缩进距离，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTextDirection(OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextDirection textDirection)
```

**描述**

设置段落样式中的文本方向。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection) textDirection | 文本方向。取值为[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTextDirection(const OH_ArkUI_ParagraphStyle* paragraphStyle, ArkUI_TextDirection* textDirection)
```

**描述**

获取段落样式中的文本方向。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)* textDirection | 文本方向。取值为[ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GestureStyle_Create()

```c
OH_ArkUI_GestureStyle* OH_ArkUI_GestureStyle_Create()
```

**描述**

创建[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_GestureStyle_Destroy](#oh_arkui_gesturestyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)* | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针，用于定义事件手势样式。 |

### OH_ArkUI_GestureStyle_Destroy()

```c
void OH_ArkUI_GestureStyle_Destroy(OH_ArkUI_GestureStyle* gestureStyle)
```

**描述**

释放[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |

### OH_ArkUI_GestureStyle_RegisterOnClickCallback()

```c
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnClickCallback(OH_ArkUI_GestureStyle* gestureStyle, void(*onClick)(ArkUI_NodeEvent*))
```

**描述**

注册事件手势样式中的点击事件回调。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)\* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |
| void(\*onClick)(ArkUI_NodeEvent\*) | 点击事件的回调函数。回调参数：event为节点事件对象，包含点击事件的相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GestureStyle_RegisterOnLongPressCallback()

```c
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnLongPressCallback(OH_ArkUI_GestureStyle* gestureStyle, void(*onLongPress)(ArkUI_GestureEvent*))
```

**描述**

注册事件手势样式中的长按事件回调。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)\* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |
| void(\*onLongPress)(ArkUI_GestureEvent\*) | 长按事件的回调函数。回调参数：event为手势事件对象，包含长按事件的相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_GestureStyle_RegisterOnTouchCallback()

```c
ArkUI_ErrorCode OH_ArkUI_GestureStyle_RegisterOnTouchCallback(OH_ArkUI_GestureStyle* gestureStyle, void(*onTouch)(ArkUI_NodeEvent*))
```

**描述**

注册事件手势样式中的触摸事件回调。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)\* gestureStyle | 指向[OH_ArkUI_GestureStyle](capi-arkui-nativemodule-oh-arkui-gesturestyle.md)对象的指针。 |
| void(\*onTouch)(ArkUI_NodeEvent\*) | 触摸事件的回调函数。回调参数：event为节点事件对象，包含触摸事件的相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextShadowStyle_Create()

```c
OH_ArkUI_TextShadowStyle* OH_ArkUI_TextShadowStyle_Create()
```

**描述**

创建[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_TextShadowStyle_Destroy](#oh_arkui_textshadowstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针，用于定义文本阴影样式。 |

### OH_ArkUI_TextShadowStyle_Destroy()

```c
void OH_ArkUI_TextShadowStyle_Destroy(OH_ArkUI_TextShadowStyle* textShadowStyle)
```

**描述**

释放[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* textShadowStyle | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针。 |

### OH_ArkUI_TextShadowStyle_SetTextShadow()

```c
ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_SetTextShadow(OH_ArkUI_TextShadowStyle* textShadowStyle, const OH_ArkUI_ShadowOptions** options, uint32_t length)
```

**描述**

设置文本阴影样式的文本阴影选项。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* textShadowStyle | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针。 |
| const [OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)** options | 文本阴影选项，指向[OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)对象数组的指针。 |
| uint32_t length | 文本阴影选项数组元素的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextShadowStyle_GetTextShadow()

```c
ArkUI_ErrorCode OH_ArkUI_TextShadowStyle_GetTextShadow(const OH_ArkUI_TextShadowStyle* textShadowStyle, OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)
```

**描述**

获取文本阴影样式的文本阴影选项。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)* textShadowStyle | 指向[OH_ArkUI_TextShadowStyle](capi-arkui-nativemodule-oh-arkui-textshadowstyle.md)对象的指针。 |
| [OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)** shadowOptions | 文本阴影选项，指向[OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)对象数组的指针。 |
| uint32_t shadowOptionsSize | 阴影选项的缓冲区大小。 |
| uint32_t* writeLength | 文本阴影样式中实际的文本阴影选项数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_Create()

```c
OH_ArkUI_DecorationStyle* OH_ArkUI_DecorationStyle_Create()
```

**描述**

创建[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_DecorationStyle_Destroy](#oh_arkui_decorationstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针，用于定义文本装饰线样式。 |

### OH_ArkUI_DecorationStyle_Destroy()

```c
void OH_ArkUI_DecorationStyle_Destroy(OH_ArkUI_DecorationStyle* decorationStyle)
```

**描述**

释放[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |

### OH_ArkUI_DecorationStyle_SetTextDecorationType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationType(OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationType type)
```

**描述**

设置文本装饰线样式的装饰线类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype) type | 装饰线类型。取值为[ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_GetTextDecorationType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationType(const OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationType* type)
```

**描述**

获取文本装饰线样式的装饰线类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)* type | 装饰线类型。取值为[ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_SetColor()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetColor(OH_ArkUI_DecorationStyle* decorationStyle, uint32_t color)
```

**描述**

设置文本装饰线样式的装饰线颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| uint32_t color | 装饰线颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_GetColor()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetColor(const OH_ArkUI_DecorationStyle* decorationStyle, uint32_t* color)
```

**描述**

获取文本装饰线样式的装饰线颜色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| uint32_t* color | 装饰线颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_SetTextDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetTextDecorationStyle(OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationStyle style)
```

**描述**

设置文本装饰线样式的装饰线样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle) style | 装饰线样式。取值为[ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_GetTextDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetTextDecorationStyle(const OH_ArkUI_DecorationStyle* decorationStyle, ArkUI_TextDecorationStyle* style)
```

**描述**

获取文本装饰线样式的装饰线样式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)* style | 装饰线样式。取值为[ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_SetThicknessScale()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetThicknessScale(OH_ArkUI_DecorationStyle* decorationStyle, float thicknessScale)
```

**描述**

设置文本装饰线样式的装饰线的粗细缩放比例。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| float thicknessScale | 装饰线的粗细缩放比例。取值范围为[0, +∞)。传入负数时不生效。默认值：1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_GetThicknessScale()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetThicknessScale(const OH_ArkUI_DecorationStyle* decorationStyle, float* thicknessScale)
```

**描述**

获取文本装饰线样式的装饰线的粗细缩放比例。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| float* thicknessScale | 装饰线的粗细缩放比例。取值范围为[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_SetEnableMultiType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_SetEnableMultiType(OH_ArkUI_DecorationStyle* decorationStyle, bool enableMultiType)
```

**描述**

设置文本装饰线样式中是否开启多装饰线显示。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| bool enableMultiType | 是否开启多装饰线显示。传入true时开启多装饰线显示，允许同时显示多种类型的装饰线（如同时显示下划线和删除线），适用于需要复合装饰效果的场景；传入false时不开启，仅显示单一类型装饰线，适用于只需要一种装饰线的场景。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_DecorationStyle_GetEnableMultiType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyle_GetEnableMultiType(const OH_ArkUI_DecorationStyle* decorationStyle, bool* enableMultiType)
```

**描述**

获取文本装饰线样式中是否开启多装饰线显示。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)* decorationStyle | 指向[OH_ArkUI_DecorationStyle](capi-arkui-nativemodule-oh-arkui-decorationstyle.md)对象的指针。 |
| bool* enableMultiType | 是否开启多装饰线显示。true表示开启，false表示关闭。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BaselineOffsetStyle_Create()

```c
OH_ArkUI_BaselineOffsetStyle* OH_ArkUI_BaselineOffsetStyle_Create()
```

**描述**

创建[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_BaselineOffsetStyle_Destroy](#oh_arkui_baselineoffsetstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针，用于定义基线偏移量样式。 |

### OH_ArkUI_BaselineOffsetStyle_Destroy()

```c
void OH_ArkUI_BaselineOffsetStyle_Destroy(OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle)
```

**描述**

释放[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* baselineOffsetStyle | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针。 |

### OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset()

```c
ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_SetBaselineOffset(OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float baselineOffset)
```

**描述**

设置基线偏移量。适用于需要调整文本基线位置的场景，例如上下角标定位、行内图标与文字垂直对齐等。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* baselineOffsetStyle | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针。 |
| float baselineOffset | 基线偏移量，单位为vp。取值范围(-∞, +∞)。正值与负值分别对应不同的偏移方向，0表示无偏移。具体方向效果需结合上下角标等场景确定。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BaselineOffsetStyle_GetBaselineOffset()

```c
ArkUI_ErrorCode OH_ArkUI_BaselineOffsetStyle_GetBaselineOffset(const OH_ArkUI_BaselineOffsetStyle* baselineOffsetStyle, float* baselineOffset)
```

**描述**

获取基线偏移量。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)* baselineOffsetStyle | 指向[OH_ArkUI_BaselineOffsetStyle](capi-arkui-nativemodule-oh-arkui-baselineoffsetstyle.md)对象的指针。 |
| float* baselineOffset | 基线偏移量，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LetterSpacingStyle_Create()

```c
OH_ArkUI_LetterSpacingStyle* OH_ArkUI_LetterSpacingStyle_Create()
```

**描述**

创建[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_LetterSpacingStyle_Destroy](#oh_arkui_letterspacingstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针，用于定义字符间距样式。 |

### OH_ArkUI_LetterSpacingStyle_Destroy()

```c
void OH_ArkUI_LetterSpacingStyle_Destroy(OH_ArkUI_LetterSpacingStyle* letterSpacingStyle)
```

**描述**

释放[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* letterSpacingStyle | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针。 |

### OH_ArkUI_LetterSpacingStyle_SetLetterSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_SetLetterSpacing(OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float letterSpacing)
```

**描述**

设置字符间距。适用于需要调整文字间距的场景，例如标题加宽间距提升可读性、紧凑排版缩小间距等。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* letterSpacingStyle | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针。 |
| float letterSpacing | 字符间距值，单位为vp。取值范围(-∞, +∞)。正值表示加宽字符间距，负值表示缩小字符间距，0表示使用默认间距。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LetterSpacingStyle_GetLetterSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_LetterSpacingStyle_GetLetterSpacing(const OH_ArkUI_LetterSpacingStyle* letterSpacingStyle, float* letterSpacing)
```

**描述**

获取字符间距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)* letterSpacingStyle | 指向[OH_ArkUI_LetterSpacingStyle](capi-arkui-nativemodule-oh-arkui-letterspacingstyle.md)对象的指针。 |
| float* letterSpacing | 字符间距值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineHeightStyle_Create()

```c
OH_ArkUI_LineHeightStyle* OH_ArkUI_LineHeightStyle_Create()
```

**描述**

创建[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_LineHeightStyle_Destroy](#oh_arkui_lineheightstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针，用于定义行高样式。 |

### OH_ArkUI_LineHeightStyle_Destroy()

```c
void OH_ArkUI_LineHeightStyle_Destroy(OH_ArkUI_LineHeightStyle* lineHeightStyle)
```

**描述**

释放[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |

### OH_ArkUI_LineHeightStyle_SetLineHeight()

```c
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_SetLineHeight(OH_ArkUI_LineHeightStyle* lineHeightStyle, float lineHeight)
```

**描述**

设置文本行高。

>**说明：**
>
>与[OH_ArkUI_LineHeightStyle_SetLineHeightMultiple](#oh_arkui_lineheightstyle_setlineheightmultiple)同时设置时，仅lineHeightMultiple生效，lineHeight不生效。lineHeightMultiple小于0时不生效，此时使用lineHeight设置行高。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |
| float lineHeight | 固定行高值，单位为vp。与[OH_ArkUI_LineHeightStyle_SetLineHeightMultiple](#oh_arkui_lineheightstyle_setlineheightmultiple)同时设置时，仅lineHeightMultiple生效，lineHeight不生效，lineHeightMultiple小于0时不生效，此时使用lineHeight设置行高。取值范围(-∞, +∞)，负值表示自适应字体大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineHeightStyle_GetLineHeight()

```c
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_GetLineHeight(const OH_ArkUI_LineHeightStyle* lineHeightStyle, float* lineHeight)
```

**描述**

获取文本行高。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |
| float* lineHeight | 固定行高值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |


### OH_ArkUI_LineHeightStyle_SetLineHeightMultiple()

```c
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_SetLineHeightMultiple(OH_ArkUI_LineHeightStyle* lineHeightStyle, float lineHeightMultiple)
```

**描述**

设置行高样式的行高倍数。

> **说明：**
>
> - lineHeightMultiple与lineHeight或[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)同时设置时，仅lineHeightMultiple生效，行高为该行最高字体高度与倍数的乘积。
>
> - lineHeightMultiple小于0时不生效，使用lineHeight和[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)设置行高和行间距。
>
> - lineHeight可以通过[OH_ArkUI_LineHeightStyle_SetLineHeight()](#oh_arkui_lineheightstyle_setlineheight)接口设置。
>
> - lineHeightMultiple等于0时等效于设置为1。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |
| float lineHeightMultiple | 行高倍数。取值范围为[0, +∞)。传入负数时不生效，传入0时等效于设置为1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineHeightStyle_GetLineHeightMultiple()

```c
ArkUI_ErrorCode OH_ArkUI_LineHeightStyle_GetLineHeightMultiple(const OH_ArkUI_LineHeightStyle* lineHeightStyle, float* lineHeightMultiple)
```

**描述**

获取行高样式的行高倍数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)* lineHeightStyle | 指向[OH_ArkUI_LineHeightStyle](capi-arkui-nativemodule-oh-arkui-lineheightstyle.md)对象的指针。 |
| float* lineHeightMultiple | 行高倍数。取值范围为[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_SetLineSpacingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_SetLineSpacingStyle(OH_ArkUI_SpanStyle* spanStyle, const OH_ArkUI_LineSpacingStyle* lineSpacingStyle)
```

**描述**

设置属性字符串样式对象的行间距样式。

> **说明：**
>
> 此操作会替换[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象中已设置的其他类型样式。一个SpanStyle对象只能持有一种类型的样式，设置新类型样式后，之前已设置的其他类型样式（如已设置的GestureStyle、ParagraphStyle等）将被清除。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| const [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SpanStyle_GetLineSpacingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_SpanStyle_GetLineSpacingStyle(const OH_ArkUI_SpanStyle* spanStyle, OH_ArkUI_LineSpacingStyle* lineSpacingStyle)
```

**描述**

获取属性字符串样式对象的行间距样式。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)* spanStyle | 指向[OH_ArkUI_SpanStyle](capi-arkui-nativemodule-oh-arkui-spanstyle.md)对象的指针。 |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针，用于定义行间距样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineSpacingStyle_Create()

```c
OH_ArkUI_LineSpacingStyle* OH_ArkUI_LineSpacingStyle_Create()
```

**描述**

创建[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象。

> **说明：**
> 
> 当该对象不再使用时，调用[OH_ArkUI_LineSpacingStyle_Destroy](#oh_arkui_linespacingstyle_destroy)销毁它。

**起始版本：** 26.0.0

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针，用于定义行间距样式。 |

### OH_ArkUI_LineSpacingStyle_Destroy()

```c
void OH_ArkUI_LineSpacingStyle_Destroy(OH_ArkUI_LineSpacingStyle* lineSpacingStyle)
```

**描述**

释放[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象占用的内存。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |

### OH_ArkUI_LineSpacingStyle_SetLineSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_SetLineSpacing(OH_ArkUI_LineSpacingStyle* lineSpacingStyle, float lineSpacing)
```

**描述**

设置行间距。

>**说明：**
>
>与[OH_ArkUI_LineHeightStyle_SetLineHeightMultiple](#oh_arkui_lineheightstyle_setlineheightmultiple)同时设置时，仅lineHeightMultiple生效，行间距不生效。lineHeightMultiple小于0时不生效，此时行间距正常生效。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |
| float lineSpacing | 行间距值，单位为vp。取值范围(-∞, +∞)。与[OH_ArkUI_LineHeightStyle_SetLineHeightMultiple](#oh_arkui_lineheightstyle_setlineheightmultiple)同时设置时，仅lineHeightMultiple生效，行间距不生效。lineHeightMultiple小于0时不生效，此时行间距正常生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineSpacingStyle_GetLineSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_GetLineSpacing(const OH_ArkUI_LineSpacingStyle* lineSpacingStyle, float* lineSpacing)
```

**描述**

获取行间距。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |
| float* lineSpacing | 行间距值，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineSpacingStyle_SetOnlyBetweenLines()

```c
ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_SetOnlyBetweenLines(OH_ArkUI_LineSpacingStyle* lineSpacingStyle, bool onlyBetweenLines)
```

**描述**

设置行间距是否只在行间生效。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |
| bool onlyBetweenLines | 行间距是否只在行间生效。true表示仅在行与行之间添加间距，首行上方、尾行下方无额外间距，false表示所有行之间、首行上方、尾行下方均添加完整行间距。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_LineSpacingStyle_GetOnlyBetweenLines()

```c
ArkUI_ErrorCode OH_ArkUI_LineSpacingStyle_GetOnlyBetweenLines(const OH_ArkUI_LineSpacingStyle* lineSpacingStyle, bool* onlyBetweenLines)
```

**描述**

获取行间距是否只在行间生效。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)* lineSpacingStyle | 指向[OH_ArkUI_LineSpacingStyle](capi-arkui-nativemodule-oh-arkui-linespacingstyle.md)对象的指针。 |
| bool* onlyBetweenLines | 行间距是否只在行间生效。true表示仅在行与行之间添加间距，首行上方、尾行下方无额外间距，false表示所有行之间、首行上方、尾行下方均添加完整行间距。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BackgroundColorStyle_Create()

```c
OH_ArkUI_BackgroundColorStyle* OH_ArkUI_BackgroundColorStyle_Create()
```

**描述**

创建[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_BackgroundColorStyle_Destroy](#oh_arkui_backgroundcolorstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针，用于定义背景颜色样式。 |

### OH_ArkUI_BackgroundColorStyle_Destroy()

```c
void OH_ArkUI_BackgroundColorStyle_Destroy(OH_ArkUI_BackgroundColorStyle* style)
```

**描述**

释放[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* style | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |

### OH_ArkUI_BackgroundColorStyle_SetColor()

```c
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetColor(OH_ArkUI_BackgroundColorStyle* style, uint32_t color)
```

**描述**

设置背景颜色样式的背景色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* style | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |
| uint32_t color | 背景颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BackgroundColorStyle_GetColor()

```c
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetColor(const OH_ArkUI_BackgroundColorStyle* style, uint32_t* color)
```

**描述**

获取背景颜色样式的背景色。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* style | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |
| uint32_t* color | 背景颜色，0xARGB格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BackgroundColorStyle_SetRadius()

```c
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_SetRadius(OH_ArkUI_BackgroundColorStyle* style, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**描述**

设置背景颜色样式的背景圆角。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* style | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |
| float topLeft | 左上角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float topRight | 右上角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float bottomLeft | 左下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float bottomRight | 右下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_BackgroundColorStyle_GetRadius()

```c
ArkUI_ErrorCode OH_ArkUI_BackgroundColorStyle_GetRadius(const OH_ArkUI_BackgroundColorStyle* style, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)
```

**描述**

获取背景颜色样式的背景圆角。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)* style | 指向[OH_ArkUI_BackgroundColorStyle](capi-arkui-nativemodule-oh-arkui-backgroundcolorstyle.md)对象的指针。 |
| float* topLeft | 左上角圆角半径，单位为vp。 |
| float* topRight | 右上角圆角半径，单位为vp。 |
| float* bottomLeft | 左下角圆角半径，单位为vp。 |
| float* bottomRight | 右下角圆角半径，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_UrlStyle_Create()

```c
OH_ArkUI_UrlStyle* OH_ArkUI_UrlStyle_Create()
```

**描述**

创建[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_UrlStyle_Destroy](#oh_arkui_urlstyle_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针，用于定义超链接样式。 |

### OH_ArkUI_UrlStyle_Destroy()

```c
void OH_ArkUI_UrlStyle_Destroy(OH_ArkUI_UrlStyle* style)
```

**描述**

释放[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* style | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针。 |

### OH_ArkUI_UrlStyle_SetUrl()

```c
ArkUI_ErrorCode OH_ArkUI_UrlStyle_SetUrl(OH_ArkUI_UrlStyle* style, const char* url)
```

**描述**

设置超链接样式的超链接内容。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* style | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针。 |
| const char* url | 超链接内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_UrlStyle_GetUrl()

```c
ArkUI_ErrorCode OH_ArkUI_UrlStyle_GetUrl(const OH_ArkUI_UrlStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取超链接样式的超链接内容。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)* style | 指向[OH_ArkUI_UrlStyle](capi-arkui-nativemodule-oh-arkui-urlstyle.md)对象的指针。 |
| char* buffer | 超链接内容写入内存的缓冲区，内存空间需由开发者分配。 |
| int32_t bufferSize | 缓冲区最多可写入的字符的数量。 |
| int32_t* writeLength | 返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示实际写入缓冲区的字符的数量。 <br>                    返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示字符串完整写入缓冲区所需要的最小长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区大小不足，可通过writeLength参数获取所需最小缓冲区大小，重新分配足够大小的缓冲区后再次调用。 |

### OH_ArkUI_UserDataSpan_Create()

```c
OH_ArkUI_UserDataSpan* OH_ArkUI_UserDataSpan_Create()
```

**描述**

创建[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_UserDataSpan_Destroy](#oh_arkui_userdataspan_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针，用于定义用户数据Span样式。 |

### OH_ArkUI_UserDataSpan_Destroy()

```c
void OH_ArkUI_UserDataSpan_Destroy(OH_ArkUI_UserDataSpan* userDataSpan)
```

**描述**

释放[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* userDataSpan | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针。 |

### OH_ArkUI_UserDataSpan_SetUserData()

```c
ArkUI_ErrorCode OH_ArkUI_UserDataSpan_SetUserData(OH_ArkUI_UserDataSpan* userDataSpan, void* userData)
```

**描述**

设置用户数据Span样式中的用户数据。

>**说明：**
>
>该接口允许开发者将任意类型的自定义数据关联到当前的样式对象上。用于在属性字符串中存储用户数据。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* userDataSpan | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针。 |
| void* userData | 用户数据，生命周期需由开发者自行管理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_UserDataSpan_GetUserData()

```c
ArkUI_ErrorCode OH_ArkUI_UserDataSpan_GetUserData(const OH_ArkUI_UserDataSpan* userDataSpan, void** userData)
```

**描述**

获取用户数据Span样式中的用户数据。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)* userDataSpan | 指向[OH_ArkUI_UserDataSpan](capi-arkui-nativemodule-oh-arkui-userdataspan.md)对象的指针。 |
| void** userData | 用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomSpan_Create()

```c
OH_ArkUI_CustomSpan* OH_ArkUI_CustomSpan_Create()
```

**描述**

创建[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_CustomSpan_Destroy](#oh_arkui_customspan_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)* | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针，用于定义自定义绘制Span。 |

### OH_ArkUI_CustomSpan_Destroy()

```c
void OH_ArkUI_CustomSpan_Destroy(OH_ArkUI_CustomSpan* customSpan)
```

**描述**

释放[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)* customSpan | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |

### OH_ArkUI_CustomSpan_RegisterOnMeasureCallback()

```c
ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnMeasureCallback(OH_ArkUI_CustomSpan* customSpan, ArkUI_CustomSpanMetrics*(*onMeasure)(float))
```

**描述**

设置自定义绘制Span获取尺寸大小时的回调函数。适用于在文本中嵌入自定义内容（如自定义图标、内联控件、特殊表情等）时，需要根据内容计算占用尺寸的场景。回调返回的尺寸将影响该Span在文本排版中的占位大小。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)\* customSpan | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |
| ArkUI_CustomSpanMetrics\*(\*onMeasure)(float) | 获取尺寸大小的回调函数。fontSize为组件中的文本字体大小，单位为fp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_CustomSpan_RegisterOnDrawCallback()

```c
ArkUI_ErrorCode OH_ArkUI_CustomSpan_RegisterOnDrawCallback(OH_ArkUI_CustomSpan* customSpan, void(*onDraw)(ArkUI_DrawContext*, ArkUI_CustomSpanDrawInfo*))
```

**描述**

注册自定义绘制Span绘制时的回调函数。适用于需要绘制非标准文本内容的场景，例如在文本中绘制自定义图标、装饰图形、特殊标记等。通过该回调，开发者可以使用图形绘制上下文实现任意自定义绘制效果。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)\* customSpan | 指向[OH_ArkUI_CustomSpan](capi-arkui-nativemodule-oh-arkui-customspan.md)对象的指针。 |
| void(\*onDraw)(ArkUI_DrawContext\*, ArkUI_CustomSpanDrawInfo\*) | 绘制时的回调函数。回调参数：context为图形绘制上下文，drawInfo为自定义绘制Span的绘制信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_Create()

```c
OH_ArkUI_ImageAttachment* OH_ArkUI_ImageAttachment_Create()
```

**描述**

创建[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象。

>**说明：**
>
>当该对象不再使用时，调用[OH_ArkUI_ImageAttachment_Destroy](#oh_arkui_imageattachment_destroy)销毁它。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针，用于定义图片样式对象。 |

### OH_ArkUI_ImageAttachment_Destroy()

```c
void OH_ArkUI_ImageAttachment_Destroy(OH_ArkUI_ImageAttachment* imageAttachment)
```

**描述**

释放[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象占用的内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |

### OH_ArkUI_ImageAttachment_SetPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPixelMap(OH_ArkUI_ImageAttachment* imageAttachment, struct OH_PixelmapNative* pixelmap)
```

**描述**

设置图片样式中的图片数据源。

>**说明：**
>
>与[OH_ArkUI_ImageAttachment_SetResource](#oh_arkui_imageattachment_setresource)同时设置时，后设置的生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| struct [OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)* pixelmap | 图片数据源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPixelMap(const OH_ArkUI_ImageAttachment* imageAttachment, struct OH_PixelmapNative** pixelmap)
```

**描述**

获取图片样式中的图片数据源。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| struct [OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)** pixelmap | 图片数据源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetResource()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetResource(OH_ArkUI_ImageAttachment* imageAttachment, const char* resource)
```

**描述**

设置图片样式中的图片资源地址。

>**说明：**
>
>与[OH_ArkUI_ImageAttachment_SetPixelMap](#oh_arkui_imageattachment_setpixelmap)同时设置时，后设置的生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| const char* resource | 图片资源地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetResource()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetResource(const OH_ArkUI_ImageAttachment* imageAttachment, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取图片样式中的图片资源地址。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| char* buffer | 图片资源地址字符串写入内存的缓冲区，内存空间需由开发者分配。 |
| int32_t bufferSize | 缓冲区大小。 |
| int32_t* writeLength | 返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示实际写入缓冲区的字符串长度。 <br>                    返回[ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)时，表示字符串完整写入缓冲区所需要的最小长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区大小不足。 |

### OH_ArkUI_ImageAttachment_SetSizeWidth()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeWidth(OH_ArkUI_ImageAttachment* imageAttachment, float width)
```

**描述**

设置图片样式中的图片宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float width | 图片宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetSizeWidth()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeWidth(const OH_ArkUI_ImageAttachment* imageAttachment, float* width)
```

**描述**

获取图片样式中的图片宽度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float* width | 图片宽度，单位为vp。取值范围：[0, +∞)。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetSizeHeight()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSizeHeight(OH_ArkUI_ImageAttachment* imageAttachment, float height)
```

**描述**

设置图片样式中的图片高度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float height | 图片高度，单位为vp。取值范围：[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetSizeHeight()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSizeHeight(const OH_ArkUI_ImageAttachment* imageAttachment, float* height)
```

**描述**

获取图片样式中的图片高度。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float* height | 图片高度，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetVerticalAlign(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ImageSpanAlignment verticalAlign)
```

**描述**

设置图片样式中的图片对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment) verticalAlign | 图片对齐方式。取值为[ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetVerticalAlign(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ImageSpanAlignment* verticalAlign)
```

**描述**

获取图片样式中的图片对齐方式。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment)* verticalAlign | 图片对齐方式。取值为[ArkUI_ImageSpanAlignment](capi-image-span-h.md#arkui_imagespanalignment)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetObjectFit()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetObjectFit(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit objectFit)
```

**描述**

设置图片样式中的图片缩放类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_ObjectFit](capi-image-h.md#arkui_objectfit) objectFit | 图片缩放类型。取值为[ArkUI_ObjectFit](capi-image-h.md#arkui_objectfit)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetObjectFit()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetObjectFit(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_ObjectFit* objectFit)
```

**描述**

获取图片样式中的图片缩放类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_ObjectFit](capi-image-h.md#arkui_objectfit)* objectFit | 图片缩放类型。取值为[ArkUI_ObjectFit](capi-image-h.md#arkui_objectfit)中的枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetMargin()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetMargin(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin margin)
```

**描述**

设置图片样式中的图片外边距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) margin | 图片外边距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetMargin()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetMargin(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin* margin)
```

**描述**

获取图片样式中的图片外边距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md)* margin | 图片外边距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetPadding()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetPadding(OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin padding)
```

**描述**

设置图片样式中的图片内边距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) padding | 图片内边距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetPadding()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetPadding(const OH_ArkUI_ImageAttachment* imageAttachment, ArkUI_Margin* padding)
```

**描述**

获取图片样式中的图片内边距。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md)* padding | 图片内边距，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetBorderRadiuses()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetBorderRadiuses(OH_ArkUI_ImageAttachment* imageAttachment, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**描述**

设置图片样式中的图片圆角。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float topLeft | 左上角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float topRight | 右上角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float bottomLeft | 左下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |
| float bottomRight | 右下角圆角半径，单位为vp。取值范围：[0, +∞)。传入负数时使用默认值0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetBorderRadiuses()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetBorderRadiuses(const OH_ArkUI_ImageAttachment* imageAttachment, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)
```

**描述**

获取图片样式中的图片圆角。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float* topLeft | 左上角圆角半径，单位为vp。取值范围[0, +∞)。 |
| float* topRight | 右上角圆角半径，单位为vp。取值范围[0, +∞)。 |
| float* bottomLeft | 左下角圆角半径，单位为vp。取值范围[0, +∞)。 |
| float* bottomRight | 右下角圆角半径，单位为vp。取值范围[0, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetColorFilter()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetColorFilter(OH_ArkUI_ImageAttachment* imageAttachment, const float* colorFilter, uint32_t size)
```

**描述**

设置图片样式中的图片颜色过滤器。

>**说明：**
>
>与[OH_ArkUI_ImageAttachment_SetDrawingColorFilter](#oh_arkui_imageattachment_setdrawingcolorfilter)同时设置时，后设置的生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| const float* colorFilter | 图片颜色过滤器，float类型数组，包含颜色矩阵变换系数，用于对图片进行颜色变换，数组长度由参数size指定。 |
| uint32_t size | 颜色过滤器数组的元素数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetColorFilter()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetColorFilter(const OH_ArkUI_ImageAttachment* imageAttachment, float** colorFilter, uint32_t colorFilterSize, uint32_t* writeLength)
```

**描述**

获取图片样式中的图片颜色过滤器。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| float** colorFilter | 图片颜色过滤器写入内存的缓冲区，内存空间需由开发者分配。 |
| uint32_t colorFilterSize | 缓冲区大小。 |
| uint32_t* writeLength | 图片颜色过滤器数组的实际大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 <br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区大小不足。 |

### OH_ArkUI_ImageAttachment_SetDrawingColorFilter()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetDrawingColorFilter(OH_ArkUI_ImageAttachment* imageAttachment, const OH_Drawing_ColorFilter* drawingColorFilter)
```

**描述**

设置图片样式中的图片颜色滤镜。

>**说明：**
>
>与[OH_ArkUI_ImageAttachment_SetColorFilter](#oh_arkui_imageattachment_setcolorfilter)同时设置时，后设置的生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| const [OH_Drawing_ColorFilter](../apis-arkgraphics2d/capi-drawing-oh-drawing-colorfilter.md)* drawingColorFilter | 图片颜色滤镜。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetDrawingColorFilter()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetDrawingColorFilter(const OH_ArkUI_ImageAttachment* imageAttachment, OH_Drawing_ColorFilter* drawingColorFilter)
```

**描述**

获取图片样式中的图片颜色滤镜。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| [OH_Drawing_ColorFilter](../apis-arkgraphics2d/capi-drawing-oh-drawing-colorfilter.md)* drawingColorFilter | 图片颜色滤镜。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetSyncLoad()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSyncLoad(OH_ArkUI_ImageAttachment* imageAttachment, bool syncLoad)
```

**描述**

设置图片样式中是否同步加载图片。

>**说明：**
>
>此属性仅在通过[OH_ArkUI_ImageAttachment_SetResource](#oh_arkui_imageattachment_setresource)设置图片源为资源地址时生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| bool syncLoad | 是否同步加载图片。true表示同步加载，同步加载时阻塞UI线程，不会显示占位图；false表示异步加载。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetSyncLoad()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSyncLoad(const OH_ArkUI_ImageAttachment* imageAttachment, bool* syncLoad)
```

**描述**

获取图片样式中是否同步加载图片。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| bool* syncLoad | 是否同步加载图片。true表示同步加载；false表示异步加载。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_SetSupportSvg()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_SetSupportSvg(OH_ArkUI_ImageAttachment* imageAttachment, bool supportSvg)
```

**描述**

设置图片样式中是否开启SVG标签解析能力增强功能。开启后可解析更丰富的SVG标签及属性，提升SVG图片的渲染兼容性。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| bool supportSvg | 是否开启SVG标签解析能力增强功能。true表示开启；false表示不开启。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ImageAttachment_GetSupportSvg()

```c
ArkUI_ErrorCode OH_ArkUI_ImageAttachment_GetSupportSvg(const OH_ArkUI_ImageAttachment* imageAttachment, bool* supportSvg)
```

**描述**

获取图片样式中是否开启SVG标签解析能力增强功能。开启后可解析更丰富的SVG标签及属性，提升SVG图片的渲染兼容性。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)* imageAttachment | 指向[OH_ArkUI_ImageAttachment](capi-arkui-nativemodule-oh-arkui-imageattachment.md)对象的指针。 |
| bool* supportSvg | 是否开启SVG标签解析能力增强功能。true表示开启；false表示未开启。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextEditorChangeEvent_GetRangeBefore()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetRangeBefore(const OH_ArkUI_TextEditorChangeEvent* event, uint32_t* start, uint32_t* end)
```

**描述**

获取文本变化信息中待被替换的原文本的范围。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_ArkUI_TextEditorChangeEvent* event | 指向[OH_ArkUI_TextEditorChangeEvent](capi-arkui-nativemodule-oh-arkui-texteditorchangeevent.md)对象的指针。 |
| uint32_t* start | 待替换内容范围的起始索引。 |
| uint32_t* end | 待替换内容范围的结束索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextEditorChangeEvent_GetReplacementStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetReplacementStyledString(const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

获取文本变化信息中的用于替换的属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_ArkUI_TextEditorChangeEvent* event | 指向[OH_ArkUI_TextEditorChangeEvent](capi-arkui-nativemodule-oh-arkui-texteditorchangeevent.md)对象的指针。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextEditorChangeEvent_GetPreviewStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorChangeEvent_GetPreviewStyledString(const OH_ArkUI_TextEditorChangeEvent* event, ArkUI_StyledString_Descriptor* descriptor)
```

**描述**

获取文本变化信息中的预览内容属性字符串。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_ArkUI_TextEditorChangeEvent* event | 指向[OH_ArkUI_TextEditorChangeEvent](capi-arkui-nativemodule-oh-arkui-texteditorchangeevent.md)对象的指针。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | 指向[ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果码。 <br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 操作成功。 <br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_Dispose()

```c
void OH_ArkUI_TextLayoutManager_Dispose(ArkUI_TextLayoutManager* layoutManager)
```

**描述**

释放文本布局管理器对象占用的内存。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向ArkUI_TextLayoutManager对象的指针。 |

### OH_ArkUI_TextLayoutManager_GetLineCount()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineCount(ArkUI_TextLayoutManager* layoutManager, int32_t* outLineCount)
```

**描述**

获取文本行数。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向ArkUI_TextLayoutManager对象的指针。 |
| int32_t* outLineCount | 文本行数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_GetRectsForRange()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetRectsForRange(ArkUI_TextLayoutManager* layoutManager, int32_t start, int32_t end, OH_Drawing_RectWidthStyle widthStyle, OH_Drawing_RectHeightStyle heightStyle, OH_Drawing_TextBox** outTextBoxes)
```

**描述**

获取给定的矩形区域宽度样式以及高度样式的规格下，文本中任意区间范围内的字符或占位符所占的绘制区域信息。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向ArkUI_TextLayoutManager对象的指针。 |
| int32_t start | 起始位置索引，start取值需要大于等于0，否则会返回参数异常。 |
| int32_t end | 结束位置索引，end取值需要大于等于start，否则会返回参数异常。 |
| [OH_Drawing_RectWidthStyle](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_rectwidthstyle) widthStyle | 矩形区域宽度样式。 |
| [OH_Drawing_RectHeightStyle](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_rectheightstyle) heightStyle | 矩形区域高度样式。 |
| [OH_Drawing_TextBox](../apis-arkgraphics2d/capi-drawing-oh-drawing-textbox.md)** outTextBoxes | 指向OH_Drawing_TextBox对象的二级指针。 |

**返回：**

| 类型 | 说明 |
| ---- | --- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |


### OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate(ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)
```

**描述**

获取距离给定坐标最近的字形(glyph)的位置信息。返回的位置索引基于字形单位而非字符单位——字形是渲染视觉单位，与字符(character)可能存在多对多映射关系。例如文本为“世界Hello”，其字形索引范围为[0, 7]，一个汉字占三个字符，其对应的字符索引范围为[0, 11]。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| ------ | --- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向ArkUI_TextLayoutManager对象的指针。 |
| double dx | 相对于控件的x坐标，单位为px。 |
| double dy | 相对于控件的y坐标，单位为px。 |
| [OH_Drawing_PositionAndAffinity](../apis-arkgraphics2d/capi-drawing-oh-drawing-positionandaffinity.md)** outPos | 指向OH_Drawing_PositionAndAffinity对象的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_GetLineMetrics()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetLineMetrics(ArkUI_TextLayoutManager* layoutManager, int32_t lineNumber, OH_Drawing_LineMetrics* outMetrics)
```

**描述**

获取指定行的行信息、文本样式信息、以及字体属性信息。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向ArkUI_TextLayoutManager对象的指针。 |
| int32_t lineNumber | 指定行的行号索引，行号索引从0开始计数，lineNumber小于0或大于等于文本行数时会返回参数异常。 |
| [OH_Drawing_LineMetrics](../apis-arkgraphics2d/capi-drawing-oh-drawing-linemetrics.md)* outMetrics | 指向OH_Drawing_LineMetrics对象的指针。 |

**返回：**

| 类型 | 说明 |
| ---- | --- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_GetCharacterPositionAtCoordinate()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterPositionAtCoordinate(ArkUI_TextLayoutManager* layoutManager, double dx, double dy, OH_Drawing_PositionAndAffinity** outPos)
```

**描述**

获取距离指定坐标最近的字符的位置信息。

与OH_ArkUI_TextLayoutManager_GetGlyphPositionAtCoordinate的区别：此方法返回字符级别的位置信息，适用于文本编辑、光标定位等基于字符编码的场景；而GetGlyphPositionAtCoordinate返回字形级别的位置信息，适用于渲染相关的精确定位场景。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| ------ | --- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向[ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)对象的指针。 |
| double dx | 相对于控件的x坐标，单位为px。 |
| double dy | 相对于控件的y坐标，单位为px。 |
| [OH_Drawing_PositionAndAffinity](../apis-arkgraphics2d/capi-drawing-oh-drawing-positionandaffinity.md)** outPos | 指向[OH_Drawing_PositionAndAffinity](../apis-arkgraphics2d/capi-drawing-oh-drawing-positionandaffinity.md)对象的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_GetGlyphRangeForCharacterRange()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetGlyphRangeForCharacterRange(ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* charRange, OH_Drawing_Range** outGlyphRange,
OH_Drawing_Range** outActualCharRange);
```

**描述**

获取由指定字符索引范围所生成的字形索引范围以及实际的字符索引范围。例如文本为“世界Hello”，其中文本“世”的字形索引范围为[0, 1]，一个汉字占三个字符，所以其对应的字符索引范围为[0, 3]。如果指定的字符索引范围是[0, 1]，但无法解析出三分之一个汉字，所以实际的字符索引范围是[0, 3]。outGlyphRange、outActualCharRange返回的[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象在使用完成后，需通过[OH_Drawing_ReleaseRangeBuffer](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_releaserangebuffer)释放。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| ------ | --- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向[ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)对象的指针。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)* charRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的指针，表示字符索引范围。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)** outGlyphRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的二级指针，表示字形索引范围。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)** outActualCharRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的二级指针，表示实际的字符索引范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TextLayoutManager_GetCharacterRangeForGlyphRange()

```c
ArkUI_ErrorCode OH_ArkUI_TextLayoutManager_GetCharacterRangeForGlyphRange(ArkUI_TextLayoutManager* layoutManager, OH_Drawing_Range* glyphRange, OH_Drawing_Range** outCharRange,
OH_Drawing_Range** outActualGlyphRange)
```

**描述**

获取由指定字形索引范围所生成的字符索引范围以及实际的字形索引范围。例如文本为“世界Hello”，其字形索引范围为[0, 7]，一个汉字占三个字符，所以其对应的字符索引范围为[0, 11]。如果指定的索引范围是[0, 11]，但字形一共只有7个，所以实际的字形索引范围是[0, 7]。outCharRange、outActualGlyphRange返回的[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象在使用完成后，需通过[OH_Drawing_ReleaseRangeBuffer](../apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_releaserangebuffer)释放。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| ------ | --- |
| [ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)* layoutManager | 指向[ArkUI_TextLayoutManager](capi-arkui-nativemodule-arkui-textlayoutmanager.md)对象的指针。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)* glyphRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的指针，表示字形索引范围。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)** outCharRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的二级指针，表示字符索引范围。 |
| [OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)** outActualGlyphRange | 指向[OH_Drawing_Range](../apis-arkgraphics2d/capi-drawing-oh-drawing-range.md)对象的二级指针，表示实际的字形索引范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br> [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br> [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetLinearGradient()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetLinearGradient(OH_ArkUI_ParagraphStyle* paragraphStyle, const OH_ArkUI_LinearGradientOptions* linearGradient)
```

**描述**

设置段落样式的线性渐变。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| const [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* linearGradient | 指向[OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetLinearGradient()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetLinearGradient(const OH_ArkUI_ParagraphStyle* paragraphStyle, OH_ArkUI_LinearGradientOptions* linearGradient)
```

**描述**

获取段落样式的线性渐变。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* linearGradient | 指向[OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetRadialGradient()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetRadialGradient(OH_ArkUI_ParagraphStyle* paragraphStyle, const OH_ArkUI_RadialGradientOptions* radialGradient)
```

**描述**

设置段落样式的径向渐变。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| const [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* radialGradient | 指向[OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_GetRadialGradient()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetRadialGradient(const OH_ArkUI_ParagraphStyle* paragraphStyle, OH_ArkUI_RadialGradientOptions* radialGradient)
```

**描述**

获取段落样式的径向渐变。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* radialGradient | 指向[OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ParagraphStyle_SetTailIndents()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_SetTailIndents(OH_ArkUI_ParagraphStyle* paragraphStyle, const float* tailIndents, uint32_t size)
```

**描述**

设置段落样式的尾部缩进。

> **说明：** 
> 
> 所有输入指针参数必须由调用者负责分配、管理和释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| const float* tailIndents | 尾部缩进值数组。单位：fp。取值范围：[0, +∞)。其有效长度由size指定。若size等于1，则所有文本行使用相同的尾部缩进值tailIndents[0]；若size大于1，则第i行（从0开始计数）使用tailIndents[i]作为尾部缩进值。当文本行数超过size时，超出部分的行将复用tailIndents[size - 1]的值做缩进。|
| uint32_t size | tailIndents数组中有效尾部缩进值的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |


### OH_ArkUI_ParagraphStyle_GetTailIndents()

```c
ArkUI_ErrorCode OH_ArkUI_ParagraphStyle_GetTailIndents(const OH_ArkUI_ParagraphStyle* paragraphStyle, float** tailIndents, uint32_t tailIndentsSize, uint32_t* writeLength)
```

**描述**

获取段落样式的尾部缩进。

> **说明：** 
>
> 所有输入指针参数必须由调用者负责分配、管理和释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)* paragraphStyle | 指向[OH_ArkUI_ParagraphStyle](capi-arkui-nativemodule-oh-arkui-paragraphstyle.md)对象的指针。 |
| float** tailIndents | 尾部缩进值，单位为fp。 |
| uint32_t tailIndentsSize | tailIndents缓冲区大小。 |
| uint32_t* writeLength | 实际写入缓冲区的尾部缩进值个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | 返回结果。<br>        [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>        [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>        [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 缓冲区长度小于最小缓冲区长度。 |