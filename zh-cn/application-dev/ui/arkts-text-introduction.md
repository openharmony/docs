# 文本概述
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiangyuan6-->
<!--SE: @pssea-->
<!--TSE: @jiaoaozihao-->

文本包含用户输入的信息、呈现的文本内容和小图标，这些元素共同构建了用户与系统间的交互界面，提升了操作的便捷性与信息展示的直观性。

开发者可根据实际应用场景选择合适的文本组件进行页面开发。

## 文本显示

主要用于显示静态文本。开发者可以使用Text组件配合Span组件创建文本节点，也可以使用属性字符串（[StyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#styledstring)/[MutableStyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#mutablestyledstring)）节点生成文本信息并接入Text组件。参考[文本显示 (Text/Span)](arkts-common-components-text-display.md)章节。

## 文本输入

当需要在单行输入框（TextInput）或多行输入框（TextArea）中输入纯文本时，应优先考虑使用此文本组件。参考[文本输入 (TextInput/TextArea)](arkts-common-components-text-input.md)章节。

## 富文本

当需要在编辑框内插入图片或者自定义图标等需求时，应优先考虑使用此文本组件。参考[富文本 (RichEditor)](arkts-common-components-richeditor.md)章节。

## 图标小符号

当需要显示小图标时，应优先考虑使用此图标组件。参考[图标小符号 (SymbolGlyph/SymbolSpan)](arkts-common-components-symbol.md)章节。

## 属性字符串

当需要在字符或者段落级别设置文本样式，包括调整字号、添加字体颜色、使文本具备可点击性，以及通过自定义方式绘制文本等场景时，应优先考虑使用属性字符串。参考[属性字符串 (StyledString/MutableStyledString)](arkts-styled-string.md)章节。

## 图文混排

当需要图片和文字混排的场景，可以使用Span和ImageSpan实现。若需要样式多样的混排效果，可以选择属性字符串实现。参考[图文混排](arkts-text-image-layout.md)章节。