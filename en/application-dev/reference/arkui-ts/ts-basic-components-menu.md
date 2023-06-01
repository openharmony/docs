# Menu

The **\<Menu>** component is a vertical list of items presented to the user.

> **NOTE**
>
> - This component is supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The **\<Menu>** component must be used together with the [bindMenu](ts-universal-attributes-menu.md) or [bindContextMenu](ts-universal-attributes-menu.md) method. It does not work when used alone.

## Child Components

This component contains the [MenuItem](ts-basic-components-menuitem.md) and [MenuItemGroup](ts-basic-components-menuitemgroup.md) child components.

## APIs

Menu()

Creates a fixed container for a menu. This API does not have any parameters.

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name    | Type                 | Description                                                            |
| -------- | ------------------------- | ---------------------------------------------------------------- |
| fontSize | [Length](ts-types.md#length) | Font size of the menu text. When **Length** is of the number type, the unit is fp.|

## Example

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
      MenuItem({ content: "Copy", labelInfo: "Ctrl+C" })
      MenuItem({ content: "Paste", labelInfo: "Ctrl+V" })
    }
  }

  @Builder
  MyMenu(){
    Menu() {
      MenuItem({ startIcon: $r("app.media.icon"), content: "Menu option" })
      MenuItem({ startIcon: $r("app.media.icon"), content: "Menu option" })
        .enabled(false)
      MenuItem({
        startIcon: this.iconStr,
        content: "Menu option",
        endIcon: $r("app.media.arrow_right_filled"),
        builder: this.SubMenu.bind(this)
      })
      MenuItemGroup({ header: 'Subtitle' }) {
        MenuItem ({ content: "Menu option" })
          .selectIcon(true)
          .selected(this.select)
          .onChange((selected) => {
            console.info("menuItem select" + selected);
            this.iconStr2 = $r("app.media.icon");
          })
        MenuItem({
          startIcon: $r("app.media.view_list_filled"),
          content: "Menu option",
          endIcon: $r("app.media.arrow_right_filled"),
          builder: this.SubMenu.bind(this)
        })
      }
      MenuItem({
        startIcon: this.iconStr2,
        content: "Menu option",
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
