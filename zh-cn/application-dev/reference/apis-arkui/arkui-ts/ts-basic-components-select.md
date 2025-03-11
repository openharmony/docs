#  Select

提供下拉选择菜单，可以让用户在多个选项之间选择。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Select(options: Array\<SelectOption>)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                           | 必填 | 说明           |
| ------- | ---------------------------------------------- | ---- | -------------- |
| options | Array\<[SelectOption](#selectoption对象说明)\> | 是   | 设置下拉选项。 |

## SelectOption对象说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                            | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | -------------- |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 下拉选项内容。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| icon   | [ResourceStr](ts-types.md#resourcestr) | 否   | 下拉选项图片。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| symbolIcon<sup>12+</sup>  | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 下拉选项Symbol图片。<br/>symbolIcon优先级高于icon。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### selected

selected(value: number | Resource)

设置下拉菜单初始选项的索引，第一项的索引为0。当不设置selected属性或设置异常值时，默认选择值为-1，菜单项不选中；当设置为undefined、null时，选中第一项。

从API version 10开始，该属性支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| value  | number&nbsp;\|&nbsp;[Resource](ts-types.md#resource)<sup>11+</sup> | 是   | 下拉菜单初始选项的索引。 |

### selected<sup>16+</sup>

selected(numCount: Optional<number | Resource>)

设置下拉菜单初始选项的索引，第一项的索引为0。当不设置selected属性或设置异常值时，默认选择值为-1，菜单项不选中；当设置为undefined、null时，选中第一项。

该属性支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| numCount | [Optional](ts-universal-attributes-custom-property.md#optional12)\<number&nbsp;\|&nbsp;[Resource](ts-types.md#resource)> | 是   | 下拉菜单初始选项的索引。<br/>当numCount的值为undefined时，选中第一项。 |

### value

value(value: ResourceStr)

设置下拉按钮本身的文本内容。当菜单选中时默认会替换为菜单项文本内容。

从API version 10开始，该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                     |
| ------ | ---------------------------------------------------- | ---- | ------------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr)<sup>11+</sup> | 是   | 下拉按钮本身的文本内容。 |

### value<sup>16+</sup>

value(resStr: Optional\<ResourceStr>)

设置下拉按钮本身的文本内容。当菜单选中时默认会替换为菜单项文本内容。与[value](#value)相比，resStr参数新增了对undefined类型的支持。

该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resStr | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceStr](ts-types.md#resourcestr)> | 是   | 下拉按钮本身的文本内容。<br/>当resStr的值为undefined时维持上次取值。 |

### controlSize<sup>12+</sup>

controlSize(value: ControlSize)

设置Select组件的尺寸。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                             |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| value  | [ControlSize](ts-basic-components-button.md#controlsize11枚举说明)<sup>11+</sup> | 是   | Select组件的尺寸。<br/>默认值:ControlSize.NORMAL |

controlSize、width、height接口作用优先级：

   1）如果开发者只设置了width和height，当文字大小设置的是比较大的值的时候，文字超出组件大小，且以省略号方式显示；

   2）如果开发者只设置了controlSize，没有设置width和height，组件宽高自适应文字，文字不超出组件，并设置最小宽度minWidth和最小高度minHeight；

   3）如果controlSize、width、height接口都设置了，width和height设置的值生效，但如果width和height设置的值小于controlSize设置的最小宽度minWidth和最小高度minHeight，width和height设置的值不生效，宽高仍保持controlSize设置的最小宽度minWidth和最小高度minHeight。

### controlSize<sup>16+</sup>

controlSize(size: Optional\<ControlSize>)

设置Select组件的尺寸。与[controlSize](#controlsize12)<sup>12+</sup>相比，size参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ControlSize](ts-basic-components-button.md#controlsize11枚举说明)> | 是   | Select组件的尺寸。<br/>当size的值为undefined时，默认值:ControlSize.NORMAL |

controlSize、width、height接口作用优先级：

   1）如果开发者只设置了width和height，当文字大小设置的是比较大的值的时候，文字超出组件大小，且以省略号方式显示；

   2）如果开发者只设置了controlSize，没有设置width和height，组件宽高自适应文字，文字不超出组件，并设置最小宽度minWidth和最小高度minHeight；

   3）如果controlSize、width、height接口都设置了，width和height设置的值生效，但如果width和height设置的值小于controlSize设置的最小宽度minWidth和最小高度minHeight，width和height设置的值不生效，宽高仍保持controlSize设置的最小宽度minWidth和最小高度minHeight。

### menuItemContentModifier<sup>12+</sup>

menuItemContentModifier(modifier: ContentModifier\<MenuItemConfiguration>)

定制Select下拉菜单项内容区的方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                          | 必填 | 说明                                             |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------ |
| modifier  | [ContentModifier\<MenuItemConfiguration>](#menuitemconfiguration12对象说明) | 是   | 在Select组件上，定制下拉菜单项内容区的方法。<br/>modifier: 内容修改器，开发者需要自定义class实现ContentModifier接口。 |

### menuItemContentModifier<sup>16+</sup>

menuItemContentModifier(modifier: Optional\<ContentModifier\<MenuItemConfiguration>>)

定制Select下拉菜单项内容区的方法。与[menuItemContentModifier](#menuitemcontentmodifier12)<sup>12+</sup>相比，modifier参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| modifier | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ContentModifier\<MenuItemConfiguration>](#menuitemconfiguration12对象说明)> | 是   | 在Select组件上，定制下拉菜单项内容区的方法。<br/>modifier: 内容修改器，开发者需要自定义class实现ContentModifier接口。<br/>当modifier的值为undefined时，不使用内容修改器。 |

### divider<sup>12+</sup>

divider(options: Optional\<DividerOptions> | null)

设置分割线样式，不设置该属性则按“默认值”展示分割线。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型    | 必填 | 说明                                                                  |
| ------ | ------- | ---- | --------------------------------------------------------------------- |
| options  | Optional\<[DividerOptions](ts-basic-components-textpicker.md#divideroptions12对象说明)> \| null | 是   | 1.设置DividerOptions，则按设置的样式显示分割线。<br/>默认值：<br/>{<br/>strokeWidth: '1px' , <br/>color: '#33182431'<br/>}<br/>2.设置为null时，不显示分割线。<br/>3.strokeWidth设置过宽时，会覆盖文字。分割线会从每一个Item底部开始，同时向上向下画分割线。<br/>4.startMargin和endMargin的默认值与不设置divider属性时的分割线样式保持一致。startMargin和endMargin的和与optionWidth的值相等时，不显示分割线。 startMargin和endMargin的和超过optionWidth的值时，按照默认样式显示分割线。|

### dividerStyle<sup>16+</sup>

设置分割线样式，不设置该属性则按“默认值”展示分割线。该属性与divider互斥，按调用顺序生效。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型    | 必填 | 说明                                                                  |
| ------ | ------- | ---- | --------------------------------------------------------------------- |
| options  | Optional\<[DividerStyleOptions](ts-types.md#dividerstyleoptions12)> \| null | 是   | 1.设置DividerOptions，则按设置的样式显示分割线。<br/>默认值：<br/>{<br/>strokeWidth: '1px' , <br/>color: '#33182431'<br/>}<br/>2.设置为null或undifined时，展示默认分割线。<br/>3.当mode为FLOAT_ABOVE_MENU时，strokeWidth设置过宽时，会覆盖文字。分割线会从每一个Item底部开始，同时向上向下画分割线。当mode为EMBEDDED_IN_MENU时，分割线在Menu中展开，独立占用高度。<br/>4.startMargin和endMargin的默认值与不设置divider属性时的分割线样式保持一致。startMargin和endMargin的和与optionWidth的值相等时，不显示分割线。 startMargin和endMargin的和超过optionWidth的值时，按照默认样式显示分割线。|

### font

font(value: Font)

设置下拉按钮本身的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                                                         |
| ------ | ------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Font](ts-types.md#font) | 是   | 下拉按钮本身的文本样式。<br/>API Version 11及以前默认值：<br/>{<br/>size:&nbsp;`$r('sys.float.ohos_id_text_size_button1')`,<br/>weight:&nbsp;FontWeight.Medium<br/>} <br/>API Version 12以后，如果设置controlSize的值为：controlSize.SMALL，size默认值是`$r('sys.float.ohos_id_text_size_button2')`，否则为`$r('sys.float.ohos_id_text_size_button1')`。 |

### font<sup>16+</sup>

font(selectFont: Optional\<Font>)

设置下拉按钮本身的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。与[font](#font)相比，selectFont参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| selectFont | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Font](ts-types.md#font)> | 是   | 下拉按钮本身的文本样式。<br/>如果设置controlSize的值为：controlSize.SMALL，size默认值是`$r('sys.float.ohos_id_text_size_button2')`，否则为`$r('sys.float.ohos_id_text_size_button1')`。<br/>当selectFont的值为undefined时，恢复为系统文本样式。 |

### fontColor

fontColor(value: ResourceColor)

设置下拉按钮本身的文本颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 下拉按钮本身的文本颜色。<br/>默认值：`$r('sys.color.ohos_id_color_text_primary')`混合`$r('sys.color.ohos_id_alpha_content_primary')`的透明度。 |

### fontColor<sup>16+</sup>

fontColor(resColor: Optional\<ResourceColor>)

设置下拉按钮本身的文本颜色。与[fontColor](#fontcolor)相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉按钮本身的文本颜色。<br/>当resColor的值为undefined时，默认值：`$r('sys.color.ohos_id_color_text_primary')`混合`$r('sys.color.ohos_id_alpha_content_primary')`的透明度。<br/>当value的值为undefined时，维持上次取值。 |

### selectedOptionBgColor

selectedOptionBgColor(value: Optional\<ResourceColor>)

设置下拉菜单选中项的背景色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单选中项的背景色。<br/>默认值：`$r('sys.color.ohos_id_color_component_activated')`混合`$r('sys.color.ohos_id_alpha_highlight_bg')`的透明度。 |

### selectedOptionBgColor<sup>16+</sup>

selectedOptionBgColor(resColor: Optional\<ResourceColor>)

设置下拉菜单选中项的背景色。与[selectedOptionBgColor](#selectedoptionbgcolor)相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单选中项的背景色。<br/>当resColor的值为undefined时，默认值：`$r('sys.color.ohos_id_color_component_activated')`混合`$r('sys.color.ohos_id_alpha_highlight_bg')`的透明度。 |

### selectedOptionFont

selectedOptionFont(value: Font)

设置下拉菜单选中项的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                                                         |
| ------ | ------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Font](ts-types.md#font) | 是   | 下拉菜单选中项的文本样式。<br/>默认值：<br/>{<br/>size:&nbsp;$r('sys.color.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |

### selectedOptionFont<sup>16+</sup>

selectedOptionFont(selectFont: Optional\<Font>)

设置下拉菜单选中项的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。与[selectedOptionFont](#selectedoptionfont)相比，selectFont参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| selectFont | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Font](ts-types.md#font)> | 是   | 下拉菜单选中项的文本样式。<br/>当selectFont的值为undefined时，默认值：<br/>{<br/>size:&nbsp;$r('sys.color.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |

### selectedOptionFontColor

selectedOptionFontColor(value: ResourceColor)

设置下拉菜单选中项的文本颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 下拉菜单选中项的文本颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_activated') |

### selectedOptionFontColor<sup>16+</sup>

selectedOptionFontColor(resColor: Optional\<ResourceColor>)

设置下拉菜单选中项的文本颜色。与[selectedOptionFontColor](#selectedoptionfontcolor)相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单选中项的文本颜色。<br/>当resColor的值为undefined时，默认值：$r('sys.color.ohos_id_color_text_primary_activated') |

### optionBgColor

optionBgColor(value: ResourceColor)

设置下拉菜单项的背景色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 下拉菜单项的背景色。<br/>默认值：<br/>API version 11之前，默认值为Color.White。<br/>API version 11及之后，默认值为Color.Transparent。 |

### optionBgColor<sup>16+</sup>

optionBgColor(resColor: Optional\<ResourceColor>)

设置下拉菜单项的背景色。与[optionBgColor](#optionbgcolor)相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单项的背景色。<br/>当resColor的值为undefined时，默认值为Color.Transparent。 |

### optionFont

optionFont(value: Optional\<Font>)

设置下拉菜单项的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                                                         |
| ------ | ------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Font](ts-types.md#font)> | 是   | 下拉菜单项的文本样式。<br/>默认值：<br/>{<br/>size:&nbsp;$r('sys.float.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |

### optionFont<sup>16+</sup>

optionFont(selectFont: Optional\<Font>)

设置下拉菜单项的文本样式。当size为0的时候，文本不显示，当size为负值的时候，文本的size按照默认值显示。

与[optionFont](#optionfont)相比，selectFont参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| selectFont | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Font](ts-types.md#font)> | 是   | 下拉菜单项的文本样式。<br/>当selectFont的值为undefined时，默认值：<br/>{<br/>size:&nbsp;$r('sys.float.ohos_id_text_size_body1'),<br/>weight:&nbsp;FontWeight.Regular<br/>} |

### optionFontColor

optionFontColor(value: ResourceColor)

设置下拉菜单项的文本颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 下拉菜单项的文本颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary') |

### optionFontColor<sup>16+</sup>

optionFontColor(resColor: Optional\<ResourceColor>)

设置下拉菜单项的文本颜色。与[optionFontColor](#optionfontcolor)相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单项的文本颜色。<br/>当resColor的值为undefined时，默认值：$r('sys.color.ohos_id_color_text_primary') |

### space<sup>10+</sup>

space(value: Length)

设置下拉菜单项的文本与箭头之间的间距。不支持设置百分比。设置为null、undefined，或者小于等于8的值，取默认值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                         | 必填 | 说明                                             |
| ------ | ---------------------------- | ---- | ------------------------------------------------ |
| value  | [Length](ts-types.md#length) | 是   | 下拉菜单项的文本与箭头之间的间距。<br/>默认值：8 |

### space<sup>16+</sup>

space(spaceLength: Optional\<Length>)

设置下拉菜单项的文本与箭头之间的间距。不支持设置百分比。设置为null、undefined，或者小于等于8的值，取默认值。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| spaceLength | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Length](ts-types.md#length)> | 是   | 下拉菜单项的文本与箭头之间的间距。<br/>当spaceLength的值为undefined时，默认值：8 |

### arrowPosition<sup>10+</sup>

arrowPosition(value: ArrowPosition)

设置下拉菜单项的文本与箭头之间的对齐方式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ArrowPosition](#arrowposition10枚举说明) | 是   | 下拉菜单项的文本与箭头之间的对齐方式。<br/>默认值：ArrowPosition.END |

### arrowPosition<sup>16+</sup>

arrowPosition(position: Optional\<ArrowPosition>)

设置下拉菜单项的文本与箭头之间的对齐方式。与[arrowPosition](#arrowposition10)相比，position参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| position | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ArrowPosition](#arrowposition10枚举说明)> | 是   | 下拉菜单项的文本与箭头之间的对齐方式。<br/>当position的值为undefined时，默认值：ArrowPosition.END |

### menuAlign<sup>10+</sup>

menuAlign(alignType: MenuAlignType, offset?: Offset)

设置下拉按钮与下拉菜单间的对齐方式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                      | 必填 | 说明                                                         |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| alignType | [MenuAlignType](#menualigntype10枚举说明) | 是   | 对齐方式类型。<br/>默认值：MenuAlignType.START               |
| offset    | [Offset](ts-types.md#offset)              | 否   | 按照对齐类型对齐后，下拉菜单相对下拉按钮的偏移量。<br/> 默认值：{dx: 0, dy: 0} |

### menuAlign<sup>16+</sup>

menuAlign(alignType: Optional\<MenuAlignType>, offset?: Offset)

设置下拉按钮与下拉菜单间的对齐方式。与[menuAlign](#menualign10)<sup>10+</sup>相比，alignType参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| alignType | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[MenuAlignType](#menualigntype10枚举说明)> | 是   | 对齐方式类型。<br/>当alignType的值为undefined时，默认值：MenuAlignType.START |
| offset    | [Offset](ts-types.md#offset)                                 | 否   | 按照对齐类型对齐后，下拉菜单相对下拉按钮的偏移量。<br/> 默认值：{dx: 0, dy: 0} |

### optionWidth<sup>11+</sup>

optionWidth(value: Dimension | OptionWidthMode )

设置下拉菜单项的宽度，不支持设置百分比。OptionWidthMode类型为枚举类型，OptionWidthMode决定下拉菜单是否继承下拉按钮宽度。

当设置为异常值或小于最小宽度56vp时，属性不生效，菜单项宽度设为默认值，即菜单默认宽度为2栅格。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[OptionWidthMode](ts-appendix-enums.md#optionwidthmode11) | 是   | 下拉菜单项的宽度。 |

### optionWidth<sup>16+</sup>

optionWidth(width: Optional\<Dimension | OptionWidthMode> )

设置下拉菜单项的宽度，不支持设置百分比。OptionWidthMode类型为枚举类型，OptionWidthMode决定下拉菜单是否继承下拉按钮宽度。与[optionWidth](#optionwidth11)<sup>11+</sup>相比，width参数新增了对undefined类型的支持。

当设置为异常值或小于最小宽度56vp时，属性不生效，菜单项宽度设为默认值，即菜单默认宽度为2栅格。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| width  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[OptionWidthMode](ts-appendix-enums.md#optionwidthmode11)> | 是   | 下拉菜单项的宽度。<br/>当width的值为undefined时，属性不生效，菜单项宽度设为默认值，即菜单默认宽度为2栅格。 |

### optionHeight<sup>11+</sup>

optionHeight(value: Dimension)

设置下拉菜单显示的最大高度，不支持设置百分比。下拉菜单的默认最大高度是屏幕可用高度的80%，设置的菜单最大高度不能超过默认最大高度。

当设置为异常值或零时，属性不生效，下拉菜单最大高度设为默认值，即下拉菜单最大高度默认值为屏幕可用高度的80%。

如果下拉菜单所有选项的实际高度没有设定的高度大，下拉菜单的高度按实际高度显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                 | 必填 | 说明                     |
| ------ | ------------------------------------ | ---- | ------------------------ |
| value  | [Dimension](ts-types.md#dimension10) | 是   | 下拉菜单显示的最大高度。 |

### optionHeight<sup>16+</sup>

optionHeight(height: Optional\<Dimension>)

设置下拉菜单显示的最大高度，不支持设置百分比。下拉菜单的默认最大高度是屏幕可用高度的80%，设置的菜单最大高度不能超过默认最大高度。与[optionHeight](#optionheight11)<sup>11+</sup>相比，height参数新增了对undefined类型的支持。

当设置为异常值或零时，属性不生效，下拉菜单最大高度设为默认值，即下拉菜单最大高度默认值为屏幕可用高度的80%。

如果下拉菜单所有选项的实际高度没有设定的高度大，下拉菜单的高度按实际高度显示。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| height | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[Dimension](ts-types.md#dimension10)> | 是   | 下拉菜单显示的最大高度。<br/>当height的值为undefined时，属性不生效，下拉菜单最大高度设为默认值，即下拉菜单最大高度默认值为屏幕可用高度的80%。 |

### menuBackgroundColor<sup>11+</sup>

menuBackgroundColor(value: ResourceColor)

设置下拉菜单的背景色。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 下拉菜单的背景色。<br/>默认值：<br/>API version 11之前，默认值为$r('sys.color.ohos_id_color_card_bg')。<br/>API version 11及之后，默认值为Color.Transparent。 |

### menuBackgroundColor<sup>16+</sup>

menuBackgroundColor(resColor: Optional\<ResourceColor>)

设置下拉菜单的背景色。与[menuBackgroundColor](#menubackgroundcolor11)<sup>11+</sup>相比，resColor参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| resColor | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[ResourceColor](ts-types.md#resourcecolor)> | 是   | 下拉菜单的背景色。<br/>当resColor的值为undefined时，默认值为Color.Transparent。 |

### menuBackgroundBlurStyle<sup>11+</sup>

menuBackgroundBlurStyle(value: BlurStyle)

设置下拉菜单的背景模糊材质。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [BlurStyle](ts-universal-attributes-background.md#blurstyle9) | 是   | 下拉菜单的背景模糊材质。<br/>默认值：BlurStyle.COMPONENT_ULTRA_THICK |

### menuBackgroundBlurStyle<sup>16+</sup>

menuBackgroundBlurStyle(style: Optional\<BlurStyle>)

设置下拉菜单的背景模糊材质。与[menuBackgroundBlurStyle](#menubackgroundblurstyle11)<sup>11+</sup>相比，style参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style  | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[BlurStyle](ts-universal-attributes-background.md#blurstyle9)> | 是   | 下拉菜单的背景模糊材质。<br/>当style的值为undefined时，默认值：BlurStyle.COMPONENT_ULTRA_THICK |

### avoidance<sup>18+</sup>

avoidance(mode: AvoidanceMode)

设置下拉菜单的避让模式。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                      | 必填 | 说明                                                         |
| --------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| mode      | [AvoidanceMode](#avoidancemode18枚举说明)  | 是   | 设置下拉菜单的避让模式。<br/>默认值：AvoidanceMode.COVER_TARGET |

## ArrowPosition<sup>10+</sup>枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 说明             |
| ------------------- | ------------------ |
| END | 文字在前，箭头在后。 |
| START | 箭头在前，文字在后。 |

## MenuAlignType<sup>10+</sup>枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 值 | 说明             |
| ------------------- | --- | ------------------ |
| START               | 0 |按照语言方向起始端对齐。 |
| CENTER              | 1 |居中对齐。 |
| END                 | 2 |按照语言方向末端对齐。 |

## AvoidanceMode<sup>18+</sup>枚举说明

下拉菜单避让模式的枚举选项。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 说明             |
| ------------------- | ------------------ |
| COVER_TARGET        | 当四周都无足够空间显示时，覆盖目标组件。 |
| AVOID_AROUND_TARGET | 目标组件四周无足够空间时，在最大空间处压缩显示（可滚动）。 |

## MenuItemConfiguration<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                         | 必填 | 说明                                                         |
| ------ | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 下拉菜单项的文本内容。 |
| icon  | [ResourceStr](ts-types.md#resourcestr) | 否   | 下拉菜单项的图片内容。 |
| symbolIcon<sup>12+</sup>  | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 下拉选项Symbol图片内容。|
| selected  | boolean | 是   | 下拉菜单项是否被选中。<br/>默认值：false |
| index  | number | 是   | 下拉菜单项的索引。 |
| triggerSelect  | (index: number, value: string) :void | 是   | 下拉菜单选中某一项的回调函数。<br/>index: 选中菜单项的索引。<br/>value: 选中菜单项的文本。<br/>说明: index会赋值给事件[onSelect](#onselect)回调中的索引参数； value会返回给Select组件显示，同时会赋值给事件[onSelect](#onselect)回调中的文本参数。 |

## 事件

### onSelect

onSelect(callback: OnSelectCallback )

下拉菜单选中某一项的回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                    | 必填 | 说明                       |
| -------- | --------------------------------------- | ---- | -------------------------- |
| callback | [OnSelectCallback](#onselectcallback16) | 是   | 下拉菜单选中某一项的回调。 |

### onSelect<sup>16+</sup>

onSelect(callback: Optional\<OnSelectCallback> )

下拉菜单选中某一项的回调。与[onSelect](#onselect)相比，callback参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | [Optional](ts-universal-attributes-custom-property.md#optional12)\<[OnSelectCallback](#onselectcallback16)> | 是   | 下拉菜单选中某一项的回调。<br/>当callback的值为undefined时，不使用回调函数。 |

## OnSelectCallback<sup>16+</sup>

type OnSelectCallback = (index: number, value: string) => void

下拉菜单选中某一项的回调。

**卡片能力：** 从API version 16开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| index  | number | 是   | 选中项的索引。 |
| value  | string | 是   | 选中项的值。   |

##  示例1（设置下拉菜单）

该示例通过配置SelectOptions实现下拉菜单。

```ts
// xxx.ets
@Entry
@Component
struct SelectExample {
  @State text: string = "TTTTT"
  @State index: number = 2
  @State space: number = 8
  @State arrowPosition: ArrowPosition = ArrowPosition.END

  build() {
    Column() {
      Select([{ value: 'aaa', icon: $r("app.media.selection") },
        { value: 'bbb', icon: $r("app.media.selection") },
        { value: 'ccc', icon: $r("app.media.selection") },
        { value: 'ddd', icon: $r("app.media.selection") }])
        .selected(this.index)
        .value(this.text)
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .space(this.space)
        .arrowPosition(this.arrowPosition)
        .menuAlign(MenuAlignType.START, { dx: 0, dy: 0 })
        .optionWidth(200)
        .optionHeight(300)
        .onSelect((index: number, text?: string | undefined) => {
          console.info('Select:' + index)
          this.index = index;
          if (text) {
            this.text = text;
          }
        })
        .avoidance(AvoidanceMode.COVER_TARGET);
    }.width('100%')
  }
}
```

![](figures/selectExample.png)



##  示例2（设置symbol类型图标）
该示例实现了一个下拉菜单中图片为Symbol的Select组件。

```ts
// xxx.ets
import { SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@Component
struct SelectExample {
  @State text: string = "TTTTT"
  @State index: number = 2
  @State space: number = 8
  @State arrowPosition: ArrowPosition = ArrowPosition.END
  @State symbolModifier1: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_wifi')).fontColor([Color.Green]);
  @State symbolModifier2: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]);
  @State symbolModifier3: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_trash')).fontColor([Color.Gray]);
  @State symbolModifier4: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.exposure')).fontColor([Color.Gray]);

  build() {
    Column() {
      Select([{ value: 'aaa', symbolIcon: this.symbolModifier1 },
        { value: 'bbb', symbolIcon: this.symbolModifier2 },
        { value: 'ccc', symbolIcon: this.symbolModifier3 },
        { value: 'ddd', symbolIcon: this.symbolModifier4 }])
        .selected(this.index)
        .value(this.text)
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .space(this.space)
        .arrowPosition(this.arrowPosition)
        .menuAlign(MenuAlignType.START, { dx: 0, dy: 0 })
        .onSelect((index: number, text?: string | undefined) => {
          console.info('Select:' + index)
          this.index = index;
          if (text) {
            this.text = text;
          }
        })
        .avoidance(AvoidanceMode.COVER_TARGET);
    }.width('100%')
  }
}
```

![](figures/SelectSymbol.png)

##  示例3（自定义下拉菜单）
该示例实现了一个自定义下拉菜选项的Select组件。自定义下拉菜单选项样式为“文本 + Symbol图片 + 空白间隔 + 文本 + 绘制三角形”，点击菜单选项后Select组件显示菜单选项的文本内容。

```ts
import { SymbolGlyphModifier } from '@kit.ArkUI'

class MyMenuItemContentModifier implements ContentModifier<MenuItemConfiguration> {
  modifierText: string = ""

  constructor(text: string) {
    this.modifierText = text;
  }

  applyContent(): WrappedBuilder<[MenuItemConfiguration]> {
    return wrapBuilder(MenuItemBuilder)
  }
}

@Builder
function MenuItemBuilder(configuration: MenuItemConfiguration) {
  Row() {
    Text(configuration.value)
    Blank()
    if (configuration.symbolIcon) {
      SymbolGlyph().attributeModifier(configuration.symbolIcon).fontSize(24)
    } else if (configuration.icon) {
      Image(configuration.icon).size({ width: 24, height: 24 })
    }
    Blank(30)
    Text((configuration.contentModifier as MyMenuItemContentModifier).modifierText)
    Blank(30)
    Path()
      .width('100px')
      .height('150px')
      .commands('M40 0 L80 100 L0 100 Z')
      .fillOpacity(0)
      .stroke(Color.Black)
      .strokeWidth(3)
  }
  .onClick(() => {
    configuration.triggerSelect(configuration.index, configuration.value.valueOf().toString())
  })
}

@Entry
@Component
struct SelectExample {
  @State text: string = "Content Modifier Select"
  @State symbolModifier1: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.ohos_trash')).fontColor([Color.Gray]);
  @State symbolModifier2: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.exposure')).fontColor([Color.Gray]);

  build() {
    Column() {
      Row() {
        Select([{ value: 'item1', icon: $r('app.media.icon'), symbolIcon: this.symbolModifier1 },
          { value: 'item1', icon: $r('app.media.icon'), symbolIcon: this.symbolModifier2 }])
          .value(this.text)
          .onSelect((index: number, text?: string) => {
            console.info('Select index:' + index)
            console.info('Select text:' + text)
          })
          .menuItemContentModifier(new MyMenuItemContentModifier("Content Modifier"))

      }.alignItems(VerticalAlign.Center).height('50%')
    }
  }
}
```
![](figures/SelectBuilderSymbol.png)

##  示例4（设置分割线样式）
该示例通过配置divider的DividerOptions类型实现分割线样式的下拉菜单。

```ts
// xxx.ets
@Entry
@Component
struct SelectExample {
  @State text: string = "TTTTT"
  @State index: number = -1
  @State arrowPosition: ArrowPosition = ArrowPosition.END

  build() {
    Column() {
      Select([{ value: 'aaa', icon: $r("app.media.icon") },
        { value: 'bbb', icon: $r("app.media.icon") },
        { value: 'ccc', icon: $r("app.media.icon") },
        { value: 'ddd', icon: $r("app.media.icon") }])
        .selected(this.index)
        .value(this.text)
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .arrowPosition(this.arrowPosition)
        .menuAlign(MenuAlignType.START, { dx: 0, dy: 0 })
        .optionWidth(200)
        .optionHeight(300)
        .divider({
          strokeWidth: 5,
          color: Color.Blue,
          startMargin: 10,
          endMargin: 10
        })
        .onSelect((index: number, text?: string | undefined) => {
          console.info('Select:' + index)
          this.index = index;
          if (text) {
            this.text = text;
          }
        })
        .avoidance(AvoidanceMode.COVER_TARGET);
    }.width('100%')
  }
}
```
![](figures/SelectCustomDivider.png)

##  示例5（设置无分割线样式）
该示例通过配置divider为null实现无分割线样式的下拉菜单。

```ts
// xxx.ets
@Entry
@Component
struct SelectExample {
  @State text: string = "TTTTT"
  @State index: number = -1
  @State arrowPosition: ArrowPosition = ArrowPosition.END

  build() {
    Column() {
      Select([{ value: 'aaa', icon: $r("app.media.icon") },
        { value: 'bbb', icon: $r("app.media.icon") },
        { value: 'ccc', icon: $r("app.media.icon") },
        { value: 'ddd', icon: $r("app.media.icon") }])
        .selected(this.index)
        .value(this.text)
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .arrowPosition(this.arrowPosition)
        .menuAlign(MenuAlignType.START, { dx: 0, dy: 0 })
        .optionWidth(200)
        .optionHeight(300)
        .divider(null)
        .onSelect((index: number, text?: string | undefined) => {
          console.info('Select:' + index)
          this.index = index;
          if (text) {
            this.text = text;
          }
        })
        .avoidance(AvoidanceMode.COVER_TARGET);
    }.width('100%')
  }
}
```
![](figures/SelectHideDivider.png)
