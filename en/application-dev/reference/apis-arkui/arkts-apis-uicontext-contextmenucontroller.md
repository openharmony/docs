# Class (ContextMenuController)

Provides the capability to control the closing of context menus.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - In the following API examples, you must first use [getContextMenuController()](./arkts-apis-uicontext-uicontext.md#getcontextmenucontroller12) in **UIContext** to obtain a **ContextMenuController** instance, and then call the APIs using the obtained instance.

## close<sup>12+</sup>

close(): void

Closes this context menu.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

This example demonstrates how to trigger the **close()** API of **ContextMenuController** via a timer to close the menu automatically after a specified delay.

```ts
import { ContextMenuController } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  menu: ContextMenuController = this.getUIContext().getContextMenuController();

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Test ContextMenu1 Close')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu2')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu3')
    }
    .width(200)
    .height(160)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button("Start Timer").onClick(()=>
      {
        setTimeout(() => {
          this.menu.close();
        }, 10000);
      })

      Column() {
        Text("Test ContextMenu close")
          .fontSize(20)
          .width('100%')
          .height(500)
          .backgroundColor(0xAFEEEE)
          .textAlign(TextAlign.Center)
      }
      .bindContextMenu(this.MenuBuilder, ResponseType.LongPress)
    }
    .width('100%')
    .height('100%')
  }
}
```

![contextMenuController_close](figures/contextMenuController_close.gif)
