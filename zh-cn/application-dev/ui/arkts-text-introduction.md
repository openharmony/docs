# 文本概述

文本包含用户输入的信息、呈现的文本内容和小图标，这些元素共同构建了用户与系统间的交互界面，提升了操作的便捷性与信息展示的直观性。

开发者可根据实际应用场景选择合适的文本组件进行页面开发。

| 文本组件名称 |  应用场景 |
| -------- | -------- |
| 文本（[Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md)/[Span](../reference/apis-arkui/arkui-ts/ts-basic-components-span.md)） | 主要用于显示静态文本。开发者可以使用Text组件配合Span组件创建文本节点，也可以使用属性字符串（[StyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#styledstring)/[MutableStyledString](../reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#mutablestyledstring)）节点生成文本信息并接入Text组件。 |
| 文本输入（[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)/[TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md)） | 当需要在单行输入框（TextInput）或多行输入框（TextArea）中输入纯文本时，应优先考虑使用此文本组件。 |
| 富文本（[RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md)） | 当需要在编辑框内插入图片或者自定义图标等需求时，应优先考虑使用此文本组件。 |
| 图标小符号（[SymbolGlyph](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolGlyph.md)/[SymbolSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-symbolSpan.md)） | 当需要显示小图标时，应优先考虑使用此图标组件。 |