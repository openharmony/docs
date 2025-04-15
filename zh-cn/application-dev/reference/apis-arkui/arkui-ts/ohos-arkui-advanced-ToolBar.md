# ToolBar


工具栏用于展示针对当前界面内容的操作选项，在界面底部显示。底部最多显示5个入口，超过则收纳入“更多”子项中，在最右侧显示。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 该组件不支持在Wearable设备上使用。


## 导入模块

```ts
import { SymbolGlyphModifier, DividerModifier, ToolBar, ToolBarOptions, ToolBarModifier, ItemState, LengthMetrics } from '@kit.ArkUI';
```


## 子组件

无

## 属性
不支持[通用属性](ts-component-general-attributes.md)。

## ToolBar

Toolbar({toolBarList: ToolBarOptions, activateIndex?: number, controller: TabsController, dividerModifier?: DividerModifier, toolBarModifier?: ToolBarModifier})

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                          | 类型                                                         | 必填 | 装饰器类型  | 说明                                                                                                                                                             |
| ----------------------------- | ------------------------------------------------------------ | ---- | ----------- |----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| toolBarList                   | [ToolBarOptions](#toolbaroptions)                            | 是   | @ObjectLink | 工具栏列表。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                     |
| activateIndex                 | number                                                       | 否   | @Prop       | 激活态的子项。<br/>取值范围：大于等于-1。<br/>默认值：-1，没有激活态的子项。若设置数值小于-1，按没有激活项处理。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                           |
| controller                    | [TabsController](ts-container-tabs.md#tabscontroller)        | 是   | -           | 工具栏控制器，不支持控制工具栏子项。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                         |
| dividerModifier<sup>13+</sup> | [DividerModifier](ts-universal-attributes-attribute-modifier.md) | 否   | @Prop       | 工具栏头部分割线属性，可设置分割线高度、颜色等。<br/>默认值：系统默认值。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                    |
| toolBarModifier<sup>13+</sup> | [ToolBarModifier](#toolbarmodifier13)                        | 否   | @Prop       | 工具栏属性，可设置工具栏高度、背景色、内边距（仅在工具栏子项数量小于5时生效）、是否显示按压态。<br/>默认值：<br/>工具栏高度：56vp。<br/>背景色：ohos_id_toolbar_bg。<br/>内边距：24vp。<br/>显示按压态。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |

## ToolBarOptions

继承于 Array<[ToolBarOption](#toolbaroption)>。

**装饰器类型：**\@Observed

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## ToolBarOption

**装饰器类型：**\@Observed

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                     | 类型                                                        | 必填 | 说明                                                                                                                                                                                                                                                     |
|----------------------------------------|-----------------------------------------------------------| -------- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| content                                | [ResourceStr](ts-types.md#resourcestr)                    | 是 | 工具栏子项的文本。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                          |
| action                                 | ()&nbsp;=&gt;&nbsp;void                                   | 否 | 工具栏子项点击事件。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                         |
| icon                                   | [Resource](ts-types.md#resource)                          | 否 | 工具栏子项的图标。<br/>toolBarSymbolOptions有传入参数时，icon不生效。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                  |
| state                                  | [ItemState](#itemstate)                                   | 否 | 工具栏子项的状态。<br/>默认为ENABLE。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                           |
| iconColor<sup>13+</sup>                | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项的图标填充颜色。<br/>默认值为$r('sys.color.icon_primary')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                                |
| activatedIconColor<sup>13+</sup>       | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项激活态的图标填充颜色。<br/>默认值为$r('sys.color.icon_emphasize')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                           |
| textColor<sup>13+</sup>                | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项的文本颜色。<br/>默认值为$r('sys.color.font_primary')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                                  |
| activatedTextColor<sup>13+</sup>       | [ResourceColor](ts-types.md#resourcecolor)                | 否 | 工具栏子项激活态的文本颜色。<br/>默认值为$r('sys.color.font_emphasize')。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                             |
| toolBarSymbolOptions<sup>13+</sup>     | [ToolBarSymbolGlyphOptions](#toolbarsymbolglyphoptions13) | 否 | 工具栏子项的图标属性，symbol类型。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                                                               |
| accessibilityText<sup>18+</sup>        | [ResourceStr](ts-types.md#resourcestr)                    | 否 | 工具栏子项的无障碍文本属性。当组件不包含文本属性时，屏幕朗读选中此组件时不播报，使用者无法清楚地知道当前选中了什么组件。为了解决此场景，开发人员可为不包含文字信息的组件设置无障碍文本，当屏幕朗读选中此组件时播报无障碍文本的内容，帮助屏幕朗读的使用者清楚地知道自己选中了什么组件。<br/>默认值为当前项content属性内容。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                             |
| accessibilityDescription<sup>18+</sup> | [ResourceStr](ts-types.md#resourcestr)                    | 否 | 工具栏子项的无障碍描述。此描述用于向用户详细解释当前组件，开发人员应为组件的这一属性提供较为详尽的文本说明，以协助用户理解即将执行的操作及其可能产生的后果。特别是当这些后果无法仅从组件的属性和无障碍文本中直接获知时。如果组件同时具备文本属性和无障碍说明属性，当组件被选中时，系统将首先播报组件的文本属性，随后播报无障碍说明属性的内容。<br/>默认值为“单指双击即可执行”。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                                                                                    |
| accessibilityLevel<sup>18+</sup>       | string                                                    | 否 | 工具栏子项无障碍重要性。用于控制当前项是否可被无障碍辅助服务所识别。<br/>支持的值为：<br/>"auto"：当前组件会转换'yes'。<br/>"yes"：当前组件可被无障碍辅助服务所识别。<br/>"no"：当前组件不可被无障碍辅助服务所识别。<br/>"no-hide-descendants"：当前组件及其所有子组件不可被无障碍辅助服务所识别。<br/>默认值："auto"。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

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
不支持[通用事件](ts-component-general-events.md)。

## 示例

### 示例1（工具栏不同状态的默认效果）
该示例展示了工具栏子项state属性分别设置ENABLE、DISABLE、ACTIVATE状态的不同显示效果。
```ts
import { ToolBar, ToolBarOptions, ItemState } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions();

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
      state: ItemState.DISABLE
    })
    this.toolbarList.push({
      content: '粘贴',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state: ItemState.ACTIVATE
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
      }
      .align(Alignment.Bottom)
      .width('100%')
      .height('100%')
    }
  }
}
```

![zh-cn_image_toolbar_example01](figures/zh-cn_image_toolbar_example01.png)

### 示例2（设置工具栏自定义样式）
该示例通过设置属性ToolBarModifier自定义工具栏高度、背景色、按压效果等样式。
```ts
import {
  SymbolGlyphModifier,
  DividerModifier,
  ToolBar,
  ToolBarOptions,
  ToolBarModifier,
  ItemState,
  LengthMetrics,
} from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions();
  // 自定义工具栏样式
  private toolBarModifier: ToolBarModifier =
    new ToolBarModifier().height(LengthMetrics.vp(52)).backgroundColor(Color.Transparent).stateEffect(false);
  @State dividerModifier: DividerModifier = new DividerModifier().height(0);

  aboutToAppear() {
    // 添加工具栏子项
    this.toolbarList.push({
      content: 'Long long long long long long long long text',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
      state: ItemState.ACTIVATE,
      toolBarSymbolOptions: {
        normal: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Green]), // 普通态symbol图标
        activated: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]), // 激活态symbol图标
      },
      activatedTextColor: $r('sys.color.font_primary'),
    })
    this.toolbarList.push({
      content: 'Copy',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state: ItemState.DISABLE,
      iconColor: '#ff18cb53',
      activatedIconColor: '#ffec5d5d', // 激活态icon颜色
      activatedTextColor: '#ffec5d5d', // 激活态文本颜色
    })
    this.toolbarList.push({
      content: 'Paste',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state: ItemState.ACTIVATE,
      textColor: '#ff18cb53',
    })
    this.toolbarList.push({
      content: 'All',
      icon: $r('sys.media.ohos_ic_public_select_all'),
      action: () => {
      },
      state: ItemState.ACTIVATE,
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
      }
      .align(Alignment.Bottom)
      .width('100%')
      .height('100%')
    }
  }
}
```

![zh-cn_image_toolbar_example02](figures/zh-cn_image_toolbar_example02.png)


### 示例3（设置工具栏自定义播报）
该示例通过设置工具栏子项属性accessibilityText、accessibilityDescription、accessibilityLevel自定义屏幕朗读播报文本。
```ts
import { ToolBar, ToolBarOptions, ItemState } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions();

  aboutToAppear() {
    // 添加工具栏子项
    this.toolbarList.push({
      content: '剪贴我是超超超超超超超超超长样式',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
      accessibilityText: '剪贴', // 该项屏幕朗读播报文本为‘剪贴’
      accessibilityDescription: '单指双击即可剪贴', // 该项屏幕朗读播报描述为'单指双击即可剪贴'
      accessibilityLevel: 'yes' // 该项可被无障碍屏幕朗读聚焦
    })
    this.toolbarList.push({
      content: '拷贝',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state: ItemState.DISABLE,
      accessibilityLevel: 'no' // 该项将无法被屏幕朗读服务所识别，屏幕朗读不可聚焦
    })
    this.toolbarList.push({
      content: '粘贴',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state: ItemState.ACTIVATE
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
      }
      .align(Alignment.Bottom)
      .width('100%')
      .height('100%')
    }
  }
}
```
![zh-cn_image_toolbar_example01](figures/zh-cn_image_toolbar_example01.png)
