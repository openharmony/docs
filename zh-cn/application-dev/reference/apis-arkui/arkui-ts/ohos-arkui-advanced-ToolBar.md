# ToolBar


工具栏用于展示针对当前界面内容的操作选项，在界面底部显示。底部最多显示5个入口，超过则收纳入“更多”子项中，在最右侧显示。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```ts
import { SymbolGlyphModifier, DividerModifier, ToolBar, ToolBarOptions, ToolBarModifier, ItemState, LengthMetrics } from '@kit.ArkUI';
```


## 子组件

无

## 属性
支持[通用属性](ts-universal-attributes-size.md)

## ToolBar

Toolbar({toolBarList: ToolBarOptions, activateIndex?: number, controller: TabsController, dividerModifier: DividerModifier, toolBarModifier: ToolBarModifier})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                          | 类型                                                         | 必填 | 装饰器类型  | 说明                                                         |
| ----------------------------- | ------------------------------------------------------------ | ---- | ----------- | ------------------------------------------------------------ |
| toolBarList                   | [ToolBarOptions](#toolbaroptions)                            | 是   | @ObjectLink | 工具栏列表。                                                 |
| activateIndex                 | number                                                       | 否   | @Prop       | 激活态的子项。<br/>默认值：-1。                              |
| controller                    | [TabsController](ts-container-tabs.md#tabscontroller)        | 是   | -           | 工具栏控制器。                                               |
| dividerModifier<sup>13+</sup> | [DividerModifier](ts-universal-attributes-attribute-modifier.md) | 否   | @Prop       | 工具栏头部分割线属性，可设置分割线高度、颜色等。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| toolBarModifier<sup>13+</sup> | [ToolBarModifier](#toolbarmodifier13)                        | 否   | @Prop       | 工具栏属性，可设置工具栏高度、背景色、内边距（仅在工具栏子项数量小于5时生效）、是否显示按压态。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |

## ToolBarOptions

继承于 Array<[ToolBarOption](#toolbaroption)>。

**装饰器类型：**\@Observed

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## ToolBarOption

**装饰器类型：**\@Observed

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                 | 类型                                                        | 必填 | 说明                                                                                                           |
|------------------------------------|-----------------------------------------------------------| -------- |--------------------------------------------------------------------------------------------------------------|
| content                            | [ResourceStr](ts-types.md#resourcestr)                    | 是 | 工具栏子项的文本。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                |
| action                             | ()&nbsp;=&gt;&nbsp;void                                   | 否 | 工具栏子项点击事件。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                               |
| icon                               | [Resource](ts-types.md#resource)                          | 否 | 工具栏子项的图标。<br/>toolBarSymbolOptions有传入参数时，icon不生效。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。        |
| state                              | [ItemState](#itemstate)                                   | 否 | 工具栏子项的状态。<br/>默认为ENABLE。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |
| iconColor<sup>13+</sup>            | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项的图标填充颜色。<br/>默认值为$r('sys.color.icon_primary')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。      |
| activatedIconColor<sup>13+</sup>   | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项激活态的图标填充颜色。<br/>默认值为$r('sys.color.icon_emphasize')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| textColor<sup>13+</sup>            | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项的文本颜色。<br/>默认值为$r('sys.color.font_primary')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。        |
| activatedTextColor<sup>13+</sup>   | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项激活态的文本颜色。<br/>默认值为$r('sys.color.font_emphasize')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。   |
| toolBarSymbolOptions<sup>13+</sup> | [ToolBarSymbolGlyphOptions](#toolbarsymbolglyphoptions13) | 否 | 工具栏子项的图标属性，symbol类型。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                     |

## ToolBarModifier<sup>13+</sup>
ToolBarModifier提供设置工具栏高度(height)、背景色(backgroundColor)、左右内边距（padding，仅在item小于5个时生效）、是否显示按压态（stateEffect）的方法。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

### backgroundColor

backgroundColor(backgroundColor: ResourceColor): ToolBarModifier

自定义绘制工具栏背景色的接口，若重载该方法则可进行工具栏背景色的自定义绘制。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                   | 必填 | 说明                                                               |
| ------- | ------------------------------------------------------ | ---- |------------------------------------------------------------------|
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 是   | 工具栏背景色。<br/>默认背景色为$r('sys.color.ohos_id_color_toolbar_bg')。 |

### padding

padding(padding: LengthMetrics): ToolBarModifier

自定义绘制工具栏左右内边距的接口，若重载该方法则可进行工具栏左右内边距的自定义绘制。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填 | 说明                                                                                  |
| ------- |--------| ---- |-------------------------------------------------------------------------------------|
| padding | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 是   | 工具栏左右内边距，仅在item小于5个时生效。<br/>工具栏默认在item小于5个时padding为24vp，大于等于5个时为0。 |

### height

height(height: LengthMetrics): ToolBarModifier

自定义绘制工具栏高度的接口，若重载该方法则可进行工具栏高度的自定义绘制，此高度不包含分割线高度。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                 |
| ------- |---------------------------------| ---- |------------------------------------|
| height | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 是   | 工具栏高度。<br/>工具栏高度默认为56vp（不包含分割线）。 |

### stateEffect

stateEffect(stateEffect: boolean): ToolBarModifier

设置是否显示按压态效果的接口。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                             | 必填 | 说明                                                       |
| ------- |--------------------------------| ---- |----------------------------------------------------------|
| stateEffect | boolean | 是   | 工具栏是否显示按压态效果。<br/>true为显示按压态效果，false为移除按压态效果，默认为true。 |

## ItemState

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ENABLE | 1 | 工具栏子项为正常可点击状态。 |
| DISABLE | 2 | 工具栏子项为不可点击状态。 |
| ACTIVATE | 3 | 工具栏子项为激活状态，可点击。 |

## ToolBarSymbolGlyphOptions<sup>13+</sup>

ToolBarSymbolGlyphOptions定义图标的属性。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型       | 必填 | 说明                                                                                       |
| ------ | ---------- | ---- |------------------------------------------------------------------------------------------|
| normal | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 工具栏symbol图标普通态样式。<br/>默认值：fontColor：$r('sys.color.icon_primary')，fontSize：24vp。  |
| activated| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 工具栏symbol图标激活态样式。<br/>默认值：fontColor：$r('sys.color.icon_emphasize')，fontSize：24vp。 |

## 事件
支持[通用事件](ts-universal-events-click.md)

## 示例1(基础用法)

```ts
import { ToolBar, ToolBarOptions, ItemState } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions()
  aboutToAppear() {
    this.toolbarList.push({
      content: '剪贴我是超超超超超超超超超长样式',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: '拷贝',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state:ItemState.DISABLE
    })
    this.toolbarList.push({
      content: '粘贴',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state:ItemState.ACTIVATE
    })
    this.toolbarList.push({
      content: '全选',
      icon: $r('sys.media.ohos_ic_public_select_all'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: '分享',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: '分享',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
  }
  build() {
    Row() {
      Stack() {
        Column() {
          ToolBar({
            activateIndex: 2,
            toolBarList: this.toolbarList,
          })
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![zh-cn_image_toolbar_example01](figures/zh-cn_image_toolbar_example01.png)

## 示例2(设置工具栏自定义样式)
```ts
import { SymbolGlyphModifier, DividerModifier, ToolBar, ToolBarOptions, ToolBarModifier, ItemState, LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions();
  private toolBarModifier: ToolBarModifier =
  new ToolBarModifier().height(LengthMetrics.vp(52)).backgroundColor(Color.Transparent).stateEffect(false);
  @State dividerModifier: DividerModifier = new DividerModifier().height(0);

  aboutToAppear() {
    this.toolbarList.push({
      content: 'Long long long long long long long long text',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
      state: ItemState.ACTIVATE,
      toolBarSymbolOptions: {
        normal: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Green]),
        activated: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]),
      },
      activatedTextColor: $r('sys.color.font_primary'),
    })
    this.toolbarList.push({
      content: 'Copy',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state:ItemState.DISABLE,
      iconColor: '#ff18cb53',
      activatedIconColor: '#ffec5d5d',
      activatedTextColor: '#ffec5d5d',
    })
    this.toolbarList.push({
      content: 'Paste',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state:ItemState.ACTIVATE,
      textColor: '#ff18cb53',
    })
    this.toolbarList.push({
      content: 'All',
      icon: $r('sys.media.ohos_ic_public_select_all'),
      action: () => {
      },
      state:ItemState.ACTIVATE,
    })
    this.toolbarList.push({
      content: '分享',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: '分享',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
  }
  build() {
    Row() {
      Stack() {
        Column() {
          ToolBar({
            toolBarModifier: this.toolBarModifier,
            dividerModifier: this.dividerModifier,
            activateIndex: 0,
            toolBarList: this.toolbarList,
          })
            .height(52)
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![zh-cn_image_toolbar_example02](figures/zh-cn_image_toolbar_example02.png)
