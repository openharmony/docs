# 文本组件公共接口
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

>**说明：**
>
>文本类组件公共接口。
>本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CaretStyle<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                   | 只读 | 可选 | 说明 |
| ------ | ------------------------------------------ | ---- | ---- | -------- |
| width  | [Length](ts-types.md#length)               | 否   | 是 | 光标尺寸，不支持百分比。<br/>默认值：'2vp' |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 是   | 光标颜色。<br/>默认值：'#ff007dff' |

## LayoutManager<sup>12+</sup>

布局管理器对象。

> **说明：**
>
> 文本内容变更后，需等待布局完成才可获取到最新的布局信息。

### 导入对象
以Text组件为例，完整示例请参考Text组件的[示例10获取文本信息](./ts-basic-components-text.md#示例10获取文本信息)。
```ts
controller: TextController = new TextController();
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
| x | number | 是    | 相对于组件的横坐标。<br/>单位：[px](ts-pixel-units.md) |
| y | number | 是    | 相对于组件的纵坐标。<br/>单位：[px](ts-pixel-units.md) |

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
| lineNumber | number | 是    | 行号，从0开始。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| [LineMetrics](#linemetrics12) | 行信息、文本样式信息、以及字体属性信息。<br/>当行号小于0或超出实际行，返回无效值。 |

### getRectsForRange<sup>14+</sup>

getRectsForRange(range: TextRange, widthStyle: RectWidthStyle, heightStyle: RectHeightStyle): Array\<TextBox>

获取给定的矩形区域宽度以及矩形区域高度的规格下，文本中任意区间范围内的字符或占位符所占的绘制区域信息。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                 | 必填 | 说明                     |
| ----------- | ----------------------------------- | ---- | ------------------------ |
| range       | [TextRange](#textrange12)| 是   | 需要获取的区域的文本区间。  |
| widthStyle  | [RectWidthStyle](#rectwidthstyle14)   | 是   | 返回的矩形区域的宽度的规格。|
| heightStyle | [RectHeightStyle](#rectheightstyle14) | 是   | 返回的矩形区域的高度的规格。|

**返回值：**

| 类型                         | 说明        |
| --------------------------- | ----------- |
| Array\<[TextBox](#textbox14)> | 矩形区域数组。|

## PositionWithAffinity<sup>12+</sup>

位置以及亲和度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 只读 | 可选 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 否   | 否   | 字形相对于组件内容的索引，整数。  |
| affinity  | [Affinity](#affinity12) | 否   | 否   | 位置亲和度。             |

## TextMenuItemId<sup>12+</sup>

自定义菜单项的Id值。用于识别菜单选项，内置菜单项Id值见下列属性表格。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 可选  | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  是  |  否 | 默认裁剪。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| COPY  | [TextMenuItemId](#textmenuitemid12) |  是  |  否  | 默认复制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| PASTE | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 默认粘贴。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 默认全选。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 互通服务。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否   | 拍摄输入。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| AI_WRITER<sup>13+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 可对选中的文本进行润色、摘要提取、排版等。该菜单项依赖大模型能力，否则不生效。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| TRANSLATE<sup>15+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的文本提供翻译服务。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |
| SHARE<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的文本提供分享服务，拉起分享窗口分享选中文本内容。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| SEARCH<sup>18+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的文本提供搜索服务，拉起浏览器搜索选中文本内容。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| url<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的URL提供跳转服务，拉起浏览器搜索或者应用页面。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| email<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的邮箱地址提供跳转服务，拉起邮箱应用。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| phoneNumber<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的电话号码跳转服务，拉起电话拨号页面。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| address<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的地址提供跳转服务，拉起地图应用。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| dateTime<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的日期和时间提供跳转服务，拉起新建日程页面。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| askAI<sup>20+</sup>   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 对选中的文本提供AI问询能力。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
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
| boolean | 两个TextMenuItemId是否相等。<br/>true表示相等，false表示不相等。 |

## TextMenuItem<sup>12+</sup>对象说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                              | 只读 | 可选 | 说明   |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | 否   | 否 | 菜单名称。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| icon | [ResourceStr](ts-types.md#resourcestr) | 否   | 是 | 菜单图标。<br/>不支持网络图片。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| id | [TextMenuItemId](#textmenuitemid12) |  否   | 否  | 菜单id。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| labelInfo<sup>15+</sup> | [ResourceStr](ts-types.md#resourcestr) | 否   | 是 | 快捷键提示。<br/>该字段仅2in1设备支持。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。 |

## EditMenuOptions

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onCreateMenu<sup>12+</sup>

onCreateMenu(menuItems: Array\<TextMenuItem>): Array\<TextMenuItem>

在菜单创建时触发该回调，可在该回调中进行菜单数据设置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12对象说明)> | 是   |  将要显示的菜单项。<br/>**说明：** <br/>对默认菜单项的名称、图标、快捷键提示修改不生效。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12对象说明)> | 处理后的菜单项。|

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

### onPrepareMenu<sup>20+</sup>

onPrepareMenu?: OnPrepareMenuCallback

当文本选择区域变化后显示菜单之前触发该回调，可在该回调中进行菜单数据设置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [OnPrepareMenuCallback](#onpreparemenucallback20) | 当文本选择区域变化后显示菜单之前触发该回调，可在该回调中进行菜单数据设置。|

## OnPrepareMenuCallback<sup>20+</sup>

type OnPrepareMenuCallback = (menuItems: Array\<TextMenuItem\>) => Array\<TextMenuItem\>

当文本选择区域变化后显示菜单之前触发该回调，可在该回调中进行菜单数据设置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem12对象说明)> | 是   | 将要显示的菜单项。<br/>**说明：** <br/>对默认菜单项的名称、图标、快捷键提示修改不生效。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- |
| Array\<[TextMenuItem](#textmenuitem12对象说明)> | 处理后的菜单项。|

## TextRange<sup>12+</sup>

文本范围。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -- | -- | -- | -- | -- |
| start | number | 否 | 是 | 起始索引。 |
| end | number | 否 | 是 | 结束索引。 |

## EditableTextOnChangeCallback<sup>12+</sup>

type EditableTextOnChangeCallback = (value: string, previewText?: PreviewText, options?: TextChangeOptions) => void

输入内容发生变化时，触发该回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| value | string | 是 | 文本框内正式上屏的文本内容。 |
| previewText | [PreviewText](#previewtext12) | 否 | 预上屏文本信息，包含预上屏起始位置和文本内容。 |
| options<sup>15+</sup> | [TextChangeOptions](#textchangeoptions15对象说明) | 否 | 文本内容变化信息，包含变化前后的选区范围、变化前的文本内容和预上屏文本信息。 |

## TextDataDetectorType<sup>11+</sup>枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 值   | 说明                               |
| ----- | ----- | --------------------------------- |
| PHONE_NUMBER  | 0 | 电话号码 |
| URL | 1 | 链接 |
| EMAIL | 2 | 邮箱 |
| ADDRESS | 3 | 地址 |
| DATE_TIME<sup>12+</sup> | 4 | 时间 |

## TextDeleteDirection<sup>12+</sup>枚举说明

定义删除文本方向。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                        |
| ------- | ---- | ---------------------------------- |
| BACKWARD | 0    | 向后删除。 |
| FORWARD    | 1    | 向前删除。 |

## SuperscriptStyle<sup>20+</sup>枚举说明

定义文本上下角标样式。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                        |
| ------- | ---- | ---------------------------------- |
| NORMAL | 0    | 普通文本样式。 |
| SUPERSCRIPT    | 1    | 上标文本样式。 |
| SUBSCRIPT    | 2    | 下标文本样式。 |

## MenuType<sup>13+</sup>枚举说明

菜单类型。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| SELECTION_MENU | 0 | 文本选择菜单。|
| PREVIEW_MENU | 1 | 图片预览菜单。|

## KeyboardAppearance<sup>15+</sup>枚举说明

键盘外观。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| NONE_IMMERSIVE | 0 | 默认外观模式，不采用沉浸式风格。|
| IMMERSIVE | 1 | 沉浸式模式，跟随系统。|
| LIGHT_IMMERSIVE | 2 | 浅色沉浸式风格。|
| DARK_IMMERSIVE | 3 | 深色沉浸式风格。|

## InsertValue<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                          | 只读 | 可选 | 说明                                                         |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| insertOffset  | number | 否   | 否 | 插入的值的位置信息。 |
| insertValue  | string | 否   | 否   | 插入的值。 |

## DeleteValue<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| deleteOffset  | number | 否   | 否 | 删除的值的位置信息。 |
| direction  | [TextDeleteDirection](#textdeletedirection12枚举说明) | 否   | 否   | 删除值的方向。 |
| deleteValue  | string | 否   | 否   | 删除的值。 |

## TextDataDetectorConfig<sup>11+</sup>对象说明

该配置只支持[Text](ts-basic-components-text.md#text)组件和[RichEditor](ts-basic-components-richeditor.md#richeditor)组件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 只读 | 可选 | 说明  |
| ------ | -------- | ---- | ---- | ------------------------------------------- |
| types   | [TextDataDetectorType](ts-text-common.md#textdatadetectortype11枚举说明)[] | 否 | 否  | 设置文本识别的实体类型。设置types为null或者[]时，识别所有类型的实体，否则只识别指定类型的实体。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| onDetectResultUpdate   | Callback\<string> | 否 | 是  | 文本识别成功后，触发onDetectResultUpdate回调。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| color<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | 否 | 是   | 设置文本识别成功后的实体颜色。<br/>默认值：'#ff0a59f7'<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| decoration<sup>12+</sup>  | [DecorationStyleInterface](ts-universal-styled-string.md#decorationstyleinterface)| 否 | 是   | 设置文本识别成功后的实体装饰线样式。<br/>默认值：<br/>{<br/>&nbsp;type:&nbsp;TextDecorationType.Underline,<br/>&nbsp;color:&nbsp;与实体颜色一致,<br/>&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;<br/>}<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| enablePreviewMenu<sup>20+</sup>   | boolean | 否 | 是   | 设置是否开启文本识别长按显示预览菜单。true表示开启，false表示未开启。<br/>默认值：false<br/>当[copyOptions](ts-basic-components-richeditor.md#copyoptions)设置为None时，若enablePreviewMenu设置为true，长按AI实体也不能显示预览菜单。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## PreviewText<sup>12+</sup>

预上屏信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                             | 只读 | 可选 | 说明                                                     |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| offset | number | 否   | 否 | 预上屏内容的起始位置。 |
| value    | string         | 否   | 否   | 预上屏的内容。         |

## FontSettingOptions<sup>12+</sup>对象说明

字体配置项，比如通过设置应用内组件的字体粗细，进行可变字重调节。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                             | 只读 | 可选 | 说明                                                     |
| -------- | ------------------------------------------------ | ---- | ---- | -------------------------------------------------------- |
| enableVariableFontWeight | boolean | 否 | 是  | 是否支持可变字重调节。<br/>默认值：false<br/>值为true，表示支持字重调节，值为false，表示不支持字重调节。 |

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

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -- | -- | -- | -- | -- |
| onWillChange | Callback<[StyledStringChangeValue](#styledstringchangevalue12), boolean> | 否 | 是 | 文本内容将要变化回调函数。 |
| onDidChange | [OnDidChangeCallback](#ondidchangecallback12) | 否 | 是 | 文本内容完成变化回调函数。 |

## StyledStringChangeValue<sup>12+</sup>

属性字符串的文本变化信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -- | -- | -- | -- | -- |
| range | [TextRange](#textrange12) | 否 | 否 | 即将被替换的属性字符串子串在原字符串中的范围。 |
| replacementString | [StyledString](ts-universal-styled-string.md#styledstring) | 否 | 否 | 用于替换的属性字符串。 |
| previewText | [StyledString](ts-universal-styled-string.md#styledstring) | 否 | 是 | 预览样式字符串。 |

## AutoCapitalizationMode<sup>20+</sup>枚举说明

自动大小写模式类型，只提供接口能力，具体实现以输入法应用为主。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| NONE | 0 | 默认状态无效。|
| WORDS | 1 | 按单词自动大小写。|
| SENTENCES | 2 | 按句子自动大小写。|
| ALL_CHARACTERS | 3 | 按全字符自动大小写。|

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
| selectionStart | number | 是    | 选中开始位置。<br/>取值小于0时，按0处理。 |
| selectionEnd   | number | 是    | 选中结束位置。<br/>取值大于文本长度时，按当前文本长度处理。 |
| options   | [SelectionOptions](ts-universal-attributes-text-style.md#selectionoptions12对象说明) | 否    | 选择项配置。 |

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
| [LayoutManager](ts-text-common.md#layoutmanager12) | 布局管理器对象。 |

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
| boolean | 光标是否设置成功。<br/>true表示光标设置成功，false表示设置失败。 |

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

getStyledString(): MutableStyledString

获取富文本组件显示的属性字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型    | 说明                          |
| ------- | ----------------------------- |
| [MutableStyledString](ts-universal-styled-string.md#mutablestyledstring) | 富文本组件显示的属性字符串。 |

## DecorationStyleResult<sup>12+</sup>

后端返回的文本装饰线样式信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                              | 只读 | 可选 | 说明   |
| ------- | --------------------------------- | ---- | ---- | --------------------------------- |
| type | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | 否   | 否 | 装饰线类型。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| color | [ResourceColor](ts-types.md#resourcecolor) | 否   | 否   | 装饰线颜色。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | 否   | 是   | 装饰线样式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| thicknessScale<sup>20+</sup> | number | 否   | 是   | 装饰线粗细缩放比例。<br/>默认值：1.0<br/>**说明：** 负值按默认值处理。<br/> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## LineMetrics<sup>12+</sup>

type LineMetrics = LineMetrics

用于描述文本布局中单行文字的度量信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | 用于描述文本布局中单行文字的度量信息。 |

## Affinity<sup>12+</sup>

type Affinity = Affinity

位置亲和度枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | 位置亲和度枚举。 |

## TextBox<sup>14+</sup>

type TextBox = TextBox

文本矩形区域。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [TextBox](../../apis-arkgraphics2d/js-apis-graphics-text.md#textbox) | 文本矩形区域。 |

## Paragraph<sup>20+</sup>

type Paragraph = Paragraph

保存文本内容及样式的载体，支持排版与绘制操作。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [Paragraph](../../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph) | 保存文本内容及样式的载体，支持排版与绘制操作。 |

## RectHeightStyle<sup>14+</sup>

type RectHeightStyle = RectHeightStyle

矩形区域高度规格枚举。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [RectHeightStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectheightstyle) | 矩形区域高度规格枚举。 |

## RectWidthStyle<sup>14+</sup>

type RectWidthStyle = RectWidthStyle

矩形区域宽度规格枚举。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                              | 说明   |
| --------------------------------- | --------------------------------- |
| [RectWidthStyle](../../apis-arkgraphics2d/js-apis-graphics-text.md#rectwidthstyle) | 矩形区域宽度规格枚举。 |

## TextChangeOptions<sup>15+</sup>对象说明

变化前的文本信息，以及变化后的选区范围。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| rangeBefore  | [TextRange](#textrange12) | 否   | 否 | 变化前的选区范围。 |
| rangeAfter  | [TextRange](#textrange12) | 否   | 否   | 变化后的选区范围。 |
| oldContent  | string | 否   | 否   | 变化前的文本内容。 |
| oldPreviewText | [PreviewText](#previewtext12) | 否   | 否 | 变化前的预上屏信息。 |

## EditableTextChangeValue<sup>15+</sup>

文本变化的详细信息，包括预上屏。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| content  | string | 否   | 否 | 当前的文本内容。 |
| previewText  | [PreviewText](#previewtext12) | 否   | 是   | 预上屏的内容信息。 |
| options  | [TextChangeOptions](#textchangeoptions15对象说明) | 否   | 是   | 变化的文本内容信息。 |

## TextMenuShowMode<sup>16+</sup>

菜单的显示模式。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| DEFAULT | 0 | 显示在当前窗口中。<br/>|
| PREFER_WINDOW | 1 | 优先显示在独立窗口中，若不支持独立窗口，则显示在当前窗口中。<br/>**说明：** <br/>除应用主窗口、应用子窗口、系统模态窗口及系统桌面类型的窗口外，其他类型的窗口不支持将文本选择菜单显示在独立窗口中。<br/>在预览器中不支持将文本选择菜单显示在独立窗口中。<br/>在UIExtension中不支持将文本选择菜单显示在独立窗口中。<br/>当文本类组件已经显示在子窗类型的Popup、Dialog、Toast、Menu中时，不支持将其对应的文本选择菜单显示在独立窗口中。<br/>当TextInput、TextArea可支持拉起AutoFill时，不支持将其对应的文本选择菜单显示在独立窗口中。<br/>|

## TextMenuOptions<sup>16+</sup>对象说明

菜单选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| showMode  | [TextMenuShowMode](#textmenushowmode16) | 否   | 是 | 菜单的显示模式。<br/>默认值：TextMenuShowMode.DEFAULT |

## ShaderStyle<sup>20+</sup>

文本着色器效果基类。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## LinearGradientStyle<sup>20+</sup>

显示为线性渐变。LinearGradientStyle继承自[ShaderStyle](#shaderstyle20)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型   | 只读 | 可选   | 说明  |
| ------- | ------ | ---- | ----- | ----- |
| options | [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18对象说明) | 否 | 否  | 显示为线性渐变效果。 |

### constructor<sup>20+</sup>

constructor(options: LinearGradientOptions)

用于创建LinearGradientStyle对象的构造函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| options | [LinearGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#lineargradientoptions18对象说明) | 是    | 显示为线性渐变效果。 |

## RadialGradientStyle<sup>20+</sup>

显示为径向渐变。RadialGradientStyle继承自[ShaderStyle](#shaderstyle20)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| options | [RadialGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#radialgradientoptions18对象说明) | 否  | 否 | 显示为径向渐变效果。 |

### constructor<sup>20+</sup>

constructor(options: RadialGradientOptions)

用于创建RadialGradientOptions对象的构造函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [RadialGradientOptions](../arkui-ts/ts-universal-attributes-gradient-color.md#radialgradientoptions18对象说明) | 是    | 显示为径向渐变效果。 |

## ColorShaderStyle<sup>20+</sup>

显示为纯色。ColorShaderStyle继承自[ShaderStyle](#shaderstyle20)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| color | [ResourceColor](ts-types.md#resourcecolor) | 否  | 否  | 显示为纯色效果。 |

### constructor<sup>20+</sup>

constructor(color: ResourceColor)

用于创建ResourceColor对象的构造函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| color | [ResourceColor](ts-types.md#resourcecolor) | 是    | 显示为纯色效果。 |

## IMEClient<sup>20+</sup>对象说明

输入控件绑定输入法客户端类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                    | 只读 | 可选 | 说明                                                    |
| ------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| nodeId  | number | 否  | 否 | 当前输入控件的组件UniqueId。取值范围大于等于0。 |

## TextChangeReason<sup>20+</sup>

组件内容变化原因。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ------- | ---- | ------------------- |
| UNKNOWN | 0 | 未知原因。 |
| INPUT | 1 | 用户输入。 |
| PASTE | 2 | 粘贴。 |
| CUT | 3 | 剪切。 |
| DRAG | 4 | 拖拽。 |
| AUTO_FILL | 5 | 自动填充。 |
| AI_WRITE | 6 | 小艺帮写。 |
| REDO | 7 | 重做。 |
| UNDO | 8 | 撤销。 |
| CONTROLLER | 9 | 开发者API调用。 |
| ACCESSIBILITY | 10 | 无障碍接口。 |
| COLLABORATION | 11 | 跨端拍照。 |
| STYLUS | 12 | 手写笔。 |

## MaxLinesOptions<sup>20+</sup>对象说明

配置TextArea组件，文本超长时的显示效果。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称              | 类型    | 只读 | 可选  | 说明                                                         |
| ------------------- | ------- | ------- | ------- | ------------------------------------------------------------ |
| overflowMode | [MaxLinesMode](#maxlinesmode20)  | 否  | 是 | `overflowMode`可配置TextArea组件的非内联模式。当超出设置的`maxLines`最大行数时，会启用滚动效果。需同时配置[`textOverflow`](ts-basic-components-textarea.md#textoverflow12)，且仅当`textOverflow`为None或Clip时，`MaxLinesMode`才能生效。默认情况下，`MaxLinesMode`的值为Clip，超出`maxLines`后文本会被截断。 |

## MaxLinesMode<sup>20+</sup>

TextArea组件在文本超长时显示效果。默认值为CLIP，按最大行截断显示。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                   | 值  | 说明                  |
| --------------------- | -------  | ------------------- |
| CLIP                  | 0  | 文本超长时按最大行截断显示。 |
| SCROLL                | 1  | 文本超长时可滚动显示。 |

## LineSpacingOptions<sup>20+</sup>对象说明

设置文本的行间距，是否仅在行与行之间生效。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 名称 | 类型                                                         | 只读 | 可选 | 说明             |
| ------ | ------------------------------------------------------------ | ---- | ---- | ---------------- |
| onlyBetweenLines  | boolean | 否   | 是 | 文本的行间距是否仅在行与行之间生效。<br/>当设置为true时，行间距仅适用于行与行之间，首行上方和尾行下方无额外的行间距。当设置为false时，首行上方和尾行下方均会存在行间距。<br/>默认值：false |

## TextVerticalAlign<sup>20+</sup>

文本垂直对齐的方式。默认值BASELINE，沿基线对齐。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         |  值          | 说明                  |
| --------------------- | -------------------| ------------------- |
| BASELINE |  0          | 对齐文本基线。 |
| BOTTOM   |  1          | 对齐文本底部。 |
| CENTER   |  2          | 垂直居中对齐。 |
| TOP      |  3          | 对齐文本顶部。 |

## ContentTransition<sup>20+</sup>

文本动效基类。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## NumericTextTransition<sup>20+</sup>

数字翻牌动效。仅限正整数，不支持小数和负数。不支持渐变色和Text跑马灯模式。不支持选中，[copyOption](../arkui-ts/ts-basic-components-text.md#copyoption9)属性无效。当文本存在子组件时或通过属性字符串设置时，数字翻牌失效。

NumericTextTransition继承自[ContentTransition](#contenttransition20)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                             | [FlipDirection](#flipdirection20)    | 否   | 是 | 翻牌方向。<br>默认值：FlipDirection.DOWN |
| enableBlur                                 | boolean                              | 否   | 是 | 是否开启翻牌模糊效果。<br>默认值：false<br>true：开启翻牌模糊效果。<br>false：不开启翻牌模糊效果。|

### constructor<sup>20+</sup>

constructor(options?: NumericTextTransitionOptions)

用于创建NumericTextTransition对象的构造函数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| options | [NumericTextTransitionOptions](#numerictexttransitionoptions20对象说明) | 否    | 设置数字翻牌动效。 |

## NumericTextTransitionOptions<sup>20+</sup>对象说明

数字翻牌的参数。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ------------------------------------------ | ---------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| flipDirection                              | [FlipDirection](#flipdirection20)    | 否   | 是 | 翻牌方向。<br>默认值：FlipDirection.DOWN |
| enableBlur                                 | boolean                              | 否   | 是 | 是否开启翻牌模糊效果。<br>默认值：false<br>true：开启翻牌模糊效果。<br>false：不开启翻牌模糊效果。|

## FlipDirection<sup>20+</sup>

翻牌方向。默认值为DOWN。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                   | 值  | 说明                  |
| --------------------- | -------  | ------------------- |
| DOWN                  | 0  | 内容往下翻。|
| UP                    | 1  | 内容往上翻。 |

## TextLayoutOptions对象说明<sup>20+</sup>

文本布局选项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| constraintWidth | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)  | 否 | 是 | 设置被计算文本布局宽度。若不设置则宽度为单行布局所占最大宽度值。 |
