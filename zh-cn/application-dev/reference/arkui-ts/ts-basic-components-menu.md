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

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性:

| 名称     | 参数类型                  | 描述                                                             |
| -------- | ------------------------- | ---------------------------------------------------------------- |
| fontSize<sup>deprecated</sup> | [Length](ts-types.md#length) | 统一设置Menu中所有文本的尺寸，Length为number类型时，使用fp单位。<br/>从API Version 10开始废弃，建议使用font代替。 |
| font<sup>10+</sup> | [Font](ts-types.md#font) | 统一设置Menu中所有文本的字体样式。 |
| fontColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 统一设置Menu中所有文本的颜色。 |

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
        builder: this.SubMenu.bind(this)
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
          builder: this.SubMenu.bind(this)
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
