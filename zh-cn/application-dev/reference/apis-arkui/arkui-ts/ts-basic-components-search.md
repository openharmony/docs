#  Search

搜索框组件，适用于浏览器的搜索内容输入框等应用场景。

> **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Search(options?: { value?: string, placeholder?: ResourceStr, icon?: string, controller?: SearchController })

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数:**

| 参数名      | 类型         | 必填 | 说明        |
| ----------- | ------------- | ---- | ------------- |
| value       | string                                               | 否   | 设置当前显示的搜索文本内容。<br />从API version 10开始，该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| placeholder | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> | 否   | 设置无输入时的提示文本。                                     |
| icon        | string                                               | 否   | 设置搜索图标路径，默认使用系统搜索图标。<br/>**说明：** <br/>icon的数据源支持本地图片和网络图片。<br/>-&nbsp;支持的图片格式包括png、jpg、bmp、svg、gif、pixelmap和heif。<br/>-&nbsp;支持Base64字符串。格式data:image/[png\|jpeg\|bmp\|webp\|heif];base64,[base64 data], 其中[base64 data]为Base64字符串数据。<br/>如果与属性searchIcon同时设置，则searchIcon优先。 |
| controller  | [SearchController](#searchcontroller) | 否   | 设置Search组件控制器。                                       |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### searchButton

searchButton(value: string, option?: SearchButtonOptions)

设置搜索框末尾搜索按钮。

点击搜索按钮，同时触发onSubmit与onClick回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                  | 必填 | 说明                         |
| ------ | ----------------------------------------------------- | ---- | ---------------------------- |
| value  | string                                                | 是   | 搜索框末尾搜索按钮文本内容。 |
| option | [SearchButtonOptions](#searchbuttonoptions10对象说明) | 否   | 配置搜索框文本样式。<br />默认值：<br />{<br />fontSize: '16fp',<br />fontColor: '#ff3f97e9'<br />}         |

### placeholderColor

placeholderColor(value: ResourceColor)

设置placeholder文本颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                             |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | placeholder文本颜色。<br />默认值：'#99182431'。 |

### placeholderFont

placeholderFont(value?: Font)

设置placeholder文本样式，包括字体大小，字体粗细，字体族，字体风格。当前支持'HarmonyOS Sans'字体和[注册自定义字体](../js-apis-font.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                  |
| ------ | ------------------------ | ---- | --------------------- |
| value  | [Font](ts-types.md#font) | 否   | placeholder文本样式。 |

### textFont

textFont(value?: Font)

设置搜索框内输入文本样式，包括字体大小，字体粗细，字体族，字体风格。目前仅支持默认字体族。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                   |
| ------ | ------------------------ | ---- | ---------------------- |
| value  | [Font](ts-types.md#font) | 否   | 搜索框内输入文本样式。 |

### textAlign<sup>9+</sup>

textAlign(value: TextAlign)

设置文本在搜索框中的对齐方式。目前支持的对齐方式有：Start、Center、End。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                                   |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------ |
| value  | [TextAlign](ts-appendix-enums.md#textalign) | 是   | 文本在搜索框中的对齐方式。<br/>默认值：TextAlign.Start |

### copyOption<sup>9+</sup>

copyOption(value: CopyOptions)

设置输入的文本是否可复制。设置CopyOptions.None时，当前Search中的文字无法被复制或剪切，仅支持粘贴。

设置CopyOptions.None时，不允许拖拽。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                             | 必填 | 说明                                                         |
| ------ | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [CopyOptions](ts-appendix-enums.md#copyoptions9) | 是   | 输入的文本是否可复制。<br />默认值：CopyOptions.LocalDevice，支持设备内复制。 |

### searchIcon<sup>10+</sup>

searchIcon(value: IconOptions | SymbolGlyphModifier)

设置左侧搜索图标样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                  | 必填 | 说明               |
| ------ | ------------------------------------- | ---- | ------------------ |
| value  | [IconOptions](#iconoptions10对象说明) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 是   | 左侧搜索图标样式。<!--RP1--><br />浅色模式默认值：<br />{<br />size: '16vp',<br />color: '#99182431',<br />src: ' '<br />}<br />深色模式默认值：<br />{<br />size: '16vp',<br />color: '#99ffffff',<br />src: ' '<br />} <!--RP1End-->|

### cancelButton<sup>10+</sup>

cancelButton(value: CancelButtonOptions | CancelButtonSymbolOptions)

设置右侧清除按钮样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [CancelButtonOptions](#cancelbuttonoptions12对象说明) \| [CancelButtonSymbolOptions](#cancelbuttonsymboloptions12对象说明) | 是   | 右侧清除按钮样式。<br>默认值：<br />{<br/>style: CancelButtonStyle.INPUT,<br/>icon:&nbsp;{<br/>size: '16vp',<br/>color: '#99ffffff',<br/>src: ' '<br/>}<br/>}<br/>当style为CancelButtonStyle.CONSTANT时，默认显示清除样式。 |

### fontColor<sup>10+</sup>

fontColor(value: ResourceColor)

设置输入文本的字体颜色。[文本通用属性](ts-universal-attributes-text-style.md)fontSize、fontStyle、fontWeight和fontFamily在[textFont](#textfont)属性中设置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                            |
| ------ | ------------------------------------------ | ---- | ----------------------------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 输入文本的字体颜色。<br />默认值：'#FF182431'。 |

### caretStyle<sup>10+</sup>

caretStyle(value: CaretStyle)

设置光标样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明                                                         |
| ------ | ----------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [CaretStyle](ts-text-common.md#caretstyle10) | 是   | 光标样式。<br />默认值：<br />{<br />width: '1.5vp',<br />color: '#007DFF'<br />} |

>  **说明：**     
>   从API version 12开始，此接口支持设置文本手柄颜色，光标和文本手柄颜色保持一致。

### enableKeyboardOnFocus<sup>10+</sup>

enableKeyboardOnFocus(value: boolean)

设置Search通过点击以外的方式获焦时，是否绑定输入法。

从API version 10开始，获焦默认绑定输入法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                            |
| ------ | ------- | ---- | ----------------------------------------------- |
| value  | boolean | 是   | Search获焦时，是否绑定输入法<br/>默认值：true。 |

### selectionMenuHidden<sup>10+</sup>

selectionMenuHidden(value: boolean)

设置是否不弹出系统文本选择菜单。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否不弹出系统文本选择菜单。<br />设置为true时，单击输入框光标、长按输入框、双击输入框、三击输入框或者右键输入框，不弹出系统文本选择菜单。<br />设置为false时，弹出系统文本选择菜单。<br />默认值：false |

### customKeyboard<sup>10+</sup>

customKeyboard(value: CustomBuilder, options?: KeyboardOptions)

设置自定义键盘。

当设置自定义键盘时，输入框激活后不会打开系统输入法，而是加载指定的自定义组件。

自定义键盘的高度可以通过自定义组件根节点的height属性设置，宽度不可设置，使用系统默认值。

自定义键盘采用覆盖原始界面的方式呈现，当没有开启避让模式或者输入框不需要避让的场景不会对应用原始界面产生压缩或者上提。

自定义键盘无法获取焦点，但是会拦截手势事件。

默认在输入控件失去焦点时，关闭自定义键盘，开发者也可以通过[stopEditing](#stopediting10)方法控制键盘关闭。

如果设备支持拍摄输入，设置自定义键盘后，该输入框会不支持拍摄输入。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型                                        | 必填 | 说明                             |
| --------------------- | ------------------------------------------- | ---- | -------------------------------- |
| value                 | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 自定义键盘。                     |
| options<sup>12+</sup> | [KeyboardOptions](ts-basic-components-richeditor.md#keyboardoptions12)       | 否   | 设置自定义键盘是否支持避让功能。 |

### type<sup>11+</sup>

type(value: SearchType)

设置输入框类型。

<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                | 必填 | 说明                        |
| ------ | ----------------------------------- | ---- | -------------------------- |
| value  | [SearchType](#searchtype11枚举说明) | 是   | 输入框类型。<br/>默认值：SearchType.Normal |

### maxLength<sup>11+</sup>

maxLength(value: number)

设置文本的最大输入字符数。默认不设置最大输入字符数限制。到达文本最大字符限制，将无法继续输入字符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                | 必填 | 说明                   |
| ------ | ----------------------------------- | ---- | ---------------------- |
| value  | number | 是   | 文本的最大输入字符数。 |

### enterKeyType<sup>12+</sup>

enterKeyType(value: EnterKeyType)

设置输入法回车键类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                             | 必填 | 说明                                               |
| ------ | ------------------------------------------------ | ---- | -------------------------------------------------- |
| value  | [EnterKeyType](ts-types.md#enterkeytype枚举说明) | 是   | 输入法回车键类型。<br/>默认值：EnterKeyType.Search |

### lineHeight<sup>12+</sup>

lineHeight(value: number | string | Resource)

设置文本的文本行高，设置值不大于0时，不限制文本行高，自适应字体大小，number类型时单位为fp。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本的文本行高。 |

### decoration<sup>12+</sup>

decoration(value: TextDecorationOptions)

设置文本装饰线类型样式及其颜色。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [TextDecorationOptions](ts-types.md#textdecorationoptions12对象说明) | 是   | 文本装饰线对象。<br />默认值：{<br/>&nbsp;type:&nbsp;TextDecorationType.None,<br/>&nbsp;color:&nbsp;Color.Black,<br/>&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;<br/>} |

### letterSpacing<sup>12+</sup>

letterSpacing(value: number | string | Resource)

设置文本字符间距。设置该值为百分比时，按默认值显示。设置该值为0时，按默认值显示。

当取值为负值时，文字会发生压缩，负值过小时会将组件内容区大小压缩为0，导致无内容显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                       | 必填 | 说明           |
| ------ | -------------------------- | ---- | -------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本字符间距。 |

### fontFeature<sup>12+</sup>

fontFeature(value: string)

设置文字特性效果，比如数字等宽的特性。

格式为：normal \| \<feature-tag-value\>

\<feature-tag-value\>的格式为：\<string\> \[ \<integer\> \| on \| off ]

\<feature-tag-value\>的个数可以有多个，中间用','隔开。

例如，使用等宽数字的输入格式为："ss01" on。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| value  | string | 是   | 文字特性效果。 |

Font Feature当前支持的属性见 [fontFeature属性列表](ts-basic-components-text.md#fontfeature12)。
设置 Font Feature 属性，Font Feature 是 OpenType 字体的高级排版能力，如支持连字、数字等宽等特性，一般用在自定义字体中，其能力需要字体本身支持。
更多 Font Feature 能力介绍可参考 https://www.w3.org/TR/css-fonts-3/#font-feature-settings-prop 和 https://sparanoid.com/lab/opentype-features/

### selectedBackgroundColor<sup>12+</sup>

selectedBackgroundColor(value: ResourceColor)

设置文本选中底板颜色。如果未设置不透明度，默认为20%不透明度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                                       |
| ------ | ------------------------------------------ | ---- | ------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 文本选中底板颜色。<br/>默认为20%不透明度。 |

### inputFilter<sup>12+</sup>

inputFilter(value: ResourceStr, error?: &nbsp;Callback<&nbsp;string&nbsp;>)

通过正则表达式设置输入过滤器。匹配表达式的输入允许显示，不匹配的输入将被过滤。仅支持单个字符匹配，不支持字符串匹配。

设置inputFilter且输入的字符不为空字符，会导致设置输入框类型(即type接口)附带的文本过滤效果失效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                               |
| ------ | -------------------------------------- | ---- | ---------------------------------- |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 正则表达式。                       |
| error  | &nbsp;Callback<&nbsp;string&nbsp;>     | 否   | 正则匹配失败时，返回被过滤的内容。 |

### textIndent<sup>12+</sup>

textIndent(value: Dimension)

设置首行文本缩进。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                 | 必填 | 说明                         |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| value  | [Dimension](ts-types.md#dimension10)| 是   | 首行文本缩进。<br/>默认值：0   |

### minFontSize<sup>12+</sup>

minFontSize(value: number | string | Resource)

设置文本最小显示字号。

需配合[maxFontSize](#maxfontsize12)以及布局大小限制使用，单独设置不生效。

自适应字号生效时，fontSize设置不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本最小显示字号。 |

### maxFontSize<sup>12+</sup>

maxFontSize(value: number | string | Resource)

设置文本最大显示字号。

需配合[minFontSize](#minfontsize12)以及布局大小限制使用，单独设置不生效。

自适应字号生效时，fontSize设置不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本最大显示字号。 |

### editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

设置自定义菜单扩展项，允许用户设置扩展项的文本内容、图标、回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| editMenu  | [EditMenuOptions](ts-text-common.md#editmenuoptions对象说明) | 是   | 扩展菜单选项。 |

### enablePreviewText<sup>12+</sup>

enablePreviewText(enable: boolean)

设置是否开启输入预上屏。

预上屏内容定义为文字暂存态，目前不支持文字拦截功能，因此不触发onWillInsert、onDidInsert、onWillDelete、onDidDelete回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| enable | boolean | 是   | 是否开启输入预上屏。<br/>默认值：true |

>  **说明：**
>
>  该接口在CAPI场景使用时下，默认关闭。可以在工程的module.json5中配置[metadata](../../../../application-dev/quick-start/module-structure.md#metadata对象内部结构)字段控制是否启用预上屏，配置如下：
> ```json
> "metadata": [
>  {
>     "name": "can_preview_text",
>     "value": "true",
>  }
> ]
> ```

### enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(isEnabled: boolean)

设置是否开启触控反馈。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| isEnabled | boolean | 是   | 是否开启触控反馈。<br/>默认值：true |

## IconOptions<sup>10+</sup>对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                   | 必填 | 说明    |
| ------ | ------------------------------------------ | ---- | ----------- |
| size   | [Length](ts-types.md#length)               | 否   | 图标尺寸，不支持百分比。    |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 图标颜色。    |
| src    | [ResourceStr](ts-types.md#resourcestr)     | 否   | 图标/图片源。 |

## SearchButtonOptions<sup>10+</sup>对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                   | 必填 | 说明         |
| --------- | ------------------------------------------ | ---- | ---------------- |
| fontSize  | [Length](ts-types.md#length)               | 否   | 文本按钮字体大小，不支持百分比。 |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | 文本按钮字体颜色。 |

## CancelButtonStyle<sup>10+</sup>枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                    | 描述             |
| ----------------------- | ---------------- |
| CONSTANT  | 清除按钮常显样式。 |
| INVISIBLE | 清除按钮常隐样式。 |
| INPUT     | 清除按钮输入样式。 |

## SearchType<sup>11+</sup>枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                 | 值            | 描述            |
| ------------------ | ------ | ------------- |
| NORMAL   | 0 | 基本输入模式。<br/>支持输入数字、字母、下划线、空格、特殊字符。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NUMBER   | 2 | 纯数字输入模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| PHONE_NUMBER | 3 | 电话号码输入模式。<br/>支持输入数字、空格、+ 、-、*、#、(、)，长度不限。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| EMAIL    | 5 | 邮箱地址输入模式。<br/>支持数字，字母，下划线、小数点、!、#、$、%、&、'、*、+、-、/、=、?、^、`、\{、\|、\}、~，以及@字符（只能存在一个@字符）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NUMBER_DECIMAL<sup>12+</sup>  | 12 | 带小数点的数字输入模式。<br/>支持数字，小数点（只能存在一个小数点）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| URL<sup>12+</sup>  | 13 | 带URL的输入模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## CancelButtonOptions<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                   | 必填 | 说明         |
| --------- | ------------------------------------------ | ---- | ---------------- |
| style  | [CancelButtonStyle](#cancelbuttonstyle10枚举说明)               | 否   | 右侧清除按钮显示状态。 |
| icon | [IconOptions](#iconoptions10对象说明) | 否   | 右侧清除按钮图标。 |

## CancelButtonSymbolOptions<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                   | 必填 | 说明         |
| --------- | ------------------------------------------ | ---- | ---------------- |
| style  | [CancelButtonStyle](#cancelbuttonstyle10枚举说明)               | 否   | 右侧清除按钮显示状态。 |
| icon | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 右侧清除按钮Symbol图标。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onSubmit

onSubmit(callback: (value: string) => void)

点击搜索图标、搜索按钮或者按下软键盘搜索按钮时触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| value  | string | 是   | 当前搜索框中输入的文本内容。 |

### onChange

onChange(callback:&nbsp;EditableTextOnChangeCallback)

输入内容发生变化时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| callback  | [EditableTextOnChangeCallback](ts-text-common.md#editabletextonchangecallback12) | 是   | 当前输入文本内容变化时的回调。 |

### onCopy

onCopy(callback: (value: string) => void)

进行复制操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| value  | string | 是   | 复制的文本内容。 |

### onCut

onCut(callback: (value: string) => void)

进行剪切操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| value  | string | 是   | 剪切的文本内容。 |

### onPaste

onPaste(callback: (value: string, event: PasteEvent) => void)

进行粘贴操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                                         | 必填 | 说明                   |
| ------------------- | ------------------------------------------------------------ | ---- | ---------------------- |
| value               | string                                                       | 是   | 粘贴的文本内容。       |
| event<sup>11+</sup> | [PasteEvent](ts-basic-components-richeditor.md#pasteevent11) | 是   | 用户自定义的粘贴事件。 |

### onTextSelectionChange<sup>10+</sup>

onTextSelectionChange(callback: (selectionStart: number, selectionEnd: number) => void)

文本选择的位置发生变化或编辑状态下光标位置发生变化时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型   | 必填 | 说明                                              |
| -------------- | ------ | ---- | ------------------------------------------------- |
| selectionStart | number | 是   | 文本选择区域起始位置，文本框中文字的起始位置为0。 |
| selectionEnd   | number | 是   | 文本选择区域结束位置。                            |

### onContentScroll<sup>10+</sup>

onContentScroll(callback: (totalOffsetX: number, totalOffsetY: number) => void)

文本内容滚动时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型   | 必填 | 说明                               |
| ------------ | ------ | ---- | ---------------------------------- |
| totalOffsetX | number | 是   | 文本在内容区的横坐标偏移，单位px。 |
| totalOffsetY | number | 是   | 文本在内容区的纵坐标偏移，单位px。 |

### onEditChange<sup>12+</sup>

onEditChange(callback:&nbsp;Callback<&nbsp;boolean&nbsp;>)

输入状态变化时，触发该回调。有光标时为编辑态，无光标时为非编辑态。isEditing为true表示正在输入。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                | 必填 | 说明                 |
| --------- | ---------------------------------- | ---- | -------------------- |
| isEditing | &nbsp;Callback<&nbsp;boolean&nbsp;> | 是   | 为true表示正在输入。 |

### onWillInsert<sup>12+</sup>

onWillInsert(callback: Callback\<InsertValue, boolean>)

在将要输入时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[InsertValue](ts-text-common.md#insertvalue12对象说明), boolean> | 是   | 在将要输入时调用的回调。<br/>在返回true时，表示正常插入，返回false时，表示不插入。<br/>在预上屏操作时，该回调不触发。<br/>仅支持系统输入法输入的场景。 |

### onDidInsert<sup>12+</sup>

onDidInsert(callback: Callback\<InsertValue>)

在输入完成时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[InsertValue](ts-text-common.md#insertvalue12对象说明)> | 是   | 在输入完成时调用的回调。<br/>仅支持系统输入法输入的场景。 |

### onWillDelete<sup>12+</sup>

onWillDelete(callback: Callback\<DeleteValue, boolean>)

在将要删除时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[DeleteValue](ts-text-common.md#deletevalue12对象说明), boolean> | 是   | 在将要删除时调用的回调。<br/>在返回true时，表示正常删除，返回false时，表示不删除。<br/>在预上屏删除操作时，该回调不触发。<br/>仅支持系统输入法输入的场景。 |

### onDidDelete<sup>12+</sup>

onDidDelete(callback: Callback\<DeleteValue>)

在删除完成时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[DeleteValue](ts-text-common.md#deletevalue12对象说明)> | 是   | 在删除完成时调用的回调。<br/>仅支持系统输入法输入的场景。 |

## SearchController

Search组件的控制器继承自[TextContentControllerBase](ts-types.md#textcontentcontrollerbase10)。

### 导入对象
```
controller: SearchController = new SearchController()
```

### constructor<sup>8+</sup>

constructor()

SearchController的构造函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### caretPosition<sup>8+</sup>

caretPosition(value: number): void

设置输入光标的位置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数:**

| 参数名 | 类型 | 必填 | 说明                           |
| ------ | -------- | ---- | ---------------------------------- |
| value  | number   | 是   | 从字符串开始到光标所在位置的长度。 |

### stopEditing<sup>10+</sup>

stopEditing(): void

退出编辑态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setTextSelection<sup>12+</sup>

setTextSelection(selectionStart: number, selectionEnd: number, options?: SelectionOptions): void;

组件在获焦状态下，调用该接口设置文本选择区域并高亮显示，且只有在selectionStart小于selectionEnd时，文字才会被选取、高亮显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型 | 必填 | 说明   |
| -------------- | -------- | ---- | -------- |
| selectionStart | number   | 是   | 文本选择区域起始位置，文本框中文字的起始位置为0。<br/>当selectionStart小于0时、按照0处理；当selectionStart大于文字最大长度时、按照文字最大长度处理。<br/> |
| selectionEnd   | number   | 是   | 文本选择区域结束位置。<br/>当selectionEnd小于0时、按照0处理；当selectionEnd大于文字最大长度时、按照文字最大长度处理。<br/> |
| options | [SelectionOptions](ts-types.md#selectionoptions12对象说明) | 否    | 选中文字时的配置。<br />默认值：MenuPolicy.DEFAULT。 |

>  **说明：**
>
>  如果selectionStart或selectionEnd被赋值为undefined时，当作0处理。
>
>  如果selectionMenuHidden被赋值为true或设备为2in1时，即使options被赋值为MenuPolicy.SHOW，调用setTextSelection也不弹出菜单。
>
>  如果选中的文本含有emoji表情时，表情的起始位置包含在设置的文本选中区域内就会被选中。

##  示例

### 示例1
Search基本使用示例。
```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State changeValue: string = ''
  @State submitValue: string = ''
  @State positionInfo: CaretOffset = { index: 0, x: 0, y: 0 }
  controller: SearchController = new SearchController()

  build() {
    Column({space: 10}) {
      Text('onSubmit:' + this.submitValue).fontSize(18).margin(15)
      Text('onChange:' + this.changeValue).fontSize(18).margin(15)
      Search({ value: this.changeValue, placeholder: 'Type to search...', controller: this.controller })
        .searchButton('SEARCH')
        .width('95%')
        .height(40)
        .backgroundColor('#F5F5F5')
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .onSubmit((value: string) => {
          this.submitValue = value
        })
        .onChange((value: string) => {
          this.changeValue = value
        })
        .margin(20)
      Button('Set caretPosition 1')
        .onClick(() => {
          // 设置光标位置到输入的第一个字符后
          this.controller.caretPosition(1)
        })
      Button('Get CaretOffset')
        .onClick(() => {
          this.positionInfo = this.controller.getCaretOffset()
        })
    }.width('100%')
  }
}
```

![search](figures/search.gif)

### 示例2
searchButton、searchIcon、cancelButton属性接口使用示例。
```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State changeValue: string = ''
  @State submitValue: string = ''

  build() {
    Column() {
      Text('onSubmit:' + this.submitValue).fontSize(18).margin(15)
      Search({ value: this.changeValue, placeholder: 'Type to search...' })
        .searchButton('SEARCH')
        .searchIcon({
          src: $r('app.media.search')
        })
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: {
            src: $r('app.media.cancel')
          }
        })
        .width('90%')
        .height(40)
        .maxLength(20)
        .backgroundColor('#F5F5F5')
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .onSubmit((value: string) => {
          this.submitValue = value
        })
        .onChange((value: string) => {
          this.changeValue = value
        })
        .margin(20)
    }.width('100%')
  }
}
```

![searchButton](figures/searchButton.gif)


### 示例3
Search绑定自定义键盘使用示例。
```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  controller: SearchController = new SearchController()
  @State inputValue: string = ""

  // 自定义键盘组件
  @Builder CustomKeyboardBuilder() {
    Column() {
      Button('x').onClick(() => {
        // 关闭自定义键盘
        this.controller.stopEditing()
      })
      Grid() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {
          GridItem() {
            Button(item + "")
              .width(110).onClick(() => {
              this.inputValue += item
            })
          }
        })
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
    }.backgroundColor(Color.Gray)
  }

  build() {
    Column() {
      Search({ controller: this.controller, value: this.inputValue})
        // 绑定自定义键盘
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })
    }
  }
}
```

![customKeyboard](figures/searchCustomKeyboard.png)

### 示例4
enterKeyType属性接口使用示例。
```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State text: string = ''
  @State enterTypes: Array<EnterKeyType> = [EnterKeyType.Go, EnterKeyType.Search, EnterKeyType.Send, EnterKeyType.Done, EnterKeyType.Next, EnterKeyType.PREVIOUS, EnterKeyType.NEW_LINE]
  @State index: number = 0
  build() {
    Column({ space: 20 }) {
      Search({ placeholder: '请输入文本', value: this.text })
        .width(380)
        .enterKeyType(this.enterTypes[this.index])
        .onChange((value: string) => {
          this.text = value
        })
        .onSubmit((value: String) => {
          console.log("trigger search onsubmit" + value);
        })

      Button('改变EnterKeyType').onClick(() => {
        this.index = (this.index + 1) % this.enterTypes.length;
      })
    }.width('100%')
  }
}
```

![searchEnterKeyType](figures/searchEnterKey.gif)

### 示例5

该示例实现了使用lineHeight设置文本的文本行高，使用letterSpacing设置文本字符间距，使用decoration设置文本装饰线样式。

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  build() {
    Row() {
      Column() {
        Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)
        Search({value: 'lineHeight unset'})
          .border({ width: 1 }).padding(10)
        Search({value: 'lineHeight 15'})
          .border({ width: 1 }).padding(10).lineHeight(15)
        Search({value: 'lineHeight 30'})
          .border({ width: 1 }).padding(10).lineHeight(30)

        Text('letterSpacing').fontSize(9).fontColor(0xCCCCCC)
        Search({value: 'letterSpacing 0'})
          .border({ width: 1 }).padding(5).letterSpacing(0)
        Search({value: 'letterSpacing 3'})
          .border({ width: 1 }).padding(5).letterSpacing(3)
        Search({value: 'letterSpacing -1'})
          .border({ width: 1 }).padding(5).letterSpacing(-1)

        Text('decoration').fontSize(9).fontColor(0xCCCCCC)
        Search({value: 'LineThrough, Red'})
          .border({ width: 1 }).padding(5)
          .decoration({type: TextDecorationType.LineThrough, color: Color.Red})
        Search({value: 'Overline, Red, DOTTED'})
          .border({ width: 1 }).padding(5)
          .decoration({type: TextDecorationType.Overline, color: Color.Red, style: TextDecorationStyle.DOTTED})
        Search({value: 'Underline, Red, WAVY'})
          .border({ width: 1 }).padding(5)
          .decoration({type: TextDecorationType.Underline, color: Color.Red, style: TextDecorationStyle.WAVY})
      }.height('90%')
    }
    .width('90%')
    .margin(10)
  }
}

```

![SearchDecoration](figures/search_decoration.png)

### 示例6
fontFeature属性使用示例，对比了fontFeature使用ss01属性和不使用ss01属性的效果。

```ts
@Entry
@Component
struct search {
  @State text1: string = 'This is ss01 on : 0123456789'
  @State text2: string = 'This is ss01 off: 0123456789'

  build() {
    Column(){
      Search({value: this.text1})
        .margin({top:200})
        .fontFeature("\"ss01\" on")
      Search({value: this.text2})
        .margin({top:10})
        .fontFeature("\"ss01\" off")
    }
    .width("90%")
    .margin("5%")
  }
}
```
![fontFeature](figures/searchFontFeature.png)

### 示例7

自定义键盘弹出发生避让示例。

```ts
@Entry
@Component
struct SearchExample {
  controller: SearchController = new SearchController()
  @State inputValue: string = ""
  @State height1: string | number = '80%'
  @State supportAvoidance: boolean = true

  // 自定义键盘组件
  @Builder
  CustomKeyboardBuilder() {
    Column() {
      Row() {
        Button('x').onClick(() => {
          // 关闭自定义键盘
          this.controller.stopEditing()
        }).margin(10)
      }

      Grid() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {
          GridItem() {
            Button(item + "")
              .width(110).onClick(() => {
              this.inputValue += item
            })
          }
        })
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
    }
    .backgroundColor(Color.Gray)
  }

  build() {
    Column() {
      Row() {
        Button("20%")
          .fontSize(24)
          .onClick(() => {
            this.height1 = "20%"
          })
        Button("80%")
          .fontSize(24)
          .margin({ left: 20 })
          .onClick(() => {
            this.height1 = "80%"
          })
      }
      .justifyContent(FlexAlign.Center)
      .alignItems(VerticalAlign.Bottom)
      .height(this.height1)
      .width("100%")
      .padding({ bottom: 50 })

      Search({ controller: this.controller, value: this.inputValue })// 绑定自定义键盘
        .customKeyboard(this.CustomKeyboardBuilder(), { supportAvoidance: this.supportAvoidance })
        .margin(10)
        .border({ width: 1 })
        .onChange((value: string) => {
          this.inputValue = value
        })
    }
  }
}
```

![CustomSearchKeyType](figures/searchCustomKeyboard.gif)

### 示例8

该示例实现了使用minFontSize及maxFontSize设置文本自适应字号。

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  build() {
    Row() {
      Column() {
        Text('adaptive font').fontSize(9).fontColor(0xCCCCCC)

        Search({value: 'This is the text without the adaptive font'})
          .width('80%').height(90).borderWidth(1)
        Search({value: 'This is the text without the adaptive font'})
          .width('80%').height(90).borderWidth(1)
          .minFontSize(4)
          .maxFontSize(40)
      }.height('90%')
    }
    .width('90%')
    .margin(10)
  }
}
```

![searchAdaptFont](figures/search_adapt_font.png)

### 示例9

该示例展示输入框支持插入和删除回调。

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State insertValue: string = ""
  @State deleteValue: string = ""
  @State insertOffset: number = 0
  @State deleteOffset: number = 0
  @State deleteDirection: number = 0

  build() {
    Row() {
      Column() {
        Search({ value: "Search支持插入回调文本" })
          .height(60)
          .onWillInsert((info: InsertValue) => {
            this.insertValue = info.insertValue
            return true;
          })
          .onDidInsert((info: InsertValue) => {
            this.insertOffset = info.insertOffset
          })

        Text("insertValue:" + this.insertValue + "  insertOffset:" + this.insertOffset).height(30)

        Search({ value: "Search支持删除回调文本b" })
          .height(60)
          .onWillDelete((info: DeleteValue) => {
            this.deleteValue = info.deleteValue
            info.direction
            return true;
          })
          .onDidDelete((info: DeleteValue) => {
            this.deleteOffset = info.deleteOffset
            this.deleteDirection = info.direction
          })

        Text("deleteValue:" + this.deleteValue + "  deleteOffset:" + this.deleteOffset).height(30)
        Text("deleteDirection:" + (this.deleteDirection == 0 ? "BACKWARD" : "FORWARD")).height(30)

      }.width('100%')
    }
    .height('100%')
  }
}
```

![SearchInsertAndDelete](figures/SearchInsertAndDelete.PNG)

### 示例10

editMenuOptions使用示例，展示设置自定义菜单扩展项的文本内容、图标、回调方法。

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State text: string = 'Search editMenuOptions'

  onCreateMenu(menuItems: Array<TextMenuItem>) {
    menuItems.forEach((value, index) => {
      value.icon = $r('app.media.startIcon')
      if (value.id.equals(TextMenuItemId.COPY)) {
        value.content = "复制change"
      }
      if (value.id.equals(TextMenuItemId.SELECT_ALL)) {
        value.content = "全选change"
      }
    })
    let item1: TextMenuItem = {
      content: 'custom1',
      icon: $r('app.media.startIcon'),
      id: TextMenuItemId.of('custom1'),
    }
    let item2: TextMenuItem = {
      content: 'custom2',
      id: TextMenuItemId.of('custom2'),
      icon: $r('app.media.startIcon'),
    }
    menuItems.push(item1)
    menuItems.unshift(item2)
    return menuItems
  }

  build() {
    Column() {
      Search({ value: this.text })
        .width('95%')
        .editMenuOptions({
          onCreateMenu: this.onCreateMenu, onMenuItemClick: (menuItem: TextMenuItem, textRange: TextRange) => {
            if (menuItem.id.equals(TextMenuItemId.of("custom2"))) {
              console.log("拦截 id: custom2 start:" + textRange.start + "; end:" + textRange.end)
              return true;
            }
            if (menuItem.id.equals(TextMenuItemId.COPY)) {
              console.log("拦截 COPY start:" + textRange.start + "; end:" + textRange.end)
              return true;
            }
            if (menuItem.id.equals(TextMenuItemId.SELECT_ALL)) {
              console.log("不拦截 SELECT_ALL start:" + textRange.start + "; end:" + textRange.end)
              return false;
            }
            return false;
          }
        })
        .margin({ top: 100 })
    }
    .width("90%")
    .margin("5%")
  }
}
```

![searchEditMenuOptions](figures/searchEditMenuOptions.gif)

### 示例11

searchIcon和cancelButton使用SymbolGlyphModifier设置图标样式示例。

```ts
// xxx.ets
import { SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@Component
struct SearchExample {
  controller: SearchController = new SearchController()
  @State changeValue: string = ''
  @State submitValue: string = ''

  build() {
    Column() {
      Search({ value: this.changeValue, placeholder: 'Type to search...', controller: this.controller })
        .searchIcon(new SymbolGlyphModifier($r('sys.symbol.magnifyingglass')).fontColor([Color.Red]))
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: new SymbolGlyphModifier($r('sys.symbol.xmark')).fontColor([Color.Green])
        })
        .searchButton('SEARCH')
        .width('95%')
        .height(40)
        .backgroundColor('#F5F5F5')
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .margin(10)
    }
    .width('100%')
    .height('100%')
  }
}
```

![searchSymbolGlyphModifierIcon](figures/searchSymbolGlyphModifierIcon.png)

