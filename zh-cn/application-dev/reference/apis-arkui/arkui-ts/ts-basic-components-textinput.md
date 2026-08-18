# TextInput
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiaxiaguang-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

单行文本输入框组件，用于接收用户的单行文本输入。支持多种输入类型（如文本、密码、邮箱、数字等）、自定义样式（字体、颜色、下划线、装饰线等）、输入过滤、密码输入模式、自动填充等功能，适用于登录注册、搜索、表单填写等多种场景。能够解决文本输入验证、格式化、安全输入等常见需求，简化开发流程、提升用户体验并增强数据安全性。

>  **说明：**
>
> - 该组件从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 该组件仅支持单文本样式，若需实现富文本样式，建议使用[RichEditor](ts-basic-components-richeditor.md)组件。
>
> - 如需设置触摸文本组件外部时是否清除文本选中和手柄，可使用[setTextSelectionClearPolicy](../arkts-apis-uicontext-uicontext.md#settextselectionclearpolicy)接口。


## 子组件

无


## 接口

TextInput(value?: TextInputOptions)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ---- |
| value | [TextInputOptions](#textinputoptions对象说明) | 否  | TextInput组件参数。默认值undefined。不设置该参数时，输入框初始化为空。 |

## TextInputOptions对象说明

TextInput初始化参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 只读 | 可选   | 说明 |
| ---- | ----- | ---- | ---- | ---- |
| placeholder             | [ResourceStr](ts-types.md#resourcestr)   | 否    | 是 | 设置无输入时的提示文本。不设置时默认无提示文本。                             |
| text                    | [ResourceStr](ts-types.md#resourcestr)   | 否    | 是 | 设置输入框当前的文本内容。不设置时默认为空字符串。<br>建议通过onChange事件将状态变量与文本实时绑定，<br>避免组件刷新时TextInput中的文本内容异常。<br>从API version 10开始，该参数支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。<br>从API version 18开始，该参数支持[!!](../../../ui/state-management/arkts-new-binding.md#系统组件参数双向绑定)双向绑定变量。 |
| controller<sup>8+</sup> | [TextInputController](#textinputcontroller8) | 否    | 是 | 设置TextInput控制器。当需要通过控制器调用光标设置、文本选择等方法时传入此参数。不设置时默认无控制器，无法使用控制器相关方法。                          |

## 属性

除支持[通用属性](ts-component-general-attributes.md)，还支持以下属性：

>  **说明：**    
>  默认情况下，通用属性[padding](ts-universal-attributes-size.md#padding)的默认值为<br>{<br>&nbsp;top: '8vp',<br>&nbsp;right: '16vp',<br>&nbsp;bottom: '8vp',<br>&nbsp;left: '16vp'<br> } 
>
>  输入框开启下划线模式时，通用属性padding的默认值为<br>{<br>&nbsp;top: '12vp',<br>&nbsp;right: '0vp',<br>&nbsp;bottom: '12vp',<br>&nbsp;left: '0vp'<br> }
>
>  当输入框设置padding为0时，可设置[borderRadius](ts-universal-attributes-border.md#borderradius)为0避免光标被截断。当光标在文本框边缘显示异常时，请检查是否是padding、borderRadius属性影响造成。
>
>   从API version 10开始，单行输入框可设置.width('auto')使组件宽度自适应文本宽度，自适应时组件宽度受constraintSize属性以及父容器传递的最大最小宽度限制，其余使用方式参考[尺寸设置](ts-universal-attributes-size.md)。

### type

type(value: InputType)

设置输入框类型。

不同的InputType会拉起对应类型的键盘，同时限制输入。未通过该接口设置时，默认为InputType.Normal。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                      |
| ------ | ------------------------------- | ---- | ----------------------------------------- |
| value  | [InputType](#inputtype枚举说明) | 是   | 输入框类型。 |

>  **说明：**    
>  密码填充服务需要密码相关的[输入框类型](#inputtype枚举说明)(如InputType.Password、InputType.NUMBER_PASSWORD、InputType.NEW_PASSWORD、InputType.USER_NAME)。<!--RP2--><!--RP2End-->
>
>  设置[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，装饰线[decoration](#decoration12)、下划线[showUnderline](#showunderline10)、行高[lineHeight](#lineheight12)、文字特性[fontFeature](#fontfeature12)不生效。

### placeholderColor

placeholderColor(value: ResourceColor)

设置placeholder文本颜色。未通过该接口设置时，默认颜色跟随主题，Wearable设备上默认值为'#99ffffff'（白色，不透明度为60%）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                         |
| ------ | ------------------------------------------ | ---- | -------------------------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | placeholder文本颜色。 |

### placeholderFont

placeholderFont(value?: Font)

设置placeholder文本样式，包括字体大小、字体粗细、字体族、字体风格。

> **说明：**
>
> 可以使用[loadFontSync](../../apis-arkgraphics2d/js-apis-graphics-text.md#loadfontsync)注册自定义字体。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                  |
| ------ | ------------------------ | ---- | --------------------- |
| value  | [Font](ts-types.md#font) | 否   | placeholder文本样式。<br>省略该参数时使用系统默认字体样式。<br>Wearable设备上字体大小默认值为18fp |

### enterKeyType

enterKeyType(value: EnterKeyType)

设置输入法回车键类型。未通过该接口设置时，默认为EnterKeyType.Done。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                             | 必填 | 说明                                             |
| ------ | ------------------------------------------------ | ---- | ------------------------------------------------ |
| value  | [EnterKeyType](#enterkeytype枚举说明) | 是   | 输入法回车键类型。 |

### caretColor

caretColor(value: ResourceColor)

设置输入框光标颜色。未通过该接口设置时，默认为'#007DFF'（蓝色），Wearable设备上默认值为'#5EA1FF'（蓝色，比'#007DFF'颜色稍浅）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                   |
| ------ | ------------------------------------------ | ---- | -------------------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 输入框光标颜色。 |

>  **说明：**     
>   从API version 12开始，此接口支持设置文本手柄颜色，光标和文本手柄颜色保持一致。

### maxLength

maxLength(value: number)

设置文本的最大输入字符数。未通过该接口设置时，默认可以无限输入。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | 是   | 文本的最大输入字符数。<br>取值范围：[0, 2^31-1]<br>**说明：** <br>当不设置该属性或设置异常值时，取默认值。设置小数时，取整数部分。设置值超过取值范围上限时，可能导致组件显示或功能异常，请勿超过上限值。 |

### fontColor

fontColor(value: ResourceColor)

设置字体颜色。未通过该接口设置时，默认颜色跟随主题，Wearable设备上默认值为'#dbffffff'（白色，不透明度为86%）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明       |
| ------ | ------------------------------------------ | ---- | ---------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 字体颜色。 |

### fontSize

fontSize(value: Length)

设置字体大小。未通过该接口设置时，默认字体大小为16fp，Wearable设备上默认值为18fp。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                         | 必填 | 说明                                                         |
| ------ | ---------------------------- | ---- | ------------------------------------------------------------ |
| value  | [Length](ts-types.md#length) | 是   | 字体大小。fontSize为number类型时，使用fp单位。不支持设置百分比字符串。 |

### fontStyle

fontStyle(value: FontStyle)

设置字体样式。未通过该接口设置时，默认为FontStyle.Normal。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                    |
| ------ | ------------------------------------------- | ---- | --------------------------------------- |
| value  | [FontStyle](ts-appendix-enums.md#fontstyle) | 是   | 字体样式。 |

### fontWeight

fontWeight(value: number | FontWeight | ResourceStr)

设置文本的字体粗细，设置过大可能会在不同字体下有截断。未通过该接口设置时，默认为FontWeight.Normal。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;[FontWeight](ts-appendix-enums.md#fontweight)&nbsp;\|&nbsp;[ResourceStr](ts-types.md#resourcestr) | 是   | 文本的字体粗细，number类型取值[100,900]，取值间隔为100，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如“400”，以及“bold”、“bolder”、“lighter”、“regular”、“medium”，分别对应FontWeight中相应的枚举值。<br>从API version 20开始，支持Resource类型。 |

### fontFamily

fontFamily(value: ResourceStr)

设置字体列表。未通过该接口设置时，默认字体为'HarmonyOS Sans'。

> **说明：**
>
> 推荐使用[loadFontSync](../../apis-arkgraphics2d/js-apis-graphics-text.md#loadfontsync)注册自定义字体。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                   | 必填 | 说明                                                         |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 字体列表。使用多个字体时，请用逗号','分隔，字体的优先级按顺序生效。例如：'Arial,HarmonyOS Sans'。<br>应用当前支持'HarmonyOS Sans'字体和自定义字体。<br>卡片当前仅支持'HarmonyOS Sans'字体。<br>Wearable设备支持'HarmonyOS Sans'字体和自定义字体。 |

### inputFilter<sup>8+</sup>

inputFilter(value: ResourceStr, error?: Callback\<string>)

通过正则表达式设置输入过滤器。匹配表达式的输入允许显示，不匹配的输入将被过滤。单字符输入场景仅支持单字符匹配，多字符输入场景支持字符串匹配，例如粘贴。未通过该接口设置时，默认无输入过滤规则，所有输入都允许显示。

从API version 11开始，设置inputFilter且输入的字符不为空字符，会导致[type](#type)接口附带的文本过滤效果失效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                   | 必填 | 说明                               |
| ------ | -------------------------------------- | ---- | ---------------------------------- |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 正则表达式。 |
| error  | Callback\<string>                | 否   | 正则匹配失败时，返回被过滤的内容。 |

### copyOption<sup>9+</sup>

copyOption(value: CopyOptions)

设置输入的文本是否可复制。设置CopyOptions.None时，只支持粘贴和全选。设置CopyOptions.None时，不允许拖拽。未通过该接口设置时，默认为CopyOptions.LocalDevice，支持设备内复制。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                             | 必填 | 说明                                                         |
| ------ | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [CopyOptions](ts-appendix-enums.md#copyoptions9) | 是   | 输入的文本是否可复制。 |

### showPasswordIcon<sup>9+</sup>

showPasswordIcon(value: boolean)

设置在密码模式下，输入框末尾的图标是否显示。未通过该接口设置时，默认TV设备为false，其他设备为true。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                        |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| value  | boolean | 是   | 密码输入模式时，输入框末尾的图标是否显示。<br>true表示显示，false表示不显示。 |

### style<sup>9+</sup>

style(value: TextInputStyle &nbsp;|&nbsp;TextContentStyle)

设置输入框为默认风格或内联输入风格，内联输入风格只支持InputType.Normal类型。<br>输入框类型介绍请参考[type](#type)接口。未通过该接口设置时，默认为TextInputStyle.Default。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [TextInputStyle](#textinputstyle9枚举说明)&nbsp;\|&nbsp;[TextContentStyle](ts-appendix-enums.md#textcontentstyle10) | 是   | 输入框为默认风格或内联输入风格。 |

### textAlign<sup>9+</sup>

textAlign(value: TextAlign)

设置文本在输入框中的水平对齐方式。未通过该接口设置时，默认为TextAlign.Start。

支持TextAlign.Start、TextAlign.Center和TextAlign.End。TextAlign.JUSTIFY的对齐方式按照TextAlign.Start处理。

可通过[align](ts-universal-attributes-location.md#align)属性控制文本段落在垂直方向上的位置。此组件不支持通过align属性控制文本段落在水平方向上的位置。

- Alignment.TopStart、Alignment.Top、Alignment.TopEnd：内容顶部对齐。

- Alignment.Start、Alignment.Center、Alignment.End：内容垂直居中。

- Alignment.BottomStart、Alignment.Bottom、Alignment.BottomEnd：内容底部对齐。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                                       |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| value  | [TextAlign](ts-appendix-enums.md#textalign) | 是   | 文本在输入框中的水平对齐方式。 |

>  **说明：**  
>
>  textAlign只能调整文本整体的布局，不影响字符的显示顺序。若需要调整字符的显示顺序，请参考[镜像状态字符对齐](../../../ui/arkts-internationalization.md#镜像状态字符对齐)。

### textDirection<sup>23+</sup>

textDirection(direction: TextDirection | undefined)

指定文本排版方向，未通过该接口设置时，默认文本排版方向遵循组件布局方向。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                        | 必填 | 说明                                                       |
| ------ | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| direction  | [TextDirection](ts-text-common.md#textdirection22) \| undefined | 是   | 文本排版方向。<br>设置为undefined时，按照TextDirection.DEFAULT处理，表现为文本排版方向遵循组件布局方向。 |

### selectedBackgroundColor<sup>10+</sup>

selectedBackgroundColor(value: ResourceColor)

设置文本选中底板颜色。如果未设置不透明度，默认为20%不透明度。未通过该接口设置时，默认为'#FF007DFF'（蓝色），Wearable设备上默认值为'#FF1F71FF'（蓝色，比'#FF007DFF'颜色稍深）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                       |
| ------ | ------------------------------------------ | ---- | ------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 文本选中底板颜色。 |

### caretStyle<sup>10+</sup>

caretStyle(value: CaretStyle)

设置光标风格。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明         |
| ------ | ----------------------------------- | ---- | ------------ |
| value  | [CaretStyle](ts-text-common.md#caretstyle10) | 是   | 光标的风格，用于自定义光标的显示样式。配置项包括width（光标宽度）和color（光标颜色）等。不设置时使用系统默认光标样式。 |

>  **说明：**
>
>   当同时设置caretColor属性和caretStyle属性中的color参数时，遵循后设置生效原则。
>
>   从API version 12开始，此接口支持设置文本手柄颜色，光标和文本手柄颜色保持一致。

### caretPosition<sup>10+</sup>

caretPosition(value: number)

设置光标位置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| value  | number | 是   | 光标的位置。<br>第一个字符前的位置是0。<br>当取值小于0时，取0；大于文本长度时，显示在文本末尾。 |

### showUnit<sup>10+</sup>

showUnit(value: CustomBuilder)

设置控件作为文本框单位。需搭配[showUnderline](#showunderline10)使用，当showUnderline为true时生效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                           |
| ------ | ------------------------------------------- | ---- | ------------------------------ |
| value  | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 文本输入时，文本框的显示单位。 |

### showError<sup>10+</sup>

showError(value?: ResourceStr | undefined)

设置错误状态下提示的错误文本或者不显示错误状态。

当参数类型为ResourceStr并且输入内容不符合定义规范时，提示错误文本，当提示错误单行文本超长时，末尾以省略号显示。当参数类型为undefined时，不显示错误状态。请参考[示例2](#示例2设置下划线)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                          | 必填 | 说明                                                         |
| ------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;undefined | 否   | 错误状态下提示的错误文本或者不显示错误状态。<br>默认不显示错误状态。<br>Wearable设备上字体大小为：13fp，对齐方式为：居中对齐<br>**说明：** <br>从API version 12开始，value支持Resource类型。<br>不支持[TextInputStyle](#textinputstyle9枚举说明)的内联模式。 |

### showUnderline<sup>10+</sup>

showUnderline(value: boolean)

设置是否开启下划线。未通过该接口设置时，默认不开启下划线，下划线默认颜色为'#33182431'（深灰色，不透明度为20%），默认粗细为1px，文本框尺寸48vp，下划线只支持InputType.Normal类型。设置密码模式时，下划线不生效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| value  | boolean | 是   | 是否开启下划线。<br>true表示开启，false表示不开启。 |

>  **说明：**
>
> - 下划线只支持[InputType.Normal](#inputtype枚举说明)类型。
>
> - 设置[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，装饰线[decoration](#decoration12)、下划线[showUnderline](#showunderline10)、行高[lineHeight](#lineheight12)、文字特性[fontFeature](#fontfeature12)不生效。

### passwordIcon<sup>10+</sup>

passwordIcon(value: PasswordIcon)

设置在密码模式下，输入框末尾的图标。未通过该接口设置时，默认使用系统提供的密码图标。支持jpg、png、bmp、heic和webp类型的图片格式。该图标的固定尺寸为24vp，Wearable设备上默认尺寸为28vp，若引用的图标过大或过小，均显示为固定尺寸。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                    | 必填 | 说明                                                         |
| ------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [PasswordIcon](#passwordicon10对象说明) | 是   | 密码输入模式时，输入框末尾的图标。 |

### enableKeyboardOnFocus<sup>10+</sup>

enableKeyboardOnFocus(value: boolean)

设置TextInput通过点击以外的方式获焦时，是否主动拉起软键盘。未通过该接口设置时，默认TV设备为false，其他设备为true。

从API version 10开始，获焦默认绑定输入法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                        |
| ------ | ------- | ---- | ----------------------------------------------------------- |
| value  | boolean | 是   | 通过点击以外的方式获焦时，是否主动拉起软键盘。<br>true表示主动拉起软键盘，false表示不主动拉起。 |

### selectionMenuHidden<sup>10+</sup>

selectionMenuHidden(value: boolean)

设置是否隐藏系统文本选择菜单。未通过该接口设置时，默认显示系统文本选择菜单。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否隐藏系统文本选择菜单。<br>设置为true时，单击输入框光标、长按输入框、双击输入框、三击输入框或者右键输入框，隐藏系统文本选择菜单。<br>设置为false时，显示系统文本选择菜单。 |

### barState<sup>10+</sup>

barState(value: BarState)

设置内联输入风格编辑态时滚动条的显示模式。未通过该接口设置时，默认为BarState.Auto。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [BarState](ts-appendix-enums.md#barstate) | 是   | 内联输入风格编辑态时滚动条的显示模式。仅设置内联模式时该属性生效。 |

### maxLines<sup>10+</sup>

maxLines(value: number)

设置内联输入风格编辑态时文本可显示的最大行数。未通过该接口设置时，默认为3。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | number | 是   | 内联输入风格编辑态时文本可显示的最大行数。仅设置内联模式且处于编辑态时该属性生效。<br>取值范围：(0, UINT32_MAX]。传入0或负数时，按默认值3处理；超出UINT32_MAX时，自动修正为UINT32_MAX。|

### customKeyboard<sup>10+</sup>

customKeyboard(value: CustomBuilder | ComponentContent | undefined, options?: KeyboardOptions)

设置自定义键盘。

当设置自定义键盘时，输入框激活后不会打开系统输入法，而是加载指定的自定义组件。

自定义键盘的高度可以通过自定义组件根节点的height属性设置，宽度不可设置，使用系统默认值。

自定义键盘采用覆盖原始界面的方式呈现，当没有开启避让模式或者输入框不需要避让的场景不会对应用原始界面产生压缩或者上提。

自定义键盘无法获取焦点，但是会拦截手势事件。

默认在输入控件失去焦点时，关闭自定义键盘，开发者也可以通过[TextInputController](#textinputcontroller8).[stopEditing](#stopediting10)方法控制键盘关闭。

当设置自定义键盘时，可以通过绑定[onKeyPreIme](ts-universal-events-key.md#onkeypreime12)事件规避物理键盘的输入。

从API version 23开始，自定义键盘可以通过[setCustomKeyboardContinueFeature](../arkts-apis-uicontext-uicontext.md#setcustomkeyboardcontinuefeature23)开启接续，在切换至其他自定义键盘时，会直接切换，不会触发键盘关闭和拉起动画。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名                | 类型                                        | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| value                 | [CustomBuilder](ts-types.md#custombuilder8) \| [ComponentContent](../js-apis-arkui-ComponentContent.md#componentcontent-1)<sup>22+</sup> \| undefined<sup>22+</sup> | 是   | 自定义键盘。设定值为undefined时，关闭自定义键盘。 |
| options<sup>12+</sup> | [KeyboardOptions](ts-basic-components-richeditor.md#keyboardoptions12)       | 否   | 设置自定义键盘是否支持避让功能。<br>不设置该参数时，自定义键盘默认不支持避让功能。                             |

### enableAutoFill<sup>11+</sup>

enableAutoFill(value: boolean)

设置是否启用自动填充。未通过该接口设置时，默认启用自动填充。<!--RP6--><!--RP6End-->

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否启用自动填充。<br>true表示启用，false表示不启用。 |

### enableSelectedDataDetector<sup>22+</sup>

enableSelectedDataDetector(enable: boolean | undefined)

设置是否对选中文本进行实体识别。该接口依赖设备底层应具有文本识别能力，否则设置不会生效。未通过该接口设置时，默认开启选中文本实体识别，并识别所有类型的实体，同时启用AI菜单功能。

当enableSelectedDataDetector设置为true时，默认识别所有类型的实体。

启用后可识别选区中的邮件、电话、网址、日期、地址等，并在文本选择菜单中展示对应的AI菜单项。

AI菜单功能启用时，在组件中选中文本后，文本选择菜单能够展示对应的AI菜单项，包括[TextMenuItemId](ts-text-common.md#textmenuitemid12)中的url（打开链接）、email（新建邮件）、phoneNumber（呼叫）、address（导航前往）、dateTime（新建日程）。

AI菜单生效时，选中范围内需包括且仅包括一个完整的AI实体，才能展示对应的选项。该菜单项与[TextMenuItemId](ts-text-common.md#textmenuitemid12)中的askAI菜单项不同时出现。

需要[CopyOptions](ts-appendix-enums.md#copyoptions9)为CopyOptions.LocalDevice或CopyOptions.CROSS_DEVICE时，本功能生效。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | --------------------------------- |
| enable  | boolean \| undefined | 是   | 是否开启选中文本实体识别。<br>true：开启识别，false：关闭识别。<br>值为undefined时，按默认值处理。 |

### passwordRules<sup>11+</sup>

passwordRules(value: string)

定义生成密码的规则。在触发自动填充时，所设置的密码规则会透传给密码保险箱，用于新密码的生成。<!--RP1--><!--RP1End-->

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| value  | string | 是   | 定义生成密码的规则。<br>**说明：**<br>需先设置[enableAutoFill](#enableautofill11)启用自动填充功能，并设置[contentType](#contenttype12)为NEW_PASSWORD类型，该属性在触发自动填充时生效。 |

### cancelButton<sup>11+</sup>

cancelButton(options: CancelButtonOptions)

设置右侧清除按钮样式，仅支持图片类型的图标。不支持[TextInputStyle](#textinputstyle9枚举说明)的内联模式。示例请参考[示例4（设置右侧清除按钮样式）](#示例4设置右侧清除按钮样式)。未通过该接口设置时，默认为{<br>style: CancelButtonStyle.INPUT<br>}，Wearable设备上图标默认尺寸为28vp。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| options  | [CancelButtonOptions](ts-basic-components-search.md#cancelbuttonoptions12对象说明) | 是   | 右侧清除按钮样式选项。 |

### selectAll<sup>11+</sup>

selectAll(value: boolean)

设置初始状态时，是否全选文本。不支持[TextInputStyle](#textinputstyle9枚举说明)的内联模式。未通过该接口设置时，默认不会全选文本。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | --------------------------------- |
| value  | boolean | 是   | 是否全选文本。<br>true表示会全选文本，false表示不会全选文本。 |

### showCounter<sup>11+</sup>

showCounter(value: boolean, options?: InputCounterOptions)

设置当通过InputCounterOptions输入的字符数超过阈值时显示计数器。未调用showCounter接口时，默认不显示计数器。

参数value为true时，才能设置options，文本框开启计数下标功能，需要配合[maxLength](#maxlength)（设置最大字符限制）一起使用。字符计数器显示的效果是当前输入字符数/最大可输入字符数。

当输入字符数大于最大字符数乘百分比值时，显示字符计数器。如果用户设置计数器时不设置InputCounterOptions，那么当前输入字符数超过最大字符数时，边框和计数器下标将变为红色。用户同时设置参数value为true和[InputCounterOptions](ts-universal-attributes-text-style.md#inputcounteroptions11对象说明)，当thresholdPercentage数值在有效区间内，且输入字符数超过最大字符数时，边框和计数器下标将变为红色，框体抖动。highlightBorder设置为false，则不显示红色边框，计数器默认显示红色，框体抖动。

[内联模式](../../../ui/arkts-common-components-text-input.md#内联模式)、[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)下字符计数器不显示。

[示例5（设置计数器）](#示例5设置计数器)展示了设置showCounter的效果。

>**说明：**
>
> 从API version 12开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名                | 类型                                                  | 必填 | 说明             |
| --------------------- | ----------------------------------------------------- | ---- | ---------------- |
| value                 | boolean                                               | 是   | 是否显示计数器。<br>true表示显示计数器，false表示不显示。 |
| options | [InputCounterOptions](ts-universal-attributes-text-style.md#inputcounteroptions11对象说明) | 否   | 计数器的配置项，用于设置计数器阈值百分比、边框高亮等。当需要自定义计数器显示规则时传入此参数。不传入时使用默认计数器配置（阈值百分比为100%，边框高亮为true）。 |

### contentType<sup>12+</sup>

contentType(value: ContentType)

设置自动填充类型。<!--RP7--><!--RP7End-->

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                  | 必填 | 说明           |
| ------ | ------------------------------------- | ---- | -------------- |
| value  | [ContentType](#contenttype12枚举说明) | 是   | 自动填充类型。取值范围：详见ContentType枚举说明。 |

### underlineColor<sup>12+</sup>

underlineColor(value: ResourceColor|UnderlineColor|undefined)

设置下划线颜色。未通过该接口设置时，默认为主题配置的下划线颜色，主题配置的默认下划线颜色为'#33182431'（深灰色，不透明度为20%）。

开启输入框下划线[showUnderline](#showunderline10)时，支持配置下划线颜色。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) \| [UnderlineColor](#underlinecolor12对象说明) \| undefined | 是   | 设置下划线颜色。<br>当设置下划线颜色模式时，修改下划线颜色。当只设定非特殊状态下的颜色，可以直接输入ResourceColor。设定值为undefined、null、无效值时，所有下划线恢复为默认值。 |

### lineHeight<sup>12+</sup>

lineHeight(value: number | string | Resource)

设置文本的行高。

设置值不大于0时，不限制文本行高，自适应字体大小，number类型时单位为fp。string类型支持number类型取值的字符串形式，可以附带单位，例如"10"、"10fp"。

> **说明：**
>
> - 特殊字符字体高度远超出同行的其他字符高度时，文本框出现截断、遮挡、内容相对位置发生变化等不符合预期的显示异常，需要开发者调整组件高度、行高等属性，修改对应的页面布局。
>
> - 设置[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，通过该接口设置行高[lineHeight](#lineheight12)不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本行高。<br>number类型时单位为fp。 |

### decoration<sup>12+</sup>

decoration(value: TextDecorationOptions)

设置文本装饰线类型样式及其颜色。未通过该接口设置时，默认为{<br>&nbsp;type:&nbsp;TextDecorationType.None,<br>&nbsp;color:&nbsp;Color.Black,<br>&nbsp;style:&nbsp;TextDecorationStyle.SOLID,<br>&nbsp;thicknessScale:&nbsp;1.0<br>}。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [TextDecorationOptions](ts-universal-attributes-text-style.md#textdecorationoptions12对象说明) | 是   | 文本装饰线对象。 |

>  **说明：**
>
>  当文字的下边缘轮廓与装饰线位置相交时，会触发下划线避让规则，下划线将在这些字符处避让文字。常见“gjyqp”等英文字符。
>
>  当文本装饰线的颜色设置为Color.Transparent时，装饰线颜色设置为跟随每行第一个字的字体颜色。当文本装饰线的颜色设置为透明色16进制对应值“#00FFFFFF”时，装饰线颜色设置为透明色。
>
>  设置[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，装饰线[decoration](#decoration12)、下划线[showUnderline](#showunderline10)、行高[lineHeight](#lineheight12)、文字特性[fontFeature](#fontfeature12)不生效。

### letterSpacing<sup>12+</sup>

letterSpacing(value: number | string | Resource)

设置文本字符间距。设置该值为百分比时，按默认值显示。设置该值为0时，按默认值显示。string类型支持number类型取值的字符串形式，可以附带单位，例如"10"、"10fp"。

当取值为负值时，文字会发生压缩，负值过小时会将组件内容区大小压缩为0，导致无内容显示。

对每个字符生效，包括行尾字符。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                       | 必填 | 说明           |
| ------ | -------------------------- | ---- | -------------- |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本字符间距。<br>单位：[fp](ts-pixel-units.md#基本像素单位) |

### fontFeature<sup>12+</sup>

fontFeature(value: string)

设置文字特性效果，比如数字等宽的特性。

格式为：normal \| \<feature-tag-value\>

\<feature-tag-value\>的格式为：\<string\> \[ \<integer\> \| on \| off ]

\<feature-tag-value\>的个数可以有多个，中间用','隔开。

例如，使用等宽数字的输入格式为："ss01" on。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| value  | string | 是   | 文字特性效果，用于设置OpenType字体高级排版能力（如等宽数字、连字等）。格式为normal或<feature-tag-value>，例如"ss01" on。 |

Font Feature当前支持的属性参见[fontFeature](ts-basic-components-text.md#fontfeature12)属性列表。

设置Font Feature属性，Font Feature是OpenType字体的高级排版能力，如支持连字、数字等宽等特性，一般用在自定义字体中，其能力需要字体本身支持。

更多Font Feature能力介绍可参考https://www.w3.org/TR/css-fonts-3/#font-feature-settings-prop和https://sparanoid.com/lab/opentype-features/。

>  **说明：**
>
>  设置[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，不支持通过fontFeature设置文本样式。

### wordBreak<sup>12+</sup>

wordBreak(value: WordBreak)

设置文本断行规则。该属性在组件设置[TextInputStyle](#textinputstyle9枚举说明)的内联模式时样式生效，但对placeholder文本无效。未通过该接口设置时，默认为WordBreak.BREAK_WORD。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| value  | [WordBreak](ts-appendix-enums.md#wordbreak11) | 是   | 内联输入风格编辑态时断行规则。 |

>  **说明：**
>
>  组件不支持clip属性设置，设置该属性任意枚举值对组件文本截断无影响。

### textOverflow<sup>12+</sup>

textOverflow(value: TextOverflow)

设置文本超长时的显示方式。仅在[TextInputStyle](#textinputstyle9枚举说明)值为内联模式的编辑态、非编辑态下支持。未通过该接口设置时，内联模式非编辑态下默认为TextOverflow.Ellipsis，内联模式编辑态下默认为TextOverflow.Clip。

文本截断是按字进行。例如，英文以单词为最小单位进行截断，若需要以字母为单位进行截断，可将wordBreak属性设置为WordBreak.BREAK_ALL。

当overflow设置为TextOverflow.None时，效果与TextOverflow.Clip相同。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                          | 必填 | 说明                                                                                                |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------------------------------------------------------------------------- |
| value  | [TextOverflow](ts-appendix-enums.md#textoverflow)            | 是   | 文本超长时的显示方式。 |

>  **说明：**  
>   TextInput组件不支持设置TextOverflow.MARQUEE模式，当设置为TextOverflow.MARQUEE模式时，[内联模式](../../../ui/arkts-common-components-text-input.md#内联模式)非编辑态下显示为TextOverflow.Ellipsis，内联模式编辑态下以及非内联模式下显示为TextOverflow.Clip。
>
>  未设置内联模式时，按照默认风格显示。若此时设置textOverflow，则不生效。

### textIndent<sup>12+</sup>

textIndent(value: Dimension)

设置首行文本缩进。未通过该接口设置时，默认为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                  | 必填 | 说明                         |
| ------ | ------------------------------------ | ---- | ---------------------------- |
| value  | [Dimension](ts-types.md#dimension10) | 是   | 首行文本缩进。<br>单位：[vp](ts-pixel-units.md#基本像素单位) <br>取值范围：大于等于0。设置负数时，按默认值处理。|

### minFontSize<sup>12+</sup>

minFontSize(value: number | string | Resource)

设置文本最小显示字号。string类型支持number类型取值的字符串形式，可以附带单位，例如"10"、"10fp"。

需配合[maxFontSize](#maxfontsize12)以及[maxLines](#maxlines10)(组件设置为内联输入风格且编辑态时使用)或布局大小限制使用，单独设置不生效。

自适应字号生效时，fontSize设置不生效。

minFontSize小于或等于0时，自适应字号不生效，此时按照[fontSize](#fontsize)属性的值生效，未设置时按照其默认值生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本最小显示字号。<br>单位：[fp](ts-pixel-units.md#基本像素单位)<br>需大于0，小于或等于0时自适应字号不生效，按fontSize属性值生效。<br>需配合maxFontSize使用，单独设置不生效。 |

### maxFontSize<sup>12+</sup>

maxFontSize(value: number | string | Resource)

设置文本最大显示字号。string类型支持number类型取值的字符串形式，可以附带单位，例如"10"、"10fp"。

需配合[minFontSize](#minfontsize12)以及[maxLines](#maxlines10)(组件设置为内联输入风格且编辑态时使用)或布局大小限制使用，单独设置不生效。

自适应字号生效时，fontSize设置不生效。

maxFontSize小于等于0或者maxFontSize小于minFontSize时，自适应字号不生效，此时按照[fontSize](#fontsize)属性的值生效，未设置时按照其默认值生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 文本最大显示字号。<br>单位：[fp](ts-pixel-units.md#基本像素单位)<br>需大于0且大于minFontSize，否则自适应字号不生效，按fontSize属性值生效。<br>需配合minFontSize使用，单独设置不生效。 |

### heightAdaptivePolicy<sup>12+</sup>

heightAdaptivePolicy(value: TextHeightAdaptivePolicy)

组件设置为内联输入风格时，设置文本自适应高度的方式。未通过该接口设置时，默认为TextHeightAdaptivePolicy.MAX_LINES_FIRST。

当设置为TextHeightAdaptivePolicy.MAX_LINES_FIRST时，优先使用[maxLines](#maxlines10)属性来调整文本高度。如果使用maxLines属性的布局大小超过了布局约束，则尝试在[minFontSize](#minfontsize12)和[maxFontSize](#maxfontsize12)的范围内缩小字体以显示更多文本。

当设置为TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST时，优先使用minFontSize属性来调整文本高度。如果使用minFontSize属性可以将文本布局在一行中，则尝试在minFontSize和maxFontSize的范围内增大字体并使用最大限度的字体大小。

当设置为TextHeightAdaptivePolicy.LAYOUT_CONSTRAINT_FIRST时，与TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST效果一样。

组件设置为非内联输入风格时，设置文本自适应高度(TextHeightAdaptivePolicy)的三种方式效果一样，即在minFontSize和maxFontSize的范围内缩小字体以显示更多文本。

>  **说明：**
>
>  组件设置为内联输入风格，编辑态与非编辑态存在字体大小不一致情况。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [TextHeightAdaptivePolicy](ts-appendix-enums.md#textheightadaptivepolicy10) | 是   | 文本自适应高度的方式。仅设置内联输入风格时该属性生效。 |

### showPassword<sup>12+</sup>

showPassword(visible: boolean)

设置密码的显隐状态。未通过该接口设置时，默认不显示密码。

当[InputType](#inputtype枚举说明)设置为Password、NEW_PASSWORD和NUMBER_PASSWORD模式时，密码保护功能才能生效。非密码输入模式则不会触发该功能。

[密码模式](../../../ui/arkts-common-components-text-input.md#密码模式)时，由于输入框后端的状态和前端应用侧的状态管理变量会不一致，可能导致末尾图标的状态异常。建议在[onSecurityStateChange](#onsecuritystatechange12)上增加状态同步。参考[示例1（设置与获取光标位置）](#示例1设置与获取光标位置)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| visible  | boolean | 是  | 是否显示密码。<br>true表示会显示密码，false表示不会显示密码。<br>建议在[onSecurityStateChange](#onsecuritystatechange12)回调中同步状态，避免末尾图标状态异常。 |

### lineBreakStrategy<sup>12+</sup>

lineBreakStrategy(strategy: LineBreakStrategy)

设置折行规则。该属性在wordBreak不等于BREAK_ALL的时候生效，不支持连字符。未通过该接口设置时，默认为LineBreakStrategy.GREEDY。

适用于需要优化文本换行效果的场景：LineBreakStrategy.GREEDY适用于优先填充每行的快速换行；LineBreakStrategy.HIGH_QUALITY适用于追求更优视觉效果的排版；LineBreakStrategy.BALANCED适用于需要均匀分配各行内容的布局。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| strategy | [LineBreakStrategy](ts-appendix-enums.md#linebreakstrategy12) | 是   | 文本的折行规则。<br>LineBreakStrategy.GREEDY表示贪婪折行，优先填充每行；LineBreakStrategy.HIGH_QUALITY表示高质量折行，平衡行长；LineBreakStrategy.BALANCED表示均衡折行，优化排版美观。 <br>**说明：**<br>仅设置[TextInputStyle](#textinputstyle9枚举说明)的内联模式时该属性生效。 |

### editMenuOptions<sup>12+</sup>

editMenuOptions(editMenu: EditMenuOptions)

设置自定义菜单扩展项，允许用户设置扩展项的文本内容、图标、回调方法。

调用[disableMenuItems](../arkts-apis-uicontext-textmenucontroller.md#disablemenuitems20)或[disableSystemServiceMenuItems](../arkts-apis-uicontext-textmenucontroller.md#disablesystemservicemenuitems20)接口屏蔽文本选择菜单内的系统服务菜单项时，editMenuOptions接口内回调方法[onCreateMenu](./ts-text-common.md#oncreatemenu12)的入参列表中不包含被屏蔽的菜单选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| editMenu  | [EditMenuOptions](ts-text-common.md#editmenuoptions) | 是   | 扩展菜单选项。 |

### enablePreviewText<sup>12+</sup>

enablePreviewText(enable: boolean)

设置是否开启输入预上屏。未通过该接口设置时，默认开启输入预上屏。

预上屏内容定义为文字暂存态，目前不支持文字拦截功能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| enable | boolean | 是   | 是否开启输入预上屏。<br>true表示开启输入预上屏，false表示不开启输入预上屏。 |

>  **说明：**
>
>  “预上屏”描述的是一种文字暂存状态。需要在输入法中开启预上屏功能，在输入文本过程中，未确认输入候选词时，文本框中显示标记文本。例如，通过拼音输入中文时，未确定候选词之前，在输入框中显示拼音字母，该状态称为文字预上屏。

### enableHapticFeedback<sup>13+</sup>

enableHapticFeedback(isEnabled: boolean)

设置是否开启触控反馈。未通过该接口设置时，默认开启触控反馈。

开启触控反馈时，需要在工程的[module.json5](../../../quick-start/module-configuration-file.md)中配置requestPermissions字段以开启振动权限，配置如下：

```json
"requestPermissions": [
  {
    "name": "ohos.permission.VIBRATE"
  }
]
```

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| isEnabled | boolean | 是   | 是否开启触控反馈。<br>true表示开启触控反馈，false表示不开启触控反馈。 |

### autoCapitalizationMode<sup>20+</sup>

autoCapitalizationMode(mode: AutoCapitalizationMode)

设置自动大小写模式的文本模式，只提供接口能力，具体实现以输入法应用为主。未通过该接口设置时，默认不产生大小写转换效果，具体实现以输入法应用为主。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| mode | [AutoCapitalizationMode](ts-text-common.md#autocapitalizationmode20枚举说明) | 是   | 自动大小写模式，用于设置输入法的大小写转换规则，具体实现以输入法应用为主。 |

### keyboardAppearance<sup>15+</sup>

keyboardAppearance(appearance: Optional\<KeyboardAppearance>)

设置输入框拉起的键盘样式，需要输入法适配后生效。具体参考[输入法应用沉浸模式](../../../inputmethod/inputmethod-immersive-mode-guide.md)。未通过该接口设置时，默认为KeyboardAppearance.NONE_IMMERSIVE。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------ |
| appearance | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[KeyboardAppearance](ts-text-common.md#keyboardappearance15枚举说明)> | 是   | 键盘样式。 |

### strokeWidth<sup>20+</sup>

strokeWidth(width: Optional\<LengthMetrics>)

设置文本描边的宽度。未通过该接口设置时，默认值为0，不做描边处理。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---------------- |
| width  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)> | 是   | 文本描边的宽度。如果LengthMetrics的unit值是PERCENT，当前设置不生效，按默认值处理。<br>若设置值小于0，显示实心字；若大于0，显示空心字。 |

### strokeColor<sup>20+</sup>

strokeColor(color: Optional\<ResourceColor>)

设置文本描边的颜色。未通过该接口设置时，默认为字体颜色，设置异常值时取默认值。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明       |
| ------ | ------------------------------------------ | ---- | ---------- |
| color  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 描边颜色。 |

### stopBackPress<sup>15+</sup>

stopBackPress(isStopped: Optional\<boolean>)

设置是否阻止返回键事件向其他组件或系统传递。设置为true时，TextInput拦截返回键事件，不向其他组件传递；设置为false时，返回键事件正常向其他组件或系统传递。适用于需要自定义返回键行为的场景，如表单未保存时拦截返回操作并弹出确认提示、自定义导航流程、游戏或特殊交互场景中需要接管返回键控制等。未通过该接口设置时，默认为true，异常值取默认值。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                | 必填 | 说明                                      |
| ------ | --------------------------------------------------- | ---- | ----------------------------------------- |
| isStopped  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否阻止返回键。<br>true表示阻止，false表示不阻止。 |

### halfLeading<sup>18+</sup>

halfLeading(halfLeading: Optional\<boolean>)

设置文本在行内垂直居中，将行间距平分至行的顶部与底部。未通过该接口设置时，默认为false。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| halfLeading | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是  | 设置文本是否垂直居中。<br>true表示将行间距平分至行的顶部与底部，false则不平分。 |

### minFontScale<sup>18+</sup>

minFontScale(scale: Optional\<number | Resource>)

设置文本最小的字体缩放倍数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| scale  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<number \| [Resource](ts-types.md#resource)> | 是   | 文本最小的字体缩放倍数，支持undefined类型。<br>取值范围：[0, 1]<br>**说明：** <br>设置的值小于0时，按值为0处理。设置的值大于1，按值为1处理。异常值默认不生效。<br>使用前需在工程中配置[configuration.json](../../../quick-start/app-configuration-file.md#configuration标签)文件和[app.json5](../../../quick-start/app-configuration-file.md)文件，具体详见[示例18（设置最小字体范围与最大字体范围）](#示例18设置最小字体范围与最大字体范围)。 |

### maxFontScale<sup>18+</sup>

maxFontScale(scale: Optional\<number | Resource>)

设置文本最大的字体缩放倍数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                          |
| ------ | --------------------------------------------- | ---- | --------------------------------------------- |
| scale  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<number \| [Resource](ts-types.md#resource)> | 是   | 文本最大的字体缩放倍数，支持undefined类型。<br>取值范围：[1, +∞)<br>**说明：** <br>设置的值小于1时，按值为1处理。异常值默认不生效。<br>当设置maxFontScale属性后，showError最多放大到2倍。<br>使用前需在工程中配置[configuration.json](../../../quick-start/app-configuration-file.md#configuration标签)文件和[app.json5](../../../quick-start/app-configuration-file.md)文件，具体详见[示例18（设置最小字体范围与最大字体范围）](#示例18设置最小字体范围与最大字体范围)。 |

### cancelButton<sup>18+</sup>

cancelButton(symbolOptions: CancelButtonSymbolOptions)

设置右侧清除按钮样式，仅支持symbol图标。不支持[TextInputStyle](#textinputstyle9枚举说明)的内联模式。示例请参考[示例15（设置symbol类型清除按钮）](#示例15设置symbol类型清除按钮)。未通过该接口设置时，默认为{<br>style: CancelButtonStyle.INPUT<br>}。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| symbolOptions  | [CancelButtonSymbolOptions](ts-basic-components-search.md#cancelbuttonsymboloptions12对象说明) | 是   | 右侧清除按钮样式。 |

### ellipsisMode<sup>18+</sup>

ellipsisMode(mode: Optional\<EllipsisMode>)

设置省略位置。ellipsisMode属性仅在[TextInputStyle](#textinputstyle9枚举说明)的内联模式下生效，需要配合[textOverflow](#textoverflow12)设置为TextOverflow.Ellipsis使用，单独设置ellipsisMode属性不生效。未通过该接口设置时，默认为EllipsisMode.END。

非编辑态时正常生效，编辑态时EllipsisMode.START和EllipsisMode.CENTER仅在maxLines设置为1时生效，EllipsisMode.END、EllipsisMode.MULTILINE_START和EllipsisMode.MULTILINE_CENTER正常生效。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                | 必填 | 说明                                      |
| ------ | --------------------------------------------------- | ---- | ----------------------------------------- |
| mode  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[EllipsisMode](ts-appendix-enums.md#ellipsismode11)> | 是   | 省略位置。 |

### enableAutoFillAnimation<sup>20+</sup>

enableAutoFillAnimation(enabled: Optional\<boolean>)

设置是否启用自动填充动效。未通过该接口设置时，默认为true。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| enabled  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否启用自动填充动效。<br>true表示启用，false表示不启用。<br>**说明：**<br>需先设置[enableAutoFill](#enableautofill11)启用自动填充功能。启用之后，仅输入模式[InputType](#inputtype枚举说明)设置为Password、NEW_PASSWORD或NUMBER_PASSWORD的输入框在进行自动填充时动效可生效。 |

### enableAutoSpacing<sup>20+</sup>

enableAutoSpacing(enabled: Optional\<boolean>)

设置是否开启中文与西文的自动间距。未通过该接口设置时，默认为false。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| enabled | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否开启中文与西文的自动间距。<br>true为开启自动间距，false为不开启。 |

### compressLeadingPunctuation<sup>23+</sup>

compressLeadingPunctuation(enabled: Optional\<boolean>)

设置是否开启行首标点符号压缩。未通过该接口设置时，默认不开启行首标点符号压缩。

> **说明：**
>
> - 支持压缩的标点符号，请参考[ParagraphStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#paragraphstyle)的行首压缩的标点范围。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| enabled | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否开启行首标点符号压缩。<br>true表示开启行首标点符号压缩；false表示不开启行首标点符号压缩。 |

### orphanCharOptimization

orphanCharOptimization(enabled: Optional\<boolean>)

设置文本排版时是否使能孤字优化。不通过该接口设置，默认不使能孤字优化。

使能后，会调整换行点以尽可能避免孤立字符（段落尾行首字符），改善文本布局。该特性需在wordBreak为非BREAK_ALL且待排版文本首个[TextStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#textstyle)的[locale](../../apis-arkgraphics2d/js-apis-graphics-text.md#textstyle)为"zh-Hans"或"zh-Hant"时生效。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型             | 必填 | 说明                                            |
| ---------------- | ------- | ---- | ----------------------------------------------- |
| enabled         | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是 | 段落最后一行是否使能孤字优化。<br>true表示使能孤字优化，false表示不使能孤字优化。<br>值为undefined或null时，不使能孤字优化。<br>孤字优化需在wordBreak为非BREAK_ALL并且待排版文本首个TextStyle的locale为"zh-Hans"或"zh-Hant"时生效。 |

### strokeJoinStyle

strokeJoinStyle(strokeJoinStyle: StrokeJoinStyle | undefined)

设置文本描边拐角样式，仅在使用strokeWidth设置文本描边时生效。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型             | 必填 | 说明                                            |
| ---------------- | ------- | ---- | ----------------------------------------------- |
| strokeJoinStyle         | [StrokeJoinStyle](ts-text-common.md#strokejoinstyle) \| undefined | 是 | 设置文本描边拐角样式，仅在使用strokeWidth设置文本描边时生效。<br>值为undefined时，按照StrokeJoinStyle.MITER_JOIN处理，请参考[StrokeJoinStyle](ts-text-common.md#strokejoinstyle)，文本拐角处表现为锐角。 |

### shaderStyle

shaderStyle(shader: ShaderStyle | undefined)

设置文本着色器效果，如线性渐变、径向渐变效果等。

> **说明：**
>
> 当同时设置shaderStyle和[strokeWidth](#strokewidth20)时，shaderStyle不生效。
>
> shaderStyle的优先级高于[fontColor](#fontcolor)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名           | 类型             | 必填 | 说明                                            |
| ---------------- | ------- | ---- | ----------------------------------------------- |
| shader         | [ShaderStyle](ts-text-common.md#shaderstyle20) \| undefined | 是 | 文本着色器效果，用于设置文本的渐变或特殊颜色效果。支持线性渐变、径向渐变、纯色等类型。<br>当同时设置shaderStyle和strokeWidth时，shaderStyle不生效。<br>值为undefined时，无渐变效果。 |

### punctuationOverflow

punctuationOverflow(enabled: Optional\<boolean>)

设置是否启用行尾标点符号悬挂。不通过该接口设置，默认标点符号不悬挂。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----- | ---- | ---- |
| enabled | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是 | 是否启用行尾标点符号悬挂。<br>true表示启用行尾标点符号悬挂，false表示不启用行尾标点符号悬挂。设置为undefined或null时，不启用标点符号悬挂。|

### includeFontPadding<sup>23+</sup>

includeFontPadding(include: Optional\<boolean>)

设置是否在首行和尾行增加间距以避免文字截断。不通过该接口设置，默认不增加间距。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| include | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否在首行和尾行增加间距以避免文字截断。<br>true表示在首行和尾行增加间距；false表示在首行和尾行不增加间距。 |

### fallbackLineSpacing<sup>23+</sup>

fallbackLineSpacing(enabled: Optional\<boolean>)

针对多行文字叠加，支持行高基于文字实际高度自适应。此接口仅当行高小于文字实际高度时生效。不通过该接口设置，默认行高不基于文字实际高度自适应。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| enabled | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 行高是否基于文字实际高度自适应。<br>true表示行高基于文字实际高度自适应；false表示行高不基于文字实际高度自适应。<br>此接口仅当行高小于文字实际高度时生效。 |

### selectedDragPreviewStyle<sup>23+</sup>

selectedDragPreviewStyle(value: SelectedDragPreviewStyle | undefined)

设置文本输入框内文本拖拽时的背板样式。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                             | 必填 | 说明                                                       |
| ------ | ------------------------------------------------ | ---- | ---------------------------------------------------------- |
| value  | [SelectedDragPreviewStyle](ts-text-common.md#selecteddragpreviewstyle23对象说明) \| undefined | 是   | 文本拖拽时的背板样式。<br>设置为undefined时：背板颜色跟随主题，浅色模式显示白色，深色模式显示黑色。|

## InputType枚举说明

单行文本输入框类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

<!--Table: 25%; 8%; 67%-->
| 名称                          |  值   | 说明                       |
| ----------------------------- | ----- | --------------------------- |
| Normal                        | 0 | 基本输入模式，无特殊限制。<br>内联输入风格只支持InputType.Normal类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Number                        | 2 | 纯数字输入模式。<br>不支持负数、小数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| PhoneNumber<sup>9+</sup>      | 3 | 电话号码输入模式。<br>支持输入数字、空格、+ 、-、*、#、(、)，长度不限。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Email                         | 5 | 邮箱地址输入模式。<br>支持数字、字母、下划线、小数点、!、#、$、%、&、'、"、*、+、-、/、=、?、^、`、\{、\|、\}、~，以及@（仅支持一个）。邮箱地址格式需符合基本规范：@字符前为用户名部分，@字符后为域名部分。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Password                      | 7 | 密码输入模式。<br>默认输入文字短暂显示后变成圆点。从API version 12开始，PC/2in1设备上输入文字直接显示为圆点。<br>TV设备上输入框末尾默认不显示小眼睛图标，其他设备输入框末尾默认显示小眼睛图标。<br>密码输入模式中，[decoration](#decoration12)、[showUnderline](#showunderline10)、[lineHeight](#lineheight12)、[fontFeature](#fontfeature12)不生效。<br>在已启用密码保险箱的情况下，支持用户名、密码的自动保存和自动填充。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NUMBER_PASSWORD<sup>11+</sup> | 8 | 纯数字密码输入模式。<br>默认输入文字短暂显示后变成圆点。从API version 12开始，PC/2in1设备上输入文字直接显示为圆点。<br>TV设备上输入框末尾默认不显示小眼睛图标，其他设备输入框末尾默认显示小眼睛图标。<br>密码输入模式中，[decoration](#decoration12)、[showUnderline](#showunderline10)、[lineHeight](#lineheight12)、[fontFeature](#fontfeature12)不生效。在已启用密码保险箱的情况下，支持用户名、密码的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| USER_NAME<sup>11+</sup>       | 10 | 用户名输入模式，无特殊限制。<br>在已启用密码保险箱的情况下，支持用户名的自动保存和自动填充，用于配合[InputType.Password](#inputtype枚举说明)、[InputType.NUMBER_PASSWORD](#inputtype枚举说明)、[InputType.NEW_PASSWORD](#inputtype枚举说明)完成用户名密码配对填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| NEW_PASSWORD<sup>11+</sup>    | 11 | 新密码输入模式。<br>默认输入文字短暂显示后变成圆点。从API version 12开始，PC/2in1设备上输入文字直接显示为圆点。<br>TV设备上输入框末尾默认不显示小眼睛图标，其他设备输入框末尾默认显示小眼睛图标。<br>密码输入模式中，[decoration](#decoration12)、[showUnderline](#showunderline10)、[lineHeight](#lineheight12)、[fontFeature](#fontfeature12)不生效。在已启用密码保险箱的情况下，支持自动生成新密码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| NUMBER_DECIMAL<sup>11+</sup>  | 12 | 带小数点的数字输入模式。<br>支持数字，小数点（只能存在一个小数点）。不支持负数（包括负数整数和负数小数）。若需支持负数输入，请使用[inputFilter](#inputfilter8)属性实现负数过滤。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| URL<sup>12+</sup>  | 13 | 带URL的输入模式，无特殊限制。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| ONE_TIME_CODE<sup>20+</sup>  | 14 | 验证码输入模式，无特殊限制。该模式下组件获焦后会默认拉起系统输入法。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## ContentType<sup>12+</sup>枚举说明

自动填充类型。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

<!--Table: 25%; 8%; 67%-->
| 名称                       | 值   | 说明                                                         |
| -------------------------- | ---- | ------------------------------------------------------------ |
| USER_NAME                  | 0    | 【用户名】在已启用密码保险箱的情况下，支持用户名的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PASSWORD                   | 1    | 【密码】在已启用密码保险箱的情况下，支持密码的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NEW_PASSWORD               | 2    | 【新密码】在已启用密码保险箱的情况下，支持自动生成新密码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| FULL_STREET_ADDRESS        | 3    | 【详细地址】在已启用情景化自动填充的情况下，支持详细地址的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| HOUSE_NUMBER               | 4    | 【门牌号】在已启用情景化自动填充的情况下，支持门牌号的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| DISTRICT_ADDRESS           | 5    | 【区/县】在已启用情景化自动填充的情况下，支持区/县的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CITY_ADDRESS               | 6    | 【市】在已启用情景化自动填充的情况下，支持市的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PROVINCE_ADDRESS           | 7    | 【省】在已启用情景化自动填充的情况下，支持省的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| COUNTRY_ADDRESS            | 8    | 【国家】在已启用情景化自动填充的情况下，支持国家的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PERSON_FULL_NAME           | 9    | 【姓名】在已启用情景化自动填充的情况下，支持姓名的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PERSON_LAST_NAME           | 10   | 【姓氏】在已启用情景化自动填充的情况下，支持姓氏的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PERSON_FIRST_NAME          | 11   | 【名字】在已启用情景化自动填充的情况下，支持名字的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PHONE_NUMBER               | 12   | 【手机号码】在已启用情景化自动填充的情况下，支持手机号码的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PHONE_COUNTRY_CODE         | 13   | 【国家代码】在已启用情景化自动填充的情况下，支持国家代码的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| FULL_PHONE_NUMBER          | 14   | 【包含国家代码的手机号码】在已启用情景化自动填充的情况下，支持包含国家代码的手机号码的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| EMAIL_ADDRESS              | 15   | 【邮箱地址】在已启用情景化自动填充的情况下，支持邮箱地址的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BANK_CARD_NUMBER           | 16   | 【银行卡号】在已启用情景化自动填充的情况下，支持银行卡号的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| ID_CARD_NUMBER             | 17   | 【身份证号】在已启用情景化自动填充的情况下，支持身份证号的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NICKNAME                   | 23   | 【昵称】在已启用情景化自动填充的情况下，支持昵称的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| DETAIL_INFO_WITHOUT_STREET | 24   | 【无街道地址】在已启用情景化自动填充的情况下，支持无街道地址的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| FORMAT_ADDRESS             | 25   | 【标准地址】在已启用情景化自动填充的情况下，支持标准地址的自动保存和自动填充。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PASSPORT_NUMBER<sup>18+</sup>            | 26   | 【护照号】在已启用情景化自动填充的情况下，支持护照号的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| VALIDITY<sup>18+</sup>                   | 27   | 【护照有效期】在已启用情景化自动填充的情况下，支持护照有效期的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| ISSUE_AT<sup>18+</sup>                   | 28   | 【护照签发地】在已启用情景化自动填充的情况下，支持护照签发地的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| ORGANIZATION<sup>18+</sup>               | 29   | 【发票抬头名称】在已启用情景化自动填充的情况下，支持发票抬头名称的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| TAX_ID<sup>18+</sup>                     | 30   | 【税号】在已启用情景化自动填充的情况下，支持税号的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| ADDRESS_CITY_AND_STATE<sup>18+</sup>     | 31   | 【所在地区】在已启用情景化自动填充的情况下，支持所在地区的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| FLIGHT_NUMBER<sup>18+</sup>              | 32   | 【航班号】暂不支持自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| LICENSE_NUMBER<sup>18+</sup>             | 33   | 【驾驶证号】暂不支持自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| LICENSE_FILE_NUMBER<sup>18+</sup>        | 34   | 【驾驶证档案编号】暂不支持自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| LICENSE_PLATE<sup>18+</sup>              | 35   | 【车牌号】在已启用情景化自动填充的情况下，支持车牌号的自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| ENGINE_NUMBER<sup>18+</sup>              | 36   | 【行驶证发动机号】暂不支持自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| LICENSE_CHASSIS_NUMBER<sup>18+</sup>     | 37   | 【车架号】暂不支持自动保存和自动填充。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

## TextInputStyle<sup>9+</sup>枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值 | 说明                                                         |
| ------- | ---- | ------------------------------------------------------------ |
| Default | - | 默认风格，光标宽1.5vp，光标高度与文本选中底板高度和字体大小相关。 |
| Inline  | - | 内联输入风格，也称内联模式。文本选中底板高度与输入框高度相同。<br>内联输入是在有明显的编辑态/非编辑态的区分场景下使用，例如：文件列表视图中的重命名。<br>不支持showError属性。<br>不支持showCounter属性，内联模式下字符计数器不显示。<br>内联模式下，不支持拖入文本。 |

## PasswordIcon<sup>10+</sup>对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 只读 | 可选   | 说明 |
| ---- | ----- | ---- | ---- |---- |
| onIconSrc  | string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否 | 是   | 密码输入模式时，能够切换密码可见时显示的图标。默认为系统提供的密码图标。<br>string格式可用于加载网络图片和本地图片。<br>网络图片支持http或https协议的URL格式；本地图片支持应用资源路径格式。 |
| offIconSrc | string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否    | 是 | 密码输入模式时，能够切换密码不可见时显示的图标。默认为系统提供的密码图标。<br>string格式可用于加载网络图片和本地图片。<br>网络图片支持http或https协议的URL格式；本地图片支持应用资源路径格式。 |

## EnterKeyType枚举说明

输入法回车键类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                   | 值 | 说明               |
| ---------------------- | --- | ------------------ |
| Go                     | 2 | 显示为开始样式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| Search                 | 3 | 显示为搜索样式。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| Send                   | 4 | 显示为发送样式。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| Next                   | 5 | 显示为下一步样式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| Done                   | 6 | 显示为完成样式。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| PREVIOUS<sup>11+</sup> | 7 | 显示为上一步样式。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| NEW_LINE<sup>11+</sup> | 8 | 显示为换行样式。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。  |

## 事件

除支持[通用事件](ts-component-general-events.md)外，还支持以下事件：

### onChange

onChange(callback:&nbsp;EditableTextOnChangeCallback)

输入内容发生变化时，触发该回调。

在本回调中，若执行了光标操作，需要开发者在预上屏场景下依据previewText参数调整光标逻辑，以适应预上屏场景。

> **说明：**
>
> onWillChange和onChange形成will/did时序模式：
> - onWillChange在文本变更前触发，可通过返回false拦截变更；返回true则允许变更，随后触发onChange。
> - onChange在变更完成后触发，无法拦截。
> - 两者可以同时使用，onWillChange用于拦截控制，onChange用于获取变更结果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| callback  | [EditableTextOnChangeCallback](ts-text-common.md#editabletextonchangecallback12) | 是   | 当前输入文本内容变化时的回调。 |

### onSubmit

onSubmit(callback: OnSubmitCallback)

按下输入法回车键触发该回调。

非TV设备按下回车键时输入框默认会失焦且收起键盘，可在OnSubmitCallback回调中配置是否收起键盘，参考[示例2（设置下划线）](#示例2设置下划线)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                             | 必填 | 说明                                                         |
| ------------------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback            | [OnSubmitCallback](#onsubmitcallback18) | 是   | 提交回调。 |

### onEditChanged<sup>(deprecated)</sup>

onEditChanged(callback:&nbsp;(isEditing:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)

输入状态变化时，触发该回调。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[onEditChange](#oneditchange8)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型    | 必填 | 说明                 |
| --------- | ------- | ---- | -------------------- |
| isEditing | boolean | 是   | 当前是否正在输入中。<br>true表示正在输入，即输入框处于编辑态，有光标显示，可以接收用户输入；false表示当前没有输入，即输入框处于非编辑态，无光标显示，不能接收用户输入。 |

### onEditChange<sup>8+</sup>

onEditChange(callback: Callback\<boolean>)

输入状态变化时，触发该回调。有光标时为编辑态，无光标时为非编辑态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型    | 必填 | 说明                 |
| --------- | ------- | ---- | -------------------- |
| callback | Callback\<boolean> | 是   | 输入状态变化回调，返回值为true表示输入框处于编辑态（有光标显示，可以接收用户输入）；返回值为false表示输入框处于非编辑态（无光标显示，不能接收用户输入）。 |

### onCopy<sup>8+</sup>

onCopy(callback: Callback\<string>)

进行复制操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型    | 必填 | 说明             |
| --------- | ------- | ---- | ---------------- |
| callback | Callback\<string> | 是   | 复制回调，其返回值为复制的文本内容。 |

### onWillCopy

onWillCopy(callback: Callback\<string, boolean>)

在进行复制操作前，触发该回调。

> **说明：**
>
> onWillCopy和onCopy形成will/did时序模式：
> - onWillCopy在复制操作前触发，可通过返回false拦截复制操作；返回true则允许复制，随后触发onCopy。
> - onCopy在复制操作完成后触发，无法拦截。
> - 两者可以同时使用，onWillCopy用于拦截控制，onCopy用于获取复制结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| callback  | Callback\<string, boolean> | 是   | 复制操作前的回调。回调参数类型为string时，表示将要被复制的文本内容。回调参数类型为boolean时，表示当前选中文本是否允许被复制，true：允许文本被复制，执行正常的复制操作；false：不允许文本被复制，拦截此次复制操作，文本不会被复制到剪贴板。 |

### onCut<sup>8+</sup>

onCut(callback: Callback\<string>)

进行剪切操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型    | 必填 | 说明             |
| --------- | ------- | ---- | ---------------- |
| callback | Callback\<string> | 是   | 剪切回调，其返回值为剪切的文本内容。 |

### onWillCut

onWillCut(callback: Callback\<string, boolean>)

在进行剪切操作前，触发该回调。

**起始版本：** 26.0.0

> **说明：**
>
> onWillCut和onCut形成will/did时序模式：
> - onWillCut在剪切操作前触发，可通过返回false拦截剪切操作；返回true则允许剪切，随后触发onCut。
> - onCut在剪切操作完成后触发，无法拦截。
> - 两者可以同时使用，onWillCut用于拦截控制，onCut用于获取剪切结果。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| callback  | Callback\<string, boolean> | 是   | 剪切操作前的回调。回调参数类型为string时，表示将要被剪切的文本内容。回调参数类型为boolean时，表示当前选中文本是否允许被剪切，true：允许文本被剪切，执行正常的剪切操作；false：不允许文本被剪切，拦截此次剪切操作，文本不会被剪切到剪贴板也不会从输入框中删除。 |

### onPaste<sup>8+</sup>

onPaste(callback: OnPasteCallback)

进行粘贴操作时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 
| 参数名              | 类型                                                         | 必填 | 说明                   |
| ------------------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | [OnPasteCallback](#onpastecallback18)       | 是   | 粘贴回调。 |

### onTextSelectionChange<sup>10+</sup>

onTextSelectionChange(callback: OnTextSelectionChangeCallback)

文本选择的位置或编辑状态下光标位置发生变化时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型   | 必填 | 说明                                    |
| -------------- | ------ | ---- | --------------------------------------- |
| callback | [OnTextSelectionChangeCallback](#ontextselectionchangecallback18) | 是   | 文本选择变化回调或光标位置变化回调。 |

### onContentScroll<sup>10+</sup>

onContentScroll(callback: OnContentScrollCallback)

文本内容滚动时，触发该回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型   | 必填 | 说明                               |
| ------------ | ------ | ---- | ---------------------------------- |
| callback | [OnContentScrollCallback](#oncontentscrollcallback18) | 是   | 文本内容滚动回调。 |

### onSecurityStateChange<sup>12+</sup>

onSecurityStateChange(callback: Callback\<boolean>)

密码显隐状态切换时，触发该回调。

>**说明：**
>
> 从API version 20开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型   | 必填 | 说明                               |
| ------------ | ------ | ---- | ---------------------------------- |
| callback | Callback\<boolean> | 是   | 回调函数。<br>true表示密码显示；false表示密码隐藏。|

### onWillInsert<sup>12+</sup>

onWillInsert(callback: Callback\<InsertValue, boolean>)

在将要输入时，触发该回调。

> **说明：**
>
> onWillInsert和onDidInsert形成will/did时序模式：
> - onWillInsert在输入操作前触发，可通过返回false拦截输入操作；返回true则允许输入，随后触发onDidInsert。
> - onDidInsert在输入完成后触发，无法拦截。
> - 两者可以同时使用，onWillInsert用于拦截控制，onDidInsert用于获取输入结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[InsertValue](ts-text-common.md#insertvalue12对象说明), boolean> | 是   | 在将要输入时调用的回调。<br>回调参数类型为InsertValue时，包含将要插入的文本内容等信息。回调参数类型为boolean时，表示是否允许此次插入，返回true：允许文本正常插入到输入框中；返回false：拦截此次插入操作，文本不会被插入。开发者可通过此回调实现对输入内容的过滤和拦截。<br>在预上屏和候选词操作时，该回调不触发。<br>仅支持系统输入法输入的场景。 |

### onDidInsert<sup>12+</sup>

onDidInsert(callback: Callback\<InsertValue>)

在输入完成时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[InsertValue](ts-text-common.md#insertvalue12对象说明)> | 是   | 在输入完成时调用的回调。<br>仅支持系统输入法输入的场景。 |

### onWillDelete<sup>12+</sup>

onWillDelete(callback: Callback\<DeleteValue, boolean>)

在将要删除时，触发该回调。

> **说明：**
>
> - 点击清除按钮不触发onWillDelete回调。
> - onWillDelete和onDidDelete形成will/did时序模式：
>   - onWillDelete在删除操作前触发，可通过返回false拦截删除操作；返回true则允许删除，随后触发onDidDelete。
>   - onDidDelete在删除完成后触发，无法拦截。
>   - 两者可以同时使用，onWillDelete用于拦截控制，onDidDelete用于获取删除结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[DeleteValue](ts-text-common.md#deletevalue12对象说明), boolean> | 是   | 在将要删除时调用的回调。<br>回调参数类型为DeleteValue时，包含将要删除的文本内容等信息。回调参数类型为boolean时，表示是否允许此次删除，返回true：允许文本正常删除；返回false：拦截此次删除操作，文本不会被删除。开发者可通过此回调实现对删除操作的拦截和控制。<br>在预上屏删除操作时，该回调不触发。<br>仅支持系统输入法输入的场景。 |

### onDidDelete<sup>12+</sup>

onDidDelete(callback: Callback\<DeleteValue>)

在删除完成时，触发该回调。

> **说明：**
>
> - 点击清除按钮不触发onDidDelete回调。
> - onWillDelete和onDidDelete形成will/did时序模式：
>   - onWillDelete在删除操作前触发，可通过返回false拦截删除操作；返回true则允许删除，随后触发onDidDelete。
>   - onDidDelete在删除完成后触发，无法拦截。
>   - 两者可以同时使用，onWillDelete用于拦截控制，onDidDelete用于获取删除结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[DeleteValue](ts-text-common.md#deletevalue12对象说明)> | 是   | 在删除完成时调用的回调。<br>仅支持系统输入法输入的场景。 |

### onWillChange<sup>15+</sup>

onWillChange(callback: Callback\<EditableTextChangeValue, boolean>)

在文本内容将要发生变化时，触发该回调。

> **说明：**
> - onWillChange的回调时序晚于onWillInsert、onWillDelete，早于onDidInsert、onDidDelete。
> - onWillChange和onChange形成will/did时序模式：
>   - onWillChange在文本变更前触发，可通过返回false拦截变更；返回true则允许变更，随后触发onChange。
>   - onChange在变更完成后触发，无法拦截。
>   - 两者可以同时使用，onWillChange用于拦截控制，onChange用于获取变更结果。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[EditableTextChangeValue](ts-text-common.md#editabletextchangevalue15), boolean> | 是   | 在文本内容将要发生变化时的回调。<br>回调参数类型为EditableTextChangeValue时，包含文本变化的相关信息。回调参数类型为boolean时，表示是否允许此次文本变化，返回true：允许文本正常修改，变化会生效；返回false：拦截此次文本变化操作，文本内容不会发生改变。开发者可通过此回调实现对文本变化的拦截和控制。 |

### onWillAttachIME<sup>20+</sup>

onWillAttachIME(callback: Callback\<IMEClient>)

在输入框将要绑定输入法前触发该回调。

<!--Del-->
在输入框将要绑定输入法前，可以通过`UIContext`的系统接口[setKeyboardAppearanceConfig](../js-apis-arkui-UIContext-sys.md#setkeyboardappearanceconfig20)设置键盘的样式。<!--DelEnd-->

从API version 22开始，调用[IMEClient](ts-text-common.md#imeclient20对象说明)的[setExtraConfig](ts-text-common.md#setextraconfig22)方法可以设置输入法扩展信息。在绑定输入法成功后，输入法会收到扩展信息，输入法可以依据此信息实现自定义功能。

IMEClient仅在onWillAttachIME执行期间有效，不可进行异步调用。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| callback  | Callback\<[IMEClient](ts-text-common.md#imeclient20对象说明)> | 是   | 在输入框将要绑定输入法前触发该回调。 |

## TextInputController<sup>8+</sup>

TextInput组件的控制器继承自[TextContentControllerBase](ts-universal-attributes-text-style.md#textcontentcontrollerbase)，涉及的接口有[getTextContentRect](ts-universal-attributes-text-style.md#gettextcontentrect)、[getTextContentLineCount](ts-universal-attributes-text-style.md#gettextcontentlinecount)、[getCaretOffset](ts-universal-attributes-text-style.md#getcaretoffset11)、[addText](ts-universal-attributes-text-style.md#addtext15)、[deleteText](ts-universal-attributes-text-style.md#deletetext15)、[getSelection](ts-universal-attributes-text-style.md#getselection15)、[clearPreviewText](ts-universal-attributes-text-style.md#clearpreviewtext17)、[setStyledPlaceholder](ts-universal-attributes-text-style.md#setstyledplaceholder22)、[deleteBackward](ts-universal-attributes-text-style.md#deletebackward23)、[scrollToVisible](ts-universal-attributes-text-style.md#scrolltovisible23)<!--Del-->以及系统接口[getText](ts-text-common-sys.md#gettext19)<!--DelEnd-->。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 导入对象
```ts
controller: TextInputController = new TextInputController();
```

### constructor<sup>8+</sup>

constructor()

TextInputController的构造函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### caretPosition<sup>8+</sup>

caretPosition(value:&nbsp;number): void

设置输入光标的位置。当取值小于0时，取0，大于文本长度时，显示在文本末尾。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明  |
| ----- | ------ | ---- | ------ |
| value | number | 是    | 从字符串开始到光标所在位置的字符长度。 |
### setTextSelection<sup>10+</sup>

setTextSelection(selectionStart:&nbsp;number, selectionEnd:&nbsp;number, options?:&nbsp;SelectionOptions): void

设置文本选择区域并高亮显示。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| selectionStart | number | 是    | 文本选择区域起始位置，文本框中文字的起始位置为0。当selectionStart<0时，按照0处理；当selectionStart大于文本长度时，按照文本长度处理。 |
| selectionEnd   | number | 是    | 文本选择区域结束位置。当selectionEnd<0时，按照0处理；当selectionEnd大于文本长度时，按照文本长度处理。|
| options<sup>12+</sup>   | [SelectionOptions](ts-universal-attributes-text-style.md#selectionoptions12对象说明) | 否    | 选中文字时的配置，用于控制文本选择菜单的显示策略。<br>配置项包括menuPolicy，用于指定菜单显示方式：MenuPolicy.DEFAULT表示按系统默认行为显示菜单；MenuPolicy.SHOW表示强制显示菜单；MenuPolicy.HIDE表示强制隐藏菜单。<br>默认值MenuPolicy.DEFAULT<br>从API version 12开始，该接口中的options参数支持在原子化服务中使用。 |

>  **说明：**
>
>  如果selectionStart或selectionEnd被赋值为undefined时，当作0处理。
>
>  如果selectionMenuHidden被赋值为true或设备为2in1时，即使options被赋值为MenuPolicy.SHOW，调用setTextSelection也不弹出菜单。
>
>  如果emoji表情被选中区域截断时，表情的起始位置包含在设置的文本选中区域内就会被选中。

### stopEditing<sup>10+</sup>

stopEditing(): void

退出编辑态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## UnderlineColor<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 只读 | 可选   | 说明 |
| ---- | ----- | ---- | ---- | ---- |
| typing  | [ResourceColor](ts-types.md#resourcecolor) \| undefined | 否   | 是 | 键入时下划线颜色。不填写、undefined、null、无效值时恢复默认，默认为主题配置的下划线颜色。 |
| normal  | [ResourceColor](ts-types.md#resourcecolor) \| undefined | 否   | 是 | 非特殊状态时下划线颜色。不填写、undefined、null、无效值时恢复默认，默认为主题配置的下划线颜色。 |
| error   | [ResourceColor](ts-types.md#resourcecolor) \| undefined | 否   | 是 | 错误时下划线颜色。不填写、undefined、null、无效值时恢复默认，默认为主题配置的下划线颜色。此选项会修改showCounter属性中达到最大字符数时的颜色。 |
| disable | [ResourceColor](ts-types.md#resourcecolor) \| undefined | 否   | 是 | 禁用时下划线颜色。不填写、undefined、null、无效值时恢复默认，默认为主题配置的下划线颜色。 |

## SubmitEvent<sup>11+</sup>

定义用户提交事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 只读 | 可选   | 说明 |
| ---- | ----- | ---- | ---- | ---- |
| text              | string     | 否   | 否 | 输入框文本内容。                                   |

### keepEditableState<sup>11+</sup>

keepEditableState(): void

用户自定义输入框编辑状态，调用时保持编辑态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## OnPasteCallback<sup>18+</sup>

type OnPasteCallback = (content: string, event: PasteEvent) => void

粘贴回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名              | 类型                                                         | 必填 | 说明                   |
| ------------------- | ------------------------------------------------------------ | ---- | ---------------------- |
| content               | string                                                       | 是   | 粘贴的文本内容。       |
| event | [PasteEvent](ts-basic-components-richeditor.md#pasteevent11) | 是   | 用户自定义的粘贴事件。 |

## OnSubmitCallback<sup>18+</sup>

type OnSubmitCallback = (enterKey: EnterKeyType, event: SubmitEvent) => void

提交回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名              | 类型                                             | 必填 | 说明                                                         |
| ------------------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| enterKey            | [EnterKeyType](#enterkeytype枚举说明) | 是   | 输入法回车键类型。 |
| event | [SubmitEvent](#submitevent11)         | 是   | 提交事件。可以控制是否收起键盘。                                                   |

## OnTextSelectionChangeCallback<sup>18+</sup>

type OnTextSelectionChangeCallback = (selectionStart: number, selectionEnd: number) => void

文本选择变化回调或光标位置变化回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名         | 类型   | 必填 | 说明                                    |
| -------------- | ------ | ---- | --------------------------------------- |
| selectionStart | number | 是   | 所选文本的起始位置，文字的起始位置为0。 |
| selectionEnd   | number | 是   | 所选文本的结束位置。                    |

## OnContentScrollCallback<sup>18+</sup>

type OnContentScrollCallback = (totalOffsetX: number, totalOffsetY: number) => void

文本内容滚动回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型   | 必填 | 说明                               |
| ------------ | ------ | ---- | ---------------------------------- |
| totalOffsetX | number | 是   | 文本在内容区的横坐标偏移，单位px。 |
| totalOffsetY | number | 是   | 文本在内容区的纵坐标偏移，单位px。 |

## 示例

### 示例1（设置与获取光标位置）

从API version 8开始，该示例通过[controller](#textinputcontroller8)实现了光标位置的设置与获取的功能，同时，可以使用!!实现text参数的双向数据绑定（从API version 18开始）。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  // index：光标所在位置的索引值
  // x：光标相对输入框的x坐标位值，单位px
  // y：光标相对输入框的y坐标位值，单位px
  @State positionInfo: CaretOffset = { index: 0, x: 0, y: 0 }; 
  @State passwordState: boolean = false;
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ text: this.text!!, placeholder: 'input your word...', controller: this.controller })
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .caretColor(Color.Blue)
        .width('95%')
        .height(40)
        .margin(20)
        .fontSize(14)
        .fontColor(Color.Black)
        .inputFilter('[a-z]', (e) => {
          console.info(JSON.stringify(e));
        })
      Text(this.text)
      Button('Set caretPosition 1')
        .margin(15)
        .onClick(() => {
          // 将光标移动至第一个字符后
          this.controller.caretPosition(1);
        })
      Button('Get CaretOffset')
        .margin(15)
        .onClick(() => {
          // 获取光标相对输入框的位置
          this.positionInfo = this.controller.getCaretOffset();
        })
      // 密码输入框
      TextInput({ placeholder: 'input your password...' })
        .width('95%')
        .height(40)
        .margin(20)
        .type(InputType.Password)
        .maxLength(9)
        .showPasswordIcon(true)
        .showPassword(this.passwordState)
        .onSecurityStateChange(((isShowPassword: boolean) => {
          // 更新密码显示状态
          console.info('isShowPassword', isShowPassword);
          this.passwordState = isShowPassword;
        }))
      // 邮箱地址自动填充类型
      TextInput({ placeholder: 'input your email...' })
        .width('95%')
        .height(40)
        .margin(20)
        .contentType(ContentType.EMAIL_ADDRESS)
        .maxLength(9)
      // 内联风格输入框
      TextInput({ text: 'inline style' })
        .width('95%')
        .height(50)
        .margin(20)
        .borderRadius(0)
        .style(TextInputStyle.Inline)
    }.width('100%')
  }
}
```

![TextInput](figures/TextInput.gif)

### 示例2（设置下划线）

从API version 10开始支持，该示例通过[showUnderline](#showunderline10)、[showError](#showerror10)、[showUnit](#showunit10)、[passwordIcon](#passwordicon10)属性展示了下划线在不同场景的效果，同时，可以通过[underlineColor](#underlinecolor12)（从API version 12开始）支持配置下划线颜色。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  // $r('app.media.ImageOne')需要替换为开发者所需的图像资源文件。
  @State passWordSrc1: Resource = $r('app.media.ImageOne'); 
  // $r('app.media.ImageTwo')需要替换为开发者所需的图像资源文件。
  @State passWordSrc2: Resource = $r('app.media.ImageTwo'); 
  @State textError: string = '';
  @State text: string = '';
  @State nameText: string = 'test';

  @Builder
  itemEnd() {
    Select([{ value: 'KB' },
      { value: 'MB' },
      { value: 'GB' },
      { value: 'TB', }])
      .height('48vp')
      .borderRadius(0)
      .selected(2)
      .align(Alignment.Center)
      .value('MB')
      .font({ size: 20, weight: 500 })
      .fontColor('#182431')
      .selectedOptionFont({ size: 20, weight: 400 })
      .optionFont({ size: 20, weight: 400 })
      .backgroundColor(Color.Transparent)
      .responseRegion({
        height: '40vp',
        width: '80%',
        x: '10%',
        y: '6vp'
      })
      .onSelect((index: number) => {
        console.info('Select:' + index);
      })
  }

  build() {
    Column({ space: 20 }) {
      // 自定义密码显示图标
      TextInput({ placeholder: 'user define password icon' })
        .type(InputType.Password)
        .width(350)
        .height(60)
        .passwordIcon({ onIconSrc: this.passWordSrc1, offIconSrc: this.passWordSrc2 })
      // 下划线模式
      TextInput({ placeholder: 'underline style' })
        .showUnderline(true)
        .width(350)
        .height(60)
        .showError('Error')
        .showUnit(this.itemEnd)

      Text(`用户名：${this.text}`)
        .width(350)
      TextInput({ placeholder: '请输入用户名', text: this.text })
        .showUnderline(true)
        .width(350)
        .showError(this.textError)
        .onChange((value: string) => {
          this.text = value;
        })
        .onSubmit((enterKey: EnterKeyType, event: SubmitEvent) => {
          // 用户名不正确会清空输入框和用户名并提示错误文本
          if (this.text == this.nameText) {
            this.textError = '';
          } else {
            this.textError = '用户名输入错误';
            this.text = '';
            // 调用keepEditableState方法，输入框保持编辑态
            event.keepEditableState();
          }
        })
      // 设置下划线颜色
      TextInput({ placeholder: '提示文本内容' })
        .width(350)
        .showUnderline(true)
        .underlineColor({
          normal: Color.Orange,
          typing: Color.Green,
          error: Color.Red,
          disable: Color.Gray
        })
      TextInput({ placeholder: '提示文本内容' })
        .width(350)
        .showUnderline(true)
        .underlineColor(Color.Gray);

    }.width('100%').margin({ top: 10 })
  }
}
```

![TextInputError](figures/TextInputUnderline.png)

### 示例3（设置自定义键盘）

该示例通过[customKeyboard](#customkeyboard10)（从API version 10开始）属性分别将value中的入参类型设置为[CustomBuilder](ts-types.md#custombuilder8)和[ComponentContent](../js-apis-arkui-ComponentContent.md#componentcontent-1)，实现了自定义键盘的功能。

从API version 22开始[customKeyboard](#customkeyboard10)属性新增了入参类型[ComponentContent](../js-apis-arkui-ComponentContent.md#componentcontent-1)。

```ts
// xxx.ets
import { ComponentContent } from '@kit.ArkUI';
class BuilderParams {
  inputValue: string;
  controller: TextInputController;

  constructor(inputValue: string, controller: TextInputController) {
    this.inputValue = inputValue;
    this.controller = controller;
  }
}
@Builder
function CustomKeyboardBuilder(builderParams: BuilderParams) {
  Column() {
    Row() {
      Button('x').onClick(() => {
        // 关闭自定义键盘
        builderParams.controller.stopEditing();
      }).margin(10)
    }

    Grid() {
      ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {
        GridItem() {
          Button(item + '')
            .width(110).onClick(() => {
            builderParams.inputValue += item;
          })
        }
      })
    }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
  }.backgroundColor(Color.Gray)
}
@Entry
@Component
struct TextInputExample {
  controller: TextInputController = new TextInputController();
  @State inputValue: string = '';
  @State componentContent?: ComponentContent<BuilderParams> = undefined;
  @State builderParam: BuilderParams = new BuilderParams(this.inputValue, this.controller);
  @State supportAvoidance: boolean = true;

  aboutToAppear(): void {
    // 创建ComponentContent
    this.componentContent = new ComponentContent(this.getUIContext(), wrapBuilder(CustomKeyboardBuilder), this.builderParam);
  }
  build(){
    Column() {
      Text('Builder').margin(10).border({ width: 1 })
      TextInput({ controller: this.builderParam.controller, text: this.builderParam.inputValue })
        .customKeyboard(this.componentContent, { supportAvoidance: this.supportAvoidance })
        .margin(10).border({ width: 1 }).height('48vp')

      Text('ComponentContent').margin(10).border({ width: 1 })
      TextInput({ controller: this.builderParam.controller, text: this.builderParam.inputValue })
        .customKeyboard(new ComponentContent(this.getUIContext(), wrapBuilder(CustomKeyboardBuilder), this.builderParam), { supportAvoidance: this.supportAvoidance })
        .margin(10).border({ width: 1 }).height('48vp')
    }
  }
}
```

![customKeyboard](figures/textInputCustomKeyboard1.gif)

### 示例4（设置右侧清除按钮样式）

该示例通过[cancelButton](#cancelbutton11)属性展示了自定义右侧清除按钮样式的效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ placeholder: 'input ...', controller: this.controller })
        .width(380)
        .height(60)
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: {
            size: 45,
            // $r('app.media.startIcon')需要替换为开发者所需的图像资源文件。
            src: $r('app.media.startIcon'),
            color: Color.Blue
          }
        })
        .onChange((value: string) => {
          this.text = value;
        })
    }
  }
}
```

![cancelButton](figures/TextInputCancelButton.png)

### 示例5（设置计数器）

该示例通过[maxLength](#maxlength)、[showCounter](#showcounter11)（从API version 11开始）、[showUnderline](#showunderline10)（从API version 10开始）属性实现了计数器的功能。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ text: this.text, controller: this.controller })
        .placeholderFont({ size: 16, weight: 400 })
        .width(336)
        .height(56)
        .maxLength(6)
        .showUnderline(true)
        .showCounter(true,
          { thresholdPercentage: 50, highlightBorder: true })
          // 计数器显示效果为用户当前输入字符数/最大字符限制数。最大字符限制数通过maxLength()接口设置。
          // 如果用户当前输入字符数达到最大字符限制乘50%（thresholdPercentage）。字符计数器显示。
          // 用户设置highlightBorder为false时，配置取消红色边框。不设置此参数时，默认为true。
        .onChange((value: string) => {
          this.text = value;
        })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![TextInputCounter](figures/TextInputShowCounter.jpg)


### 示例6（电话号码格式化）

该示例通过[onChange](#onchange)回调实现了电话号码格式化为XXX XXXX XXXX的功能。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  public readonly NUM_TEXT_MAXSIZE_LENGTH = 13;
  @State telNumberNoSpace: string = '';
  @State nextCaret: number = -1; // 用于记录下次光标设置的位置
  @State actualCh: number = -1; // 用于记录光标在第i个数字后插入或者第i个数字前删除
  @State lastCaretPosition: number = 0;
  @State lastCaretPositionEnd: number = 0;
  controller: TextInputController = new TextInputController();

  isEmpty(str?: string): boolean {
    return str == 'undefined' || !str || !new RegExp('[^\\s]').test(str);
  }

  checkNeedNumberSpace(numText: string) {
    let isSpace: RegExp = new RegExp('[\\+;,#\\*]', 'g');
    let isRule: RegExp = new RegExp('^\\+.*');

    if (isSpace.test(numText)) {
      // 如果电话号码里有特殊字符，就不加空格
      if (isRule.test(numText)) {
        return true;
      } else {
        return false;
      }
    }
    return true;
  }

  removeSpace(str: string): string {
    if (this.isEmpty(str)) {
      return '';
    }
    return str.replace(new RegExp('[\\s]', 'g'), '');
  }

  setCaret() {
    if (this.nextCaret != -1) {
      console.info('to keep caret position right, change caret to', this.nextCaret);
      this.controller.caretPosition(this.nextCaret);
      this.nextCaret = -1;
    }
  }

  calcCaretPosition(nextText: string) {
    let befNumberNoSpace: string = this.removeSpace(this.text);
    this.actualCh = 0;
    if (befNumberNoSpace.length < this.telNumberNoSpace.length) { // 插入场景
      for (let i = 0; i < this.lastCaretPosition; i++) {
        if (this.text[i] != ' ') {
          this.actualCh += 1;
        }
      }
      this.actualCh += this.telNumberNoSpace.length - befNumberNoSpace.length;
      console.info('actualCh: ' + this.actualCh);
      for (let i = 0; i < nextText.length; i++) {
        if (nextText[i] != ' ') {
          this.actualCh -= 1;
          if (this.actualCh <= 0) {
            this.nextCaret = i + 1;
            break;
          }
        }
      }
    } else if (befNumberNoSpace.length > this.telNumberNoSpace.length) { // 删除场景
      if (this.lastCaretPosition === this.text.length) {
        console.info('Caret at last, no need to change');
      } else if (this.lastCaretPosition === this.lastCaretPositionEnd) {
        // 按键盘上回退键一个一个删的情况
        for (let i = this.lastCaretPosition; i < this.text.length; i++) {
          if (this.text[i] != ' ') {
            this.actualCh += 1;
          }
        }
        for (let i = nextText.length - 1; i >= 0; i--) {
          if (nextText[i] != ' ') {
            this.actualCh -= 1;
            if (this.actualCh <= 0) {
              this.nextCaret = i;
              break;
            }
          }
        }
      } else {
        // 剪切/手柄选择 一次删多个字符
        this.nextCaret = this.lastCaretPosition; // 保持光标位置
      }
    }
  }

  build() {
    Column() {
      Row() {
        TextInput({ text: `${this.text}`, controller: this.controller }).type(InputType.PhoneNumber).height('48vp')
          .onChange((value: string) => {
            this.telNumberNoSpace = this.removeSpace(value);
            let nextText: string = '';
            // 根据电话号码长度决定格式化方式：长度超限则不格式化，否则按'XXX XXXX XXXX'格式插入空格
            if (this.telNumberNoSpace.length > this.NUM_TEXT_MAXSIZE_LENGTH - 2) {
              nextText = this.telNumberNoSpace;
            } else if (this.checkNeedNumberSpace(value)) {
              if (this.telNumberNoSpace.length <= 3) {
                nextText = this.telNumberNoSpace;
              } else {
                let firstPart: string = this.telNumberNoSpace.substring(0, 3);
                let secondPart: string = this.telNumberNoSpace.substring(3);
                nextText = firstPart + ' ' + secondPart;
                if (this.telNumberNoSpace.length > 7) {
                  secondPart = this.telNumberNoSpace.substring(3, 7);
                  let thirdPart: string = this.telNumberNoSpace.substring(7);
                  nextText = firstPart + ' ' + secondPart + ' ' + thirdPart;
                }
              }
            } else {
              nextText = value;
            }
            console.info('onChange Triggered:' + this.text + '|' + nextText + '|' + value);
            if (this.text === nextText && nextText === value) {
              // 此时说明数字已经格式化完成了 在这个时候改变光标位置不会被重置掉
              this.setCaret();
            } else {
              this.calcCaretPosition(nextText);
            }
            this.text = nextText;
          })
          .onTextSelectionChange((selectionStart, selectionEnd) => {
            // 记录光标位置
            console.info('selection change: ', selectionStart, selectionEnd);
            this.lastCaretPosition = selectionStart;
            this.lastCaretPositionEnd = selectionEnd;
          })// 从API version 10开始支持
      }
    }
    .width('100%')
    .height('100%')
  }
}
```
![phone_example](figures/phone_number.PNG)

### 示例7（设置文本断行规则）

从API version 12开始，该示例通过[wordBreak](#wordbreak12)属性实现了TextInput不同断行规则下的效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State textStrEn: string =
    'This is set wordBreak to WordBreak text Taumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu.';
  @State textStrZn: string =
    '多行文本输入框组件，当输入的文本内容超过组件宽度时会自动换行显示。\n高度未设置时，组件无默认高度，自适应内容高度。宽度未设置时，默认撑满最大宽度。';

  build() {
    Row() {
      Column() {
        Text('TextInput为inline模式，WordBreakType属性为NORMAL的样式：').fontSize(16).fontColor(0xCCCCCC)
        TextInput({
          text: this.textStrEn
        })
          .margin(10)
          .fontSize(16)
          .style(TextInputStyle.Inline)// Inline模式
          .wordBreak(WordBreak.NORMAL) // 非Inline模式该属性无效

        Text('TextInput为inline模式，英文文本，WordBreakType属性为BREAK_ALL的样式：').fontSize(16).fontColor(0xCCCCCC)
        TextInput({
          text: this.textStrEn
        })
          .margin(10)
          .fontSize(16)
          .style(TextInputStyle.Inline)
          .wordBreak(WordBreak.BREAK_ALL)

        Text('TextInput为inline模式，中文文本，WordBreakType属性为BREAK_ALL的样式：').fontSize(16).fontColor(0xCCCCCC)
        TextInput({
          text: this.textStrZn
        })
          .margin(10)
          .fontSize(16)
          .style(TextInputStyle.Inline)
          .wordBreak(WordBreak.BREAK_ALL)

        Text('TextInput为inline模式，WordBreakType属性为BREAK_WORD的样式：').fontSize(16).fontColor(0xCCCCCC)
        TextInput({
          text: this.textStrEn
        })
          .margin(10)
          .fontSize(16)
          .style(TextInputStyle.Inline)
          .wordBreak(WordBreak.BREAK_WORD)
      }.width('100%')
    }.height('100%').margin(10)
  }
}
```
![TextInputWordBreak](figures/TextInputWordBreak.png)

### 示例8（设置文本样式）

从API version 12开始，该示例通过[lineHeight](#lineheight12)、[letterSpacing](#letterspacing12)、[decoration](#decoration12)属性展示了不同样式的文本效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  build() {
    Row() {
      Column() {
        Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)
        TextInput({ text: 'lineHeight unset' })
          .border({ width: 1 }).padding(10).margin(5)
        TextInput({ text: 'lineHeight 15' })
          .border({ width: 1 }).padding(10).margin(5).lineHeight(15)
        TextInput({ text: 'lineHeight 30' })
          .border({ width: 1 }).padding(10).margin(5).lineHeight(30)

        Text('letterSpacing').fontSize(9).fontColor(0xCCCCCC)
        TextInput({ text: 'letterSpacing 0' })
          .border({ width: 1 }).padding(5).margin(5).letterSpacing(0)
        TextInput({ text: 'letterSpacing 3' })
          .border({ width: 1 }).padding(5).margin(5).letterSpacing(3)
        TextInput({ text: 'letterSpacing -1' })
          .border({ width: 1 }).padding(5).margin(5).letterSpacing(-1)

        Text('decoration').fontSize(9).fontColor(0xCCCCCC)
        TextInput({ text: 'LineThrough, Red' })
          .border({ width: 1 }).padding(5).margin(5)
          .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })
        TextInput({ text: 'Overline, Red, DASHED' })
          .border({ width: 1 }).padding(5).margin(5)
          .decoration({ type: TextDecorationType.Overline, color: Color.Red, style: TextDecorationStyle.DASHED })
        TextInput({ text: 'Underline, Red, WAVY' })
          .border({ width: 1 }).padding(5).margin(5)
          .decoration({ type: TextDecorationType.Underline, color: Color.Red, style: TextDecorationStyle.WAVY })
      }.height('90%')
    }
    .width('90%')
    .margin(10)
  }
}
```

![TextInputDecoration](figures/textinput_decoration.png)

### 示例9（设置文字特性效果）

从API version 12开始，该示例通过[fontFeature](#fontfeature12)属性实现了文本在不同文字特性下的展示效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text1: string = 'This is ss01 on : 0123456789';
  @State text2: string = 'This is ss01 off: 0123456789';

  build() {
    Column() {
      TextInput({ text: this.text1 })
        .fontSize(20)
        .margin({ top: 200 })
        .fontFeature('"ss01" on')
      TextInput({ text: this.text2 })
        .margin({ top: 10 })
        .fontSize(20)
        .fontFeature('"ss01" off')
    }
    .width('90%')
    .margin('5%')
  }
}
```

![fontFeature](figures/textInputFontFeature.png)

### 示例10（自定义键盘避让）

该示例通过[customKeyboard](#customkeyboard10)（从API version 10开始）属性配置[KeyboardOptions](ts-basic-components-richeditor.md#keyboardoptions12)（从API version 12开始）接口实现了自定义键盘避让的效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  controller: TextInputController = new TextInputController();
  @State inputValue: string = '';
  @State height1: string | number = '80%';
  @State supportAvoidance: boolean = true;

  // 自定义键盘组件
  @Builder
  CustomKeyboardBuilder() {
    Column() {
      Row() {
        Button('x').onClick(() => {
          // 关闭自定义键盘
          this.controller.stopEditing();
        }).margin(10)
      }

      Grid() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {
          GridItem() {
            Button(item + '')
              .width(110).onClick(() => {
              this.inputValue += item;
            })
          }
        })
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
    }.backgroundColor(Color.Gray)
  }

  build() {
    Column() {
      Row() {
        Button('20%')
          .fontSize(24)
          .onClick(() => {
            this.height1 = '20%';
          })
        Button('80%')
          .fontSize(24)
          .margin({ left: 20 })
          .onClick(() => {
            this.height1 = '80%';
          })
      }
      .justifyContent(FlexAlign.Center)
      .alignItems(VerticalAlign.Bottom)
      .height(this.height1)
      .width('100%')
      .padding({ bottom: 50 })

      TextInput({ controller: this.controller, text: this.inputValue })// 绑定自定义键盘
        .customKeyboard(this.CustomKeyboardBuilder(), { supportAvoidance: this.supportAvoidance })
        .margin(10)
        .border({ width: 1 })

    }
  }
}
```

![CustomTextInputType](figures/textInputCustomKeyboard.gif)

### 示例11（设置文本自适应）

从API version 12开始，该示例通过[minFontSize](#minfontsize12)、[maxFontSize](#maxfontsize12)、[heightAdaptivePolicy](#heightadaptivepolicy12)属性实现了文本自适应字号的功能。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  build() {
    Row() {
      Column() {
        Text('heightAdaptivePolicy').fontSize(9).fontColor(0xCCCCCC)
        TextInput({ text: 'This is the text without the height adaptive policy set' })
          .width('80%').height(50).borderWidth(1).margin(1)
        TextInput({ text: 'This is the text with the height adaptive policy set' })
          .width('80%')
          .height(50)
          .borderWidth(1)
          .margin(1)
          .minFontSize(4)
          .maxFontSize(40)
          .maxLines(3)
          .heightAdaptivePolicy(TextHeightAdaptivePolicy.MAX_LINES_FIRST)
        TextInput({ text: 'This is the text with the height adaptive policy set' })
          .width('80%')
          .height(50)
          .borderWidth(1)
          .margin(1)
          .minFontSize(4)
          .maxFontSize(40)
          .maxLines(3)
          .heightAdaptivePolicy(TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST)
        TextInput({ text: 'This is the text with the height adaptive policy set' })
          .width('80%')
          .height(50)
          .borderWidth(1)
          .margin(1)
          .minFontSize(4)
          .maxFontSize(40)
          .maxLines(3)
          .heightAdaptivePolicy(TextHeightAdaptivePolicy.LAYOUT_CONSTRAINT_FIRST)
      }.height('90%')
    }
    .width('90%')
    .margin(10)
  }
}
```

![TextInputAdaptFont](figures/textinput_adapt_font.png)

### 示例12（设置折行规则）

从API version 12开始，该示例通过[lineBreakStrategy](#linebreakstrategy12)属性实现了TextInput不同折行规则下的效果。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State message1: string =
    'They can be classified as built-in components–those directly provided by the ArkUI framework and custom components – those defined by developers' +
      'The built-in components include buttons radio progress indicators and text You can set the rendering effect of these components in method chaining mode,' +
      'page components are divided into independent UI units to implementindependent creation development and reuse of different units on pages making pages more engineering-oriented.';
  @State lineBreakStrategyIndex: number = 0;
  @State lineBreakStrategy: LineBreakStrategy[] =
    [LineBreakStrategy.GREEDY, LineBreakStrategy.HIGH_QUALITY, LineBreakStrategy.BALANCED];
  @State lineBreakStrategyStr: string[] = ['GREEDY', 'HIGH_QUALITY', 'BALANCED'];

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center }) {
      Text('lineBreakStrategy').fontSize(16).fontColor(Color.Black)
      TextInput({ text: this.message1 })
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('100%')
        .maxLines(12)
        .style(TextInputStyle.Inline)
        .lineBreakStrategy(this.lineBreakStrategy[this.lineBreakStrategyIndex])
      Row() {
        Button('当前lineBreakStrategy模式：' + this.lineBreakStrategyStr[this.lineBreakStrategyIndex]).onClick(() => {
          this.lineBreakStrategyIndex++;
          if (this.lineBreakStrategyIndex > (this.lineBreakStrategyStr.length - 1)) {
            this.lineBreakStrategyIndex = 0;
          }
        })
      }.margin({ top: 20 })
    }.height(700).width(370).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![textInputLineBreakStrategy](figures/textInputLineBreakStrategy.gif)

### 示例13（支持插入和删除回调）
从API version 12开始，该示例通过[onWillInsert](#onwillinsert12)、[onDidInsert](#ondidinsert12)、[onWillDelete](#onwilldelete12)、[onDidDelete](#ondiddelete12)接口实现了插入和删除的效果。
```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State insertValue: string = '';
  @State deleteValue: string = '';
  @State insertOffset: number = 0;
  @State deleteOffset: number = 0;
  @State deleteDirection: number = 0;
  @State currentValue_1: string = '';
  @State currentValue_2: string = '';

  build() {
    Row() {
      Column() {
        TextInput({ text: 'TextInput支持插入回调文本' })
          .height(60)
          .onWillInsert((info: InsertValue) => {
            this.insertValue = info.insertValue;
            return true;
          })
          .onDidInsert((info: InsertValue) => {
            this.insertOffset = info.insertOffset;
          })
          .onWillChange((info: EditableTextChangeValue) => {
            this.currentValue_1 = info.content;
            return true;
          })

        Text('insertValue:' + this.insertValue + '  insertOffset:' + this.insertOffset).height(30)
        Text('currentValue_1:' + this.currentValue_1).height(30)

        TextInput({ text: 'TextInput支持删除回调文本b' })
          .height(60)
          .onWillDelete((info: DeleteValue) => {
            this.deleteValue = info.deleteValue;
            this.deleteDirection = info.direction;
            return true;
          })
          .onDidDelete((info: DeleteValue) => {
            this.deleteOffset = info.deleteOffset;
            this.deleteDirection = info.direction;
          })
          .onWillChange((info: EditableTextChangeValue) => {
            this.currentValue_2 = info.content;
            return true;
          })

        Text('deleteValue:' + this.deleteValue + '  deleteOffset:' + this.deleteOffset).height(30)
        Text('deleteDirection:' + (this.deleteDirection == 0 ? 'BACKWARD' : 'FORWARD')).height(30)
        Text('currentValue_2:' + this.currentValue_2).height(30)

      }.width('100%')
    }
    .height('100%')
  }
}
```

![TextInputInsertAndDelete](figures/TextInputInsertAndDelete.PNG)

### 示例14（文本扩展自定义菜单）

从API version 12开始，该示例通过[editMenuOptions](#editmenuoptions12)接口实现了文本设置自定义菜单扩展项的文本内容、图标以及回调的功能，同时，可以在[onPrepareMenu](ts-text-common.md#属性-1)（从API version 20开始）回调中，进行菜单数据的设置。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = 'TextInput editMenuOptions';
  @State endIndex: number = 0;
  onCreateMenu = (menuItems: Array<TextMenuItem>) => {
    // $r('app.media.startIcon')需要替换为开发者所需的图像资源文件。
    // 从API version 23开始支持TextMenuItemId.autoFill
    const idsToFilter: TextMenuItemId[] = [
      TextMenuItemId.autoFill
    ]
    const items = menuItems.filter(item => !idsToFilter.some(id => id.equals(item.id)))
    let item1: TextMenuItem = {
      content: 'create1',
      icon: $r('app.media.startIcon'),
      id: TextMenuItemId.of('create1'),
    };
    let item2: TextMenuItem = {
      content: 'create2',
      id: TextMenuItemId.of('create2'),
      icon: $r('app.media.startIcon'),
    };
    items.push(item1);
    items.unshift(item2);
    return items;
  }
  onMenuItemClick = (menuItem: TextMenuItem, textRange: TextRange) => {
    if (menuItem.id.equals(TextMenuItemId.of('create2'))) {
      console.info('拦截 id: create2 start:' + textRange.start + '; end:' + textRange.end);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.of('prepare1'))) {
      console.info('拦截 id: prepare1 start:' + textRange.start + '; end:' + textRange.end);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.COPY)) {
      console.info('拦截 COPY start:' + textRange.start + '; end:' + textRange.end);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.SELECT_ALL)) {
      console.info('不拦截 SELECT_ALL start:' + textRange.start + '; end:' + textRange.end);
      return false;
    }
    return false;
  }
  // $r('app.media.startIcon')需要替换为开发者所需的图像资源文件。
  onPrepareMenu = (menuItems: Array<TextMenuItem>) => {
    let item1: TextMenuItem = {
      content: 'prepare1_' + this.endIndex,
      icon: $r('app.media.startIcon'),
      id: TextMenuItemId.of('prepare1'),
    };
    menuItems.unshift(item1);
    return menuItems;
  }
  @State editMenuOptions: EditMenuOptions = {
    onCreateMenu: this.onCreateMenu,
    onMenuItemClick: this.onMenuItemClick,
    onPrepareMenu: this.onPrepareMenu
  };

  build() {
    Column() {
      TextInput({ text: this.text })
        .width('95%')
        .height(50)
        .editMenuOptions(this.editMenuOptions)
        .margin({ top: 100 })
        .onTextSelectionChange((selectionStart: number, selectionEnd: number) => {
          this.endIndex = selectionEnd;
        })
    }
    .width('90%')
    .margin('5%')
  }
}
```

<!--RP4-->
![textInputEditMenuOptions](figures/textInputEditMenuOptions.png)
<!--RP4End-->

### 示例15（设置symbol类型清除按钮）

从API version 18开始，该示例通过[cancelButton](#cancelbutton18)属性展示了自定义右侧symbol类型清除按钮样式的效果。

```ts
import { SymbolGlyphModifier } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  symbolModifier: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.trash')).fontColor([Color.Red]).fontSize(16).fontWeight(FontWeight.Regular);

  build() {
    Column() {
      TextInput({ text: this.text, placeholder: 'input your word...' })
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: this.symbolModifier
        })
    }
  }
}
```

![cancelButton](figures/TextInputCancelButton_SymbolGlyphModifier.jpg)

### 示例16（文本设置省略模式）

该示例通过[textOverflow](#textoverflow12)、[ellipsisMode](#ellipsismode18)、[style](#style9)属性展示了文本超长省略以及调整省略位置的效果，通过MULTILINE_START和MULTILINE_CENTER两种类型实现了单行文本和多行文本场景下的省略号在行首和行中的效果。

从API version 9开始，通过[style](#style9)设置输入框的风格。

从API version 12开始，通过[textOverflow](#textoverflow12)设置文本超长时的显示方式。

从API version 18开始，通过[ellipsisMode](#ellipsismode18)设置省略号位置。

从API version 24开始，[EllipsisMode](ts-appendix-enums.md#ellipsismode11)新增了MULTILINE_START和MULTILINE_CENTER枚举。

```ts
// xxx.ets
@Entry
@Component
struct EllipsisModeExample {
  @State text: string = 'As the sun begins to set, casting a warm golden hue across the sky,' +
    'the world seems to slow down and breathe a sigh of relief. The sky is painted with hues of orange, ' +
    ' pink, and lavender, creating a breath taking tapestry that stretches as far as the eye can see.' +
    'The air is filled with the sweet scent of blooming flowers, mingling with the earthy aroma of freshly turned soil.';
  @State ellipsisModeIndex: number = 0;
  @State ellipsisMode: (EllipsisMode | undefined | null)[] =
    [EllipsisMode.END, EllipsisMode.START, EllipsisMode.CENTER, EllipsisMode.MULTILINE_START,
      EllipsisMode.MULTILINE_CENTER]; // 从API version 24开始新增MULTILINE_START和MULTILINE_CENTER
  @State ellipsisModeStr: string[] = ['END ', 'START', 'CENTER', 'MULTILINE_START', 'MULTILINE_CENTER'];
  @State textOverflowIndex: number = 0;
  @State textOverflow: TextOverflow[] = [TextOverflow.Ellipsis, TextOverflow.Clip];
  @State textOverflowStr: string[] = ['Ellipsis', 'Clip'];
  @State styleInputIndex: number = 0;
  @State styleInput: TextInputStyle[] = [TextInputStyle.Inline, TextInputStyle.Default];
  @State styleInputStr: string[] = ['Inline', 'Default'];

  build() {
    Row() {
      Column({ space: 20 }) {
        TextInput({ text: this.text })
          .textOverflow(this.textOverflow[this.textOverflowIndex])
          .ellipsisMode(this.ellipsisMode[this.ellipsisModeIndex])
          .style(this.styleInput[this.styleInputIndex])
          .fontSize(30)
          .margin(30)
        Button('更改ellipsisMode模式：' + this.ellipsisModeStr[this.ellipsisModeIndex]).onClick(() => {
          this.ellipsisModeIndex++;
          if (this.ellipsisModeIndex > (this.ellipsisModeStr.length - 1)) {
            this.ellipsisModeIndex = 0;
          }
        }).fontSize(20)
        Button('更改textOverflow模式：' + this.textOverflowStr[this.textOverflowIndex]).onClick(() => {
          this.textOverflowIndex++;
          if (this.textOverflowIndex > (this.textOverflowStr.length - 1)) {
            this.textOverflowIndex = 0;
          }
        }).fontSize(20)
        Button('更改Style大小：' + this.styleInputStr[this.styleInputIndex]).onClick(() => {
          this.styleInputIndex++;
          if (this.styleInputIndex > (this.styleInputStr.length - 1)) {
            this.styleInputIndex = 0;
          }
        }).fontSize(20)
      }
    }
  }
}
```

![textInputEllipsisMode](figures/textInputEllipsisMode.gif)

### 示例17（输入框支持输入状态变化等回调）

从API version 8开始，该示例通过[onEditChange](#oneditchange8)、[onCopy](#oncopy8)、[onCut](#oncut8)、[onPaste](#onpaste8)、[onContentScroll](#oncontentscroll10)（从API version 10开始）、[onWillCopy](#onwillcopy)、[onWillCut](#onwillcut)接口实现了输入框监测输入状态变化、复制、剪切、粘贴、文本内容滚动回调的效果、如何屏蔽系统复制功能，以及如何屏蔽系统剪切功能，同时，可以通过设置[selectAll](#selectall11)（从API version 11开始）属性，输入框初始状态下是否全选文本。

从API版本26.0.0开始，新增[onWillCopy](#onwillcopy)、[onWillCut](#onwillcut)接口。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State editStatus: boolean = false;
  @State copyValue: string = '';
  @State cutValue: string = '';
  @State pasteValue: string = '';
  @State totalOffsetX: number = 0;
  @State totalOffsetY: number = 0;

  build() {
    Row() {
      Column() {
        TextInput({ text: 'TextInput支持输入状态变化时回调' })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('HarmonyOS Sans')
          .copyOption(CopyOptions.LocalDevice)
          .textAlign(TextAlign.Center)
          .selectedBackgroundColor(Color.Blue)
          .caretStyle({ width: '4vp' })
          .caretPosition(10)
          .selectionMenuHidden(true)
          .onEditChange((status: boolean) => {
            this.editStatus = status;
          })
          .defaultFocus(true)// 设置TextInput默认获焦
          .enableKeyboardOnFocus(false)
          .selectAll(false)

        Text('editStatus:' + this.editStatus).height(30)

        TextInput({ text: 'TextInput支持复制操作时回调' })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('HarmonyOS Sans')
          .copyOption(CopyOptions.LocalDevice)
          .textAlign(TextAlign.Center)
          .selectedBackgroundColor(Color.Blue)
          .caretStyle({ width: '4vp' })
          .onCopy((copyValue: string) => {
            this.copyValue = copyValue;
          })
          // 从API版本26.0.0开始支持onWillCopy
          .onWillCopy((value: string) => {
            console.info(`on will copy ${value}`);
            return false;
          })

        Text('copyValue:' + this.copyValue).height(30)

        TextInput({ text: 'TextInput支持剪切操作时回调' })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('HarmonyOS Sans')
          .copyOption(CopyOptions.LocalDevice)
          .textAlign(TextAlign.Center)
          .selectedBackgroundColor(Color.Blue)
          .caretStyle({ width: '4vp' })
          .onCut((cutValue: string) => {
            this.cutValue = cutValue;
          })
          // 从API版本26.0.0开始支持onWillCut
          .onWillCut((value: string) => {
            console.info(`on will cut ${value}`);
            return false;
          })

        Text('cutValue:' + this.cutValue).height(30)

        TextInput({ text: 'TextInput支持粘贴操作时回调' })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('HarmonyOS Sans')
          .copyOption(CopyOptions.LocalDevice)
          .textAlign(TextAlign.Center)
          .selectedBackgroundColor(Color.Blue)
          .caretStyle({ width: '4vp' })
          .onPaste((pasteValue: string) => {
            this.pasteValue = pasteValue;
          })

        Text('pasteValue:' + this.pasteValue).height(30)

        TextInput({ text: 'TextInput支持文本内容滚动时回调: 文本内容宽度超出输入框宽度，滚动文本查看偏移量变化' })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .fontFamily('HarmonyOS Sans')
          .copyOption(CopyOptions.LocalDevice)
          .textAlign(TextAlign.Center)
          .selectedBackgroundColor(Color.Blue)
          .caretStyle({ width: '4vp' })
          .onContentScroll((totalOffsetX: number, totalOffsetY: number) => {
            this.totalOffsetX = totalOffsetX;
            this.totalOffsetY = totalOffsetY;
          })

        Text('totalOffsetX:' + this.totalOffsetX + '  totalOffsetY:' + this.totalOffsetY).height(30)

      }.width('100%')
    }
    .height('100%')
  }
}
```

![TextInputEditChange](figures/TextInputEditChange.png)

### 示例18（设置最小字体范围与最大字体范围）

从API version 18开始，该示例通过[minFontScale](#minfontscale18)、[maxFontScale](#maxfontscale18)设置字体显示最小与最大范围<!--Del-->（该示例使用系统接口，应用类型需调整为系统应用，可参考HarmonyAppProvision的[系统接口说明](../../../reference/development-intro-api.md#系统接口说明)）<!--DelEnd-->。
<!--code_no_check-->
```json5
// 开启应用缩放跟随系统
// AppScope/resources/base，新建文件夹profile。
// AppScope/resources/base/profile，新建文件configuration.json。
// AppScope/resources/base/profile/configuration.json，增加如下代码。
{
  "configuration": {
    "fontSizeScale": "followSystem",
    "fontSizeMaxScale": "3.2"
  }
}
```
<!--code_no_check-->
```json5
// AppScope/app.json5，修改如下代码。
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name",
    "configuration": "$profile:configuration"
  }
}
```
<!--RP3-->
<!--code_no_check-->
```ts
// xxx.ets
import { abilityManager, Configuration } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct TextInputExample {
  @State currentFontSizeScale: number = 1;
  @State minFontScale: number = 0.85;
  @State maxFontScale: number = 2;

  // 设置字体大小
  async setFontScale(scale: number): Promise<void> {
    let configInit: Configuration = {
      language: 'zh-Ch',
      fontSizeScale: scale,
    };
    // 更新配置-字体大小，调用系统接口更新字体配置
    // 需在工程的module.json5文件的requestPermissions字段配置权限：ohos.permission.UPDATE_CONFIGURATION
    abilityManager.updateConfiguration(configInit, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to update configuration. Code: ${err.code}, message: ${err.message}`);
      } else {
        this.currentFontSizeScale = scale;
        console.info('updateConfiguration success.');
      }
    });
  }

  build() {
    Column() {
      Column({ space: 30 }) {
        Text('通过minFontScale、maxFontScale调整文本显示的最大和最小字体缩放倍数。')
        TextInput({
          placeholder: 'The text area can hold an unlimited amount of text. input your word...',
          text: '通过minFontScale、maxFontScale调整文本显示的最大和最小字体缩放倍数。'
        })
          .minFontScale(this.minFontScale)// 设置最小字体缩放倍数，参数为undefined则跟随系统默认倍数缩放
          .maxFontScale(this.maxFontScale) // 设置最大字体缩放倍数，参数为undefined则跟随系统默认倍数缩放
      }.width('100%')

      Column() {
        Row() {
          Button('1倍').onClick(() => {
            this.setFontScale(1);
          }).margin(10)
          Button('1.75倍').onClick(() => {
            this.setFontScale(1.75);
          }).margin(10)
        }

        Row() {
          Button('2倍').onClick(() => {
            this.setFontScale(2);
          }).margin(10)
          Button('3.2倍').onClick(() => {
            this.setFontScale(3.2);
          }).margin(10)
        }
      }.margin({ top: 50 })
    }
  }
}
```
<!--RP3End-->

| 系统字体缩放倍数为2倍 | 系统字体缩放倍数为3.2倍 |
| ---------------------------------- | ------------------------------------ |
| ![](figures/TextInput_font_scale1.png)  | ![](figures/TextInput_font_scale2.png)  |

### 示例19（设置选中指定区域的文本内容）

从API version 10开始，该示例通过[setTextSelection](#settextselection10)方法展示如何设置选中指定区域的文本内容以及菜单的显隐策略。

```ts
// xxx.ets

@Entry
@Component
struct TextInputExample {
  controller: TextInputController = new TextInputController();
  @State startIndex: number = 0;
  @State endIndex: number = 0;

  build() {
    Column({ space: 3 }) {
      Text('Selection start:' + this.startIndex + ' end:' + this.endIndex)
      TextInput({ text: 'Hello World', controller: this.controller })
        .width('95%')
        .height(40)
        .defaultFocus(true)
        .enableKeyboardOnFocus(true)
        .onTextSelectionChange((selectionStart: number, selectionEnd: number) => {
          this.startIndex = selectionStart;
          this.endIndex = selectionEnd;
        })

      Button('setTextSelection [0,3], set menuPolicy is MenuPolicy.SHOW')
        .onClick(() => {
          this.controller.setTextSelection(0, 3, { menuPolicy: MenuPolicy.SHOW });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![textInputSetTextSelection](figures/textInputSetTextSelection.png)

### 示例20（设置文本描边）

从API version 20开始，该示例通过[strokeWidth](#strokewidth20)和[strokeColor](#strokecolor20)属性设置文本的描边宽度及颜色。

从API版本26.0.0开始，新增[strokeJoinStyle](#strokejoinstyle)接口，支持设置文本描边拐角样式。

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct TextInputExample {
  build() {
    Row() {
      Column() {
        Text('stroke feature').fontSize(9).fontColor(0xCCCCCC)

        TextInput({ text: 'Text without stroke' })
          .width('100%')
          .height(60)
          .borderWidth(1)
          .fontSize(40)
        TextInput({ text: 'Text with stroke' })
          .width('100%')
          .height(60)
          .borderWidth(1)
          .fontSize(40)
          .strokeWidth(LengthMetrics.px(-3.0))
          .strokeColor(Color.Red)
        TextInput({ text: 'Text with stroke' })
          .width('100%')
          .height(60)
          .borderWidth(1)
          .fontSize(40)
          .strokeWidth(LengthMetrics.px(3.0))
          .strokeJoinStyle(StrokeJoinStyle.MITER_JOIN)
          .strokeColor(Color.Red)
      }.height('90%')
    }
    .width('90%')
    .margin(10)
  }
}
```

![textInputSetStroke](figures/textInputSetStroke.png)

### 示例21（设置中西文自动间距）

从API version 20开始，该示例通过[enableAutoSpacing](#enableautospacing20)属性设置中西文自动间距。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  build() {
    Row() {
      Column() {
        Text('开启中西文自动间距').margin(5)
        TextInput({text: '中西文Auto Spacing自动间距'})
          .enableAutoSpacing(true)
        Text('关闭中西文自动间距').margin(5)
        TextInput({text: '中西文Auto Spacing自动间距'})
          .enableAutoSpacing(false)
      }.height('100%')
    }
    .width('60%')
  }
}
```

![textInputEnableAutoSpacing](figures/textInputEnableAutoSpacing.png)

### 示例22（设置字符计数颜色以及超出字符颜色）

从API version 22开始，该示例通过[showCounter](#showcounter11)属性的counterTextColor和counterTextOverflowColor设置字符计数颜色以及超出字符颜色。

```ts
import { ColorMetrics } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '';
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ text: this.text, controller: this.controller })
        .placeholderFont({ size: 16, weight: 400 })
        .width(336)
        .height(56)
        .maxLength(6)
        .showCounter(true, {
          thresholdPercentage: 50,
          highlightBorder: true,
          counterTextColor: ColorMetrics.resourceColor(Color.Red),
          counterTextOverflowColor: ColorMetrics.resourceColor(Color.Orange)
        })
        .onChange((value: string) => {
          this.text = value;
        })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![TextInputShowCounterColor](figures/TextInputShowCounterColor.gif)

### 示例23（设置placeholder富文本样式）

从API version 22开始，该示例通过[setStyledPlaceholder](ts-universal-attributes-text-style.md#setstyledplaceholder22)接口设置placeholder富文本样式。
```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI';
@Entry
@Component
struct TextInputExample  {
  styledString: MutableStyledString =
    new MutableStyledString('输入框富文本：文本',
      [
        {
          start: 0,
          length: 7,
          styledKey: StyledStringKey.FONT,
          styledValue: new TextStyle({
            fontColor: Color.Orange,
            fontSize: LengthMetrics.fp(24)
          })
        },
        {
          start: 7,
          length: 4,
          styledKey: StyledStringKey.FONT,
          styledValue: new TextStyle({
            fontColor: Color.Gray,
            fontSize: LengthMetrics.fp(20),
            strokeWidth: LengthMetrics.px(-5),
            strokeColor: Color.Black,
          })
        },
        {
          start: 0,
          length: 1,
          styledKey: StyledStringKey.PARAGRAPH_STYLE,
          styledValue: new ParagraphStyle({
            textVerticalAlign: TextVerticalAlign.CENTER
          })
        }
      ]);
  controllerInput: TextInputController = new TextInputController();

  aboutToAppear() {
    this.controllerInput.setStyledPlaceholder(this.styledString)
  }

  build() {
    Scroll() {
      Column() {
        Text('TextInput placeholder富文本')
          .fontSize(8)
        TextInput({
          controller: this.controllerInput
        })
          .fontSize(24)
          .margin(10)
      }
      .width('100%')
    }
  }
}
```
![textInputPlaceholder](figures/textInputPlaceholder.jpg)

### 示例24（设置输入法扩展信息）

从API version 22开始，该示例通过[IMEClient](ts-text-common.md#imeclient20对象说明)的setExtraConfig设置输入法扩展信息。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  build() {
    Column() {
      TextInput({ text: '拉起输入法前执行onWillAttachIME回调' })
        .onWillAttachIME((client: IMEClient) => {
          // 设置输入法扩展信息，包括自定义属性和节点ID
          client.setExtraConfig({
            customSettings: {
              name: 'TextInput', // 自定义属性
              id: client.nodeId // 自定义属性
            }
          })
        })
    }.height('100%')
  }
}
```

### 示例25（设置内联输入风格编辑态时滚动条的显示模式）

从API version 10开始，该示例通过[barState](#barstate10)接口设置内联输入风格编辑态时滚动条的显示或隐藏状态。

```ts
@Entry
@Component
struct TextInputBarStateDemo {
  @State message: string = '这里是一段长文本'.repeat(10)

  build() {
    Column({ space: 20 }) {
      TextInput({ text: '内联模式，设置BarState.On，' + this.message })
        .style(TextInputStyle.Inline)
        .barState(BarState.On)

      TextInput({ text: '内联模式，设置BarState.Off，' + this.message })
        .style(TextInputStyle.Inline)
        .barState(BarState.Off)
    }
    .width('100%')
    .height('100%')
    .padding(20)
    .justifyContent(FlexAlign.Center)
  }
}

```

![textInput_barState](figures/textInput_barState.gif)

### 示例26（设置行首标点符号压缩和行尾标点符号悬挂）

本示例通过[compressLeadingPunctuation](#compressleadingpunctuation23)接口设置行首标点符号压缩，通过[punctuationOverflow](#punctuationoverflow)设置行尾标点符号悬挂。

左侧有间距的标点符号位于行首时，标点会直接压缩间距至左侧边界。

文本自动换行后，剩余内容（含标点符号）需要能够放入上一行，标点符号悬挂才生效。

从API版本23开始，新增compressLeadingPunctuation接口。

从API版本26.0.0开始，新增punctuationOverflow接口。

```ts
@Entry
@Component
struct PunctuationDemo {
  @State compressLeadingPunctuation: boolean = false;
  @State punctuationOverflow: boolean = false;
  @State text: string = '「123456789！\n『123456789：';

  build() {
    Column() {
      TextInput({ text: this.text })
        .compressLeadingPunctuation(this.compressLeadingPunctuation)
        .punctuationOverflow(this.punctuationOverflow)
        .fontSize('20fp')
        .style(TextInputStyle.Inline)
        .align(Alignment.Center)
        .width('45%')

      Column() {
        Button('开启行首标点符号压缩').onClick(() => {
          this.compressLeadingPunctuation = true;
        }).margin(5)
        Button('关闭行首标点符号压缩').onClick(() => {
          this.compressLeadingPunctuation = false;
        }).margin(5)
        Button('开启行尾标点符号悬挂').onClick(() => {
          this.punctuationOverflow = true;
        }).margin(5)
        Button('关闭行尾标点符号悬挂').onClick(() => {
          this.punctuationOverflow = false;
        }).margin(5)
      }
    }.width('100%').padding(20)
  }
}
```
![textInputPunctuation](figures/textInputPunctuation.gif)

### 示例27（设置自适应间距）

该示例通过[includeFontPadding](#includefontpadding23)接口增加首行尾行间距和[fallbackLineSpacing](#fallbacklinespacing23)接口设置自适应行间距。

从API version 23开始，新增[includeFontPadding](#includefontpadding23)和[fallbackLineSpacing](#fallbacklinespacing23)接口。

```ts
// xxx.ets

const UYGHUR_TEXT: string = 'ياخشىمۇسەنياخشىمۇسەنياخشىمۇسەنياخشىمۇسەنياخشىمۇسەنياخشىمۇسەنياخشىمۇسەن';
@Entry
@Component
struct Index {
  @State include: boolean | null | undefined = false;
  @State fallback: boolean | null | undefined = false;
  @State displayText: string = UYGHUR_TEXT;

  build() {
    Column() {
      TextInput({
        text: this.displayText,
        placeholder: '请输入内容...'
      })
        .includeFontPadding(this.include)
        .fallbackLineSpacing(this.fallback)
        .lineHeight(5)
        .width('100%')
        .height(100)
        .backgroundColor('#eee')
        .borderWidth(1)
        .borderColor('#dddddd')

      Scroll() {
        Column() {
          // --- IncludeFontPadding相关按钮 ---
          Button('设置includePadding: ' + this.include)
            .onClick(() => {
              this.include = this.include === false ? true : false;
            })
            .margin({ bottom: 10 })

          // --- FallbackLineSpacing相关按钮 ---
          Button('设置fallbackLineSpacing: ' + this.fallback)
            .onClick(() => {
              this.fallback = this.fallback === false ? true : false;
            })
            .margin({ bottom: 10 })

        }
        .width('100%')
        .padding(5)
      }
      .height(250)
      .backgroundColor('transparent')
      .scrollBarWidth(2)
      .scrollBarColor('#888')

    }
    .width('100%')
    .height('100%')
    .padding(20)
  }
}
```

![textInputIncludeFontPadding](figures/TextInput_IncludeFontPadding.gif)

### 示例28（设置文本拖拽时的背板样式）

该示例通过[selectedDragPreviewStyle](#selecteddragpreviewstyle23)接口设置文本拖拽时的背板样式。

从API version 23开始，新增selectedDragPreviewStyle接口。

```ts
@Entry
@Component
struct TextInputTest {
  build() {
    Column() {
      TextInput({ text: 'HelloWorld', placeholder: 'please input words' })
        .copyOption(CopyOptions.InApp)
        .width(200)
        .height(50)
        .margin(150)
        .draggable(true)
        .selectedDragPreviewStyle({color: 'rgba(227, 248, 249, 1)'})
    }
    .height('100%')
  }
}
```

![selectedDragPreviewStyle](figures/textInputSelectedDragPreviewStyle.png)

### 示例29（删除文本框内的最后一个字符）

该示例通过调用[deleteBackward](ts-universal-attributes-text-style.md#deletebackward23)接口删除文本框内最后一个字符。

从API version 23开始，新增[deleteBackward](ts-universal-attributes-text-style.md#deletebackward23)接口。

``` typescript
@Entry
@Component
struct Page {
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ text: 'TextInput输入框Deletebackward示例', controller: this.controller })
      Button('Delete backward')
        .onClick(() => {
          // 删除文本框内最后一个字符
          this.controller.deleteBackward();
        })
    }
  }
}
```

![textInputDeleteBackward](figures/TextInput_DeleteBackward.gif)

### 示例30（设置文本排版方向）

该示例通过[textDirection](#textdirection23)接口设置文本排版方向。

从API version 23开始，新增textDirection接口。

``` ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = 'TextInput文本排版方向示例';

  build() {
    Column() {
      Text('TextInput文本排版方向RTL，布局方向default')
        .fontSize(12).width('90%').margin(5)
      TextInput({ text: this.text })
        .width(336)
        .fontSize(16)
        .textDirection(TextDirection.RTL)
        .showCounter(true)
        .maxLength(50)
      Text('TextInput文本排版方向RTL，布局方向default，文本水平方向对齐方式LEFT')
        .fontSize(12).width('90%').margin(5)
      TextInput({ text: this.text })
        .width(336)
        .fontSize(16)
        .textDirection(TextDirection.RTL)
        .showCounter(true)
        .maxLength(50)
        .textAlign(TextAlign.LEFT)
      Text('TextInput文本排版方向LTR，布局方向Rtl')
        .fontSize(12).width('90%').margin(5)
      TextInput({ text: this.text })
        .width(336)
        .fontSize(16)
        .textDirection(TextDirection.LTR)
        .direction(Direction.Rtl)
        .maxLength(50)
        .showCounter(true)
    }.width('100%').height('100%')
  }
}
```

![textTextInputDirection](figures/textTextInputDirection.PNG)

### 示例31（将指定范围的文字滚动到可视区内）

本示例通过[scrollToVisible](./ts-universal-attributes-text-style.md#scrolltovisible23)将可视区外的文本滚动到可视区内。

从API version 23开始，新增scrollToVisible接口。

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = '1234567891234567891234😁😁😁6789123456789123456789012121214521';
  controller: TextInputController = new TextInputController();

  build() {
    Column() {
      TextInput({ text: this.text, controller: this.controller })
        .width(336)
        .height(56)
      Button('滚动文本到可视区').onClick(()=> {
        // 将第22-30个字符滚动到可视区内
        this.controller.scrollToVisible({ start: 22, end: 30})
      })
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![textinputscrolltovisible](figures/textinput_scroll_to_visible.gif)

### 示例32（设置文本排版时是否使能孤字优化）

该示例通过[orphanCharOptimization](#orphancharoptimization)接口设置使能孤字优化，确保段落最后一行不出现孤字。

从API版本26.0.0开始，新增orphanCharOptimization接口。

``` ts
// xxx.ets
@Entry
@Component
struct TextExample {
  @State text: string = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa文本aaaaaaaaaaaaa';

  build() {
    Column({ space: 3 }) {
      Text('TextInput不使能孤字优化')
        .fontSize(12).width('90%').margin(5)
      TextInput({ text: this.text })
        .fontSize(20)
        .width('384')
        .borderWidth(1)
        .style(TextInputStyle.Inline)
      Text('TextInput使能孤字优化')
        .fontSize(12).width('90%').margin(5)
      TextInput({ text: this.text })
        .fontSize(20)
        .width('384')
        .borderWidth(1)
        .orphanCharOptimization(true)
        .style(TextInputStyle.Inline)
    }
    .width('100%')
    .height('100%')
  }
}
```

该效果图会因设备尺寸差异有显示区别，仅供参考。

不开启孤字优化：

![textInputOrphanCharOptimization1](figures/textInputOrphanCharOptimization1.png)

开启孤字优化：

![textInputOrphanCharOptimization2](figures/textInputOrphanCharOptimization2.png)

### 示例33（设置文本着色器效果）

该示例通过[shaderStyle](#shaderstyle)接口实现对TextInput组件内文本着色效果。

从API版本26.0.0开始，新增shaderStyle接口。

```ts
@Entry
@Component
struct ShaderColorStyle {
  @State message: string = 'Hello World';
  @State linearGradientOptions1: LinearGradientOptions =
    {
      angle: 45,
      colors: [[Color.Red, 0.0], [Color.Blue, 0.3], [Color.Green, 0.5]]
    };
  @State linearGradientOptions2: LinearGradientOptions =
    {
      direction: GradientDirection.LeftTop,
      colors: [[Color.Red, 0.0], [Color.Blue, 0.3], [Color.Green, 0.5]],
      repeating: true,
    };
  @State radialGradientOptions: RadialGradientOptions =
    {
      center: [50, 50],
      radius: 20,
      colors: [[Color.Red, 0.0], [Color.Blue, 0.3], [Color.Green, 0.5]],
      repeating: true,
    };
  @State colorShaderStyle: ColorShaderStyle =
    {
      color: Color.Blue
    };
  build() {
    Column({ space: 5 }) {
      Text('angle为45°的线性渐变').fontSize(18).width('90%')
        .margin({ top: 40, left: 40 })
      TextInput({ text: this.message })
        .fontSize(20)
        .width('80%')
        .height(50)
        .shaderStyle(this.linearGradientOptions1)
      Text('direction为LeftTop的线性渐变').fontSize(18).width('90%')
        .margin({ top: 40, left: 40 })
      TextInput({ text: this.message })
        .fontSize(20)
        .width('80%')
        .height(50)
        .shaderStyle(this.linearGradientOptions2)
      Text('径向渐变').fontSize(18).width('90%')
        .margin({ top: 40, left: 40 })
      TextInput({ text: this.message })
        .fontSize(20)
        .width('80%')
        .height(50)
        .shaderStyle(this.radialGradientOptions)
      Text('纯色').fontSize(18).width('90%')
        .margin({ top: 40, left: 40 })
      TextInput({ text: this.message })
        .fontSize(20)
        .width('80%')
        .height(50)
        .shaderStyle(this.colorShaderStyle)
    }
  }
}
```
![TextInputShaderStyle](figures/textInputShaderStyle.png)

### 示例34（设置文本选择的AI菜单）

该示例通过[enableSelectedDataDetector](#enableselecteddatadetector22)，配置文本选择AI菜单功能。

从API version 22开始，新增enableSelectedDataDetector。

```ts
@Entry
@Component
struct Demo34 {
  exampleText: string = '示例网址：www.example.com';

  build() {
    Column() {
      Row() {
        TextInput({ text: this.exampleText })
          .copyOption(CopyOptions.LocalDevice)
          .enableSelectedDataDetector(true)
          .border({ width: 1, color: Color.Black })
          .height(300)
          .margin(10)
      }
    }
  }
}
```
<!--RP5--><!--RP5End-->