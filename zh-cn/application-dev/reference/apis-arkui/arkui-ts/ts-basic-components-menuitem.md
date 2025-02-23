# MenuItem

用来展示菜单Menu中具体的item菜单项。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

MenuItem(value?: MenuItemOptions| CustomBuilder)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                         |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------- |
| value  | [MenuItemOptions](#menuitemoptions对象说明)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 否   | 包含设置MenuItem的各项信息。 |

## MenuItemOptions对象说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                                        | 必填 | 说明                             |
| --------- | ------------------------------------------- | ---- | -------------------------------------- |
| startIcon | [ResourceStr](ts-types.md#resourcestr)      | 否   | item中显示在左侧的图标信息路径。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。      |
| content   | [ResourceStr](ts-types.md#resourcestr)      | 否   | item的内容信息。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                        |
| endIcon   | [ResourceStr](ts-types.md#resourcestr)      | 否   | item中显示在右侧的图标信息路径。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| labelInfo | [ResourceStr](ts-types.md#resourcestr)      | 否   | 定义结束标签信息，如快捷方式Ctrl+C等。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | 否   | 用于构建二级菜单。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                      |
| symbolStartIcon<sup>12+</sup>   | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | item中显示在左侧的HMSymbol图标信息路径。配置该项时，原先startIcon图标不显示。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| symbolEndIcon<sup>12+</sup>   | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | item中显示在右侧的HMSymbol图标信息路径。配置该项时，原先endIcon图标不显示。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|


## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### selected

selected(value: boolean)

设置菜单项是否选中。

从API version 10开始，该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | 是   | 菜单项是否选中。<br />默认值：false |

### selectIcon

selectIcon(value: boolean | ResourceStr | SymbolGlyphModifier)

设置当菜单项被选中时，是否显示被选中的图标。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | boolean&nbsp;\|&nbsp;[ResourceStr](ts-types.md#resourcestr)<sup>10+</sup>\|&nbsp;[SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)<sup>12+</sup> | 是   | 菜单项被选中时，是否显示被选中的图标。<br/>默认值：false<br/>true: 菜单项被选中时，显示默认的对勾图标<br/>false: 即使菜单项被选中也不显示图标<br/>ResourceStr: 菜单项被选中时，显示指定的图标<br/>SymbolGlyphModifier: 菜单项被选中时，显示指定的HMSymbol图标。 |
### contentFont<sup>10+</sup>

contentFont(value: Font)

设置菜单项中内容信息的字体样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                         |
| ------ | ------------------------ | ---- | ---------------------------- |
| value  | [Font](ts-types.md#font) | 是   | 菜单项中内容信息的字体样式。 |

### contentFontColor<sup>10+</sup>

contentFontColor(value: ResourceColor)

设置菜单项中内容信息的字体颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 菜单项中内容信息的字体颜色。<br />默认值：'#E5000000' |

### labelFont<sup>10+</sup>

labelFont(value: Font)

设置菜单项中标签信息的字体样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 说明                         |
| ------ | ------------------------ | ---- | ---------------------------- |
| value  | [Font](ts-types.md#font) | 是   | 菜单项中标签信息的字体样式。 |

### labelFontColor<sup>10+</sup>

labelFontColor(value: ResourceColor)

设置菜单项中标签信息的字体颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 菜单项中标签信息的字体颜色。<br />默认值：'#99000000' |

## 事件

### onChange

onChange(callback: (selected: boolean) => void)

当选中状态发生变化时，触发该回调。只有手动触发且MenuItem状态改变时才会触发onChange回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| selected | boolean | 是   | 选中状态发生变化时，触发该回调。<br />返回值为true时，表示已选中，为false时，表示未选中。 |

## 示例

详见[Menu组件示例](ts-basic-components-menu.md#示例)。
