# Menu
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Armstrong15-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

以垂直列表形式显示的菜单。

> **说明：**
>
> - 该组件从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - Menu组件需和[bindMenu](ts-universal-attributes-menu.md#bindmenu)或[bindContextMenu](ts-universal-attributes-menu.md#bindcontextmenu8)方法配合使用，不支持作为普通组件单独使用。

## 子组件

包含[MenuItem](ts-basic-components-menuitem.md)、[MenuItemGroup](ts-basic-components-menuitemgroup.md)子组件。

## 接口

Menu()

作为菜单的固定容器，无参数。

> **说明：** 
>
> 菜单和菜单项宽度计算规则：
>
> 布局过程中，期望每个菜单项的宽度一致。若子组件设置了宽度，则以[尺寸计算规则](ts-universal-attributes-size.md#constraintsize)为准。
>
> Menu不设置宽度的情况：Menu会对子组件MenuItem、MenuItemGroup设置默认2栅格的宽度，若菜单项内容区比2栅格宽，则会自适应撑开。
>
> Menu设置宽度的情况：Menu会对子组件MenuItem、MenuItemGroup设置减去padding后的固定宽度。
>
> Menu支持设置的最小宽度为64vp。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### font<sup>10+</sup>

font(value: Font)

统一设置Menu中所有文本的尺寸。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                     | 必填 | 说明                                                         |
| ------ | ------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Font](ts-types.md#font) | 是   | Menu中所有文本的尺寸。<br/>默认值：<br/>{<br/>      size: 16,<br/>      family: 'HarmonyOS Sans',<br/>      weight: FontWeight.Medium,<br/>      style: FontStyle.Normal<br/>} |
### fontColor<sup>10+</sup>

fontColor(value: ResourceColor)

统一设置Menu中所有文本的颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                   |
| ------ | ------------------------------------------ | ---- | ---------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | Menu中所有文本的颜色。 |

### radius<sup>10+</sup>

radius(value: Dimension | BorderRadiuses)

设置Menu边框圆角半径。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[BorderRadiuses](ts-types.md#borderradiuses9) | 是   | Menu边框圆角半径。<br/>默认值：2in1设备上默认值为8vp，其他设备上默认值为20vp。<br/> 从API version 12开始，当水平方向两个圆角半径之和的最大值大于菜单宽度，或垂直方向两个圆角半径之和的最大值大于菜单高度时，菜单四个圆角均采用菜单默认圆角半径值。<br/>当设置Dimension类型且传参为异常值时，菜单圆角取默认值。<br/>当设置BorderRadiuses类型且传参为异常值时，菜单默认没有圆角。 |

### menuItemDivider<sup>12+</sup>

menuItemDivider(options: DividerStyleOptions | undefined)

设置menuItem分割线样式，不设置该属性则不展示分割线。

startMargin + endMargin 超过组件宽度后startMargin和endMargin会被置0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                     | 必填         | 说明           |
|---------|--------------------------------------------------------|------------| -------------- |
| options | [DividerStyleOptions](ts-types.md#dividerstyleoptions12)&nbsp;\| &nbsp;undefined | 是   | 设置menuItem分割线样式。<br />-strokeWidth：分割线的线宽。<br />-color：分割线的颜色。<br />-startMargin：分割线与menuItem侧边起始端的距离。<br />-endMargin：分割线与menuItem侧边结束端的距离。<br />-mode：分割线的模式，默认值为FLOATING_ABOVE_MENU。 |

### menuItemGroupDivider<sup>12+</sup>

menuItemGroupDivider(options: DividerStyleOptions | undefined)

设置menuItemGroup上下分割线的样式，不设置该属性则默认展示分割线。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                     | 必填         | 说明           |
|---------|--------------------------------------------------------|------------| -------------- |
| options | [DividerStyleOptions](ts-types.md#dividerstyleoptions12)&nbsp;\| &nbsp;undefined | 是   | 设置menuItemGroup顶部和底部分割线样式。<br />-strokeWidth：分割线的线宽，默认值是1px。<br />-color：分割线的颜色，默认值是 #33000000。<br />-startMargin：分割线与menuItemGroup侧边起始端的距离，默认为16vp，单位为vp。<br />-endMargin：分割线与menuItemGroup侧边结束端的距离，默认为16vp，单位为vp。<br />-mode：分割线的模式，默认值为FLOATING_ABOVE_MENU。 |

### subMenuExpandingMode<sup>12+</sup>

subMenuExpandingMode(mode: SubMenuExpandingMode)

设置Menu子菜单展开样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- |--------------|
| mode  | [SubMenuExpandingMode](#submenuexpandingmode12枚举说明) | 是   | Menu子菜单展开样式。<br/>默认值：SubMenuExpandingMode.SIDE_EXPAND  |

### subMenuExpandSymbol<sup>20+</sup>

subMenuExpandSymbol(symbol: SymbolGlyphModifier)

设置Menu子菜单展开符号。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- |--------------|
| symbol  | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md)| 是   | Menu子菜单展开符号。<br/>1、子菜单的展开样式为SubMenuExpandingMode.SIDE_EXPAND时，不显示展开符号。<br/>2、子菜单的展开样式为SubMenuExpandingMode.EMBEDDED_EXPAND时，展开时展开符号会顺时针旋转180°。<br/>默认值：`$r('sys.symbol.chevron_down').fontSize('24vp')` <br/>3、子菜单的展开样式为SubMenuExpandingMode.STACK_EXPAND时，展开时展开符号会顺时针旋转90°。<br/>默认值：`$r('sys.symbol.chevron_forward').fontSize('20vp').padding('2vp')`  |

### fontSize<sup>(deprecated)</sup>

fontSize(value: Length)

统一设置Menu中所有文本的尺寸。

从API Version 10开始废弃，建议使用[font](#font10)代替。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                         | 必填 | 说明                                                         |
| ------ | ---------------------------- | ---- | ------------------------------------------------------------ |
| value  | [Length](ts-types.md#length) | 是   | Menu中所有文本的尺寸，Length为number类型时，使用fp单位。不支持设置百分比。 |

## SubMenuExpandingMode<sup>12+</sup>枚举说明

Menu子菜单展开样式枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 值   | 说明                                       |
| --------------- | ---- | ------------------------------------------ |
| SIDE_EXPAND     | 0    | 默认展开样式，子菜单位于同一平面侧边展开。 |
| EMBEDDED_EXPAND | 1    | 直接展开样式，子菜单嵌于主菜单内展开。     |
| STACK_EXPAND    | 2    | 堆叠样式，子菜单浮于主菜单上方展开。       |

## 示例

### 示例1（设置多级菜单）

该示例通过配置MenuItem中的builder参数实现多级菜单。

```ts
@Entry
@Component
struct Index {
  @State select: boolean = true;
  // $r('app.media.xxx')需要替换为开发者所需的图像资源文件。
  private iconStr: ResourceStr = $r("app.media.view_list_filled");
  private iconStr2: ResourceStr = $r("app.media.arrow_right_filled");

  @Builder
  SubMenu() {
    Menu() {
      MenuItem({ content: "复制", labelInfo: "Ctrl+C" })
      MenuItem({ content: "粘贴", labelInfo: "Ctrl+V" })
    }
  }

  @Builder
  MyMenu(){
    Menu() {
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })
        .enabled(false)
      MenuItem({
        startIcon: this.iconStr,
        content: "菜单选项",
        endIcon: this.iconStr2,
        builder: ():void=>this.SubMenu()
      })
      MenuItemGroup({ header: '小标题' }) {
        MenuItem({
          startIcon: this.iconStr,
          content: "菜单选项",
          endIcon: this.iconStr2,
          builder: ():void=>this.SubMenu()
        })
        MenuItem({
          startIcon: $r("app.media.app_icon"),
          content: "菜单选项",
          endIcon: this.iconStr2,
          builder: ():void=>this.SubMenu()
        })
      }
      MenuItem({
        startIcon: this.iconStr,
        content: "菜单选项",
      })
    }
  }

  build() {
    Row() {
      Column() {
        Text('click to show menu')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .bindMenu(this.MyMenu)
      .width('100%')
    }
    .height('100%')
  }
}
```

![menu](figures/menu.png)

### 示例2（设置symbol类型图标）

该示例通过配置symbolStartIcon、symbolEndIcon实现symbol类型图标的菜单。

```ts
// xxx.ets
import { SymbolGlyphModifier } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State startIconModifier: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_mic')).fontSize('24vp');
  @State endIconModifier: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_trash')).fontSize('24vp');
  @State selectIconModifier: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.checkmark')).fontSize('24vp');
  @State select: boolean = true;

  @Builder
  SubMenu() {
    Menu() {
      MenuItem({ content: "复制", labelInfo: "Ctrl+C" })
      MenuItem({ content: "粘贴", labelInfo: "Ctrl+V" })
    }
  }

  @Builder
  MyMenu() {
    Menu() {
      MenuItem({ symbolStartIcon: this.startIconModifier, content: "菜单选项" })
      MenuItem({ symbolStartIcon: this.startIconModifier, content: "菜单选项" })
        .enabled(false)
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        content: "菜单选项",
        symbolEndIcon: this.endIconModifier,
        builder: (): void => this.SubMenu()
      })
      MenuItemGroup({ header: '小标题' }) {
        MenuItem({
          symbolStartIcon: this.startIconModifier,
          content: "菜单选项",
          symbolEndIcon: this.endIconModifier,
          builder: (): void => this.SubMenu()
        })
        MenuItem({
          symbolStartIcon: this.startIconModifier,
          content: "菜单选项",
          symbolEndIcon: this.endIconModifier,
          builder: (): void => this.SubMenu()
        })
      }
      MenuItem({
        content: "菜单选项",
      }).selected(this.select).selectIcon(this.selectIconModifier)
    }
  }

  build() {
    Row() {
      Column() {
        Text('click to show menu')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .bindMenu(this.MyMenu)
      .width('100%')
    }
    .height('100%')
  }
}
```

![zh-cn_image_0000001174582862](figures/normal-symbol.png)

### 示例3（设置Menu子菜单展开符号）

该示例通过配置subMenuExpandSymbol实现对Menu子菜单展开符号配置颜色。

```ts
import { SymbolGlyphModifier } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State startIconModifier: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_star'))
  @State endIconModifier: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_mic'))
  @State expandSymbolModifier: SymbolGlyphModifier =
    new SymbolGlyphModifier($r('sys.symbol.chevron_down')).fontColor([Color.Red]).fontSize('24vp')

  @Builder
  SubMenu() {
    Menu() {
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        content: "图标"
      })
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        content: "列表"
      })
    }.backgroundColor(Color.Grey)
  }

  @Builder
  MyMenu() {
    Menu() {
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        symbolEndIcon: this.endIconModifier,
        content: "新建文件夹",
        builder: (): void => this.SubMenu(),
      })
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        content: "排序方式",
        builder: (): void => this.SubMenu(),
      })
      MenuItem({
        symbolStartIcon: this.startIconModifier,
        content: "查看方式",
        builder: (): void => this.SubMenu(),
      })
    }
    .subMenuExpandingMode(SubMenuExpandingMode.EMBEDDED_EXPAND)
    .backgroundColor(Color.Grey)
    .subMenuExpandSymbol(this.expandSymbolModifier)
  }

  build() {
    Button('click to show menu')
      .position({ top: 40, left: 40 })
      .bindMenu(this.MyMenu)
  }
}
```

![image](figures/menu-arrow.gif)

### 示例4（设置分割线样式）

该示例通过设置menuItemGroupDivider属性实现分割线样式。

```ts
import { LengthMetrics } from '@kit.ArkUI'

@Entry
@Component
struct Index {

  @Builder
  MyMenu() {
    Menu() {
      MenuItem({ content: "Item Content" })
      MenuItem({ content: "Item Content" })
      MenuItem({ content: "Item Content" })
      MenuItemGroup() {
        MenuItem({ content: "Group Child" })
        MenuItem({ content: "Group Child" })
      }
      MenuItem({ content: "Item Content" })
    }
    .menuItemDivider({
      strokeWidth: LengthMetrics.vp(5),
      color: '#d5d5d5',
      mode: DividerMode.EMBEDDED_IN_MENU
    })
    .menuItemGroupDivider({
      strokeWidth: LengthMetrics.vp(5),
      color: '#707070',
      mode: DividerMode.EMBEDDED_IN_MENU
    })
  }

  build() {
    RelativeContainer() {
      Button("show menu")
        .bindMenu(this.MyMenu())
    }
    .height('100%')
    .width('100%')
  }
}
```

![dividerStyleMode](figures/MenudividerStyleMode.png)