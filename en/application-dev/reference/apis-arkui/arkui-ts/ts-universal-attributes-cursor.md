# Cursor Control

You can control the display style of the mouse cursor.

>  **NOTE**
>
>  This feature is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.


## cursorControl

### setCursor

setCursor(value: PointerStyle): void

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Sets the current mouse cursor style. This API can be used globally in method statements.

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ---- | ---- |
| value | [PointerStyle](../../apis-input-kit/js-apis-pointer.md#pointerstyle) | All consistent  | Cursor style.|


### restoreDefault

restoreDefault(): void

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Restores the mouse cursor to the default arrow style. This API can be used globally in method statements.


## Example

This example demonstrates how to change the mouse cursor style using **setCursor**.

> **NOTE**
> 
> Directly using **cursorControl** can lead to [ambiguous instance issues](../../../ui/arkts-global-interface.md). To avoid this, obtain a **UIContext** instance using [getUIContext](../js-apis-arkui-UIContext.md#uicontext), and then obtain the associated **cursorControl** object using [getCursorController](../js-apis-arkui-UIContext.md#getcursorcontroller12).

```ts
// xxx.ets
import { pointer } from '@kit.InputKit';

@Entry
@Component
struct CursorControlExample {
  @State text: string = '';
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      Row().height(200).width(200).backgroundColor(Color.Green).position({x: 150 ,y:70})
        .onHover((flag) => {
          if (flag) {
            // You are advised to use this.getUIContext().getCursorController().setCursor().
            cursorControl.setCursor(pointer.PointerStyle.EAST)
          } else {
            // You are advised to use this.getUIContext().getCursorController().restoreDefault().
            cursorControl.restoreDefault()
          }
        })
      Row().height(200).width(200).backgroundColor(Color.Blue).position({x: 220 ,y:120})
        .onHover((flag) => {
          if (flag) {
            // You are advised to use this.getUIContext().getCursorController().setCursor().
            cursorControl.setCursor(pointer.PointerStyle.WEST)
          } else {
            // You are advised to use this.getUIContext().getCursorController().restoreDefault().
            cursorControl.restoreDefault()
          }
        })
    }.width('100%')
  }
}
```
Diagrams:

When the mouse hovers over the blue area, it displays a west-pointing arrow cursor style.

![cursor_blue](figures/cursor_blue.jpg)

When the mouse hovers over the blue area, it displays an east-pointing arrow cursor style.

![cursor_green](figures/cursor_green.jpg)
