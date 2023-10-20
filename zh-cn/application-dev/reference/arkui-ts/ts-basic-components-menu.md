# Menu

以垂直列表形式显示的菜单。

> **说明：**
>
> - 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - Menu组件需和[bindMenu](ts-universal-attributes-menu.md)或[bindContextMenu](ts-universal-attributes-menu.md)方法配合使用，不支持作为普通组件单独使用。

## 子组件

包含[MenuItem](ts-basic-components-menuitem.md)、[MenuItemGroup](ts-basic-components-menuitemgroup.md)子组件。

## 接口

Menu()

作为菜单的固定容器，无参数。

> **说明:**
> 菜单和菜单项宽度计算规则：
>
> 布局过程中，期望每个菜单项的宽度一致。若子组件设置了宽度，则以[尺寸计算规则](ts-universal-attributes-size.md#constraintsize取值对widthheight影响)为准。
>
> 不设置宽度的情况：菜单组件会对子组件MenuItem、MenuItemGroup设置默认2栅格的宽度，若菜单项内容区比2栅格宽，则会自适应撑开。
>
> 设置宽度的情况：菜单组件会对子组件MenuItem、MenuItemGroup设置减去padding后的固定宽度。

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性:

| 名称     | 参数类型                  | 描述                                                             |
| -------- | ------------------------- | ---------------------------------------------------------------- |
| fontSize<sup>(deprecated)</sup> | [Length](ts-types.md#length) | 统一设置Menu中所有文本的尺寸，Length为number类型时，使用fp单位。<br/>从API Version 10开始废弃，建议使用font代替。 |
| font<sup>10+</sup> | [Font](ts-types.md#font) | 统一设置Menu中所有文本的字体样式。 |
| fontColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 统一设置Menu中所有文本的颜色。 |
| radius<sup>10+</sup> | [Dimension](ts-types.md#dimension10) \| [BorderRadiuses](ts-types.md#borderradiuses9) | 设置Menu边框圆角半径。<br/> 默认值跟随主题。数值高于menu宽度的一半时，走默认值。 |
| width<sup>10+</sup> | [Length](ts-types.md#length) | 设置Menu边框宽度。<br/> 支持设置的最小宽度为64vp。 |

## 示例

```ts
@Entry
@Component
struct Index {
  @State select: boolean = true
  private iconStr: ResourceStr = $r("app.media.view_list_filled")
  private iconStr2: ResourceStr = $r("app.media.view_list_filled")

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
        endIcon: $r("app.media.arrow_right_filled"),
        builder: ():void=>this.SubMenu()
      })
      MenuItemGroup({ header: '小标题' }) {
        MenuItem({ content: "菜单选项" })
          .selectIcon(true)
          .selected(this.select)
          .onChange((selected) => {
            console.info("menuItem select" + selected);
            this.iconStr2 = $r("app.media.icon");
          })
        MenuItem({
          startIcon: $r("app.media.view_list_filled"),
          content: "菜单选项",
          endIcon: $r("app.media.arrow_right_filled"),
          builder: ():void=>this.SubMenu()
        })
      }
      MenuItem({
        startIcon: this.iconStr2,
        content: "菜单选项",
        endIcon: $r("app.media.arrow_right_filled")
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

![menu1](figures/menu1.png)
