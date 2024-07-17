# 文本组件公共接口

>**说明：**
>
>文本类组件公共接口。
>本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CaretStyle<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 参数名 | 参数类型                                   | 必填 | 参数描述 |
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

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| number | 组件内容的总行数。 |

### getGlyphPositionAtCoordinate

getGlyphPositionAtCoordinate(x: number, y: number): PositionWithAffinity

获取较为接近给定坐标的字形的位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| x | number | 是    | 相对于组件的横坐标，单位px |
| y | number | 是    | 相对于组件的纵坐标，单位px |

**返回值：**

| 类型                                          | 说明        |
| --------------------------------------------- | ----------- |
| [PositionWithAffinity](#positionwithaffinity) | 字形位置信息。|

### getLineMetrics

getLineMetrics(lineNumber: number): LineMetrics

获取指定行的行信息、文本样式信息、以及字体属性信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名    | 类型   | 必填   | 说明                 |
| ------ | ------ | ---- | -------------------- |
| lineNumber | number | 是    | 行号。从0开始。 |

**返回值：**

| 类型                                       | 说明       |
| ---------------------------------------- | -------- |
| [LineMetrics](../../apis-arkgraphics2d/js-apis-graphics-text.md#linemetrics) | 行信息、文本样式信息、以及字体属性信息。 |

## PositionWithAffinity

位置以及亲和度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型                   | 只读 | 必填 | 说明                      |
| --------- | --------------------- | ---- | ---- | ------------------------ |
| position  | number                | 是   | 是   | 字形相对于组件内容的索引，整数。  |
| affinity  | [Affinity](../../apis-arkgraphics2d/js-apis-graphics-text.md#affinity) | 是   | 是   | 位置亲和度。             |

## TextMenuItemId<sup>12+</sup>

菜单的Id值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型              | 只读   | 必填   | 说明     |
| ------------ |---------------------| ---- | ---- | ------ |
| CUT  | [TextMenuItemId](#textmenuitemid12) |  是  |  否  | 默认裁剪。 |
| COPY  | [TextMenuItemId](#textmenuitemid12) |  是  |  否  | 默认复制。 |
| PASTE | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 默认粘贴。 |
| SELECT_ALL   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 默认全选。 |
| COLLABORATION_SERVICE   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 互通服务。 |
| CAMERA_INPUT   | [TextMenuItemId](#textmenuitemid12)   | 是    | 否    | 拍摄输入。 |

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

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| id | [TextMenuItemId](#textmenuitemid12) | 是   | TextMenuItemId的id。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| boolean | 两个TextMenuItemId是否相等。 |

## TextMenuItem对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| content | [ResourceStr](ts-types.md#resourcestr) | 是   | 菜单名称。 |
| icon | [ResourceStr](ts-types.md#resourcestr) | 否   | 菜单图标。<br/>不支持网络图片。 |
| id | [TextMenuItemId](#textmenuitemid12) | 是   | 菜单id。 |

## EditMenuOptions对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onCreateMenu

onCreateMenu(menuItems: Array\<TextMenuItem>): Array\<TextMenuItem>

菜单数据模版编辑能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItems | Array<[TextMenuItem](#textmenuitem对象说明)> | 是   | 菜单项。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| Array\<[TextMenuItem](#textmenuitem对象说明)> | 设置的菜单项。 |

### onMenuItemClick

onMenuItemClick(menuItem: TextMenuItem, range: TextRange): boolean

菜单项功能函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明   |
| ------- | --------------------------------- | ---- | --------------------------------- |
| menuItem | [TextMenuItem](#textmenuitem对象说明) | 是   | 菜单项。 |
| range | [TextRange](ts-universal-attributes-text-style.md#textrange12) | 是   | 选中的文本信息。 |

**返回值：**

| 类型              |       说明       |
| ------- | --------------------------------- | 
| boolean | 菜单项的执行逻辑。<br/>返回为true，拦截系统默认逻辑，仅执行自定义逻辑。<br/>返回为false，先执行自定义逻辑，再执行系统逻辑。 |