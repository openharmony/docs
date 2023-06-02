# Menu Control

A context menu – a vertical list of items – can be bound to a component and displayed by long-pressing, clicking, or right-clicking the component.

>  **NOTE**
>
>  - The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  - **CustomBuilder** does not support the use of **bindMenu** and **bindContextMenu** methods. To display a multi-level menu, use the [\<Menu>](ts-basic-components-menu.md) component instead.


## Attributes


| Name                        | Type                                                    | Description                                                        |
| ---------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| bindMenu                     | content: Array<[MenuItem](#menuitem)&gt; \| [CustomBuilder](ts-types.md#custombuilder8),<br>options: [MenuOptions](#menuoptions10) | Menu bound to the component, which is displayed when you click the component. A menu item can be a combination of text and icons or a custom component.<br>**content**: array of menu item text and icons or custom components.<br>**options**: parameters of the context menu. Optional.|
| bindContextMenu<sup>8+</sup> | content: [CustomBuilder](ts-types.md#custombuilder8),<br>responseType: [ResponseType](ts-appendix-enums.md#responsetype8)<br>options: [ContextMenuOptions](#contextmenuoptions10) | Context menu bound to the component, which is displayed when the user long-presses or right-clicks the component. Only custom menu items are supported.<br>**responseType**: how the context menu triggered, which can be long-press or right-click. Mandatory.  <br>**options**: parameters of the context menu. Optional.|

## MenuItem

| Name              | Type                                  | Mandatory| Description                  |
| ------------------ | -------------------------------------- | ---- | ---------------------- |
| value              | string                                 | Yes  | Menu item text.          |
| icon<sup>10+</sup> | [ResourceStr](ts-types.md#resourcestr) | No  | Menu item icon.          |
| action             | () =&gt; void                | Yes  | Action triggered when a menu item is clicked.|

## MenuOptions<sup>10+</sup>

| Name  | Type                            | Mandatory| Description                                                  |
| ------ | -------------------------------- | ---- | ------------------------------------------------------ |
| title  | string                           | No  | Menu title.                                            |
| offset | [Position](ts-types.md#position8) | No  | Offset for showing the context menu, which should not cause the menu to extend beyond the screen.|
| placement | [Placement](ts-appendix-enums.md#placement8) | No| Preferred position of the context menu. If the set position is insufficient for holding the component, it will be automatically adjusted.<br>**NOTE**<br>Setting **placement** to **undefined** or **null** is equivalent to not setting it at all.|
| onAppear | () =&gt; void | No| Callback triggered when the menu is displayed.|
| onDisappear | () =&gt; void | No| Callback triggered when the menu is hidden.|

## ContextMenuOptions<sup>10+</sup>

| Name       | Type                                        | Mandatory| Description                                                        |
| ----------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| offset      | [Position](ts-types.md#position8)            | No  | Offset for showing the context menu, which should not cause the menu to extend beyond the screen.        |
| placement   | [Placement](ts-appendix-enums.md#placement8) | No  | Preferred position of the context menu. If the set position is insufficient for holding the component, it will be automatically adjusted.<br>**NOTE**<br>Setting **placement** to **undefined** or **null** is equivalent to not setting it at all.|
| onAppear    | () =&gt; void                      | No  | Callback triggered when the menu is displayed.                                      |
| onDisappear | () =&gt; void                      | No  | Callback triggered when the menu is hidden.                                      |

## Example

### Example 1

Menu with Textual Menu Items

```ts
// xxx.ets
@Entry
@Component
struct MenuExample {
  build() {
    Column() {
      Text('click for Menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu([
      {
        value: 'Menu1',
        action: () => {
          console.info('handle Menu1 select')
        }
      },
      {
        value: 'Menu2',
        action: () => {
          console.info('handle Menu2 select')
        }
      },
    ])
  }
}
```

![en_image_0000001174582862](figures/en_image_0000001174582862.gif)

### Example 2

Menu with Custom Menu Items

```ts
@Entry
@Component
struct MenuExample {
  @State listData: number[] = [0, 0, 0]

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      ForEach(this.listData, (item, index) => {
        Column() {
          Row() {
            Image($r("app.media.icon")).width(20).height(20).margin({ right: 5 })
            Text(`Menu${index + 1}`).fontSize(20)
          }
          .width('100%')
          .height(30)
          .justifyContent(FlexAlign.Center)
          .align(Alignment.Center)
          .onClick(() => {
            console.info(`Menu${index + 1} Clicked!`)
          })

          if (index != this.listData.length - 1) {
            Divider().height(10).width('80%').color('#ccc')
          }
        }.padding(5).height(40)
      })
    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
        .fontSize(20)
        .margin({ top: 20 })
        .bindMenu(this.MenuBuilder)
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#f0f0f0')
  }
}
```

![en_image_0000001186807708](figures/en_image_0000001186807708.gif)

### Example 3

Context Menu (Displayed Upon Right-Clicking)

```ts
// xxx.ets
@Entry
@Component
struct ContextMenuExample {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }.width(100)
  }
  
  build() {
    Column() {
      Text('rightclick for menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindContextMenu(this.MenuBuilder, ResponseType.RightClick)
  }
}
```
