# Menu Control

A menu – a vertical list of items – can be bound to a component and displayed by long-pressing, clicking, or right-clicking the component.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name                          | Type                                                       | Description                                                        |
| ---------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| bindMenu                     | Array<MenuItem&gt; \| [CustomBuilder](ts-types.md#custombuilder8) | Menu bound to the component, which is displayed when you click the component. Textual and custom menu items are supported.|
| bindContextMenu<sup>8+</sup> | content: [CustomBuilder](ts-types.md#custombuilder8)<br>responseType: [ResponseType](ts-appendix-enums.md#responsetype8) | Context menu bound to the component, which is displayed when you long-press or right-click the component. Only custom menu items are supported.|

## MenuItem

| Name    | Type                     | Description         |
| ------ | ----------------------- | ----------- |
| value  | string                  | Menu item text.     |
| action | () =&gt; void | Action triggered when a menu item is clicked.|


## Example

#### Menu with Textual Menu Items

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

#### Menu with Custom Menu Items

```ts
// xxx.ets
import router from '@system.router'

@Entry
@Component
struct MenuExample {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('text1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Text('text2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Button('Next')
        .fontSize(20)
        .width(100)
        .height(50)
        .onClick(() => {
          router.push({ uri: 'pages/details' })
        })

    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu(this.MenuBuilder)
  }
}
```

![en_image_0000001186807708](figures/en_image_0000001186807708.gif)

#### Context Menu (Displayed Upon Right-Clicking)

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
