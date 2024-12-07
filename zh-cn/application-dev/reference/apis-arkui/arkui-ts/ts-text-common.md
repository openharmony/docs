# 文本组件公共接口

>**说明：**
>
>文本类组件公共接口。
>本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CaretStyle<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                   | 必填 | 说明 |
| ------ | ------------------------------------------ | ---- | -------- |
| width  | [Length](ts-types.md#length)               | 否   | 光标尺寸，不支持百分比。 |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 光标颜色。 |

## LayoutManager<sup>12+</sup>

布局管理器对象。

> **说明：**
>
> 文本内容变更后，需等待布局完成才可获取到最新的布局信息。

### 导入对象
以Text组件为例
```
controller: TextController = new TextController()
let layoutManager: LayoutManager = this.controller.getLayoutManager();
```

### getLineCount

getLineCount(): number

获取组件内容的总行数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 组件内容的总行数。 |

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

获取较为接近给定坐标的字形的位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| x | number | 是    | 相对于组件的横坐标，单位px |
| y | number | 是    | 相对于组件的纵坐标，单位px |

**返回值：**

| 类型                                          | 说明        |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity12) | 字形位置信息。|

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics

获取指定行的行信息、文本样式信息、以及字体属性信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | 是    | 行号。从0开始。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | 行信息、文本样式信息、以及字体属性信息。 |

### getRectsForRange<sup>14+</sup>

getRectsForRange(range: Range, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

获取给定的矩形区域宽度以及矩形区域高度的规格下，文本中任意区间范围内的字符或占位符所占的绘制区域信息。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                 | 必填 | 说明                     |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [Range](../../apis-arkgraphics2d/js-apis-graphics-text.md#range)                     | 是   | 需要获取的区域的文本区间。  |
| widthStyle  | [RectWidthStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectwidthstyle)   | 是   | 返回的矩形区域的宽度的规格。|
| heightStyle | [RectHeightStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectheightstyle) | 是   | 返回的矩形区域的高度的规格。|

**返回值：**

| 类型                         | 说明        |
| --------------------------- | ----------- |
| Array\<[TextBox](../../apis-arkgraphics2d/js-apis-graphics-text.md#textbox)> | 矩形区域数组。|

## PositionWithAffinity<sup>12+</sup>

位置以及亲和度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 只读 | 可选 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 否   | 字形相对于组件内容的索引，整数。  |
| affinity  | [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | 是   | 是   | 位置亲和度。             |

## TextMenuItemId<sup>12+</sup>

菜单的Id值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 可选  | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  是  |  是 | 默认裁剪。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| COPY  | [TextMenuItemId](#textmenuitemid12) |  是  |  是  | 默认复制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PASTE | [TextMenuItemId](#textmenuitemid12)   | 是    | 是    | 默认粘贴。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | 是    | 是    | 默认全选。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | 是    | 是    | 互通服务。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | 是    | 是   | 拍摄输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| AI_WRITER<sup>13+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 是    | 可对选中的文本进行润色、摘要提取、排版等。该菜单项依赖大模型能力，否则不生效。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |

### of

static of(id: ResourceStr): TextMenuItemId

根据id创建TextMenuItemId。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [ResourceStr](ts-types.md#resourcestr) | 是   | 菜单的id。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| [TextMenuItemId](#textmenuitemid12) | TextMenuItemId的对象。 |

### equals

equals(id: TextMenuItemId): boolean

判断TextMenuItemId是否相等。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [TextMenuItemId](#textmenuitemid12) | 是   | TextMenuItemId的id。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| boolean | 两个TextMenuItemId是否相等。 |

## TextMenuItem<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | 是   | 菜单名称。 |
| icon | [ResourceStr](ts-types.md#resourcestr) | 否   | 菜单图标。<br/>不支持网络图片。 |
| id | [TextMenuItemId](#textmenuitemid12) | 是   | 菜单id。 |

## EditMenuOptions对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onCreateMenu<sup>12+</sup>

onCreateMenu(menuItems: Array\<TextMenuItem>): Array\<TextMenuItem>

菜单数据模版编辑能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12对象说明)> | 是   | 菜单项。<br/>**说明：** <br/>对默认菜单项的名称修改不生效。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12对象说明)> | 设置的菜单项。<br/>**说明：** <br/>不返回系统默认菜单项的图标。 |

### onMenuItemClick<sup>12+</sup>

onMenuItemClick(menuItem: TextMenuItem, range: TextRange): boolean

菜单项功能函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItem | [TextMenuItem](#textmenuitem12对象说明) | 是   | 菜单项。 |
| range | [TextRange](#textrange12) | 是   | 选中的文本信息。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| boolean | 菜单项的执行逻辑。<br/>返回为true，拦截系统默认逻辑，仅执行自定义逻辑。<br/>返回为false，先执行自定义逻辑，再执行系统逻辑。 |

## TextRange<sup>12+</sup>

文本范围。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

| 名称 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| start | number | 否 | 起始索引。 |
| end | number | 否 | 结束索引。 |

## EditableTextOnChangeCallback<sup>12+</sup>

type EditableTextOnChangeCallback = (value: string, previewText?: PreviewText) => void

输入内容发生变化时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| value | string | 是 | 文本框内正式上屏的文本内容。 |
| previewText | [PreviewText](#previewtext12) | 否 | 预上屏文本信息，包含预上屏起始位置和文本内容。 |

## TextDataDetectorType<sup>11+</sup>枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 说明                               |
| ----- | -------------------------------------- |
| PHONE_NUMBER  | 电话号码 |
| URL | 链接 |
| EMAIL | 邮箱 |
| ADDRESS | 地址 |
| DATE_TIME<sup>12+</sup> | 时间 |

## TextDeleteDirection<sup>12+</sup>枚举说明

定义删除文本方向。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                        |
| ------- | ---- | ---------------------------------- |
| BACKWARD | 0    | 向后删除。 |
| FORWARD    | 1    | 向前删除。 |

## MenuType<sup>13+</sup>枚举说明

菜单类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| SELECTION_MENU | 0 | 文本选择菜单。|
| PREVIEW_MENU | 1 | 图片预览菜单。|

## InsertValue<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                          | 必填 | 说明                                                         |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| insertOffset  | number | 是   | 插入的值的位置信息。 |
| insertValue  | string | 是   | 插入的值。 |

## DeleteValue<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 必填 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| deleteOffset  | number | 是   | 删除的值的位置信息。 |
| direction  | [TextDeleteDirection](#textdeletedirection12枚举说明) | 是   | 删除值的方向。 |
| deleteValue  | string | 是   | 删除的值。 |

## TextDataDetectorConfig<sup>11+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 必填 | 说明  |
| ------ | -------- | ---- | ------------------------------------------- |
| types   | [TextDataDetectorType](ts-text-common.md#textdatadetectortype11枚举说明)[] | 是   | 设置文本识别的实体类型。设置types为null或者[]时，识别所有类型的实体，否则只识别指定类型的实体。 |
| onDetectResultUpdate   | (result: string) => void | 否   | 文本识别成功后，触发onDetectResultUpdate回调。<br/>-&nbsp;result：文本识别的结果，Json格式。 |
| color<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | 否   | 设置文本识别成功后的实体颜色。<br/>默认值：'#ff0a59f7' |
| decoration<sup>12+</sup>  | [DecorationStyleInterface](ts-universal-styled-string.md#decorationstyleinterface对象说明)| 否   | 设置文本识别成功后的实体装饰线样式。<br/>默认值：<br/>{<br/>&nbsp;type:&nbsp;TextDecorationType.Underline,<br/>&nbsp;color:&nbsp;与实体颜色一致,<br/>&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;<br/>} |
## PreviewText<sup>12+</sup>

预上屏信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                             | 必填 | 说明                                                     |
| -------- | ------------------------------------------------ | ---- | -------------------------------------------------------- |
| offset | number | 是   | 预上屏内容的起始位置。 |
| value    | string         | 是   | 预上屏的内容。         |

## FontSettingOptions<sup>12+</sup>对象说明

字体配置项。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                             | 必填 | 说明                                                     |
| -------- | ------------------------------------------------ | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | 否   | 是否支持字重无极调节。 |

## OnDidChangeCallback<sup>12+</sup>

type OnDidChangeCallback = (rangeBefore: TextRange, rangeAfter: TextRange) => void

文本变换后回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| rangeBefore | [TextRange](#textrange12) | 是 | 文本变化前将要被替换的文本范围。 |
| rangeAfter | [TextRange](#textrange12) | 是 | 文本变化后新增内容的文本范围。 |

## StyledStringChangedListener<sup>12+</sup>

属性字符串的文本内容变化监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| onWillChange | Callback<[StyledStringChangeValue](ts-basic-components-richeditor.md#styledstringchangevalue12), boolean> | 否 | 文本内容将要变化回调函数。 |
| onDidChange | [OnDidChangeCallback](#ondidchangecallback12) | 否 | 文本内容完成变化回调函数。 |

## StyledStringChangeValue<sup>12+</sup>

属性字符串的文本变化信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| range | TextRange | 是 | 即将被替换的属性字符串子串在原字符串中的范围。 |
| replacementString | [StyledString](ts-universal-styled-string.md#styledstring) | 是 | 用于替换的属性字符串。 |
| previewText | [StyledString](ts-universal-styled-string.md#styledstring) | 否 | 预览样式字符串。 |

## TextBaseController<sup>12+</sup>

文本选择控制器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setSelection<sup>12+</sup>

setSelection(selectionStart:&nbsp;number, selectionEnd:&nbsp;number, options?:&nbsp;SelectionOptions): void

支持设置组件内的内容选中，选中部分背板高亮。

selectionStart和selectionEnd均为-1时表示全选。

未获焦时调用该接口不产生选中效果。

从API version 12开始，在2in1设备中，无论options取何值，调用setSelection接口都不会弹出菜单，此外，如果组件中已经存在菜单，调用setSelection接口会关闭菜单。

在非2in1设备中，options取值为MenuPolicy.DEFAULT时，遵循以下规则：

1. 组件内有手柄菜单时，接口调用后不关闭菜单，并且调整菜单位置。

2. 组件内有不带手柄的菜单时，接口调用后不关闭菜单，并且菜单位置不变。

3. 组件内无菜单时，接口调用后也无菜单显示。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型   | 必填   | 说明    |
| -------------- | ------ | ---- | ------- |
| selectionStart | number | 是    | 选中开始位置。 |
| selectionEnd   | number | 是    | 选中结束位置。 |
| options<sup>12+</sup>   | [SelectionOptions](ts-types.md#selectionoptions12对象说明) | 否    | 选择项配置。 |

### closeSelectionMenu<sup>12+</sup>

closeSelectionMenu(): void

关闭自定义选择菜单或系统默认选择菜单。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getLayoutManager<sup>12+</sup>

getLayoutManager(): LayoutManager

获取布局管理器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [LayoutManager](ts-text-common.md#LayoutManager) | 布局管理器对象。 |

## TextEditControllerEx<sup>12+</sup>

文本扩展编辑控制器。

继承自[TextBaseController](#textbasecontroller12)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### isEditing<sup>12+</sup>

isEditing(): boolean

获取当前富文本的编辑状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                          |
| ------- | ----------------------------- |
| boolean | true为编辑态，false为非编辑态。 |

### stopEditing<sup>12+</sup>

stopEditing(): void

退出编辑态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getCaretOffset<sup>12+</sup>

getCaretOffset(): number

返回当前光标所在位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 当前光标所在位置。 |

### setCaretOffset<sup>12+</sup>

setCaretOffset(offset: number): boolean

设置光标位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型   | 必填   | 说明                |
| ------ | ------ | ---- | -------------------- |
| offset | number | 是    | 光标偏移位置。超出所有内容范围时，设置失败。 |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 光标是否设置成功。 |

### getPreviewText<sup>12+</sup>

getPreviewText?(): PreviewText

获取预上屏信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [PreviewText](#previewtext12) | 预上屏信息。 |.

## StyledStringController<sup>12+</sup>

定义StyledString控制器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setStyledString<sup>12+</sup>

setStyledString(styledString: StyledString): void

设置富文本组件显示的属性字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明                |
| ----- | ------ | ---- | ------------------- |
| styledString | [StyledString](ts-universal-styled-string.md#styledstring) | 是    | 属性字符串。<br/>**说明：** <br/>StyledString的子类[MutableStyledString](ts-universal-styled-string.md#mutablestyledstring)也可以作为入参值。 |

### getStyledString<sup>12+</sup>

getStyledString(): MutableStyledString;

获取富文本组件显示的属性字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                          |
| ------- | ----------------------------- |
| [MutableStyledString](ts-universal-styled-string.md#mutablestyledstring) | 富文本组件显示的属性字符串 |

## DecorationStyleResult<sup>12+</sup>

后端返回的文本装饰线样式信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| type | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | 是   | 装饰线类型。 |
| color | [ResourceColor](ts-types.md#resourcecolor) | 是   | 装饰线颜色。 |
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | 否   | 装饰线样式。 |