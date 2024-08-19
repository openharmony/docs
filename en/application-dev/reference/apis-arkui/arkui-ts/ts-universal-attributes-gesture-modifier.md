# Gesture Modifier

With the gesture modifier, you can dynamically set gestures bound to components, complete with the **if/else** syntax.

>  **NOTE**
>
>  This feature is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## gestureModifier

gestureModifier(modifier: GestureModifier)

Creates a gesture modifier.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| modifier | [GestureModifier](#gesturemodifier-1) | Yes  | Modifier for dynamically setting gestures bound to the current component. The **if/else** syntax is supported.<br>**modifier**: gesture modifier. You need a custom class to implement the **GestureModifier** API.|

## GestureModifier

You need a custom class to implement the **GestureModifier** API.

### applyGesture
applyGesture(event: UIGestureEvent): void

Binds a gesture to this component.

You can customize this API as required. The **if/else** syntax is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name           | Type                                       | Description                                      |
| ------------- | ----------------------------------------  | ---------------------------------------- |
| event        | [UIGestureEvent](./ts-uigestureevent.md#uigestureevent) |  **UIGestureEvent** object, which is used to set the gesture to be bound to the component.     |

## Example

```ts
// xxx.ets
class MyButtonModifier implements GestureModifier {
  supportDoubleTap: boolean = true

  applyGesture(event: UIGestureEvent): void {
    if (this.supportDoubleTap) {
      event.addGesture(
        new TapGestureHandler({ count: 2, fingers: 1 })
          .tag("aaa")
          .onAction((event: GestureEvent) => {
            console.log("button tap ")
          })
      )
    } else {
      event.addGesture(
        new PanGestureHandler()
          .onActionStart(()=>{
            console.log("Pan start");
          })
      )
    }
  }
}

@Entry
@Component
struct Index {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Column()
          .gestureModifier(this.modifier)
          .width(500)
          .height(500)
          .backgroundColor(Color.Blue)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--no_check-->