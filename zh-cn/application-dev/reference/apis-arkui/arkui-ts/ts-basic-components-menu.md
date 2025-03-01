# Menu

以垂直列表形式显示的菜单。

> **说明：**
>
> - 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - Menu组件需和[bindMenu](ts-universal-attributes-menu.md#bindmenu)或[bindContextMenu](ts-universal-attributes-menu.md#bindcontextmenu8)方法配合使用，不支持作为普通组件单独使用。

## 子组件

包含[MenuItem](ts-basic-components-menuitem.md)、[MenuItemGroup](ts-basic-components-menuitemgroup.md)子组件。

## 接口

Menu()

作为菜单的固定容器，无参数。

> **说明:** 
>
> 菜单和菜单项宽度计算规则：
>
> 布局过程中，期望每个菜单项的宽度一致。若子组件设置了宽度，则以[尺寸计算规则](ts-universal-attributes-size.md#constraintsize)为准。
>
> 不设置宽度的情况：菜单组件会对子组件MenuItem、MenuItemGroup设置默认2栅格的宽度，若菜单项内容区比2栅格宽，则会自适应撑开。
>
> 设置宽度的情况：菜单组件会对子组件MenuItem、MenuItemGroup设置减去padding后的固定宽度。
>
> 设置Menu边框[width](ts-universal-attributes-size.md#width)时，支持设置的最小宽度为64vp。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### fontSize<sup>(deprecated)</sup>

fontSize(value: Length)

统一设置Menu中所有文本的尺寸。

从API Version 10开始废弃，建议使用[font](#font10)代替。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                         | 必填 | 说明                                                     |
| ------ | ---------------------------- | ---- | -------------------------------------------------------- |
| value  | [Length](ts-types.md#length) | 是   | Menu中所有文本的尺寸，Length为number类型时，使用fp单位。 |

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
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | Menu中所有文本的颜色。<br/>默认值：'#E5000000' |

### radius<sup>10+</sup>

radius(value: Dimension | BorderRadiuses)

设置Menu边框圆角半径。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;[BorderRadiuses](ts-types.md#borderradiuses9) | 是   | Menu边框圆角半径。<br/>默认值：2in1设备上默认值为8vp，其他设备上默认值为20vp。<br/> 从API version 12开始，当水平方向两个圆角半径之和的最大值大于菜单宽度，或垂直方向两个圆角半径之和的最大值大于菜单高度时，菜单四个圆角均采用菜单默认圆角半径值。 |

### menuItemDivider<sup>12+</sup>

menuItemDivider(options: DividerStyleOptions | undefined)

设置menuItem分割线样式, 不设置该属性则不展示分割线。

startMargin + endMargin 超过组件宽度后startMargin和endMargin会被置0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                     | 必填         | 说明           |
|---------|--------------------------------------------------------|------------| -------------- |
| options | [DividerStyleOptions](ts-types.md#dividerstyleoptions12)&nbsp;\| &nbsp;undefined | 是   | 设置menuItem分割线样式。<br />-strokeWidth:分割线的线宽。<br />-color：分割线的颜色。<br />-startMargin：分割线与menuItem侧边起端的距离。<br />-endMargin：分割线与menuItem侧边结束端的距离。 |

### menuItemGroupDivider<sup>12+</sup>

menuItemGroupDivider(options: DividerStyleOptions | undefined)

设置menuItemGroup上下分割线的样式, 不设置该属性则默认展示分割线。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                     | 必填         | 说明           |
|---------|--------------------------------------------------------|------------| -------------- |
| options | [DividerStyleOptions](ts-types.md#dividerstyleoptions12)&nbsp;\| &nbsp;undefined | 是   | 设置menuItemGroup顶部和底部分割线样式。<br />-strokeWidth:分割线的线宽, 默认值是1px。<br />-color：分割线的颜色, 默认值是 #33000000。<br />-startMargin：分割线与menuItemGroup侧边起端的距离, 默认值是16。<br />-endMargin：分割线与menuItemGroup侧边结束端的距离, 默认值是16。 |

### subMenuExpandingMode<sup>12+</sup>

subMenuExpandingMode(mode: SubMenuExpandingMode)

设置Menu子菜单展开样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- |--------------|
| mode  | [SubMenuExpandingMode](#submenuexpandingmode12枚举说明) | 是   | Menu子菜单展开样式。<br/>默认值：SubMenuExpandingMode.SIDE_EXPAND  |

## SubMenuExpandingMode<sup>12+</sup>枚举说明

Menu子菜单展开样式枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 值 | 说明                                       |
| --------------- | - | ------------------------------------------ |
| SIDE_EXPAND     | 0 | 默认展开样式, 子菜单位于同一平面侧边展开。 |
| EMBEDDED_EXPAND | 1 | 直接展开样式, 子菜单嵌于主菜单内展开。     |
| STACK_EXPAND    | 2 | 堆叠样式, 子菜单浮于主菜单上方展开。       |

## 示例

### 示例1（设置多级菜单）

该示例通过配置MenuItem中的builder参数实现多级菜单。

```ts
@Entry
@Component
struct Index {
  @State select: boolean = true
  private iconStr: ResourceStr = $r("app.media.view_list_filled")
  private iconStr2: ResourceStr = $r("app.media.arrow_right_filled")

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